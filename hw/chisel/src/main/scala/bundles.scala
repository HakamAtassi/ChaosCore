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
class fetch_packet(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._
    val fetch_PC        = UInt(32.W)
    val valid_bits      = Vec(fetchWidth, Bool())
    val instructions    = Vec(fetchWidth, new Instruction(coreParameters))

    val GHR             = UInt(GHRWidth.W)
    val NEXT            = UInt(log2Ceil(RASEntries).W)
    val TOS             = UInt(log2Ceil(RASEntries).W)
}

class metadata extends Bundle{
    val br_type =       br_type_t()

    val Imm             = UInt(32.W)
    val instruction_PC  = UInt(32.W)
    val RAS             = UInt(32.W)
    val BTB_target      = UInt(32.W)

    val is_control      = Bool()
}

class instruction_cache_data_line(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._

    val set_bits:Int                        = log2Ceil(L1_instructionCacheSets)
    val byte_offset_bits:Int                = log2Ceil(L1_instructionCacheBlockSizeBytes)

    val tag_bits:Int                        = 32 - set_bits - byte_offset_bits
    val data_bits:Int                       = L1_instructionCacheBlockSizeBytes*8

    val valid   = Bool()
    val tag     = UInt(tag_bits.W)
    val data    = UInt(data_bits.W)

}

class instruction_cache_address_packet(coreParameters: CoreParameters) extends Bundle {
    import coreParameters._

    val set_bits:Int                    = log2Ceil(L1_instructionCacheSets)
    val tag_bits:Int                    = 32 - log2Ceil(L1_instructionCacheBlockSizeBytes)-set_bits    // 32 - bits required to index set - bits required to index within line - 2 bits due to 4 byte aligned data
    val instruction_offset_bits:Int     = log2Ceil(L1_instructionCacheBlockSizeBytes/4)
    val fetch_packet_bits:Int           = log2Ceil(L1_instructionCacheBlockSizeBytes/4/fetchWidth)

    val tag                     = UInt(tag_bits.W)
    val set                     = UInt(set_bits.W)
    val fetch_packet            = UInt(fetch_packet_bits.W)
    val instruction_offset      = UInt(instruction_offset_bits.W)
}




/////////////////
// BP channels //
/////////////////

object br_type_t extends ChiselEnum{
    val NONE, BR, JAL, JALR, RET, CALL = Value
}

class BTB_entry(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._

    val BTB_tag_size:Int            = 32 - log2Ceil(BTBEntries) - 2

    val BTB_valid                   = Bool()
    val BTB_tag                     = UInt(BTB_tag_size.W)
    val BTB_target                  = UInt(32.W)   // FIXME: this can be slightly smaller

    val BTBbr_type_t                 = br_type_t()
    val BTB_fetch_packet_index      = UInt(log2Ceil(fetchWidth).W)
}

class commit(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._

    val fetch_PC                = UInt(32.W)    // To update gshare/PHT
    val T_NT                    = Bool()    // To update BTB (BTB only updates on taken branches)
    val ROB_index               = UInt(log2Ceil(ROBEntries).W)

    val br_type                 = br_type_t()
    val fetch_packet_index      = UInt(log2Ceil(fetchWidth).W)  // fetch packet index of the branch

    val is_misprediction        = Bool()
    val exception               = Bool()
    val expected_PC             = UInt(32.W)    // For BTB aswell

    // SAVED STATE
    val GHR                     = UInt(GHRWidth.W)
    val TOS                     = UInt(log2Ceil(RASEntries).W)
    val NEXT                    = UInt(log2Ceil(RASEntries).W)

    val free_list_front_pointer = UInt((physicalRegBits + 1).W)

    val RDold                   = Vec(fetchWidth, UInt(architecturalRegBits.W))
    val RD                      = Vec(fetchWidth, UInt(physicalRegBits.W))
    val RD_valid                = Vec(fetchWidth, Bool())
}

//class exception(coreParameters:CoreParameters) extends Bundle{
//}


class RAS_update extends Bundle{    // Request call or ret
    val call_addr = UInt(32.W)
    val call      = Bool()
    val ret       = Bool()
}

class RAS_read(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._
    val NEXT      = UInt((log2Ceil(RASEntries).W))
    val TOS       = UInt((log2Ceil(RASEntries).W))
    val ret_addr  = UInt(32.W)
}

class revert(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._
    val nextBits:Int = log2Ceil(RASEntries)
    val tosBits:Int  = log2Ceil(RASEntries)
    val nosBits:Int  = log2Ceil(RASEntries)

    //val GHR               = UInt(GHRWidth.W)
    val PC                = UInt(32.W)


    //val RAS_TOS           = UInt(tosBits.W)
    //val RAS_NEXT          = UInt(nextBits)
}

class prediction(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._
    val hit         =   Bool()  // FIXME: I dont think this is assigned in BTB since it was added after the fact
    val target      =   UInt(32.W)
    val br_type     =   br_type_t()
    val GHR         =   UInt(GHRWidth.W)
    val T_NT        =   Bool()
}

class Instruction(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._
    val instruction     =   UInt(32.W)
    val packet_index    =   UInt(log2Ceil(fetchWidth*4).W)    // contains the remainder of the PC. ex: 0, 4, 8, 12, 0, ... for fetchWidth of 4
    val ROB_index       =   UInt(log2Ceil(ROBEntries).W)
}

object RS_types extends ChiselEnum{
    val INT, MEM, FP = Value
}

class decoded_instruction(coreParameters:CoreParameters) extends Bundle{
    // coreParameters
    import coreParameters._

    val ready_bits          =  new sources_ready()

    val RDold               =  UInt(architecturalRegBits.W) // Actual dest
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


class decoded_fetch_packet(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._
    val fetch_PC                = UInt(32.W)
    val decoded_instruction     = Vec(fetchWidth, new decoded_instruction(coreParameters))
    val valid_bits              = Vec(fetchWidth, Bool())

    val GHR                     = UInt(GHRWidth.W)
    val TOS                     = UInt(log2Ceil(RASEntries).W)
    val NEXT                    = UInt(log2Ceil(RASEntries).W)


    val free_list_front_pointer = UInt((physicalRegBits + 1).W)

}

// decoded instruction after it goes through register read
class read_decoded_instruction(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._
    // coreParameters
    val decoded_instruction = new decoded_instruction(coreParameters)

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



class misprediction(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._
    val valid = Bool()

    val is_misprediction = Bool()
    val expected_PC      = UInt(32.W)   // Buffed from backend

    // State revision data
    val GHR     = UInt(GHRWidth.W)
    val NEXT    = UInt(log2Ceil(RASEntries).W)
    val TOS     = UInt(log2Ceil(RASEntries).W)
}


class FTQ_entry(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._

    val valid = Bool()

    // Branch validation data
    val fetch_PC = UInt(32.W)    // fetch packet pc of the base instruction

    val is_misprediction    = Bool()   // If set, predicted_expected_PC represents expected PC. Otherwise, it represents predicted PC
    val predicted_PC        = UInt(32.W)    // if fetch packet contains a branch, this containts the dominant branch address
                                            // if fetch packet does not contain a taken branch, the dominant branch just PC+N

    val ROB_index               = UInt(log2Ceil(ROBEntries).W)

    val T_NT = Bool()
    val br_type = br_type_t()

    // FU branch data buffers
    val dominant_index = UInt(log2Ceil(fetchWidth).W)
    val resolved_PC    = UInt(32.W)

}

/////////////////////
// BACKEND BUNDLES //
/////////////////////

class ROB_output(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._
    
    // 1 per row data
    val row_valid               = Bool()
    val fetch_PC                = UInt(32.W)
    val ROB_index               = UInt(log2Ceil(ROBEntries).W)

    val GHR     = UInt(GHRWidth.W)
    val NEXT    = UInt(log2Ceil(RASEntries).W)
    val TOS     = UInt(log2Ceil(RASEntries).W)
    val free_list_front_pointer = UInt((physicalRegBits + 1).W)


    // N per row 
    val ROB_entries             = Vec(fetchWidth, new ROB_entry(coreParameters))    // "static" instruction data
    val complete                = Vec(fetchWidth, Bool())                       // Is instruction complete
    val exception               = Vec(fetchWidth, Bool())                      // Is instruction complete
}

class ROB_shared(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._

    val fetch_PC                = UInt(32.W)

    val free_list_front_pointer = UInt((physicalRegBits + 1).W)

    val GHR     = UInt(GHRWidth.W)
    val NEXT    = UInt(log2Ceil(RASEntries).W)
    val TOS     = UInt(log2Ceil(RASEntries).W)
}

// ROB entries that pertain to each instruction independantly (this info goes in a standalone bank)
class ROB_entry(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._

    val valid       = Bool()  // is this particular instruction valid?
    val is_branch   = Bool()

    val memory_type = memory_type_t()

    val RD          =   UInt(physicalRegBits.W)
    val RD_valid    =   Bool()
    val RDold       =   UInt(architecturalRegBits.W)
}

class ROB_WB(coreParameters:CoreParameters) extends Bundle{
    val busy        = Bool()
    val exception   = Bool()
}

class sources_ready extends Bundle{
    val RS1_ready    =   Bool()
    val RS2_ready    =   Bool()
}

// FIXME:  This is messed up 
class RS_entry(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._

    val decoded_instruction = new decoded_instruction(coreParameters)

    //val ready_bits          =   new sources_ready()

    val valid               =  Bool()  // Is whole RS entry valid
}

class MEMRS_entry(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._
    val decoded_instruction =  new decoded_instruction(coreParameters)

    //val ready_bits          =  new sources_ready()

    val fetch_PC            =  UInt(32.W)
    //val committed            =  Bool()  // Has this instruction committed
    val valid               =  Bool()  // Is whole RS entry valid
}

////////////////////////////
// EXECUTION ENGINE PORTS //
////////////////////////////


class FU_output(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._
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
    val is_unsigned         =   Bool()            // signed/is_unsigned
    val wr_data             =   UInt(32.W)

    // MOB
    val MOB_index           =   UInt(log2Ceil(MOBEntries).W)


    val ROB_index           =   UInt(log2Ceil(ROBEntries).W)
    val FTQ_index           =   UInt(log2Ceil(FTQEntries).W)
    
    val fetch_packet_index  =   UInt(log2Ceil(fetchWidth).W)


    val exception           =   Bool()
}


class PC_file(fetchWidth:Int){
    val PC = UInt(32.W)
    val index = UInt(fetchWidth.W)
}


//////////
// DRAM //
//////////

class DRAM_request(coreParameters:CoreParameters) extends Bundle{   // FIXME: change this to something generic like MMIO request...
    val addr    = UInt(32.W)
    val wr_data = UInt(32.W)
    val wr_en   = Bool()
}

class DRAM_response(coreParameters:CoreParameters) extends Bundle{
    val data = UInt(256.W)  // Must be same size as cache line
}


// FIXME:
// There should be a standard memory request bus
// And a seperate dram repsonse bus
//

class frontend_memory_request(coreParameters:CoreParameters) extends Bundle{
    val addr    = UInt(32.W)
    val wr_data = UInt(32.W)
    val wr_en   = Bool()
}

class frontend_memory_response(coreParameters:CoreParameters) extends Bundle{
    val data = UInt(32.W)
}


class backend_memory_request(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._
    val addr            = UInt(32.W)
    val data            = UInt(32.W)
    val memory_type     = memory_type_t()               // LOAD/STORE
    val access_width    = access_width_t()              // B/HW/W

    val MOB_index       = UInt(log2Ceil(MOBEntries).W)
}

class backend_memory_response(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._
    //val addr            = UInt(32.W)
    val data            = UInt(32.W)
    //val memory_type     = memory_type_t() // LOAD/STORE
    //val access_width    = access_width_t()              // B/HW/W
    val MOB_index       = UInt(log2Ceil(MOBEntries).W)
}




// LDQ //

object memory_type_t extends ChiselEnum{
    val NONE, LOAD, STORE = Value
}

object access_width_t extends ChiselEnum{
    val NONE, B, HW, W = Value
}

class memory_access(coreParameters:CoreParameters) extends Bundle{   // output of the AGU
    import coreParameters._
    val memory_type     = memory_type_t()   // LOAD/STORE
    val RD              = UInt(physicalRegBits.W)
    val access_width    = access_width_t()  // B/HW/W
    val is_unsigned     = Bool()            // signed/is_unsigned
    val address         = UInt(32.W)
    val wr_data         = UInt(32.W)
}

////////
// TL //
////////


object TileLink_Opcodes extends ChiselEnum{
val Acquire, 
    Get, 
    PutFullData, 
    PutPartialData, 
    ArithmeticData, 
    LogicalData, 
    Hint, 
    AccessAck, 
    AccessAckData, 
    HintAck, 
    Grant, 
    GrantData, 
    Release, 
    ReleaseData, 
    Probe, 
    ProbeAck, 
    ProbeAckData = Value
}


class TileLink_Channel_A extends Bundle {
  val a_opcode   = UInt(3.W) 
  val a_param    = UInt(3.W) 
  val a_size     = UInt(3.W) 
  val a_source   = UInt(4.W) 
  val a_address  = UInt(32.W)
  val a_mask     = UInt(4.W) 
  val a_data     = UInt(256.W)
}

class TileLink_Channel_D extends Bundle {
  val d_opcode   = UInt(3.W)
  val d_param    = UInt(3.W)
  val d_size     = UInt(3.W)
  val d_source   = UInt(4.W)
  val d_sink     = UInt(4.W)
  val d_data     = UInt(256.W)
}





/*loads mark as complete when they are 100% correct and non-speculative.*/
/*That is, loads can mark the RD ready to avoid stalling the pipeline*/
/*But have the possibility of causing an exception that prevents them from committing*/
/*Loads are not freed until they actually commit.*/
class MOB_entry(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._

    val valid           = Bool()
    val memory_type     = memory_type_t()

    val ROB_index       = UInt(log2Ceil(ROBEntries).W)
    val fetch_packet_index      = UInt(log2Ceil(fetchWidth).W)  // fetch packet index of the branch

    val address         = UInt(32.W)        // LOAD/STORE address
    val access_width    = access_width_t()  // B/HW/W

    val RD              = UInt(physicalRegBits.W) // dest reg
    val data            = UInt(32.W)              
    val data_valid      = Bool()

    // Entry state
    val pending         = Bool()    // AGU data valid but not requested from cache
    val completed       = Bool()    // Load/Store sent to FU bus
    val committed       = Bool()    // entry committed
    val exception       = Bool()    // entry violated ordering (load/load or store/load)

}


class MSHR_entry(coreParameters:CoreParameters) extends Bundle{
    // An entire row of the MSHR.
    import coreParameters._
    val address                 =   UInt(32.W)      // address shared across MSHR row
    val miss_request            =   Vec(L1_MSHRWidth, new backend_memory_request(coreParameters))
    val allocate_way            =   UInt(log2Ceil(L1_DataCacheWays).W)

    val front_pointer           =   UInt(log2Ceil(L1_MSHRWidth).W)
    val back_pointer            =   UInt(log2Ceil(L1_MSHREntries).W)

    def queue(miss_request:backend_memory_request): Unit = {
        //miss_request(back_index) := DontCare  // FIXME: actually write data...
        back_pointer := back_pointer + 1.U
    }

    def dequeue: Unit = {
        miss_request(front_pointer) := 0.U.asTypeOf(new backend_memory_response(coreParameters))
        front_pointer := front_pointer + 1.U
    }

    def front: backend_memory_request = {
        miss_request(front_pointer)
    }

    def full: Bool = {
        // MSHR entry pointers do not wrap around. If full, it does not accept any additional entries. 
        // When the queue begins emptying, it empties all the way and clears the row.
        (front_pointer + 1.U) === L1_MSHRWidth.U
    }

    def empty: Bool = {
        // MSHR entry pointers do not wrap around. If full, it does not accept any additional entries. 
        // When the queue begins emptying, it empties all the way and clears the row.
        front_pointer === back_pointer
    }



}


////////////
// DATA $ //
////////////







/////////
// CSR //
/////////




/////////
// AXI //
/////////

class AXI_AW(nocParameters:NOCParameters) extends Bundle{
  import nocParameters._
  val awid      = UInt(ID_WIDTH.W)
  val awaddr    = UInt(ADDR_WIDTH.W)
  val awlen     = UInt(8.W)
  val awsize    = UInt(3.W)
  val awburst   = UInt(2.W)
  val awlock    = UInt(1.W)
  val awcache   = UInt(4.W)
  val awprot    = UInt(3.W)
  val awqos     = UInt(4.W)
  val awregion  = UInt(4.W)
  val awuser    = UInt(AWUSER_WIDTH.W)
}


class AXI_W(nocParameters:NOCParameters) extends Bundle{
  import nocParameters._
  val wdata = UInt(ADDR_WIDTH.W)
  val wstrb = UInt(STRB_WIDTH.W)
  val wlast = UInt(1.W)
  val wuser = UInt(WUSER_WIDTH.W)
}

class AXI_B(nocParameters:NOCParameters) extends Bundle{
  import nocParameters._
  val bid   = UInt(ID_WIDTH.W)
  val bresp = UInt(2.W)
  val buser = UInt(BUSER_WIDTH.W)
}

class AXI_AR(nocParameters:NOCParameters) extends Bundle{
  import nocParameters._
  val arid    = UInt(ID_WIDTH.W)
  val araddr  = UInt(ADDR_WIDTH.W)
  val arlen   = UInt(8.W)
  val arsize  = UInt(3.W)
  val arburst = UInt(2.W)
  val arlock  = UInt(1.W)
  val arcache = UInt(4.W)
  val arprot  = UInt(3.W)
  val arqos   = UInt(4.W)
  val arregion= UInt(4.W)
  val aruser  = UInt(ARUSER_WIDTH.W)
}

class AXI_R(nocParameters:NOCParameters) extends Bundle{
  import nocParameters._
  val rid   = UInt(ID_WIDTH.W)
  val rdata = UInt(DATA_WIDTH.W)
  val rresp = UInt(2.W)
  val rlast = UInt(1.W)
  val ruser = UInt(RUSER_WIDTH.W)
}

// AXI master IO
class AXIFullIO(nocParameters:NOCParameters) extends Bundle {
  import nocParameters._
  val AXI_AW = Decoupled(new AXI_AW(nocParameters))                 // AXI Write address request
  val AXI_W  = Decoupled(new AXI_W(nocParameters))                  // AXI Write Data 
  val AXI_B  = Flipped(Decoupled(new AXI_B(nocParameters)))         // AXI Write Response
  val AXI_AR = Decoupled(new AXI_AR(nocParameters))                 // AXI Read Address
  val AXI_R  = Flipped(Decoupled(new AXI_R(nocParameters)))         // AXI read Response
}



// AXI_slave_port is the Flipped() of an AXI master port

