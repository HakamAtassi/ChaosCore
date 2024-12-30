/* ------------------------------------------------------------------------------------
* Filename: RF.scala
* Author: Hakam Atassi
* Date: May 23 2024
* Description: The top leve of the backend. Includes everything from allocation to register writeback.
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

// Backend Operation:
// Recives fetchWidth decoded and renamed instructions from the frontend
// Allocates the instructions into the corresponding reservation stations (ROB exists externally)
// When instructions are scheduled, they go through the Register Read stage. Their position in the RS is also cleared.
//      This stage reads RS1, RS2, and PC data from the register files
// The read instructions are then passed to their scheduled execution engines
// Once executed, the computed data is broadcasted to the RS and written to the PRF



class backend(coreParameters:CoreParameters) extends Module{
    import coreParameters._
    val portCount = getPortCount(coreParameters)
    val branchPortCount = getBranchPortCount(coreParameters)
    val memoryPortCount = FUParamSeq.count(_.supportsAddressGeneration)
    val nonMemoryPortCount = portCount - memoryPortCount 

    val io = IO(new Bundle{
        // FLUSH //
        val flush                       =   Flipped(ValidIO(new flush(coreParameters)))

        // pointers to MOB entries for updating later
        val reserved_pointers           =   Vec(fetchWidth, ValidIO(UInt(log2Ceil(MOBEntries).W)))                               // pointer to allocated entry

        val backend_memory_response     =   Flipped(Decoupled(new backend_memory_response(coreParameters))) // From MEM
        val backend_memory_request      =   Decoupled(new backend_memory_request(coreParameters))     // To MEM



        // REDIRECTS // 
        val commit                      =   Flipped(ValidIO(new commit(coreParameters)))

        // PC_file access (for branch unit)
        val PC_file_exec_addr           =   Vec(branchPortCount, Output(UInt(log2Ceil(ROBEntries).W)))
        val PC_file_exec_data           =   Vec(branchPortCount, Input(UInt(32.W)))

        // ALLOCATE //
        val fetch_PC                    =   Input(UInt(32.W))  // DEBUG
        val backend_packet              =   Vec(fetchWidth, Flipped(Decoupled(new decoded_instruction(coreParameters))))


        val MOB_output                  =   Decoupled(new FU_output(coreParameters))                                               // broadcast load data

        //val mtvec = Output(UInt(32.W))
        ////////////////
        // INTERRUPTS //
        ////////////////

        // ibex naming convention
        val irq_software_i                      = Input(Bool())      //msip
        val irq_timer_i                         = Input(Bool())      //mtip
        val irq_external_i                      = Input(Bool())      //meip
        val debug_req_i                         = Input(Bool())      //debug
        val irq_nm_i                            = Input(Bool())      //nmi


        // UPDATE //
        val FU_outputs                  =   Vec(portCount, Decoupled(new FU_output(coreParameters)))
    }); dontTouch(io)


    val CSR_port = IO(Output(new CSR_out(coreParameters)))




    //////////////////////////
    // RESERVATION STATIONS //
    //////////////////////////

    val INT_RS   =  Module(new RS(coreParameters, INTRSPortCount, "INT"))
    val MEM_RS   =  Module(new RS(coreParameters, MEMRSPortCount, "MEM"))


    /////////
    // MOB //
    /////////
    val MOB   =  Module(new simple_MOB(coreParameters))

    ///////////////////////////
    // SCHEDULE INSTRUCTIONS //
    ///////////////////////////

    val backend_can_allocate = MEM_RS.io.backend_packet.map(_.ready).reduce(_ && _) && INT_RS.io.backend_packet.map(_.ready).reduce(_ && _) && MOB.io.reserve.map(_.ready).reduce(_ && _)
    
    for (i <- 0 until fetchWidth){
        io.backend_packet(i).ready        := backend_can_allocate
    }

    // INT RS //
    for (i <- 0 until fetchWidth){
        INT_RS.io.backend_packet(i).bits   := io.backend_packet(i).bits  // pass data along
        INT_RS.io.backend_packet(i).valid  := io.backend_packet(i).bits.needs_INT_RS && io.backend_packet(i).valid
    }

    INT_RS.io.commit <> io.commit

    MEM_RS.io.commit <> io.commit

    dontTouch(io)
    dontTouch(io.backend_packet)



    for (i <- 0 until fetchWidth){
        val needs_MEM_RS = io.backend_packet(i).bits.needs_memory

        MEM_RS.io.backend_packet(i).bits     := io.backend_packet(i).bits  // pass data along
        MEM_RS.io.backend_packet(i).valid    := io.backend_packet(i).bits.needs_MEM_RS && io.backend_packet(i).valid
    }

    MOB.io.commit <> io.commit
    for (i <- 0 until fetchWidth){
        MOB.io.reserve(i).bits     := io.backend_packet(i).bits  // pass data along
        MOB.io.reserve(i).valid    := io.backend_packet(i).bits.needs_MEM_RS && io.backend_packet(i).valid
    }
    

    // ASSIGN MOB POINTERS FOR MEMRS //
    for(i <- 0 until fetchWidth){
        MEM_RS.io.backend_packet(i).bits.MOB_index := MOB.io.reserved_pointers(i).bits
    }


    ///////////////////////////
    // REGISTER FILES (READ) //
    ///////////////////////////

    val INT_PRF = Module(new sim_nReadmWrite(coreParameters))
    //val INT_PRF = Module(new nReadmWriteLVT(n=portCount*2, m=portCount, depth=physicalRegCount, width=32))    //FIXME: currently exposes an issue in the ROB


    val read_decoded_instructions   =   Wire(Vec(portCount, new read_decoded_instruction(coreParameters)))

    ///////////////////////
    // EXECUTION ENGINES //
    ///////////////////////

    val execution_engine = Module(new execution_engine(coreParameters))
    // NOTE: EX. UNITS ARE ALWAYS STRUCTURED AS [ALU, ALU, ALU, ALU, MEM, MEM, ...]
    // That is, first come arithmetic units, then branch units. 
    // Which may explain the structure of this code. 

    // CONNECT NON-MEMORY FUs to Reg Read
    for(i <- 0 until nonMemoryPortCount){
        // RS <> PRF //
        INT_PRF.io.raddr(i*2)       := INT_RS.io.RF_inputs(i).bits.RS1
        INT_PRF.io.raddr(i*2+1)     := INT_RS.io.RF_inputs(i).bits.RS2

        // PRF <> instr //
        read_decoded_instructions(i).RS1_data := INT_PRF.io.rdata(i*2)
        read_decoded_instructions(i).RS2_data := INT_PRF.io.rdata(i*2+1)


        // FWD instruction //
        read_decoded_instructions(i).decoded_instruction := RegNext(INT_RS.io.RF_inputs(i).bits)
        execution_engine.io.FU_input(i).valid            := RegNext(INT_RS.io.RF_inputs(i).valid)
        execution_engine.io.FU_input(i).bits             <> read_decoded_instructions(i)
        
        // RS ready <> FU ready //
        INT_RS.io.RF_inputs(i).ready        := execution_engine.io.FU_input(i).ready

    }

    // CONNECT BRANCH UNITS TO PC FILE (in ROB)
    for (i <- 0 until portCount) {
        read_decoded_instructions(i).fetch_PC := DontCare
        if (FUParamSeq(i).supportsBranch) {
            val PC_file_port_index = FUParamSeq.take(i).count(_.supportsBranch)
            io.PC_file_exec_addr(PC_file_port_index) := INT_RS.io.RF_inputs(i).bits.ROB_index
            read_decoded_instructions(i).fetch_PC := io.PC_file_exec_data(PC_file_port_index)
        }
    }


    // CONNECT MEMORY FUs TO REG READ
    for(i <- nonMemoryPortCount until portCount){
        // RS <> PRF //
        INT_PRF.io.raddr(i*2)       := MEM_RS.io.RF_inputs(i-nonMemoryPortCount).bits.RS1
        INT_PRF.io.raddr(i*2+1)     := MEM_RS.io.RF_inputs(i-nonMemoryPortCount).bits.RS2

        // PRF <> instr //
        read_decoded_instructions(i).RS1_data := INT_PRF.io.rdata(i*2)
        read_decoded_instructions(i).RS2_data := INT_PRF.io.rdata(i*2+1)

        // FWD instruction //
        read_decoded_instructions(i).decoded_instruction := RegNext(MEM_RS.io.RF_inputs(i-nonMemoryPortCount).bits)
        execution_engine.io.FU_input(i).valid            := RegNext(MEM_RS.io.RF_inputs(i-nonMemoryPortCount).valid)
        execution_engine.io.FU_input(i).bits             <> read_decoded_instructions(i)
        
        // RS ready <> FU ready //
        MEM_RS.io.RF_inputs(i-nonMemoryPortCount).ready        := execution_engine.io.FU_input(i).ready
    }

    // CONNECT EX. ENGINE TO WB (ALUs)
    for(i <- 0 until nonMemoryPortCount){
        // FU data <> PRF (WB) //
        INT_PRF.io.waddr(i)  :=    execution_engine.io.FU_output(i).bits.PRD
        INT_PRF.io.wen(i)    :=    execution_engine.io.FU_output(i).valid && execution_engine.io.FU_output(i).bits.RD_valid
        INT_PRF.io.wdata(i)  :=    execution_engine.io.FU_output(i).bits.RD_data

        // RS <> RD complete/ready //
        INT_RS.io.FU_outputs(i) <> execution_engine.io.FU_output(i)
        MEM_RS.io.FU_outputs(i) <> execution_engine.io.FU_output(i)

        io.FU_outputs(i) <> execution_engine.io.FU_output(i)
    }

    // CONNECT EX. ENGINE TO MOB
    for(i <- nonMemoryPortCount until portCount){
        // THIS LOOP WILL ONLY EVER RUN ONCE
        MOB.io.AGU_output(i-nonMemoryPortCount) <> execution_engine.io.FU_output(i)  // FIXME add param number of AGU inputs to MOB

        INT_PRF.io.waddr(i)  :=  MOB.io.MOB_output.bits.PRD 
        INT_PRF.io.wen(i)    :=  MOB.io.MOB_output.bits.RD_valid && MOB.io.MOB_output.valid 
        INT_PRF.io.wdata(i)  :=  MOB.io.MOB_output.bits.RD_data

        // FIXME: this is a bit weird
        // Basically, the AGU only generates an address. this address goes to the MOB. Thats it. 
        // In other words, the AGU (of which many may exist based on config) (which lives in the exeuction engine) doesnt actually resolve any dependancies
        // the output of the MOB, which is currently fixed to 1, is what actually writes to the reg file, ROB, and reservation stations to resolve/wakeup insns. 

        INT_RS.io.FU_outputs(i) <> MOB.io.MOB_output //execution_engine.io.FU_output(i)
        MEM_RS.io.FU_outputs(i) <> MOB.io.MOB_output //execution_engine.io.FU_output(i)
        io.FU_outputs(i)        <> MOB.io.MOB_output

    }



    execution_engine.io.commit           <> io.commit

    MOB.io.commit <> io.commit
    for (i <- 0 until fetchWidth){
        MOB.io.reserve(i).bits     := io.backend_packet(i).bits  // pass data along
        MOB.io.reserve(i).valid    := io.backend_packet(i).bits.needs_MEM_RS && io.backend_packet(i).valid
    }
    
    ////////////////
    // INTERRUPTS //
    ////////////////
    execution_engine.io.irq_software_i                 := io.irq_software_i    
    execution_engine.io.irq_timer_i                    := io.irq_timer_i
    execution_engine.io.irq_external_i                 := io.irq_external_i
    execution_engine.io.debug_req_i                    := io.debug_req_i
    execution_engine.io.irq_nm_i                       := io.irq_nm_i
    

    // Output CSR_port values
    execution_engine.CSR_port <> CSR_port

    ////////////////
    // AGU <> MOB //
    ////////////////
    MOB.io.fetch_PC <> io.fetch_PC
    io.MOB_output   <> MOB.io.MOB_output   // this updates reg status etc...


    ///////////
    // FLUSH //
    ///////////

    INT_RS.io.flush <> io.flush
    MEM_RS.io.flush <> io.flush
    MOB.io.flush    <> io.flush

    execution_engine.io.flush       <>  io.flush
    io.reserved_pointers            <>  MOB.io.reserved_pointers
    io.backend_memory_request       <>  MOB.io.backend_memory_request
    io.backend_memory_response      <>  MOB.io.backend_memory_response

}
