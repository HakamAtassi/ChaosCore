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


//FIXME: 
// Update this module that that it has partial ordering
// Meaning that loads cannot execute if there are previous unresolved stores
// when an entry is found to have no oustanding previous stores, use it to look up the mob, forward the data, and request the load. 


class MOB(coreParameters:CoreParameters) extends Module{
    import coreParameters._
    val portCount       = getPortCount(coreParameters)
    val portCountBits   = log2Ceil(portCount)

    val ptr_width = log2Ceil(MOBEntries) + 1

    val io = IO(new Bundle{
        // FLUSH //
        val flush                   =     Flipped(ValidIO(new flush(coreParameters)))

        // ALLOCATE //
        val reserve                 =      Vec(fetchWidth, Flipped(Decoupled(new decoded_instruction(coreParameters))))         // reserve entry (rename)
        val reserved_pointers       =      Vec(fetchWidth, ValidIO(UInt(log2Ceil(MOBEntries).W)))                               // pointer to allocated entry

        val fetch_PC                =      Input(UInt(32.W))                                                                  // DEBUG

        //val complete                =      ValidIO(new FU_output(coreParameters))                                               // update ROB (front of MOB)
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

    val MOB = RegInit(VecInit(Seq.fill(MOBEntries)(0.U.asTypeOf(new MOB_entry(coreParameters))))); //dontTouch(MOB)


    val front_pointer   = RegInit(UInt(ptr_width.W), 0.U)
    val back_pointer    = RegInit(UInt(ptr_width.W), 0.U)

    val front_index     = front_pointer(ptr_width-2, 0)
    val back_index      = back_pointer(ptr_width-2, 0)

    ////////////////////////////
    // INDETERMINATION MATRIX //
    ////////////////////////////


    // DEP. MATRIX

    // every time a store allocation takes place, set the input mob index bit of each row in the matrix for mob entries that are younger than the incoming index.
    // when the address resolves, clear that bit in the same fashion
    // an entry in the MOB is considered unambigious if its entire row indicates no dependancies




    //for(i <- 0 until fetchWidth){
        //when(io.reserve(i).fire){
            //printf("MOB accepted packet @ PC: 0x(%x)\n", io.fetch_PC)
            //printf("=============\n")
        //}
    //}




  	val matrix = RegInit(VecInit.tabulate(MOBEntries, MOBEntries){(x, y) => 0.B })
    // pretend this is a half-matrix
    // matrix[0] = [0]
    // matrix[1] = [0, 0]
    // matrix[3] = [0, 0, 0]
    // etc...

    dontTouch(matrix)


    def get_indetermination_matrix_row(row: UInt): UInt = {
        matrix(row).asUInt
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

            val is_younger = age_vector(i) < age_vector(back_index+index_offset)

            for(j <- 0 until fetchWidth){
                when(io.reserve(i).bits.memory_type === memory_type_t.STORE && is_younger){
                    matrix(j)(back_index+index_offset) := 1.B
                }
            }

            MOB(back_index + index_offset).valid                :=  1.B
            MOB(back_index + index_offset).MOB_STATE            :=  MOB_STATES.VALID
            MOB(back_index + index_offset).memory_type          :=  io.reserve(i).bits.memory_type
            MOB(back_index + index_offset).access_width         :=  io.reserve(i).bits.access_width
            MOB(back_index + index_offset).PRD                  :=  io.reserve(i).bits.PRD
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


    val response_age = Wire(UInt((ptr_width-1).W))
    response_age := age_vector(io.backend_memory_response.bits.MOB_index)
    val byte_sels    = Wire(Vec(MOBEntries, Vec(4, Bool())))
    val wr_bytes     = Wire(Vec(MOBEntries, Vec(4, UInt(8.W))))

    byte_sels    := MOB.map(MOB_entry => get_MOB_row_byte_sel(coreParameters, MOB_entry))
    wr_bytes     := MOB.map(MOB_entry => get_MOB_row_wr_bytes(coreParameters, MOB_entry))

    //val data_out     = Wire(Vec(4, UInt(8.W)))

    val incoming_is_valid       = io.AGU_output.valid
    val incoming_address        = io.AGU_output.bits.address


    // update entry //
    val MOB_index                       = io.AGU_output.bits.MOB_index
    when(io.AGU_output.valid){
        MOB(MOB_index).address         := io.AGU_output.bits.address
        MOB(MOB_index).data            := io.AGU_output.bits.wr_data

        // Update indet. matrix
        for(i <- 0 until MOBEntries){
            matrix(i)(MOB_index) := 0.B
        }
        
        // Update MOB entry state
        when((MOB(MOB_index).memory_type === memory_type_t.LOAD) && (MOB(MOB_index).MOB_STATE === MOB_STATES.VALID) && MOB(MOB_index).valid){
            MOB(MOB_index).MOB_STATE       := MOB_STATES.WAIT  // no outstanding stores to worry about
        }.elsewhen((MOB(MOB_index).memory_type === memory_type_t.STORE) && (MOB(MOB_index).MOB_STATE === MOB_STATES.VALID) && MOB(MOB_index).valid){
            MOB(MOB_index).MOB_STATE       := MOB_STATES.WAIT
        }
    }

    dontTouch(age_vector)
    dontTouch(wr_bytes)
    dontTouch(byte_sels)
    

    // FORWARD //
    // select a load that has no previous unresolved stores
    
    val forwarding_MOB_index = Wire(UInt(log2Ceil(MOBEntries).W))
    val forwarding_address = Wire(UInt(32.W))
    forwarding_MOB_index := 0.U




    // these names are based on deprecated code. 
    // FIXME: update name
    val incoming_is_load = Wire(Bool())
    incoming_is_load := 0.B
    for(i <- 0 until MOBEntries){
        when((matrix(MOB_index).asUInt === 0.U) && (MOB(i).memory_type === memory_type_t.LOAD) && (MOB(i).MOB_STATE === MOB_STATES.WAIT)){
            forwarding_MOB_index := i.U
            incoming_is_load    := 1.B
        }
    }

    val incoming_age = age_vector(forwarding_MOB_index)
    forwarding_address := MOB(forwarding_MOB_index).address
    dontTouch(incoming_is_load)
    //dontTouch(incoming_age)


    when(incoming_is_load){
        MOB(forwarding_MOB_index).MOB_STATE := MOB_STATES.READY
    }

    // search lower half
    for(b <- 0 until 4){
        for(i <- 0 until MOBEntries){
            val is_lower_half   = i.U > MOB_index
            val is_valid        = MOB(i).valid
            val is_older        = age_vector(i) > incoming_age

            // FIXME: conflicting should be for each byte, not each word...
            val is_conflicting  = (forwarding_address & "hFFFFFFFC".U) === ("hFFFFFFFC".U & MOB(i).address) && byte_sels(i)(b)
            val is_store        = MOB(i).memory_type === memory_type_t.STORE

            when(is_older && is_conflicting && is_valid){
                when(incoming_is_load && is_store && is_lower_half){
                    MOB(forwarding_MOB_index).fwd_valid(b) := byte_sels(i)(b)
                    MOB(forwarding_MOB_index).fwd_data(b) := wr_bytes(i)(b)
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
            val is_conflicting  = (forwarding_address & "hFFFFFFFC".U) === ("hFFFFFFFC".U & MOB(i).address) && byte_sels(i)(b)
            val is_store        = MOB(i).memory_type === memory_type_t.STORE


            when(is_older && is_conflicting && is_valid){
                when(incoming_is_load && is_store && is_upper_half){
                    MOB(forwarding_MOB_index).fwd_valid(b) := byte_sels(i)(b)
                    MOB(forwarding_MOB_index).fwd_data(b) := wr_bytes(i)(b)
                }
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

    
    fire_store           := MOB(front_index).valid && (MOB(front_index).MOB_STATE === MOB_STATES.WAIT) && MOB(front_index).committed && (MOB(front_index).memory_type === memory_type_t.STORE)    // stores are sent only from front of queue

    val load_index                               = PriorityEncoder(possible_load_vec)

    val prev_resolved = get_indetermination_matrix_row(load_index) === 0.U

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

    ///////////////
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
        io.MOB_output.bits.PRD                   := MOB(CDB_write_index).PRD
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
        MOB(CDB_write_index).MOB_STATE := MOB_STATES.DONE
    }


    /////////////////////
    // UPDATE COMPLETE //
    /////////////////////

    val MOB_update_commit = MOB.map(MOB_entry => (MOB_entry.valid) && (MOB_entry.MOB_STATE === MOB_STATES.WAIT))
    val selected_MOB_entry_for_commit = MOB(PriorityEncoder(MOB_update_commit))


    ///////////////////
    // UPDATE COMMIT //
    ///////////////////ROB
    // Update commit bit
    for(i <- 0 until MOBEntries){
        when(MOB(i).valid && io.commit.valid && (MOB(i).ROB_index === io.commit.bits.ROB_index) && (MOB(i).memory_type === memory_type_t.STORE)){
            MOB(i).committed := 1.B
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
    when(io.flush.valid){   //FIXME: 
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
        io.reserve(i).ready := (availalbe_MOB_entries >= fetchWidth.U) && !io.flush.valid
    }




}
