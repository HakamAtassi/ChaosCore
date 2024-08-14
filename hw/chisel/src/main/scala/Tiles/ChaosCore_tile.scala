/* ------------------------------------------------------------------------------------
* Filename: ChaosCore_tile.scala
* Author: Hakam Atassi
* Date: August 7 2024
* Description: A tile instantiation of ChaosCore
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

class ChaosCore_tile(coreParameters:CoreParameters, addressMap:AddressMap, nocParameters:NOCParameters) extends Module{
    val io = IO(new Bundle{
        /////////////////
        // I$ AXI Port //
        /////////////////
        val instruction_cache_AXI_port = new AXIFullIO(nocParameters)

        /////////////////
        // D$ AXI Port //
        /////////////////
        val data_cache_AXI_port         = new AXIFullIO(nocParameters)
    })
    // This module instantiates ChaosCore, connects caches, and propegates its AXI ports

    ///////////////
    // CHAOSCORE //
    ///////////////
    val ChaosCore           = Module(new ChaosCore(coreParameters))
    //val flush               = ChaosCore.io.commit.valid && ChaosCore.io.commit.bits.is_misprediction

    ////////////
    // CACHES //
    ////////////
    val instruction_cache   = Module(new L1_instruction_cache(coreParameters, nocParameters))
    val data_cache          = Module(new L1_data_cache(coreParameters, nocParameters))
    
    ChaosCore.io.frontend_memory_request    <> instruction_cache.io.CPU_request     // FIXME: rename these signals in the I$ to be more cohesive
    ChaosCore.io.frontend_memory_response   <> instruction_cache.io.CPU_response        // FIXME: rename these signals in the I$ to be more cohesive

    ChaosCore.io.backend_memory_request     <> data_cache.io.CPU_request
    ChaosCore.io.backend_memory_response    <> data_cache.io.CPU_response


    instruction_cache.io         := DontCare


    data_cache.io                := DontCare
    
    data_cache.AXI_port.AXI_AW   := DontCare
    data_cache.AXI_port.AXI_B    := DontCare
    data_cache.AXI_port.AXI_W    := DontCare
    data_cache.AXI_port.AXI_AR   := DontCare
    data_cache.AXI_port.AXI_R    := DontCare


    ////////
    // IO //
    ////////


    // CACHE <> IO //
    instruction_cache.AXI_port <> io.instruction_cache_AXI_port
    data_cache.AXI_port        <> io.data_cache_AXI_port

}