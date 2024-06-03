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


class ROB_mem[T <: Data](dataType: T, depth: Int) extends Module {
  val io = IO(new Bundle {
    // Port A
    val addrA = Input(UInt(log2Ceil(depth).W))
    val writeDataA = Input(dataType)
    val writeEnableA = Input(Bool())
    val readDataA = Output(dataType)

    // Port B
    val addrB = Input(UInt(log2Ceil(depth).W))
    val writeDataB = Input(dataType)
    val writeEnableB = Input(Bool())
    val readDataB = Output(dataType)

    // Port C   (read only)
    val addrC = Input(UInt(log2Ceil(depth).W))
    val readDataC = Output(dataType)
  })

  // Create the true dual-port memory
  val mem = SyncReadMem(depth, dataType)

  // Operations for Port A
  when(io.writeEnableA) {
    mem.write(io.addrA, io.writeDataA)
  }
  io.readDataA := mem.read(io.addrA, 1.B)

  // Operations for Port B
  when(io.writeEnableB) {
    mem.write(io.addrB, io.writeDataB)
  }
  io.readDataB := mem.read(io.addrB, 1.B)

  io.readDataC := mem.read(io.addrC, 1.B)

}

// The PC segment of the ROB
// Is accessed during the register read phase
//class PC_file(parameters:Parameters) extends Module{}

class ROB(parameters:Parameters) extends Module{
    import parameters._
    val portCount = getPortCount(parameters)

    val io = IO(new Bundle{
        // ALLOCATE //
        val ROB_packet      =   Vec(dispatchWidth, Flipped(Decoupled(new ROB_entry(parameters))))

        // UPDATE //
        val FU_outputs      =   Vec(portCount, Flipped(ValidIO(new FU_output(parameters))))

        // COMMIT //
        val ROB             =   Output(Vec(commitWidth, new ROB_entry(parameters)))

        // REDIRECTS // 
        val commit          =   Input(Vec(commitWidth, new commit(parameters)))
    })


    // ROB is generally a 2 write 1 read memory.
    // 1 write from ROB_packet
    // 1 write from FUs
    // 1 read to ROB

    // ROB_packet port writes metadata, instruction type, PC, etc...
    // FUs simply mark as valid. 

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

    val ROB_busy_banks: Seq[ROB_mem[UInt]] = Seq.tabulate(portCount) { w =>
        Module(new ROB_mem(UInt(8.W), depth=ROBEntires))
    }


    //////////////
    // POINTERS //
    //////////////

    val pointer_width   =   log2Ceil(ROBEntires) + 1
    val front_pointer   =   RegInit(UInt(pointer_width.W), 0.U)
    val back_pointer    =   RegInit(UInt(pointer_width.W), 0.U)

    val front_index     =   Wire(UInt(log2Ceil(ROBEntires).W))
    //front_pointer(pointer_width-2, 0)
    val back_index      =   back_pointer(pointer_width-2, 0)


    /////////////////////////
    // WRITE FROM ROB_packet //
    /////////////////////////

    for(bank <- 0 until dispatchWidth){ // write new ROB_packet data
        ROB_entry_banks(bank).io.addrA         := back_index
        ROB_entry_banks(bank).io.writeDataA    := io.ROB_packet(bank).bits
        ROB_entry_banks(bank).io.writeEnableA  := io.ROB_packet(bank).bits.valid

        ROB_busy_banks(bank).io.addrA         := back_index
        ROB_busy_banks(bank).io.writeDataA    := 0.B
        ROB_busy_banks(bank).io.writeEnableA  := io.ROB_packet(bank).valid
    }
    
    // FIXME: back pointer doesnt move
    //back_pointer := back_pointer + io.ROB_packet.map.valid

    ////////////////////
    // WRITE FROM FUs //
    ////////////////////

    // Each input needs to be matched with its corresponding bank to set busy bit.
    // This is because instructions from any ROB bank can be scheduled to any FU port (ex ALU scheduling entirely depends on availability.)

    val live_busy_bit = Wire(Vec(commitWidth, Bool()))  // combinational version of the top of ROB busy bits

    
    for(bank <- 0 until portCount){
        ROB_busy_banks(bank).io.addrB         := 0.B
        ROB_busy_banks(bank).io.writeDataB    := 0.B
        ROB_busy_banks(bank).io.writeEnableB  := 0.B

            live_busy_bit(bank) :=  ROB_busy_banks(bank).io.readDataC(0).asBool

        for(FU <- 0 until portCount){
            // port B for FU access
            when(bank.U === (io.FU_outputs(FU).bits.fetch_packet_index) && io.FU_outputs(FU).valid){
                ROB_busy_banks(bank).io.addrB         := io.FU_outputs(FU).bits.ROB_index
                ROB_busy_banks(bank).io.writeDataB    := 1.B
                ROB_busy_banks(bank).io.writeEnableB  := 1.B
            }
            when(((bank.U === io.FU_outputs(FU).bits.fetch_packet_index) && (io.FU_outputs(FU).bits.ROB_index === front_pointer(log2Ceil(ROBEntires)-1,0)) && (io.FU_outputs(FU).valid))){
                live_busy_bit(bank) :=  1.B
            }
        }
    }

    ////////////////
    // ROB //
    ////////////////


    // The core can ROB up to commitWidth instructions per cycle.
    // Commitable instructions are marked valid on the output. 
    // Instructions ROB from left to right and N at a time. 
    // When 1 or more instructions are valid and done, that data is sent to the output as a commited instruction.
    // They are also then invalidated from the ROB.
    // front_pointer only increments when an entire row has been commited. 

    for (bank <- 0 until portCount){ // Assign ROB read port
        ROB_busy_banks(bank).io.addrC          := front_index
        ROB_entry_banks(bank).io.addrC         := front_index

    }

    // Assign valid bits

    val commit_valid = Wire(Vec(commitWidth, Bool()))


    
    //commit_valid(0) := ROB_busy_banks(0).io.readDataC.asBool && ROB_entry_banks(0).io.readDataC.valid   &&  1.B
    commit_valid(0) := live_busy_bit(0) && ROB_entry_banks(0).io.readDataC.valid   &&  1.B
    for(i <- 1 until commitWidth){
        commit_valid(i) := live_busy_bit(i) && ROB_entry_banks(i).io.readDataC.valid && (commit_valid(i-1) || !ROB_entry_banks(i-1).io.readDataC.valid)
    }


    // invalidate commited entires
    for(bank <- 0 until commitWidth){            // clear commited entry
        ROB_entry_banks(bank).io.addrB         := back_index
        ROB_entry_banks(bank).io.writeDataB    := 0.U.asTypeOf(new ROB_entry(parameters))
        ROB_entry_banks(bank).io.writeEnableB  := commit_valid(bank)
    }

    /////////////////////////////////////
    // Pointer moving and ROB logic //
    /////////////////////////////////////


    // Commits clear the valid bit corresponding to that ROB entry. 
    // However, "live commits", or commits that update the element that is already at the front of the ROB, 
    // should cause the ROB pointer to increment the next cycle. This requires extra logic since
    // normally, the updating would take 1 cycle to clear valid bits and another to update the pointer.
    // To get around this, the pointer is incremented when either all bits at the ROB top are invalid (and a ROB took place last cycle), or 
    // when all valid bits are currently being set to busy (active low (but have not yet updated))

    val comb_commit = Wire(Bool())

    // Create a vector of conditions
    val conditions = VecInit((0 until portCount).map { i =>
        !ROB_entry_banks(i).io.readDataC.valid || live_busy_bit(i)
    })

    // Combine the conditions using fold and logical AND
    comb_commit := conditions.reduce(_ && _) && io.FU_outputs.map(_.valid).reduce(_ || _)


    val increment_front_pointer =  !ROB_entry_banks.map(_.io.readDataC.valid).reduce(_ || _) && RegNext(commit_valid.reduce(_ || _)) || comb_commit

    when(increment_front_pointer){  // all ROB entries are invalid. increment pointer
        front_pointer := front_pointer + 1.U    // increment actual reg
        front_index := front_pointer + 1.U        // bypass value
    }.otherwise{
        front_index := front_pointer(log2Ceil(ROBEntires)-1,0)
    }

    for(bank <- 0 until commitWidth){
        io.ROB(bank) := ROB_entry_banks(bank).io.readDataC
        io.ROB(bank).valid := ROB_entry_banks(bank).io.readDataC.valid && commit_valid(bank)
    }


    /////////////////
    // VALID/READY //
    /////////////////


    //val full = (front_index === back_index) && (front_pointer =/= back_pointer)
    for(i <- 0 until dispatchWidth){
        io.ROB_packet(i).ready := DontCare
    }


}

