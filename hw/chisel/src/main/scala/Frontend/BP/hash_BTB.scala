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
import chisel3.util._
import java.io.{File, FileWriter}
import java.rmi.server.UID

import helperFunctions._

//class instruction_queue[T <: Data](gen: T, coreParameters: coreParameters) extends Module {
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



class hash_BTB(coreParameters:CoreParameters) extends Module{
    import coreParameters._
    

  val io = IO(new Bundle{

      // PREDICTION REQUEST 
      val predict_PC                          = Input(UInt(32.W))

      // PREDICTION OUTPUT
      val BTB_output                          = ValidIO(new BTB_entry(coreParameters))

      // UPDATE
      val commit = Flipped(ValidIO(new commit(coreParameters)))

  })

  
  // INIT
  val valid_mem = RegInit(VecInit(Seq.fill(BTBEntries)(0.B)))
  val mem = SyncReadMem(BTBEntries, new BTB_entry(coreParameters))


  // SIGNALS
  val s0_lookup_address  = io.predict_PC % BTBEntries.U
  val s0_entry_valid     = valid_mem(s0_lookup_address)

  val s1_tag             = RegNext(io.predict_PC)
  val s1_entry_valid     = RegNext(s0_entry_valid)


  // UPDATE 
  // BTB 

  val BTB_entry_input = WireInit(0.U.asTypeOf(new BTB_entry(coreParameters)))
  val commit_fetch_PC = io.commit.bits.fetch_PC
  val commit_BTB_index = io.commit.bits.fetch_PC % BTBEntries.U

  dontTouch(BTB_entry_input)

  BTB_entry_input.valid   := 1.B
  BTB_entry_input.tag     := io.commit.bits.fetch_PC
  BTB_entry_input.target  := io.commit.bits.target
  BTB_entry_input.br_mask := io.commit.bits.br_mask
  BTB_entry_input.br_type := io.commit.bits.br_type

  when(io.commit.valid && io.commit.bits.T_NT){
    mem.write(commit_BTB_index, BTB_entry_input)
    valid_mem(commit_BTB_index) := 1.B
  }

  // OUTPUT

  val BTB_output = mem.read(s0_lookup_address)

  val hit = BTB_output.tag === s1_tag

  dontTouch(hit)

  io.BTB_output.bits := BTB_output
  io.BTB_output.valid := hit && s1_entry_valid



}
