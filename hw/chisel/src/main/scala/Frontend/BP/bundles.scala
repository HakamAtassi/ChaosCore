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


class fetch_packet(width:Int = 4) extends Bundle{
    val fetch_PC        = UInt(32.W)
    val instructions    = Vec(width, UInt(32.W))
    val valid_bits      = Vec(width, Bool())
}

class BTB_resp(GHR_width:Int=16, width:Int=4) extends Bundle{  // Width agnostic
    val hit     = Bool()
    val idx     = UInt(width.W)
    val T_NT    = Bool()
    val RAS     = UInt(32.W)
    val target  = UInt(32.W)
    val GHR     = UInt(GHR_width.W)
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

class commit(fetchWidth:Int=4, GHRWidth:Int=16) extends Bundle{
    val PC      = UInt(32.W)
    val GHR     = UInt(GHRWidth.W)
    val T_NT    = Bool()
    
    val valid    = Bool()
    val tag      = UInt()
    val target   = UInt(32.W)
    val brType  = UInt(typeBits.W)
    val brMask   = UInt(brMaskBits.W)

    val valid   = Bool()
    // PC entires...
}

class mispredict(GHRWidth:Int=16, RASEntires:Int = 128) extends Bundle{
    val PC = UInt(32.W) //
    val GHR = UInt(GHRWidth.W)  // To reset GHR
    val TOS = UInt(log2Ceil(RASEntires).W)  // To reset GHR
    val NEXT = UInt(log2Ceil(RASEntires).W) // TO reset GHR
}

class RAS_update(GHRWidth:Int=16) extends Bundle{
    val call_addr = UInt(32.W)
    val call = Bool()
    val ret = Bool()
}

class revert(GHRWidth:Int=16) extends Bundle{
    val valid             = Bool()
    val GHR                = Bool()
}

class prediction(fetchWidth:Int=4, GHRWidth:Int=16, RASEntires:Int=128) extends Bundle{
    val stub             = Bool()
    // TODO: 
}