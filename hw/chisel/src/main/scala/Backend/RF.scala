/* ------------------------------------------------------------------------------------
* Filename: RF.scala
* Author: Hakam Atassi
* Date: May 22 2024
* Description: The "merged" register files. 
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
import getPortCount._

import chisel3.experimental._ 

// Define the BlackBox module
// FIXME: make sure this RF actually has 65 regs (0, 64)
class nReadmWrite extends BlackBox with HasBlackBoxResource {
  val io = IO(new Bundle {

    val clock = Input(Clock())
    val reset = Input(Bool())

    val raddr_0 = Input(UInt(7.W))
    val raddr_1 = Input(UInt(7.W))
    val raddr_2 = Input(UInt(7.W))
    val raddr_3 = Input(UInt(7.W))
    val raddr_4 = Input(UInt(7.W))
    val raddr_5 = Input(UInt(7.W))
    val raddr_6 = Input(UInt(7.W))
    val raddr_7 = Input(UInt(7.W))
    val rdata_0 = Output(UInt(32.W))
    val rdata_1 = Output(UInt(32.W))
    val rdata_2 = Output(UInt(32.W))
    val rdata_3 = Output(UInt(32.W))
    val rdata_4 = Output(UInt(32.W))
    val rdata_5 = Output(UInt(32.W))
    val rdata_6 = Output(UInt(32.W))
    val rdata_7 = Output(UInt(32.W))
    val waddr_0 = Input(UInt(7.W))
    val waddr_1 = Input(UInt(7.W))
    val waddr_2 = Input(UInt(7.W))
    val waddr_3 = Input(UInt(7.W))
    val wen_0 = Input(Bool())
    val wen_1 = Input(Bool())
    val wen_2 = Input(Bool())
    val wen_3 = Input(Bool())
    val wdata_0 = Input(UInt(32.W))
    val wdata_1 = Input(UInt(32.W))
    val wdata_2 = Input(UInt(32.W))
    val wdata_3 = Input(UInt(32.W))
  })

  // Reference the external Verilog file
  addResource("/nReadmWrite.v")
}


// a simulation version of the nReadmWrite memory 
// because LVT memories are hard to read during debug
class sim_nReadmWrite(coreParameters:CoreParameters) extends Module {
  import coreParameters._

  val io = IO(new Bundle {

    val raddr = Input(Vec(portCount*2, UInt(physicalRegBits.W)))
    val rdata = Output(Vec(portCount*2, UInt(32.W)))

    val waddr = Input(Vec(portCount, UInt(physicalRegBits.W)))
    val wen   = Input(Vec(portCount, Bool()))
    val wdata = Input(Vec(portCount, UInt(32.W)))
  })

  val mem = SyncReadMem(physicalRegCount, UInt(32.W))

  // Write ports
  for(i <- 0 until portCount){
    when(io.wen(i)){
      val data = Mux(io.waddr(i) === 0.U, 0.U, io.wdata(i))
      mem.write(io.waddr(i), data)
    }
  }


  // Read ports
  for(i <- 0 until portCount*2){
    io.rdata(i) := mem.read(io.raddr(i))
  }
}