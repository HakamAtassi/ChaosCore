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

  def apply(coreConfig:String) ={
    require(coreConfig.startsWith("RV32I"), "Extenstion must start with RV32I")

    var portCount = 4
    if(coreConfig.contains("M")) portCount += 1
    if(coreConfig.contains("F")) portCount += 1
    //TODO: add the rest...

    portCount
  }


}

object generatePortIDVec
{
  def apply(coreConfig:String) ={
    require(coreConfig.startsWith("RV32I"), "Extenstion must start with RV32I")

    var portCount = getPortCount(coreConfig)
    val portCountBits = log2Ceil(portCount)

    val portIDVec = VecInit(Seq.fill(portCount)(0.U(portCountBits.W)))

    portIDVec(0)  := 0.U   // ALU, Branch, CSRs, Int2FP, Mul(optional)
    portIDVec(1)  := 1.U   // ALU, Branch, Int2FP, Mul(optional)
    portIDVec(2)  := 2.U   // AGU + Store
    portIDVec(3)  := 3.U   // AGU + Load

    if(coreConfig.contains("M")) portIDVec(4)  :=  4.U   // IDIV (optional)
    // TODO: update as needed

  }
}