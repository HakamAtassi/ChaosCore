/* ------------------------------------------------------------------------------------
* Filename: RS.scala
* Author: Hakam Atassi
* Date: Apr 23 2024
* Description: The Reservation Station modules. Core is currently read-after-dispatch.
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
import getPortCount._
import Thermometor._


// The Reservation station is able to allocate up to N items at a time
// And is able to schedule N items at a time as well, based on port availability. 

// FIXME: scale this up to fetchWidth/dispatchWidth or similar 
class RS(parameters:Parameters) extends Module{
    import parameters._

    val portCount = getPortCount(parameters)
    val portCountBits = log2Ceil(portCount)

    val io = IO(new Bundle{
        // ALLOCATE //
        val backend_packet          =      Input(Vec(dispatchWidth, new backend_packet(parameters)))
        val INTRS_ready             =      Output(Vec(dispatchWidth, Bool()))

        // UPDATE //
        val FU_outputs       =      Vec(portCount, Flipped(ValidIO(new FU_output(parameters))))


        // REDIRECTS // 
        val commit            =   Input(Vec(commitWidth, new commit(parameters)))

        // REG READ (then execute) //
        val RF_inputs        =      Vec(ALUportCount, Decoupled(new decoded_instruction(parameters)))

    })

    // Allocate RS regs
    val reservation_station = RegInit(VecInit(Seq.fill(RSEntries)(0.U.asTypeOf(new RS_entry(parameters)))))
 
    // Reg allocate POS for new input
    val validVec = reservation_station.map(_.valid)
    val validUInt = Cat(validVec.reverse)
    val allocate_index = SelectFirstN(~validUInt, dispatchWidth)
    

    // Allocate new RS entry
    for(i <- 0 until dispatchWidth){
        when(io.backend_packet(i).valid){
            val allocateIndexBinary = OHToUInt(allocate_index(i))
            reservation_station(allocateIndexBinary).decoded_instruction <> io.backend_packet(i).decoded_instruction
            reservation_station(allocateIndexBinary).ready_bits:= io.backend_packet(i).ready_bits
            reservation_station(allocateIndexBinary).valid   := 1.B
        }
    }

    ///////////////////////
    // UPDATE RS ENTRIES //
    ///////////////////////

    // FIXME: these needs to be fixed.
    // 1) there can be N FUs placing the data on the CDB    (Done)
    // 2) the ready can also be "bypassed" such that it can issue that same cycle rather than writing 1 cycle then reading the ready bits from the reg another

    val RS1_match = Wire(Vec(RSEntries, Bool()))    // what instructions have both inputs ready?
    val RS2_match = Wire(Vec(RSEntries, Bool()))    // what instructions have both inputs ready?
    
    for (i <- 0 until RSEntries) {
        var _RS1_match = false.B
        var _RS2_match = false.B

        for (FU <- 0 until portCount) {
            _RS1_match = _RS1_match || ((io.FU_outputs(FU).bits.RD === reservation_station(i).decoded_instruction.RS1) && io.FU_outputs(FU).bits.RD_valid && io.FU_outputs(FU).valid)
        }
        for (FU <- 0 until portCount) {
            _RS2_match = _RS2_match || ((io.FU_outputs(FU).bits.RD === reservation_station(i).decoded_instruction.RS2) && io.FU_outputs(FU).bits.RD_valid && io.FU_outputs(FU).valid)
        }

        RS1_match(i) := _RS1_match
        RS2_match(i) := _RS2_match
    }




    for(i <- 0 until RSEntries){
        when(!reservation_station(i).ready_bits.RS2_ready && reservation_station(i).valid){
            reservation_station(i).ready_bits.RS2_ready := RS2_match(i)
        }
    }

    for(i <- 0 until RSEntries){
        when(!reservation_station(i).ready_bits.RS1_ready && reservation_station(i).valid){
            reservation_station(i).ready_bits.RS1_ready := RS1_match(i)
        }
    }


    ////////////////////////////
    // INSTRUCTION SCHEDULING //
    ////////////////////////////

    // Scheduling involves 2 parts
    // 1) Determining which instructions are schedulable (Ready RS1/RS2)
    // 2) Selecting which instructions to actually schedule
    //    a) This first involves ensuring the uOp's port is ready and that a previous scheduled instruction does not expect to use it (avoid conflict)
    //    b) Then, determine arbitrarily, or based on age, expected latecy, instruction type, etc ... which instruction to actually schedule
    //    b) Note that it is very important to ensure port collision does not occur at this stage.
    //       This means that if the first scheduled instruction is a div, no other scheduled instructions can be a div (because there is only 1 div port), etc...

    // which instructions can be schedueld this cycle...
    val schedulable_instructions = Wire(Vec(RSEntries, Bool()))    // what instructions have both inputs ready?
    for(i <- 0 until RSEntries){

        schedulable_instructions(i) :=  (reservation_station(i).ready_bits.RS1_ready || RS1_match(i)) && 
                                        (reservation_station(i).ready_bits.RS2_ready || RS2_match(i)) && 
                                        reservation_station(i).valid
    }

    /////////////////////
    // PORT SCHEDULING //
    /////////////////////

    // At this stage, you have upto dispatchWidth fetched instructions

    // FIXME: scheduler should really be accounting for age, as without age, the changes of something really closely resembling deadlock/livelock may occur

    for (i <- 0 until ALUportCount){
        io.RF_inputs(i).valid := 0.B
        io.RF_inputs(i).bits := 0.U.asTypeOf(new decoded_instruction(parameters))
    }

    // Assign port 0

    val port0_RS_index = Wire(UInt(log2Ceil(RSEntries).W))
    val port1_RS_index = Wire(UInt(log2Ceil(RSEntries).W))
    val port2_RS_index = Wire(UInt(log2Ceil(RSEntries).W))
    val port3_RS_index = Wire(UInt(log2Ceil(RSEntries).W))


    port0_RS_index := 0.U
    port1_RS_index := 0.U
    port2_RS_index := 0.U
    port3_RS_index := 0.U


    val port0_valid = Wire(Bool())
    val port1_valid = Wire(Bool())
    val port2_valid = Wire(Bool())
    val port3_valid = Wire(Bool())

    port0_valid := 0.B
    port1_valid := 0.B
    port2_valid := 0.B
    port3_valid := 0.B

    for(i <- 0 until RSEntries){
        val current_instruction = reservation_station(i)
        when((current_instruction.decoded_instruction.portID === 0.U) && schedulable_instructions(i)){
            port0_RS_index := i.U
            port0_valid := 1.B
        }
    }

    for(i <- 0 until RSEntries){
        val current_instruction = reservation_station(i)
        when((current_instruction.decoded_instruction.portID === 1.U) && schedulable_instructions(i)){
            port1_RS_index := i.U
            port1_valid := 1.B
        }
    }

    for(i <- 0 until RSEntries){
        val current_instruction = reservation_station(i)
        when((current_instruction.decoded_instruction.portID === 2.U) && schedulable_instructions(i)){
            port2_RS_index := i.U
            port2_valid := 1.B
        }
    }

    if(coreConfig.contains("M")){
        for(i <- 0 until RSEntries){
            val current_instruction = reservation_station(i)
            when((current_instruction.decoded_instruction.portID === 3.U) && schedulable_instructions(i)){
                port3_RS_index := i.U
                port3_valid := 1.B
            }
        }
    }


    // Free selected instructions from RS

    when(schedulable_instructions(port0_RS_index) && port0_valid){
        reservation_station(port0_RS_index).valid := 0.B
        reservation_station(port0_RS_index) <> 0.U.asTypeOf(new RS_entry(parameters))
    }

    when(schedulable_instructions(port1_RS_index) && port1_valid){
        reservation_station(port1_RS_index).valid := 0.B
        reservation_station(port1_RS_index) <> 0.U.asTypeOf(new RS_entry(parameters))
    }

    when(schedulable_instructions(port2_RS_index) && port2_valid){
        reservation_station(port2_RS_index).valid := 0.B
        reservation_station(port2_RS_index) <> 0.U.asTypeOf(new RS_entry(parameters))
    }


    if(coreConfig.contains("M")){
        when(schedulable_instructions(port3_RS_index) && port3_valid){
            reservation_station(port3_RS_index).valid := 0.B
            reservation_station(port3_RS_index) <> 0.U.asTypeOf(new RS_entry(parameters))
        }
    }

    // Write selected instructions to ports
    
    when(port0_valid){
        io.RF_inputs(0).bits <> reservation_station(port0_RS_index).decoded_instruction
        io.RF_inputs(0).valid := schedulable_instructions(port0_RS_index)
    }

    when(port1_valid){
        io.RF_inputs(1).bits <> reservation_station(port1_RS_index).decoded_instruction
        io.RF_inputs(1).valid := schedulable_instructions(port1_RS_index)
    }

    when(port2_valid){
        io.RF_inputs(2).bits <> reservation_station(port2_RS_index).decoded_instruction
        io.RF_inputs(2).valid := schedulable_instructions(port2_RS_index)
    }


    if(coreConfig.contains("M")){
        when(port3_valid){
            io.RF_inputs(3).bits <> reservation_station(port3_RS_index).decoded_instruction
            io.RF_inputs(3).valid := schedulable_instructions(port3_RS_index)
        }
    }


    //FIXME: input ready bits from FUs do nothing

    
    /////////////////////
    // READY SIGNALING //
    /////////////////////


    // There are 4 possible ready bits. 
    // These bits corrispond to how many instructions you can dispatch to the RS per cycle. 
    
    val availalbe_RS_entries =   PopCount(~Cat(reservation_station.map(_.valid)))

    // 0    |   0
    // 1    |   1
    // 2    |   11
    // 3    |   111
    // 4    |   1111
    // 5    |   1111
    // N-1  |   1111
    val themometor_value = Thermometor(in=availalbe_RS_entries, max=RSEntries)
    for (i <- 0 until dispatchWidth){
        io.INTRS_ready(i) := themometor_value(dispatchWidth-1,0)(i)
    }
}
