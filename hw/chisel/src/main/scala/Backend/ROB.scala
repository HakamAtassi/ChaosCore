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


class ROB_instruction_bank(bank_idx:Int = 0)(coreParameters:CoreParameters) extends Module{
    import coreParameters._

    val io = IO(new Bundle{
        // allocate input (1 wr)
        val decoded_insn                  =   Flipped(Decoupled(new decoded_instruction(coreParameters)))
        val ROB_back_idx                  =   Input(UInt(log2Ceil(ROBEntries).W))

        // WB inputs
        val FU_inputs                     =   Vec(portCount, Flipped(Decoupled(new FU_output(coreParameters))))

        // commit insn (1 bit, commit this instruction)
        val commit                        =   Input(Bool())

        // commit output
        val ROB_instruction_entry         =   Output(new ROB_instruction_entry(coreParameters))
        val ROB_front_idx                 =   Input(UInt(log2Ceil(ROBEntries).W))

        // Flush
        val flush                         =   ValidIO(new flush(coreParameters)) 
    }); dontTouch(io)

    // On allocate, write row and clear as needed 
    // On WB, update WB mem as needed
    // On commit, set commit bit
    // Clear entries with commit bit set
    // On flush, clear bank entries


    /////////////////////
    // WRITE-BACK BANK //
    /////////////////////
    // Implemented as LUTS
    val wb_mem = RegInit(VecInit(Seq.fill(ROBEntries)(0.U.asTypeOf(new ROB_WB_entry(coreParameters)))))

    // allocate
    when(io.decoded_insn.fire){
        // clear entry, update valid
        wb_mem(io.ROB_front_idx)       := 0.U.asTypeOf(new ROB_WB_entry(coreParameters))
        wb_mem(io.ROB_front_idx).valid := 1.B   // is this entry filled (irregardless of instruction being valid)
    }

    // update (WB)
    for(FU_input <- io.FU_inputs){
        when(FU_input.fire && FU_input.bits.fetch_packet_index === bank_idx.U){
            wb_mem(FU_input.bits.ROB_index).complete            := FU_input.valid
            wb_mem(FU_input.bits.ROB_index).exception           := FU_input.bits.exception
            wb_mem(FU_input.bits.ROB_index).exception_cause     := FU_input.bits.exception_cause
            wb_mem(FU_input.bits.ROB_index).mem_violation       := 0.B //FU_input.bits.exception
        }
    }

    // commit
    when(io.commit){
        wb_mem(io.ROB_front_idx).committed           := 1.B
    }

    // free entry after "full" commit
    when(wb_mem(io.ROB_front_idx).valid && wb_mem(io.ROB_front_idx).committed && wb_mem(io.ROB_front_idx).complete){
        wb_mem(io.ROB_front_idx) := 0.U.asTypeOf(new ROB_WB_entry(coreParameters))
    }

    // flush
    when(io.flush.valid) {
        wb_mem := VecInit(Seq.fill(ROBEntries)(0.U.asTypeOf(new ROB_WB_entry(coreParameters))))
    }


    //////////////////////
    // INSTRUCTION BANK //
    //////////////////////
    // 1 Read + 1 Write 

    val insn_mem = SyncReadMem(ROBEntries, new ROB_uOp_entry(coreParameters))

    // allocate
    when(io.decoded_insn.fire){
        // clear entry, update valid
        val insn_entry = Wire(new ROB_uOp_entry(coreParameters))
        insn_entry.decoded_insn := io.decoded_insn.bits
        insn_mem.write(io.ROB_back_idx, insn_entry)
    }


    ///////////////////
    // ASSIGN OUTPUT //
    ///////////////////

    // rob row output for commit
    io.ROB_instruction_entry.uOp := insn_mem.read(io.ROB_front_idx)
    io.ROB_instruction_entry.WB  := RegNext(wb_mem(io.ROB_front_idx))

    // ready bits for WB mem access (always ready for WB)
    // WB mem always ready
    for(i <- 0 until portCount){
        io.FU_inputs(i).ready := 1.B
    }

    io.decoded_insn.ready := (io.ROB_back_idx + 1.U) =/= io.ROB_front_idx
}


class ROB_shared_bank(coreParameters:CoreParameters) extends Module{
    import coreParameters._

    val io = IO(new Bundle{
        // allocate input (1 wr)
        val ROB_packet                    =   Flipped(Decoupled(new decoded_fetch_packet(coreParameters))) // ignore decoded_instruction input

        val ROB_back_idx                  =   Input(UInt(log2Ceil(ROBEntries).W))

        // commit insn (1 bit, commit this instruction)
        val ROB_front_idx                 =   Input(UInt(log2Ceil(ROBEntries).W))
        val ROB_shared_entry              =   Output(new ROB_shared_entry(coreParameters))

    }); dontTouch(io)

    // 1 + N Read, 1 Write
    //// 1 Read for ROB commit row. N Read for Branch units
    // 1 Write for allocate

    val shared_mem = SyncReadMem(ROBEntries, new ROB_shared_entry(coreParameters))

    // allocate //
    when(io.ROB_packet.fire) {
        val shared_entry = Wire(new ROB_shared_entry(coreParameters))
        shared_entry.fetch_PC                   := io.ROB_packet.bits.fetch_PC
        shared_entry.free_list_front_pointer    := io.ROB_packet.bits.free_list_front_pointer
        shared_entry.GHR                        := io.ROB_packet.bits.GHR
        shared_entry.NEXT                       := io.ROB_packet.bits.NEXT
        shared_entry.TOS                        := io.ROB_packet.bits.TOS
        shared_entry.prediction                 := io.ROB_packet.bits.prediction

        shared_mem.write(io.ROB_back_idx, shared_entry)
    }

    // commit //
    io.ROB_shared_entry := shared_mem.read(io.ROB_front_idx)


    io.ROB_packet.ready := (io.ROB_back_idx + 1.U) =/= io.ROB_front_idx
}

class ROB_branch_bank(bank_idx: Int = 0)(coreParameters: CoreParameters) extends Module {
    import coreParameters._
    val io = IO(new Bundle {
        // commit port
        val resolved_branch_out     = Output(new ROB_branch_entry(coreParameters))
        val ROB_front_idx           = Input(UInt(log2Ceil(ROBEntries).W))

        // WB port (1 WR)
        val FU_inputs               = Vec(portCount, Flipped(Decoupled(new FU_output(coreParameters))))
    }); dontTouch(io)

    // update on WB
    // Read on commit

    // branches write back their result to this unit on write back
    // ports may or may not be available

    //////////////////
    // ASSIGN READY //
    //////////////////

    // input arbitration
    // inputs write to this module if they are valid, are a branch, and write to this particular branch
    // however, only 1 branch can write to this module each cycle (only 1 write port)
    // therefore, only 1 output ready will be high each cycle for this particular branch bank

    val mem = SyncReadMem(ROBEntries, new ROB_branch_entry(coreParameters))

    /////////////////////////
    // ROUND ROBIN ARBITER //
    /////////////////////////
    // output is ready if input is non branch or if bank is available

    val valid_branch_inputs = io.FU_inputs.zipWithIndex.map { case (fu_input, idx) =>
        fu_input.valid && fu_input.bits.CTRL && fu_input.bits.fetch_packet_index === bank_idx.U
    }

    val arbiter = Module(new RRArbiter(new FU_output(coreParameters), portCount))
    arbiter.io.in.zip(io.FU_inputs).foreach { case (arb_in, fu_input) =>
        arb_in.valid := valid_branch_inputs(io.FU_inputs.indexOf(fu_input))
        arb_in.bits := fu_input.bits
    }

    // output ready if granted or doesnt need this bank
    // ie, not a control insn, or is a control insn to a diff bank
    io.FU_inputs.zipWithIndex.foreach { case (fu_input, idx) =>
        fu_input.ready := arbiter.io.in(idx).ready || !fu_input.bits.CTRL || fu_input.bits.fetch_packet_index =/= bank_idx.U
    }

    ///////////////////
    // MEMORY UPDATE //
    ///////////////////
    // update (WB)

    when(arbiter.io.out.fire) {
        val wb_addr = arbiter.io.out.bits.ROB_index
        val resolved_branch = Wire(new ROB_branch_entry(coreParameters))
        resolved_branch.target_PC := arbiter.io.out.bits.target_address
        resolved_branch.taken := arbiter.io.out.bits.branch_taken

        mem.write(wb_addr, resolved_branch)
    }

    //////////////////
    // OUTPUT LOGIC //
    //////////////////

    io.resolved_branch_out := mem.read(io.ROB_front_idx) 
}






class ROB(coreParameters:CoreParameters) extends Module{
    import coreParameters._
    val portCount = getPortCount(coreParameters)
    val branchPortCount = getBranchPortCount(coreParameters)

    val io = IO(new Bundle{
        // ALLOCATE //
        val ROB_packet                  =   Flipped(Decoupled(new decoded_fetch_packet(coreParameters)))

        // UPDATE //
        val FU_inputs                  =    Vec(portCount, Flipped(Decoupled(new FU_output(coreParameters))))

        // COMMIT //
        val commit                      =   Output(new commit(coreParameters))

        // FLUSH 
        val flush                       =   ValidIO(new flush(coreParameters)) 

        // ROB index
        val ROB_index                   =   Output(UInt(log2Ceil(ROBEntries).W))

        // PC FILE //
        // 1 pre branch unit
        val PC_file_exec_addr           =   Vec(branchPortCount, Input(UInt(log2Ceil(ROBEntries).W)))
        val PC_file_exec_data           =   Vec(branchPortCount, Output(UInt(32.W)))
    }); dontTouch(io)

    val CSR_port = IO(Input(new CSR_out(coreParameters))); dontTouch(CSR_port)

    // only update WB valid memory on a grant/no grant basis
    // for instance, multiple instructions may be writing to the same branch WB bank in a single cycle.
    // Only mark those branches as complete in the ROB_WB_bank if the ROB_branch_bank grants the write-back.

    // more broadly, instructions are only marked as completed if its writeback phase is complete. 
    //// this includes writing back to the RF and ROB (branches and just WB bits)

    val pointer_width = log2Ceil(ROBEntries)+1

    val front_pointer = RegInit(UInt(pointer_width.W), 0.U)
    val back_pointer  = RegInit(UInt(pointer_width.W), 0.U)

    val front_index = Wire(UInt((pointer_width-1).W))
    val back_index  = Wire(UInt((pointer_width-1).W))

    io.ROB_index := back_index


    //////////////////////////
    // ROB INSTRUCTION BANK //
    //////////////////////////
    // WB + uOPs

    val ROB_instruction_banks: Seq[ROB_instruction_bank] = Seq.tabulate(fetchWidth) { w => Module(new ROB_instruction_bank(bank_idx=w)(coreParameters))}

    for(i <- 0 until fetchWidth){
        ROB_instruction_banks(i).io.decoded_insn.valid    := io.ROB_packet.valid
        ROB_instruction_banks(i).io.decoded_insn.bits     := io.ROB_packet.bits.decoded_instruction(i)

        
        ROB_instruction_banks(i).io.ROB_back_idx         := back_index

        for(j <- 0 until portCount){
            ROB_instruction_banks(i).io.FU_inputs(j).bits              :=  io.FU_inputs(j).bits 
            ROB_instruction_banks(i).io.FU_inputs(j).valid             :=  io.FU_inputs(j).valid 
        }

        ROB_instruction_banks(i).io.ROB_front_idx        := front_index
        ROB_instruction_banks(i).io.flush                := io.flush
    }
    
    



    /////////////////////
    // ROB SHARED BANK //
    /////////////////////
    // fetch PC + prediction

    val ROB_shared_bank = Module(new ROB_shared_bank(coreParameters))

    ROB_shared_bank.io.ROB_packet                    := io.ROB_packet
    ROB_shared_bank.io.ROB_back_idx                  := back_index
    ROB_shared_bank.io.ROB_front_idx                 := front_index

    /////////////////////
    // ROB BRANCH BANK //
    /////////////////////
    // Resolved branch data

    val ROB_branch_banks: Seq[ROB_branch_bank] = Seq.tabulate(fetchWidth) { w => Module(new ROB_branch_bank(bank_idx=w)(coreParameters))}

    for(i <- 0 until fetchWidth){
        ROB_branch_banks(i).io.ROB_front_idx                      :=  front_index         
        for(j <- 0 until portCount){
            ROB_branch_banks(i).io.FU_inputs(j).bits              :=  io.FU_inputs(j).bits 
            ROB_branch_banks(i).io.FU_inputs(j).valid             :=  io.FU_inputs(j).valid 
        }
    }







    /////////////////////////
    // HANDLE CONTROL FLOW //
    /////////////////////////

    // get earliest taken CTRL insn (branch, XRET, etc)
    val CTRL_insn_oh = VecInit(
        ROB_instruction_banks.zipWithIndex.map { case (bank, i) =>
            bank.io.ROB_instruction_entry.uOp.decoded_insn.CTRL &&
            bank.io.ROB_instruction_entry.WB.complete &&
            ROB_branch_banks(i).io.resolved_branch_out.taken &&
            bank.io.ROB_instruction_entry.WB.valid
        }
    )


    // CSR instructions flush. Hence, get earliest CSRRW
    val CSRRW_insn_oh     =  ROB_instruction_banks.map(bank =>  bank.io.ROB_instruction_entry.uOp.decoded_insn.CSRRW     && 
                                                                bank.io.ROB_instruction_entry.WB.complete   &&
                                                                bank.io.ROB_instruction_entry.WB.valid) 
    
    // Fences also flush. Hence, get earliest FENCE
    val FENCE_insn_oh     =  ROB_instruction_banks.map(bank =>  bank.io.ROB_instruction_entry.uOp.decoded_insn.FENCE     && 
                                                                bank.io.ROB_instruction_entry.WB.complete   &&
                                                                bank.io.ROB_instruction_entry.WB.valid) 
    
    // get any other MISC. flushing insns. 
    val FLUSH_insn_oh     =  ROB_instruction_banks.map(bank =>  bank.io.ROB_instruction_entry.uOp.decoded_insn.FLUSH     && 
                                                                bank.io.ROB_instruction_entry.WB.complete   &&
                                                                bank.io.ROB_instruction_entry.WB.valid) 

    // Exceptions also flush. Get earliest excepting insn. 
    val EXCEPTION_insn_oh = ROB_instruction_banks.map(bank =>   bank.io.ROB_instruction_entry.WB.exception  && 
                                                                bank.io.ROB_instruction_entry.WB.complete   &&
                                                                bank.io.ROB_instruction_entry.WB.valid) 

    val earliest_CTRL_oh = VecInit(
        (0 until ROB_instruction_banks.length).map { i =>
            CTRL_insn_oh(i) || CSRRW_insn_oh(i) || FENCE_insn_oh(i) || FLUSH_insn_oh(i) || EXCEPTION_insn_oh(i)
        }
    )

    val earliest_CTRL_idx = PriorityEncoder(earliest_CTRL_oh.asUInt)

    val earliest_CTRL_insn = MuxLookup(
        earliest_CTRL_idx,
        0.U.asTypeOf(new ROB_instruction_entry(coreParameters)), // Default value
        ROB_instruction_banks.zipWithIndex.map { case (bank, idx) =>
            idx.U -> bank.io.ROB_instruction_entry
        }
    )

    val earliest_CTRL_branch_info = MuxLookup(
        earliest_CTRL_idx,
        0.U.asTypeOf(new ROB_branch_entry(coreParameters)), // Default value
        ROB_branch_banks.zipWithIndex.map { case (bank, idx) =>
            idx.U -> bank.io.resolved_branch_out
        }
    )




    val prediction = ROB_shared_bank.io.ROB_shared_entry.prediction


    io.flush := 0.U.asTypeOf(new flush(coreParameters))



    when(earliest_CTRL_oh.reduce(_ || _) && earliest_CTRL_insn.uOp.decoded_insn.CTRL && earliest_CTRL_insn.WB.committed){
        // dominant branch is a typical branch
        // only flush if doesnt match prediction
        when(0.B /*prediction.taken && prediction.target_address === earliest_CTRL_branch_info.target_PC*/){    // FIXME: for this, you need to ensure WHICH branch is taken and to where, if any (br mask...)
            // prediction correct, do nothing
        }.otherwise{
            io.flush.valid := 1.B
            io.flush.bits.flushing_PC:= ROB_shared_bank.io.ROB_shared_entry.fetch_PC + (4.U * earliest_CTRL_idx)
            io.flush.bits.redirect_PC:= earliest_CTRL_branch_info.target_PC
            io.flush.bits.is_misprediction := 1.B
        }
    
    }.elsewhen(earliest_CTRL_oh.reduce(_ || _) && earliest_CTRL_insn.WB.exception /*&&*/ /*about to commit*/){ //FIXME: not complete// excepting instructions don't commit
        // is an exception
        // flush and jump to MTVEC

        io.flush.bits.is_exception := 1.B
    }.elsewhen(earliest_CTRL_oh.reduce(_ || _) && earliest_CTRL_branch_info.WB.committed){
        // is a CSRRW, FENCE, FLUSH, or otherwise
        // flush and jump to next insn
        io.flush.valid := 1.B
        io.flush.bits.flushing_PC := ROB_shared_bank.io.ROB_shared_entry.fetch_PC + (4.U * earliest_CTRL_idx)
        io.flush.bits.redirect_PC := ROB_shared_bank.io.ROB_shared_entry.fetch_PC + (4.U * earliest_CTRL_idx) + 4.U

        io.flush.bits.is_fence    := earliest_CTRL_branch_info.uOp.decoded_insn.FENCE
        io.flush.bits.is_CSR      := earliest_CTRL_branch_info.uOp.decoded_insn.CSR
    }


    // ASSIGN FLUSH //
    ROB_instruction_banks.foreach { bank => bank.io.flush.valid := io.flush.valid }

    ////////////
    // COMMIT //
    ////////////
    
    // most instructions commit when they are complete and previous instructions have either committed or are actively committing
    // CSRRW operations commit first, then complete. 
    // memory stores also commit first, then complete. 
    // instructions are not deallocated from the ROB unless they are both complete and committed

    // in other words:
    // if previous instruction is invalid || (committed && completed)
    // commit(i) = (!insn(i-1).valid || (insn(i-1).complete && (insn(i-1).committed || insn(i-1).is_committing))) && (insn(i).complete || insn(i).STORE || insn(i).CSRRW)

    val commit_vec = {
        val entries = ROB_instruction_banks.map(_.io.ROB_instruction_entry)
        val committing = ROB_instruction_banks.map(_.io.commit)


        val cVec = WireInit(VecInit(Seq.fill(fetchWidth)(false.B)))

        cVec(0) := (entries(0).WB.complete || entries(0).uOp.decoded_insn.STORE || entries(0).uOp.decoded_insn.CSRRW) && entries(0).WB.valid

        for (i <- 1 until fetchWidth) {
            val prevValid      = entries(i-1).WB.valid
            val prevComplete   = entries(i-1).WB.complete
            val prevCommittedOrCommitting = entries(i-1).WB.committed || committing(i-1)


            cVec(i) :=  (entries(i).WB.complete || entries(i).uOp.decoded_insn.STORE || entries(i).uOp.decoded_insn.CSRRW) && 
                        (!prevValid || (prevComplete && prevCommittedOrCommitting)) && 
                        i.U <= earliest_CTRL_idx &&
                        !EXCEPTION_insn_oh(i)   // don't commit exceptions

        }
        cVec
    }

    // Drive the commit signal for each instruction bank
    for (i <- 0 until fetchWidth) {
        ROB_instruction_banks(i).io.commit := commit_vec(i)
    }

    
    // DRIVE I/O COMMIT //
    io.commit.fetch_PC  := ROB_shared_bank.io.ROB_shared_entry.fetch_PC
    io.commit.ROB_index := back_index
    io.commit.free_list_front_pointer := ROB_shared_bank.io.ROB_shared_entry.free_list_front_pointer

    for(i <- 0 until fetchWidth){
        io.commit.insn_commit(i).valid          := ROB_instruction_banks(i).io.ROB_instruction_entry.WB.committed

        io.commit.insn_commit(i).bits.MOB_index := ROB_instruction_banks(i).io.ROB_instruction_entry.uOp.decoded_insn.MOB_index
        io.commit.insn_commit(i).bits.MOB_valid := ROB_instruction_banks(i).io.ROB_instruction_entry.uOp.decoded_insn.MOB_valid
        io.commit.insn_commit(i).bits.RD        := ROB_instruction_banks(i).io.ROB_instruction_entry.uOp.decoded_insn.RD
        io.commit.insn_commit(i).bits.RD_valid  := ROB_instruction_banks(i).io.ROB_instruction_entry.uOp.decoded_insn.RD_valid
        io.commit.insn_commit(i).bits.PRD       := ROB_instruction_banks(i).io.ROB_instruction_entry.uOp.decoded_insn.PRD
        io.commit.insn_commit(i).bits.PRDold    := ROB_instruction_banks(i).io.ROB_instruction_entry.uOp.decoded_insn.PRDold
    }


    // This signal is only every high if the row completes without any flushes of any kind
    val row_commit = ROB_instruction_banks.map(bank => !bank.io.ROB_instruction_entry.WB.valid).reduce(_ || _)

    when(io.flush.valid){
        front_pointer := 0.U
        back_pointer  := 0.U
    }.otherwise{
        front_pointer := front_pointer + row_commit
        back_pointer  := back_pointer + io.ROB_packet.fire
    }







    ///////////////
    // INTERRUPT //
    ///////////////
    
    // TODO: 


    //////////////////
    // ASSIGN READY //
    //////////////////

    // Compress ready bits for each instruction bank
    val instruction_bank_FU_output_ready = VecInit(
        (0 until portCount).map { i =>
            ROB_instruction_banks.map(_.io.FU_inputs(i).ready).reduce(_ && _)
        }
    )

    // Compress ready bits for each branch bank
    val branch_bank_FU_output_ready = VecInit(
        (0 until portCount).map { i =>
            ROB_branch_banks.map(_.io.FU_inputs(i).ready).reduce(_ && _)
        }
    )

    // Compute the final FU output ready bits as the AND of both
    val FU_ready_bits = VecInit(
        (0 until portCount).map { i =>
            instruction_bank_FU_output_ready(i) && branch_bank_FU_output_ready(i)
        }
    )

    // Assign each bit to the corresponding element in io.FU_inputs.ready
    for (i <- 0 until portCount) {
        io.FU_inputs(i).ready := FU_ready_bits(i)
    }

    io.ROB_packet.ready := ROB_shared_bank.io.ROB_packet.ready && ROB_instruction_banks.map(_.io.decoded_insn.ready).reduce(_ && _)


    ////////////////////
    // GENERATE TRACE //
    ////////////////////
    // print data for each committing instruction //

    if(DEBUG){
        for(i <- 0 until fetchWidth){
            val instruction_PC  = ROB_shared_bank.io.ROB_shared_entry.fetch_PC + (i*4).U

            val arch_RD         = ROB_instruction_banks(i).io.ROB_instruction_entry.uOp.decoded_insn.RD
            val arch_RD_valid   = ROB_instruction_banks(i).io.ROB_instruction_entry.uOp.decoded_insn.RD_valid
            val PRD             = ROB_instruction_banks(i).io.ROB_instruction_entry.uOp.decoded_insn.PRD

            val done            = ROB_instruction_banks(i).io.ROB_instruction_entry.WB.committed && ROB_instruction_banks(i).io.ROB_instruction_entry.WB.complete && ROB_instruction_banks(i).io.ROB_instruction_entry.WB.valid

            val RD_data         = ROB_instruction_banks(i).io.ROB_instruction_entry.WB.RD_data.get

            
            //FIXME: add support for stores, CSRs, etc...
            when(done && arch_RD_valid){
                // PC RD data
                printf("core   0: 3 0x%x x%d 0x%x\n", instruction_PC, arch_RD, RD_data);
                //printf("core   0: 3 0x80000004 (0x00000093) x1  0x00000000", )
            }.elsewhen(done){
                printf("core   0: 3 0x%x\n", instruction_PC)
            }

        }
    }


}
