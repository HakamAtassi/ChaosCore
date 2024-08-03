package ChaosCore

import chisel3._
import chisel3.experimental._

import circt.stage.ChiselStage 

import chisel3.util._




class AXI_master_slave(coreParameters:CoreParameters, val nocParameters:NOCParameters) extends Module {

    val AXI_master  = Module(new AXI_master(coreParameters, nocParameters))
    val axi_ram     = Module(new axi_ram(nocParameters))



    axi_ram.io.clk := clock
    axi_ram.io.rst := reset


    axi_ram.io.s_axi_awid     := AXI_master.AXI_AW.bits.m_axi_awid
    axi_ram.io.s_axi_awaddr   := AXI_master.AXI_AW.bits.m_axi_awaddr
    axi_ram.io.s_axi_awlen    := AXI_master.AXI_AW.bits.m_axi_awlen
    axi_ram.io.s_axi_awsize   := AXI_master.AXI_AW.bits.m_axi_awsize
    axi_ram.io.s_axi_awburst  := AXI_master.AXI_AW.bits.m_axi_awburst
    axi_ram.io.s_axi_awlock   := AXI_master.AXI_AW.bits.m_axi_awlock
    axi_ram.io.s_axi_awcache  := AXI_master.AXI_AW.bits.m_axi_awcache
    axi_ram.io.s_axi_awprot   := AXI_master.AXI_AW.bits.m_axi_awprot
    axi_ram.io.s_axi_awvalid  <> AXI_master.AXI_AW.valid
    axi_ram.io.s_axi_awready  <> AXI_master.AXI_AW.ready

    axi_ram.io.s_axi_wdata    := AXI_master.AXI_W.bits.m_axi_wdata
    axi_ram.io.s_axi_wstrb    := AXI_master.AXI_W.bits.m_axi_wstrb
    axi_ram.io.s_axi_wlast    := AXI_master.AXI_W.bits.m_axi_wlast
    axi_ram.io.s_axi_wvalid   <> AXI_master.AXI_W.valid
    axi_ram.io.s_axi_wready   <> AXI_master.AXI_W.ready

   
    AXI_master.AXI_B.bits.m_axi_bid     := axi_ram.io.s_axi_bid
    AXI_master.AXI_B.bits.m_axi_bresp   := axi_ram.io.s_axi_bresp
    AXI_master.AXI_B.valid              := axi_ram.io.s_axi_bvalid
    axi_ram.io.s_axi_bready             <> AXI_master.AXI_B.ready

    axi_ram.io.s_axi_arid     <> AXI_master.AXI_AR.bits.m_axi_arid
    axi_ram.io.s_axi_araddr   := AXI_master.AXI_AR.bits.m_axi_araddr
    axi_ram.io.s_axi_arlen    := AXI_master.AXI_AR.bits.m_axi_arlen
    axi_ram.io.s_axi_arsize   := AXI_master.AXI_AR.bits.m_axi_arsize
    axi_ram.io.s_axi_arburst  := AXI_master.AXI_AR.bits.m_axi_arburst
    axi_ram.io.s_axi_arlock   := AXI_master.AXI_AR.bits.m_axi_arlock
    axi_ram.io.s_axi_arcache  := AXI_master.AXI_AR.bits.m_axi_arcache
    axi_ram.io.s_axi_arprot   := AXI_master.AXI_AR.bits.m_axi_arprot
    axi_ram.io.s_axi_arvalid  <> AXI_master.AXI_AR.valid
    axi_ram.io.s_axi_arready  <> AXI_master.AXI_AR.ready

    AXI_master.AXI_R.bits.m_axi_rid     := axi_ram.io.s_axi_rid
    AXI_master.AXI_R.bits.m_axi_rdata   :=  axi_ram.io.s_axi_rdata
    AXI_master.AXI_R.bits.m_axi_rresp   :=  axi_ram.io.s_axi_rresp
    AXI_master.AXI_R.bits.m_axi_rlast   := axi_ram.io.s_axi_rlast
    AXI_master.AXI_R.valid              := axi_ram.io.s_axi_rvalid
    axi_ram.io.s_axi_rready   <> AXI_master.AXI_R.ready

}