/* ------------------------------------------------------------------------------------
* Filename: system_bus.scala
* Author: Hakam Atassi
* Date: July 20 2024
* Description: 
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
import java.io.{File, FileWriter}
import java.rmi.server.UID

// I$ ID == 0
// D$ ID == 1

class system_bus(coreParameters:CoreParameters, addressMap:AddressMap) extends Module {
    import coreParameters._
    import addressMap._
    val io = IO(new Bundle {
        // Inputs 
        val core_bus_A                 = Flipped(Decoupled(new TileLink_Channel_A()))   // I$ Request
        val core_bus_D                 = Decoupled(new TileLink_Channel_D())   // Bus granted request
                                    
        // Outputs (Bus out)
        val debug_printer_A            = Decoupled(new TileLink_Channel_A())
        val debug_printer_D            = Flipped(Decoupled(new TileLink_Channel_D()))

        val DRAM_A                     = Decoupled(new TileLink_Channel_A())
        val DRAM_D                     = Flipped(Decoupled(new TileLink_Channel_D()))
    })


    //////////////
    // REQUESTS //
    //////////////

    val is_DRAM             = (io.core_bus_A.bits.a_address >= DRAM_low) && (io.core_bus_A.bits.a_address <= DRAM_high) && io.core_bus_A.valid
    val is_debug_printer    = (io.core_bus_A.bits.a_address === debug_printer_address) && io.core_bus_A.valid

    io.DRAM_A <> 0.U.asTypeOf(Decoupled(new TileLink_Channel_A()))
    io.debug_printer_A <> 0.U.asTypeOf(Decoupled(new TileLink_Channel_A()))
    io.core_bus_A <> 0.U.asTypeOf(Decoupled(new TileLink_Channel_A()))

    when(is_DRAM){
        io.DRAM_A <> io.core_bus_A
    }.elsewhen(is_debug_printer){
        io.debug_printer_A <> io.core_bus_A
    }


    ///////////////
    // RESPONSES //
    ///////////////

    val debug_printer_queue        =  Module(new Queue(new TileLink_Channel_D(), 2, flow=true, hasFlush=false, useSyncReadMem=false))
    val DRAM_queue                =  Module(new Queue(new TileLink_Channel_D(), 2, flow=true, hasFlush=false, useSyncReadMem=false))

    debug_printer_queue.io.enq <> io.debug_printer_D
    DRAM_queue.io.enq <> io.DRAM_D


    val arbiter = Module(new RRArbiter(new TileLink_Channel_D(), 2))

    // Connect the queues to the arbiter
    arbiter.io.in(0) <> debug_printer_queue.io.deq
    arbiter.io.in(1) <> DRAM_queue.io.deq

    // Connect the arbiter output to core_bus_D
    io.core_bus_D <> arbiter.io.out





  
}