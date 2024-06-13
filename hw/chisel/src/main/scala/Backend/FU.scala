/* ------------------------------------------------------------------------------------
* Filename: FU.scala
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

class ALU(parameters:Parameters) extends Module{
    import parameters._
    import InstructionType._

    val io = IO(new Bundle{
        // Input
        val FU_input      =   Flipped(Decoupled(new read_decoded_instruction(parameters)))
        
        // Output
        val FU_output     =   ValidIO(new FU_output(parameters))
    })

    // misaligned fetch exception ??

    // Operand data
    val RS1_data            =   io.FU_input.bits.RS1_data
    val RS2_data            =   io.FU_input.bits.RS2_data
    val imm                 =   io.FU_input.bits.decoded_instruction.IMM
    val instruction_PC      =   io.FU_input.bits.PC + io.FU_input.bits.decoded_instruction.packet_index

    // Dest reg
    val RD                  =   io.FU_input.bits.decoded_instruction.RD

    // Op select
    val instructionType     =   io.FU_input.bits.decoded_instruction.instructionType
    val FUNCT3              =   io.FU_input.bits.decoded_instruction.FUNCT3
    val IMMEDIATE           =   io.FU_input.bits.decoded_instruction.IMMEDIATE
    val SUBTRACT            =   io.FU_input.bits.decoded_instruction.SUBTRACT
    val MULTIPLY            =   io.FU_input.bits.decoded_instruction.MULTIPLY

    //////////////////////////
    //////////////////////////
    //////////////////////////

    //val target_address     = RegInit(UInt(32.W), 0.U)
    //val not_target_address = RegInit(UInt(32.W), 0.U)

    //val comp_result = RegInit(Bool(), 0.B)
    //val target_addr = Wire(UInt(32.W))

    val arithmetic_result = RegInit(UInt(32.W), 0.U)


    // Arithmetic Regs
    val add_result      = Wire(UInt(32.W))
    val sub_result      = Wire(UInt(32.W))
    val slt_result      = Wire(UInt(32.W))
    val sltu_result     = Wire(UInt(32.W))
    val and_result      = Wire(UInt(32.W))
    val or_result       = Wire(UInt(32.W))
    val xor_result      = Wire(UInt(32.W))
    val sll_result      = Wire(UInt(32.W))
    val srl_result      = Wire(UInt(32.W))
    val sra_result      = Wire(SInt(32.W))
    val lui_result      = Wire(UInt(32.W))
    val auipc_result    = Wire(UInt(32.W))

    // Multiply Regs

    //val mul_result          = Wire(UInt(32.W))
    //val mulh_result         = Wire(UInt(32.W))
    //val mulhsu_result       = Wire(UInt(32.W))
    //val mulhu_result        = Wire(UInt(32.W))
    //val div_result          = Wire(UInt(32.W))
    //val divu_result         = Wire(UInt(32.W))
    //val remainder_result    = Wire(UInt(32.W))
    //val remainderu_result   = Wire(UInt(32.W))

    // Either use RS1 / RS2 or RS1 / imm based on is_imm flag
    val operand2 = Mux(IMMEDIATE, imm, RS2_data)

    // Perform arithmetic operations
    add_result      := RS1_data + operand2
    sub_result      := RS1_data - operand2
    slt_result      := Mux(RS1_data.asSInt < operand2.asSInt, 1.U, 0.U)
    sltu_result     := Mux(RS1_data.asUInt < operand2.asUInt, 1.U, 0.U)
    and_result      := RS1_data & operand2
    or_result       := RS1_data | operand2
    xor_result      := RS1_data ^ operand2
    sll_result      := RS1_data << operand2(4,0) // Logical left shift
    srl_result      := RS1_data >> operand2(4,0) // Logical right shift
    sra_result      := ((RS1_data.asSInt) >> operand2(4,0)).asSInt

    lui_result      := (imm << 12)  // FIXME: is imm signed??
    auipc_result    := (instruction_PC + (imm<<12)) // same here???


    // perform multiply operations
    //val multiply_temp = Wire(UInt(64.W))
    //multiply_temp := RS1_data * operand2
    //mul_result := multiply_temp(31,0)
    //mul_result := multiply_temp(63,32)
    //mul_result := multiply_temp(31,0)


    /////////////
    // CONTROL //
    /////////////

    val ADD      =   (instructionType === OP || instructionType === OP_IMM) && FUNCT3 === "b000".U  && !MULTIPLY && !SUBTRACT
    val SUB      =   (instructionType === OP || instructionType === OP_IMM) && FUNCT3 === "b000".U  && !MULTIPLY && SUBTRACT
    val XOR      =   (instructionType === OP || instructionType === OP_IMM) && FUNCT3 === "b100".U  && !MULTIPLY
    val OR       =   (instructionType === OP || instructionType === OP_IMM) && FUNCT3 === "b110".U  && !MULTIPLY
    val AND      =   (instructionType === OP || instructionType === OP_IMM) && FUNCT3 === "b111".U  && !MULTIPLY
    val SLL      =   (instructionType === OP || instructionType === OP_IMM) && FUNCT3 === "b001".U  && !MULTIPLY
    val SRL      =   (instructionType === OP || instructionType === OP_IMM) && FUNCT3 === "b101".U  && !MULTIPLY && !SUBTRACT
    val SRA      =   (instructionType === OP || instructionType === OP_IMM) && FUNCT3 === "b101".U  && !MULTIPLY && SUBTRACT
    val SLT      =   (instructionType === OP || instructionType === OP_IMM) && FUNCT3 === "b010".U  && !MULTIPLY
    val SLTU     =   (instructionType === OP || instructionType === OP_IMM) && FUNCT3 === "b011".U  && !MULTIPLY

    val LUI     =   (instructionType === InstructionType.LUI) && !MULTIPLY
    val AUIPC   =   (instructionType === InstructionType.AUIPC) && !MULTIPLY

    val MUL      =   (instructionType === OP) && FUNCT3 === "b000".U  && MULTIPLY
    val MULH     =   (instructionType === OP) && FUNCT3 === "b001".U  && MULTIPLY
    val MULHSU   =   (instructionType === OP) && FUNCT3 === "b010".U  && MULTIPLY
    val MULHU    =   (instructionType === OP) && FUNCT3 === "b011".U  && MULTIPLY
    val DIV      =   (instructionType === OP) && FUNCT3 === "b100".U  && MULTIPLY
    val DIVU     =   (instructionType === OP) && FUNCT3 === "b101".U  && MULTIPLY
    val REM      =   (instructionType === OP) && FUNCT3 === "b110".U  && MULTIPLY
    val REMU     =   (instructionType === OP) && FUNCT3 === "b111".U  && MULTIPLY

    arithmetic_result := 0.U
    when(ADD)       {
        arithmetic_result   := add_result
    }.elsewhen(SUB) {
        arithmetic_result   := sub_result
    }.elsewhen(XOR) {
        arithmetic_result   := xor_result
    }.elsewhen(OR)  {
        arithmetic_result   := or_result
    }.elsewhen(AND) {
        arithmetic_result   := and_result
    }.elsewhen(SLL) {
        arithmetic_result   := sll_result
    }.elsewhen(SRL) {
        arithmetic_result   := srl_result
    }.elsewhen(SRA) {
        arithmetic_result   := sra_result.asUInt
    }.elsewhen(SLT) {
        arithmetic_result   := slt_result
    }.elsewhen(SLTU){
        arithmetic_result   := sltu_result
    }.elsewhen(LUI){
        arithmetic_result   := lui_result
    }.elsewhen(AUIPC){
        arithmetic_result   := auipc_result
    }

    dontTouch(LUI)

    /////////
    /*
    when(MUL){
    }.elsewhen(MULH){

    }.elsewhen(MULHSU){

    }.elsewhen(MULHU){

    }.elsewhen(DIV){

    }.elsewhen(DIVU){

    }.elsewhen(REM){

    }.elsewhen(REMU){

    }
    */

    // ALU pipelined; always ready
    io.FU_input.ready       :=   1.B    

    // Not a branch unit (all FUs share the same output channel)
    io.FU_output.bits.branch_taken          := DontCare
    io.FU_output.bits.target_address        := DontCare
    io.FU_output.bits.branch_valid          := 0.B

    io.FU_output.bits.instruction_PC        := RegNext(io.FU_input.bits.PC + (io.FU_input.bits.decoded_instruction.packet_index)<<2.U)
    io.FU_output.bits.fetch_packet_index    := RegNext(io.FU_input.bits.decoded_instruction.packet_index)

    // Actual Outputs
    io.FU_output.bits.RD         :=   RegNext(io.FU_input.bits.decoded_instruction.RD)
    io.FU_output.bits.RD_valid   :=   RegNext(io.FU_input.bits.decoded_instruction.RD_valid)
    io.FU_output.bits.RD_data    :=   arithmetic_result

    io.FU_output.bits.ROB_index  :=   RegNext(io.FU_input.bits.decoded_instruction.ROB_index)
    io.FU_output.valid           :=   RegNext(io.FU_input.valid)

}


class branch_unit(parameters:Parameters) extends Module{
    import parameters._

    val io = IO(new Bundle{
        // Input
        val FU_input      =   Flipped(Decoupled(new read_decoded_instruction(parameters)))
        
        // Output
        val FU_output     =   ValidIO(new FU_output(parameters))
    })


    // Operand data
    val RS1_data    =   io.FU_input.bits.RS1_data
    val RS2_data    =   io.FU_input.bits.RS2_data
    val IMM         =   io.FU_input.bits.decoded_instruction.IMM
    val PC          =   io.FU_input.bits.PC + io.FU_input.bits.decoded_instruction.packet_index

    // Dest reg
    val RD                  =   io.FU_input.bits.decoded_instruction.RD

    // Op select

    val instructionType     =   io.FU_input.bits.decoded_instruction.instructionType
    val FUNCT3              =   io.FU_input.bits.decoded_instruction.FUNCT3
    val IMMEDIATE           =   io.FU_input.bits.decoded_instruction.IMMEDIATE
    val SUBTRACT            =   io.FU_input.bits.decoded_instruction.SUBTRACT
    val MULTIPLY            =   io.FU_input.bits.decoded_instruction.MULTIPLY

    //
    val BRANCH      =   instructionType === InstructionType.BRANCH
    val BEQ         =   instructionType === InstructionType.BRANCH && FUNCT3 === "b000".U
    val BNE         =   instructionType === InstructionType.BRANCH && FUNCT3 === "b001".U
    val BLT         =   instructionType === InstructionType.BRANCH && FUNCT3 === "b100".U
    val BGE         =   instructionType === InstructionType.BRANCH && FUNCT3 === "b101".U
    val BLTU        =   instructionType === InstructionType.BRANCH && FUNCT3 === "b110".U
    val BGEU        =   instructionType === InstructionType.BRANCH && FUNCT3 === "b111".U
    val JAL         =   instructionType === InstructionType.JAL
    val JALR        =   instructionType === InstructionType.JALR 



    //
    val EQ      = Wire(Bool())
    val NE      = Wire(Bool())
    val LT      = Wire(Bool())
    val GE      = Wire(Bool())
    val LTU     = Wire(Bool())
    val GEU     = Wire(Bool())
    
    EQ         :=  (RS1_data.asSInt === RS2_data.asSInt) && BEQ
    NE         :=  (RS1_data.asSInt =/= RS2_data.asSInt) && BNE
    LT         :=  (RS1_data.asSInt   < RS2_data.asSInt) && BLT
    GE         :=  (RS1_data.asSInt  >= RS2_data.asSInt) && BGE
    LTU        :=  (RS1_data.asUInt   < RS2_data.asUInt) && BLTU
    GEU        :=  (RS1_data.asUInt  >= RS2_data.asUInt) && BGEU

    val branch_taken   = Wire(Bool())
    val target_address = Wire(UInt(32.W))

    branch_taken    := 0.B
    target_address  := PC   // FIXME: what should the default address be?

    
    dontTouch(BEQ)
    dontTouch(EQ)
    dontTouch(GE)

    when(EQ)        {branch_taken := 1.B; target_address := PC + IMM}
    .elsewhen(NE)   {branch_taken := 1.B; target_address := PC + IMM}
    .elsewhen(LT)   {branch_taken := 1.B; target_address := PC + IMM}
    .elsewhen(GE)   {branch_taken := 1.B; target_address := PC + IMM}
    .elsewhen(LTU)  {branch_taken := 1.B; target_address := PC + IMM}
    .elsewhen(GEU)  {branch_taken := 1.B; target_address := PC + IMM}
    .elsewhen(JAL)  {branch_taken := 1.B; target_address := PC + IMM}
    .elsewhen(JALR) {branch_taken := 1.B; target_address := RS1_data + IMM}


    // PC of branch instruction and packet index (to access ROB bank)
    io.FU_output.bits.instruction_PC        :=  RegNext(io.FU_input.bits.PC + (io.FU_input.bits.decoded_instruction.packet_index)<<2.U)
    io.FU_output.bits.fetch_packet_index    :=  RegNext(io.FU_input.bits.decoded_instruction.packet_index)

    // ALU pipelined; always ready
    io.FU_input.ready := 1.B
    io.FU_output.bits.branch_valid :=   (BRANCH || JAL || JALR)

    // Not a branch unit (all FUs share the same output channel)
    io.FU_output.bits.branch_taken      :=      RegNext(branch_taken)
    io.FU_output.bits.target_address    :=      RegNext(target_address)

    // Actual Outputs
    io.FU_output.bits.RD                :=      RegNext(io.FU_input.bits.decoded_instruction.RD)
    io.FU_output.bits.RD_valid          :=      RegNext(io.FU_input.bits.decoded_instruction.RD_valid)
    io.FU_output.bits.RD_data           :=      RegNext(PC + 4.U)
    io.FU_output.bits.ROB_index         :=      RegNext(io.FU_input.bits.decoded_instruction.ROB_index)
    io.FU_output.valid                  :=      RegNext(io.FU_input.valid)

}



// Top Level FU
class FU(parameters:Parameters,
         has_ALU:Boolean,
         has_branch_unit: Boolean 
         //MUL:Bool    
) extends Module{
    import parameters._
    import InstructionType._
    val io = IO(new Bundle{
        // Input
        val FU_input      =   Flipped(Decoupled(new read_decoded_instruction(parameters)))
        
        // Output
        val FU_output     =   ValidIO(new FU_output(parameters))
    })

    // All functional have a latency of 1 cycle (for now)
    // FIXME: Add Mul/Div + bypassing
    // Also make sure to inner modules dont write to CDB at the same time

    val is_ALU  = io.FU_input.bits.decoded_instruction.needs_ALU && io.FU_input.valid
    val is_CTRL = io.FU_input.bits.decoded_instruction.needs_branch_unit && io.FU_input.valid



    val ALU = if (has_ALU) Some(Module(new ALU(parameters))) else None
    val branch_unit = if (has_branch_unit) Some(Module(new branch_unit(parameters))) else None

    ALU.foreach { alu =>
        alu.io.FU_input <> io.FU_input
    }

    branch_unit.foreach { bu =>
        bu.io.FU_input <> io.FU_input
    }

    io.FU_output := DontCare


    if(ALU.isDefined){
        when(is_ALU) {
            io.FU_output := ALU.get.io.FU_output
        }
    }


    if(branch_unit.isDefined){
        when(is_CTRL) {
            io.FU_output := branch_unit.get.io.FU_output    //FIXME: Get??
        }
    }

}