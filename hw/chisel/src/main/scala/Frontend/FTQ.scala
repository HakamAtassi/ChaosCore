/* ------------------------------------------------------------------------------------
* Filename: FTQ.scala
* Author: Hakam Atassi
* Date: May 29 2024
* Description: A buffer that stores results of branches as they are made in the frontend. 
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
import chisel3.util._


// FTQ is a queue implemented in registers that buffers the results of predictions in the frontend
// Predictions are buffered in the order they are made.
// On branch resolutions, the prediction result is sent to this FTQ
// Where the frontend is checked for Mispredictions.
// On a commit, redirect frontend as needed
// TODO: what happens to ROB after a mispredict?
class FTQ(coreParameters:CoreParameters) extends Module{
    import coreParameters._
    val portCount = getPortCount(coreParameters)

    val io = IO(new Bundle{
        // FLUSH //
        val flush               =   Input(Bool())

        // UPDATE //
        val FU_outputs          =   Vec(portCount, Flipped(ValidIO(new FU_output(coreParameters))))

        // PREDICTIONS //
        val predictions         =   Flipped(Decoupled(new FTQ_entry(coreParameters)))
        val ROB_index          =    Input(UInt(log2Ceil(ROBEntries).W))

        // COMMIT // 
        val commit              =   Flipped(ValidIO(new commit(coreParameters)))

        // FTQ //
        val FTQ                 =   Output(new FTQ_entry(coreParameters))
        val FTQ_index           =   Output(UInt(log2Ceil(FTQEntries).W))
    })

    val pointer_bits = log2Ceil(FTQEntries)+1


    val front_pointer   = RegInit(UInt(pointer_bits.W), 0.U)
    val back_pointer    = RegInit(UInt(pointer_bits.W), 0.U)

    val front_index =  front_pointer(pointer_bits-2, 0)
    val back_index  = back_pointer(pointer_bits-2, 0)


    val FTQ = RegInit(VecInit(Seq.fill(FTQEntries)(0.U.asTypeOf(new FTQ_entry(coreParameters)))))



    // whenever input branch is valid, try to write to FTQ

    // whenever FU_outputs is valid and has a branch (can only have 1 branch)
    // update that FTQ entry (it is not possible for an FU output result to not be in FTQ)

    // On ROB, if commiting instruction is a branch, dequeue FTQ and handle commit as needed
    // If commiting instruction is not a branch, FTQ is not changed. 


    /////////////////////////////
    // BACKEND POINTER CONTROL //
    /////////////////////////////
    
    when(io.predictions.valid && io.predictions.ready){
        FTQ(back_index)             := io.predictions.bits
        FTQ(back_index).ROB_index   := io.ROB_index
        FTQ(back_index).valid       := 1.B
        back_pointer := back_pointer + 1.U
    }



    //////////////////////
    // BACKEND UPDATES  //
    //////////////////////

    // maintain the status of branch instructions/resolution in the FTQ


    // How do you determine the actual next address of a fetch packet?
    // By finding the earliest taken branch in the fetch packet, if any


    val FTQ_index               = (io.FU_outputs(0).bits.FTQ_index)
    val is_valid                = io.FU_outputs(0).valid   
    val is_branch               = io.FU_outputs(0).bits.branch_valid
    val is_taken                = io.FU_outputs(0).bits.branch_taken
    val is_more_dominant        = (io.FU_outputs(0).bits.fetch_packet_index <= FTQ(FTQ_index).dominant_index)
    // Everytime a branch is resolved in the FU, check if it is the most dominant taken branch in the fetch packet. 

    when(is_valid && is_branch && is_more_dominant && is_taken){
        FTQ(FTQ_index).dominant_index   :=   io.FU_outputs(0).bits.fetch_packet_index
        FTQ(FTQ_index).resolved_PC      :=   io.FU_outputs(0).bits.target_address
        FTQ(FTQ_index).T_NT             :=   1.B
        // FIXME: other signals?
    }

    ///////////////////////////
    // FRONT POINTER CONTROL //
    ///////////////////////////

    //val ROB_match = io.commit.bits. === front_pointer
    val ROB_match = (FTQ(front_index).ROB_index === io.commit.bits.ROB_index)

    val dq = FTQ(front_index).valid && io.commit.valid && ROB_match

    dontTouch(dq)

    when(dq){
        FTQ(front_index) := 0.U.asTypeOf(new FTQ_entry(coreParameters))
        front_pointer := front_pointer + 1.U
    }

    when(io.flush){
        for(i <- 0 until FTQEntries){
            FTQ(i) := 0.U.asTypeOf(0.U.asTypeOf(new FTQ_entry(coreParameters)))
        }
        front_pointer := 0.B
        back_pointer := 0.B
    }

    // FIXME: predictor needs to output the default dominant index as fetchWidth - 1, and the default taken address as fetch pc + 16

    ////////////////////
    // ASSIGN OUTPUTS //
    ////////////////////

    io.FTQ := FTQ(front_index)
    io.FTQ_index := back_index

    /////////////////
    // VALID/READY //
    /////////////////

    dontTouch(front_index)
    dontTouch(back_index)

    val full = (front_pointer(pointer_bits-1) =/= back_pointer(pointer_bits-1)) && (front_index === back_index)

    io.predictions.ready := !full


}


