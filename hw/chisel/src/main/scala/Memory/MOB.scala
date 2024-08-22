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
import circt.stage.ChiselStage 

import chisel3.util._
import getPortCount._




/*  Opeartion
*
*   // ALLOCATE //
*   On Allocate, reserve an entry for the Load/Store instruction.
*   
*   // AGU OUT //
*   On AGU output, buffer Adderess + Data (store only) into MOB. Set pending = 1
*   If Store, search for younger conflicting loads that have already written to FU. If found, set exception
*   If Load, search for younger conflicting loads that have already written to FU. If found, set exception
*
*   // CACHE ACCESS //
*   Every cycle, check MOB for any pending pending loads. If load found & cache is ready, request load. Set pending = 0
*   If no loads (cache port free) and cache is ready, send MOB head to cache if store and pending and commited and not exception. Set pending = 0
*
*   // POINTERS //
*   Front pointer increments (DQ) if valid & not pending & completed & committed
*
*   // FLUSH //
*   If flush (mispred or exception): clear entries, reset pointers. 
*
*   // COMMIT //
*   Set commited for all entries with the same ROB index as commit input
*   
*   // CACHE RESPONSE //   
*   Write response data to MOB. Mark data as valid. Load only...
*   
*   // FU OUTPUT //
*   Select earliest load with valid data that hasnt been written to FU yet (!completed & data_valid)
*   If load queue ready, Merge with earlier stores, write to queue. Set completed  
*   Select earliest store that is (pending & !completed)
*   If store queue ready, write to queue. Set completed
*
*/


/* Operation (improved/cleaner)

// On decode, the core reserves a spot for memory operations.

// On AGU output, the address/data fields of the memory entries are updated.

// On AGU output:
//      - if load, request read from cache
//      - if store, check for load conflicts that have already written their result. If found, mark violation bit. If none found, do nothing.

// On cache response, look up MOB for data to merge, do the merge, then output data. 

// When entry at top of MOB, if complete & no issues (no violation, etc), set complete bit in ROB
// If violation (load-store, etc...), set violation bit and complete bit in ROB. 

*/



class MOB(coreParameters:CoreParameters) extends Module{
    import coreParameters._
    val portCount       = getPortCount(coreParameters)
    val portCountBits   = log2Ceil(portCount)

    val ptr_width = log2Ceil(MOBEntries) + 1

    val io = IO(new Bundle{
        // FLUSH //
        val flush                   =      Input(Bool())

        // ALLOCATE //
        val reserve                 =      Vec(fetchWidth, Flipped(Decoupled(new decoded_instruction(coreParameters))))         // reserve entry (rename)
        val reserved_pointers       =      Vec(fetchWidth, ValidIO(UInt(log2Ceil(MOBEntries).W)))                           // pointer to allocated entry

        val fetch_PC                =      Input(UInt(32.W))                                                                // DEBUG

        //val complete              =      ValidIO(new FU_output(coreParameters))                                               // update ROB (front of MOB)

        val AGU_output              =      Flipped(ValidIO(new FU_output(coreParameters)))                                      // update address (AGU)

        val MOB_output              =      ValidIO(new FU_output(coreParameters))                                               // broadcast load data

        // REDIRECTS // 
        val commit                  =      Flipped(ValidIO(new commit(coreParameters)))                                         // commit mem op

        //val RF_inputs               =      Vec(portCount, Decoupled(new decoded_instruction(coreParameters)))                   // write RD

        ///////////////////////////
        // D$ BACKEND MEM ACCESS //
        ///////////////////////////
        val backend_memory_request              =   Decoupled(new backend_memory_request(coreParameters))
        val backend_memory_response             =   Flipped(Decoupled(new backend_memory_response(coreParameters)))

    }); dontTouch(io)

    val front_pointer   = RegInit(UInt(ptr_width.W), 0.U)
    val back_pointer    = RegInit(UInt(ptr_width.W), 0.U)

    val front_index     = front_pointer(ptr_width-2, 0)
    val back_index      = back_pointer(ptr_width-2, 0)

    val MOB = RegInit(VecInit(Seq.fill(MOBEntries)(0.U.asTypeOf(new MOB_entry(coreParameters)))))

    /////////////////////////
    // GENERATE AGE VECTOR //
    /////////////////////////
    val age_vector          = Wire(Vec(MOBEntries, UInt((ptr_width - 1).W)))
    val age_valid_vector    = Wire(Vec(MOBEntries, UInt((ptr_width - 1).W)))

    // Give each mob entry an age.
    // Mob entry @ front pointer will have value of MAX
    // Mob entry @ back pointer will have value of MAX - number of entries
    for(i <- 0 until MOBEntries){
        age_vector(i)       := (i.U - front_index) % MOBEntries.U // FIXME: make sure this isnt generating extra hardware...
        age_valid_vector(i) := MOB(i).valid
    }


    //////////////////////
    // ALLOCATE/RESERVE //
    //////////////////////
    val written_vec = Wire(Vec(fetchWidth, Bool()))

    for(i <- 0 until fetchWidth){
        written_vec(i) := 0.B
        when(io.reserve(i).valid && io.reserve(i).ready){
            written_vec(i) := 1.B
        }
    }

    for(i <- 0 until fetchWidth){   // reserve mob index
        io.reserved_pointers(i).valid := 0.U
        io.reserved_pointers(i).bits  := 0.U
        when(written_vec(i)){
            val index_offset = PopCount(written_vec.take(i+1))-1.U

            MOB(back_index + index_offset).valid                :=  1.B
            MOB(back_index + index_offset).memory_type          :=  io.reserve(i).bits.memory_type
            MOB(back_index + index_offset).access_width         :=  io.reserve(i).bits.access_width
            MOB(back_index + index_offset).RD                   :=  io.reserve(i).bits.RD
            MOB(back_index + index_offset).ROB_index            :=  io.reserve(i).bits.ROB_index
            MOB(back_index + index_offset).fetch_packet_index   :=  io.reserve(i).bits.packet_index

            io.reserved_pointers(i).bits                        := back_index + index_offset
            io.reserved_pointers(i).valid                       := 1.U
        }
    }

    back_pointer := back_pointer + PopCount(written_vec)


    /////////////
    // AGU OUT //
    /////////////
    // Write data
    val MOB_index                       = io.AGU_output.bits.MOB_index
    val address                         = io.AGU_output.bits.address
    val data                            = io.AGU_output.bits.wr_data


    // merge data then write load to load FU queue
    val response_age = Wire(UInt((ptr_width-1).W))
    val byte_sels    = Wire(Vec(MOBEntries, UInt(4.W)))
    val wr_bytes     = Wire(Vec(MOBEntries, Vec(4, UInt(8.W))))
    val data_out     = Wire(Vec(4, UInt(8.W)))
    when(io.AGU_output.valid){
        MOB(MOB_index).pending         := 1.B
        MOB(MOB_index).address         := address
        MOB(MOB_index).data            := data
    }

    dontTouch(MOB)

    // Check exception
    val incoming_is_valid       = io.AGU_output.valid
    val incoming_address        = io.AGU_output.bits.address
    val incoming_age            = age_vector(io.AGU_output.bits.MOB_index)
    val incoming_is_load        = io.AGU_output.bits.memory_type === memory_type_t.LOAD
    val incoming_is_store       = io.AGU_output.bits.memory_type === memory_type_t.STORE

    val store_store_violation   = Wire(Vec(MOBEntries, Bool())) // Not a real violation. If any bits are set, terminate search
    store_store_violation := VecInit(Seq.fill(MOBEntries)(0.B))


    // violation checks
    for(i <- 0 until MOBEntries){
        val is_valid        = MOB(i).valid
        val is_younger      = age_vector(i) < incoming_age
        val is_conflicting  = incoming_address === (get_fetch_packet_aligned_address(coreParameters, MOB(i).address))

        val is_load         = MOB(i).memory_type === memory_type_t.LOAD
        val is_store        = MOB(i).memory_type === memory_type_t.STORE
        val is_complete     = MOB(i).completed
        val is_pending      = MOB(i).pending

        when(io.AGU_output.valid && is_younger && is_conflicting && is_valid && (PopCount(store_store_violation.take(i)) === 0.U)){
            when(incoming_is_load && is_load && is_complete){                    // load load violation
                MOB(i).exception := 1.B
            }.elsewhen(incoming_is_store && is_load && is_complete){             // store load violation
                MOB(i).exception := 1.B
            }.elsewhen(incoming_is_store && is_store && is_pending){                // store store "violation"
                store_store_violation(i) := 1.B
            }
        }
    }


    //////////////////
    // CACHE ACCESS //
    //////////////////
    // Check for pending loads, send to memory as needed
    val fire_store = Wire(Bool())

    io.backend_memory_request.bits   := 0.U.asTypeOf(new backend_memory_request(coreParameters))
    io.backend_memory_request.valid  := 0.B

    val possible_load_vec = Wire(Vec(MOBEntries, Bool()))

    // FIXME: need to add cache ready check + FSM/skidbuffer stuff...
    possible_load_vec    := MOB.map(MOB_entry => MOB_entry.valid && MOB_entry.pending && (MOB_entry.memory_type === memory_type_t.LOAD))
    fire_store           := MOB(front_index).valid && MOB(front_index).committed && MOB(front_index).pending && !MOB(front_index).exception && (MOB(front_index).memory_type === memory_type_t.STORE)    // stores are sent only from front of queue

    when(possible_load_vec.asUInt =/= 0.U){    // possible load, do that
        val load_index                               = PriorityEncoder(possible_load_vec)
        io.backend_memory_request.valid             := 1.B
        io.backend_memory_request.bits.addr         := MOB(load_index).address
        io.backend_memory_request.bits.memory_type  := MOB(load_index).memory_type
        io.backend_memory_request.bits.access_width := MOB(load_index).access_width
        io.backend_memory_request.bits.MOB_index    := load_index

        when(io.backend_memory_request.fire){
            MOB(load_index).pending                     := 0.B
        }
    }.elsewhen(fire_store){
        io.backend_memory_request.valid             := 1.B
        io.backend_memory_request.bits.addr         := MOB(front_index).address
        io.backend_memory_request.bits.memory_type  := MOB(front_index).memory_type
        io.backend_memory_request.bits.access_width := MOB(front_index).access_width
        io.backend_memory_request.bits.data         := MOB(front_index).data
        io.backend_memory_request.bits.MOB_index    := front_index

        when(io.backend_memory_request.fire){
            MOB(front_index).pending                     := 0.B
        }
    }

    dontTouch(back_index)


    ///////////////////
    // UPDATE COMMIT //
    ///////////////////
    // Update commit bit
    for(i <- 0 until MOBEntries){
        when(MOB(i).valid && io.commit.valid && (MOB(i).ROB_index === io.commit.bits.ROB_index)){
            MOB(i).committed := 1.B
        }
    }

    //////////////
    // POINTERS //
    //////////////

    val is_committed       = MOB(front_index).committed
    val is_complete        = MOB(front_index).completed
    val is_valid           = MOB(front_index).valid
    val is_pending         = MOB(front_index).pending
    
    when(is_valid && !is_pending && is_complete && is_committed){
        MOB(front_index) := 0.U.asTypeOf(new MOB_entry(coreParameters))
        front_pointer    := front_pointer + 1.U
    }

    ///////////
    // FLUSH //
    ///////////
    when(io.commit.valid && (io.commit.bits.is_misprediction || io.commit.bits.exception)){   //FIXME: 
        for(i <- 0 until MOBEntries){
            MOB(i) := 0.U.asTypeOf(new MOB_entry(coreParameters))
        }
        front_pointer := 0.U
        back_pointer := 0.U
    }

    ////////////////////
    // CACHE RESPONSE //
    ////////////////////
    when(io.backend_memory_response.valid){
    }

    ///////////
    // MERGE //
    ///////////
    // Get MOB indices
    val FU_output_load_Q        = Module(new Queue(new FU_output(coreParameters), 4, flow=false, hasFlush=true, useSyncReadMem=false))
    val FU_output_store_Q       = Module(new Queue(new FU_output(coreParameters), 4, flow=false, hasFlush=true, useSyncReadMem=false))

    val possible_FU_loads       = Wire(Vec(MOBEntries, Bool()))
    val possible_FU_stores      = Wire(Vec(MOBEntries, Bool()))

    possible_FU_loads          := MOB.map(MOB_entry => MOB_entry.valid && !MOB_entry.completed && MOB_entry.data_valid && (MOB_entry.memory_type === memory_type_t.LOAD))
    possible_FU_stores         := MOB.map(MOB_entry => MOB_entry.valid && !MOB_entry.completed && (MOB_entry.pending && (MOB_entry.memory_type === memory_type_t.STORE)))

    val possible_FU_load_index  = PriorityEncoder(possible_FU_loads)
    val possible_FU_store_index = PriorityEncoder(possible_FU_stores)


    // write store to store FU queue
    FU_output_store_Q.io.enq.valid                        := possible_FU_stores.reduce(_ || _)
    FU_output_store_Q.io.enq.bits                         := DontCare
    FU_output_store_Q.io.enq.bits.exception               := MOB(possible_FU_store_index).exception
    FU_output_store_Q.io.enq.bits.ROB_index               := MOB(possible_FU_store_index).ROB_index
    FU_output_store_Q.io.enq.bits.fetch_packet_index      := MOB(possible_FU_store_index).fetch_packet_index
    FU_output_store_Q.io.flush.get                        := io.commit.valid && (io.commit.bits.is_misprediction || io.commit.bits.exception)

    when(FU_output_store_Q.io.enq.fire && !(io.commit.valid && (io.commit.bits.is_misprediction || io.commit.bits.exception))){
        MOB(possible_FU_store_index).completed := 1.B
    }



    response_age := age_vector(io.backend_memory_response.bits.MOB_index)


    // get byte mask and data for each row
    byte_sels    := MOB.map(MOB_entry => get_MOB_row_byte_sel(coreParameters, MOB_entry))
    wr_bytes     := MOB.map(MOB_entry => get_MOB_row_wr_bytes(coreParameters, MOB_entry))

    for(i <- 0 until 4){
        data_out(i)     := io.backend_memory_response.bits.data((i+1)*8-1,i*8)
    }

    for(i <- 0 until MOBEntries){    // forward from MOB
        val is_valid            = MOB(i).valid
        val is_younger          = age_vector(i) < response_age
        val is_conflicting      = MOB(i).address === MOB(io.backend_memory_response.bits.MOB_index).address

        val is_load             = MOB(i).memory_type === memory_type_t.LOAD
        val is_store            = MOB(i).memory_type === memory_type_t.STORE

        val fwd_address         = MOB(i).address        // 32 bit address
        val fwd_access_width    = MOB(i).access_width  // 1, 2, 4 (b, hw, w)

        when(is_valid && is_younger && is_conflicting && is_store){
            // found earlier conflicting store!
            // perform the forward
            for(j <- 0 until 4){
                when(byte_sels(i)(j)){
                    data_out(j) := wr_bytes(i)(j)
                }
            }
        }
    }

    when(io.backend_memory_response.valid && (MOB(io.backend_memory_response.bits.MOB_index).memory_type === memory_type_t.LOAD)){
        MOB(io.backend_memory_response.bits.MOB_index).data_valid   := 1.B
        MOB(io.backend_memory_response.bits.MOB_index).data := data_out.asUInt
    }

    dontTouch(data_out)
    dontTouch(wr_bytes)
    dontTouch(byte_sels)

    dontTouch(possible_FU_store_index)
    dontTouch(response_age)
    dontTouch(age_vector)

    dontTouch(MOB)
    dontTouch(front_index)

    FU_output_load_Q.io.enq.valid                     := possible_FU_loads.reduce(_ || _)
    FU_output_load_Q.io.enq.bits                      <> DontCare
    FU_output_load_Q.io.enq.bits.exception            := MOB(possible_FU_load_index).exception
    FU_output_load_Q.io.enq.bits.ROB_index            := MOB(possible_FU_load_index).ROB_index
    FU_output_load_Q.io.enq.bits.RD                   := MOB(possible_FU_load_index).RD
    FU_output_load_Q.io.enq.bits.fetch_packet_index   := MOB(possible_FU_load_index).fetch_packet_index
    FU_output_load_Q.io.enq.bits.RD_data              := MOB(possible_FU_load_index).data
    FU_output_load_Q.io.enq.bits.RD_valid             := 1.B

    FU_output_load_Q.io.flush.get := io.commit.valid && (io.commit.bits.is_misprediction || io.commit.bits.exception)
    when(FU_output_load_Q.io.enq.fire && !(io.commit.valid && (io.commit.bits.is_misprediction || io.commit.bits.exception))){
        MOB(possible_FU_load_index).completed := 1.B
    }

    val FU_output_arbiter       = Module(new Arbiter(new FU_output(coreParameters), 2))

    FU_output_arbiter.io.in(0) <> FU_output_load_Q.io.deq
    FU_output_arbiter.io.in(1) <> FU_output_store_Q.io.deq


    FU_output_arbiter.io.out.ready := 1.B

    dontTouch(FU_output_arbiter.io.out)

    io.backend_memory_response.ready := 1.B


    ///////////////
    // FU OUTPUT //
    ///////////////

    //io.MOB_output                   := DontCare
    io.MOB_output.valid             <> FU_output_arbiter.io.out.valid
    io.MOB_output.bits              <> FU_output_arbiter.io.out.bits
    io.MOB_output.bits.RD           := FU_output_arbiter.io.out.bits.RD
    io.MOB_output.bits.RD_valid     := FU_output_arbiter.io.out.bits.RD_valid
    io.MOB_output.bits.RD_data      := FU_output_arbiter.io.out.bits.RD_data

    ///////////
    // READY //
    ///////////

    val availalbe_MOB_entries = PopCount(~Cat(MOB.map(_.valid)))
    
    for (i <- 0 until fetchWidth){
        io.reserve(i).ready := availalbe_MOB_entries >= fetchWidth.U
    }




}
