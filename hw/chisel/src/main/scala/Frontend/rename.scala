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

class WAW_handler(coreParameters:CoreParameters) extends Module{
    import coreParameters._
    // sometimes, multiple instructions within a single fetch packet will 
    // have the same PRD. During rename, this PRD will result in two different mappins between
    // arch. reg and physical reg from the free list. 
    // This module ensures that the RAT is updated with the most recent mapping in said fetch packet.


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

    // Idea: every wr en is only high if no later instruction is actively renaming the same PRD

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

class RAT(coreParameters:CoreParameters) extends Module{
    import coreParameters._

    val portCount = getPortCount(coreParameters)

    assert(RATCheckpointCount%2 == 0, "Rat checkpoint count must be multiple of 2")

    val io = IO(new Bundle{
        // input read ports
        val instruction_RS1             =   Input(Vec(fetchWidth, UInt(architecturalRegBits.W)))
        val instruction_RS2             =   Input(Vec(fetchWidth, UInt(architecturalRegBits.W)))
        val instruction_RD              =   Input(Vec(fetchWidth, UInt(architecturalRegBits.W)))

        // write ports (post WAW handling)
        val free_list_wr_en             =   Input(Vec(fetchWidth, Bool()))
        val free_list_RD                =   Input(Vec(fetchWidth, UInt(physicalRegBits.W)))

        // Exception/Commit
        //val exception                   =   Input(Bool())

        val flush                       =   Flipped(ValidIO(new flush(coreParameters)))
        val commit                      =   Input(ValidIO(new commit(coreParameters)))

        // renamed outputs
        val RAT_PRDold                  =   Output(Vec(fetchWidth, UInt(physicalRegBits.W)))
        val RAT_RS1                     =   Output(Vec(fetchWidth, UInt(physicalRegBits.W)))
        val RAT_RS2                     =   Output(Vec(fetchWidth, UInt(physicalRegBits.W)))
    })


    ////////////////////
    // RAT STRUCTURES //
    ////////////////////
    val commit_RAT      = RegInit(VecInit(Seq.fill(architecturalRegCount)(0.U(physicalRegBits.W))))
    val speculative_RAT = RegInit(VecInit(Seq.fill(architecturalRegCount)(0.U(physicalRegBits.W))))


    /////////////////////
    // SPECULATIVE RAT //
    /////////////////////

    // read RAT
    for(i <- 0 until fetchWidth){
        io.RAT_RS1(i)    := speculative_RAT(io.instruction_RS1(i))
        io.RAT_RS2(i)    := speculative_RAT(io.instruction_RS2(i))
        io.RAT_PRDold(i) := speculative_RAT(io.instruction_RD(i))
    }

    // write RAT
    for (i <- 0 until fetchWidth){
        when(io.free_list_wr_en(i)){
            speculative_RAT(io.instruction_RD(i)) := io.free_list_RD(i)
        }
    }

    ////////////////
    // COMMIT RAT //
    ////////////////
    // write RAT
    for (i <- 0 until fetchWidth){
        when(io.commit.valid && io.commit.bits.insn_commit(i).valid && io.commit.bits.insn_commit(i).bits.committed && io.commit.bits.insn_commit(i).bits.RD_valid){
            commit_RAT(io.commit.bits.insn_commit(i).bits.RD) := io.commit.bits.insn_commit(i).bits.PRD
        }
    }

    ////////////
    // REVERT //
    ////////////
    when(io.flush.valid){
        speculative_RAT := commit_RAT
        for(i <- 0 until fetchWidth){
            when(io.commit.valid && io.commit.bits.insn_commit(i).valid && io.commit.bits.insn_commit(i).bits.committed && io.commit.bits.insn_commit(i).bits.RD_valid){
                speculative_RAT(io.commit.bits.insn_commit(i).bits.RD) := io.commit.bits.insn_commit(i).bits.PRD
            }
        }
    }




}

class rename(data_type:String = "Int")(coreParameters:CoreParameters) extends Module{
    import coreParameters._
    // Takes in N input instructions
    // Reads the renamed versions of RS1, RS2, and PRD (old)
    // performs a rename to PRD using the free list
    // outputs PRD(old), PRD, RS1, RS2

    // Also provides checkpointing capability.

    // FIXME: module currently doesnt check for data type when renaming...!!!!
    val RATCheckpointBits    = log2Ceil(RATCheckpointCount)

    val portCount = if(data_type == "Int"){get_INT_consumer_count(FUParamSeq)} else {get_FP_consumer_count(FUParamSeq)}

    val io = IO(new Bundle{
        // FLUSH
        val flush = Flipped(ValidIO(new flush(coreParameters)))

        // CHECKPOINT 
        val commit                          =   Flipped(ValidIO(new commit(coreParameters)))

        // Instruction input (decoded)
        val decoded_fetch_packet            =   Flipped(Decoupled(new decoded_fetch_packet(coreParameters)))

        val FU_outputs                      =   Vec(portCount, Flipped(Decoupled(new FU_output(coreParameters))))

        // Instruction output (renamed)
        val renamed_decoded_fetch_packet    =   Decoupled(new decoded_fetch_packet(coreParameters))
    }); dontTouch(io)


    val accepted_decoded_packet = Reg(new decoded_fetch_packet(coreParameters))

    when(io.decoded_fetch_packet.fire){
        accepted_decoded_packet := io.decoded_fetch_packet.bits
    }



    /////////////
    // MODULES //
    /////////////
    val free_list       = Module(new free_list(coreParameters))
    val WAW_handler     = Module(new WAW_handler(coreParameters:CoreParameters))
    val RAT             = Module(new RAT(coreParameters:CoreParameters))

    //////////////////
    // HELPER WIRES //
    //////////////////
    
    val fire = io.decoded_fetch_packet.fire && !(io.flush.valid) 

    ////////////////////
    // OUTPUT BUNDLES //
    ////////////////////
    val renamed_decoded_fetch_packet = Wire(Decoupled(new decoded_fetch_packet(coreParameters)))    // input to skid buffer

    renamed_decoded_fetch_packet.bits       := io.decoded_fetch_packet.bits
    renamed_decoded_fetch_packet.valid      := fire

    ///////////////
    // FREE LIST //
    ///////////////

    for(i <- 0 until fetchWidth){
        free_list.io.rename_valid(i)                   :=   io.decoded_fetch_packet.bits.decoded_instruction(i).RD_valid && 
                                                            (io.decoded_fetch_packet.bits.decoded_instruction(i).RD =/= 0.U) && 
                                                            fire
    }

    free_list.io.commit := io.commit
    for(i <- 0 until fetchWidth){
        renamed_decoded_fetch_packet.bits.decoded_instruction(i).PRD          := free_list.io.renamed_values(i)
        renamed_decoded_fetch_packet.bits.decoded_instruction(i).RD           := io.decoded_fetch_packet.bits.decoded_instruction(i).RD
        //renamed_decoded_fetch_packet.bits.decoded_instruction(i).PRDold       := io.decoded_fetch_packet.bits.decoded_instruction(i).PRDold
    }
    renamed_decoded_fetch_packet.bits.free_list_front_pointer                 := free_list.io.free_list_front_pointer

    /////////
    // WAW //
    /////////
    for(i <- 0 until fetchWidth){
        WAW_handler.io.decoder_RD_valid_bits(i)    :=  io.decoded_fetch_packet.bits.decoded_instruction(i).RD_valid && fire
        WAW_handler.io.decoder_RD_values(i)        :=  io.decoded_fetch_packet.bits.decoded_instruction(i).RD
        WAW_handler.io.free_list_RD_values(i)      :=  free_list.io.renamed_values(i)
    }

    /////////
    // RAT //
    /////////

    // Assign write ports
    RAT.io.free_list_wr_en                         :=  WAW_handler.io.RAT_wr_en 
    RAT.io.free_list_RD                            :=  WAW_handler.io.FL_RD_values
    RAT.io.commit                                  <> io.commit
    RAT.io.flush                                  <> io.flush
    
    // Assign read ports
    for(i <- 0 until fetchWidth){
        RAT.io.instruction_RD(i)                   :=  WAW_handler.io.RAT_RD_values(i)
        RAT.io.instruction_RS1(i)                  :=  io.decoded_fetch_packet.bits.decoded_instruction(i).RS1
        RAT.io.instruction_RS2(i)                  :=  io.decoded_fetch_packet.bits.decoded_instruction(i).RS2
    }

    val renamed_RS1     = Wire(Vec(fetchWidth, UInt(physicalRegBits.W)))
    val renamed_RS2     = Wire(Vec(fetchWidth, UInt(physicalRegBits.W)))
    val renamed_PRDold  = Wire(Vec(fetchWidth, UInt(physicalRegBits.W)))


    // superscalar forwarding logic
    for(i <- 0 until fetchWidth){
       renamed_RS1(i) := RAT.io.RAT_RS1(i)   // default case (no forwarding)
       renamed_RS2(i) := RAT.io.RAT_RS2(i)   // default case (no forwarding)
       renamed_PRDold(i) := RAT.io.RAT_PRDold(i)   // default case (no forwarding)
        for(j <- 0 until i){
            // forward RS1
            when((io.decoded_fetch_packet.bits.decoded_instruction(i).RS1 === io.decoded_fetch_packet.bits.decoded_instruction(j).RD) && 
                (io.decoded_fetch_packet.bits.decoded_instruction(i).RS1_valid && io.decoded_fetch_packet.bits.decoded_instruction(j).RD_valid) && io.decoded_fetch_packet.bits.decoded_instruction(j).valid
                        ){
                renamed_RS1(i) := free_list.io.renamed_values(j)
            }
            // forward RS2
            when((io.decoded_fetch_packet.bits.decoded_instruction(i).RS2 === io.decoded_fetch_packet.bits.decoded_instruction(j).RD) && 
                            (io.decoded_fetch_packet.bits.decoded_instruction(i).RS2_valid && io.decoded_fetch_packet.bits.decoded_instruction(j).RD_valid) && io.decoded_fetch_packet.bits.decoded_instruction(j).valid
            ){
                renamed_RS2(i) := free_list.io.renamed_values(j)
            }
            // forward RDold
            when((io.decoded_fetch_packet.bits.decoded_instruction(i).RD === io.decoded_fetch_packet.bits.decoded_instruction(j).RD) && 
                            (io.decoded_fetch_packet.bits.decoded_instruction(i).RD_valid && io.decoded_fetch_packet.bits.decoded_instruction(j).RD_valid && 
                            io.decoded_fetch_packet.bits.decoded_instruction(i).RD =/= 0.U && io.decoded_fetch_packet.bits.decoded_instruction(j).RD =/= 0.U) && io.decoded_fetch_packet.bits.decoded_instruction(j).valid
            ){
                renamed_PRDold(i) := free_list.io.renamed_values(j)
            }
        }
    }

    for (i <- 0 until renamed_decoded_fetch_packet.bits.decoded_instruction.length) {
        renamed_decoded_fetch_packet.bits.decoded_instruction(i).RS1    := io.decoded_fetch_packet.bits.decoded_instruction(i).RS1
        renamed_decoded_fetch_packet.bits.decoded_instruction(i).RS2    := io.decoded_fetch_packet.bits.decoded_instruction(i).RS2
        renamed_decoded_fetch_packet.bits.decoded_instruction(i).PRDold := 0.U //io.decoded_fetch_packet.bits.decoded_instruction(i).RD

        when(io.decoded_fetch_packet.bits.decoded_instruction(i).RS1_valid){
            renamed_decoded_fetch_packet.bits.decoded_instruction(i).RS1    := renamed_RS1(i)
        }

        when(io.decoded_fetch_packet.bits.decoded_instruction(i).RS2_valid){
            renamed_decoded_fetch_packet.bits.decoded_instruction(i).RS2    := renamed_RS2(i)
        }
        when(io.decoded_fetch_packet.bits.decoded_instruction(i).RD_valid){
            renamed_decoded_fetch_packet.bits.decoded_instruction(i).PRDold := renamed_PRDold(i)
        }

    }



    ////////////////
    // READY BITS //
    ////////////////

    val ready_memory  = RegInit(VecInit(Seq.fill(physicalRegCount)(0.B)))
    val comb_ready_bits = Wire(Vec(physicalRegCount, Bool()))


    comb_ready_bits := ready_memory




    for(i <- 0 until portCount){

        val set_RD      = io.FU_outputs(i).bits.PRD
        val RD_valid    = io.FU_outputs(i).valid && io.FU_outputs(i).bits.RD_valid

        io.FU_outputs(i).ready := 1.B   // rename can always set ready bits

        when(RD_valid){ // set ready bits
            comb_ready_bits(set_RD) := 1.B
            ready_memory(set_RD) := 1.B
        }
    }






    free_list.io.commit           <> io.commit
    free_list.io.flush                    <> io.flush

    // x0 as a dest or source is never remapped
    // x0 always ready
    comb_ready_bits(0) := 1.U
    
    // Update ready register
    when(io.renamed_decoded_fetch_packet.fire){
        ready_memory := comb_ready_bits
    }

    when(io.flush.valid){
        ready_memory := Seq.fill(physicalRegCount)(1.B)
    }


    dontTouch(ready_memory)
    dontTouch(comb_ready_bits)

    /////////////////
    // SKID BUFFER //
    /////////////////

    // fetch packet Q takes up a lot of area...
    val renamed_decoded_fetch_packet_Q  = Module(new Queue(new decoded_fetch_packet(coreParameters), 2, flow=false, hasFlush=true, useSyncReadMem=false))
    val outputs_ready                   =  io.renamed_decoded_fetch_packet.ready 

    dontTouch(renamed_decoded_fetch_packet)

    renamed_decoded_fetch_packet_Q.io.enq                   <> renamed_decoded_fetch_packet
    renamed_decoded_fetch_packet_Q.io.enq.valid             := (renamed_decoded_fetch_packet.valid) && !io.flush.valid

    renamed_decoded_fetch_packet_Q.io.deq                   <> io.renamed_decoded_fetch_packet
    renamed_decoded_fetch_packet_Q.io.flush.get             := io.flush.valid



    // Reset ready bit
    for(i <- 0 until fetchWidth){
        val set_RD      = io.renamed_decoded_fetch_packet.bits.decoded_instruction(i).PRD 
        val RD_valid    = io.renamed_decoded_fetch_packet.bits.decoded_instruction(i).RD_valid 

        val initialReady = Wire(new sources_ready)
        initialReady.RS1_ready := comb_ready_bits(io.renamed_decoded_fetch_packet.bits.decoded_instruction(i).RS1)
        initialReady.RS2_ready := comb_ready_bits(io.renamed_decoded_fetch_packet.bits.decoded_instruction(i).RS2)

        for(j <- 0 until i){
            val prev_RD_valid   = io.renamed_decoded_fetch_packet.bits.decoded_instruction(j).RD_valid
            val prev_PRD         = io.renamed_decoded_fetch_packet.bits.decoded_instruction(j).PRD
            val RS1        = io.renamed_decoded_fetch_packet.bits.decoded_instruction(i).RS1
            val RS2        = io.renamed_decoded_fetch_packet.bits.decoded_instruction(i).RS2
            when(prev_RD_valid && (prev_PRD === RS1) && RS1 =/= 0x0.U){
                initialReady.RS1_ready := 0.U 
            }.elsewhen(prev_RD_valid && (prev_PRD === RS2 && RS2 =/= 0x0.U)){
                initialReady.RS2_ready := 0.U 
            }
        }

        when(!io.renamed_decoded_fetch_packet.bits.decoded_instruction(i).RS1_valid){initialReady.RS1_ready := 1.U }
        when(!io.renamed_decoded_fetch_packet.bits.decoded_instruction(i).RS2_valid){initialReady.RS2_ready := 1.U }

        io.renamed_decoded_fetch_packet.bits.decoded_instruction(i).ready_bits := initialReady
    }



    for(i <- 0 until fetchWidth){
        val set_RD      = io.renamed_decoded_fetch_packet.bits.decoded_instruction(i).PRD
        val RD_valid    = io.renamed_decoded_fetch_packet.bits.decoded_instruction(i).RD_valid 

        when(RD_valid && io.renamed_decoded_fetch_packet.fire && io.renamed_decoded_fetch_packet.bits.decoded_instruction(i).valid){    // is this fine?
            ready_memory(set_RD) := 0.B
        }
    }

    ready_memory(0) := 1.B
    comb_ready_bits(0) := 1.B

    io.decoded_fetch_packet.ready                           := RegNext(outputs_ready) && free_list.io.can_allocate





}

