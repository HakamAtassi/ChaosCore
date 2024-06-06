/* ------------------------------------------------------------------------------------
* Filename: hash_BTB.scala
* Author: Hakam Atassi
* Date: Apr 19 2024
* Description: A branch target buffer implemented as a hash table for 2-wide execution. 
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

import helperFunctions._

//class instruction_queue[T <: Data](gen: T, parameters: Parameters) extends Module {
class hash_BTB_mem[T <: Data](gen: T, depth: Int) extends Module {
  val io = IO(new Bundle {
    val enable = Input(Bool())

    // Read
    val rd_addr = Input(UInt(log2Ceil(depth).W))
    val data_out = Output(gen)
    
    // Write
    val wr_addr = Input(UInt(log2Ceil(depth).W))
    val wr_en = Input(Bool())
    val data_in = Input(gen)
  })

  val mem = SyncReadMem(depth, gen)
  io.data_out := DontCare

  /////////////////////
  // HAZARD HANDLING //
  /////////////////////

  val hazard_reg = RegInit(Bool(), 0.B)
  val din_buff = RegInit(gen, 0.U.asTypeOf(gen))

  hazard_reg := (io.rd_addr === io.wr_addr) && io.wr_en
  din_buff := io.data_in

  //////////////////
  // READ & WRITE //
  //////////////////

  val data_out = Wire(gen)
  data_out := 0.U.asTypeOf(gen)

  when(io.enable) {
    when(io.wr_en) {
      mem.write(io.wr_addr, io.data_in)
    }

    data_out := mem.read(io.rd_addr, io.enable)
  }

    io.data_out := Mux(hazard_reg, din_buff, data_out) // Forward buffered data if hazard
}



class hash_BTB(parameters:Parameters) extends Module{
    import parameters._
    

    val io = IO(new Bundle{

        //prediction-input
        val predict_PC                          = Input(UInt(32.W))
        val predict_valid                       = Input(Bool())


        //prediction-output
        val BTB_hit                             = Output(Bool())
        val BTB_output                          = Output(new BTB_entry(parameters))

        //commit-input
        val commit                              = Input(new commit(parameters))

    })

    val commit_input_tag    = shiftDownByTagBits(io.commit.fetch_PC)
    val predict_input_tag   = shiftDownByTagBits(io.predict_PC)

    // memory // 

    val BTB_memory = Module(new hash_BTB_mem(new BTB_entry(parameters), depth = BTBEntries))

    val prediction_BTB_address  = (io.predict_PC >> log2Ceil(fetchWidth*4))
    val commit_BTB_address      = (io.commit.fetch_PC >> log2Ceil(fetchWidth*4))

    BTB_memory.io.enable    := 1.B
    BTB_memory.io.rd_addr   := prediction_BTB_address
    BTB_memory.io.wr_addr   := commit_BTB_address
    BTB_memory.io.wr_en     := io.commit.valid


    val commit_BTB_entry = Wire(new BTB_entry(parameters))

    // FIXME: consider updating this to its own bundle and using <>
    commit_BTB_entry.BTB_valid                  := 1.B
    commit_BTB_entry.BTB_tag                    := commit_input_tag
    commit_BTB_entry.BTB_target                 := io.commit.expected_PC
    commit_BTB_entry.BTB_br_type                := io.commit.br_type
    commit_BTB_entry.BTB_fetch_packet_index     := io.commit.fetch_packet_index

    BTB_memory.io.data_in := commit_BTB_entry

    ////////////////////////////////////
    // Hit logic and assignment logic // 
    ////////////////////////////////////

    val BTB_valid_output    = BTB_memory.io.data_out.BTB_valid
    val BTB_tag_output      = BTB_memory.io.data_out.BTB_tag

    io.BTB_hit      := (RegNext(predict_input_tag) === BTB_tag_output) && BTB_valid_output.asBool
    io.BTB_output <> BTB_memory.io.data_out
    io.BTB_output.BTB_valid := RegNext(io.predict_valid)
}
