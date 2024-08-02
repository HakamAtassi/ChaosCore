package ChaosCore

import chisel3._
import chisel3.util._

class AXI_AW(nocParameters:NOCParameters) extends Bundle{
  import nocParameters._
  val m_axi_awid      = UInt(ID_WIDTH.W)
  val m_axi_awaddr    = UInt(ADDR_WIDTH.W)
  val m_axi_awlen     = UInt(8.W)
  val m_axi_awsize    = UInt(3.W)
  val m_axi_awburst   = UInt(2.W)
  val m_axi_awlock    = UInt(1.W)
  val m_axi_awcache   = UInt(4.W)
  val m_axi_awprot    = UInt(3.W)
}

class AXI_W(nocParameters:NOCParameters) extends Bundle{
  import nocParameters._
  val m_axi_wdata = UInt(ADDR_WIDTH.W)
  val m_axi_wstrb = UInt(STRB_WIDTH.W)
  val m_axi_wlast = UInt(1.W)
}

class AXI_B(nocParameters:NOCParameters) extends Bundle{
  import nocParameters._
  val m_axi_bid   = UInt(ID_WIDTH.W)
  val m_axi_bresp = UInt(2.W)
}

class AXI_AR(nocParameters:NOCParameters) extends Bundle{
  import nocParameters._
  val m_axi_arid    = UInt(ID_WIDTH.W)
  val m_axi_araddr  = UInt(ADDR_WIDTH.W)
  val m_axi_arlen   = UInt(8.W)
  val m_axi_arsize  = UInt(3.W)
  val m_axi_arburst = UInt(2.W)
  val m_axi_arlock  = UInt(1.W)
  val m_axi_arcache = UInt(4.W)
  val m_axi_arprot  = UInt(3.W)
}

class AXI_R(nocParameters:NOCParameters) extends Bundle{
  import nocParameters._
  val m_axi_rid   = UInt(ID_WIDTH.W)
  val m_axi_rdata = UInt(DATA_WIDTH.W)
  val m_axi_rresp = UInt(2.W)
  val m_axi_rlast = UInt(1.W)
}


class AXIFullIO(nocParameters:NOCParameters) extends Bundle {
  import nocParameters._
  val AXI_AW = Output(new AXI_AW(nocParameters))       // AXI Write address request
  val AXI_W  = Output(new AXI_W(nocParameters))        // AXI Write Data 
  val AXI_B  = Input(new AXI_B(nocParameters))         // AXI Write Response
  val AXI_AR = Output(new AXI_AR(nocParameters))       // AXI Read Address
  val AXI_R  = Input(new AXI_R(nocParameters))         // AXI read Response
}


/**
AXI FULL NODE is for use in the transport of cache lines across the system interconnect. 
On write request, the AXI node will assert AXI AW (address and metadata). It will also assert the first unit of data.
The AXI node may then either accept the first unit of data AND the AW data, or may way some period of time for the W data to be accepted. 
The AXI node will then transport 1 beat at a time in an INCR only burst type. 
*/

trait AXICacheNode {

  val nocParameters:NOCParameters

  val AXI_AW    = IO(Decoupled(new AXI_AW(nocParameters)))
  val AXI_W     = IO(Decoupled(new AXI_W(nocParameters)))
  val AXI_B     = IO(Flipped(Decoupled(new AXI_B(nocParameters))))

  val AXI_AR    = IO(Decoupled(new AXI_AR(nocParameters)))
  val AXI_R     = IO(Flipped(Decoupled(new AXI_R(nocParameters))))

  class AXI_request(nocParameters:NOCParameters) extends Bundle {
    val AXI_AW    = ValidIO(new AXI_AW(nocParameters))
    val AXI_W     = ValidIO(new AXI_W(nocParameters))
    val AXI_AR    = ValidIO(new AXI_AR(nocParameters))
  }


  ///////////////////////
  // DEASSERT REQUESTS //
  ///////////////////////

  // Response channels
  AXI_B.ready   := 0.B
  AXI_R.ready   := 0.B

  // axi defaults
  AXI_AW.bits   := 0.U.asTypeOf(new AXI_AW(nocParameters))
  AXI_AW.valid  := 0.B

  AXI_W.bits    := 0.U.asTypeOf(new AXI_W(nocParameters))
  AXI_W.valid   := 0.B

  AXI_AR.bits   := 0.U.asTypeOf(new AXI_AR(nocParameters))
  AXI_AR.valid  := 0.B


  // Reconstructed response buffer
  val final_response_buffer = Module(new Queue(UInt(256.W), 1, flow=true, hasFlush=false, useSyncReadMem=false))
  final_response_buffer.io.deq.ready := 0.B
  final_response_buffer.io.enq.valid := 0.B
  final_response_buffer.io.enq.bits := DontCare

  //////////
  // APIs //
  //////////

  def AXI_read_request(address:UInt, bytes:UInt):Bool = {

    // drive channels
    AXI_AR.valid              := 1.B
    AXI_AR.bits.m_axi_arid    := 0.U
    AXI_AR.bits.m_axi_araddr  := address
    AXI_AR.bits.m_axi_arlen   := 0.U
    AXI_AR.bits.m_axi_arsize  := 0.U
    AXI_AR.bits.m_axi_arburst := 0x1.U
    AXI_AR.bits.m_axi_arlock  := 0x0.U
    AXI_AR.bits.m_axi_arcache := 0x0.U
    AXI_AR.bits.m_axi_arprot  := 0x0.U

    when(AXI_AR.fire && final_response_buffer.io.enq.ready){
      printf("AXI read accepted")
    }.otherwise{
      printf("AXI read not accepted")
    }
    AXI_AR.fire
  }
  
  val AXI_AW_DATA_BUFFER = Reg(UInt(256.W))   // FIXME: make this a param based on cache line width
  def AXI_write_request(address:UInt, data:UInt, bytes:UInt):Bool = {

    // Queue AXI request
    AXI_AW.valid                := 1.B
    AXI_AW.bits.m_axi_awid      := 0.U
    AXI_AW.bits.m_axi_awaddr    := address
    AXI_AW.bits.m_axi_awlen     := 0.U
    AXI_AW.bits.m_axi_awsize    := 0.U
    AXI_AW.bits.m_axi_awburst   := 0x0.U
    AXI_AW.bits.m_axi_awlock    := 0.U
    AXI_AW.bits.m_axi_awcache   := 0.U
    AXI_AW.bits.m_axi_awprot    := 0.U




    when(AXI_AW.fire){
      AXI_AW_DATA_BUFFER := data
      printf("AXI write accepted")
    }.otherwise{
      printf("AXI write not accepted")
    }
    AXI_AW.fire
  }

  /**
  @return: The data found in the one entry response Q + if the "fire" of that queue
  */
  def AXI_read:(UInt, Bool) = {
    final_response_buffer.io.deq.ready := 1.B
    (final_response_buffer.io.deq.bits, final_response_buffer.io.deq.fire)
  }

  /////////////
  // AXI FSM //
  /////////////

  object AXI_REQUEST_STATES extends ChiselEnum {
    val ADDRESS_PHASE, READ_DATA_PHASE, WRITE_DATA_PHASE, READ_RESPONSE_PHASE, WRITE_RESPONSE_PHASE = Value
  }

  val AXI_REQUEST_STATE       = RegInit(AXI_REQUEST_STATES(), AXI_REQUEST_STATES.ADDRESS_PHASE)
  val AXI_REQUEST_NEXT_STATE  = Wire(AXI_REQUEST_STATES())

  AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.ADDRESS_PHASE

  switch(AXI_REQUEST_STATE){
    is(AXI_REQUEST_STATES.ADDRESS_PHASE){
      // ASSIGN AXI OUTPUT

      // FSM
      AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.ADDRESS_PHASE
      when(AXI_AW.fire){                   // AW accepted
        AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.WRITE_DATA_PHASE
      }.elsewhen(AXI_AR.fire){             // AR accepted
        AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.READ_DATA_PHASE
      }
    }

    is(AXI_REQUEST_STATES.WRITE_DATA_PHASE){
      when(AXI_W.bits.m_axi_wlast.asBool){
        AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.WRITE_RESPONSE_PHASE
      }
    }

    is(AXI_REQUEST_STATES.WRITE_RESPONSE_PHASE){
      when(AXI_B.fire){
        AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.ADDRESS_PHASE
      }
    }

    is(AXI_REQUEST_STATES.READ_RESPONSE_PHASE){
      when(AXI_R.bits.m_axi_rlast.asBool){ // FIXME:  last and okay and ... 
        AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.READ_RESPONSE_PHASE
      }
    }

  }

  AXI_REQUEST_STATE := AXI_REQUEST_NEXT_STATE

  ///////////////
  // DATA PATH //
  ///////////////

  // SHARED ADDRESS PHASE
  when(AXI_REQUEST_STATE === AXI_REQUEST_STATES.ADDRESS_PHASE){ // drive output request
    AXI_AW.valid := 1.B
    AXI_AR.valid := 1.B
  }

  // WRITE DATA PHASE
  when(AXI_REQUEST_STATE === AXI_REQUEST_STATES.WRITE_DATA_PHASE){ 

    AXI_W.valid            := 1.B
    AXI_W.bits.m_axi_wdata :=  AXI_AW_DATA_BUFFER(31, 0)
    AXI_W.bits.m_axi_wstrb := 0x1.U
    AXI_W.bits.m_axi_wlast := 1.U

    when(AXI_W.fire){
      AXI_AW_DATA_BUFFER := AXI_AW_DATA_BUFFER >> 32.U
    }
  }

  // WRITE RESPONSE PHASE
  when(AXI_REQUEST_STATE === AXI_REQUEST_STATES.WRITE_RESPONSE_PHASE){
    AXI_B.ready := 1.B
  }

  // READ RESPONSE PHASE
  val AXI_read_buffer = Reg(UInt(256.W))
  when(AXI_REQUEST_STATE === AXI_REQUEST_STATES.READ_RESPONSE_PHASE){
    AXI_R.ready := 1.B
    when(AXI_R.fire && AXI_R.bits.m_axi_rlast.asBool){
      final_response_buffer.io.enq.bits := (AXI_read_buffer << 32.U) | AXI_R.bits.m_axi_rdata
      final_response_buffer.io.enq.valid := 1.B
    }.elsewhen(AXI_R.fire){
      AXI_read_buffer := (AXI_read_buffer << 32.U) | AXI_R.bits.m_axi_rdata
    }
  }





}