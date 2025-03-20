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

case class SDL2Params(
  address: BigInt = 0x4000
)



case object SDL2Key extends Field[Option[SDL2Params]](None)



class SDL2IO(data_width: Int = 24, address_width: Int = 17) extends Bundle {
  val clock   = Input(Clock())
  val reset   = Input(Bool())

  val input_ready = Output(Bool())
  val input_valid = Input(Bool())

  val operation   = Input(Bool())   // slightly more abstract wr_en
  val address     = Input(UInt(address_width.W))  // address for data
  val data        = Input(UInt(data_width.W)) // data

  val dump        = Input(Bool())
}


class SDL2MMIOBlackBox(address_width: Int, data_width:Int) extends BlackBox(Map("address_width" -> IntParam(address_width), "data_width" -> IntParam(data_width))) 
with HasBlackBoxResource {
  val io = IO(new SDL2IO(data_width=data_width, address_width=address_width))
  addResource("/csrc/SDL2_frame.cc")
  addResource("/vsrc/SDL2_frame.v")
}

class SDL2TL(params: SDL2Params, beatBytes: Int)(implicit p: Parameters) extends ClockSinkDomain(ClockSinkParameters())(p) {
  val device = new SimpleDevice("SDL2", Seq("ucbbar,SDL2")) 
  val node = TLRegisterNode(Seq(AddressSet(params.address, 4096-1)), device, "reg/control", beatBytes=beatBytes)

  override lazy val module = new SDL2Impl
  class SDL2Impl extends Impl {


    withClockAndReset(clock, reset) {
      // Create registers with proper widths
      val reg_operation = RegInit(0.U(1.W))
      val reg_address   = RegInit(0.U(17.W))
      val reg_data      = RegInit(0.U(24.W))

      val dump      = WireInit(0.B)
      val doorbell   = WireInit(0.B)
      
      // Instantiate the blackbox
      val impl_io = Module(new SDL2MMIOBlackBox(address_width = 17, data_width = 24)).io
      
      // Connect clock and reset to the blackbox.
      impl_io.clock := clock
      impl_io.reset := reset.asBool
      
      // Drive the blackbox inputs from the registers.
      impl_io.operation   := reg_operation
      impl_io.address     := reg_address
      impl_io.data        := reg_data
      impl_io.dump        := dump

      impl_io.input_valid := doorbell

      // Set up the regmap, making sure the widths match the registers:
      node.regmap(
        0x00 -> Seq(RegField.r(1, impl_io.input_ready)), 
        0x04 -> Seq(RegField.w(1, reg_operation)),       
        0x08 -> Seq(RegField.w(17, reg_address)),        
        0x0C -> Seq(RegField.w(24, reg_data)),           
        0x10 -> Seq(RegField.w(1, dump)),            
        0x14 -> Seq(RegField.w(1, doorbell))             
      )
    }

  }
}





trait CanHavePeripherySDL2 { this: BaseSubsystem =>
  private val portName = "SDL2"

  private val pbus = locateTLBusWrapper(PBUS)

  p(SDL2Key) match {
    case Some(params) => {
      val SDL2 = LazyModule(new SDL2TL(params, pbus.beatBytes)(p))
      SDL2.clockNode := pbus.fixedClockNode
      pbus.coupleTo(portName) { SDL2.node := TLFragmenter(pbus.beatBytes, pbus.blockBytes) := _ }
    }
    case None => // Do nothing if SDL2 is not enabled
  }
}



class WithSDL2 extends Config((site, here, up) => {
  case SDL2Key => {
    Some(SDL2Params())
  }
})
