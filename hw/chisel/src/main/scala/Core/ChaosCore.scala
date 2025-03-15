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
import chisel3.util._


// Top level integrates the Frontend, Allocator, Backend, ROB and FTQ

class ChaosCore(coreParameters:CoreParameters) extends Module{
    
    import coreParameters._

    val io = IO(new Bundle{

        val commit                              =   ValidIO(new commit(coreParameters))
        val flush                               =   ValidIO(new flush(coreParameters))

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

        ////////////////
        // INTERRUPTS //
        ////////////////

        // ibex naming convention
        val irq_software_i                      = Input(Bool())      //msip
        val irq_timer_i                         = Input(Bool())      //mtip
        val irq_external_i                      = Input(Bool())      //meip
        val debug_req_i                         = Input(Bool())      //debug
        val irq_nm_i                            = Input(Bool())      //nmi
        //val [14:0] irq_fast_i =    //fast local interrupts

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

    val ROB         = Module(new ROB(coreParameters))


    io.flush <> ROB.io.flush

    io.revert <> frontend.io.revert

    /////////////////////
    // BACKEND <> DRAM //
    /////////////////////
    backend.io.backend_memory_response    <>  io.backend_memory_response
    backend.io.backend_memory_request     <>  io.backend_memory_request

    ////////////////////
    // BACKEND <> ROB //
    ////////////////////

    backend.io.commit <> ROB.io.commit

    io.commit <> ROB.io.commit

    /////////////////////
    // FRONTEND <> FTQ //
    /////////////////////

    //////////////////////
    // FRONTEND <> DRAM //
    //////////////////////
    frontend.io.memory_request       <>  io.frontend_memory_request
    frontend.io.memory_response      <>  io.frontend_memory_response

    /////////////////////
    // FRONTEND <> ROB //
    /////////////////////
    frontend.io.commit <> ROB.io.commit

    /////////////////////////
    // FRONTEND <> BACKEND //
    /////////////////////////
    frontend.io.FU_outputs <> backend.io.FU_outputs
    frontend.io.FU_outputs(3) <> backend.io.INT_MOB_output      //FIXME: make this dynamic?


    ////////////////////
    // ROB <> BACKEND //
    ////////////////////
    ROB.io.FU_inputs <> backend.io.FU_outputs 
    //ROB.io.mtvec <> backend.io.mtvec
    ROB.CSR_port <> backend.CSR_port

    ROB.io.commit <> backend.io.commit


    ///////////
    // FLUSH //
    ///////////

    frontend.io.flush   <>  ROB.io.flush
    backend.io.flush    <>  ROB.io.flush


    //////////////////////
    // ALLOCATION LOGIC //
    //////////////////////

    val backend_can_allocate = backend.io.backend_packet.map(_.ready).reduce(_ && _) && ROB.io.ROB_packet.ready


    backend.io.fetch_PC   <> frontend.io.renamed_decoded_fetch_packet.bits.fetch_PC
    // ROB and RS do not update until ready
    for(i <- 0 until fetchWidth){
        backend.io.backend_packet(i).bits   := frontend.io.renamed_decoded_fetch_packet.bits.decoded_instruction(i)
        backend.io.backend_packet(i).valid  := frontend.io.renamed_decoded_fetch_packet.valid && frontend.io.renamed_decoded_fetch_packet.bits.decoded_instruction(i).valid && backend_can_allocate
        backend.io.backend_packet(i).bits.ROB_index := ROB.io.ROB_index
    }

    // FIXME: does the frontend have appropriate backpressure incase the ROB cant accept/is not ready????
    ROB.io.ROB_packet           <> frontend.io.renamed_decoded_fetch_packet
    ROB.io.ROB_packet.valid     := frontend.io.renamed_decoded_fetch_packet.valid && backend_can_allocate
    

    for(i <- 0 until fetchWidth){
        ROB.io.ROB_packet.bits.decoded_instruction(i).MOB_index := backend.io.reserved_pointers(i).bits
    }



   

    // Connect branch unit to PC file (which exists in the ROB)
    backend.io.PC_file_exec_addr <> ROB.io.PC_file_exec_addr
    backend.io.PC_file_exec_data <> ROB.io.PC_file_exec_data


    frontend.io.renamed_decoded_fetch_packet.ready := backend_can_allocate


  ////////////////
  // INTERRUPTS //
  ////////////////
  //
  dontTouch(io)

  backend.io.irq_software_i                  := io.irq_software_i    
  backend.io.irq_timer_i                     := io.irq_timer_i
  backend.io.irq_external_i                  := io.irq_external_i
  backend.io.debug_req_i                     := io.debug_req_i
  backend.io.irq_nm_i                        := io.irq_nm_i
  

}
