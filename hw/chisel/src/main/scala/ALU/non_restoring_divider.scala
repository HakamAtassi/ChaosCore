/* ------------------------------------------------------------------------------------
* Filename: non_restoring_divider.scala
* Author: Hakam Atassi
* Date: Mar 4 2024
* Description: A pipelined integer division unit
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

import circt.stage.ChiselStage
import chisel3._
import chisel3.util._
import java.io.{File, FileWriter}
import java.rmi.server.UID

class non_restoring_computation extends Module{
  val io = IO(new Bundle{
    val partial_remainder_in    = Input(UInt(32.W))
    val divisor                 = Input(UInt(32.W))
    val sel                     = Input(Bool())

    val partial_remainder_out   = Output(UInt(32.W))
  })


  io.partial_remainder_out := Mux(io.sel, io.partial_remainder_in + io.divisor, io.partial_remainder_in - io.divisor)
}

class non_restoring_divider extends Module{
  val io = IO(new Bundle{
    val dividend    =     Flipped(Decoupled(UInt(32.W)))
    val divisor     =     Flipped(Decoupled(UInt(32.W)))

    val quotient    =     Decoupled(UInt(32.W))
    val remainder   =     Decoupled(UInt(32.W))
  })

  // FIXME: Add stall signal if cant output result (backpressure)
  // FIXME: missing remainder update if negative...
  // FIXME: forgot to follow my own naming conventions

  // Assign inputs as always ready
  io.dividend.ready :=  1.B
  io.divisor.ready  :=  1.B  

  // Generate vec and divisor Regs (constant width)
  val valid_reg     = RegInit(UInt(33.W), 0.U)  // No need to make this a vector
  val divisor_regs  = RegInit(VecInit(Seq.fill (32) (0.U(32.W))))
  val dividend_regs = Seq.tabulate(32)(i => RegInit(0.U((32 - i).W)))   // Reg 0 -> 32 bits. Reg 31 -> 1 Bit
  val quotient_regs = Seq.tabulate(32)(i => RegInit(0.U((i+1).W)))      // Reg 0 -> 1 Bit.   Reg 31 -> 32 Bits
  val partial_remainder_regs = RegInit(VecInit(Seq.fill (33) (0.U(32.W))))

  // "genvar" wires
  val partial_remainder_outputs = Seq.fill(32)(Wire(UInt(32.W)))

  // Shift inputs
  valid_reg         := valid_reg<<1 | (io.dividend.valid && io.divisor.valid)  // Shift in valid
  divisor_regs(0)   := io.divisor.bits


  // Connect up non_restoring_computation modules
  val non_restoring_dividers = Seq.tabulate(32) { i =>
    val non_restoring_computation = Module(new non_restoring_computation)
    non_restoring_computation.io.partial_remainder_in  := Cat(partial_remainder_regs(i)(30,0),dividend_regs(i)(dividend_regs(i).getWidth-1))
    non_restoring_computation.io.divisor               := divisor_regs(i)
    non_restoring_computation.io.sel                   := partial_remainder_regs(i)(31)

   partial_remainder_outputs(i) := non_restoring_computation.io.partial_remainder_out
   dontTouch(partial_remainder_outputs(i))
  }

  // Stage 0 logic
  partial_remainder_regs(0) := 0.U
  dividend_regs(0)          := io.dividend.bits
  divisor_regs(0)           := io.divisor.bits
  
  for(i <- 1 to 31){
    divisor_regs(i) := divisor_regs(i-1)
  }

  dividend_regs(0) := io.dividend.bits
  for(i <- 1 until 32) { 
      dividend_regs(i) := dividend_regs(i-1)((31-i),0)
      dontTouch(dividend_regs(i))
  }

  dontTouch(quotient_regs(0))
  dontTouch(partial_remainder_regs(0))
  quotient_regs(0) := (~partial_remainder_outputs(0)(31))
  for(i <- 1 to 31){
    //partial_remainder_regs(i) := Cat(partial_remainder_outputs(i-1)(30,0), dividend_regs(i)(dividend_regs(i).getWidth-1))
    partial_remainder_regs(i) := partial_remainder_outputs(i-1)
    quotient_regs(i) := quotient_regs(i-1) ## (~partial_remainder_outputs(i)(31))
    dontTouch(quotient_regs(i))
    dontTouch(partial_remainder_regs(i))
  }
  partial_remainder_regs(32) := partial_remainder_outputs(31)

  io.remainder.bits := partial_remainder_regs(32)

  // Assign Outputs
  io.quotient.valid   :=  valid_reg(valid_reg.getWidth-1)
  io.remainder.valid  :=  valid_reg(valid_reg.getWidth-1)
  io.quotient.bits   :=  quotient_regs(31)
  io.remainder.bits  :=  partial_remainder_regs(32)
}

object Main extends App{
  println("Building non_restoring_divider");

  var non_restoring_divider = ChiselStage.emitSystemVerilog(gen=new non_restoring_divider, firtoolOpts=Array("-disable-all-randomization", "-strip-debug-info"))

  var file = new File("../verilog/dividers/non_restoring_divider.v")

  var fw = new FileWriter(file)

  try {
    fw.write(non_restoring_divider)
  } finally {
    fw.close()
  }
}
