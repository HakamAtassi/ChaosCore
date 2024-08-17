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

package ChaosCore

import chisel3._
import chisel3.ltl._
import circt.stage.ChiselStage 
import chisel3.util._
import java.io.{File, FileWriter}
import java.rmi.server.UID


class PC_gen(coreParameters:CoreParameters) extends Module{
    import coreParameters._

    val io = IO(new Bundle{
        val commit                          =   Flipped(ValidIO(new commit(coreParameters)))
        val revert                          =   Flipped(ValidIO(new revert(coreParameters)))

        val prediction                      =   Flipped(Decoupled(new prediction(coreParameters)))           // BTB response
        val RAS_read                        =   Flipped(new RAS_read(coreParameters))
        // TODO: Exception:...                                                     // exception

        val PC_next                         =   Decoupled(new frontend_memory_request(coreParameters))
    }); dontTouch(io)

    // PC regs
    val PC_reg                 = RegInit(UInt(32.W), startPC.asUInt)
    val flush_PC_reg           = RegInit(UInt(32.W), 0.U)

    // MUX outputs
    val PC_mux                 = Wire(UInt(32.W))
    val flush_PC_mux           = Wire(UInt(32.W))

    // MUX ctrl
    val is_misprediction       = Wire(Bool())
    val is_revert              = Wire(Bool())
    val flushing_event         = Wire(Bool())
    val use_BTB                = Wire(Bool())
    val use_RAS                = Wire(Bool())

    val is_branch              = Wire(Bool())
    val is_jalr                = Wire(Bool())
    val is_ret                 = Wire(Bool())

    //val exception              = Wire(Bool())

    val PC_increment           =   Wire(UInt(32.W))

    is_misprediction    := (io.commit.valid && io.commit.bits.is_misprediction)
    is_revert           := (io.revert.valid)
    is_branch           := (io.prediction.bits.br_type === br_type_t.BR)     && io.prediction.valid
    is_jalr             := (io.prediction.bits.br_type === br_type_t.JALR)   && io.prediction.valid
    is_ret              := (io.prediction.bits.br_type === br_type_t.RET)    && io.prediction.valid
    use_BTB             := (io.prediction.bits.hit && io.prediction.valid && !is_ret)
    use_RAS             := is_ret
    flushing_event      := is_misprediction || is_revert

    // FLUSHING MUX //
    when(io.commit.valid && io.commit.bits.is_misprediction){
        flush_PC_mux := io.commit.bits.fetch_PC
    }.elsewhen(io.revert.valid){
        flush_PC_mux := io.revert.bits.PC
    }.otherwise(flush_PC_mux := 0.U)    // TODO: exception
    flush_PC_reg := flush_PC_mux

    dontTouch(use_BTB)
    dontTouch(use_RAS)
    dontTouch(RegNext(flushing_event))


    // NEXT PC MUX
    when(use_BTB){
        PC_mux := io.prediction.bits.target
    }.elsewhen(use_RAS){
        PC_mux := io.RAS_read.ret_addr
    }.elsewhen(RegNext(flushing_event)){
        PC_mux := flush_PC_reg
    }.otherwise{
        PC_mux := PC_reg 
    }

    PC_increment    :=  get_PC_increment(coreParameters, PC_mux)
    when(io.PC_next.fire){PC_reg := PC_mux + PC_increment}

    // OUTPUT
    io.PC_next.bits      := DontCare
    io.PC_next.bits.addr := PC_mux
    io.PC_next.valid     := !flushing_event

    io.prediction.ready := io.PC_next.ready



}