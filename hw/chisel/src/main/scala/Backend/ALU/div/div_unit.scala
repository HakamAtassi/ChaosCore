/* ------------------------------------------------------------------------------------
* Filename: div_unit.scala
* Author: Alisher Rakhimov
* Date: Sep 12 2024
* Description: The multiplication implementation of a generic ALU
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

class div_unit(coreParameters:CoreParameters) extends GALU(coreParameters){
    import coreParameters._
    import InstructionType._

    val divider = Module(new non_restoring_divider)
    val decoded_instr_q = Module(new Queue(new read_decoded_instruction(coreParameters), 33, flow=false, hasFlush=true, useSyncReadMem=false))

    divider.io := DontCare
    decoded_instr_q.io.enq.bits := DontCare
    divider.io.dividend.valid := 0.B
    divider.io.divisor.valid := 0.B
    decoded_instr_q.io.enq.valid := 0.B
    decoded_instr_q.io.flush.get := io.flush.valid
    divider.io.flush := io.flush.valid

    when (div_unit_input_valid){
        decoded_instr_q.io.enq.bits := io.FU_input.bits
        decoded_instr_q.io.enq.valid := 1.B
        divider.io.dividend.valid := 1.B
        divider.io.divisor.valid := 1.B
        when (DIV || REM){
            divider.io.dividend.bits := operand1_signed.asUInt
            divider.io.divisor.bits  := operand2_signed.asUInt
            divider.io.signed        := 1.B
        }.elsewhen(DIVU || REMU){
            divider.io.dividend.bits := operand1_unsigned
            divider.io.divisor.bits  := operand2_unsigned
            divider.io.signed        := 0.B
        }
    }

    val DIV_complete = WireInit(Bool(), 0.B)
    val DIVU_complete = WireInit(Bool(), 0.B)
    val REM_complete = WireInit(Bool(), 0.B)
    val REMU_complete = WireInit(Bool(), 0.B)

    // div_result      := (operand1_signed / operand2_signed).asUInt
    // divu_result     := operand1_unsigned / operand2_unsigned
    // rem_result      := (operand1_signed % operand2_signed).asUInt
    // remu_result     := operand1_unsigned % operand2_unsigned

    // when(operand2_unsigned === 0.U){
    //     div_result := "hffffffff".U
    //     divu_result := "hffffffff".U
    //     rem_result := operand1_unsigned
    //     remu_result := operand1_unsigned
    // }

    FU_output.io.enq.bits := DontCare
    divider.io.quotient.ready := 1.B
    divider.io.remainder.ready := 1.B
    decoded_instr_q.io.deq.ready := 0.B
    FU_output.io.enq.valid :=   0.B

    when(divider.io.quotient.valid && divider.io.remainder.valid){
        decoded_instr_q.io.deq.ready := 1.B

        DIV_complete      :=   decoded_instr_q.io.deq.bits.decoded_instruction.MULTIPLY && decoded_instr_q.io.deq.bits.decoded_instruction.FUNCT3 === "b100".U
        DIVU_complete     :=   decoded_instr_q.io.deq.bits.decoded_instruction.MULTIPLY && decoded_instr_q.io.deq.bits.decoded_instruction.FUNCT3 === "b101".U
        REM_complete      :=   decoded_instr_q.io.deq.bits.decoded_instruction.MULTIPLY && decoded_instr_q.io.deq.bits.decoded_instruction.FUNCT3 === "b110".U
        REMU_complete     :=   decoded_instr_q.io.deq.bits.decoded_instruction.MULTIPLY && decoded_instr_q.io.deq.bits.decoded_instruction.FUNCT3 === "b111".U

        when(DIV_complete || DIVU_complete){
            arithmetic_result := divider.io.quotient.bits
        }.elsewhen(REM_complete || REMU_complete){
            arithmetic_result := divider.io.remainder.bits
        }

        dontTouch(arithmetic_result)

        // Not a branch unit (all FUs share the same output channel)
        FU_output.io.enq.valid                      :=   1.B
        FU_output.io.enq.bits.branch_valid          :=   0.B
        FU_output.io.enq.bits.fetch_PC              :=   decoded_instr_q.io.deq.bits.fetch_PC
        FU_output.io.enq.bits.fetch_packet_index    :=   decoded_instr_q.io.deq.bits.decoded_instruction.packet_index

        // Actual Outputs
        FU_output.io.enq.bits.PRD                   :=   decoded_instr_q.io.deq.bits.decoded_instruction.PRD
        FU_output.io.enq.bits.RD_valid              :=   decoded_instr_q.io.deq.bits.decoded_instruction.RD_valid

        FU_output.io.enq.bits.RD_data               :=   arithmetic_result

        FU_output.io.enq.bits.MOB_index             :=   decoded_instr_q.io.deq.bits.decoded_instruction.MOB_index
        FU_output.io.enq.bits.address               :=   0.U

        FU_output.io.enq.bits.ROB_index             :=   decoded_instr_q.io.deq.bits.decoded_instruction.ROB_index
    }

}


