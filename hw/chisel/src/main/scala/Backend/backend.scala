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
// Recives dispatchWidth decoded and renamed instructions from the frontend
// Allocates the instructions into the corresponding reservation stations (ROB exists externally)
// When instructions are scheduled, they go through the Register Read stage. Their position in the RS is also cleared.
//      This stage reads RS1, RS2, and PC data from the register files
// The read instructions are then passed to their scheduled execution engines
// Once executed, the computed data is broadcasted to the RS and written to the PRF



class backend(parameters:Parameters) extends Module{
    import parameters._
    val portCount = getPortCount(parameters)

    val io = IO(new Bundle{

        // DRAM CHANNELS //
        val DRAM_resp               =   Flipped(Decoupled(Input(new DRAM_resp(parameters))))  // FROM DRAM
        val DRAM_request            =   Decoupled(new DRAM_request(parameters))               // TO DRAM

        // REDIRECTS // 
        val commit                  =    Input(new commit(parameters))

        // PC_file access (for branch unit)
        val PC_file_exec_addr           =   Output(UInt(log2Ceil(ROBEntires).W))
        val PC_file_exec_data           =   Input(UInt(log2Ceil(ROBEntires).W))


        // ALLOCATE //
        //val backend_packet          =   Vec(dispatchWidth, Flipped(Decoupled(new decoded_instruction(parameters))))
        val backend_packet          =   Flipped(Decoupled(new decoded_fetch_packet(parameters)))

        //val INTRS_sources_ready     =   Input(Vec(dispatchWidth, new sources_ready()))
        //val MEMRS_sources_ready     =   Input(Vec(dispatchWidth, new sources_ready()))

        val MEMRS_ready             =   Output(Vec(dispatchWidth, Bool()))
        val INTRS_ready             =   Output(Vec(dispatchWidth, Bool()))

        // UPDATE //
        val FU_outputs              =   Vec(portCount, ValidIO(new FU_output(parameters)))
    })



    //////////////////////////
    // RESERVATION STATIONS //
    //////////////////////////

    val INT_RS   =  Module(new RS(parameters))
    val MEM_RS   =  Module(new MEMRS(parameters))
    //val FP_RS  =  ???

    // Assign Reservation Stations

    INT_RS.io.commit <> io.commit

    for (i <- 0 until dispatchWidth){
        INT_RS.io.backend_packet(i).bits     := io.backend_packet.bits.decoded_instruction(i)  // pass data along
        INT_RS.io.backend_packet(i).valid    := (io.backend_packet.bits.decoded_instruction(i).RS_type === RS_types.INT) && io.backend_packet.bits.valid_bits(i)   
        
        // does this entry correspond to RS
    }


    INT_RS.io.commit <> io.commit

    for (i <- 0 until dispatchWidth){
        MEM_RS.io.backend_packet(i).bits     := io.backend_packet.bits.decoded_instruction(i)  // pass data along
        MEM_RS.io.backend_packet(i).valid    := (io.backend_packet.bits.decoded_instruction(i).RS_type === RS_types.MEM)  && io.backend_packet.bits.valid_bits(i) // does this entry correspond to RS
    }

    // Assign ready bits
    for (i <- 0 until dispatchWidth){
        io.MEMRS_ready(i)        := MEM_RS.io.backend_packet(i).ready
        io.INTRS_ready(i)        := INT_RS.io.backend_packet(i).ready
    }


    ///////////////////////////
    // REGISTER FILES (READ) //
    ///////////////////////////

    val INT_PRF = Module(new nReadmWrite); INT_PRF.io.clock := clock; INT_PRF.io.reset := reset;    // Connect blackbox


    // FIXME: portcount should consist of ALU port count + MEM ports. now it only counts the number of ALU ports
    val read_decoded_instructions   =   Wire(Vec(portCount, new read_decoded_instruction(parameters)))

    // FIXME: the assignemnt of these should be based on some central config
    INT_PRF.io.raddr_0  :=    INT_RS.io.RF_inputs(0).bits.RS1   // INT RS PORT 0
    INT_PRF.io.raddr_1  :=    INT_RS.io.RF_inputs(0).bits.RS2   // INT RS PORT 0
    INT_PRF.io.raddr_2  :=    INT_RS.io.RF_inputs(1).bits.RS1   // INT RS PORT 1
    INT_PRF.io.raddr_3  :=    INT_RS.io.RF_inputs(1).bits.RS2   // INT RS PORT 1
    INT_PRF.io.raddr_4  :=    INT_RS.io.RF_inputs(2).bits.RS1   // INT RS PORT 2
    INT_PRF.io.raddr_5  :=    INT_RS.io.RF_inputs(2).bits.RS2   // INT RS PORT 2
    INT_PRF.io.raddr_6  :=    MEM_RS.io.RF_inputs(3).bits.RS1   // MEM RS PORT 0
    INT_PRF.io.raddr_7  :=    MEM_RS.io.RF_inputs(3).bits.RS2   // MEM RS PORT 0

    io.PC_file_exec_addr := INT_RS.io.RF_inputs(0).bits.ROB_index


    // update read out data
    read_decoded_instructions(0).RS1_data := INT_PRF.io.rdata_0
    read_decoded_instructions(0).RS2_data := INT_PRF.io.rdata_1
    read_decoded_instructions(0).PC       := io.PC_file_exec_data   // branch unit

    read_decoded_instructions(1).RS1_data := INT_PRF.io.rdata_2
    read_decoded_instructions(1).RS2_data := INT_PRF.io.rdata_3
    read_decoded_instructions(1).PC       := 0.U

    read_decoded_instructions(2).RS1_data := INT_PRF.io.rdata_4
    read_decoded_instructions(2).RS2_data := INT_PRF.io.rdata_5
    read_decoded_instructions(2).PC       := 0.U

    read_decoded_instructions(3).RS1_data := INT_PRF.io.rdata_6
    read_decoded_instructions(3).RS2_data := INT_PRF.io.rdata_7
    read_decoded_instructions(3).PC       := 0.U


    // Convert decoded_instructions to read_decoded_instructions
    // FIXME: these assignments should be based on some central config file (which ports do what?)
    read_decoded_instructions(0).decoded_instruction <> RegNext(INT_RS.io.RF_inputs(0).bits)
    read_decoded_instructions(1).decoded_instruction <> RegNext(INT_RS.io.RF_inputs(1).bits)
    read_decoded_instructions(2).decoded_instruction <> RegNext(INT_RS.io.RF_inputs(2).bits)
    read_decoded_instructions(3).decoded_instruction <> RegNext(MEM_RS.io.RF_inputs(3).bits)

    ////////////////////
    // PC REG FILE ?? //
    ////////////////////


    ///////////////////////
    // EXECUTION ENGINES //
    ///////////////////////

    val FU0 = Module(new FU(parameters, has_ALU=true, has_branch_unit=true))
    val FU1 = Module(new FU(parameters, has_ALU=true, has_branch_unit=false))
    val FU2 = Module(new FU(parameters, has_ALU=true, has_branch_unit=false))
    val FU3 = Module(new MEMFU(parameters))


    // Connect FUs
    FU0.io.FU_input.bits            <> read_decoded_instructions(0)
    FU0.io.FU_input.valid           := RegNext(INT_RS.io.RF_inputs(0).valid)

    FU1.io.FU_input.bits            <> read_decoded_instructions(1)
    FU1.io.FU_input.valid           := RegNext(INT_RS.io.RF_inputs(1).valid)

    FU2.io.FU_input.bits            <> read_decoded_instructions(2)
    FU2.io.FU_input.valid           := RegNext(INT_RS.io.RF_inputs(2).valid)

    FU3.io.FU_input.bits            <> read_decoded_instructions(3)
    FU3.io.FU_input.valid           := RegNext(MEM_RS.io.RF_inputs(3).valid)


    // INT RS ready assignemnt
    INT_RS.io.RF_inputs(0).ready        := FU0.io.FU_input.ready
    INT_RS.io.RF_inputs(1).ready        := FU1.io.FU_input.ready
    INT_RS.io.RF_inputs(2).ready        := FU2.io.FU_input.ready

    // MEM RS ready assignemnt

    MEM_RS.io.RF_inputs(0).ready       := FU0.io.FU_input.ready
    MEM_RS.io.RF_inputs(1).ready       := FU1.io.FU_input.ready
    MEM_RS.io.RF_inputs(2).ready       := FU2.io.FU_input.ready
    MEM_RS.io.RF_inputs(3).ready       := FU3.io.FU_input.ready


    ////////////////////////////
    // REGISTER FILES (WRITE) //
    ////////////////////////////


    // Write to INT PRF
    INT_PRF.io.waddr_0  :=    FU0.io.FU_output.bits.RD
    INT_PRF.io.waddr_1  :=    FU1.io.FU_output.bits.RD
    INT_PRF.io.waddr_2  :=    FU2.io.FU_output.bits.RD
    INT_PRF.io.waddr_3  :=    FU3.io.FU_output.bits.RD

    INT_PRF.io.wen_0    :=    FU0.io.FU_output.valid && FU0.io.FU_output.bits.RD_valid
    INT_PRF.io.wen_1    :=    FU1.io.FU_output.valid && FU1.io.FU_output.bits.RD_valid
    INT_PRF.io.wen_2    :=    FU2.io.FU_output.valid && FU2.io.FU_output.bits.RD_valid
    INT_PRF.io.wen_3    :=    FU3.io.FU_output.valid && FU3.io.FU_output.bits.RD_valid

    INT_PRF.io.wdata_0  :=    FU0.io.FU_output.bits.RD_data
    INT_PRF.io.wdata_1  :=    FU1.io.FU_output.bits.RD_data
    INT_PRF.io.wdata_2  :=    FU2.io.FU_output.bits.RD_data
    INT_PRF.io.wdata_3  :=    FU3.io.FU_output.bits.RD_data

    ////////////////////////
    // FU TO RS BROADCAST //
    ////////////////////////

    INT_RS.io.FU_outputs(0) <> FU0.io.FU_output
    INT_RS.io.FU_outputs(1) <> FU1.io.FU_output
    INT_RS.io.FU_outputs(2) <> FU2.io.FU_output
    INT_RS.io.FU_outputs(3) <> FU3.io.FU_output


    MEM_RS.io.FU_outputs(0) <> FU0.io.FU_output
    MEM_RS.io.FU_outputs(1) <> FU1.io.FU_output
    MEM_RS.io.FU_outputs(2) <> FU2.io.FU_output
    MEM_RS.io.FU_outputs(3) <> FU3.io.FU_output

    //////////////////////
    // FU TO ROB UPDATE //
    //////////////////////

    io.FU_outputs(0) <> FU0.io.FU_output
    io.FU_outputs(1) <> FU1.io.FU_output
    io.FU_outputs(2) <> FU2.io.FU_output
    io.FU_outputs(3) <> FU3.io.FU_output


    INT_RS.io.commit := io.commit
    MEM_RS.io.commit := io.commit

    ///////////////////
    // MEM_RS TO MEM //
    ///////////////////
    
    io.DRAM_request <>  FU3.io.DRAM_request
    io.DRAM_resp    <>  FU3.io.DRAM_resp


    io.backend_packet.ready := DontCare

}