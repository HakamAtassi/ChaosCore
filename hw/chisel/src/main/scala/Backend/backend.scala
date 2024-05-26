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
    val portCount = getPortCount(coreConfig)

    val io = IO(new Bundle{
        // inputs
        val backendPacket       =   Vec(dispatchWidth, Flipped(Decoupled(new BackendPacket(parameters))))
        val dram_resp           =   Flipped(Decoupled(Input(new dram_resp())))

        // outputs (to memory system)
        // to memory
        // to branch FTQ
        //val memoryRequestPacket =   Flipped(Decoupled(new MemoryRequestPacket(parameters)))
        val dram_request         =   Decoupled(new dram_request())

    })



    //////////////////////////
    // RESERVATION STATIONS //
    //////////////////////////

    val INT_RS   =  Module(new RS(parameters))
    val MEM_RS   =  Module(new MEMRS(parameters))
    //val FP_RS  =  ???
     

    // Assign Reservation Stations
    INT_RS.io.RF_inputs := DontCare

    for (i <- 0 until dispatchWidth){
        INT_RS.io.backendPacket(i).valid := (io.backendPacket(i).bits.decoded_instruction.RS_type === RS_types.INT) && io.backendPacket(i).valid   // does this entry correspond to RS
        io.backendPacket(i).ready        := INT_RS.io.backendPacket(i).ready    // propogate ready

        INT_RS.io.backendPacket(i).bits := io.backendPacket(i).bits  // pass data along
    }

    MEM_RS.io.RF_inputs := DontCare

    for (i <- 0 until dispatchWidth){
        MEM_RS.io.backendPacket(i).valid :=   (io.backendPacket(i).bits.decoded_instruction.RS_type === RS_types.MEM)  && io.backendPacket(i).valid // does this entry correspond to RS
        io.backendPacket(i).ready        := MEM_RS.io.backendPacket(i).ready    // propogate ready

        MEM_RS.io.backendPacket(i).bits := io.backendPacket(i).bits  // pass data along
    }


    ///////////////////////////
    // REGISTER FILES (READ) //
    ///////////////////////////

    val INT_PRF = Module(new nReadmWrite); INT_PRF.io.clock := clock; INT_PRF.io.reset := reset;


    val read_decoded_instructions   =   Wire(Vec(portCount, new read_decoded_instruction(coreConfig:String, fetchWidth:Int, ROBEntires:Int, physicalRegCount:Int)))

    INT_PRF.io.raddr_0  :=    INT_RS.io.RF_inputs(0).bits.RS1
    INT_PRF.io.raddr_1  :=    INT_RS.io.RF_inputs(0).bits.RS2
    INT_PRF.io.raddr_2  :=    INT_RS.io.RF_inputs(1).bits.RS1
    INT_PRF.io.raddr_3  :=    INT_RS.io.RF_inputs(1).bits.RS2
    INT_PRF.io.raddr_4  :=    INT_RS.io.RF_inputs(2).bits.RS1
    INT_PRF.io.raddr_5  :=    INT_RS.io.RF_inputs(2).bits.RS2
    INT_PRF.io.raddr_6  :=    MEM_RS.io.RF_inputs.bits.RS2
    INT_PRF.io.raddr_7  :=    MEM_RS.io.RF_inputs.bits.RS2






    // update read out data
    read_decoded_instructions(0).RS1_data := INT_PRF.io.rdata_0
    read_decoded_instructions(0).RS2_data := INT_PRF.io.rdata_1
    read_decoded_instructions(0).PC       := 0.U

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
    read_decoded_instructions(0).decoded_instruction <> RegNext(INT_RS.io.RF_inputs(0).bits)
    read_decoded_instructions(1).decoded_instruction <> RegNext(INT_RS.io.RF_inputs(1).bits)
    read_decoded_instructions(2).decoded_instruction <> RegNext(INT_RS.io.RF_inputs(2).bits)
    read_decoded_instructions(3).decoded_instruction <> RegNext(INT_RS.io.RF_inputs(3).bits)

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
    FU0.io.FU_input.bits <> read_decoded_instructions(0)
    FU0.io.FU_input.valid := RegNext(INT_RS.io.RF_inputs(0).valid)
    // ???                := FU1.io.FU_input.ready

    FU1.io.FU_input.bits <> read_decoded_instructions(1)
    FU1.io.FU_input.valid := RegNext(INT_RS.io.RF_inputs(1).valid)
    // ???                := FU1.io.FU_input.ready

    FU2.io.FU_input.bits <> read_decoded_instructions(2)
    FU2.io.FU_input.valid := RegNext(INT_RS.io.RF_inputs(2).valid)
    // ???                := FU1.io.FU_input.ready

    FU3.io.FU_input.bits <> read_decoded_instructions(3)
    FU3.io.FU_input.valid := RegNext(INT_RS.io.RF_inputs(3).valid)
    // ???                := FU1.io.FU_input.ready







    ////////////////////////////
    // REGISTER FILES (WRITE) //
    ////////////////////////////


    // Write to INT PRF
    INT_PRF.io.waddr_0  :=    FU0.io.FU_output.RD.bits
    INT_PRF.io.waddr_1  :=    FU1.io.FU_output.RD.bits
    INT_PRF.io.waddr_2  :=    FU2.io.FU_output.RD.bits
    INT_PRF.io.waddr_3  :=    FU3.io.FU_output.RD.bits

    INT_PRF.io.wen_0    :=    FU0.io.FU_output.RD.valid
    INT_PRF.io.wen_1    :=    FU1.io.FU_output.RD.valid
    INT_PRF.io.wen_2    :=    FU2.io.FU_output.RD.valid
    INT_PRF.io.wen_3    :=    FU3.io.FU_output.RD.valid

    INT_PRF.io.wdata_0  :=    FU0.io.FU_output.data
    INT_PRF.io.wdata_1  :=    FU1.io.FU_output.data
    INT_PRF.io.wdata_2  :=    FU2.io.FU_output.data
    INT_PRF.io.wdata_3  :=    FU3.io.FU_output.data

    ////////////////////////
    // FU TO RS BROADCAST //
    ////////////////////////

    INT_RS.io.FU_broadcast(0) <> FU0.io.FU_output
    INT_RS.io.FU_broadcast(1) <> FU1.io.FU_output
    INT_RS.io.FU_broadcast(2) <> FU2.io.FU_output
    INT_RS.io.FU_broadcast(3) <> FU3.io.FU_output


    MEM_RS.io.FU_broadcast(0) <> FU0.io.FU_output
    MEM_RS.io.FU_broadcast(1) <> FU1.io.FU_output
    MEM_RS.io.FU_broadcast(2) <> FU2.io.FU_output
    MEM_RS.io.FU_broadcast(3) <> FU3.io.FU_output

    ///////////////////
    // MEM_RS TO MEM //
    ///////////////////

    FU3.io.dram_request := DontCare
    FU3.io.dram_resp    := DontCare

    //val is_DRAM_request = 
    //val is_DRAM_wr_en   = 
    //val DRAM_rq_addr    = 

    io.dram_request := DontCare
    io.dram_resp := DontCare

    
    io.dram_request.bits := FU3.io.dram_request.bits
    FU3.io.dram_resp.bits := io.dram_resp.bits
    
}