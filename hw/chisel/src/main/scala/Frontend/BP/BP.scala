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

package ChaosCore

import chisel3._
import circt.stage.ChiselStage 
import chisel3.util._
import java.io.{File, FileWriter}
import java.rmi.server.UID

class BP(coreParameters:CoreParameters) extends Module{
    import coreParameters._
    val io = IO(new Bundle{
        // Flush
        val flush       = Input(Bool())

        // Predict Channel
        val predict     = Flipped(Decoupled(new frontend_memory_request(coreParameters)))    // PC input

        // Commit Channel 
        val commit      = Flipped(ValidIO(new commit(coreParameters)))

        // Revert Channel
        val RAS_update  = Input(new RAS_update)

        // RAS Channel
        val RAS_read    = Output(new RAS_read(coreParameters))

        // GHR Channel
        val GHR         = Input(UInt(GHRWidth.W))

        // Prediction Channel (output)
        val prediction  = Decoupled(new prediction(coreParameters))    // Output of predictions
    })

    ////////////////////
    // OUTPUT BUNDLES //
    ////////////////////
    val prediction = Wire(Decoupled(new prediction(coreParameters)))

    /////////////
    // MODULES //
    /////////////
    val gshare      = Module(new gshare(coreParameters)) // FIXME: should this be addressed by the PC or by the fetch packet aligned PC?
    val BTB         = Module(new hash_BTB(coreParameters))
    val RAS         = Module(new RAS(coreParameters))

    ///////////////
    // GHR LOGIC //
    ///////////////
    val misprediction       = Wire(Bool());                         misprediction := 0.U

    val misprediction_TOS   = Wire(UInt(log2Ceil(RASEntries).W));   misprediction_TOS := 0.U
    val misprediction_NEXT  = Wire(UInt(log2Ceil(RASEntries).W));   misprediction_NEXT := 0.U

    misprediction       :=  io.commit.bits.is_misprediction

    misprediction_TOS   :=  io.commit.bits.TOS
    misprediction_NEXT  :=  io.commit.bits.NEXT

    //////////////////
    // Commit logic //
    //////////////////
    // PHT => updates on cond branches, correct or incorrect
    // BTB => updates on truely taken branches
    // GHR => updates speculatively. Reverts on reverts from predecoder or mispredictions
    // RAS => updates speculatively. Reverts on mispredictions

    val update_BTB = Wire(Bool())
    val update_PHT = Wire(Bool())
    val update_RAS = Wire(Bool())

    // BTB and PHT are updated for ALL taken branches
    // Regardless of type (BT, JAL, etc...)
    update_BTB := io.commit.bits.T_NT && io.commit.valid
    update_PHT := (io.commit.bits.br_type =/= br_type_t.NONE) && io.commit.valid
    update_RAS := !misprediction


    /////////////////
    // Init gshare //
    /////////////////
    // predict port
    gshare.io.predict_GHR               := io.GHR
    gshare.io.predict_PC                := io.predict.bits.addr
    gshare.io.predict_valid             := io.predict.valid

    // commit port
    gshare.io.commit                <> io.commit
    gshare.io.commit.valid          := update_PHT

    //////////////
    // Init BTB //
    //////////////
    // Reminder: BTB only updates on taken branches...
    // predict port
    BTB.io.predict_PC                       := io.predict.bits.addr
    BTB.io.predict_valid                    := io.predict.valid

    // commit port
    BTB.io.commit           <>  io.commit
    BTB.io.commit.valid     :=  update_BTB

    ///////////////////////////////
    // Init Return-Address-Stack //
    ///////////////////////////////
    // handle misprediction
    RAS.io.revert_NEXT  :=   misprediction_NEXT
    RAS.io.revert_TOS   :=   misprediction_TOS
    RAS.io.revert_valid :=   misprediction

    // update port
    RAS.io.wr_addr      := io.RAS_update.call_addr
    RAS.io.wr_valid     := io.RAS_update.call && update_RAS
    RAS.io.rd_valid     := io.RAS_update.ret  && update_RAS

    // Assign outputs

    // RAS
    io.RAS_read.ret_addr := RAS.io.ret_addr
    io.RAS_read.NEXT     := RAS.io.NEXT
    io.RAS_read.TOS      := RAS.io.TOS

    // BTB
    // FIXME: something needs to be added here to ensure that predictions after 
    // A replated mispredicted packet are correct...

    prediction.bits.target    := BTB.io.BTB_output.BTB_target
    prediction.bits.br_type   := BTB.io.BTB_output.BTB_br_type
    prediction.bits.hit       := BTB.io.BTB_hit
    prediction.bits.T_NT      := gshare.io.T_NT

    prediction.valid        := RegNext(io.predict.valid && !io.flush) //BTB.io.BTB_output.valid && gshare.io.valid
    prediction.ready        := io.prediction.ready

    io.prediction <> prediction


    /////////////////
    // SKID BUFFER //
    /////////////////
    val prediction_skid_buffer      = Module(new Queue(new prediction(coreParameters), 1, flow=true, hasFlush=true, useSyncReadMem=false))

    prediction_skid_buffer.io.enq                  <> prediction
    prediction_skid_buffer.io.deq                  <> io.prediction
    prediction_skid_buffer.io.flush.get            := io.flush

    io.predict.ready        := io.prediction.ready

}