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

class instruction_fetch_v3(coreParameters: CoreParameters) extends Module {
  import coreParameters._

  val dataSizeBits = L1_cacheLineSizeBytes * 8

  val io = IO(new Bundle {

    val commit = Flipped(ValidIO(new commit(coreParameters)))
    val revert = ValidIO(new revert(coreParameters))

    // TO I$
    val memory_request = Decoupled(new frontend_memory_request(coreParameters))
    val memory_response = Flipped(Decoupled(new fetch_packet(coreParameters))) // TO CPU

    // OUTPUT
    val fetch_packet = Decoupled(new fetch_packet(coreParameters)) // Fetch packet result (To Decoders)

    // FLUSH
    val flush = Flipped(ValidIO(new flush(coreParameters)))

  }); dontTouch(io)


  // PREDICTION STRUCTURES
  val gshare = Module(new gshare(coreParameters))
  val BTB = Module(new hash_BTB(coreParameters))
  //val RAS = Module(new RAS(coreParameters))
  val GHR = RegInit(UInt(GHRWidth.W), 0.U)

  val prediction = WireInit(0.U.asTypeOf(new prediction(coreParameters)))

  val PC = WireInit(UInt(32.W), 0.U)
  val next_PC = RegInit(UInt(32.W), startPC)
  val prev_PC = RegInit(UInt(32.W), 0.U)


  val s0_request = WireInit(false.B)
  val s0_request_addr = WireInit(0.U(32.W))

  val s1_requested = WireInit(false.B)
  val s1_hit = WireInit(false.B)
  val s1_miss = WireInit(false.B)
  val s1_request_addr = RegInit(UInt(32.W), startPC)
  val s1_replay = WireInit(false.B)

  val s1_BTB_hit = WireInit(false.B)


  BTB.io.commit                              <> io.commit
  gshare.io.GHR             := GHR
  gshare.io.commit          := io.commit


  ////////////////////////
  // S0 - Read memories //
  ////////////////////////
  s0_request := 1.B && !reset.asBool

  s0_request_addr := next_PC      // s0 just requests the PC register, which stores the next desired fetch PC

  
  // request I$ //
  io.memory_request.valid := s0_request
  io.memory_request.bits.addr := s0_request_addr

  // request BTB //
  BTB.io.predict_PC         := s0_request_addr
  gshare.io.predict_PC      := s0_request_addr % BTBEntries.U

  // update s0 next PC
  next_PC := s0_request_addr + get_PC_increment(coreParameters, io.memory_request.bits.addr)


  ////////////////////
  // S1 - UPDATE PC //
  ////////////////////

  s1_requested := RegNext(s0_request)

  s1_hit := s1_requested && io.memory_response.valid 
  s1_miss := s1_requested && !io.memory_response.valid

  s1_replay := s1_miss || (s1_hit && !io.fetch_packet.fire) // replay if request missed, or it hit but wasnt accepted

  // update s1_addr
  when(!s1_replay){
    s1_request_addr := io.memory_request.bits.addr
  }

  // replay request as needed
  when(s1_replay){
    s0_request_addr := s1_request_addr
  }

  s1_BTB_hit := s1_requested && BTB.io.BTB_output.valid
  

  /////////////////////////////
  // CONSTRUCTION PREDICTION // 
  /////////////////////////////

  prediction.hit     := s1_BTB_hit         // BTB hit
  prediction.T_NT    := gshare.io.T_NT && s1_BTB_hit && !s1_replay && (BTB.io.BTB_output.bits.br_mask >=  RegNext(s0_request_addr / 4.U)  % (fetchWidth.U)) // GSHARE T/NT
  //prediction.T_NT    := 1.B && s1_BTB_hit && !s1_replay && (BTB.io.BTB_output.bits.br_mask >=  RegNext(s0_request_addr / 4.U)  % (fetchWidth.U)) // GSHARE T/NT
  //prediction.T_NT := 0.B
  prediction.br_type := BTB.io.BTB_output.bits.br_type


  when(prediction.T_NT && BTB.io.BTB_output.valid){
    prediction.target  := BTB.io.BTB_output.bits.target
    prediction.br_mask := BTB.io.BTB_output.bits.br_mask
    s0_request_addr    := prediction.target
  }.otherwise{
    prediction.target := get_fetch_packet_aligned_address(coreParameters, io.memory_response.bits.fetch_PC) + fetchWidth.U*4.U
    prediction.br_mask := 0.U
  }


  when(s1_BTB_hit && !s1_replay && (BTB.io.BTB_output.bits.br_mask >=  RegNext(s0_request_addr / 4.U)  % (fetchWidth.U))){
    GHR := (GHR << 1) | prediction.T_NT
  }





  ///////////////////
  // ASSIGN OUTPUT //
  ///////////////////

  io.fetch_packet <> io.memory_response
  io.fetch_packet.bits.fetch_PC := (get_fetch_packet_aligned_address(coreParameters, io.memory_response.bits.fetch_PC))


  for(i <- 0 until fetchWidth){
    io.fetch_packet.bits.instructions(i).packet_index := i.U
    
    // ignore things before the start of the packet
    // ignore things after the assumed prediction 
    io.fetch_packet.bits.valid_bits(i):=  (i.U >= (RegNext(s0_request_addr / 4.U)  % (fetchWidth.U))) && 
                                          ((i.U <= prediction.br_mask) || !prediction.T_NT) && 
                                          io.memory_response.valid
  }

  io.fetch_packet.valid     := io.memory_response.valid && !io.flush.valid 

  io.revert := DontCare
  io.memory_request.bits.wr_data := 0.U
  io.memory_request.bits.wr_en := 0.B

  if(speculative){
    io.fetch_packet.bits.prediction := prediction
    io.fetch_packet.bits.GHR := GHR
    
    io.fetch_packet.bits.NEXT := 0.U  // RAS stuff
    io.fetch_packet.bits.TOS := 0.U
  }else{
    io.fetch_packet.bits.prediction := DontCare
    io.fetch_packet.bits.GHR := DontCare
    io.fetch_packet.bits.NEXT := 0.U
    io.fetch_packet.bits.TOS := 0.U
  }


  // flush
  when(io.flush.valid){ 
    s0_request := 0.B
    s1_replay := 0.B
    next_PC := io.flush.bits.redirect_PC
    io.fetch_packet.valid := 0.B  // invalidate output
  }



  dontTouch(prediction)
  dontTouch(s0_request)
  dontTouch(s0_request_addr)
  dontTouch(s1_replay)
  dontTouch(s1_requested)
  dontTouch(s1_hit)
  dontTouch(s1_miss)

}