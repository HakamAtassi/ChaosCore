/* ------------------------------------------------------------------------------------
* Filename: BP.scala
* Author: Hakam Atassi
* Date: Apr 26 2024
* Description: A wrapper for the primary branch prediction structures (ie, RAS, BTB, GSHARE, GHR)
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

class BP(GHRWidth:Int = 16, fetchWidth:Int = 4, RASEntries:Int=128, BTBEntries:Int = 4096) extends Module{
    val io = IO(new Bundle{
        // Predict Channel
        val predict     = Flipped(Decoupled(UInt(32.W)))

        // Commit Channel 
        val commit      = Flipped(Decoupled(new commit(fetchWidth=fetchWidth))) // common case. Update BTB, PHT

        // Mispredict Channel 
        val mispredict  = Flipped(Decoupled(new mispredict(GHRWidth=GHRWidth, RASEntries=RASEntries)))

        // Revert Channel
        val RAS_update  = new RAS_update    // input

        // RAS Channel
        val RAS_read    = new RAS_read(RASEntries=RASEntries)   // output

        // GHR Channel
        val revert      = Flipped(Decoupled(new revert(GHRWidth=GHRWidth)))

        // Prediction Channel (output)
        val prediction  = Decoupled(new prediction(fetchWidth=fetchWidth, GHRWidth=GHRWidth))    // Output of predictions
    })


    val GHR = RegInit(UInt(GHRWidth.W),0.U)
    /////////////////
    // Init gshare //
    /////////////////
    val gshare = Module(new gshare(GHR_width=GHRWidth))

    // predict port
    gshare.io.predict_GHR               := GHR
    gshare.io.predict_PC                := io.predict.bits
    gshare.io.predict_valid             := io.predict.valid

    // commit port
    gshare.io.commit_GHR                := io.commit.bits.GHR
    gshare.io.commit_PC                 := io.commit.bits.PC
    gshare.io.commit_branch_direction   := io.commit.bits.T_NT

    gshare.io.commit_valid              := io.commit.valid

    //////////////
    // Init BTB //
    //////////////
    val BTB = Module(new hash_BTB(entries=BTBEntries))
    // Reminder: BTB only updates on taken branches...

    // predict port
    BTB.io.predict_PC       := io.predict.bits
    BTB.io.predict_valid    := io.predict.valid

    // FIXME: this updates blindly. Where is taken only commit handled?????
    // FIXME: commit_tag not done.
    // commit port
    BTB.io.commit_PC               := io.commit.bits.PC
    
    BTB.io.commit_target           :=   io.commit.bits.target
    BTB.io.commit_br_type          :=   io.commit.bits.br_type
    BTB.io.commit_br_mask          :=   io.commit.bits.br_mask
    

    BTB.io.commit_valid            :=   io.commit.valid


    ///////////////////////////////
    // Init Return-Address-Stack //
    ///////////////////////////////
    val RAS = Module(new RAS(entries=RASEntries))

    RAS.io.revert_NEXT  := 0.U
    RAS.io.revert_TOS   := 0.U
    RAS.io.revert_valid := 0.U

    RAS.io.wr_addr      := 0.U
    RAS.io.wr_valid     := 0.U
    RAS.io.rd_valid     := 0.U


    when(io.mispredict.valid){  // if mispred, handle mispred...
        // mispredict port
        RAS.io.revert_NEXT  :=   io.mispredict.bits.NEXT
        RAS.io.revert_TOS   :=   io.mispredict.bits.TOS
        RAS.io.revert_valid :=   io.mispredict.valid
    }.otherwise{
        // update port
        RAS.io.wr_addr      := io.RAS_update.call_addr
        RAS.io.wr_valid     := io.RAS_update.call
        RAS.io.rd_valid     := io.RAS_update.ret
    }

    /////////
    // GHR //
    /////////
    
    val is_cond_branch = 0.U
        //BTB.io.valid   // FIXME: not implemented

    when(io.mispredict.valid){
        GHR := io.mispredict.bits.GHR
    }.elsewhen(io.revert.valid){
        GHR := io.revert.bits.GHR
    }.otherwise{
        GHR := (GHR<<1) | (is_cond_branch & gshare.io.T_NT.asUInt)
    }


    // Assign outputs

    // RAS
    io.RAS_read.ret_addr := RAS.io.ret_addr
    io.RAS_read.NEXT     := RAS.io.NEXT
    io.RAS_read.TOS      := RAS.io.TOS

    // BTB
    io.prediction.bits.target    := BTB.io.BTB_target
    io.prediction.bits.br_type   := BTB.io.BTB_type
    io.prediction.bits.br_mask   := BTB.io.BTB_br_mask
    io.prediction.bits.hit       := BTB.io.BTB_hit
    io.prediction.bits.GHR       := GHR
    io.prediction.bits.T_NT      := gshare.io.T_NT

    io.predict.ready        := io.prediction.ready     // if cant output prediction, cannot receive new prediction
    io.prediction.valid     := (BTB.io.BTB_valid && gshare.io.valid)


    io.commit.ready := 1.B
    io.mispredict.ready := 1.B
    io.revert.ready := 1.B

}