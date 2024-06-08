/* ------------------------------------------------------------------------------------
* Filename: LSQ.scala
* Author: Hakam Atassi
* Date: June 8 2024
* Description: A simulation only module for printing via memory mapped writes from the core
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


class debug_printer(parameters:Parameters, addressMap:AddressMap) extends Module{
    import parameters._
    import addressMap._

    val io = IO(new Bundle{
        val DRAM_request = Flipped(Decoupled(new DRAM_request(parameters)))
    })

    when((io.DRAM_request.bits.addr === debug_printer_address) && io.DRAM_request.valid){
        printf("%c", io.DRAM_request.bits.wr_data)
    }

    io.DRAM_request.ready := 1.B

}