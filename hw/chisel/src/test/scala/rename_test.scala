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
class rename_spec extends AnyFreeSpec with Matchers {

  "test0" in {
    simulate(new rename(new CoreParameters())) { dut =>

        for(i <- 0 until 64){

          dut.io.decoded_fetch_packet.valid.poke(1.B)
          dut.io.renamed_decoded_fetch_packet.ready.poke(1.B)

          for(i<-0 until 4){
            dut.io.decoded_fetch_packet.bits.decoded_instruction(i).RD.poke(1.U)
            dut.io.decoded_fetch_packet.bits.decoded_instruction(i).RD_valid.poke(1.B)

            dut.io.decoded_fetch_packet.bits.decoded_instruction(i).RS1.poke(1.U)
            dut.io.decoded_fetch_packet.bits.decoded_instruction(i).RS1_valid.poke(1.B)

            dut.io.decoded_fetch_packet.bits.decoded_instruction(i).RS2.poke(1.U)
            dut.io.decoded_fetch_packet.bits.decoded_instruction(i).RS2_valid.poke(1.B)
          }

          dut.clock.step()

          for(i <- 0 until 4){
            //dut.io.renamed_decoded_fetch_packet.bits.decoded_instruction(i).RD.expect((i+1).U)
            val result_RD = dut.io.renamed_decoded_fetch_packet.bits.decoded_instruction(i).RD.peek()
            println(s"renamed RD = {$result_RD}")
          }
        }





//io_decoded_fetch_packet_bits_decoded_instruction_0_RD,
//io_decoded_fetch_packet_bits_decoded_instruction_0_RD_valid,
//io_decoded_fetch_packet_bits_decoded_instruction_0_RS1,
//io_decoded_fetch_packet_bits_decoded_instruction_0_RS2,
//io_decoded_fetch_packet_bits_decoded_instruction_0_RS1_valid,
//io_decoded_fetch_packet_bits_decoded_instruction_0_RS2_valid,


    }
  }
}