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


// STORES and CSR related instructions(CSRRW, xRET, ECALL, EBREAK, etc) all COMMIT first
// Where commit indicates that no previous instruction flushes the pipeline. 
// Then, these instructions execute, mark complete, and if they do not cause an exception, can retire
// Where retire indicates that the instruction can safely exit the pipeline

// When a flush occurs, you flush all unretired instructions, even if committed. 



package ChaosCore

import chisel3._
import chisel3.util._


class ROB_instruction_bank(bank_idx:Int = 0)(coreParameters:CoreParameters) extends Module{
    import coreParameters._

    val portCount = getPortCount(coreParameters)
    val io = IO(new Bundle{
        // allocate input (1 wr)
        val decoded_insn                  =   Flipped(Decoupled(new decoded_instruction(coreParameters)))
        val ROB_back_idx                  =   Input(UInt(log2Ceil(ROBEntries).W))

        // WB inputs
        val producers                     =   Vec(producer_count, Flipped(Decoupled(new FU_output(coreParameters))))

        // commit insn (1 bit, commit this instruction)
        val commit                        =   Input(Bool())
        
        // same for retire
        val retire                        =   Input(Bool())

        // commit output
        val ROB_instruction_entry         =   Output(new ROB_instruction_entry(coreParameters))
        val ROB_front_idx                 =   Input(UInt(log2Ceil(ROBEntries).W))

        // Flush
        val flush                         =   Flipped(ValidIO(new flush(coreParameters)))
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
        wb_mem(io.ROB_back_idx)       := 0.U.asTypeOf(new ROB_WB_entry(coreParameters))
        wb_mem(io.ROB_back_idx).valid := io.decoded_insn.bits.valid 
    }

    // update (WB)
    for(FU_input <- io.producers){
        when(FU_input.fire && FU_input.bits.fetch_packet_index === bank_idx.U){
            wb_mem(FU_input.bits.ROB_index).complete            := FU_input.valid
            wb_mem(FU_input.bits.ROB_index).exception           := FU_input.bits.exception
            wb_mem(FU_input.bits.ROB_index).exception_cause     := FU_input.bits.exception_cause
            wb_mem(FU_input.bits.ROB_index).mem_violation       := 0.B //FU_input.bits.exception
            if(DEBUG){ wb_mem(FU_input.bits.ROB_index).RD_data.get  := FU_input.bits.RD_data }
        }
    }

    // commit

    when(io.commit){
        wb_mem(io.ROB_front_idx).committed           := 1.B
    }

    // free entry after "full" commit
    when(io.retire){
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
    val insn_entry = Wire(new ROB_uOp_entry(coreParameters))
    insn_entry.decoded_insn := io.decoded_insn.bits
    when(io.decoded_insn.fire){
        // clear entry, update valid
        insn_mem.write(io.ROB_back_idx, insn_entry)
    }


    ///////////////////
    // ASSIGN OUTPUT //
    ///////////////////

    // On write, ensure that writes to the commit row are visible 1 cycle later.
    // rob row output for commit
    io.ROB_instruction_entry.uOp := insn_mem.read(io.ROB_front_idx)




    io.ROB_instruction_entry.WB  := wb_mem(RegNext(io.ROB_front_idx))
    

    // ready bits for WB mem access (always ready for WB)
    // WB mem always ready

    io.producers.foreach(_.ready := 1.B)

    io.decoded_insn.ready := (io.ROB_back_idx + 1.U) =/= io.ROB_front_idx
}


class ROB_shared_bank(coreParameters:CoreParameters) extends Module{
    import coreParameters._

    val portCount = getPortCount(coreParameters)
    val branchPortCount = getBranchPortCount(coreParameters)

    val io = IO(new Bundle{
        // allocate input (1 wr)
        val ROB_packet                    =   Flipped(Decoupled(new decoded_fetch_packet(coreParameters))) // ignore decoded_instruction input
        val ROB_back_idx                  =   Input(UInt(log2Ceil(ROBEntries).W))

        // commit (1 RD)
        val ROB_shared_entry              =   ValidIO(new ROB_shared_entry(coreParameters))
        val ROB_front_idx                 =   Input(UInt(log2Ceil(ROBEntries).W))

        val commit_row                    =   Input(Bool())
        val flush                         =   Input(Bool())

        // PC FILE //
        // 1 pre branch unit
        val PC_file_exec_addr           =   Vec(branchPortCount, Input(UInt(log2Ceil(ROBEntries).W)))
        val PC_file_exec_data           =   Vec(branchPortCount, Output(UInt(32.W)))

    }); dontTouch(io)

    // 1 + N Read, 1 Write
    //// 1 Read for ROB commit row. N Read for Branch units
    // 1 Write for allocate

    val shared_mem = SyncReadMem(ROBEntries, new ROB_shared_entry(coreParameters))
    val valid_vec  = RegInit(VecInit(Seq.fill(ROBEntries)(0.B)))


    // allocate //
    when(io.ROB_packet.fire) {
        val shared_entry = Wire(new ROB_shared_entry(coreParameters))
        shared_entry.fetch_PC                   := io.ROB_packet.bits.fetch_PC
        shared_entry.GHR                        := io.ROB_packet.bits.GHR
        shared_entry.NEXT                       := io.ROB_packet.bits.NEXT
        shared_entry.TOS                        := io.ROB_packet.bits.TOS
        shared_entry.prediction                 := io.ROB_packet.bits.prediction

        valid_vec(io.ROB_back_idx)              := 1.B
        shared_mem.write(io.ROB_back_idx, shared_entry)
    }

    // commit //
    io.ROB_shared_entry.bits := shared_mem.read(io.ROB_front_idx)
    io.ROB_shared_entry.valid := valid_vec(RegNext(io.ROB_front_idx))
    when(io.commit_row){
        valid_vec(io.ROB_front_idx) := 0.B  // clear valid bit
    }

    when(io.flush){
        valid_vec := VecInit(Seq.fill(ROBEntries)(0.B))
    }

    // PC FILE
    for(i <- 0 until branchPortCount){
        io.PC_file_exec_data(i) := shared_mem.read(io.PC_file_exec_addr(i)).fetch_PC
    }


    io.ROB_packet.ready := (io.ROB_back_idx + 1.U) =/= io.ROB_front_idx
}

class ROB_branch_bank(bank_idx: Int = 0)(coreParameters: CoreParameters) extends Module {
    import coreParameters._

    val portCount = getPortCount(coreParameters)
    val io = IO(new Bundle {
        // commit port
        val resolved_branch_out     = Output(new ROB_branch_entry(coreParameters))
        val ROB_front_idx           = Input(UInt(log2Ceil(ROBEntries).W))

        // WB port (1 WR)
        val INT_producers               = Vec(INT_producer_count, Flipped(Decoupled(new FU_output(coreParameters))))
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

    val valid_branch_inputs = WireInit(VecInit(io.INT_producers.zipWithIndex.map { case (fu_input, idx) =>
        fu_input.valid && (fu_input.bits.CTRL) && (fu_input.bits.fetch_packet_index === bank_idx.U)
    }))

    dontTouch(valid_branch_inputs)

    val arbiter = Module(new RRArbiter(new FU_output(coreParameters), INT_producer_count))
    arbiter.io.in.zip(io.INT_producers).foreach { case (arb_in, fu_input) =>
        arb_in.valid := valid_branch_inputs(io.INT_producers.indexOf(fu_input))
        arb_in.bits := fu_input.bits
    }

    // output ready if granted or doesnt need this bank
    // ie, not a control insn, or is a control insn to a diff bank
    io.INT_producers.zipWithIndex.foreach { case (fu_input, idx) =>
        fu_input.ready := arbiter.io.in(idx).ready || !fu_input.bits.CTRL || fu_input.bits.fetch_packet_index =/= bank_idx.U
    }

    arbiter.io.out.ready := 1.B // you can always handle the selected write

    ///////////////////
    // MEMORY UPDATE //
    ///////////////////
    // update (WB)

    val wb_addr = arbiter.io.out.bits.ROB_index
    val resolved_branch = Wire(new ROB_branch_entry(coreParameters))
    resolved_branch := 0.U.asTypeOf(new ROB_branch_entry(coreParameters))
    when(arbiter.io.out.fire) {
        resolved_branch.target_PC := arbiter.io.out.bits.target_address
        resolved_branch.taken := arbiter.io.out.bits.branch_taken

        mem.write(wb_addr, resolved_branch)
    }

    //////////////////
    // OUTPUT LOGIC //
    //////////////////

    io.resolved_branch_out := Mux(RegNext(wb_addr === io.ROB_front_idx) && RegNext(arbiter.io.out.fire), RegNext(resolved_branch), mem.read(io.ROB_front_idx))
}

class ROB(coreParameters:CoreParameters) extends Module{
    import coreParameters._
    val portCount = getPortCount(coreParameters)
    val branchPortCount = getBranchPortCount(coreParameters)

    val io = IO(new Bundle{
        // ALLOCATE //
        val ROB_packet                  =   Flipped(Decoupled(new decoded_fetch_packet(coreParameters)))

        // UPDATE //
        //val FU_inputs                  =    Vec(4, Flipped(Decoupled(new FU_output(coreParameters))))   // FIXME: this is temporary
  
        val INT_producers               =   Vec(INT_producer_count, Flipped(Decoupled(new FU_output(coreParameters))))
        val FP_producers                =   if (coreConfig.contains("F")) Some(Vec(FP_producer_count, Flipped(Decoupled(new FU_output(coreParameters))))) else None

        // COMMIT //
        val commit                      =   ValidIO(new commit(coreParameters))

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

    back_index   := back_pointer(pointer_width-2, 0)
    front_index  := front_pointer(pointer_width-2, 0)


    var producers = Seq.empty[DecoupledIO[FU_output]]   // combined list of producers
    producers = producers ++ io.INT_producers ++ io.FP_producers.getOrElse(Seq.empty)




    //////////////////////////
    // ROB INSTRUCTION BANK //
    //////////////////////////
    // WB + uOPs

    val ROB_instruction_banks: Seq[ROB_instruction_bank] = Seq.tabulate(fetchWidth) { w => Module(new ROB_instruction_bank(bank_idx=w)(coreParameters))}

    for(i <- 0 until fetchWidth){
        ROB_instruction_banks(i).io.decoded_insn.valid    := io.ROB_packet.valid
        ROB_instruction_banks(i).io.decoded_insn.bits     := io.ROB_packet.bits.decoded_instruction(i)

        ROB_instruction_banks(i).io.ROB_back_idx          := back_index

        for(j <- 0 until producer_count){
            // FIXME: ready?
            ROB_instruction_banks(i).io.producers(j).bits              :=  producers(j).bits //io.FU_inputs(j).bits 
            ROB_instruction_banks(i).io.producers(j).valid             :=  producers(j).valid //io.FU_inputs(j).valid 
        }

        ROB_instruction_banks(i).io.ROB_front_idx        := front_index
    }
    
    /////////////////////
    // ROB SHARED BANK //
    /////////////////////
    // fetch PC + prediction

    val ROB_shared_bank = Module(new ROB_shared_bank(coreParameters))

    ROB_shared_bank.io.ROB_packet.valid                  := io.ROB_packet.valid
    ROB_shared_bank.io.ROB_packet.bits                   := io.ROB_packet.bits
    //FIXME: rob_packet missing ready

    ROB_shared_bank.io.PC_file_exec_addr <> io.PC_file_exec_addr
    ROB_shared_bank.io.PC_file_exec_data <>  io.PC_file_exec_data

    ROB_shared_bank.io.ROB_back_idx                  := back_index
    ROB_shared_bank.io.ROB_front_idx                 := front_index

    /////////////////////
    // ROB BRANCH BANK //
    /////////////////////
    // Resolved branch data

    val ROB_branch_banks: Seq[ROB_branch_bank] = Seq.tabulate(fetchWidth) { w => Module(new ROB_branch_bank(bank_idx=w)(coreParameters))}

    for(i <- 0 until fetchWidth){
        ROB_branch_banks(i).io.ROB_front_idx                      :=  front_index         
        for(j <- 0 until INT_producer_count){ // FPs dont resolve branches...
            ROB_branch_banks(i).io.INT_producers(j).bits             :=  io.INT_producers(j).bits 
            ROB_branch_banks(i).io.INT_producers(j).valid             :=  io.INT_producers(j).valid 
        }
    }



    /////////////////////////
    // HANDLE CONTROL FLOW //
    /////////////////////////

    // get earliest taken CTRL insn (branch, XRET, etc)
    val CTRL_insn_oh = VecInit(
        ROB_instruction_banks.zipWithIndex.map { case (bank, i) =>
            (bank.io.ROB_instruction_entry.uOp.decoded_insn.CTRL || bank.io.ROB_instruction_entry.uOp.decoded_insn.XRET) &&
            bank.io.ROB_instruction_entry.WB.complete &&
            ROB_branch_banks(i).io.resolved_branch_out.taken &&
            bank.io.ROB_instruction_entry.WB.valid
        }
    )

    dontTouch(CTRL_insn_oh)


    // CSR instructions flush. Hence, get earliest CSRRW
    val CSRRW_insn_oh     =  WireInit(VecInit(ROB_instruction_banks.map(bank =>  bank.io.ROB_instruction_entry.uOp.decoded_insn.CSRRW     && 
                                                                bank.io.ROB_instruction_entry.WB.complete   && 
                                                                bank.io.ROB_instruction_entry.WB.valid)))
    
    // Fences also flush. Hence, get earliest FENCE
    val FENCE_insn_oh     =  WireInit(VecInit(ROB_instruction_banks.map(bank =>  bank.io.ROB_instruction_entry.uOp.decoded_insn.FENCE     && 
                                                                bank.io.ROB_instruction_entry.WB.complete   &&
                                                                bank.io.ROB_instruction_entry.WB.valid) ))
    
    // get any other MISC. flushing insns. 
    val FLUSH_insn_oh     =  WireInit(VecInit(ROB_instruction_banks.map(bank =>  bank.io.ROB_instruction_entry.uOp.decoded_insn.FLUSH     && 
                                                                bank.io.ROB_instruction_entry.WB.complete   &&
                                                                bank.io.ROB_instruction_entry.WB.valid) ))

    // Exceptions also flush. Get earliest excepting insn. 
    val EXCEPTION_insn_oh = WireInit(VecInit(ROB_instruction_banks.map(bank =>   bank.io.ROB_instruction_entry.WB.exception  && 
                                                                bank.io.ROB_instruction_entry.WB.complete   &&
                                                                bank.io.ROB_instruction_entry.WB.valid) ))

    val earliest_CTRL_oh = VecInit(
        (0 until ROB_instruction_banks.length).map { i =>
            CTRL_insn_oh(i) || CSRRW_insn_oh(i) || FENCE_insn_oh(i) || FLUSH_insn_oh(i) || EXCEPTION_insn_oh(i)
        }
    )

    val earliest_CTRL_idx = PriorityEncoder(earliest_CTRL_oh.asUInt)

    // mux out the info for the taken branches
    val earliest_CTRL_insn = WireInit(0.U.asTypeOf(new ROB_instruction_entry(coreParameters)))
    val prediction_earliest_CTRL_insn = WireInit(0.U.asTypeOf(new ROB_instruction_entry(coreParameters)))
    val earliest_CTRL_branch_info = WireInit(0.U.asTypeOf(new ROB_branch_entry(coreParameters)))





    // done with this row
    // this signal increments pointers and helps with interrupts and things
    val row_retire = ROB_instruction_banks.zipWithIndex.map { case (bank, i) =>
        !bank.io.ROB_instruction_entry.WB.valid || 
        (bank.io.ROB_instruction_entry.WB.valid && (bank.io.ROB_instruction_entry.retire || i.U > earliest_CTRL_idx))
    }.reduce(_ && _) && ROB_shared_bank.io.ROB_shared_entry.valid

    val prediction = WireInit(0.U.asTypeOf(new prediction(coreParameters)))
    prediction      := ROB_shared_bank.io.ROB_shared_entry.bits.prediction


    for(i <- 0 until fetchWidth){
        when(earliest_CTRL_idx === i.U){
            earliest_CTRL_insn          := ROB_instruction_banks(i).io.ROB_instruction_entry
            earliest_CTRL_branch_info   := ROB_branch_banks(i).io.resolved_branch_out
        }
        when(prediction.br_mask === i.U){
            prediction_earliest_CTRL_insn          := ROB_instruction_banks(i).io.ROB_instruction_entry
        }
    }

    val output_flush    = WireInit(0.U.asTypeOf(ValidIO(new flush(coreParameters))))
    val expected_next_PC = WireInit(UInt(32.W), 0.U)

    val oldest_insn = PriorityEncoder(VecInit(ROB_instruction_banks.map(bank => bank.io.ROB_instruction_entry.WB.valid)).asUInt)


    expected_next_PC    := ROB_shared_bank.io.ROB_shared_entry.bits.fetch_PC + (4.U * fetchWidth.U)


    io.flush := output_flush

    // FIXME: important! We are transitioning from the weird CSR commit/complete stuff in stores and CSR insns to instrucions ALWAYS requiring a 
    // commit and complete bit to be set for its retirement. If a flush is taking place, re-attempt any unretired instructions(uncompleted but committed) instructions too

    when(earliest_CTRL_oh.reduce(_ || _) && earliest_CTRL_insn.uOp.decoded_insn.CTRL && earliest_CTRL_insn.retire){
        // dominant branch is a typical branch
        // only flush if doesnt match prediction
        expected_next_PC    := earliest_CTRL_branch_info.target_PC
        when((prediction.br_mask === earliest_CTRL_idx) && (prediction.target === earliest_CTRL_branch_info.target_PC) && (prediction.T_NT)){
            // prediction correct, do nothing
        }.otherwise{
            output_flush.valid := 1.B
            output_flush.bits.flushing_PC:= ROB_shared_bank.io.ROB_shared_entry.bits.fetch_PC + (4.U * earliest_CTRL_idx)
            output_flush.bits.redirect_PC:= earliest_CTRL_branch_info.target_PC
            output_flush.bits.is_misprediction := 1.B
        }
    
    }.elsewhen(earliest_CTRL_oh.reduce(_ || _) && earliest_CTRL_insn.WB.exception && oldest_insn === earliest_CTRL_idx){ // exceptions only "trigger" when they are the oldest instruction in the pipeline
        // is an exception
        // flush and jump to MTVEC
        output_flush.valid := 1.B
        output_flush.bits.flushing_PC   := ROB_shared_bank.io.ROB_shared_entry.bits.fetch_PC + (4.U * earliest_CTRL_idx)
        output_flush.bits.redirect_PC   := CSR_port.mtvec.asUInt
        expected_next_PC                := CSR_port.mtvec.asUInt

        output_flush.bits.is_exception  := 1.B
        output_flush.bits.exception_cause := earliest_CTRL_insn.WB.exception_cause
    }.elsewhen(earliest_CTRL_oh.reduce(_ || _) && earliest_CTRL_insn.retire){
        // is a CSRRW, FENCE, FLUSH, or otherwise
        // flush and jump to next insn
        output_flush.valid := 1.B
        output_flush.bits.flushing_PC := ROB_shared_bank.io.ROB_shared_entry.bits.fetch_PC + (4.U * earliest_CTRL_idx)
        output_flush.bits.redirect_PC := ROB_shared_bank.io.ROB_shared_entry.bits.fetch_PC + (4.U * earliest_CTRL_idx) + 4.U

        expected_next_PC              := ROB_shared_bank.io.ROB_shared_entry.bits.fetch_PC + (4.U * earliest_CTRL_idx) + 4.U

        output_flush.bits.is_fence    := earliest_CTRL_insn.uOp.decoded_insn.FENCE
        output_flush.bits.is_CSR      := earliest_CTRL_insn.uOp.decoded_insn.CSRRW
    }.elsewhen(earliest_CTRL_oh.reduce(_ || _) === 0.B && prediction_earliest_CTRL_insn.retire){    // no taken branch (make sure frontend agrees/agreed)

        when(prediction.T_NT){ // if you predicted taken
            // flush to the instruction after the incorrectly predicted one
            output_flush.valid := 1.B
            output_flush.bits.flushing_PC := ROB_shared_bank.io.ROB_shared_entry.bits.fetch_PC + (prediction.br_mask*4.U) //(4.U * earliest_CTRL_idx)
            output_flush.bits.redirect_PC :=  ROB_shared_bank.io.ROB_shared_entry.bits.fetch_PC + prediction.br_mask*4.U + 4.U  // re-execute incorrectly speculated instruction
            output_flush.bits.is_misprediction := 1.B
        }

    }

    dontTouch(prediction_earliest_CTRL_insn)

    
    // ASSIGN FLUSH //
    ROB_instruction_banks.foreach { bank => bank.io.flush := output_flush }

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

        cVec(0) := entries(0).commit

        for (i <- 1 until fetchWidth) {
            val prevValid      = entries(i-1).WB.valid
            val prevComplete   = entries(i-1).WB.complete
            val prevCommittedOrCommitting = entries(i-1).WB.committed || committing(i-1)

            cVec(i) :=  entries(i).WB.valid          &&        // insn is valid
                        !entries(i).WB.committed     &&        // insn not already committed
                        (entries(i).commit)           &&       // insn should commit (already complete or completes after commit)
                        (!prevValid || (prevComplete && prevCommittedOrCommitting)) &&                                          // prev insn has committed or is committing
                        i.U <= earliest_CTRL_idx &&                                                                             // only commit up to commit point 
                        !EXCEPTION_insn_oh(i)                                                                                   // don't commit exceptions
        }
        cVec
    }

    val retire_vec = {
        val entries = ROB_instruction_banks.map(_.io.ROB_instruction_entry)
        val rVec = WireInit(VecInit(Seq.fill(fetchWidth)(false.B)))
        for (i <- 0 until fetchWidth) {rVec(i) :=  entries(i).WB.valid && entries(i).retire}
        rVec
    }

    // Drive the commit signal for each instruction bank
    for (i <- 0 until fetchWidth) {
        ROB_instruction_banks(i).io.commit := commit_vec(i)
        ROB_instruction_banks(i).io.retire := retire_vec(i)
    }


    
    // DRIVE I/O COMMIT //
    io.commit.bits := DontCare // FIXME: complete assignment particularly for branches

    io.commit.bits.fetch_PC  := ROB_shared_bank.io.ROB_shared_entry.bits.fetch_PC
    io.commit.bits.GHR  := ROB_shared_bank.io.ROB_shared_entry.bits.GHR
    io.commit.bits.target    := earliest_CTRL_branch_info.target_PC
    

    io.commit.bits.br_type    :=  Mux(earliest_CTRL_insn.uOp.decoded_insn.CTRL, br_type_t.BR, br_type_t.NONE)  // FIXME: actually encode branches


    io.commit.bits.br_mask    :=  earliest_CTRL_idx
    io.commit.bits.ROB_index := front_index

    for(i <- 0 until fetchWidth){
        io.commit.bits.insn_commit(i).valid          := ROB_instruction_banks(i).io.ROB_instruction_entry.WB.valid  

        io.commit.bits.insn_commit(i).bits.WB_committed := ROB_instruction_banks(i).io.ROB_instruction_entry.WB.committed
        io.commit.bits.insn_commit(i).bits.WB_complete := ROB_instruction_banks(i).io.ROB_instruction_entry.WB.complete

        io.commit.bits.insn_commit(i).bits.MOB_index := ROB_instruction_banks(i).io.ROB_instruction_entry.uOp.decoded_insn.MOB_index
        io.commit.bits.insn_commit(i).bits.MOB_valid := ROB_instruction_banks(i).io.ROB_instruction_entry.uOp.decoded_insn.MOB_valid
        io.commit.bits.insn_commit(i).bits.RD        := ROB_instruction_banks(i).io.ROB_instruction_entry.uOp.decoded_insn.RD
        io.commit.bits.insn_commit(i).bits.RD_valid  := ROB_instruction_banks(i).io.ROB_instruction_entry.uOp.decoded_insn.RD_valid
        io.commit.bits.insn_commit(i).bits.PRD       := ROB_instruction_banks(i).io.ROB_instruction_entry.uOp.decoded_insn.PRD
        io.commit.bits.insn_commit(i).bits.PRDold    := ROB_instruction_banks(i).io.ROB_instruction_entry.uOp.decoded_insn.PRDold
    }

    // ASSIGN commit T_NT
    io.commit.bits.T_NT := ROB_instruction_banks.zip(ROB_branch_banks)
    .map { case (insn_bank, branch_bank) =>
        insn_bank.io.ROB_instruction_entry.WB.committed && insn_bank.io.ROB_instruction_entry.uOp.decoded_insn.CTRL && branch_bank.io.resolved_branch_out.taken
    }.reduce(_ || _) && ROB_shared_bank.io.ROB_shared_entry.valid


    io.commit.valid := ROB_instruction_banks.map(bank =>   bank.io.ROB_instruction_entry.WB.valid).reduce(_ || _) && ROB_shared_bank.io.ROB_shared_entry.valid   // output commit is high if any instructions are committing




    when(io.flush.valid){
        front_pointer := 0.U
        back_pointer  := 0.U
    }.otherwise{
        front_pointer := front_pointer + row_retire
        back_pointer  := back_pointer + io.ROB_packet.fire
    }

    ROB_shared_bank.io.commit_row                       := row_retire
    ROB_shared_bank.io.flush                            := output_flush.valid

    //////////////////
    // ASSIGN READY //
    //////////////////

    // Compress ready bits for each instruction bank
    val instruction_bank_FU_output_ready = VecInit(
        (0 until portCount).map { i =>
            ROB_instruction_banks.map(_.io.producers(i).ready).reduce(_ && _)
        }
    )

    // Compress ready bits for each branch bank
    val branch_bank_FU_output_ready = VecInit(
        (0 until portCount).map { i =>
            ROB_branch_banks.map(_.io.INT_producers(i).ready).reduce(_ && _)
        }
    )

    // Compute the final FU output ready bits as the AND of both
    val FU_ready_bits = VecInit(
        (0 until portCount).map { i =>
            instruction_bank_FU_output_ready(i) && branch_bank_FU_output_ready(i)
        }
    )

    // Assign each bit to the corresponding element in io.FU_inputs.ready
    for (i <- 0 until INT_producer_count) {
        io.INT_producers(i).ready := 1.B //FU_ready_bits(i)
    }

    if(coreConfig.contains("F")){
        for (i <- 0 until FP_producer_count) {
            io.FP_producers.get(i).ready := 1.B //FU_ready_bits(i)
        }
    }

    io.ROB_packet.ready := ROB_shared_bank.io.ROB_packet.ready && ROB_instruction_banks.map(_.io.decoded_insn.ready).reduce(_ && _)



    ///////////////
    // INTERRUPT //
    ///////////////
    
    when(CSR_port.interrupt && row_retire){ 
        // on interrupt, jump to mtvec
        // set PC to the next instruction that would have committed
        output_flush    := 0.U.asTypeOf(ValidIO(new flush(coreParameters)))
        output_flush.valid := 1.B

        output_flush.bits.flushing_PC := expected_next_PC
        output_flush.bits.redirect_PC := CSR_port.mtvec.asUInt
        output_flush.bits.is_interrupt := 1.B
    }


    ////////////////////
    // GENERATE TRACE //
    ////////////////////
    // print data for each committing instruction //

    if(DEBUG){
        for(i <- 0 until fetchWidth){
            val instruction_PC  = ROB_shared_bank.io.ROB_shared_entry.bits.fetch_PC + (i*4).U

            val arch_RD         = ROB_instruction_banks(i).io.ROB_instruction_entry.uOp.decoded_insn.RD
            val arch_RD_valid   = ROB_instruction_banks(i).io.ROB_instruction_entry.uOp.decoded_insn.RD_valid
            val PRD             = ROB_instruction_banks(i).io.ROB_instruction_entry.uOp.decoded_insn.PRD
            val RD_data         = ROB_instruction_banks(i).io.ROB_instruction_entry.WB.RD_data.get

            val IS_STORE        = ROB_instruction_banks(i).io.ROB_instruction_entry.uOp.decoded_insn.STORE
            val IS_LOAD         = ROB_instruction_banks(i).io.ROB_instruction_entry.uOp.decoded_insn.LOAD
            val IS_CSRRW        = ROB_instruction_banks(i).io.ROB_instruction_entry.uOp.decoded_insn.CSRRW
            val IS_CTRL         = ROB_instruction_banks(i).io.ROB_instruction_entry.uOp.decoded_insn.CTRL

            val done            = ROB_shared_bank.io.ROB_shared_entry.valid && ROB_instruction_banks(i).io.ROB_instruction_entry.WB.committed && (ROB_instruction_banks(i).io.ROB_instruction_entry.WB.complete || IS_STORE) && ROB_instruction_banks(i).io.ROB_instruction_entry.WB.valid

            
            // FIXME: ADD STORES AND EXCEPTIONS
            // ALSO MAYBE INTERRUPTS
            when(done && IS_STORE){
                //printf("core   0: 3 0x%x mem[0x%0x] = 0x%x\n", instruction_PC, arch_RD, RD_data);
                //printf("core   0: 3 0x%x mem[0x%x] = 0x%x\n", instruction_PC, RD_data, PRD)
                printf("core   0: 3 0x%x STORE ???\n", instruction_PC)
            }.elsewhen(done && IS_LOAD){
                printf("core   0: 3 0x%x 0x%d = 0x%x | mem[???]\n", instruction_PC, arch_RD, RD_data)
            }.elsewhen(done && IS_CSRRW){
                //printf();
                val CSR_addr =  ROB_instruction_banks(i).io.ROB_instruction_entry.uOp.decoded_insn.CSR_addr

                printf("core   0: 3 0x%x", instruction_PC);
                //printf(cf"core   0: 3 0x$instruction_PC");
                printf("CSR 0x%x", CSR_addr)
                //printf(cf"CSR 0x$CSR_addr")

                // TODO add CSR W (RS1)
                //when(CSRW){
                    //printf("core   0: 3 0x%x x%d 0x%x\n", arch_RD, RD_data);
                //}

                printf("\n");

            }.elsewhen(done && IS_CTRL){
                printf("core   0: 3 0x%x CTRL \n", instruction_PC);
            }.elsewhen(done && arch_RD_valid && arch_RD =/= 0.U){  // "normal" PRD modifying insn
                printf("core   0: 3 0x%x x%d 0x%x\n", instruction_PC, arch_RD, RD_data);
            }.elsewhen(done){    // something else with no PRD
                printf("core   0: 3 0x%x\n", instruction_PC)
            }

        }
    }


    dontTouch(expected_next_PC)
    dontTouch(earliest_CTRL_insn)
    dontTouch(prediction)

    //dontTouch(earliest_CTRL_idx)
    //dontTouch(earliest_CTRL_branch_info)
    //dontTouch(CSRRW_insn_oh)
    //dontTouch(FENCE_insn_oh)
    //dontTouch(FLUSH_insn_oh)
    //dontTouch(EXCEPTION_insn_oh)
    //dontTouch(earliest_CTRL_oh)


}
