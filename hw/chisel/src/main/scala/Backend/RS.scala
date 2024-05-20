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
import java.io.{File, FileWriter}
import java.rmi.server.UID

import getPortCount._


// FIXME: scale this up to fetchWidth/dispatchWidth or similar 
class RS(RSEntries: Int, physicalRegCount:Int, coreConfig:String) extends Module{

    val portCount = getPortCount(coreConfig)
    val portCountBits = log2Ceil(portCount)

    val io = IO(new Bundle{
        val RS_input       =   Flipped(Decoupled(new RF_port(coreConfig=coreConfig, physicalRegCount=physicalRegCount)))  // input from allocat logic
        val FU_broadcast   =   Flipped(ValidIO(new FU_output(physicalRegCount)))

        val RF_inputs      =   Vec(portCount, Decoupled(new RF_port(coreConfig=coreConfig, physicalRegCount=physicalRegCount)))
    })


    // Allocate RS regs
    val reservation_station = RegInit(VecInit(Seq.fill(RSEntries)(0.U.asTypeOf(new RS_entry(coreConfig=coreConfig, physicalRegCount=physicalRegCount)))))

    // Reg allocate POS for new input
    val validVec = reservation_station.map(_.valid)
    val validUInt = Cat(validVec.reverse)
    dontTouch(validUInt)
    val allocate_index = PriorityEncoder(~validUInt)
    dontTouch(allocate_index)

    // Allocate new RS entry
    when(io.RS_input.valid){
        reservation_station(allocate_index).valid := io.RS_input.valid
        reservation_station(allocate_index).RF_data <> io.RS_input.bits
    }

    ///////////////////////
    // UPDATE RS ENTRIES //
    ///////////////////////

    // FIXME: these needs to be fixed.
    // 1) there can be N FUs placing the data on the CDB
    // 2) the ready can also be "bypassed" such that it can issue that same cycle rather than writing 1 cycle then reading the ready bits from the reg another
    for(i <- 0 until RSEntries){
        when(!reservation_station(i).RF_data.RS1_ready){
            reservation_station(i).RF_data.RS1_ready := (io.FU_broadcast.bits.RD === reservation_station(i).RF_data.RS1.bits) && io.FU_broadcast.valid
        }

        when(!reservation_station(i).RF_data.RS2_ready){
            reservation_station(i).RF_data.RS2_ready := (io.FU_broadcast.bits.RD === reservation_station(i).RF_data.RS2.bits) && io.FU_broadcast.valid
        }
    }

    ////////////////////////////
    // INSTRUCTION SCHEDULING //
    ////////////////////////////

    // This logic determines which instructions to schdeule in the RS
    // Note that this involves determinining which instruction is ready to scheudle, and which is actually scheduled...

    val schedulable_instructions = Wire(Vec(RSEntries, Bool()))    // what instructions have both inputs ready?
    for(i <- 0 until RSEntries){
        schedulable_instructions(i) := reservation_station(i).RF_data.RS1_ready && reservation_station(i).RF_data.RS2_ready
    }

    // update this to selectFirstN, etc...
    val scheduled_instruction_index = PriorityEncoder(schedulable_instructions.asUInt)   // get index of the instruction you want to schedule
    val scheduled_instruction = reservation_station(scheduled_instruction_index)

    reservation_station(scheduled_instruction_index).valid := 0.B    // Free RS entry

    /////////////////////
    // PORT SCHEDULING //
    /////////////////////

    val schedulable_ports = Wire(Vec(portCount, Bool()))  // which ports can the current instruction be sent to

    schedulable_ports(0) := scheduled_instruction.RF_data.uOp.portID.value === 0.U || scheduled_instruction.RF_data.uOp.portID.value === 1.U // (is CSR or is in [ALU, Branch, INT2FP, MUL])
    schedulable_ports(1) := scheduled_instruction.RF_data.uOp.portID.value === 1.U                                                     // (is in [ALU, Branch, INT2FP, MUL])
    schedulable_ports(2) := scheduled_instruction.RF_data.uOp.portID.value === 2.U                                                     // Store
    schedulable_ports(3) := scheduled_instruction.RF_data.uOp.portID.value === 3.U                                                     // Load

    if(coreConfig.contains("M")) schedulable_ports(4) := scheduled_instruction.RF_data.uOp.portID.value === 4.U // IDIV (optional)

    // Each instruction is able to use a subset of the available ports, based on the uOp.
    // Get a OH encoding of the available ports. 

    val scheduled_port = PriorityEncoder(~schedulable_ports.asUInt)

    io.RF_inputs  := DontCare
    
    for(i <- 0 until portCount){
        io.RF_inputs(i).valid  := 0.B
        when(scheduled_port === i.U){
            io.RF_inputs(i.U).valid  := 1.B
        }
    }

    io.RF_inputs(scheduled_port).bits  <> scheduled_instruction.RF_data

    io.RS_input.ready := !(reservation_station.map(_.valid).reduce(_ && _)) // All entires being valid means RS is full.
}



