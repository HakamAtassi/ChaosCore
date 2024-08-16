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

import chisel3.experimental.dataview._

class SOC(coreParameters:CoreParameters, addressMap:AddressMap, nocParameters:NOCParameters) extends Module{

    val m_axi = IO(new VerilogAXIFullIO(nocParameters))

    val dram_AXI = m_axi.viewAs[AXIFullIO]

    ///////////////
    // CHAOSCORE //
    ///////////////
    val ChaosCore_tile = Module(new ChaosCore_tile(coreParameters, addressMap, nocParameters))
    //val flush               = ChaosCore.io.commit.valid && ChaosCore.io.commit.bits.is_misprediction



    /////////////////
    // PERIPHIRALS //
    /////////////////
    val AXI_debug_printer = Module(new AXI_debug_printer(nocParameters, addressMap))
    //instruction_cache.io.flush := flush


    //////////////////
    // INTERCONNECT //
    //////////////////

    val axi_interconnect = Module(new axi_interconnect_2x2(nocParameters))

    axi_interconnect.io := DontCare

    // Connect to NOC

    // D$ <> NOC
    ChaosCore_tile.io.instruction_cache_AXI_port    <> axi_interconnect.io.m_AXI_port(0)

    // I$ <> NOC
    ChaosCore_tile.io.data_cache_AXI_port           <> axi_interconnect.io.m_AXI_port(1)

    // NOC <> IO (DRAM)
    axi_interconnect.io.s_AXI_port(0) <> dram_AXI

    // NOC <> UART
    axi_interconnect.io.s_AXI_port(1) <> AXI_debug_printer.io.s_AXI
    

    dontTouch(axi_interconnect.io)

}