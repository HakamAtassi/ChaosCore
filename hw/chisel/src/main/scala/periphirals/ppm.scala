package ChaosCore

import sys.process._

import chisel3._
import chisel3.util._
import chisel3.experimental.{IntParam, BaseModule}
import freechips.rocketchip.prci._
import freechips.rocketchip.subsystem.{BaseSubsystem, PBUS}
import org.chipsalliance.cde.config.{Parameters, Field, Config}
import freechips.rocketchip.diplomacy._
import freechips.rocketchip.regmapper.{HasRegMap, RegField}
import freechips.rocketchip.tilelink._
import freechips.rocketchip.util.UIntIsOneOf

case class PPMParams(
  address: BigInt = 0x4000,
  width: Int = 32,
  useAXI4: Boolean = false,
  useBlackBox: Boolean = true
)



case object PPMKey extends Field[Option[PPMKey]](None)


class PPMIO(val data_width: Int = 24, val address_width: Int = 16) extends Bundle {
  val clock   = Input(Clock())
  val reset   = Input(Bool())
  val data    = Input(UInt(data_width.W))
  val address = Input(UInt(address_width.W))
  val wr_en   = Input(Bool())
  val dump    = Input(Bool())
}


trait HasPPMTopIO {
  def io: PPMTopIO
}

class PPMMMIOBlackBox(address_width: Int, data_width:Int) extends BlackBox(Map("address_width" -> IntParam(address_width), "data_width" -> IntParam(data_width))) 
with HasBlackBoxResource {
  val io = IO(new PPMIO(data_width=data_width, address_width=address_width))
  addResource("/vsrc/PPM.v")
}

class PPMTL(params: PPMParams, beatBytes: Int)(implicit p: Parameters) extends ClockSinkDomain(ClockSinkParameters())(p) {
  val device = new SimpleDevice("ppm", Seq("ucbbar,PPM")) 
  val node = TLRegisterNode(Seq(AddressSet(params.address, 4096-1)), device, "reg/control", beatBytes=beatBytes)

  override lazy val module = new PPMImpl
  class PPMImpl extends Impl with HasPPMTopIO {
    val io = IO(new PPMTopIO)
    withClockAndReset(clock, reset) {
        
        // How many clock cycles in a PWM cycle?
        val PPM_in = Wire(new DecoupledIO(UInt(PPMIO(data_width=8, address_width=log2Ceil(params.IMAGE_WIDTH*params.IMAGE_HEIGHT)))))
        val dump            = Reg(Bool())

        val impl_io = if (params.useBlackBox) {
            val impl = Module(new PPMMMIOBlackBox(params.width))
            impl.io
        }

        // connect clock and reset
        impl_io.clock := clock
        impl_io.reset := reset.asBool

        
        // set up regmap
        node.regmap(
            0x00 -> Seq(RegField.w(PPM_in.getWidth, PPM_in)),               // SRAM IO
            0x04 -> Seq(RegField.w(1, dump)),                               // dump contents of memory to ppm
        )


        // assign reg values to implementation

        // wr pixel info
        impl_io.address := PPM_in.bits.address
        impl_io.data := PPM_in.bits.data
        impl_io.wr_en := PPM_in.bits.wr_en

        // dump to file
        impl_io.dump := PPM_in.bits.dump

    }
  }
}



trait CanHavePeripheryPPM { this: BaseSubsystem =>
  private val portName = "ppm"

  private val pbus = locateTLBusWrapper(PBUS)

  val ppm_busy = p(PPMKey) match {
    case Some(params) => {
        
        val ppm = LazyModule(new PPMTL(params, pbus.beatBytes)(p))
        ppm.clockNode := pbus.fixedClockNode
        pbus.coupleTo(portName) { ppm.node := TLFragmenter(pbus.beatBytes, pbus.blockBytes) := _ }
        ppm

    }
    case None => None
  }
}


class WithPPM(useAXI4: Boolean = false, useBlackBox: Boolean = false) extends Config((site, here, up) => {
  case PPMKey => {
    Some(PPMParams(useAXI4 = useAXI4, useBlackBox = useBlackBox))
  }
})
