/* ------------------------------------------------------------------------------------
* Filename: FU.scala
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

class ALU(parameters:Parameters) extends Module{    // FIXME: I think this can be only 1 stage
    import parameters._
    import InstructionType._

    val io = IO(new Bundle{
        // Input
        val FU_input      =   Flipped(Decoupled(new read_decoded_instruction(coreConfig=coreConfig, fetchWidth=fetchWidth, ROBEntires=ROBEntires, physicalRegCount=physicalRegCount)))
        
        // Output
        val FU_output     =   new FU_output(physicalRegCount)
    })

    // misaligned fetch exception ??

    // Operand data
    val RS1_data    =   io.FU_input.bits.RS1_data
    val RS2_data    =   io.FU_input.bits.RS2_data
    val imm         =   io.FU_input.bits.decoded_instruction.IMM
    val PC          =   io.FU_input.bits.PC + io.FU_input.bits.decoded_instruction.packet_index

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

    //val taken_address     = RegInit(UInt(32.W), 0.U)
    //val not_taken_address = RegInit(UInt(32.W), 0.U)

    //val comp_result = RegInit(Bool(), 0.B)
    //val target_addr = Wire(UInt(32.W))

    val arithmetic_result = Wire(UInt(32.W))


    // Arithmetic Regs
    val add_result  = RegInit(0.U(32.W))
    val sub_result  = RegInit(0.U(32.W))
    val slt_result  = RegInit(0.U(32.W))
    val sltu_result = RegInit(0.U(32.W))
    val and_result  = RegInit(0.U(32.W))
    val or_result   = RegInit(0.U(32.W))
    val xor_result  = RegInit(0.U(32.W))
    val sll_result  = RegInit(0.U(32.W))
    val srl_result  = RegInit(0.U(32.W))
    val sra_result  = RegInit(0.U(32.W))

    // Multiply Regs

    val mul_result          = RegInit(0.U(32.W))
    val mulh_result         = RegInit(0.U(32.W))
    val mulhsu_result       = RegInit(0.U(32.W))
    val mulhu_result        = RegInit(0.U(32.W))
    val div_result          = RegInit(0.U(32.W))
    val divu_result         = RegInit(0.U(32.W))
    val remainder_result    = RegInit(0.U(32.W))
    val remainderu_result   = RegInit(0.U(32.W))

    // Either use RS1 / RS2 or RS1 / imm based on is_imm flag
    val operand2 = Mux(IMMEDIATE, imm, RS2_data)

    // Perform arithmetic operations
    add_result  := RS1_data + operand2
    sub_result  := RS1_data - operand2
    slt_result  := Mux(RS1_data.asSInt < operand2.asSInt, 1.U, 0.U)
    sltu_result := Mux(RS1_data.asUInt < operand2.asUInt, 1.U, 0.U)
    and_result  := RS1_data & operand2
    or_result   := RS1_data | operand2
    xor_result  := RS1_data ^ operand2
    sll_result  := RS1_data << operand2(4,0) // Logical left shift
    srl_result  := RS1_data >> operand2(4,0) // Logical right shift
    sra_result  := (RS1_data.asSInt >> operand2(4,0)).asUInt // Arithmetic right shift

    // perform multiply operations
    //val multiply_temp = Wire(UInt(64.W))
    //multiply_temp := RS1_data * operand2
    //mul_result := multiply_temp(31,0)
    //mul_result := multiply_temp(63,32)
    //mul_result := multiply_temp(31,0)


    /////////////
    // CONTROL //
    /////////////

    val ADD      =   instructionType === OP && FUNCT3 === "b000".U  && !MULTIPLY && SUBTRACT
    val SUB      =   instructionType === OP && FUNCT3 === "b000".U  && !MULTIPLY && SUBTRACT
    val XOR      =   instructionType === OP && FUNCT3 === "b100".U  && !MULTIPLY
    val OR       =   instructionType === OP && FUNCT3 === "b110".U  && !MULTIPLY
    val AND      =   instructionType === OP && FUNCT3 === "b111".U  && !MULTIPLY
    val SLL      =   instructionType === OP && FUNCT3 === "b001".U  && !MULTIPLY
    val SRL      =   instructionType === OP && FUNCT3 === "b101".U  && !MULTIPLY
    val SRA      =   instructionType === OP && FUNCT3 === "b101".U  && !MULTIPLY
    val SLT      =   instructionType === OP && FUNCT3 === "b010".U  && !MULTIPLY
    val SLTU     =   instructionType === OP && FUNCT3 === "b011".U  && !MULTIPLY

    val MUL      =   instructionType === OP && FUNCT3 === "b000".U  && MULTIPLY
    val MULH     =   instructionType === OP && FUNCT3 === "b001".U  && MULTIPLY
    val MULHSU   =   instructionType === OP && FUNCT3 === "b010".U  && MULTIPLY
    val MULHU    =   instructionType === OP && FUNCT3 === "b011".U  && MULTIPLY
    val DIV      =   instructionType === OP && FUNCT3 === "b100".U  && MULTIPLY
    val DIVU     =   instructionType === OP && FUNCT3 === "b101".U  && MULTIPLY
    val REM      =   instructionType === OP && FUNCT3 === "b110".U  && MULTIPLY
    val REMU     =   instructionType === OP && FUNCT3 === "b111".U  && MULTIPLY


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
        arithmetic_result   := sra_result
    }.elsewhen(SLT) {
        arithmetic_result   := slt_result
    }.elsewhen(SLTU){
        arithmetic_result   := sltu_result
    }

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


    // TODO: ready stuff


    io.FU_input.ready := DontCare
    io.FU_output := DontCare

    io.FU_output.RD.bits    :=   io.FU_input.bits.decoded_instruction.RD
    io.FU_output.data       :=   arithmetic_result

}


class branch_unit(parameters:Parameters) extends Module{
    import parameters._
    import InstructionType._

    val io = IO(new Bundle{
        // Input
        val FU_input      =   Flipped(Decoupled(new read_decoded_instruction(coreConfig=coreConfig, fetchWidth=fetchWidth, ROBEntires=ROBEntires, physicalRegCount=physicalRegCount)))
        
        // Output
        val FU_output     =   new FU_output(physicalRegCount)
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
    val IS_BRANCH   =   instructionType === BRANCH
    val BEQ         =   instructionType === BRANCH && FUNCT3 === "b000".U
    val BNE         =   instructionType === BRANCH && FUNCT3 === "b001".U
    val BLT         =   instructionType === BRANCH && FUNCT3 === "b100".U
    val BGE         =   instructionType === BRANCH && FUNCT3 === "b101".U
    val BLTU        =   instructionType === BRANCH && FUNCT3 === "b110".U
    val BGEU        =   instructionType === BRANCH && FUNCT3 === "b111".U

    val JAL         =   instructionType === InstructionType.JAL
    val JALR        =   instructionType === InstructionType.JALR 


    //
    val EQ      = Wire(Bool())
    val NE      = Wire(Bool())
    val BT      = Wire(Bool())
    val GE      = Wire(Bool())
    val LTU     = Wire(Bool())
    val GEU     = Wire(Bool())
    
    EQ         :=  RS1_data.asSInt === RS2_data.asSInt
    NE         :=  RS1_data.asSInt =/= RS2_data.asSInt
    BT         :=  RS1_data.asSInt   < RS2_data.asSInt
    GE         :=  RS1_data.asSInt  >= RS2_data.asSInt
    LTU        :=  RS1_data.asUInt   < RS2_data.asUInt
    GEU        :=  RS1_data.asUInt  >= RS2_data.asUInt


    val branch_taken  = Wire(Bool())
    val taken_address = Wire(UInt(32.W))

    io.FU_input.ready := DontCare
    io.FU_output := DontCare

    branch_taken := 0.B

    when(EQ)        {branch_taken := 1.B}
    .elsewhen(NE)   {branch_taken := 1.B}
    .elsewhen(BT)   {branch_taken := 1.B}
    .elsewhen(GE)   {branch_taken := 1.B}
    .elsewhen(LTU)  {branch_taken := 1.B}
    .elsewhen(GEU)  {branch_taken := 1.B}
    .elsewhen(JAL)  {branch_taken := 1.B}
    .elsewhen(JALR) {branch_taken := 1.B}

    taken_address := 0.U
    when(IS_BRANCH){taken_address := PC + IMM}
    .elsewhen(JAL) {taken_address := PC + IMM}
    .elsewhen(JALR){taken_address := RS1_data + IMM}


    io.FU_output.RD.bits    :=   RD
    io.FU_output.data       :=   PC + 4.U

    io.FU_output.branch_address :=  taken_address
    io.FU_output.branch_taken   :=  branch_taken


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
        val FU_input      =   Flipped(Decoupled(new read_decoded_instruction(coreConfig=coreConfig, fetchWidth=fetchWidth, ROBEntires=ROBEntires, physicalRegCount=physicalRegCount)))
        
        // Output
        val FU_output     =   new FU_output(physicalRegCount)
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

    if(branch_unit.isDefined){
        when(is_CTRL) {
            io.FU_output := branch_unit.get.io.FU_output
        }
    }


    if(ALU.isDefined){
        when(is_ALU) {
            io.FU_output := ALU.get.io.FU_output
        }
    }




}


// MEM FU
class MEMFU(parameters:Parameters) extends Module{
    import parameters._
    import InstructionType._
    val io = IO(new Bundle{
        // Input
        val FU_input      =   Flipped(Decoupled(new read_decoded_instruction(coreConfig=coreConfig, fetchWidth=fetchWidth, ROBEntires=ROBEntires, physicalRegCount=physicalRegCount)))
        val dram_resp     =   Flipped(Decoupled(new dram_resp()))

        // Output
        val FU_output     =   Output(new FU_output(physicalRegCount))      // To RF
        val dram_request  =   Decoupled(new dram_request())                // To DRAM
    })


    val IS_LOAD  = io.FU_input.bits.decoded_instruction.IS_LOAD  && io.FU_input.valid
    val IS_STORE = io.FU_input.bits.decoded_instruction.IS_STORE && io.FU_input.valid

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


    val SB                  =   IS_STORE && FUNCT3 === "b000".U
    val SH                  =   IS_STORE && FUNCT3 === "b001".U
    val SW                  =   IS_STORE && FUNCT3 === "b010".U

    val LB                  =   IS_LOAD && FUNCT3 === "b000".U
    val LH                  =   IS_LOAD && FUNCT3 === "b001".U
    val LW                  =   IS_LOAD && FUNCT3 === "b010".U
    val LBU                 =   IS_LOAD && FUNCT3 === "b100".U
    val LHU                 =   IS_LOAD && FUNCT3 === "b101".U


    /////////////////////
    // COMPUTE ADDRESS //
    /////////////////////

    val addr = RS1_data + IMM

    ///////////////////////
    // FORMAT WRITE DATA //
    ///////////////////////

    val wr_data = Wire(UInt(32.W))

    wr_data := 0.U
    when(SW){wr_data := RS2_data & 0xFF.U}
    when(SH){wr_data := RS2_data & 0xFFFF.U}
    when(SB){wr_data := RS2_data.asUInt & "hFFFF_FFFF".U(32.W)}


    ///////////////////
    // DRAM REQUESTS //
    ///////////////////

    // For loads, Send request to memory. 1 Cycle later, write back to PRF (place output).


    // For store, just send store request to memory.


    io.dram_request.valid           := IS_LOAD || IS_STORE
    io.dram_request.bits.wr_en      := IS_STORE
    io.dram_request.bits.wr_data    := wr_data
    io.dram_request.bits.addr       := addr


    //////////////////////
    // FORMAT READ DATA //
    //////////////////////

    val rd_data = Wire(UInt(32.W))

    rd_data := 0.U
    when(RegNext(LB)) {rd_data := (io.dram_resp.bits.data & 0xFF.U).asSInt.asUInt}
    when(RegNext(LH)) {rd_data := (io.dram_resp.bits.data & 0xFFFF.U).asSInt.asUInt}
    when(RegNext(LW)) {rd_data := (io.dram_resp.bits.data & "hFFFF_FFFF".U).asSInt.asUInt}
    when(RegNext(LBU)){rd_data := (io.dram_resp.bits.data & 0xFF.U).asUInt}
    when(RegNext(LHU)){rd_data := (io.dram_resp.bits.data & 0xFFFF.U).asUInt}

    ////////////////////////
    // ASSIGN PRF OUTPUTS //
    ////////////////////////

    io.FU_output := DontCare
    io.FU_output.data := rd_data
    io.FU_output.RD.bits   := RegNext(RD)
    io.FU_output.RD.valid  := RegNext(IS_LOAD)



    io.FU_input.ready := 1.B
    io.dram_resp.ready := 1.B


}