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
        val reserved_pointers       =      Vec(fetchWidth, ValidIO(UInt(log2Ceil(MOBEntries).W)))                               // pointer to allocated entry

        //val fetch_PC                =      Input(UInt(32.W))                                                                  // DEBUG

        val complete                =      ValidIO(new FU_output(coreParameters))                                               // update ROB (front of MOB)
        val AGU_output              =      Flipped(ValidIO(new FU_output(coreParameters)))                                      // update address (AGU)
        val MOB_output              =      ValidIO(new FU_output(coreParameters))                                               // broadcast load data

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

    val MOB = RegInit(VecInit(Seq.fill(MOBEntries)(0.U.asTypeOf(new MOB_entry(coreParameters))))); dontTouch(MOB)


    val front_pointer   = RegInit(UInt(ptr_width.W), 0.U)
    val back_pointer    = RegInit(UInt(ptr_width.W), 0.U)

    val front_index     = front_pointer(ptr_width-2, 0)
    val back_index      = back_pointer(ptr_width-2, 0)

    ////////////////////////////
    // INDETERMINATION MATRIX //
    ////////////////////////////

    // Chisel does not allow for a vector with entries of different type, even if that type is defined to be a 
    // different number of Bool() regs. 
    // Instead, a matrix of UInts of different widths is used. 

    // The conversion is as follows:
    // Setting col 0 => Setting row N-1.
    // Setting col 1 => Setting row N-2
    // Reading row 0 => Reading col N-1
    // Reading row 1 => Reading col N-2
 	val matrix = RegInit(VecInit.tabulate(MOBEntries){x => 0.U((x+1).W) })

    def get_indetermination_matrix_row(row: UInt): UInt = {
        // from Row row, read bit 0, 
        // from Row row + 1, read bit 1
        // from Row row + N, read bit N
        // collect bits and return them as a UINT

        // Collect bits from each row entry and combine into a single UInt
        val bits = (0 until MOBEntries).map { i =>
            matrix(i)(row)
        }
        
        // Combine collected bits into a single UInt value
        VecInit(bits).asUInt
    }

    def set_indetermination_matrix_col(col:UInt): Unit = {
        matrix(MOBEntries.U - 1.U - col) := ((1<<MOBEntries)-1).U
    }

    def reset_indetermination_matrix_col(col:UInt): Unit = {
        matrix(MOBEntries.U - 1.U - col) := 0.U
    }

    /////////////////////////
    // GENERATE AGE VECTOR //
    /////////////////////////
    val age_vector          = Wire(Vec(MOBEntries, UInt((ptr_width - 1).W)))
    val age_valid_vector    = Wire(Vec(MOBEntries, UInt((ptr_width - 1).W)))


    // Give each mob entry an age.
    // Mob entry @ front pointer will have value of MAX
    // Mob entry @ back pointer will have value of MAX - number of entries
    for(i <- 0 until MOBEntries){
        val offset =  MOBEntries.U -1.U + front_index
        age_vector(i)       := offset - i.U
        age_valid_vector(i) := MOB(i).valid
    }


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

    for(i <- 0 until fetchWidth){   // reserve mob index
        io.reserved_pointers(i).valid := 0.U
        io.reserved_pointers(i).bits  := 0.U
        when(written_vec(i)){
            val index_offset = PopCount(written_vec.take(i+1))-1.U
            set_indetermination_matrix_col(back_index)

            MOB(back_index + index_offset).valid                :=  1.B
            MOB(back_index + index_offset).MOB_STATE            :=  MOB_STATES.VALID
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


    // Update indetermination matrix 

    /////////////
    // AGU OUT //
    /////////////


    val response_age = Wire(UInt((ptr_width-1).W))
    response_age := age_vector(io.backend_memory_response.bits.MOB_index)
    val byte_sels    = Wire(Vec(MOBEntries, Vec(4, Bool())))
    val wr_bytes     = Wire(Vec(MOBEntries, Vec(4, UInt(8.W))))

    byte_sels    := MOB.map(MOB_entry => get_MOB_row_byte_sel(coreParameters, MOB_entry))
    wr_bytes     := MOB.map(MOB_entry => get_MOB_row_wr_bytes(coreParameters, MOB_entry))

    //val data_out     = Wire(Vec(4, UInt(8.W)))

    val incoming_is_valid       = io.AGU_output.valid
    val incoming_address        = io.AGU_output.bits.address
    val incoming_age            = age_vector(io.AGU_output.bits.MOB_index)
    val incoming_is_load        = io.AGU_output.bits.memory_type === memory_type_t.LOAD
    val incoming_is_store       = io.AGU_output.bits.memory_type === memory_type_t.STORE

    val store_store_violation   = Wire(Vec(MOBEntries, Bool())) // Not a real violation. If any bits are set, terminate search
    store_store_violation       := VecInit(Seq.fill(MOBEntries)(0.B))

    // update entry //
    val MOB_index                       = io.AGU_output.bits.MOB_index
    when(io.AGU_output.valid){
        MOB(MOB_index).address         := io.AGU_output.bits.address
        MOB(MOB_index).data            := io.AGU_output.bits.wr_data

        // Update indet. matrix
        reset_indetermination_matrix_col(MOB_index)
        
        // Update MOB entry state
        when((MOB(MOB_index).memory_type === memory_type_t.LOAD) && MOB(MOB_index).valid){
            MOB(MOB_index).MOB_STATE       := MOB_STATES.READY
        }.elsewhen((MOB(MOB_index).memory_type === memory_type_t.STORE) && MOB(MOB_index).valid){
            MOB(MOB_index).MOB_STATE       := MOB_STATES.COMPLETE
        }
    }

    dontTouch(age_vector)

    dontTouch(wr_bytes)
    dontTouch(byte_sels)

    //  Input is Load //
    // Search for older conflicting stores. Merge as needed

    // search lower half

    for(b <- 0 until 4){
        for(i <- 0 until MOBEntries){
            val is_lower_half   = i.U > MOB_index
            val is_valid        = MOB(i).valid
            val is_older        = age_vector(i) > incoming_age

            // FIXME: conflicting should be for each byte, not each word...
            val is_conflicting  = (incoming_address & "hFFFFFFFC".U) === ("hFFFFFFFC".U & MOB(i).address) && byte_sels(i)(b)

            val is_store        = MOB(i).memory_type === memory_type_t.STORE
            val is_complete     = ((MOB(i).MOB_STATE === MOB_STATES.COMPLETE) || (MOB(i).MOB_STATE === MOB_STATES.WAIT) || (MOB(i).MOB_STATE === MOB_STATES.COMMITTED))

            when(io.AGU_output.valid && is_older && is_conflicting && is_valid){
                when(incoming_is_load && is_store && is_complete && is_lower_half){
                    MOB(MOB_index).fwd_valid(b) := byte_sels(i)(b)
                    MOB(MOB_index).fwd_data(b) := wr_bytes(i)(b)
                }
            }
        }
    }

    // search upper half

    for(b <- 0 until 4){
        for(i <- 0 until MOBEntries){

            val is_upper_half   = i.U < MOB_index
            val is_valid        = MOB(i).valid
            val is_older        = age_vector(i) > incoming_age

            // FIXME: conflicting should be for each byte, not each word...
            val is_conflicting  = (incoming_address & "hFFFFFFFC".U) === ("hFFFFFFFC".U & MOB(i).address) && byte_sels(i)(b)

            val is_store        = MOB(i).memory_type === memory_type_t.STORE
            val is_complete     = ((MOB(i).MOB_STATE === MOB_STATES.COMPLETE) || (MOB(i).MOB_STATE === MOB_STATES.WAIT) || (MOB(i).MOB_STATE === MOB_STATES.COMMITTED))

            when(io.AGU_output.valid && is_older && is_conflicting && is_valid){
                when(incoming_is_load && is_store && is_complete && is_upper_half){
                    MOB(MOB_index).fwd_valid(b) := byte_sels(i)(b)
                    MOB(MOB_index).fwd_data(b) := wr_bytes(i)(b)
                }
            }
        }
    }



    // Input is Store //
    // Search for younger conflicting loads. Set violation as needed.
    for(i <- 0 until MOBEntries){
        val is_valid        = MOB(i).valid
        val is_younger      = age_vector(i) < incoming_age
        val is_conflicting  = (incoming_address & "hFFFFFFFC".U) === ("hFFFFFFFC".U & MOB(i).address)
        val is_complete     = (MOB(i).MOB_STATE === MOB_STATES.COMPLETE) ||  (MOB(i).MOB_STATE === MOB_STATES.ALMOST_COMPLETE)
        val is_load         = MOB(i).memory_type === memory_type_t.LOAD
        val is_store        = MOB(i).memory_type === memory_type_t.STORE

        // FIXME: here, the conflicting depends on the TYPE of store and TYPE of load...
        when(io.AGU_output.valid && is_younger && is_conflicting && is_valid){
            when(incoming_is_store && is_load && is_complete){
                MOB(i).violation := 1.B
            }
        }
    }

    //////////////////
    // CACHE ACCESS //
    //////////////////
    // Select entry to write to memory


    // Attempt to fire a load to memory

    // If none found, fire the store at the front of the MOB if committed
    val fire_store          = Wire(Bool())
    val possible_load_vec   = Wire(Vec(MOBEntries, Bool()))

    io.backend_memory_request.bits   := 0.U.asTypeOf(new backend_memory_request(coreParameters))
    io.backend_memory_request.valid  := 0.B

    possible_load_vec    := MOB.map(MOB_entry => MOB_entry.valid && (MOB_entry.MOB_STATE === MOB_STATES.READY) && (MOB_entry.memory_type === memory_type_t.LOAD))
    fire_store           := MOB(front_index).valid && (MOB(front_index).MOB_STATE === MOB_STATES.COMMITTED) && !MOB(front_index).violation && (MOB(front_index).memory_type === memory_type_t.STORE)    // stores are sent only from front of queue

    val load_index                               = PriorityEncoder(possible_load_vec)
    when(MOB(load_index).valid && (MOB(load_index).MOB_STATE === MOB_STATES.READY) && (MOB(load_index).memory_type === memory_type_t.LOAD)){
        io.backend_memory_request.valid             := 1.B
        io.backend_memory_request.bits.addr         := MOB(load_index).address
        io.backend_memory_request.bits.memory_type  := MOB(load_index).memory_type
        io.backend_memory_request.bits.access_width := MOB(load_index).access_width
        io.backend_memory_request.bits.MOB_index    := load_index

        when(io.backend_memory_request.fire){
            MOB(load_index).MOB_STATE                   := MOB_STATES.REQUESTED
        }
    }.elsewhen(fire_store){
        io.backend_memory_request.valid             := 1.B
        io.backend_memory_request.bits.addr         := MOB(front_index).address
        io.backend_memory_request.bits.memory_type  := MOB(front_index).memory_type
        io.backend_memory_request.bits.access_width := MOB(front_index).access_width
        io.backend_memory_request.bits.data         := MOB(front_index).data
        io.backend_memory_request.bits.MOB_index    := front_index

        when(io.backend_memory_request.fire){
            MOB(front_index).MOB_STATE := MOB_STATES.DONE
        }
    }


    ////////////////////
    // CACHE RESPONSE //
    ////////////////////

    val test = Wire(UInt(2.W))
    val response_MOB_index = io.backend_memory_response.bits.MOB_index
    test := (MOB(response_MOB_index).address) & 0x3.U
    when(io.backend_memory_response.valid){
        when(MOB(response_MOB_index).memory_type === memory_type_t.LOAD){   // stores dont return anything
            MOB(response_MOB_index).MOB_STATE := MOB_STATES.CDB_WRITE   // update state
            MOB(response_MOB_index).data := io.backend_memory_response.bits.data << (test*8.U)  // this shift helps with forwarding logic (everything is aligned to the word)
        }
    }

    //////////////
    // CDB WRITE //
    ///////////////
    // Select entry to write to CDB.
    // Update state to almost complete or complete based on violation valid status

    // FIXME: this part is really not optimal
    // Currently, the forwarding forwards the entire word aligned data
    // then, that data is swizzled based on the required byte from the load
    // based on the buffered address

    val select_MOB_entry_for_CDB_WRITE = MOB.map(MOB_entry => (MOB_entry.valid) && (MOB_entry.memory_type === memory_type_t.LOAD) && (MOB_entry.MOB_STATE === MOB_STATES.CDB_WRITE))
    val CDB_write_index = Wire(UInt(log2Ceil(MOBEntries).W))
    CDB_write_index := PriorityEncoder(select_MOB_entry_for_CDB_WRITE)

    val merged_data = Wire(Vec(4, UInt(8.W)))
    merged_data := VecInit(Seq.fill(4)(0.U(8.W)))

    val word_offset = Wire(UInt(2.W)) 
    word_offset := (MOB(CDB_write_index).address & 0x3.U)

    for(i<-0 until 4){
        merged_data(i) := MOB(CDB_write_index).data((i+1)*8-1, i*8)
    }
    // forward word


    for(i <- 0 until 4){
        when(MOB(CDB_write_index).fwd_valid(i)){    // for W access, forward all colliding bits
            merged_data(i.U) := MOB(CDB_write_index).fwd_data(i.U)
        }
    }

    dontTouch(word_offset)

    io.MOB_output.valid                     := 0.B
    io.MOB_output.bits                      := 0.U.asTypeOf(new FU_output(coreParameters))

    when(MOB(CDB_write_index).valid && (MOB(CDB_write_index).memory_type === memory_type_t.LOAD) && (MOB(CDB_write_index).MOB_STATE === MOB_STATES.CDB_WRITE)){
        io.MOB_output.bits                      := DontCare
        io.MOB_output.valid                     := 1.B
        io.MOB_output.bits.ROB_index            := MOB(CDB_write_index).ROB_index // this should not do anything
        io.MOB_output.bits.MOB_index            := CDB_write_index
        io.MOB_output.bits.address              := MOB(CDB_write_index).address
        io.MOB_output.bits.RD                   := MOB(CDB_write_index).RD
        io.MOB_output.bits.fetch_packet_index   := MOB(CDB_write_index).fetch_packet_index
        
        when(MOB(CDB_write_index).access_width === access_width_t.W){
            io.MOB_output.bits.RD_data              := ((merged_data.asUInt) >> (word_offset*8.U))
        }.elsewhen(MOB(CDB_write_index).access_width === access_width_t.HW){
            io.MOB_output.bits.RD_data              := ((merged_data.asUInt) >> (word_offset*8.U)) & 0xFFFF.U
        }.elsewhen(MOB(CDB_write_index).access_width === access_width_t.B){
            io.MOB_output.bits.RD_data              := ((merged_data.asUInt) >> (word_offset*8.U)) & 0xFF.U
        }

        io.MOB_output.bits.RD_valid             := 1.B
    }

    when(MOB(CDB_write_index).valid && (MOB(CDB_write_index).MOB_STATE === MOB_STATES.CDB_WRITE) && (MOB(CDB_write_index).memory_type === memory_type_t.LOAD)){   // FIXME: what if load/store?
        when(get_indetermination_matrix_row(CDB_write_index).orR){
            MOB(CDB_write_index).MOB_STATE := MOB_STATES.ALMOST_COMPLETE
        }.otherwise{
            MOB(CDB_write_index).MOB_STATE := MOB_STATES.COMPLETE
        }
    }


    /////////////////////
    // VIOLATION VALID //
    /////////////////////
    // Update all entries in "almost complete" state to complete state
    // if violation valid bit is set
    for ((mobEntry, i) <- MOB.zipWithIndex) {
        when((get_indetermination_matrix_row(i.U(log2Ceil(MOBEntries).W)).orR === 0.B) && 
            (mobEntry.MOB_STATE === MOB_STATES.ALMOST_COMPLETE)) {
            mobEntry.MOB_STATE := MOB_STATES.COMPLETE
        }
    }

    /////////////////////
    // UPDATE COMPLETE //
    /////////////////////

    val MOB_update_commit = MOB.map(MOB_entry => (MOB_entry.valid) && (MOB_entry.MOB_STATE === MOB_STATES.COMPLETE))
    val selected_MOB_entry_for_commit = MOB(PriorityEncoder(MOB_update_commit))


    io.complete.valid               := 0.B
    io.complete.bits                := 0.U.asTypeOf(new FU_output(coreParameters))

    when(selected_MOB_entry_for_commit.valid && (selected_MOB_entry_for_commit.MOB_STATE === MOB_STATES.COMPLETE)){
        when(selected_MOB_entry_for_commit.memory_type === memory_type_t.LOAD){
            selected_MOB_entry_for_commit.MOB_STATE := MOB_STATES.DONE

            io.complete.valid          := selected_MOB_entry_for_commit.valid
            io.complete.bits.ROB_index := selected_MOB_entry_for_commit.ROB_index
            io.complete.bits.MOB_index := PriorityEncoder(MOB_update_commit)
            io.complete.bits.fetch_packet_index := selected_MOB_entry_for_commit.fetch_packet_index
            io.complete.bits.violation := selected_MOB_entry_for_commit.violation
        }.elsewhen(selected_MOB_entry_for_commit.memory_type === memory_type_t.STORE && (selected_MOB_entry_for_commit.MOB_STATE === MOB_STATES.COMPLETE)){
            selected_MOB_entry_for_commit.MOB_STATE := MOB_STATES.WAIT

            io.complete.valid          := selected_MOB_entry_for_commit.valid
            io.complete.bits.ROB_index := selected_MOB_entry_for_commit.ROB_index
            io.complete.bits.MOB_index := PriorityEncoder(MOB_update_commit)
            io.complete.bits.fetch_packet_index := selected_MOB_entry_for_commit.fetch_packet_index
            io.complete.bits.violation := selected_MOB_entry_for_commit.violation
        }
    }






    ///////////////////
    // UPDATE COMMIT //
    ///////////////////
    // Update commit bit
    for(i <- 0 until MOBEntries){
        when(MOB(i).valid && io.commit.valid && (MOB(i).ROB_index === io.commit.bits.ROB_index) && (MOB(i).memory_type === memory_type_t.STORE)){
            MOB(i).MOB_STATE := MOB_STATES.COMMITTED
        }
    }


    ////////////////
    // FREE FRONT //
    ////////////////
    val front_is_done       = MOB(front_index).MOB_STATE === MOB_STATES.DONE
    val front_is_valid      = MOB(front_index).valid
    
    when(front_is_valid && front_is_done){
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


    ///////////
    // READY //
    ///////////

    io.backend_memory_response.ready := 1.B

    val availalbe_MOB_entries = PopCount(~Cat(MOB.map(_.valid)))
    
    for (i <- 0 until fetchWidth){
        io.reserve(i).ready := availalbe_MOB_entries >= fetchWidth.U
    }




}
