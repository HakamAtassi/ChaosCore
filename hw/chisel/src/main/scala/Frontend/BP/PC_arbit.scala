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
        val commit      = Flipped(Decoupled(new commit(fetchWidth=4, GHRWidth=16, BTBEntries=4096, RASEntries = 128)))                                  // from BROB
        val prediction  = Flipped(Decoupled(new prediction(fetchWidth=fetchWidth, GHRWidth=GHRWidth)))                         // BTB response
        val revert      = Flipped(Decoupled(new revert(GHRWidth=GHRWidth)))                                                    // Pre-decoder revert request
        val RAS_read    = Flipped(new RAS_read(RASEntries=RASEntries))
        // TODO: Exception:...                                                                            // exception

        val PC_next     = Decoupled(UInt(32.W))
    })

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

    val instruction_index_within_packet = Wire(UInt(log2Ceil(fetchWidth).W))
    val PC_increment                    =   Wire(UInt((log2Ceil(fetchWidth)+3).W))

    ////////////
    // PC REG //
    ////////////

    when(correct_stage_active){
        PC := correction_address
    }.elsewhen(io.PC_next.valid){
        PC := io.PC_next.bits + PC_increment
    }.otherwise{
        PC := PC
    }

    dontTouch(PC)
    //////////////////
    // Assign wires //
    //////////////////
    correct_stage_active := misprediction || reversion /*|| exception */
    misprediction        := io.commit.valid && io.commit.bits.misprediction
    reversion            := io.revert.valid

    is_branch := io.prediction.bits.br_type === 0.U
    is_jalr   := io.prediction.bits.br_type === 0.U  // FIXME: idk how jalr helps and what its encoded as in the btb...
    is_ret    := io.prediction.bits.br_type === 2.U

    use_misprediction_PC   := misprediction
    //use_exception_PC       := exception
    use_revert_PC          := reversion

    use_BTB           := (io.prediction.valid && io.prediction.bits.hit && (!is_ret)) && !correct_stage_active  // use BTB BR
    use_RAS           := is_ret && !correct_stage_active
    use_next_PC       := !correct_stage_active

    correct_stage_active := (misprediction || reversion /* exception */)
    
    ///////////////////////////
    // Generate PC increment //
    ///////////////////////////

    instruction_index_within_packet := (io.PC_next.bits >> 2.U)
    PC_increment    :=  (fetchWidth.U - instruction_index_within_packet) << 2.U

    dontTouch(use_BTB)
    dontTouch(use_RAS)

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
        correction_address := io.commit.bits.misprediction_PC
    }
    .otherwise{
        correction_address := 0.U
    }

    correction_address_reg := correction_address

    dontTouch(use_BTB)
    dontTouch(use_RAS)
    dontTouch(PC_increment)

    // output stage
    // FIXME: this priority needs to be swapped
    when(RegNext(correct_stage_active)){
        io.PC_next.bits := correction_address_reg
    }.elsewhen(use_BTB){
        io.PC_next.bits := io.prediction.bits.target
    }.elsewhen(use_RAS){
        io.PC_next.bits := io.RAS_read.ret_addr
    }.otherwise{    // use correction address
        io.PC_next.bits := PC
    }

    /////////////////////////
    // valid/ready control //
    /////////////////////////

    io.PC_next.valid := !(correct_stage_active)  
    //&& (!reset.asBool) // FIXME: is this okay?
    //FIXME: ready does not do anything at the moment.

    io.prediction.ready := 1.B
    io.commit.ready := 1.B
    io.revert.ready := 1.B

}