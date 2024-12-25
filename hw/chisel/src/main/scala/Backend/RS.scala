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
import getPortCount._
import Thermometor._


// The Reservation station is able to allocate up to N items at a time
// And is able to schedule N items at a time as well, based on port availability. 

// FIXME: the output port assignment and stuff should all be parameterizable
// Ex: memrs needs only 1 port. its ID is arbitrary, stuff like that

// FIXME: the number of ports the RS has should be based on the number of INT/MEM FUs
class RS(coreParameters:CoreParameters, RSPortCount:Int, RS_type:String) extends Module{
    import coreParameters._


    val io = IO(new Bundle{
        // FLUSH //
        val flush             =      Flipped(ValidIO(new flush(coreParameters)))

        // ALLOCATE //
        val backend_packet    =      Vec(fetchWidth, Flipped(Decoupled(new decoded_instruction(coreParameters))))

        // UPDATE //
        val FU_outputs        =      Vec(WBPortCount, Flipped(ValidIO(new FU_output(coreParameters))))

        // REG READ (then execute) //
        val RF_inputs         =      Vec(RSPortCount, Decoupled(new decoded_instruction(coreParameters)))

        // commit (mostly for CSRs) // 
        val commit                  =      Flipped(ValidIO(new commit(coreParameters)))                                         // commit mem op
        val partial_commit          =      Input(new partial_commit(coreParameters))                                         // commit mem op

    }); dontTouch(io)


    ///////////////////////////////
    // RESERVATION STATION LOGIC //
    ///////////////////////////////


    // Allocate RS regs
    //FIXME: update this so that it writes from top to bottom
    val reservation_station = RegInit(VecInit(Seq.fill(RSEntries)(0.U.asTypeOf(new RS_entry(coreParameters)))))


    val committed     = RegInit(VecInit(Seq.fill(RSEntries)(0.B)))
    val committed_next = WireInit(committed) // Wire for immediate updates

    committed_next := committed


    dontTouch(reservation_station)
    
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


    ///////////////////////
    // UPDATE RS ENTRIES //
    ///////////////////////

    for (i <- 0 until RSEntries) {
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
    }



    for (i <- 0 until RSEntries) {
        for (j <- 0 until fetchWidth) {
            when(reservation_station(i).valid && io.commit.valid && 
            (io.partial_commit.ROB_index === reservation_station(i).decoded_instruction.ROB_index) && 
            io.partial_commit.valid(j) && (j.U === reservation_station(i).decoded_instruction.packet_index)) {
                committed_next(i) := 1.B // Update the wire immediately
            }
        }
    }

    // Update the register at the end of the cycle
    committed := committed_next








    /////////////////////
    // PORT SCHEDULING //
    /////////////////////

    // for each port, select an input and place it
    // if it was found that the instruction was accepted, free it from the RS


    // instruction scheduling is a 3 step process
    // ...
    // set schedulable bit for all instructions that match FU requirements and are ready to execute
    // select 1 instruction based on this bit vector
    // Set that instruction as scheduled such that following ports do not reschedule it

    for (i <- 0 until RSPortCount){
        io.RF_inputs(i).valid := 0.B
        io.RF_inputs(i).bits  := 0.U.asTypeOf(new decoded_instruction(coreParameters))
    }

    val port_RS_index  = Wire(Vec(RSPortCount, UInt(log2Ceil(RSEntries).W)))

    port_RS_index := Seq.fill(RSPortCount)(0.U)


    // FIXME: convert these to "PriorityMux"

    // FIXME: there is actually a performance issue here. 
    // you essentially "virtually" assign each instruction to a port, then overwrite it due to the priority
    // since you are scheduling instructions anyway, you might aswell place them in a queue or something so that the RS is free...


  	val schedulable_instructions = WireInit(VecInit.tabulate(RSPortCount, RSEntries){ (x, y) => 0.B })
    val scheduled                = WireInit(VecInit.tabulate(RSEntries, RSPortCount){ (x, y) => 0.B })
    
    
    dontTouch(schedulable_instructions)


    // the scheduling logic is as follows:
    // first, create a bit vector of what instructions are ready to execute
    // second, create a bit vector for each instrctuction of the form [0,1,1,0] that maps its port support
    // third, in a loop (for each port), select an instruction based on the above vector (and with ~not scheduled) via a priority encoder and schedule the instruction
    // Last, then mark scheduled.

    // step 1
    for(port <- 0 until RSPortCount){
        for(i <- 0 until RSEntries){

            val current_instruction = reservation_station(i).decoded_instruction

            val current_port_support     = FUParamSeq(port)

            val RS1_valid_ready_or_not_valid    = (reservation_station(i).decoded_instruction.ready_bits.RS1_ready && reservation_station(i).decoded_instruction.RS1_valid) || !reservation_station(i).decoded_instruction.RS1_valid
            val RS2_valid_ready_or_not_valid    = (reservation_station(i).decoded_instruction.ready_bits.RS2_ready && reservation_station(i).decoded_instruction.RS2_valid) || !reservation_station(i).decoded_instruction.RS2_valid
            val need_commit_first               = (current_instruction.needs_CSRs &&  committed(i)) || !(current_instruction.needs_CSRs) || current_instruction.MRET

            val fireable                        = reservation_station(i).valid && RS1_valid_ready_or_not_valid && RS2_valid_ready_or_not_valid && need_commit_first
                                            
                                            
            val supported = (
            (current_instruction.needs_ALU && current_port_support.supportsInt.B) ||
            (current_instruction.needs_branch_unit && current_port_support.supportsBranch.B) ||
            (current_instruction.needs_CSRs && current_port_support.supportsCSRs.B) ||
            (current_instruction.needs_div && current_port_support.supportsDiv.B) ||
            (current_instruction.needs_mul && current_port_support.supportsMult.B) ||
            (current_instruction.needs_memory && current_port_support.supportsAddressGeneration.B)
            )

                // FIXME: another problem is that the FUParamSeq is "mixed" intems of RS
                // so the first port for the MEMRS may be the Nth entry of the param seq. 
                // this is a bit anoying to abstract

            if(RS_type == "MEM"){   //FIXME: Why can this not be more abstract. why is the RS required to be passed an RS type?
                schedulable_instructions(port)(i) := fireable
            }else{
                schedulable_instructions(port)(i) := fireable && supported
            }

        }
    }


    // TODO: add RS ready check

    for (port <- 0 until RSPortCount) {
        val scheduled_index = PriorityEncoder(schedulable_instructions(port))
        io.RF_inputs(port).valid := 0.B
        when(schedulable_instructions(port).reduce(_ || _) && !scheduled(scheduled_index).take(port).fold(0.B)(_ || _)) {

            // Schedule instruction
            io.RF_inputs(port).bits := reservation_station(scheduled_index).decoded_instruction
            io.RF_inputs(port).valid := 1.B

            // Mark as scheduled
            scheduled(scheduled_index)(port) := 1.B
            port_RS_index(port)   := scheduled_index

        }
    }


    for (port <- 0 until RSPortCount) {
        when(io.RF_inputs(port).fire){
            reservation_station(port_RS_index(port)) := 0.U.asTypeOf(new RS_entry(coreParameters))
            committed_next(port_RS_index(port)) := 0.B
        }
    }

    dontTouch(port_RS_index)

    // ADD RS entry freeing logic


    // iterate over RS
    // find instructions that are ready to be dispatched
    // dispatch them to corresponding port

    // what if instruction fits into several FUs? How do you choose where it does?


    when(io.flush.valid){
        for(port <- 0 until RSPortCount){
            io.RF_inputs(port).bits := 0.U.asTypeOf(new decoded_instruction(coreParameters))
            io.RF_inputs(port).valid := 0.B
        }
    }

    //////////////
    // FLUSH RS //
    //////////////

    for(i <- 0 until RSEntries){
        when(io.flush.valid && committed_next(i) === 0.B){
            reservation_station(i) := 0.U.asTypeOf(new RS_entry(coreParameters))
        }
    }

    /////////////////////
    // READY SIGNALING //
    /////////////////////


    // There are 4 possible ready bits. 
    // These bits corrispond to how many instructions you can dispatch to the RS per cycle. 
    
    val availalbe_RS_entries = PopCount(~Cat(reservation_station.map(_.valid)))
    
    for (i <- 0 until fetchWidth){
        io.backend_packet(i).ready := availalbe_RS_entries >= fetchWidth.U
    }


}
