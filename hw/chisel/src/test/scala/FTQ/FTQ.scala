package ChaosCore

import tywaves.simulator._
import tywaves.simulator.ParametricSimulator._
import tywaves.simulator.simulatorSettings._
import chisel3._


// _root_ disambiguates from package chisel3.util.circt if user imports chisel3.util._
import _root_.circt.stage.ChiselStage
import org.scalatest.funspec.AnyFunSpec
import org.scalatest.matchers.should.Matchers



class FTQTest extends AnyFunSpec with Matchers {

    val parameters = Parameters()
    val addressMap = AddressMap()

    import parameters._

  describe("ParametricSimulator") {
    it("sets full") {
      simulate(new FTQ(parameters), Seq(VcdTrace, SaveWorkdirFile("gcdWorkdir"))) { dut =>

      dut.clock.step()
      dut.clock.step()

      dut.reset.poke(1.B)
      dut.clock.step()
      dut.reset.poke(0.B)
      dut.clock.step()


      dut.io.predictions.ready.expect(1.B)


      for(i <- 0 until FTQEntries){
        dut.io.predictions.valid.poke(1.B)
        dut.io.predictions.bits.fetch_PC.poke((i*16).U)
        dut.clock.step()
      }

      dut.io.predictions.valid.poke(0.B)
      dut.io.predictions.bits.fetch_PC.poke(0.U)
      dut.clock.step()


      dut.io.predictions.ready.expect(0.B)  // Should be full

      dut.io.predictions.valid.poke(1.B)
      dut.clock.step()
      dut.clock.step()
      dut.clock.step()

      dut.io.predictions.ready.expect(0.B)  // Should still be full
      dut.io.FTQ.fetch_PC.expect(0.U)

      // Free entry
      dut.io.commit.valid.poke(1.B)
      dut.io.commit.bits.fetch_PC.poke(16.U)
      dut.clock.step()
      dut.io.commit.valid.poke(0.B)
      dut.io.commit.bits.fetch_PC.poke(0.U)

      dut.io.predictions.ready.expect(0.B)


      dut.io.commit.valid.poke(1.B)
      dut.io.commit.bits.fetch_PC.poke(0.U)
      dut.clock.step()
      dut.io.commit.valid.poke(0.B)
      dut.io.commit.bits.fetch_PC.poke(0.U)

      dut.io.predictions.ready.expect(1.B)

      }
    }
  }
}

