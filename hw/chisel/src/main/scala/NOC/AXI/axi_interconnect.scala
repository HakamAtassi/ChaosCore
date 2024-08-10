/*	------------------------------------------------------------------------------------
*	Filename:	axi_interconnect.scala
*	Author:	Hakam	Atassi
*	Date:	May	22	2024
*	Description:	A	blackbox	for	alex	forenchich's	axi	interconnect
*	License:	MIT
*
*	Copyright	(c)	2024	by	Hakam	Atassi
*
*	Permission	is	hereby	granted,	free	of	charge,	to	any	person	obtaining	a	copy
*	of	this	software	and	associated	documentation	files	(the	"Software"),	to	deal
*	in	the	Software	without	restriction,	including	without	limitation	the	rights
*	to	use,	copy,	modify,	merge,	publish,	distribute,	sublicense,	and/or	sell
*	copies	of	the	Software,	and	to	permit	persons	to	whom	the	Software	is
*	furnished	to	do	so,	subject	to	the	following	conditions:
*	
*	The	above	copyright	notice	and	this	permission	notice	shall	be	included	in	all
*	copies	or	substantial	portions	of	the	Software.
*
*	THE	SOFTWARE	IS	PROVIDED	"AS	IS",	WITHOUT	WARRANTY	OF	ANY	KIND,	EXPRESS	OR
*	IMPLIED,	INCLUDING	BUT	NOT	LIMITED	TO	THE	WARRANTIES	OF	MERCHANTABILITY,
*	FITNESS	FOR	A	PARTICULAR	PURPOSE	AND	NONINFRINGEMENT.	IN	NO	EVENT	SHALL	THE
*	AUTHORS	OR	COPYRIGHT	HOLDERS	BE	LIABLE	FOR	ANY	CLAIM,	DAMAGES	OR	OTHER
*	LIABILITY,	WHETHER	IN	AN	ACTION	OF	CONTRACT,	TORT	OR	OTHERWISE,	ARISING	FROM,
*	OUT	OF	OR	IN	CONNECTION	WITH	THE	SOFTWARE	OR	THE	USE	OR	OTHER	DEALINGS	IN	THE
*	SOFTWARE.
*	------------------------------------------------------------------------------------	
*/


package	ChaosCore

import	chisel3._
import	chisel3.experimental._
import	circt.stage.ChiselStage	
import	chisel3.util._


//	Define	the	BlackBox	module
class	axi_interconnect_wrap_2x2(nocParameters:NOCParameters)	extends	BlackBox(Map(
	"DATA_WIDTH"						->	nocParameters.DATA_WIDTH,
	"ADDR_WIDTH"						->	nocParameters.ADDR_WIDTH,
	"STRB_WIDTH"						->	nocParameters.STRB_WIDTH,
	"ID_WIDTH"								->	nocParameters.ID_WIDTH,
	"AWUSER_ENABLE"			->	nocParameters.AWUSER_ENABLE,
	"AWUSER_WIDTH"				->	nocParameters.AWUSER_WIDTH,
	"WUSER_ENABLE"				->	nocParameters.WUSER_ENABLE,
	"WUSER_WIDTH"					->	nocParameters.WUSER_WIDTH,
	"BUSER_ENABLE"				->	nocParameters.BUSER_ENABLE,
	"BUSER_WIDTH"					->	nocParameters.BUSER_WIDTH,
	"ARUSER_ENABLE"			->	nocParameters.ARUSER_ENABLE,
	"ARUSER_WIDTH"				->	nocParameters.ARUSER_WIDTH,
	"RUSER_ENABLE"				->	nocParameters.RUSER_ENABLE,
	"RUSER_WIDTH"					->	nocParameters.RUSER_WIDTH,
	"FORWARD_ID"						->	nocParameters.FORWARD_ID,
	"M_REGIONS"							->	nocParameters.M_REGIONS,

    "M00_BASE_ADDR" 	-> nocParameters.M_BASE_ADDR,
    "M00_ADDR_WIDTH" 	-> nocParameters.M_ADDR_WIDTH,
    "M00_CONNECT_READ" 	-> nocParameters.M_CONNECT_READ,
    "M00_CONNECT_WRITE" -> nocParameters.M_CONNECT_WRITE,
    "M00_SECURE" 		-> nocParameters.M_SECURE,
    "M01_BASE_ADDR" 	-> nocParameters.M_BASE_ADDR,
    "M01_ADDR_WIDTH" 	-> nocParameters.M_ADDR_WIDTH,
    "M01_CONNECT_READ" 	-> nocParameters.M_CONNECT_READ,
    "M01_CONNECT_WRITE" -> nocParameters.M_CONNECT_WRITE,
    "M01_SECURE" 		-> nocParameters.M_SECURE

))	with	HasBlackBoxResource{


	val	io	=	IO(new	Bundle	{

		import	nocParameters._
		val	clk	=	Input(Clock())
		val	rst	=	Input(Bool())

		//	AXI	slave	interface	s00_axi
		val	s00_axi_awid					=	Input(UInt(ID_WIDTH.W))
		val	s00_axi_awaddr			=	Input(UInt(ADDR_WIDTH.W))
		val	s00_axi_awlen				=	Input(UInt(8.W))
		val	s00_axi_awsize			=	Input(UInt(3.W))
		val	s00_axi_awburst		=	Input(UInt(2.W))
		val	s00_axi_awlock			=	Input(Bool())
		val	s00_axi_awcache		=	Input(UInt(4.W))
		val	s00_axi_awprot			=	Input(UInt(3.W))
		val	s00_axi_awqos				=	Input(UInt(4.W))
		val	s00_axi_awuser			=	Input(UInt(AWUSER_WIDTH.W))
		val	s00_axi_awvalid		=	Input(Bool())
		val	s00_axi_awready		=	Output(Bool())

		val	s00_axi_wdata				=	Input(UInt(DATA_WIDTH.W))
		val	s00_axi_wstrb				=	Input(UInt(STRB_WIDTH.W))
		val	s00_axi_wlast				=	Input(Bool())
		val	s00_axi_wuser				=	Input(UInt(WUSER_WIDTH.W))
		val	s00_axi_wvalid			=	Input(Bool())
		val	s00_axi_wready			=	Output(Bool())

		val	s00_axi_bid						=	Output(UInt(ID_WIDTH.W))
		val	s00_axi_bresp				=	Output(UInt(2.W))
		val	s00_axi_buser				=	Output(UInt(BUSER_WIDTH.W))
		val	s00_axi_bvalid			=	Output(Bool())
		val	s00_axi_bready			=	Input(Bool())

		val	s00_axi_arid					=	Input(UInt(ID_WIDTH.W))
		val	s00_axi_araddr			=	Input(UInt(ADDR_WIDTH.W))
		val	s00_axi_arlen				=	Input(UInt(8.W))
		val	s00_axi_arsize			=	Input(UInt(3.W))
		val	s00_axi_arburst		=	Input(UInt(2.W))
		val	s00_axi_arlock			=	Input(Bool())
		val	s00_axi_arcache		=	Input(UInt(4.W))
		val	s00_axi_arprot			=	Input(UInt(3.W))
		val	s00_axi_arqos				=	Input(UInt(4.W))
		val	s00_axi_aruser			=	Input(UInt(ARUSER_WIDTH.W))
		val	s00_axi_arvalid		=	Input(Bool())
		val	s00_axi_arready		=	Output(Bool())

		val	s00_axi_rid						=	Output(UInt(ID_WIDTH.W))
		val	s00_axi_rdata				=	Output(UInt(DATA_WIDTH.W))
		val	s00_axi_rresp				=	Output(UInt(2.W))
		val	s00_axi_rlast				=	Output(Bool())
		val	s00_axi_ruser				=	Output(UInt(RUSER_WIDTH.W))
		val	s00_axi_rvalid			=	Output(Bool())
		val	s00_axi_rready			=	Input(Bool())

		//	AXI	slave	interface	s01_axi
		val	s01_axi_awid					=	Input(UInt(ID_WIDTH.W))
		val	s01_axi_awaddr			=	Input(UInt(ADDR_WIDTH.W))
		val	s01_axi_awlen				=	Input(UInt(8.W))
		val	s01_axi_awsize			=	Input(UInt(3.W))
		val	s01_axi_awburst		=	Input(UInt(2.W))
		val	s01_axi_awlock			=	Input(Bool())
		val	s01_axi_awcache		=	Input(UInt(4.W))
		val	s01_axi_awprot			=	Input(UInt(3.W))
		val	s01_axi_awqos				=	Input(UInt(4.W))
		val	s01_axi_awuser			=	Input(UInt(AWUSER_WIDTH.W))
		val	s01_axi_awvalid		=	Input(Bool())
		val	s01_axi_awready		=	Output(Bool())
		val	s01_axi_wdata				=	Input(UInt(DATA_WIDTH.W))
		val	s01_axi_wstrb				=	Input(UInt(STRB_WIDTH.W))
		val	s01_axi_wlast				=	Input(Bool())
		val	s01_axi_wuser				=	Input(UInt(WUSER_WIDTH.W))
		val	s01_axi_wvalid			=	Input(Bool())
		val	s01_axi_wready			=	Output(Bool())
		val	s01_axi_bid						=	Output(UInt(ID_WIDTH.W))
		val	s01_axi_bresp				=	Output(UInt(2.W))
		val	s01_axi_buser				=	Output(UInt(BUSER_WIDTH.W))
		val	s01_axi_bvalid			=	Output(Bool())
		val	s01_axi_bready			=	Input(Bool())
		val	s01_axi_arid					=	Input(UInt(ID_WIDTH.W))
		val	s01_axi_araddr			=	Input(UInt(ADDR_WIDTH.W))
		val	s01_axi_arlen				=	Input(UInt(8.W))
		val	s01_axi_arsize			=	Input(UInt(3.W))
		val	s01_axi_arburst		=	Input(UInt(2.W))
		val	s01_axi_arlock			=	Input(Bool())
		val	s01_axi_arcache		=	Input(UInt(4.W))
		val	s01_axi_arprot			=	Input(UInt(3.W))
		val	s01_axi_arqos				=	Input(UInt(4.W))
		val	s01_axi_aruser			=	Input(UInt(ARUSER_WIDTH.W))
		val	s01_axi_arvalid		=	Input(Bool())
		val	s01_axi_arready		=	Output(Bool())
		val	s01_axi_rid						=	Output(UInt(ID_WIDTH.W))
		val	s01_axi_rdata				=	Output(UInt(DATA_WIDTH.W))
		val	s01_axi_rresp				=	Output(UInt(2.W))
		val	s01_axi_rlast				=	Output(Bool())
		val	s01_axi_ruser				=	Output(UInt(RUSER_WIDTH.W))
		val	s01_axi_rvalid			=	Output(Bool())
		val	s01_axi_rready			=	Input(Bool())

		//	AXI	master	interface	m00_axi
		val	m00_axi_awid					=	Output(UInt(ID_WIDTH.W))
		val	m00_axi_awaddr			=	Output(UInt(ADDR_WIDTH.W))
		val	m00_axi_awlen				=	Output(UInt(8.W))
		val	m00_axi_awsize			=	Output(UInt(3.W))
		val	m00_axi_awburst		=	Output(UInt(2.W))
		val	m00_axi_awlock			=	Output(Bool())
		val	m00_axi_awcache		=	Output(UInt(4.W))
		val	m00_axi_awprot			=	Output(UInt(3.W))
		val	m00_axi_awqos				=	Output(UInt(4.W))
		val	m00_axi_awregion	=	Output(UInt(4.W))
		val	m00_axi_awuser			=	Output(UInt(AWUSER_WIDTH.W))
		val	m00_axi_awvalid		=	Output(Bool())
		val	m00_axi_awready		=	Input(Bool())
		val	m00_axi_wdata				=	Output(UInt(DATA_WIDTH.W))
		val	m00_axi_wstrb				=	Output(UInt(STRB_WIDTH.W))
		val	m00_axi_wlast				=	Output(Bool())
		val	m00_axi_wuser				=	Output(UInt(WUSER_WIDTH.W))
		val	m00_axi_wvalid			=	Output(Bool())
		val	m00_axi_wready			=	Input(Bool())
		val	m00_axi_bid						=	Input(UInt(ID_WIDTH.W))
		val	m00_axi_bresp				=	Input(UInt(2.W))
		val	m00_axi_buser				=	Input(UInt(BUSER_WIDTH.W))
		val	m00_axi_bvalid			=	Input(Bool())
		val	m00_axi_bready			=	Output(Bool())
		val	m00_axi_arid					=	Output(UInt(ID_WIDTH.W))
		val	m00_axi_araddr			=	Output(UInt(ADDR_WIDTH.W))
		val	m00_axi_arlen				=	Output(UInt(8.W))
		val	m00_axi_arsize			=	Output(UInt(3.W))
		val	m00_axi_arburst		=	Output(UInt(2.W))
		val	m00_axi_arlock			=	Output(Bool())
		val	m00_axi_arcache		=	Output(UInt(4.W))
		val	m00_axi_arprot			=	Output(UInt(3.W))
		val	m00_axi_arqos				=	Output(UInt(4.W))
		val	m00_axi_arregion	=	Output(UInt(4.W))
		val	m00_axi_aruser			=	Output(UInt(ARUSER_WIDTH.W))
		val	m00_axi_arvalid		=	Output(Bool())
		val	m00_axi_arready		=	Input(Bool())
		val	m00_axi_rid						=	Input(UInt(ID_WIDTH.W))
		val	m00_axi_rdata				=	Input(UInt(DATA_WIDTH.W))
		val	m00_axi_rresp				=	Input(UInt(2.W))
		val	m00_axi_rlast				=	Input(Bool())
		val	m00_axi_ruser				=	Input(UInt(RUSER_WIDTH.W))
		val	m00_axi_rvalid			=	Input(Bool())
		val	m00_axi_rready			=	Output(Bool())


		//	AXI	master	interface	m01_axi
		val	m01_axi_awid					=	Output(UInt(ID_WIDTH.W))
		val	m01_axi_awaddr			=	Output(UInt(ADDR_WIDTH.W))
		val	m01_axi_awlen				=	Output(UInt(8.W))
		val	m01_axi_awsize			=	Output(UInt(3.W))
		val	m01_axi_awburst		=	Output(UInt(2.W))
		val	m01_axi_awlock			=	Output(Bool())
		val	m01_axi_awcache		=	Output(UInt(4.W))
		val	m01_axi_awprot			=	Output(UInt(3.W))
		val	m01_axi_awqos				=	Output(UInt(4.W))
		val	m01_axi_awregion	=	Output(UInt(4.W))
		val	m01_axi_awuser			=	Output(UInt(AWUSER_WIDTH.W))
		val	m01_axi_awvalid		=	Output(Bool())
		val	m01_axi_awready		=	Input(Bool())
		val	m01_axi_wdata				=	Output(UInt(DATA_WIDTH.W))
		val	m01_axi_wstrb				=	Output(UInt(STRB_WIDTH.W))
		val	m01_axi_wlast				=	Output(Bool())
		val	m01_axi_wuser				=	Output(UInt(WUSER_WIDTH.W))
		val	m01_axi_wvalid			=	Output(Bool())
		val	m01_axi_wready			=	Input(Bool())
		val	m01_axi_bid						=	Input(UInt(ID_WIDTH.W))
		val	m01_axi_bresp				=	Input(UInt(2.W))
		val	m01_axi_buser				=	Input(UInt(BUSER_WIDTH.W))
		val	m01_axi_bvalid			=	Input(Bool())
		val	m01_axi_bready			=	Output(Bool())
		val	m01_axi_arid					=	Output(UInt(ID_WIDTH.W))
		val	m01_axi_araddr			=	Output(UInt(ADDR_WIDTH.W))
		val	m01_axi_arlen				=	Output(UInt(8.W))
		val	m01_axi_arsize			=	Output(UInt(3.W))
		val	m01_axi_arburst		=	Output(UInt(2.W))
		val	m01_axi_arlock			=	Output(Bool())
		val	m01_axi_arcache		=	Output(UInt(4.W))
		val	m01_axi_arprot			=	Output(UInt(3.W))
		val	m01_axi_arqos				=	Output(UInt(4.W))
		val	m01_axi_arregion	=	Output(UInt(4.W))
		val	m01_axi_aruser			=	Output(UInt(ARUSER_WIDTH.W))
		val	m01_axi_arvalid		=	Output(Bool())
		val	m01_axi_arready		=	Input(Bool())
		val	m01_axi_rid						=	Input(UInt(ID_WIDTH.W))
		val	m01_axi_rdata				=	Input(UInt(DATA_WIDTH.W))
		val	m01_axi_rresp				=	Input(UInt(2.W))
		val	m01_axi_rlast				=	Input(Bool())
		val	m01_axi_ruser				=	Input(UInt(RUSER_WIDTH.W))
		val	m01_axi_rvalid			=	Input(Bool())
		val	m01_axi_rready			=	Output(Bool())

	})
	//	ALEX	FORENCICH	AXI	INTERCONNECT
	addResource("/verilog-axi/rtl/axi_interconnect_wrap_2x2.v")
}



//	Define	the	BlackBox	module
class	axi_interconnect_2x2(nocParameters:NOCParameters)	extends	Module{

	import	nocParameters._
	val	io	=	IO(new	Bundle	{
		//	AXI	M	port	(input)
		val	m_AXI_port	=	Vec(M_COUNT,	Flipped(new	AXIFullIO(nocParameters)))

		//	AXI	S	port	(output)
		val	s_AXI_port	=	Vec(S_COUNT,	new	AXIFullIO(nocParameters))
	})

	//io.m_AXI_port := DontCare
	//io.s_AXI_port := DontCare


	//	INIT	NOC
	val	NOC	=	Module(new	axi_interconnect_wrap_2x2(nocParameters))


	clock	<>	NOC.io.clk
	reset	<>	NOC.io.rst
	

	// Connect io master to noc slave port
	// Master 0
	NOC.io.s00_axi_awid       <>  io.m_AXI_port(0).AXI_AW.bits.awid
	NOC.io.s00_axi_awaddr     <>  io.m_AXI_port(0).AXI_AW.bits.awaddr
	NOC.io.s00_axi_awlen      <>  io.m_AXI_port(0).AXI_AW.bits.awlen
	NOC.io.s00_axi_awsize     <>  io.m_AXI_port(0).AXI_AW.bits.awsize
	NOC.io.s00_axi_awburst    <>  io.m_AXI_port(0).AXI_AW.bits.awburst
	NOC.io.s00_axi_awlock     <>  io.m_AXI_port(0).AXI_AW.bits.awlock
	NOC.io.s00_axi_awcache    <>  io.m_AXI_port(0).AXI_AW.bits.awcache
	NOC.io.s00_axi_awprot     <>  io.m_AXI_port(0).AXI_AW.bits.awprot
	NOC.io.s00_axi_awqos      <>  io.m_AXI_port(0).AXI_AW.bits.awqos
	NOC.io.s00_axi_awuser     <>  io.m_AXI_port(0).AXI_AW.bits.awuser
	NOC.io.s00_axi_awvalid    <>  io.m_AXI_port(0).AXI_AW.valid
	NOC.io.s00_axi_awready    <>  io.m_AXI_port(0).AXI_AW.ready

	NOC.io.s00_axi_wdata      <>  io.m_AXI_port(0).AXI_W.bits.wdata
	NOC.io.s00_axi_wstrb      <>  io.m_AXI_port(0).AXI_W.bits.wstrb
	NOC.io.s00_axi_wlast      <>  io.m_AXI_port(0).AXI_W.bits.wlast
	NOC.io.s00_axi_wuser      <>  io.m_AXI_port(0).AXI_W.bits.wuser
	NOC.io.s00_axi_wvalid     <>  io.m_AXI_port(0).AXI_W.valid
	NOC.io.s00_axi_wready     <>  io.m_AXI_port(0).AXI_W.ready

	NOC.io.s00_axi_bid        <>  io.m_AXI_port(0).AXI_B.bits.bid
	NOC.io.s00_axi_bresp      <>  io.m_AXI_port(0).AXI_B.bits.bresp
	NOC.io.s00_axi_buser      <>  io.m_AXI_port(0).AXI_B.bits.buser
	NOC.io.s00_axi_bvalid     <>  io.m_AXI_port(0).AXI_B.valid
	NOC.io.s00_axi_bready     <>  io.m_AXI_port(0).AXI_B.ready

	NOC.io.s00_axi_arid       <>  io.m_AXI_port(0).AXI_AR.bits.arid
	NOC.io.s00_axi_araddr     <>  io.m_AXI_port(0).AXI_AR.bits.araddr
	NOC.io.s00_axi_arlen      <>  io.m_AXI_port(0).AXI_AR.bits.arlen
	NOC.io.s00_axi_arsize     <>  io.m_AXI_port(0).AXI_AR.bits.arsize
	NOC.io.s00_axi_arburst    <>  io.m_AXI_port(0).AXI_AR.bits.arburst
	NOC.io.s00_axi_arlock     <>  io.m_AXI_port(0).AXI_AR.bits.arlock
	NOC.io.s00_axi_arcache    <>  io.m_AXI_port(0).AXI_AR.bits.arcache
	NOC.io.s00_axi_arprot     <>  io.m_AXI_port(0).AXI_AR.bits.arprot
	NOC.io.s00_axi_arqos      <>  io.m_AXI_port(0).AXI_AR.bits.arqos
	NOC.io.s00_axi_aruser     <>  io.m_AXI_port(0).AXI_AR.bits.aruser
	NOC.io.s00_axi_arvalid    <>  io.m_AXI_port(0).AXI_AR.valid
	NOC.io.s00_axi_arready    <>  io.m_AXI_port(0).AXI_AR.ready

	NOC.io.s00_axi_rid        <>  io.m_AXI_port(0).AXI_R.bits.rid
	NOC.io.s00_axi_rdata      <>  io.m_AXI_port(0).AXI_R.bits.rdata
	NOC.io.s00_axi_rresp      <>  io.m_AXI_port(0).AXI_R.bits.rresp
	NOC.io.s00_axi_rlast      <>  io.m_AXI_port(0).AXI_R.bits.rlast
	NOC.io.s00_axi_ruser      <>  io.m_AXI_port(0).AXI_R.bits.ruser
	NOC.io.s00_axi_rvalid     <>  io.m_AXI_port(0).AXI_R.valid
	NOC.io.s00_axi_rready     <>  io.m_AXI_port(0).AXI_R.ready

	// Master 1
	NOC.io.s01_axi_awid       <>  io.m_AXI_port(1).AXI_AW.bits.awid
	NOC.io.s01_axi_awaddr     <>  io.m_AXI_port(1).AXI_AW.bits.awaddr
	NOC.io.s01_axi_awlen      <>  io.m_AXI_port(1).AXI_AW.bits.awlen
	NOC.io.s01_axi_awsize     <>  io.m_AXI_port(1).AXI_AW.bits.awsize
	NOC.io.s01_axi_awburst    <>  io.m_AXI_port(1).AXI_AW.bits.awburst
	NOC.io.s01_axi_awlock     <>  io.m_AXI_port(1).AXI_AW.bits.awlock
	NOC.io.s01_axi_awcache    <>  io.m_AXI_port(1).AXI_AW.bits.awcache
	NOC.io.s01_axi_awprot     <>  io.m_AXI_port(1).AXI_AW.bits.awprot
	NOC.io.s01_axi_awqos      <>  io.m_AXI_port(1).AXI_AW.bits.awqos
	NOC.io.s01_axi_awuser     <>  io.m_AXI_port(1).AXI_AW.bits.awuser
	NOC.io.s01_axi_awvalid    <>  io.m_AXI_port(1).AXI_AW.valid
	NOC.io.s01_axi_awready    <>  io.m_AXI_port(1).AXI_AW.ready

	NOC.io.s01_axi_wdata      <>  io.m_AXI_port(1).AXI_W.bits.wdata
	NOC.io.s01_axi_wstrb      <>  io.m_AXI_port(1).AXI_W.bits.wstrb
	NOC.io.s01_axi_wlast      <>  io.m_AXI_port(1).AXI_W.bits.wlast
	NOC.io.s01_axi_wuser      <>  io.m_AXI_port(1).AXI_W.bits.wuser
	NOC.io.s01_axi_wvalid     <>  io.m_AXI_port(1).AXI_W.valid
	NOC.io.s01_axi_wready     <>  io.m_AXI_port(1).AXI_W.ready

	NOC.io.s01_axi_bid        <>  io.m_AXI_port(1).AXI_B.bits.bid
	NOC.io.s01_axi_bresp      <>  io.m_AXI_port(1).AXI_B.bits.bresp
	NOC.io.s01_axi_buser      <>  io.m_AXI_port(1).AXI_B.bits.buser
	NOC.io.s01_axi_bvalid     <>  io.m_AXI_port(1).AXI_B.valid
	NOC.io.s01_axi_bready     <>  io.m_AXI_port(1).AXI_B.ready

	NOC.io.s01_axi_arid       <>  io.m_AXI_port(1).AXI_AR.bits.arid
	NOC.io.s01_axi_araddr     <>  io.m_AXI_port(1).AXI_AR.bits.araddr
	NOC.io.s01_axi_arlen      <>  io.m_AXI_port(1).AXI_AR.bits.arlen
	NOC.io.s01_axi_arsize     <>  io.m_AXI_port(1).AXI_AR.bits.arsize
	NOC.io.s01_axi_arburst    <>  io.m_AXI_port(1).AXI_AR.bits.arburst
	NOC.io.s01_axi_arlock     <>  io.m_AXI_port(1).AXI_AR.bits.arlock
	NOC.io.s01_axi_arcache    <>  io.m_AXI_port(1).AXI_AR.bits.arcache
	NOC.io.s01_axi_arprot     <>  io.m_AXI_port(1).AXI_AR.bits.arprot
	NOC.io.s01_axi_arqos      <>  io.m_AXI_port(1).AXI_AR.bits.arqos
	NOC.io.s01_axi_aruser     <>  io.m_AXI_port(1).AXI_AR.bits.aruser
	NOC.io.s01_axi_arvalid    <>  io.m_AXI_port(1).AXI_AR.valid
	NOC.io.s01_axi_arready    <>  io.m_AXI_port(1).AXI_AR.ready

	NOC.io.s01_axi_rid        <>  io.m_AXI_port(1).AXI_R.bits.rid
	NOC.io.s01_axi_rdata      <>  io.m_AXI_port(1).AXI_R.bits.rdata
	NOC.io.s01_axi_rresp      <>  io.m_AXI_port(1).AXI_R.bits.rresp
	NOC.io.s01_axi_rlast      <>  io.m_AXI_port(1).AXI_R.bits.rlast
	NOC.io.s01_axi_ruser      <>  io.m_AXI_port(1).AXI_R.bits.ruser
	NOC.io.s01_axi_rvalid     <>  io.m_AXI_port(1).AXI_R.valid
	NOC.io.s01_axi_rready     <>  io.m_AXI_port(1).AXI_R.ready



	// connect ???
	NOC.io.m00_axi_awid       <>  io.s_AXI_port(0).AXI_AW.bits.awid
	NOC.io.m00_axi_awaddr     <>  io.s_AXI_port(0).AXI_AW.bits.awaddr
	NOC.io.m00_axi_awlen      <>  io.s_AXI_port(0).AXI_AW.bits.awlen
	NOC.io.m00_axi_awsize     <>  io.s_AXI_port(0).AXI_AW.bits.awsize
	NOC.io.m00_axi_awburst    <>  io.s_AXI_port(0).AXI_AW.bits.awburst
	NOC.io.m00_axi_awlock     <>  io.s_AXI_port(0).AXI_AW.bits.awlock
	NOC.io.m00_axi_awcache    <>  io.s_AXI_port(0).AXI_AW.bits.awcache
	NOC.io.m00_axi_awprot     <>  io.s_AXI_port(0).AXI_AW.bits.awprot
	NOC.io.m00_axi_awqos      <>  io.s_AXI_port(0).AXI_AW.bits.awqos
	NOC.io.m00_axi_awuser     <>  io.s_AXI_port(0).AXI_AW.bits.awuser
	NOC.io.m00_axi_awregion   <>  io.s_AXI_port(0).AXI_AW.bits.awregion
	NOC.io.m00_axi_awvalid    <>  io.s_AXI_port(0).AXI_AW.valid
	NOC.io.m00_axi_awready    <>  io.s_AXI_port(0).AXI_AW.ready

	NOC.io.m00_axi_wdata      <>  io.s_AXI_port(0).AXI_W.bits.wdata
	NOC.io.m00_axi_wstrb      <>  io.s_AXI_port(0).AXI_W.bits.wstrb
	NOC.io.m00_axi_wlast      <>  io.s_AXI_port(0).AXI_W.bits.wlast
	NOC.io.m00_axi_wuser      <>  io.s_AXI_port(0).AXI_W.bits.wuser
	NOC.io.m00_axi_wvalid     <>  io.s_AXI_port(0).AXI_W.valid
	NOC.io.m00_axi_wready     <>  io.s_AXI_port(0).AXI_W.ready

	NOC.io.m00_axi_bid        <>  io.s_AXI_port(0).AXI_B.bits.bid
	NOC.io.m00_axi_bresp      <>  io.s_AXI_port(0).AXI_B.bits.bresp
	NOC.io.m00_axi_buser      <>  io.s_AXI_port(0).AXI_B.bits.buser
	NOC.io.m00_axi_bvalid     <>  io.s_AXI_port(0).AXI_B.valid
	NOC.io.m00_axi_bready     <>  io.s_AXI_port(0).AXI_B.ready

	NOC.io.m00_axi_arid       <>  io.s_AXI_port(0).AXI_AR.bits.arid
	NOC.io.m00_axi_araddr     <>  io.s_AXI_port(0).AXI_AR.bits.araddr
	NOC.io.m00_axi_arlen      <>  io.s_AXI_port(0).AXI_AR.bits.arlen
	NOC.io.m00_axi_arsize     <>  io.s_AXI_port(0).AXI_AR.bits.arsize
	NOC.io.m00_axi_arburst    <>  io.s_AXI_port(0).AXI_AR.bits.arburst
	NOC.io.m00_axi_arlock     <>  io.s_AXI_port(0).AXI_AR.bits.arlock
	NOC.io.m00_axi_arcache    <>  io.s_AXI_port(0).AXI_AR.bits.arcache
	NOC.io.m00_axi_arprot     <>  io.s_AXI_port(0).AXI_AR.bits.arprot
	NOC.io.m00_axi_arqos      <>  io.s_AXI_port(0).AXI_AR.bits.arqos
	NOC.io.m00_axi_arregion   <>  io.s_AXI_port(0).AXI_AR.bits.arregion
	NOC.io.m00_axi_aruser     <>  io.s_AXI_port(0).AXI_AR.bits.aruser
	NOC.io.m00_axi_arvalid    <>  io.s_AXI_port(0).AXI_AR.valid
	NOC.io.m00_axi_arready    <>  io.s_AXI_port(0).AXI_AR.ready

	NOC.io.m00_axi_rid        <>  io.s_AXI_port(0).AXI_R.bits.rid
	NOC.io.m00_axi_rdata      <>  io.s_AXI_port(0).AXI_R.bits.rdata
	NOC.io.m00_axi_rresp      <>  io.s_AXI_port(0).AXI_R.bits.rresp
	NOC.io.m00_axi_rlast      <>  io.s_AXI_port(0).AXI_R.bits.rlast
	NOC.io.m00_axi_ruser      <>  io.s_AXI_port(0).AXI_R.bits.ruser
	NOC.io.m00_axi_rvalid     <>  io.s_AXI_port(0).AXI_R.valid
	NOC.io.m00_axi_rready     <>  io.s_AXI_port(0).AXI_R.ready

	// Slave 1
	NOC.io.m01_axi_awid       <>  io.s_AXI_port(1).AXI_AW.bits.awid
	NOC.io.m01_axi_awaddr     <>  io.s_AXI_port(1).AXI_AW.bits.awaddr
	NOC.io.m01_axi_awlen      <>  io.s_AXI_port(1).AXI_AW.bits.awlen
	NOC.io.m01_axi_awsize     <>  io.s_AXI_port(1).AXI_AW.bits.awsize
	NOC.io.m01_axi_awburst    <>  io.s_AXI_port(1).AXI_AW.bits.awburst
	NOC.io.m01_axi_awlock     <>  io.s_AXI_port(1).AXI_AW.bits.awlock
	NOC.io.m01_axi_awcache    <>  io.s_AXI_port(1).AXI_AW.bits.awcache
	NOC.io.m01_axi_awprot     <>  io.s_AXI_port(1).AXI_AW.bits.awprot
	NOC.io.m01_axi_awqos      <>  io.s_AXI_port(1).AXI_AW.bits.awqos
	NOC.io.m01_axi_awuser     <>  io.s_AXI_port(1).AXI_AW.bits.awuser
	NOC.io.m01_axi_arregion   <>  io.s_AXI_port(1).AXI_AW.bits.awregion
	NOC.io.m01_axi_awvalid    <>  io.s_AXI_port(1).AXI_AW.valid
	NOC.io.m01_axi_awready    <>  io.s_AXI_port(1).AXI_AW.ready

	NOC.io.m01_axi_wdata      <>  io.s_AXI_port(1).AXI_W.bits.wdata
	NOC.io.m01_axi_wstrb      <>  io.s_AXI_port(1).AXI_W.bits.wstrb
	NOC.io.m01_axi_wlast      <>  io.s_AXI_port(1).AXI_W.bits.wlast
	NOC.io.m01_axi_wuser      <>  io.s_AXI_port(1).AXI_W.bits.wuser
	NOC.io.m01_axi_wvalid     <>  io.s_AXI_port(1).AXI_W.valid
	NOC.io.m01_axi_wready     <>  io.s_AXI_port(1).AXI_W.ready

	NOC.io.m01_axi_bid        <>  io.s_AXI_port(1).AXI_B.bits.bid
	NOC.io.m01_axi_bresp      <>  io.s_AXI_port(1).AXI_B.bits.bresp
	NOC.io.m01_axi_buser      <>  io.s_AXI_port(1).AXI_B.bits.buser
	NOC.io.m01_axi_bvalid     <>  io.s_AXI_port(1).AXI_B.valid
	NOC.io.m01_axi_bready     <>  io.s_AXI_port(1).AXI_B.ready

	NOC.io.m01_axi_arid       <>  io.s_AXI_port(1).AXI_AR.bits.arid
	NOC.io.m01_axi_araddr     <>  io.s_AXI_port(1).AXI_AR.bits.araddr
	NOC.io.m01_axi_arlen      <>  io.s_AXI_port(1).AXI_AR.bits.arlen
	NOC.io.m01_axi_arsize     <>  io.s_AXI_port(1).AXI_AR.bits.arsize
	NOC.io.m01_axi_arburst    <>  io.s_AXI_port(1).AXI_AR.bits.arburst
	NOC.io.m01_axi_arlock     <>  io.s_AXI_port(1).AXI_AR.bits.arlock
	NOC.io.m01_axi_arcache    <>  io.s_AXI_port(1).AXI_AR.bits.arcache
	NOC.io.m01_axi_arprot     <>  io.s_AXI_port(1).AXI_AR.bits.arprot
	NOC.io.m01_axi_arqos      <>  io.s_AXI_port(1).AXI_AR.bits.arqos
	NOC.io.m01_axi_aruser     <>  io.s_AXI_port(1).AXI_AR.bits.aruser
	NOC.io.m01_axi_aruser     <>  io.s_AXI_port(1).AXI_AR.bits.arregion
	NOC.io.m01_axi_arvalid    <>  io.s_AXI_port(1).AXI_AR.valid
	NOC.io.m01_axi_arready    <>  io.s_AXI_port(1).AXI_AR.ready

	NOC.io.m01_axi_rid        <>  io.s_AXI_port(1).AXI_R.bits.rid
	NOC.io.m01_axi_rdata      <>  io.s_AXI_port(1).AXI_R.bits.rdata
	NOC.io.m01_axi_rresp      <>  io.s_AXI_port(1).AXI_R.bits.rresp
	NOC.io.m01_axi_rlast      <>  io.s_AXI_port(1).AXI_R.bits.rlast
	NOC.io.m01_axi_ruser      <>  io.s_AXI_port(1).AXI_R.bits.ruser
	NOC.io.m01_axi_rvalid     <>  io.s_AXI_port(1).AXI_R.valid
	NOC.io.m01_axi_rready     <>  io.s_AXI_port(1).AXI_R.ready

			

}
