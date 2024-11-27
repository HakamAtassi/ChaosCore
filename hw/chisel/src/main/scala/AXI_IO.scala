/* ------------------------------------------------------------------------------------
* Filename: bundles.scala
* Author: Hakam Atassi
* Date: Apr 23 2024
* Description: useful data channels for use throughout the BP
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

////////////
// AXI AW //
////////////

// chisel io
class AXI_AW(val nocParameters:NOCParameters) extends Bundle{
  import nocParameters._
val awid      = UInt(ID_WIDTH.W)
val awaddr    = UInt(ADDR_WIDTH.W)
val awlen     = UInt(8.W)
val awsize    = UInt(3.W)
val awburst   = UInt(2.W)
val awlock    = UInt(1.W)
val awcache   = UInt(4.W)
val awprot    = UInt(3.W)
val awqos     = UInt(4.W)
val awregion  = UInt(4.W)
val awuser    = UInt(AWUSER_WIDTH.W)
}

/////////
// ??? //
/////////

class AXI_W(val nocParameters:NOCParameters) extends Bundle{
  import nocParameters._
  val wdata = UInt(ADDR_WIDTH.W)
  val wstrb = UInt(STRB_WIDTH.W)
  val wlast = UInt(1.W)
  val wuser = UInt(WUSER_WIDTH.W)
}


/////////
// ??? //
/////////

class AXI_B(val nocParameters:NOCParameters) extends Bundle{
  import nocParameters._
  val bid   = UInt(ID_WIDTH.W)
  val bresp = UInt(2.W)
  val buser = UInt(BUSER_WIDTH.W)
}



/////////
// ??? //
/////////

class AXI_AR(val nocParameters:NOCParameters) extends Bundle{
  import nocParameters._
  val arid    = UInt(ID_WIDTH.W)
  val araddr  = UInt(ADDR_WIDTH.W)
  val arlen   = UInt(8.W)
  val arsize  = UInt(3.W)
  val arburst = UInt(2.W)
  val arlock  = UInt(1.W)
  val arcache = UInt(4.W)
  val arprot  = UInt(3.W)
  val arqos   = UInt(4.W)
  val arregion= UInt(4.W)
  val aruser  = UInt(ARUSER_WIDTH.W)
}



/////////
// ??? //
/////////

class AXI_R(val nocParameters:NOCParameters) extends Bundle{
  import nocParameters._
  val rid   = UInt(ID_WIDTH.W)
  val rdata = UInt(DATA_WIDTH.W)
  val rresp = UInt(2.W)
  val rlast = UInt(1.W)
  val ruser = UInt(RUSER_WIDTH.W)
}

////////////
// AXI IO //
////////////

// AXI master chisel IO
class AXIFullIO(val nocParameters:NOCParameters) extends Bundle {
  import nocParameters._
  val AXI_AW = Decoupled(new AXI_AW(nocParameters))                 // AXI Write address request
  val AXI_W  = Decoupled(new AXI_W(nocParameters))                  // AXI Write Data 
  val AXI_B  = Flipped(Decoupled(new AXI_B(nocParameters)))         // AXI Write Response
  val AXI_AR = Decoupled(new AXI_AR(nocParameters))                 // AXI Read Address
  val AXI_R  = Flipped(Decoupled(new AXI_R(nocParameters)))         // AXI read Response
}

// AXI master verilog IO
class VerilogAXIFullIO(val nocParameters:NOCParameters) extends Bundle {
  import nocParameters._
    // AW 
val awvalid   = Output(Bool())
val awready   = Input(Bool())
val awid      = Output(UInt(ID_WIDTH.W))
val awaddr    = Output(UInt(ADDR_WIDTH.W))
val awlen     = Output(UInt(8.W))
val awsize    = Output(UInt(3.W))
val awburst   = Output(UInt(2.W))
val awlock    = Output(UInt(1.W))
val awcache   = Output(UInt(4.W))
val awprot    = Output(UInt(3.W))
val awqos     = Output(UInt(4.W))
val awregion  = Output(UInt(4.W))
val awuser    = Output(UInt(AWUSER_WIDTH.W))

// W
val wready   = Input(Bool())
val wvalid   = Output(Bool())
val wdata = Output(UInt(ADDR_WIDTH.W))
val wstrb = Output(UInt(STRB_WIDTH.W))
val wlast = Output(UInt(1.W))
val wuser = Output(UInt(WUSER_WIDTH.W))

// B
val bready= Output(Bool())
val bvalid= Input(Bool())
val bid   = Input(UInt(ID_WIDTH.W))
val bresp = Input(UInt(2.W))
val buser = Input(UInt(BUSER_WIDTH.W))

// AR
val arvalid   = Output(Bool())
val arready   = Input(Bool())
val arid    = Output(UInt(ID_WIDTH.W))
val araddr  = Output(UInt(ADDR_WIDTH.W))
val arlen   = Output(UInt(8.W))
val arsize  = Output(UInt(3.W))
val arburst = Output(UInt(2.W))
val arlock  = Output(UInt(1.W))
val arcache = Output(UInt(4.W))
val arprot  = Output(UInt(3.W))
val arqos   = Output(UInt(4.W))
val arregion= Output(UInt(4.W))
val aruser  = Output(UInt(ARUSER_WIDTH.W))


// R
val rready   = Output(Bool())
val rvalid   = Input(Bool())
val rid   = Input(UInt(ID_WIDTH.W))
val rdata = Input(UInt(DATA_WIDTH.W))
val rresp = Input(UInt(2.W))
val rlast = Input(UInt(1.W))
val ruser = Input(UInt(RUSER_WIDTH.W))

}


// Mapping of standard verilog AXI io *to* Chisel AXI io



object AXIFullIO {

  implicit val AXI_VIEW = DataView[VerilogAXIFullIO, AXIFullIO](
    vab => new AXIFullIO(vab.nocParameters),

        // AXI AW 
        _.awvalid   -> _.AXI_AW.valid,
        _.awready   -> _.AXI_AW.ready,
        _.awid      -> _.AXI_AW.bits.awid,
        _.awaddr    -> _.AXI_AW.bits.awaddr,
        _.awlen     -> _.AXI_AW.bits.awlen,
        _.awsize    -> _.AXI_AW.bits.awsize,
        _.awburst   -> _.AXI_AW.bits.awburst,
        _.awlock    -> _.AXI_AW.bits.awlock,
        _.awcache   -> _.AXI_AW.bits.awcache,
        _.awprot    -> _.AXI_AW.bits.awprot,
        _.awqos     -> _.AXI_AW.bits.awqos,
        _.awregion  -> _.AXI_AW.bits.awregion,
        _.awuser    -> _.AXI_AW.bits.awuser,

        // AXI W 
        _.wvalid -> _.AXI_W.valid,
        _.wready -> _.AXI_W.ready,
        _.wdata  -> _.AXI_W.bits.wdata,
        _.wstrb  -> _.AXI_W.bits.wstrb,
        _.wlast  -> _.AXI_W.bits.wlast,
        _.wuser  -> _.AXI_W.bits.wuser,


        // AXI B
        _.bvalid-> _.AXI_B.valid,
        _.bready-> _.AXI_B.ready,
        _.bid   -> _.AXI_B.bits.bid,
        _.bresp -> _.AXI_B.bits.bresp,
        _.buser -> _.AXI_B.bits.buser,

        // AXI AR
        _.arvalid ->    _.AXI_AR.valid,
        _.arready ->    _.AXI_AR.ready,
        _.arid    ->    _.AXI_AR.bits.arid,
        _.araddr  ->    _.AXI_AR.bits.araddr,
        _.arlen   ->    _.AXI_AR.bits.arlen,
        _.arsize  ->    _.AXI_AR.bits.arsize,
        _.arburst ->    _.AXI_AR.bits.arburst,
        _.arlock  ->    _.AXI_AR.bits.arlock,
        _.arcache ->    _.AXI_AR.bits.arcache,
        _.arprot  ->    _.AXI_AR.bits.arprot,
        _.arqos   ->    _.AXI_AR.bits.arqos,
        _.arregion->    _.AXI_AR.bits.arregion,
        _.aruser  ->    _.AXI_AR.bits.aruser,

        // AXI R
        _.rvalid->_.AXI_R.valid,
        _.rready->_.AXI_R.ready,
        _.rid   -> _.AXI_R.bits.rid,
        _.rdata -> _.AXI_R.bits.rdata,
        _.rresp -> _.AXI_R.bits.rresp,
        _.rlast -> _.AXI_R.bits.rlast,
        _.ruser -> _.AXI_R.bits.ruser,

  )
}


// use dataview to maintain standard AXIO names


// Verilog AXI 


