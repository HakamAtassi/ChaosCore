/* ------------------------------------------------------------------------------------
* Filename: CSR.scala
* Author: Hakam Atassi
* Date: Sep 15 2024
* Description: The core CSRs
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



class CSRs(coreParameters:CoreParameters) extends GALU(coreParameters){

    import coreParameters._


    //////////////////////////
    // PERFORMANCE COUNTERS //
    //////////////////////////

    val cycle_reg    = RegInit(UInt(64.W), 0.U)
    val time_reg     = RegInit(UInt(64.W), 0.U)
    val instret_reg  = RegInit(UInt(64.W), 0.U)

    // 0xC00 - 0xC1F
    val cyclel    = cycle_reg(31,0)
    val timel     = time_reg(31,0)
    val instretl  = instret_reg(31,0)

    // 0xC80 - 0xC9F
    val cycleh   = cycle_reg(63, 32)
    val timeh    = time_reg(63, 32)
    val instreth = instret_reg(63, 32)


    // PERFORMANCE COUNTER UPDATES

    cycle_reg   := cycle_reg   + 1.U
    time_reg    := time_reg    + 1.U
    instret_reg := instret_reg + PopCount(io.partial_commit.valid)


    ////////////////////////
    // SELECTION & OUTPUT //
    ////////////////////////

    // this is placeholder until I implemement an actual CSR file
    val CSR_out    = Reg(UInt(32.W))

    when(CSR_addr === 0xC00.U){
        CSR_out := cyclel
    }.elsewhen(CSR_addr === 0xC01.U){
        CSR_out := timel
    }.elsewhen(CSR_addr === 0xC02.U){
        CSR_out := instretl
    }.elsewhen(CSR_addr === 0xC80.U){
        CSR_out := timel
    }.elsewhen(CSR_addr === 0xC81.U){
        CSR_out := cycleh
    }.elsewhen(CSR_addr === 0xC82.U){
        CSR_out := instreth
    }






    // ALU pipelined; always ready
    io.FU_input.ready                       := 1.B    

    // Not a branch unit (all FUs share the same output channel)
    io.FU_output.bits.branch_valid          := 0.B

    io.FU_output.bits.fetch_PC              := RegNext(io.FU_input.bits.fetch_PC)
    io.FU_output.bits.fetch_packet_index    := RegNext(io.FU_input.bits.decoded_instruction.packet_index)

    // Actual Outputs
    io.FU_output.bits.PRD                   := RegNext(io.FU_input.bits.decoded_instruction.PRD)
    io.FU_output.bits.RD_valid              := RegNext(io.FU_input.bits.decoded_instruction.RD_valid)
    io.FU_output.bits.RD_data               := CSR_out


    io.FU_output.bits.MOB_index             := RegNext(io.FU_input.bits.decoded_instruction.MOB_index)
    io.FU_output.bits.address               := 0.U

    io.FU_output.bits.ROB_index             := RegNext(io.FU_input.bits.decoded_instruction.ROB_index)

    input_valid                             := CSR_input_valid

    dontTouch(CSR_input_valid)
    dontTouch(input_valid)

}