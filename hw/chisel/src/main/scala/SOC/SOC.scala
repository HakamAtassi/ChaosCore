/* ------------------------------------------------------------------------------------
* Filename: SOC.scala
* Author: Hakam Atassi
* Date: June 9 2024
* Description: Top level SOC including periphirals
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

class SOC(parameters:Parameters, addressMap:AddressMap) extends Module{

    val io = IO(new Bundle{
        val frontend_memory_request                =   Decoupled(new memory_request(parameters))
        val frontend_memory_response               =   Flipped(Decoupled(new DRAM_resp(parameters)))

        ///////////////////////////
        // D$ BACKEND MEM ACCESS //
        ///////////////////////////

        val backend_memory_request                =   Decoupled(new memory_request(parameters))
        val backend_memory_response               =   Flipped(Decoupled(new memory_response(parameters)))
    })

    ///////////////
    // CHAOSCORE //
    ///////////////

    val ChaosCore = Module(new ChaosCore(parameters))


    ////////////////////
    // PIPELINE FLUSH //
    ////////////////////

    ////////////
    // CACHES //
    ////////////

    // TODO: forward kill signal to the cache to kill requests
    val instruction_cache   = Module(new instruction_cache(parameters))

    instruction_cache.io.memory_response        <> io.frontend_memory_response
    instruction_cache.io.memory_request         <> io.frontend_memory_request


    /////////////////
    // PERIPHIRALS //
    /////////////////

    val debug_printer = Module(new debug_printer(parameters, addressMap))


    /////////////////
    // CONNECTIONS //
    /////////////////


    ChaosCore.io.frontend_memory_response    <> io.frontend_memory_response
    ChaosCore.io.frontend_memory_request     <> io.frontend_memory_request

    ChaosCore.io.backend_memory_response     <> io.backend_memory_response
    ChaosCore.io.backend_memory_request      <> io.backend_memory_request

    ChaosCore.io.backend_memory_request  <> debug_printer.io.memory_request



}