/* ------------------------------------------------------------------------------------
* Filename: ALU_collapsing_queue.scala
* Author: Hakam Atassi
* Date: Sep 2024
* Description: A fixed latency decoupled queue
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

// used to help synth tool retiming. 
class ALU_collapsing_queue[T <: chisel3.Data](genType: T, stages: Int) extends Module {
    val io = IO(new Bundle {
        val flush = Input(Bool())
        val in = Flipped(Decoupled(genType))
        val out = Decoupled(genType)
    })
    
    val SR = RegInit(VecInit(Seq.fill(stages)(0.U.asTypeOf(ValidIO(genType)))))
    
    // Check if any entries are empty or if output is ready
    io.in.ready := !SR.map(_.valid).reduce(_ && _) || io.out.ready

    // ALLOCATE //
    when(io.in.fire){
        SR(0).bits := io.in.bits
        SR(0).valid := io.in.valid
    }
    
    // Shift logic
    for (i <- 0 until stages-1) {
        when(io.out.ready || (!SR.take(i + 1).map(_.valid).reduce(_ && _))) {
            SR(i+1) := SR(i)
        }
    }
    
    // Assign output
    io.out.bits := SR(stages-1).bits
    io.out.valid := SR(stages-1).valid
    
    // Flush logic
    when(io.flush) {
        SR.foreach(x => x := 0.U.asTypeOf(ValidIO(genType)))
    }
}