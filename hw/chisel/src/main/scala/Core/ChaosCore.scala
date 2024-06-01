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

    val io = IO(new Bundle{

        ////////////////////////////
        // I$ FRONTEND MEM ACCESS //
        ////////////////////////////

        // From DRAM
        val frontend_DRAM_resp               =   Flipped(Decoupled(Input(new DRAM_resp(parameters))))
        
        // To DRAM
        val frontend_DRAM_request            =   Decoupled(new DRAM_request(parameters))

        ///////////////////////////
        // D$ BACKEND MEM ACCESS //
        ///////////////////////////

        // From DRAM
        val backend_DRAM_resp               =   Flipped(Decoupled(Input(new DRAM_resp(parameters))))

        // To DRAM
        val backend_DRAM_request            =   Decoupled(new DRAM_request(parameters))
    })


    /////////////
    // MODULES //
    /////////////

    val frontend    = Module(new frontend(parameters))
    val backend     = Module(new backend(parameters))

    val allocator   = Module(new allocator(parameters))

    val FTQ         = Module(new FTQ(parameters))
    val ROB         = Module(new ROB(parameters))
    val BRU         = Module(new BRU(parameters))



    /////////////////////
    // BACKEND <> DRAM //
    /////////////////////

    backend.io.DRAM_resp        <>  io.backend_DRAM_resp
    backend.io.DRAM_request     <>  io.backend_DRAM_request

    ///////////////////////////
    // BACKEND <> ALLOCATOR //
    ///////////////////////////
    
    backend.io.backend_packet   <>  allocator.io.backend_packet
    backend.io.MEMRS_ready      <>  allocator.io.MEMRS_ready
    backend.io.INTRS_ready      <>  allocator.io.INTRS_ready

    backend.io.MEMRS_sources_ready      <>  allocator.io.MEMRS_sources_ready
    backend.io.INTRS_sources_ready      <>  allocator.io.INTRS_sources_ready

    ////////////////////
    // BACKEND <> BRU //
    ////////////////////

    backend.io.misprediction <> BRU.io.misprediction

    /////////////////////
    // FRONTEND <> FTQ //
    /////////////////////

    frontend.io.prediction <> FTQ.io.prediction   //buffer made predictions

    //////////////////////
    // FRONTEND <> DRAM //
    //////////////////////

    frontend.io.DRAM_resp       <>  io.frontend_DRAM_resp
    frontend.io.DRAM_request    <>  io.frontend_DRAM_request

    ///////////////////////////
    // FRONTEND <> ALLOCATOR //
    ///////////////////////////
    
    frontend.io.renamed_decoded_fetch_packet <> allocator.io.renamed_decoded_fetch_packet // this name sucks

    /////////////////////
    // FRONTEND <> BRU //
    /////////////////////

    frontend.io.misprediction <> BRU.io.misprediction

    /////////////////////////
    // FRONTEND <> BACKEND //
    /////////////////////////

    frontend.io.FU_outputs <> backend.io.FU_outputs

    //////////////////////
    // ROB <> ALLOCATOR //
    //////////////////////
    
    ROB.io.ROB_packet <> allocator.io.ROB_packet

    ////////////////////
    // ROB <> BACKEND //
    ////////////////////

    ROB.io.FU_outputs <> backend.io.FU_outputs 

    ////////////////////
    // FTQ <> BACKEND //
    ////////////////////

    FTQ.io.FU_outputs <> backend.io.FU_outputs

    ////////////////
    // ROB <> FTQ //
    ////////////////

    ROB.io.ROB_commit <> FTQ.io.ROB_commit

    ////////////////
    // ROB <> BRU //
    ////////////////

    ROB.io.ROB_commit <>  BRU.io.ROB_commit


    ////////////////
    // BRU <> FTQ //
    ////////////////

    BRU.io.FTQ <> FTQ.io.FTQ

}