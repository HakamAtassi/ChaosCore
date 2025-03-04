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

        // COMMIT // 
        val commit                      =   Flipped(ValidIO(new commit(coreParameters)))

        // PC_file access (for branch unit)
        val PC_file_exec_addr           =   Vec(branchPortCount, Output(UInt(log2Ceil(ROBEntries).W)))
        val PC_file_exec_data           =   Vec(branchPortCount, Input(UInt(32.W)))

        // ALLOCATE //
        val fetch_PC                    =   Input(UInt(32.W))  // DEBUG
        val backend_packet              =   Vec(fetchWidth, Flipped(Decoupled(new decoded_instruction(coreParameters))))


        val MOB_output                  =   Decoupled(new FU_output(coreParameters))                                               // broadcast load data

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
    val INT_RS: Seq[age_RS] = Seq.tabulate(nonMemoryPortCount) { w => Module(new age_RS(coreParameters))}  // init distributed reservation stations for int operations
    val MEM_RS              = Module(new age_RS(coreParameters))

    /////////
    // MOB //
    /////////
    val MOB   =  Module(new simple_MOB(coreParameters))

    //////////////
    // ALLOCATE //
    //////////////

    val backend_can_allocate =  MEM_RS.io.backend_packet.map(_.ready).reduce(_ && _) &&     // mem RS ready
                                INT_RS.map(_.io.backend_packet.map(_.ready).reduce(_ && _)).reduce(_ && _) &&     // all INT RS ready
                                MOB.io.reserve.map(_.ready).reduce(_ && _)                  // MOB ready
    
    for (i <- 0 until fetchWidth){
        io.backend_packet(i).ready        := backend_can_allocate
    }

    // allocate RS entries
    // reservation stations only allocate instructions if they correspond to that port
    for (i <- 0 until nonMemoryPortCount){
        for(j <- 0 until fetchWidth){
            INT_RS(i).io.backend_packet(j).bits   := io.backend_packet(j).bits
            INT_RS(i).io.backend_packet(j).valid  := io.backend_packet(j).valid && io.backend_packet(j).bits.assigned_port === i.U
        }
    }

    // MEMRS //
    for(i <- 0 until fetchWidth){
        MEM_RS.io.backend_packet(i).bits   := io.backend_packet(i).bits
        MEM_RS.io.backend_packet(i).valid  := io.backend_packet(i).valid && io.backend_packet(i).bits.assigned_port === (portCount-1).U // AGU unit defined to be last FU
    }


    // reserve mem ops
    for (i <- 0 until fetchWidth){
        MOB.io.reserve(i).bits     := io.backend_packet(i).bits
        MOB.io.reserve(i).valid    := io.backend_packet(i).bits.needs_MEM_RS && io.backend_packet(i).valid
    }
    
    // inform MEM_RS about location of allocated entries for mem ops for AGU WB
    for(i <- 0 until fetchWidth){
        MEM_RS.io.backend_packet(i).bits.MOB_index := MOB.io.reserved_pointers(i).bits
    }



    ///////////////////////////
    // REGISTER FILES (READ) //
    ///////////////////////////
    val INT_PRF = Module(new nReadmWriteLVT(n=portCount*2, m=portCount, depth=physicalRegCount, width=32))

    if(coreConfig.contains("F")){
        // TODO
    }

    ///////////////////////
    // EXECUTION ENGINES //
    ///////////////////////

    val execution_engine = Module(new execution_engine(coreParameters))
    // NOTE: EX. UNITS ARE ALWAYS STRUCTURED AS [ALU, ALU, ALU, ALU, MEM, MEM, ...]
    // That is, first come arithmetic units, then branch units. 
    // Which may explain the structure of this code. 

    val read_decoded_instructions   =   Wire(Vec(portCount, new read_decoded_instruction(coreParameters)))

    // CONNECT NON-MEMORY FUs to Reg Read
    for(i <- 0 until nonMemoryPortCount){
        // RS <> PRF //
        INT_PRF.io.raddr(i*2)       := INT_RS(i).io.RF_inputs.bits.RS1
        INT_PRF.io.raddr(i*2+1)     := INT_RS(i).io.RF_inputs.bits.RS2

        // PRF <> instr //
        read_decoded_instructions(i).RS1_data := INT_PRF.io.rdata(i*2)
        read_decoded_instructions(i).RS2_data := INT_PRF.io.rdata(i*2+1)


        // FWD instruction //
        read_decoded_instructions(i).decoded_instruction := RegNext(INT_RS(i).io.RF_inputs.bits)
        execution_engine.io.FU_input(i).valid            := RegNext(INT_RS(i).io.RF_inputs.valid)
        execution_engine.io.FU_input(i).bits             <> read_decoded_instructions(i)
        
        // RS ready <> FU ready //
        INT_RS(i).io.RF_inputs.ready        := execution_engine.io.FU_input(i).ready
    }


    // CONNECT BRANCH UNITS TO PC FILE (in ROB)
    for (i <- 0 until portCount) {
        read_decoded_instructions(i).fetch_PC := DontCare
        if (FUParamSeq(i).supportsBranch) {
            val PC_file_port_index = FUParamSeq.take(i).count(_.supportsBranch)
            io.PC_file_exec_addr(PC_file_port_index) := INT_RS(i).io.RF_inputs.bits.ROB_index
            execution_engine.io.FU_input(i).bits.fetch_PC := io.PC_file_exec_data(PC_file_port_index)
        }
    }


    // CONNECT MEMORY FUs TO REG READ
    for(i <- nonMemoryPortCount until portCount){
        // RS <> PRF //
        INT_PRF.io.raddr(i*2)       := MEM_RS.io.RF_inputs.bits.RS1
        INT_PRF.io.raddr(i*2+1)     := MEM_RS.io.RF_inputs.bits.RS2

        // PRF <> instr //
        read_decoded_instructions(i).RS1_data := INT_PRF.io.rdata(i*2)
        read_decoded_instructions(i).RS2_data := INT_PRF.io.rdata(i*2+1)

        // FWD instruction //
        read_decoded_instructions(i).decoded_instruction := RegNext(MEM_RS.io.RF_inputs.bits)
        execution_engine.io.FU_input(i).valid            := RegNext(MEM_RS.io.RF_inputs.valid)
        execution_engine.io.FU_input(i).bits             <> read_decoded_instructions(i)
        
        // RS ready <> FU ready //
        MEM_RS.io.RF_inputs.ready        := execution_engine.io.FU_input(i).ready
    }


    // CONNECT EX. ENGINE TO PRF WB (ALUs)
    for(i <- 0 until nonMemoryPortCount){
        // FU data <> PRF (WB) //
        INT_PRF.io.waddr(i)  :=    execution_engine.io.FU_output(i).bits.PRD
        INT_PRF.io.wen(i)    :=    execution_engine.io.FU_output(i).valid && execution_engine.io.FU_output(i).bits.RD_valid
        INT_PRF.io.wdata(i)  :=    execution_engine.io.FU_output(i).bits.RD_data

        // INTRS RS1/RS2 //
        for(RS_index <- 0 until nonMemoryPortCount){
            INT_RS(RS_index).io.FU_outputs(i) <> execution_engine.io.FU_output(i)
        }

        // MEMRS RS1/RS2 //
        MEM_RS.io.FU_outputs(i) <> execution_engine.io.FU_output(i)

        io.FU_outputs(i) <> execution_engine.io.FU_output(i)
    }


    // CONNECT EX. ENGINE TO MOB
    for(i <- nonMemoryPortCount until portCount){
        // THIS LOOP WILL ONLY EVER RUN FOR ONE ITERATION
        MOB.io.AGU_output <> execution_engine.io.FU_output(i)  // FIXME add param number of AGU inputs to MOB

        INT_PRF.io.waddr(i)  :=  MOB.io.MOB_output.bits.PRD 
        INT_PRF.io.wen(i)    :=  MOB.io.MOB_output.bits.RD_valid && MOB.io.MOB_output.valid 
        INT_PRF.io.wdata(i)  :=  MOB.io.MOB_output.bits.RD_data

        // INTRS RS1/RS2 //
        for(RS_index <- 0 until nonMemoryPortCount){
            INT_RS(RS_index).io.FU_outputs(i) <> MOB.io.MOB_output
        }

        // MEMRS RS1/RS2 //
        MEM_RS.io.FU_outputs(i) <> MOB.io.MOB_output

        io.FU_outputs(i)        <> MOB.io.MOB_output
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


    ////////////
    // COMMIT //
    ////////////
    execution_engine.io.commit           <> io.commit
    MOB.io.commit                        <> io.commit
    MEM_RS.io.commit                     <> io.commit
    INT_RS.foreach(_.io.commit <> io.commit)

    ///////////
    // FLUSH //
    ///////////

    INT_RS.foreach(_.io.flush <> io.flush)
    MEM_RS.io.flush <> io.flush
    MOB.io.flush    <> io.flush

    execution_engine.io.flush       <>  io.flush

    //////////
    // MISC //
    //////////

    io.reserved_pointers            <>  MOB.io.reserved_pointers
    io.backend_memory_request       <>  MOB.io.backend_memory_request
    io.backend_memory_response      <>  MOB.io.backend_memory_response

}
