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

class BP(parameters:Parameters) extends Module{
    import parameters._
    val io = IO(new Bundle{
        // Predict Channel
        val predict     = Flipped(Decoupled(new memory_request(parameters)))

        // Commit Channel 
        val commit      = Flipped(ValidIO(new commit(parameters)))

        // Revert Channel
        val RAS_update  = Input(new RAS_update)

        // RAS Channel
        val RAS_read    = Output(new RAS_read(parameters))

        // GHR Channel
        val GHR         = Input(UInt(GHRWidth.W))

        // Prediction Channel (output)
        val prediction  = Decoupled(new prediction(parameters))    // Output of predictions
    })


    // It is assumed that whether or not the BTB is updated is controller externally.
    // That is, the BTB is only allocated with taken branches.
    //===
    // FIXME: there are 2 options here, either multiplex the GHR so that ongoing predictuions use the correct value
    // or insert a frontend bubble

    // On commits (misprediction) (predicted, actual)
        // (T / NT) 
            // GHR revert
            // RAS revert
            // PHT update
            // BTB no change
            // prediction no change (mispredict PC should be on input due to mux)
            // reverts ignored
        // (NT / T)
            // GHR revert
            // RAS revert
            // PHT update
            // BTB update
            // prediction no change (mispredict PC should be on input due to mux)
            // reverts ignored
    // On reverts (pre-decoder)
        // Commit as normal
        // Predict as normal
        // GHR revert
    // On commits (no mispredict or revert)
        // (NT / NT)
            // PHT update
            // BTB no change
        // (T / T)
            // PHT update
            // BTB update

    // predictions
    //FIXME: what needs to be muxed here?
        // valid as normal
    // reverts
        // invalid during mispredictions
        // otherwise valid
    // RAS updates
        // only valid when no mispredict or revert


    /////////////
    // MODULES //
    /////////////


    val gshare      = Module(new gshare(parameters)) // FIXME: should this be addressed by the PC or by the fetch packet aligned PC?
    val BTB         = Module(new hash_BTB(parameters))
    val RAS         = Module(new RAS(parameters))

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
    update_PHT := (io.commit.bits.br_type =/= _br_type.NONE) && io.commit.valid
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
    gshare.io.commit.valid              := update_PHT


    //////////////
    // Init BTB //
    //////////////
    // Reminder: BTB only updates on taken branches...

    // predict port
    BTB.io.predict_PC                       := io.predict.bits.addr
    BTB.io.predict_valid                    := io.predict.valid


    // commit port
    BTB.io.commit   <>  io.commit

    BTB.io.commit.valid                     :=  update_BTB

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
    io.prediction.bits.target    := BTB.io.BTB_output.BTB_target
    io.prediction.bits.br_type   := BTB.io.BTB_output.BTB_br_type
    io.prediction.bits.br_mask   := DontCare
    io.prediction.bits.hit       := BTB.io.BTB_hit
    io.prediction.bits.GHR       := io.GHR
    io.prediction.bits.T_NT      := gshare.io.T_NT

    // FIXME: stall on revert...
    io.predict.ready        := io.prediction.ready && !(misprediction )   // 1 cycle stall on mispredict or revert
    io.prediction.valid     := BTB.io.BTB_output.BTB_valid && gshare.io.valid

}