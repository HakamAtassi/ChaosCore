package	ChaosCore

import	chisel3._
import	chisel3.experimental._
import	circt.stage.ChiselStage	
import	chisel3.util._


//	Define	the	BlackBox	module
class axi_interconnect(nocParameters:NOCParameters)	extends	BlackBox(Map(
	"S_COUNT" -> nocParameters.S_COUNT,
	"M_COUNT" -> nocParameters.M_COUNT,

	"DATA_WIDTH"			->	nocParameters.DATA_WIDTH,
	"ADDR_WIDTH"			->	nocParameters.ADDR_WIDTH,
	"STRB_WIDTH"			->	nocParameters.STRB_WIDTH,
	"ID_WIDTH"				->	nocParameters.ID_WIDTH,
	"AWUSER_ENABLE"			->	nocParameters.AWUSER_ENABLE,
	"AWUSER_WIDTH"			->	nocParameters.AWUSER_WIDTH,
	"WUSER_ENABLE"			->	nocParameters.WUSER_ENABLE,
	"WUSER_WIDTH"			->	nocParameters.WUSER_WIDTH,
	"BUSER_ENABLE"			->	nocParameters.BUSER_ENABLE,
	"BUSER_WIDTH"			->	nocParameters.BUSER_WIDTH,
	"ARUSER_ENABLE"			->	nocParameters.ARUSER_ENABLE,
	"ARUSER_WIDTH"			->	nocParameters.ARUSER_WIDTH,
	"RUSER_ENABLE"			->	nocParameters.RUSER_ENABLE,
	"RUSER_WIDTH"			->	nocParameters.RUSER_WIDTH,
	"FORWARD_ID"			->	nocParameters.FORWARD_ID,
	"M_REGIONS"				->	nocParameters.M_REGIONS,


	"M_BASE_ADDR"			->BigInt("10008000080000000",16),	// Need to insert dummy 1 to avoid optimization
	"M_ADDR_WIDTH"			->BigInt("10000000c00000018",16),

	//"M_BASE_ADDR"			->BigInt("18000000000080000",16),	// Need to insert dummy 1 to avoid optimization
	//"M_ADDR_WIDTH"			->BigInt("1000000180000000c",16),
	"M_CONNECT_READ"		->0xf,
	"M_CONNECT_WRITE"		->0xf,
	"M_SECURE"				->0,
))	with	HasBlackBoxResource{

	val	io	=	IO(new	Bundle	{

		import	nocParameters._
		val	clk	=	Input(Clock())
		val	rst	=	Input(UInt(1.W))

		//	AXI	slave	interface	s_axi
		val	s_axi_awid			=	Input(UInt((S_COUNT*ID_WIDTH).W))
		val	s_axi_awaddr		=	Input(UInt((S_COUNT*ADDR_WIDTH).W))
		val	s_axi_awlen			=	Input(UInt((S_COUNT*8).W))
		val	s_axi_awsize		=	Input(UInt((S_COUNT*3).W))
		val	s_axi_awburst		=	Input(UInt((S_COUNT*2).W))
		val	s_axi_awlock		=	Input(UInt((S_COUNT*1).W))
		val	s_axi_awcache		=	Input(UInt((S_COUNT*4).W))
		val	s_axi_awprot		=	Input(UInt((S_COUNT*3).W))
		val	s_axi_awqos			=	Input(UInt((S_COUNT*4).W))
		val	s_axi_awuser		=	Input(UInt((S_COUNT*AWUSER_WIDTH).W))
		val	s_axi_awvalid		=	Input(UInt((S_COUNT*1).W))
		val	s_axi_awready		=	Output(UInt((S_COUNT*1).W))

		val	s_axi_wdata			=	Input(UInt((S_COUNT*DATA_WIDTH).W))
		val	s_axi_wstrb			=	Input(UInt((S_COUNT*STRB_WIDTH).W))
		val	s_axi_wlast			=	Input(UInt((S_COUNT*1).W))
		val	s_axi_wuser			=	Input(UInt((S_COUNT*WUSER_WIDTH).W))
		val	s_axi_wvalid		=	Input(UInt((S_COUNT*1).W))
		val	s_axi_wready		=	Output(UInt((S_COUNT*1).W))

		val	s_axi_bid			=	Output(UInt((S_COUNT*ID_WIDTH).W))
		val	s_axi_bresp			=	Output(UInt((S_COUNT*2).W))
		val	s_axi_buser			=	Output(UInt((S_COUNT*BUSER_WIDTH).W))
		val	s_axi_bvalid		=	Output(UInt((S_COUNT*1).W))
		val	s_axi_bready		=	Input(UInt((S_COUNT*1).W))

		val	s_axi_arid			=	Input(UInt((S_COUNT*ID_WIDTH).W))
		val	s_axi_araddr		=	Input(UInt((S_COUNT*ADDR_WIDTH).W))
		val	s_axi_arlen			=	Input(UInt((S_COUNT*8).W))
		val	s_axi_arsize		=	Input(UInt((S_COUNT*3).W))
		val	s_axi_arburst		=	Input(UInt((S_COUNT*2).W))
		val	s_axi_arlock		=	Input(UInt((S_COUNT*1).W))
		val	s_axi_arcache		=	Input(UInt((S_COUNT*4).W))
		val	s_axi_arprot		=	Input(UInt((S_COUNT*3).W))
		val	s_axi_arqos			=	Input(UInt((S_COUNT*4).W))
		val	s_axi_aruser		=	Input(UInt((S_COUNT*ARUSER_WIDTH).W))
		val	s_axi_arvalid		=	Input(UInt((S_COUNT*1).W))
		val	s_axi_arready		=	Output(UInt((S_COUNT*1).W))

		val	s_axi_rid			=	Output(UInt((S_COUNT*ID_WIDTH).W))
		val	s_axi_rdata			=	Output(UInt((S_COUNT*DATA_WIDTH).W))
		val	s_axi_rresp			=	Output(UInt((S_COUNT*2).W))
		val	s_axi_rlast			=	Output(UInt((S_COUNT*1).W))
		val	s_axi_ruser			=	Output(UInt((S_COUNT*RUSER_WIDTH).W))
		val	s_axi_rvalid		=	Output(UInt((S_COUNT*1).W))
		val	s_axi_rready		=	Input(UInt((S_COUNT*1).W))

		//	AXI	master	interface	m_axi
		val	m_axi_awid			=	Output(UInt((M_COUNT*ID_WIDTH).W))
		val	m_axi_awaddr		=	Output(UInt((M_COUNT*ADDR_WIDTH).W))
		val	m_axi_awlen			=	Output(UInt((M_COUNT*8).W))
		val	m_axi_awsize		=	Output(UInt((M_COUNT*3).W))
		val	m_axi_awburst		=	Output(UInt((M_COUNT*2).W))
		val	m_axi_awlock		=	Output(UInt((M_COUNT*1).W))
		val	m_axi_awcache		=	Output(UInt((M_COUNT*4).W))
		val	m_axi_awprot		=	Output(UInt((M_COUNT*3).W))
		val	m_axi_awqos			=	Output(UInt((M_COUNT*4).W))
		val	m_axi_awregion		=	Output(UInt((M_COUNT*4).W))
		val	m_axi_awuser		=	Output(UInt((M_COUNT*AWUSER_WIDTH).W))
		val	m_axi_awvalid		=	Output(UInt((M_COUNT*1).W))
		val	m_axi_awready		=	Input(UInt((M_COUNT*1).W))

		val	m_axi_wdata			=	Output(UInt((M_COUNT*DATA_WIDTH).W))
		val	m_axi_wstrb			=	Output(UInt((M_COUNT*STRB_WIDTH).W))
		val	m_axi_wlast			=	Output(UInt((M_COUNT*1).W))
		val	m_axi_wuser			=	Output(UInt((M_COUNT*WUSER_WIDTH).W))
		val	m_axi_wvalid		=	Output(UInt((M_COUNT*1).W))
		val	m_axi_wready		=	Input(UInt((M_COUNT*1).W))

		val	m_axi_bid			=	Input(UInt((M_COUNT*ID_WIDTH).W))
		val	m_axi_bresp			=	Input(UInt((M_COUNT*2).W))
		val	m_axi_buser			=	Input(UInt((M_COUNT*BUSER_WIDTH).W))
		val	m_axi_bvalid		=	Input(UInt((M_COUNT*1).W))
		val	m_axi_bready		=	Output(UInt((M_COUNT*1).W))

		val	m_axi_arid			=	Output(UInt((M_COUNT*ID_WIDTH).W))
		val	m_axi_araddr		=	Output(UInt((M_COUNT*ADDR_WIDTH).W))
		val	m_axi_arlen			=	Output(UInt((M_COUNT*8).W))
		val	m_axi_arsize		=	Output(UInt((M_COUNT*3).W))
		val	m_axi_arburst		=	Output(UInt((M_COUNT*2).W))
		val	m_axi_arlock		=	Output(UInt((M_COUNT*1).W))
		val	m_axi_arcache		=	Output(UInt((M_COUNT*4).W))
		val	m_axi_arprot		=	Output(UInt((M_COUNT*3).W))
		val	m_axi_arqos			=	Output(UInt((M_COUNT*4).W))
		val	m_axi_arregion		=	Output(UInt((M_COUNT*4).W))
		val	m_axi_aruser		=	Output(UInt((M_COUNT*ARUSER_WIDTH).W))
		val	m_axi_arvalid		=	Output(UInt((M_COUNT*1).W))
		val	m_axi_arready		=	Input(UInt((M_COUNT*1).W))

		val	m_axi_rid			=	Input(UInt((M_COUNT*ID_WIDTH).W))
		val	m_axi_rdata			=	Input(UInt((M_COUNT*DATA_WIDTH).W))
		val	m_axi_rresp			=	Input(UInt((M_COUNT*2).W))
		val	m_axi_rlast			=	Input(UInt((M_COUNT*1).W))
		val	m_axi_ruser			=	Input(UInt((M_COUNT*RUSER_WIDTH).W))
		val	m_axi_rvalid		=	Input(UInt((M_COUNT*1).W))
		val	m_axi_rready		=	Output(UInt((M_COUNT*1).W))

	})

	//	ALEX	FORENCICH	AXI	INTERCONNECT
	addResource("/verilog-axi/rtl/axi_interconnect.v")
}





class axi_interconnect_top(nocParameters:NOCParameters)	extends	Module{

	import	nocParameters._
	val	io	=	IO(new	Bundle	{
		//	AXI	M	port	(input)
		val	m_AXI_port	=	Vec(M_COUNT,	Flipped(new	AXIFullIO(nocParameters)))

		//	AXI	S	port	(output)
		val	s_AXI_port	=	Vec(S_COUNT,	new	AXIFullIO(nocParameters))
	})

	//	INIT	NOC
	val	NOC	=	Module(new	axi_interconnect(nocParameters))


	clock	<>	NOC.io.clk
	reset	<>	NOC.io.rst

	

	// ASSIGN MASTERS 
	def read_slice(n: UInt, slice_width: Int, index: Int): UInt = {
		n(slice_width * (index + 1) - 1, slice_width * index)
	}

	def read_slice_reverse(n: UInt, slice_width: Int, index: Int): UInt = {
		n(n.getWidth - (slice_width * (index + 1)), n.getWidth - slice_width * index - 1)
	}





	//connect up masters
	for(i<-0 until M_COUNT){
		io.s_AXI_port(i).AXI_AW.bits.awid  		:=read_slice(NOC.io.m_axi_awid, io.s_AXI_port(i).AXI_AW.bits.awid.getWidth, i)
		io.s_AXI_port(i).AXI_AW.bits.awaddr 	:=read_slice(NOC.io.m_axi_awaddr, io.s_AXI_port(i).AXI_AW.bits.awaddr.getWidth ,i)
		io.s_AXI_port(i).AXI_AW.bits.awlen 		:=read_slice(NOC.io.m_axi_awlen, io.s_AXI_port(i).AXI_AW.bits.awlen.getWidth, i)
		io.s_AXI_port(i).AXI_AW.bits.awsize 	:=read_slice(NOC.io.m_axi_awsize, io.s_AXI_port(i).AXI_AW.bits.awsize.getWidth, i)
		io.s_AXI_port(i).AXI_AW.bits.awburst	:=read_slice(NOC.io.m_axi_awburst, io.s_AXI_port(i).AXI_AW.bits.awburst.getWidth, i)
		io.s_AXI_port(i).AXI_AW.bits.awlock		:=read_slice(NOC.io.m_axi_awlock, io.s_AXI_port(i).AXI_AW.bits.awlock.getWidth, i)
		io.s_AXI_port(i).AXI_AW.bits.awcache	:=read_slice(NOC.io.m_axi_awcache, io.s_AXI_port(i).AXI_AW.bits.awcache.getWidth, i)
		io.s_AXI_port(i).AXI_AW.bits.awprot		:=read_slice(NOC.io.m_axi_awprot, io.s_AXI_port(i).AXI_AW.bits.awprot.getWidth ,i)
		io.s_AXI_port(i).AXI_AW.bits.awqos		:=read_slice(NOC.io.m_axi_awqos, io.s_AXI_port(i).AXI_AW.bits.awqos.getWidth ,i)
		io.s_AXI_port(i).AXI_AW.bits.awuser		:=read_slice(NOC.io.m_axi_awuser, io.s_AXI_port(i).AXI_AW.bits.awuser.getWidth ,i)
		io.s_AXI_port(i).AXI_AW.bits.awregion	:=read_slice(NOC.io.m_axi_awregion, io.s_AXI_port(i).AXI_AW.bits.awregion.getWidth ,i)
		io.s_AXI_port(i).AXI_AW.valid			:=read_slice(NOC.io.m_axi_awvalid, io.s_AXI_port(i).AXI_AW.valid.getWidth ,i)
		NOC.io.m_axi_awready 					:=Cat(io.s_AXI_port.map(_.AXI_AW.ready).reverse)
	
		io.s_AXI_port(i).AXI_W.bits.wdata 		:= read_slice(NOC.io.m_axi_wdata,io.s_AXI_port(i).AXI_W.bits.wdata.getWidth,i)
		io.s_AXI_port(i).AXI_W.bits.wstrb 		:= read_slice(NOC.io.m_axi_wstrb,io.s_AXI_port(i).AXI_W.bits.wstrb.getWidth,i)
		io.s_AXI_port(i).AXI_W.bits.wlast 		:= read_slice(NOC.io.m_axi_wlast,io.s_AXI_port(i).AXI_W.bits.wlast.getWidth,i)
		io.s_AXI_port(i).AXI_W.bits.wuser		:= read_slice(NOC.io.m_axi_wuser,io.s_AXI_port(i).AXI_W.bits.wuser.getWidth,i)
		io.s_AXI_port(i).AXI_W.valid 	  		:= read_slice(NOC.io.m_axi_wvalid,io.s_AXI_port(i).AXI_W.valid.getWidth,i)
		NOC.io.m_axi_wready 			  		:= 	Cat(io.s_AXI_port.map(_.AXI_W.ready).reverse)

		NOC.io.m_axi_bid 	:= Cat(io.s_AXI_port.map(_.AXI_B.bits.bid).reverse)
		NOC.io.m_axi_bresp 	:= Cat(io.s_AXI_port.map(_.AXI_B.bits.bresp).reverse)
		NOC.io.m_axi_buser 	:= Cat(io.s_AXI_port.map(_.AXI_B.bits.buser).reverse)
		NOC.io.m_axi_bvalid := Cat(io.s_AXI_port.map(_.AXI_B.valid).reverse)
		io.s_AXI_port(i).AXI_B.ready := read_slice(NOC.io.m_axi_bready,1,i)

		io.s_AXI_port(i).AXI_AR.bits.arid 		:= read_slice(NOC.io.m_axi_arid,ID_WIDTH,i)
		io.s_AXI_port(i).AXI_AR.bits.araddr 	:= read_slice(NOC.io.m_axi_araddr,ADDR_WIDTH,i)
		io.s_AXI_port(i).AXI_AR.bits.arlen 		:= read_slice(NOC.io.m_axi_arlen,8,i)
		io.s_AXI_port(i).AXI_AR.bits.arsize	 	:= read_slice(NOC.io.m_axi_arsize,3,i)
		io.s_AXI_port(i).AXI_AR.bits.arburst	:= read_slice(NOC.io.m_axi_arburst,2,i)
		io.s_AXI_port(i).AXI_AR.bits.arlock 	:= read_slice(NOC.io.m_axi_arlock,1,i)
		io.s_AXI_port(i).AXI_AR.bits.arcache 	:= read_slice(NOC.io.m_axi_arcache,4,i)
		io.s_AXI_port(i).AXI_AR.bits.arprot 	:= read_slice(NOC.io.m_axi_arprot,3,i)
		io.s_AXI_port(i).AXI_AR.bits.arqos 		:= read_slice(NOC.io.m_axi_arqos,4,i)
		io.s_AXI_port(i).AXI_AR.bits.arregion 	:= read_slice(NOC.io.m_axi_arregion,1,i)
		io.s_AXI_port(i).AXI_AR.bits.aruser 	:= read_slice(NOC.io.m_axi_aruser,ARUSER_WIDTH,i)
		io.s_AXI_port(i).AXI_AR.valid			:= read_slice(NOC.io.m_axi_arvalid,1,i)
		NOC.io.m_axi_arready					:= Cat(io.s_AXI_port.map(_.AXI_AR.ready).reverse)

		NOC.io.m_axi_rid   := Cat(io.s_AXI_port.map(_.AXI_R.bits.rid).reverse)
		NOC.io.m_axi_rdata := Cat(io.s_AXI_port.map(_.AXI_R.bits.rdata).reverse)
		NOC.io.m_axi_rresp := Cat(io.s_AXI_port.map(_.AXI_R.bits.rresp).reverse)
		NOC.io.m_axi_rlast := Cat(io.s_AXI_port.map(_.AXI_R.bits.rlast).reverse)
		NOC.io.m_axi_ruser := Cat(io.s_AXI_port.map(_.AXI_R.bits.ruser).reverse)
		NOC.io.m_axi_rvalid:= Cat(io.s_AXI_port.map(_.AXI_R.valid).reverse)
		io.s_AXI_port(i).AXI_R.ready := read_slice(NOC.io.m_axi_rready,1,i)
	}
		




	for(i<-0 until S_COUNT){
		NOC.io.s_axi_awid   := Cat(io.m_AXI_port.map(_.AXI_AW.bits.awid).reverse)
		NOC.io.s_axi_awaddr	:= Cat(io.m_AXI_port.map(_.AXI_AW.bits.awaddr).reverse)
		NOC.io.s_axi_awlen  := Cat(io.m_AXI_port.map(_.AXI_AW.bits.awlen).reverse)
		NOC.io.s_axi_awsize := Cat(io.m_AXI_port.map(_.AXI_AW.bits.awsize).reverse)
		NOC.io.s_axi_awburst:= Cat(io.m_AXI_port.map(_.AXI_AW.bits.awburst).reverse)
		NOC.io.s_axi_awlock	:= Cat(io.m_AXI_port.map(_.AXI_AW.bits.awlock).reverse)
		NOC.io.s_axi_awcache:= Cat(io.m_AXI_port.map(_.AXI_AW.bits.awcache).reverse)
		NOC.io.s_axi_awprot := Cat(io.m_AXI_port.map(_.AXI_AW.bits.awprot).reverse)
		NOC.io.s_axi_awqos  := Cat(io.m_AXI_port.map(_.AXI_AW.bits.awqos).reverse)
		NOC.io.s_axi_awuser := Cat(io.m_AXI_port.map(_.AXI_AW.bits.awuser).reverse)
		NOC.io.s_axi_awvalid:= Cat(io.m_AXI_port.map(_.AXI_AW.valid).reverse)
		io.m_AXI_port(i).AXI_AW.ready := 	read_slice(NOC.io.s_axi_awready,1,i)

		NOC.io.s_axi_wdata := Cat(io.m_AXI_port.map(_.AXI_W.bits.wdata).reverse)
		NOC.io.s_axi_wstrb := Cat(io.m_AXI_port.map(_.AXI_W.bits.wstrb).reverse)
		NOC.io.s_axi_wlast := Cat(io.m_AXI_port.map(_.AXI_W.bits.wlast).reverse)
		NOC.io.s_axi_wuser := Cat(io.m_AXI_port.map(_.AXI_W.bits.wuser).reverse)
		NOC.io.s_axi_wvalid:= Cat(io.m_AXI_port.map(_.AXI_W.valid).reverse)
		io.m_AXI_port(i).AXI_W.ready := read_slice(NOC.io.s_axi_wready,1,i)
	
	 
	 	// FIXME: REVERSE RHS
		io.m_AXI_port(i).AXI_B.bits.bid 	:= 	read_slice(NOC.io.s_axi_bid,ID_WIDTH ,i)
		io.m_AXI_port(i).AXI_B.bits.bresp 	:= 	read_slice(NOC.io.s_axi_bresp,2,i)
		io.m_AXI_port(i).AXI_B.bits.buser 	:= 	read_slice(NOC.io.s_axi_buser,BUSER_WIDTH,i)
		io.m_AXI_port(i).AXI_B.valid 		:= 	read_slice(NOC.io.s_axi_bvalid,1,i)
		NOC.io.s_axi_bready 				:= 	Cat(io.m_AXI_port.map(_.AXI_B.ready).reverse)

		NOC.io.s_axi_arid   := Cat(io.m_AXI_port.map(_.AXI_AR.bits.arid).reverse)
		NOC.io.s_axi_araddr := Cat(io.m_AXI_port.map(_.AXI_AR.bits.araddr).reverse)
		NOC.io.s_axi_arlen  := Cat(io.m_AXI_port.map(_.AXI_AR.bits.arlen).reverse)
		NOC.io.s_axi_arsize := Cat(io.m_AXI_port.map(_.AXI_AR.bits.arsize).reverse)
		NOC.io.s_axi_arburst:= Cat(io.m_AXI_port.map(_.AXI_AR.bits.arburst).reverse)
		NOC.io.s_axi_arlock := Cat(io.m_AXI_port.map(_.AXI_AR.bits.arlock).reverse)
		NOC.io.s_axi_arcache:= Cat(io.m_AXI_port.map(_.AXI_AR.bits.arcache).reverse)
		NOC.io.s_axi_arprot := Cat(io.m_AXI_port.map(_.AXI_AR.bits.arprot).reverse)
		NOC.io.s_axi_arqos  := Cat(io.m_AXI_port.map(_.AXI_AR.bits.arqos).reverse)
		NOC.io.s_axi_aruser := Cat(io.m_AXI_port.map(_.AXI_AR.bits.aruser).reverse)
		NOC.io.s_axi_arvalid:= Cat(io.m_AXI_port.map(_.AXI_AR.valid).reverse)
		io.m_AXI_port(i).AXI_AR.ready := read_slice(NOC.io.s_axi_arready,1,i)
	
		// FIXME: reverse RH,,iS
		io.m_AXI_port(i).AXI_R.bits.rid 	:= 	read_slice(NOC.io.s_axi_rid,ID_WIDTH,i)
		io.m_AXI_port(i).AXI_R.bits.rdata 	:= 	read_slice(NOC.io.s_axi_rdata,DATA_WIDTH,i)
		io.m_AXI_port(i).AXI_R.bits.rresp 	:=	read_slice(NOC.io.s_axi_rresp,2,i)
		io.m_AXI_port(i).AXI_R.bits.rlast 	:=  read_slice(NOC.io.s_axi_rlast,1,i)
		io.m_AXI_port(i).AXI_R.bits.ruser 	:= 	read_slice(NOC.io.s_axi_ruser,RUSER_WIDTH,i)
		io.m_AXI_port(i).AXI_R.valid 		:= 	read_slice(NOC.io.s_axi_rvalid,1,i)
		NOC.io.s_axi_rready					:= 	Cat(io.m_AXI_port.map(_.AXI_R.ready).reverse)
	}
	

	
	dontTouch(io)

}

