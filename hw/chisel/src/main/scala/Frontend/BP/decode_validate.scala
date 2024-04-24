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


class decode_validate(width:Int = 4) extends Module{

    val io = IO(new Bundle{
        val BTB_resp     = Input(new BTB_resp())
        val fetch_packet = Input(new fetch_packet())
        val input_valid  = Input(Bool())

        // kill incoming instructions
        val kill = Output(Bool())

        // Redirect frontend
        val redirect    = Output(Bool())
        val PC_redirect = Output(UInt(32.W))
        val GHR_redirect = Output(new BTB_resp().GHR)

        // Output validated instructions
        val final_fetch_packet = Output(new fetch_packet())

        // RAS control
        val call_valid         = Output(Bool())
        val call_addr          = Output(UInt(32.W))
        val ret_valid          = Output(Bool())

    })

    /////////////
    // STAGE 1 //
    /////////////
    
    // Assign decoders register outputs
    // Assign decoders in first stage

    val decoders: Seq[branch_decoder] = Seq.tabulate(width) { w =>
        Module(new branch_decoder(index=w))
    }

    val decoder_metadata         = Wire(Vec(width, new metadata()))
    val decoder_T_NT             = Wire(Vec(width, Bool()))

    for(i <- 0 until width){
        // Inputs
        decoders(i).io.fetch_PC        :=  io.fetch_packet.fetch_PC
        decoders(i).io.instruction     :=  io.fetch_packet.instructions(i)
        decoders(i).io.valid           :=  io.fetch_packet.valid_bits(i)
        decoders(i).io.BTB_resp        :=  io.BTB_resp
        // Outputs
        decoder_metadata(i)            :=  decoders(i).io.metadata
        decoder_T_NT(i)                :=  decoders(i).io.T_NT
    }

    val metadata_reg = Reg(Vec(width, new metadata()))
    val T_NT_reg     = Reg(Vec(width, Bool()))
    val GHR_reg      = Reg(new BTB_resp().GHR)

    T_NT_reg := decoder_T_NT
    metadata_reg := decoder_metadata
    GHR_reg := io.BTB_resp.GHR

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
    for(i <- 0 until width){    // reverse this
        when(T_NT_reg(i) === 1.B){
            metadata_out := metadata_reg(i)
        }
    }

    /////////
    // FSM //
    /////////

    val PC_next     = Wire(UInt(32.W))
    val PC_next_reg = RegInit(UInt(32.W), 0.U)
    val PC_expected = Wire(UInt(32.W))
    val packet_valid = Wire(Bool())

    // FSM 1
    // compare wires or wire and reg?
    // When a cycle occurs and there is no input, latch the expected PC for later comparison

    val FSM1_state = RegInit(latchExpectedPC(), latchExpectedPC.wire_reg)
    

    switch(FSM1_state){
        is(latchExpectedPC.wire_wire){
            when(io.input_valid === 0.B){
                FSM1_state := latchExpectedPC.wire_reg
                PC_next_reg := PC_next
            }
        }
        is(latchExpectedPC.wire_reg){
            // Start here
            when(io.input_valid === 1.B){
                FSM1_state := latchExpectedPC.wire_wire
            }
        }
    }


    // FSM 2
    // When a comparison takes place and the PCs match, output packet on the next cycle. 
    val FSM2_state = RegInit(validate_packet(), validate_packet.packet_valid)

    val PC_mismatch = Wire(Bool())
    val PC_match = Wire(Bool())

    PC_match    := (PC_expected === io.fetch_packet.fetch_PC) && io.input_valid
    PC_mismatch := (PC_expected =/= io.fetch_packet.fetch_PC) && io.input_valid

    switch(FSM2_state){
        is(validate_packet.packet_invalid){
            when(PC_match){
                FSM2_state := validate_packet.packet_valid
            }
        }
        is(validate_packet.packet_valid){
            when(PC_match){
                FSM2_state := validate_packet.packet_invalid
            }
        }
    }

    packet_valid    := (FSM2_state === validate_packet.packet_valid)
    io.kill         := PC_mismatch
    io.redirect     := PC_mismatch
    io.GHR_redirect := GHR_reg
    io.PC_redirect  := PC_expected



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


    when(use_BTB){PC_next := metadata_out.BTB_target}
    .elsewhen(use_RAS){PC_next := metadata_out.RAS}
    .elsewhen(use_computed){PC_next := metadata_out.instruction_PC + metadata_out.Imm}
    .otherwise{PC_next := io.fetch_packet.fetch_PC + (width*4).U}


    // validate instructions

    // Set all valid bits to 0.
    for(i <- 0 until width){
        io.final_fetch_packet.valid_bits(i) := 0.B
    }

    // "validator"
    // iterate and valid as you go along.
    val validate_flag = Wire(Bool())
    validate_flag := 1.B
    for(i <- 0 until width){
        when(validate_flag && io.fetch_packet.valid_bits(i) && packet_valid){  // instructions are valid if no previous taken branch, was valid on input, and the packet as a whole is valid
            io.final_fetch_packet.valid_bits(i) := 1.B  // validate on output
        }
        when(decoder_T_NT(i) === 1.B){  // all instructions after taken branch are invalid
            validate_flag := 0.B    // branch occurred. All following branches invalid.
        }

        io.final_fetch_packet.instructions(i) := io.fetch_packet.instructions(i)    // pass along actual instruction
    }
    io.final_fetch_packet.fetch_PC := io.fetch_packet.fetch_PC  // Pass along fetch PC


    // RAS Control //
    io.call_valid := metadata_out.Call
    io.call_addr := metadata_out.instruction_PC // PC of the actual instruction, not fetch_PC
    io.ret_valid := metadata_out.Ret


}