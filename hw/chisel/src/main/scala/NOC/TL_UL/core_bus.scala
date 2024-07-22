/* ------------------------------------------------------------------------------------
* Filename: core_bus.scala
* Author: Hakam Atassi
* Date: July 20 2024
* Description: A small arbiting bus for connecting a core to the system bus. Uncached. Single core only.
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

// I$ ID == 0
// D$ ID == 1

class core_bus extends Module {
  val io = IO(new Bundle {
    // Inputs 
    val instruction_cache_A     = Flipped(Decoupled(new TileLink_Channel_A()))   // I$ Request
    val data_cache_A            = Flipped(Decoupled(new TileLink_Channel_A()))   // D$ Request
    val system_bus_D            = Flipped(Decoupled(new TileLink_Channel_D()))   // Bus granted request
                                
    // Outputs (Bus out)
    val instruction_cache_D     = Decoupled(new TileLink_Channel_D())   // D$ Response
    val data_cache_D            = Decoupled(new TileLink_Channel_D())   // I$ Response
    val system_bus_A            = Decoupled(new TileLink_Channel_A())   // Bus granted response
  })

  // FIXME: flushes?
  // INSTRUCTION CACHE QUEUE //
  val data_cache_queue          =  Module(new Queue(new TileLink_Channel_A(), 2, flow=true, hasFlush=false, useSyncReadMem=false))
  io.data_cache_A               <> data_cache_queue.io.enq

  // DATA CACHE QUEUE //
  val instruction_cache_queue   =  Module(new Queue(new TileLink_Channel_A(), 2, flow=true, hasFlush=false, useSyncReadMem=false))
  io.instruction_cache_A        <> instruction_cache_queue.io.enq


  // ROUND ROBIN OUTPUT //
  val arbiter = Module(new RRArbiter(new TileLink_Channel_A(), 2))

  // Connect the queues to the arbiter
  arbiter.io.in(0) <> data_cache_queue.io.deq
  arbiter.io.in(1) <> instruction_cache_queue.io.deq

  io.system_bus_A <> arbiter.io.out

  /////////////
  // RESPNSE //
  ////////////
  // FIXME: make the IDs params as needed
  io.instruction_cache_D <> 0.U.asTypeOf(Decoupled(new TileLink_Channel_D()))
  io.data_cache_D <> 0.U.asTypeOf(Decoupled(new TileLink_Channel_D()))

  io.system_bus_D.ready := 0.B
  when(io.system_bus_D.bits.d_source === 0.U){ // I$ response
    io.instruction_cache_D <> io.system_bus_D
  }.elsewhen(io.system_bus_D.bits.d_source === 1.U){ // D$ response
    io.data_cache_D <> io.system_bus_D
  }
  
}