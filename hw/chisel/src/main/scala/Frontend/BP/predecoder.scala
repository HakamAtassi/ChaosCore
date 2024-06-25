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


object PredecoderState extends ChiselEnum{
    val Active, Idle, Revert = Value
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
        // FLUSH
        val flush               = Input(Bool())

        // inputs
        val prediction          = Flipped(Decoupled(new prediction(parameters)))
        val fetch_packet        = Flipped(Decoupled(new fetch_packet(parameters)))
        val RAS_read            = Flipped(new RAS_read(parameters))
        val commit              = Input(new commit(parameters))

        // outputs
        val GHR                 = Output(UInt(GHRWidth.W))

        val final_fetch_packet  = Decoupled(new fetch_packet(parameters))              // Output validated instructions
        val RAS_update          = Output(new RAS_update)                               // RAS control

        // TO FTQ //
        val predictions         = Decoupled(new FTQ_entry(parameters))
    })

    dontTouch(io)

    ///////////////////
    // BRANCH DECODE //
    ///////////////////

    
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


    ////////////////
    // RAS UPDATE //
    ////////////////

    // If dominant branch is a Call or Ret, request a RAS update. 

    var dominant_branch_index = 0
    for(i <- fetchWidth-1 to 0){
        when(decoder_T_NT(i)){
            dominant_branch_index = i
        }
    }

    val dominant_branch_metadata = decoder_metadata(dominant_branch_index)


    // RAS Control //
    io.RAS_update.ret        := dominant_branch_metadata.br_type === _br_type.RET
    io.RAS_update.call       := dominant_branch_metadata.br_type === _br_type.CALL

    io.RAS_update.call_addr  := dominant_branch_metadata.instruction_PC // PC of the actual instruction, not fetch_PC



    ////////////////
    // GHR UPDATE //
    ////////////////

    val GHR = RegInit(UInt(GHRWidth.W), 0.U)
    val has_control           = Wire(Bool())

    has_control := decoder_metadata.map(_.is_control).reduce(_ || _)


    // if dominant instruction is a taken branch
    // GHR is updated with T/NT regardless of where that T/NT came from
    // However, the fetch packet must have a control instruction of some sort for that T/NT bit to be relavent
    io.GHR := GHR

    when(has_control){
        io.GHR := (GHR << 1) | decoder_T_NT.asUInt.orR
    }

    GHR := io.GHR

    when(io.commit.is_misprediction){
        GHR := io.commit.GHR
    }


    ////////////////
    // FTQ OUTPUT //
    ////////////////

    val push_FTQ = Wire(Bool())

    // Send predictions to FTQ

    push_FTQ := decoder_metadata.map(_.is_control).reduce(_ || _)


    io.predictions.valid                              := push_FTQ

    // Buffer branch state
    io.predictions.bits.fetch_PC                      := io.fetch_packet.bits.fetch_PC
    io.predictions.bits.GHR                           := GHR
    io.predictions.bits.NEXT                          := io.RAS_read.NEXT
    io.predictions.bits.TOS                           := io.RAS_read.TOS


    io.predictions.bits.dominant_index                := (fetchWidth-1).U                        // Set to lowest priority 
    io.predictions.bits.resolved_PC                   := io.fetch_packet.bits.fetch_PC + (fetchWidth.U*4.U)  // Default to next PC (assume no branches taken)

    // Init FTQ entry data
    io.predictions.bits.T_NT                          := decoder_T_NT.asUInt.orR
    when(io.predictions.bits.T_NT){
        io.predictions.bits.predicted_PC              := io.prediction.bits.target
    }.otherwise{
        io.predictions.bits.predicted_PC              := io.fetch_packet.bits.fetch_PC + (fetchWidth.U*4.U)
    }
    io.predictions.bits.valid                         := 0.B
    io.predictions.bits.is_misprediction              := 0.B
    //io.predictions.bits.RAT_IDX                       := DontCare   // FIXME: 
    io.predictions.bits.br_type                       := dominant_branch_metadata.br_type


    ////////////////////////
    // INSTRUCTION OUTPUT //
    ////////////////////////

    // "validator"
    val decoder_validator = Module(new decoder_validator(fetchWidth=fetchWidth))
    val T_NT_mask = RegNext(decoder_T_NT.asUInt)
    decoder_validator.io.instruction_T_NT_mask := T_NT_mask // FIXME: T_NT should not be set for uncond branches if not in btb...


    val offset_validity = Wire(UInt(4.W))
    offset_validity := 0.U  // FIXME: this is hardcoded...
    val test = io.fetch_packet.bits.fetch_PC & 0xF.U
    when(test === 0x0.U){offset_validity := "b1111".U}
    when(test === 0x4.U){offset_validity := "b1110".U}
    when(test === 0x8.U){offset_validity := "b1100".U}
    when(test === 0xA.U){offset_validity := "b1000".U}



    // ASSIGN FINAL FETCH PACKET //
    io.final_fetch_packet.valid := RegNext(io.fetch_packet.valid && !io.flush)
    io.final_fetch_packet.bits.fetch_PC := RegNext(io.fetch_packet.bits.fetch_PC)
    
    for(i <- 0 until fetchWidth){
        io.final_fetch_packet.bits.instructions(i) := RegNext(io.fetch_packet.bits.instructions(i))                                     // pass instructions
        io.final_fetch_packet.bits.valid_bits(i)   := RegNext(decoder_validator.io.instruction_validity(i) && offset_validity(i)) && io.final_fetch_packet.valid     // pass valid bits
    }

    io.prediction.ready   := (io.final_fetch_packet.ready && io.predictions.ready)
    io.fetch_packet.ready := (io.final_fetch_packet.ready && io.predictions.ready)

}