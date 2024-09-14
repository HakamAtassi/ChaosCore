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

import java.io.PrintWriter

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
    val commit_valid        = Wire(Bool())


    val misprediction_vec       = Wire(Vec(fetchWidth, Bool())) // FIXME: do the same for exceptions
    misprediction_vec           := Seq.fill(fetchWidth)(0.B)

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

    val row_valid_mem   =   RegInit(VecInit(Seq.fill(ROBEntries)(0.B)))
    val row_valid       =   row_valid_mem(front_pointer(pointer_width-2, 0))


    when(io.ROB_packet.valid){  // Allocate
        row_valid_mem(back_pointer(pointer_width-2, 0)) := 1.B
    }

    when(commit_valid){  // Commit
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

    dontTouch(front_index)

    val shared_mem       = Module(new ROB_shared_mem(coreParameters, depth=ROBEntries))
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
    shared_mem.io.addrB         := front_index + commit_valid

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

    // Problem:
    // if an instruction here is marked as complete
    // then the pipeline is flushed, it will never commit, which means that bit will never be reset...

    val ROB_WB_banks: Seq[ROB_WB_mem] = Seq.tabulate(fetchWidth) { w =>
        Module(new ROB_WB_mem(coreParameters, depth=ROBEntries))
    }

    for(i <- 0 until fetchWidth){
        val ROB_WB_data = Wire(new ROB_WB(coreParameters))
        ROB_WB_data.busy := 0.B
        ROB_WB_data.RD_data.foreach(_:= 0.U)

        dontTouch(ROB_WB_data)

        // commit (clear complete when done with the row)
        ROB_WB_banks(i).io.addrA          := front_index
        ROB_WB_banks(i).io.writeDataA     := ROB_WB_data
        ROB_WB_banks(i).io.writeEnableA   := commit_valid
        // WB (connect all ports)

        // FU0
        val ROB_WB_data_FU0 = Wire(new ROB_WB(coreParameters))
        ROB_WB_data_FU0.busy             :=  io.FU_outputs(0).valid
        ROB_WB_data_FU0.RD_data.foreach(_:= io.FU_outputs(0).bits.RD_data)
        ROB_WB_banks(i).io.addrB         :=  io.FU_outputs(0).bits.ROB_index
        ROB_WB_banks(i).io.writeDataB    :=  ROB_WB_data_FU0
        ROB_WB_banks(i).io.writeEnableB  :=  io.FU_outputs(0).valid && (io.FU_outputs(0).bits.fetch_packet_index === i.U)

        // FU1
        val ROB_WB_data_FU1 = Wire(new ROB_WB(coreParameters))
        ROB_WB_data_FU1.busy             :=  io.FU_outputs(1).valid
        ROB_WB_data_FU1.RD_data.foreach(_:= io.FU_outputs(1).bits.RD_data)
        ROB_WB_banks(i).io.addrC         :=  io.FU_outputs(1).bits.ROB_index
        ROB_WB_banks(i).io.writeDataC    :=  ROB_WB_data_FU1
        ROB_WB_banks(i).io.writeEnableC  :=  io.FU_outputs(1).valid && (io.FU_outputs(1).bits.fetch_packet_index === i.U)

        // FU2
        val ROB_WB_data_FU2 = Wire(new ROB_WB(coreParameters))
        ROB_WB_data_FU2.busy             :=  io.FU_outputs(2).valid
        ROB_WB_data_FU2.RD_data.foreach(_:=  io.FU_outputs(2).bits.RD_data)
        ROB_WB_banks(i).io.addrD         :=  io.FU_outputs(2).bits.ROB_index
        ROB_WB_banks(i).io.writeDataD    :=  ROB_WB_data_FU2
        ROB_WB_banks(i).io.writeEnableD  :=  io.FU_outputs(2).valid && (io.FU_outputs(2).bits.fetch_packet_index === i.U)

        // FU3
        val ROB_WB_data_FU3 = Wire(new ROB_WB(coreParameters))
        ROB_WB_data_FU3.busy             :=  io.FU_outputs(3).valid
        ROB_WB_data_FU3.RD_data.foreach(_:=  io.FU_outputs(3).bits.RD_data)
        ROB_WB_banks(i).io.addrE         :=  io.FU_outputs(3).bits.ROB_index
        ROB_WB_banks(i).io.writeDataE    :=  ROB_WB_data_FU3
        ROB_WB_banks(i).io.writeEnableE  :=  io.FU_outputs(3).valid && (io.FU_outputs(3).bits.fetch_packet_index === i.U)

        // commit (connect all ports)
        ROB_WB_banks(i).io.addrG         := front_index + commit_valid
    
        ROB_WB_banks(i).io.flush         := io.commit.valid && io.commit.bits.is_misprediction
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
        ROB_entry_data.MOB_index             := io.ROB_packet.bits.decoded_instruction(i).MOB_index

        ROB_entry_data.RD_valid              := io.ROB_packet.bits.decoded_instruction(i).RD_valid
        ROB_entry_data.RD                    := io.ROB_packet.bits.decoded_instruction(i).RD
        ROB_entry_data.PRDold                := io.ROB_packet.bits.decoded_instruction(i).PRDold
        ROB_entry_data.PRD                   := io.ROB_packet.bits.decoded_instruction(i).PRD


        // allocate
        ROB_entry_banks(i).io.addrA          := back_index
        ROB_entry_banks(i).io.writeDataA     := ROB_entry_data
        ROB_entry_banks(i).io.writeEnableA   := allocate

        // commit
        ROB_entry_banks(i).io.addrB          := front_index + commit_valid
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
    commit_prediction := fetch_prediction_bank.read(front_index + commit_valid, 1.B)

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

    val fetch_resolved_banks: Seq[SyncReadMem[resolved_branch]] = Seq.tabulate(fetchWidth) { w =>
        SyncReadMem(ROBEntries, new resolved_branch(coreParameters))
    }
    
    
    val commit_resolved = Wire(Vec(fetchWidth, new resolved_branch(coreParameters)))
    //val fwd_commit_resolved = Wire(Vec(fetchWidth, new prediction(coreParameters)))

    dontTouch(commit_resolved)

    for(i <- 0 until fetchWidth){
        val FU_resolved_prediction = Wire(new resolved_branch(coreParameters))
        FU_resolved_prediction.target   := io.FU_outputs(0).bits.target_address
        FU_resolved_prediction.T_NT     := io.FU_outputs(0).bits.branch_taken
        FU_resolved_prediction.br_type  := DontCare  //io.FU_outputs(i).bits.
        FU_resolved_prediction.hit      := DontCare  // FIXME: what is this for? 


        commit_resolved(i) := fetch_resolved_banks(i).read(front_index + commit_valid)
        // allocate
        when(io.FU_outputs(0).valid && (io.FU_outputs(0).bits.fetch_packet_index === i.U)){
            fetch_resolved_banks(i).write(io.FU_outputs(0).bits.ROB_index, FU_resolved_prediction)

            when(RegNext(io.FU_outputs(0).bits.ROB_index === front_index && io.FU_outputs(0).bits.fetch_packet_index === i.U)){
                commit_resolved(i.U) := RegNext(FU_resolved_prediction)
            }
        }
    }





    /////////////////////////////////
    // FRONT POINTER CTRL / COMMIT //
    /////////////////////////////////
    front_pointer := front_pointer + commit_valid
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
        ROB_output.RD_data.foreach(rd => rd(i) := ROB_WB_banks(i).io.readDataG.RD_data.getOrElse(0.U))
        ROB_output.ROB_entries(i)       := ROB_entry_banks(i).io.readDataB
    }

    dontTouch(ROB_output)

    ////////////////////
    // PARTIAL COMMIT //
    ////////////////////


    val has_taken_branch_vec    = VecInit(Seq.tabulate(fetchWidth) { i => ROB_output.ROB_entries(i).valid && ROB_output.complete(i) && commit_resolved(i).T_NT && ROB_entry_banks(i).io.readDataB.is_branch})

    val has_taken_branch        = has_taken_branch_vec.reduce(_ || _)
    val earliest_taken_index    = PriorityEncoder(has_taken_branch_vec.asUInt) 
    val expected_PC             = Mux(has_taken_branch, commit_resolved(earliest_taken_index).target, ROB_output.fetch_PC + (fetchWidth*4).U)



    dontTouch(has_taken_branch_vec)

    // the commit signal for this module is resposible for committing an entire fetch packet at once. 
    // this is convinent for things like the front end that updates structures at the granuality of complete fetch packets. 
    // The load store queue, however, requires a more granular approach to committing, as without it, a store instruction for exmaple may block the entire load store queue

    val commit_row_complete = Wire(Vec(fetchWidth, Bool()))  // all valid instructions in that row are complete

    val commit          = Wire(new commit(coreParameters))
    val partial_commit  = Wire(new partial_commit(coreParameters))


    val pre_mispred = Wire(Vec(fetchWidth, Bool()))

    dontTouch(pre_mispred)

    for(i <- 0 until fetchWidth){   // only commit if all previous instructions are valid, complete, not a misprediction, and not an exception, or just invalid
        val is_completed    = (ROB_output.complete(i) && ROB_output.ROB_entries(i).valid)
        val is_invalid      = (!ROB_output.ROB_entries(i).valid)
        val is_valid        = (ROB_output.ROB_entries(i).valid)
        val is_load         = ROB_output.ROB_entries(i).memory_type === memory_type_t.LOAD && ROB_output.ROB_entries(i).valid
        val is_store        = ROB_output.ROB_entries(i).memory_type === memory_type_t.STORE && ROB_output.ROB_entries(i).valid


        pre_mispred(i) := (i.U <= earliest_taken_index && commit_valid) || !has_taken_branch 

        commit_row_complete(i) := (is_completed || is_invalid) && ROB_output.row_valid  // stores happen after they commit

        val allPreviousComplete = if (i == 0) true.B else commit_row_complete.take(i).reduce(_ && _)
        partial_commit.valid(i)      := (is_completed) && is_valid  && ROB_output.row_valid && allPreviousComplete && pre_mispred(i)
        partial_commit.MOB_index(i)  := ROB_output.ROB_entries(i).MOB_index
        partial_commit.MOB_valid(i)  := is_load || is_store
        partial_commit.ROB_index     := front_index
        partial_commit.RD_valid(i)   := ROB_output.ROB_entries(i).RD_valid
        partial_commit.RD(i)         := ROB_output.ROB_entries(i).RD
        partial_commit.PRD(i)        := ROB_output.ROB_entries(i).PRD
        partial_commit.PRDold(i)     := ROB_output.ROB_entries(i).PRDold

    }

    commit_valid := commit_row_complete.reduce(_ && _)

    ////////////
    // COMMIT //
    ////////////





    commit.GHR                           := ROB_output.GHR
    commit.TOS                           := ROB_output.TOS
    commit.NEXT                          := ROB_output.NEXT
    commit.ROB_index                     := ROB_output.ROB_index
    commit.free_list_front_pointer       := ROB_output.free_list_front_pointer
    commit.fetch_PC                      := ROB_output.fetch_PC

    for(i <- 0 until fetchWidth){
        commit.RD(i)                     := ROB_output.ROB_entries(i).RD
        commit.PRD(i)                    := ROB_output.ROB_entries(i).PRD
        commit.RD_valid(i)               := ROB_output.ROB_entries(i).RD_valid
    }

    commit.is_misprediction      := 0.B
    commit.T_NT                  := 0.B
    commit.br_type               := br_type_t.NONE
    commit.fetch_packet_index    := 0.U
    commit.expected_PC           := expected_PC
    commit.br_mask               := PriorityEncoderOH(has_taken_branch_vec)

    when(commit_valid){
        commit.is_misprediction      := 0.B
        commit.expected_PC           := expected_PC
        commit.br_mask               := PriorityEncoderOH(has_taken_branch_vec)
        commit.T_NT                  := commit_resolved(earliest_taken_index).T_NT
        commit.br_type               := commit_resolved(earliest_taken_index).br_type
        commit.fetch_packet_index    := earliest_taken_index
    }


    // Check for misprediction
    //when((expected_PC =/= commit_prediction.target) && commit_valid && has_taken_branch) {

    val resolved_br_mask = Wire(Vec(fetchWidth, Bool()))
    resolved_br_mask := commit_resolved.map(_.T_NT)
    dontTouch(resolved_br_mask)

    val correct_prediction = (Cat(PriorityEncoderOH(commit_prediction.br_mask)) ===  Cat(PriorityEncoderOH(resolved_br_mask))) && (expected_PC === commit_prediction.target) 


    //FIXME: this section, particularly the taken branch logic, needs to be cleaned up ALOT

    val has_branch = VecInit(Seq.tabulate(fetchWidth) { i => ROB_output.ROB_entries(i).valid && ROB_entry_banks(i).io.readDataB.is_branch}).reduce(_ || _)


    dontTouch(correct_prediction)
    dontTouch(has_branch)
    val test = Wire(UInt(32.W))

    test := 0.U


    dontTouch(test)

    when(!correct_prediction && commit_valid && has_branch) {
        commit.is_misprediction      := 1.B
        commit.br_type               := commit_resolved(earliest_taken_index).br_type
        commit.fetch_packet_index    := earliest_taken_index
        for(i <- fetchWidth-1 to 0 by - 1){
            val is_valid  = ROB_output.ROB_entries(i).valid
            val is_branch = ROB_entry_banks(i).io.readDataB.is_branch
            when((commit_resolved(i).T_NT =/= commit_prediction.br_mask(i)) && is_branch && is_valid){
                when(commit_resolved(i).T_NT === 1.B){
                    // branch was actually taken and prediction was not taken
                    // set expected PC to the computed address
                    commit.expected_PC := commit_resolved(i).target
                    test := commit_resolved(i).target
                }.otherwise{
                    // branch was actually not taken and prediction was taken
                    // set expected PC to the branch + 4.U
                    commit.expected_PC := ROB_output.fetch_PC + (i*4).U + 4.U
                    test := ROB_output.fetch_PC + (i*4).U + 4.U
                }
            }
        }
    }


    dontTouch(commit)

    io.commit.bits      := RegNext(commit)
    io.commit.valid     := RegNext(commit_valid)
    io.partial_commit   := RegNext(partial_commit)


    // COMMIT //
    when(commit_valid){
        row_valid_mem(commit.ROB_index) := 0.B
    }

    when(commit_valid && commit.is_misprediction){
        row_valid_mem := Seq.fill(ROBEntries)(0.B)
        front_pointer := 0.U
        back_pointer  := 0.U
    }

    dontTouch(commit_prediction)
    dontTouch(commit_row_complete)
    dontTouch(commit_resolved)
    dontTouch(has_taken_branch)
    dontTouch(expected_PC)
    dontTouch(earliest_taken_index)


    ///////////
    // READY //
    ///////////

    val full = PopCount(row_valid_mem) === ROBEntries.U
    //val full = (front_pointer(pointer_width-2, 0) === back_pointer(pointer_width-2, 0)) && (front_pointer =/= back_pointer)

    io.ROB_packet.ready := !full




    ///////////
    // DEBUG //
    ///////////


    if(DEBUG){
        when(io.commit.valid){
            for(i <- 0 until fetchWidth){
                val instruction_PC  = io.commit.bits.fetch_PC + (i*4).U
                val arch_RD         = io.partial_commit.RD(i)
                val arch_RD_valid   = io.partial_commit.RD_valid(i)
                val physical_RD     = io.partial_commit.PRD(i)
                val RD_data         = RegNext(ROB_output.RD_data.map(_(i)).getOrElse(0.U))

                val is_completed    = RegNext(ROB_output.complete(i) && ROB_output.ROB_entries(i).valid)

                when(arch_RD_valid && is_completed && io.partial_commit.valid(i) && arch_RD=/=0.U){
                    // PC RD data
                    printf("core   0: 3 0x%x (0x00000000) x%d  0x%x \n", instruction_PC, arch_RD, RD_data);
                  //printf("core   0: 3 0x80000004 (0x00000093) x1  0x00000000", )
                }.elsewhen(is_completed && io.partial_commit.valid(i)){
                    printf("core   0: 3 0x%x (0x00000000)  \n", instruction_PC)
                }
            }
        }
    }

}
