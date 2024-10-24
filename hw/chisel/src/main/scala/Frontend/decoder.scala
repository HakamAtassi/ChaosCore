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

import chisel3.util.experimental.decode._

class decoder(coreParameters:CoreParameters) extends Module{   // basic decoder and field extraction
    import coreParameters._
    import InstructionType._
    val io = IO(new Bundle{
        val instruction         = Flipped(Decoupled(new Instruction(coreParameters)))
        val decoded_instruction = Decoupled(new decoded_instruction(coreParameters))
    })




    val instruction = io.instruction.bits.instruction

    // Direct instruction fields
    val opcode      = instruction(6, 0)
    val RS1         = instruction(19, 15)
    val RS2         = instruction(24, 20)
    val PRD         = instruction(11, 7)
    val IMM         = getImm(instruction)
    val FUNCT3      = instruction(14, 12)
    val FUNCT7      = instruction(31, 25)


    val (instructionType, valid) = InstructionType.safe(opcode(6, 2))
    assert(valid, "Enum state must be valid, got %x!",instruction)

    //Do we check entire funct7 field or just check for single bit?


    val MULTIPLY    =   (instructionType === OP && FUNCT7 === 0x1.U)


    val SUBTRACT    =   (instructionType === OP && FUNCT7 === 0x20.U) || (instructionType === OP_IMM && FUNCT3 === 0x5.U && FUNCT7 === 0x20.U)


    val IS_IMM   =      (instructionType === OP_IMM)    || 
                        (instructionType === LUI)       || 
                        (instructionType === AUIPC)     || 
                        (instructionType === STORE)     || 
                        (instructionType === LOAD)      || 
                        (instructionType === BRANCH)    || 
                        (instructionType === JAL)       || 
                        (instructionType === JALR)      ||
                        ((instructionType === SYSTEM) && (FUNCT3 === 5.U || FUNCT3 === 6.U || FUNCT3 === 7.U))

    val needs_div            =   (instructionType === OP) && FUNCT7(0)
    val needs_mul            =   (instructionType === OP) && FUNCT7(0)
    val needs_branch_unit    =   (instructionType === BRANCH) || (instructionType === JAL) || (instructionType === JALR) || (instructionType === AUIPC)
    val needs_CSRs           =   (instructionType === SYSTEM) && (FUNCT3 === 0x0.U || FUNCT3 === 0x1.U || FUNCT3 === 0x2.U || FUNCT3 === 0x3.U || FUNCT3 === 0x5.U || FUNCT3 === 0x6.U || FUNCT3 === 0x7.U)
    val needs_ALU            =   ((instructionType === OP) &&
                                 ((FUNCT7 === 0x20.U) || (FUNCT7 === 0x00.U))) || 
                                 (instructionType === OP_IMM) || (instructionType === LUI)



    val ECALL               =   instruction === "b00000000000000000000000001110011".U 
    val MRET                =   instruction === "b00110000001000000000000001110011".U 
    //instruciton === "b00110000001000000000000001110011".U //(instructionType === SYSTEM) && (FUNCT3 === 0x0.U)


    val FENCE               =   ((instructionType === MISC_MEM) && FUNCT3 === 0x0.U)


    // Assign output

    io.decoded_instruction.valid    := io.instruction.valid
    io.instruction.ready            := io.decoded_instruction.ready

    val initialReady = Wire(new sources_ready)
    initialReady.RS1_ready := false.B
    initialReady.RS2_ready := false.B

    io.decoded_instruction.bits.ready_bits      :=   initialReady

    io.decoded_instruction.bits.RD_valid := (instructionType === OP         || 
                                            instructionType === OP_IMM      || 
                                            instructionType === LOAD        || 
                                            instructionType === JAL         || 
                                            instructionType === JALR        || 
                                            instructionType === LUI         || 
                                            instructionType === AUIPC       || 
                                            (instructionType === SYSTEM &&  FUNCT3=/=0.U))     && 
                                            io.instruction.valid

    io.decoded_instruction.bits.RS1_valid            := (instructionType === OP         || 
                                                        instructionType === OP_IMM      || 
                                                        instructionType === LOAD        || 
                                                        instructionType === STORE       || 
                                                        instructionType === JALR        || 
                                                        (needs_CSRs && !IS_IMM) ||
                                                        instructionType === BRANCH)     && 
                                                        io.instruction.valid

    io.decoded_instruction.bits.RS2_valid            := (instructionType === OP         ||
                                                        instructionType === STORE       || 
                                                        instructionType === BRANCH)     && 
                                                        io.instruction.valid


    io.decoded_instruction.bits.RD                   := PRD
    io.decoded_instruction.bits.PRDold               := DontCare
    io.decoded_instruction.bits.PRD                  := DontCare
    io.decoded_instruction.bits.RS1                  := RS1
    io.decoded_instruction.bits.RS2                  := RS2
    io.decoded_instruction.bits.IMM                  := IMM
    io.decoded_instruction.bits.FUNCT3               := FUNCT3
    io.decoded_instruction.bits.MULTIPLY             := MULTIPLY    // Multiply or Divide
    io.decoded_instruction.bits.SUBTRACT             := SUBTRACT    // subtract or arithmetic shift...
    io.decoded_instruction.bits.FENCE                := FENCE       // FLUSH of ANY TYPE    (they all do the same thing)
    io.decoded_instruction.bits.FLUSH                := 0.B       // FLUSH of ANY TYPE    (they all do the same thing)
    io.decoded_instruction.bits.MRET                 := MRET       // FLUSH of ANY TYPE    (they all do the same thing)
    io.decoded_instruction.bits.IS_IMM               := IS_IMM   // subtract or arithmetic shift...





    when(instructionType === LOAD){
        io.decoded_instruction.bits.memory_type              := memory_type_t.LOAD
    }.elsewhen(instructionType === STORE){
        io.decoded_instruction.bits.memory_type              := memory_type_t.STORE
    }.otherwise{
        io.decoded_instruction.bits.memory_type              := memory_type_t.NONE
    }

    val needs_memory         =   (instructionType === STORE) || (instructionType === LOAD)

    io.decoded_instruction.bits.packet_index         := io.instruction.bits.packet_index 
    io.decoded_instruction.bits.instructionType      := instructionType
    io.decoded_instruction.bits.ROB_index            := 0.U
    io.decoded_instruction.bits.MOB_index            := 0.U
    io.decoded_instruction.bits.needs_ALU            := needs_ALU
    io.decoded_instruction.bits.needs_memory         := needs_memory
    io.decoded_instruction.bits.needs_branch_unit    := needs_branch_unit
    io.decoded_instruction.bits.needs_CSRs           := needs_CSRs
    io.decoded_instruction.bits.needs_mul            := needs_mul
    io.decoded_instruction.bits.needs_div            := needs_div
    io.decoded_instruction.bits.ECALL                := ECALL

    io.decoded_instruction.bits.access_width                 := access_width_t.NONE
    io.decoded_instruction.bits.mem_signed  := 0.B


    when(FUNCT3  === "b000".U && needs_memory){ // LB
        io.decoded_instruction.bits.access_width             := access_width_t.B
        io.decoded_instruction.bits.mem_signed  := 1.B
    }.elsewhen(FUNCT3  === "b001".U && needs_memory){   // LHW
        io.decoded_instruction.bits.access_width             := access_width_t.HW
        io.decoded_instruction.bits.mem_signed  := 1.B
    }.elsewhen(FUNCT3  === "b010".U && needs_memory){   // LW
        io.decoded_instruction.bits.access_width             := access_width_t.W
        io.decoded_instruction.bits.mem_signed  := 1.B
    }.elsewhen(FUNCT3  === "b100".U && needs_memory){   // LBU
        io.decoded_instruction.bits.access_width             := access_width_t.B
        io.decoded_instruction.bits.mem_signed  := 0.B
    }.elsewhen(FUNCT3  === "b101".U && needs_memory){   // LHWU
        io.decoded_instruction.bits.access_width             := access_width_t.HW
        io.decoded_instruction.bits.mem_signed  := 0.B
    }

    dontTouch(IMM)
    dontTouch(instructionType)

}

class improved_decoder(coreParameters:CoreParameters) extends Module{
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

    val Y = "1"
    val N = "0"
    val X = "x"
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
        Map(
            //                                                                                                                                                                                                                          needs ALU                                  LOAD
            //                                                                                                                                                                                                                          |   needs branch unit                      |   STORE
            //                                                                                                                                                                                                                          |   |   needs CSR                          |   |   FENCE
            //                                                                                                                                                                                                                          |   |   |   needs memory                   |   |   |   FLUSH
            //                                                                                                                                                                                                                          |   |   |   |   needs mul                  |   |   |   |   RD valid?
            //                                                                                                                                                                                                                          |   |   |   |   |   needs div              |   |   |   |   |
            //                                                                                                                                                                                                                          |   |   |   |   |   |   Unsigned?          |   |   |   |   |
            //                                                                                                                                                                                                                          |   |   |   |   |   |   |   IMM?           |   |   |   |   |
            //                                                                                                                                                                                                                          |   |   |   |   |   |   |   |   MRET       |   |   |   |   |
            //                                                                                                                                                                                                                          |   |   |   |   |   |   |   |   |   ECALL  |   |   |   |   |
            //                                                                                                                                                                                                                          |   |   |   |   |   |   |   |   |   |      |   |   |   |   |
            BitPat("b1"+ binString(0x00.U(7.W)) + R_NONE + R_NONE + binString(0x0.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + N + N + N + N + N + N + N + N + N +    N + N + N + N + Y),   // ADD
            BitPat("b1"+ binString(0x20.U(7.W)) + R_NONE + R_NONE + binString(0x0.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + N + N + N + N + N + N + N + N + N +    N + N + N + N + Y),   // SUB
            BitPat("b1"+ binString(0x00.U(7.W)) + R_NONE + R_NONE + binString(0x4.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + N + N + N + N + N + N + N + N + N +    N + N + N + N + Y),   // XOR
            BitPat("b1"+ binString(0x00.U(7.W)) + R_NONE + R_NONE + binString(0x6.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + N + N + N + N + N + N + N + N + N +    N + N + N + N + Y),   // OR
            BitPat("b1"+ binString(0x00.U(7.W)) + R_NONE + R_NONE + binString(0x7.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + N + N + N + N + N + N + N + N + N +    N + N + N + N + Y),   // AND
            BitPat("b1"+ binString(0x00.U(7.W)) + R_NONE + R_NONE + binString(0x1.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + N + N + N + N + N + N + N + N + N +    N + N + N + N + Y),   // SLL
            BitPat("b1"+ binString(0x00.U(7.W)) + R_NONE + R_NONE + binString(0x5.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + N + N + N + N + N + N + N + N + N +    N + N + N + N + Y),   // SRL
            BitPat("b1"+ binString(0x20.U(7.W)) + R_NONE + R_NONE + binString(0x5.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + N + N + N + N + N + N + N + N + N +    N + N + N + N + Y),   // SRA
            BitPat("b1"+ binString(0x00.U(7.W)) + R_NONE + R_NONE + binString(0x2.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + N + N + N + N + N + N + N + N + N +    N + N + N + N + Y),   // SLT
            BitPat("b1"+ binString(0x00.U(7.W)) + R_NONE + R_NONE + binString(0x3.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + Y + N + N + N + N + N + Y + N + N + N +    N + N + N + N + Y),   // SLTU

            // IMM                                     
            BitPat("b1"+ IMM_NONE                 + R_NONE               + binString(0x0.U(3.W))         + R_NONE + s"${binString(InstructionType.OP_IMM.litValue.U(5.W))}")                                            -> BitPat("b" + Y + N + N + N + N + N + N + Y + N + N +    N + N + N + N + Y),   // ADDI
            BitPat("b1"+ IMM_NONE                 + R_NONE               + binString(0x4.U(3.W))         + R_NONE + s"${binString(InstructionType.OP_IMM.litValue.U(5.W))}")                                            -> BitPat("b" + Y + N + N + N + N + N + N + Y + N + N +    N + N + N + N + Y),   // XORI
            BitPat("b1"+ IMM_NONE                 + R_NONE               + binString(0x6.U(3.W))         + R_NONE + s"${binString(InstructionType.OP_IMM.litValue.U(5.W))}")                                            -> BitPat("b" + Y + N + N + N + N + N + N + Y + N + N +    N + N + N + N + Y),   // ORI
            BitPat("b1"+ IMM_NONE                 + R_NONE               + binString(0x7.U(3.W))         + R_NONE + s"${binString(InstructionType.OP_IMM.litValue.U(5.W))}")                                            -> BitPat("b" + Y + N + N + N + N + N + N + Y + N + N +    N + N + N + N + Y),   // ANDI
            BitPat("b1"+ binString(0x00.U(7.W))   + R_NONE   + R_NONE    + binString(0x1.U(3.W))         + R_NONE + s"${binString(InstructionType.OP_IMM.litValue.U(5.W))}")                                            -> BitPat("b" + Y + N + N + N + N + N + N + Y + N + N +    N + N + N + N + Y),   // SLLI
            BitPat("b1"+ binString(0x00.U(7.W))   + R_NONE   + R_NONE    + binString(0x5.U(3.W))         + R_NONE + s"${binString(InstructionType.OP_IMM.litValue.U(5.W))}")                                            -> BitPat("b" + Y + N + N + N + N + N + N + Y + N + N +    N + N + N + N + Y),   // SRLI
            BitPat("b1"+ binString(0x20.U(7.W))   + R_NONE   + R_NONE    + binString(0x5.U(3.W))         + R_NONE + s"${binString(InstructionType.OP_IMM.litValue.U(5.W))}")                                            -> BitPat("b" + Y + N + N + N + N + N + N + Y + N + N +    N + N + N + N + Y),   // SRAI
            BitPat("b1"+ FUNCT7_NONE              + R_NONE   + R_NONE    + binString(0x2.U(3.W))         + R_NONE + s"${binString(InstructionType.OP_IMM.litValue.U(5.W))}")                                            -> BitPat("b" + Y + N + N + N + N + N + N + Y + N + N +    N + N + N + N + Y),   // SLTI
            BitPat("b1"+ FUNCT7_NONE              + R_NONE   + R_NONE    + binString(0x3.U(3.W))         + R_NONE + s"${binString(InstructionType.OP_IMM.litValue.U(5.W))}")                                            -> BitPat("b" + Y + N + N + N + N + N + Y + Y + N + N +    N + N + N + N + Y),   // SLTUI

            // LD                                      
            BitPat("b1"+ IMM_NONE + R_NONE + binString(0x0.U(3.W)) + R_NONE + s"${binString(InstructionType.LOAD.litValue.U(5.W))}")                                                                                    -> BitPat("b" + N + N + N + Y + N + N + N + Y + N + N +    Y + N + N + N + Y),   // LB
            BitPat("b1"+ IMM_NONE + R_NONE + binString(0x1.U(3.W)) + R_NONE + s"${binString(InstructionType.LOAD.litValue.U(5.W))}")                                                                                    -> BitPat("b" + N + N + N + Y + N + N + N + Y + N + N +    Y + N + N + N + Y),   // LH
            BitPat("b1"+ IMM_NONE + R_NONE + binString(0x2.U(3.W)) + R_NONE + s"${binString(InstructionType.LOAD.litValue.U(5.W))}")                                                                                    -> BitPat("b" + N + N + N + Y + N + N + N + Y + N + N +    Y + N + N + N + Y),   // LW
            BitPat("b1"+ IMM_NONE + R_NONE + binString(0x4.U(3.W)) + R_NONE + s"${binString(InstructionType.LOAD.litValue.U(5.W))}")                                                                                    -> BitPat("b" + N + N + N + Y + N + N + Y + Y + N + N +    Y + N + N + N + Y),   // LBU
            BitPat("b1"+ IMM_NONE + R_NONE + binString(0x5.U(3.W)) + R_NONE + s"${binString(InstructionType.LOAD.litValue.U(5.W))}")                                                                                    -> BitPat("b" + N + N + N + Y + N + N + Y + Y + N + N +    Y + N + N + N + Y),   // LHU

            // STR                                     
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x0.U(3.W)) + R_NONE + s"${binString(InstructionType.STORE.litValue.U(5.W))}")                                                                       -> BitPat("b" + N + N + N + Y + N + N + N + Y + N + N +    N + Y + N + N + N),   // SB
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x1.U(3.W)) + R_NONE + s"${binString(InstructionType.STORE.litValue.U(5.W))}")                                                                       -> BitPat("b" + N + N + N + Y + N + N + N + Y + N + N +    N + Y + N + N + N),   // SHW
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x2.U(3.W)) + R_NONE + s"${binString(InstructionType.STORE.litValue.U(5.W))}")                                                                       -> BitPat("b" + N + N + N + Y + N + N + N + Y + N + N +    N + Y + N + N + N),   // SB

            // BRANCH                                      
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x0.U(3.W)) + R_NONE + s"${binString(InstructionType.BRANCH.litValue.U(5.W))}")                                                                      -> BitPat("b" + N + Y + N + N + N + N + N + Y + N + N +    N + N + N + N + N),   // BEQ
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x1.U(3.W)) + R_NONE + s"${binString(InstructionType.BRANCH.litValue.U(5.W))}")                                                                      -> BitPat("b" + N + Y + N + N + N + N + N + Y + N + N +    N + N + N + N + N),   // BNE
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x4.U(3.W)) + R_NONE + s"${binString(InstructionType.BRANCH.litValue.U(5.W))}")                                                                      -> BitPat("b" + N + Y + N + N + N + N + N + Y + N + N +    N + N + N + N + N),   // BLT
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x5.U(3.W)) + R_NONE + s"${binString(InstructionType.BRANCH.litValue.U(5.W))}")                                                                      -> BitPat("b" + N + Y + N + N + N + N + N + Y + N + N +    N + N + N + N + N),   // BGE
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x6.U(3.W)) + R_NONE + s"${binString(InstructionType.BRANCH.litValue.U(5.W))}")                                                                      -> BitPat("b" + N + Y + N + N + N + N + Y + Y + N + N +    N + N + N + N + N),   // BLTU
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x7.U(3.W)) + R_NONE + s"${binString(InstructionType.BRANCH.litValue.U(5.W))}")                                                                      -> BitPat("b" + N + Y + N + N + N + N + Y + Y + N + N +    N + N + N + N + N),   // BGEU

            // JAL                                     
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + FUNCT3_NONE + R_NONE + s"${binString(InstructionType.JAL.litValue.U(5.W))}")                                                                                   -> BitPat("b" + N + Y + N + N + N + N + N + Y + N + N +    N + N + N + N + Y),   // JAL

            // JALR                                    
            BitPat("b1"+ IMM_NONE + R_NONE + binString(0x0.U(3.W)) + R_NONE + s"${binString(InstructionType.JALR.litValue.U(5.W))}")                                                                                    -> BitPat("b" + N + Y + N + N + N + N + N + Y + N + N +    N + N + N + N + Y),   // JALR

            // MISC insn                                       
            BitPat("b1"+ FUNCT7_NONE+ R_NONE + R_NONE + FUNCT3_NONE + R_NONE + s"${binString(InstructionType.LUI.litValue.U(5.W))}")                                                                                    -> BitPat("b" + Y + N + N + N + N + N + N + Y + N + N +    N + N + N + N + Y),   // LUI
            BitPat("b1"+ FUNCT7_NONE+ R_NONE + R_NONE + FUNCT3_NONE + R_NONE + s"${binString(InstructionType.AUIPC.litValue.U(5.W))}")                                                                                  -> BitPat("b" + N + Y + N + N + N + N + N + Y + N + N +    N + N + N + N + Y),   // AUIPC

            // MISC mem                                    
            BitPat("b1"+ FUNCT7_NONE + R_NONE + R_NONE + binString(0x0.U(3.W)) + R_NONE + s"${binString(InstructionType.MISC_MEM.litValue.U(5.W))}")                                                                    -> BitPat("b" + Y + N + N + N + N + N + N + Y + N + N +    N + N + Y + Y + N),   // FENCE

            // CSR                                     
            BitPat("b1"+ IMM_NONE + R_NONE + binString(0x1.U(3.W)) + R_NONE + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")                                                                                  -> BitPat("b" + N + N + N + N + N + N + N + Y + N + N +    N + N + N + Y + N),   // CSRRW
            BitPat("b1"+ IMM_NONE + R_NONE + binString(0x2.U(3.W)) + R_NONE + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")                                                                                  -> BitPat("b" + N + N + N + N + N + N + N + Y + N + N +    N + N + N + Y + N),   // CSRRS
            BitPat("b1"+ IMM_NONE + R_NONE + binString(0x3.U(3.W)) + R_NONE + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")                                                                                  -> BitPat("b" + N + N + N + N + N + N + N + Y + N + N +    N + N + N + Y + N),   // CSRRC
            BitPat("b1"+ IMM_NONE + R_NONE + binString(0x5.U(3.W)) + R_NONE + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")                                                                                  -> BitPat("b" + N + N + Y + N + N + N + N + Y + N + N +    N + N + N + Y + N),   // CSRWI
            BitPat("b1"+ IMM_NONE + R_NONE + binString(0x6.U(3.W)) + R_NONE + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")                                                                                  -> BitPat("b" + N + N + Y + N + N + N + N + Y + N + N +    N + N + N + Y + N),   // CSRSI
            BitPat("b1"+ IMM_NONE + R_NONE + binString(0x7.U(3.W)) + R_NONE + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")                                                                                  -> BitPat("b" + N + N + Y + N + N + N + N + Y + N + N +    N + N + N + Y + N),   // CSRCI

            // SYSTEM
            BitPat("b1"+ binString(0x0.U(7.W))  + binString(0x0.U(5.W)) + binString(0x0.U(5.W)) + binString(0x0.U(3.W)) + binString(0x0.U(5.W)) + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")              -> BitPat("b" + N + N + Y + N + N + N + N + N + N + Y +    N + N + Y + Y + N),   // ECALL 
            BitPat("b1"+ binString(0x8.U(7.W))  + binString(0x2.U(5.W)) + binString(0x0.U(5.W)) + binString(0x0.U(3.W)) + binString(0x0.U(5.W)) + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")              -> BitPat("b" + N + N + Y + N + N + N + N + Y + N + N +    N + N + Y + Y + N),   // SRET FIXME: not implemented
            BitPat("b1"+ binString(0x24.U(7.W)) + binString(0x2.U(5.W)) + binString(0x0.U(3.W)) + binString(0x0.U(3.W)) + binString(0x0.U(5.W)) + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")              -> BitPat("b" + N + N + Y + N + N + N + N + Y + Y + N +    N + N + Y + Y + N),   // MRET 
            //BitPat("b"+ binString(0x24.U(7.W)) + binString(0x2.U(5.W)) + binString(0x0.U(3.W)) + binString(0x0.U(3.W)) + binString(0x0.U(5.W)) + s"${binString(InstructionType.SYSTEM.litValue.U(5.W))}")              -> BitPat("b" + N + N + Y + N + N + N + N + Y + Y + N +    N + N + Y + Y + N),   // FIXME: add EBREAK


            // M
            BitPat("b1"+ binString(0x01.U(7.W)) + R_NONE + R_NONE + binString(0x0.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + N + N + N + N + Y + N + N + N + N + N +    N + N + N + N + Y),   // mul
            BitPat("b1"+ binString(0x01.U(7.W)) + R_NONE + R_NONE + binString(0x1.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + N + N + N + N + Y + N + N + N + N + N +    N + N + N + N + Y),   // mulh
            BitPat("b1"+ binString(0x01.U(7.W)) + R_NONE + R_NONE + binString(0x2.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + N + N + N + N + Y + N + N + N + N + N +    N + N + N + N + Y),   // mulsu
            BitPat("b1"+ binString(0x01.U(7.W)) + R_NONE + R_NONE + binString(0x3.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + N + N + N + N + Y + N + N + N + N + N +    N + N + N + N + Y),   // mulu
            BitPat("b1"+ binString(0x01.U(7.W)) + R_NONE + R_NONE + binString(0x4.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + N + N + N + N + Y + Y + N + N + N + N +    N + N + N + N + Y),   // div
            BitPat("b1"+ binString(0x01.U(7.W)) + R_NONE + R_NONE + binString(0x5.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + N + N + N + N + Y + Y + N + N + N + N +    N + N + N + N + Y),   // divu
            BitPat("b1"+ binString(0x01.U(7.W)) + R_NONE + R_NONE + binString(0x6.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + N + N + N + N + Y + N + N + N + N + N +    N + N + N + N + Y),   // rem
            BitPat("b1"+ binString(0x01.U(7.W)) + R_NONE + R_NONE + binString(0x7.U(3.W)) + R_NONE + s"${binString(InstructionType.OP.litValue.U(5.W))}")                                                               -> BitPat("b" + N + N + N + N + Y + N + N + N + N + N +    N + N + N + N + Y),   // remu

        ),
        BitPat("b" + N + N + N + N + N + N + N + N + N + N + N + N + N + N + N)
    )




    //////////////////////////////////
    // READ OUT BITPATTERN & ASSIGN //
    //////////////////////////////////

    val test = decoder(Cat(io.instruction.valid, instruction(31, 2)), table)   // FIXME: add all fields, like RS1, RS2, RD, etc since some instructions have them fixed as per the spec (See MRET, sret, etc...)
    dontTouch(test)

    val (instructionType, valid) = InstructionType.safe(opcode(6, 2))
    assert(valid, "Enum state must be valid, got %x!",instruction)




    io.decoded_instruction.bits.RS1                  := RS1
    io.decoded_instruction.bits.RS2                  := RS2
    io.decoded_instruction.bits.RD                   := PRD

    io.decoded_instruction.bits.FUNCT3               := FUNCT3
    io.decoded_instruction.bits.packet_index         := io.instruction.bits.packet_index 
    io.decoded_instruction.bits.instructionType      := instructionType
    io.decoded_instruction.bits.ROB_index            := 0.U
    io.decoded_instruction.bits.MOB_index            := 0.U


//                                                                            needs ALU                                  LOAD
//                                                                            |   needs branch unit                      |   STORE
//                                                                            |   |   needs CSR                          |   |   FENCE
//                                                                            |   |   |   needs memory                   |   |   |   FLUSH
//                                                                            |   |   |   |   needs mul                  |   |   |   |   RD valid?
//                                                                            |   |   |   |   |   needs div              |   |   |   |   |
//                                                                            |   |   |   |   |   |   Unsigned?          |   |   |   |   |
//                                                                            |   |   |   |   |   |   |   IMM?           |   |   |   |   |
//                                                                            |   |   |   |   |   |   |   |   MRET       |   |   |   |   |
//                                                                            |   |   |   |   |   |   |   |   |   ECALL  |   |   |   |   |
//                                                                            |   |   |   |   |   |   |   |   |   |      |   |   |   |   |
                                                                          //  14  13  12  11  10  9   8   7   6   5      4   3   2   1   0     
                                                                          //  0   1   2   3   4   5   6   7   8   9     10   11 12   13 14     

    io.decoded_instruction.bits.needs_ALU            := test(14)
    io.decoded_instruction.bits.needs_branch_unit    := test(13)
    io.decoded_instruction.bits.needs_CSRs           := test(12)
    io.decoded_instruction.bits.needs_memory         := test(11)
    io.decoded_instruction.bits.needs_mul            := test(10)
    io.decoded_instruction.bits.needs_div            := test(9)
    io.decoded_instruction.bits.SUBTRACT             := !test(8)     // FIXME: change this to UNSIGNED

    io.decoded_instruction.bits.IS_IMM               := test(7)     //
    io.decoded_instruction.bits.MRET                 := test(6)     //
    io.decoded_instruction.bits.ECALL                := test(5)     //

    io.decoded_instruction.bits.IMM                  := IMM
    io.decoded_instruction.bits.MULTIPLY             := test(10)

    when(test(10)){
        io.decoded_instruction.bits.memory_type              := memory_type_t.LOAD
    }.elsewhen(test(11)){
        io.decoded_instruction.bits.memory_type              := memory_type_t.STORE
    }.otherwise{
        io.decoded_instruction.bits.memory_type              := memory_type_t.NONE
    }

    io.decoded_instruction.bits.FENCE                := test(2)
    io.decoded_instruction.bits.FLUSH                := test(1)
    io.decoded_instruction.bits.RD_valid             := test(0)

    when(FUNCT3  === "b000".U){         // LB
        io.decoded_instruction.bits.access_width             := access_width_t.B
        //io.decoded_instruction.bits.mem_signed  := 1.B
    }.elsewhen(FUNCT3  === "b001".U){   // LHW
        io.decoded_instruction.bits.access_width             := access_width_t.HW
        //io.decoded_instruction.bits.mem_signed  := 1.B
    }.elsewhen(FUNCT3  === "b010".U){   // LW
        io.decoded_instruction.bits.access_width             := access_width_t.W
        //io.decoded_instruction.bits.mem_signed  := 1.B
    }.elsewhen(FUNCT3  === "b100".U){   // LBU
        io.decoded_instruction.bits.access_width             := access_width_t.B
        //io.decoded_instruction.bits.mem_signed  := 0.B
    }.elsewhen(FUNCT3  === "b101".U){   // LHWU
        io.decoded_instruction.bits.access_width             := access_width_t.HW
        //io.decoded_instruction.bits.mem_signed  := 0.B
    }




    // OLD CODE //

    val MULTIPLY    =   (instructionType === OP && FUNCT7 === 0x1.U)


    val SUBTRACT    =   (instructionType === OP && FUNCT7 === 0x20.U) || (instructionType === OP_IMM && FUNCT3 === 0x5.U && FUNCT7 === 0x20.U)


    val IS_IMM   =      (instructionType === OP_IMM)    || 
                        (instructionType === LUI)       || 
                        (instructionType === AUIPC)     || 
                        (instructionType === STORE)     || 
                        (instructionType === LOAD)      || 
                        (instructionType === BRANCH)    || 
                        (instructionType === JAL)       || 
                        (instructionType === JALR)      ||
                        ((instructionType === SYSTEM) && (FUNCT3 === 5.U || FUNCT3 === 6.U || FUNCT3 === 7.U))

    val needs_div            =   (instructionType === OP) && FUNCT7(0)
    val needs_mul            =   (instructionType === OP) && FUNCT7(0)
    val needs_branch_unit    =   (instructionType === BRANCH) || (instructionType === JAL) || (instructionType === JALR) || (instructionType === AUIPC)
    val needs_CSRs           =   (instructionType === SYSTEM) && (FUNCT3 === 0x0.U || FUNCT3 === 0x1.U || FUNCT3 === 0x2.U || FUNCT3 === 0x3.U || FUNCT3 === 0x5.U || FUNCT3 === 0x6.U || FUNCT3 === 0x7.U)
    val needs_ALU            =   ((instructionType === OP) &&
                                 ((FUNCT7 === 0x20.U) || (FUNCT7 === 0x00.U))) || 
                                 (instructionType === OP_IMM) || (instructionType === LUI)



    val ECALL               =   instruction === "b00000000000000000000000001110011".U 
    val MRET                =   instruction === "b00110000001000000000000001110011".U 

    val FENCE               =   ((instructionType === MISC_MEM) && FUNCT3 === 0x0.U)


    // Assign output

    io.decoded_instruction.valid    := io.instruction.valid
    io.instruction.ready            := io.decoded_instruction.ready

    initialReady.RS1_ready := false.B
    initialReady.RS2_ready := false.B

    io.decoded_instruction.bits.ready_bits      :=   initialReady

    io.decoded_instruction.bits.RD_valid := (instructionType === OP         || 
                                            instructionType === OP_IMM      || 
                                            instructionType === LOAD        || 
                                            instructionType === JAL         || 
                                            instructionType === JALR        || 
                                            instructionType === LUI         || 
                                            instructionType === AUIPC       || 
                                            (instructionType === SYSTEM &&  FUNCT3=/=0.U))     && 
                                            io.instruction.valid

    io.decoded_instruction.bits.RS1_valid            := (instructionType === OP         || 
                                                        instructionType === OP_IMM      || 
                                                        instructionType === LOAD        || 
                                                        instructionType === STORE       || 
                                                        instructionType === JALR        || 
                                                        (needs_CSRs && !IS_IMM) ||
                                                        instructionType === BRANCH)     && 
                                                        io.instruction.valid

    io.decoded_instruction.bits.RS2_valid            := (instructionType === OP         ||
                                                        instructionType === STORE       || 
                                                        instructionType === BRANCH)     && 
                                                        io.instruction.valid


    //io.decoded_instruction.bits.MULTIPLY             := MULTIPLY    // Multiply or Divide
    io.decoded_instruction.bits.SUBTRACT             := SUBTRACT    // subtract or arithmetic shift...
    io.decoded_instruction.bits.FLUSH                := 0.B       // FLUSH of ANY TYPE    (they all do the same thing)
    io.decoded_instruction.bits.IS_IMM               := IS_IMM   // subtract or arithmetic shift...


    when(instructionType === LOAD){
        io.decoded_instruction.bits.memory_type              := memory_type_t.LOAD
    }.elsewhen(instructionType === STORE){
        io.decoded_instruction.bits.memory_type              := memory_type_t.STORE
    }.otherwise{
        io.decoded_instruction.bits.memory_type              := memory_type_t.NONE
    }

    val needs_memory         =   (instructionType === STORE) || (instructionType === LOAD)


    io.decoded_instruction.bits.access_width                 := access_width_t.NONE
    io.decoded_instruction.bits.mem_signed  := 0.B


    when(FUNCT3  === "b000".U && needs_memory){ // LB
        io.decoded_instruction.bits.access_width             := access_width_t.B
        io.decoded_instruction.bits.mem_signed  := 1.B
    }.elsewhen(FUNCT3  === "b001".U && needs_memory){   // LHW
        io.decoded_instruction.bits.access_width             := access_width_t.HW
        io.decoded_instruction.bits.mem_signed  := 1.B
    }.elsewhen(FUNCT3  === "b010".U && needs_memory){   // LW
        io.decoded_instruction.bits.access_width             := access_width_t.W
        io.decoded_instruction.bits.mem_signed  := 1.B
    }.elsewhen(FUNCT3  === "b100".U && needs_memory){   // LBU
        io.decoded_instruction.bits.access_width             := access_width_t.B
        io.decoded_instruction.bits.mem_signed  := 0.B
    }.elsewhen(FUNCT3  === "b101".U && needs_memory){   // LHWU
        io.decoded_instruction.bits.access_width             := access_width_t.HW
        io.decoded_instruction.bits.mem_signed  := 0.B
    }






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

    val decoders: Seq[improved_decoder] = Seq.tabulate(fetchWidth) { w =>
        Module(new improved_decoder(coreParameters))
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

