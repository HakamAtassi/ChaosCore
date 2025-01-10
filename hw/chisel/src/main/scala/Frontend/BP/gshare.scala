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

package ChaosCore

import chisel3._
import chisel3.util._
import java.io.{File, FileWriter}
import java.rmi.server.UID


class PHT_memory(depth: Int, width: Int) extends Module {
    // FIXME: Ensure this is write first ...
    // FIXME: This memory is NOT write first (as per validation, predict first then commit...)
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

class gshare(coreParameters:CoreParameters) extends Module{
    import coreParameters._
    // the ghsare must be addressable by the number of bits in the global history register

    val io = IO(new Bundle{

        // prediction port
        val GHR     = Input(UInt(GHRWidth.W))

        val predict_PC      = Input(UInt(32.W))


        // prediction output
        val T_NT            = Output(Bool())

        val commit      = Flipped(ValidIO(new commit(coreParameters)))
    })

    def update_state(state:UInt, T_NT:UInt): UInt = {
        val new_state = WireInit(0.U(2.W))
        when(T_NT === 1.U){
            when(state < 3.U){
                new_state := state + 1.U
            }.otherwise{
                new_state := state
            }
        }.otherwise{
            when(state > 0.U){
                new_state := state - 1.U
            }.otherwise{
                new_state := state
            }
        }
        new_state
    }


    ////////////////
    // PHT memory //     
    ////////////////

    // 2 read 1 write memory
    val mem = RegInit(VecInit(Seq.fill(BTBEntries)(0x2.U(2.W))))

    val hashed_addr = (io.GHR ^ io.predict_PC) % BTBEntries.U

    // generate output


    // UPDATE 
    // update whenever the commit has a branch, T or NT
    val update_addr = (io.commit.bits.fetch_PC ^ io.commit.bits.GHR) % BTBEntries.U
    when(io.commit.valid && io.commit.bits.br_type =/= br_type_t.NONE){
        mem(update_addr) := update_state(mem(update_addr), io.commit.bits.T_NT)
    }

    dontTouch(mem)


    io.T_NT := RegNext(mem(hashed_addr)(1))

}