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
import circt.stage.ChiselStage 

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
        val flush                       =   Input(Bool())

        // pointers to MOB entries for updating later
        val reserved_pointers           =   Vec(fetchWidth, ValidIO(UInt(log2Ceil(MOBEntries).W)))                               // pointer to allocated entry

        val backend_memory_response     =   Flipped(Decoupled(new backend_memory_response(coreParameters))) // From MEM
        val backend_memory_request      =   Decoupled(new backend_memory_request(coreParameters))     // To MEM

        // REDIRECTS // 
        val commit                      =   Flipped(ValidIO(new commit(coreParameters)))
        val partial_commit              =   Flipped(new partial_commit(coreParameters))

        // PC_file access (for branch unit)
        val PC_file_exec_addr           =   Output(UInt(log2Ceil(ROBEntries).W))
        val PC_file_exec_data           =   Input(UInt(32.W))

        // ALLOCATE //
        val fetch_PC                    =   Input(UInt(32.W))  // DEBUG
        val backend_packet              =   Vec(fetchWidth, Flipped(Decoupled(new decoded_instruction(coreParameters))))


        val MOB_output                  =   ValidIO(new FU_output(coreParameters))                                               // broadcast load data


        // UPDATE //
        val FU_outputs                  =   Vec(portCount, ValidIO(new FU_output(coreParameters)))
    }); dontTouch(io)




    //////////////////////////
    // RESERVATION STATIONS //
    //////////////////////////

    val INT_RS   =  Module(new RS(coreParameters))
    val MEM_RS   =  Module(new RS(coreParameters, "MEMRS"))


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
        INT_RS.io.backend_packet(i).bits     := io.backend_packet(i).bits  // pass data along
        INT_RS.io.backend_packet(i).valid    := (io.backend_packet(i).bits.RS_type === RS_types.INT) && io.backend_packet(i).valid
    }

    for (i <- 0 until fetchWidth){
        MEM_RS.io.backend_packet(i).bits     := io.backend_packet(i).bits  // pass data along
        MEM_RS.io.backend_packet(i).valid    := (io.backend_packet(i).bits.RS_type === RS_types.MEM) && io.backend_packet(i).valid
    }

    MOB.io.commit <> io.commit
    MOB.io.partial_commit <> io.partial_commit
    for (i <- 0 until fetchWidth){
        MOB.io.reserve(i).bits     := io.backend_packet(i).bits  // pass data along
        MOB.io.reserve(i).valid    := (io.backend_packet(i).bits.RS_type === RS_types.MEM) && io.backend_packet(i).valid
    }
    

    // ASSIGN MOB POINTERS FOR MEMRS //
    for(i <- 0 until fetchWidth){
        MEM_RS.io.backend_packet(i).bits.MOB_index := MOB.io.reserved_pointers(i).bits
    }


    ///////////////////////////
    // REGISTER FILES (READ) //
    ///////////////////////////

    //val INT_PRF = Module(new nReadmWrite); INT_PRF.io.clock := clock; INT_PRF.io.reset := reset;    // Connect blackbox
    val INT_PRF = Module(new sim_nReadmWrite)


    // FIXME: portcount should consist of ALU port count + MEM ports. now it only counts the number of ALU ports
    val read_decoded_instructions   =   Wire(Vec(portCount, new read_decoded_instruction(coreParameters)))


    // FIXME: this assignment should be based on some central config.
    // Unforetunately, the PRF is generated externally and included as a black box, which makes it tricky to parameterize effectively.
    // See how the LVT mem can be generated more effectively
    INT_PRF.io.raddr_0   :=    INT_RS.io.RF_inputs(0).bits.RS1   // INT RS PORT 0
    INT_PRF.io.raddr_1   :=    INT_RS.io.RF_inputs(0).bits.RS2   // INT RS PORT 0
    INT_PRF.io.raddr_2   :=    INT_RS.io.RF_inputs(1).bits.RS1   // INT RS PORT 1
    INT_PRF.io.raddr_3   :=    INT_RS.io.RF_inputs(1).bits.RS2   // INT RS PORT 1
    INT_PRF.io.raddr_4   :=    INT_RS.io.RF_inputs(2).bits.RS1   // INT RS PORT 2
    INT_PRF.io.raddr_5   :=    INT_RS.io.RF_inputs(2).bits.RS2   // INT RS PORT 2

    INT_PRF.io.raddr_6   :=    MEM_RS.io.RF_inputs(0).bits.RS1   // MEM RS PORT 0
    INT_PRF.io.raddr_7   :=    MEM_RS.io.RF_inputs(0).bits.RS2   // MEM RS PORT 0

    io.PC_file_exec_addr := INT_RS.io.RF_inputs(0).bits.ROB_index



    // update read out data
    read_decoded_instructions(0).RS1_data := INT_PRF.io.rdata_0
    read_decoded_instructions(0).RS2_data := INT_PRF.io.rdata_1
    read_decoded_instructions(0).fetch_PC := io.PC_file_exec_data   // branch unit

    read_decoded_instructions(1).RS1_data := INT_PRF.io.rdata_2
    read_decoded_instructions(1).RS2_data := INT_PRF.io.rdata_3
    read_decoded_instructions(1).fetch_PC := 0.U

    read_decoded_instructions(2).RS1_data := INT_PRF.io.rdata_4
    read_decoded_instructions(2).RS2_data := INT_PRF.io.rdata_5
    read_decoded_instructions(2).fetch_PC := 0.U

    read_decoded_instructions(3).RS1_data := INT_PRF.io.rdata_6
    read_decoded_instructions(3).RS2_data := INT_PRF.io.rdata_7
    read_decoded_instructions(3).fetch_PC := 0.U


    // Convert decoded_instructions to read_decoded_instructions
    // FIXME: these assignments should be based on some central config file (which ports do what?)
    read_decoded_instructions(0).decoded_instruction <> RegNext(INT_RS.io.RF_inputs(0).bits)
    read_decoded_instructions(1).decoded_instruction <> RegNext(INT_RS.io.RF_inputs(1).bits)
    read_decoded_instructions(2).decoded_instruction <> RegNext(INT_RS.io.RF_inputs(2).bits)
    read_decoded_instructions(3).decoded_instruction <> RegNext(MEM_RS.io.RF_inputs(0).bits)

    ////////////////////
    // PC REG FILE ?? //
    ////////////////////


    ///////////////////////
    // EXECUTION ENGINES //
    ///////////////////////

    //val FU0 = Module(new FU(coreParameters, has_ALU=true, has_branch_unit=true))
    //val FU1 = Module(new FU(coreParameters, has_ALU=true, has_branch_unit=false))
    //val FU2 = Module(new FU(coreParameters, has_ALU=true, has_branch_unit=false))
    //val AGU = Module(new AGU(coreParameters))

    val execution_engine = Module(new execution_engine(coreParameters))


    // Connect FUs

    // Connect ALU, Branch unit, etc... to main RS
    execution_engine.io.FU_input(0).bits            <> read_decoded_instructions(0)
    execution_engine.io.FU_input(0).valid           := RegNext(INT_RS.io.RF_inputs(0).valid)

    execution_engine.io.FU_input(1).bits            <> read_decoded_instructions(1)
    execution_engine.io.FU_input(1).valid           := RegNext(INT_RS.io.RF_inputs(1).valid)

    execution_engine.io.FU_input(2).bits            <> read_decoded_instructions(2)
    execution_engine.io.FU_input(2).valid           := RegNext(INT_RS.io.RF_inputs(2).valid)

    // Connect AGU to MEMRS
    execution_engine.io.FU_input(3).bits            <> read_decoded_instructions(3)
    execution_engine.io.FU_input(3).valid           := RegNext(MEM_RS.io.RF_inputs(0).valid)


    // This connects the actual ALU ready bits to the RS
    // FIXME: should be parameterized or at least a loop
    // MEMRS only has 1 output port...

    // INT RS ready assignemnt
    INT_RS.io.RF_inputs(0).ready        := execution_engine.io.FU_input(0).ready
    INT_RS.io.RF_inputs(1).ready        := execution_engine.io.FU_input(1).ready
    INT_RS.io.RF_inputs(2).ready        := execution_engine.io.FU_input(2).ready

    // MEM RS ready assignemnt
    MEM_RS.io.RF_inputs(0).ready       := execution_engine.io.FU_input(3).ready
    MEM_RS.io.RF_inputs(1).ready       := 0.B
    MEM_RS.io.RF_inputs(2).ready       := 0.B



    ////////////////
    // AGU <> MOB //
    ////////////////
    MOB.io.AGU_output <> execution_engine.io.FU_output(3)
    MOB.io.flush <> io.flush
    MOB.io.fetch_PC <> io.fetch_PC

    ////////////////////////////
    // REGISTER FILES (WRITE) //
    ////////////////////////////


    // Write to INT PRF
    INT_PRF.io.waddr_0  :=    execution_engine.io.FU_output(0).bits.PRD
    INT_PRF.io.waddr_1  :=    execution_engine.io.FU_output(1).bits.PRD
    INT_PRF.io.waddr_2  :=    execution_engine.io.FU_output(2).bits.PRD
    INT_PRF.io.waddr_3  :=    MOB.io.MOB_output.bits.PRD

    INT_PRF.io.wen_0    :=    execution_engine.io.FU_output(0).valid && execution_engine.io.FU_output(0).bits.RD_valid
    INT_PRF.io.wen_1    :=    execution_engine.io.FU_output(1).valid && execution_engine.io.FU_output(1).bits.RD_valid
    INT_PRF.io.wen_2    :=    execution_engine.io.FU_output(2).valid && execution_engine.io.FU_output(2).bits.RD_valid
    INT_PRF.io.wen_3    :=    MOB.io.MOB_output.valid && MOB.io.MOB_output.bits.RD_valid

    INT_PRF.io.wdata_0  :=    execution_engine.io.FU_output(0).bits.RD_data
    INT_PRF.io.wdata_1  :=    execution_engine.io.FU_output(1).bits.RD_data
    INT_PRF.io.wdata_2  :=    execution_engine.io.FU_output(2).bits.RD_data
    INT_PRF.io.wdata_3  :=    MOB.io.MOB_output.bits.RD_data

    ////////////////////////
    // FU TO RS BROADCAST //
    ////////////////////////

    INT_RS.io.FU_outputs(0) <> execution_engine.io.FU_output(0)
    INT_RS.io.FU_outputs(1) <> execution_engine.io.FU_output(1)
    INT_RS.io.FU_outputs(2) <> execution_engine.io.FU_output(2)
    INT_RS.io.FU_outputs(3) <> MOB.io.MOB_output

    MEM_RS.io.FU_outputs(0) <> execution_engine.io.FU_output(0)
    MEM_RS.io.FU_outputs(1) <> execution_engine.io.FU_output(1)
    MEM_RS.io.FU_outputs(2) <> execution_engine.io.FU_output(2)
    MEM_RS.io.FU_outputs(3) <> MOB.io.MOB_output

    //////////////////////
    // FU TO ROB UPDATE //
    //////////////////////

    io.FU_outputs(0) <> execution_engine.io.FU_output(0)
    io.FU_outputs(1) <> execution_engine.io.FU_output(1)
    io.FU_outputs(2) <> execution_engine.io.FU_output(2)
    io.FU_outputs(3) <> execution_engine.io.FU_output(3)    // this updates the ROB

    io.MOB_output   <> MOB.io.MOB_output   // this updates reg status etc...


    ///////////////////
    // MEM_RS TO MEM //
    ///////////////////


    ///////////
    // FLUSH //
    ///////////

    INT_RS.io.flush <> io.flush
    MEM_RS.io.flush <> io.flush

    execution_engine.io.flush    <> io.flush

    io.reserved_pointers <> MOB.io.reserved_pointers
    
    io.backend_memory_request       <>  MOB.io.backend_memory_request
    io.backend_memory_response      <>  MOB.io.backend_memory_response



}