/* ------------------------------------------------------------------------------------
* Filename: predecoder.scala
* Author: Hakam Atassi
* Date: Apr 23 2024
* Description: A module resposible for controlling the RAS and validating the flow of instructions into the decoders/backend
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
import chisel3.ltl._

import helperFunctions._

class predecoder(coreParameters:CoreParameters) extends Module{
    import coreParameters._

    val io = IO(new Bundle{
        // FLUSH
        val flush               = Input(Bool())
        val revert              = ValidIO(new revert(coreParameters))

        // inputs
        val prediction          = Flipped(Decoupled(new prediction(coreParameters)))
        val fetch_packet        = Flipped(Decoupled(new fetch_packet(coreParameters)))
        val RAS_read            = Flipped(new RAS_read(coreParameters))
        val commit              = Flipped(ValidIO(new commit(coreParameters)))

        // outputs
        val predictions         = Decoupled(new FTQ_entry(coreParameters))                 // FTQ...
        val final_fetch_packet  = Decoupled(new fetch_packet(coreParameters))              // Output validated instructions

        val GHR                 = Output(UInt(GHRWidth.W))
        val RAS_update          = Output(new RAS_update)                               // RAS control
    })
    dontTouch(io)

    ////////////////////////
    // SKID BUFFER INPUTS //
    ////////////////////////
    val predictions_out         = Wire(Decoupled(new FTQ_entry(coreParameters)))
    val final_fetch_packet_out  = Wire(Decoupled(new fetch_packet(coreParameters)))

    val predictions_out_Q                      = Module(new Queue(new FTQ_entry(coreParameters), 2, flow=false, hasFlush=true, useSyncReadMem=false))
    val final_fetch_packet_out_Q               = Module(new Queue(new fetch_packet(coreParameters), 2, flow=false, hasFlush=true, useSyncReadMem=false))

    ///////////////////
    // BRANCH DECODE //
    ///////////////////
    // Determine dominant branch with instruction information
    val is_JAL                 =   Wire(Bool())
    val is_JALR                =   Wire(Bool())
    val is_BRANCH              =   Wire(Bool())
    val is_RET                 =   Wire(Bool())
    val is_CALL                =   Wire(Bool())

    is_JAL                     :=   0.B
    is_JALR                    :=   0.B
    is_BRANCH                  :=   0.B
    is_RET                     :=   0.B
    is_CALL                    :=   0.B

    // FIXME: no reset...    
    val dominant_branch_index           = Wire(UInt(log2Ceil(fetchWidth).W))
    val dominant_instruction            = Wire(UInt(32.W))
    val is_control                      = Wire(Vec(fetchWidth, Bool()))
    val T_NT                            = Wire(Vec(fetchWidth, Bool()))
    val final_fetch_packet_valid_bits   = Wire(Vec(fetchWidth, Bool()))

    dominant_branch_index               := fetchWidth.U - 1.U

    for(i <- fetchWidth-1 to 0 by -1){    // Get dominant index
        val instruction                 = io.fetch_packet.bits.instructions(i).instruction
        val opcode                      = instruction(6, 0)
        val RS1                         = instruction(19, 15)
        val RS2                         = instruction(24, 20)
        val RD                          = instruction(11, 7)
        val is_BTB_taken                = io.prediction.valid && io.prediction.bits.hit && io.prediction.bits.T_NT && io.fetch_packet.bits.valid_bits(i) && io.fetch_packet.valid

        val (instruction_type, valid)   = InstructionType.safe(opcode(6, 2))

        val curr_is_JAL                 = (instruction_type === InstructionType.JAL)     && io.fetch_packet.bits.valid_bits(i) && io.fetch_packet.valid
        val curr_is_JALR                = (instruction_type === InstructionType.JALR)    && io.fetch_packet.bits.valid_bits(i) && io.fetch_packet.valid
        val curr_is_BRANCH              = (instruction_type === InstructionType.BRANCH)  && io.fetch_packet.bits.valid_bits(i) && io.fetch_packet.valid
        val curr_is_RET                 = (is_JALR && (RD === 0.U) && (RS1 === 1.U)) // FIXME: this should maybe check for imm...
        val curr_is_CALL                = (is_JALR && (RD === 1.U)) || (is_JAL && (RD === 1.U))

        val is_taken                    = ((curr_is_BRANCH && is_BTB_taken) || curr_is_JALR || curr_is_JAL)

        T_NT(i) := is_taken
        when(is_taken){
            is_JAL      :=   curr_is_JAL
            is_JALR     :=   curr_is_JALR
            is_BRANCH   :=   curr_is_BRANCH
            is_RET      :=   curr_is_RET
            is_CALL     :=   curr_is_CALL
        }
        is_control(i) := curr_is_BRANCH || curr_is_JAL || curr_is_JALR
        when(is_taken){dominant_branch_index := i.U}
    }

    dominant_instruction := io.fetch_packet.bits.instructions(dominant_branch_index).instruction
    dontTouch(dominant_instruction)

    for(i <- 0 until fetchWidth){
        final_fetch_packet_valid_bits(i) := io.fetch_packet.valid && io.fetch_packet.bits.valid_bits(i) && !PopCount(T_NT.take(i))
    }

    ///////////////////////
    // TARGET GENERATION //
    ///////////////////////
    val target_address      = Wire(UInt(32.W))
    val dominantbr_type_t   = Wire(br_type_t())

    val imm  = Wire(UInt(32.W))
    imm     := 0.U

    val masked_addr = get_fetch_packet_aligned_address(coreParameters, io.fetch_packet.bits.fetch_PC)
    when(is_RET){
        // FROM RAS
        target_address := io.RAS_read.ret_addr
    }.elsewhen(is_JAL){
        // COMPUTED
        imm := sign_extend(getImm(dominant_instruction), 32)
        target_address := imm + masked_addr + (dominant_branch_index*4.U)
    }.elsewhen(is_JALR && io.prediction.bits.hit && io.prediction.valid){
        // FROM BTB (Assuming hit)
        target_address := io.prediction.bits.target
    }.elsewhen(is_BRANCH && io.prediction.bits.hit && io.prediction.valid){
        // FROM BTB (Assuming hit)
        target_address := io.prediction.bits.target
    }.otherwise{ 
        target_address := io.fetch_packet.bits.fetch_PC + get_PC_increment(coreParameters, io.fetch_packet.bits.fetch_PC)
    }

    dominantbr_type_t                      := br_type_t.NONE
    when(is_JAL)        {dominantbr_type_t := br_type_t.JAL}
    when(is_JALR)       {dominantbr_type_t := br_type_t.JALR}
    when(is_CALL)       {dominantbr_type_t := br_type_t.CALL}
    when(is_RET)        {dominantbr_type_t := br_type_t.RET}
    when(is_BRANCH)     {dominantbr_type_t := br_type_t.BR}

    ///////////////////////////
    // EXPECTED NEXT ADDRESS //
    ///////////////////////////
    val expected_next_PC            = RegInit(UInt(32.W), startPC)
    val input_fetch_packet_valid    = Wire(Bool())
    val input_valid                 = Wire(Bool())
    val output_ready                = Wire(Bool())
    val PC_match                    = Wire(Bool())
    val PC_mismatch                 = Wire(Bool())

    PC_match                       :=  expected_next_PC === io.fetch_packet.bits.fetch_PC
    PC_mismatch                    :=  expected_next_PC =/= io.fetch_packet.bits.fetch_PC

    input_valid                    :=  io.fetch_packet.fire    && 
                                       io.prediction.fire      && 
                                       !io.flush

    output_ready                    := io.final_fetch_packet.ready && io.predictions.ready 
    
    input_fetch_packet_valid        := (io.fetch_packet.fire && (io.prediction.fire || !io.prediction.valid)) && PC_match && !io.flush

    final_fetch_packet_out.valid    := input_fetch_packet_valid
    when(input_fetch_packet_valid && final_fetch_packet_out_Q.io.enq.ready){expected_next_PC := target_address}
    when(io.commit.valid && io.commit.bits.is_misprediction){expected_next_PC := io.commit.bits.fetch_PC}

    ////////////
    // REVERT //
    ////////////
    io.revert.valid := input_valid && PC_mismatch 
    io.revert.bits.PC := expected_next_PC

    ////////////////
    // GHR UPDATE //
    ////////////////
    val GHR = RegInit(UInt(GHRWidth.W), 0.U)

    io.GHR := GHR
    when(is_control.reduce(_ || _)){
        io.GHR := (GHR << 1) | T_NT.reduce(_ || _)
    }
    GHR := io.GHR
    when(io.commit.bits.is_misprediction){
        GHR := io.commit.bits.GHR
    }

    ////////////////
    // RAS UPDATE //
    ////////////////
    // RAS Control //
    io.RAS_update.ret        := is_RET  && input_fetch_packet_valid
    io.RAS_update.call       := is_CALL && input_fetch_packet_valid
    io.RAS_update.call_addr  := masked_addr + (dominant_branch_index*4.U) + 4.U

    //////////////////////////////////
    // GENERATE FINAL FETCH PACKET  //
    //////////////////////////////////
    // ASSIGN FINAL FETCH PACKET //
    final_fetch_packet_out.bits := io.fetch_packet.bits
    final_fetch_packet_out.bits.fetch_PC := masked_addr
    for(i <- 0 until fetchWidth){
        final_fetch_packet_out.bits.valid_bits(i) := io.fetch_packet.bits.valid_bits(i) && final_fetch_packet_valid_bits(i)
    }

    final_fetch_packet_out.bits.GHR                           := GHR
    final_fetch_packet_out.bits.NEXT                          := io.RAS_read.NEXT
    final_fetch_packet_out.bits.TOS                           := io.RAS_read.TOS

    /////////////////////////
    // GENERATE FTQ OUTPUT //
    /////////////////////////
    val push_FTQ = is_control.reduce(_ || _)

    predictions_out.ready                              := io.predictions.ready
    predictions_out.valid                              := push_FTQ && input_fetch_packet_valid

    // Buffer branch state
    predictions_out.bits.fetch_PC                      := io.fetch_packet.bits.fetch_PC

    predictions_out.bits.dominant_index                := (fetchWidth-1).U                                      // Set to lowest priority 
    predictions_out.bits.resolved_PC                   := io.fetch_packet.bits.fetch_PC + (fetchWidth.U*4.U)    // Default to next PC (assume no branches taken)

    // Init FTQ entry data
    predictions_out.bits.T_NT                          := T_NT.reduce(_ || _)
    when(predictions_out.bits.T_NT){
        predictions_out.bits.predicted_PC              := target_address
    }.otherwise{
        predictions_out.bits.predicted_PC              := io.fetch_packet.bits.fetch_PC + (fetchWidth.U*4.U)
    }
    predictions_out.bits.valid                         := 0.B
    predictions_out.bits.is_misprediction              := 0.B
    predictions_out.bits.br_type                       := dominantbr_type_t
    predictions_out.bits.ROB_index                     := 0.U


    //////////////////////
    // I/O SKID BUFFERS //
    //////////////////////
    // predecoded instruction & FTQ outputs passed through a skid buffer


    predictions_out_Q.io.enq                  <> predictions_out
    predictions_out_Q.io.deq                  <> io.predictions
    predictions_out_Q.io.deq.ready            := output_ready
    predictions_out_Q.io.flush.get            := io.flush

    final_fetch_packet_out_Q.io.enq           <> final_fetch_packet_out
    final_fetch_packet_out_Q.io.deq           <> io.final_fetch_packet
    final_fetch_packet_out_Q.io.deq.ready     := output_ready
    final_fetch_packet_out_Q.io.flush.get     := io.flush

    io.prediction.ready                       := RegNext(output_ready)
    io.fetch_packet.ready                     := RegNext(output_ready)






}