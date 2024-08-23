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
  def apply(coreParameters:CoreParameters) ={
    import coreParameters._

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
  def apply(commits: Seq[commit], coreParameters:CoreParameters): commit = {
    import coreParameters._
    var mispredictionCommit = new commit(coreParameters) // Assuming `coreParameters` is available in scope

    for (i <- fetchWidth - 1 to 0 by -1) {
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

        val imm = Wire(UInt(21.W))

        when(B) {

            val temp = Wire(SInt(32.W))

            val imm_12      = instruction(31)
            val imm_10_5    = instruction(30, 25)
            val imm_4_1     = instruction(11, 8)
            val imm_11      = instruction(7)

            temp := Cat(imm_12, imm_11, imm_10_5, imm_4_1, 0.U(1.W)).asSInt
            imm := temp.asUInt

        }.elsewhen (J) {
            val temp = Wire(SInt(32.W))

            val imm_20    = instruction(31)
            val imm_19_12 = instruction(19, 12)
            val imm_11    = instruction(20)
            val imm_10_1  = instruction(30,21)

            temp := Cat(imm_20, imm_19_12, imm_11, imm_10_1, 0.U(1.W)).asSInt
            imm  := temp.asUInt
        }.elsewhen (I) {
            val temp = Wire(SInt(32.W))

            val imm_11_0      = instruction(31, 20)
            temp := imm_11_0.asSInt
            imm := temp.asUInt
        }.elsewhen(S){
            val temp = Wire(SInt(32.W))

            val imm_11_5      = instruction(31, 25)
            val imm_4_0       = instruction(11, 7)

            temp := Cat(imm_11_5, imm_4_0).asSInt

            imm := temp.asUInt
        }.elsewhen(U){
            val temp = Wire(SInt(32.W))

            val imm_31_12     = instruction(31, 12)

            temp := Cat(imm_31_12).asSInt

            imm := temp.asUInt
        }.otherwise{
            imm := 0.U
        }
        imm
    }
}




object get_decomposed_icache_address{
  def apply(coreParameters:CoreParameters, address:UInt):instruction_cache_address_packet={
      import coreParameters._

      val set_bits                    = log2Ceil(L1_instructionCacheSets)
      val tag_bits                    = 32 - log2Ceil(L1_instructionCacheBlockSizeBytes)-set_bits    // 32 - bits required to index set - bits required to index within line - 2 bits due to 4 byte aligned data
      val instruction_offset_bits     = log2Ceil(fetchWidth)
      val fetch_packet_bits           = log2Ceil(L1_instructionCacheBlockSizeBytes/4/fetchWidth)

      val decomposed_icache_address = Wire(new instruction_cache_address_packet(coreParameters))

      decomposed_icache_address.tag                 := address(31, 31-tag_bits+1)
      decomposed_icache_address.set                 := address(31-tag_bits, 31-tag_bits-set_bits+1)
      decomposed_icache_address.fetch_packet        := address(31-tag_bits-set_bits, 31-tag_bits-set_bits-fetch_packet_bits+1) 
      decomposed_icache_address.instruction_offset  := address(2+instruction_offset_bits, 2) // The offset within the packet

      decomposed_icache_address

  }
}

object get_MOB_row_byte_sel {
  def apply(coreParameters:CoreParameters, MOB_entry: MOB_entry): Vec[Bool] = {
    // Extract relevant fields from the MOB_entry
    val address     = MOB_entry.address 
    val is_store    = MOB_entry.memory_type === memory_type_t.STORE
    val access_width = MOB_entry.access_width 

    // Byte select vector (4 bits for 4 bytes in a word)
    val byte_sels = Wire(Vec(4, Bool()))

    byte_sels := VecInit(Seq(0.B, 0.B, 0.B, 0.B))

    // Calculate byte mask based on the access size and address alignment
    when(is_store) {
      switch(access_width) {
        is(access_width_t.B) {
          // Byte access, only one byte is selected based on the lower 2 bits of the address
          byte_sels(address(1, 0)) := 1.B
        }
        is(access_width_t.HW) {
          // Half-Word access, two consecutive bytes are selected
          switch(address(1, 0)) {
            is("b00".U) { byte_sels := VecInit(Seq(1.B, 1.B, 0.B, 0.B)) }
            is("b10".U) { byte_sels := VecInit(Seq(0.B, 0.B, 1.B, 1.B)) }
            // TODO: Otherwise, exception 
          }
        }
        is(access_width_t.W) {
          // Word access, all four bytes are selected
          byte_sels := VecInit(Seq(1.B, 1.B, 1.B, 1.B))
        }
      }
    }

    byte_sels
  }
}

object get_MOB_row_wr_bytes {
  def apply(coreParameters:CoreParameters, MOB_entry: MOB_entry): Vec[UInt] = {
    // Extract relevant fields from the MOB_entry
    val address = MOB_entry.address
    val data = MOB_entry.data
    val is_store = MOB_entry.memory_type === memory_type_t.STORE
    val access_width = MOB_entry.access_width // assuming access_width is defined in MOB_entry

    // Byte write vector (4 bytes for a word)
    val wr_bytes = Wire(Vec(4, UInt(8.W)))
    wr_bytes := VecInit(Seq.fill(4)(0.U(8.W))) // Initialize to zeros

    // Populate the byte write vector based on the access width and address alignment
    when(is_store) {
      switch(access_width) {
        is(access_width_t.B) {
          // Byte access, only one byte is written
          wr_bytes(address(1, 0)) := data(7, 0)
        }
        is(access_width_t.HW) {
          // Half-Word access, two consecutive bytes are written
          switch(address(1, 0)) {
            is("b00".U) {
              wr_bytes(0) := data(7, 0)
              wr_bytes(1) := data(15, 8)
            }
            is("b01".U) {
              wr_bytes(1) := data(7, 0)
              wr_bytes(2) := data(15, 8)
            }
            is("b10".U) {
              wr_bytes(2) := data(7, 0)
              wr_bytes(3) := data(15, 8)
            }
            is("b11".U) {
              wr_bytes(3) := data(7, 0)
            }
          }
        }
        is(access_width_t.W) {
          // Word access, all four bytes are written
          switch(address(1, 0)) {
            is("b00".U) {
              wr_bytes(0) := data(7, 0)
              wr_bytes(1) := data(15, 8)
              wr_bytes(2) := data(23, 16)
              wr_bytes(3) := data(31, 24)
            }
            is("b01".U) {
              wr_bytes(1) := data(7, 0)
              wr_bytes(2) := data(15, 8)
              wr_bytes(3) := data(23, 16)
            }
            is("b10".U) {
              wr_bytes(2) := data(7, 0)
              wr_bytes(3) := data(15, 8)
            }
            is("b11".U) {
              wr_bytes(3) := data(7, 0)
            }
          }
        }
      }
    }

    wr_bytes
  }
}

object get_fetch_packet_aligned_address {
  def apply(coreParameters:CoreParameters, addr: UInt): UInt = {
    import coreParameters._
    val mask = ~((fetchWidth * 4 - 1).U(addr.getWidth.W))
    addr & mask
  }
}

object get_PC_increment{
  def apply(coreParameters:CoreParameters, PC:UInt):UInt = {
    import coreParameters._
    val masked_address = (fetchWidth*4 - 1).U & PC
    val increment = (fetchWidth*4).U - masked_address
    increment
  }
}


object sign_extend {
  def apply(data: UInt, width: Int): UInt = {
    require(width >= data.getWidth, "Width for sign extension must be greater than or equal to the width of the data.")

    // Convert the data to a SInt to sign-extend it
    val temp = Wire(SInt(width.W))
    temp := data.asSInt

    // Convert back to UInt
    temp.asUInt
  }
}