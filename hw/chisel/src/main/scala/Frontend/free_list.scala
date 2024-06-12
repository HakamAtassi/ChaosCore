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

class reorder_free_inputs(parameters:Parameters) extends Module{
    import parameters._

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


class reorder_renamed_outputs(parameters:Parameters) extends Module{
    import parameters._
    val io = IO(new Bundle{
        val renamed_valid          = Input(Vec(fetchWidth, Bool()))
        val renamed_values         = Input(Vec(fetchWidth, UInt(log2Ceil(physicalRegCount).W)))

        val renamed_values_sorted     = Output(Vec(fetchWidth, UInt(log2Ceil(physicalRegCount).W)))
    })


    val valid_bits = Reverse(Cat(io.renamed_valid))

    val sels = Wire(Vec(fetchWidth, UInt(log2Ceil(fetchWidth).W)))

    sels(0)  :=  0.U 

    for (i <- 1 until fetchWidth){
        sels(i) := PopCount(valid_bits(i-1, 0)) 
    }

    for (i <- 0 until fetchWidth){
        io.renamed_values_sorted(i) := io.renamed_values(sels(i))
    }
    

}

 
class free_list(parameters:Parameters) extends Module{
    import parameters._
    val ptr_width = log2Ceil(physicalRegCount) + 1
    val portCount = getPortCount(parameters)

    // important:
    // This module assumes that the free and read requests are "ordered"
    // This is important because where the write in a 2+ wire free request, for exmaple, is based on the index of that valid bit.
    // If inputs are not reordere from [0,1,0,1] to [0,0,1,1], the queue will have random empty (garbage) spots
    // Similarly, the queue will output the values in [0,0,1,1] format but needs to reorganize things such that the are in the appropriate 
    // spots, depending on what the read request expects

    val io = IO(new Bundle{

        val rename_valid    = Input(Vec(fetchWidth, Bool()))
        val renamed_values  = Output(Vec(fetchWidth, UInt(log2Ceil(physicalRegCount).W)))    // valid mask for RD (how many renamed regs do you need from free list)
        val renamed_valid   = Output(Vec(fetchWidth, Bool()))

        // The number of values you need to free at at a time is equal to the number of functional unit ports. 
        val free_valid      = Input(Vec(portCount, Bool()))
        val free_values     = Input(Vec(portCount, UInt(log2Ceil(physicalRegCount).W)))

        val empty           = Output(Bool())
        val full            = Output(Bool())
    })


    val front_pointer = RegInit(UInt(ptr_width.W), 0.U)
    val back_pointer  = RegInit(UInt(ptr_width.W), 0.U)

    val free_list_buffer = RegInit(VecInit((1 until physicalRegCount).map(_.U(log2Ceil(physicalRegCount).W))))


    ///////////////////////
    // Reorganize inputs //
    ///////////////////////

    // Gather inputs 
    val input_sorter = Module(new reorder_free_inputs(parameters))

    input_sorter.io.free_valid             := io.free_valid
    input_sorter.io.free_values            := io.free_values

    val free_valid_sorted  = input_sorter.io.free_valid_sorted
    val free_values_sorted = input_sorter.io.free_values_sorted

    /////////////////////
    // Actual Freelist //
    /////////////////////

    val renamed_values  = Wire(Vec(fetchWidth, UInt(log2Ceil(physicalRegCount).W)))    // valid mask for RD (how many renamed regs do you need from free list)

    // front pointer
    when(!io.empty){
        front_pointer := front_pointer + PopCount(io.rename_valid)
    }

    for(i <- 0 until fetchWidth){   // assign output values
        renamed_values(i) := free_list_buffer(front_pointer(ptr_width-2, 0) + i.U)
    }

    // back pointer
    back_pointer := back_pointer + PopCount(free_valid_sorted)

    for(i <- 0 until fetchWidth){   // assign output values
        when(free_valid_sorted(i) === 1.B){
            free_list_buffer(back_pointer(ptr_width-2, 0) + i.U) := free_values_sorted(i)
        }
    }

    ////////////////////////
    // Reorganize Outputs //
    ////////////////////////

    // scatter outputs


    val renamed_index = Wire(Vec(fetchWidth, UInt(log2Ceil(fetchWidth).W)))

    for(i <- 1 to fetchWidth){   // Assign outputs
        renamed_index(i-1) :=  PopCount(io.rename_valid.take(i)) - 1.U
    }
   
    for(i <- 0 until fetchWidth){   // Assign outputs
        val rename_valid = io.rename_valid(i)
        io.renamed_values(i) := Mux(rename_valid, renamed_values(renamed_index(i)), 0.U)
    }



    ////////////////
    // Full/Empty //
    ////////////////

    io.empty := ((front_pointer + 4.U)(ptr_width-2, 0)  ===  back_pointer(ptr_width-2, 0)) && ((front_pointer + 4.U)(ptr_width-1)  =/=  back_pointer(ptr_width-1))
    io.full  := (front_pointer)  ===  back_pointer


    // Assign output valid bits

    for(i <- 0 until fetchWidth){
        io.renamed_valid(i) := io.rename_valid(i) && (!io.empty)
    }

}


