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

class WAW_handler(fetchWidth:Int, physicalRegCount:Int, architecturalRegCount:Int) extends Module{
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

class RAT_memory(fetchWidth:Int, physicalRegCount:Int, architecturalRegCount:Int, RATCheckpointCount:Int) extends Module{

    val RATCheckpointBits    = log2Ceil(RATCheckpointCount)
    val physicalRegBits      = log2Ceil(physicalRegCount)
    val architecturalRegBits = log2Ceil(architecturalRegCount)

    val io = IO(new Bundle{
        // read inputs
        val instruction_RD    =   Input(Vec(fetchWidth, UInt(architecturalRegBits.W)))
        val instruction_RS1   =   Input(Vec(fetchWidth, UInt(architecturalRegBits.W)))
        val instruction_RS2   =   Input(Vec(fetchWidth, UInt(architecturalRegBits.W)))

        // write ports (post WAW handling)
        val free_list_wr_en  =   Input(Vec(fetchWidth, Bool()))
        val free_list_RD     =   Input(Vec(fetchWidth, UInt(physicalRegBits.W)))

        // renamed outputs
        val RAT_RD    =   Output(Vec(fetchWidth, UInt(physicalRegBits.W)))
        val RAT_RS1   =   Output(Vec(fetchWidth, UInt(physicalRegBits.W)))
        val RAT_RS2   =   Output(Vec(fetchWidth, UInt(physicalRegBits.W)))

    })

    val regs = RegInit(VecInit(Seq.fill(architecturalRegCount)(0.U(physicalRegBits.W))))

    for (i <- 0 until fetchWidth){
        io.RAT_RD(i)  := RegNext(regs(io.instruction_RD(i)))
        io.RAT_RS1(i) := RegNext(regs(io.instruction_RS1(i)))
        io.RAT_RS2(i) := RegNext(regs(io.instruction_RS2(i)))
    }

    for (i <- 0 until fetchWidth){
        when(io.free_list_wr_en(i)){
            regs(io.instruction_RD(i)) := io.free_list_RD(i)
        }
    }

}


class RAT(fetchWidth:Int, physicalRegCount:Int, architecturalRegCount:Int, RATCheckpointCount:Int) extends Module{
    val RATCheckpointBits    = log2Ceil(RATCheckpointCount)
    val physicalRegBits      = log2Ceil(physicalRegCount)
    val architecturalRegBits = log2Ceil(architecturalRegCount)


    val io = IO(new Bundle{
        // input read ports
        val instruction_RD    =   Input(Vec(fetchWidth, UInt(architecturalRegBits.W)))
        val instruction_RS1   =   Input(Vec(fetchWidth, UInt(architecturalRegBits.W)))
        val instruction_RS2   =   Input(Vec(fetchWidth, UInt(architecturalRegBits.W)))

        // write ports (post WAW handling)
        val free_list_wr_en  =   Input(Vec(fetchWidth, Bool()))
        val free_list_RD     =   Input(Vec(fetchWidth, UInt(physicalRegBits.W)))

        // checkpoint (create/restore)
        val create_checkpoint        = Input(Bool())
        val active_checkpoint_value  = Output(UInt(RATCheckpointBits.W))   // What checkpoint is currently being used

        val restore_checkpoint       = Input(Bool())                       // Restore to previous valid RAT
        val restore_checkpoint_value = Input(UInt(RATCheckpointBits.W))    // ...
      
        val free_checkpoint          = Input(Bool())                       // Normal branch commit. Just dealloc. checkpoint

        val checkpoints_full         = Output(Bool())                      // No more checkpoints available

        // renamed outputs
        val RAT_RD    =   Output(Vec(fetchWidth, UInt(physicalRegBits.W)))
        val RAT_RS1   =   Output(Vec(fetchWidth, UInt(physicalRegBits.W)))
        val RAT_RS2   =   Output(Vec(fetchWidth, UInt(physicalRegBits.W)))
    })

    val active_RAT            = RegInit(UInt(RATCheckpointBits.W), 0.U)
    val available_checkpoints = RegInit(UInt(RATCheckpointBits.W), RATCheckpointCount.U)

    val RAT_memories = RegInit(VecInit.tabulate(RATCheckpointCount, architecturalRegCount){ (x, y) => 0.U(physicalRegBits.W) })
    

    // outputs of ALL RAT checkpoints

    val all_RD_outs  = RegInit(VecInit.tabulate(RATCheckpointCount, fetchWidth){ (x, y) => 0.U(physicalRegBits.W) })
    val all_RS1_outs = RegInit(VecInit.tabulate(RATCheckpointCount, fetchWidth){ (x, y) => 0.U(physicalRegBits.W) })
    val all_RS2_outs = RegInit(VecInit.tabulate(RATCheckpointCount, fetchWidth){ (x, y) => 0.U(physicalRegBits.W) })

    // Read logic

    // read from all checkpoints and place in reg
    for(i <- 0 until RATCheckpointCount){
        for(j <- 0 until fetchWidth){
            all_RD_outs(i)(j)  := RAT_memories(i)(io.instruction_RD(j))
            all_RS1_outs(i)(j) := RAT_memories(i)(io.instruction_RS1(j))
            all_RS2_outs(i)(j) := RAT_memories(i)(io.instruction_RS2(j))
        }
    }

    // select the correct data based on checkpoint value
    for(i <- 0 until fetchWidth){
        io.RAT_RD(i)  := all_RD_outs(active_RAT)(i)
        io.RAT_RS1(i) := all_RS1_outs(active_RAT)(i)
        io.RAT_RS2(i) := all_RS2_outs(active_RAT)(i)
    }


    // muxed rename data
    val wr_data_in = Wire(Vec(architecturalRegCount, UInt(physicalRegBits.W)))
    val is_being_written_vec = Wire(Vec(architecturalRegCount, Bool()))


    val reg_data_in  = VecInit.tabulate(RATCheckpointCount, architecturalRegCount){ (x, y) => 0.U(physicalRegBits.W) }
    val reg_wr_en    =VecInit.tabulate(RATCheckpointCount, architecturalRegCount){ (x, y) => 0.B }


    // is row being written by current input
    for (i <- 0 until architecturalRegCount){
        var is_being_written = 0.B
        for(j <- 0 until fetchWidth){
            is_being_written = is_being_written || (io.instruction_RD(j) === i.U)
        }
        is_being_written_vec(i) := is_being_written
    }

    // mux data from inputs
    for (i <- 0 until architecturalRegCount){
        for(j <- 0 until fetchWidth){
            wr_data_in(i) := 0.U
            when(io.instruction_RD(j) === i.U){
                wr_data_in(i) := io.free_list_RD(j)
            }
        }
    }


    // init first row of reg_data_in (since no prev checkpoint)

    for (j <- 0 until architecturalRegCount){
        reg_data_in(0)(j) := wr_data_in(j)
    }

    // mux data from input or checkpoint
    for(i <- 1 until RATCheckpointCount){
        for (j <- 0 until architecturalRegCount){
            when(io.create_checkpoint){
                reg_data_in(i)(j) := RAT_memories(i-1)(j)
            }.otherwise{
                reg_data_in(i)(j) := wr_data_in(i)
            }
        }
    }

    for(i <- 0 until RATCheckpointCount){
        for (j <- 0 until architecturalRegCount){
            // if the row in the active ret is being written, or if checkpoint being created, perform write. 
            reg_wr_en(i)(j) := (((active_RAT === i.U) && is_being_written_vec(j)) || (((active_RAT + 1.U) === i.U) && io.create_checkpoint))
        }
    }

    // Assign inputs to each reg
    for(i <- 0 until RATCheckpointCount){
        for (j <- 0 until architecturalRegCount){
            when(reg_wr_en(i)(j)){
                RAT_memories(i)(j) := reg_data_in(i)(j)
            }
        }
    }




    io.active_checkpoint_value := active_RAT

    
    // create checkpoint logic
    when(io.create_checkpoint){
        // copy active RAT to next RAT
        active_RAT := active_RAT + 1.U    // points to the active checkpoint
        available_checkpoints := available_checkpoints - 1.U
    }

    // restore checkpoint logic
    when(io.restore_checkpoint){
        // checkpoint restore is nothing more than decrementing the pointer
        active_RAT := io.restore_checkpoint_value      // go back to a valid RAT
    }

    // free checkpoint logic
    when(io.free_checkpoint){
        // simply increment the number of free checkpoints
        available_checkpoints := available_checkpoints + 1.U
    }

    io.checkpoints_full     := (available_checkpoints === 0.U)
    

}


class rename(fetchWidth:Int, physicalRegCount:Int, architecturalRegCount:Int, RATCheckpointCount:Int) extends Module{
    // Takes in N input instructions
    // Reads the renamed versions of RS1, RS2, and RD (old)
    // performs a rename to RD using the free list
    // outputs RD(old), RD, RS1, RS2

    // Also provides checkpointing capability.

    val physicalRegBits      = log2Ceil(physicalRegCount)
    val architecturalRegBits = log2Ceil(architecturalRegCount)
    val RATCheckpointBits    = log2Ceil(RATCheckpointCount)

    val io = IO(new Bundle{
        // Instrution input (rename)
        val instruction_RD            =   Input(Vec(fetchWidth, UInt(architecturalRegBits.W)))    // width of input regs from instruction (eg. RV32/RV64)
        val instruction_RD_valid      =   Input(Vec(fetchWidth, Bool()))

        val instruction_RS1           =   Input(Vec(fetchWidth, UInt(architecturalRegBits.W)))    // ...
        val instruction_RS1_valid     =   Input(Vec(fetchWidth, Bool()))

        val instruction_RS2           =   Input(Vec(fetchWidth, UInt(architecturalRegBits.W)))    // ...
        val instruction_RS2_valid     =   Input(Vec(fetchWidth, Bool()))

        // Freelist output
        //val RD_in                     =   Input(Vec(fetchWidth, UInt(architecturalRegBits.W)))
        //val instruction_RD_valid      =   Input(Vec(fetchwidth, Bool()))

        //val RS1_in                    =   Input(Vec(fetchWidth, UInt(architecturalRegBits.W)))
        //val instruction_RS1_valid     =   Input(Vec(fetchWidth, Bool()))

        //val RS2_in                    =   Input(Vec(fetchWidth, UInt(architecturalRegBits.W)))
        //val instruction_RS2_valid     =   Input(Vec(fetchWidth, Bool()))

        // RAT output
        val free_list_RD              =   Output(Vec(fetchWidth, UInt(physicalRegBits.W))) // From free list 
        val renamed_RD                =   Output(Vec(fetchWidth, UInt(physicalRegBits.W))) // From RAT
        val renamed_RS1               =   Output(Vec(fetchWidth, UInt(physicalRegBits.W)))
        val renamed_RS2               =   Output(Vec(fetchWidth, UInt(physicalRegBits.W)))


        // Instruction input (commit)
        val commit_RD                 =   Input(Vec(fetchWidth, UInt(physicalRegBits.W))) // From RAT
        val commit_RD_valid           =   Input(Vec(fetchWidth, Bool())) // From RAT

        // checkpoint (create/restore)
        val create_checkpoint         = Input(Bool())
        val active_checkpoint_value   = Output(UInt(RATCheckpointBits.W))   // What checkpoint is currently being used

        val restore_checkpoint        = Input(Bool())                       // Restore to previous valid RAT
        val restore_checkpoint_value  = Input(UInt(RATCheckpointBits.W))    // ...
        
        val free_checkpoint           = Input(Bool())                       // Normal branch commit. Just dealloc. checkpoint

        val checkpoints_full          = Output(Bool())                      // No more checkpoints available


    })

    // Notes: 
    // when doing rename, it is likely that an earlier instruction will rename its architectural RD to a value from the freelist,
    // while a later instruction will use the same architectural RD but as a source. 
    // Ex: x5 <= x1 + x6
    //     x9 <= x5 + x18
    // As such, it is very important for x5 to be renamed to the output of the freelist as opposed to the value in the RAT. 
    // In non-superscalar cores, this is not an issue becaues the first instruction would update the RAT in one cycle,
    // and the following cycle, the second instruction would just read from the now updated RAT. 
    // In superscalar, where multiple renames are done every cycle, the renamed value must be forwarded, since the RAT will not represent the earlier rename requets. 

    // RAT outputs
    val RAT_RD_values  = Wire(Vec(fetchWidth, UInt(physicalRegBits.W))) // RAT RD outputs
    val RAT_RS1_values = Wire(Vec(fetchWidth, UInt(physicalRegBits.W))) // RAT RS1 outputs
    val RAT_RS2_values = Wire(Vec(fetchWidth, UInt(physicalRegBits.W))) // RAT RS2 outputs


    ///////////////
    // Free List //
    ///////////////
    
    // for the free list
    // the input just takes in the rd_valid array as normal. the output sorting is handled via the reorder_renamed_outputs module
    // When freeing up old renamed registers at commit, the RDs need to be sorted, which is handled by the reorder_free_inputs module

    val free_list               = Module(new free_list(fetchWidth=fetchWidth, physicalRegCount=physicalRegCount))

    free_list.io.rename_valid                   :=  io.instruction_RD_valid

    free_list.io.free_valid                     :=  io.commit_RD_valid
    free_list.io.free_values                    :=  io.commit_RD


    ///////////////////////
    // RAT + WAW Handler //
    ///////////////////////

    val WAW_handler     = Module(new WAW_handler(fetchWidth=fetchWidth, physicalRegCount=physicalRegCount, architecturalRegCount=architecturalRegCount))
    val RAT             = Module(new RAT(fetchWidth=fetchWidth, physicalRegCount=physicalRegCount, architecturalRegCount=architecturalRegCount, RATCheckpointCount))

    WAW_handler.io.decoder_RD_valid_bits    :=  io.instruction_RD_valid
    WAW_handler.io.decoder_RD_values        :=  io.instruction_RD
    WAW_handler.io.free_list_RD_values      :=  free_list.io.renamed_values

    // Assign write ports
    RAT.io.free_list_wr_en                  :=  WAW_handler.io.RAT_wr_en
    RAT.io.instruction_RD                   :=  WAW_handler.io.RAT_RD_values
    RAT.io.free_list_RD                     :=  WAW_handler.io.FL_RD_values
    
    // Assign read ports
    RAT.io.instruction_RD                    :=  io.instruction_RD
    RAT.io.instruction_RS1                   :=  io.instruction_RS1
    RAT.io.instruction_RS2                   :=  io.instruction_RS2

    // Assign checkpoint stuff

    RAT.io.create_checkpoint         :=  io.create_checkpoint

    RAT.io.restore_checkpoint        :=  io.restore_checkpoint
    RAT.io.restore_checkpoint_value  :=  io.restore_checkpoint_value
      
    RAT.io.free_checkpoint           :=  io.free_checkpoint

    // RAT outputs
    RAT_RD_values   := RAT.io.RAT_RD
    RAT_RS1_values  := RAT.io.RAT_RS1
    RAT_RS2_values  := RAT.io.RAT_RS2


    ///////////////////////////////
    // Forwarding logic + Output //
    ///////////////////////////////

    // superscalar forwarding logic
    for(i <- 0 until fetchWidth){
       io.renamed_RS1(i) := RAT_RS1_values(i)   // default case (no forwarding)
       io.renamed_RS2(i) := RAT_RS2_values(i)   // default case (no forwarding)
       io.renamed_RD(i)  := RAT_RD_values(i)    // RD(old) value from RAT 
        for(j <- 0 until i){
            // forward RS1
            when(RegNext(io.instruction_RS1(i)) === RegNext(io.instruction_RD(j))){
                io.renamed_RS1(i) := RAT_RD_values(j)
            }

            // forward RS2
            when(RegNext(io.instruction_RS1(i)) === RegNext(io.instruction_RD(j))){
                io.renamed_RS2(i) := RAT_RD_values(j)
            }
        }
    }

    // Assign outputs

    io.active_checkpoint_value         := RAT.io.active_checkpoint_value
    io.checkpoints_full                := RAT.io.checkpoints_full

    io.free_list_RD              :=   free_list.io.renamed_values
    io.renamed_RD                :=   RAT.io.RAT_RD
    io.renamed_RS1               :=   RAT.io.RAT_RS1
    io.renamed_RS2               :=   RAT.io.RAT_RS2


}