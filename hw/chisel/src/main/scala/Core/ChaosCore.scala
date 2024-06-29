/* ------------------------------------------------------------------------------------
* Filename: ChaosCore.scala
* Author: Hakam Atassi
* Date: May 31 2024
* Description: The top level ChaosCore Module
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


// Top level integrates the Frontend, Allocator, Backend, ROB and FTQ

class ChaosCore(parameters:Parameters) extends Module{
    
    import parameters._

    val io = IO(new Bundle{

        val commit                              =   ValidIO(new commit(parameters))

        ////////////////////////////
        // I$ FRONTEND MEM ACCESS //
        ////////////////////////////
        val frontend_memory_response            =   Flipped(Decoupled(new fetch_packet(parameters)))
        val frontend_memory_request             =   Decoupled(new memory_request(parameters))

        ///////////////////////////
        // D$ BACKEND MEM ACCESS //
        ///////////////////////////
        val backend_memory_response             =   Flipped(Decoupled(new memory_response(parameters)))
        val backend_memory_request              =   Decoupled(new memory_request(parameters))
    })


    /////////////
    // MODULES //
    /////////////

    val frontend    = Module(new frontend(parameters))
    val backend     = Module(new backend(parameters))


    val FTQ         = Module(new FTQ(parameters))
    val ROB         = Module(new ROB(parameters))
    val BRU         = Module(new BRU(parameters))


    val flush       = Wire(Bool())

    /////////////////////
    // BACKEND <> DRAM //
    /////////////////////

    backend.io.memory_response    <>  io.backend_memory_response
    backend.io.memory_request     <>  io.backend_memory_request


    ////////////////////
    // BACKEND <> BRU //
    ////////////////////

    backend.io.commit <> BRU.io.commit

    io.commit <> BRU.io.commit

    /////////////////////
    // FRONTEND <> FTQ //
    /////////////////////

    frontend.io.predictions <> FTQ.io.predictions   //buffer made predictions


    //////////////////////
    // FRONTEND <> DRAM //
    //////////////////////

    frontend.io.memory_request       <>  io.frontend_memory_request
    frontend.io.memory_response      <>  io.frontend_memory_response

    /////////////////////
    // FRONTEND <> BRU //
    /////////////////////

    frontend.io.commit <> BRU.io.commit

    /////////////////////////
    // FRONTEND <> BACKEND //
    /////////////////////////

    frontend.io.FU_outputs <> backend.io.FU_outputs

    ////////////////////
    // ROB <> BACKEND //
    ////////////////////

    ROB.io.FU_outputs <> backend.io.FU_outputs 

    ////////////////////
    // FTQ <> BACKEND //
    ////////////////////

    FTQ.io.FU_outputs <> backend.io.FU_outputs

    ////////////////
    // FTQ <> BRU //
    ////////////////

    FTQ.io.commit    <>  BRU.io.commit

    ////////////////
    // ROB <> FTQ //
    ////////////////

    ROB.io.commit <> BRU.io.commit
    FTQ.io.commit <> BRU.io.commit


    ////////////////
    // ROB <> BRU //
    ////////////////

    ROB.io.ROB_output <>  BRU.io.ROB_output


    ////////////////
    // BRU <> FTQ //
    ////////////////

    BRU.io.FTQ <> FTQ.io.FTQ

    ///////////
    // FLUSH //
    ///////////
    flush := BRU.io.commit.valid && BRU.io.commit.bits.is_misprediction

    frontend.io.flush   <>  flush
    backend.io.flush    <>  flush
    ROB.io.flush        <>  flush
    FTQ.io.flush        <>  flush
    // FIXME: LSQ FLUSH


    //////////////////////
    // ALLOCATION LOGIC //
    //////////////////////

    // Cant dequeue a fetchpacket from the frontend unless the entire fetch packet is ready
    // This is only true when the ROB has available space and the RS entries (both INT and MEM)
    // Have enough available space

    //FIXME: 
    //Problem: 
    //MEMRS is still allocating partially if not all fetch packets are accepted. this causes instructions to leak...


    // overwrite frontend renamed_decoded_fetch_packet ready bit

    val needs_INTRS          = Wire(Vec(fetchWidth, Bool()))
    val needs_MEMRS          = Wire(Vec(fetchWidth, Bool()))

    for(i <- 0 until fetchWidth){
        needs_INTRS(i) := (frontend.io.renamed_decoded_fetch_packet.bits.decoded_instruction(i).RS_type === RS_types.INT) && frontend.io.renamed_decoded_fetch_packet.bits.valid_bits(i)
        needs_MEMRS(i) := (frontend.io.renamed_decoded_fetch_packet.bits.decoded_instruction(i).RS_type === RS_types.MEM) && frontend.io.renamed_decoded_fetch_packet.bits.valid_bits(i)
    }

    val all_INT_RS_accepted = Wire(Bool())  // every valid INT RS instruction has an available spot
    val all_MEM_RS_accepted = Wire(Bool())  // every valid MEM RS instruction has an available spot

    dontTouch(all_INT_RS_accepted)
    dontTouch(all_MEM_RS_accepted)

    dontTouch(needs_MEMRS)
    dontTouch(needs_INTRS)

    // there must be more available RS entries than requesting instructions for that RS
    // Otherwise, entry doesnt allocate
    all_INT_RS_accepted := PopCount(backend.io.INTRS_ready) >= PopCount(needs_INTRS)
    all_MEM_RS_accepted := PopCount(backend.io.MEMRS_ready) >= PopCount(needs_MEMRS)


    // ROB and RS do not update until ready
    backend.io.backend_packet   <> frontend.io.renamed_decoded_fetch_packet


    for(i <- 0 until fetchWidth){   // pass along the ROB index for each instruction (for commit and PC read)
        backend.io.backend_packet.bits.decoded_instruction(i).ROB_index := ROB.io.ROB_index
    }

    ROB.io.ROB_packet           <> frontend.io.renamed_decoded_fetch_packet

    // Connect branch unit to PC file (which exists in the ROB)
    backend.io.PC_file_exec_addr <> ROB.io.PC_file_exec_addr
    backend.io.PC_file_exec_data <> ROB.io.PC_file_exec_data

    // 
    //BRU.io.PC_file_commit_data <> ROB.io.PC_file_commit_data



    frontend.io.renamed_decoded_fetch_packet.ready := (ROB.io.ROB_packet.ready && all_INT_RS_accepted && all_MEM_RS_accepted)


}