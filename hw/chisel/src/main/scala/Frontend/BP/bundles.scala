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
package ChaosCore

import chisel3._
import circt.stage.ChiselStage
import chisel3.util._
import java.io.{File, FileWriter}
import java.rmi.server.UID


import helperFunctions.getBTBTagBits


// FIXME: this should be in utils.scala
// Helper functions //
object helperFunctions {
    def getBTBTagBits(BTBSize: Int = 4096, fetchWidth:Int=4): Int = (32 - log2Ceil(BTBSize) - 2 - log2Ceil(fetchWidth))

    // Function to shift UInt32 signal down by "getBTBTagBits"
    def shiftDownByTagBits(input: UInt, BTBSize: Int = 4096, fetchWidth:Int=4): UInt = {
        val shiftAmount = 32-getBTBTagBits(BTBSize, fetchWidth)
        input >> shiftAmount
    }

    def getImm(instruction:UInt): UInt = {

        val opcode = instruction(6,0)

        val R      = (opcode === "b0010111".U) || (opcode === "b0110111".U)
        val J      = (opcode === "b1101111".U)
        val B      = (opcode === "b1100011".U)
        val S      = (opcode === "b0100011".U)
        val U      = (opcode === "b0110011".U)
        val I      = (opcode === "b0010011".U) || (opcode === "b0000011".U) || (opcode === "b1100111".U)

        val imm = Wire(UInt(32.W))
        imm := 0.U

        when(B) {
            val imm_12      = instruction(31)
            val imm_10_5    = instruction(30, 25)
            val imm_4_1     = instruction(11, 8)
            val imm_11      = instruction(7)

            imm := Cat(imm_12, imm_11, imm_10_5, imm_4_1, 0.U(1.W)).asSInt.asUInt
        }.elsewhen (J) {
            val imm_20    = instruction(31)
            val imm_19_12 = instruction(19, 12)
            val imm_11    = instruction(20)
            val imm_10_1  = instruction(30,21)

            imm := Cat(imm_20, imm_19_12, imm_11, imm_10_1, 0.U(1.W)).asSInt.asUInt
        }.elsewhen (I) {
            val imm_11_0      = instruction(31, 20)

            imm := imm_11_0.asSInt.asUInt
        }.elsewhen(S){
            val imm_11_5      = instruction(31, 25)
            val imm_4_0       = instruction(11, 7)

            imm := Cat(imm_11_5, imm_4_0).asSInt.asUInt
        }.elsewhen(U){
            val imm_31_12     = instruction(31, 12) << 12

            imm := Cat(imm_31_12).asSInt.asUInt
        }.otherwise{
            imm := 0.asSInt.asUInt
        }
        imm
    }
}

// Channels //
class fetch_packet(parameters:Parameters) extends Bundle{
    import parameters._
    val fetch_PC        = UInt(32.W)
    val valid_bits      = Vec(fetchWidth, Bool())
    val instructions    = Vec(fetchWidth, new Instruction(parameters))
}

class metadata extends Bundle{
    val JAL             = Bool()
    val JALR            = Bool()
    val BR              = Bool()
    val Call            = Bool()
    val Ret             = Bool()
    val Imm             = UInt(32.W)
    val instruction_PC  = UInt(32.W)
    val RAS             = UInt(32.W)
    val BTB_target      = UInt(32.W)
}

/////////////////
// BP channels //
/////////////////

object _br_type extends ChiselEnum{

    val NONE, BR, JAL, JALR, RET = Value

}

class BTB_entry(parameters:Parameters) extends Bundle{
    import parameters._

    val BTB_tag_size = 32 - log2Ceil(BTBEntries) - 2

    val BTB_valid                   = Bool()
    val BTB_tag                     = UInt(BTB_tag_size.W)
    val BTB_target                  = UInt(32.W)   // FIXME: this can be slightly smaller

    val BTB_br_type                 = _br_type()
    val BTB_fetch_packet_index      = UInt(log2Ceil(fetchWidth).W)
}

class commit(parameters:Parameters) extends Bundle{
    import parameters._

    val valid   =   Bool()

    val fetch_PC      = UInt(32.W)    // To update gshare/PHT
    val T_NT                = Bool()    // To update BTB (BTB only updates on taken branches)

    
    //val target              = UInt(32.W)
    val br_type             = _br_type()
    val fetch_packet_index  = UInt(log2Ceil(fetchWidth).W)

    val is_misprediction    = Bool()
    val expected_PC         = UInt(32.W)    // For BTB aswell

    // SAVED STATE
    val GHR                 = UInt(GHRWidth.W)
    val TOS                 = UInt(log2Ceil(RASEntries).W)  // To reset GHR
    val NEXT                = UInt(log2Ceil(RASEntries).W)  // To reset GHR
    val RAT_IDX             = UInt(log2Ceil(RATCheckpointCount).W)  // To reset GHR
}

class RAS_update extends Bundle{    // Request call or ret
    val call_addr = UInt(32.W)
    val call      = Bool()
    val ret       = Bool()
}

class RAS_read(parameters:Parameters) extends Bundle{
    import parameters._
    val NEXT      = UInt((log2Ceil(RASEntries).W))
    val TOS       = UInt((log2Ceil(RASEntries).W))
    val ret_addr  = UInt(32.W)
}

class revert(parameters:Parameters) extends Bundle{
    import parameters._
    val GHR               = UInt(GHRWidth.W)
    val PC                = UInt(32.W)
}

class prediction(parameters:Parameters) extends Bundle{
    import parameters._
    val hit         =   Bool()  // FIXME: I dont think this is assigned in BTB since it was added after the fact
    val target      =   UInt(32.W)
    val br_type     =   _br_type()
    val br_mask     =   UInt(fetchWidth.W)
    val GHR         =   UInt(GHRWidth.W)
    val T_NT        =   Bool()
}

class Instruction(parameters:Parameters) extends Bundle{
    import parameters._
    val instruction     =   UInt(32.W)
    val packet_index    =   UInt(log2Ceil(fetchWidth*4).W)    // contains the remainder of the PC. ex: 0, 4, 8, 12, 0, ... for fetchWidth of 4
    val ROB_index       =   UInt(log2Ceil(ROBEntires).W)
}

object RS_types extends ChiselEnum{
    val INT, MEM, FP = Value
}

class decoded_instruction(parameters:Parameters) extends Bundle{
    // Parameters
    import parameters._
    val portCount       =   4
    val physicalRegBits =   log2Ceil(physicalRegCount)    // FIXME!!

    //val valid              =    Bool()

    //val RDold              =   UInt(physicalRegBits.W) // Actual dest
    //val RDold_valid        =   Bool()

    val ready_bits          =   new sources_ready()

    val RD                  =   UInt(physicalRegBits.W) // Actual dest
    val RD_valid            =   Bool()
    val RS1                 =   UInt(physicalRegBits.W)
    val RS1_valid           =   Bool()
    val RS2                 =   UInt(physicalRegBits.W)
    val RS2_valid           =   Bool()
    val IMM                 =   UInt(32.W)
    val FUNCT3              =   UInt(3.W)


    val packet_index        =   UInt(log2Ceil(fetchWidth*4).W)    // contains the remainder of the PC. ex: 0, 4, 8, 12, 0, ... for fetchWidth of 4
    val ROB_index           =   UInt(log2Ceil(ROBEntires).W)

    // uOp info
    val instructionType     =   InstructionType()

    val portID              =   UInt(log2Ceil(portCount).W)  // Decoder assings port ID
    
    val RS_type             =   RS_types()

    val needs_ALU           =  Bool()
    val needs_branch_unit   =  Bool()
    val needs_CSRs          =  Bool()

    val SUBTRACT            =   Bool()
    val MULTIPLY            =   Bool()
    val IMMEDIATE           =   Bool()

    val IS_LOAD             =   Bool()
    val IS_STORE            =   Bool()
    // ADD atomic instructions
}

// decoded instruction after it goes through register read
class read_decoded_instruction(parameters:Parameters) extends Bundle{
    import parameters._
    // Parameters
    val decoded_instruction = new decoded_instruction(parameters)

    // read data from register read 
    val RS1_data        =   UInt(32.W)
    val RS2_data        =   UInt(32.W)
    val PC              =   UInt(32.W)
}

/////////////////////
// DECODER BUNDLES //
/////////////////////


object InstructionType extends ChiselEnum {
    // Based on table 24.1 on RV spec

        // ROW 0
        //              {inst[6:5], inst[4:2]}
        val LOAD        = Value("b00000".U)
        val LOAD_FP     = Value("b00001".U)
        val CUSTOM_0    = Value("b00010".U)
        val MISC_MEM    = Value("b00011".U)
        val OP_IMM      = Value("b00100".U)   // RV32 I type
        val AUIPC       = Value("b00101".U)
        val OP_IMM_32   = Value("b00110".U)

        // ROW 1
        val STORE       = Value("b01000".U)
        val STORE_FP    = Value("b01001".U)
        val CUSTOM_1    = Value("b01010".U)
        val AMO         = Value("b01011".U)
        val OP          = Value("b01100".U)   // RV32 R type
        val LUI         = Value("b01101".U)
        val OP_32       = Value("b01110".U)   // RV64 R type

        // ROW 2
        val MADD        = Value("b10000".U)
        val MSUB        = Value("b10001".U)
        val NMSUB       = Value("b10010".U)
        val NMADD       = Value("b10011".U)
        val OP_FP       = Value("b10100".U)
        // RESERVED
        val CUSTOM_2    = Value("b10110".U)

        // ROW 3
        val BRANCH      = Value("b11000".U)
        val JALR        = Value("b11001".U)
        // RESERVED
        val JAL         = Value("b11011".U)
        val SYSTEM      = Value("b11100".U)
        // RESERVED
        val CUSTOM_3    = Value("b11110".U)
}



class misprediction(parameters:Parameters) extends Bundle{
    import parameters._
    val valid = Bool()

    val is_misprediction = Bool()
    val expected_PC      = UInt(32.W)   // Buffed from backend

    // State revision data
    val GHR     = UInt(GHRWidth.W)
    val NEXT    = UInt(log2Ceil(RASEntries).W)
    val TOS     = UInt(log2Ceil(RASEntries).W)
}


class FTQ_entry(parameters:Parameters) extends Bundle{
    import parameters._

    val valid = Bool()


    // Branch validation data
    val fetch_PC = UInt(32.W)    // fetch packet pc of the base instruction

    val is_misprediction    = Bool()   // If set, predicted_expected_PC represents expected PC. Otherwise, it represents predicted PC
    val predicted_PC        = UInt(32.W)    // if fetch packet contains a branch, this containts the dominant branch address
                                            // if fetch packet does not contain a taken branch, the dominant branch just PC+N

    // State revision data
    val GHR     = UInt(GHRWidth.W)
    val NEXT    = UInt(log2Ceil(RASEntries).W)
    val TOS     = UInt(log2Ceil(RASEntries).W)
    val RAT_IDX = UInt(log2Ceil(RATCheckpointCount).W)

    // FU branch data buffers
    val dominant_index = UInt(log2Ceil(fetchWidth).W)
    val resolved_PC    = UInt(32.W)

}

/////////////////////
// BACKEND BUNDLES //
/////////////////////

// PC stored seperately
class ROB_entry(parameters:Parameters) extends Bundle{
    val valid = Bool()
    // valid
    // busy
    // exception
    // uOp metdata (to know what to do about exceptions, Loads, Stores, etc...)
    val is_branch = Bool()
    // RAT checkpoint

}



class ROB_commit(parameters:Parameters) extends Bundle{
    val placeholder = Bool()
}


class sources_ready extends Bundle{
    val RS1_ready    =   Bool()
    val RS2_ready    =   Bool()
}

// FIXME:  This is messed up 
class RS_entry(parameters:Parameters) extends Bundle{
    import parameters._
    val physicalRegBits = log2Ceil(physicalRegCount)

    val decoded_instruction = new decoded_instruction(parameters)

    val ready_bits          =   new sources_ready()

    // TODO: Add ROB entry (to read PC from PC file)

    val valid        =  Bool()  // Is whole RS entry valid
}

////////////////////////////
// EXECUTION ENGINE PORTS //
////////////////////////////


class FU_output(parameters:Parameters) extends Bundle{
    import parameters._
    // Arithmetic/Load
    val RD                  =   UInt(physicalRegCount.W)
    val RD_data             =   UInt(32.W)
    val RD_valid            =   Bool()

    // Branch
    val instruction_PC      =   UInt(32.W)    // FIXME: is this necessary?
    val branch_taken        =   Bool()
    val target_address      =   UInt(32.W)
    val branch_valid        =   Bool()
    // Address of actual branch instruction?

    val ROB_index           =   UInt(log2Ceil(ROBEntires).W)
    
    val fetch_packet_index  =   UInt(log2Ceil(fetchWidth).W)

    // FIXME: this should just store fetch_packet PC and 
    // fetch packet index
    
    // needs ROB bank
}


class PC_file(fetchWidth:Int){
    val PC = UInt(32.W)
    val index = UInt(fetchWidth.W)
}

//////////
// DRAM //
//////////

class DRAM_request(parameters:Parameters) extends Bundle{
    val addr    = UInt(32.W)
    val wr_data = UInt(32.W)
    val wr_en   = Bool()
}

class DRAM_resp(parameters:Parameters) extends Bundle{
    val data = UInt(256.W)  // Must be same size as cache line
}

