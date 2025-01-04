/* ------------------------------------------------------------------------------------
* Filename: mul_unit.scala
* Author: Hakam Atassi
* Date: Sep 12 2024
* Description: The multiplication implementation of a generic ALU
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

class mul_unit(coreParameters:CoreParameters) extends GALU(coreParameters){
    import coreParameters._
    import InstructionType._

    val mul_result_64_s_s = sign_extend(operand1_signed.asUInt, 64) * sign_extend(operand2_signed.asUInt, 64)
    val mul_result_64_s_u = sign_extend(operand1_signed.asUInt, 64) * Cat(0.U(32.W), operand2_unsigned) 
    val mul_result_64_u_u = (Cat(0.U(32.W),operand1_unsigned)       * Cat(0.U(32.W), operand2_unsigned))

    mul_result      := mul_result_64_s_s(31,0)
    mulh_result     := mul_result_64_s_s(63,32)
    mulsu_result    := mul_result_64_s_u(63,32)
    mulu_result     := mul_result_64_u_u(63,32)
    div_result      := (operand1_signed / operand2_signed).asUInt
    divu_result     := operand1_unsigned / operand2_unsigned
    rem_result      := (operand1_signed % operand2_signed).asUInt
    remu_result     := operand1_unsigned % operand2_unsigned

    when(operand2_unsigned === 0.U){
        div_result := "hffffffff".U
        divu_result := "hffffffff".U
        rem_result := operand1_unsigned
        remu_result := operand1_unsigned
    }

    dontTouch(MUL)
    dontTouch(MULH)
    dontTouch(MULSU)

    when(MUL){
        arithmetic_result   := mul_result
    }.elsewhen(MULH){
        arithmetic_result   := mulh_result
    }.elsewhen(MULSU){
        arithmetic_result   := mulsu_result
    }.elsewhen(MULU){
        arithmetic_result   := mulu_result
    }.elsewhen(DIV){
        arithmetic_result   := div_result
    }.elsewhen(DIVU){
        arithmetic_result   := divu_result
    }.elsewhen(REM){
        arithmetic_result   := rem_result
    }.elsewhen(REMU){
        arithmetic_result   := remu_result
    }


    // Not a branch unit (all FUs share the same output channel)

    FU_output.io.enq.valid                      :=   RegNext(mult_unit_input_valid)
    FU_output.io.enq.bits.branch_valid          :=   0.B
    FU_output.io.enq.bits.fetch_PC              :=   RegNext(io.FU_input.bits.fetch_PC)
    FU_output.io.enq.bits.fetch_packet_index    :=   RegNext(io.FU_input.bits.decoded_instruction.packet_index)

    // Actual Outputs
    FU_output.io.enq.bits.PRD                   :=   RegNext(io.FU_input.bits.decoded_instruction.PRD)
    FU_output.io.enq.bits.RD_valid              :=   RegNext(io.FU_input.bits.decoded_instruction.RD_valid)
    FU_output.io.enq.bits.RD_data               :=   arithmetic_result

    FU_output.io.enq.bits.MOB_index             :=   RegNext(io.FU_input.bits.decoded_instruction.MOB_index)
    FU_output.io.enq.bits.address               :=   0.U

    FU_output.io.enq.bits.ROB_index             :=   RegNext(io.FU_input.bits.decoded_instruction.ROB_index)

}


