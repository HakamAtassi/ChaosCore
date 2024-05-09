/* ------------------------------------------------------------------------------------
* Filename: decode_validate.scala
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

class decode_validate(fetchWidth:Int,GHRWidth:Int, RASEntries:Int, startPC:UInt) extends Module{

    val io = IO(new Bundle{
        // inputs
        val prediction          = Flipped(Decoupled(new prediction(fetchWidth=fetchWidth, GHRWidth=GHRWidth)))
        val fetch_packet        = Flipped(Decoupled(new fetch_packet(fetchWidth=fetchWidth)))
        val RAS_read            = Flipped(new RAS_read(RASEntries=RASEntries))

        // outputs
        val kill                = Output(Bool())                                        // kill incoming instructions
        val revert              = Decoupled(new revert(GHRWidth=GHRWidth))   // Redirect frontend // FIXME: should be output...
        val final_fetch_packet  = Decoupled(new fetch_packet())                         // Output validated instructions
        val RAS_update          = Flipped(new RAS_update)                               // RAS control
    })

    /////////////
    // STAGE 1 //
    /////////////
    
    // Assign decoders register outputs
    // Assign decoders in first stage

    val decoders: Seq[branch_decoder] = Seq.tabulate(fetchWidth) { w =>
        Module(new branch_decoder(index=w, fetchWidth=fetchWidth, GHRWidth=GHRWidth))
    }

    val decoder_metadata         = Wire(Vec(fetchWidth, new metadata()))
    val decoder_T_NT             = Wire(Vec(fetchWidth, Bool()))

    val inputs_valid             = Wire(Bool())
    inputs_valid    := io.fetch_packet.valid && io.prediction.valid         // Are both inputs valid?

    for(i <- 0 until fetchWidth){
        // Inputs
        decoders(i).io.fetch_PC        :=  io.fetch_packet.bits.fetch_PC
        decoders(i).io.instruction     :=  io.fetch_packet.bits.instructions(i)
        decoders(i).io.valid           :=  io.fetch_packet.bits.valid_bits(i)
        decoders(i).io.prediction.bits :=  io.prediction.bits
        decoders(i).io.prediction.valid :=  io.prediction.valid
        decoders(i).io.RAS_read        :=  io.RAS_read
        // Outputs
        decoder_metadata(i)            :=  decoders(i).io.metadata
        decoder_T_NT(i)                :=  decoders(i).io.T_NT
    }

    val metadata_reg = Reg(Vec(fetchWidth, new metadata()))
    val T_NT_reg     = Reg(Vec(fetchWidth, Bool()))
    val GHR_reg      = Reg(UInt(GHRWidth.W))

    T_NT_reg := decoder_T_NT
    metadata_reg := decoder_metadata
    GHR_reg := io.prediction.bits.GHR

    /////////////
    // STAGE 2 //
    /////////////

    // Select dominant branch; select expected PC
    // Control RAS
    // Validate instructions
    // Assign outputs
    
    val metadata_out    = Wire(new metadata())
    // assign default value to metadata
    metadata_out := DontCare
    for(i <- 0 until fetchWidth){    // reverse this
        when(T_NT_reg(i) === 1.B){
            metadata_out := metadata_reg(i)
        }
    }

    /////////
    // FSM //
    /////////

    val PC_next      = Wire(UInt(32.W))
    val PC_next_reg  = RegInit(UInt(32.W), startPC)
    val PC_expected  = Wire(UInt(32.W))
    val packet_valid = Wire(Bool())

    // FSM 1
    // compare wires or wire and reg?
    // When a cycle occurs and there is no input, latch the expected PC for later comparison

    val FSM1_state = RegInit(latchExpectedPC(), latchExpectedPC.wire_reg)
    

    switch(FSM1_state){
        is(latchExpectedPC.wire_wire){
            when(!(io.prediction.valid && io.fetch_packet.valid)){
                FSM1_state := latchExpectedPC.wire_reg
                PC_next_reg := PC_next
            }
        }
        is(latchExpectedPC.wire_reg){
            // Start here
            when((io.prediction.valid && io.fetch_packet.valid)){
                FSM1_state := latchExpectedPC.wire_wire
            }
        }
    }


    // FSM 2
    // When a comparison takes place and the PCs match, output packet on the next cycle. 
    val FSM2_state = RegInit(validate_packet(), validate_packet.packet_invalid)

    val PC_mismatch = Wire(Bool())
    val PC_match = Wire(Bool())

    PC_match    := (PC_expected === io.fetch_packet.bits.fetch_PC) && inputs_valid
    PC_mismatch := (PC_expected =/= io.fetch_packet.bits.fetch_PC) && inputs_valid

    dontTouch(PC_match)

    switch(FSM2_state){
        is(validate_packet.packet_invalid){
            when(PC_match){
                FSM2_state := validate_packet.packet_valid
            }
        }
        is(validate_packet.packet_valid){
            when(PC_mismatch){
                FSM2_state := validate_packet.packet_invalid
            }
        }
    }

    packet_valid         := (FSM2_state === validate_packet.packet_valid)
    io.kill              := PC_mismatch
    io.revert.valid      := PC_mismatch
    io.revert.bits.GHR   := GHR_reg
    io.revert.bits.PC    := PC_expected

    ///////////////////////////////////


    // Select PC based on metadata
    

    // If need BTB, use BTB (non ret JALR)
    // If need RAS, use RAS (Ret)
    // If need computed, use computed (BR)

    val use_BTB      = Wire(Bool())
    val use_RAS      = Wire(Bool())
    val use_computed = Wire(Bool())

        
    PC_expected := Mux(FSM1_state === latchExpectedPC.wire_wire, PC_next, PC_next_reg)

    use_BTB      := metadata_out.JALR && !metadata_out.Ret
    use_RAS      := metadata_out.Ret
    use_computed := metadata_out.BR || metadata_out.JAL 

    dontTouch(metadata_out.Imm)

    when(use_BTB){PC_next := metadata_out.BTB_target}
    .elsewhen(use_RAS){PC_next := metadata_out.RAS}
    .elsewhen(use_computed){PC_next := metadata_out.instruction_PC + metadata_out.Imm.asUInt}
    .otherwise{PC_next := RegNext(io.fetch_packet.bits.fetch_PC + (fetchWidth*4).U)} // FIXME: should this always be +16?

    dontTouch(use_BTB)
    dontTouch(use_RAS)
    dontTouch(use_computed)

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
        io.final_fetch_packet.bits.valid_bits(i)   := RegNext(decoder_validator.io.instruction_validity(i)) && packet_valid && RegNext(inputs_valid)
    }


    io.final_fetch_packet.bits.fetch_PC := RegNext(io.fetch_packet.bits.fetch_PC)  // Pass along fetch PC
    // RAS Control //
    io.RAS_update.call       := metadata_out.Call
    io.RAS_update.ret        := metadata_out.Ret
    io.RAS_update.call_addr  := metadata_out.instruction_PC // PC of the actual instruction, not fetch_PC


    // Do not accept inputs if outputs have nowhere to go. 
    io.prediction.ready   := (io.final_fetch_packet.ready && !PC_mismatch)
    io.fetch_packet.ready := (io.final_fetch_packet.ready && !PC_mismatch)
    io.final_fetch_packet.valid := inputs_valid && PC_match
}