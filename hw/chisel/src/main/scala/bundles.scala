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



// Channels //
class fetch_packet(parameters:Parameters) extends Bundle{
    import parameters._
    val fetch_PC        = UInt(32.W)
    val valid_bits      = Vec(fetchWidth, Bool())
    val instructions    = Vec(fetchWidth, new Instruction(parameters))
}

class metadata extends Bundle{
    val br_type =       _br_type()

    val Imm             = UInt(32.W)
    val instruction_PC  = UInt(32.W)
    val RAS             = UInt(32.W)
    val BTB_target      = UInt(32.W)

    val is_control      = Bool()
}

class instruction_cache_data_line(parameters:Parameters) extends Bundle{
    import parameters._

    val set_bits                        = log2Ceil(L1_instructionCacheSets)
    val byte_offset_bits                = log2Ceil(L1_instructionCacheBlockSizeBytes)

    val tag_bits                        = 32 - set_bits - byte_offset_bits
    val data_bits                       = L1_instructionCacheBlockSizeBytes*8

    val valid   = Bool()
    val tag     = UInt(tag_bits.W)
    val data    = UInt(data_bits.W)

}

class instruction_cache_address_packet(parameters: Parameters) extends Bundle {

    import parameters._

    val set_bits                    = log2Ceil(L1_instructionCacheSets)
    val tag_bits                    = 32 - log2Ceil(L1_instructionCacheBlockSizeBytes)-set_bits    // 32 - bits required to index set - bits required to index within line - 2 bits due to 4 byte aligned data
    val instruction_offset_bits     = log2Ceil(L1_instructionCacheBlockSizeBytes/4)
    val fetch_packet_bits           = log2Ceil(L1_instructionCacheBlockSizeBytes/4/fetchWidth)

    val tag                     = UInt(tag_bits.W)
    val set                     = UInt(set_bits.W)
    val fetch_packet            = UInt(fetch_packet_bits.W)
    val instruction_offset      = UInt(instruction_offset_bits.W)
}




/////////////////
// BP channels //
/////////////////

object _br_type extends ChiselEnum{
    val NONE, BR, JAL, JALR, RET, CALL = Value
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

    val fetch_PC                = UInt(32.W)    // To update gshare/PHT
    val T_NT                    = Bool()    // To update BTB (BTB only updates on taken branches)
    val ROB_index               = UInt(log2Ceil(ROBEntries).W)
    
    val br_type                 = _br_type()
    val fetch_packet_index      = UInt(log2Ceil(fetchWidth).W)  // fetch packet index of the branch

    val is_misprediction        = Bool()
    val expected_PC             = UInt(32.W)    // For BTB aswell

    // SAVED STATE
    val GHR                     = UInt(GHRWidth.W)
    val TOS                     = UInt(log2Ceil(RASEntries).W)
    val NEXT                    = UInt(log2Ceil(RASEntries).W)
    val RAT_index               = UInt(log2Ceil(RATCheckpointCount).W)

    val free_list_front_pointer = UInt((physicalRegBits + 1).W)

    val RD                      = Vec(fetchWidth, UInt(physicalRegBits.W))
    val RD_valid                = Vec(fetchWidth, Bool())

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
    val nextBits = log2Ceil(RASEntries)
    val tosBits  = log2Ceil(RASEntries)
    val nosBits  = log2Ceil(RASEntries)

    //val GHR               = UInt(GHRWidth.W)
    val PC                = UInt(32.W)


    //val RAS_TOS           = UInt(tosBits.W)
    //val RAS_NEXT          = UInt(nextBits)
}

class prediction(parameters:Parameters) extends Bundle{
    import parameters._
    val hit         =   Bool()  // FIXME: I dont think this is assigned in BTB since it was added after the fact
    val target      =   UInt(32.W)
    val br_type     =   _br_type()
    val GHR         =   UInt(GHRWidth.W)
    val T_NT        =   Bool()
}

class Instruction(parameters:Parameters) extends Bundle{
    import parameters._
    val instruction     =   UInt(32.W)
    val packet_index    =   UInt(log2Ceil(fetchWidth*4).W)    // contains the remainder of the PC. ex: 0, 4, 8, 12, 0, ... for fetchWidth of 4
    val ROB_index       =   UInt(log2Ceil(ROBEntries).W)
}

object RS_types extends ChiselEnum{
    val INT, MEM, FP = Value
}

class decoded_instruction(parameters:Parameters) extends Bundle{
    // Parameters
    import parameters._

    val ready_bits          =   new sources_ready()

    val RD                  =  UInt(physicalRegBits.W) // Actual dest
    val RD_valid            =  Bool()
    val RS1                 =  UInt(physicalRegBits.W)
    val RS1_valid           =  Bool()
    val RS2                 =  UInt(physicalRegBits.W)
    val RS2_valid           =  Bool()
    val IMM                 =  UInt(21.W)
    val FUNCT3              =  UInt(3.W)


    val packet_index        =  UInt(log2Ceil(fetchWidth).W)
    val ROB_index           =  UInt(log2Ceil(ROBEntries).W)
    val MOB_index           =  UInt(log2Ceil(MOBEntries).W)
    val FTQ_index           =  UInt(log2Ceil(FTQEntries).W)

    // uOp info
    val instructionType     =  InstructionType()

    val portID              =  UInt(log2Ceil(4).W)  // Decoder assings port ID
    
    val RS_type             =  RS_types()

    val needs_ALU           =  Bool()
    val needs_branch_unit   =  Bool()
    val needs_CSRs          =  Bool()

    val SUBTRACT            =  Bool()
    val MULTIPLY            =  Bool()

    val IS_IMM              =  Bool() 

    val memory_type         =  memory_type_t()   // LOAD/STORE
    val access_width        =  access_width_t()  // B/HW/W

    // ADD atomic instructions
}


class decoded_fetch_packet(parameters:Parameters) extends Bundle{
    import parameters._
    val fetch_PC                = UInt(32.W)
    val decoded_instruction     = Vec(fetchWidth, new decoded_instruction(parameters))
    val valid_bits              = Vec(fetchWidth, Bool())

    val RAT_index               = UInt(log2Ceil(RATCheckpointCount).W)
    val free_list_front_pointer = UInt((physicalRegBits + 1).W)
}

// decoded instruction after it goes through register read
class read_decoded_instruction(parameters:Parameters) extends Bundle{
    import parameters._
    // Parameters
    val decoded_instruction = new decoded_instruction(parameters)

    // read data from register read 
    val RS1_data        =   UInt(32.W)
    val RS2_data        =   UInt(32.W)
    val fetch_PC        =   UInt(32.W)
}

/////////////////////
// DECODER BUNDLES //
/////////////////////


object InstructionType extends ChiselEnum {
    // Based on table 24.1 on RV spec

        // ROW 0
        //              (inst[6:5], inst[4:2])
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

    val T_NT = Bool()
    val br_type = _br_type()

    // State revision data
    // this should be moved to the ROB
    val GHR     = UInt(GHRWidth.W)
    val NEXT    = UInt(log2Ceil(RASEntries).W)
    val TOS     = UInt(log2Ceil(RASEntries).W)

    // FU branch data buffers
    val dominant_index = UInt(log2Ceil(fetchWidth).W)
    val resolved_PC    = UInt(32.W)

}

/////////////////////
// BACKEND BUNDLES //
/////////////////////

class ROB_output(parameters:Parameters) extends Bundle{
    import parameters._
    
    // 1 per row data
    val row_valid               = Bool()
    val fetch_PC                = UInt(32.W)
    val RAT_index               = UInt(log2Ceil(RATCheckpointCount).W)
    val ROB_index               = UInt(log2Ceil(ROBEntries).W)

    val free_list_front_pointer = UInt((physicalRegBits + 1).W)

    // N per row 
    val ROB_entries             = Vec(fetchWidth, new ROB_entry(parameters))    // "static" instruction data
    val complete                = Vec(fetchWidth, Bool())                       // Is instruction complete
    //val exception                = Vec(fetchWidth, Bool())                      // Is instruction complete
}

class ROB_shared(parameters:Parameters) extends Bundle{
    import parameters._

    val fetch_PC                = UInt(32.W)
    val RAT_index               = UInt(log2Ceil(RATCheckpointCount).W)

    val free_list_front_pointer = UInt((physicalRegBits + 1).W)
}

// ROB entries that pertain to each instruction independantly (this info goes in a standalone bank)
class ROB_entry(parameters:Parameters) extends Bundle{
    import parameters._

    val valid       = Bool()  // is this particular instruction valid?
    val is_branch   = Bool()

    //val exception   = Bool()
    val memory_type = memory_type_t()

    val RD          =   UInt(physicalRegBits.W)
    val RD_valid    =   Bool()
    //val RD_old      =   UInt(physicalRegBits.W)
}

class ROB_WB(parameters:Parameters) extends Bundle{
    val busy        = Bool()
    val exception   = Bool()
}

class sources_ready extends Bundle{
    val RS1_ready    =   Bool()
    val RS2_ready    =   Bool()
}

// FIXME:  This is messed up 
class RS_entry(parameters:Parameters) extends Bundle{
    import parameters._

    val decoded_instruction = new decoded_instruction(parameters)

    //val ready_bits          =   new sources_ready()

    val valid               =  Bool()  // Is whole RS entry valid
}

class MEMRS_entry(parameters:Parameters) extends Bundle{
    import parameters._
    val decoded_instruction =  new decoded_instruction(parameters)

    //val ready_bits          =  new sources_ready()

    val fetch_PC            =  UInt(32.W)
    val committed            =  Bool()  // Has this instruction committed
    val valid               =  Bool()  // Is whole RS entry valid
}

////////////////////////////
// EXECUTION ENGINE PORTS //
////////////////////////////


class FU_output(parameters:Parameters) extends Bundle{
    import parameters._
    // Arithmetic/Load
    val RD                  =   UInt(physicalRegBits.W)
    val RD_data             =   UInt(32.W)
    val RD_valid            =   Bool()

    // Branch
    val fetch_PC            =   UInt(32.W)    // FIXME: is this necessary?
    val branch_taken        =   Bool()
    val target_address      =   UInt(32.W)
    val branch_valid        =   Bool()

    // MEM
    val address             =   UInt(32.W)
    val memory_type         =   memory_type_t()   // LOAD/STORE
    val access_width        =   access_width_t()  // B/HW/W
    val unsigned            =   Bool()            // signed/unsigned
    val wr_data             =   UInt(32.W)

    // MOB
    val MOB_index           =   UInt(log2Ceil(MOBEntries).W)


    val ROB_index           =   UInt(log2Ceil(ROBEntries).W)
    val FTQ_index           =   UInt(log2Ceil(FTQEntries).W)
    
    val fetch_packet_index  =   UInt(log2Ceil(fetchWidth).W)
}


class PC_file(fetchWidth:Int){
    val PC = UInt(32.W)
    val index = UInt(fetchWidth.W)
}


//////////
// DRAM //
//////////

class DRAM_request(parameters:Parameters) extends Bundle{   // FIXME: change this to something generic like MMIO request...
    val addr    = UInt(32.W)
    val wr_data = UInt(32.W)
    val wr_en   = Bool()
}

class DRAM_response(parameters:Parameters) extends Bundle{
    val data = UInt(256.W)  // Must be same size as cache line
}


// FIXME:
// There should be a standard memory request bus
// And a seperate dram repsonse bus
//

class memory_request(parameters:Parameters) extends Bundle{
    val addr    = UInt(32.W)
    val wr_data = UInt(32.W)
    val wr_en   = Bool()
}

class memory_response(parameters:Parameters) extends Bundle{
    val data = UInt(32.W)
}


class backend_memory_request(parameters:Parameters) extends Bundle{
    import parameters._
    val addr            = UInt(32.W)
    val data            = UInt(32.W)
    val memory_type     = memory_type_t()               // LOAD/STORE
    val access_width    = access_width_t()              // B/HW/W

    val MOB_index       = UInt(log2Ceil(MOBEntries).W)
}

class backend_memory_response(parameters:Parameters) extends Bundle{
    import parameters._
    val addr            = UInt(32.W)
    val data            = UInt(32.W)
    val memory_type     = memory_type_t() // LOAD/STORE
    val access_width    = access_width_t()              // B/HW/W

    val MOB_index       = UInt(log2Ceil(MOBEntries).W)
}




// LDQ //

object memory_type_t extends ChiselEnum{
    val NONE, LOAD, STORE = Value
}

object access_width_t extends ChiselEnum{
    val NONE, B, HW, W = Value
}

class memory_access(parameters:Parameters) extends Bundle{   // output of the AGU
    import parameters._
    val memory_type     = memory_type_t()   // LOAD/STORE
    val RD              = UInt(physicalRegBits.W)
    val access_width    = access_width_t()  // B/HW/W
    val unsigned        = Bool()            // signed/unsigned
    val address         = UInt(32.W)
    val wr_data         = UInt(32.W)
}



/*loads mark as complete when they are 100% correct and non-speculative.*/
/*That is, loads can mark the RD ready to avoid stalling the pipeline*/
/*But have the possibility of causing an exception that prevents them from committing*/
/*Loads are not freed until they actually commit.*/
class MOB_entry(parameters:Parameters) extends Bundle{
    import parameters._

    val valid           = Bool()
    val memory_type     = memory_type_t()

    val ROB_index       = UInt(log2Ceil(ROBEntries).W)

    val address         = UInt(32.W)        // LOAD/STORE address
    val access_width    = access_width_t()  // B/HW/W

    val RD              = UInt(physicalRegBits.W) // dest reg
    val data            = UInt(32.W)              

    // Entry state
    val pending         = Bool()    // load request sent to cache
    val loaded          = Bool()    // load recieved
    val committed       = Bool()    // entry committed
    val violation       = Bool()    // entry does not violate ordering (load/load or store/load)

    val fired           = Bool()

}


// PNR?



/////////
// CSR //
/////////

