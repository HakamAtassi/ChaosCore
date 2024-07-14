package ChaosCore

import chisel3._

import chisel3._
import chisel3.experimental.BundleLiterals._
import chisel3.simulator.EphemeralSimulator._
import org.scalatest.freespec.AnyFreeSpec
import org.scalatest.matchers.must.Matchers


class MOBSpec extends AnyFreeSpec with Matchers {

    val parameters = Parameters()
    val addressMap = AddressMap()
    import parameters._

  "MOB should reserve entries" in {
    simulate(new MOB(parameters)) { dut =>

        dut.reset.poke(1.B)
        dut.clock.step()
        dut.reset.poke(0.B)
        dut.clock.step()

        for(i <- 0 until fetchWidth){
            println(dut.io.reserved_pointers(i).valid.peek())
        }


        dut.clock.step()
        dut.clock.step()



    }
  }
}