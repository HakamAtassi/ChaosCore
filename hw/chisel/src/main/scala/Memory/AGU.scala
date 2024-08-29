
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
import chisel3.ltl._
import circt.stage.ChiselStage 

import chisel3.util._

class AGU(coreParameters:CoreParameters) extends Module{
    import coreParameters._
    val io = IO(new Bundle{
        // Flush
        val flush                   =   Input(Bool())

        // Instruction Input
        val FU_input                =   Flipped(Decoupled(new read_decoded_instruction(coreParameters)))

        // Instruction Output
        val FU_output               =   ValidIO(new FU_output(coreParameters))                  // Input to LSQ
    })

    io.FU_output.bits := 0.U.asTypeOf(new FU_output(coreParameters))

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
    val unsigned        = Wire(Bool())              // signed/unsigned
    val address         = Wire(UInt(32.W))

    unsigned        := LBU || LHU
    address         := RS1_data + imm

    // Everything needed to perform the memory request (LSQ request)    
    io.FU_output.valid              := RegNext(io.FU_input.valid && !io.flush)
    io.FU_output.bits.RD            := RegNext(RD)              // LOAD DEST
    io.FU_output.bits.is_unsigned   := RegNext(unsigned)        // SIGNED/UNSIGNED
    io.FU_output.bits.address       := RegNext(address)         // ADDRESS
    io.FU_output.bits.wr_data       := RegNext(wr_data)         // WR DATA
    io.FU_output.bits.MOB_index     := RegNext(io.FU_input.bits.decoded_instruction.MOB_index)
    io.FU_output.bits.ROB_index     := RegNext(io.FU_input.bits.decoded_instruction.ROB_index)
    io.FU_output.bits.fetch_packet_index  := RegNext(io.FU_input.bits.decoded_instruction.packet_index)
    io.FU_output.bits.memory_type   := RegNext(io.FU_input.bits.decoded_instruction.memory_type)
    io.FU_output.bits.access_width  := RegNext(io.FU_input.bits.decoded_instruction.access_width)


    /////////////////
    // VALID/READY //
    /////////////////
    io.FU_input.ready               := 1.B


    ////////////
    // FORMAL //
    ////////////

    // PROPERTY: output should have a latency of 1, excluding flushes //
    val seqInputValid: Sequence = io.FU_input.valid && !io.flush
    val seqOutputValid: Sequence = io.FU_output.valid
    val normal_valid: Property = seqInputValid |=> (seqOutputValid)

    val flush_in: Sequence = io.flush
    val flushed_valid_out: Sequence = !io.FU_output.valid 
    val flushed_valid: Property = flush_in |=> (flushed_valid_out)


    // PROPERTY: stores should be masked //
    val input_is_SB: Sequence = (io.FU_input.valid) && (io.FU_input.bits.decoded_instruction.FUNCT3 === "b000".U) && (io.FU_input.bits.decoded_instruction.memory_type === memory_type_t.STORE)
    val output_smaller_than_ff: Sequence = io.FU_output.bits.wr_data <= 0xFF.U
    val SB_prop: Property = input_is_SB |=> output_smaller_than_ff

    def inputIsStore(funct3: UInt): Sequence = {
        io.FU_input.valid && 
        (io.FU_input.bits.decoded_instruction.FUNCT3 === funct3) && 
        (io.FU_input.bits.decoded_instruction.memory_type === memory_type_t.STORE)
    }

    // Define properties for each store type
    val inputIsSB: Sequence = inputIsStore("b000".U)
    val inputIsSH: Sequence = inputIsStore("b001".U)
    val inputIsSW: Sequence = inputIsStore("b010".U)

    // Define the corresponding output constraints
    val outputSmallerThanFF: Sequence = io.FU_output.bits.wr_data <= 0xFF.U
    val outputSmallerThanFFFF: Sequence = io.FU_output.bits.wr_data <= 0xFFFF.U
    val outputSmallerThanFFFFFFFF: Sequence = io.FU_output.bits.wr_data <= "hFFFFFFFF".U

    // Define properties for each type
    val SBProp: Property = inputIsSB |=> outputSmallerThanFF
    val SHProp: Property = inputIsSH |=> outputSmallerThanFFFF
    val SWProp: Property = inputIsSW |=> outputSmallerThanFFFFFFFF


    // Assert the properties

    AssertProperty(flushed_valid)
    AssertProperty(normal_valid)
    AssertProperty(SBProp)
    AssertProperty(SHProp)
    AssertProperty(SWProp)



}
