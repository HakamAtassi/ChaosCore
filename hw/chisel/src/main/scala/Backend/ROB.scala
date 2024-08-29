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




// FIXME: add partial commit logic
// when you are flushing, just flush + replay.
// Do not allow flushes and commits at the same time

package ChaosCore

import chisel3._
import chisel3.util._

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
        val commit                      =   ValidIO(new commit(coreParameters))
        val partial_commit              =   Output(new partial_commit(coreParameters))
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

    allocate := io.ROB_packet.fire


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

    val row_valid_mem        =   RegInit(VecInit(Seq.fill(ROBEntries)(0.B)))
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
    shared_mem_input.free_list_front_pointer    := io.ROB_packet.bits.free_list_front_pointer
    
    // Port A / allocate
    shared_mem.io.addrA         := back_index
    shared_mem.io.writeDataA    := shared_mem_input
    shared_mem.io.writeEnableA  := allocate

    // Port B / commit
    shared_mem.io.addrB         := front_index + io.commit.valid

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

        dontTouch(ROB_WB_data)

        // commit (clear complete when done with the row)
        ROB_WB_banks(i).io.addrA          := front_index
        ROB_WB_banks(i).io.writeDataA     := ROB_WB_data
        ROB_WB_banks(i).io.writeEnableA   := io.commit.valid
        // WB (connect all ports)

        // FU0
        val ROB_WB_data_FU0 = Wire(new ROB_WB(coreParameters))
        ROB_WB_data_FU0.busy             :=  io.FU_outputs(0).valid
        ROB_WB_banks(i).io.addrB         :=  io.FU_outputs(0).bits.ROB_index
        ROB_WB_banks(i).io.writeDataB    :=  ROB_WB_data_FU0
        ROB_WB_banks(i).io.writeEnableB  :=  io.FU_outputs(0).valid && (io.FU_outputs(0).bits.fetch_packet_index === i.U)

        // FU1
        val ROB_WB_data_FU1 = Wire(new ROB_WB(coreParameters))
        ROB_WB_data_FU1.busy             :=  io.FU_outputs(1).valid
        ROB_WB_banks(i).io.addrC         :=  io.FU_outputs(1).bits.ROB_index
        ROB_WB_banks(i).io.writeDataC    :=  ROB_WB_data_FU1
        ROB_WB_banks(i).io.writeEnableC  :=  io.FU_outputs(1).valid && (io.FU_outputs(1).bits.fetch_packet_index === i.U)

        // FU2
        val ROB_WB_data_FU2 = Wire(new ROB_WB(coreParameters))
        ROB_WB_data_FU2.busy             :=  io.FU_outputs(2).valid
        ROB_WB_banks(i).io.addrD         :=  io.FU_outputs(2).bits.ROB_index
        ROB_WB_banks(i).io.writeDataD    :=  ROB_WB_data_FU2
        ROB_WB_banks(i).io.writeEnableD  :=  io.FU_outputs(2).valid && (io.FU_outputs(2).bits.fetch_packet_index === i.U)

        // FU3
        val ROB_WB_data_FU3 = Wire(new ROB_WB(coreParameters))
        ROB_WB_data_FU3.busy             :=  io.FU_outputs(3).valid
        ROB_WB_banks(i).io.addrE         :=  io.FU_outputs(3).bits.ROB_index
        ROB_WB_banks(i).io.writeDataE    :=  ROB_WB_data_FU3
        ROB_WB_banks(i).io.writeEnableE  :=  io.FU_outputs(3).valid && (io.FU_outputs(3).bits.fetch_packet_index === i.U)

        // commit (connect all ports)
        ROB_WB_banks(i).io.addrG         := front_index + io.commit.valid

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
        ROB_entry_data.MOB_index             := io.ROB_packet.bits.decoded_instruction(i).MOB_index
        ROB_entry_data.RDold                 := io.ROB_packet.bits.decoded_instruction(i).RDold
        ROB_entry_data.RD_valid              := io.ROB_packet.bits.decoded_instruction(i).RD_valid

        // allocate
        ROB_entry_banks(i).io.addrA          := back_index
        ROB_entry_banks(i).io.writeDataA     := ROB_entry_data
        ROB_entry_banks(i).io.writeEnableA   := allocate

        // commit
        ROB_entry_banks(i).io.addrB          := front_index + io.commit.valid
    }


    //|----------------------------|//
    //| FETCH PREDICTION MEM       |//
    //| 1R/1W                      |//
    //| Write on allocate          |//
    //| Read to commit             |//
    //|----------------------------|//

    val fetch_prediction_bank   = SyncReadMem(ROBEntries, new prediction(coreParameters))
    val commit_prediction       = Wire(new prediction(coreParameters))

    // allocate

    when(allocate && io.ROB_packet.valid){
        fetch_prediction_bank.write(back_index, io.ROB_packet.bits.prediction)
    }

    // commit
    commit_prediction := fetch_prediction_bank.read(front_index + io.commit.valid, 1.B)

    //|----------------------------|//
    //| FETCH RESOLVED MEM         |//
    //| 1R/1W                      |//
    //| Write on allocate          |//
    //| Read to commit             |//
    //|----------------------------|//


    // Since this memory is not written to on allocate with a default value, 
    // Keep track of whether these entries are valid
    // if they are not valid and the instruction is committing (all instructions in that packet have completed)
    // then do not worry about a misprediction

    val fetch_resolved_banks: Seq[SyncReadMem[prediction]] = Seq.tabulate(fetchWidth) { w =>
        SyncReadMem(ROBEntries, new prediction(coreParameters))
    }
    
    
    val commit_resolved = Wire(Vec(fetchWidth, new prediction(coreParameters)))
    //val fwd_commit_resolved = Wire(Vec(fetchWidth, new prediction(coreParameters)))

    dontTouch(commit_resolved)

    for(i <- 0 until fetchWidth){
        val FU_resolved_prediction = Wire(new prediction(coreParameters))
        FU_resolved_prediction.target   := io.FU_outputs(0).bits.target_address
        FU_resolved_prediction.T_NT     := io.FU_outputs(0).bits.branch_taken
        FU_resolved_prediction.br_type  := DontCare  //io.FU_outputs(i).bits.
        FU_resolved_prediction.hit      := DontCare  // FIXME: what is this for? 
        FU_resolved_prediction.GHR      := DontCare


        commit_resolved(i) := fetch_resolved_banks(i).read(front_index + io.commit.valid)
        // allocate
        when(io.FU_outputs(0).valid && (io.FU_outputs(0).bits.fetch_packet_index === i.U) && (io.FU_outputs(0).bits.branch_valid)){
            fetch_resolved_banks(i).write(io.FU_outputs(0).bits.ROB_index, FU_resolved_prediction)

            when(RegNext(io.FU_outputs(0).bits.ROB_index === front_index && io.FU_outputs(0).bits.fetch_packet_index === i.U)){
                commit_resolved(i.U) := RegNext(FU_resolved_prediction)
            }
        }

        // commit
        //commit_resolved(i) := Mux(RegNext(io.FU_outputs(0).bits.ROB_index === front_index), RegNext(FU_resolved_prediction), fetch_resolved_banks(i).read(front_index + io.commit.valid))





        
    }





    /////////////////////////////////
    // FRONT POINTER CTRL / COMMIT //
    /////////////////////////////////
    front_pointer := front_pointer + io.commit.valid
    back_pointer := back_pointer + io.ROB_packet.fire

    back_index   := back_pointer(pointer_width-2, 0)
    front_index  := front_pointer(pointer_width-2, 0)
    dontTouch(back_pointer)
    dontTouch(front_pointer)


    ///////////////////////
    // ASSIGN ROB OUTPUT //
    ///////////////////////
    val ROB_output = Wire(new ROB_output(coreParameters))

    dontTouch(ROB_output)

    ROB_output.row_valid                := row_valid
    ROB_output.ROB_index                := front_index    // you want the unbypassed version of this pointer

    ROB_output.fetch_PC                 := shared_mem.io.readDataB.fetch_PC
    ROB_output.GHR                      := shared_mem.io.readDataB.GHR
    ROB_output.NEXT                     := shared_mem.io.readDataB.NEXT
    ROB_output.TOS                      := shared_mem.io.readDataB.TOS

    ROB_output.free_list_front_pointer  := shared_mem.io.readDataB.free_list_front_pointer

    for(i <- 0 until fetchWidth){
        ROB_output.complete(i)          := ROB_WB_banks(i).io.readDataG.busy    // Rename busy to complete
        ROB_output.ROB_entries(i)       := ROB_entry_banks(i).io.readDataB
    }

    ////////////
    // COMMIT //
    ////////////
    ////////////////////
    // PARTIAL COMMIT //
    ////////////////////
    // the commit signal for this module is resposible for committing an entire fetch packet at once. 
    // this is convinent for things like the front end that updates structures at the granuality of complete fetch packets. 
    // The load store queue, however, requires a more granular approach to committing, as without it, a store instruction for exmaple may block the entire load store queue





    val commit_valid        = Wire(Bool())
    val commit_row_complete = Wire(Vec(fetchWidth, Bool()))  // all valid instructions in that row are complete

    dontTouch(commit_prediction)
    dontTouch(commit_row_complete)

    for(i <- 0 until fetchWidth){
        val is_completed    = (ROB_output.complete(i) && ROB_output.ROB_entries(i).valid)
        val is_invalid      = (!ROB_output.ROB_entries(i).valid)
        val is_load         = ROB_output.ROB_entries(i).memory_type === memory_type_t.LOAD && ROB_output.ROB_entries(i).valid
        val is_store        = ROB_output.ROB_entries(i).memory_type === memory_type_t.STORE && ROB_output.ROB_entries(i).valid

        io.partial_commit.ROB_index(i).valid := (is_completed || is_invalid) && ROB_output.row_valid && !io.commit.bits.is_misprediction
        io.partial_commit.ROB_index(i).bits  := front_index

        io.partial_commit.MOB_index(i).valid := (is_completed || is_invalid) && ROB_output.row_valid && !io.commit.bits.is_misprediction
        io.partial_commit.MOB_index(i).bits  := ROB_output.ROB_entries(i).MOB_index

        commit_row_complete(i) := (is_completed || is_invalid) && ROB_output.row_valid  // stores happen after they commit
    }
    commit_valid := commit_row_complete.reduce(_ && _)



    dontTouch(commit_resolved)

    val has_taken_branch_vec = VecInit(Seq.tabulate(fetchWidth) { i =>
        ROB_output.ROB_entries(i).valid && ROB_output.complete(i) && commit_resolved(i).T_NT && ROB_entry_banks(i).io.readDataB.is_branch
    })

    val has_taken_branch = has_taken_branch_vec.reduce(_ || _)

    dontTouch(has_taken_branch)

    val earliest_taken_index = Mux1H(has_taken_branch_vec.zipWithIndex.map { case (taken, idx) =>
        taken -> idx.U
    })

    // Calculate the expected PC
    val expected_PC = Mux(has_taken_branch, commit_resolved(earliest_taken_index).target, ROB_output.fetch_PC + 0x10.U)

    io.commit.valid                              := commit_valid
    io.commit.bits.GHR                           := ROB_output.GHR
    io.commit.bits.TOS                           := ROB_output.TOS
    io.commit.bits.NEXT                          := ROB_output.NEXT
    io.commit.bits.ROB_index                     := ROB_output.ROB_index
    io.commit.bits.free_list_front_pointer       := ROB_output.free_list_front_pointer
    io.commit.bits.fetch_PC                      := ROB_output.fetch_PC

    for(i <- 0 until fetchWidth){
        io.commit.bits.RDold(i)                  := ROB_output.ROB_entries(i).RDold
        io.commit.bits.RD(i)                     := ROB_output.ROB_entries(i).RD
        io.commit.bits.RD_valid(i)               := ROB_output.ROB_entries(i).RD_valid
    }

    io.commit.bits.is_misprediction      := 0.B
    io.commit.bits.T_NT                  := 0.B
    io.commit.bits.br_type               := br_type_t.NONE
    io.commit.bits.fetch_packet_index    := 0.U
    io.commit.bits.expected_PC           := expected_PC

    dontTouch(expected_PC)
    dontTouch(earliest_taken_index)


    // Check for misprediction
    when((expected_PC =/= commit_prediction.target) && commit_valid) {
        io.commit.bits.is_misprediction      := 1.B
        io.commit.bits.T_NT                  := commit_resolved(earliest_taken_index).T_NT
        io.commit.bits.br_type               := commit_resolved(earliest_taken_index).br_type
        io.commit.bits.fetch_packet_index    := earliest_taken_index
        io.commit.bits.expected_PC := commit_resolved(earliest_taken_index).target
    }



    // COMMIT //
    when(io.commit.valid){
        row_valid_mem(io.commit.bits.ROB_index) := 0.B
    }

    when(io.commit.valid && io.commit.bits.is_misprediction){
        row_valid_mem := Seq.fill(ROBEntries)(0.B)
        front_pointer := 0.U
        back_pointer  := 0.U
    }


    ///////////
    // READY //
    ///////////

    val full = (front_pointer(pointer_width-2, 0) === back_pointer(pointer_width-2, 0)) && (front_pointer =/= back_pointer)

    io.ROB_packet.ready := !full


}

