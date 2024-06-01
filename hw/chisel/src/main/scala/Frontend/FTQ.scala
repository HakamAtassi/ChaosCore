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

        // UPDATE //
        val FU_outputs          =   Vec(portCount, Flipped(ValidIO(new FU_output(parameters))))

        // prediction //
        val prediction          =   Flipped(Decoupled(new FTQ_entry(parameters)))    // push made predictions to FTQ

        // COMMIT //
        val ROB_commit          =   Input(Vec(commitWidth, new ROB_entry(parameters)))

        // REDIRECTS // 
        val misprediction       =   Output(new misprediction(parameters))

        // FTQ //
        val FTQ                 =   Decoupled(new FTQ_entry(parameters))    // push made predictions to FTQ
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

    // On ROB_commit, if commiting instruction is a branch, dequeue FTQ and handle misprediction as needed
    // If commiting instruction is not a branch, FTQ is not changed. 


    /////////////////////
    // FRONTEND UPDATE //
    /////////////////////
    
    when(io.FTQ.valid){
        FTQ(back_index)   := io.FTQ.bits
        back_pointer      := back_pointer + 1.U
    }

    //////////////////////
    // ROB_commit LOGIC //
    //////////////////////


    // ROB_commit logic
    // The number of FTQ elements to dequeue is based on how many branches are being commited during this cycle.
    // 1 branch being commited, 1 pointer increment, N branches being commited, N pointer increment. 
    // A misprediction takes place when a commiting packet indicates a misprediction in the FTQ. 
    // If a fetch packet has multiple mispredictions (as indicated by the FTQ), only the first one is considered.
    // A misprediction also causes a complete FTQ flush


    // An important note that simplifies the FTQ greatly is that ROB_commit valid is "thermometer coded"
    // So, is either 0000, 0001, 0011, 0111, 1111, etc.
    // Which allows for FTQ pointer control to be quite simple. 

    // Determine whether or not to flush pipeline
    
    //val front_element_valid = FTQ(front_index).valid
    //val commit_is_branch    = io.ROB_commit.is_branch && io.ROB_commit.valid
    
    //io.misprediction.valid              := commit_is_branch
    //io.misprediction.is_misprediction   := commit_is_branch && FTQ(front_index).valid && FTQ(front_index).is_misprediction

    //io.misprediction.NEXT             := FTQ(front_index).NEXT
    //io.misprediction.TOS              := FTQ(front_index).TOS
    //io.misprediction.GHR              := FTQ(front_index).GHR


    //when(front_element_valid && commit_is_branch){ // when front element is valid and commiting instruction is a branch, dequeue
        //front_pointer := front_pointer + 1.B    // dequeue element
        //FTQ(front_index) := 0.U.asTypeOf(new FTQ_entry(parameters))
    //}


    //////

    val front_element_valid             = Wire(Vec(commitWidth, Bool()))
    val commit_is_branch                = Wire(Vec(commitWidth, Bool()))
    val front_element_misprediction     = Wire(Vec(commitWidth, Bool()))

    for (i <- 0 until commitWidth){
        front_element_valid(i)          :=  FTQ(front_index + i.U).valid
        front_element_misprediction(i)  :=  FTQ(front_index + i.U).is_misprediction
        commit_is_branch(i)             :=  io.ROB_commit(i).is_branch && io.ROB_commit(i).valid
    }



    io.misprediction.NEXT             := 0.U
    io.misprediction.TOS              := 0.U
    io.misprediction.GHR              := 0.U
    io.misprediction.expected_PC      := 0.U

    // Assign misprediction data based on frontmost misprediction in FTQ
    for (i <- commitWidth-1 until 0 by -1){ // find first case of misprediction in FTQ (if any)
        val is_misprediction = FTQ(front_index + i.U).is_misprediction
        when(is_misprediction){
            io.misprediction.NEXT             := FTQ(front_index + i.U).NEXT
            io.misprediction.TOS              := FTQ(front_index + i.U).TOS
            io.misprediction.GHR              := FTQ(front_index + i.U).GHR
            io.misprediction.expected_PC      := FTQ(front_index + i.U).predicted_expected_PC
        }
    }

    // Determine misprediction output
    // (when do you actually signal a misprediction to the core)
    // When at least 1 of the N frontmost elements has a misprediction, is valid, and is being commited 

    // FIXME: what on earth is this logic???
    io.misprediction.valid := (front_element_valid zip commit_is_branch zip front_element_misprediction).map {
    case ((valid, branch), misprediction) => valid && branch && misprediction
    }.reduce(_ || _)

    io.misprediction.is_misprediction := (front_element_valid zip commit_is_branch zip front_element_misprediction).map {
    case ((valid, branch), misprediction) => valid && branch && misprediction
    }.reduce(_ || _)

    // Pointer control

    val pointer_increment = Wire(UInt(log2Ceil(commitWidth + 1).W))
    pointer_increment := 0.U

    for (i <- 0 until commitWidth){
        when(front_element_valid(i) && commit_is_branch(i)){ // when front element is valid and commiting instruction is a branch, dequeue
            FTQ(front_index + i.U) := 0.U.asTypeOf(new FTQ_entry(parameters))
        }
    }

    front_pointer := front_pointer + PopCount(front_element_valid zip commit_is_branch map { case (valid, branch) => valid && branch })


    //////////////////////
    // BACKEND UPDATES  //
    //////////////////////

    // Update FTQ entries from backend
    // likely 1 instruction every cycle-ish
    // This does not need to be done combinationally since an FTQ update will never coincide with a ROB_commit to the same instruction...
    // (instructions must complete first before they are subject to commiting)

    for(i <- 0 until FTQEntries){
        val instruction_PC_match = (FTQ(i).instruction_PC === io.FU_outputs(0).bits.instruction_PC) && FTQ(i).valid   // FIXME: FU_ouputs(0) because port 0 contains the branch unit. Make this a param
        when(instruction_PC_match){
            FTQ(i).is_misprediction := FTQ(i).predicted_expected_PC =/= io.FU_outputs(0).bits.target_address
            FTQ(i).predicted_expected_PC := io.FU_outputs(0).bits.target_address
        }
        
    }


    /////////////////
    // VALID/READY //
    /////////////////

    // Stall when full (not ready)

    val full = (front_index === back_index) && (front_pointer =/= back_pointer)
    io.prediction.ready := !full


    io.FTQ := DontCare


}


