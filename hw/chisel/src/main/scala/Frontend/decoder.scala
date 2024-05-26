/* ------------------------------------------------------------------------------------
* Filename: decoder.scala
* Author: Hakam Atassi
* Date: May 9 2024
* Description: A single instruction decoder and the N wide fetch packet decoder.
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

import helperFunctions._


class decoder(parameters:Parameters) extends Module{   // basic decoder and field extraction
    import parameters._
    val io = IO(new Bundle{
        val instruction         = Input(new Instruction(fetchWidth=fetchWidth, ROBEntires=ROBEntires))

        val decoded_instruction = Output(new decoded_instruction(coreConfig=coreConfig, fetchWidth=fetchWidth, ROBEntires=ROBEntires, physicalRegCount=physicalRegCount))
    })

    import InstructionType._


    val instruction = io.instruction.instruction

    // Direct instruction fields
    val opcode      = instruction(6, 0)
    val RS1         = instruction(19, 15)
    val RS2         = instruction(24, 20)
    val RD          = instruction(11, 7)
    val IMM         = getImm(instruction)

    val FUNCT3      = instruction(14, 12)
    val FUNCT7      = instruction(31, 25)


    val instructionType = InstructionType(opcode(6,2))

    val MULTIPLY    = (instructionType === InstructionType.OP && FUNCT7(0))
    val SUBTRACT    = (instructionType === InstructionType.OP && FUNCT7(2))
    val IMMEDIATE   = (instructionType === InstructionType.OP_IMM)


    val needs_divider   =   (instructionType === OP) && 
                            ( FUNCT3 === 0x4.U  ||
                              FUNCT3 === 0x5.U  ||
                              FUNCT3 === 0x6.U  ||
                              FUNCT3 === 0x7.U) && FUNCT7(0)

    val needs_branch_unit   =   (instructionType === BRANCH) || 
                                (instructionType === JAL)    ||
                                (instructionType === JALR)

    val needs_ALU           =       ((instructionType === OP) && (FUNCT7(2) || (FUNCT7 === 0x00.U))) ||
                                    (instructionType === OP_IMM)


    val needs_memory        =       (instructionType === STORE) ||(instructionType === LOAD)

    // Assign output

    io.decoded_instruction.RD_valid         := 0.B  // FIXME: 
    io.decoded_instruction.RD               := RD
    io.decoded_instruction.RS1              := RS1
    io.decoded_instruction.RS2              := RS2
    io.decoded_instruction.IMM              := IMM
    io.decoded_instruction.FUNCT3           := FUNCT3
    io.decoded_instruction.MULTIPLY         := MULTIPLY // Multiply or Divide
    io.decoded_instruction.SUBTRACT         := SUBTRACT // subtract or arithmetic shift...
    io.decoded_instruction.IMMEDIATE        := IMMEDIATE // subtract or arithmetic shift...

    io.decoded_instruction.packet_index     := io.instruction.packet_index 

    io.decoded_instruction.instructionType  := instructionType

    io.decoded_instruction.ROB_index        := io.instruction.ROB_index

    io.decoded_instruction.needs_ALU                := needs_ALU
    io.decoded_instruction.needs_branch_unit        := needs_branch_unit


    // TODO: ECALL / EBREAK


    val ALU_port    =   RegInit(UInt(2.W), 0.U)

    
    when(needs_ALU){
        io.decoded_instruction.portID := ALU_port

        when(ALU_port === 2.U){
            ALU_port := 0.U
        }.otherwise{
            ALU_port := ALU_port + 1.U
        }

    }.elsewhen(needs_divider){
        io.decoded_instruction.portID := 1.U
    }.elsewhen(needs_branch_unit){
        io.decoded_instruction.portID := 0.U
    }.elsewhen(needs_memory){
        io.decoded_instruction.portID := 3.U
    }.otherwise{
        io.decoded_instruction.portID := 0.U
    }


    // Assign a reservation station

    val is_INT  =   (instructionType === OP) || (instructionType === OP_IMM)  || 
                    (instructionType === BRANCH) || (instructionType === JAL) ||
                    (instructionType === JALR)

    val is_MEM   =   (instructionType === LOAD) || (instructionType === STORE)

    when(is_INT){
        io.decoded_instruction.RS_type  :=   RS_types.INT
    }.elsewhen(is_MEM){
        io.decoded_instruction.RS_type  :=   RS_types.MEM
    }.otherwise{    // is_FP
        io.decoded_instruction.RS_type  :=   RS_types.FP
    }


}

/*
class fetch_packet_decoder(fetchWidth:Int) extends Module{
    val io = IO(new Bundle{
        val fetch_packet         =   Decoupled(new fetch_packet(fetchWidth=fetchWidth))          // Fetch packet result (To Decoders)
        val decoded_fetch_packet =   Decoupled(new decoded_fetch_packet(fetchWidth=fetchWidth))
    })

    val decoders: Seq[decoder] = Seq.tabulate(fetchWidth) { w =>
        Module(new decoder(fetchWidth=fetchWidth))
    }

    for(i <- until fetchWidth){
        decoder(i).io.instruction := io.fetch_packet.instructions(i)
    }

    // Register outputs //
    io.decoded_fetch_packet.fetch_PC                := RegNext(io.fetch_packet.fetch_PC)
    io.decoded_fetch_packet.valid_bits              := RegNext(io.fetch_packet.valid_bits)

    for(i <- until fetchWidth){
        io.decoded_fetch_packet.decoded_instructions(i)    := RegNext(decoder(i).io.decoded_instruction)
    }


}*/
