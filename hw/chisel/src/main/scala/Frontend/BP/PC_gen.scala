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

class PC_gen(parameters:Parameters) extends Module{
    import parameters._

    val io = IO(new Bundle{
        val commit                          =   Input(new commit(parameters))


        val prediction  = Flipped(Decoupled(new prediction(parameters)))                         // BTB response
        val revert      = Flipped(Decoupled(new revert(parameters)))                                                    // Pre-decoder revert request
        val RAS_read    = Flipped(new RAS_read(parameters))
        // TODO: Exception:...                                                                            // exception

        val PC_next     = Decoupled(new memory_request(parameters))
    })

    dontTouch(io)

    val PC                 = RegInit(UInt(32.W), startPC.asUInt)
    val correction_address = Wire(UInt(32.W))
    val correction_address_reg = RegInit(UInt(32.W), 0.U)

    val use_BTB            = Wire(Bool())
    val use_RAS            = Wire(Bool())
    val use_next_PC        = Wire(Bool())

    val use_misprediction_PC        = Wire(Bool())
    val use_revert_PC               = Wire(Bool())
    //val use_exception_PC            = Wire(Bool())

    val is_branch        = Wire(Bool())
    val is_jalr          = Wire(Bool())
    val is_ret           = Wire(Bool())

    val correct_stage_active        = Wire(Bool())
    val misprediction               = Wire(Bool())
    val reversion                   = Wire(Bool())
    //val exception                   = Wire(Bool())

    val instruction_index_within_packet =   Wire(UInt(log2Ceil(fetchWidth).W))
    val PC_increment                    =   Wire(UInt((log2Ceil(fetchWidth)+3).W))

    ////////////
    // PC REG //
    ////////////

    when(correct_stage_active){
        PC := correction_address
    }.elsewhen(io.PC_next.valid){
        PC := io.PC_next.bits.addr + PC_increment
    }.otherwise{
        PC := PC
    }

    dontTouch(PC)
    //////////////////
    // Assign wires //
    //////////////////
    correct_stage_active := misprediction || reversion /*|| exception */
    misprediction        := io.commit.is_misprediction && io.commit.valid

    
    reversion            := io.revert.valid

    is_branch := io.prediction.bits.br_type === _br_type.BR
    is_jalr   := io.prediction.bits.br_type === _br_type.JALR  // FIXME: idk how jalr helps and what its encoded as in the btb...
    is_ret    := io.prediction.bits.br_type === _br_type.RET

    use_misprediction_PC   := misprediction
    //use_exception_PC       := exception
    use_revert_PC          := reversion

    dontTouch(use_revert_PC)

    use_BTB           := (io.prediction.valid && io.prediction.bits.hit && (!is_ret)) && !correct_stage_active  // use BTB BR
    use_RAS           := is_ret && !correct_stage_active
    use_next_PC       := !correct_stage_active

    correct_stage_active := (misprediction || reversion /* exception */)
    
    ///////////////////////////
    // Generate PC increment //
    ///////////////////////////

    instruction_index_within_packet := (io.PC_next.bits.addr >> 2.U)
    PC_increment    :=  (fetchWidth.U - instruction_index_within_packet) << 2.U

    val expected_PC = Wire(UInt(32.W))

    expected_PC :=  0.U
    when(io.commit.valid && io.commit.is_misprediction){
        expected_PC := io.commit.expected_PC
    }


    //////////////////////
    // correction stage //
    //////////////////////
    when(use_revert_PC){
        correction_address := io.revert.bits.PC
    }
    //.elsewhen(use_exception_PC){  // FIXME: 
        //correction_address := io.commit.bits.PC
    //}
    .elsewhen(use_misprediction_PC){
        correction_address := expected_PC
    }
    .otherwise{
        correction_address := 0.U
    }

    dontTouch(correction_address)

    correction_address_reg := correction_address


    // output stage
    // FIXME: this priority needs to be swapped
    when(RegNext(correct_stage_active)){
        io.PC_next.bits.addr := correction_address_reg
    }.elsewhen(use_BTB){
        io.PC_next.bits.addr := io.prediction.bits.target
    }.elsewhen(use_RAS){
        io.PC_next.bits.addr := io.RAS_read.ret_addr
    }.otherwise{    // use correction address
        io.PC_next.bits.addr := PC
    }

    /////////////////////////
    // valid/ready control //
    /////////////////////////

    io.PC_next.valid := !(correct_stage_active) && io.PC_next.ready
    io.PC_next.bits.wr_data := 0.U
    io.PC_next.bits.wr_en := 0.B
    //FIXME: ready does not do anything at the moment.

    io.prediction.ready := 1.B
    io.revert.ready := 1.B

}

// FIXME: this module is missing fire()