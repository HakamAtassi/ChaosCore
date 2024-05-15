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

import SelectFirstN._

class reorder_free_inputs(fetchWidth:Int, physicalRegCount:Int) extends Module{

    val io = IO(new Bundle{
        val free_valid             = Input(Vec(fetchWidth, Bool()))
        val free_values            = Input(Vec(fetchWidth, UInt(log2Ceil(physicalRegCount).W)))

        val free_valid_sorted      = Output(Vec(fetchWidth, Bool()))
        val free_values_sorted     = Output(Vec(fetchWidth, UInt(log2Ceil(physicalRegCount).W)))
    })

    val sels = SelectFirstN(Reverse(Cat(io.free_valid)), fetchWidth)

    for (i <- 0 until fetchWidth){
        io.free_valid_sorted(i)   := Mux1H(sels(i), io.free_valid)
        io.free_values_sorted(i)  := Mux1H(sels(i), io.free_values)
    }


}


class reorder_renamed_outputs extends Module{

    val io = IO(new Bundle{
        val renamed_valid          = Input(Vec(fetchWidth, Bool()))
        val renamed_values         = Input(Vec(fetchWidth, UInt(log2Ceil(physicalRegCount).W)))

        val sorted_renamed_values     = Output(Vec(fetchWidth, UInt(log2Ceil(physicalRegCount).W)))
    })

    // TODO: 
    // ???

}

 
class free_list(fetchWidth:Int, physicalRegCount:Int) extends Module{
    val ptr_width = log2Ceil(physicalRegCount) + 1

    // important:
    // This module assumes that the free and read requests are "ordered"
    // This is important because where the write in a 2+ wire free request, for exmaple, is based on the index of that valid bit.
    // If inputs are not reordere from [0,1,0,1] to [0,0,1,1], the queue will have random empty (garbage) spots
    // Similarly, the queue will output the values in [0,0,1,1] format but needs to reorganize things such that the are in the appropriate 
    // spots, depending on what the read request expects

    // FIXME: does the output need to be flopped?

    val io = IO(new Bundle{

        val rename_valid    = Input(Vec(fetchWidth, Bool()))
        val renamed_values  = Output(Vec(fetchWidth, UInt(log2Ceil(physicalRegCount).W)))    // valid mask for RD (how many renamed regs do you need from free list)

        val free_valid      = Input(Vec(fetchWidth, Bool()))
        val free_values     = Input(Vec(fetchWidth, UInt(log2Ceil(physicalRegCount).W)))    // valid mask for RD (how many renamed regs do you need from free list)

        val empty           = Output(Bool())
        val full            = Output(Bool())
    })


    val front_pointer = RegInit(UInt(ptr_width.W), 0.U)
    val back_pointer  = RegInit(UInt(ptr_width.W), 0.U)

    val free_list_buffer = RegInit(VecInit((0 until physicalRegCount).map(_.U(log2Ceil(physicalRegCount).W))))


    // front pointer
    when(!io.empty){
        front_pointer := front_pointer + PopCount(io.rename_valid)
    }

    for(i <- 0 until fetchWidth){   // assign output values
        io.renamed_values(i) := free_list_buffer(front_pointer(ptr_width-2, 0) + i.U)
    }

    // back pointer
    back_pointer := back_pointer + PopCount(io.free_valid)

    for(i <- 0 until fetchWidth){   // assign output values
        when(io.free_valid(i) === 1.B){
            free_list_buffer(back_pointer(ptr_width-2, 0) + i.U) := io.free_values(i)
        }
    }


    io.empty := ((front_pointer + 4.U)(ptr_width-2, 0)  ===  back_pointer(ptr_width-2, 0)) && ((front_pointer + 4.U)(ptr_width-1)  =/=  back_pointer(ptr_width-1))
    io.full  := (front_pointer)  ===  back_pointer

}


