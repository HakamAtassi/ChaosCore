/* ------------------------------------------------------------------------------------
* Filename: ALU.scala
* Author: Hakam Atassi
* Date: Sep 2024
* Description: The Core Functional Units
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


class ALU(coreParameters:CoreParameters) extends GALU(coreParameters){
    import coreParameters._
    import InstructionType._

    // misaligned fetch exception ??

    // Perform arithmetic operations
    add_result      := operand1_unsigned + operand2_unsigned
    sub_result      := operand1_unsigned - operand2_unsigned
    xor_result      := operand1_unsigned ^ operand2_unsigned
    or_result       := operand1_unsigned | operand2_unsigned
    and_result      := operand1_unsigned & operand2_unsigned


    sll_result      := RS1_unsigned << shamt
    srl_result      := RS1_unsigned >> shamt
    sra_result      := RS1_signed   >> shamt


    slt_result      := RS1_signed < operand2_signed
    sltu_result     := RS1_unsigned < operand2_unsigned

    lui_result      := Cat(imm, 0.U(12.W)) 

    dontTouch(lui_result)
    dontTouch(LUI)


    /////////////
    // CONTROL //
    /////////////

    arithmetic_result := 0.U
    when(ADD)       {
        arithmetic_result   := add_result
    }.elsewhen(SUB) {
        arithmetic_result   := sub_result
    }.elsewhen(XOR) {
        arithmetic_result   := xor_result
    }.elsewhen(OR)  {
        arithmetic_result   := or_result
    }.elsewhen(AND) {
        arithmetic_result   := and_result
    }.elsewhen(SLL) {
        arithmetic_result   := sll_result
    }.elsewhen(SRL) {
        arithmetic_result   := srl_result
    }.elsewhen(SRA) {
        arithmetic_result   := sra_result.asUInt
    }.elsewhen(SLT) {
        arithmetic_result   := slt_result
    }.elsewhen(SLTU){
        arithmetic_result   := sltu_result
    }.elsewhen(LUI){
        arithmetic_result   := lui_result
    } 

    dontTouch(LUI)
    dontTouch(ADD)
    dontTouch(SUB)
    dontTouch(XOR)
    dontTouch(OR)
    dontTouch(AND)
    dontTouch(SLL)
    dontTouch(SRA)
    dontTouch(imm)
    dontTouch(lui_result)
    dontTouch(RS1_signed)
    dontTouch(shamt)
    dontTouch(sra_result)
    dontTouch(SRA)
    dontTouch(SRL)
    dontTouch(operand1_unsigned)
    dontTouch(sub_result)
    dontTouch(add_result)
    dontTouch(ADD)
    dontTouch(SUB)


    // Not a branch unit (all FUs share the same output channel)

    FU_output.io.enq.valid                      :=  RegNext(ALU_input_valid)
    FU_output.io.enq.bits.branch_valid          :=  0.B
    FU_output.io.enq.bits.fetch_PC              :=  RegNext(io.FU_input.bits.fetch_PC)
    FU_output.io.enq.bits.fetch_packet_index    :=  RegNext(io.FU_input.bits.decoded_instruction.packet_index)

    // Actual Outputs
    FU_output.io.enq.bits.PRD                   :=  RegNext(io.FU_input.bits.decoded_instruction.PRD)
    FU_output.io.enq.bits.RD_valid              :=  RegNext(io.FU_input.bits.decoded_instruction.RD_valid)
    FU_output.io.enq.bits.RD_data               :=  RegNext(arithmetic_result)

    //FU_output.io.enq.bits.MOB_index             :=  RegNext(io.FU_input.bits.decoded_instruction.MOB_index)
    FU_output.io.enq.bits.address               :=  0.U
    FU_output.io.enq.bits.ROB_index             :=  RegNext(io.FU_input.bits.decoded_instruction.ROB_index)


}


