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
import circt.stage.ChiselStage 
import chisel3.util._
import java.io.{File, FileWriter}
import java.rmi.server.UID


class free_list(parameters:Parameters) extends Module{
    import parameters._
    val ptr_width = log2Ceil(physicalRegCount-1) + 1

    val io = IO(new Bundle{
        val rename_valid            = Input(Vec(fetchWidth, Bool()))                                    // Request rename valid
        val renamed_values          = Output(Vec(fetchWidth, UInt(log2Ceil(physicalRegCount).W)))       // Renamed RDs
        val renamed_valid           = Output(Vec(fetchWidth, Bool()))                                   // Renamed RDs valid

        val commit                  = Flipped(ValidIO(new commit(parameters)))                          // Free regs on commit

        val free_list_front_pointer = Output(UInt((log2Ceil(physicalRegCount) + 1).W))                  // To ROB

        val empty                   = Output(Bool())                                                    // Cant rename anymore, less than 4 entries available.
        val full                    = Output(Bool())                                                    // Cant free anymore, less than 4 positions free.
    })

    val flush = io.commit.valid && io.commit.bits.is_misprediction

    // Pointers
    val front_pointer   = RegInit(UInt(ptr_width.W), 0.U)                       // front pointer starts at 0
    val back_pointer    = RegInit(UInt(ptr_width.W), (physicalRegCount-2).U)    // back pointer starts at N-1

    val front_index     = Wire(UInt((ptr_width-1).W))
    val back_index      = Wire(UInt((ptr_width-1).W))

    // Free list
    val free_list_buffer = RegInit(VecInit((1 until physicalRegCount).map(_.U(physicalRegBits.W)))) //x0 not in free list

    front_index := front_pointer(ptr_width-2, 0)
    back_index  := back_pointer(ptr_width-2, 0)

    //////////////////
    // POP ELEMENTS //
    //////////////////

    for(i <- 0 until fetchWidth){
        val read_offset          = PopCount(io.rename_valid.take(i+1)) - 1.U
        val valid = io.rename_valid(i) && !flush   // pass through valid
        io.renamed_valid(i)     := valid
        when(valid){
            io.renamed_values(i)    := free_list_buffer(front_index + read_offset)
        }.otherwise{
            io.renamed_values(i)    := 0.U
        }
    }

    io.free_list_front_pointer  := front_pointer
    
    ///////////////////
    // PUSH ELEMENTS //
    ///////////////////
    //////////////////
    // POINTER CTRL //
    //////////////////

    val allocate_valid  =   Wire(Vec(fetchWidth, Bool()))

    dontTouch(allocate_valid)

    for(i <- 0 until fetchWidth){
        allocate_valid(i) := (io.commit.bits.RD_valid(i)) && (io.commit.bits.RD(i) =/= 0.U)
    }
    


    when(!(io.commit.valid && io.commit.bits.is_misprediction)){                               // not misprediction
        front_pointer := front_pointer + PopCount(io.rename_valid)
    }.elsewhen(io.commit.valid && io.commit.bits.is_misprediction){                            // misprediction 
        front_pointer := io.commit.bits.free_list_front_pointer
    }
    when(io.commit.valid && !(io.commit.bits.is_misprediction)){                               // commit
        back_pointer := back_pointer + PopCount(allocate_valid)
    }


    ////////////////
    // Full/Empty //
    ////////////////

    val remaining_RDs   = back_pointer - front_pointer
    val free_spots      = 0.U

    val elements_in_queue = Mux(back_pointer >= front_pointer,
                                back_pointer - front_pointer,
                                (back_pointer + physicalRegCount.U) - front_pointer)

    io.empty := elements_in_queue < 4.U
    io.full  := elements_in_queue === (physicalRegCount - 1).U

}


