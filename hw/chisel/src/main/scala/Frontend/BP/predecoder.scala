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


object latchExpectedPC extends ChiselEnum{
    val wire_wire, wire_reg = Value
}

object validate_packet extends ChiselEnum{
    val packet_invalid, packet_valid = Value
}

// FIXME: make this N wide parameterizable
class decoder_validator(fetchWidth: Int) extends Module {
  val io = IO(new Bundle {
    val instruction_T_NT_mask = Input(UInt(fetchWidth.W))
    val instruction_validity = Output(UInt(fetchWidth.W))
  })

  // Define LUTs for different fetchWidth sizes
  val lut4 = VecInit(Seq(
    "b0001".U(fetchWidth.W),
    "b0011".U(fetchWidth.W),
    "b0111".U(fetchWidth.W),
    "b1111".U(fetchWidth.W)
  ))

  val lut2 = VecInit(Seq(
    "b10".U(fetchWidth.W),   // Validity mask for pattern 01 -> 01
    "b11".U(fetchWidth.W)  // Validity mask for pattern 10 -> 10
  ))

  val lut = if (fetchWidth == 4) lut4 else lut2

  io.instruction_validity := lut(PriorityEncoder(io.instruction_T_NT_mask))
}

class predecoder(parameters:Parameters) extends Module{
    import parameters._

    val io = IO(new Bundle{
        // inputs
        val prediction          = Flipped(Decoupled(new prediction(parameters)))
        val fetch_packet        = Flipped(Decoupled(new fetch_packet(parameters)))
        val RAS_read            = Flipped(new RAS_read(parameters))


        val commit              = Input(new commit(parameters))

        // outputs
        val revert              = Decoupled(new revert(parameters))                    // Redirect frontend 
        val GHR                 = Output(UInt(GHRWidth.W))

        val final_fetch_packet  = Decoupled(new fetch_packet(parameters))              // Output validated instructions
        val RAS_update          = Output(new RAS_update)                               // RAS control

        // TO FTQ //
        val predictions         = Decoupled(new FTQ_entry(parameters))
    })

    /////////////
    // STAGE 1 //
    /////////////
    
    // Assign decoders register outputs
    // Assign decoders in first stage

    val decoders: Seq[branch_decoder] = Seq.tabulate(fetchWidth) { w =>
        Module(new branch_decoder(index=w, parameters))
    }

    val decoder_metadata         = Wire(Vec(fetchWidth, new metadata()))
    val decoder_T_NT             = Wire(Vec(fetchWidth, Bool()))

    val inputs_valid             = Wire(Bool())
    inputs_valid    := io.fetch_packet.valid && io.prediction.valid         // Are both inputs valid?

    for(i <- 0 until fetchWidth){
        // Inputs
        decoders(i).io.fetch_PC         :=  io.fetch_packet.bits.fetch_PC
        decoders(i).io.instruction      :=  io.fetch_packet.bits.instructions(i).instruction
        decoders(i).io.valid            :=  io.fetch_packet.bits.valid_bits(i)
        decoders(i).io.prediction       <>  io.prediction
        decoders(i).io.RAS_read         :=  io.RAS_read
        // Outputs
        decoder_metadata(i)             :=  decoders(i).io.metadata
        decoder_T_NT(i)                 :=  decoders(i).io.T_NT
    }

    val metadata_reg = Reg(Vec(fetchWidth, new metadata()))
    val T_NT_reg     = Reg(Vec(fetchWidth, Bool()))
    val GHR_reg      = Reg(UInt(GHRWidth.W))

    T_NT_reg := decoder_T_NT
    metadata_reg := decoder_metadata
    //GHR_reg := (io.prediction.bits.GHR << 1) | io.prediction.T_NT

    /////////////
    // STAGE 2 //
    /////////////

    // Select dominant branch; select expected PC
    // Control RAS
    // Validate instructions
    // Assign outputs
    
    val metadata_out    = Wire(new metadata())

    val dominant_index = Wire(UInt(log2Ceil(fetchWidth).W))

    // assign default value to metadata
    metadata_out := 0.U.asTypeOf(new metadata())
    dominant_index:= (fetchWidth-1).U
    for(i <- fetchWidth-1 to 0 by - 1){
        when(T_NT_reg(i) === 1.B){
            metadata_out := metadata_reg(i)
            dominant_index:= i.U
        }
    }

    /////////
    // FSM //
    /////////

    val PC_next      = Wire(UInt(32.W))
    val PC_next_reg  = RegInit(UInt(32.W), startPC)
    val PC_expected  = Wire(UInt(32.W))
    //val packet_valid = Wire(Bool())

    val PC_mismatch  = Wire(Bool())
    val PC_match     = Wire(Bool())

    PC_match        := (PC_expected === io.fetch_packet.bits.fetch_PC) && inputs_valid
    PC_mismatch     := (PC_expected =/= io.fetch_packet.bits.fetch_PC) && inputs_valid


    //io.kill              := PC_mismatch
    io.revert.valid      := PC_mismatch
    io.revert.bits.GHR   := GHR_reg // FIXME: what??
    io.revert.bits.PC    := PC_expected

    ///////////////
    // GHR LOGIC //
    ///////////////

    val GHR = RegInit(UInt(GHRWidth.W), 0.U)

    val has_control          = Wire(Bool())
    val dominant_control_type = Wire(_br_type())

    has_control := 0.B
    dominant_control_type :=  _br_type.NONE

    for(i <- 0 until fetchWidth){
        when((metadata_reg(i).br_type === _br_type.BR) || (metadata_reg(i).br_type === _br_type.JAL) || (metadata_reg(i).br_type === _br_type.JALR)
            || (metadata_reg(i).br_type === _br_type.CALL) || (metadata_reg(i).br_type === _br_type.RET)){
            has_control := 1.B
            dominant_control_type :=  metadata_reg(i).br_type
        }
    }

    // if dominant instruction is a taken branch
    // GHR is updated with T/NT regardless of where that T/NT came from
    // However, the fetch packet must have a control instruction of some sort for that T/NT bit to be relavent
    io.GHR := GHR

    when(has_control){
        io.GHR := (GHR << 1) | T_NT_reg.asUInt.orR
    }

    GHR := io.GHR

    when(io.commit.is_misprediction){
        GHR := io.commit.GHR
    }

    ///////////////////////////////////


    // Select PC based on metadata
    

    // If need BTB, use BTB (non ret JALR)
    // If need RAS, use RAS (Ret)
    // If need computed, use computed (BR)

    val use_BTB      = Wire(Bool())
    val use_RAS      = Wire(Bool())
    val use_computed = Wire(Bool())

    val stage_1_valid = Wire(Bool())
    stage_1_valid := io.fetch_packet.valid && !PC_mismatch
        

    use_BTB      := (metadata_out.br_type === _br_type.JALR) && (metadata_out.br_type =/= _br_type.RET)
    use_RAS      := (metadata_out.br_type === _br_type.RET)
    use_computed := (metadata_out.br_type === _br_type.BR) || (metadata_out.br_type === _br_type.JAL)


    when(io.commit.is_misprediction){PC_next := io.commit.expected_PC}
    .elsewhen(use_BTB){PC_next := metadata_out.BTB_target}
    .elsewhen(use_RAS){PC_next := metadata_out.RAS}
    .elsewhen(use_computed){PC_next := metadata_out.instruction_PC + metadata_out.Imm.asUInt}
    .otherwise{PC_next := RegNext(io.fetch_packet.bits.fetch_PC + (fetchWidth*4).U)} // FIXME: should this always be +16?

    PC_next_reg := Mux(RegNext(stage_1_valid), PC_next, PC_next_reg)
    PC_expected := Mux(RegNext(stage_1_valid), PC_next, PC_next_reg)


    when(io.commit.is_misprediction && io.commit.valid){
        PC_next_reg := io.commit.expected_PC
        PC_expected := io.commit.expected_PC
    }


    // validate instructions

    // "validator"
    // iterate and valid as you go along.
    val validate_flag = Wire(Bool())
    validate_flag := 1.B

    val T_NT_mask = decoder_T_NT.asUInt


    val decoder_validator = Module(new decoder_validator(fetchWidth=fetchWidth))
    decoder_validator.io.instruction_T_NT_mask := T_NT_mask

    for(i <- 0 until fetchWidth){
        io.final_fetch_packet.bits.instructions(i) := RegNext(io.fetch_packet.bits.instructions(i))    // pass along actual instruction
        io.final_fetch_packet.bits.valid_bits(i)   := RegNext(decoder_validator.io.instruction_validity(i)) && RegNext(inputs_valid)
    }


    io.final_fetch_packet.bits.fetch_PC := RegNext(io.fetch_packet.bits.fetch_PC)  // Pass along fetch PC
    // RAS Control //
    //io.RAS_update.call       := metadata_out.Call
    //io.RAS_update.ret        := metadata_out.Ret

    io.RAS_update.ret        := metadata_out.br_type === _br_type.RET
    io.RAS_update.call       := metadata_out.br_type === _br_type.CALL

    io.RAS_update.call_addr  := metadata_out.instruction_PC // PC of the actual instruction, not fetch_PC


    /////////
    // FTQ //
    /////////

    val push_FTQ = Wire(Bool())

    // Send predictions to FTQ
    push_FTQ := 0.B
    for(i <- 0 until fetchWidth){
        when((metadata_reg(i).br_type =/= _br_type.NONE) &&  io.final_fetch_packet.bits.valid_bits(i)){
            push_FTQ := 1.B
        }
    }

    io.predictions.valid                              := push_FTQ

    // Buffer branch state
    io.predictions.bits.fetch_PC                      := RegNext(io.fetch_packet.bits.fetch_PC)
    io.predictions.bits.GHR                           := GHR_reg
    io.predictions.bits.NEXT                          := RegNext(io.RAS_read.NEXT)
    io.predictions.bits.TOS                           := RegNext(io.RAS_read.TOS)
    io.predictions.bits.predicted_PC                  := PC_expected


    io.predictions.bits.dominant_index                := (fetchWidth).U                        // Set to lowest priority 
    io.predictions.bits.resolved_PC                   := RegNext(io.fetch_packet.bits.fetch_PC) + (fetchWidth.U*4.U)  // Default to next PC (assume no branches taken)

    // Init FTQ entry data
    io.predictions.bits.valid                         := 0.B
    io.predictions.bits.is_misprediction              := 0.B
    //io.predictions.bits.RAT_IDX                       := DontCare   // FIXME: 
    io.predictions.bits.T_NT                          := RegNext(T_NT_mask.orR)
    io.predictions.bits.br_type                       := metadata_out.br_type


    // Do not accept inputs if outputs have nowhere to go. 
    io.prediction.ready   := (io.final_fetch_packet.ready && io.predictions.ready && !PC_mismatch)
    io.fetch_packet.ready := (io.final_fetch_packet.ready && io.predictions.ready && !PC_mismatch)
    io.final_fetch_packet.valid := RegNext(inputs_valid && PC_match)
}