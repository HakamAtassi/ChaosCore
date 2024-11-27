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
import chisel3.util._
import chisel3.experimental.dataview._
import chisel3.experimental.ChiselEnum

class AXI_debug_printer(nocParameters: NOCParameters, addressMap:AddressMap) extends Module{
    import addressMap._
    import nocParameters._

    // actual verilog IO
    // chisel dataview mapping
    val s_axi = IO(Flipped(new VerilogAXIFullIO(nocParameters)))
    val AXI_port = s_axi.viewAs[AXIFullIO]
    dontTouch(s_axi)

    object AXI_debug_printer_STATES extends ChiselEnum {
      val IDLE, WAIT_DATA, PRINTING = Value
    }

    val print_data = Reg(UInt(32.W))

    val AXI_debug_printer_STATE = RegInit(AXI_debug_printer_STATES(), AXI_debug_printer_STATES.IDLE)

    AXI_port.AXI_AW.ready   := 0.B
    AXI_port.AXI_W.ready    := 0.B
    AXI_port.AXI_B.valid    := 0.B
    AXI_port.AXI_B.bits     := 0.U.asTypeOf(new AXI_B(nocParameters))

    AXI_port.AXI_AR.ready   :=  0.B
    AXI_port.AXI_R.valid    :=  0.B
    AXI_port.AXI_R.bits     :=  0.U.asTypeOf(new AXI_R(nocParameters))

    switch(AXI_debug_printer_STATE){
      is(AXI_debug_printer_STATES.IDLE){
        // Write Channels ready
        // Read Channels never ready
        AXI_port.AXI_AW.ready := 1.B
        AXI_port.AXI_W.ready := 1.B
//        when(AXI_port.AXI_AW.fire){
          //// AW channel received
          //AXI_debug_printer_STATE := AXI_debug_printer_STATES.WAIT_DATA
        //}.elsewhen(AXI_port.AXI_AW.fire && AXI_port.AXI_W.fire){
          //// AW and W channel recieved
          //print_data := AXI_port.AXI_W.bits.wdata;
          //AXI_debug_printer_STATE := AXI_debug_printer_STATES.PRINTING
        //}
        when(AXI_port.AXI_AW.fire && AXI_port.AXI_W.fire){
          // AW and W channel recieved
          print_data := AXI_port.AXI_W.bits.wdata;
          AXI_debug_printer_STATE := AXI_debug_printer_STATES.PRINTING
        }.elsewhen(AXI_port.AXI_AW.fire){
          AXI_debug_printer_STATE := AXI_debug_printer_STATES.WAIT_DATA
        }
      }

      is(AXI_debug_printer_STATES.WAIT_DATA){
        // AW Channel unready
        // W Channel ready
        when(AXI_port.AXI_W.fire){
          print_data := AXI_port.AXI_W.bits.wdata;
          AXI_debug_printer_STATE := AXI_debug_printer_STATES.PRINTING
        }
      }

      is(AXI_debug_printer_STATES.PRINTING){
        // print data
        printf("%c", print_data)

        // generate B response 
        AXI_port.AXI_B.valid := 1.B

        // goto idle state
        // FIXME: what if AXI_B is not ready???
        when(AXI_port.AXI_B.fire){
          AXI_debug_printer_STATE := AXI_debug_printer_STATES.IDLE
        }
      }
    }






}
