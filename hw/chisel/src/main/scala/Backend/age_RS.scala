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

class age_RS(coreParameters:CoreParameters)(WBPortCount:Int) extends Module{
    import coreParameters._


    val io = IO(new Bundle{
        // FLUSH //
        val flush             =      Flipped(ValidIO(new flush(coreParameters)))

        // ALLOCATE //
        val backend_packet    =      Vec(fetchWidth, Flipped(Decoupled(new decoded_instruction(coreParameters))))

        // UPDATE //
        val FU_outputs        =      Vec(WBPortCount, Flipped(Decoupled(new FU_output(coreParameters))))

        // REG READ (module output) //
        val RF_inputs         =      Decoupled(new decoded_instruction(coreParameters))

        // commit (mostly for CSRs) // 
        val commit            =      Flipped(ValidIO(new commit(coreParameters)))                                         // commit mem op

    }); dontTouch(io)


    val reservation_station = RegInit(VecInit(Seq.fill(RSEntries)(0.U.asTypeOf(new RS_entry(coreParameters))))) // once an entry is selected and issued
    //val issue_queue         = Module(new Queue(new decoded_instruction(coreParameters), IQEntries, flow = false, hasFlush = true, useSyncReadMem = false))
    

    //////////////
    // ALLOCATE //
    //////////////
    // Allocate new RS entry

    // Reg allocate POS for new input
    val validVec = reservation_station.map(_.valid)
    val validUInt = Cat(validVec.reverse)
    val allocate_index = SelectFirstN(~validUInt, fetchWidth)
    

    // Allocate new RS entry
    for(i <- 0 until fetchWidth){
        when(io.backend_packet(i).fire){
            val allocateIndexBinary = OHToUInt(allocate_index(i))
            reservation_station(allocateIndexBinary).decoded_instruction := io.backend_packet(i).bits
            reservation_station(allocateIndexBinary).valid   := 1.B
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


    dontTouch(reservation_station)

    //////////////
    // SCHEDULE //
    //////////////

    val schedulable_instructions = WireInit(VecInit(Seq.fill(RSEntries)(0.B)))

    for(i <- 0 until RSEntries){
        val current_instruction = reservation_station(i).decoded_instruction

        val needs_commit_first = current_instruction.needs_CSRs   // FIXME: this needs to be expressed more abstractly 

        val committed          = reservation_station(i).committed 

        val RS1_ready    = reservation_station(i).decoded_instruction.ready_bits.RS1_ready
        val RS2_ready    = reservation_station(i).decoded_instruction.ready_bits.RS2_ready

        val fireable     = reservation_station(i).valid && RS1_ready && RS2_ready && (!needs_commit_first || committed)
        
        schedulable_instructions(i) := fireable
    }

    dontTouch(schedulable_instructions)

    // Schedule oldest instruction each cycle for that port. 
    // currently schedules 1 instruction per cycle. FIXME: this may be a performance bottle neck down the line


    // get oldest outstanding instruction for each port
    var scheduled_index = WireInit(0.U(log2Ceil(RSEntries).W))

    for(i <- 0 until RSEntries){    // FIXME: update to priority encoder
        when(schedulable_instructions(i) === 1.B){
            scheduled_index               := i.U
        }
    }

    // issue that instruction
    io.RF_inputs.bits  := 0.U.asTypeOf(new decoded_instruction(coreParameters))
    io.RF_inputs.valid := 0.B

    when(schedulable_instructions(scheduled_index)){
        // assign instruction to issue Q
        io.RF_inputs.bits := reservation_station(scheduled_index).decoded_instruction
        io.RF_inputs.valid := 1.B
        //issue_queue.io.enq.bits  := reservation_station(scheduled_index).decoded_instruction
        //issue_queue.io.enq.valid := 1.B
    }

    when(io.RF_inputs.fire && !io.flush.valid){
        // free RS entry
        reservation_station(scheduled_index) := 0.U.asTypeOf(new RS_entry(coreParameters))
    }



    ////////////////////
    // ASSIGN OUTPUTS //
    ////////////////////

    // write issue queue to output
    //issue_queue.io.deq <> io.RF_inputs

    when(io.RF_inputs.valid === 0.B){
        io.RF_inputs.bits := 0.U.asTypeOf(new decoded_instruction(coreParameters))
    }

    ///////////
    // FLUSH //
    ///////////

    //issue_queue.io.flush.get := io.flush.valid  // flush issue queues

    when(io.flush.valid){
        // de-assert current outputs
        io.RF_inputs.bits := 0.U.asTypeOf(new decoded_instruction(coreParameters))  // FIXME: what if the entry you are outputting is committted?
        io.RF_inputs.valid := 0.B

        // clear RS entries
        for(i <- 0 until RSEntries){
            val committed = reservation_station(i).committed && reservation_station(i).valid
            when(!committed){
                reservation_station(i) := 0.U.asTypeOf(new RS_entry(coreParameters))
            }
        }
    }

    /////////////////////
    // READY SIGNALING //
    /////////////////////

    // There are 4 possible ready bits. 
    // These bits corrispond to how many instructions you can dispatch to the RS per cycle. 
    
    val availalbe_RS_entries = PopCount(~Cat(reservation_station.map(_.valid)))

    for(i <- 0 until WBPortCount){
        io.FU_outputs(i).ready := 1.B   // RS can always set ready bits
    }
    
    for (i <- 0 until fetchWidth){
        io.backend_packet(i).ready := availalbe_RS_entries >= fetchWidth.U
    }


}
