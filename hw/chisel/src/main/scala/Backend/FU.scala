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


class ALU(coreParameters:CoreParameters) extends Module{
    import coreParameters._
    import InstructionType._

    val io = IO(new Bundle{
        // FLUSH
        val flush         =   Input(Bool())

        // Input
        val FU_input      =   Flipped(Decoupled(new read_decoded_instruction(coreParameters)))
        
        // Output
        val FU_output     =   ValidIO(new FU_output(coreParameters))
    })

    // misaligned fetch exception ??

    // Operand data
    val RS1_data            =   io.FU_input.bits.RS1_data
    val RS2_data            =   io.FU_input.bits.RS2_data
    val imm                 =   io.FU_input.bits.decoded_instruction.IMM
    val instruction_PC      =   io.FU_input.bits.fetch_PC + (io.FU_input.bits.decoded_instruction.packet_index * fetchWidth.U)

    // Dest reg
    val RD                  =   io.FU_input.bits.decoded_instruction.RD

    // Op select
    val instructionType     =   io.FU_input.bits.decoded_instruction.instructionType
    val FUNCT3              =   io.FU_input.bits.decoded_instruction.FUNCT3
    val IS_IMM              =   io.FU_input.bits.decoded_instruction.IS_IMM
    val SUBTRACT            =   io.FU_input.bits.decoded_instruction.SUBTRACT
    val MULTIPLY            =   io.FU_input.bits.decoded_instruction.MULTIPLY

    //////////////////////////
    //////////////////////////
    //////////////////////////


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

    val RS1_signed      = Wire(SInt(32.W))
    val RS1_unsigned    = Wire(UInt(32.W))

    val RS2_signed      = Wire(SInt(32.W))
    val RS2_unsigned    = Wire(UInt(32.W))

    val IMM_signed          = Wire(SInt(32.W))
    val IMM_unsigned        = Wire(UInt(32.W))

    RS1_signed              := RS1_data.asSInt
    RS1_unsigned            := RS1_data.asUInt

    RS2_signed              := RS2_data.asSInt
    RS2_unsigned            := RS2_data.asUInt

    IMM_signed              := imm(12,0).asSInt
    IMM_unsigned            := IMM_signed.asUInt


    val operand1_signed     = RS1_signed
    val operand1_unsigned   = RS1_unsigned

    val operand2_signed     = Mux(IS_IMM, IMM_signed, RS2_signed)
    val operand2_unsigned   = Mux(IS_IMM, IMM_unsigned, RS2_unsigned)



    val shamt = Wire(UInt(5.W))

    when(operand2_unsigned >= 32.U){
        shamt := 32.U
    }.otherwise{
        shamt := operand2_unsigned(4, 0).asUInt
    }


    // Perform arithmetic operations
    add_result      := operand1_unsigned + operand2_unsigned
    sub_result      := operand1_unsigned - operand2_unsigned
    xor_result      := operand1_unsigned ^ operand2_unsigned
    or_result       := operand1_unsigned | operand2_unsigned
    and_result      := operand1_unsigned & operand2_unsigned

    sll_result      := RS1_unsigned << shamt
    srl_result      := RS1_unsigned >> shamt
    sra_result      := RS1_signed   >> shamt

    slt_result      := RS1_signed < operand2_signed
    sltu_result     := RS1_unsigned < operand2_unsigned


    val RS2_shamt = Mux(RS2_data >= 32.U, 32.U, RS2_data(4,0))   // Saturate RS2 shift amount

    

    lui_result      := (imm << 12)  // FIXME: is imm signed??
    auipc_result    := (instruction_PC + (imm<<12)) // same here???


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


    // ALU pipelined; always ready
    io.FU_input.ready       :=   1.B    

    // Not a branch unit (all FUs share the same output channel)
    io.FU_output.bits.branch_taken          := DontCare
    io.FU_output.bits.target_address        := DontCare
    io.FU_output.bits.branch_valid          := 0.B

    io.FU_output.bits.fetch_PC              := RegNext(io.FU_input.bits.fetch_PC)
    io.FU_output.bits.fetch_packet_index    := RegNext(io.FU_input.bits.decoded_instruction.packet_index)

    // Actual Outputs
    io.FU_output.bits.RD         :=   RegNext(io.FU_input.bits.decoded_instruction.RD)
    io.FU_output.bits.RD_valid   :=   RegNext(io.FU_input.bits.decoded_instruction.RD_valid)
    io.FU_output.bits.RD_data    :=   arithmetic_result


    io.FU_output.bits.MOB_index  :=   RegNext(io.FU_input.bits.decoded_instruction.MOB_index)
    io.FU_output.bits.address    :=   0.U

    io.FU_output.bits.address             :=   DontCare
    io.FU_output.bits.memory_type         :=   DontCare
    io.FU_output.bits.access_width        :=   DontCare
    io.FU_output.bits.is_unsigned         :=   DontCare
    io.FU_output.bits.wr_data             :=   DontCare
    



    io.FU_output.bits.ROB_index  :=   RegNext(io.FU_input.bits.decoded_instruction.ROB_index)
    io.FU_output.valid           :=   RegNext(io.FU_input.valid && !io.flush)

}


class branch_unit(coreParameters:CoreParameters) extends Module{
    import coreParameters._

    val io = IO(new Bundle{
        val flush         =   Input(Bool())

        // Input
        val FU_input      =   Flipped(Decoupled(new read_decoded_instruction(coreParameters)))
        
        // Output
        val FU_output     =   ValidIO(new FU_output(coreParameters))
    })

    // Operand data
    val RS1_data        =   io.FU_input.bits.RS1_data
    val RS2_data        =   io.FU_input.bits.RS2_data

    val IMM           = Wire(UInt(32.W))

    val instruction_PC       = Wire(UInt(32.W))

    IMM                            :=  (io.FU_input.bits.decoded_instruction.IMM).asUInt



    instruction_PC          :=   io.FU_input.bits.fetch_PC + (io.FU_input.bits.decoded_instruction.packet_index * fetchWidth.U)

    // Dest reg
    val RD                  =   io.FU_input.bits.decoded_instruction.RD

    // Op select
    val instructionType     =   io.FU_input.bits.decoded_instruction.instructionType
    val FUNCT3              =   io.FU_input.bits.decoded_instruction.FUNCT3
    val IS_IMM           =   io.FU_input.bits.decoded_instruction.IS_IMM
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


    //
    val EQ      = Wire(Bool())
    val NE      = Wire(Bool())
    val LT      = Wire(Bool())
    val GE      = Wire(Bool())
    val LTU     = Wire(Bool())
    val GEU     = Wire(Bool())
    val JAL     = Wire(Bool())
    val JALR    = Wire(Bool())
    
    EQ         :=  (RS1_data.asSInt === RS2_data.asSInt) && BEQ
    NE         :=  (RS1_data.asSInt =/= RS2_data.asSInt) && BNE
    LT         :=  (RS1_data.asSInt   < RS2_data.asSInt) && BLT
    GE         :=  (RS1_data.asSInt  >= RS2_data.asSInt) && BGE
    LTU        :=  (RS1_data.asUInt   < RS2_data.asUInt) && BLTU
    GEU        :=  (RS1_data.asUInt  >= RS2_data.asUInt) && BGEU
    JAL        :=  instructionType === InstructionType.JAL
    JALR       :=  instructionType === InstructionType.JALR 


    val branch_taken   = Wire(Bool())
    val target_address = Wire(UInt(32.W))

    branch_taken    := 0.B
    target_address  := io.FU_input.bits.fetch_PC + (fetchWidth.U * 4.U)    // default address is the next fetch_PC
    

    val SIMM_12_0 = Wire(SInt(32.W))
    val IMM_12_0  = Wire(UInt(32.W))

    val SIMM_20_0 = Wire(SInt(32.W))
    val IMM_20_0  = Wire(UInt(32.W))

    val SIMM_11_0 = Wire(SInt(32.W))
    val IMM_11_0  = Wire(UInt(32.W))

    SIMM_12_0 := IMM(12,0).asSInt
    IMM_12_0 := SIMM_12_0.asUInt

    SIMM_20_0 := IMM(20,0).asSInt
    IMM_20_0 := SIMM_20_0.asUInt

    SIMM_11_0 := IMM(11,0).asSInt
    IMM_11_0 := SIMM_11_0.asUInt





    when(EQ)        {branch_taken := 1.B; target_address := instruction_PC + IMM_12_0}
    .elsewhen(NE)   {branch_taken := 1.B; target_address := instruction_PC + IMM_12_0}
    .elsewhen(LT)   {branch_taken := 1.B; target_address := instruction_PC + IMM_12_0}
    .elsewhen(GE)   {branch_taken := 1.B; target_address := instruction_PC + IMM_12_0}
    .elsewhen(LTU)  {branch_taken := 1.B; target_address := instruction_PC + IMM_12_0}
    .elsewhen(GEU)  {branch_taken := 1.B; target_address := instruction_PC + IMM_12_0}
    .elsewhen(JAL)  {branch_taken := 1.B; target_address := instruction_PC + IMM_20_0}
    .elsewhen(JALR) {branch_taken := 1.B; target_address := RS1_data       + IMM_11_0}


    // PC of branch instruction and packet index (to access ROB bank)
    io.FU_output.bits.fetch_PC              :=  RegNext(io.FU_input.bits.fetch_PC)
    io.FU_output.bits.fetch_packet_index    :=  RegNext(io.FU_input.bits.decoded_instruction.packet_index)

    // ALU pipelined; always ready
    io.FU_input.ready := 1.B
    io.FU_output.bits.branch_valid      :=   RegNext(BRANCH || JAL || JALR)

    // Not a branch unit (all FUs share the same output channel)
    io.FU_output.bits.branch_taken      :=      RegNext(branch_taken)
    io.FU_output.bits.target_address    :=      RegNext(target_address)

    // Actual Outputs
    io.FU_output.bits.RD                :=      RegNext(io.FU_input.bits.decoded_instruction.RD)
    io.FU_output.bits.RD_valid          :=      RegNext(io.FU_input.bits.decoded_instruction.RD_valid)
    io.FU_output.bits.RD_data           :=      RegNext(instruction_PC + 4.U)
    io.FU_output.bits.ROB_index         :=      RegNext(io.FU_input.bits.decoded_instruction.ROB_index)
    io.FU_output.bits.MOB_index         :=      RegNext(io.FU_input.bits.decoded_instruction.MOB_index)
    io.FU_output.bits.address           :=      0.U


    io.FU_output.bits.address             :=   DontCare
    io.FU_output.bits.memory_type         :=   DontCare
    io.FU_output.bits.access_width        :=   DontCare
    io.FU_output.bits.is_unsigned         :=   DontCare
    io.FU_output.bits.wr_data             :=   DontCare


    io.FU_output.valid                  :=      RegNext(io.FU_input.valid && !io.flush)

}



// Top Level FU
class FU(coreParameters:CoreParameters,
         has_ALU:Boolean,
         has_branch_unit: Boolean 
         //MUL:Bool    
) extends Module{
    import coreParameters._
    import InstructionType._
    val io = IO(new Bundle{
        // FLUSH
        val flush         =   Input(Bool())

        // Input
        val FU_input      =   Flipped(Decoupled(new read_decoded_instruction(coreParameters)))
        
        // Output
        val FU_output     =   ValidIO(new FU_output(coreParameters))
    })
    dontTouch(io)
    // All functional have a latency of 1 cycle (for now)
    // FIXME: Add Mul/Div + bypassing
    // Also make sure to inner modules dont write to CDB at the same time

    val is_ALU  = io.FU_input.bits.decoded_instruction.needs_ALU && io.FU_input.valid
    val is_CTRL = io.FU_input.bits.decoded_instruction.needs_branch_unit && io.FU_input.valid



    val ALU = if (has_ALU) Some(Module(new ALU(coreParameters))) else None
    val branch_unit = if (has_branch_unit) Some(Module(new branch_unit(coreParameters))) else None

    ALU.foreach { alu =>
        alu.io.FU_input <> io.FU_input
        alu.io.flush    <> io.flush
    }

    branch_unit.foreach { bu =>
        bu.io.FU_input <> io.FU_input
        bu.io.flush    <> io.flush
    }

    io.FU_output := DontCare


    if(ALU.isDefined){
        when(RegNext(is_ALU)) {
            io.FU_output := ALU.get.io.FU_output
        }
    }


    if(branch_unit.isDefined){
        when(RegNext(is_CTRL)) {
            io.FU_output := branch_unit.get.io.FU_output
        }
    }

    // DEBUG SIGNALS //
    val monitor_output = Wire(Bool())
    monitor_output := RegNext(io.FU_input.valid)
    dontTouch(monitor_output)
}