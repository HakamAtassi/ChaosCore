/* ------------------------------------------------------------------------------------
* Filename: ROB.scala
* Author: Hakam Atassi
* Date: May 23 2024
* Description: 
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


// The PC segment of the ROB
// Is accessed during the register read phase
//class PC_file(parameters:Parameters) extends Module{}

class ROB(parameters:Parameters) extends Module{
    import parameters._
    val portCount = getPortCount(parameters)

    val io = IO(new Bundle{
        // ALLOCATE //
        val ROB_packet      =   Flipped(Decoupled(new decoded_fetch_packet(parameters)))

        // UPDATE //
        val FU_outputs      =   Vec(portCount, Flipped(ValidIO(new FU_output(parameters))))

        // COMMIT //
        val ROB_output      =   ValidIO(new ROB_output(parameters))
        //Output(Vec(fetchWidth, new ROB_entry(parameters)))

        // REDIRECTS // 
        val commit          =   Input(new commit(parameters))
        // Commits are at the granularity of fetch packets

        // PC FILE //
        // Read port (Exec)
        val PC_file_exec_addr           =   Input(UInt(log2Ceil(ROBEntires).W))
        val PC_file_exec_data           =   Output(UInt(log2Ceil(ROBEntires).W))

    })


    // ROB is generally a 2 write 1 read memory.
    // 1 write from ROB_packet
    // 1 write from FUs
    // 1 read to ROB

    // ROB_packet port writes metadata, instruction type, PC, etc...
    // FUs simply mark as valid. 

    //////////////////////////
    // CONSTRUCT ROB PACKET //
    //////////////////////////

    val ROB_packet      =   Wire(Vec(fetchWidth, new ROB_entry(parameters)))

    for(i <- 0 until fetchWidth){
        ROB_packet(i).valid         := io.ROB_packet.bits.valid_bits(i)
        ROB_packet(i).is_branch     := io.ROB_packet.bits.decoded_instruction(i).needs_branch_unit
    }


    ////////////////////////////
    // INSTANTIATE ROB BANKS  //
    ////////////////////////////

    val ROB_entry_banks: Seq[ROB_mem[ROB_entry]] = Seq.tabulate(portCount) { w =>
        Module(new ROB_mem(new ROB_entry(parameters), depth=ROBEntires))
    }

    ////////////////////////////
    // INSTANTIATE BUSY BANKS //
    ////////////////////////////

    // Busy bit banks are kept seperate 
    // Since the FUs should write to the ENTIRE ROB_entry.
    // Keeping busy bits seperate is easier than using some sort of mask...

    val ROB_busy_banks: Seq[ROB_mem[Bool]] = Seq.tabulate(portCount) { w =>
        Module(new ROB_mem(Bool()/*UInt(8.W)*/, depth=ROBEntires))
    }

    ////////////////////////////
    // INSTANTIATE VALID BANK //
    ////////////////////////////

    // Busy bit banks are kept seperate 
    // Since the FUs should write to the ENTIRE ROB_entry.
    // Keeping busy bits seperate is easier than using some sort of mask...

    val ROB_valid_bank = Module(new ROB_mem(Bool()/*UInt(8.W)*/, depth=ROBEntires))


    val incoming_write = io.ROB_packet.valid && io.ROB_packet.ready
    

    //////////////
    // POINTERS //
    //////////////

    val pointer_width   =   log2Ceil(ROBEntires) + 1
    val front_pointer   =   RegInit(UInt(pointer_width.W), 0.U)
    val back_pointer    =   RegInit(UInt(pointer_width.W), 0.U)

    val front_index     =   Wire(UInt(log2Ceil(ROBEntires).W))
    val back_index      =   back_pointer(pointer_width-2, 0)


    ///////////////////////////
    // WRITE FROM ROB_packet //
    ///////////////////////////

    for(bank <- 0 until fetchWidth){ // write new ROB_packet data
        ROB_entry_banks(bank).io.addrA         := back_index
        ROB_entry_banks(bank).io.writeDataA    := ROB_packet(bank)
        ROB_entry_banks(bank).io.writeEnableA  := io.ROB_packet.valid

        ROB_busy_banks(bank).io.addrA         := back_index
        ROB_busy_banks(bank).io.writeDataA    := 0.B
        ROB_busy_banks(bank).io.writeEnableA  := ROB_packet(bank).valid
    }
    
    ROB_valid_bank.io.addrA         := back_index
    ROB_valid_bank.io.writeEnableA  := incoming_write
    ROB_valid_bank.io.writeDataA    := 1.B

    back_pointer := back_pointer + ROB_packet.map(_.valid).reduce(_ || _)

    ////////////////////
    // WRITE FROM FUs //
    ////////////////////

    // Each input needs to be matched with its corresponding bank to set busy bit.
    // This is because instructions from any ROB bank can be scheduled to any FU port (ex ALU scheduling entirely depends on availability.)


    
    for(bank <- 0 until portCount){
        ROB_busy_banks(bank).io.addrB         := 0.B
        ROB_busy_banks(bank).io.writeDataB    := 0.B
        ROB_busy_banks(bank).io.writeEnableB  := 0.B

        for(FU <- 0 until portCount){
            // port B for FU access
            when(bank.U === (io.FU_outputs(FU).bits.fetch_packet_index) && io.FU_outputs(FU).valid){
                ROB_busy_banks(bank).io.addrB         := io.FU_outputs(FU).bits.ROB_index
                ROB_busy_banks(bank).io.writeDataB    := 1.B
                ROB_busy_banks(bank).io.writeEnableB  := 1.B
            }
        }
    }

    /////////
    // ROB //
    /////////

    for (bank <- 0 until portCount){ // Assign ROB read port
        ROB_busy_banks(bank).io.addrC          := front_index
        ROB_entry_banks(bank).io.addrC         := front_index
    }
    ROB_valid_bank.io.addrC         := front_index

    // Assign valid bits

    val commit_valid_vec        = Wire(Vec(fetchWidth, Bool()))
    
    for(i <- 0 until fetchWidth){  // commit when all entries are complete or invalid
        commit_valid_vec(i) := (!ROB_entry_banks(i).io.readDataC.valid) || (ROB_busy_banks(i).io.readDataC && ROB_entry_banks(i).io.readDataC.valid)
    }

    val commit_valid = Wire(Bool())
    commit_valid := commit_valid_vec.asUInt.andR && ROB_valid_bank.io.readDataC.asBool

    // invalidate commited entires
    for(bank <- 0 until fetchWidth){            // clear commited entry
        ROB_entry_banks(bank).io.addrB         := back_index
        ROB_entry_banks(bank).io.writeDataB    := 0.U.asTypeOf(new ROB_entry(parameters))
        ROB_entry_banks(bank).io.writeEnableB  := commit_valid
    }


    //////////////////////////////////
    // Pointer moving and ROB logic //
    //////////////////////////////////

    when(commit_valid){  // all ROB entries are invalid. increment pointer
        front_pointer := front_pointer + 1.U    // increment actual reg
        front_index := front_pointer + 1.U      // bypass value
    }.otherwise{
        front_index := front_pointer(log2Ceil(ROBEntires)-1,0)
    }

    // clear row on commit
    ROB_valid_bank.io.addrB         := front_index
    ROB_valid_bank.io.writeDataB    := 0.B
    ROB_valid_bank.io.writeEnableB  := commit_valid

    for(bank <- 0 until fetchWidth){
        io.ROB_output.bits.ROB_entries(bank) := ROB_entry_banks(bank).io.readDataC
    }

    io.ROB_output.valid := ROB_entry_banks.map(_.io.readDataC.valid).reduce(_ || _) && commit_valid

    /////////////
    // PC_FILE //
    /////////////

    val PC_file = Module(new PC_file_mem(UInt(32.W), depth=ROBEntires))

    // FIXME: this can be simplified 

    // allocate
    PC_file.io.addrA        := back_pointer
    PC_file.io.writeDataA   := io.ROB_packet.bits.fetch_PC
    PC_file.io.writeEnableA := incoming_write

    // deallocate
    PC_file.io.addrB        := front_index
    PC_file.io.writeDataB   := 0.B
    PC_file.io.writeEnableB := commit_valid

    // Read (Exec)
    PC_file.io.addrC        :=  io.PC_file_exec_addr
    io.PC_file_exec_data    :=  PC_file.io.readDataC

    // Read (Commit)
    PC_file.io.addrD        :=  front_index
    io.ROB_output.bits.fetch_PC := PC_file.io.readDataD
        

    // TODO: 
    io.ROB_output.bits.RAT_IDX := DontCare
    

    /////////////////
    // VALID/READY //
    /////////////////


    val full = (front_index === back_index) && (front_pointer =/= back_pointer)
    io.ROB_packet.ready := !full


}

