/* ------------------------------------------------------------------------------------
* Filename: RF.scala
* Author: Hakam Atassi
* Date: May 23 2024
* Description: The "merged" register files. 
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

/*
class FU(parameters:Parameters) extends Module{
    import parameters._

    val io = IO(new Bundle{
        // Input
        val FU_input      =   Flipped(Decoupled(new read_decoded_instruction(coreConfig=coreConfig, fetchWidth=fetchWidth, ROBEntires=ROBEntires)))
        val RS_entry      =   new FU_input(coreConfig=coreConfig, ROBEntires=ROBEntires, physicalRegCount=physicalRegCount)
        
        // Output
        val FU_output     =   new FU_output(physicalRegCount)
    })

    // misaligned fetch exception ??

    // Operand data
    val RS1_data    =   io.FU_input.RS1_data
    val RS2_data    =   io.FU_input.RS2_data
    val imm         =   io.FU_input.IMM
    val PC          =   io.FU_input.PC + io.FU_input.packet_index

    // Dest reg
    val RD          =   io.FU_input.RD

    //////////////////////////
    //////////////////////////
    //////////////////////////

    val taken_address     = RegInit(UInt(32.W), 0.U)
    val not_taken_address = RegInit(UInt(32.W), 0.U)

    val comp_result = RegInit(Bool(), 0.B)
    val target_addr = Wire(UInt(32.W))

    val arithmetic_result = Wire(UInt(32.W))

    val add_result = RegInit(0.U(32.W))
    val sub_result = RegInit(0.U(32.W))
    val slt_result = RegInit(0.U(32.W))
    val and_result = RegInit(0.U(32.W))
    val or_result  = RegInit(0.U(32.W))
    val xor_result = RegInit(0.U(32.W))
    val sll_result = RegInit(0.U(32.W))
    val srl_result = RegInit(0.U(32.W))
    val sra_result = RegInit(0.U(32.W))

    // Either use RS1 / RS2 or RS1 / imm based on is_imm flag
    val operand2 = Mux(is_imm, imm, RS2_data)

    // Perform arithmetic operations
    add_result := RS1_data + operand2
    sub_result := RS1_data - operand2
    slt_result := Mux(RS1_data.asSInt < operand2.asSInt, 1.U, 0.U) // Set less than
    and_result := RS1_data & operand2
    or_result  := RS1_data | operand2
    xor_result := RS1_data ^ operand2
    sll_result := RS1_data << operand2(4,0) // Logical left shift
    srl_result := RS1_data >> operand2(4,0) // Logical right shift
    sra_result := (RS1_data.asSInt >> operand2(4,0)).asUInt // Arithmetic right shift




    io.FU_output := DontCare

}
*/