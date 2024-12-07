/* ------------------------------------------------------------------------------------
 * Filename: instruction_fetch.scala
 * Author: Hakam Atassi
 * Date: Mar 12 2024
 * Description: The components of the frontend that generate the stream of (raw) instructions
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

class instruction_fetch_v2(coreParameters: CoreParameters) extends Module {
  import coreParameters._

  val dataSizeBits = L1_cacheLineSizeBytes * 8

  val io = IO(new Bundle {

    val commit = Flipped(ValidIO(new commit(coreParameters)))
    val revert = ValidIO(new revert(coreParameters))

    // TO I$
    val memory_request = Decoupled(new frontend_memory_request(coreParameters))
    val memory_response = Flipped(Decoupled(new fetch_packet(coreParameters))) // TO CPU

    // OUTPUT
    val fetch_packet = Decoupled(
      new fetch_packet(coreParameters)
    ) // Fetch packet result (To Decoders)

    // FLUSH
    val flush = Flipped(ValidIO(new flush(coreParameters)))

  })

  ///////////
  // INITS //
  ///////////
  io.revert := DontCare
  io := DontCare

  val gshare = Module(new gshare(coreParameters))
  val BTB = Module(new hash_BTB(coreParameters))
  //val RAS = Module(new RAS(coreParameters))

  val PC_next = RegInit(UInt(32.W), startPC.asUInt)
  val replay_PC = RegInit(UInt(32.W), startPC.asUInt)
  val first_req = RegInit(Bool(), 1.B)
  val GHR = RegInit(UInt(GHRWidth.W), 0.U)

  first_req := 0.B

  /////////////
  // STAGE 0 //
  /////////////

  // GENERATE PC

  val is_branch =  WireInit(Bool(), 0.B) //(io.prediction.bits.br_type === br_type_t.BR) && io.prediction.valid
  val is_jalr =    WireInit(Bool(), 0.B) //(io.prediction.bits.br_type === br_type_t.JALR) && io.prediction.valid
  val is_ret =     WireInit(Bool(), 0.B) //(io.prediction.bits.br_type === br_type_t.RET) && io.prediction.valid
  val use_BTB =    WireInit(Bool(), 0.B) //(io.prediction.bits.hit && io.prediction.valid && !is_ret)
  val use_RAS =    WireInit(Bool(), 0.B) //is_ret
  //flushing_event := io.flush.valid || is_revert


  when(use_BTB && (first_req || io.memory_response.fire)) {
    PC_next := 0.U //io.prediction.bits.target
  }.elsewhen(use_RAS && (first_req || io.memory_response.fire)) {
    PC_next := 0.U //io.RAS_read.ret_addr
  }.elsewhen((first_req || io.memory_response.fire)) {
    PC_next := PC_next + (fetchWidth * 4).U
  }.otherwise{
    PC_next := PC_next
  }

  dontTouch(PC_next)

  /////////////
  // STAGE 1 //
  /////////////

  replay_PC := Mux((io.memory_response.fire || first_req), PC_next, replay_PC)

  // Access I$
  dontTouch(io)

  io.memory_response.ready    := RegNext(io.memory_request.valid)
  io.memory_request.bits.addr := Mux((io.memory_response.fire || first_req), PC_next, replay_PC)
  io.memory_request.valid := 1.B


  // Access pred structures (BTB/GSHARE)
  gshare.io.predict_GHR     := GHR
  gshare.io.predict_PC      := PC_next
  gshare.io.predict_valid   := 1.B
  gshare.io.commit          := io.commit
  
  BTB.io.predict_PC                          := PC_next
  BTB.io.predict_valid                       := 1.B
  BTB.io.commit                              := io.commit

  /////////////
  // STAGE 2 //
  /////////////

  // Pre-decode instructions
  // construct prediction based on BTB and gshare


  io.fetch_packet.bits.fetch_PC := PC_next

  io.fetch_packet <> io.memory_response

  io.fetch_packet.bits.prediction := DontCare
  io.fetch_packet.bits.GHR := GHR
  io.fetch_packet.bits.NEXT := 0.U
  io.fetch_packet.bits.TOS := 0.U

}
