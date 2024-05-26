/* ------------------------------------------------------------------------------------
* Filename: LSQ.scala
* Author: Hakam Atassi
* Date: May 23 2024
* Description: A Memory Reservation station. Currently just a queue of memory operations.
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

// Expected operation: writes incoming memory operations from allocate stage.
// Sends instruction to MEM when its both the front of the queue and has its operands ready

class MEMRS(parameters:Parameters) extends Module{
    import parameters._
    val portCount = getPortCount(coreConfig)
    val portCountBits = log2Ceil(portCount)

    val pointerSize = log2Ceil(RSEntries)+1

    val io = IO(new Bundle{
        // from allocate
        val backendPacket  =   Vec(dispatchWidth, Flipped(Decoupled(new BackendPacket(parameters))))

        // from Mem
        val FU_broadcast   =   Vec(portCount, Flipped(new FU_output(physicalRegCount)))

        // To FU
        val RF_inputs      =   Decoupled(new decoded_instruction(coreConfig=coreConfig, fetchWidth:Int, ROBEntires=ROBEntires, physicalRegCount=physicalRegCount))
    })

    
    val reservation_station = RegInit(VecInit(Seq.fill(RSEntries)(0.U.asTypeOf(new RS_entry(coreConfig=coreConfig, fetchWidth:Int, ROBEntires=ROBEntires, physicalRegCount=physicalRegCount)))))



    //////////////
    // ALLOCATE //
    //////////////
    // write up to dispatchWidth entries into the queue (in order).
    
    val validVec = reservation_station.map(_.valid)
    val validUInt = Cat(validVec.reverse)
    val allocate_index = SelectFirstN(~validUInt, dispatchWidth)
    
    // Allocate new RS entry
    for(i <- 0 until dispatchWidth){
        when(io.backendPacket(i).valid){
            val allocateIndexBinary = OHToUInt(allocate_index(i))
            reservation_station(allocateIndexBinary).decoded_instruction <> io.backendPacket(i).bits.decoded_instruction
            reservation_station(allocateIndexBinary).ready_bits:= io.backendPacket(i).bits.ready_bits
            reservation_station(allocateIndexBinary).valid   := 1.B
        }
    }

    ////////////
    // UPDATE //
    ////////////
    // mark RS1/RS2 as ready based on CDB.

    val RS1_match = Wire(Vec(RSEntries, Bool()))
    val RS2_match = Wire(Vec(RSEntries, Bool()))
    
    for (i <- 0 until RSEntries) {
        var _RS1_match = false.B
        var _RS2_match = false.B

        for (FU <- 0 until portCount) {
            _RS1_match = _RS1_match || ((io.FU_broadcast(FU).RD.bits === reservation_station(i).decoded_instruction.RS1) && io.FU_broadcast(FU).RD.valid)
        }
        for (FU <- 0 until portCount) {
            _RS2_match = _RS2_match || ((io.FU_broadcast(FU).RD.bits === reservation_station(i).decoded_instruction.RS2) && io.FU_broadcast(FU).RD.valid)
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

    /////////////////
    // MEM REQUEST //
    /////////////////
    // if oldest RS entry is ready to send to MEM and MEM is not busy, send MEM request.

    //val scheduled_mem_operation 

    val schedulable_instructions = Wire(Vec(RSEntries, Bool()))    // what instructions have both inputs ready?
    for(i <- 0 until RSEntries){

        val load_valid_ready  =         reservation_station(i).valid && (reservation_station(i).ready_bits.RS1_ready || RS1_match(i))

        val store_valid_ready =         (reservation_station(i).ready_bits.RS1_ready || RS1_match(i)) && 
                                        (reservation_station(i).ready_bits.RS2_ready || RS2_match(i)) && 
                                        reservation_station(i).valid

        schedulable_instructions(i) :=  load_valid_ready || store_valid_ready
    }
    



    val scheduled_index = PriorityEncoder(schedulable_instructions)

    // free scheduled instruction
    reservation_station(scheduled_index).valid := 0.B
    reservation_station(scheduled_index) <> 0.U.asTypeOf(new RS_entry(coreConfig=coreConfig, fetchWidth:Int, ROBEntires=ROBEntires, physicalRegCount=physicalRegCount))

    io.RF_inputs.bits <> reservation_station(scheduled_index).decoded_instruction
    io.RF_inputs.valid := schedulable_instructions.asUInt.orR


    // assign ready bits
    val availalbe_RS_entries =   PopCount(~Cat(reservation_station.map(_.valid)))
    val themometor_value = Thermometor(in=availalbe_RS_entries, max=RSEntries)
    for (i <- 0 until dispatchWidth){
        io.backendPacket(i).ready := themometor_value(dispatchWidth-1,0)(i)
    }


}