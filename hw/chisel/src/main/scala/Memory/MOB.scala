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
import Thermometor._

class MOB(parameters:Parameters) extends Module{
    import parameters._
    val portCount       = getPortCount(parameters)
    val portCountBits   = log2Ceil(portCount)

    val ptr_width = log2Ceil(MOBEntries) + 1

    val io = IO(new Bundle{
        // FLUSH //
        val flush                   =      Input(Bool())

        // ALLOCATE //
        val reserve                 =      Vec(fetchWidth, Flipped(Decoupled(new decoded_instruction(parameters))))         // reserve entry (rename)
        val reserved_pointers       =      Vec(fetchWidth, ValidIO(UInt(log2Ceil(MOBEntries).W)))                           // pointer to allocated entry

        val fetch_PC                =      Input(UInt(32.W))                                                                // DEBUG

        val AGU_output              =      Flipped(ValidIO(new FU_output(parameters)))                                      // update address (AGU)

        val MOB_output              =      ValidIO(new FU_output(parameters))                                      // update address (AGU)

        // REDIRECTS // 
        val commit                  =      Flipped(ValidIO(new commit(parameters)))                                         // commit mem op
        //val RF_inputs               =      Vec(portCount, Decoupled(new decoded_instruction(parameters)))                   // write RD

        ///////////////////////////
        // D$ BACKEND MEM ACCESS //
        ///////////////////////////
        val backend_memory_request              =   Decoupled(new backend_memory_request(parameters))
        val backend_memory_response             =   Flipped(Decoupled(new backend_memory_response(parameters)))

    })

    val front_pointer   = RegInit(UInt(ptr_width.W), 0.U)
    val back_pointer    = RegInit(UInt(ptr_width.W), 0.U)

    val front_index   = front_pointer(ptr_width-2, 0)
    val back_index    = back_pointer(ptr_width-2, 0)

    val MOB = RegInit(VecInit(Seq.fill(MOBEntries)(0.U.asTypeOf(new MOB_entry(parameters)))))

    /////////////////////////
    // GENERATE AGE VECTOR //
    /////////////////////////
    val age_vector          = Wire(Vec(MOBEntries, UInt((ptr_width - 1).W)))
    val age_valid_vector    = Wire(Vec(MOBEntries, UInt((ptr_width - 1).W)))

    // Give each mob entry an age.
    // Mob entry @ front pointer will have value of 15
    // Mob entry @ back pointer will have value of 15 - number of entries
    for(i <- 0 until MOBEntries){   
        age_vector(i)       := (front_index + MOBEntries.U - i.U) % MOBEntries.U // make sure this isnt generating extra hardware...
        age_valid_vector(i) := MOB(i).valid
    }

    //////////////
    // RESERVE //
    //////////////
    val written_vec = Wire(Vec(fetchWidth, Bool()))

    for(i <- 0 until dispatchWidth){
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

            MOB(back_index + index_offset).memory_type          :=  io.reserve(i).bits.memory_type
            MOB(back_index + index_offset).RD                   :=  io.reserve(i).bits.RD
            MOB(back_index + index_offset).ROB_index            :=  io.reserve(i).bits.ROB_index

            io.reserved_pointers(index_offset).bits     := back_index + index_offset
            io.reserved_pointers(index_offset).valid    := 1.U
        }
    }


    ////////////////////
    // WRITE AGU DATA //
    ////////////////////
    // On input
    // Update address, set to pending.

    val MOB_index                        = io.AGU_output.bits.MOB_index
    val address                          = io.AGU_output.bits.address
    when(io.AGU_output.valid){
        MOB(MOB_index).pending              := 1.B
        MOB(MOB_index).address              := address
    }

    /////////////////////
    // VIOLATION CHECK //
    /////////////////////
    // On input
    // Check for load-load or store-load conflicts
    // On incoming operations, check for store-store, store-load, and load-load conflicts (younger load/store operations to the same address that have completed).
    // store-store conflicts cause the current search to terminate early
    // store-load conflicts set violation bit
    // load-load conflicts set violation bit(to maintain RVWMO memory consistency)
    val incoming_is_valid       = io.AGU_output.valid
    val incoming_address        = io.AGU_output.bits.address
    val incoming_age            = age_vector(io.AGU_output.bits.MOB_index)
    val incoming_is_load        = io.AGU_output.bits.memory_type === memory_type_t.LOAD
    val incoming_is_store       = io.AGU_output.bits.memory_type === memory_type_t.STORE

    val store_store_violation     = Wire(Vec(MOBEntries, Bool())) // Not a real violation. If any bits are set, terminate search

    for(i <- 0 until MOBEntries){
        store_store_violation(i)    := 0.B
    }

    // violation checks
    for(i <- 0 until MOBEntries){       
        val is_valid        = MOB(i).valid
        val is_younger      = age_vector(i) < incoming_age
        val is_conflicting  = incoming_address === (MOB(i).address & "hFFFF_FFF0".U)

        val is_load         = MOB(i).memory_type === memory_type_t.LOAD
        val is_store        = MOB(i).memory_type === memory_type_t.STORE

        when(is_younger && is_conflicting && is_valid && (PopCount(store_store_violation.take(i)) === 0.U) ){ // FIXME: && adderess has been placed by AGU?
            when(incoming_is_load && is_load){          // load load violation
                MOB(MOB_index).violation := 1.B
            }.elsewhen(incoming_is_store && is_load){   // store load violation. 
                MOB(MOB_index).violation := 1.B
            }.elsewhen(incoming_is_store && is_store){  // store store "violation"
                store_store_violation(i) := 1.B
            }
        }
    }


    ////////////////////////
    // REQUEST LOAD/STORE //
    ////////////////////////
    // Check for pending loads, send to memory as needed
    val fire_store = Wire(Bool())
    val fire_load  = Wire(Bool())


    io.backend_memory_request.bits   := 0.U.asTypeOf(new backend_memory_request(parameters))
    io.backend_memory_request.valid  := 0.B

    for(i <- 0 until MOBEntries){   // schedule load
        fire_load   := MOB(i).valid && MOB(i).pending && MOB(i).memory_type === memory_type_t.LOAD
        fire_store  := MOB(front_index).valid && MOB(front_index).committed && MOB(front_index).memory_type === memory_type_t.STORE
        when(fire_load){    // schedule load
            MOB(i).pending := 0.B
            io.backend_memory_request.bits.addr         := MOB(i).address
            io.backend_memory_request.bits.memory_type  := MOB(i).memory_type
            io.backend_memory_request.bits.access_width := MOB(i).access_width
            io.backend_memory_request.bits.MOB_index    := i.U
        }
    }.elsewhen(fire_store){
        MOB(i).pending := 0.B
        io.backend_memory_request.bits.addr             := MOB(i).address
        io.backend_memory_request.bits.memory_type      := MOB(i).memory_type
        io.backend_memory_request.bits.access_width     := MOB(i).access_width
        io.backend_memory_request.bits.MOB_index        := i.U
    }



    for(i <- 0 until MOBEntries){ // free front pointer
        val is_committed       = MOB(front_index).committed
        val is_store           = MOB(front_index).memory_type  === memory_type_t.STORE
        val is_load            = MOB(front_index).memory_type  === memory_type_t.LOAD
        val is_valid           = MOB(front_index).valid
        val is_pending         = MOB(front_index).pending
        val fired              = MOB(front_index).fired
        when(is_valid && is_store && !is_pending && fired && is_committed){    // free store
            MOB(front_index) := 0.U.asTypeOf(new MOB_entry(parameters))
        }.elsewhen(is_valid && is_load && !is_pending && fired){               // free load
            MOB(front_index) := 0.U.asTypeOf(new MOB_entry(parameters))

        }
    }

    //////////////////////
    // VIOLATION OUTPUT //
    //////////////////////

    // TODO:




    /////////////////////////
    // MERGE AND WRITEBACK //
    /////////////////////////
    // On memory response
    // Look up MOB, merge, and write to reg file

    io.backend_memory_response  := DontCare


    val response_age = Wire(UInt((ptr_width-1).W))

    
    val byte_sels   = Wire(Vec(MOBEntries, UInt(4.W)))
    val wr_bytes    = Wire(Vec(MOBEntries, Vec(4, UInt(8.W))))

    val data_out    = Wire(Vec(4, UInt(8.W)))

    response_age := age_vector(io.backend_memory_response.bits.MOB_index)


    data_out     := DontCare 

    // Compute row writes
    for(i <- 0 until MOBEntries){    // forward from MOB
        byte_sels(i) := get_MOB_row_byte_sel(parameters, MOB(i))
        wr_bytes(i)     := DontCare //Seq.fill(4, 0.U) //0.U //get_MOB_row_byte_wr(MOB(i))
    }

    // Forward from row write to data out
    for(i <- 0 until MOBEntries){    // forward from MOB
        val is_valid        = MOB(i).valid
        val is_younger      = age_vector(i) < response_age
        val is_conflicting  = incoming_address === MOB(i).address

        val is_load         = MOB(i).memory_type === memory_type_t.LOAD
        val is_store        = MOB(i).memory_type === memory_type_t.STORE

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


    io.MOB_output               := DontCare


    for(i <- 0 until 4){    // forward from MOB
        byte_sels(i) := get_MOB_row_byte_sel(parameters, MOB(i))
        wr_bytes(i)     := DontCare //Seq.fill(4, 0.U) //0.U //get_MOB_row_byte_wr(MOB(i))
    }

    io.MOB_output.valid := io.backend_memory_response.valid
    io.MOB_output.bits.RD    := MOB(io.backend_memory_response.bits.MOB_index).RD
    io.MOB_output.bits.RD_data    := wr_bytes.asUInt    // does this work?




    ///////////////////
    // UPDATE COMMIT //
    ///////////////////
    // Update commit bit
    for(i <- 0 until MOBEntries){
        when(io.commit.valid && MOB(i).ROB_index === io.commit.bits.ROB_index){
            MOB(i).committed := 1.B
        }
    }

    ///////////
    // READY //
    ///////////


    val availalbe_MOB_entries = PopCount(~Cat(MOB.map(_.valid)))
    
    for (i <- 0 until dispatchWidth){
        io.reserve(i).ready := availalbe_MOB_entries >= fetchWidth.U
    }




}
