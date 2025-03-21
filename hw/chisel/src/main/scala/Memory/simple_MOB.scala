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

    val nonMemoryPortCount = portCount - memPortCount 


    val ptr_width = log2Ceil(MOBEntries) + 1

    val io = IO(new Bundle{
        // FLUSH //

        val flush               =     Flipped(ValidIO(new flush(coreParameters)))

        // ALLOCATE //
        val reserve                 =      Vec(fetchWidth, Flipped(Decoupled(new decoded_instruction(coreParameters))))         // reserve entry (rename)
        val reserved_pointers       =      Vec(fetchWidth, ValidIO(UInt(log2Ceil(MOBEntries).W)))                               // pointer to allocated entry

        val AGU_output              =      Flipped(Decoupled(new FU_output(coreParameters)))                                      // update address (AGU)
        val INT_MOB_output          =      Decoupled(new FU_output(coreParameters))                                               // broadcast load data
        val FP_MOB_output           =      if (coreConfig.contains("F")) Some(Decoupled(new FU_output(coreParameters))) else None

        // REDIRECTS // 
        val commit                  =      Flipped(ValidIO(new commit(coreParameters)))                                         // commit mem op

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
            MOB_entry.data_type            :=  Mux(io.reserve(i).bits.needs_FPU, data_type_t.FP, data_type_t.INT) // io.reserve(i).bits.mem_signed

            io.reserved_pointers(i).bits                        := back_index + index_offset
            io.reserved_pointers(i).valid                       := 1.U


            MOB(back_index + index_offset) := MOB_entry

        }
    }

    back_pointer := back_pointer + PopCount(written_vec)




    ////////////////
    // AGU UPDATE //
    ////////////////

    for(i <- 0 until memPortCount){
        val AGU_index = io.AGU_output.bits.MOB_index
        when(io.AGU_output.valid && MOB(AGU_index).valid){
            MOB(AGU_index).address  := io.AGU_output.bits.address
            MOB(AGU_index).data  := io.AGU_output.bits.wr_data
            MOB(AGU_index).resolved := 1.B
        }
    }


    ///////////////////
    // COMMIT UPDATE //
    ///////////////////

    val comb_committed = Wire(Vec(MOBEntries, Bool()))
    comb_committed := MOB.map(MOB_entry => MOB_entry.committed)

    for(i <- 0 until fetchWidth){
        when(io.commit.bits.insn_commit(i).valid && io.commit.bits.insn_commit(i).bits.WB_committed && MOB(io.commit.bits.insn_commit(i).bits.MOB_index).valid && (io.commit.bits.ROB_index === MOB(io.commit.bits.insn_commit(i).bits.MOB_index).ROB_index) && io.commit.bits.insn_commit(i).bits.MOB_valid){
            comb_committed(io.commit.bits.insn_commit(i).bits.MOB_index) := 1.B
        }
    }

    for(i <- 0 until MOBEntries){
        MOB(i).committed := comb_committed(i)
    }

    ///////////
    // FLUSH //
    ///////////
    val committed_entries = PopCount(comb_committed.zip(MOB).map { case (committed, mobEntry) => committed && mobEntry.valid })


    
    // ENTRY FSM

    for(i <- 0 until MOBEntries){
        when((MOB(i).committed || MOB(i).memory_type === memory_type_t.LOAD) && MOB(i).resolved && MOB(i).in(MOB_STATES.VALID)){  
            MOB(i).MOB_STATE := MOB_STATES.READY
        }
    }

    ///////////
    // CACHE //
    ///////////

    val req_reg = RegInit(new backend_memory_request(coreParameters), 0.U.asTypeOf(new backend_memory_request(coreParameters)))


    // cache request

    io.backend_memory_request.bits   := 0.U.asTypeOf(new backend_memory_request(coreParameters))
    io.backend_memory_request.valid  := (MOB_front.MOB_STATE === MOB_STATES.READY) && MOB_front.valid
    

    io.backend_memory_request.bits.addr         := MOB_front.address
    io.backend_memory_request.bits.memory_type  := MOB_front.memory_type
    io.backend_memory_request.bits.access_width := MOB_front.access_width
    io.backend_memory_request.bits.PRD          := MOB_front.PRD
    io.backend_memory_request.bits.ROB_index    := MOB_front.ROB_index
    io.backend_memory_request.bits.MOB_index    := front_index
    io.backend_memory_request.bits.mem_signed   := MOB_front.mem_signed
    io.backend_memory_request.bits.packet_index := MOB_front.fetch_packet_index

    // SB => {data, data, data, data}
    // SH => {data, data}
    // SW => {HW}
    when(MOB_front.access_width === access_width_t.B){
        io.backend_memory_request.bits.data := Fill(4, MOB_front.data(7, 0))
    }.elsewhen(MOB_front.access_width === access_width_t.HW){
        io.backend_memory_request.bits.data := Fill(2, MOB_front.data(15, 0))
    }.otherwise{
        io.backend_memory_request.bits.data := MOB_front.data
    }

    

    // SEND REQUEST
    when(io.backend_memory_request.fire){   // entry requested
        //MOB(front_index) := 0.U.asTypeOf(new MOB_entry(coreParameters))
        MOB(front_index).MOB_STATE := MOB_STATES.REQUESTED
        MOB(front_index).counter := MOB(front_index).counter + 1.U
        req_reg          := io.backend_memory_request.bits
    }

    for(i <- 0 until MOBEntries){
        when(MOB(i).valid && MOB(i).MOB_STATE === MOB_STATES.REQUESTED){
            MOB(i).counter := MOB(front_index).counter + 1.U
            when(MOB(i).counter === 2.U && MOB(i).memory_type === memory_type_t.STORE){ // stores are successfull when they are requested and dont get nacked in 2 cycles
                MOB(i).MOB_STATE := MOB_STATES.DONE
            }
        }
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
        when(MOB(response_index).valid){
            when(io.backend_memory_response.bits.nack){
                MOB(response_index).MOB_STATE := MOB_STATES.NACKED
            }.otherwise{
                MOB(response_index).MOB_STATE := MOB_STATES.DONE
            }
        }
    }


    // HANDLE NACK
    when(MOB(front_index).valid && MOB(front_index).MOB_STATE === MOB_STATES.NACKED){
        MOB(front_index).MOB_STATE := MOB_STATES.READY  // set to ready and try again
    }

    // FREE ENTRY
    when(MOB(front_index).MOB_STATE === MOB_STATES.DONE){ // entry response
        when(!io.flush.valid || comb_committed(front_index)){
            front_pointer := front_pointer + 1.U
        }


        MOB(front_index) := 0.U.asTypeOf(new MOB_entry(coreParameters))
    }

    




    // cache response



    // Create a default zeroed-out decoupled wire for memory response
    val memory_response = WireInit(0.U.asTypeOf(Decoupled(new FU_output(coreParameters))))

    // Extract indices and types
    val response_index  = io.backend_memory_response.bits.MOB_index
    val response_type   = MOB(response_index).data_type

    // Populate `memory_response` only when valid and not nacked
    memory_response.valid                   := io.backend_memory_response.valid && !io.backend_memory_response.bits.nack
    memory_response.bits.ROB_index           := MOB(response_index).ROB_index
    memory_response.bits.MOB_index           := io.backend_memory_response.bits.MOB_index
    memory_response.bits.address             := io.backend_memory_response.bits.addr
    memory_response.bits.PRD                 := MOB(response_index).PRD
    memory_response.bits.RD_data             := io.backend_memory_response.bits.data
    memory_response.bits.RD_valid            := io.backend_memory_response.valid
    memory_response.bits.fetch_packet_index  := MOB(response_index).fetch_packet_index

    io.INT_MOB_output.valid := 0.B
    io.INT_MOB_output.bits  := 0.U.asTypeOf(new FU_output(coreParameters))

    if(coreConfig.contains("F")){
        io.FP_MOB_output.get.valid  := 0.B
        io.FP_MOB_output.get.bits   := 0.U.asTypeOf(new FU_output(coreParameters))
    }

    when(response_type === data_type_t.INT) {
        io.INT_MOB_output <> memory_response
    }.elsewhen(response_type === data_type_t.FP) {
        if(coreConfig.contains("F")){
            io.FP_MOB_output.get  <> memory_response
        }
    }.otherwise {
        assert(false.B, "INVALID MEMORY RESPONSE DATA TYPE!")
    }



//    when(MOB(front_index).valid && MOB(front_index).MOB_STATE === MOB_STATES.DONE && MOB(front_index).memory_type === memory_type_t.STORE){
        //io.MOB_output.bits.ROB_index            := MOB(front_index).ROB_index
        ////io.MOB_output.bits.MOB_index            := MOB(front_index).MOB_index
        //io.MOB_output.bits.address              := MOB(front_index).address
        ////io.MOB_output.bits.PRD                  := MOB(front_index).PRD
        ////io.MOB_output.bits.RD_data              := MOB(front_index).RD_data
        ////io.MOB_output.bits.RD_valid             := MOB(front_index).RD_valid
        //io.MOB_output.bits.fetch_packet_index   := MOB(front_index).fetch_packet_index //io.backend_memory_response.bits.fetch_packet_index
        //io.MOB_output.valid                     := 1.B
    //}


    when(io.flush.valid){
        for(i <- 0 until MOBEntries){
            val clear = !comb_committed(i) && MOB(i).valid
            when(clear){
                MOB(i) := 0.U.asTypeOf(new MOB_entry(coreParameters))
            }
        }
        back_pointer := front_pointer + committed_entries
    }


    dontTouch(committed_entries)
    dontTouch(front_index)
    dontTouch(back_index)


    ///////////
    // READY //
    ///////////


    for(i<-0 until memPortCount){
        io.AGU_output.ready := 1.B  // always ready to accept a resolved address
    }

    io.backend_memory_response.ready := 1.B

    val availalbe_MOB_entries = PopCount(~Cat(MOB.map(_.valid)))
    
    for (i <- 0 until fetchWidth){
        io.reserve(i).ready := (availalbe_MOB_entries >= fetchWidth.U) && !io.flush.valid
    }

}
