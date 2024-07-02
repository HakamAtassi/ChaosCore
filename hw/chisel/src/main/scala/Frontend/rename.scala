/* ------------------------------------------------------------------------------------
* Filename: rename.scala
* Author: Hakam Atassi
* Date: May 9 2024
* Description: The components required for superscalar renaming. 
* License: MIT
*
* Copyright (c) 2024 by Hakam Atassi
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
* ------------------------------------------------------------------------------------ 
*/

package ChaosCore

import chisel3._
import chisel3.util._


// the architecture of the RAT and RAT checkpointing is inspired by sargantana.

class WAW_handler(parameters:Parameters) extends Module{
    import parameters._
    // sometimes, multiple instructions within a single fetch packet will 
    // have the same RD. During rename, this RD will result in two different mappins between
    // arch. reg and physical reg from the free list. 
    // This module ensures that the RAT is updated with the most recent mapping in said fetch packet.

    val physicalRegBits = log2Ceil(physicalRegCount)
    val architecturalRegBits = log2Ceil(architecturalRegCount)

    val io = IO(new Bundle{
        // From decoders and free_list
        val decoder_RD_valid_bits   = Input(Vec(fetchWidth, Bool()))
        val decoder_RD_values       = Input(Vec(fetchWidth, UInt(architecturalRegBits.W)))
        val free_list_RD_values     = Input(Vec(fetchWidth, UInt(physicalRegBits.W)))

        // To RAT write
        val RAT_wr_en               = Output(Vec(fetchWidth, Bool()))
        val RAT_RD_values           = Output(Vec(fetchWidth, UInt(architecturalRegBits.W)))
        val FL_RD_values            = Output(Vec(fetchWidth, UInt(physicalRegBits.W)))
    })

    // Idea: every wr en is only high if no later instruction is actively renaming the same RD

    // pass values through
    // Only wr_en really matters
    io.RAT_RD_values := io.decoder_RD_values
    io.FL_RD_values  := io.free_list_RD_values

  for (i <- 0 until fetchWidth) {
    var rat_wr_en_i = io.decoder_RD_valid_bits(i)
    for (j <- i + 1 until fetchWidth) {
      rat_wr_en_i = rat_wr_en_i && ((io.decoder_RD_values(i) =/= io.decoder_RD_values(j)) || !io.decoder_RD_valid_bits(j))
    }
    io.RAT_wr_en(i) := rat_wr_en_i
  }

}

class RAT(parameters:Parameters) extends Module{
    import parameters._
    val RATCheckpointBits    = log2Ceil(RATCheckpointCount)
    val physicalRegBits      = log2Ceil(physicalRegCount)
    val architecturalRegBits = log2Ceil(architecturalRegCount)

    val portCount = getPortCount(parameters)

    assert(RATCheckpointCount%2 == 0, "Rat checkpoint count must be multiple of 2")

    val io = IO(new Bundle{
        // input read ports
        val instruction_RS1             =   Input(Vec(fetchWidth, UInt(architecturalRegBits.W)))
        val instruction_RS2             =   Input(Vec(fetchWidth, UInt(architecturalRegBits.W)))
        val instruction_RD              =   Input(Vec(fetchWidth, UInt(architecturalRegBits.W)))

        // UPDATE //
        val FU_outputs                  =   Vec(portCount, Flipped(ValidIO(new FU_output(parameters))))

        // write ports (post WAW handling)
        val free_list_wr_en             =   Input(Vec(fetchWidth, Bool()))
        val free_list_RD                =   Input(Vec(fetchWidth, UInt(physicalRegBits.W)))

        // checkpoint (create/restore)
        val create_checkpoint           =   Input(Bool())
        val restore_checkpoint          =   Input(Bool())
        val free_checkpoint             =   Input(Bool())
        val restore_checkpoint_value    =   Input(UInt(RATCheckpointBits.W))   // What checkpoint is currently being used

        val active_checkpoint_value     =   Output(UInt(RATCheckpointBits.W))   // What checkpoint is currently being used

        val checkpoints_full            =   Output(Bool())                      // No more checkpoints available

        // renamed outputs
        val RAT_RD                      =   Output(Vec(fetchWidth, UInt(physicalRegBits.W)))
        val RAT_RS1                     =   Output(Vec(fetchWidth, UInt(physicalRegBits.W)))
        val RAT_RS2                     =   Output(Vec(fetchWidth, UInt(physicalRegBits.W)))

        val ready_bits                  =   Output(Vec(fetchWidth, new sources_ready()))
    })


    ////////////////////
    // RAT STRUCTURES //
    ////////////////////

    val RAT_memories    = RegInit(VecInit.tabulate(RATCheckpointCount, architecturalRegCount){(x, y) => 0.U(physicalRegBits.W) })
    val ready_memory  = RegInit(VecInit(Seq.fill(physicalRegCount)(0.B)))
    
    ////////////////
    // CHECKPOINT //
    ////////////////

    val active_RAT      = RegInit(UInt(RATCheckpointBits.W), 0.U)
    val active_RAT_comb = Wire(UInt(RATCheckpointBits.W))

    val available_checkpoints      = RegInit(UInt(RATCheckpointBits.W), 0.U)
    val available_checkpoints_comb = Wire(UInt(RATCheckpointBits.W))


    active_RAT_comb := active_RAT
    when(io.restore_checkpoint){
        active_RAT_comb := io.restore_checkpoint_value
    }.elsewhen(io.create_checkpoint){
        active_RAT_comb := active_RAT + 1.U
    }
    active_RAT := active_RAT_comb

    available_checkpoints_comb  := available_checkpoints - io.create_checkpoint // FIXME: I think this is wrong
    when(io.free_checkpoint){
        available_checkpoints := available_checkpoints + 1.U
    }

    available_checkpoints := available_checkpoints_comb

    ////////////////
    // RENAME/MAP //
    ////////////////

    dontTouch(active_RAT_comb)

    for(i <- 0 until fetchWidth){
        io.RAT_RD(i)  := RegNext(RAT_memories(active_RAT)(io.instruction_RD(i)))
        io.RAT_RS1(i) := RegNext(RAT_memories(active_RAT)(io.instruction_RS1(i)))
        io.RAT_RS2(i) := RegNext(RAT_memories(active_RAT)(io.instruction_RS2(i)))
    }

    // CREATE CHECKPOINT
    when(io.create_checkpoint){
        for (j <- 0 until architecturalRegCount){
            RAT_memories(active_RAT_comb)(j) := RAT_memories(active_RAT)(j) // copy data over to next checkpoint
        }
    }

    // GET WR_EN & WR_DIN
    val wr_din  = Wire(Vec(architecturalRegCount, UInt(physicalRegBits.W)))
    val wr_en   = Wire(Vec(architecturalRegCount, Bool()))

    for(i <- 0 until architecturalRegCount){
        wr_din(i) := 0.U
        wr_en(i)  := 0.B
    }

    for(i <- 0 until fetchWidth){
        wr_din(io.instruction_RD(i))   := io.free_list_RD(i)
        wr_en(io.instruction_RD(i))    := io.free_list_wr_en(i)
    }

    // WRITE MAPPING
    for (i <- 0 until architecturalRegCount){
        when(wr_en(i) === 1.B){
            RAT_memories(active_RAT_comb)(i) := wr_din(i)
        }
    }

    ////////////////
    // READY BITS //
    ////////////////

    // setting ready bit
    // whenever an instruction completes
    // if the completing instruction(s) is writing to the mapping that exists in the ith entry of the ROB
    // and that completing instruction is valid
    // set that ready bit, and bypass it as needed

    val comb_ready_bits = Wire(Vec(physicalRegCount, Bool()))

    for(i <- 0 until physicalRegCount){
        comb_ready_bits(i) := ready_memory(i)
    }

    // Set ready bit from FU
    for(i <- 0 until fetchWidth){
        val set_RD      = io.FU_outputs(i).bits.RD
        val RD_valid    = io.FU_outputs(i).valid && io.FU_outputs(i).bits.RD_valid

        comb_ready_bits(set_RD) := ready_memory(set_RD) || RD_valid
    }

    // Reset ready bit
    for(i <- 0 until fetchWidth){
        val set_RD      = io.free_list_RD(i)
        val RD_valid    = io.free_list_wr_en(i)

        when(RD_valid){
            comb_ready_bits(set_RD) := 0.B
        }
    }

    // Update ready register
    for(i <- 0 until physicalRegCount){
        ready_memory(i) := comb_ready_bits(i)
    }






    // assign ready output

    for(i <- 0 until fetchWidth){
        val initialReady = Wire(new sources_ready)
        //initialReady.RS1_ready := RegNext(comb_ready_bits(io.instruction_RS1(i))).asBool

        // if the source is x0, its ready regardless of what its value says
        // if the source is not valid, its ready regardless of what its value says
        initialReady.RS1_ready := Mux(RegNext(io.instruction_RS1(i)) === 0.U, 1.B, comb_ready_bits(io.RAT_RS1(i)))
        initialReady.RS2_ready := Mux(RegNext(io.instruction_RS2(i)) === 0.U, 1.B, comb_ready_bits(io.RAT_RS2(i)))

        io.ready_bits(i)       := initialReady
    }


    io.active_checkpoint_value  := active_RAT
    io.checkpoints_full         := (available_checkpoints === 0.U)
    
}

class rename(parameters:Parameters) extends Module{
    import parameters._
    // Takes in N input instructions
    // Reads the renamed versions of RS1, RS2, and RD (old)
    // performs a rename to RD using the free list
    // outputs RD(old), RD, RS1, RS2

    // Also provides checkpointing capability.

    val physicalRegBits      = log2Ceil(physicalRegCount)
    val architecturalRegBits = log2Ceil(architecturalRegCount)
    val RATCheckpointBits    = log2Ceil(RATCheckpointCount)

    val portCount = getPortCount(parameters)

    val io = IO(new Bundle{
        // FLUSH
        val flush                           =   Input(Bool())

        // CHECKPOINT 
        val commit                          =   Flipped(ValidIO(new commit(parameters)))

        // Instruction input (decoded)
        val decoded_fetch_packet            =   Flipped(Decoupled(new decoded_fetch_packet(parameters)))

        val FU_outputs                      =   Vec(portCount, Flipped(ValidIO(new FU_output(parameters))))

        // Instruction output (renamed)
        val renamed_decoded_fetch_packet    =   Decoupled(new decoded_fetch_packet(parameters))
    })

    dontTouch(io)

    ////////////////////
    // OUTPUT BUNDLES //
    ////////////////////
    val renamed_decoded_fetch_packet = Wire(Decoupled(new decoded_fetch_packet(parameters)))


    /////////////
    // MODULES //
    /////////////

    val free_list       = Module(new free_list(parameters))
    val WAW_handler     = Module(new WAW_handler(parameters:Parameters))
    val RAT             = Module(new RAT(parameters:Parameters))


    renamed_decoded_fetch_packet.bits                := RegNext(io.decoded_fetch_packet.bits)


    ////////////////
    // CHECKPOINT //
    ////////////////


    // GENERATE SIGNALS
    val restore_checkpoint          = io.commit.valid && io.commit.bits.is_misprediction
    val restore_checkpoint_value    = io.commit.bits.RAT_index
    val free_checkpoint             = io.commit.valid && !io.commit.bits.is_misprediction && (io.commit.bits.br_type =/= _br_type.NONE)
    val create_checkpoint           = Wire(Bool())

    val create_checkpoint_vec   = Wire(Vec(fetchWidth, Bool()))
    for(i <- 0 until fetchWidth){
        create_checkpoint_vec(i) := io.decoded_fetch_packet.bits.decoded_instruction(i).needs_branch_unit && 
                                    io.decoded_fetch_packet.valid &&
                                    io.decoded_fetch_packet.bits.valid_bits(i)
    }

    create_checkpoint := create_checkpoint_vec.reduce(_ || _)

    // ASSIGN RAT 
    RAT.io.create_checkpoint           :=   create_checkpoint
    RAT.io.restore_checkpoint          :=   restore_checkpoint
    RAT.io.restore_checkpoint_value    :=   restore_checkpoint_value
    RAT.io.free_checkpoint             :=   free_checkpoint



    /////////
    // WAW //
    /////////

    for(i <- 0 until fetchWidth){
        WAW_handler.io.decoder_RD_valid_bits(i)    :=  io.decoded_fetch_packet.bits.decoded_instruction(i).RD_valid && io.decoded_fetch_packet.valid
        WAW_handler.io.decoder_RD_values(i)        :=  io.decoded_fetch_packet.bits.decoded_instruction(i).RD
        WAW_handler.io.free_list_RD_values(i)      :=  free_list.io.renamed_values(i)
    }

    /////////
    // RAT //
    /////////

    // Assign write ports
    RAT.io.free_list_wr_en                         :=  WAW_handler.io.RAT_wr_en
    RAT.io.free_list_RD                            :=  WAW_handler.io.FL_RD_values
    RAT.io.FU_outputs                              :=  io.FU_outputs
    
    // Assign read ports
    for(i <- 0 until fetchWidth){
        RAT.io.instruction_RD(i)                   :=  WAW_handler.io.RAT_RD_values(i)
        RAT.io.instruction_RS1(i)                  :=  io.decoded_fetch_packet.bits.decoded_instruction(i).RS1
        RAT.io.instruction_RS2(i)                  :=  io.decoded_fetch_packet.bits.decoded_instruction(i).RS2
    }

    val renamed_RS1 = Wire(Vec(fetchWidth, UInt(log2Ceil(physicalRegCount).W)))
    val renamed_RS2 = Wire(Vec(fetchWidth, UInt(log2Ceil(physicalRegCount).W)))

    // superscalar forwarding logic
    for(i <- 0 until fetchWidth){
       renamed_RS1(i) := RAT.io.RAT_RS1(i)   // default case (no forwarding)
       renamed_RS2(i) := RAT.io.RAT_RS2(i)   // default case (no forwarding)
        for(j <- 0 until i){
            // forward RS1
            when(RegNext(io.decoded_fetch_packet.bits.decoded_instruction(i).RS1) === RegNext(io.decoded_fetch_packet.bits.decoded_instruction(j).RD)){
                renamed_RS1(i) := RegNext(free_list.io.renamed_values(j))
            }
            // forward RS2
            when(RegNext(io.decoded_fetch_packet.bits.decoded_instruction(i).RS2) === RegNext(io.decoded_fetch_packet.bits.decoded_instruction(j).RD)){
                renamed_RS2(i) := RegNext(free_list.io.renamed_values(j))
            }
        }
    }

    for(i <- 0 until fetchWidth){
        renamed_decoded_fetch_packet.bits.decoded_instruction(i).RS1             := renamed_RS1(i)
        renamed_decoded_fetch_packet.bits.decoded_instruction(i).RS2             := renamed_RS2(i)
    }

    renamed_decoded_fetch_packet.bits.RAT_index                  := RAT.io.active_checkpoint_value

    ///////////////
    // FREE LIST //
    ///////////////

    // Provide a renamed RD for every valid RD, non-zero, RD
    for(i <- 0 until fetchWidth){
        // perform rename if RD is valid, packet is valid, and reg is not x0

        // Request new values
        free_list.io.rename_valid(i)                   :=   io.decoded_fetch_packet.bits.decoded_instruction(i).RD_valid && 
                                                            io.decoded_fetch_packet.valid && 
                                                            (io.decoded_fetch_packet.bits.decoded_instruction(i).RD =/= 0.U)
    }
    free_list.io.commit := io.commit
    
    for(i <- 0 until fetchWidth){
        renamed_decoded_fetch_packet.bits.decoded_instruction(i).RD              := RegNext(free_list.io.renamed_values(i))
        renamed_decoded_fetch_packet.bits.decoded_instruction(i).RD_valid        := RegNext(io.decoded_fetch_packet.bits.decoded_instruction(i).RD_valid)
        renamed_decoded_fetch_packet.bits.decoded_instruction(i).ready_bits      := RAT.io.ready_bits(i)
    }

    renamed_decoded_fetch_packet.bits.free_list_front_pointer    := RegNext(free_list.io.free_list_front_pointer)

    // FIXME: output valid should be if all the instructions that need a rename, are renamed. 
    // IE, if input has no RD, free list empty should not matter.
    // So, instead of free_list.io.empty being a condition to valid, there should be a "renameble" signal
    renamed_decoded_fetch_packet.valid := RegNext(io.decoded_fetch_packet.valid && !io.flush && !free_list.io.empty)
    renamed_decoded_fetch_packet.ready := io.renamed_decoded_fetch_packet.ready

    /////////////////
    // SKID BUFFER //
    /////////////////
    val renamed_decoded_fetch_packet_skid_buffer = Module(new Queue(new decoded_fetch_packet(parameters), 1, flow=true, hasFlush=true, useSyncReadMem=false))

    renamed_decoded_fetch_packet_skid_buffer.io.enq         <> renamed_decoded_fetch_packet
    renamed_decoded_fetch_packet_skid_buffer.io.deq         <> io.renamed_decoded_fetch_packet
    renamed_decoded_fetch_packet_skid_buffer.io.flush.get   := io.flush

    /////////////////
    // READY/VALID //
    /////////////////

    io.decoded_fetch_packet.ready                       := !free_list.io.empty && io.renamed_decoded_fetch_packet.ready

}