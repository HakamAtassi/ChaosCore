/* ------------------------------------------------------------------------------------
* Filename: CSR.scala
* Author: Hakam Atassi
* Date: Sep 15 2024
* Description: The core CSRs
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




class CSR(addr:Int) extends Bundle{

    val ACCESS = (addr >> 10) & 0x3
    val privilege = (addr >> 8) & 0x3
}


class DefaultCSR(addr:Int) extends CSR(addr){
	val reg = UInt(32.W)
}



// Bundle defining custom fields for mstatus CSR
class MStatusFields extends Bundle {
	val field1 = UInt(10.W)
	val field2 = UInt(10.W)
	val field3 = UInt(12.W)
}

// Custom CSR with fields using a Bundle
class MStatusCSR(addr: Int) extends CSR(addr) {
	val reg = new MStatusFields()
}

class TimerCSR(addr: Int) extends CSR(addr) {
  val reg = UInt(64.W)
  //0.U(64.W)

  def valuel = reg(31,0)
  def valueh = reg(63,32)
}

