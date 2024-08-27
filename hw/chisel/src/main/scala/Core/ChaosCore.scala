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

class ChaosCore(coreParameters:CoreParameters) extends Module{
    
    import coreParameters._

    val io = IO(new Bundle{

        val commit                              =   ValidIO(new commit(coreParameters))
        val kill                               =   Output(Bool())

        val revert                              =   ValidIO(new revert(coreParameters))

        ////////////////////////////
        // I$ FRONTEND MEM ACCESS //
        ////////////////////////////
        val frontend_memory_request             =   Decoupled(new frontend_memory_request(coreParameters))
        val frontend_memory_response            =   Flipped(Decoupled(new fetch_packet(coreParameters)))

        ///////////////////////////
        // D$ BACKEND MEM ACCESS //
        ///////////////////////////
        val backend_memory_request              =   Decoupled(new backend_memory_request(coreParameters))
        val backend_memory_response             =   Flipped(Decoupled(new backend_memory_response(coreParameters)))
    }); dontTouch(io)

    //////////////////
    // REQUIREMENTS //
    //////////////////
    require(isPow2(physicalRegCount-1), "Number of physical regs must be a power of 2 (excluding x0)")
    require(isPow2(ROBEntries), "ROB entries not a power of 2")
    require(isPow2(RSEntries), "Reservation station entries not a power of 2")

    /////////////
    // MODULES //
    /////////////

    val frontend    = Module(new frontend(coreParameters))
    val backend     = Module(new backend(coreParameters))


    val FTQ         = Module(new FTQ(coreParameters))
    val ROB         = Module(new ROB(coreParameters))
    val BRU         = Module(new BRU(coreParameters))


    val flush       = Wire(Bool())


    io.kill := flush

    io.revert <> frontend.io.revert

    /////////////////////
    // BACKEND <> DRAM //
    /////////////////////
    backend.io.backend_memory_response    <>  io.backend_memory_response
    backend.io.backend_memory_request     <>  io.backend_memory_request

    ////////////////////
    // BACKEND <> BRU //
    ////////////////////

    backend.io.commit <> BRU.io.commit

    io.commit <> BRU.io.commit

    /////////////////////
    // FRONTEND <> FTQ //
    /////////////////////

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
    flush := BRU.io.commit.valid && (BRU.io.commit.bits.is_misprediction || BRU.io.commit.bits.violation)

    frontend.io.flush   <>  flush
    backend.io.flush    <>  flush
    ROB.io.flush        <>  flush
    FTQ.io.flush        <>  flush


    //////////////////////
    // ALLOCATION LOGIC //
    //////////////////////

    val backend_can_allocate = backend.io.backend_packet.map(_.ready).reduce(_ && _) && ROB.io.ROB_packet.ready && FTQ.io.predictions.ready


    backend.io.fetch_PC   <> frontend.io.renamed_decoded_fetch_packet.bits.fetch_PC
    // ROB and RS do not update until ready
    for(i <- 0 until fetchWidth){
        backend.io.backend_packet(i).bits   := frontend.io.renamed_decoded_fetch_packet.bits.decoded_instruction(i)
        backend.io.backend_packet(i).valid  := frontend.io.renamed_decoded_fetch_packet.valid && frontend.io.renamed_decoded_fetch_packet.bits.valid_bits(i) && backend_can_allocate
        backend.io.backend_packet(i).bits.FTQ_index := FTQ.io.FTQ_index
        backend.io.backend_packet(i).bits.ROB_index := ROB.io.ROB_index
    }

    // FIXME: does the frontend have appropriate backpressure incase the ROB cant accept/is not ready????
    ROB.io.ROB_packet           <> frontend.io.renamed_decoded_fetch_packet
    ROB.io.ROB_packet.valid     := frontend.io.renamed_decoded_fetch_packet.valid && backend_can_allocate

   
    frontend.io.predictions.ready := backend_can_allocate
    FTQ.io.predictions.valid  := frontend.io.predictions.valid && backend_can_allocate
    FTQ.io.predictions.bits  := frontend.io.predictions.bits


    FTQ.io.ROB_index <> ROB.io.ROB_index

    // Connect branch unit to PC file (which exists in the ROB)
    backend.io.PC_file_exec_addr <> ROB.io.PC_file_exec_addr
    backend.io.PC_file_exec_data <> ROB.io.PC_file_exec_data


    frontend.io.renamed_decoded_fetch_packet.ready := backend_can_allocate

}