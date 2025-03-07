/* ------------------------------------------------------------------------------------
* Filename: branch_unit.scala
* Author: Hakam Atassi
* Date: Sep 12 2024
* Description: The branch implementation of a generic ALU
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


class branch_unit(coreParameters:CoreParameters) extends GALU(coreParameters){
    import coreParameters._

    val IMM     = Wire(UInt(32.W))

    IMM        :=  (io.FU_input.bits.decoded_instruction.IMM).asUInt

    EQ         :=  (RS1_data.asSInt === RS2_data.asSInt) && BEQ
    NE         :=  (RS1_data.asSInt =/= RS2_data.asSInt) && BNE
    LT         :=  (RS1_data.asSInt   < RS2_data.asSInt) && BLT
    GE         :=  (RS1_data.asSInt  >= RS2_data.asSInt) && BGE
    LTU        :=  (RS1_data.asUInt   < RS2_data.asUInt) && BLTU
    GEU        :=  (RS1_data.asUInt  >= RS2_data.asUInt) && BGEU


    val branch_taken   = Wire(Bool())
    val target_address = Wire(UInt(32.W))

    branch_taken    := 0.B
    target_address  := instruction_PC + 4.U  // default address is the next fetch_PC
    

    val SIMM_12_0 = Wire(SInt(32.W))
    val IMM_12_0  = Wire(UInt(32.W))

    val SIMM_20_0 = Wire(SInt(32.W))
    val IMM_20_0  = Wire(UInt(32.W))

    val SIMM_11_0 = Wire(SInt(32.W))
    val IMM_11_0  = Wire(UInt(32.W))

    SIMM_12_0 := IMM(12,0).asSInt
    IMM_12_0 := SIMM_12_0.asUInt

    SIMM_20_0 := IMM(20,0).asSInt
    IMM_20_0 := SIMM_20_0.asUInt

    SIMM_11_0 := IMM(11,0).asSInt
    IMM_11_0 := SIMM_11_0.asUInt


    auipc_result    := (instruction_PC + Cat(imm, 0.U(12.W))) // same here???

    arithmetic_result   := instruction_PC + 4.U


    when(EQ)        {branch_taken := 1.B; target_address := instruction_PC + IMM_12_0}
    .elsewhen(NE)   {branch_taken := 1.B; target_address := instruction_PC + IMM_12_0}
    .elsewhen(LT)   {branch_taken := 1.B; target_address := instruction_PC + IMM_12_0}
    .elsewhen(GE)   {branch_taken := 1.B; target_address := instruction_PC + IMM_12_0}
    .elsewhen(LTU)  {branch_taken := 1.B; target_address := instruction_PC + IMM_12_0}
    .elsewhen(GEU)  {branch_taken := 1.B; target_address := instruction_PC + IMM_12_0}
    .elsewhen(JAL)  {branch_taken := 1.B; target_address := instruction_PC + IMM_20_0}
    .elsewhen(JALR) {branch_taken := 1.B; target_address := RS1_data       + IMM_11_0}
    .elsewhen(AUIPC){branch_taken := 0.B; target_address := 0.U; arithmetic_result   := auipc_result}   




    // PC of branch instruction and packet index (to access ROB bank)

    FU_output.io.enq.valid                      :=  RegNext(branch_unit_input_valid)
    FU_output.io.enq.bits.fetch_PC              :=  RegNext(io.FU_input.bits.fetch_PC)
    FU_output.io.enq.bits.fetch_packet_index    :=  RegNext(io.FU_input.bits.decoded_instruction.packet_index)

    // FIXME: why branch valid and CTRL?
    FU_output.io.enq.bits.branch_valid      :=   RegNext(io.FU_input.bits.decoded_instruction.CTRL)
    FU_output.io.enq.bits.CTRL      :=           RegNext(io.FU_input.bits.decoded_instruction.CTRL)

    // Not a branch unit (all FUs share the same output channel)
    FU_output.io.enq.bits.branch_taken      :=      RegNext(branch_taken)
    FU_output.io.enq.bits.target_address    :=      RegNext(target_address)

    // Actual Outputs
    FU_output.io.enq.bits.PRD               :=      RegNext(io.FU_input.bits.decoded_instruction.PRD)
    FU_output.io.enq.bits.RD_valid          :=      RegNext(io.FU_input.bits.decoded_instruction.RD_valid)
    FU_output.io.enq.bits.RD_data           :=      RegNext(arithmetic_result)
    FU_output.io.enq.bits.ROB_index         :=      RegNext(io.FU_input.bits.decoded_instruction.ROB_index)
    FU_output.io.enq.bits.MOB_index         :=      RegNext(io.FU_input.bits.decoded_instruction.MOB_index)
    FU_output.io.enq.bits.address           :=      0.U
    

    dontTouch(EQ)
    dontTouch(NE)
    dontTouch(LT)
    dontTouch(GE)
    dontTouch(LTU)
    dontTouch(GEU)
    dontTouch(JAL)
    dontTouch(JALR)
    dontTouch(AUIPC)
    dontTouch(IMM_20_0)
    dontTouch(IMM_11_0)

}
