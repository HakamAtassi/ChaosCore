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

import helperFunctions._

import chisel3.util.experimental.decode._

class branch_decode(coreParameters: CoreParameters) extends Module{
  val io = IO(new Bundle {

    val instruction      = Flipped(ValidIO(UInt(32.W)))

    val branch  = Output(Bool())
    val JAL     = Output(Bool())
    val JALR    = Output(Bool())
  }); dontTouch(io)



    val instruction = io.instruction.bits

    // Direct instruction fields
    val opcode      = instruction(6, 0)
    val RS1         = instruction(19, 15)
    val RS2         = instruction(24, 20)
    val PRD         = instruction(11, 7)
    val IMM         = getImm(instruction)

    val FUNCT3      = instruction(14, 12)
    val FUNCT7      = instruction(31, 25)

    // helper fields
    // "1" and "0" => are concatenated to a bit string which is then converted to an int
    // "?" is a dont care
    val Y = "1"
    val N = "0"
    val R_NONE = "?????"
    val FUNCT7_NONE = "???????"
    val FUNCT3_NONE = "???"
    val IMM_NONE = "????????????"

    // This decoder is inspired by how BOOM does things because they very elegantly use the Chisel Decode lib
    // to clean up the decode 


    def binString(n:UInt): String = {
        n.litValue.toString(2).reverse.padTo(n.getWidth, '0').reverse
    }


    val table = TruthTable(
            Map( // (Hint: Scroll right to see mappings)
            //                                                                                                                                                                                                                          // INSTRUCTION STEERING //                      
            //                                                                                                                                                                                                                          BRANCH
            //                                                                                                                                                                                                                          |   JAL
            //                                                                                                                                                                                                                          |   |   JALR
            //                                                                                                                                                                                                                          |   |   |   
            //                                                                                                                                                                                                                          |   |   |   |   
            //                                                                                                                                                                                                                          |   |   |   |   |   
            //                                                                                                                                                                                                                          |   |   |   |   |   |   
            //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       
            //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       
            //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       
            //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       
            //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       
            //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       
            //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       
            //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       
            //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       
            //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       
            //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       
            //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x0.U(3.W)) + R_NONE + s"${binString(InstructionType.BRANCH.litValue.U(5.W))}") -> BitPat("b" + Y + N + N + N + N + N + N),   // BEQ
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x1.U(3.W)) + R_NONE + s"${binString(InstructionType.BRANCH.litValue.U(5.W))}") -> BitPat("b" + Y + N + N + N + N + N + N),   // BNE
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x4.U(3.W)) + R_NONE + s"${binString(InstructionType.BRANCH.litValue.U(5.W))}") -> BitPat("b" + Y + N + N + N + N + N + N),   // BLT
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x5.U(3.W)) + R_NONE + s"${binString(InstructionType.BRANCH.litValue.U(5.W))}") -> BitPat("b" + Y + N + N + N + N + N + N),   // BGE
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x6.U(3.W)) + R_NONE + s"${binString(InstructionType.BRANCH.litValue.U(5.W))}") -> BitPat("b" + Y + N + N + N + N + N + N),   // BLTU
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x7.U(3.W)) + R_NONE + s"${binString(InstructionType.BRANCH.litValue.U(5.W))}") -> BitPat("b" + Y + N + N + N + N + N + N),   // BGEU
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + FUNCT3_NONE + R_NONE + s"${binString(InstructionType.JAL.litValue.U(5.W))}")              -> BitPat("b" + N + Y + N + N + N + N + N),   // JAL
            BitPat("b1"+ IMM_NONE + R_NONE + binString(0x0.U(3.W)) + R_NONE + s"${binString(InstructionType.JALR.litValue.U(5.W))}")               -> BitPat("b" + N + N + Y + N + N + N + N),   // JALR


        ),
        BitPat("b" + N + N + N + N + N + N + N)
    )

    //////////////////////////////////
    // READ OUT BITPATTERN & ASSIGN //
    //////////////////////////////////

    val decode_pat = decoder(Cat(io.instruction.valid, instruction(31, 2)), table)

    io.branch         := decode_pat(6)
    io.JAL            := decode_pat(5)
    io.JALR           := decode_pat(4)



}


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


  val branch_decoders: Seq[branch_decode] = Seq.tabulate(fetchWidth) { w =>
      Module(new branch_decode(coreParameters))
  }



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
  prediction.br_type := BTB.io.BTB_output.bits.br_type


  when(prediction.T_NT && BTB.io.BTB_output.valid){
    prediction.target  := BTB.io.BTB_output.bits.target
    prediction.br_mask := BTB.io.BTB_output.bits.br_mask
    s0_request_addr    := prediction.target
  }.otherwise{
    prediction.target := get_fetch_packet_aligned_address(coreParameters, io.memory_response.bits.fetch_PC) + fetchWidth.U*4.U
    prediction.br_mask := 0.U
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


    // connect branch decoder
    branch_decoders(i).io.instruction.bits    := io.memory_response.bits.instructions(i).instruction
    branch_decoders(i).io.instruction.valid   :=  (i.U >= (RegNext(s0_request_addr / 4.U)  % (fetchWidth.U))) && 
                                                  ((i.U <= prediction.br_mask) || !prediction.T_NT) && 
                                                  io.memory_response.valid
    
  }


  

  // update GHR
  //when(s1_BTB_hit && !s1_replay && (BTB.io.BTB_output.bits.br_mask >=  RegNext(s0_request_addr / 4.U)  % (fetchWidth.U))){
  when(branch_decoders.map(branch_decoder => branch_decoder.io.branch || branch_decoder.io.JAL || branch_decoder.io.JALR).reduce(_ || _)){
    GHR := (GHR << 1) | prediction.T_NT
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

    GHR := io.commit.bits.GHR
    when(io.flush.bits.is_misprediction){
      GHR := (io.commit.bits.GHR << 1) | io.flush.bits.T_NT
    }
  }



  dontTouch(prediction)
  dontTouch(s0_request)
  dontTouch(s0_request_addr)
  dontTouch(s1_replay)
  dontTouch(s1_requested)
  dontTouch(s1_hit)
  dontTouch(s1_miss)

}
