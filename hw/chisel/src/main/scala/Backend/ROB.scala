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
//class PC_file(coreParameters:CoreParameters) extends Module{}

class ROB(coreParameters:CoreParameters) extends Module{
    import coreParameters._
    val portCount = getPortCount(coreParameters)

    val io = IO(new Bundle{
        // FLUSH //
        val flush                       =   Input(Bool())

        // ALLOCATE //
        val ROB_packet                  =   Flipped(Decoupled(new decoded_fetch_packet(coreParameters)))

        // UPDATE //
        val FU_outputs                  =   Vec(portCount, Flipped(ValidIO(new FU_output(coreParameters))))

        // COMMIT //
        val ROB_output                  =   Output(new ROB_output(coreParameters))

        // REDIRECTS // 
        val commit                      =   Flipped(ValidIO(new commit(coreParameters)))
        
        val ROB_index                   =   Output(UInt(log2Ceil(ROBEntries).W))

        // PC FILE //
        // Read port (Exec)
        val PC_file_exec_addr           =   Input(UInt(log2Ceil(ROBEntries).W))
        val PC_file_exec_data           =   Output(UInt(32.W))
    }); dontTouch(io)

    //////////////
    // POINTERS // 
    //////////////

    val pointer_width = log2Ceil(ROBEntries)+1

    val front_pointer = RegInit(UInt(pointer_width.W), 0.U)
    val back_pointer  = RegInit(UInt(pointer_width.W), 0.U)

    val front_index = Wire(UInt((pointer_width-1).W))
    val back_index  = Wire(UInt((pointer_width-1).W))

    io.ROB_index := back_index
    
    //////////////////////////////////
    // BACK POINTER CTRL / ALLOCATE //
    //////////////////////////////////
    
    val allocate = Wire(Bool())

    allocate := io.ROB_packet.valid && io.ROB_packet.ready


    //////////////
    // MEMORIES //
    //////////////

    //|-----------------------|//
    //| Row valid             |//
    //| Regs                  |//
    //| Write on allocate     |//
    //| Write on commit       |//
    //| Read to commit        |//
    //|-----------------------|//

    val row_valid_mem   =   RegInit(VecInit(Seq.fill(ROBEntries)(0.B)))
    val row_valid       =   row_valid_mem(front_pointer(pointer_width-2, 0))

    when(io.ROB_packet.valid){  // Allocate
        row_valid_mem(back_pointer(pointer_width-2, 0)) := 1.B
    }

    when(io.commit.valid){  // Commit
        row_valid_mem(front_pointer(pointer_width-2, 0)) := 0.B
    }

    when(io.flush){
        row_valid_mem := Seq.fill(ROBEntries)(0.B)
    }

    //|-------------------------|//
    //| SHARED MEM              |//
    //| 2R/1W                   |//
    //| Write on allocate       |//
    //| Read to FUs (for PC)    |//
    //| Read to commit          |//
    //|-------------------------|//

    val shared_mem      = Module(new ROB_shared_mem(coreParameters, depth=ROBEntries))
    val shared_mem_input = Wire(new ROB_shared(coreParameters))

    shared_mem_input.fetch_PC                   := io.ROB_packet.bits.fetch_PC
    shared_mem_input.GHR                        := io.ROB_packet.bits.GHR
    shared_mem_input.TOS                        := io.ROB_packet.bits.TOS
    shared_mem_input.NEXT                       := io.ROB_packet.bits.NEXT
    shared_mem_input.RAT_index                  := io.ROB_packet.bits.RAT_index
    shared_mem_input.free_list_front_pointer    := io.ROB_packet.bits.free_list_front_pointer
    
    // Port A / allocate
    shared_mem.io.addrA         := back_index
    shared_mem.io.writeDataA    := shared_mem_input
    shared_mem.io.writeEnableA  := allocate

    // Port B / commit
    shared_mem.io.addrB         := front_index

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
        Module(new ROB_WB_mem(coreParameters, depth=ROBEntries))
    }

    for(i <- 0 until fetchWidth){
        val ROB_WB_data = Wire(new ROB_WB(coreParameters))
        ROB_WB_data.busy := 0.B
        ROB_WB_data.exception := 0.B

        // allocate
        ROB_WB_banks(i).io.addrA          := back_index
        ROB_WB_banks(i).io.writeDataA     := ROB_WB_data
        ROB_WB_banks(i).io.writeEnableA   := allocate

        // WB (connect all ports)

        // FU0
        val ROB_WB_data_FU0 = Wire(new ROB_WB(coreParameters))
        ROB_WB_data_FU0.busy             :=  io.FU_outputs(0).valid
        ROB_WB_data_FU0.exception        :=  0.B
        ROB_WB_banks(i).io.addrB         :=  io.FU_outputs(0).bits.ROB_index
        ROB_WB_banks(i).io.writeDataB    :=  ROB_WB_data_FU0
        ROB_WB_banks(i).io.writeEnableB  :=  io.FU_outputs(0).valid && (io.FU_outputs(0).bits.fetch_packet_index === i.U)

        // FU1
        val ROB_WB_data_FU1 = Wire(new ROB_WB(coreParameters))
        ROB_WB_data_FU1.busy             :=  io.FU_outputs(1).valid
        ROB_WB_data_FU1.exception        :=  0.B
        ROB_WB_banks(i).io.addrC         :=  io.FU_outputs(1).bits.ROB_index
        ROB_WB_banks(i).io.writeDataC    :=  ROB_WB_data_FU1
        ROB_WB_banks(i).io.writeEnableC  :=  io.FU_outputs(1).valid && (io.FU_outputs(1).bits.fetch_packet_index === i.U)

        // FU2
        val ROB_WB_data_FU2 = Wire(new ROB_WB(coreParameters))
        ROB_WB_data_FU2.busy             :=  io.FU_outputs(2).valid
        ROB_WB_data_FU2.exception        :=  0.B
        ROB_WB_banks(i).io.addrD         :=  io.FU_outputs(2).bits.ROB_index
        ROB_WB_banks(i).io.writeDataD    :=  ROB_WB_data_FU2
        ROB_WB_banks(i).io.writeEnableD  :=  io.FU_outputs(2).valid && (io.FU_outputs(2).bits.fetch_packet_index === i.U)

        // FU3
        val ROB_WB_data_FU3 = Wire(new ROB_WB(coreParameters))
        ROB_WB_data_FU3.busy             :=  io.FU_outputs(3).valid
        ROB_WB_data_FU3.exception        :=  0.B
        ROB_WB_banks(i).io.addrE         :=  io.FU_outputs(3).bits.ROB_index
        ROB_WB_banks(i).io.writeDataE    :=  ROB_WB_data_FU3
        ROB_WB_banks(i).io.writeEnableE  :=  io.FU_outputs(3).valid && (io.FU_outputs(3).bits.fetch_packet_index === i.U)

        // commit (connect all ports)
        ROB_WB_banks(i).io.addrG         := front_index

    }

    //|----------------------------|//
    //| INSTR MEM                  |//
    //| 1R/1W                      |//
    //| Write on allocate          |//
    //| Read to commit             |//
    //|----------------------------|//

    val ROB_entry_banks: Seq[ROB_entry_mem] = Seq.tabulate(fetchWidth) { w =>
        Module(new ROB_entry_mem(coreParameters=coreParameters, depth=ROBEntries))
    }

    for(i <- 0 until fetchWidth){
        val ROB_entry_data = Wire(new ROB_entry(coreParameters))
        ROB_entry_data.valid                 := io.ROB_packet.bits.valid_bits(i)
        ROB_entry_data.is_branch             := io.ROB_packet.bits.decoded_instruction(i).needs_branch_unit
        ROB_entry_data.memory_type           := io.ROB_packet.bits.decoded_instruction(i).memory_type
        ROB_entry_data.RD                    := io.ROB_packet.bits.decoded_instruction(i).RD
        ROB_entry_data.RDold                 := io.ROB_packet.bits.decoded_instruction(i).RDold
        ROB_entry_data.RD_valid              := io.ROB_packet.bits.decoded_instruction(i).RD_valid

        // allocate
        ROB_entry_banks(i).io.addrA          := back_index
        ROB_entry_banks(i).io.writeDataA     := ROB_entry_data
        ROB_entry_banks(i).io.writeEnableA   := allocate

        // commit
        ROB_entry_banks(i).io.addrB          := front_index
    }

    /////////////////////////////////
    // FRONT POINTER CTRL / COMMIT //
    /////////////////////////////////
    front_pointer := front_pointer + io.commit.valid


    when(io.flush){
        front_pointer := 0.U
        front_index   := 0.U
    }.elsewhen(io.commit.valid){   // bypass
        val bypassed_pointer = (front_pointer + 1.U)
        front_index := bypassed_pointer(pointer_width-2, 0)
        front_pointer := front_pointer + 1.U
    }.otherwise{
        front_index := front_pointer(pointer_width-2, 0)
    }

    when(io.flush){
        back_pointer := 0.U
        back_index  := 0.U
    }.otherwise{
        back_pointer := back_pointer + allocate
        back_index   := back_pointer(pointer_width-2, 0)
    }

    ///////////////////////
    // ASSIGN ROB OUTPUT //
    ///////////////////////

    io.ROB_output.row_valid                := row_valid
    io.ROB_output.ROB_index                := RegNext(front_index)    // you want the unbypassed version of this pointer

    io.ROB_output.fetch_PC                 := shared_mem.io.readDataB.fetch_PC
    io.ROB_output.RAT_index                := shared_mem.io.readDataB.RAT_index
    io.ROB_output.GHR                      := shared_mem.io.readDataB.GHR
    io.ROB_output.NEXT                     := shared_mem.io.readDataB.NEXT
    io.ROB_output.TOS                      := shared_mem.io.readDataB.TOS

    io.ROB_output.free_list_front_pointer  := shared_mem.io.readDataB.free_list_front_pointer

    for(i <- 0 until fetchWidth){

        io.ROB_output.exception(i)         := ROB_WB_banks(i).io.readDataG.exception    
        io.ROB_output.complete(i)          := ROB_WB_banks(i).io.readDataG.busy    // Rename busy to complete
        io.ROB_output.ROB_entries(i)       := ROB_entry_banks(i).io.readDataB
    }

    ///////////
    // READY //
    ///////////

    val full = (front_pointer(pointer_width-2, 0) === back_pointer(pointer_width-2, 0)) && (front_pointer =/= back_pointer)

    io.ROB_packet.ready := !full

    ///////////
    // DEBUG //
    ///////////




}

