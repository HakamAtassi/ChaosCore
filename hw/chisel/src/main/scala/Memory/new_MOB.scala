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


class new_MOB(coreParameters:CoreParameters) extends Module{
    import coreParameters._
    val portCount       = getPortCount(coreParameters)
    val portCountBits   = log2Ceil(portCount)

    val memPortCount = FUParamSeq.count(_.supportsAddressGeneration)
    val nonMemoryPortCount = portCount - memPortCount 


    val ptr_width = log2Ceil(LOADQEntries) + 1

    val io = IO(new Bundle{
        // FLUSH //

        val flush               =     Flipped(ValidIO(new flush(coreParameters)))

        // ALLOCATE //
        val reserve                 =      Vec(fetchWidth, Flipped(Decoupled(new decoded_instruction(coreParameters))))         // reserve entry (rename)
        val s_reserved_pointers     =      Vec(fetchWidth, ValidIO(UInt(log2Ceil(STOREQEntries).W)))                               // pointer to allocated entry
        val l_reserved_pointers     =      Vec(fetchWidth, ValidIO(UInt(log2Ceil(LOADQEntries).W)))  

        val fetch_PC                =      Input(UInt(32.W))                                                                  // DEBUG

        val AGU_output              =      Vec(memPortCount, Flipped(Decoupled(new FU_output(coreParameters))))                                      // update address (AGU)
        val MOB_output              =      Decoupled(new FU_output(coreParameters))                                               // broadcast load data

        // REDIRECTS // 
        val commit                  =      Flipped(ValidIO(new commit(coreParameters)))                                         // commit mem op

        ///////////////////////////
        // D$ BACKEND MEM ACCESS //
        ///////////////////////////
        val backend_memory_request              =   Decoupled(new backend_memory_request(coreParameters))
        val backend_memory_response             =   Flipped(Decoupled(new backend_memory_response(coreParameters)))

    }); dontTouch(io)


    ///////////////////////
    // LOAD/STORE QUEUES //
    ///////////////////////

    val LOAD_Q  = RegInit(VecInit(Seq.fill(LOADQEntries)(0.U.asTypeOf(new MOB_entry(coreParameters)))));
    val STORE_Q = RegInit(VecInit(Seq.fill(STOREQEntries)(0.U.asTypeOf(new MOB_entry(coreParameters)))));
    

    val s_front_pointer   = RegInit(UInt(ptr_width.W), 0.U)
    val s_back_pointer    = RegInit(UInt(ptr_width.W), 0.U)

    val s_front_index     = s_front_pointer(ptr_width-2, 0)
    val s_back_index      = s_back_pointer(ptr_width-2, 0)

    val l_front_pointer   = RegInit(UInt(ptr_width.W), 0.U)
    val l_back_pointer    = RegInit(UInt(ptr_width.W), 0.U)

    val l_front_index     = l_front_pointer(ptr_width-2, 0)
    val l_back_index      = l_back_pointer(ptr_width-2, 0)

    val LOADQ_front       = LOAD_Q(l_front_index)
    val STOREQ_front      = STORE_Q(s_front_index)


    //////////////////////
    // ALLOCATE/RESERVE //
    //////////////////////

    // Update MOB
    val written_vec_l = Wire(Vec(fetchWidth, Bool())) // help avoid bubbles during allocation
    val written_vec_s = Wire(Vec(fetchWidth, Bool()))

    for(i <- 0 until fetchWidth){
        written_vec_l(i) := 0.B
        written_vec_s(i) := 0.B
        when(io.reserve(i).fire && io.reserve(i).bits.memory_type === memory_type_t.LOAD){
            written_vec_l(i) := 1.B
        }.elsewhen(io.reserve(i).fire && io.reserve(i).bits.memory_type === memory_type_t.STORE){
            written_vec_s(i) := 1.B
        }
    }

    for(i <- 0 until fetchWidth){   // reserve MOB index
        io.s_reserved_pointers(i).valid := 0.U
        io.s_reserved_pointers(i).bits  := 0.U
        io.l_reserved_pointers(i).valid := 0.U
        io.l_reserved_pointers(i).bits  := 0.U
        when(written_vec_l(i) || written_vec_s(i)){

            val MOB_entry = Wire(new MOB_entry(coreParameters))
            MOB_entry := DontCare

            MOB_entry.valid                :=  1.B
            MOB_entry.MOB_STATE            :=  MOB_STATES.VALID
            MOB_entry.memory_type          :=  io.reserve(i).bits.memory_type
            MOB_entry.access_width         :=  io.reserve(i).bits.access_width
            MOB_entry.PRD                  :=  io.reserve(i).bits.PRD
            MOB_entry.ROB_index            :=  io.reserve(i).bits.ROB_index
            MOB_entry.fetch_packet_index   :=  io.reserve(i).bits.packet_index
            MOB_entry.mem_signed           :=  io.reserve(i).bits.mem_signed

            when (written_vec_l(i)){

                val index_offset = PopCount(written_vec_l.take(i+1))-1.U
                LOAD_Q(l_back_index + index_offset)                 := MOB_entry
                io.l_reserved_pointers(i).bits                        := l_back_index + index_offset
                io.l_reserved_pointers(i).valid                       := 1.U
            }

            when(written_vec_s(i)){

                val index_offset = PopCount(written_vec_s.take(i+1))-1.U
                STORE_Q(s_back_index + index_offset)                := MOB_entry
                io.s_reserved_pointers(i).bits                        := s_back_index + index_offset
                io.s_reserved_pointers(i).valid                       := 1.U
            }

        }

    }

    s_back_pointer := s_back_pointer + PopCount(written_vec_s)
    l_back_pointer := l_back_pointer + PopCount(written_vec_l)




    ////////////////
    // AGU UPDATE //
    ////////////////

    for(i <- 0 until memPortCount){

        //TRY TO LOAD FWD. PUSH TO QUEUE IF UNABLE
        val AGU_index_l = io.AGU_output(i).bits.LOADQ_index
        when(io.AGU_output(i).valid && io.AGU_output(i).bits.memory_type === memory_type_t.LOAD){
            LOAD_Q(AGU_index_l).address  := io.AGU_output(i).bits.address
            LOAD_Q(AGU_index_l).data  := io.AGU_output(i).bits.wr_data
            LOAD_Q(AGU_index_l).resolved := 1.B
        }

        //PUSH ALL STORES TO QUEUE
        val AGU_index_s = io.AGU_output(i).bits.STOREQ_index
        when(io.AGU_output(i).valid && io.AGU_output(i).bits.memory_type === memory_type_t.STORE){
            STORE_Q(AGU_index_s).address  := io.AGU_output(i).bits.address
            STORE_Q(AGU_index_s).data  := io.AGU_output(i).bits.wr_data
            STORE_Q(AGU_index_s).resolved := 1.B
        }
    }


    // ///////////////////
    // // COMMIT UPDATE //
    // ///////////////////

    val loads_committed = Wire(Vec(LOADQEntries, Bool()))
    loads_committed := LOAD_Q.map(MOB_entry => MOB_entry.committed)

    val stores_committed = Wire(Vec(STOREQEntries, Bool()))
    stores_committed := STORE_Q.map(MOB_entry => MOB_entry.committed)

    for(i <- 0 until fetchWidth){
        when(io.commit.bits.insn_commit(i).valid && io.commit.bits.insn_commit(i).bits.WB_committed && LOAD_Q(io.commit.bits.insn_commit(i).bits.LOADQ_index).valid &&
         (io.commit.bits.ROB_index === LOAD_Q(io.commit.bits.insn_commit(i).bits.LOADQ_index).ROB_index) && io.commit.bits.insn_commit(i).bits.MOB_valid && io.commit.bits.insn_commit(i).bits.LOAD){
            loads_committed(io.commit.bits.insn_commit(i).bits.LOADQ_index) := 1.B
        }
        when(io.commit.bits.insn_commit(i).valid && io.commit.bits.insn_commit(i).bits.WB_committed && STORE_Q(io.commit.bits.insn_commit(i).bits.STOREQ_index).valid && 
        (io.commit.bits.ROB_index === STORE_Q(io.commit.bits.insn_commit(i).bits.STOREQ_index).ROB_index) && io.commit.bits.insn_commit(i).bits.MOB_valid && io.commit.bits.insn_commit(i).bits.STORE){
            stores_committed(io.commit.bits.insn_commit(i).bits.STOREQ_index) := 1.B
        }
    }

    for(i <- 0 until LOADQEntries){
        LOAD_Q(i).committed  := loads_committed(i)
    }

    for (i <- 0 until STOREQEntries){
        STORE_Q(i).committed := stores_committed(i)
    }

    // ///////////
    // // FLUSH //
    // ///////////
    val committed_load_entries = PopCount(loads_committed.zip(LOAD_Q).map { case (committed, mobEntry) => committed && mobEntry.valid })
    val committed_store_entries  = PopCount(stores_committed.zip(STORE_Q).map { case (committed, mobEntry) => committed && mobEntry.valid })


    
    // // ENTRY FSM

    for(i <- 0 until LOADQEntries){
        when(LOAD_Q(i).resolved && LOAD_Q(i).in(MOB_STATES.VALID)){  
            LOAD_Q(i).MOB_STATE := MOB_STATES.READY
        }
    }

    for(i <- 0 until STOREQEntries){
        when(STORE_Q(i).committed && STORE_Q(i).resolved && STORE_Q(i).in(MOB_STATES.VALID)){  
            STORE_Q(i).MOB_STATE := MOB_STATES.READY
        }
    }


    ///////////
    // CACHE //
    ///////////

    // cache request. priotity goes to loads
    io.backend_memory_request.bits   := 0.U.asTypeOf(new backend_memory_request(coreParameters))
    io.backend_memory_request.valid  := 0.B
    when((LOADQ_front.MOB_STATE === MOB_STATES.READY) && LOADQ_front.valid){
        io.backend_memory_request.valid  := 1.B

        io.backend_memory_request.bits.addr         := LOADQ_front.address
        io.backend_memory_request.bits.memory_type  := LOADQ_front.memory_type
        io.backend_memory_request.bits.access_width := LOADQ_front.access_width
        io.backend_memory_request.bits.PRD          := LOADQ_front.PRD
        io.backend_memory_request.bits.ROB_index    := LOADQ_front.ROB_index
        io.backend_memory_request.bits.MOB_index    := l_front_index
        io.backend_memory_request.bits.mem_signed   := LOADQ_front.mem_signed
        io.backend_memory_request.bits.packet_index := LOADQ_front.fetch_packet_index

        when(io.backend_memory_request.fire){   // entry requested
            //MOB(front_index) := 0.U.asTypeOf(new MOB_entry(coreParameters))
            LOADQ_front.MOB_STATE := MOB_STATES.REQUESTED
        }

    }.elsewhen((STOREQ_front.MOB_STATE === MOB_STATES.READY) && STOREQ_front.valid){
        io.backend_memory_request.valid  := 1.B

        io.backend_memory_request.bits.addr         := STOREQ_front.address
        io.backend_memory_request.bits.memory_type  := STOREQ_front.memory_type
        io.backend_memory_request.bits.access_width := STOREQ_front.access_width
        io.backend_memory_request.bits.PRD          := STOREQ_front.PRD
        io.backend_memory_request.bits.ROB_index    := STOREQ_front.ROB_index
        io.backend_memory_request.bits.MOB_index    := s_front_index
        io.backend_memory_request.bits.mem_signed   := STOREQ_front.mem_signed
        io.backend_memory_request.bits.packet_index := STOREQ_front.fetch_packet_index

        // SB => {data, data, data, data}
        // SH => {data, data}
        // SW => {HW}
        when(STOREQ_front.access_width === access_width_t.B){
            io.backend_memory_request.bits.data := Fill(4, STOREQ_front.data(7, 0))
        }.elsewhen(STOREQ_front.access_width === access_width_t.HW){
            io.backend_memory_request.bits.data := Fill(2, STOREQ_front.data(15, 0))
        }.otherwise{
            io.backend_memory_request.bits.data := STOREQ_front.data
        }

        when(io.backend_memory_request.fire){   // entry requested
            //MOB(front_index) := 0.U.asTypeOf(new MOB_entry(coreParameters))
            STOREQ_front.MOB_STATE := MOB_STATES.REQUESTED
            STOREQ_front.counter := STOREQ_front.counter + 1.U
        }
    }
    

    //WAIT FOR STORE TO SUCESSFULLY SEND
    for(i <- 0 until STOREQEntries){
        when(STORE_Q(i).valid && STORE_Q(i).MOB_STATE === MOB_STATES.REQUESTED){
            STORE_Q(i).counter := STOREQ_front.counter + 1.U
            when(STORE_Q(i).counter === 2.U){ // stores are successfull when they are requested and dont get nacked in 2 cycles
                STORE_Q(i).MOB_STATE := MOB_STATES.DONE
            }
        }
    }



    // AWAIT NACK
    {
        val response_index = io.backend_memory_response.bits.MOB_index
        // NACK
        when(io.backend_memory_response.bits.nack){
            LOAD_Q(response_index).MOB_STATE := MOB_STATES.NACKED
        }
    }

    // AWAIT RESPONSE
    when(io.backend_memory_response.fire){ // entry response
        val response_index = io.backend_memory_response.bits.MOB_index
        val response_addr  = io.backend_memory_response.bits.addr 
        // NACK
        when(LOAD_Q(response_index).valid && response_addr === LOAD_Q(response_index).address){
            when(io.backend_memory_response.bits.nack){
                LOAD_Q(response_index).MOB_STATE := MOB_STATES.NACKED
            }.otherwise{
                LOAD_Q(response_index).MOB_STATE := MOB_STATES.DONE
            }
        }
    }


    // HANDLE NACK
    when(LOADQ_front.valid && LOADQ_front.MOB_STATE === MOB_STATES.NACKED){
        LOADQ_front.MOB_STATE := MOB_STATES.READY  // set to ready and try again
    }

    // FREE ENTRY
    when(LOADQ_front.MOB_STATE === MOB_STATES.DONE){ // entry response
        when(!io.flush.valid || loads_committed(l_front_index)){
            l_front_pointer := l_front_pointer + 1.U
        }
        LOADQ_front := 0.U.asTypeOf(new MOB_entry(coreParameters))
    }

    when(STOREQ_front.MOB_STATE === MOB_STATES.DONE){ // entry response
        when(!io.flush.valid || stores_committed(s_front_index)){
            s_front_pointer := s_front_pointer + 1.U
        }
        STOREQ_front := 0.U.asTypeOf(new MOB_entry(coreParameters))
    }



    // cache response
    io.MOB_output.bits                      := 0.U.asTypeOf(new FU_output(coreParameters))
    io.MOB_output.bits.address              := io.backend_memory_response.bits.addr
    io.MOB_output.bits.RD_data              := io.backend_memory_response.bits.data
    io.MOB_output.bits.RD_valid             := io.backend_memory_response.valid
    io.MOB_output.valid                     := io.backend_memory_response.valid && !io.backend_memory_response.bits.nack

    when (io.backend_memory_response.bits.memory_type === memory_type_t.LOAD){
        io.MOB_output.bits.ROB_index            := LOAD_Q(io.backend_memory_response.bits.MOB_index).ROB_index
        io.MOB_output.bits.LOADQ_index          := io.backend_memory_response.bits.MOB_index
        io.MOB_output.bits.PRD                  := LOAD_Q(io.backend_memory_response.bits.MOB_index).PRD
        io.MOB_output.bits.fetch_packet_index   := LOAD_Q(io.backend_memory_response.bits.MOB_index).fetch_packet_index
    }.elsewhen(io.backend_memory_response.bits.memory_type === memory_type_t.STORE){
        io.MOB_output.bits.ROB_index            := STORE_Q(io.backend_memory_response.bits.MOB_index).ROB_index
        io.MOB_output.bits.STOREQ_index          := io.backend_memory_response.bits.MOB_index
        io.MOB_output.bits.PRD                  := STORE_Q(io.backend_memory_response.bits.MOB_index).PRD
        io.MOB_output.bits.fetch_packet_index   := STORE_Q(io.backend_memory_response.bits.MOB_index).fetch_packet_index
    }


    when(io.flush.valid){
        for(i <- 0 until LOADQEntries){
            val clear = !loads_committed(i) && LOAD_Q(i).valid
            when(clear){
                LOAD_Q(i) := 0.U.asTypeOf(new MOB_entry(coreParameters))
            }
        }
        l_back_pointer := l_front_pointer + committed_load_entries


        for(i <- 0 until STOREQEntries){
            val clear = !stores_committed(i) && STORE_Q(i).valid
            when(clear){
                STORE_Q(i) := 0.U.asTypeOf(new MOB_entry(coreParameters))
            }
        }
        s_back_pointer := s_front_pointer + committed_store_entries
    }


    dontTouch(committed_load_entries)
    dontTouch(l_front_index)
    dontTouch(l_back_index)

    dontTouch(committed_store_entries)
    dontTouch(s_front_index)
    dontTouch(s_back_index)


    ///////////
    // READY //
    ///////////


    for(i<-0 until memPortCount){
        io.AGU_output(i).ready := 1.B  // always ready to accept a resolved address
    }

    io.backend_memory_response.ready := 1.B

    val available_LOAD_entries = PopCount(~Cat(LOAD_Q.map(_.valid)))
    val available_STORE_entries = PopCount(~Cat(STORE_Q.map(_.valid)))
    
    for (i <- 0 until fetchWidth){
        io.reserve(i).ready := (available_LOAD_entries >= fetchWidth.U) && (available_STORE_entries >= fetchWidth.U) && !io.flush.valid
    }

}
