/* ------------------------------------------------------------------------------------
* Filename: FPU.scala
* Author: Hakam Atassi
* Date: March 8 2025
* Description: The Core's monolithic floating point unit. 
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

import chisel3.util._
import hardfloat._


import freechips.rocketchip.tile._

object FPConstants
{
  val RM_SZ = 3
  val FLAGS_SZ = 5
}

trait HasFPUCtrlSigs {
  val ldst = Bool()
  val wen = Bool()
  val ren1 = Bool()
  val ren2 = Bool()
  val ren3 = Bool()
  val swap12 = Bool()
  val swap23 = Bool()
  val typeTagIn = UInt(2.W)
  val typeTagOut = UInt(2.W)
  val fromint = Bool()
  val toint = Bool()
  val fastpipe = Bool()
  val fma = Bool()
  val div = Bool()
  val sqrt = Bool()
  val wflags = Bool()
  val vec = Bool()
}


class FPInput(coreParameters:CoreParameters) extends Bundle with  HasFPUCtrlSigs {
  val rm = Bits(FPConstants.RM_SZ.W)    // rounding mode
  val fmaCmd = Bits(2.W)    // floating multiply add command
  val typ = Bits(2.W)       // ???
  val fmt = Bits(2.W)       // ???
  val in1 = Bits((32+1).W)  // input 1
  val in2 = Bits((32+1).W)  // input 2
  val in3 = Bits((32+1).W)  // input 3

}

class FPResult(coreParameters:CoreParameters) extends Bundle {
  val data = Bits((32+1).W)
  val exc = Bits(FPConstants.FLAGS_SZ.W)
}



class FPUFMAPipe(coreParameters:CoreParameters)(latency: Int, t:FType) extends Module{
  require(latency>0)

  val minFLen = 32
  val fLen = 32
  def xLen = 32

  val minXLen = 32
  val nIntTypes = log2Ceil(xLen/minXLen) + 1
  def floatTypes = FType.all.filter(t => minFLen <= t.ieeeWidth && t.ieeeWidth <= fLen)
  def minType = floatTypes.head
  def maxType = floatTypes.last
  def prevType(t: FType) = floatTypes(typeTag(t) - 1)
  def maxExpWidth = maxType.exp
  def maxSigWidth = maxType.sig
  def typeTag(t: FType) = floatTypes.indexOf(t)
  def typeTagWbOffset = (FType.all.indexOf(minType) + 1).U
  def typeTagGroup(t: FType) = (if (floatTypes.contains(t)) typeTag(t) else typeTag(maxType)).U
  // typeTag
  def H = typeTagGroup(FType.H)
  def S = typeTagGroup(FType.S)
  def D = typeTagGroup(FType.D)
  def I = typeTag(maxType).U



  def sanitizeNaN(x: UInt, t: FType): UInt = {
    if (typeTag(t) == 0) {
      x
    } else {
      val maskedNaN = x & ~((BigInt(1) << (t.sig-1)) | (BigInt(1) << (t.sig+t.exp-4))).U(t.recodedWidth.W)
      Mux(t.isNaN(x), maskedNaN, x)
    }
  }



  val io = IO(new Bundle {
    val in = Flipped(Valid(new FPInput(coreParameters)))
    val out = Valid(new FPResult(coreParameters))
  })

  val valid = RegNext(io.in.valid)
  val in = Reg(new FPInput(coreParameters))
  when (io.in.valid) {
    val one = 1.U << (t.sig + t.exp - 1)
    val zero = (io.in.bits.in1 ^ io.in.bits.in2) & (1.U << (t.sig + t.exp))
    val cmd_fma = io.in.bits.ren3
    val cmd_addsub = io.in.bits.swap23
    in := io.in.bits
    when (cmd_addsub) { in.in2 := one }
    when (!(cmd_fma || cmd_addsub)) { in.in3 := zero }
  }

  val fma = Module(new MulAddRecFNPipe((latency-1) min 2, t.exp, t.sig))
  fma.io.validin := valid
  fma.io.op := in.fmaCmd
  fma.io.roundingMode := in.rm
  fma.io.detectTininess := hardfloat.consts.tininess_afterRounding
  fma.io.a := in.in1
  fma.io.b := in.in2
  fma.io.c := in.in3

  val res = Wire(new FPResult(coreParameters))
  res.data := sanitizeNaN(fma.io.out, t)
  res.exc := fma.io.exceptionFlags

  io.out := Pipe(fma.io.validout, res, (latency-3) max 0)
}



class FPU(coreParameters:CoreParameters) extends Module{
    import coreParameters._

    //import FUParam._  // FIXME: needs this 
    val io = IO(new Bundle{
        // FLUSH
        val flush         =   Flipped(ValidIO(new flush(coreParameters)))

        // Input
        val FU_input      =   Flipped(Decoupled(new read_decoded_instruction(coreParameters)))
        
        // Output
        val FU_output     =   Decoupled(new FU_output(coreParameters))

        // partial_commit (for CSRs)
        val commit         =   Flipped(ValidIO(new commit(coreParameters)))

    }); dontTouch(io)
    // link to hardfloat docs
    // http://www.jhauser.us/arithmetic/HardFloat-1/doc/HardFloat-Verilog.html


    // Define the Floating Point type (adjust as needed)
    val fpType = new FType(8, 24)  // FP32 example (8-bit exponent, 24-bit mantissa)


    // RecFNToIn    // This lives in FP to Int
    // IntToRecFN   // This lives in a conversion supported ALU

    // Conversions:
    // (FN to Recoded FN -> recFNFromFN)    // input to modules (standard ieee FP to RecFN)
    // (Recoded FN to FN -> fNFromRecFN)    // output of modules (RecFN to standard ieee FP)


    io := DontCare


    /////////////
    // MODULES //
    /////////////

    val FPUMA = Module(new FPUFMAPipe(coreParameters)(latency=5, t=fpType))

    ////////////
    // DECODE //
    ////////////


    ///////////////////////////////
    // CONVERT FROM UINT32 to FP //
    ///////////////////////////////

    val FPU_input = WireInit(0.U.asTypeOf(ValidIO(new FPInput(coreParameters))))


    //val ldst = Bool()
    //FPU_input.bits.wen = Bool()
    //FPU_input.bits.ren1 = Bool()
    //FPU_input.bits.ren2 = Bool()
    //FPU_input.bits.ren3 = Bool()
    //FPU_input.bits.swap12 = Bool()
    //FPU_input.bits.swap23 = Bool()
    //FPU_input.bits.typeTagIn = UInt(2.W)
    //FPU_input.bits.typeTagOut = UInt(2.W)
    //FPU_input.bits.fromint = Bool()
    //FPU_input.bits.toint = Bool()
    //FPU_input.bits.fastpipe = Bool()
    //FPU_input.bits.fma = Bool()
    //FPU_input.bits.div = Bool()
    //FPU_input.bits.sqrt = Bool()
    //FPU_input.bits.wflags = Bool()
    //FPU_input.bits.vec = Bool()


    FPU_input.bits.fma := 1.B


    FPU_input.bits.rm := 0.U //Bits(FPConstants.RM_SZ.W)    // rounding mode
    FPU_input.bits.fmaCmd := 0.U //Bits(2.W)    // floating multiply add command
    FPU_input.bits.typ := 0.U //Bits(2.W)       // ???
    FPU_input.bits.fmt := 0.U //Bits(2.W)       // ???
    FPU_input.bits.in1 := io.FU_input.bits.RS1_data //Bits((32+1).W)  // input 1
    FPU_input.bits.in2 := io.FU_input.bits.RS2_data //Bits((32+1).W)  // input 2
    FPU_input.bits.in3 := io.FU_input.bits.RS3_data //Bits((32+1).W)  // input 3

    // Assign FPU inputs
    FPUMA.io.in <> FPU_input













    ///////////////////////////////
    // CONVERT FROM FP TO UINT32 //
    ///////////////////////////////
    val FPU_output = WireInit(0.U.asTypeOf(ValidIO(new FPResult(coreParameters))))

    io.FU_output.bits.RD_data   := FType(exp=8, sig=24).ieee(FPUMA.io.out.bits.data)
    io.FU_output.valid     := FPUMA.io.out.valid





    // always ready for now
    io.FU_input.ready := 1.B






}



