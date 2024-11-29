package ChaosCore

import chisel3._
import chisel3.util._

import chisel3.experimental.dataview._
//import chisel3.experimental.ChiselEnum

import	chisel3.experimental._





/**
AXI FULL NODE is for use in the transport of cache lines across the system interconnect. 
On write request, the AXI node will assert AXI AW (address and metadata). It will also assert the first unit of data.
The AXI node may then either accept the first unit of data AND the AW data, or may way some period of time for the W data to be accepted. 
The AXI node will then transport 1 beat at a time in an INCR only burst type. 
*/

trait AXICacheNode {
  val nocParameters:NOCParameters
  val coreParameters:CoreParameters

  import nocParameters._
  import coreParameters._

  // actual verilog IO
  // chisel dataview mapping
  val m_axi = IO(new VerilogAXIFullIO(nocParameters))
  val AXI_port = m_axi.viewAs[AXIFullIO]
  dontTouch(m_axi)

  object AXI_REQUEST_STATES extends ChiselEnum {
    val ACTIVE, AW_R_PHASE, R_W_PHASE, R_PHASE, W_PHASE, AR_W_PHASE, B_PHASE = Value
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

  val AXI_AR_buf = Reg(new AXI_AR(nocParameters))
  val AXI_AW_buf = Reg(new AXI_AW(nocParameters))

  AXI_AR_buf := 0.U.asTypeOf(new AXI_AR(nocParameters))
  AXI_AW_buf := 0.U.asTypeOf(new AXI_AW(nocParameters))



  def AXI_read_request(address:UInt, ID:UInt, bytes:UInt): Bool = {
    import nocParameters._
    // drive channels
    //AXI_port.AXI_AR.valid        := AXI_REQUEST_STATE === AXI_REQUEST_STATES.ADDRESS_PHASE
    AXI_AR_buf.arid    := ID
    AXI_AR_buf.araddr  := address
    AXI_AR_buf.arlen   := Mux(bytes < DATA_WIDTH_BYTES.U, 0.U, bytes/DATA_WIDTH_BYTES.U - 1.U)
    AXI_AR_buf.arsize  := log2Ceil(DATA_WIDTH/8).U
    AXI_AR_buf.arburst := 0x1.U
    AXI_AR_buf.arlock  := 0x0.U
    AXI_AR_buf.arcache := 0x0.U
    AXI_AR_buf.arprot  := 0x0.U

    AXI_port.AXI_AR.valid        := AXI_REQUEST_STATE === AXI_REQUEST_STATES.ACTIVE
    AXI_port.AXI_AR.bits.arid    := ID
    AXI_port.AXI_AR.bits.araddr  := address
    AXI_port.AXI_AR.bits.arlen   := Mux(bytes < DATA_WIDTH_BYTES.U, 0.U, bytes/DATA_WIDTH_BYTES.U - 1.U)
    AXI_port.AXI_AR.bits.arsize  := log2Ceil(DATA_WIDTH/8).U
    AXI_port.AXI_AR.bits.arburst := 0x1.U
    AXI_port.AXI_AR.bits.arlock  := 0x0.U
    AXI_port.AXI_AR.bits.arcache := 0x0.U
    AXI_port.AXI_AR.bits.arprot  := 0x0.U

    AXI_port.AXI_AR.fire

  }
  
  val AXI_AW_DATA_BUFFER = Reg(UInt((L1_cacheLineSizeBytes*8).W))
  def AXI_write_request(address:UInt, ID:UInt, data:UInt, bytes:UInt): Bool = {
    import nocParameters._
    // awlen = transfer size / bus width 
    // awsize = always 0x2.U (32 bits) for simplicity

    AXI_AW_buf.awid      := ID
    AXI_AW_buf.awaddr    := address
    AXI_AW_buf.awlen     := Mux(bytes < DATA_WIDTH_BYTES.U, 0.U, bytes/DATA_WIDTH_BYTES.U - 1.U)
    AXI_AW_buf.awsize    := log2Ceil(DATA_WIDTH/8).U
    AXI_AW_buf.awburst   := 0x1.U
    AXI_AW_buf.awlock    := 0.U
    AXI_AW_buf.awcache   := 0.U
    AXI_AW_buf.awprot    := 0.U

    AXI_port.AXI_AW.valid          := (AXI_REQUEST_STATE === AXI_REQUEST_STATES.ACTIVE)
    AXI_port.AXI_AW.bits.awid      := ID
    AXI_port.AXI_AW.bits.awaddr    := address
    AXI_port.AXI_AW.bits.awlen     := Mux(bytes < DATA_WIDTH_BYTES.U, 0.U, bytes/DATA_WIDTH_BYTES.U - 1.U)
    AXI_port.AXI_AW.bits.awsize    := log2Ceil(DATA_WIDTH/8).U
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

  val AXI_REQUEST_STATE       = RegInit(AXI_REQUEST_STATES(), AXI_REQUEST_STATES.ACTIVE)
  val AXI_REQUEST_NEXT_STATE  = Wire(AXI_REQUEST_STATES())

  val R_done = RegInit(Bool(), 0.B)
  val W_done = RegInit(Bool(), 0.B)


  AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATE

  switch(AXI_REQUEST_STATE){
    is(AXI_REQUEST_STATES.ACTIVE){
      when((AXI_port.AXI_AR.fire && AXI_port.AXI_AW.fire) ){
        // Both AR and AW valid
        AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.R_W_PHASE
      }.elsewhen(AXI_port.AXI_AR.fire && !AXI_port.AXI_AW.valid){
        AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.R_PHASE
      }.elsewhen(AXI_port.AXI_AR.fire){
        // Only AR accepted
        AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.AW_R_PHASE
      }.elsewhen(AXI_port.AXI_AW.fire && !AXI_port.AXI_AR.valid){
        AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.W_PHASE
      }.elsewhen(AXI_port.AXI_AW.fire){
        // Only AW accepted
        AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.AR_W_PHASE
      }.otherwise{
        AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.ACTIVE
      }
    }

    is(AXI_REQUEST_STATES.R_W_PHASE){
      AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.R_W_PHASE
      when(R_done && W_done){
        AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.B_PHASE
      }
    }
    is(AXI_REQUEST_STATES.R_PHASE){
      AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.R_PHASE
      when(R_done){
        AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.ACTIVE
      }
    }
    is(AXI_REQUEST_STATES.W_PHASE){
      AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.W_PHASE
      when(W_done){
        AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.B_PHASE
      }
    }



    is(AXI_REQUEST_STATES.AR_W_PHASE){
      AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.AR_W_PHASE
      when(AXI_port.AXI_AR.fire){ // AR accepted
        AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.R_W_PHASE
      }
    }

    is(AXI_REQUEST_STATES.AW_R_PHASE){
      AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.AW_R_PHASE
      when(AXI_port.AXI_AW.fire){ // AW accepted
        AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.R_W_PHASE
      }
    }

    is(AXI_REQUEST_STATES.B_PHASE){
      AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.B_PHASE
      when(AXI_port.AXI_B.fire){ // Ack write complete
        AXI_REQUEST_NEXT_STATE := AXI_REQUEST_STATES.ACTIVE
      }
    }

  }

  AXI_REQUEST_STATE := AXI_REQUEST_NEXT_STATE

  ///////////////
  // DATA PATH //
  ///////////////


  val write_counter = RegInit(UInt(32.W), 0.U)
  val read_counter  = RegInit(UInt(32.W), 0.U)

  val AXI_read_buffer = Reg(UInt(256.W))
  when(AXI_REQUEST_STATE === AXI_REQUEST_STATES.ACTIVE){ // Write address channels. Reset control regs
    R_done := (!AXI_port.AXI_AR.valid)  // These might need to be more robust. how to init done?
    W_done := (!AXI_port.AXI_AW.valid)
    when(AXI_port.AXI_AW.fire){
      write_counter := AXI_port.AXI_AW.bits.awlen
    }
    when(AXI_port.AXI_AR.fire){
      read_counter := AXI_port.AXI_AR.bits.arlen
    }
  }

  when(AXI_REQUEST_STATE === AXI_REQUEST_STATES.AR_W_PHASE){  // Drive AR and W data
    // AXI AR
    AXI_port.AXI_AR.valid        := 1.B
    AXI_port.AXI_AR.bits.arid    := AXI_AR_buf.arid
    AXI_port.AXI_AR.bits.araddr  := AXI_AR_buf.araddr
    AXI_port.AXI_AR.bits.arlen   := AXI_AR_buf.arlen
    AXI_port.AXI_AR.bits.arsize  := AXI_AR_buf.arsize 
    AXI_port.AXI_AR.bits.arburst := 0x1.U
    AXI_port.AXI_AR.bits.arlock  := 0x0.U
    AXI_port.AXI_AR.bits.arcache := 0x0.U
    AXI_port.AXI_AR.bits.arprot  := 0x0.U

    // AXI W
    when(!W_done){
      W_done                    := AXI_port.AXI_W.bits.wlast
      AXI_port.AXI_W.bits.wlast := (write_counter === 0.U)
      AXI_port.AXI_W.valid      := 1.B
      AXI_port.AXI_W.bits.wdata := AXI_AW_DATA_BUFFER(DATA_WIDTH-1, 0)
      AXI_port.AXI_W.bits.wstrb := 0xF.U
    }
    when(!W_done && AXI_port.AXI_W.fire){
      write_counter := write_counter - 1.U
      AXI_AW_DATA_BUFFER := AXI_AW_DATA_BUFFER >> 32.U
    }

  }

  final_response_buffer.io.enq.valid := 0.B
  when(AXI_REQUEST_STATE === AXI_REQUEST_STATES.AW_R_PHASE){
    // AXI R
    AXI_port.AXI_R.ready := 1.B
    when(AXI_port.AXI_R.fire && AXI_port.AXI_R.bits.rlast.asBool){
      AXI_read_buffer := 0.U
      final_response_buffer.io.enq.bits.data := (AXI_read_buffer >> 32.U) | (AXI_port.AXI_R.bits.rdata << (256.U - 32.U))
      final_response_buffer.io.enq.bits.ID   := AXI_port.AXI_R.bits.rid
      final_response_buffer.io.enq.valid     := 1.B
    }.elsewhen(AXI_port.AXI_R.fire){
      AXI_read_buffer := (AXI_read_buffer >> 32.U) | (AXI_port.AXI_R.bits.rdata << (256.U - 32.U))
    }

    // AXI AW
    AXI_port.AXI_AW.valid          := 1.B
    AXI_port.AXI_AW.bits.awid      := AXI_AW_buf.awid
    AXI_port.AXI_AW.bits.awaddr    := AXI_AW_buf.awaddr
    AXI_port.AXI_AW.bits.awlen     := AXI_AW_buf.awlen
    AXI_port.AXI_AW.bits.awsize    := AXI_AW_buf.awsize
    AXI_port.AXI_AW.bits.awburst   := 0x1.U
    AXI_port.AXI_AW.bits.awlock    := 0.U
    AXI_port.AXI_AW.bits.awcache   := 0.U
    AXI_port.AXI_AW.bits.awprot    := 0.U

  }




  when(AXI_REQUEST_STATE === AXI_REQUEST_STATES.R_W_PHASE){ 

    // AXI R
    AXI_port.AXI_R.ready := 1.B
    when(!R_done && AXI_port.AXI_R.fire){
      AXI_read_buffer := (AXI_read_buffer >> 32.U) | (AXI_port.AXI_R.bits.rdata << (256.U - 32.U))
      R_done := AXI_port.AXI_R.bits.rlast
    }

    // AXI W
    when(!W_done){
      W_done := AXI_port.AXI_W.bits.wlast
      AXI_port.AXI_W.bits.wlast := (write_counter === 0.U)
      AXI_port.AXI_W.valid      := 1.B
      AXI_port.AXI_W.bits.wdata := AXI_AW_DATA_BUFFER(DATA_WIDTH-1, 0)
      AXI_port.AXI_W.bits.wstrb := 0xF.U
    }
    when(!W_done && AXI_port.AXI_W.fire){
      write_counter := write_counter - 1.U
      AXI_AW_DATA_BUFFER := AXI_AW_DATA_BUFFER >> 32.U
    }

    when(W_done && R_done){
      AXI_read_buffer := 0.U
      final_response_buffer.io.enq.bits.data := AXI_read_buffer
      final_response_buffer.io.enq.bits.ID := AXI_port.AXI_R.bits.rid
      final_response_buffer.io.enq.valid := 1.B
    }

  }

  when(AXI_REQUEST_STATE === AXI_REQUEST_STATES.R_PHASE){ 

    // AXI R
    when(!R_done && AXI_port.AXI_R.fire){
      AXI_read_buffer := (AXI_read_buffer >> 32.U) | (AXI_port.AXI_R.bits.rdata << (256.U - 32.U))
      R_done := AXI_port.AXI_R.bits.rlast
    }

    // AXI R
    AXI_port.AXI_R.ready := 1.B
    when(AXI_port.AXI_R.fire && AXI_port.AXI_R.bits.rlast.asBool){
      AXI_read_buffer := 0.U
      final_response_buffer.io.enq.bits.data := (AXI_read_buffer >> 32.U) | (AXI_port.AXI_R.bits.rdata << (256.U - 32.U))
      final_response_buffer.io.enq.bits.ID := AXI_port.AXI_R.bits.rid
      final_response_buffer.io.enq.valid := 1.B
    }
  }

  when(AXI_REQUEST_STATE === AXI_REQUEST_STATES.W_PHASE){ 
    // AXI W
    when(!W_done){
      W_done := AXI_port.AXI_W.bits.wlast
      AXI_port.AXI_W.bits.wlast := (write_counter === 0.U)
      AXI_port.AXI_W.valid      := 1.B
      AXI_port.AXI_W.bits.wdata := AXI_AW_DATA_BUFFER(DATA_WIDTH-1, 0)
      AXI_port.AXI_W.bits.wstrb := 0xF.U
    }
    when(!W_done && AXI_port.AXI_W.fire){
      write_counter := write_counter - 1.U
      AXI_AW_DATA_BUFFER := AXI_AW_DATA_BUFFER >> 32.U
    }
  }




  when(AXI_REQUEST_STATE === AXI_REQUEST_STATES.B_PHASE){
    AXI_port.AXI_B.ready := 1.B
  }

  dontTouch(AXI_REQUEST_STATE)
  dontTouch(final_response_buffer.io)

  AXI_port.AXI_AW.valid := 0.B
  AXI_port.AXI_AR.valid := 0.B

}