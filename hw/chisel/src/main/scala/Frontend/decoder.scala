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


object apply_decoding{
    def apply(coreParameters:CoreParameters, decode_pat: UInt): decoded_instruction = {
        /* converts decoded pattern into a decoded instruction object */

        // INSTRUCTION STEERING //
        // needs ALU (25)
        // needs branch unit (24)
        // needs CSR (23)
        // needs memory (22)
        // needs mul (21)
        // needs div (20)
        // needs FPU (19)

        // OPERAND //
        // RS1 valid (18)
        // RS2 valid (17)
        // RD valid (16)
        // IMM (15)
        // Unsigned (14)
        
        // INSTRUCTION TYPE //
        // base Arithmetic (add/sub/etc) (13)
        // multiply (12)
        // Load (11)
        // Store (10)
        // CTRL (branch) (9)
        // XRET (8)
        // CSR R/W (7)
        // ENV (ECALL/EBREAK) (6)
        // FENCE  (5)

        // LUI (4)
        // AUIPC (3)
        // JAL (2)
        // JALR (1)


        // MISC //
        // FLUSH (0)


        val decoded_instruction = Wire(new decoded_instruction(coreParameters))

        decoded_instruction.needs_ALU            := decode_pat(25)
        decoded_instruction.needs_branch_unit    := decode_pat(24)
        decoded_instruction.needs_CSRs           := decode_pat(23)
        decoded_instruction.needs_memory         := decode_pat(22)
        decoded_instruction.needs_mul            := decode_pat(21)
        decoded_instruction.needs_div            := decode_pat(20)
        decoded_instruction.needs_FPU            := decode_pat(19)

        // Operand
        decoded_instruction.RS1_valid            := decode_pat(18)
        decoded_instruction.RS2_valid            := decode_pat(17)
        decoded_instruction.RD_valid             := decode_pat(16)
        decoded_instruction.IS_IMM               := decode_pat(15)
        decoded_instruction.UNSIGNED             := decode_pat(14)

        // INSTRUCTION TYPE //
        decoded_instruction.BASE_ARITHMETIC      := decode_pat(13)
        decoded_instruction.MULTIPLY             := decode_pat(12)
        decoded_instruction.LOAD                 := decode_pat(11)
        decoded_instruction.STORE                := decode_pat(10)
        decoded_instruction.CTRL                 := decode_pat(9)
        decoded_instruction.XRET                 := decode_pat(8)
        decoded_instruction.CSRRW                := decode_pat(7)
        decoded_instruction.ENV                  := decode_pat(6)
        decoded_instruction.FENCE                := decode_pat(5)

        decoded_instruction.LUI                  := decode_pat(4)
        decoded_instruction.AUIPC                := decode_pat(3)

        decoded_instruction.JAL                  := decode_pat(2)
        decoded_instruction.JALR                 := decode_pat(1)

        // MISC //
        decoded_instruction.FLUSH                := decode_pat(0)

        decoded_instruction
    }
}

object decode_base {
    def apply:Map[BitPat, BitPat] = {


        // helper fields
        // "1" and "0" => are concatenated to a bit string which is then converted to an int
        // "?" is a dont care
        val Y = "1"
        val N = "0"
        val R_NONE = "?????"
        val FUNCT7_NONE = "???????"
        val FUNCT3_NONE = "???"
        val IMM_NONE = "????????????"

        def binString(n:UInt): String = {
            n.litValue.toString(2).reverse.padTo(n.getWidth, '0').reverse
        }

        // INSTRUCTION STEERING //
        // needs ALU
        // needs branch unit
        // needs CSR
        // needs memory
        // needs mul
        // needs div
        // needs FPU

        // OPERAND //
        // RS1 valid
        // RS2 valid
        // RD valid
        // IMM
        // Unsigned
        
        // INSTRUCTION TYPE //
        // Arithmetic (add/sub/div/mul/etc)
        // Load
        // Store
        // CTRL (branch)
        // CSR R/W
        // XRET ?
        // ENV (ECALL/EBREAK)
        // FENCE ?


        // MISC //
        // FLUSH
                Map( // (Hint: Scroll right to see mappings)
                //                                                                                                                                                                                                                          // INSTRUCTION STEERING //                      // EXEC.//                      // INSTRUCTION TYPE //                                            // MISC //
                //                                                                                                                                                                                                                          needs ALU unit                                  RS1 valid                       ADD/SUB                                                           FLUSH
                //                                                                                                                                                                                                                          |   needs branch unit                           |   RS2 valid                   |   MUL/DIV                                                       |
                //                                                                                                                                                                                                                          |   |   needs CSR unit                          |   |   RD valid                |   |   Mem load                                                  |
                //                                                                                                                                                                                                                          |   |   |   needs memory unit                   |   |   |   IMM                 |   |   |   Mem Store                                             |
                //                                                                                                                                                                                                                          |   |   |   |   needs mul unit                  |   |   |   |   Unsigned        |   |   |   |   ctrl                                              | 
                //                                                                                                                                                                                                                          |   |   |   |   |   needs div unit              |   |   |   |   |               |   |   |   |   |   XRET                                          | 
                //                                                                                                                                                                                                                          |   |   |   |   |   |   needs FPU               |   |   |   |   |               |   |   |   |   |   |   CSRRW                                     | 
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   ENV                                   |
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   FENCE                             |
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   LUI                           |
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   |   AUIPC                     |
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   |   |   JAL                   |
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   |   |   |   JALR              |
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   |   |   |   |                 |
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   |   |   |   |                 |
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   |   |   |   |                 |
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   |   |   |   |                 |
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   |   |   |   |                 |
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   |   |   |   |                 |
                BitPat("b1"+ binString(0x00.U(7.W)) + R_NONE + R_NONE + binString(0x0.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + N + N + N + N + N + N +                     Y + Y + Y + N + N +             Y + N + N + N + N + N + N + N + N + N + N + N + N +               N ),   // ADD
                BitPat("b1"+ binString(0x20.U(7.W)) + R_NONE + R_NONE + binString(0x0.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + N + N + N + N + N + N +                     Y + Y + Y + N + N +             Y + N + N + N + N + N + N + N + N + N + N + N + N +               N ),   // SUB
                BitPat("b1"+ binString(0x00.U(7.W)) + R_NONE + R_NONE + binString(0x4.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + N + N + N + N + N + N +                     Y + Y + Y + N + N +             Y + N + N + N + N + N + N + N + N + N + N + N + N +               N ),   // XOR
                BitPat("b1"+ binString(0x00.U(7.W)) + R_NONE + R_NONE + binString(0x6.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + N + N + N + N + N + N +                     Y + Y + Y + N + N +             Y + N + N + N + N + N + N + N + N + N + N + N + N +               N ),   // OR
                BitPat("b1"+ binString(0x00.U(7.W)) + R_NONE + R_NONE + binString(0x7.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + N + N + N + N + N + N +                     Y + Y + Y + N + N +             Y + N + N + N + N + N + N + N + N + N + N + N + N +               N ),   // AND
                BitPat("b1"+ binString(0x00.U(7.W)) + R_NONE + R_NONE + binString(0x1.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + N + N + N + N + N + N +                     Y + Y + Y + N + N +             Y + N + N + N + N + N + N + N + N + N + N + N + N +               N ),   // SLL
                BitPat("b1"+ binString(0x00.U(7.W)) + R_NONE + R_NONE + binString(0x5.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + N + N + N + N + N + N +                     Y + Y + Y + N + N +             Y + N + N + N + N + N + N + N + N + N + N + N + N +               N ),   // SRL
                BitPat("b1"+ binString(0x20.U(7.W)) + R_NONE + R_NONE + binString(0x5.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + N + N + N + N + N + N +                     Y + Y + Y + N + N +             Y + N + N + N + N + N + N + N + N + N + N + N + N +               N ),   // SRA
                BitPat("b1"+ binString(0x00.U(7.W)) + R_NONE + R_NONE + binString(0x2.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + N + N + N + N + N + N +                     Y + Y + Y + N + N +             Y + N + N + N + N + N + N + N + N + N + N + N + N +               N ),   // SLT
                BitPat("b1"+ binString(0x00.U(7.W)) + R_NONE + R_NONE + binString(0x3.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + N + N + N + N + N + N +                     Y + Y + Y + N + Y +             Y + N + N + N + N + N + N + N + N + N + N + N + N +               N ),   // SLTU
                BitPat("b1"+ IMM_NONE                 + R_NONE               + binString(0x0.U(3.W))         + R_NONE + s"${binString(InstructionType.OP_IMM.litValue.U(5.W))}")                                            -> BitPat("b" + Y + N + N + N + N + N + N +                     Y + N + Y + Y + N +             Y + N + N + N + N + N + N + N + N + N + N + N + N +               N ),   // ADDI
                BitPat("b1"+ IMM_NONE                 + R_NONE               + binString(0x4.U(3.W))         + R_NONE + s"${binString(InstructionType.OP_IMM.litValue.U(5.W))}")                                            -> BitPat("b" + Y + N + N + N + N + N + N +                     Y + N + Y + Y + N +             Y + N + N + N + N + N + N + N + N + N + N + N + N +               N ),   // XORI
                BitPat("b1"+ IMM_NONE                 + R_NONE               + binString(0x6.U(3.W))         + R_NONE + s"${binString(InstructionType.OP_IMM.litValue.U(5.W))}")                                            -> BitPat("b" + Y + N + N + N + N + N + N +                     Y + N + Y + Y + N +             Y + N + N + N + N + N + N + N + N + N + N + N + N +               N ),   // ORI
                BitPat("b1"+ IMM_NONE                 + R_NONE               + binString(0x7.U(3.W))         + R_NONE + s"${binString(InstructionType.OP_IMM.litValue.U(5.W))}")                                            -> BitPat("b" + Y + N + N + N + N + N + N +                     Y + N + Y + Y + N +             Y + N + N + N + N + N + N + N + N + N + N + N + N +               N ),   // ANDI
                BitPat("b1"+ binString(0x00.U(7.W))   + R_NONE   + R_NONE    + binString(0x1.U(3.W))         + R_NONE + s"${binString(InstructionType.OP_IMM.litValue.U(5.W))}")                                            -> BitPat("b" + Y + N + N + N + N + N + N +                     Y + N + Y + Y + N +             Y + N + N + N + N + N + N + N + N + N + N + N + N +               N ),   // SLLI
                BitPat("b1"+ binString(0x00.U(7.W))   + R_NONE   + R_NONE    + binString(0x5.U(3.W))         + R_NONE + s"${binString(InstructionType.OP_IMM.litValue.U(5.W))}")                                            -> BitPat("b" + Y + N + N + N + N + N + N +                     Y + N + Y + Y + N +             Y + N + N + N + N + N + N + N + N + N + N + N + N +               N ),   // SRLI
                BitPat("b1"+ binString(0x20.U(7.W))   + R_NONE   + R_NONE    + binString(0x5.U(3.W))         + R_NONE + s"${binString(InstructionType.OP_IMM.litValue.U(5.W))}")                                            -> BitPat("b" + Y + N + N + N + N + N + N +                     Y + N + Y + Y + N +             Y + N + N + N + N + N + N + N + N + N + N + N + N +               N ),   // SRAI
                BitPat("b1"+ FUNCT7_NONE              + R_NONE   + R_NONE    + binString(0x2.U(3.W))         + R_NONE + s"${binString(InstructionType.OP_IMM.litValue.U(5.W))}")                                            -> BitPat("b" + Y + N + N + N + N + N + N +                     Y + N + Y + Y + N +             Y + N + N + N + N + N + N + N + N + N + N + N + N +               N ),   // SLTI
                BitPat("b1"+ FUNCT7_NONE              + R_NONE   + R_NONE    + binString(0x3.U(3.W))         + R_NONE + s"${binString(InstructionType.OP_IMM.litValue.U(5.W))}")                                            -> BitPat("b" + Y + N + N + N + N + N + N +                     Y + N + Y + Y + Y +             Y + N + N + N + N + N + N + N + N + N + N + N + N +               N ),   // SLTUI
                BitPat("b1"+ FUNCT7_NONE+ R_NONE + R_NONE + FUNCT3_NONE + R_NONE + s"${binString(InstructionType.LUI.litValue.U(5.W))}")                                                                                    -> BitPat("b" + Y + N + N + N + N + N + N +                     N + N + Y + Y + N +             N + N + N + N + N + N + N + N + N + Y + N + N + N +               N ),   // LUI
                BitPat("b1"+ FUNCT7_NONE+ R_NONE + R_NONE + FUNCT3_NONE + R_NONE + s"${binString(InstructionType.AUIPC.litValue.U(5.W))}")                                                                                  -> BitPat("b" + N + Y + N + N + N + N + N +                     N + N + Y + Y + N +             N + N + N + N + N + N + N + N + N + N + Y + N + N +               N ),   // AUIPC

                BitPat("b1"+ IMM_NONE + R_NONE + binString(0x0.U(3.W)) + R_NONE + s"${binString(InstructionType.LOAD.litValue.U(5.W))}")                                                                                    -> BitPat("b" + N + N + N + Y + N + N + N +                     Y + N + Y + Y + N +             N + N + Y + N + N + N + N + N + N + N + N + N + N +               N ),   // LB
                BitPat("b1"+ IMM_NONE + R_NONE + binString(0x1.U(3.W)) + R_NONE + s"${binString(InstructionType.LOAD.litValue.U(5.W))}")                                                                                    -> BitPat("b" + N + N + N + Y + N + N + N +                     Y + N + Y + Y + N +             N + N + Y + N + N + N + N + N + N + N + N + N + N +               N ),   // LH
                BitPat("b1"+ IMM_NONE + R_NONE + binString(0x2.U(3.W)) + R_NONE + s"${binString(InstructionType.LOAD.litValue.U(5.W))}")                                                                                    -> BitPat("b" + N + N + N + Y + N + N + N +                     Y + N + Y + Y + N +             N + N + Y + N + N + N + N + N + N + N + N + N + N +               N ),   // LW
                BitPat("b1"+ IMM_NONE + R_NONE + binString(0x4.U(3.W)) + R_NONE + s"${binString(InstructionType.LOAD.litValue.U(5.W))}")                                                                                    -> BitPat("b" + N + N + N + Y + N + N + N +                     Y + N + Y + Y + Y +             N + N + Y + N + N + N + N + N + N + N + N + N + N +               N ),   // LBU
                BitPat("b1"+ IMM_NONE + R_NONE + binString(0x5.U(3.W)) + R_NONE + s"${binString(InstructionType.LOAD.litValue.U(5.W))}")                                                                                    -> BitPat("b" + N + N + N + Y + N + N + N +                     Y + N + Y + Y + Y +             N + N + Y + N + N + N + N + N + N + N + N + N + N +               N ),   // LHU
                BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x0.U(3.W)) + R_NONE + s"${binString(InstructionType.STORE.litValue.U(5.W))}")                                                                       -> BitPat("b" + N + N + N + Y + N + N + N +                     Y + Y + N + Y + N +             N + N + N + Y + N + N + N + N + N + N + N + N + N +               N ),   // SB
                BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x1.U(3.W)) + R_NONE + s"${binString(InstructionType.STORE.litValue.U(5.W))}")                                                                       -> BitPat("b" + N + N + N + Y + N + N + N +                     Y + Y + N + Y + N +             N + N + N + Y + N + N + N + N + N + N + N + N + N +               N ),   // SHW
                BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x2.U(3.W)) + R_NONE + s"${binString(InstructionType.STORE.litValue.U(5.W))}")                                                                       -> BitPat("b" + N + N + N + Y + N + N + N +                     Y + Y + N + Y + N +             N + N + N + Y + N + N + N + N + N + N + N + N + N +               N ),   // SB

                BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x0.U(3.W)) + R_NONE + s"${binString(InstructionType.BRANCH.litValue.U(5.W))}")                                                                      -> BitPat("b" + N + Y + N + N + N + N + N +                     Y + Y + N + N + N +             N + N + N + N + Y + N + N + N + N + N + N + N + N +               N ),   // BEQ
                BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x1.U(3.W)) + R_NONE + s"${binString(InstructionType.BRANCH.litValue.U(5.W))}")                                                                      -> BitPat("b" + N + Y + N + N + N + N + N +                     Y + Y + N + N + N +             N + N + N + N + Y + N + N + N + N + N + N + N + N +               N ),   // BNE
                BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x4.U(3.W)) + R_NONE + s"${binString(InstructionType.BRANCH.litValue.U(5.W))}")                                                                      -> BitPat("b" + N + Y + N + N + N + N + N +                     Y + Y + N + N + N +             N + N + N + N + Y + N + N + N + N + N + N + N + N +               N ),   // BLT
                BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x5.U(3.W)) + R_NONE + s"${binString(InstructionType.BRANCH.litValue.U(5.W))}")                                                                      -> BitPat("b" + N + Y + N + N + N + N + N +                     Y + Y + N + N + N +             N + N + N + N + Y + N + N + N + N + N + N + N + N +               N ),   // BGE
                BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x6.U(3.W)) + R_NONE + s"${binString(InstructionType.BRANCH.litValue.U(5.W))}")                                                                      -> BitPat("b" + N + Y + N + N + N + N + N +                     Y + Y + N + N + Y +             N + N + N + N + Y + N + N + N + N + N + N + N + N +               N ),   // BLTU
                BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x7.U(3.W)) + R_NONE + s"${binString(InstructionType.BRANCH.litValue.U(5.W))}")                                                                      -> BitPat("b" + N + Y + N + N + N + N + N +                     Y + Y + N + N + Y +             N + N + N + N + Y + N + N + N + N + N + N + N + N +               N ),   // BGEU

                BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + FUNCT3_NONE + R_NONE + s"${binString(InstructionType.JAL.litValue.U(5.W))}")                                                                                   -> BitPat("b" + N + Y + N + N + N + N + N +                     N + N + Y + Y + N +             N + N + N + N + Y + N + N + N + N + N + N + Y + N +               N ),   // JAL
                BitPat("b1"+ IMM_NONE + R_NONE + binString(0x0.U(3.W)) + R_NONE + s"${binString(InstructionType.JALR.litValue.U(5.W))}")                                                                                    -> BitPat("b" + N + Y + N + N + N + N + N +                     Y + N + Y + Y + N +             N + N + N + N + Y + N + N + N + N + N + N + N + Y +               N ),   // JALR


                BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x0.U(3.W)) + R_NONE + s"${binString(InstructionType.MISC_MEM.litValue.U(5.W))}")                                                                    -> BitPat("b" + Y + N + N + N + N + N + N +                     N + N + N + N + N +             Y + N + N + N + N + N + N + N + Y + N + N + N + N +               Y ),   // FENCE //FIXME: UNSURE

                BitPat("b1"+ IMM_NONE + R_NONE + binString(0x1.U(3.W)) + R_NONE + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")                                                                                  -> BitPat("b" + N + N + Y + N + N + N + N +                     Y + N + Y + N + N +             N + N + N + N + N + N + Y + N + N + N + N + N + N +               Y ),   // CSRRW
                BitPat("b1"+ IMM_NONE + R_NONE + binString(0x2.U(3.W)) + R_NONE + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")                                                                                  -> BitPat("b" + N + N + Y + N + N + N + N +                     Y + N + Y + N + N +             N + N + N + N + N + N + Y + N + N + N + N + N + N +               Y ),   // CSRRS
                BitPat("b1"+ IMM_NONE + R_NONE + binString(0x3.U(3.W)) + R_NONE + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")                                                                                  -> BitPat("b" + N + N + Y + N + N + N + N +                     Y + N + Y + N + N +             N + N + N + N + N + N + Y + N + N + N + N + N + N +               Y ),   // CSRRC
                BitPat("b1"+ IMM_NONE + R_NONE + binString(0x5.U(3.W)) + R_NONE + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")                                                                                  -> BitPat("b" + N + N + Y + N + N + N + N +                     N + N + Y + Y + N +             N + N + N + N + N + N + Y + N + N + N + N + N + N +               Y ),   // CSRWI
                BitPat("b1"+ IMM_NONE + R_NONE + binString(0x6.U(3.W)) + R_NONE + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")                                                                                  -> BitPat("b" + N + N + Y + N + N + N + N +                     N + N + Y + Y + N +             N + N + N + N + N + N + Y + N + N + N + N + N + N +               Y ),   // CSRSI
                BitPat("b1"+ IMM_NONE + R_NONE + binString(0x7.U(3.W)) + R_NONE + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")                                                                                  -> BitPat("b" + N + N + Y + N + N + N + N +                     N + N + Y + Y + N +             N + N + N + N + N + N + Y + N + N + N + N + N + N +               Y ),   // CSRCI

                BitPat("b1"+ binString(0x000.U(7.W))  + binString(0x0.U(5.W)) + binString(0x0.U(5.W)) + binString(0x0.U(3.W)) + binString(0x0.U(5.W)) + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")            -> BitPat("b" + N + N + Y + N + N + N + N +                     N + N + N + N + N +             N + N + N + N + N + N + N + Y + N + N + N + N + N +               N ),   // ECALL 
                BitPat("b1"+ binString(0x001.U(7.W))  + binString(0x0.U(5.W)) + binString(0x0.U(5.W)) + binString(0x0.U(3.W)) + binString(0x0.U(5.W)) + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")            -> BitPat("b" + N + N + Y + N + N + N + N +                     N + N + N + N + N +             N + N + N + N + N + N + N + Y + N + N + N + N + N +               N ),   // EBREAK

                BitPat("b1"+ binString(0x018.U(7.W))  + binString(0x2.U(5.W)) + binString(0x0.U(5.W)) + binString(0x0.U(3.W)) + binString(0x0.U(5.W)) + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")            -> BitPat("b" + N + N + Y + N + N + N + N +                     N + N + N + N + N +             N + N + N + N + Y + Y + Y + N + N + N + N + N + N +               N ),   // MRET      
                BitPat("b1"+ binString(0x008.U(7.W))  + binString(0x2.U(5.W)) + binString(0x0.U(5.W)) + binString(0x0.U(3.W)) + binString(0x0.U(5.W)) + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")            -> BitPat("b" + N + N + Y + N + N + N + N +                     N + N + N + N + N +             N + N + N + N + Y + Y + Y + N + N + N + N + N + N +               N ),   // SRET FIXME: not implemented

                BitPat("b1"+ binString(0x105.U(12.W)) + binString(0x0.U(5.W)) + binString(0x0.U(3.W)) + binString(0x0.U(5.W)) + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")                                    -> BitPat("b" + Y + N + N + N + N + N + N +                     Y + N + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N ),   // WFI (As NOP) 
                BitPat("b1"+ binString(0x01.U(7.W)) + R_NONE + R_NONE + binString(0x0.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + N + N + N + N + Y + N + N +                     Y + Y + Y + N + N +             N + Y + N + N + N + N + N + N + N + N + N + N + N +               N ),   // mul
                BitPat("b1"+ binString(0x01.U(7.W)) + R_NONE + R_NONE + binString(0x1.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + N + N + N + N + Y + N + N +                     Y + Y + Y + N + N +             N + Y + N + N + N + N + N + N + N + N + N + N + N +               N ),   // mulh
                BitPat("b1"+ binString(0x01.U(7.W)) + R_NONE + R_NONE + binString(0x2.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + N + N + N + N + Y + N + N +                     Y + Y + Y + N + Y +             N + Y + N + N + N + N + N + N + N + N + N + N + N +               N ),   // mulsu
                BitPat("b1"+ binString(0x01.U(7.W)) + R_NONE + R_NONE + binString(0x3.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + N + N + N + N + Y + N + N +                     Y + Y + Y + N + Y +             N + Y + N + N + N + N + N + N + N + N + N + N + N +               N ),   // mulu
                BitPat("b1"+ binString(0x01.U(7.W)) + R_NONE + R_NONE + binString(0x4.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + N + N + N + N + N + Y + N +                     Y + Y + Y + N + N +             N + Y + N + N + N + N + N + N + N + N + N + N + N +               N ),   // div
                BitPat("b1"+ binString(0x01.U(7.W)) + R_NONE + R_NONE + binString(0x5.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + N + N + N + N + N + Y + N +                     Y + Y + Y + N + Y +             N + Y + N + N + N + N + N + N + N + N + N + N + N +               N ),   // divu
                BitPat("b1"+ binString(0x01.U(7.W)) + R_NONE + R_NONE + binString(0x6.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + N + N + N + N + N + Y + N +                     Y + Y + Y + N + N +             N + Y + N + N + N + N + N + N + N + N + N + N + N +               N ),   // rem
                BitPat("b1"+ binString(0x01.U(7.W)) + R_NONE + R_NONE + binString(0x7.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + N + N + N + N + N + Y + N +                     Y + Y + Y + N + Y +             N + Y + N + N + N + N + N + N + N + N + N + N + N +               N ),   // remu
            )


    }
}

object decode_FP {
    def apply:Map[BitPat, BitPat] = {



        // helper fields
        // "1" and "0" => are concatenated to a bit string which is then converted to an int
        // "?" is a dont care
        val Y = "1"
        val N = "0"
        val R_NONE = "?????"
        val RS3_NONE = "???"
        val RM_NONE = "???"
        val FUNCT7_NONE = "???????"
        val FUNCT3_NONE = "???"
        val IMM_NONE = "????????????"

        def binString(n:UInt): String = {
            n.litValue.toString(2).reverse.padTo(n.getWidth, '0').reverse
        }

        // INSTRUCTION STEERING //
        // needs ALU
        // needs branch unit
        // needs CSR
        // needs memory
        // needs mul
        // needs div
        // needs FPU

        // OPERAND //
        // RS1 valid
        // RS2 valid
        // RD valid
        // IMM
        // Unsigned
        
        // INSTRUCTION TYPE //
        // Arithmetic (add/sub/div/mul/etc)
        // Load
        // Store
        // CTRL (branch)
        // CSR R/W
        // XRET ?
        // ENV (ECALL/EBREAK)
        // FENCE ?


        // MISC //
        // FLUSH

        Map( // (Hint: Scroll right to see mappings)
                //                                                                                                                                                                                                                          // INSTRUCTION STEERING //                      // EXEC.//                      // INSTRUCTION TYPE //                                            // MISC //
                //                                                                                                                                                                                                                          needs ALU unit                                  RS1 valid                       ADD/SUB                                                           FLUSH
                //                                                                                                                                                                                                                          |   needs branch unit                           |   RS2 valid                   |   MUL/DIV                                                       |
                //                                                                                                                                                                                                                          |   |   needs CSR unit                          |   |   RD valid                |   |   Mem load                                                  |
                //                                                                                                                                                                                                                          |   |   |   needs memory unit                   |   |   |   IMM                 |   |   |   Mem Store                                             |
                //                                                                                                                                                                                                                          |   |   |   |   needs mul unit                  |   |   |   |   Unsigned        |   |   |   |   ctrl                                              | 
                //                                                                                                                                                                                                                          |   |   |   |   |   needs div unit              |   |   |   |   |               |   |   |   |   |   XRET                                          | 
                //                                                                                                                                                                                                                          |   |   |   |   |   |   needs FPU               |   |   |   |   |               |   |   |   |   |   |   CSRRW                                     | 
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   ENV                                   |
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   FENCE                             |
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   LUI                           |
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   |   AUIPC                     |
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   |   |   JAL                   |
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   |   |   |   JALR              |
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   |   |   |   |                 |
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   |   |   |   |                 |
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   |   |   |   |                 |
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   |   |   |   |                 |
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   |   |   |   |                 |
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   |   |   |   |                 |
                BitPat("b1"+ IMM_NONE + R_NONE + "010" + R_NONE + s"0000111")                                                                                                                                               -> BitPat("b" + Y + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N ), // FLW
                BitPat("b1"+ R_NONE + R_NONE + R_NONE + "010" + R_NONE + s"0100111")                                                                                                                                        -> BitPat("b" + Y + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N ), // FSW

                BitPat("b1"+ RS3_NONE + "00" + R_NONE + R_NONE + RM_NONE + R_NONE + s"1000011")                                                                                                                             -> BitPat("b" + Y + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N ), // FMADD.S
                BitPat("b1"+ RS3_NONE + "00" + R_NONE + R_NONE + RM_NONE + R_NONE + s"1000111")                                                                                                                             -> BitPat("b" + Y + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N ), // FMSUB.S
                BitPat("b1"+ RS3_NONE + "00" + R_NONE + R_NONE + RM_NONE + R_NONE + s"1001011")                                                                                                                             -> BitPat("b" + Y + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N ), // FNMSUB.S
                BitPat("b1"+ RS3_NONE + "00" + R_NONE + R_NONE + RM_NONE + R_NONE + s"1001111")                                                                                                                             -> BitPat("b" + Y + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N ), // FNMADD.S

                BitPat("b1"+ "0000000" + R_NONE + R_NONE + RM_NONE + R_NONE + "1010011")                                                                                                                                    -> BitPat("b" + Y + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N ), // FADD.S
                BitPat("b1"+ "0000100" + R_NONE + R_NONE + RM_NONE + R_NONE + "1010011")                                                                                                                                    -> BitPat("b" + Y + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N ), // FSUB.S
                BitPat("b1"+ "0001000" + R_NONE + R_NONE + RM_NONE + R_NONE + "1010011")                                                                                                                                    -> BitPat("b" + Y + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N ), // FMUL.S
                BitPat("b1"+ "0001100" + R_NONE + R_NONE + RM_NONE + R_NONE + "1010011")                                                                                                                                    -> BitPat("b" + Y + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N ), // FDIV.S
                
                BitPat("b1"+ "0101100" + "00000" + R_NONE + RM_NONE + R_NONE + "1010011")                                                                                                                                   -> BitPat("b" + Y + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N ), // FSQRT.S

                BitPat("b1"+ "0010000" + R_NONE + R_NONE + "000" + R_NONE + "1010011")                                                                                                                                      -> BitPat("b" + Y + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N ), // FSGNJ.S
                BitPat("b1"+ "0010000" + R_NONE + R_NONE + "001" + R_NONE + "1010011")                                                                                                                                      -> BitPat("b" + Y + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N ), // FSGNJN.S
                BitPat("b1"+ "0010000" + R_NONE + R_NONE + "010" + R_NONE + "1010011")                                                                                                                                      -> BitPat("b" + Y + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N ), // FSGNJX.S
                BitPat("b1"+ "0010100" + R_NONE + R_NONE + "000" + R_NONE + "1010011")                                                                                                                                      -> BitPat("b" + Y + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N ), // FMIN.S
                BitPat("b1"+ "0010100" + R_NONE + R_NONE + "001" + R_NONE + "1010011")                                                                                                                                      -> BitPat("b" + Y + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N ), // FMAX.S

                BitPat("b1"+ "1100000" + "00000" + R_NONE + RM_NONE + R_NONE + "1010011")                                                                                                                                   -> BitPat("b" + Y + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N ), // FCVT.W.S
                BitPat("b1"+ "1100000" + "00001" + R_NONE + RM_NONE + R_NONE + "1010011")                                                                                                                                   -> BitPat("b" + Y + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N ), // FCVT.WU.S
                BitPat("b1"+ "1110000" + "00000" + R_NONE + "000" + R_NONE + "1010011")                                                                                                                                     -> BitPat("b" + Y + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N ), // FMV.X.W

                BitPat("b1"+ "1010000" + R_NONE + R_NONE + "010" + R_NONE + "1010011")                                                                                                                                      -> BitPat("b" + Y + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N ), // FEQ.S
                BitPat("b1"+ "1010000" + R_NONE + R_NONE + "001" + R_NONE + "1010011")                                                                                                                                      -> BitPat("b" + Y + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N ), // FLT.S
                BitPat("b1"+ "1010000" + R_NONE + R_NONE + "000" + R_NONE + "1010011")                                                                                                                                      -> BitPat("b" + Y + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N ), // FLE.S

                BitPat("b1"+ "1110000" + "00000" + R_NONE + "001" + R_NONE + "1010011")                                                                                                                                     -> BitPat("b" + Y + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N ), // FCLASS.S

                BitPat("b1"+ "1101000" + "00000" + R_NONE + RM_NONE + R_NONE + "1010011")                                                                                                                                   -> BitPat("b" + Y + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N ), // FCVT.S.W
                BitPat("b1"+ "1101000" + "00001" + R_NONE + RM_NONE + R_NONE + "1010011")                                                                                                                                   -> BitPat("b" + Y + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N ), // FCVT.S.WU

                BitPat("b1"+ "1111000" + "00000" + R_NONE + "000" + R_NONE + "1010011")                                                                                                                                     -> BitPat("b" + Y + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N ), // FMV.W.X
            )
    }
}


class decoder(coreParameters:CoreParameters) extends Module{
    import coreParameters._
    import InstructionType._

    val io = IO(new Bundle{
        // FIXME: why decoupled?
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


    // INSTRUCTION STEERING //
    // needs ALU
    // needs branch unit
    // needs CSR
    // needs memory
    // needs mul
    // needs div
    // needs FPU

    // OPERAND //
    // RS1 valid
    // RS2 valid
    // RD valid
    // IMM
    // Unsigned
    
    // INSTRUCTION TYPE //
    // Arithmetic (add/sub/div/mul/etc)
    // Load
    // Store
    // CTRL (branch)
    // CSR R/W
    // XRET ?
    // ENV (ECALL/EBREAK)
    // FENCE ?

    // MISC //
    // FLUSH

    // Combine the various decoding maps based on what the core is configured to support
    val table = TruthTable(
        decode_base.apply ++ (if (coreConfig.contains("F")) decode_FP.apply else Map.empty),
        BitPat("b" + N + N + N + N + N + N + N + N + N + N + N + N + N + N + N + N + N + N + N + N + N + N)
    )


    //////////////////////////////////
    // READ OUT BITPATTERN & ASSIGN //
    //////////////////////////////////

    val decode_pat = decoder(Cat(io.instruction.valid, instruction(31, 2)), table)   // FIXME: add all fields, like RS1, RS2, RD, etc since some instructions have them fixed as per the spec (See MRET, sret, etc...)


    // INSTRUCTION STEERING //
    // needs ALU (25)
    // needs branch unit (24)
    // needs CSR (23)
    // needs memory (22)
    // needs mul (21)
    // needs div (20)
    // needs FPU (19)

    // OPERAND //
    // RS1 valid (18)
    // RS2 valid (17)
    // RD valid (16)
    // IMM (15)
    // Unsigned (14)
    
    // INSTRUCTION TYPE //
    // base Arithmetic (add/sub/etc) (13)
    // multiply (12)
    // Load (11)
    // Store (10)
    // CTRL (branch) (9)
    // XRET (8)
    // CSR R/W (7)
    // ENV (ECALL/EBREAK) (6)
    // FENCE  (5)

    // LUI (4)
    // AUIPC (3)
    // JAL (2)
    // JALR (1)


    // MISC //
    // FLUSH (0)


    // instruction steering
    io.decoded_instruction.bits.valid                := io.instruction.valid //io.instruciton.bits.valid
    io.decoded_instruction.bits.needs_ALU            := decode_pat(25)
    io.decoded_instruction.bits.needs_branch_unit    := decode_pat(24)
    io.decoded_instruction.bits.needs_CSRs           := decode_pat(23)
    io.decoded_instruction.bits.needs_memory         := decode_pat(22)
    io.decoded_instruction.bits.needs_mul            := decode_pat(21)
    io.decoded_instruction.bits.needs_div            := decode_pat(20)
    io.decoded_instruction.bits.needs_FPU            := decode_pat(19)

    // Operand
    io.decoded_instruction.bits.RS1_valid            := decode_pat(18)
    io.decoded_instruction.bits.RS2_valid            := decode_pat(17)
    io.decoded_instruction.bits.RD_valid             := decode_pat(16)
    io.decoded_instruction.bits.IS_IMM               := decode_pat(15)
    io.decoded_instruction.bits.UNSIGNED             := decode_pat(14)

    // INSTRUCTION TYPE //
    io.decoded_instruction.bits.BASE_ARITHMETIC      := decode_pat(13)
    io.decoded_instruction.bits.MULTIPLY             := decode_pat(12)
    io.decoded_instruction.bits.LOAD                 := decode_pat(11)
    io.decoded_instruction.bits.STORE                := decode_pat(10)
    io.decoded_instruction.bits.CTRL                 := decode_pat(9)
    io.decoded_instruction.bits.XRET                 := decode_pat(8)
    io.decoded_instruction.bits.CSRRW                := decode_pat(7)
    io.decoded_instruction.bits.ENV                  := decode_pat(6)
    io.decoded_instruction.bits.FENCE                := decode_pat(5)

    io.decoded_instruction.bits.LUI                  := decode_pat(4)
    io.decoded_instruction.bits.AUIPC                := decode_pat(3)

    io.decoded_instruction.bits.JAL                  := decode_pat(2)
    io.decoded_instruction.bits.JALR                 := decode_pat(1)

    // MISC //
    io.decoded_instruction.bits.FLUSH                := decode_pat(0)


    io.decoded_instruction.bits.IMM                  := IMM 
    io.decoded_instruction.bits.RS1                  := RS1
    io.decoded_instruction.bits.RS2                  := RS2
    io.decoded_instruction.bits.RD                   := PRD

    io.decoded_instruction.bits.FUNCT3               := FUNCT3
    io.decoded_instruction.bits.FUNCT7               := FUNCT7
    io.decoded_instruction.bits.packet_index         := io.instruction.bits.packet_index 
    io.decoded_instruction.bits.ROB_index            := 0.U
    io.decoded_instruction.bits.MOB_index            := 0.U

    //////////////////
    // PORT BINDING //
    //////////////////
    // Assign a port for this instruction
    // FIXME: add an element of randomness here...
    // FIXME: this makes a lot more sense to be used with multiple reservation stations, not just one
    def shift_port_seq(portSR: Vec[UInt]): Unit = { // Shift portSR by 1
    val first = portSR.head
        for (i <- 0 until portSR.length - 1) {
            portSR(i) := portSR(i + 1)
        }
        portSR(portSR.length - 1) := first
    }

    def get_next_port(portSR: Vec[UInt]): UInt = { // Get the lowest SR entry
        portSR.head
    }

    // Create UInt Vecs of the port #s that support the corresponding instruction

    val ALU_port_seq = RegInit(VecInit(FUParamSeq.zipWithIndex.filter(_._1.supportsInt).map(_._2.U)))
    val branch_port_seq = RegInit(VecInit(FUParamSeq.zipWithIndex.filter(_._1.supportsBranch).map(_._2.U)))
    val CSR_port_seq = RegInit(VecInit(FUParamSeq.zipWithIndex.filter(_._1.supportsCSRs).map(_._2.U)))
    val memory_port_seq = RegInit(VecInit(FUParamSeq.zipWithIndex.filter(_._1.supportsAddressGeneration).map(_._2.U)))
    val mul_port_seq = RegInit(VecInit(FUParamSeq.zipWithIndex.filter(_._1.supportsMult).map(_._2.U)))
    val div_port_seq = RegInit(VecInit(FUParamSeq.zipWithIndex.filter(_._1.supportsDiv).map(_._2.U)))

    dontTouch(ALU_port_seq)
    dontTouch(branch_port_seq)
    dontTouch(CSR_port_seq)
    dontTouch(memory_port_seq)
    dontTouch(mul_port_seq)
    dontTouch(div_port_seq)

    // Assign ports based on instruction requirements
    when(io.decoded_instruction.bits.needs_ALU) {
        io.decoded_instruction.bits.assigned_port := get_next_port(ALU_port_seq)
    }.elsewhen(io.decoded_instruction.bits.needs_branch_unit) {
        io.decoded_instruction.bits.assigned_port := get_next_port(branch_port_seq)
    }.elsewhen(io.decoded_instruction.bits.needs_CSRs) {
        io.decoded_instruction.bits.assigned_port := get_next_port(CSR_port_seq)
    }.elsewhen(io.decoded_instruction.bits.needs_memory) {
        io.decoded_instruction.bits.assigned_port := get_next_port(memory_port_seq)
    }.elsewhen(io.decoded_instruction.bits.needs_mul) {
        io.decoded_instruction.bits.assigned_port := get_next_port(mul_port_seq)
    }.elsewhen(io.decoded_instruction.bits.needs_div) {
        io.decoded_instruction.bits.assigned_port := get_next_port(div_port_seq)
    }
    //.elsewhen(io.decoded_instruction.bits.needs_FPU) {
        //io.decoded_instruction.bits.assigned_port := get_next_port(FPU_port_seq)
    //}

    // Update next ports after assignment
    shift_port_seq(ALU_port_seq)
    shift_port_seq(branch_port_seq)
    shift_port_seq(CSR_port_seq)
    shift_port_seq(memory_port_seq)
    shift_port_seq(mul_port_seq)
    shift_port_seq(div_port_seq)





    when (instruction(31,12) === 0x105.U){
        io.decoded_instruction.bits.IMM := 0.U
    }
   

    when(decode_pat(11)){
        io.decoded_instruction.bits.memory_type              := memory_type_t.LOAD
    }.elsewhen(decode_pat(10)){
        io.decoded_instruction.bits.memory_type              := memory_type_t.STORE
    }.otherwise{
        io.decoded_instruction.bits.memory_type              := memory_type_t.NONE
    }

    // FIXME: why is this not part of the decoder? cant you just used the UNSIGNED FLAG?
    // STORES should never be signed/unsigned. They just store the data at that particular width. loads determine if that data is signed or not...
    // FIXME: SIGNED FOR STORES doesnt seem to actually matter (rocket keeps it high in sb isa test)
    when(io.decoded_instruction.bits.STORE && FUNCT3  === "b000".U){ // SB
        io.decoded_instruction.bits.access_width             := access_width_t.B
    }.elsewhen(io.decoded_instruction.bits.STORE && FUNCT3  === "b001".U ){   // LH
        io.decoded_instruction.bits.access_width             := access_width_t.HW
    }.elsewhen(io.decoded_instruction.bits.STORE && FUNCT3  === "b010".U){   // SW
        io.decoded_instruction.bits.access_width             := access_width_t.W
    }

    when(io.decoded_instruction.bits.LOAD && FUNCT3  === "b000".U){ // LB
        io.decoded_instruction.bits.access_width             := access_width_t.B
        io.decoded_instruction.bits.mem_signed  := 1.B
    }.elsewhen(io.decoded_instruction.bits.LOAD && FUNCT3  === "b001".U ){   // LHW
        io.decoded_instruction.bits.access_width             := access_width_t.HW
        io.decoded_instruction.bits.mem_signed  := 1.B
    }.elsewhen(io.decoded_instruction.bits.LOAD && FUNCT3  === "b010".U){   // LW
        io.decoded_instruction.bits.access_width             := access_width_t.W
        io.decoded_instruction.bits.mem_signed  := 1.B
    }.elsewhen(io.decoded_instruction.bits.LOAD && FUNCT3  === "b100".U){   // LBU
        io.decoded_instruction.bits.access_width             := access_width_t.B
        io.decoded_instruction.bits.mem_signed  := 0.B
    }.elsewhen(io.decoded_instruction.bits.LOAD && FUNCT3  === "b101".U){   // LHWU
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
    //decoded_fetch_packet.bits.valid_bits                 := io.fetch_packet.bits.valid_bits
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

