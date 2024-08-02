package ChaosCore

import chisel3._
import chisel3.experimental.BundleLiterals._
import chisel3.simulator.EphemeralSimulator._
import org.scalatest.freespec.AnyFreeSpec
import org.scalatest.matchers.must.Matchers

/**
  * This is a trivial example of how to run this Specification
  * From within sbt use:
  * {{{
  * testOnly gcd.GCDSpec
  * }}}
  * From a terminal shell use:
  * {{{
  * sbt 'testOnly gcd.GCDSpec'
  * }}}
  * Testing from mill:
  * {{{
  * mill %NAME%.test.testOnly gcd.GCDSpec
  * }}}
  */
class axi_master_slave_spec extends AnyFreeSpec with Matchers {

  "Gcd should calculate proper greatest common denominator" in {
    simulate(new AXI_master_slave(new CoreParameters(), new NOCParameters())) { dut =>
        println("TEST")
    }
  }
}