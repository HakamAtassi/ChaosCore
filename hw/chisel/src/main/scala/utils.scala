/* ------------------------------------------------------------------------------------
* Filename: utils.scala
* Author: Hakam Atassi
* Date: Apr 23 2024
* Description: An unorgianized file with various utility functions
* License: MIT
*
* Copyright (c) 2024 by Hakam Atassi
*
* Permission is hereby granted, free of charge, to any person obtaining a copy
* of this software and associated documentation files (the "Software"), to deal
* in the Software without restriction, including without limitation the rights
* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
* copies of the Software, and to permit persons to whom the Software is
* furnished to do so, subject to the following conditions:
* 
* The above copyright notice and this permission notice shall be included in all
* copies or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
* SOFTWARE.
* ------------------------------------------------------------------------------------ 
*/

package ChaosCore

import chisel3._
import circt.stage.ChiselStage
import chisel3.util._
import java.rmi.server.UID


// a variable priority encoder
object SelectFirstN
{
  def apply(in: UInt, n: Int) = {
    val sels = Wire(Vec(n, UInt(in.getWidth.W)))
    var mask = in

    dontTouch(sels)

    for (i <- 0 until n) {
      sels(i) := PriorityEncoderOH(mask)
      mask = mask & ~sels(i)
    }

    sels
  }
}

object Thermometor
{
  // 0 => 0b0
  // 1 => 0b1
  // 2 => 0b11
  // 3 => 0b111
  // 4 => 0b1111
  // etc...
  def apply(in: UInt, max:Int)={
      Mux1H(Seq.tabulate(max+1)(i => (in === i.U) -> ((1.U << i ) - 1.U)))
  }
}


object getPortCount
{
  // Returns total number of ports across all reservations stations
  def apply(parameters:Parameters) ={
    import parameters._

    var portCount = ALUportCount
    //ALUportCount // Defined in config
    //MEMportCount // Defined in config 
    //FPUportCount // Defined in config 

    portCount += MEMportCount

    if(coreConfig.contains("F")) portCount += FPUportCount
    //TODO: add the rest...

    portCount
  }

}

object findMispredictionCommit {
  def apply(commits: Seq[commit], parameters:Parameters): commit = {
    import parameters._
    var mispredictionCommit = new commit(parameters) // Assuming `parameters` is available in scope

    for (i <- commitWidth - 1 to 0 by -1) {
      when(commits(i).is_misprediction) {
        mispredictionCommit = commits(i)
      }
    }

    mispredictionCommit
  }
}

object helperFunctions {
    def getBTBTagBits(BTBSize: Int = 4096, fetchWidth:Int=4): Int = (32 - log2Ceil(BTBSize) - 2 - log2Ceil(fetchWidth))

    // Function to shift UInt32 signal down by "getBTBTagBits"
    def shiftDownByTagBits(input: UInt, BTBSize: Int = 4096, fetchWidth:Int=4): UInt = {
        val shiftAmount = 32-getBTBTagBits(BTBSize, fetchWidth)
        input >> shiftAmount
    }

    def getImm(instruction:UInt): UInt = {

        val opcode = instruction(6,0)

        val U      = (opcode === "b0010111".U) || (opcode === "b0110111".U)
        val J      = (opcode === "b1101111".U)
        val B      = (opcode === "b1100011".U)
        val S      = (opcode === "b0100011".U)
        val R      = (opcode === "b0110011".U)
        val I      = (opcode === "b0010011".U) || (opcode === "b0000011".U) || (opcode === "b1100111".U)

        val imm = Wire(UInt(32.W))
        imm := 0.U

        when(B) {
            val imm_12      = instruction(31)
            val imm_10_5    = instruction(30, 25)
            val imm_4_1     = instruction(11, 8)
            val imm_11      = instruction(7)

            imm := Cat(imm_12, imm_11, imm_10_5, imm_4_1, 0.U(1.W)).asSInt.asUInt
        }.elsewhen (J) {
            val imm_20    = instruction(31)
            val imm_19_12 = instruction(19, 12)
            val imm_11    = instruction(20)
            val imm_10_1  = instruction(30,21)

            imm := Cat(imm_20, imm_19_12, imm_11, imm_10_1, 0.U(1.W)).asSInt.asUInt
        }.elsewhen (I) {
            val imm_11_0      = instruction(31, 20)

            imm := imm_11_0.asSInt.asUInt
        }.elsewhen(S){
            val imm_11_5      = instruction(31, 25)
            val imm_4_0       = instruction(11, 7)

            imm := Cat(imm_11_5, imm_4_0).asSInt.asUInt
        }.elsewhen(U){
            val imm_31_12     = instruction(31, 12) << 12

            imm := Cat(imm_31_12).asSInt.asUInt
        }.otherwise{
            imm := 0.asSInt.asUInt
        }
        imm
    }
}




object get_decomposed_icache_address{
  def apply(parameters:Parameters, address:UInt):instruction_cache_address_packet={
      import parameters._

      // FIXME: move these value calculations elsewhere
      val set_bits                    = log2Ceil(L1_instructionCacheSets)
      val tag_bits                    = 32 - log2Ceil(L1_instructionCacheBlockSizeBytes)-set_bits    // 32 - bits required to index set - bits required to index within line - 2 bits due to 4 byte aligned data
      val instruction_offset_bits     = log2Ceil(L1_instructionCacheBlockSizeBytes/4)
      val fetch_packet_bits           = log2Ceil(L1_instructionCacheBlockSizeBytes/4/fetchWidth)

      val decomposed_icache_address = Wire(new instruction_cache_address_packet(parameters))

      decomposed_icache_address.tag                 := address(31, 31-tag_bits+1)
      decomposed_icache_address.set                 := address(31-tag_bits, 31-tag_bits-set_bits+1)
      decomposed_icache_address.fetch_packet        := address(31-tag_bits-set_bits, 31-tag_bits-set_bits-fetch_packet_bits+1) 
      decomposed_icache_address.instruction_offset  := address(2+instruction_offset_bits, 2) // The offset within the packet

      decomposed_icache_address

  }
}
