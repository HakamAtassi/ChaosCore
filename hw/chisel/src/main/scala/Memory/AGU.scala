
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
import circt.stage.ChiselStage 

import chisel3.util._

class AGU(parameters:Parameters) extends Module{
    import parameters._
    val io = IO(new Bundle{
        // Flush
        val flush                   =   Input(Bool())

        // Instruction Input
        val FU_input                =   Flipped(Decoupled(new read_decoded_instruction(parameters)))

        // Instruction Output
        val FU_output               =   ValidIO(new FU_output(parameters))                  // Input to LSQ
    })

    io.FU_output := DontCare

    ////////////////////
    // MEMORY REQUEST //
    ////////////////////
    // METADATA //
    //////////////
    val _imm                   =   Wire(SInt(32.W))
    val imm                    =   Wire(UInt(32.W))

    _imm                      :=  (io.FU_input.bits.decoded_instruction.IMM).asSInt
    imm                       :=  _imm.asUInt

    val RS1_data               =   io.FU_input.bits.RS1_data
    val RS2_data               =   io.FU_input.bits.RS2_data
    val IMM                    =   imm
    val PC                     =   io.FU_input.bits.fetch_PC + (io.FU_input.bits.decoded_instruction.packet_index * fetchWidth.U)
    val RD                     =   io.FU_input.bits.decoded_instruction.RD

    val FUNCT3                 =   io.FU_input.bits.decoded_instruction.FUNCT3

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
    val memory_type     = Wire(memory_type_t())     // LOAD/STORE
    val access_width    = Wire(access_width_t())    // B/HW/W
    val unsigned        = Wire(Bool())              // signed/unsigned
    val address         = Wire(UInt(32.W))

    when(is_load){
        memory_type := memory_type_t.LOAD
    }.elsewhen(is_store){
        memory_type := memory_type_t.STORE
    }.otherwise{
        memory_type := memory_type_t.NONE
    }

    access_width := access_width_t.NONE
    when(SB || LB || LBU){
        access_width := access_width_t.B
    }.elsewhen(SH || LH || LHU){
        access_width := access_width_t.HW
    }.elsewhen(SW || LW){
        access_width := access_width_t.W
    }

    unsigned        := LBU || LHU
    address         := RS1_data + imm

    // Everything needed to perform the memory request (LSQ request)    
    io.FU_output.valid              := RegNext(io.FU_input.valid)
    io.FU_output.bits.memory_type   := RegNext(memory_type)     // LOAD/STORE
    io.FU_output.bits.RD            := RegNext(RD)              // LOAD DEST
    io.FU_output.bits.access_width  := RegNext(access_width)    // B/HW/W
    io.FU_output.bits.unsigned      := RegNext(unsigned)          // SIGNED/UNSIGNED
    io.FU_output.bits.address       := RegNext(address)         // ADDRESS
    io.FU_output.bits.wr_data       := RegNext(wr_data)         // WR DATA

    /////////////////
    // VALID/READY //
    /////////////////
    io.FU_input.ready               := 1.B
}
