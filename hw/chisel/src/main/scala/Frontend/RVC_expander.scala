/* ------------------------------------------------------------------------------------
* Filename: RVC_expander.scala
* Author: Alisher Rakhimov
* Date: Oct 13 2024
* Description: Decodes and expands compressed 16-bit instructions into the regular 32-bit instructions
* License: MIT
*
* Copyright (c) 2024 by Alisher Rakhimov
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

class RVC_expander(coreParameters:CoreParameters) extends Module{
    import coreParameters._
    import InstructionType._
    val io = IO(new Bundle{
        val compressed_instr = Input(UInt(16.W))

        val instruction = Output(UInt(32.W))
    })

    val instruction = io.compressed_instr

    val expanded_instruction = Wire(UInt(32.W))
    expanded_instruction := 0.U

    val valid_compressed = instruction(1,0) =/= 3.U

    val Q0 = instruction(1,0) === 0.U
    val Q1 = instruction(1,0) === 1.U
    val Q2 = instruction(1,0) === 2.U

    val FUNCT3 = instruction(15,13)
    val FUNCT6 = instruction(15,10)

    val RD = instruction(11,7)
    val lower_imm = instruction(6,2)
    val imm_5 = instruction(12)

    //Quadrant 0
    val ADDI4SPN   = FUNCT3 === "b000".U && Q0 && (instruction(12,5) =/= 0.U)
    val LW         = FUNCT3 === "b010".U && Q0 
    val SW         = FUNCT3 === "b110".U && Q0

    //val FLD        = FUNCT3 === "b001".U && Q0  
    //val FLW        = FUNCT3 === "b011".U && Q0 
    //val FSD        = FUNCT3 === "b101".U && Q0 
    //val FSW        = FUNCT3 === "b111".U && Q0 

    //Quadrant 1
    val NOP        = FUNCT3 === "b000".U && Q1 && (RD === 0.U) && (Cat(imm_5, lower_imm) =/= 0.U)
    val ADDI       = FUNCT3 === "b000".U && Q1 && (RD =/= 0.U) && (Cat(imm_5, lower_imm) =/= 0.U)
    val JAL        = FUNCT3 === "b001".U && Q1
    val LI         = FUNCT3 === "b010".U && Q1 && (RD =/= 0.U) 
    val ADDI16SP   = FUNCT3 === "b011".U && Q1 && (RD === 2.U)
    val LUI        = FUNCT3 === "b011".U && Q1 && (RD =/= 0.U) && (RD =/= 2.U) && (lower_imm =/= 0.U)

    val SRLI       = FUNCT6 === "b10000".U && Q1 && (lower_imm =/= 0.U) && (imm_5 === 0.U) 
    val SRAI       = FUNCT6 === "b10001".U && Q1 && (lower_imm =/= 0.U) && (imm_5 === 0.U) 
    val ANDI       = FUNCT3 === "b100".U && instruction(11,10) === "b10".U && Q1
    val SUB        = FUNCT6 === "b10011".U && Q1 && (instruction(6,5) === 0.U)
    val XOR        = FUNCT6 === "b10001".U && Q1 && (instruction(6,5) === 1.U)
    val OR         = FUNCT6 === "b10001".U && Q1 && (instruction(6,5) === 2.U)
    val AND        = FUNCT6 === "b10001".U && Q1 && (instruction(6,5) === 3.U)

    val J          = FUNCT3 === "b101".U && Q1

    val BEQZ       = FUNCT3 === "b110".U && Q1
    val BNEZ       = FUNCT3 === "b111".U && Q1

    //Quadrant 2
    val SLLI       = FUNCT3 === "b000".U && Q2 && (imm_5 === 0.U) && (lower_imm =/= 0.U) && (RD =/= 0.U)
    val JR         = FUNCT3 === "b100".U && Q2 && (imm_5 === 0.U) && (lower_imm === 0.U) && (RD =/= 0.U)
    val MV         = FUNCT3 === "b100".U && Q2 && (RD =/= 0.U) && (lower_imm =/= 0.U)
    val EBREAK     = FUNCT3 === "b100".U && Q2 && (instruction(12,2) === "b10000000000".U)
    val JALR       = FUNCT3 === "b100".U && Q2 && (imm_5 === 1.U) && (lower_imm === 0.U) && (RD =/= 0.U)
    val ADD        = FUNCT3 === "b100".U && Q2 && (imm_5 === 1.U) && (lower_imm =/= 0.U) && (RD =/= 0.U)

    val LWSP       = FUNCT3 === "b010".U && Q2 && (RD =/= 0.U)
    val SWSP       = FUNCT3 === "b110".U && Q2

    //val FLDSP      = FUNCT3 === "b001".U && Q2
    //val FLWSP      = FUNCT3 === "b011".U && Q2
    //val FSDSP      = FUNCT3 === "b101".U && Q2
    //val SWSP       = FUNCT3 === "b110".U && Q2
    //val FSWSP      = FUNCT3 === "b111".U && Q2

    //Generate Immediates
    val lwsp_imm = Cat(instruction(3,2), instruction(12), instruction(6,4), 0.U(2.W))
    val swsp_imm = Cat(instruction(8,7), instruction(12,9), 0.U(2.W))
    val lsw_imm = Cat(instruction(5), instruction(12,10), instruction(6), 0.U(2.W))
    val j_imm = Cat(instruction(12), instruction(8), instruction(10,9), instruction(6), instruction(7), instruction(2), instruction(11), instruction(5,3), 0.U(1.W))
    val b_imm = Cat(instruction(12), instruction(6,5), instruction(2), instruction(11,10), instruction(4,3), 0.U(1.W))
    val shamt = Cat(instruction(12), instruction(6,2))
    val lui_imm = Cat(shamt, 0.U(12.W))
    val addi16sp_imm = Cat(instruction(12), instruction(4,3), instruction(5), instruction(2), instruction(6), 0.U(4.W))
    val addi4spn_imm = Cat(instruction(10,7), instruction(12,11), instruction(5), instruction(6), 0.U(2.W))

    //Formats
    val CR  = JR || JALR || MV || ADD 
    val CI  = LWSP || LI || LUI ||ADDI || ADDI16SP ||SLLI
    val CSS = SWSP
    val CIW = ADDI4SPN
    val CL  = LW
    val CS  = SW
    val CA  = AND || OR || XOR || SUB
    val CB  = BEQZ || BNEZ || SRLI || SRAI || ANDI
    val CJ  = J || JAL


    //Expanded Codes
    val decoded_instr = Wire(new expanded_instruction(coreParameters))
    
    decoded_instr.opcode := 0.U
    decoded_instr.rs1 := 0.U
    decoded_instr.rs2 := 0.U
    decoded_instr.rd := 0.U
    decoded_instr.funct3 := 0.U
    decoded_instr.funct7 := 0.U
    decoded_instr.imm := 0.U

    //Get Correct Immediate
    when(LWSP){
        decoded_instr.imm := lwsp_imm
    }.elsewhen(SWSP){
        decoded_instr.imm := swsp_imm
    }.elsewhen(LW || SW){
        decoded_instr.imm := lsw_imm
    }.elsewhen(CJ){
        decoded_instr.imm := sign_extend(j_imm, 32)
    }.elsewhen(BNEZ || BEQZ || ANDI){
        decoded_instr.imm := sign_extend(b_imm, 32)
    }.elsewhen(SRLI || SRAI || SLLI){
        decoded_instr.imm := shamt
    }.elsewhen(ADDI || LI){
        decoded_instr.imm := sign_extend(shamt, 32)
    }.elsewhen(LUI){
        decoded_instr.imm := sign_extend(lui_imm, 32)
    }.elsewhen(ADDI16SP){
        decoded_instr.imm := sign_extend(addi16sp_imm, 32)
    }.elsewhen(ADDI4SPN){
        decoded_instr.imm := addi4spn_imm
    }

    //Get opcode
    when(LW || LWSP){
        decoded_instr.opcode := "b0000011".U
    }.elsewhen (SW || SWSP) {
        decoded_instr.opcode := "b0100011".U
        expanded_instruction := Cat(decoded_instr.imm(11,5), decoded_instr.rs2, decoded_instr.rs1, decoded_instr.funct3, decoded_instr.imm(4,0), decoded_instr.opcode)
    }.elsewhen (JAL || J){
        decoded_instr.opcode := "b1101111".U
        expanded_instruction := Cat(decoded_instr.imm(20), decoded_instr.imm(10,1), decoded_instr.imm(11), decoded_instr.imm(19,12), decoded_instr.rd, decoded_instr.opcode)
    }.elsewhen (JALR || JR){
        decoded_instr.opcode := "b1100111".U
    }.elsewhen (BEQZ || BNEZ) {
        decoded_instr.opcode := "b1100011".U
        expanded_instruction := Cat(decoded_instr.imm(12), decoded_instr.imm(10,5), decoded_instr.rs2, decoded_instr.rs1, decoded_instr.funct3, decoded_instr.imm(4,1), decoded_instr.imm(11), decoded_instr.opcode)
    }.elsewhen (LUI) {
        decoded_instr.opcode := "b0110111".U
        expanded_instruction := Cat(decoded_instr.imm(31,12), decoded_instr.rd, decoded_instr.opcode)
    }.elsewhen (EBREAK) {
        decoded_instr.opcode := "b1110011".U
    }.elsewhen (SUB || XOR || OR || AND || ADD || MV) {
        decoded_instr.opcode := "b0110011".U
        expanded_instruction := Cat(decoded_instr.funct7, decoded_instr.rs2, decoded_instr.rs1, decoded_instr.funct3, decoded_instr.rd, decoded_instr.opcode)
    }.elsewhen (ADDI4SPN || NOP || ADDI || LI || ADDI16SP || SRLI || SRAI || ANDI || SLLI) {
        decoded_instr.opcode := "b0010011".U
    }

    //funct3
    when(LW || LWSP || SW || SWSP) {
        decoded_instr.funct3 := 0x2.U
    }.elsewhen (BNEZ || SLLI) {
        decoded_instr.funct3 := 0x1.U
    }.elsewhen (XOR) {
        decoded_instr.funct3 := 0x4.U
    }.elsewhen (OR) {
        decoded_instr.funct3 := 0x6.U
    }.elsewhen (AND) {
        decoded_instr.funct3 := 0x7.U
    }.elsewhen (SRLI || SRAI) {
        decoded_instr.funct3 := 0x5.U
    }

    //funct7
    when(SUB || SRAI){
        decoded_instr.funct7 := 0x20.U
    }

    val rd_rs1 = Mux(CR || CI, instruction(11,7), Cat(0x1.U(2.W), instruction(9,7)))
    val rd_rs2 = Mux(CR || CSS, instruction(6,2), Cat(0x1.U(2.W), instruction(4,2)))

    //LI and LUI only RD
    //BEQZ and BNEZ only RS1
    //JR and JALR only RS1/2
    when(CR || CI || CA || CB){
        decoded_instr.rs1 := rd_rs1
        decoded_instr.rd := rd_rs1
    }.elsewhen(CL || CS){
        decoded_instr.rs1 := rd_rs1
    }

    when(CR || CSS || CS || CA){
        decoded_instr.rs2 := rd_rs2
    }.elsewhen(CIW || CL){
        decoded_instr.rd := rd_rs2
    }

    when(JAL || JALR){
        decoded_instr.rd := 1.U
    }

    when(J || JR){
        decoded_instr.rd := 0.U
    }

    when(LWSP || SWSP || ADDI4SPN || ADDI16SP){
        decoded_instr.rs1 := 2.U
    }

    when(ADDI16SP){
        decoded_instr.rd := 2.U
    }

    when(LI || MV){
        decoded_instr.rs1 := 0.U
    }

    //Contruct Expanded Instruction
    when(LW || LWSP || ADDI4SPN || NOP || ADDI || LI || ADDI16SP || SRLI || SRAI || ANDI || SLLI || EBREAK || JALR || JR){
        expanded_instruction := Cat(decoded_instr.imm(11,0), decoded_instr.rs1, decoded_instr.funct3, decoded_instr.rd, decoded_instr.opcode)
    }

    io.instruction := expanded_instruction

}