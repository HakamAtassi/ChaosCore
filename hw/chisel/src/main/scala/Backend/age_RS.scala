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

import chisel3.util._


//TODO: add port assignment
//TODO: add commit bit
//TODO: fix complete issue in ROB for CSRs and Stores


class age_RS(coreParameters:CoreParameters, RSPortCount:Int, RS_type:String) extends Module{
    import coreParameters._


    val io = IO(new Bundle{
        // FLUSH //
        val flush             =      Flipped(ValidIO(new flush(coreParameters)))

        // ALLOCATE //
        val backend_packet    =      Vec(fetchWidth, Flipped(Decoupled(new decoded_instruction(coreParameters))))

        // UPDATE //
        val FU_outputs        =      Vec(WBPortCount, Flipped(Decoupled(new FU_output(coreParameters))))

        // REG READ (module output) //
        val RF_inputs         =      Vec(RSPortCount, Decoupled(new decoded_instruction(coreParameters)))

        // commit (mostly for CSRs) // 
        val commit                  =      Flipped(ValidIO(new commit(coreParameters)))                                         // commit mem op

    }); dontTouch(io)


    val reservation_station = RegInit(VecInit(Seq.fill(RSEntries)(0.U.asTypeOf(new RS_entry(coreParameters))))) // once an entry is selected and issued
    val issue_queues: Seq[Queue[decoded_instruction]] = Seq.tabulate(RSPortCount) { w => 
    Module(new Queue(new decoded_instruction(coreParameters), IQEntries, flow = false, hasFlush = true, useSyncReadMem = false))
    }


    object arrow extends ChiselEnum{
        val up, left = Value
    }

    val age_matrix = RegInit(VecInit.tabulate(RSEntries, RSEntries){(x, y) => arrow.up})    // does init dir matter?

    //////////////////////
    // AGE MATRIX LOGIC //
    //////////////////////
    
    def update_age(index:UInt):Unit = { // this is called when RS entries are allocated
        for(i <- 0 until RSEntries){
            age_matrix(index)(i) := arrow.up
            age_matrix(i)(index) := arrow.left
        }
    }

    def get_age(index:UInt): UInt = {   // return age for some entry
        //0.U
        age_matrix(index).asUInt
    }
    
    //////////////
    // ALLOCATE //
    //////////////
    // Allocate new RS entry

    val validUInt = Cat(reservation_station.map(_.valid))
    val allocate_index_vec = SelectFirstN(~validUInt, fetchWidth).map(x => OHToUInt(x))
    
    for(i <- 0 until fetchWidth){
        when(io.backend_packet(i).fire){
            val allocate_index = allocate_index_vec(i)
            reservation_station(allocate_index).decoded_instruction := io.backend_packet(i).bits
            reservation_station(allocate_index).valid   := 1.B

            update_age(allocate_index)  // update age matrix
        }
    }

    ////////////
    // UPDATE //
    ////////////

    for (i <- 0 until RSEntries) {

        // set RS1/RS2 ready
        for (FU <- 0 until WBPortCount) {
            when((io.FU_outputs(FU).bits.PRD === reservation_station(i).decoded_instruction.RS1) && io.FU_outputs(FU).bits.RD_valid && io.FU_outputs(FU).valid){
                when(reservation_station(i).valid){
                    reservation_station(i).decoded_instruction.ready_bits.RS1_ready := 1.B
                }
            }

            when((io.FU_outputs(FU).bits.PRD === reservation_station(i).decoded_instruction.RS2) && io.FU_outputs(FU).bits.RD_valid && io.FU_outputs(FU).valid){
                when(reservation_station(i).valid){
                    reservation_station(i).decoded_instruction.ready_bits.RS2_ready := 1.B
                }
            }
        }

        // mark committed
        for (j <- 0 until fetchWidth) {
            when(reservation_station(i).valid && 
            (io.commit.bits.ROB_index === reservation_station(i).decoded_instruction.ROB_index) && 
            io.commit.bits.insn_commit(j).bits.WB_committed && (j.U === reservation_station(i).decoded_instruction.packet_index)) {
                reservation_station(i).committed := 1.B 
            }
        }

    }




    //////////////
    // SCHEDULE //
    //////////////

    // step 1: create a bit vector for each port that encodes a 1 for each schedule-able instruction in the RS
    // Ex: 
    //// port[0]              = [0,0,0,0,1,0,0,1,1,...,0]
    //// port[...]            = [...]
    //// port[portCount-1]    = [1,1,0,1,0,0,1,1,0,...,0]

  	val schedulable_instructions       = WireInit(VecInit.tabulate(RSPortCount, RSEntries){ (x, y) => 0.B })

    for(port <- 0 until RSPortCount){
        for(i <- 0 until RSEntries){
            val current_instruction = reservation_station(i).decoded_instruction

            val needs_commit_first = current_instruction.needs_commit_first // ex, CSRW, mem store, etc...
            val committed          = reservation_station(i).committed 

            val RS1_ready    = reservation_station(i).decoded_instruction.ready_bits.RS1_ready
            val RS2_ready    = reservation_station(i).decoded_instruction.ready_bits.RS2_ready

            val fireable     = reservation_station(i).valid && RS1_ready && RS2_ready && (!needs_commit_first || committed)
            
            schedulable_instructions(port)(i) := fireable && current_instruction.assigned_port === port.U
        }
    }

    // Schedule oldest instruction each cycle for that port. 
    // currently schedules 1 instruction per cycle. FIXME: this may be a performance bottle neck down the line

    val scheduled                      = WireInit(VecInit.tabulate(RSEntries, RSPortCount){(x, y) => 0.B})    

    for(port <- 0 until RSPortCount) {
        

        // get oldest outstanding instruction for each port
        var scheduled_age   = WireInit(0.U(log2Ceil(RSEntries).W))
        var scheduled_index = WireInit(0.U(log2Ceil(RSEntries).W))

        val prev_max_vector = WireInit(VecInit(Seq.fill(RSEntries+1)(0.U(log2Ceil(RSEntries).W)))) 

        for(i <- 0 until RSEntries){
            val already_scheduled = scheduled(i).take(port).fold(0.B)(_ || _)

            when(schedulable_instructions(port)(i) === 1.B && !already_scheduled && get_age(i.U) >= prev_max_vector(i)){
                prev_max_vector(i+1)          := i.U
                scheduled_index               := i.U
                scheduled_age                 := get_age(i.U)
            }
        }


        // issue that instruction
        issue_queues(port).io.enq.bits  := 0.U.asTypeOf(new decoded_instruction(coreParameters))
        issue_queues(port).io.enq.valid := 0.B

        when(reservation_station(scheduled_index).valid){   // FIXME: and if issue queue can accept...
            // assign instruction to issue Q
            issue_queues(port).io.enq.bits  := reservation_station(scheduled_index).decoded_instruction //scheduled_instruction(port).bits
            issue_queues(port).io.enq.valid := 1.B
            
            // mark it as scheduled (so it isn't double-scheduled for a similar port)
            scheduled(scheduled_index)(port) := 1.B

            // free RS entry
            reservation_station(scheduled_index) := 0.U.asTypeOf(new RS_entry(coreParameters))
        }
    }



    ////////////////////
    // ASSIGN OUTPUTS //
    ////////////////////

    // write issue queue to output
    for (port <- 0 until RSPortCount) {
        issue_queues(port).io.deq <> io.RF_inputs(port)
    }

    ///////////
    // FLUSH //
    ///////////

    for(port <- 0 until RSPortCount){
        issue_queues(port).io.flush.get := io.flush.valid  // flush issue queues
    }

    when(io.flush.valid){
        // de-assert current outputs & flush issue queues
        for(port <- 0 until RSPortCount){
            issue_queues(port).io.flush.get := io.flush.valid  // flush issue queues
            io.RF_inputs(port).bits := 0.U.asTypeOf(new decoded_instruction(coreParameters))
            io.RF_inputs(port).valid := 0.B
        }

        // clear RS entries
        for(i <- 0 until RSEntries){
            reservation_station(i) := 0.U.asTypeOf(new RS_entry(coreParameters))
        }
    }

    /////////////////////
    // READY SIGNALING //
    /////////////////////

    // There are 4 possible ready bits. 
    // These bits corrispond to how many instructions you can dispatch to the RS per cycle. 
    
    val availalbe_RS_entries = PopCount(~Cat(reservation_station.map(_.valid)))

    for(i <- 0 until portCount){
        io.FU_outputs(i).ready := 1.B   // RS can always set ready bits
    }
    
    for (i <- 0 until fetchWidth){
        io.backend_packet(i).ready := availalbe_RS_entries >= fetchWidth.U
    }


}
