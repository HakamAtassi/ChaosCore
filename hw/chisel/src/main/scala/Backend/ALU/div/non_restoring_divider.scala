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
package ChaosCore

import chisel3._
import chisel3.util._

class non_restoring_computation extends Module{
  val io = IO(new Bundle{
    val partial_remainder_in    = Input(UInt(33.W))
    val divisor                 = Input(UInt(32.W))
    val sel                     = Input(Bool())

    val partial_remainder_out   = Output(UInt(33.W))
  })

  io.partial_remainder_out := Mux(io.sel, io.partial_remainder_in + io.divisor, io.partial_remainder_in - io.divisor)
}

class non_restoring_divider extends Module{
  val io = IO(new Bundle{
    val dividend    =     Flipped(Decoupled(UInt(32.W)))
    val divisor     =     Flipped(Decoupled(UInt(32.W)))

    val quotient    =     Decoupled(UInt(32.W))
    val remainder   =     Decoupled(UInt(32.W))
    val stall       =     Input(Bool())
    val flush       =     Input(Bool())
    val signed      =     Input(Bool())
  })

  // FIXME: Add stall signal if cant output result (backpressure)
  // FIXME: remainder entirely not output
  // FIXME: forgot to follow my own naming conventions

  // Assign inputs as always ready
  when (!io.stall && !io.flush){
    io.dividend.ready :=  1.B
    io.divisor.ready  :=  1.B  
  }.otherwise{
    io.dividend.ready :=  0.B
    io.divisor.ready  :=  0.B  
  }

  // Generate vec and divisor Regs (constant width)
  val valid_reg     = RegInit(UInt(33.W), 0.U)  // No need to make this a vector
  val divisor_regs  = RegInit(VecInit(Seq.fill (33) (0.U(32.W))))
  val dividend_regs = Seq.tabulate(32)(i => RegInit(0.U((32 - i).W)))   // Reg 0 -> 32 bits. Reg 31 -> 1 Bit
  val quotient_regs = Seq.tabulate(32)(i => RegInit(0.U((i+1).W)))      // Reg 0 -> 1 Bit.   Reg 31 -> 32 Bits
  val partial_remainder_regs = RegInit(VecInit(Seq.fill (33) (0.U(33.W))))
  val divisor_sign_reg      = RegInit(UInt(33.W), 0.U)
  val dividend_sign_reg      = RegInit(UInt(33.W), 0.U)

  // "genvar" wires
  val partial_remainder_outputs = Seq.fill(32)(Wire(UInt(33.W)))

  


  // Connect up non_restoring_computation modules
  val non_restoring_dividers = Seq.tabulate(32) { i =>
    val non_restoring_computation = Module(new non_restoring_computation)
    non_restoring_computation.io.partial_remainder_in  := Cat(partial_remainder_regs(i)(31,0),dividend_regs(i)(dividend_regs(i).getWidth-1))
    non_restoring_computation.io.divisor               := divisor_regs(i)
    non_restoring_computation.io.sel                   := partial_remainder_regs(i)(32)

  partial_remainder_outputs(i) := non_restoring_computation.io.partial_remainder_out
  dontTouch(partial_remainder_outputs(i))
  }
  
  when(!io.stall){
    // Stage 0 logic
    partial_remainder_regs(0) := 0.U
    dividend_regs(0)          := Mux(io.dividend.bits(31) && io.signed, ~io.dividend.bits + 1.U, io.dividend.bits)
    divisor_regs(0)           := Mux(io.divisor.bits(31) && io.signed, ~io.divisor.bits + 1.U, io.divisor.bits) 

    //shift inputs
    valid_reg               := valid_reg<<1 | (io.dividend.valid && io.divisor.valid)  // Shift in valid
    divisor_sign_reg        := divisor_sign_reg<<1 | (io.divisor.bits(31) && io.signed)
    dividend_sign_reg       := dividend_sign_reg<<1 | (io.dividend.bits(31) && io.signed)


    for(i <- 1 until 32) { 
      divisor_regs(i) := divisor_regs(i-1)
    }
    for(i <- 1 to 31){
      partial_remainder_regs(i) := partial_remainder_outputs(i-1)
      quotient_regs(i) := quotient_regs(i-1) ## (~partial_remainder_outputs(i)(32))
      dividend_regs(i) := dividend_regs(i-1)((31-i),0)
    }
    quotient_regs(0) := (~partial_remainder_outputs(0)(32))

    partial_remainder_regs(32) := partial_remainder_outputs(31)
    divisor_regs(32) := divisor_regs(31)
  }
  
  when(io.flush){

    for(i <- 0 until 31) { 
      divisor_regs(i)   := 0.U
      dividend_regs(i)  := 0.U
      partial_remainder_regs(i) := 0.U
      quotient_regs(i) := 0.U
    }

    valid_reg               := 0.U
    divisor_sign_reg        := 0.U
    dividend_sign_reg       := 0.U

    divisor_regs(32)   := 0.U
    partial_remainder_regs(32) := 0.U
    
    io.quotient.valid := 0.B
    io.remainder.valid := 0.B
  }
  
  for(i <- 1 until 32) { 
    dontTouch(dividend_regs(i))
    dontTouch(divisor_regs(i))
  }

  dontTouch(quotient_regs(0))
  dontTouch(partial_remainder_regs(0))
  for(i <- 1 to 31){
    dontTouch(quotient_regs(i))
    dontTouch(partial_remainder_regs(i))
  }

  val final_remainder  =  Wire(UInt(32.W))
  val q_sign = Wire(Bool())
  q_sign    := divisor_sign_reg(divisor_sign_reg.getWidth - 1) ^ dividend_sign_reg(dividend_sign_reg.getWidth - 1)

  // Assign Outputs
  io.quotient.valid   :=  valid_reg(valid_reg.getWidth-1)
  io.remainder.valid  :=  valid_reg(valid_reg.getWidth-1)
  io.quotient.bits    :=  Mux(q_sign, ~quotient_regs(31) + 1.U, quotient_regs(31))
  final_remainder     :=  Mux(partial_remainder_regs(32)(32),partial_remainder_regs(32) + divisor_regs(32),partial_remainder_regs(32))
  io.remainder.bits   :=  Mux(dividend_sign_reg(dividend_sign_reg.getWidth - 1), ~final_remainder + 1.U, final_remainder)
  when(divisor_regs(32) === 0.U){io.quotient.bits := "hffffffff".U}
}