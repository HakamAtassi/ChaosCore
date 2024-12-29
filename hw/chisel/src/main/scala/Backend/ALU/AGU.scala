
/* ------------------------------------------------------------------------------------
* Filename: AGU.scala
* Author: Hakam Atassi
* Date: May 23 2024
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

class AGU(coreParameters:CoreParameters) extends GALU(coreParameters){
    import coreParameters._

    io.FU_output.bits := 0.U.asTypeOf(new FU_output(coreParameters))

    ////////////////////
    // MEMORY REQUEST //
    ////////////////////
    // METADATA //
    //////////////


    val IMM                    =   imm
    val PC                     =   io.FU_input.bits.fetch_PC + (io.FU_input.bits.decoded_instruction.packet_index * fetchWidth.U)


    val is_load                =   io.FU_input.bits.decoded_instruction.memory_type === memory_type_t.LOAD   &&   io.FU_input.valid
    val is_store               =   io.FU_input.bits.decoded_instruction.memory_type === memory_type_t.STORE  &&   io.FU_input.valid
    val SB                     =   is_store && FUNCT3  === "b000".U               &&   io.FU_input.valid
    val SH                     =   is_store && FUNCT3  === "b001".U               &&   io.FU_input.valid
    val SW                     =   is_store && FUNCT3  === "b010".U               &&   io.FU_input.valid

    val LB                     =   is_load  && FUNCT3  === "b000".U               &&   io.FU_input.valid
    val LH                     =   is_load  && FUNCT3  === "b001".U               &&   io.FU_input.valid
    val LW                     =   is_load  && FUNCT3  === "b010".U               &&   io.FU_input.valid

    val LBU                    =   is_load  && FUNCT3  === "b100".U               &&   io.FU_input.valid
    val LHU                    =   is_load  && FUNCT3  === "b101".U               &&   io.FU_input.valid

    ////////////////////
    // GENERATE WRITE //
    ////////////////////
    val wr_data = Wire(UInt(32.W))

    wr_data := 0.U
    when(SB){wr_data := RS2_data & 0xFF.U}
    when(SH){wr_data := RS2_data & 0xFFFF.U}
    when(SW){wr_data := RS2_data.asUInt & "hFFFF_FFFF".U(32.W)}

    ///////////////////
    // GENERATE ADDR //
    ///////////////////
    val unsigned        = Wire(Bool())              // signed/unsigned
    val address         = Wire(UInt(32.W))

    unsigned        := LBU || LHU
    address         := RS1_data + sign_extend_var(imm, 21, 32)

    // Everything needed to perform the memory request (LSQ request)    

    FU_output.io.enq.valid              := RegNext(AGU_input_valid && !io.flush.valid)
    FU_output.io.enq.bits.PRD           := RegNext(PRD)             // LOAD DEST
    FU_output.io.enq.bits.is_unsigned   := RegNext(unsigned)        // SIGNED/UNSIGNED
    FU_output.io.enq.bits.address       := RegNext(address)         // ADDRESS
    FU_output.io.enq.bits.wr_data       := RegNext(wr_data)         // WR DATA
    FU_output.io.enq.bits.MOB_index     := RegNext(io.FU_input.bits.decoded_instruction.MOB_index)
    FU_output.io.enq.bits.ROB_index     := RegNext(io.FU_input.bits.decoded_instruction.ROB_index)
    FU_output.io.enq.bits.fetch_packet_index  := RegNext(io.FU_input.bits.decoded_instruction.packet_index)
    FU_output.io.enq.bits.memory_type   := RegNext(io.FU_input.bits.decoded_instruction.memory_type)
    FU_output.io.enq.bits.access_width  := RegNext(io.FU_input.bits.decoded_instruction.access_width)


    /////////////////
    // VALID/READY //
    /////////////////
    io.FU_input.ready               := 1.B


}
