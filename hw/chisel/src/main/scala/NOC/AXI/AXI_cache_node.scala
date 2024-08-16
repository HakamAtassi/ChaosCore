package ChaosCore

import chisel3._
import chisel3.util._

import chisel3.experimental.dataview._


/**
AXI FULL NODE is for use in the transport of cache lines across the system interconnect. 
On write request, the AXI node will assert AXI AW (address and metadata). It will also assert the first unit of data.
The AXI node may then either accept the first unit of data AND the AW data, or may way some period of time for the W data to be accepted. 
The AXI node will then transport 1 beat at a time in an INCR only burst type. 
*/

trait AXICacheNode {

  val nocParameters:NOCParameters

  import nocParameters._

  // FIXME: use the AXI master bundle

  // actual verilog IO
  val m_axi = IO(new VerilogAXIFullIO(nocParameters))


  val AXI_port = m_axi.viewAs[AXIFullIO]

  // chisel dataview mapping

  object AXI_REQUEST_STATES extends ChiselEnum {
    val ADDRESS_PHASE, WRITE_DATA_PHASE, READ_RESPONSE_PHASE, WRITE_RESPONSE_PHASE = Value
  }

  ///////////////////////
  // DEASSERT REQUESTS //
  ///////////////////////

  // Response channels
  AXI_port.AXI_B.ready   := 0.B
  AXI_port.AXI_R.ready   := 0.B

  // axi defaults
  AXI_port.AXI_AW.bits   := 0.U.asTypeOf(new AXI_AW(nocParameters))
  AXI_port.AXI_AW.valid  := 0.B

  AXI_port.AXI_W.bits    := 0.U.asTypeOf(new AXI_W(nocParameters))
  AXI_port.AXI_W.valid   := 0.B

  AXI_port.AXI_AR.bits   := 0.U.asTypeOf(new AXI_AR(nocParameters))
  AXI_port.AXI_AR.valid  := 0.B

  class final_AXI_response extends Bundle{
    val data = UInt(256.W)
    val ID   = UInt(ID_WIDTH.W)
  }

  // Reconstructed response buffer
  val final_response_buffer = Module(new Queue(new final_AXI_response, 1, flow=true, hasFlush=false, useSyncReadMem=false))
  final_response_buffer.io.deq.ready := 0.B
  final_response_buffer.io.enq.valid := 0.B
  final_response_buffer.io.enq.bits := DontCare

  //////////
  // APIs //
  //////////

  def AXI_read_request(address:UInt, ID:UInt, bytes:UInt):Bool = {
    import nocParameters._
    // drive channels
    AXI_port.AXI_AR.valid        := AXI_REQUEST_STATE === AXI_REQUEST_STATES.ADDRESS_PHASE
    AXI_port.AXI_AR.bits.arid    := ID
    AXI_port.AXI_AR.bits.araddr  := address
    AXI_port.AXI_AR.bits.arlen   := Mux(bytes < DATA_WIDTH_BYTES.U, 0.U, bytes/DATA_WIDTH_BYTES.U - 1.U)
    AXI_port.AXI_AR.bits.arsize  := log2Ceil(DATA_WIDTH/8).U // FIXME: hardcoded..
    AXI_port.AXI_AR.bits.arburst := 0x1.U
    AXI_port.AXI_AR.bits.arlock  := 0x0.U
    AXI_port.AXI_AR.bits.arcache := 0x0.U
    AXI_port.AXI_AR.bits.arprot  := 0x0.U

    AXI_port.AXI_AR.fire
  }
  
  val AXI_AW_DATA_BUFFER = Reg(UInt(256.W))   // FIXME: make this a param based on cache line width
  def AXI_write_request(address:UInt, ID:UInt, data:UInt, bytes:UInt):Bool = {
    import nocParameters._
    // awlen = transfer size / bus width 
    // awsize = always 0x2.U (32 bits) for simplicity


    AXI_port.AXI_AW.valid          := (AXI_REQUEST_STATE === AXI_REQUEST_STATES.ADDRESS_PHASE)
    AXI_port.AXI_AW.bits.awid      := ID
    AXI_port.AXI_AW.bits.awaddr    := address
    AXI_port.AXI_AW.bits.awlen     := Mux(bytes < DATA_WIDTH_BYTES.U, 0.U, bytes/DATA_WIDTH_BYTES.U - 1.U)
    AXI_port.AXI_AW.bits.awsize    := log2Ceil(DATA_WIDTH/8).U  // FIXME: hardcoded..
    AXI_port.AXI_AW.bits.awburst   := 0x1.U
    AXI_port.AXI_AW.bits.awlock    := 0.U
    AXI_port.AXI_AW.bits.awcache   := 0.U
    AXI_port.AXI_AW.bits.awprot    := 0.U

    when(AXI_port.AXI_AW.fire){
      AXI_AW_DATA_BUFFER := data
    }    
    AXI_port.AXI_AW.fire
  }

  /**
  @return: The data found in the one entry response Q + if the "fire" of that queue
  */
  def AXI_read:(final_AXI_response, Bool) = {
    final_response_buffer.io.deq.ready := 1.B
    (final_response_buffer.io.deq.bits, final_response_buffer.io.deq.fire)
  }

  /////////////
  // AXI FSM //
  /////////////


  val AXI_REQUEST_STATE       = RegInit(AXI_REQUEST_STATES(), AXI_REQUEST_STATES.ADDRESS_PHASE)
  val AXI_REQUEST_NEXT_STATE  = Wire(AXI_REQUEST_STATES())

  AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATE

  switch(AXI_REQUEST_STATE){
    is(AXI_REQUEST_STATES.ADDRESS_PHASE){
      // ASSIGN AXI OUTPUT

      // FSM
      AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.ADDRESS_PHASE
      when(AXI_port.AXI_AW.fire){                   // AW accepted
        AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.WRITE_DATA_PHASE
      }.elsewhen(AXI_port.AXI_AR.fire){             // AR accepted
        AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.READ_RESPONSE_PHASE
      }
    }

    is(AXI_REQUEST_STATES.WRITE_DATA_PHASE){
      when(AXI_port.AXI_W.bits.wlast.asBool && AXI_port.AXI_W.fire){
        AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.WRITE_RESPONSE_PHASE
      }
    }

    is(AXI_REQUEST_STATES.WRITE_RESPONSE_PHASE){
      when(AXI_port.AXI_B.fire){
        AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.ADDRESS_PHASE
      }
    }

    is(AXI_REQUEST_STATES.READ_RESPONSE_PHASE){
      when(AXI_port.AXI_R.bits.rlast.asBool && AXI_port.AXI_R.fire){ // FIXME:  last and okay and ... 
        AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.ADDRESS_PHASE
      }
    }
  }

  AXI_REQUEST_STATE := AXI_REQUEST_NEXT_STATE

  ///////////////
  // DATA PATH //
  ///////////////

  val write_counter = RegInit(UInt(32.W), 0.U)
  val read_counter  = RegInit(UInt(32.W), 0.U)

  // SHARED ADDRESS PHASE
  when(AXI_REQUEST_STATE === AXI_REQUEST_STATES.ADDRESS_PHASE){ // drive output request
    when(AXI_port.AXI_AW.fire){
      write_counter := AXI_port.AXI_AW.bits.awlen
    }.elsewhen(AXI_port.AXI_AR.fire){
      read_counter := AXI_port.AXI_AR.bits.arlen
    }
  }

  dontTouch(AXI_REQUEST_STATE)

  // WRITE DATA PHASE
  when(AXI_REQUEST_STATE === AXI_REQUEST_STATES.WRITE_DATA_PHASE){ 

    AXI_port.AXI_W.valid            := 1.B
    AXI_port.AXI_W.bits.wdata := AXI_AW_DATA_BUFFER(DATA_WIDTH-1, 0)
    AXI_port.AXI_W.bits.wstrb := 0xF.U
    AXI_port.AXI_W.bits.wlast := (write_counter === 0.U)

    when(AXI_port.AXI_W.fire){
      write_counter := write_counter - 1.U
      AXI_AW_DATA_BUFFER := AXI_AW_DATA_BUFFER >> 32.U
    }
  }

  // WRITE RESPONSE PHASE
  when(AXI_REQUEST_STATE === AXI_REQUEST_STATES.WRITE_RESPONSE_PHASE){
    AXI_port.AXI_B.ready := 1.B
  }

  // READ RESPONSE PHASE
  val AXI_read_buffer = Reg(UInt(256.W))
  when(AXI_REQUEST_STATE === AXI_REQUEST_STATES.READ_RESPONSE_PHASE){
    AXI_port.AXI_R.ready := 1.B
    when(AXI_port.AXI_R.fire && AXI_port.AXI_R.bits.rlast.asBool){
      final_response_buffer.io.enq.bits.data := (AXI_read_buffer >> 32.U) | (AXI_port.AXI_R.bits.rdata << (256.U - 32.U))
      final_response_buffer.io.enq.bits.ID := AXI_port.AXI_R.bits.rid
      final_response_buffer.io.enq.valid := 1.B
    }.elsewhen(AXI_port.AXI_R.fire){
      AXI_read_buffer := (AXI_read_buffer >> 32.U) | (AXI_port.AXI_R.bits.rdata << (256.U - 32.U))
    }
  }


  AXI_port.AXI_AW.valid := 0.B
  AXI_port.AXI_AR.valid := 0.B
  //printf("%d %d\n", AXI_AW.valid, AXI_AW.bits.m_axi_awaddr)

}