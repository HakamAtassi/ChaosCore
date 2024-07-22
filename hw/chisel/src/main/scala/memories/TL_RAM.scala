/* ------------------------------------------------------------------------------------
* Filename: core_bus.scala
* Author: Hakam Atassi
* Date: July 20 2024
* Description: A TL-UL memory for simulation
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


class TL_RAM(sizeKB: Int) extends Module {
  val io = IO(new Bundle {
    // Inputs
    val request  = Flipped(Decoupled(new TileLink_Channel_A())) // Request
    // Outputs
    val response = Decoupled(new TileLink_Channel_D())          // Response
  })

  // Define the memory size and initialize the memory
  val memSize = sizeKB * 1024 / 32 // Convert size from KB to bytes and then to number of 256-bit words
  val mem = SyncReadMem(memSize, UInt(256.W))

  // Default values for the IO signals
  io.request.ready := true.B
  io.response.valid := false.B
  io.response.bits := 0.U.asTypeOf(new TileLink_Channel_D)

  when(io.request.fire) {
    val addr = io.request.bits.a_address >> 5 // Assuming address is byte-aligned, shift right to get word-aligned (256 bits = 32 bytes)

    when(io.request.bits.a_opcode === 0.U) { // Read operation
      val readData = mem.read(addr)
      io.response.valid := true.B
      io.response.bits.d_opcode := 0.U // Read response
      io.response.bits.d_param := 0.U
      io.response.bits.d_size := io.request.bits.a_size
      io.response.bits.d_source := io.request.bits.a_source
      io.response.bits.d_sink := 0.U // Not used in this simple example
      io.response.bits.d_data := readData
    }.elsewhen(io.request.bits.a_opcode === 1.U) { // Write operation
      when(io.request.bits.a_mask === "b11111111111111111111111111111111".U) { // Assuming full 256-bit write
        mem.write(addr, io.request.bits.a_data)
      }
      io.response.valid := true.B
      io.response.bits.d_opcode := 1.U // Write acknowledgment
      io.response.bits.d_param := 0.U
      io.response.bits.d_size := io.request.bits.a_size
      io.response.bits.d_source := io.request.bits.a_source
      io.response.bits.d_sink := 0.U // Not used in this simple example
      io.response.bits.d_data := 0.U // No data for write acknowledgment
    }
  }

}
