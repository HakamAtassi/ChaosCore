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

class BP(GHRWidth:Int = 16, fetchWidth:Int = 4, RASEntires:Int=128, BTBEntires:Int = 4096) extends Module{
    val io = IO(new Bundle{
        // Predict Channel
        val predict = Decoupled(Input(UInt(32.W)))

        // Commit Channel 
        val commit = Input(new commit(fetchWidth=fetchWidth)) // common case. Update BTB, PHT

        // Mispredict Channel 
        val mispredict = Input(new commit(GHRWidth=GHRWidth, RASEntires:RASEntires))

        // Revert Channel
        val RAS_update = Input(new RAS_update())

        // GHR Channel
        val revert = Input(new revert(GHRWidth=GHRWidth))

        // Prediction Channel (output)
        val prediction = Output(new prediction(fetchWidth=fetchWidth, GHRWidth=GHRWidth, RASEntires:RASEntires))    // Output of predictions
    })


    /////////////////
    // Init GHSARE //
    /////////////////
    val gshare = Module(new gshare(GHR_width=GHRWidth))

    // predict port
    gshare.io.predict_GHR               = ???
    ghsare.io.predict_PC                = 
    ghsare.io.predict_valid             =

    // commit port
    gshare.io.commit_GHR                = io.commit.GHR
    gshare.io.commit_PC                 = io.commit.PC
    gshare.io.commit_valid              = io.commit.valid
    gshare.io.commit_branch_direction   = io.T_NT

    // prediction output
    gshare.io.commit_T_NT               = 
    gshare.io.commit_valid


    //////////////
    // Init BTB //
    //////////////
    val BTB = Module(new hash_BTB(entires=BTBEntires))
    // Reminder: BTB only updates on taken branches...

    // predict port
    BTB.io.predict_PC       =
    BTB.io.predict_valid    =

    // FIXME: this updates blindly. Where is taken only commit handled?????
    // commit port
    BTB.io.commit_PC        = io.commit.PC
    // FIXME: commit_tag not done.
    BTB.io.commit_data      = Cat(1.U, commit_tag, io.commit.target, io.commit.br_type, io.commit.brMask)
    BTB.io.commit_valid     = io.commit.valid

    // output port
    BTB.io.BTB_valid
    BTB.io.BTB_target
    BTB.io.BTB_type
    BTB.io.BTB_brMask

    ///////////////////////////////
    // Init Return-Address-Stack //
    ///////////////////////////////
    val RAS = Module(new RAS(entires=RASEntires))

    // TODO: implement control...
    // update port
    RAS.io.wr_addr      = DontCare
    RAS.io.wr_valid     = DontCare
    RAS.io.rd_valid     =DontCare

    // mispredict port
    RAS.io.revert_NEXT  =DontCare
    RAS.io.revert_TOS   =   DontCare
    RAS.io.revert_valid =   DontCare

    // output port
    RAS.io.ret_addr     =DontCare
    RAS.io.ret_NEXT     =DontCare
    RAS.io.ret_TOS      =DontCare



    // Assign prediction

    // TODO: skid buffer for when not ready

}