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
// On a misprediction, redirect frontend as needed
// TODO: what happens to ROB after a mispredict?
class FTQ(parameters:Parameters) extends Module{
    import parameters._
    val portCount = getPortCount(parameters)

    val io = IO(new Bundle{

        //// Inputs

        // From Backend (update FTQ entires)
        val FU_output                  =   Input(new FU_output(parameters))    // To update FTQ

        // From frontend/predecoder (append FTQ entries)
        val branch_prediction           =   Flipped(Decoupled((new FTQ_entry(parameters))))

        // From ROB    (commit & check mispred)
        val commit                      =   Input(new ROB_entry(parameters))

        // Clear, etc...

        //// Output 
        val misprediction               =   Output(new misprediction(parameters))
    })

    val pointer_bits = log2Ceil(FTQEntries)+1


    val front_pointer   = RegInit(UInt(pointer_bits.W), 0.U)
    val back_pointer    = RegInit(UInt(pointer_bits.W), 0.U)

    val front_index = front_pointer(pointer_bits-2, 0)
    val back_index  = back_pointer(pointer_bits-2, 0)


    val FTQ = RegInit(VecInit(Seq.fill(FTQEntries)(0.U.asTypeOf(new FTQ_entry(parameters)))))


    // whenever input branch is valid, try to write to FTQ

    // whenever FU_outputs is valid and has a branch (can only have 1 branch)
    // update that FTQ entry (it is not possible for an FU output result to not be in FTQ)

    // On commit, if commiting instruction is a branch, dequeue FTQ and handle misprediction as needed
    // If commiting instruction is not a branch, FTQ is not changed. 


    /////////////////////
    // FRONTEND UPDATE //
    /////////////////////
    
    when(io.branch_prediction.valid){
        FTQ(back_index)   := io.branch_prediction.bits
        back_pointer        := back_pointer + 1.U
    }

    //////////////////
    // COMMIT LOGIC //
    //////////////////

    // Determine whether or not to flush pipeline
    
    val front_element_valid = FTQ(front_index).valid
    val commit_is_branch    = io.commit.is_branch && io.commit.valid
    
    io.misprediction.valid              := commit_is_branch
    io.misprediction.is_misprediction   := commit_is_branch && FTQ(front_index).valid && FTQ(front_index).is_misprediction

    io.misprediction.NEXT             := FTQ(front_index).NEXT
    io.misprediction.TOS              := FTQ(front_index).TOS
    io.misprediction.GHR              := FTQ(front_index).GHR

    io.misprediction.expected_PC      := 0.U


    when(front_element_valid && commit_is_branch){ // when front element is valid and commiting instruction is a branch, dequeue
        front_pointer := front_pointer + 1.B    // dequeue element
        FTQ(front_index) := 0.U.asTypeOf(new FTQ_entry(parameters))
    }

    //////////////////////
    // BACKEND UPDATES  //
    //////////////////////

    // Update FTQ entries from backend
    // likely 1 instruction every cycle-ish

    for(i <- 0 until FTQEntries){
        val instruction_PC_match = (FTQ(i).instruction_PC === io.FU_output.instruction_PC) && FTQ(i).valid
        when(instruction_PC_match){
            FTQ(i).is_misprediction := FTQ(i).predicted_expected_PC =/= io.FU_output.target_address
            FTQ(i).predicted_expected_PC := io.FU_output.target_address
        }
        
    }


    /////////////////
    // VALID/READY //
    /////////////////

    // Stall when full (not ready)

    val full = (front_index === back_index) && (front_pointer =/= back_pointer)
    io.branch_prediction.ready := !full


}


