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
        // FLUSH //
        val flush           =   Input(Bool())

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

        val ROB_index       =   Output(UInt(log2Ceil(ROBEntires).W))

        // PC FILE //
        // Read port (Exec)
        val PC_file_exec_addr           =   Input(UInt(log2Ceil(ROBEntires).W))
        val PC_file_exec_data           =   Output(UInt(32.W))
    })

    //////////////////
    // REQUIREMENTS //
    //////////////////
    require(isPow2(ROBEntires), "ROB entries not a power of 2")

    //////////////
    // POINTERS // 
    //////////////

    val pointer_width = log2Ceil(ROBEntires)+1

    val front_pointer = RegInit(UInt(pointer_width.W), 0.U)
    val back_pointer  = RegInit(UInt(pointer_width.W), 0.U)

    val front_index = Wire(UInt((pointer_width-1).W))
    val back_index  = Wire(UInt((pointer_width-1).W))


    io.ROB_index := back_index


    back_index  := back_pointer(pointer_width-2, 0)
    
    //////////////////////////////////
    // BACK POINTER CTRL / ALLOCATE //
    //////////////////////////////////
    
    val allocate = Wire(Bool())

    allocate := io.ROB_packet.valid && io.ROB_packet.ready

    when(io.flush){
        back_pointer := 0.U
    }.otherwise{
        back_pointer := back_pointer + allocate
    }


    //////////////
    // MEMORIES //
    //////////////

    //|-------------------------|//
    //| SHARED MEM              |//
    //| 2R/1W                   |//
    //| Write on allocate       |//
    //| Read to FUs (for PC)    |//
    //| Read to commit          |//
    //|-------------------------|//

    val shared_mem = Module(new ROB_shared_mem(parameters, depth=ROBEntires))

    val shared_mem_input = Wire(new ROB_shared(parameters))

    shared_mem_input.row_valid  := io.ROB_packet.valid
    shared_mem_input.fetch_PC   := io.ROB_packet.bits.fetch_PC
    shared_mem_input.RAT_IDX    := io.ROB_packet.bits.RAT_IDX
    
    // Port A / allocate
    shared_mem.io.addrA         := back_index
    shared_mem.io.writeDataA    := shared_mem_input
    shared_mem.io.writeEnableA  := allocate

    // Port B / commit
    shared_mem.io.addrB         := front_index
    io.ROB_output.bits.fetch_PC := shared_mem.io.readDataB.fetch_PC
    io.ROB_output.bits.RAT_IDX  := shared_mem.io.readDataB.RAT_IDX

    // Port C / FUs
    shared_mem.io.addrC         := io.PC_file_exec_addr
    io.PC_file_exec_data        := shared_mem.io.readDataC.fetch_PC


    //|------------------------------|//
    //| BUSY MEM                     |//
    //| 1R/(N+1)W                    |//
    //| Write on allocate            |//
    //| Write on complete            |//
    //| Read to commit               |//
    //|------------------------------|//

    val ROB_WB_banks: Seq[ROB_WB_mem] = Seq.tabulate(fetchWidth) { w =>
        Module(new ROB_WB_mem(parameters, depth=ROBEntires))
    }

    for(i <- 0 until fetchWidth){
        val ROB_WB_data = Wire(new ROB_WB(parameters))
        ROB_WB_data.busy := 0.B
        ROB_WB_data.exception := 0.B

        // allocate
        ROB_WB_banks(i).io.addrA          := back_index
        ROB_WB_banks(i).io.writeDataA     := ROB_WB_data
        ROB_WB_banks(i).io.writeEnableA   := allocate

        // WB (connect all ports)

        // FU0
        val ROB_WB_data_FU0 = Wire(new ROB_WB(parameters))
        ROB_WB_data_FU0.busy             :=  io.FU_outputs(0).valid
        ROB_WB_data_FU0.exception        :=  0.B
        ROB_WB_banks(i).io.addrB         :=  io.FU_outputs(0).bits.ROB_index
        ROB_WB_banks(i).io.writeDataB    :=  ROB_WB_data_FU0
        ROB_WB_banks(i).io.writeEnableB  :=  io.FU_outputs(0).valid && (io.FU_outputs(0).bits.fetch_packet_index === i.U)

        // FU1
        val ROB_WB_data_FU1 = Wire(new ROB_WB(parameters))
        ROB_WB_data_FU1.busy             :=  io.FU_outputs(1).valid
        ROB_WB_data_FU1.exception        :=  0.B
        ROB_WB_banks(i).io.addrC         :=  io.FU_outputs(1).bits.ROB_index
        ROB_WB_banks(i).io.writeDataC    :=  ROB_WB_data_FU1
        ROB_WB_banks(i).io.writeEnableC  :=  io.FU_outputs(1).valid && (io.FU_outputs(1).bits.fetch_packet_index === i.U)

        // FU2
        val ROB_WB_data_FU2 = Wire(new ROB_WB(parameters))
        ROB_WB_data_FU2.busy             :=  io.FU_outputs(2).valid
        ROB_WB_data_FU2.exception        :=  0.B
        ROB_WB_banks(i).io.addrD         :=  io.FU_outputs(2).bits.ROB_index
        ROB_WB_banks(i).io.writeDataD    :=  ROB_WB_data_FU2
        ROB_WB_banks(i).io.writeEnableD  :=  io.FU_outputs(2).valid && (io.FU_outputs(2).bits.fetch_packet_index === i.U)

        // FU3
        val ROB_WB_data_FU3 = Wire(new ROB_WB(parameters))
        ROB_WB_data_FU3.busy             :=  io.FU_outputs(3).valid
        ROB_WB_data_FU3.exception        :=  0.B
        ROB_WB_banks(i).io.addrE         :=  io.FU_outputs(3).bits.ROB_index
        ROB_WB_banks(i).io.writeDataE    :=  ROB_WB_data_FU3
        ROB_WB_banks(i).io.writeEnableE  :=  io.FU_outputs(3).valid && (io.FU_outputs(3).bits.fetch_packet_index === i.U)

        // commit (connect all ports)

        ROB_WB_banks(i).io.addrG       := front_index

    }


    
    //ROB_WB_banks.map(_.io.readDataG.busy).reduce(_ && _) && shared_mem.io.readDataB.row_valid


    //|----------------------------|//
    //| INSTR MEM                  |//
    //| 1R/1W                      |//
    //| Write on allocate          |//
    //| Read to commit             |//
    //|----------------------------|//


    val ROB_entry_banks: Seq[ROB_entry_mem] = Seq.tabulate(fetchWidth) { w =>
        Module(new ROB_entry_mem(parameters=parameters, depth=ROBEntires))
    }


    for(i <- 0 until fetchWidth){
        val ROB_entry_data = Wire(new ROB_entry(parameters))
        ROB_entry_data.valid                 := io.ROB_packet.bits.valid_bits(i)
        ROB_entry_data.is_branch             := io.ROB_packet.bits.decoded_instruction(i).needs_branch_unit
        ROB_entry_data.is_load               := io.ROB_packet.bits.decoded_instruction(i).IS_LOAD
        ROB_entry_data.is_store              := io.ROB_packet.bits.decoded_instruction(i).IS_STORE

        // allocate
        ROB_entry_banks(i).io.addrA          := back_index
        ROB_entry_banks(i).io.writeDataA     := ROB_entry_data
        ROB_entry_banks(i).io.writeEnableA   := allocate

        // commit
        ROB_entry_banks(i).io.addrB          := front_index
        io.ROB_output.bits.ROB_entries(i)    := ROB_entry_banks(i).io.readDataB
    }


    /////////////////////////////////
    // FRONT POINTER CTRL / COMMIT //
    /////////////////////////////////

    val commit = Wire(Bool())

    val commit_row_valid    = Wire(Bool())  // the row is valid
    
    val commit_row_complete = Wire(Vec(fetchWidth, Bool()))  // all valid instructions in that row are complete


    commit_row_valid := shared_mem.io.readDataB.row_valid

    for(i <- 0 until fetchWidth){   // FIXME: the commit condition here is very important and is currently a hack...
        val is_completed    = (ROB_WB_banks(i).io.readDataG.busy && ROB_entry_banks(i).io.readDataB.valid)
        val is_invalid      = (!ROB_entry_banks(i).io.readDataB.valid)
        val is_load         = ROB_entry_banks(i).io.readDataB.is_load
        val is_store        = ROB_entry_banks(i).io.readDataB.is_store
        commit_row_complete(i) := is_completed || is_invalid || is_load || is_store
    }


    commit := commit_row_valid && commit_row_complete.reduce(_ && _)



    front_pointer := front_pointer + commit

    io.ROB_output.valid := commit
    io.ROB_output.bits.ROB_index := RegNext(front_index)    // you want the unbypassed version of this pointer

    when(io.flush){
        front_pointer := 0.U
        front_index   := 0.U
    }.elsewhen(commit){   // bypass
        val bypassed_pointer = (front_pointer + 1.U)
        front_index := bypassed_pointer(pointer_width-2, 0)
        front_pointer := front_pointer + 1.U
    }.otherwise{
        front_index := front_pointer(pointer_width-2, 0)
    }

    ///////////
    // READY //
    ///////////

    val full = (front_pointer(pointer_width-2, 0) === back_pointer(pointer_width-2, 0)) && (front_pointer =/= back_pointer)


    io.ROB_packet.ready := !full


    ///////////
    // DEBUG //
    ///////////

    val shared_memory_update_notif = RegNext(io.ROB_packet.valid)
    dontTouch(shared_memory_update_notif)



}
// FIXME: ROB commit doesnt really work
// Front and back pointers are reset, but what if the first element is valid? 

