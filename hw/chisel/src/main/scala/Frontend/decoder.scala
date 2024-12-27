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
import chisel3.util._
import java.io.{File, FileWriter}
import java.rmi.server.UID

import helperFunctions._

import chisel3.util.experimental.decode._


class decoder(coreParameters:CoreParameters) extends Module{
    import coreParameters._
    import InstructionType._

    val io = IO(new Bundle{
        val instruction         = Flipped(Decoupled(new Instruction(coreParameters)))
        val decoded_instruction = Decoupled(new decoded_instruction(coreParameters))
    })

    io.decoded_instruction := DontCare

    val instruction = io.instruction.bits.instruction

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

    io.decoded_instruction.valid    := io.instruction.valid
    io.instruction.ready            := io.decoded_instruction.ready

    val initialReady = Wire(new sources_ready)
    initialReady.RS1_ready := false.B
    initialReady.RS2_ready := false.B

    io.decoded_instruction.bits.ready_bits      :=   initialReady

    def binString(n:UInt): String = {
        n.litValue.toString(2).reverse.padTo(n.getWidth, '0').reverse
    }


    val table = TruthTable(
        Map(    // (Hint: Scroll right to see mappings)
            //                                                                                                                                                                                                                          RS2 valid         
            //                                                                                                                                                                                                                          |   RS1 valid    
            //                                                                                                                                                                                                                          |   |   needs ALU                                  LOAD
            //                                                                                                                                                                                                                          |   |   |   needs branch unit                      |   STORE
            //                                                                                                                                                                                                                          |   |   |   |   needs CSR                          |   |   FENCE
            //                                                                                                                                                                                                                          |   |   |   |   |   needs memory                   |   |   |   FLUSH
            //                                                                                                                                                                                                                          |   |   |   |   |   |   needs mul                  |   |   |   |   RD valid
            //                                                                                                                                                                                                                          |   |   |   |   |   |   |   needs div              |   |   |   |   |
            //                                                                                                                                                                                                                          |   |   |   |   |   |   |   |   Unsigned?          |   |   |   |   |
            //                                                                                                                                                                                                                          |   |   |   |   |   |   |   |   |   IMM?           |   |   |   |   |
            //                                                                                                                                                                                                                          |   |   |   |   |   |   |   |   |   |   MRET       |   |   |   |   |
            //                                                                                                                                                                                                                          |   |   |   |   |   |   |   |   |   |   |   ECALL  |   |   |   |   |
            //                                                                                                                                                                                                                          |   |   |   |   |   |   |   |   |   |   |   |      |   |   |   |   |
            BitPat("b1"+ binString(0x00.U(7.W)) + R_NONE + R_NONE + binString(0x0.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + Y + Y + N + N + N + N + N + N + N + N + N +    N + N + N + N + Y),   // ADD
            BitPat("b1"+ binString(0x20.U(7.W)) + R_NONE + R_NONE + binString(0x0.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + Y + Y + N + N + N + N + N + N + N + N + N +    N + N + N + N + Y),   // SUB
            BitPat("b1"+ binString(0x00.U(7.W)) + R_NONE + R_NONE + binString(0x4.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + Y + Y + N + N + N + N + N + N + N + N + N +    N + N + N + N + Y),   // XOR
            BitPat("b1"+ binString(0x00.U(7.W)) + R_NONE + R_NONE + binString(0x6.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + Y + Y + N + N + N + N + N + N + N + N + N +    N + N + N + N + Y),   // OR
            BitPat("b1"+ binString(0x00.U(7.W)) + R_NONE + R_NONE + binString(0x7.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + Y + Y + N + N + N + N + N + N + N + N + N +    N + N + N + N + Y),   // AND
            BitPat("b1"+ binString(0x00.U(7.W)) + R_NONE + R_NONE + binString(0x1.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + Y + Y + N + N + N + N + N + N + N + N + N +    N + N + N + N + Y),   // SLL
            BitPat("b1"+ binString(0x00.U(7.W)) + R_NONE + R_NONE + binString(0x5.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + Y + Y + N + N + N + N + N + N + N + N + N +    N + N + N + N + Y),   // SRL
            BitPat("b1"+ binString(0x20.U(7.W)) + R_NONE + R_NONE + binString(0x5.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + Y + Y + N + N + N + N + N + N + N + N + N +    N + N + N + N + Y),   // SRA
            BitPat("b1"+ binString(0x00.U(7.W)) + R_NONE + R_NONE + binString(0x2.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + Y + Y + N + N + N + N + N + N + N + N + N +    N + N + N + N + Y),   // SLT
            BitPat("b1"+ binString(0x00.U(7.W)) + R_NONE + R_NONE + binString(0x3.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + Y + Y + N + N + N + N + N + Y + N + N + N +    N + N + N + N + Y),   // SLTU

            // IMM                                     
            BitPat("b1"+ IMM_NONE                 + R_NONE               + binString(0x0.U(3.W))         + R_NONE + s"${binString(InstructionType.OP_IMM.litValue.U(5.W))}")                                            -> BitPat("b" + N + Y + Y + N + N + N + N + N + N + Y + N + N +    N + N + N + N + Y),   // ADDI
            BitPat("b1"+ IMM_NONE                 + R_NONE               + binString(0x4.U(3.W))         + R_NONE + s"${binString(InstructionType.OP_IMM.litValue.U(5.W))}")                                            -> BitPat("b" + N + Y + Y + N + N + N + N + N + N + Y + N + N +    N + N + N + N + Y),   // XORI
            BitPat("b1"+ IMM_NONE                 + R_NONE               + binString(0x6.U(3.W))         + R_NONE + s"${binString(InstructionType.OP_IMM.litValue.U(5.W))}")                                            -> BitPat("b" + N + Y + Y + N + N + N + N + N + N + Y + N + N +    N + N + N + N + Y),   // ORI
            BitPat("b1"+ IMM_NONE                 + R_NONE               + binString(0x7.U(3.W))         + R_NONE + s"${binString(InstructionType.OP_IMM.litValue.U(5.W))}")                                            -> BitPat("b" + N + Y + Y + N + N + N + N + N + N + Y + N + N +    N + N + N + N + Y),   // ANDI
            BitPat("b1"+ binString(0x00.U(7.W))   + R_NONE   + R_NONE    + binString(0x1.U(3.W))         + R_NONE + s"${binString(InstructionType.OP_IMM.litValue.U(5.W))}")                                            -> BitPat("b" + N + Y + Y + N + N + N + N + N + N + Y + N + N +    N + N + N + N + Y),   // SLLI
            BitPat("b1"+ binString(0x00.U(7.W))   + R_NONE   + R_NONE    + binString(0x5.U(3.W))         + R_NONE + s"${binString(InstructionType.OP_IMM.litValue.U(5.W))}")                                            -> BitPat("b" + N + Y + Y + N + N + N + N + N + N + Y + N + N +    N + N + N + N + Y),   // SRLI
            BitPat("b1"+ binString(0x20.U(7.W))   + R_NONE   + R_NONE    + binString(0x5.U(3.W))         + R_NONE + s"${binString(InstructionType.OP_IMM.litValue.U(5.W))}")                                            -> BitPat("b" + N + Y + Y + N + N + N + N + N + N + Y + N + N +    N + N + N + N + Y),   // SRAI
            BitPat("b1"+ FUNCT7_NONE              + R_NONE   + R_NONE    + binString(0x2.U(3.W))         + R_NONE + s"${binString(InstructionType.OP_IMM.litValue.U(5.W))}")                                            -> BitPat("b" + N + Y + Y + N + N + N + N + N + N + Y + N + N +    N + N + N + N + Y),   // SLTI
            BitPat("b1"+ FUNCT7_NONE              + R_NONE   + R_NONE    + binString(0x3.U(3.W))         + R_NONE + s"${binString(InstructionType.OP_IMM.litValue.U(5.W))}")                                            -> BitPat("b" + N + Y + Y + N + N + N + N + N + Y + Y + N + N +    N + N + N + N + Y),   // SLTUI

            // LD                                      
            BitPat("b1"+ IMM_NONE + R_NONE + binString(0x0.U(3.W)) + R_NONE + s"${binString(InstructionType.LOAD.litValue.U(5.W))}")                                                                                    -> BitPat("b" + N + Y + N + N + N + Y + N + N + N + Y + N + N +    Y + N + N + N + Y),   // LB
            BitPat("b1"+ IMM_NONE + R_NONE + binString(0x1.U(3.W)) + R_NONE + s"${binString(InstructionType.LOAD.litValue.U(5.W))}")                                                                                    -> BitPat("b" + N + Y + N + N + N + Y + N + N + N + Y + N + N +    Y + N + N + N + Y),   // LH
            BitPat("b1"+ IMM_NONE + R_NONE + binString(0x2.U(3.W)) + R_NONE + s"${binString(InstructionType.LOAD.litValue.U(5.W))}")                                                                                    -> BitPat("b" + N + Y + N + N + N + Y + N + N + N + Y + N + N +    Y + N + N + N + Y),   // LW
            BitPat("b1"+ IMM_NONE + R_NONE + binString(0x4.U(3.W)) + R_NONE + s"${binString(InstructionType.LOAD.litValue.U(5.W))}")                                                                                    -> BitPat("b" + N + Y + N + N + N + Y + N + N + Y + Y + N + N +    Y + N + N + N + Y),   // LBU
            BitPat("b1"+ IMM_NONE + R_NONE + binString(0x5.U(3.W)) + R_NONE + s"${binString(InstructionType.LOAD.litValue.U(5.W))}")                                                                                    -> BitPat("b" + N + Y + N + N + N + Y + N + N + Y + Y + N + N +    Y + N + N + N + Y),   // LHU

            // STR                                     
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x0.U(3.W)) + R_NONE + s"${binString(InstructionType.STORE.litValue.U(5.W))}")                                                                       -> BitPat("b" + Y + Y + N + N + N + Y + N + N + N + Y + N + N +    N + Y + N + N + N),   // SB
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x1.U(3.W)) + R_NONE + s"${binString(InstructionType.STORE.litValue.U(5.W))}")                                                                       -> BitPat("b" + Y + Y + N + N + N + Y + N + N + N + Y + N + N +    N + Y + N + N + N),   // SHW
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x2.U(3.W)) + R_NONE + s"${binString(InstructionType.STORE.litValue.U(5.W))}")                                                                       -> BitPat("b" + Y + Y + N + N + N + Y + N + N + N + Y + N + N +    N + Y + N + N + N),   // SB

            // BRANCH                                      
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x0.U(3.W)) + R_NONE + s"${binString(InstructionType.BRANCH.litValue.U(5.W))}")                                                                      -> BitPat("b" + Y + Y + N + Y + N + N + N + N + N + Y + N + N +    N + N + N + N + N),   // BEQ
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x1.U(3.W)) + R_NONE + s"${binString(InstructionType.BRANCH.litValue.U(5.W))}")                                                                      -> BitPat("b" + Y + Y + N + Y + N + N + N + N + N + Y + N + N +    N + N + N + N + N),   // BNE
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x4.U(3.W)) + R_NONE + s"${binString(InstructionType.BRANCH.litValue.U(5.W))}")                                                                      -> BitPat("b" + Y + Y + N + Y + N + N + N + N + N + Y + N + N +    N + N + N + N + N),   // BLT
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x5.U(3.W)) + R_NONE + s"${binString(InstructionType.BRANCH.litValue.U(5.W))}")                                                                      -> BitPat("b" + Y + Y + N + Y + N + N + N + N + N + Y + N + N +    N + N + N + N + N),   // BGE
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x6.U(3.W)) + R_NONE + s"${binString(InstructionType.BRANCH.litValue.U(5.W))}")                                                                      -> BitPat("b" + Y + Y + N + Y + N + N + N + N + Y + Y + N + N +    N + N + N + N + N),   // BLTU
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x7.U(3.W)) + R_NONE + s"${binString(InstructionType.BRANCH.litValue.U(5.W))}")                                                                      -> BitPat("b" + Y + Y + N + Y + N + N + N + N + Y + Y + N + N +    N + N + N + N + N),   // BGEU

            // JAL                                     
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + FUNCT3_NONE + R_NONE + s"${binString(InstructionType.JAL.litValue.U(5.W))}")                                                                                   -> BitPat("b" + N + N + N + Y + N + N + N + N + N + Y + N + N +    N + N + N + N + Y),   // JAL

            // JALR                                    
            BitPat("b1"+ IMM_NONE + R_NONE + binString(0x0.U(3.W)) + R_NONE + s"${binString(InstructionType.JALR.litValue.U(5.W))}")                                                                                    -> BitPat("b" + N + Y + N + Y + N + N + N + N + N + Y + N + N +    N + N + N + N + Y),   // JALR

            // MISC insn                                       
            BitPat("b1"+ FUNCT7_NONE+ R_NONE + R_NONE + FUNCT3_NONE + R_NONE + s"${binString(InstructionType.LUI.litValue.U(5.W))}")                                                                                    -> BitPat("b" + N + N + Y + N + N + N + N + N + N + Y + N + N +    N + N + N + N + Y),   // LUI
            BitPat("b1"+ FUNCT7_NONE+ R_NONE + R_NONE + FUNCT3_NONE + R_NONE + s"${binString(InstructionType.AUIPC.litValue.U(5.W))}")                                                                                  -> BitPat("b" + N + N + N + Y + N + N + N + N + N + Y + N + N +    N + N + N + N + Y),   // AUIPC

            // MISC mem                                    
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x0.U(3.W)) + R_NONE + s"${binString(InstructionType.MISC_MEM.litValue.U(5.W))}")                                                                    -> BitPat("b" + N + Y + Y + N + N + N + N + N + N + Y + N + N +    N + N + N + N + Y), //BitPat("b" + N + N + N + N + Y + N + N + N + N + N + N + N +    N + N + Y + Y + N),   // FENCE

            // CSR                                     
            BitPat("b1"+ IMM_NONE + R_NONE + binString(0x1.U(3.W)) + R_NONE + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")                                                                                  -> BitPat("b" + N + Y + N + N + Y + N + N + N + N + N + N + N +    N + N + N + Y + Y),   // CSRRW
            BitPat("b1"+ IMM_NONE + R_NONE + binString(0x2.U(3.W)) + R_NONE + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")                                                                                  -> BitPat("b" + N + Y + N + N + Y + N + N + N + N + N + N + N +    N + N + N + Y + Y),   // CSRRS
            BitPat("b1"+ IMM_NONE + R_NONE + binString(0x3.U(3.W)) + R_NONE + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")                                                                                  -> BitPat("b" + N + Y + N + N + Y + N + N + N + N + N + N + N +    N + N + N + Y + Y),   // CSRRC
            BitPat("b1"+ IMM_NONE + R_NONE + binString(0x5.U(3.W)) + R_NONE + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")                                                                                  -> BitPat("b" + N + N + N + N + Y + N + N + N + N + Y + N + N +    N + N + N + Y + Y),   // CSRWI
            BitPat("b1"+ IMM_NONE + R_NONE + binString(0x6.U(3.W)) + R_NONE + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")                                                                                  -> BitPat("b" + N + N + N + N + Y + N + N + N + N + Y + N + N +    N + N + N + Y + Y),   // CSRSI
            BitPat("b1"+ IMM_NONE + R_NONE + binString(0x7.U(3.W)) + R_NONE + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")                                                                                  -> BitPat("b" + N + N + N + N + Y + N + N + N + N + Y + N + N +    N + N + N + Y + Y),   // CSRCI

            // SYSTEM
            BitPat("b1"+ binString(0x008.U(7.W))  + binString(0x2.U(5.W)) + binString(0x0.U(5.W)) + binString(0x0.U(3.W)) + binString(0x0.U(5.W)) + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")            -> BitPat("b" + N + N + N + N + Y + N + N + N + N + Y + N + N +    N + N + Y + Y + N),   // SRET FIXME: not implemented
            BitPat("b1"+ binString(0x000.U(7.W))  + binString(0x0.U(5.W)) + binString(0x0.U(5.W)) + binString(0x0.U(3.W)) + binString(0x0.U(5.W)) + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")            -> BitPat("b" + N + N + N + N + Y + N + N + N + N + N + N + Y +    N + N + N + Y + N),   // ECALL 
            BitPat("b1"+ binString(0x018.U(7.W))  + binString(0x2.U(5.W)) + binString(0x0.U(5.W)) + binString(0x0.U(3.W)) + binString(0x0.U(5.W)) + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")            -> BitPat("b" + N + N + N + N + Y + N + N + N + N + N + Y + N +    N + N + N + Y + N),   // MRET

            BitPat("b1"+ binString(0x105.U(12.W)) + binString(0x0.U(5.W)) + binString(0x0.U(3.W)) + binString(0x0.U(5.W)) + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")                                    -> BitPat("b" + N + Y + Y + N + N + N + N + N + N + Y + N + N +    N + N + N + N + Y),   // WFI (As NOP) 
            //BitPat("b"+ binString(0x24.U(7.W)) + binString(0x2.U(5.W)) + binString(0x0.U(3.W)) + binString(0x0.U(3.W)) + binString(0x0.U(5.W)) + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")              -> BitPat("b" + N + N + Y + N + N + N + N + Y + Y + N +    N + N + Y + Y + N),   // FIXME: add EBREAK


            // M
            BitPat("b1"+ binString(0x01.U(7.W)) + R_NONE + R_NONE + binString(0x0.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + Y + N + N + N + N + Y + N + N + N + N + N +    N + N + N + N + Y),   // mul
            BitPat("b1"+ binString(0x01.U(7.W)) + R_NONE + R_NONE + binString(0x1.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + Y + N + N + N + N + Y + N + N + N + N + N +    N + N + N + N + Y),   // mulh
            BitPat("b1"+ binString(0x01.U(7.W)) + R_NONE + R_NONE + binString(0x2.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + Y + N + N + N + N + Y + N + N + N + N + N +    N + N + N + N + Y),   // mulsu
            BitPat("b1"+ binString(0x01.U(7.W)) + R_NONE + R_NONE + binString(0x3.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + Y + N + N + N + N + Y + N + N + N + N + N +    N + N + N + N + Y),   // mulu
            BitPat("b1"+ binString(0x01.U(7.W)) + R_NONE + R_NONE + binString(0x4.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + Y + N + N + N + N + Y + Y + N + N + N + N +    N + N + N + N + Y),   // div
            BitPat("b1"+ binString(0x01.U(7.W)) + R_NONE + R_NONE + binString(0x5.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + Y + N + N + N + N + Y + Y + N + N + N + N +    N + N + N + N + Y),   // divu
            BitPat("b1"+ binString(0x01.U(7.W)) + R_NONE + R_NONE + binString(0x6.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + Y + N + N + N + N + Y + N + N + N + N + N +    N + N + N + N + Y),   // rem
            BitPat("b1"+ binString(0x01.U(7.W)) + R_NONE + R_NONE + binString(0x7.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + Y + N + N + N + N + Y + N + N + N + N + N +    N + N + N + N + Y),   // remu

        ),
        BitPat("b" + N + N + N + N + N + N + N + N + N + N + N + N + N + N + N + N + N)
    )




    //////////////////////////////////
    // READ OUT BITPATTERN & ASSIGN //
    //////////////////////////////////

    val decode_pat = decoder(Cat(io.instruction.valid, instruction(31, 2)), table)   // FIXME: add all fields, like RS1, RS2, RD, etc since some instructions have them fixed as per the spec (See MRET, sret, etc...)

    val (instructionType, valid) = InstructionType.safe(opcode(6, 2))
    when(io.instruction.fire){
        //assert(valid, "Enum state must be valid, got %x!",instruction)
    }




    io.decoded_instruction.bits.RS1                  := RS1
    io.decoded_instruction.bits.RS2                  := RS2
    io.decoded_instruction.bits.RD                   := PRD

    io.decoded_instruction.bits.FUNCT3               := FUNCT3
    io.decoded_instruction.bits.packet_index         := io.instruction.bits.packet_index 
    io.decoded_instruction.bits.instructionType      := instructionType
    io.decoded_instruction.bits.ROB_index            := 0.U
    io.decoded_instruction.bits.MOB_index            := 0.U


    io.decoded_instruction.bits.FENCE                := decode_pat(2)
    io.decoded_instruction.bits.FLUSH                := decode_pat(1)
    io.decoded_instruction.bits.RD_valid             := decode_pat(0)
    io.decoded_instruction.bits.needs_ALU            := decode_pat(14)
    io.decoded_instruction.bits.needs_branch_unit    := decode_pat(13)
    io.decoded_instruction.bits.needs_CSRs           := decode_pat(12)
    io.decoded_instruction.bits.needs_memory         := decode_pat(11)
    io.decoded_instruction.bits.needs_mul            := decode_pat(10)
    io.decoded_instruction.bits.needs_div            := decode_pat(9)
    io.decoded_instruction.bits.SUBTRACT             := decode_pat(8)     // FIXME: change this to UNSIGNED
    io.decoded_instruction.bits.IS_IMM               := decode_pat(7)
    io.decoded_instruction.bits.MRET                 := decode_pat(6)
    io.decoded_instruction.bits.ECALL                := decode_pat(5)
    io.decoded_instruction.bits.IMM                  := IMM 
    io.decoded_instruction.bits.MULTIPLY             := decode_pat(10)

    when (instruction(31,12) === 0x105.U){
        io.decoded_instruction.bits.IMM := 0.U
    }
   

    when(decode_pat(4)){
        io.decoded_instruction.bits.memory_type              := memory_type_t.LOAD
    }.elsewhen(decode_pat(3)){
        io.decoded_instruction.bits.memory_type              := memory_type_t.STORE
    }.otherwise{
        io.decoded_instruction.bits.memory_type              := memory_type_t.NONE
    }

    // FIXME: remove this and integrate it into the decoder
    val SUBTRACT    =   (instructionType === OP && FUNCT7 === 0x20.U) || (instructionType === OP_IMM && FUNCT3 === 0x5.U && FUNCT7 === 0x20.U)

    io.decoded_instruction.bits.SUBTRACT            := SUBTRACT

    io.decoded_instruction.bits.RS1_valid            := decode_pat(15)
    io.decoded_instruction.bits.RS2_valid            := decode_pat(16)

    when(FUNCT3  === "b000".U){ // LB
        io.decoded_instruction.bits.access_width             := access_width_t.B
        io.decoded_instruction.bits.mem_signed  := 1.B
    }.elsewhen(FUNCT3  === "b001".U ){   // LHW
        io.decoded_instruction.bits.access_width             := access_width_t.HW
        io.decoded_instruction.bits.mem_signed  := 1.B
    }.elsewhen(FUNCT3  === "b010".U){   // LW
        io.decoded_instruction.bits.access_width             := access_width_t.W
        io.decoded_instruction.bits.mem_signed  := 1.B
    }.elsewhen(FUNCT3  === "b100".U){   // LBU
        io.decoded_instruction.bits.access_width             := access_width_t.B
        io.decoded_instruction.bits.mem_signed  := 0.B
    }.elsewhen(FUNCT3  === "b101".U){   // LHWU
        io.decoded_instruction.bits.access_width             := access_width_t.HW
        io.decoded_instruction.bits.mem_signed  := 0.B
    }
    dontTouch(decode_pat)
}



class fetch_packet_decoder(coreParameters:CoreParameters) extends Module{
    import coreParameters._
    val io = IO(new Bundle{
        // FLUSH
        val flush = Flipped(ValidIO(new flush(coreParameters)))

        val fetch_packet         =  Flipped(Decoupled(new fetch_packet(coreParameters)))          // Fetch packet result (To Decoders)

        val decoded_fetch_packet =  Decoupled(new decoded_fetch_packet(coreParameters))
    })

    ////////////////////
    // OUTPUT BUNDLES //
    ////////////////////
    val decoded_fetch_packet    = Wire(Decoupled(new decoded_fetch_packet(coreParameters)))

    val decoders: Seq[decoder] = Seq.tabulate(fetchWidth) { w =>
        Module(new decoder(coreParameters))
    }

    var fetch_packet_ready = 1.B
    for(i <- 0 until fetchWidth){
        decoders(i).io.instruction.bits     := io.fetch_packet.bits.instructions(i)
        decoders(i).io.instruction.valid    := io.fetch_packet.valid && io.fetch_packet.bits.valid_bits(i)
    }
    io.fetch_packet.ready :=  io.decoded_fetch_packet.ready

    // Register outputs //
    for(i <- 0 until fetchWidth){
        decoded_fetch_packet.bits.decoded_instruction(i) := decoders(i).io.decoded_instruction.bits
        decoders(i).io.decoded_instruction.ready         := io.decoded_fetch_packet.ready
        io.fetch_packet.ready                            := io.decoded_fetch_packet.ready
    }

    decoded_fetch_packet.valid                           := io.fetch_packet.valid && !io.flush.valid
    decoded_fetch_packet.bits.fetch_PC                   := io.fetch_packet.bits.fetch_PC
    decoded_fetch_packet.bits.valid_bits                 := io.fetch_packet.bits.valid_bits
    decoded_fetch_packet.bits.GHR                        := io.fetch_packet.bits.GHR
    decoded_fetch_packet.bits.NEXT                       := io.fetch_packet.bits.NEXT
    decoded_fetch_packet.bits.TOS                        := io.fetch_packet.bits.TOS

    decoded_fetch_packet.bits.free_list_front_pointer    := DontCare // This is fine. Allocated during rename


    //////////////////
    // SKID BUFFERS //
    //////////////////

    val decoded_fetch_packet_out_Q                      = Module(new Queue(new decoded_fetch_packet(coreParameters), 2, flow=false, hasFlush=true, useSyncReadMem=false))

    decoded_fetch_packet.valid                          := (io.fetch_packet.fire) && !io.flush.valid

    decoded_fetch_packet.bits.prediction                := io.fetch_packet.bits.prediction

    decoded_fetch_packet_out_Q.io.enq                   <> decoded_fetch_packet
    decoded_fetch_packet_out_Q.io.deq                   <> io.decoded_fetch_packet
    decoded_fetch_packet_out_Q.io.deq.ready             := io.decoded_fetch_packet.ready
    decoded_fetch_packet_out_Q.io.flush.get             := io.flush.valid

    io.fetch_packet.ready                               := RegNext(io.decoded_fetch_packet.ready)

}

