/* ------------------------------------------------------------------------------------
* Filename: branch_decoder.scala
* Author: Hakam Atassi
* Date: Apr 23 2024
* Description: A small decoder that determines if an indiv. instruction is a branch, and if so, is it taken (in isolation).
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
import java.io.{File, FileWriter}
import java.rmi.server.UID


import helperFunctions._

class branch_decoder(index:Int, parameters:Parameters) extends Module{
    import parameters._

    val io = IO(new Bundle{
        val fetch_PC    = Input(UInt(32.W)) // PC of the fetch packet

        val instruction = Input(UInt(32.W))
        val valid       = Input(Bool())
        
        val prediction  = Flipped(Decoupled(new prediction(parameters)))
        val RAS_read    = Flipped(new RAS_read(parameters))

        val T_NT        = Output(Bool())

        val metadata    = Output(new metadata())

    })

    val opcode = io.instruction(6, 0)
    val (instructionType, valid) = InstructionType.safe(opcode(6, 2))

    val RS1     = io.instruction(19, 15)
    val RD      = io.instruction(11, 7)
    val _imm    = Wire(SInt(32.W))
    val imm     = Wire(UInt(32.W))

    _imm := getImm(io.instruction).asSInt
    imm := _imm.asUInt

    val JAL     = (instructionType === InstructionType.JAL)
    val JALR    = (instructionType === InstructionType.JALR)
    val BR      = (instructionType === InstructionType.BRANCH)
    val CALL    = (JALR && (RD === 1.U)) || (JAL && (RD === 1.U))
    val RET     = (JALR && (RD === 0.U) && (RS1 === 1.U) && imm === 0.U)

    dontTouch(CALL)

    val fetch_PC_adjusted = Wire(UInt(32.W))
    fetch_PC_adjusted := io.fetch_PC + (index*4).U

    // JALR and BR are sort of opposite instructions, because JALR is always taken but needs to get its address from a buffer somewhere.
    // BR has its address available in the instruction encoding, but depends on both PHT for T_NT prediction and BTB for dominant index. 
    // Note that since 1 packet can have several branches, so simplify things, predictions depend on the BTB to inform BP of the dominant branch
    // if that is not available, default to NT. 

    
    val br_type = Wire(_br_type())

    dontTouch(br_type)


    when(CALL){
        br_type := _br_type.CALL
    }.elsewhen(RET){
        br_type := _br_type.RET
    }.elsewhen(JAL){
        br_type := _br_type.JAL
    }.elsewhen(JALR){
        br_type := _br_type.JALR
    }.elsewhen(BR){
        br_type := _br_type.BR
    }.otherwise{
        br_type := _br_type.NONE
    }

    io.metadata.is_control := (br_type =/= _br_type.NONE) && io.valid


    // Assign T/NT
    val BTB_hit_valid = io.prediction.bits.hit && io.prediction.valid

    when (RET) {    // Doesnt need BTB hit since addr is from RAS
        io.T_NT := io.valid
        io.metadata.BTB_target      :=  io.RAS_read.ret_addr
    }.elsewhen (JAL) {
        io.T_NT := io.valid
        io.metadata.BTB_target      :=  fetch_PC_adjusted + imm
    }.elsewhen (JALR) {
        io.T_NT := io.valid && BTB_hit_valid
        io.metadata.BTB_target      :=  io.prediction.bits.target
    }.elsewhen(BR) {
        io.T_NT := io.valid && BTB_hit_valid
        io.metadata.BTB_target      :=  io.prediction.bits.target
    }.otherwise{
        io.T_NT := 0.U  
        io.metadata.BTB_target      :=  0.U
    }

    io.metadata.br_type         :=  br_type
    io.metadata.Imm             :=  imm
    io.metadata.instruction_PC  :=  fetch_PC_adjusted
    io.metadata.RAS             :=  io.RAS_read.ret_addr

    io.prediction.ready := 1.B

}