/* ------------------------------------------------------------------------------------
* Filename: ghsare.scala
* Author: Hakam Atassi
* Date: Apr 19 2024
* Description: A gshare PHT. 
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

import chisel3._
import circt.stage.ChiselStage
import chisel3.util._
import java.io.{File, FileWriter}
import java.rmi.server.UID


class PHT_memory(depth: Int, width: Int) extends Module {
    // FIXME: Ensure this is write first ...
    // 2 read 1 write memory
  val io = IO(new Bundle {
    // read port 1 (predict)
    val addrA           = Input(UInt(log2Ceil(depth).W))
    val readDataA       = Output(UInt(log2Ceil(depth).W))

    // read port 2 (commit)
    val addrB           = Input(UInt(log2Ceil(depth).W))
    val readDataB       = Output(UInt(log2Ceil(depth).W))

    // write port 1 (commit)
    val addrC           = Input(UInt(log2Ceil(depth).W))
    val writeDataC      = Input(UInt(width.W))
    val writeEnableC    = Input(Bool())
  })

  // Create the true dual-port memory
  val mem = SyncReadMem(depth, UInt(width.W))

  io.readDataA := mem.read(io.addrA)
  io.readDataB := mem.read(io.addrB)

  // Operations for Port C
  when(io.writeEnableC) {
    mem.write(io.addrC, io.writeDataC)
  }
}

class gshare(GHR_width:Int = 16) extends Module{
    // the ghsare must be addressable by the number of bits in the global history register

    val io = IO(new Bundle{

        // prediction port
        val predict_GHR     = Input(UInt(GHR_width.W))
        val predict_PC      = Input(UInt(32.W))
        val predict_valid   = Input(Bool())

        // prediction output
        val T_NT  = Output(Bool())
        val valid = Output(Bool())

        // commit port
        val commit_GHR         = Input(UInt(GHR_width.W))
        val commit_PC          = Input(UInt(32.W))
        val commit_valid       = Input(Bool())
        val commit_branch_direction       = Input(Bool())
        
    })


    ////////////////
    // PHT memory //     
    ////////////////

    val prediction_state = Wire(UInt(2.W))
    val commit_state     = Wire(UInt(2.W))
    val commit_state_updated     = Wire(UInt(2.W))

    val hashed_predict_addr = Wire(UInt(GHR_width.W))
    val hashed_commit_addr = Wire(UInt(GHR_width.W))

    val PHT = Module(new PHT_memory(depth=(1<<GHR_width), width=2))


    hashed_predict_addr := io.predict_PC(GHR_width-1, 0) ^ io.predict_GHR
    hashed_commit_addr  := io.commit_PC(GHR_width-1, 0) ^ io.commit_GHR

    dontTouch(hashed_predict_addr)
    dontTouch(hashed_commit_addr)

    // Read and generate prediction
    PHT.io.addrA := hashed_predict_addr
    prediction_state := PHT.io.readDataA 

    io.T_NT := prediction_state(1)
    io.valid := RegNext(io.predict_valid)

    // Read and update state
    PHT.io.addrB := hashed_commit_addr
    commit_state := PHT.io.readDataB 

    // Write updated data
    PHT.io.addrC := RegNext(hashed_commit_addr)
    PHT.io.writeDataC := commit_state_updated
    PHT.io.writeEnableC := RegNext(io.commit_valid) 

    /////////
    // FSM // 
    /////////

    when(RegNext(io.commit_branch_direction) === 1.U){
        when(commit_state < 3.U){
            commit_state_updated := commit_state + 1.U
        }.otherwise{
            commit_state_updated := commit_state
        }
    }.otherwise{
        when(commit_state > 0.U){
            commit_state_updated := commit_state - 1.U
        }.otherwise{
            commit_state_updated := commit_state
        }
    }

}