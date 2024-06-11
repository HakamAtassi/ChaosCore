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

        ////////////////////////////
        // I$ FRONTEND MEM ACCESS //
        ////////////////////////////

        // From DRAM
        val frontend_DRAM_resp               =   Flipped(Decoupled(new DRAM_resp(parameters)))
        
        // To DRAM
        val frontend_DRAM_request            =   Decoupled(new DRAM_request(parameters))

        ///////////////////////////
        // D$ BACKEND MEM ACCESS //
        ///////////////////////////

        //// From DRAM
        //val backend_DRAM_resp               =   Flipped(Decoupled(new DRAM_resp(parameters)))
        //// To DRAM
        //val backend_DRAM_request            =   Decoupled(new DRAM_request(parameters))


        val data_cache_response     =   Flipped(Decoupled(new data_cache_response(parameters))) // From MEM
        val data_cache_request      =   Decoupled(new data_cache_request(parameters))     // To MEM
    })


    /////////////
    // MODULES //
    /////////////

    val frontend    = Module(new frontend(parameters))
    val backend     = Module(new backend(parameters))


    val FTQ         = Module(new FTQ(parameters))
    val ROB         = Module(new ROB(parameters))
    val BRU         = Module(new BRU(parameters))



    /////////////////////
    // BACKEND <> DRAM //
    /////////////////////

    backend.io.data_cache_response    <>  io.data_cache_response
    backend.io.data_cache_request     <>  io.data_cache_request


    ////////////////////
    // BACKEND <> BRU //
    ////////////////////

    backend.io.commit <> BRU.io.commit

    /////////////////////
    // FRONTEND <> FTQ //
    /////////////////////

    frontend.io.predictions <> FTQ.io.predictions   //buffer made predictions

    //////////////////////
    // FRONTEND <> DRAM //
    //////////////////////

    frontend.io.DRAM_resp       <>  io.frontend_DRAM_resp
    frontend.io.DRAM_request    <>  io.frontend_DRAM_request

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


    //////////////////////
    // ALLOCATION LOGIC //
    //////////////////////

    // Cant dequeue a fetchpacket from the frontend unless the entire fetch packet is ready
    // This is only true when the ROB has available space and the RS entries (both INT and MEM)
    // Have enough available space


    // overwrite frontend renamed_decoded_fetch_packet ready bit

    val needs_INTRS           = Wire(Vec(fetchWidth, Bool()))
    val needs_MEMRS          = Wire(Vec(fetchWidth, Bool()))

    for(i <- 0 until fetchWidth){
        needs_INTRS(i) := frontend.io.renamed_decoded_fetch_packet.bits.decoded_instruction(i).RS_type === RS_types.INT
        needs_MEMRS(i) := frontend.io.renamed_decoded_fetch_packet.bits.decoded_instruction(i).RS_type === RS_types.MEM
    }

    val all_INT_RS_accepted = Wire(Bool())  // every valid INT RS instruction has an available spot
    val all_MEM_RS_accepted = Wire(Bool())  // every valid MEM RS instruction has an available spot

    // there must be more available RS entries than requesting instructions for that RS
    // Otherwise, entry doesnt allocate
    all_INT_RS_accepted := PopCount(backend.io.INTRS_ready) <= PopCount(needs_INTRS)
    all_MEM_RS_accepted := PopCount(backend.io.MEMRS_ready) <= PopCount(needs_MEMRS)

    frontend.io.renamed_decoded_fetch_packet.ready := (ROB.io.ROB_packet.ready && all_INT_RS_accepted && all_MEM_RS_accepted)

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


}