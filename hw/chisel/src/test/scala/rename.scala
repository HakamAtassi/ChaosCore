
package ChaosCore

import tywaves.simulator._
import tywaves.simulator.ParametricSimulator._
import tywaves.simulator.simulatorSettings._
import chisel3._


// _root_ disambiguates from package chisel3.util.circt if user imports chisel3.util._
import _root_.circt.stage.ChiselStage
import org.scalatest.funspec.AnyFunSpec
import org.scalatest.matchers.should.Matchers



//class ratTest extends AnyFunSpec with Matchers {

    //val parameters = Parameters()
    //val addressMap = AddressMap()

  //describe("ParametricSimulator") {
    //it("creates checkpoints") {
      //simulate(new RAT(parameters), Seq(VcdTrace, SaveWorkdirFile("gcdWorkdir"))) { dut =>
        //for(i <- 0 until 16){
            //// fill mapping
            //// create checkpoint
            //// revert to first rat
            //// check values
            //for(j <- 0 until 32){
              //dut.io.instruction_RD(0).poke(j.U)
              //dut.io.free_list_wr_en(0).poke(1.B)
              //dut.io.free_list_RD(0).poke(j.U)
              //dut.clock.step()
            //}
            //dut.io.create_checkpoint.poke(1.B)
            //dut.clock.step()
            //dut.io.create_checkpoint.poke(0.B)
        //}
        //dut.io.checkpoints_full.expect(1.B)

        //for(i <- 0 until 16){
          //dut.io.free_checkpoint.poke(1.B)
          //dut.clock.step()
          //dut.io.checkpoints_full.expect(0.B)
        //}

        //dut.io.free_checkpoint.poke(0.B)

        //for(i <- 0 until 16){
            //// fill mapping
            //// create checkpoint
            //// revert to first rat
            //// check values
            //for(j <- 0 until 32){
              //dut.io.instruction_RD(0).poke(j.U)
              //dut.io.free_list_wr_en(0).poke(1.B)
              //dut.io.free_list_RD(0).poke(j.U)
              //dut.clock.step()
            //}
            //dut.io.create_checkpoint.poke(1.B)
            //dut.clock.step()
            //dut.io.create_checkpoint.poke(0.B)
        //}
        //dut.io.checkpoints_full.expect(1.B)

      //}
    //}
  //}

  //describe("ParametricSimulator") {
    //it("writes to the next checkpoint when actively checkpointing") {
      //simulate(new RAT(parameters), Seq(VcdTrace, SaveWorkdirFile("gcdWorkdir"))) { dut =>
          //// fill mapping
          //// create checkpoint
          //// revert to first rat
          //// check values
          //dut.clock.step()
          //dut.clock.step()

          //// write & create checkpoint
          //dut.io.create_checkpoint.poke(1.B)
          //dut.io.instruction_RD(0).poke(7.U)
          //dut.io.free_list_wr_en(0).poke(1.B)
          //dut.io.free_list_RD(0).poke(4.U)
          //dut.clock.step()
          
          //dut.io.create_checkpoint.poke(0.B)
          //dut.io.instruction_RD(0).poke(0.U)
          //dut.io.free_list_wr_en(0).poke(0.B)
          //dut.io.free_list_RD(0).poke(0.U)

          //// read 
          //dut.io.create_checkpoint.poke(0.B)
          //dut.io.instruction_RS1(0).poke(7.U)
          //dut.clock.step()
          //dut.io.RAT_RS1(0).expect(4.U)

          //// restore checkpoint
          //dut.io.restore_checkpoint.poke(1.B)
          //dut.io.restore_checkpoint_value.poke(0.U)
          //dut.clock.step()
          //dut.io.restore_checkpoint.poke(0.B)
          //dut.io.restore_checkpoint_value.poke(0.U)

          //dut.clock.step()

          //// read first RAT
          //dut.io.create_checkpoint.poke(0.B)
          //dut.io.instruction_RS1(0).poke(7.U)
          //dut.clock.step()
          //dut.io.RAT_RS1(0).expect(0.U)


      //}
    //}
  //}

  //describe("ParametricSimulator") {
    //it("checkpoints correctly between 15->0") {
      //simulate(new RAT(parameters), Seq(VcdTrace, SaveWorkdirFile("gcdWorkdir"))) { dut =>
          //// fill mapping
          //// create checkpoint
          //// revert to first rat
          //// check values
          //dut.clock.step()
          //dut.clock.step()

          //// write & create checkpoint
          //dut.io.create_checkpoint.poke(1.B)
          //dut.clock.step()
          //dut.io.create_checkpoint.poke(0.B)

          //// Free RAT 0
          //dut.io.free_checkpoint.poke(1.B)
          //dut.clock.step()
          //dut.io.free_checkpoint.poke(0.B)


          ////
          //for(i <- 0 until 14){
            //dut.io.create_checkpoint.poke(1.B)
            //dut.clock.step()
          //}

          //dut.io.create_checkpoint.poke(0.B)
          //dut.io.checkpoints_full.expect(0.B)

          //// write stuff to RAT 15
          //for(j <- 0 until 32){
            //dut.io.instruction_RD(0).poke(j.U)
            //dut.io.free_list_wr_en(0).poke(1.B)
            //dut.io.free_list_RD(0).poke(j.U)
            //dut.clock.step()
          //}

          //// create another checkpoint

          //dut.io.create_checkpoint.poke(1.B)
          //dut.clock.step()
          //dut.io.create_checkpoint.poke(0.B)

          //dut.clock.step()
          //dut.clock.step()


          //dut.io.checkpoints_full.expect(1.B)

          //dut.io.instruction_RS1(0).poke(7.U)
          //dut.clock.step()
          //dut.io.RAT_RS1(0).expect(7.U)


          //dut.io.instruction_RS1(0).poke(31.U)
          //dut.clock.step()
          //dut.io.RAT_RS1(0).expect(31.U)



      //}
    //}
  //}

  //// TEST x0 stuff
//}


class freeListSpec extends AnyFunSpec with Matchers {

    val parameters = Parameters()
    val addressMap = AddressMap()

  describe("ParametricSimulator") {
    it("outputs correct RDs") {
      simulate(new free_list(parameters), Seq(VcdTrace, SaveWorkdirFile("gcdWorkdir"))) { dut =>
          // fill mapping
          // create checkpoint
          // revert to first rat
          // check values
          dut.clock.step()
          dut.clock.step()

          dut.reset.poke(1.B)          
          dut.clock.step()
          dut.reset.poke(0.B)          
          dut.clock.step()


          dut.io.rename_valid(0).poke(1.B)
          dut.io.rename_valid(1).poke(1.B)
          dut.io.rename_valid(2).poke(1.B)
          dut.io.rename_valid(3).poke(1.B)

          dut.io.renamed_values(0).expect(1.U)
          dut.io.renamed_values(1).expect(2.U)
          dut.io.renamed_values(2).expect(3.U)
          dut.io.renamed_values(3).expect(4.U)


          dut.clock.step()

          dut.io.rename_valid(0).poke(1.B)
          dut.io.rename_valid(1).poke(0.B)
          dut.io.rename_valid(2).poke(1.B)
          dut.io.rename_valid(3).poke(1.B)

          dut.io.renamed_values(0).expect(5.U)
          dut.io.renamed_values(1).expect(0.U)
          dut.io.renamed_values(2).expect(6.U)
          dut.io.renamed_values(3).expect(7.U)

          dut.clock.step()

          dut.io.rename_valid(0).poke(0.B)
          dut.io.rename_valid(1).poke(0.B)
          dut.io.rename_valid(2).poke(0.B)
          dut.io.rename_valid(3).poke(0.B)

          dut.io.renamed_values(0).expect(0.U)
          dut.io.renamed_values(1).expect(0.U)
          dut.io.renamed_values(2).expect(0.U)
          dut.io.renamed_values(3).expect(0.U)

          dut.clock.step()

          dut.io.rename_valid(0).poke(0.B)
          dut.io.rename_valid(1).poke(0.B)
          dut.io.rename_valid(2).poke(0.B)
          dut.io.rename_valid(3).poke(1.B)

          dut.io.renamed_values(0).expect(0.U)
          dut.io.renamed_values(1).expect(0.U)
          dut.io.renamed_values(2).expect(0.U)
          dut.io.renamed_values(3).expect(8.U)

          dut.clock.step()
      }
    }

    it("assigns full empty correctly") {
      simulate(new free_list(parameters), Seq(VcdTrace, SaveWorkdirFile("gcdWorkdir"))) { dut =>
          // fill mapping
          // create checkpoint
          // revert to first rat
          // check values
          dut.clock.step()
          dut.clock.step()

          dut.reset.poke(1.B)          
          dut.clock.step()
          dut.reset.poke(0.B)          
          dut.clock.step()

          dut.clock.step()
          dut.clock.step()

          dut.io.can_allocate.expect(1.B)

          for(i <- 0 until 100){
            dut.io.rename_valid(0).poke(1.B)
            dut.clock.step()
          }

          dut.io.rename_valid(0).poke(0.B)

          dut.io.can_allocate.expect(0.B)
          dut.io.can_reallocate.expect(1.B)

          for(i <- 0 until 100){
            dut.io.commit.valid.poke(1.B)
            dut.io.commit.bits.RD(0).poke(1.U)
            dut.io.commit.bits.RD_valid(0).poke(1.B)
            dut.clock.step()
          }


          dut.io.commit.valid.poke(0.B)
          dut.io.commit.bits.RD(0).poke(0.U)
          dut.io.commit.bits.RD_valid(0).poke(0.B)

          dut.io.can_allocate.expect(1.B)
          dut.io.can_reallocate.expect(0.B)

          for(i <- 0 until 100){
            dut.io.rename_valid(0).poke(1.B)
            dut.clock.step()
          }

            dut.io.rename_valid(0).poke(0.B)




      }
    }


  }

}
