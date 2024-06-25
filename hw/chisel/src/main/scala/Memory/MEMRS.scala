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
// Sends instruction to MEM when its both the front of the queue and has its operands MEMRS_ready

// FIXME: MEMRS is full of issues
// one in particular is the lack of wrap around for the points since RSEntires is not always a multiple of 2
class MEMRS(parameters:Parameters) extends Module{
    import parameters._
    val portCount = getPortCount(parameters)
    val portCountBits = log2Ceil(portCount)

    val pointerSize = log2Ceil(RSEntries)+1

    val io = IO(new Bundle{
        // FLUSH //
        val flush                   =   Input(Bool())

        // ALLOCATE //
        val backend_packet          =      Vec(dispatchWidth, Flipped(Decoupled(new decoded_instruction(parameters))))

        // UPDATE //
        val FU_outputs              =      Vec(portCount, Flipped(ValidIO(new FU_output(parameters))))

        // REDIRECTS // 
        val commit                  =      Input(new commit(parameters))

        // REG READ (then execute) //
        val RF_inputs               =      Vec(portCount, Decoupled(new decoded_instruction(parameters)))
    })

    ////////////////////////
    // MODULE ASSUMPTIONS //
    ////////////////////////
    require(isPow2(RSEntries), "MEM Reservation station entries not a power of 2")

    
    val reservation_station = RegInit(VecInit(Seq.fill(RSEntries)(0.U.asTypeOf(new MEMRS_entry(parameters)))))

    // queue pointers
    val pointer_width = log2Ceil(RSEntries)+1
    val front_pointer = RegInit(UInt(pointer_width.W), 0.U)
    val back_pointer  = RegInit(UInt(pointer_width.W), 0.U)

    val front_index     =   front_pointer(pointer_width-2, 0)
    val back_index      =   back_pointer(pointer_width-2, 0)

    //////////////
    // ALLOCATE //
    //////////////
    // write up to dispatchWidth entries into the queue (in order).
    
    // Allocate new RS entry

    val written_vec = Wire(Vec(fetchWidth, Bool()))

    for(i <- 0 until dispatchWidth){
        written_vec(i) := 0.B
        when(io.backend_packet(i).valid && io.backend_packet(i).ready){
            written_vec(i) := 1.B
        }
    }

    for(i <- 0 until dispatchWidth){
        when(written_vec(i)){
            val index_offset = PopCount(written_vec.take(i+1))-1.U
            reservation_station(back_index + index_offset).decoded_instruction <> io.backend_packet(i).bits
            reservation_station(back_index + index_offset).valid              := 1.B
        }
    }
    back_pointer := back_pointer + PopCount(written_vec)


    //////////////////////
    // UPDATE (SOURCES) //
    //////////////////////
    // mark RS1/RS2 as MEMRS_ready based on CDB.

    val RS1_match = Wire(Vec(RSEntries, Bool()))
    val RS2_match = Wire(Vec(RSEntries, Bool()))
    
    for (i <- 0 until RSEntries) {
        var _RS1_match = false.B
        var _RS2_match = false.B

        for (FU <- 0 until portCount) {
            _RS1_match = _RS1_match || ((io.FU_outputs(FU).bits.RD === reservation_station(i).decoded_instruction.RS1) && io.FU_outputs(FU).valid && io.FU_outputs(FU).bits.RD_valid)
        }
        for (FU <- 0 until portCount) {
            _RS2_match = _RS2_match || ((io.FU_outputs(FU).bits.RD === reservation_station(i).decoded_instruction.RS2)  && io.FU_outputs(FU).valid && io.FU_outputs(FU).bits.RD_valid)
        }

        RS1_match(i) := _RS1_match
        RS2_match(i) := _RS2_match
    }


    dontTouch(RS2_match)
    dontTouch(RS1_match)

    for(i <- 0 until RSEntries){
        when(!reservation_station(i).decoded_instruction.ready_bits.RS2_ready && reservation_station(i).valid){
            reservation_station(i).decoded_instruction.ready_bits.RS2_ready := RS2_match(i)
        }
    }

    for(i <- 0 until RSEntries){
        when(!reservation_station(i).decoded_instruction.ready_bits.RS1_ready && reservation_station(i).valid){
            reservation_station(i).decoded_instruction.ready_bits.RS1_ready := RS1_match(i)
        }
    }


    /////////////////////
    // UPDATE (COMMIT) //
    /////////////////////
    // Mark instruction as commited via commit channel

    for(i <- 0 until RSEntries){
        when(!reservation_station(i).commited && reservation_station(i).valid){
            val commited = (io.commit.ROB_index === reservation_station(i).decoded_instruction.ROB_index) && io.commit.valid
            reservation_station(i).commited := commited
        }
    }


    /////////////////
    // MEM REQUEST //
    /////////////////
    // If front of the MEMRS has its sources ready and has committed, send to memory and update front pointer

    // FIXME: this is missing the valid for RS1 and RS2
    val good_to_go =    (reservation_station(front_index).valid && reservation_station(front_index).commited &&
                        reservation_station(front_index).decoded_instruction.ready_bits.RS1_ready && reservation_station(front_index).decoded_instruction.ready_bits.RS2_ready)

    front_pointer := front_pointer + good_to_go

    // clear RS entry
    when(good_to_go){
        reservation_station(front_index) := 0.U.asTypeOf(new MEMRS_entry(parameters))
    }
    

    //////////////
    // FLUSH RS //
    //////////////
    for(i <- 0 until RSEntries){
        when(io.flush){
            reservation_station(i) := 0.U.asTypeOf(new MEMRS_entry(parameters))
        }
    }


    ////////////////////
    // ASSIGN OUTPUTS //
    ////////////////////

    io.RF_inputs(0).bits    := 0.U.asTypeOf(new decoded_instruction(parameters))
    io.RF_inputs(0).valid   := 0.B

    io.RF_inputs(1).bits    := 0.U.asTypeOf(new decoded_instruction(parameters))
    io.RF_inputs(1).valid   := 0.B

    io.RF_inputs(2).bits    := 0.U.asTypeOf(new decoded_instruction(parameters))
    io.RF_inputs(2).valid   := 0.B

    // FIXME: RF_inputs port should be a parameter
    io.RF_inputs(3).bits   <> reservation_station(front_index).decoded_instruction
    io.RF_inputs(3).valid  := good_to_go


    // assign MEMRS_ready bits
    val availalbe_RS_entries = PopCount(~Cat(reservation_station.map(_.valid)))
    val themometor_value = Thermometor(in=availalbe_RS_entries, max=RSEntries)
    for (i <- 0 until dispatchWidth){
        io.backend_packet(i).ready := themometor_value(dispatchWidth-1,0)(i)
    }


}
