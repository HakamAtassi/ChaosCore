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


    val FTQ         = Module(new FTQ(parameters))
    val ROB         = Module(new ROB(parameters))
    val BRU         = Module(new BRU(parameters))



    /////////////////////
    // BACKEND <> DRAM //
    /////////////////////

    backend.io.DRAM_resp        <>  io.backend_DRAM_resp
    backend.io.DRAM_request     <>  io.backend_DRAM_request


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

    ROB.io.ROB <>  BRU.io.ROB


    ////////////////
    // BRU <> FTQ //
    ////////////////

    BRU.io.FTQ <> FTQ.io.FTQ



    frontend.io.renamed_decoded_fetch_packet <> backend.io.backend_packet
    ROB.io.ROB_packet <> frontend.io.ROB_packet

    frontend.io.MEMRS_ready <> backend.io.MEMRS_ready
    frontend.io.INTRS_ready <> backend.io.INTRS_ready



}