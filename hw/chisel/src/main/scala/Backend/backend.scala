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

    val io = IO(new Bundle{
        // FLUSH //
        val flush                       =   Flipped(ValidIO(new flush(coreParameters)))

        // pointers to MOB entries for updating later
        val reserved_pointers           =   Vec(fetchWidth, ValidIO(UInt(log2Ceil(MOBEntries).W)))                               // pointer to allocated entry

        val backend_memory_response     =   Flipped(Decoupled(new backend_memory_response(coreParameters))) // From MEM
        val backend_memory_request      =   Decoupled(new backend_memory_request(coreParameters))     // To MEM

        // REDIRECTS // 
        val commit                      =   Flipped(ValidIO(new commit(coreParameters)))
        val partial_commit              =   Input(new partial_commit(coreParameters))

        // PC_file access (for branch unit)
        val PC_file_exec_addr           =   Output(UInt(log2Ceil(ROBEntries).W))
        val PC_file_exec_data           =   Input(UInt(32.W))

        // ALLOCATE //
        val fetch_PC                    =   Input(UInt(32.W))  // DEBUG
        val backend_packet              =   Vec(fetchWidth, Flipped(Decoupled(new decoded_instruction(coreParameters))))


        val MOB_output                  =   ValidIO(new FU_output(coreParameters))                                               // broadcast load data

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
        val FU_outputs                  =   Vec(portCount, ValidIO(new FU_output(coreParameters)))
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
    INT_RS.io.partial_commit <> io.partial_commit

    MEM_RS.io.commit <> io.commit
    MEM_RS.io.partial_commit <> io.partial_commit

    dontTouch(io)
    dontTouch(io.backend_packet)



    for (i <- 0 until fetchWidth){
        val needs_MEM_RS = io.backend_packet(i).bits.needs_memory

        MEM_RS.io.backend_packet(i).bits     := io.backend_packet(i).bits  // pass data along
        MEM_RS.io.backend_packet(i).valid    := io.backend_packet(i).bits.needs_MEM_RS && io.backend_packet(i).valid
    }

    MOB.io.commit <> io.commit
    MOB.io.partial_commit <> io.partial_commit
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
    //val INT_PRF = Module(new nReadmWriteLVT(n=portCount*2, m=portCount, depth=physicalRegCount, width=32))    // currently exposes an issue in the ROB


    val read_decoded_instructions   =   Wire(Vec(portCount, new read_decoded_instruction(coreParameters)))


    ///////////////////////
    // EXECUTION ENGINES //
    ///////////////////////

    //MEM_RS.io.RF_inputs(0).ready       := 0.B   //FIXME: parameterize this

    val execution_engine = Module(new execution_engine(coreParameters))

    //portedFUParamSeq.map(println)

    for(i <- 0 until portCount){
        val RS_port     = portedFUParamSeq(i).INTRS_MEMRS_port
        val RS1_index   = portedFUParamSeq(i).RS1_RS2_indices(0)
        val RS2_index   = portedFUParamSeq(i).RS1_RS2_indices(1)
        val PRFRD       = portedFUParamSeq(i).PRFRD

        if(portedFUParamSeq(i).is_INTFU){
            // RS <> PRF //
            INT_PRF.io.raddr(RS1_index)     := INT_RS.io.RF_inputs(RS_port).bits.RS1
            INT_PRF.io.raddr(RS2_index)     := INT_RS.io.RF_inputs(RS_port).bits.RS2

            // PRF <> instr //
            read_decoded_instructions(i).RS1_data := INT_PRF.io.rdata(RS1_index)
            read_decoded_instructions(i).RS2_data := INT_PRF.io.rdata(RS2_index)
            read_decoded_instructions(i).fetch_PC := io.PC_file_exec_data   // branch unit  FIXME: this needs to be extended to have multiple fetch_PC ports in the ROB

            // FWD instruction //
            read_decoded_instructions(i).decoded_instruction := RegNext(INT_RS.io.RF_inputs(RS_port).bits)
            
            // RS ready <> FU ready //
            INT_RS.io.RF_inputs(RS_port).ready        := execution_engine.io.FU_input(i).ready

            // FU data <> PRF //
            INT_PRF.io.waddr(PRFRD)  :=    execution_engine.io.FU_output(i).bits.PRD
            INT_PRF.io.wen(PRFRD)    :=    execution_engine.io.FU_output(i).valid && execution_engine.io.FU_output(i).bits.RD_valid
            INT_PRF.io.wdata(PRFRD)  :=    execution_engine.io.FU_output(i).bits.RD_data


            // RS <> RD complete/ready //
            INT_RS.io.FU_outputs(i) := execution_engine.io.FU_output(i)
            MEM_RS.io.FU_outputs(i) := execution_engine.io.FU_output(i)

            execution_engine.io.FU_input(i).valid           := RegNext(INT_RS.io.RF_inputs(RS_port).valid)

        }
        else if(portedFUParamSeq(i).is_MEMFU){
            // RS <> PRF //
            INT_PRF.io.raddr(RS1_index)     :=    MEM_RS.io.RF_inputs(RS_port).bits.RS1   // MEM RS PORT 0
            INT_PRF.io.raddr(RS2_index)     :=    MEM_RS.io.RF_inputs(RS_port).bits.RS2   // MEM RS PORT 0

            // PRF <> instr //
            read_decoded_instructions(i).RS1_data := INT_PRF.io.rdata(RS1_index)
            read_decoded_instructions(i).RS2_data := INT_PRF.io.rdata(RS2_index)
            read_decoded_instructions(i).fetch_PC := io.PC_file_exec_data   // branch unit

            // FWD instruction //
            read_decoded_instructions(i).decoded_instruction <> RegNext(MEM_RS.io.RF_inputs(RS_port).bits)

            // MEMRS ready <> FU ready //
            MEM_RS.io.RF_inputs(RS_port).ready    := execution_engine.io.FU_input(RS_port).ready

            // AGU_output <> MOB //
            MOB.io.AGU_output <> execution_engine.io.FU_output(3)  // FIXME add param number of AGU inputs to MOB

            // MOB <> PRF //
            INT_PRF.io.waddr(PRFRD)  :=    MOB.io.MOB_output.bits.PRD
            INT_PRF.io.wen(PRFRD)    :=    MOB.io.MOB_output.valid && MOB.io.MOB_output.bits.RD_valid
            INT_PRF.io.wdata(PRFRD)  :=    MOB.io.MOB_output.bits.RD_data 

            // RS <> RD complete/ready //
            INT_RS.io.FU_outputs(i) := MOB.io.MOB_output
            MEM_RS.io.FU_outputs(i) := MOB.io.MOB_output

            execution_engine.io.FU_input(i).valid           := RegNext(MEM_RS.io.RF_inputs(RS_port).valid)
        }

        execution_engine.io.FU_input(i).bits            <> read_decoded_instructions(i)

        io.FU_outputs(i) <> execution_engine.io.FU_output(i)
    }

    execution_engine.io.partial_commit           <> io.partial_commit
    execution_engine.io.commit           <> io.commit

    execution_engine.io.commit           <> io.commit


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



    MOB.io.commit <> io.commit
    MOB.io.partial_commit <> io.partial_commit
    for (i <- 0 until fetchWidth){
        MOB.io.reserve(i).bits     := io.backend_packet(i).bits  // pass data along
        MOB.io.reserve(i).valid    := io.backend_packet(i).bits.needs_MEM_RS && io.backend_packet(i).valid
    }
    
    for(i <- 0 until fetchWidth){
        if(FUParamSeq(i).supportsBranch){
            io.PC_file_exec_addr := INT_RS.io.RF_inputs(i).bits.ROB_index
        }
    }

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



    ////////////////////////
    // VERIFICATION HOOKS //
    // DO NOT TOUCH ///////
    ////////////////////////

    //val FU_outputs                  =   Vec(portCount, ValidIO(new FU_output(coreParameters)))







}




// TODO:
// Still cant have N many branch units (due to missing ROB update stuff)
// Such as the ability to read N PCs from the PC file...
// Need to add dynamic scheduling to the RS
// Need to add parameterizable outputs from the MOB
// and need to more clearly distinguish between ports overall and MOB output ports...
