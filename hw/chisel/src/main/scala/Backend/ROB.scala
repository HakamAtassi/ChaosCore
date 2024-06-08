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



    front_index := front_pointer >> 1
    back_index  := back_pointer >> 1
    
    //////////////////////////////////
    // BACK POINTER CTRL / ALLOCATE //
    //////////////////////////////////
    
    val allocate = Wire(Bool())

    allocate := io.ROB_packet.valid && io.ROB_packet.ready

    front_pointer := front_pointer + allocate


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
    shared_mem.io.addrA         := front_index
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

        val ROB_WB_data_FU0 = Wire(new ROB_WB(parameters))
        ROB_WB_data_FU0.busy            := 0.B
        ROB_WB_data_FU0.exception       := 0.B
        ROB_WB_banks(i).io.addrB         :=  io.FU_outputs(i).bits.ROB_index
        ROB_WB_banks(i).io.writeDataB    :=  ROB_WB_data_FU0
        ROB_WB_banks(i).io.writeEnableB  :=  io.FU_outputs(i).valid

        val ROB_WB_data_FU1 = Wire(new ROB_WB(parameters))
        ROB_WB_data_FU1.busy := 0.B
        ROB_WB_data_FU1.exception := 0.B
        ROB_WB_banks(i).io.addrC         :=  io.FU_outputs(i).bits.ROB_index
        ROB_WB_banks(i).io.writeDataC    :=  ROB_WB_data_FU1
        ROB_WB_banks(i).io.writeEnableC  :=  io.FU_outputs(i).valid

        val ROB_WB_data_FU2 = Wire(new ROB_WB(parameters))
        ROB_WB_data_FU2.busy := 0.B
        ROB_WB_data_FU2.exception := 0.B
        ROB_WB_banks(i).io.addrD         :=  io.FU_outputs(i).bits.ROB_index
        ROB_WB_banks(i).io.writeDataD    :=  ROB_WB_data_FU2
        ROB_WB_banks(i).io.writeEnableD  :=  io.FU_outputs(i).valid

        val ROB_WB_data_FU3 = Wire(new ROB_WB(parameters))
        ROB_WB_data_FU3.busy := 0.B
        ROB_WB_data_FU3.exception := 0.B
        ROB_WB_banks(i).io.addrE         :=  io.FU_outputs(i).bits.ROB_index
        ROB_WB_banks(i).io.writeDataE    :=  ROB_WB_data_FU3
        ROB_WB_banks(i).io.writeEnableE  :=  io.FU_outputs(i).valid


        // commit (connect all ports)

        ROB_WB_banks(i).io.addrG       := front_index

    }
        //io.ROB_output.bits.ROB_entries(i) := ROB_WB_banks(i).readDataG
    io.ROB_output.valid := ROB_WB_banks.map(_.io.readDataG.busy).reduce(_ && _) && shared_mem.io.readDataB.row_valid


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


    val full = (front_index === back_index) && (front_pointer =/= back_pointer)

    io.ROB_packet.ready := !full



}

