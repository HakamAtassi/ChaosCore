
// See README.md for license details.

package ChaosCore

import chisel3._
import chisel3.experimental.BundleLiterals._
import chisel3.simulator.EphemeralSimulator._
import org.scalatest.freespec.AnyFreeSpec
import org.scalatest.matchers.must.Matchers

// run with 
// sbt "testOnly ChaosCore.<test name>"
class test0 extends AnyFreeSpec with Matchers {
  import Parameters._

  val parameters = Parameters()
  val addressMap = AddressMap()

  "First 4 elements read out of free list should be 0,1,2,3" in {
    simulate(new free_list(parameters)) { dut =>
    
        dut.reset.poke(true.B)
        dut.clock.step()
        dut.reset.poke(false.B)
        dut.clock.step()



    }
  }
}

