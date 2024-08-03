
/* ------------------------------------------------------------------------------------
* Filename: axi_interconnect.scala
* Author: Hakam Atassi
* Date: May 22 2024
* Description: A blackbox for alex forenchich's axi interconnect
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
import chisel3.experimental._

import circt.stage.ChiselStage 

import chisel3.util._



// Define the BlackBox module
class axi_ram(nocParameters:NOCParameters) extends BlackBox(Map(
  "DATA_WIDTH"      -> nocParameters.DATA_WIDTH,
  //"ADDR_WIDTH"      -> nocParameters.ADDR_WIDTH,
  //"STRB_WIDTH"      -> nocParameters.STRB_WIDTH,
  //"ID_WIDTH"        -> nocParameters.ID_WIDTH,

)) with HasBlackBoxResource{

  import nocParameters._

  val io = IO(new Bundle {
    val clk = Input(Clock())
    val rst = Input(Bool())

    val s_axi_awid = Input(UInt(ID_WIDTH.W))
    val s_axi_awaddr = Input(UInt(ADDR_WIDTH.W))
    val s_axi_awlen = Input(UInt(8.W))
    val s_axi_awsize = Input(UInt(3.W))
    val s_axi_awburst = Input(UInt((2).W))
    val s_axi_awlock = Input(UInt(1.W))
    val s_axi_awcache = Input(UInt((4).W))
    val s_axi_awprot = Input(UInt((3).W))
    val s_axi_awvalid = Input(UInt(1.W))
    val s_axi_awready = Output(UInt(1.W))

    val s_axi_wdata = Input(UInt((DATA_WIDTH).W))
    val s_axi_wstrb = Input(UInt(((STRB_WIDTH)).W))
    val s_axi_wlast = Input(UInt(1.W))
    val s_axi_wvalid = Input(UInt(1.W))
    val s_axi_wready = Output(UInt(1.W))

    val s_axi_bid = Output(UInt((ID_WIDTH).W))
    val s_axi_bresp = Output(UInt((1).W))
    val s_axi_bvalid = Output(UInt(1.W))
    val s_axi_bready = Input(UInt(1.W))

    val s_axi_arid = Input(UInt((ID_WIDTH).W))
    val s_axi_araddr = Input(UInt(ADDR_WIDTH.W))
    val s_axi_arlen = Input(UInt((8).W))
    val s_axi_arsize = Input(UInt((3).W))
    val s_axi_arburst = Input(UInt((2).W))
    val s_axi_arlock = Input(UInt(1.W))
    val s_axi_arcache = Input(UInt((4).W))
    val s_axi_arprot = Input(UInt((3).W))
    val s_axi_arvalid = Input(UInt(1.W))
    val s_axi_arready = Output(UInt(1.W))

    val s_axi_rid = Output(UInt((ID_WIDTH).W))
    val s_axi_rdata = Output(UInt((DATA_WIDTH).W))
    val s_axi_rresp = Output(UInt((2).W))
    val s_axi_rlast = Output(UInt(1.W))
    val s_axi_rvalid = Output(UInt(1.W))
    val s_axi_rready = Input(UInt(1.W))
  })

  // Reference the external Verilog file
  addResource("/verilog-axi/rtl/axi_ram.v")
}
