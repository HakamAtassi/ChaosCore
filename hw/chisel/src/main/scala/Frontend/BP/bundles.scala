/* ------------------------------------------------------------------------------------
* Filename: bundles.scala
* Author: Hakam Atassi
* Date: Apr 23 2024
* Description: useful data channels for use throughout the BP
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

import chisel3._
import circt.stage.ChiselStage
import chisel3.util._
import java.io.{File, FileWriter}
import java.rmi.server.UID


import helperFunctions.getBTBTagBits





// Helper functions //
object helperFunctions {
    def getBTBTagBits(BTBSize: Int = 4096, fetchWidth:Int=4): Int = (32 - log2Ceil(BTBSize) - 2 - log2Ceil(fetchWidth))

    // Function to shift UInt32 signal down by "getBTBTagBits"
    def shiftDownByTagBits(input: UInt, BTBSize: Int = 4096, fetchWidth:Int=4): UInt = {
        val shiftAmount = 32-getBTBTagBits(BTBSize, fetchWidth)
        input >> shiftAmount
    }


    //def getInstructionType(instruction:UInt): SInt = {

        //val opcode = instruction(6,0)

        //val R      = (opcode === "b0010111".U) || (opcode === "b0110111".U)
        //val J      = (opcode === "b1101111".U)
        //val B      = (opcode === "b1100011".U)
        //val S      = (opcode === "b0100011".U)
        //val U      = (opcode === "b0110011".U)
        //val I      = (opcode === "b0010011".U) || (opcode === "b0000011".U) || (opcode === "b1100111".U)

    //}


    def getImm(instruction:UInt): SInt = {

        val opcode = instruction(6,0)

        val R      = (opcode === "b0010111".U) || (opcode === "b0110111".U)
        val J      = (opcode === "b1101111".U)
        val B      = (opcode === "b1100011".U)
        val S      = (opcode === "b0100011".U)
        val U      = (opcode === "b0110011".U)
        val I      = (opcode === "b0010011".U) || (opcode === "b0000011".U) || (opcode === "b1100111".U)

        val imm = Wire(SInt(32.W))
        imm := 0.asSInt

        when(B) {
            val imm_12      = instruction(31)
            val imm_10_5    = instruction(30, 25)
            val imm_4_1     = instruction(11, 8)
            val imm_11      = instruction(7)

            imm := Cat(imm_12, imm_10_5, imm_4_1, imm_11, 0.U(1.W)).asSInt
        }.elsewhen (J) {
            val imm_20    = instruction(31)
            val imm_19_12 = instruction(19, 12)
            val imm_11    = instruction(20)
            val imm_10_1  = instruction(30,21)

            imm := Cat(imm_20, imm_19_12, imm_11, imm_10_1, 0.U(1.W)).asSInt
        }.elsewhen (I) {
            val imm_11_0      = instruction(31, 20)

            imm := instruction.asSInt
        }.elsewhen(S){
            val imm_11_5      = instruction(31, 25)
            val imm_4_0       = instruction(11, 7)

            imm := Cat(imm_11_5, imm_4_0).asSInt
        }.elsewhen(U){
            val imm_31_12       = instruction(31, 12) << 12

            imm := Cat(imm_31_12).asSInt
        }.otherwise{
            imm := 0.asSInt
        }
        imm
    }


}



// Channels //
class fetch_packet(fetchWidth:Int = 4) extends Bundle{
    val fetch_PC        = UInt(32.W)
    val valid_bits      = Vec(fetchWidth, Bool())
    val instructions    = Vec(fetchWidth, UInt(32.W))
}


class metadata extends Bundle{
    val JAL             = Bool()
    val JALR            = Bool()
    val BR              = Bool()
    val Call            = Bool()
    val Ret             = Bool()
    val Imm             = SInt(32.W)
    val instruction_PC  = UInt(32.W)
    val RAS             = UInt(32.W)
    val BTB_target      = UInt(32.W)
}

/////////////////
// BP channels //
/////////////////

class commit(fetchWidth:Int=4, GHRWidth:Int=16, BTBEntries:Int=4096, RASEntries:Int = 128) extends Bundle{
    val PC      = Input(UInt(32.W))
    val GHR     = Input(UInt(GHRWidth.W))
    val T_NT    = Input(Bool())
    
    //val tag      =Input(UInt(getBTBTagBits(BTBEntries).W))
    val target   =  Input(UInt(32.W))
    val br_type  =  Input(UInt(2.W))
    val br_mask  =  Input(UInt(fetchWidth.W))

    val misprediction = Input(Bool())
    val TOS           = Input(UInt(log2Ceil(RASEntries).W))  // To reset GHR
    val NEXT          = Input(UInt(log2Ceil(RASEntries).W))  // To reset GHR
    val misprediction_PC = Input(UInt(32.W))

}

class RAS_update extends Bundle{    // Request call or ret
    val call_addr = Input(UInt(32.W))
    val call      = Input(Bool())
    val ret       = Input(Bool())
}

class RAS_read(RASEntries:Int=128) extends Bundle{
    val NEXT      = Output(UInt((log2Ceil(RASEntries).W)))
    val TOS       = Output(UInt((log2Ceil(RASEntries).W)))
    val ret_addr  = Output(UInt(32.W))
}

class revert(GHRWidth:Int=16) extends Bundle{
    val GHR               = Input(UInt(GHRWidth.W))
    val PC                = Input(UInt(32.W))
}

class prediction(fetchWidth:Int=4, GHRWidth:Int=16) extends Bundle{
    val hit         =   Output(Bool())  // FIXME: I dont think this is assigned in BTB since it was added after the fact
    val target      =   Output(UInt(32.W))
    val br_type     =   Output(UInt(2.W))
    val br_mask     =   Output(UInt(fetchWidth.W))
    val GHR         =   Output(UInt(GHRWidth.W))
    val T_NT        =   Output(Bool())
}


// TODO: 

object instruction_type extends ChiselEnum {
    val R,
        I,
        S,
        B,
        U,
        J = Value
} 

class decoded_instruction extends Bundle{
    // ??
}

/////////////////////
// BACKEND BUNDLES //
/////////////////////

class ROB_entry extends Bundle{
    // ??
}

class BOB_entry extends Bundle{
    // ??
}

class decoded_fetch_packet(fetchWidth:Int = 4) extends Bundle{
    val decoded_instructions    = Vec(fetchWidth, new decoded_instruction())
    val fetch_PC                = UInt(32.W)
    val valid_bits              = Vec(fetchWidth, Bool())
}
