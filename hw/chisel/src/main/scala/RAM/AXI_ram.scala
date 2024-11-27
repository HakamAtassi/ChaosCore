package	ChaosCore

import	chisel3._
import	chisel3.experimental._
import	chisel3.util._

//	Define	the	BlackBox	module

class axi_ram(nocParameters:NOCParameters) extends BlackBox(Map(

	"DATA_WIDTH"						->	32, //nocParameters.DATA_WIDTH,
	"ADDR_WIDTH"						->	16, //nocParameters.ADDR_WIDTH,
	"STRB_WIDTH"						->	4, //nocParameters.STRB_WIDTH,
	"ID_WIDTH"							->	8, //nocParameters.ID_WIDTH,
	"PIPELINE_OUTPUT"					->	0, //nocParameters.PIPELINE_OUTPUT,

))	with	HasBlackBoxResource{

	val	io	=	IO(new	Bundle	{
		import	nocParameters._
		val	clk	=	Input(Clock())
		val	rst	=	Input(Bool())

        val s_axi_awid     = Input(UInt(ID_WIDTH.W))
        val s_axi_awaddr   = Input(UInt(ADDR_WIDTH.W))
        val s_axi_awlen    = Input(UInt(8.W))
        val s_axi_awsize   = Input(UInt(3.W))
        val s_axi_awburst  = Input(UInt(2.W))
        val s_axi_awlock   = Input(Bool())
        val s_axi_awcache  = Input(UInt(4.W))
        val s_axi_awprot   = Input(UInt(3.W))
        val s_axi_awvalid  = Input(Bool())
        val s_axi_awready  = Output(Bool())
        val s_axi_wdata    = Input(UInt(DATA_WIDTH.W))
        val s_axi_wstrb    = Input(UInt(STRB_WIDTH.W))
        val s_axi_wlast    = Input(Bool())
        val s_axi_wvalid   = Input(Bool())
        val s_axi_wready   = Output(Bool())
        val s_axi_bid      = Output(UInt(ID_WIDTH.W))
        val s_axi_bresp    = Output(UInt(2.W))
        val s_axi_bvalid   = Output(Bool())
        val s_axi_bready   = Input(Bool())
        val s_axi_arid     = Input(UInt(ID_WIDTH.W))
        val s_axi_araddr   = Input(UInt(ADDR_WIDTH.W))
        val s_axi_arlen    = Input(UInt(8.W))
        val s_axi_arsize   = Input(UInt(3.W))
        val s_axi_arburst  = Input(UInt(2.W))
        val s_axi_arlock   = Input(Bool())
        val s_axi_arcache  = Input(UInt(4.W))
        val s_axi_arprot   = Input(UInt(3.W))
        val s_axi_arvalid  = Input(Bool())
        val s_axi_arready  = Output(Bool())
        val s_axi_rid      = Output(UInt(ID_WIDTH.W))
        val s_axi_rdata    = Output(UInt(DATA_WIDTH.W))
        val s_axi_rresp    = Output(UInt(2.W))
        val s_axi_rlast    = Output(Bool())
        val s_axi_rvalid   = Output(Bool())
        val s_axi_rready   = Input(Bool())
	})
	//	ALEX	FORENCICH	AXI	INTERCONNECT
	addResource("/verilog-axi/rtl/axi_ram.v")
}

class axi_ram_wrap(nocParameters:NOCParameters) extends Module{

    val io = IO(new Bundle{
        val s_AXI = Flipped(new AXIFullIO(nocParameters))
    })

	val	ram	=	Module(new axi_ram(nocParameters))

	clock	<>	ram.io.clk
	reset	<>	ram.io.rst

    ram.io.s_axi_awid     <> io.s_AXI.AXI_AW.bits.awid
    ram.io.s_axi_awaddr   <> io.s_AXI.AXI_AW.bits.awaddr
    ram.io.s_axi_awlen    <> io.s_AXI.AXI_AW.bits.awlen
    ram.io.s_axi_awsize   <> io.s_AXI.AXI_AW.bits.awsize
    ram.io.s_axi_awburst  <> io.s_AXI.AXI_AW.bits.awburst
    ram.io.s_axi_awlock   <> io.s_AXI.AXI_AW.bits.awlock
    ram.io.s_axi_awcache  <> io.s_AXI.AXI_AW.bits.awcache
    ram.io.s_axi_awprot   <> io.s_AXI.AXI_AW.bits.awprot
    ram.io.s_axi_awvalid  <> io.s_AXI.AXI_AW.valid
    ram.io.s_axi_awready  <> io.s_AXI.AXI_AW.ready

    ram.io.s_axi_wdata    <> io.s_AXI.AXI_W.bits.wdata
    ram.io.s_axi_wstrb    <> io.s_AXI.AXI_W.bits.wstrb
    ram.io.s_axi_wlast    <> io.s_AXI.AXI_W.bits.wlast
    ram.io.s_axi_wvalid   <> io.s_AXI.AXI_W.valid
    ram.io.s_axi_wready   <> io.s_AXI.AXI_W.ready

    ram.io.s_axi_bid      <> io.s_AXI.AXI_B.bits.bid
    ram.io.s_axi_bresp    <> io.s_AXI.AXI_B.bits.bresp
    ram.io.s_axi_bvalid   <> io.s_AXI.AXI_B.valid
    ram.io.s_axi_bready   <> io.s_AXI.AXI_B.ready

    ram.io.s_axi_arid     <> io.s_AXI.AXI_AR.bits.arid
    ram.io.s_axi_araddr   <> io.s_AXI.AXI_AR.bits.araddr
    ram.io.s_axi_arlen    <> io.s_AXI.AXI_AR.bits.arlen
    ram.io.s_axi_arsize   <> io.s_AXI.AXI_AR.bits.arsize
    ram.io.s_axi_arburst  <> io.s_AXI.AXI_AR.bits.arburst
    ram.io.s_axi_arlock   <> io.s_AXI.AXI_AR.bits.arlock
    ram.io.s_axi_arcache  <> io.s_AXI.AXI_AR.bits.arcache
    ram.io.s_axi_arprot   <> io.s_AXI.AXI_AR.bits.arprot
    ram.io.s_axi_arvalid  <> io.s_AXI.AXI_AR.valid
    ram.io.s_axi_arready  <> io.s_AXI.AXI_AR.ready

    ram.io.s_axi_rid      <> io.s_AXI.AXI_R.bits.rid
    ram.io.s_axi_rdata    <> io.s_AXI.AXI_R.bits.rdata
    ram.io.s_axi_rresp    <> io.s_AXI.AXI_R.bits.rresp
    ram.io.s_axi_rlast    <> io.s_AXI.AXI_R.bits.rlast
    ram.io.s_axi_rvalid   <> io.s_AXI.AXI_R.valid
    ram.io.s_axi_rready   <> io.s_AXI.AXI_R.ready

    io.s_AXI.AXI_R.bits.ruser   := DontCare
    io.s_AXI.AXI_B.bits.buser := DontCare
}