//******************************************************************************
// Copyright (c) 2019 - 2019, The Regents of the University of California (Regents).
// All Rights Reserved. See LICENSE and LICENSE.SiFive for license details.
//------------------------------------------------------------------------------

//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
// CVA6 Tile Wrapper
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------

package ChaosCore

import chisel3._
import chisel3.util._
import chisel3.experimental.{IntParam, StringParam}

import scala.collection.mutable.{ListBuffer}

import org.chipsalliance.cde.config._
import freechips.rocketchip.subsystem._
import freechips.rocketchip.devices.tilelink._
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.prci._
import freechips.rocketchip.rocket._
import freechips.rocketchip.subsystem.{RocketCrossingParams}
import freechips.rocketchip.tilelink._
import freechips.rocketchip.interrupts._
import freechips.rocketchip.util._
import freechips.rocketchip.tile._
import freechips.rocketchip.amba.axi4._
import _root_.ChaosCore.memory_type_t.LOAD

case class ChaosCoreTileBoundaryBufferParams(force: Boolean = false)

case class ChaosCoreParams(
  pgLevels: Int = 2, // sv39 default
  bootFreqHz: BigInt = 0,
  useDebug: Boolean = true,
  useAtomics: Boolean = false,
  useAtomicsOnlyForIO: Boolean = false,
  useCompressed: Boolean = false,
  useRVE: Boolean = false,
  useConditionalZero: Boolean = false,
  useZba: Boolean = false,
  useZbb: Boolean = false,
  useZbs: Boolean = false,
  nLocalInterrupts: Int = 0,
  useNMI: Boolean = false,
  nBreakpoints: Int = 1,
  useBPWatch: Boolean = false,
  mcontextWidth: Int = 0,
  scontextWidth: Int = 0,
  nPMPs: Int = 0,
  nPerfCounters: Int = 0,
  haveBasicCounters: Boolean = true,
  haveCFlush: Boolean = false,
  misaWritable: Boolean = true,
  nL2TLBEntries: Int = 0,
  nL2TLBWays: Int = 0,
  nPTECacheEntries: Int = 0,
  mtvecInit: Option[BigInt] = Some(BigInt(0)),
  mtvecWritable: Boolean = true,
  fastLoadWord: Boolean = true,
  fastLoadByte: Boolean = false,
  branchPredictionModeCSR: Boolean = false,
  clockGate: Boolean = false,
  mvendorid: Int = 0, // 0 means non-commercial implementation
  mimpid: Int = 0x20181004, // release date in BCD
  mulDiv: Option[MulDivParams] = Some(MulDivParams()),
  debugROB: Option[DebugROBParams] = None, // if size < 1, SW ROB, else HW ROB
  haveCease: Boolean = true, // non-standard CEASE instruction
  haveSimTimeout: Boolean = true, // add plusarg for simulation timeout

  fetchWidth: Int = 1,

) extends CoreParams {

  //override def vMemDataBits: Int = 0

  val useVM: Boolean = false
  val useUser: Boolean = false
  val useSupervisor: Boolean = false
  val useHypervisor: Boolean = false
  val xLen: Int = 32
  val lgPauseCycles = 5
  val haveFSDirty = false
  val pmpGranularity: Int = 0
  val fpu: Option[FPUParams] = None 
  val decodeWidth: Int = 4
  val retireWidth: Int = 1
  val instBits: Int = if (useCompressed) 16 else 32
  val lrscCycles: Int = 80 // worst case is 14 mispredicted branches + slop
  val traceHasWdata: Boolean = debugROB.isDefined // ooo wb, so no wdata in trace

}


case class ChaosCoreAttachParams(
  tileParams: ChaosCoreTileParams,
  crossingParams: RocketCrossingParams,
  icache: Option[ICacheParams] = Some(ICacheParams()),
  dcache: Option[DCacheParams] = Some(DCacheParams()),
) extends CanAttachTile {
  type TileType = ChaosCoreTile
  val lookup = PriorityMuxHartIdFromSeq(Seq(tileParams))
}


case class ChaosCoreTileParams(
  name: Option[String] = Some("ChaosCore_tile"),
  tileId: Int = 0,
  trace: Boolean = false,
  core: ChaosCoreParams = ChaosCoreParams(),
  icache: Option[ICacheParams] = Some(ICacheParams()),
  dcache: Option[DCacheParams] = Some(DCacheParams())
) extends InstantiableTileParams[ChaosCoreTile] {
  val beuAddr: Option[BigInt] = None
  val blockerCtrlAddr: Option[BigInt] = None
  val btb: Option[BTBParams] = Some(BTBParams())
  val boundaryBuffers: Option[ChaosCoreTileBoundaryBufferParams] = None
  require(icache.isDefined)
  require(dcache.isDefined)
  val clockSinkParams: ClockSinkParameters = ClockSinkParameters()
  def instantiate(crossing: HierarchicalElementCrossingParamsLike, lookup: LookupByHartIdImpl)(implicit p: Parameters): ChaosCoreTile = {
    new ChaosCoreTile(this, crossing, lookup)
  }
  val baseName = name.getOrElse("ChaosCore_tile")
  val uniqueName = s"${baseName}_$tileId"
}

class ChaosCoreTile(
  val chaosParams: ChaosCoreTileParams,
  crossing: ClockCrossingType,
  lookup: LookupByHartIdImpl,
  q: Parameters)
  extends BaseTile(chaosParams, crossing, lookup, q)
  with SinksExternalInterrupts
  with SourcesExternalNotifications
{

  //////////////////
  //// INTERRUPTS //
  //////////////////

  def connectChaosCoreInterrupts(debug: Bool, msip: Bool, mtip: Bool, meip: Bool) {
    val (interrupts, _) = intSinkNode.in(0)
    debug := interrupts(0)
    msip := interrupts(1)
    mtip := interrupts(2)
    meip := interrupts(3)
  }

  // Private constructor ensures altered LazyModule.p is used implicitly
  def this(params: ChaosCoreTileParams, crossing: HierarchicalElementCrossingParamsLike, lookup: LookupByHartIdImpl)(implicit p: Parameters) =
    this(params, crossing.crossingType, lookup, p)

  // Require TileLink nodes
  val intOutwardNode = chaosParams.beuAddr map { _ => IntIdentityNode() }
  val masterNode = visibilityNode
  val slaveNode = TLIdentityNode()

  /////////////////
  // ICACHE INIT //
  /////////////////

  val icache = LazyModule(new ICache(tileParams.icache.get, 0))

  //icache.resetVectorSinkNode := resetVectorNexusNode
  tlMasterXbar.node := TLWidthWidget(tileParams.icache.get.rowBits/8) := icache.masterNode
  icache.hartIdSinkNodeOpt.foreach { _ := hartIdNexusNode }
  icache.mmioAddressPrefixSinkNodeOpt.foreach { _ := mmioAddressPrefixNexusNode }


  /////////////////
  // DCACHE INIT //
  /////////////////

  lazy val dcache: HellaCache = LazyModule(p(BuildHellaCache)(this)(p))
  var nDCachePorts = 0


  tlMasterXbar.node := TLWidthWidget(tileParams.dcache.get.rowBits/8) := dcache.node
  dcache.hartIdSinkNodeOpt.map { _ := hartIdNexusNode }
  dcache.mmioAddressPrefixSinkNodeOpt.map { _ := mmioAddressPrefixNexusNode }
  InModuleBody {
    dcache.module.io.tlb_port := DontCare
  }

  val dtim_adapter = tileParams.dcache.flatMap { d => d.scratch.map { s =>
    LazyModule(new ScratchpadSlavePort(AddressSet.misaligned(s, d.dataScratchpadBytes), lazyCoreParamsView.coreDataBytes, tileParams.core.useAtomics && !tileParams.core.useAtomicsOnlyForIO))
  }}
  dtim_adapter.foreach(lm => connectTLSlave(lm.node, lm.node.portParams.head.beatBytes))

  val bus_error_unit = chaosParams.beuAddr map { a =>
    val beu = LazyModule(new BusErrorUnit(new L1BusErrors, BusErrorUnitParams(a), xLen/8))
    intOutwardNode.get := beu.intNode
    connectTLSlave(beu.node, xBytes)
    beu
  }

  val tile_master_blocker =
    tileParams.blockerCtrlAddr
      .map(BasicBusBlockerParams(_, xBytes, masterPortBeatBytes, deadlock = true))
      .map(bp => LazyModule(new BasicBusBlocker(bp)))

  tile_master_blocker.foreach(lm => connectTLSlave(lm.controlNode, xBytes))

  // TODO: this doesn't block other masters, e.g. RoCCs
  tlOtherMastersNode := tile_master_blocker.map { _.node := tlMasterXbar.node } getOrElse { tlMasterXbar.node }
  masterNode :=* tlOtherMastersNode
  DisableMonitors { implicit p => tlSlaveXbar.node :*= slaveNode }

  nDCachePorts += 1

  val dtimProperty = dtim_adapter.map(d => Map(
    "sifive,dtim" -> d.device.asProperty)).getOrElse(Nil)

  val itimProperty = icache.itimProperty.toSeq.flatMap(p => Map("sifive,itim" -> p))

  val beuProperty = bus_error_unit.map(d => Map(
          "sifive,buserror" -> d.device.asProperty)).getOrElse(Nil)

  // Required entry of CPU device in the device tree for interrupt purpose
  val cpuDevice: SimpleDevice = new SimpleDevice("cpu", Seq("sifive,rocket0", "riscv")) {
    override def parent = Some(ResourceAnchors.cpus)
    override def describe(resources: ResourceBindings): Description = {
      val Description(name, mapping) = super.describe(resources)
      Description(name, mapping ++ cpuProperties ++ nextLevelCacheProperty
                  ++ tileProperties ++ dtimProperty ++ itimProperty ++ beuProperty)
    }
  }

  ResourceBinding {
    Resource(cpuDevice, "reg").bind(ResourceAddress(tileId))
  }

  // Implementation class (See below)
  override lazy val module = new ChaosCoreTileModuleImp(this)

  override def makeMasterBoundaryBuffers(crossing: ClockCrossingType)(implicit p: Parameters) = (chaosParams.boundaryBuffers, crossing) match {
    case (Some(ChaosCoreTileBoundaryBufferParams(true )), _)                   => TLBuffer()
    case (Some(ChaosCoreTileBoundaryBufferParams(false)), _: RationalCrossing) => TLBuffer(BufferParams.none, BufferParams.flow, BufferParams.none, BufferParams.flow, BufferParams(1))
    case _ => TLBuffer(BufferParams.none)
  }

  override def makeSlaveBoundaryBuffers(crossing: ClockCrossingType)(implicit p: Parameters) = (chaosParams.boundaryBuffers, crossing) match {
    case (Some(ChaosCoreTileBoundaryBufferParams(true )), _)                   => TLBuffer()
    case (Some(ChaosCoreTileBoundaryBufferParams(false)), _: RationalCrossing) => TLBuffer(BufferParams.flow, BufferParams.none, BufferParams.none, BufferParams.none, BufferParams.none)
    case _ => TLBuffer(BufferParams.none)
  }



}



class ChaosCoreTileModuleImp(outer: ChaosCoreTile) extends BaseTileModuleImp(outer){
  // annotate the parameters
  Annotated.params(this, outer.chaosParams)

  import outer.chaosParams.core._

  val core = Module(new ChaosCore(CoreParameters( 
    // Override parameters from Chipyard params to ChaosCore params
    startPC = 0x10000.U,
    fetchWidth = outer.chaosParams.core.fetchWidth,

//    DEBUG = outer.chaosParams.core.DEBUG, 
    //coreConfig = outer.chaosParams.core.coreConfig,
    //hartID = outer.chaosParams.core.hartID, 
    //GHRWidth = outer.chaosParams.core.GHRWidth,
    //RASEntries = outer.chaosParams.core.RASEntries,
    //BTBEntries = outer.chaosParams.core.BTBEntries,
    //FTQEntries = outer.chaosParams.core.FTQEntries,
    //ROBEntries = outer.chaosParams.core.ROBEntries,
    //architecturalRegCount = outer.chaosParams.core.architecturalRegCount,
    //RATCheckpointCount = outer.chaosParams.core.RATCheckpointCount,
    //physicalRegCount = outer.chaosParams.core.physicalRegCount,
    //RSEntries = outer.chaosParams.core.RSEntries,
    //ALUportCount = outer.chaosParams.core.ALUportCount,
    //MEMportCount = outer.chaosParams.core.MEMportCount,
    //FPUportCount = outer.chaosParams.core.FPUportCount,
    //ALUStages = outer.chaosParams.core.ALUStages,
    //MOBWBPortCount = outer.chaosParams.core.MOBWBPortCount,
    //instruction_queue_depth = outer.chaosParams.core.instruction_queue_depth,
    //speculative = outer.chaosParams.core.speculative,
    //MOBEntries = outer.chaosParams.core.MOBEntries,
    //IQEntries = outer.chaosParams.core.IQEntries,
    //FUParamSeq = outer.chaosParams.core.FUParamSeq
  )))


  core.io := DontCare
  //outer.icache.module.io := DontCare
  //outer.dcache.module.io := DontCare
  dontTouch(core.io)
  dontTouch(outer.icache.module.io)
  dontTouch(outer.dcache.module.io)
  dontTouch(outer.dcache.module.io)

  ////////////////
  // I$ CONNECT //
  ////////////////

  // connect I$ resp
  for(i <- 0 until fetchWidth){  // FIXME: this needs to be based on the fetchwidth parameter
    core.io.frontend_memory_response.bits.instructions(i).instruction    := (outer.icache.module.io.resp.bits.data >> (32*i).U)(31, 0)
    core.io.frontend_memory_response.bits.fetch_PC        := RegNext(outer.icache.module.io.req.bits.addr)
    core.io.frontend_memory_response.bits.valid_bits(i)   := RegNext((outer.icache.module.io.req.bits.addr(log2Ceil(fetchWidth*4), 0)) <= i.U)
    core.io.frontend_memory_response.bits.prediction      := DontCare//0.U
    core.io.frontend_memory_response.bits.GHR             := DontCare//0.U
    core.io.frontend_memory_response.bits.NEXT            := DontCare//0.U
    core.io.frontend_memory_response.bits.TOS             := DontCare//0.U
  }


  // connect I$ request 
  outer.icache.module.io.req.bits.addr  := core.io.frontend_memory_request.bits.addr
  outer.icache.module.io.req.valid      := core.io.frontend_memory_request.valid
  outer.icache.module.io.req.ready      <> core.io.frontend_memory_request.ready

  core.io.frontend_memory_response.valid      := outer.icache.module.io.resp.valid

  outer.icache.module.io.s1_paddr := RegNext(core.io.frontend_memory_request.bits.addr)           // delayed one cycle w.r.t. req (no vmem)
  outer.icache.module.io.s2_vaddr :=  RegNext(RegNext(core.io.frontend_memory_request.bits.addr)) // delayed two cycles w.r.t. req
  outer.icache.module.io.s1_kill := core.io.flush.valid                                           // delayed one cycle w.r.t. req
  outer.icache.module.io.s2_kill := 0.U                                                           // delayed two cycles; prevents I$ miss emission
  outer.icache.module.io.s2_cacheable := 0.B                                                      // should L2 cache line on a miss?
  outer.icache.module.io.s2_prefetch := 1.U                                                       // should I$ prefetch next line on a miss?

  outer.icache.module.io.invalidate := 0.B // flush L1 cache from CPU. IIRC, SFENCE.I

  ///** enable clock. */
  outer.icache.module.io.clock_enabled := 1.B

  ///** I$ miss or ITIM access will still enable clock even [[ICache]] is asked to be gated. */
  //outer.icache.module.io.keep_clock_enabled = Output(Bool())
  //outer.icache.module.io.errors = new ICacheErrors
  //val perf = Output(new ICachePerfEvents()) // performance counting





  ////////////////
  // D$ CONNECT //
  ////////////////

  // see https://github.com/chipsalliance/rocket-chip/blob/2fe6bb5e9c23360cac8297bb26512e4ca614f67b/src/main/scala/rocket/HellaCache.scala#L110

  outer.dcache.module.io.ptw := DontCare  // no vmem
  
  // CACHE REQ //
  outer.dcache.module.io.cpu.req.valid       := core.io.backend_memory_request.valid
  core.io.backend_memory_request.ready       := outer.dcache.module.io.cpu.req.ready

  // CACHE REQ - MEM OP //
  outer.dcache.module.io.cpu.req.bits.addr   := core.io.backend_memory_request.bits.addr
  //outer.dcache.module.io.cpu.req.bits.idx       := 0.U // something for virtual memory?
  outer.dcache.module.io.cpu.req.bits.tag    := core.io.backend_memory_request.bits.MOB_index // request ID
  outer.dcache.module.io.cpu.req.bits.cmd    := Mux(core.io.backend_memory_request.bits.memory_type === memory_type_t.LOAD, M_XRD, M_XWR)
  
  outer.dcache.module.io.cpu.req.bits.size   := core.io.backend_memory_request.bits.access_width.asUInt

  outer.dcache.module.io.cpu.req.bits.signed := core.io.backend_memory_request.bits.mem_signed //Bool()
  outer.dcache.module.io.cpu.req.bits.dprv   := "b11".U // privilege
  outer.dcache.module.io.cpu.req.bits.dv     := 0.B 

  outer.dcache.module.io.cpu.req.bits.data   := core.io.backend_memory_request.bits.data
  outer.dcache.module.io.cpu.req.bits.mask   := DontCare

  //outer.dcache.module.io.cpu.req.bits.idx    := 0.B



  // CACHE REQ - INTERNAL //
  outer.dcache.module.io.cpu.req.bits.phys      := 0.B
  outer.dcache.module.io.cpu.req.bits.no_xcpt   := 0.B //core.io.backend_memory_request.valid
  outer.dcache.module.io.cpu.req.bits.no_resp   := 0.B
  outer.dcache.module.io.cpu.req.bits.no_alloc  := 0.B

  // CACHE REQ - DATA //
  outer.dcache.module.io.cpu.s1_data.data    := RegNext(core.io.backend_memory_request.bits.data)
  outer.dcache.module.io.cpu.s1_data.mask    := DontCare

  // CACHE REQ - MISC //
  outer.dcache.module.io.cpu.s1_kill            := 0.B //core.io.flush.valid // kill previous cycle's req
  outer.dcache.module.io.cpu.s2_kill            := 0.B //core.io.flush.valid // kill req from two cycles ago


  // CACHE RESP //
  // Only responses are NACKS or read resp (filter out store resps)
  core.io.backend_memory_response.valid     :=  0.U
  core.io.backend_memory_response.bits.addr := 0.U
  core.io.backend_memory_response.bits.MOB_index := 0.U
  core.io.backend_memory_response.bits.nack := 0.B

  when(outer.dcache.module.io.cpu.s2_nack || (outer.dcache.module.io.cpu.resp.bits.cmd === M_XRD)){
    core.io.backend_memory_response.valid     := outer.dcache.module.io.cpu.resp.valid
    core.io.backend_memory_response.bits.addr := outer.dcache.module.io.cpu.resp.bits.addr  
    core.io.backend_memory_response.bits.MOB_index := outer.dcache.module.io.cpu.resp.bits.tag
    core.io.backend_memory_response.bits.nack := outer.dcache.module.io.cpu.s2_nack

  }


  outer.dcache.module.io.cpu.s2_paddr;
  outer.dcache.module.io.cpu.s2_nack_cause_raw; // reason for nack is store-load RAW hazard (performance hint)
  outer.dcache.module.io.cpu.s2_uncached;       // advisory signal that the access is MMIO


  outer.dcache.module.io.cpu.resp.bits.idx   
  outer.dcache.module.io.cpu.resp.bits.tag   
  outer.dcache.module.io.cpu.resp.bits.cmd   
  outer.dcache.module.io.cpu.resp.bits.size  
  outer.dcache.module.io.cpu.resp.bits.signed
  outer.dcache.module.io.cpu.resp.bits.dprv  
  outer.dcache.module.io.cpu.resp.bits.dv    

  core.io.backend_memory_response.bits.data := outer.dcache.module.io.cpu.resp.bits.data
  outer.dcache.module.io.cpu.resp.bits.mask

  outer.dcache.module.io.cpu.resp.bits.replay 
  outer.dcache.module.io.cpu.resp.bits.has_data
  outer.dcache.module.io.cpu.resp.bits.data_word_bypass
  outer.dcache.module.io.cpu.resp.bits.data_raw 
  outer.dcache.module.io.cpu.resp.bits.store_data 

  // CACHE RESP - MISC //
  outer.dcache.module.io.cpu.replay_next  
  outer.dcache.module.io.cpu.s2_xcpt      
  outer.dcache.module.io.cpu.s2_gpa       
  outer.dcache.module.io.cpu.s2_gpa_is_pte
  outer.dcache.module.io.cpu.uncached_resp
  outer.dcache.module.io.cpu.ordered      
  outer.dcache.module.io.cpu.store_pending
  outer.dcache.module.io.cpu.perf         
  


  // CLOCKING
  outer.dcache.module.io.cpu.keep_clock_enabled := 1.B // is D$ currently being clocked?


  ////////////////
  // INTERRUPTS //
  ////////////////

  outer.connectChaosCoreInterrupts(core.io.debug_req_i, core.io.irq_software_i, core.io.irq_timer_i, core.io.irq_external_i)




}
