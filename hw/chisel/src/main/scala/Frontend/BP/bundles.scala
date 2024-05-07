/* ------------------------------------------------------------------------------------
* Filename: bundles.scala
* Author: Hakam Atassi
* Date: Apr 23 2024
* Description: useful data channels for use throughout the BP
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

import chisel3._
import circt.stage.ChiselStage
import chisel3.util._
import java.io.{File, FileWriter}
import java.rmi.server.UID


// Helper functions //
object helperFunctions {
  def getBTBTagBits(BTBSize: Int = 4096, fetchWidth:Int=4): Int = (32 - log2Ceil(BTBSize) - 2 - log2Ceil(fetchWidth))

  // Function to shift UInt32 signal down by "getBTBTagBits"
  def shiftDownByTagBits(input: UInt, BTBSize: Int = 4096, fetchWidth:Int=4): UInt = {
    val shiftAmount = 32-getBTBTagBits(BTBSize, fetchWidth)
    input >> shiftAmount
  }
}


import helperFunctions.getBTBTagBits


// Channels //
class fetch_packet(fetchWidth:Int = 4) extends Bundle{
    val fetch_PC        = UInt(32.W)
    val instructions    = Vec(fetchWidth, UInt(32.W))
    val valid_bits      = Vec(fetchWidth, Bool())
}


class metadata extends Bundle{
    val JAL             = Bool()
    val JALR            = Bool()
    val BR              = Bool()
    val Call            = Bool()
    val Ret             = Bool()
    val Imm             = UInt(32.W)
    val instruction_PC  = UInt(32.W)
    val RAS             = UInt(32.W)
    val BTB_target      = UInt(32.W)
}

/////////////////
// BP channels //
/////////////////

class commit(fetchWidth:Int=4, GHRWidth:Int=16, BTBEntries:Int=4096, RASEntries:Int = 128) extends Bundle{
    val PC      = Input(UInt(32.W))
    val GHR     = Input(UInt(GHRWidth.W))
    val T_NT    = Input(Bool())
    
    //val tag      =Input(UInt(getBTBTagBits(BTBEntries).W))
    val target   =  Input(UInt(32.W))
    val br_type  =  Input(UInt(2.W))
    val br_mask  =  Input(UInt(fetchWidth.W))

    val misprediction = Input(Bool())
    val TOS     = Input(UInt(log2Ceil(RASEntries).W))  // To reset GHR
    val NEXT    = Input(UInt(log2Ceil(RASEntries).W)) // TO reset GHR

}

/* deprecated
class mispredict(GHRWidth:Int=16, RASEntries:Int = 128) extends Bundle{
    val PC      = Input(UInt(32.W)) //
    val GHR     = Input(UInt(GHRWidth.W))  // To reset GHR
    val TOS     = Input(UInt(log2Ceil(RASEntries).W))  // To reset GHR
    val NEXT    = Input(UInt(log2Ceil(RASEntries).W)) // TO reset GHR
}
*/

class RAS_update extends Bundle{    // Request call or ret
    val call_addr = Input(UInt(32.W))
    val call      = Input(Bool())
    val ret       = Input(Bool())
}

class RAS_read(RASEntries:Int=128) extends Bundle{
    val NEXT      = Output(UInt((log2Ceil(RASEntries).W)))
    val TOS       = Output(UInt((log2Ceil(RASEntries).W)))
    val ret_addr  = Output(UInt(32.W))
}

class revert(GHRWidth:Int=16) extends Bundle{
    val GHR               = Input(UInt(GHRWidth.W))
    val PC                = Input(UInt(32.W))
}

class prediction(fetchWidth:Int=4, GHRWidth:Int=16) extends Bundle{
    val hit         =   Output(Bool())  // FIXME: I dont think this is assigned in BTB since it was added after the fact
    val target      =   Output(UInt(32.W))
    val br_type     =   Output(UInt(2.W))
    val br_mask     =   Output(UInt(fetchWidth.W))
    val GHR         =   Output(UInt(GHRWidth.W))
    val T_NT        =   Output(Bool())
}