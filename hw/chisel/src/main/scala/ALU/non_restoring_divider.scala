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


// FIXME: forgot to follow my own naming conventions


class non_restoring_computation extends Module{

  val io = IO(new Bundle{
    val partial_remainder_in    = Input(UInt(32.W))
    val divisor                 = Input(UInt(32.W))

    val partial_remainder_out   = Output(UInt(32.W))
  })

  val partial_in_msb = Wire(Bool())
  partial_in_msb := io.partial_remainder_in(31)

  io.partial_remainder_out := Mux(partial_in_msb, io.partial_remainder_in + io.divisor, io.partial_remainder_in - io.divisor)
}


class non_restoring_divider extends Module{

  val io = IO(new Bundle{
    val dividend    =     Flipped(Decoupled(UInt(32.W)))
    val divisor     =     Flipped(Decoupled(UInt(32.W)))

    val quotient    =     Decoupled(UInt(32.W))
    val remainder   =     Decoupled(UInt(32.W))
  })

  // FIXME: Add stall signal if cant output result (backpressure)

  // Assign inputs as always ready
  io.dividend.ready :=  1.B
  io.divisor.ready  :=  1.B  

  // Generate vec and divisor Regs (constant width)
  val valid_reg     = RegInit(UInt(34.W), 0.U)  // No need to make this a vector
  val divisor_regs  = RegInit(VecInit(Seq.fill (33) (0.U(32.W))))
  val dividend_regs = Seq.tabulate(32)(i => RegInit(0.U((32 - i).W)))   // Reg 0 -> 32 bits. Reg 31 -> 1 Bit
  val quotient_regs = Seq.tabulate(32)(i => RegInit(0.U((i+1).W)))      // Reg 0 -> 1 Bit.   Reg 31 -> 32 Bits
  val partial_remainder_regs = RegInit(VecInit(Seq.fill (33) (0.U(32.W))))

  // "genvar" wires
  val partial_remainder_outputs = Seq.fill(32)(Wire(UInt(32.W)))


  // Shift inputs
  valid_reg         := Cat((io.dividend.valid && io.divisor.valid), valid_reg(31,1))  // Shift in valid
  divisor_regs(0)   := io.divisor.bits

  // Connect up non_restoring_computation modules
  val non_restoring_dividers = Seq.tabulate(32) { i =>
    val non_restoring_computation = Module(new non_restoring_computation)
    non_restoring_computation.io.partial_remainder_in  := partial_remainder_regs(i)
    non_restoring_computation.io.divisor               := divisor_regs(i+1)

   partial_remainder_outputs(i) := non_restoring_computation.io.partial_remainder_out
  }

  // Stage 0 logic
  partial_remainder_regs(0) := Cat(0.U(31.W), dividend_regs(0)(31))
  dividend_regs(1)          := dividend_regs(0)(30,0)
  divisor_regs(1)           := divisor_regs(0)
  
  
  
  // Stage 1 logic
  
  
  // Stage 2-32 logic


  // Stage 33 logic (output) 
  io.quotient.valid   :=  valid_reg(32)
  io.remainder.valid  :=  valid_reg(32)

  io.quotient.bits   :=  0.U
  io.remainder.bits  :=  0.U


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
