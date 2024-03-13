/* ------------------------------------------------------------------------------------
* Filename: unpipelined_non_restoring_divider.scala
* Author: Hakam Atassi
* Date: Mar 7 2024
* Description: An integer division unit
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

object unpipelined_non_restoring_divider{
  object division_state extends ChiselEnum{
    val idle, active, delay, done = Value
  }
}

class unpipelined_non_restoring_divider extends Module{
  import unpipelined_non_restoring_divider.division_state
  import unpipelined_non_restoring_divider.division_state._
  val io = IO(new Bundle{
    val dividend    =     Flipped(Decoupled(UInt(32.W)))
    val divisor     =     Flipped(Decoupled(UInt(32.W)))
    val signed      =     Flipped(Decoupled(Bool()))    // Inputs are signed 

    val quotient    =     Decoupled(UInt(32.W))
    val remainder   =     Decoupled(UInt(32.W))
  })

  val quotient = RegInit(UInt(32.W), 0.U)
  val partial_remainder = RegInit(UInt(33.W), 0.U)

  val dividend = RegInit(UInt(32.W), 0.U)
  val divisor = RegInit(UInt(32.W), 0.U)

  val dividend_sign_bit = RegInit(UInt(1.W), 0.B)
  val divisor_sign_bit  = RegInit(UInt(1.W), 0.B)

  val flop_inputs = Wire(Bool())  // Place new inputs in registers

  val partial_remainder_next = Wire(UInt(33.W))
  val partial_remainder_msb  = Wire(Bool())
  val partial_remainder_shifted = Wire(UInt(33.W))

  val state_counter = RegInit(UInt(5.W), 0.U)  // controls when common case is exited (0->31 iterations)
  val division_state = RegInit(idle)


  io.dividend.ready := 0.B
  io.divisor.ready := 0.B
  io.signed.ready := 0.B

  
  io.quotient.valid := 0.B
  io.remainder.valid := 0.B
  io.quotient.bits := 0.U
  io.remainder.bits := 0.U


  switch (division_state){
    is(idle){

      io.dividend.ready := 1.B
      io.divisor.ready := 1.B
      io.signed.ready := 1.B
      when(io.dividend.valid && io.divisor.valid && io.signed.valid){
        division_state := active
        io.dividend.ready := 0.B
        io.divisor.ready := 0.B
        io.signed.ready := 0.B
      }

      // FIXME: this can be simplified
       when(io.divisor.bits(31).asBool === 1.B && io.signed.bits === 1.B){divisor := ~io.divisor.bits + 1.U}.otherwise{divisor := io.divisor.bits}
       when(io.dividend.bits(31).asBool === 1.B && io.signed.bits === 1.B){dividend := ~io.dividend.bits + 1.U}.otherwise{dividend := io.dividend.bits}

      when(io.signed.bits === 1.B){ // inputs are signed
        divisor_sign_bit := io.divisor.bits(31)
        dividend_sign_bit := io.dividend.bits(31)
      }.otherwise{
        divisor_sign_bit := 0.U
        dividend_sign_bit := 0.U
      }
      dontTouch(dividend_sign_bit)
      dontTouch(divisor_sign_bit)

      partial_remainder := 0.U
      state_counter := state_counter + 0.U
      quotient  := 0.U
    }

    is(active){
      dividend := dividend << 1
      quotient := quotient(30,0) ## ~partial_remainder_next(32)
      partial_remainder := partial_remainder_next
      state_counter := state_counter + 1.U
      when(state_counter === 31.U){
        division_state := done
      }
    }

    is(delay){
      division_state := done
    }

    is(done){


        when((dividend_sign_bit ^ divisor_sign_bit) === 1.U){
          io.quotient.bits := (~quotient)+1.U
        }.otherwise{
          io.quotient.bits := quotient
        }

        io.remainder.bits := partial_remainder  // Sign of this??

        io.quotient.valid := 1.B
        io.remainder.valid := 1.B

        division_state := idle
    }
  }
  
  flop_inputs := io.divisor.valid & io.dividend.valid && io.signed.valid

  
  partial_remainder_msb := partial_remainder(32).asBool
  partial_remainder_shifted := (partial_remainder<<1) | dividend(31)

  partial_remainder_next := Mux(partial_remainder_msb, partial_remainder_shifted + divisor, partial_remainder_shifted - divisor)


}

