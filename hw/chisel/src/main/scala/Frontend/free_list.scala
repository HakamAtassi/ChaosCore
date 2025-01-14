/* ------------------------------------------------------------------------------------
* Filename: free_list.scala
* Author: Hakam Atassi
* Date: May 9 2024
* Description: A superscalar free list that can both read and write up to fetchWidth entries at a time in any order.
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
import java.io.{File, FileWriter}
import java.rmi.server.UID





class free_list(coreParameters:CoreParameters) extends Module{
    import coreParameters._
    val ptr_width = log2Ceil(physicalRegCount-1) + 1

    val io = IO(new Bundle{
        val rename_valid            = Input(Vec(fetchWidth, Bool()))                                    // Request rename valid
        val renamed_values          = Output(Vec(fetchWidth, UInt(log2Ceil(physicalRegCount).W)))       // Renamed RDs
        val renamed_valid           = Output(Vec(fetchWidth, Bool()))                                   // Renamed RDs valid

        val commit                  = Flipped(ValidIO(new commit(coreParameters)))                          // Free regs on commit

        val flush                   = Flipped(ValidIO(new flush(coreParameters)))

        val free_list_front_pointer = Output(UInt(ptr_width.W))                  // To ROB

        val can_allocate            = Output(Bool())
    }); dontTouch(io)

    val flush = io.flush.valid

    // Pointers

    val free_list_buffer               = RegInit(VecInit(Seq.fill(physicalRegCount-1)(1.B)))
    val commit_free_list_buffer        = RegInit(VecInit(Seq.fill(physicalRegCount-1)(1.B)))


    //////////////////
    // POP ELEMENTS //
    //////////////////

    val selectedPRDs = SelectFirstNInt(free_list_buffer.asUInt, fetchWidth)

    //val test = Wire(UInt(7.W))

    for(i <- 0 until fetchWidth){   // remove from freelist
        io.renamed_values(i) := 0.U 
        io.renamed_valid(i)  := io.rename_valid(i) && !flush && io.can_allocate
        when(io.rename_valid(i)){
            //val PRD = selectedPRDs(i)
            val PRD = Cat(0.U, selectedPRDs(i))
            free_list_buffer(PRD)       := 0.B
            io.renamed_values(i)        := PRD + 1.U
        }
    }

    io.free_list_front_pointer  := 0.U

    //FIXME: does the order of these matter?
    for(i <- 0 until fetchWidth){
        when(io.commit.bits.insn_commit(i).valid && io.commit.bits.insn_commit(i).bits.committed && io.commit.bits.insn_commit(i).bits.RD_valid && io.commit.bits.insn_commit(i).bits.RD =/= 0.U){    // dont add x0
            val commit_PRDold = Wire(UInt(log2Ceil(physicalRegCount-1).W))
            commit_PRDold := (io.commit.bits.insn_commit(i).bits.PRDold - 1.U) % (physicalRegCount-1).U

            free_list_buffer(commit_PRDold) := 1.B
            commit_free_list_buffer(commit_PRDold) := 1.B
        }

        when(io.commit.bits.insn_commit(i).valid && io.commit.bits.insn_commit(i).bits.committed && io.commit.bits.insn_commit(i).bits.RD_valid && io.commit.bits.insn_commit(i).bits.RD =/= 0.U){
            val commit_PRD = Wire(UInt(log2Ceil(physicalRegCount-1).W))
            commit_PRD := (io.commit.bits.insn_commit(i).bits.PRD - 1.U) % (physicalRegCount-1).U
            commit_free_list_buffer(commit_PRD) := 0.B
        }
    }


    ///////////////////
    // MISPREDICTION //
    ///////////////////

    //FIXME: does the order of these matter?
    when(io.flush.valid){
        free_list_buffer := commit_free_list_buffer
        for(i <- 0 until fetchWidth){
            when(io.commit.bits.insn_commit(i).valid && io.commit.bits.insn_commit(i).bits.committed && io.commit.bits.insn_commit(i).bits.RD_valid){
                val commit_PRD = Wire(UInt(log2Ceil(physicalRegCount-1).W))
                commit_PRD := io.commit.bits.insn_commit(i).bits.PRD - 1.U
                free_list_buffer(commit_PRD) := 0.B
            }

            when(io.commit.bits.insn_commit(i).valid && io.commit.bits.insn_commit(i).bits.committed && io.commit.bits.insn_commit(i).bits.RD_valid){
                val commit_PRDold = Wire(UInt(log2Ceil(physicalRegCount-1).W))
                commit_PRDold := io.commit.bits.insn_commit(i).bits.PRDold - 1.U
                free_list_buffer(commit_PRDold) := 1.B
            }

        }
        //for(i <- 0 until fetchWidth){
        //}
        
    }



    ////////////////
    // Full/Empty //
    ////////////////
    val available_entries = PopCount(free_list_buffer)

    io.can_allocate   := available_entries >= (fetchWidth).U   // +1 because x0 is always ready

    ////////////////
    // ASSERTIONS //
    ////////////////

    dontTouch(free_list_buffer)
    dontTouch(available_entries)
    dontTouch(commit_free_list_buffer)

}
