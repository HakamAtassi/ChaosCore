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

// FIXME: the output port assignment and stuff should all be parameterizable
// Ex: memrs needs only 1 port. its ID is arbitrary, stuff like that
class RS(coreParameters:CoreParameters, RSType:String="RS") extends Module{
    import coreParameters._

    val portCount = getPortCount(coreParameters)
    val portCountBits = log2Ceil(portCount)

    val io = IO(new Bundle{
        // FLUSH //
        val flush                   =   Input(Bool())

        // ALLOCATE //
        val backend_packet          =      Vec(fetchWidth, Flipped(Decoupled(new decoded_instruction(coreParameters))))

        // UPDATE //
        val FU_outputs        =      Vec(portCount, Flipped(ValidIO(new FU_output(coreParameters))))    //FIXME: +1 is placeholder.

        // REG READ (then execute) //
        val RF_inputs         =      Vec(ALUportCount, Decoupled(new decoded_instruction(coreParameters)))

    }); dontTouch(io)



    ///////////////////////////////
    // RESERVATION STATION LOGIC //
    ///////////////////////////////


    // Allocate RS regs
    //FIXME: update this so that it writes from top to bottom
    val reservation_station = RegInit(VecInit(Seq.fill(RSEntries)(0.U.asTypeOf(new RS_entry(coreParameters)))))

    dontTouch(reservation_station)
    
    // Reg allocate POS for new input
    val validVec = reservation_station.map(_.valid)
    val validUInt = Cat(validVec.reverse)
    val allocate_index = SelectFirstN(~validUInt, fetchWidth)
    

    // Allocate new RS entry
    for(i <- 0 until fetchWidth){
        when(io.backend_packet(i).fire){
            val allocateIndexBinary = OHToUInt(allocate_index(i))
            reservation_station(allocateIndexBinary).decoded_instruction := io.backend_packet(i).bits
            reservation_station(allocateIndexBinary).valid   := 1.B
        }
    }


    ///////////////////////
    // UPDATE RS ENTRIES //
    ///////////////////////

    // FIXME: these needs to be fixed.
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
        when(!reservation_station(i).decoded_instruction.ready_bits.RS1_ready && reservation_station(i).valid){
            reservation_station(i).decoded_instruction.ready_bits.RS1_ready := RS1_match(i)
        }
    }

    for(i <- 0 until RSEntries){
        when(!reservation_station(i).decoded_instruction.ready_bits.RS2_ready && reservation_station(i).valid){
            reservation_station(i).decoded_instruction.ready_bits.RS2_ready := RS2_match(i)
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

    dontTouch(schedulable_instructions)

    // to this (more functional)
  for(i <- 0 until RSEntries){

        schedulable_instructions(i) :=  (reservation_station(i).decoded_instruction.ready_bits.RS1_ready) &&
                                        (reservation_station(i).decoded_instruction.ready_bits.RS2_ready) && 
                                        reservation_station(i).valid
    }
     

    //////////////
    // FLUSH RS //
    //////////////

    for(i <- 0 until RSEntries){
        when(io.flush){
            reservation_station(i) := 0.U.asTypeOf(new RS_entry(coreParameters))
        }
    }

    /////////////////////
    // PORT SCHEDULING //
    /////////////////////

    // for each port, select an input and place it
    // if it was found that the instruction was accepted, free it from the RS

    for (i <- 0 until ALUportCount){
        io.RF_inputs(i).valid := 0.B
        io.RF_inputs(i).bits := 0.U.asTypeOf(new decoded_instruction(coreParameters))
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

    // FIXME: convert these to "PriorityMux"


    dontTouch(port0_RS_index)

    // port 0 //
    if(RSType == "MEMRS"){
        for(i <- 0 until RSEntries){
            val current_instruction = reservation_station(i)
            when((current_instruction.decoded_instruction.portID === 3.U) && schedulable_instructions(i)){
                io.RF_inputs(0).bits <> reservation_station(i.U).decoded_instruction
                io.RF_inputs(0).valid <> reservation_station(i.U).valid
                port0_RS_index := i.U
            }
        }

        when(io.RF_inputs(0).fire){
            reservation_station(port0_RS_index) := 0.U.asTypeOf(new RS_entry(coreParameters))
        }
    }else{
        for(i <- 0 until RSEntries){
            val current_instruction = reservation_station(i)
            when((current_instruction.decoded_instruction.portID === 0.U) && schedulable_instructions(i)){
                io.RF_inputs(0).bits <> reservation_station(i.U).decoded_instruction
                io.RF_inputs(0).valid <> reservation_station(i.U).valid
                port0_RS_index := i.U
            }
        }

        when(io.RF_inputs(0).fire){
            reservation_station(port0_RS_index) := 0.U.asTypeOf(new RS_entry(coreParameters))
        }
    }

    ////////////
    // port 1 //
    ////////////
    for(i <- 0 until RSEntries){
        val current_instruction = reservation_station(i)
        when((current_instruction.decoded_instruction.portID === 1.U) && schedulable_instructions(i)){
            io.RF_inputs(1).bits <> reservation_station(i.U).decoded_instruction
            io.RF_inputs(1).valid <> reservation_station(i.U).valid
            port1_RS_index := i.U
        }
    }


    when(io.RF_inputs(1).fire){
        reservation_station(port1_RS_index) := 0.U.asTypeOf(new RS_entry(coreParameters))
    }

    ////////////
    // port 2 //
    ////////////
    for(i <- 0 until RSEntries){
        val current_instruction = reservation_station(i)
        when((current_instruction.decoded_instruction.portID === 2.U) && schedulable_instructions(i)){
            io.RF_inputs(2).bits <> reservation_station(i.U).decoded_instruction
            io.RF_inputs(2).valid <> reservation_station(i.U).valid
            port2_RS_index := i.U
        }
    }


    when(io.RF_inputs(2).fire){
        reservation_station(port2_RS_index) := 0.U.asTypeOf(new RS_entry(coreParameters))
    }

    ////////////
    // port 3 //
    ////////////

    if(coreConfig.contains("M")){
        for(i <- 0 until RSEntries){
            val current_instruction = reservation_station(i)
            when((current_instruction.decoded_instruction.portID === 3.U) && schedulable_instructions(i)){
                io.RF_inputs(3).bits <> reservation_station(i.U).decoded_instruction
                io.RF_inputs(3).valid <> reservation_station(i.U).valid
                port3_RS_index := i.U
            }
        }
    }


    if(coreConfig.contains("M")){
        when(io.RF_inputs(3).fire){
            reservation_station(port3_RS_index) := 0.U.asTypeOf(new RS_entry(coreParameters))
        }
    }

    
    /////////////////////
    // READY SIGNALING //
    /////////////////////


    // There are 4 possible ready bits. 
    // These bits corrispond to how many instructions you can dispatch to the RS per cycle. 
    
    val availalbe_RS_entries = PopCount(~Cat(reservation_station.map(_.valid)))
    
    for (i <- 0 until fetchWidth){
        io.backend_packet(i).ready := availalbe_RS_entries >= fetchWidth.U
    }


}
