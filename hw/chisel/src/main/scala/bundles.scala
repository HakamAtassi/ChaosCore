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
import chisel3.util._
import java.io.{File, FileWriter}
import java.rmi.server.UID
//import chisel3.experimental.ChiselEnum


import helperFunctions.getBTBTagBits



// Channels //
class fetch_packet(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._
    val fetch_PC        = UInt(32.W)
    val valid_bits      = Vec(fetchWidth, Bool())
    val instructions    = Vec(fetchWidth, new Instruction(coreParameters))

    val prediction      = new prediction(coreParameters)

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
    val byte_offset_bits:Int                = log2Ceil(L1_cacheLineSizeBytes)

    val tag_bits:Int                        = 32 - set_bits - byte_offset_bits
    val data_bits:Int                       = L1_cacheLineSizeBytes*8

    val valid   = Bool()
    val tag     = UInt(tag_bits.W)
    val data    = UInt(data_bits.W)

}

class instruction_cache_address_packet(coreParameters: CoreParameters) extends Bundle {
    import coreParameters._

    val set_bits:Int                    = log2Ceil(L1_instructionCacheSets)
    val tag_bits:Int                    = 32 - log2Ceil(L1_cacheLineSizeBytes)-set_bits    // 32 - bits required to index set - bits required to index within line - 2 bits due to 4 byte aligned data
    val instruction_offset_bits:Int     = log2Ceil(L1_cacheLineSizeBytes/4)
    val fetch_packet_bits:Int           = log2Ceil(L1_cacheLineSizeBytes/4/fetchWidth)

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

    val valid                   = Bool()

    val tag                     = UInt(32.W)

    val target                  = UInt(32.W)   // FIXME: this can be slightly smaller
    val br_mask                 = UInt(log2Ceil(fetchWidth).W)   // which entry in the fetch packet does this BTB prediction entry correspond to
    val br_type                 = br_type_t()
}

class insn_commit(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._

    // BE VERY CAREFUL ABOUT WHICH OF THESE SINGALS YOU USE 
    // THE COMMITTED FUNCTION IS THE ACTUAL "THIS INSTRUCTION IS ABOUT TO EXIT THE PIPELINE FULLY" SIGNAL
    // WB_committed is just "nothing prior to this instruction has caused issues, but may or may not actually be complete". Think stores, CSR insns, etc...

    val WB_complete                = Bool()
    val WB_committed               = Bool()

    def committed: Bool = {
        WB_committed && WB_complete
    }


    val MOB_index               = UInt(log2Ceil(MOBEntries).W)
    val MOB_valid               = Bool()   // only valid on loads and stores

    val RD                      = UInt(architecturalRegBits.W)
    val RD_valid                = Bool()
    val PRD                     = UInt(physicalRegBits.W)
    val PRDold                  = UInt(physicalRegBits.W)
}

class commit(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._

    // GLOBAL COMMIT SIGNALS
    val fetch_PC                = UInt(32.W)    // To update gshare/PHT
    val ROB_index               = UInt(log2Ceil(ROBEntries).W)

    val fetch_packet_index      = UInt(log2Ceil(fetchWidth).W)  // fetch packet index of the branch

    val is_misprediction        = Bool()
    val expected_PC             = UInt(32.W)    // For BTB aswell

    // SAVED STATE
    val GHR                     = UInt(GHRWidth.W)
    val TOS                     = UInt(log2Ceil(RASEntries).W)
    val NEXT                    = UInt(log2Ceil(RASEntries).W)

    val free_list_front_pointer = UInt((physicalRegBits + 1).W)

    // INSN COMMIT SIGNALS
    val insn_commit             = Vec(fetchWidth, ValidIO(new insn_commit(coreParameters)))

    // BP signals
    val T_NT                    = Bool()    // set when taken branch is committed
    val target                  = UInt(32.W)
    val br_type                 = br_type_t()
    val br_mask                 = UInt(log2Ceil(fetchWidth).W)

}


class flush(coreParameters:CoreParameters) extends Bundle{
    val is_misprediction    = Bool()
    val is_exception        = Bool()
    val is_interrupt        = Bool()
    
    val is_fence            = Bool()
    val is_CSR              = Bool()

    def is_valid(): Bool = {
        is_misprediction || is_exception || is_fence || is_CSR || is_interrupt
    }


    val exception_cause     = EX_CAUSE()

    val flushing_PC         = UInt(32.W)    // PC of the instruciton causing the flush
    val redirect_PC         = UInt(32.W)    // PC the instruction should redirect to
}


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
    val T_NT        =   Bool()  // FIXME: I dont think this is assigned in BTB since it was added after the fact
    val target      =   UInt(32.W)
    val br_type     =   br_type_t() 
    val br_mask     =   UInt(log2Ceil(fetchWidth).W) // OH of the taken branch in the fetch packet
}

class resolved_branch(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._
    val hit         =   Bool()  // FIXME: I dont think this is assigned in BTB since it was added after the fact
    val target      =   UInt(32.W)
    val br_type     =   br_type_t()
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

    // ~30 bits
    val ready_bits          =  new sources_ready()

    val valid               =  Bool()

    val RD                  =  UInt(architecturalRegBits.W) 
    val PRD                 =  UInt(physicalRegBits.W)
    val PRDold              =  UInt(physicalRegBits.W)

    val RS1                 =  UInt(physicalRegBits.W)
    val RS2                 =  UInt(physicalRegBits.W)
    val IMM                 =  UInt(21.W)
    val FUNCT3              =  UInt(3.W)
    val FUNCT7              =  UInt(7.W)

    // ~12 bits
    val packet_index        =  UInt(log2Ceil(fetchWidth).W)
    val ROB_index           =  UInt(log2Ceil(ROBEntries).W)
    val MOB_index           =  UInt(log2Ceil(MOBEntries).W)


    val mem_signed          =  Bool()
    val memory_type         =  memory_type_t()   // LOAD/STORE
    val access_width        =  access_width_t()  // B/HW/W

    // Instruction steering
    val needs_ALU           = Bool()
    val needs_branch_unit   = Bool()
    val needs_CSRs          = Bool()
    val needs_memory        = Bool()
    val needs_mul           = Bool()
    val needs_div           = Bool()
    val needs_FPU           = Bool()

    val assigned_port       = UInt(portCount.W)

    // Operand
    val RS1_valid          = Bool()
    val RS2_valid          = Bool()
    val RD_valid           = Bool()
    val IS_IMM             = Bool()
    val UNSIGNED           = Bool()

    // INSTRUCTION TYPE //
    val BASE_ARITHMETIC    = Bool()
    val MULTIPLY           = Bool()
    val LOAD               = Bool()
    val STORE              = Bool()
    val CTRL               = Bool()
    val CSRRW              = Bool()
    val XRET               = Bool()
    val ENV                = Bool()
    val FENCE              = Bool()

    val LUI                = Bool()
    val AUIPC              = Bool()
    val JAL                = Bool()
    val JALR               = Bool()

    // MISC //
    val FLUSH              = Bool()



    def needs_INT_RS: Bool = {
        val result =    needs_ALU          ||
                        needs_branch_unit  ||
                        needs_CSRs         ||
                        needs_mul          ||
                        needs_div
        result
    }

    def needs_MEM_RS: Bool = {
        needs_memory
    }

    def MOB_valid: Bool = {
        STORE || LOAD
    }

    def CSR_addr: UInt = {
        IMM(11,0).asUInt
    }
}


class decoded_fetch_packet(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._
    val fetch_PC                = UInt(32.W)
    val decoded_instruction     = Vec(fetchWidth, new decoded_instruction(coreParameters))

    val GHR                     = UInt(GHRWidth.W)
    val TOS                     = UInt(log2Ceil(RASEntries).W)
    val NEXT                    = UInt(log2Ceil(RASEntries).W)

    val prediction              = new prediction(coreParameters)

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

/////////////////////
// BACKEND BUNDLES //
/////////////////////

class ROB_uOp_entry(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._
    val decoded_insn = new decoded_instruction(coreParameters)
}

class ROB_WB_entry(coreParameters:CoreParameters) extends Bundle{
    val valid               = Bool()
    val committed           = Bool()    // instruction "committed" (previous instructions do not flush)
    val complete            = Bool()
    val exception           = Bool()
    val exception_cause     = EX_CAUSE()
    val mem_violation       = Bool()    // for e.g., speculative memory violation
    
    val RD_data = if (coreParameters.DEBUG) Some(UInt(32.W)) else None      // for WB data

    //val mem addr = if (coreParameters.DEBUG) Some(UInt(32.W)) else None     // for memory accesses
    val RS1_data = if (coreParameters.DEBUG) Some(UInt(32.W)) else None     // for CSR/memory writes

}

class ROB_instruction_entry(coreParameters:CoreParameters) extends Bundle{
    val uOp = new ROB_uOp_entry(coreParameters)
    val WB = new ROB_WB_entry(coreParameters)

    def commit:Bool = { // just a helper function
        (WB.valid && WB.complete) || uOp.decoded_insn.STORE || uOp.decoded_insn.needs_CSRs
    }

    def retire:Bool = { // instruction can safely exit pipeline
        (WB.valid && WB.complete && !WB.exception && WB.committed) 
    }
}

class ROB_shared_entry(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._

    // fetch packet metadata
    val fetch_PC                = UInt(32.W)

    val free_list_front_pointer = UInt((physicalRegBits + 1).W)

    val GHR     = UInt(GHRWidth.W)
    val NEXT    = UInt(log2Ceil(RASEntries).W)
    val TOS     = UInt(log2Ceil(RASEntries).W)


    val prediction      = new prediction(coreParameters)
}


class ROB_branch_entry(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._

    val target_PC = UInt(32.W)
    val taken     = Bool()
}



// ROB entries that pertain to each instruction independantly (this info goes in a standalone bank)

class sources_ready extends Bundle{
    val RS1_ready    =   Bool()
    val RS2_ready    =   Bool()
}

class RS_entry(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._

    val decoded_instruction = new decoded_instruction(coreParameters)
    val committed           =  Bool()  // 
    val valid               =  Bool()  // 
}

class MEMRS_entry(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._
    val decoded_instruction =  new decoded_instruction(coreParameters)
    val fetch_PC            =  UInt(32.W)
    val valid               =  Bool()  // Is whole RS entry valid
}

////////////////////////////
// EXECUTION ENGINE PORTS //
////////////////////////////


class FU_output(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._
    // Arithmetic/Load
    val PRD                 =   UInt(physicalRegBits.W)
    val RD_data             =   UInt(32.W)
    val RS1_data            =   if (coreParameters.DEBUG) Some(UInt(32.W)) else None     // for CSR/memory writes
    val RD_valid            =   Bool()

    // Branch
    val CTRL                =   Bool()
    val fetch_PC            =   UInt(32.W)    // FIXME: is this necessary?
    val branch_taken        =   Bool()
    val target_address      =   UInt(32.W)
    val branch_valid        =   Bool()

    // Exception 
    val exception           =   Bool()          // does the instruction cause an exception?
    val exception_cause     =   EX_CAUSE()
    //val mstat               =   PRIVILAGE()     // What privilige was this instruction executed in?


    // MEM
    val address             =   UInt(32.W)
    val memory_type         =   memory_type_t()   // LOAD/STORE
    val access_width        =   access_width_t()  // B/HW/W
    val is_unsigned         =   Bool()            // signed/is_unsigned
    val wr_data             =   UInt(32.W)

    // MOB
    val MOB_index           =   UInt(log2Ceil(MOBEntries).W)

    val ROB_index           =   UInt(log2Ceil(ROBEntries).W)
    
    val fetch_packet_index  =   UInt(log2Ceil(fetchWidth).W)

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


// FIXME:
// There should be a standard memory request bus
// And a seperate dram repsonse bus
class frontend_memory_request(coreParameters:CoreParameters) extends Bundle{
    val addr    = UInt(32.W)
    val wr_data = UInt(32.W)
    val wr_en   = Bool()
}



class backend_memory_request(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._
    val addr            = UInt(32.W)
    val data            = UInt(32.W)
    val mem_signed      = Bool()               // LOAD/STORE
    val memory_type     = memory_type_t()               // LOAD/STORE
    val access_width    = access_width_t()              // B/HW/W

    val MOB_index       = UInt(log2Ceil(MOBEntries).W)
    val packet_index    = UInt(log2Ceil(fetchWidth).W)
    val ROB_index       = UInt(log2Ceil(ROBEntries).W)
    val PRD              = UInt(physicalRegBits.W)
}

class backend_memory_response(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._
    val addr            = UInt(32.W)
    val PRD              = UInt(32.W)
    val fetch_packet_index = UInt(32.W)
    val ROB_index       = UInt(log2Ceil(ROBEntries).W)

    val data            = UInt(32.W)
    //val memory_type     = memory_type_t() // LOAD/STORE
    //val access_width    = access_width_t()              // B/HW/W
    val MOB_index       = UInt(log2Ceil(MOBEntries).W)

    val nack            = Bool()

}


// LDQ //

object memory_type_t extends ChiselEnum{
    val NONE, LOAD, STORE = Value
}

//object access_width_t extends ChiselEnum{
    //val NONE, B, HW, W = Value
//}

object access_width_t extends ChiselEnum{   // in LOG2
    val B, HW, W, DW, NONE = Value
}

class memory_access(coreParameters:CoreParameters) extends Bundle{   // output of the AGU
    import coreParameters._
    val memory_type     = memory_type_t()   // LOAD/STORE
    val PRD             = UInt(physicalRegBits.W)
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


/*loads mark as complete when they are 100% correct and non-speculative.*/
/*That is, loads can mark the PRD ready to avoid stalling the pipeline*/
/*But have the possibility of causing an exception that prevents them from committing*/
/*Loads are not freed until they actually commit.*/


object MOB_STATES extends ChiselEnum {
    val INVALID,       
    VALID,              // 1    (entry valid)
    COMMITTED,          
    RESOLVED,           
    READY,              
    REQUESTED,          // 3    (Request sent)
    NACKED,             // 4    (Requested but denied)
    DONE = Value        // 6    (Response received)
}

class MOB_entry(coreParameters:CoreParameters) extends Bundle{
    import coreParameters._

    val valid                   = Bool()
    val memory_type             = memory_type_t()

    val ROB_index               = UInt(log2Ceil(ROBEntries).W)
    val fetch_packet_index      = UInt(log2Ceil(fetchWidth).W)  // fetch packet index of the branch

    val address                 = UInt(32.W)        // LOAD/STORE address
    val mem_signed              = Bool()
    val access_width            = access_width_t()  // B/HW/W

    val PRD                     = UInt(physicalRegBits.W) // dest reg
    val data                    = UInt(32.W)              
    val data_valid              = Bool()

    val counter                 = UInt(2.W)

    val fwd_valid               = Vec(4, Bool())
    val fwd_data                = Vec(4, UInt(8.W))

    val committed               = Bool()
    val resolved                = Bool()    // all previous stores resolved?


    // Entry state
    val MOB_STATE               = MOB_STATES()

    def in(s: MOB_STATES.Type): Bool = {
        MOB_STATE === s
    }

}



class MSHR_entry(coreParameters:CoreParameters) extends Bundle{
    // An entire row of the MSHR.
    import coreParameters._


    val address                 =   UInt(32.W)      // address shared across MSHR row
    val miss_requests           =   Vec(L1_MSHRWidth, new backend_memory_request(coreParameters))
    val allocate_way            =   UInt(log2Ceil(L1_DataCacheWays).W)

    val pointer_width           = log2Ceil(L1_MSHRWidth)

    val front_pointer           =   UInt(pointer_width.W)
    val back_pointer            =   UInt(pointer_width.W)


    val valid                   =   Bool()

    def dequeue: Unit = {
        miss_requests(front_pointer) := 0.U.asTypeOf(new backend_memory_request(coreParameters))
        front_pointer := front_pointer + 1.U
    }

    def front: backend_memory_request = {
        miss_requests(front_pointer)
    }

    def full: Bool = {
        // MSHR entry pointers do not wrap around. If full, it does not accept any additional entries. 
        // When the queue begins emptying, it empties all the way and clears the row.
        (front_pointer + 1.U) === L1_MSHRWidth.U
    }

    def last: Bool = {
        // MSHR entry pointers do not wrap around. If full, it does not accept any additional entries. 
        // When the queue begins emptying, it empties all the way and clears the row.
        (front_pointer + 1.U) === back_pointer
    }

    def clear: Unit = {
        front_pointer := 0.U
        back_pointer := 0.U
        address := 0.U
        allocate_way := 0.U
        valid := 0.U
        //miss_request := 0.U // TODO: 
    }
}





/////////
// CSR //
/////////





// AXI_slave_port is the Flipped() of an AXI master port





object PRIVILAGE extends ChiselEnum{
    val USER, SUPERVISOR, RESERVED, MACHINE = Value
}

object EX_CAUSE extends ChiselEnum {
  val INSTRUCTION_ADDRESS_MISALIGNED  = Value(0.U)
  val INSTRUCTION_ACCESS_FAULT        = Value(1.U)
  val ILLEGAL_INSTRUCTION             = Value(2.U)
  val BREAKPOINT                      = Value(3.U)
  val LOAD_ADDRESS_MISALIGNED         = Value(4.U)
  val LOAD_ACCESS_FAULT               = Value(5.U)
  val STORE_AMO_ADDRESS_MISALIGNED    = Value(6.U)
  val STORE_AMO_ACCESS_FAULT          = Value(7.U)
  val ECALL_FROM_U_MODE               = Value(8.U)
  val ECALL_FROM_S_MODE               = Value(9.U)
  val RESERVED_10                     = Value(10.U)
  val ECALL_FROM_M_MODE               = Value(11.U)
  val INSTRUCTION_PAGE_FAULT          = Value(12.U)
  val LOAD_PAGE_FAULT                 = Value(13.U)
  val RESERVED_14                     = Value(14.U)
  val STORE_AMO_PAGE_FAULT            = Value(15.U)
  val RESERVED_16_17                  = Value(16.U)
  val COUNTER_OVERFLOW_INTERRUPT      = Value(18.U)
  val HARDWARE_ERROR                  = Value(19.U)
  //val RESERVED_20_23                  = Value(20)
  //val RESERVED_24_31                  = Value(24)
  //val RESERVED_32_47                  = Value(32)
  //val RESERVED_48_63                  = Value(48)
  //val PLATFORM_USE                    = Value(64)
}





object ACCESS extends ChiselEnum{
    val RW, RO = Value
}


class CSR_out(coreParameters:CoreParameters) extends Bundle{
    // globally viewable CSR

    val mtvec = new mtvec()

    val interrupt = Bool()  // edge triggered interrupt detected

}



