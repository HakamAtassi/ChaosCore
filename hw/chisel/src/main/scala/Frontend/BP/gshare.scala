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
    val addrA = Input(UInt(log2Ceil(depth).W))

    // read port 2 (commit)
    val addrB = Input(UInt(log2Ceil(depth).W))

    // write port 1 (commit)
    val addrC = Input(UInt(log2Ceil(depth).W))
    val writeDataB = Input(UInt(width.W))
    val writeEnableB = Input(Bool())
    val readDataB = Output(UInt(width.W))
  })


  // Create the true dual-port memory
  val mem = SyncReadMem(depth, UInt(width.W))


  // Operations for Port A
  io.readDataA := mem.read(io.addrA, io.writeEnableA)

  io.readDataB := mem.read(io.addrB, io.writeEnableB)


  // Operations for Port C
  when(io.writeEnableB) {
    mem.write(io.addrB, io.writeDataB)
  }
}

class ghsare(GHRBits:Int = 15) extends Module{
    // the ghsare must be addressable by the number of bits in the global history register

    val io = IO(new Bundle{

        // prediction port
        val predict_GHR     = Input(UInt(GHRBits.W))
        val predict_PC      = Input(UInt(32.W))
        val predict_valid   = Input(Bool())

        // prediction output
        val T_NT  = Output(Bool())
        val valid = Output(Bool())

        // commit port
        val commit_GHR         = Input(UInt(GHRBits.W))
        val commit_PC          = Input(UInt(32.W))
        val commit_valid       = Input(Bool())
        
    })


    ////////////////
    // PHT memory //     
    ////////////////

    val prediction_state = Wire(UInt(2.W))
    val commit_state     = Wire(UInt(2.W))
    val commit_state_updated     = Wire(UInt(2.W))

    val hashed_predict_addr = Wire(UInt(GHRBits.W))
    val hashed_commit_addr = Wire(UInt(GHRBits.W))

    val PHT = PHT_memory(depth=(2<<GHRBits), width=2)


    hashed_predict_addr := io.predict_PC(GHRBits-1, 0) ^ prediction_GHR
    hashed_commit_addr  := io.commit_PC(GHRBits-1, 0) ^ commit_GHR


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
    PHT.io.writeDataA := commit_state_updated
    PHT.io.writeEnableA := RegNext(io.commit_valid) 

    /////////
    // FSM // 
    /////////

    when(RegNext(io.commit_branch_direction) == 1.U){
        when(commit_state < 3.U){
            commit_state_updated := commit_state + 1.U
        }.otherwise{
            commit_state_updated := commit_state
        }
    }.otherwise{
        when(commit_state > 0.U){
            commit_state_updated := commit_state - 1.U
        }.otherwise{
            commit_State_updated := commit_state
        }
    }

}