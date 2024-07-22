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

/*

class SOC(coreParameters:CoreParameters, addressMap:AddressMap, nocParameters:NOCParameters) extends Module{

    val io = IO(new Bundle{
        ////////////////////////
        // TILELINK INTERFACE //
        ////////////////////////
		val DRAM_TL_A                      = Decoupled(new TileLink_Channel_A())
		val DRAM_TL_D                      = Flipped(Decoupled(new TileLink_Channel_D()))
    })

    ///////////////
    // CHAOSCORE //
    ///////////////

    val ChaosCore           = Module(new ChaosCore(coreParameters))
    val flush               = ChaosCore.io.commit.valid && ChaosCore.io.commit.bits.is_misprediction

    ////////////
    // CACHES //
    ////////////
    val instruction_cache   = Module(new instruction_cache(coreParameters, nocParameters))
    val data_cache          = Module(new blocking_data_cache(coreParameters, nocParameters))

    /////////////////
    // PERIPHIRALS //
    /////////////////

    val debug_printer = Module(new debug_printer(coreParameters, addressMap))


    ChaosCore.io.frontend_memory_response    <> instruction_cache.io.CPU_response
    ChaosCore.io.frontend_memory_request     <> instruction_cache.io.CPU_request 
    instruction_cache.io.flush := flush

    ChaosCore.io.backend_memory_response     <> data_cache.io.backend_memory_response
    ChaosCore.io.backend_memory_request      <> data_cache.io.backend_memory_request

    //////////////
    // CORE BUS //
    //////////////
    val core_bus = Module(new core_bus())
    val system_bus = Module(new system_bus(coreParameters, addressMap))

    core_bus.io.instruction_cache_A <> instruction_cache.io.instruction_cache_A
    core_bus.io.instruction_cache_D <> instruction_cache.io.instruction_cache_D

    core_bus.io.data_cache_A        <> data_cache.io.data_cache_A
    core_bus.io.data_cache_D        <> data_cache.io.data_cache_D

    core_bus.io.system_bus_A        <> system_bus.io.core_bus_A
    core_bus.io.system_bus_D        <> system_bus.io.core_bus_D

    ////////////////
    // SYSTEM BUS //
    ////////////////

    system_bus.io.debug_printer_A <> debug_printer.io.debug_printer_A
    system_bus.io.debug_printer_D <> debug_printer.io.debug_printer_D

    system_bus.io.DRAM_A          <> io.DRAM_TL_A
    system_bus.io.DRAM_D          <> io.DRAM_TL_D


}
*/