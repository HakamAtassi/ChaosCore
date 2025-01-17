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
  val fetchWidth: Int = 4
  val fpu: Option[FPUParams] = None 
  //  fetchWidth doubled, but coreInstBytes halved, for RVC:
  val decodeWidth: Int = 4
  val retireWidth: Int = 1
  val instBits: Int = if (useCompressed) 16 else 32
  val lrscCycles: Int = 80 // worst case is 14 mispredicted branches + slop
  val traceHasWdata: Boolean = debugROB.isDefined // ooo wb, so no wdata in trace
}


/*
case class ChaosCoreParams(
  //Defaults based on Ibex "small" configuration
  //See https://github.com/lowRISC/ibex for more information
  val bootFreqHz: BigInt = BigInt(1700000000),
  val pmpEnable: Int = 0,
  val pmpGranularity: Int = 0,
  val pmpNumRegions: Int = 4,
  val mhpmCounterNum: Int = 0,
  val mhpmCounterWidth: Int = 0,
  val rv32e: Int = 0,
  val rv32m: String = "RV32MFast",
  val rv32b: String = "RV32BNone",
  val regFile: String = "RegFileFF",
  val branchTargetALU: Int = 0,
  val wbStage: Int = 0,
  val branchPredictor: Int = 0,
  val dbgHwBreakNum: Int = 1,
  val dmHaltAddr: Int = 0x1A110800,
  val dmExceptionAddr: Int = 0x1A110808
) extends CoreParams {
  val xLen = 32
  val pgLevels = 2
  val useVM: Boolean = false
  val useHypervisor: Boolean = false
  val useUser: Boolean = true
  val useSupervisor: Boolean = false
  val useDebug: Boolean = true
  val useAtomics: Boolean = false
  val useAtomicsOnlyForIO: Boolean = false
  val useCompressed: Boolean = false
  override val useVector: Boolean = false
  val useSCIE: Boolean = false
  val useRVE: Boolean = true
  val mulDiv: Option[MulDivParams] = Some(MulDivParams()) // copied from Rocket
  val fpu: Option[FPUParams] = None //floating point not supported
  val fetchWidth: Int = 1
  val decodeWidth: Int = 1
  val retireWidth: Int = 2
  val instBits: Int = if (useCompressed) 16 else 32
  val nLocalInterrupts: Int = 15
  val nPMPs: Int = 0
  val nBreakpoints: Int = 0
  val useBPWatch: Boolean = false
  val nPerfCounters: Int = 29
  val haveBasicCounters: Boolean = true
  val haveFSDirty: Boolean = false
  val misaWritable: Boolean = false
  val haveCFlush: Boolean = false
  val nL2TLBEntries: Int = 0
  val mtvecInit: Option[BigInt] = Some(BigInt(0))
  val mtvecWritable: Boolean = true
  val nL2TLBWays: Int = 1
  val lrscCycles: Int = 80
  val mcontextWidth: Int = 0
  val scontextWidth: Int = 0
  val useNMI: Boolean = true
  val nPTECacheEntries: Int = 0
  val traceHasWdata: Boolean = false
  val useConditionalZero: Boolean = false
  val useZba: Boolean = false
  val useZbb: Boolean = false
  val useZbs: Boolean = false
}
*/





/*
case class BoomCoreParams(
// DOC include start: BOOM Parameters
  pgLevels: Int = 3,
  fetchWidth: Int = 4,
  decodeWidth: Int = 1,
  numRobEntries: Int = 32,
  issueParams: Seq[IssueParams] = Seq(
    IssueParams(issueWidth=2, numEntries=8, iqType=IQ_MEM, dispatchWidth=1),
    IssueParams(issueWidth=1, numEntries=8, iqType=IQ_UNQ, dispatchWidth=1),
    IssueParams(issueWidth=1, numEntries=8, iqType=IQ_ALU, dispatchWidth=1),
    IssueParams(issueWidth=1, numEntries=8, iqType=IQ_FP , dispatchWidth=1)),
  lsuWidth: Int = 1,
  numLdqEntries: Int = 8,
  numStqEntries: Int = 8,
  numIntPhysRegisters: Int = 48,
  numFpPhysRegisters: Int = 48,
  numImmPhysRegisters: Int = 32,
  numIrfReadPorts: Int = 3,
  numFrfReadPorts: Int = 3,
  numIrfBanks: Int = 1,
  numFrfBanks: Int = 1,
  maxBrCount: Int = 4,
  numFetchBufferEntries: Int = 8,
  enableColumnALUIssue: Boolean = false,
  enableALUSingleWideDispatch: Boolean = false,
  enableBankedFPFreelist: Boolean = false,
  enablePrefetching: Boolean = false,
  enableFastLoadUse: Boolean = false,
  enableCompactingLSUDuringDispatch: Boolean = true,
  enableAgenStage: Boolean = false,
  enableStLdForwarding: Boolean = false,
  enableFastPNR: Boolean = false,
  enableSFBOpt: Boolean = true,
  enableGHistStallRepair: Boolean = true,
  enableBTBFastRepair: Boolean = true,
  enableLoadToStoreForwarding: Boolean = true,
  enableSuperscalarSnapshots: Boolean = true,
  enableSlowBTBRedirect: Boolean = false,
  enableBPDHPMs: Boolean = false,

  useAtomicsOnlyForIO: Boolean = false,
  ftq: FtqParameters = FtqParameters(nEntries=16),
  intToFpLatency: Int = 2,
  imulLatency: Int = 3,
  nPerfCounters: Int = 2,
  numRXQEntries: Int = 4,
  numRCQEntries: Int = 8,
  numDCacheBanks: Int = 1,
  dcacheSinglePorted: Boolean = false,

  nPMPs: Int = 8,
  enableICacheDelay: Boolean = false,
  icacheSinglePorted: Boolean = true,

  /* branch prediction */
  enableBranchPrediction: Boolean = true,
  branchPredictor: Function2[BranchPredictionBankResponse, Parameters, Tuple2[Seq[BranchPredictorBank], BranchPredictionBankResponse]] = ((resp_in: BranchPredictionBankResponse, p: Parameters) => (Nil, resp_in)),
  globalHistoryLength: Int = 64,
  localHistoryLength: Int = 32,
  localHistoryNSets: Int = 128,
  bpdMaxMetaLength: Int = 120,
  numRasEntries: Int = 32,
  enableRasTopRepair: Boolean = true,

  /* more stuff */
  useCompressed: Boolean = true,
  useFetchMonitor: Boolean = true,
  bootFreqHz: BigInt = 0,
  fpu: Option[FPUParams] = Some(FPUParams(sfmaLatency=4, dfmaLatency=4, divSqrt=true)),
  usingFPU: Boolean = true,
  haveBasicCounters: Boolean = true,
  misaWritable: Boolean = false,
  mtvecInit: Option[BigInt] = Some(BigInt(0)),
  mtvecWritable: Boolean = true,
  haveCFlush: Boolean = false,
  mulDiv: Option[freechips.rocketchip.rocket.MulDivParams] = Some(MulDivParams(divEarlyOut=true)),
  nBreakpoints: Int = 0, // TODO Fix with better frontend breakpoint unit
  nL2TLBEntries: Int = 512,
  nL2TLBWays: Int = 1,
  nLocalInterrupts: Int = 0,
  useNMI: Boolean = false,
  useAtomics: Boolean = true,
  useDebug: Boolean = true,
  useUser: Boolean = true,
  useSupervisor: Boolean = false,
  useVM: Boolean = true,
  useSCIE: Boolean = false,
  useRVE: Boolean = false,
  useBPWatch: Boolean = false,
  clockGate: Boolean = false,
  mcontextWidth: Int = 0,
  scontextWidth: Int = 0,
  trace: Boolean = false,

  /* debug stuff */
  enableCommitLogPrintf: Boolean = false,
  enableBranchPrintf: Boolean = false,
  enableMemtracePrintf: Boolean = false

// DOC include end: BOOM Parameters
) extends freechips.rocketchip.tile.CoreParams
{
  override def traceCustom = Some(new BoomTraceBundle)
  val xLen = 64
  val haveFSDirty = true
  val pmpGranularity: Int = 4
  val instBits: Int = 16
  val lrscCycles: Int = 80 // worst case is 14 mispredicted branches + slop
  val retireWidth = decodeWidth
  val nPTECacheEntries = 0
  val useHypervisor = false
  val jumpInFrontend: Boolean = false // unused in boom
  val traceHasWdata = trace
  val useConditionalZero = false
  val useZba = true
  val useZbb = true
  val useZbs = true

  override def customCSRs(implicit p: Parameters) = new BoomCustomCSRs
}
*/


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
  //val dcache: Option[DCacheParams] = Some(DCacheParams())
  //val icache: Option[ICacheParams] = Some(ICacheParams())
  val clockSinkParams: ClockSinkParameters = ClockSinkParameters()
  def instantiate(crossing: HierarchicalElementCrossingParamsLike, lookup: LookupByHartIdImpl)(implicit p: Parameters): ChaosCoreTile = {
    new ChaosCoreTile(this, crossing, lookup)
  }
  val baseName = name.getOrElse("ChaosCore_tile")
  val uniqueName = s"${baseName}_$tileId"
}


//abstract class InstantiableTileParams[TileType <: BaseTile] extends TileParams {
  //def instantiate(crossing: TileCrossingParamsLike, lookup: LookupByHartIdImpl)
                //(implicit p: Parameters): TileType
//}


//case class FPUParams(
  //minFLen: Int = 32,          // Minimum floating point length (no need to change)
  //fLen: Int = 64,             // Maximum floating point length, use 32 if only single precision is supported
  //divSqrt: Boolean = true,    // Div/Sqrt operation supported
  //sfmaLatency: Int = 3,       // Rocket specific: Fused multiply-add pipeline latency (single precision)
  //dfmaLatency: Int = 4        // Rocket specific: Fused multiply-add pipeline latency (double precision)
//)

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

  val core = Module(new ChaosCore(CoreParameters( 
    startPC = 0x10000.U // FIXME: this should be set based on the starting address of the bootrom automatically
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
  for(i <- 0 until 4){  // FIXME: this needs to be based on the fetchwidth parameter
      core.io.frontend_memory_response.bits.instructions(i).instruction    := (outer.icache.module.io.resp.bits.data >> (32*i).U)(31, 0) //(outer.icache.module.io.resp.bits.data)(i)
      // FIXME: idk about the rest of these params. maybe we can scrap them all together?
      core.io.frontend_memory_response.bits.fetch_PC        := RegNext(outer.icache.module.io.req.bits.addr)
      core.io.frontend_memory_response.bits.valid_bits(i)   := RegNext((outer.icache.module.io.req.bits.addr(3, 0)) <= i.U)
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

  outer.icache.module.io.s1_paddr := RegNext(core.io.frontend_memory_request.bits.addr) // delayed one cycle w.r.t. req (no vmem)
  outer.icache.module.io.s2_vaddr :=  RegNext(RegNext(core.io.frontend_memory_request.bits.addr)) //Input(UInt(vaddrBits.W)) // delayed two cycles w.r.t. req
  outer.icache.module.io.s1_kill := core.io.flush.valid //Input(Bool()) // delayed one cycle w.r.t. req
  outer.icache.module.io.s2_kill := 0.U //Input(Bool()) // delayed two cycles; prevents I$ miss emission
  outer.icache.module.io.s2_cacheable := 0.B //Input(Bool()) // should L2 cache line on a miss?
  outer.icache.module.io.s2_prefetch := 1.U //Input(Bool()) // should I$ prefetch next line on a miss?

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

  when(outer.dcache.module.io.cpu.resp.bits.cmd === M_XRD){
    core.io.backend_memory_response.bits.memory_type := memory_type_t.LOAD
  }.elsewhen(outer.dcache.module.io.cpu.resp.bits.cmd === M_XWR){
    core.io.backend_memory_response.bits.memory_type := memory_type_t.STORE
  }


  outer.dcache.module.io.cpu.s2_paddr;
  outer.dcache.module.io.cpu.s2_nack_cause_raw; // reason for nack is store-load RAW hazard (performance hint)
  outer.dcache.module.io.cpu.s2_uncached;       // advisory signal that the access is MMIO


  outer.dcache.module.io.cpu.resp.bits.idx   
  outer.dcache.module.io.cpu.resp.bits.tag   
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
