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

case class ChaosCoreTileBoundaryBufferParams(force: Boolean = false)

case class ChaosCoreParams(
  xLen: Int = 32,
  pgLevels: Int = 3, // sv39 default
  bootFreqHz: BigInt = 0,
  useVM: Boolean = false,
  useUser: Boolean = false,
  useSupervisor: Boolean = false,
  useHypervisor: Boolean = false,
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
  nPMPs: Int = 8,
  nPerfCounters: Int = 0,
  haveBasicCounters: Boolean = true,
  haveCFlush: Boolean = false,
  misaWritable: Boolean = true,
  nL2TLBEntries: Int = 0,
  nL2TLBWays: Int = 1,
  nPTECacheEntries: Int = 8,
  mtvecInit: Option[BigInt] = Some(BigInt(0)),
  mtvecWritable: Boolean = true,
  fastLoadWord: Boolean = true,
  fastLoadByte: Boolean = false,
  branchPredictionModeCSR: Boolean = false,
  clockGate: Boolean = false,
  mvendorid: Int = 0, // 0 means non-commercial implementation
  mimpid: Int = 0x20181004, // release date in BCD
  mulDiv: Option[MulDivParams] = Some(MulDivParams()),
  fpu: Option[FPUParams] = Some(FPUParams()),
  debugROB: Option[DebugROBParams] = None, // if size < 1, SW ROB, else HW ROB
  haveCease: Boolean = true, // non-standard CEASE instruction
  haveSimTimeout: Boolean = true, // add plusarg for simulation timeout
) extends CoreParams {
  val lgPauseCycles = 5
  val haveFSDirty = false
  val pmpGranularity: Int = if (useHypervisor) 4096 else 4
  val fetchWidth: Int = if (useCompressed) 2 else 1
  //  fetchWidth doubled, but coreInstBytes halved, for RVC:
  val decodeWidth: Int = fetchWidth / (if (useCompressed) 2 else 1)
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
  val core: ChaosCoreParams = ChaosCoreParams()
) extends InstantiableTileParams[ChaosCoreTile] {
  val beuAddr: Option[BigInt] = None
  val blockerCtrlAddr: Option[BigInt] = None
  val btb: Option[BTBParams] = Some(BTBParams())
  val boundaryBuffers: Option[ChaosCoreTileBoundaryBufferParams] = None
  val dcache: Option[DCacheParams] = Some(DCacheParams())
  val icache: Option[ICacheParams] = Some(ICacheParams())
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

  // TODO: Create the top module of the core and connect it with the ports in "outer"

  // If your core is in Verilog (assume your blackbox is called "MyCoreBlackbox"), instantiate it here like
  //   val core = Module(new MyCoreBlackbox(params...))
  // (as described in the blackbox tutorial) and connect appropriate signals. See the blackbox tutorial
  // (link on the top of the page) for more info.
  // You can look at https://github.com/ucb-bar/cva6-wrapper/blob/master/src/main/scala/CVA6Tile.scala
  // for a Verilog example.

  // If your core is in Chisel, you can simply instantiate the top module here like other Chisel module
  // and connect appropriate signal. You can even implement this class as your top module.
  // See https://github.com/riscv-boom/riscv-boom/blob/master/src/main/scala/common/tile.scala and
  // https://github.com/chipsalliance/rocket-chip/blob/master/src/main/scala/tile/RocketTile.scala for
  // Chisel example.

  //https://github.com/riscv-boom/riscv-boom/blob/master/src/main/scala/v4/common/tile.scala#L182


  // INIT the core
  // connect the I$ and D$



  val core = Module(new ChaosCore(CoreParameters(
    startPC = 0x10000.U
  )))

  core.io := DontCare
  dontTouch(core.io)
  outer.icache.module.io := DontCare
  dontTouch(outer.icache.module.io)
  outer.dcache.module.io := DontCare
  dontTouch(outer.dcache.module.io)

  //outer.icache.module.io.resp <> core.io.frontend_memory_response
  //outer.icache.module.io.req <> core.io.frontend_memory_request


  //val frontend_memory_request             =   Decoupled(new frontend_memory_request(coreParameters))
  //val frontend_memory_response            =   Flipped(Decoupled(new fetch_packet(coreParameters)))

  /////////////////////////////
  //// D$ BACKEND MEM ACCESS //
  /////////////////////////////
  //val backend_memory_request              =   Decoupled(new backend_memory_request(coreParameters))
  //val backend_memory_response             =   Flipped(Decoupled(new backend_memory_response(coreParameters)))



}