/* ------------------------------------------------------------------------------------
* Filename: MEMFU.scala
* Author: Hakam Atassi
* Date: May 23 2024
* Description: The core Memory Functional Unit
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


object memfuState extends ChiselEnum{
    val ACTIVE, WAIT = Value
}


class MEMFU(parameters:Parameters) extends Module{
    import parameters._
    val io = IO(new Bundle{
        // Instruction Input
        val FU_input                =   Flipped(Decoupled(new read_decoded_instruction(parameters)))

        // Memory Input
        val memory_response         =   Flipped(Decoupled(new memory_response(parameters))) 

        // Memory Output
        val memory_request          =   Decoupled(new memory_request(parameters))        

        // Instruction Output
        val FU_output               =   ValidIO(new FU_output(parameters))                 
    })

    val memfu_state     = RegInit(memfuState(), memfuState.ACTIVE)

    /////////
    // FSM //
    /////////

    val FU_input_bits_reg   = RegInit(new read_decoded_instruction(parameters), 0.U.asTypeOf(new read_decoded_instruction(parameters)))
    val FU_input_valid_reg  = RegInit(Bool(), 0.B)

    switch(memfu_state){

        is(memfuState.ACTIVE){

            FU_input_bits_reg   := io.FU_input.bits
            FU_input_valid_reg  := io.FU_input.valid

            when(io.FU_input.fire && io.memory_request.fire){
                // send request to memory directly


                memfu_state := memfuState.ACTIVE
            }.elsewhen(io.FU_input.fire){
                // Wait till memory is valid


                memfu_state := memfuState.WAIT
            }
        }


        is(memfuState.WAIT){
            when(io.memory_request.fire){
                // send request to memory

                FU_input_bits_reg := 0.U.asTypeOf(new read_decoded_instruction(parameters))

                memfu_state := memfuState.ACTIVE
            }
        }
    }



    val use_buffered_FU_input   =   (memfu_state === memfuState.WAIT)

    val FU_input                =   Mux(use_buffered_FU_input, FU_input_bits_reg,     io.FU_input.bits)
    val FU_input_valid          =   Mux(use_buffered_FU_input, FU_input_valid_reg,    io.FU_input.valid)


    val IS_LOAD                 =   FU_input.decoded_instruction.IS_LOAD  && FU_input_valid
    val IS_STORE                =   FU_input.decoded_instruction.IS_STORE && FU_input_valid

    // Operand data
    val RS1_data                =   FU_input.RS1_data
    val RS2_data                =   FU_input.RS2_data
    val IMM                     =   FU_input.decoded_instruction.IMM
    val PC                      =   FU_input.PC + (FU_input.decoded_instruction.packet_index * fetchWidth.U)

    // Dest reg
    val RD                      =   FU_input.decoded_instruction.RD

    // Op select
    val FUNCT3                  =   FU_input.decoded_instruction.FUNCT3

    val SB                      =   IS_STORE && FUNCT3 === "b000".U && FU_input_valid
    val SH                      =   IS_STORE && FUNCT3 === "b001".U && FU_input_valid
    val SW                      =   IS_STORE && FUNCT3 === "b010".U && FU_input_valid

    val LB                      =   IS_LOAD && FUNCT3 === "b000".U  && FU_input_valid
    val LH                      =   IS_LOAD && FUNCT3 === "b001".U  && FU_input_valid
    val LW                      =   IS_LOAD && FUNCT3 === "b010".U  && FU_input_valid
    val LBU                     =   IS_LOAD && FUNCT3 === "b100".U  && FU_input_valid
    val LHU                     =   IS_LOAD && FUNCT3 === "b101".U  && FU_input_valid


    val instruction_complete    = RegNext((IS_LOAD && io.memory_response.fire) || (IS_STORE && io.memory_request.fire))


    /////////////////////
    // COMPUTE ADDRESS //
    /////////////////////

    val addr = RS1_data + IMM

    ///////////////////////
    // FORMAT WRITE DATA //
    ///////////////////////

    val wr_data = Wire(UInt(32.W))

    wr_data := 0.U
    when(SB){wr_data := RS2_data & 0xFF.U}
    when(SH){wr_data := RS2_data & 0xFFFF.U}
    when(SW){wr_data := RS2_data.asUInt & "hFFFF_FFFF".U(32.W)}


    ///////////////////
    // DRAM REQUESTS //
    ///////////////////


    io.memory_request.valid           := IS_LOAD || IS_STORE
    io.memory_request.bits.wr_en      := IS_STORE
    io.memory_request.bits.wr_data    := wr_data
    io.memory_request.bits.addr       := addr


    //////////////////////
    // FORMAT READ DATA //
    //////////////////////

    // this can be parallelized, I'm pretty sure (byte enable with parallel muxes...)

    val rd_data = Wire(UInt(32.W))

    val memory_response_8   = Wire(UInt(8.W))
    val memory_response_16  = Wire(UInt(16.W))
    val memory_response_32  = Wire(UInt(32.W))

    val memory_response_8_s   = Wire(SInt(32.W))
    val memory_response_16_s  = Wire(SInt(32.W))
    val memory_response_32_s  = Wire(SInt(32.W))

    val memory_response_8_u   = Wire(UInt(32.W))
    val memory_response_16_u  = Wire(UInt(32.W))
    val memory_response_32_u  = Wire(UInt(32.W))


    memory_response_8   := (io.memory_response.bits.data & "hFF".U)
    memory_response_16  := (io.memory_response.bits.data & "hFFFF".U)
    memory_response_32  := (io.memory_response.bits.data & "hFFFF_FFFF".U)


    memory_response_8_s      := (memory_response_8).asSInt
    memory_response_16_s     := (memory_response_16).asSInt
    memory_response_32_s     := (memory_response_32).asSInt

    memory_response_8_u      := (memory_response_8).asUInt
    memory_response_16_u     := (memory_response_16).asUInt
    memory_response_32_u     := (memory_response_32).asUInt

    rd_data := 0.U

    when(LB)  {rd_data := memory_response_8_s.asUInt}
    when(LH)  {rd_data := memory_response_16_s.asUInt}
    when(LW)  {rd_data := memory_response_32_s.asUInt}
    when(LBU) {rd_data := memory_response_8_u}
    when(LHU) {rd_data := memory_response_16_u}



    ////////////////////////
    // ASSIGN PRF OUTPUTS //
    ////////////////////////

    // Not a branch unit (all FUs share the same output channel)
    io.FU_output.bits.branch_taken              := 0.B
    io.FU_output.bits.target_address            := 0.B
    io.FU_output.bits.branch_valid              := 0.B

    io.FU_output.bits.instruction_PC            := RegNext(io.FU_input.bits.PC + (io.FU_input.bits.decoded_instruction.packet_index<<2.U))
    io.FU_output.bits.fetch_packet_index        := RegNext(io.FU_input.bits.decoded_instruction.packet_index)

    io.FU_output.bits.RD_data                   := RegNext(rd_data.asUInt)
    io.FU_output.bits.RD                        := RegNext(RD)
    io.FU_output.bits.RD_valid                  := RegNext(IS_LOAD)

    io.FU_output.bits.ROB_index                 := RegNext(io.FU_input.bits.decoded_instruction.ROB_index)

    /////////////////
    // VALID/READY //
    /////////////////

    // READY
    io.FU_input.ready               :=  (memfu_state === memfuState.ACTIVE)
    io.memory_response.ready        :=  1.B // FIXME: this may work but is not 100% correct

    // VALID
    io.memory_request.valid         :=   FU_input_valid



    io.FU_output.valid              :=  instruction_complete   // I dont think this outputs anything on stores...

}