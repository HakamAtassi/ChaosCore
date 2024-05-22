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
class RS(dispatchWidth:Int, RSEntries: Int, physicalRegCount:Int, coreConfig:String) extends Module{

    val portCount = getPortCount(coreConfig)
    val portCountBits = log2Ceil(portCount)

    val io = IO(new Bundle{
        val RS_input       =   Vec(dispatchWidth, Flipped(Decoupled(new RF_port(coreConfig=coreConfig, physicalRegCount=physicalRegCount))))
        
        // input from allocate logic
        val FU_broadcast   =   Vec(portCount, Flipped(ValidIO(new FU_output(physicalRegCount))))
        val RF_inputs      =   Vec(portCount, Decoupled(new RF_port(coreConfig=coreConfig, physicalRegCount=physicalRegCount)))
    })


    // Allocate RS regs
    val reservation_station = RegInit(VecInit(Seq.fill(RSEntries)(0.U.asTypeOf(new RS_entry(coreConfig=coreConfig, physicalRegCount=physicalRegCount)))))

    // Reg allocate POS for new input
    val validVec = reservation_station.map(_.valid)
    val validUInt = Cat(validVec.reverse)
    val allocate_index = SelectFirstN(~validUInt, dispatchWidth)
    

    // Allocate new RS entry
    for(i <- 0 until dispatchWidth){
        when(io.RS_input(i).valid){
            val allocateIndexBinary = OHToUInt(allocate_index(i))
            reservation_station(allocateIndexBinary).valid   := io.RS_input(i).valid
            reservation_station(allocateIndexBinary).RF_data <> io.RS_input(i).bits
        }
    }

    ///////////////////////
    // UPDATE RS ENTRIES //
    ///////////////////////

    // FIXME: these needs to be fixed.
    // 1) there can be N FUs placing the data on the CDB
    // 2) the ready can also be "bypassed" such that it can issue that same cycle rather than writing 1 cycle then reading the ready bits from the reg another
    
    for(i <- 0 until RSEntries){
        var RS1_match = 0.B
        for(FU <- 0 until portCount){
            RS1_match = RS1_match ||  (io.FU_broadcast(FU).bits.RD === reservation_station(i).RF_data.RS1.bits) && io.FU_broadcast(FU).valid
        }
        when(!reservation_station(i).RF_data.RS1_ready && reservation_station(i).valid){
            reservation_station(i).RF_data.RS1_ready := RS1_match
        }

        var RS2_match = 0.B
        for(FU <- 0 until portCount){
            RS2_match = RS2_match ||  (io.FU_broadcast(FU).bits.RD === reservation_station(i).RF_data.RS2.bits) && io.FU_broadcast(FU).valid
        }
        when(!reservation_station(i).RF_data.RS2_ready && reservation_station(i).valid){
            reservation_station(i).RF_data.RS2_ready := RS2_match
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
        schedulable_instructions(i) := reservation_station(i).RF_data.RS1_ready && reservation_station(i).RF_data.RS2_ready && reservation_station(i).valid
    }

    /////////////////////
    // PORT SCHEDULING //
    /////////////////////

    // At this stage, you have upto dispatchWidth fetched instructions

    // FIXME: scheduler should really be accounting for age, as without age, the changes of something really closely resembling deadlock/livelock may occur

    for (i <- 0 until portCount){
        io.RF_inputs(i).valid := 0.B
        io.RF_inputs(i).bits := 0.U.asTypeOf(new RF_port(coreConfig=coreConfig, physicalRegCount=physicalRegCount))
    }

    
    val schedulable_instruction_indexes = Wire(Vec(dispatchWidth, UInt(log2Ceil(RSEntries).W))) // what instructions have scheduled in the ROB (to free later on)
    schedulable_instruction_indexes := Seq.fill(dispatchWidth)(0.U)


    //val port_tests = Wire(Vec(N, Bool()))
    //val temp_tests = VecInit(Seq.fill(portCount)(false.B))

    var port0_busy = 0.B
    val port0_busy_wire = Wire(Bool())

    var port1_busy = 0.B
    val port1_busy_wire = Wire(Bool())

    var port2_busy = 0.B
    val port2_busy_wire = Wire(Bool())

    var port3_busy = 0.B
    val port3_busy_wire = Wire(Bool())

    var port4_busy = 0.B
    val port4_busy_wire = Wire(Bool())

    dontTouch(port1_busy_wire)
    dontTouch(port0_busy_wire)


    for(i <- 0 until RSEntries){
        var current_instruction = reservation_station(i)
        when((current_instruction.RF_data.uOp.portID.value === 0.U) && !port0_busy && io.RF_inputs(0).ready && schedulable_instructions(i)){
            // assign valid and RS data
            io.RF_inputs(0).bits <> current_instruction.RF_data
            io.RF_inputs(0).valid := 1.B
            reservation_station(i.U).valid := 0.B
            reservation_station(i.U) <> 0.U.asTypeOf(new RS_entry(coreConfig=coreConfig, physicalRegCount=physicalRegCount))
        }
        port0_busy = port0_busy || ((current_instruction.RF_data.uOp.portID.value === 0.U) && schedulable_instructions(i))
    }

    for(i <- 0 until RSEntries){
        var current_instruction = reservation_station(i)
        when((current_instruction.RF_data.uOp.portID.value === 1.U) && !port1_busy && io.RF_inputs(1).ready &&  schedulable_instructions(i)){
            // assign valid and RS data
            // when an instruction is decoded to say that it can use port 1, it will first try to use port 1, and if that doesnt work, will use port 0
            io.RF_inputs(1).bits <> current_instruction.RF_data
            io.RF_inputs(1).valid := 1.B

            reservation_station(i.U).valid := 0.B
            reservation_station(i.U) <> 0.U.asTypeOf(new RS_entry(coreConfig=coreConfig, physicalRegCount=physicalRegCount))
        }.elsewhen((current_instruction.RF_data.uOp.portID.value === 1.U)  && !port0_busy && schedulable_instructions(i) && io.RF_inputs(0).ready){    // port 1 busy, try port 0
            io.RF_inputs(0).bits <> current_instruction.RF_data
            io.RF_inputs(0).valid := 1.B

            reservation_station(i.U).valid := 0.B
            reservation_station(i.U) <> 0.U.asTypeOf(new RS_entry(coreConfig=coreConfig, physicalRegCount=physicalRegCount))
        }

        port0_busy = port0_busy || ((current_instruction.RF_data.uOp.portID.value === 0.U) && schedulable_instructions(i))
        port1_busy = port1_busy || ((current_instruction.RF_data.uOp.portID.value === 1.U) && schedulable_instructions(i))
    }

    for(i <- 0 until RSEntries){
        var current_instruction = reservation_station(i)
        when((current_instruction.RF_data.uOp.portID.value === 2.U) && !port2_busy && schedulable_instructions(i) && io.RF_inputs(2).ready){
            // assign valid and RS data
            io.RF_inputs(2).bits <> current_instruction.RF_data
            io.RF_inputs(2).valid := 1.B

            reservation_station(i.U).valid := 0.B
            reservation_station(i.U) <> 0.U.asTypeOf(new RS_entry(coreConfig=coreConfig, physicalRegCount=physicalRegCount))
        }
        port2_busy = port2_busy || ((current_instruction.RF_data.uOp.portID.value === 2.U) && schedulable_instructions(i))
    }
    
    for(i <- 0 until RSEntries){
        var current_instruction = reservation_station(i)
        when((current_instruction.RF_data.uOp.portID.value === 3.U) && !port3_busy && schedulable_instructions(i) && io.RF_inputs(3).ready){
            // assign valid and RS data
            io.RF_inputs(3).bits <> current_instruction.RF_data
            io.RF_inputs(3).valid := 1.B

            reservation_station(i.U).valid := 0.B
            reservation_station(i.U) <> 0.U.asTypeOf(new RS_entry(coreConfig=coreConfig, physicalRegCount=physicalRegCount))
        }
        port3_busy = port3_busy || ((current_instruction.RF_data.uOp.portID.value === 3.U) && schedulable_instructions(i))
    }

    for(i <- 0 until RSEntries){
        // optional
        var current_instruction = reservation_station(i)
        if(coreConfig.contains("M")){
            when((current_instruction.RF_data.uOp.portID.value === 4.U) && !port4_busy && schedulable_instructions(i) && io.RF_inputs(4).ready){
                // assign valid and RS data
                io.RF_inputs(4).bits <> current_instruction.RF_data
                io.RF_inputs(4).valid := 1.B

                reservation_station(i.U).valid := 0.B
                reservation_station(i.U) <> 0.U.asTypeOf(new RS_entry(coreConfig=coreConfig, physicalRegCount=physicalRegCount))
            }
            port4_busy = port4_busy || ((current_instruction.RF_data.uOp.portID.value === 4.U) && schedulable_instructions(i))
        }
    }

    port4_busy_wire := port4_busy
    port3_busy_wire := port3_busy
    port2_busy_wire := port2_busy
    port1_busy_wire := port1_busy
    port0_busy_wire := port0_busy



    
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
        io.RS_input(i).ready := themometor_value(dispatchWidth-1,0)(i)
    }
}
