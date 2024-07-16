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
import chisel3.ltl._
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

        val free_list_front_pointer = Output(UInt(ptr_width.W))                  // To ROB

        val can_reallocate          = Output(Bool())
        val can_allocate            = Output(Bool())
    })
    dontTouch(io)

    val flush = io.commit.valid && io.commit.bits.is_misprediction

    // Pointers
    val front_pointer   = RegInit(UInt(ptr_width.W), 0.U)                       // front pointer starts at 0
    val back_pointer    = RegInit(UInt(ptr_width.W), (physicalRegCount-1).U)    // back pointer starts at N-1

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
        val valid = io.rename_valid(i) && !flush && io.can_allocate
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

    for(i <- 0 until fetchWidth){
        allocate_valid(i) := (io.commit.bits.RD_valid(i)) && (io.commit.bits.RD(i) =/= 0.U) && io.commit.valid
    }

    when(!(io.commit.valid && io.commit.bits.is_misprediction) && io.can_allocate){            // Allocate elements
        front_pointer := front_pointer + PopCount(io.rename_valid)
    }.elsewhen(io.commit.valid && io.commit.bits.is_misprediction){                            // misprediction 
        front_pointer := io.commit.bits.free_list_front_pointer
    }

    when(io.commit.valid && io.can_reallocate && ~flush){                                      // reallocate
        back_pointer := back_pointer + PopCount(allocate_valid)
    }

    ////////////////
    // Full/Empty //
    ////////////////

    val available_elemets   = back_pointer - front_pointer

    io.can_reallocate := (available_elemets + fetchWidth.U) <= (physicalRegCount.U - 1.U)  // elements are reallocated if they fit into the buffer
    io.can_allocate   := fetchWidth.U <= available_elemets

    ////////////////
    // ASSERTIONS //
    ////////////////

    dontTouch(front_index)
    dontTouch(back_index)
    dontTouch(available_elemets)
    dontTouch(allocate_valid)


    ////////////
    // FORMAL //
    ////////////

    val has_been_reset_reg = RegInit(Bool(), 0.B)
    has_been_reset_reg := reset.asBool


    // COMMIT //
    val valid_commit_ptr    = RegInit(VecInit(Seq.fill(64)(0.U(ptr_width.W))))
    val valid_commit_valid  = RegInit(VecInit(Seq.fill(64)(0.B)))
    val commit_ptr_valid    = Wire(Bool())

    for(i <- 0 until 64){   // output set
        when(io.renamed_valid.reduce(_ || _)){  // when you rename, place the ptr somewhere and mark valid
            valid_commit_ptr(i) := io.free_list_front_pointer
            valid_commit_valid(i) := 0.B
        }
    }

    commit_ptr_valid := 0.B
    for(i <- 0 until 64){
        when((io.commit.bits.free_list_front_pointer === valid_commit_ptr(i)) && valid_commit_valid(i) && io.commit.valid){
            commit_ptr_valid := 1.B
            valid_commit_ptr(i) := 0.U
            valid_commit_valid(i) := 0.B
        }
    }   
    
    // Assert entry count
    val available_regs_within_bounds = Sequence.BoolSequence(((back_pointer-front_pointer) <= 64.U))

    val can_reallocate = Sequence.BoolSequence(((back_pointer-front_pointer)<=60.U) === io.can_reallocate) // can accept commit regs

    val can_allocate = Sequence.BoolSequence(((back_pointer-front_pointer)>=4.U) === io.can_allocate) // can accept commit regs

    // Assert that when input is valid, the free list pointer is correct
    val free_list_pointer = Sequence(Sequence.BoolSequence(io.rename_valid.reduce(_ || _)), Sequence.BoolSequence(io.free_list_front_pointer === front_index))

    // Assume that when you have a rename request, at some point in the future, 
    val valid_output = Sequence.BoolSequence(io.renamed_valid.reduce(_ || _))
    val valid_commit = Sequence.BoolSequence((commit_ptr_valid && io.commit.valid) || !(io.commit.valid))    // commit pointer must be either valid or not a commit



    AssertProperty(available_regs_within_bounds)
    AssertProperty(can_reallocate)
    AssertProperty(can_allocate)


    AssumeProperty(valid_commit)



}


