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
        val predict     = Flipped(Decoupled(UInt(32.W)))

        // Commit Channel 
        val commit                          =   Input(Vec(commitWidth, new commit(parameters)))

        // common case. Update BTB, PHT

        // Mispredict Channel 
        //val mispredict  = Flipped(Decoupled(new mispredict(GHRWidth=GHRWidth, RASEntries=RASEntries)))

        // Revert Channel
        val RAS_update  = Input(new RAS_update)

        // RAS Channel
        val RAS_read    = Output(new RAS_read(parameters))

        // GHR Channel
        val revert      = Flipped(Decoupled(new revert(parameters)))

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

    val GHR_reg = RegInit(UInt(GHRWidth.W),0.U)
    val GHR = Wire(UInt(GHRWidth.W))

    val gshare = Module(new gshare(parameters)) // FIXME: should this be addressed by the PC or by the fetch packet aligned PC?
    val BTB = Module(new hash_BTB(parameters))
    val RAS = Module(new RAS(parameters))

    ///////////////
    // GHR LOGIC //
    ///////////////

    val GHR_update = Wire(Bool())
    val misprediction = Wire(Bool());                   misprediction := 0.U
    val misprediction_GHR = Wire(UInt(GHRWidth.W));     misprediction_GHR := 0.U

    val misprediction_TOS   = Wire(UInt(log2Ceil(RASEntries).W));   misprediction_TOS := 0.U
    val misprediction_NEXT  = Wire(UInt(log2Ceil(RASEntries).W));   misprediction_NEXT := 0.U

    val revert = Wire(Bool())


    for(i <- commitWidth-1 to 0 by -1){
        when(io.commit(i).is_misprediction){
            misprediction       :=  1.B
            misprediction_GHR   :=  io.commit(i).GHR

            misprediction_TOS   :=  io.commit(i).TOS
            misprediction_NEXT  :=  io.commit(i).NEXT
        }
    }


    revert := io.revert.valid

    // Update GHR whenever the BTB indates a branch
    GHR_update := gshare.io.valid && BTB.io.BTB_valid && BTB.io.BTB_hit && (BTB.io.BTB_type === 0.U)


    val otherwise = Wire(Bool())

    otherwise := 0.B

    when(misprediction){   // During mispredic, use input GHR
        GHR := misprediction_GHR
    }.elsewhen(revert){ // Same for revert
        GHR := io.revert.bits.GHR
        //GHR := 0x42.U
    }.elsewhen(GHR_update){
        GHR := (GHR_reg << 1) | gshare.io.T_NT.asUInt
        //GHR := 0x42.U
    }.otherwise{        // Otherwise, GHR comes from the actual GHR reg
        GHR := GHR_reg
    }

    GHR_reg := GHR
    io.prediction.bits.GHR := GHR_reg
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
    val revert_RAS = Wire(Bool())
    val revert_GHR = Wire(Bool())



    update_BTB := io.commit.map(c => c.T_NT && c.valid).reduce(_ || _)
    update_PHT := io.commit.map(c => c.is_BR && c.valid).reduce(_ || _)
    update_RAS := !misprediction



    //update_BTB := io.commit.bits.T_NT && io.commit.valid                                    // Only update when the branch is found taken
    //update_PHT := io.commit.bits.is_BR && io.commit.valid                                 // BTB only updates on conditional branches
    //update_RAS := !misprediction                                                            // RAS can only push/pop when not misprediction
    revert_GHR := misprediction || (io.revert.valid)
    revert_RAS := misprediction

    /////////////////
    // Init gshare //
    /////////////////

    // predict port
    gshare.io.predict_GHR               := GHR
    gshare.io.predict_PC                := io.predict.bits
    gshare.io.predict_valid             := io.predict.valid

    gshare.io.commit_GHR                := 0.U
    gshare.io.commit_PC                 := 0.U
    gshare.io.commit_branch_direction   := 0.U

    // commit port

    for(i <- 0 until commitWidth){
        when(io.commit(i).is_BR && io.commit(i).valid){
            gshare.io.commit_GHR                := io.commit(i).GHR
            gshare.io.commit_PC                 := io.commit(i).instruction_PC
            gshare.io.commit_branch_direction   := io.commit(i).T_NT
        }
    }

    gshare.io.commit_valid              := update_PHT



    //////////////
    // Init BTB //
    //////////////
    // Reminder: BTB only updates on taken branches...

    // predict port
    BTB.io.predict_PC               := io.predict.bits
    BTB.io.predict_valid            := io.predict.valid

    BTB.io.commit_PC                :=   0.U
    BTB.io.commit_target            :=   0.U

    // commit port

    //BTB.io.commit_PC                :=   io.commit.bits.instruction_PC
    //BTB.io.commit_target            :=   io.commit.bits.expected_PC
    
    for(i <- 0 until commitWidth){
        when(io.commit(i).is_BR && io.commit(i).valid){
            BTB.io.commit_PC                :=   io.commit(i).instruction_PC
            BTB.io.commit_target            :=   io.commit(i).expected_PC
        }
    }

    BTB.io.commit_br_type           :=   DontCare // FIXME: what branch type to place in BTB? this should come from FTQ/ROB
    //io.commit.bits.br_type
    BTB.io.commit_br_mask           :=   DontCare //FIXME: this does nothing right now
    //io.commit.bits.br_mask
    BTB.io.commit_valid             :=   update_BTB

    ///////////////////////////////
    // Init Return-Address-Stack //
    ///////////////////////////////
    
    // handle misprediction
    RAS.io.revert_NEXT  :=   misprediction_NEXT
    RAS.io.revert_TOS   :=   misprediction_TOS
    RAS.io.revert_valid :=   revert_RAS

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
    io.prediction.bits.target    := BTB.io.BTB_target
    io.prediction.bits.br_type   := BTB.io.BTB_type
    io.prediction.bits.br_mask   := BTB.io.BTB_br_mask
    io.prediction.bits.hit       := BTB.io.BTB_hit
    //io.prediction.bits.GHR       := GHR
    io.prediction.bits.T_NT      := gshare.io.T_NT

    // FIXME: stall on revert...
    //io.predict.ready        := io.prediction.ready     // if cant output prediction, cannot receive new prediction
    io.predict.ready        := io.prediction.ready && !(misprediction || revert)   // 1 cycle stall on mispredict or revert
    io.prediction.valid     := (BTB.io.BTB_valid && gshare.io.valid)


    io.revert.ready := 1.B

}