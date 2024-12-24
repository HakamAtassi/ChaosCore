/* ------------------------------------------------------------------------------------
* Filename: MOB.scala
* Author: Hakam Atassi
* Date: May 23 2024
* Description: A very naive Load/Store queue that executes memory operations serially.
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
import getPortCount._


class simple_MOB(coreParameters:CoreParameters) extends Module{
    import coreParameters._
    val portCount       = getPortCount(coreParameters)
    val portCountBits   = log2Ceil(portCount)

    val ptr_width = log2Ceil(MOBEntries) + 1

    val io = IO(new Bundle{
        // FLUSH //

        val flush               =     Flipped(ValidIO(new flush(coreParameters)))



        // ALLOCATE //
        val reserve                 =      Vec(fetchWidth, Flipped(Decoupled(new decoded_instruction(coreParameters))))         // reserve entry (rename)
        val reserved_pointers       =      Vec(fetchWidth, ValidIO(UInt(log2Ceil(MOBEntries).W)))                               // pointer to allocated entry

        val fetch_PC                =      Input(UInt(32.W))                                                                  // DEBUG

        //val complete                =      ValidIO(new FU_output(coreParameters))                                               // update ROB (front of MOB)
        val AGU_output              =      Flipped(ValidIO(new FU_output(coreParameters)))                                      // update address (AGU)
        val MOB_output              =      ValidIO(new FU_output(coreParameters))                                               // broadcast load data

        // REDIRECTS // 
        val commit                  =      Flipped(ValidIO(new commit(coreParameters)))                                         // commit mem op
        val partial_commit          =      Input(new partial_commit(coreParameters))                                         // commit mem op

        ///////////////////////////
        // D$ BACKEND MEM ACCESS //
        ///////////////////////////
        val backend_memory_request              =   Decoupled(new backend_memory_request(coreParameters))
        val backend_memory_response             =   Flipped(Decoupled(new backend_memory_response(coreParameters)))

    }); dontTouch(io)


    /////////
    // MOB //
    /////////

    val MOB = RegInit(VecInit(Seq.fill(MOBEntries)(0.U.asTypeOf(new MOB_entry(coreParameters)))));
    

    val front_pointer   = RegInit(UInt(ptr_width.W), 0.U)
    val back_pointer    = RegInit(UInt(ptr_width.W), 0.U)

    val front_index     = front_pointer(ptr_width-2, 0)
    val back_index      = back_pointer(ptr_width-2, 0)

    val MOB_front       = MOB(front_index)


    //////////////////////
    // ALLOCATE/RESERVE //
    //////////////////////

    // Update MOB
    val written_vec = Wire(Vec(fetchWidth, Bool())) // help avoid bubbles during allocation

    for(i <- 0 until fetchWidth){
        written_vec(i) := 0.B
        when(io.reserve(i).fire){
            written_vec(i) := 1.B
        }
    }

    for(i <- 0 until fetchWidth){   // reserve MOB index
        io.reserved_pointers(i).valid := 0.U
        io.reserved_pointers(i).bits  := 0.U
        when(written_vec(i)){

            val MOB_entry = Wire(new MOB_entry(coreParameters))
            MOB_entry := DontCare

            val index_offset = PopCount(written_vec.take(i+1))-1.U

            MOB_entry.valid                :=  1.B
            MOB_entry.MOB_STATE            :=  MOB_STATES.VALID
            MOB_entry.memory_type          :=  io.reserve(i).bits.memory_type
            MOB_entry.access_width         :=  io.reserve(i).bits.access_width
            MOB_entry.PRD                  :=  io.reserve(i).bits.PRD
            MOB_entry.ROB_index            :=  io.reserve(i).bits.ROB_index
            MOB_entry.fetch_packet_index   :=  io.reserve(i).bits.packet_index
            MOB_entry.mem_signed           :=  io.reserve(i).bits.mem_signed

            io.reserved_pointers(i).bits                        := back_index + index_offset
            io.reserved_pointers(i).valid                       := 1.U


            MOB(back_index + index_offset) := MOB_entry

        }
    }

    back_pointer := back_pointer + PopCount(written_vec)




    ////////////////
    // AGU UPDATE //
    ////////////////

    val AGU_index = io.AGU_output.bits.MOB_index
    when(io.AGU_output.valid){
        MOB(AGU_index).address  := io.AGU_output.bits.address
        MOB(AGU_index).data  := io.AGU_output.bits.wr_data
        MOB(AGU_index).resolved := 1.B
    }


    ///////////////////
    // COMMIT UPDATE //
    ///////////////////

    val comb_committed = Wire(Vec(MOBEntries, Bool()))
    comb_committed := MOB.map(MOB_entry => MOB_entry.committed)

    for(i <- 0 until fetchWidth){
        when(io.partial_commit.valid(i) && MOB(io.partial_commit.MOB_index(i)).valid && (io.partial_commit.ROB_index === MOB(io.partial_commit.MOB_index(i)).ROB_index) && io.partial_commit.MOB_valid(i)){
            comb_committed(io.partial_commit.MOB_index(i)) := 1.B
        }
    }

    for(i <- 0 until MOBEntries){
        MOB(i).committed := comb_committed(i)
    }

    ///////////
    // FLUSH //
    ///////////
    val committed_entries = PopCount(comb_committed.zip(MOB).map { case (committed, mobEntry) => committed && mobEntry.valid })


    dontTouch(committed_entries)

    when(io.flush.valid){
        for(i <- 0 until MOBEntries){
            val clear = !comb_committed(i) && MOB(i).valid
            when(clear){
                MOB(i) := 0.U.asTypeOf(new MOB_entry(coreParameters))
            }
        }
        //back_pointer := back_pointer - flushed_entries   // walk back back pointer a few elements
        back_pointer := front_pointer + committed_entries
    }


    dontTouch(front_index)
    dontTouch(back_index)


    
    // ENTRY FSM

    for(i <- 0 until MOBEntries){
        when(MOB(i).committed && MOB(i).resolved && MOB(i).in(MOB_STATES.VALID)){  
            MOB(i).MOB_STATE := MOB_STATES.READY
        }
    }

    ///////////
    // CACHE //
    ///////////

    val req_reg = RegInit(new backend_memory_request(coreParameters), 0.U.asTypeOf(new backend_memory_request(coreParameters)))


    // cache request

    io.backend_memory_request.bits   := 0.U.asTypeOf(new backend_memory_request(coreParameters))
    //io.backend_memory_request.valid  := (MOB_front.committed && MOB_front.resolved) && MOB_front.valid
    io.backend_memory_request.valid  := (MOB_front.MOB_STATE === MOB_STATES.READY) && MOB_front.valid
    
    //(MOB_front.committed || (MOB_front.memory_type === memory_type_t.LOAD)) && MOB_front.valid

    io.backend_memory_request.bits.addr         := MOB_front.address
    io.backend_memory_request.bits.memory_type  := MOB_front.memory_type
    io.backend_memory_request.bits.access_width := MOB_front.access_width
    io.backend_memory_request.bits.PRD          := MOB_front.PRD
    io.backend_memory_request.bits.ROB_index    := MOB_front.ROB_index
    io.backend_memory_request.bits.MOB_index    := front_index
    io.backend_memory_request.bits.mem_signed   := MOB_front.mem_signed
    io.backend_memory_request.bits.data         := MOB_front.data
    io.backend_memory_request.bits.packet_index := MOB_front.fetch_packet_index
    

    // SEND REQUEST
    when(io.backend_memory_request.fire){   // entry requested
        //MOB(front_index) := 0.U.asTypeOf(new MOB_entry(coreParameters))
        MOB(front_index).MOB_STATE := MOB_STATES.REQUESTED
        req_reg          := io.backend_memory_request.bits
    }

    when(MOB(front_index).valid && (MOB(front_index).MOB_STATE === MOB_STATES.REQUESTED) && (MOB(front_index).memory_type === memory_type_t.STORE)){
        MOB(front_index).MOB_STATE := MOB_STATES.DONE
    }


    // AWAIT NACK
    {
        val response_index = io.backend_memory_response.bits.MOB_index
        // NACK
        when(io.backend_memory_response.bits.nack){
            MOB(response_index).MOB_STATE := MOB_STATES.NACKED
        }
    }

    // AWAIT RESPONSE
    when(io.backend_memory_response.fire){ // entry response
        val response_index = io.backend_memory_response.bits.MOB_index
        // NACK
        when(io.backend_memory_response.bits.nack){
            MOB(response_index).MOB_STATE := MOB_STATES.NACKED
        }.otherwise{
            MOB(response_index).MOB_STATE := MOB_STATES.DONE
        }
    }


    // HANDLE NACK
    when(MOB(front_index).valid && MOB(front_index).MOB_STATE === MOB_STATES.NACKED){
        MOB(front_index).MOB_STATE := MOB_STATES.READY  // set to ready and try again
    }

    // FREE ENTRY
    when(MOB(front_index).MOB_STATE === MOB_STATES.DONE){ // entry response
        front_pointer := front_pointer + 1.U
       MOB(front_index) := 0.U.asTypeOf(new MOB_entry(coreParameters))
    }



    // cache response
    io.MOB_output.bits                      := 0.U.asTypeOf(new FU_output(coreParameters))
    io.MOB_output.bits.ROB_index            := io.backend_memory_response.bits.ROB_index
    io.MOB_output.bits.MOB_index            := io.backend_memory_response.bits.MOB_index    // why is this needed?
    io.MOB_output.bits.address              := io.backend_memory_response.bits.addr
    io.MOB_output.bits.PRD                  := io.backend_memory_response.bits.PRD
    io.MOB_output.bits.RD_data              := io.backend_memory_response.bits.data
    io.MOB_output.bits.RD_valid             := io.backend_memory_response.valid
    io.MOB_output.bits.fetch_packet_index   := io.backend_memory_response.bits.fetch_packet_index
    io.MOB_output.valid                     := io.backend_memory_response.valid && !io.backend_memory_response.bits.nack

    when(io.backend_memory_response.fire){
        io.MOB_output.bits.ROB_index            := req_reg.ROB_index
        io.MOB_output.bits.MOB_index            := req_reg.MOB_index
        io.MOB_output.bits.fetch_packet_index   := req_reg.packet_index
        io.MOB_output.bits.PRD                  := req_reg.PRD
    }

    ///////////
    // READY //
    ///////////

    io.backend_memory_response.ready := 1.B

    val availalbe_MOB_entries = PopCount(~Cat(MOB.map(_.valid)))
    
    for (i <- 0 until fetchWidth){
        io.reserve(i).ready := (availalbe_MOB_entries >= fetchWidth.U) && !io.flush.valid
    }

}
