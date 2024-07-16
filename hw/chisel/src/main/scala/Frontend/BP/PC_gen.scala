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


class PC_gen(parameters:Parameters) extends Module{
    import parameters._

    val io = IO(new Bundle{
        val commit                          =   Flipped(ValidIO(new commit(parameters)))
        val revert                          =   Flipped(ValidIO(new revert(parameters)))

        val prediction                      =   Flipped(Decoupled(new prediction(parameters)))           // BTB response
        val RAS_read                        =   Flipped(new RAS_read(parameters))
        // TODO: Exception:...                                                     // exception

        val PC_next                         =   Decoupled(new memory_request(parameters))
    })

    dontTouch(io)

    val PC                 = RegInit(UInt(32.W), startPC.asUInt)

    val use_BTB            = Wire(Bool())
    val use_RAS            = Wire(Bool())


    val is_branch        = Wire(Bool())
    val is_jalr          = Wire(Bool())
    val is_ret           = Wire(Bool())

    //val exception                   = Wire(Bool())

    val instruction_index_within_packet =   Wire(UInt(log2Ceil(fetchWidth).W))
    val PC_increment                    =   Wire(UInt(32.W))



    is_branch           := (io.prediction.bits.br_type === br_type_t.BR)     && io.prediction.valid
    is_jalr             := (io.prediction.bits.br_type === br_type_t.JALR)   && io.prediction.valid
    is_ret              := (io.prediction.bits.br_type === br_type_t.RET)    && io.prediction.valid

    use_BTB             := (io.prediction.bits.hit && io.prediction.valid && !is_ret)
    use_RAS             := is_ret




    instruction_index_within_packet := ( io.PC_next.bits.addr >> log2Ceil(fetchWidth))
    PC_increment    :=  (fetchWidth.U - instruction_index_within_packet) << log2Ceil(fetchWidth)


    // output stage

    io.PC_next.bits.addr := 0.B
    io.PC_next.valid     := 0.B



    when(io.PC_next.fire){
        PC := io.PC_next.bits.addr + PC_increment
    }




    val PC_next = Wire(Decoupled(new memory_request(parameters)))
    PC_next := 0.U.asTypeOf(Decoupled(new memory_request(parameters)))

    val flush = io.commit.bits.is_misprediction && io.commit.valid

    when(flush){
        PC_next.bits.addr     := io.commit.bits.fetch_PC 
    }.elsewhen(io.revert.valid){
        PC_next.bits.addr     := io.revert.bits.PC
        PC_next.valid         := 1.B && !flush
    }.otherwise{
        when(use_BTB){
            PC_next.bits.addr := io.prediction.bits.target
            PC_next.valid     := 1.B && !flush
        }.elsewhen(use_RAS){
            PC_next.bits.addr := io.RAS_read.ret_addr
            PC_next.valid     := 1.B && !flush
        }.otherwise{
            PC_next.bits.addr := PC
            PC_next.valid     := 1.B && !flush
        }
    }

    PC_next.ready <> io.PC_next.ready


    // Buffer output


    val PC_next_skid_buffer  = Module(new Queue(new memory_request(parameters), 1, flow=true, hasFlush=false, useSyncReadMem=false))

    PC_next_skid_buffer.io.enq <> PC_next
    PC_next_skid_buffer.io.deq <> io.PC_next
    io.PC_next.valid := PC_next_skid_buffer.io.deq.valid && !flush

    /////////////////////////
    // valid/ready control //
    /////////////////////////
    io.prediction.ready := io.PC_next.ready


    ////////////
    // FORMAL //
    ////////////

    // PROPERTY: if not mispred, revert, pred, and previous pc was accepted, output should be prev PC + 16
    val PC_16_pre: Sequence         = io.PC_next.ready && !io.commit.valid && !io.revert.valid && !io.prediction.valid
    val PC_16_post: Sequence        = io.PC_next.bits.addr === (RegNext(io.PC_next.bits.addr & "hFFFF_FFF0".U) + 16.U)
    val normal_valid: Property      = PC_16_pre |-> PC_16_post


    // PROPERTY: if ret, jump to ret addr
    val RET_pre: Sequence                = io.PC_next.ready && !io.commit.valid && !io.revert.valid && io.prediction.valid && (io.prediction.bits.br_type === br_type_t.RET)
    val RET_post: Sequence               = io.PC_next.bits.addr ===  io.RAS_read.ret_addr
    val RET_property: Property           = RET_pre |-> RET_post

    // PROPERTY: if revert, jump to revert
    val revert_pre: Sequence                = io.PC_next.ready && !io.commit.valid && io.revert.valid && !io.prediction.valid
    val revert_post: Sequence               = io.PC_next.bits.addr ===  io.RAS_read.ret_addr
    val revert_property: Property           = revert_pre |-> revert_post


    // PROPERTY: priority


    // PROPERTY: output is invalid during flush
    val flush_pre: Sequence                = io.commit.valid && io.commit.bits.is_misprediction
    val flush_post: Sequence               = io.PC_next.valid === 0.B
    val flush_property: Property           = flush_pre |-> flush_post


    AssertProperty(normal_valid)
    AssertProperty(RET_property)
    AssertProperty(revert_property)
    AssertProperty(flush_property)


    CoverProperty(normal_valid)
    CoverProperty(RET_property)
    CoverProperty(revert_property)
    CoverProperty(flush_property)






    // ASSUMPTION: 
    val no_commit: Sequence         = io.commit.valid === 0.B
    val no_revert: Sequence         = io.revert.valid === 0.B
    val no_prediction: Sequence     = io.prediction.valid === 0.B
    val output_ready: Sequence      = io.PC_next.ready === 0.B
    //AssumeProperty(no_commit)
    //AssumeProperty(no_revert)
    //AssumeProperty(no_prediction)
    AssumeProperty(output_ready)

}
