/* ------------------------------------------------------------------------------------
* Filename: FPU.scala
* Author: Hakam Atassi
* Date: March 8 2025
* Description: The Core's monolithic floating point unit. 
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

class FPU(coreParameters:CoreParameters) extends GALU(coreParameters){
    import coreParameters._

    // Supports all standard FPU operations:
    // FMA 
    // FMS
    // Add
    // sub, 
    // mul
    // div
    // square root
    // convert
    // compare
    // etc...


    // need a scoreboarding mechanism of some kind




 


    // Not a branch unit (all FUs share the same output channel)

    FU_output.io.enq.valid                      :=  RegNext(ALU_input_valid)
    FU_output.io.enq.bits.branch_valid          :=  0.B
    FU_output.io.enq.bits.fetch_PC              :=  RegNext(io.FU_input.bits.fetch_PC)
    FU_output.io.enq.bits.fetch_packet_index    :=  RegNext(io.FU_input.bits.decoded_instruction.packet_index)

    // Actual Outputs
    FU_output.io.enq.bits.PRD                   :=  RegNext(io.FU_input.bits.decoded_instruction.PRD)
    FU_output.io.enq.bits.RD_valid              :=  RegNext(io.FU_input.bits.decoded_instruction.RD_valid)
    FU_output.io.enq.bits.RD_data               :=  RegNext(arithmetic_result)

    FU_output.io.enq.bits.MOB_index             :=  RegNext(io.FU_input.bits.decoded_instruction.MOB_index)
    FU_output.io.enq.bits.address               :=  0.U
    FU_output.io.enq.bits.ROB_index             :=  RegNext(io.FU_input.bits.decoded_instruction.ROB_index)


}



