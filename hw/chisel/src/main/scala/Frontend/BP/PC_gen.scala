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
import circt.stage.ChiselStage
import chisel3.util._
import java.io.{File, FileWriter}
import java.rmi.server.UID


object PcGenState extends ChiselEnum{
    val Active, Idle, Correct = Value
}


class PC_gen(parameters:Parameters) extends Module{
    import parameters._

    val io = IO(new Bundle{
        val commit                          =   Input(new commit(parameters))

        val prediction  = Flipped(Decoupled(new prediction(parameters)))           // BTB response
        val RAS_read    = Flipped(new RAS_read(parameters))
        // TODO: Exception:...                                                     // exception

        val PC_next     = Decoupled(new memory_request(parameters))
    })

    dontTouch(io)

    val PC                 = RegInit(UInt(32.W), startPC.asUInt)

    val use_BTB            = Wire(Bool())
    val use_RAS            = Wire(Bool())


    val is_branch        = Wire(Bool())
    val is_jalr          = Wire(Bool())
    val is_ret           = Wire(Bool())

    val misprediction               = Wire(Bool())
    //val exception                   = Wire(Bool())

    val instruction_index_within_packet =   Wire(UInt(log2Ceil(fetchWidth).W))
    val PC_increment                    =   Wire(UInt((log2Ceil(fetchWidth)+3).W))


    is_branch           := (io.prediction.bits.br_type === _br_type.BR)     && io.prediction.valid
    is_jalr             := (io.prediction.bits.br_type === _br_type.JALR)   && io.prediction.valid
    is_ret              := (io.prediction.bits.br_type === _br_type.RET)    && io.prediction.valid

    use_BTB             := (io.prediction.bits.hit && io.prediction.valid && !is_ret)
    use_RAS             := is_ret

    misprediction       := io.commit.is_misprediction && io.commit.valid


    instruction_index_within_packet := ( io.PC_next.bits.addr >> log2Ceil(fetchWidth))
    PC_increment    :=  (fetchWidth.U - instruction_index_within_packet) << log2Ceil(fetchWidth)


    when(io.PC_next.fire){
        PC := io.PC_next.bits.addr + PC_increment
    }

    // output stage
    when(misprediction){
        io.PC_next.bits.addr := io.commit.expected_PC
        io.PC_next.valid    := 1.B
    }.elsewhen(use_BTB){
        io.PC_next.bits.addr := io.prediction.bits.target
        io.PC_next.valid    := 1.B
    }.elsewhen(use_RAS){
        io.PC_next.valid    := 1.B
        io.PC_next.bits.addr := io.RAS_read.ret_addr
    }.otherwise{    // use correction address
        io.PC_next.valid    := 1.B
        io.PC_next.bits.addr := PC
    }






    /////////////////////////
    // valid/ready control //
    /////////////////////////

    io.PC_next.bits.wr_data := 0.U
    io.PC_next.bits.wr_en := 0.B

    io.prediction.ready := 1.B

}
