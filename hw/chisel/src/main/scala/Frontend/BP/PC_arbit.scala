/* ------------------------------------------------------------------------------------
* Filename: PC_arbit.scala
* Author: Hakam Atassi
* Date: Apr 2024
* Description: A module that arbitrates the PCs based on the BTB, Misprediction, Exception, Redirect, and +16 signals
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

class PC_arbit(GHRWidth:Int = 16, fetchWidth:Int = 4, RASEntries:Int=128, startPC:UInt="h80000000".U) extends Module{

    val io = IO(new Bundle{
        val mispredict  = Flipped(Decoupled(new mispredict(GHRWidth=GHRWidth, RASEntries=RASEntries)))                       // external mispredict
        val prediction  = Flipped(Decoupled(new prediction(fetchWidth=fetchWidth, GHRWidth=GHRWidth)))    // BTB response
        val revert      = Flipped(Decoupled(new revert(GHRWidth=GHRWidth)))                                                   // Pre-decoder revert request
        val RAS_read    = Flipped(new RAS_read(RASEntries=RASEntries))
        // TODO: Exception:...                                                                            // exception

        val PC_next     = Decoupled(UInt(32.W))
    })

    //val sel_exception   = Wire(Bool())
    val sel_mispred     = Wire(Bool())
    val sel_revert      = Wire(Bool())
    val sel_ret         = Wire(Bool())
    val sel_target      = Wire(Bool())
    val sel_PC_4        = Wire(Bool())

    val PC                   = RegInit(UInt(32.W), startPC)
    val aligned_PC_increment = Wire(UInt(log2Ceil(fetchWidth).W))
    val instruction_index    = Wire(UInt(log2Ceil(fetchWidth).W))
    


    //sel_exception      := io.exception.valid
    sel_mispred        := io.mispredict.valid 
    sel_revert         := io.revert.valid

    sel_ret            := io.prediction.valid && io.prediction.bits.hit && (io.prediction.bits.br_type === 0.U)   // FIXME: br_type wrong
    sel_target         := io.prediction.valid && io.prediction.bits.hit && (io.prediction.bits.br_type === 0.U)   // FIXME: br_type wrong

    sel_PC_4           := 1.B   // if none of the above (default)


    // TODO: assign aligned increment
    instruction_index := PC(log2Ceil(fetchWidth) + 2,2)
    aligned_PC_increment    := (fetchWidth.U-instruction_index)<<2


    when(io.PC_next.ready){
        PC := io.PC_next.bits + aligned_PC_increment
    }.otherwise{
        PC := io.PC_next.bits
    }
    
    
    // FIXME: is this accurate
    io.mispredict.ready  := 1.B
    io.prediction.ready  := 1.B
    io.revert.ready      := 1.B

    io.PC_next.valid     := 1.B

        
    when(sel_mispred)       {io.PC_next.bits := io.mispredict.bits.PC}
    //.elsewhen(sel_exception){io.PC_next.bits := io.exception.PC}
    .elsewhen(sel_revert)   {io.PC_next.bits := io.revert.bits.PC}
    .elsewhen(sel_ret)      {io.PC_next.bits := io.RAS_read.ret_addr}
    .elsewhen(sel_target)   {io.PC_next.bits := io.prediction.bits.target}
    .elsewhen(sel_PC_4)     {io.PC_next.bits := PC}
    .otherwise              {io.PC_next.bits := 0.U}

}