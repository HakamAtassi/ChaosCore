/* ------------------------------------------------------------------------------------
* Filename: GALU.scala
* Author: Hakam Atassi
* Date: Sep 2024
* Description: A generic ALU. Only containts control logic and no real arithmetic. 
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

// General ALU/GALU
class GALU(coreParameters:CoreParameters) extends Module{
    import coreParameters._
    import InstructionType._

    val io = IO(new Bundle{
        // Flush
        val flush         =   Flipped(ValidIO(new flush(coreParameters)))

        // Input
        val FU_input      =   Flipped(Decoupled(new read_decoded_instruction(coreParameters)))
        
        // Output
        val FU_output     =   Decoupled(new FU_output(coreParameters))


        // commit (for CSRs only)
        val commit          =   Flipped(ValidIO(new commit(coreParameters)))

    })

    // misaligned fetch exception ??


    // Operand data
    val RS1_data            =   io.FU_input.bits.RS1_data
    val RS2_data            =   io.FU_input.bits.RS2_data
    val imm                 =   io.FU_input.bits.decoded_instruction.IMM
    val instruction_PC      =   io.FU_input.bits.fetch_PC + (io.FU_input.bits.decoded_instruction.packet_index * fetchWidth.U)
    val CSRRW               =  io.FU_input.bits.decoded_instruction.CSRRW


    // Dest reg
    val PRD                 =   io.FU_input.bits.decoded_instruction.PRD

    // Op select
    val SRET                =   io.FU_input.bits.decoded_instruction.XRET    &&     io.FU_input.bits.decoded_instruction.FUNCT7 === "b0001000".U
    val MRET                =   io.FU_input.bits.decoded_instruction.XRET    &&     io.FU_input.bits.decoded_instruction.FUNCT7 === "b0011000".U
    // FIXME: MNRET?

    val CTRL                =   io.FU_input.bits.decoded_instruction.CTRL


    val FUNCT3              =   io.FU_input.bits.decoded_instruction.FUNCT3
    val FUNCT7              =   io.FU_input.bits.decoded_instruction.FUNCT7
    val FENCE               =   io.FU_input.bits.decoded_instruction.FENCE
    val IS_IMM              =   io.FU_input.bits.decoded_instruction.IS_IMM
    val SUBTRACT            =   FUNCT7 === "b0100000".U
    val UNSIGNED            =   io.FU_input.bits.decoded_instruction.UNSIGNED

    val ECALL               =   io.FU_input.bits.decoded_instruction.ENV    && io.FU_input.bits.decoded_instruction.IMM === 0x0.U
    val EBREAK              =   io.FU_input.bits.decoded_instruction.ENV    && io.FU_input.bits.decoded_instruction.IMM === 0x1.U

    val BASE_ARITHMETIC     = io.FU_input.bits.decoded_instruction.BASE_ARITHMETIC
    val MULTIPLY            = io.FU_input.bits.decoded_instruction.MULTIPLY


    //////////////
    // OUTPUT Q //
    //////////////

    val FU_output = Module(new Queue(new FU_output(coreParameters), 2, flow=false, hasFlush=true, useSyncReadMem=false))
    FU_output.io.enq.bits := DontCare

    //////////////////////////
    //////////////////////////
    //////////////////////////




    val arithmetic_result = RegInit(UInt(32.W), 0.U)

    val CSR_addr = imm(11, 0).asUInt


    // Arithmetic Regs
    // Base
    val add_result      = WireInit(UInt(32.W), 0.U)
    val sub_result      = WireInit(UInt(32.W), 0.U)
    val slt_result      = WireInit(UInt(32.W), 0.U)
    val sltu_result     = WireInit(UInt(32.W), 0.U)
    val and_result      = WireInit(UInt(32.W), 0.U)
    val or_result       = WireInit(UInt(32.W), 0.U)
    val xor_result      = WireInit(UInt(32.W), 0.U)
    val sll_result      = WireInit(UInt(32.W), 0.U)
    val srl_result      = WireInit(UInt(32.W), 0.U)
    val sra_result      = WireInit(SInt(32.W), 0.S)
    val lui_result      = WireInit(UInt(32.W), 0.U)
    val auipc_result    = WireInit(UInt(32.W), 0.U)

    // Mul
    val mul_result      =   WireInit(UInt(32.W), 0.U)
    val mulh_result     =   WireInit(UInt(32.W), 0.U)
    val mulsu_result    =   WireInit(UInt(32.W), 0.U)
    val mulu_result     =   WireInit(UInt(32.W), 0.U)
    val div_result      =   WireInit(UInt(32.W), 0.U)
    val divu_result     =   WireInit(UInt(32.W), 0.U)
    val rem_result      =   WireInit(UInt(32.W), 0.U)
    val remu_result     =   WireInit(UInt(32.W), 0.U)

    // Br
    val EQ              =   WireInit(Bool(), 0.B)
    val NE              =   WireInit(Bool(), 0.B)
    val LT              =   WireInit(Bool(), 0.B)
    val GE              =   WireInit(Bool(), 0.B)
    val LTU             =   WireInit(Bool(), 0.B)
    val GEU             =   WireInit(Bool(), 0.B)


    val RS1_signed      =   Wire(SInt(32.W))
    val RS1_unsigned    =   Wire(UInt(32.W))

    val RS2_signed      =   Wire(SInt(32.W))
    val RS2_unsigned    =   Wire(UInt(32.W))

    val IMM_signed      =   Wire(SInt(32.W))
    val IMM_unsigned    =   Wire(UInt(32.W))

    RS1_signed         :=   RS1_data.asSInt
    RS1_unsigned       :=   RS1_data.asUInt

    RS2_signed         :=   RS2_data.asSInt
    RS2_unsigned       :=   RS2_data.asUInt

    IMM_signed         :=   imm(12,0).asSInt
    IMM_unsigned       :=   IMM_signed.asUInt


    val operand1_signed     = RS1_signed
    val operand1_unsigned   = RS1_unsigned

    val operand2_signed     = Mux(IS_IMM, IMM_signed, RS2_signed)
    val operand2_unsigned   = Mux(IS_IMM, IMM_unsigned, RS2_unsigned)

    val shamt = Wire(UInt(5.W))

    // FIXME: saturate to 31 or 32?
    when(operand2_unsigned(4, 0).asUInt >= 32.U){
        shamt := 31.U
    }.otherwise{
        shamt := operand2_unsigned(4, 0).asUInt
    }

    val RS2_shamt = Mux(RS2_data >= 32.U, 32.U, RS2_data(4,0))   // Saturate RS2 shift amount

    /////////////
    // CONTROL //
    /////////////

    // BASE INSTRUCTIONS //
    val ADD      =   (BASE_ARITHMETIC) && FUNCT3 === "b000".U && !SUBTRACT
    val SUB      =   (BASE_ARITHMETIC) && FUNCT3 === "b000".U && SUBTRACT
    val XOR      =   (BASE_ARITHMETIC) && FUNCT3 === "b100".U  
    val OR       =   (BASE_ARITHMETIC) && FUNCT3 === "b110".U 
    val AND      =   (BASE_ARITHMETIC) && FUNCT3 === "b111".U 
    val SLL      =   (BASE_ARITHMETIC) && FUNCT3 === "b001".U
    val SRL      =   (BASE_ARITHMETIC) && FUNCT3 === "b101".U && !SUBTRACT
    val SRA      =   (BASE_ARITHMETIC) && FUNCT3 === "b101".U && SUBTRACT
    val SLT      =   (BASE_ARITHMETIC) && FUNCT3 === "b010".U
    val SLTU     =   (BASE_ARITHMETIC) && FUNCT3 === "b011".U
    val LUI      =   io.FU_input.bits.decoded_instruction.LUI
    val AUIPC    =   io.FU_input.bits.decoded_instruction.AUIPC

    dontTouch(SLL)
    dontTouch(SRL)
    dontTouch(SRA)
    dontTouch(instruction_PC)
    dontTouch(AUIPC)
    dontTouch(LUI)
    dontTouch(BASE_ARITHMETIC)
    
    // "M" INSTRUCTIONS //
    val MUL      =   (MULTIPLY) && FUNCT3 === "b000".U
    val MULH     =   (MULTIPLY) && FUNCT3 === "b001".U
    val MULSU    =   (MULTIPLY) && FUNCT3 === "b010".U
    val MULU     =   (MULTIPLY) && FUNCT3 === "b011".U
    val DIV      =   (MULTIPLY) && FUNCT3 === "b100".U
    val DIVU     =   (MULTIPLY) && FUNCT3 === "b101".U
    val REM      =   (MULTIPLY) && FUNCT3 === "b110".U
    val REMU     =   (MULTIPLY) && FUNCT3 === "b111".U

    dontTouch(MUL)
    dontTouch(MULH)
    dontTouch(MULSU)
    dontTouch(MULU)
    dontTouch(DIV)
    dontTouch(DIVU)
    dontTouch(REM)
    dontTouch(REMU)

    // BRANCH INSTRUCTIONS //
    val BRANCH      =   io.FU_input.valid && io.FU_input.bits.decoded_instruction.CTRL && !io.FU_input.bits.decoded_instruction.JAL && !io.FU_input.bits.decoded_instruction.JALR   // FIXME: once again, crappy decoding...
    val BEQ         =   BRANCH && FUNCT3 === "b000".U
    val BNE         =   BRANCH && FUNCT3 === "b001".U
    val BLT         =   BRANCH && FUNCT3 === "b100".U
    val BGE         =   BRANCH && FUNCT3 === "b101".U
    val BLTU        =   BRANCH && FUNCT3 === "b110".U
    val BGEU        =   BRANCH && FUNCT3 === "b111".U
    val JALR        =   io.FU_input.bits.decoded_instruction.JALR
    val JAL         =   io.FU_input.bits.decoded_instruction.JAL


    
    // INPUT VALIDS
    val ALU_input_valid                     =   io.FU_input.fire && io.FU_input.bits.decoded_instruction.needs_ALU
    val branch_unit_input_valid             =   io.FU_input.fire && io.FU_input.bits.decoded_instruction.needs_branch_unit
    val mult_unit_input_valid               =   io.FU_input.fire && io.FU_input.bits.decoded_instruction.MULTIPLY
    val AGU_input_valid                     =   io.FU_input.fire && io.FU_input.bits.decoded_instruction.needs_memory
    val CSR_input_valid                     =   io.FU_input.fire && io.FU_input.bits.decoded_instruction.needs_CSRs
    

    dontTouch(ALU_input_valid)
    dontTouch(branch_unit_input_valid)
    dontTouch(mult_unit_input_valid)

    
    ////////////////////
    // ASSIGN OUTPUTS //
    ////////////////////
    FU_output.io.flush.get := io.flush.valid

    io.FU_input.ready :=  FU_output.io.enq.ready
    io.FU_output <> FU_output.io.deq

    dontTouch(FU_output.io)

}


