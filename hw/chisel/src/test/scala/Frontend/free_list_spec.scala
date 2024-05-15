
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

  "First 4 elements read out of free list should be 0,1,2,3" in {
    simulate(new free_list(
        fetchWidth=4,
        physicalRegCount = 96
    )) { dut =>
    
        dut.reset.poke(true.B)
        dut.clock.step()
        dut.reset.poke(false.B)
        dut.clock.step()

        //dut.io.empty.expect(0.B) // Should start off not empty
        //dut.io.full.expect(1.B) // Should start off full

        // check first 4 values
        dut.io.renamed_values(0).expect(0)
        dut.io.renamed_values(1).expect(1)
        dut.io.renamed_values(2).expect(2)
        dut.io.renamed_values(3).expect(3)

        // check first 4 valid bits
        dut.io.rename_valid(0).expect(0)
        dut.io.rename_valid(1).expect(0)
        dut.io.rename_valid(2).expect(0)
        dut.io.rename_valid(3).expect(0)


    }
  }
}

class test1 extends AnyFreeSpec with Matchers {

  "First 4 elements after read should be 4,5,6,7" in {
    simulate(new free_list(
        fetchWidth=4,
        physicalRegCount = 96
    )) { dut =>
    
        dut.reset.poke(true.B)
        dut.clock.step()
        dut.reset.poke(false.B)
        dut.clock.step()

        //dut.io.empty.expect(0.B) // Should start off not empty
        //dut.io.full.expect(1.B) // Should start off full


        dut.io.rename_valid(0).poke(true.B)
        dut.io.rename_valid(1).poke(true.B)
        dut.io.rename_valid(2).poke(true.B)
        dut.io.rename_valid(3).poke(true.B)

        dut.clock.step()

        dut.io.rename_valid(0).poke(false.B)
        dut.io.rename_valid(1).poke(false.B)
        dut.io.rename_valid(2).poke(false.B)
        dut.io.rename_valid(3).poke(false.B)


        // check first 4 values
        dut.io.renamed_values(0).expect(4)
        dut.io.renamed_values(1).expect(5)
        dut.io.renamed_values(2).expect(6)
        dut.io.renamed_values(3).expect(7)

    }
  }
}

class test2 extends AnyFreeSpec with Matchers {

  "elements after half read should update correspondingly" in {
    simulate(new free_list(
        fetchWidth=4,
        physicalRegCount = 96
    )) { dut =>
    
        dut.reset.poke(true.B)
        dut.clock.step()
        dut.reset.poke(false.B)
        dut.clock.step()

        //dut.io.empty.expect(0.B) // Should start off not empty
        //dut.io.full.expect(1.B) // Should start off full

        dut.io.rename_valid(0).poke(true.B)
        dut.io.rename_valid(1).poke(true.B)
        dut.io.rename_valid(2).poke(false.B)
        dut.io.rename_valid(3).poke(false.B)

        dut.clock.step()

        dut.io.rename_valid(0).poke(false.B)
        dut.io.rename_valid(1).poke(false.B)
        dut.io.rename_valid(2).poke(false.B)
        dut.io.rename_valid(3).poke(false.B)


        // check first 4 values
        dut.io.renamed_values(0).expect(2)
        dut.io.renamed_values(1).expect(3)

    }
  }
}



// TEST reorder

class test3 extends AnyFreeSpec with Matchers {

  "test input reorder words" in {
    simulate(new reorder_free_inputs(
        fetchWidth=4,
        physicalRegCount = 96
    )) { dut =>
    
        dut.reset.poke(true.B)
        dut.clock.step()
        dut.reset.poke(false.B)
        dut.clock.step()

        //dut.io.empty.expect(0.B) // Should start off not empty
        //dut.io.full.expect(1.B) // Should start off full

        dut.io.free_valid(0).poke(true.B)
        dut.io.free_valid(1).poke(true.B)
        dut.io.free_valid(2).poke(true.B)
        dut.io.free_valid(3).poke(true.B)

        dut.io.free_values(0).poke(7.U)
        dut.io.free_values(1).poke(5.U)
        dut.io.free_values(2).poke(3.U)
        dut.io.free_values(3).poke(1.U)


        dut.io.free_values_sorted(0).expect(7.U)
        dut.io.free_values_sorted(1).expect(5.U)
        dut.io.free_values_sorted(2).expect(3.U)
        dut.io.free_values_sorted(3).expect(1.U)




    }
  }
}