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
class FTQ(parameters:Parameters) extends Module{
    import parameters._
    val portCount = getPortCount(parameters)

    val io = IO(new Bundle{

        // UPDATE //
        val FU_outputs          =   Vec(portCount, Flipped(ValidIO(new FU_output(parameters))))

        // PREDICTIONS //
        val predictions         =   Vec(fetchWidth, Flipped(Decoupled(new FTQ_entry(parameters))))


        // COMMIT // 
        val commit           =   Input(Vec(commitWidth, new commit(parameters)))


        // FTQ //
        val FTQ                 =   Output(Vec(commitWidth, new FTQ_entry(parameters)))
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

    // On ROB, if commiting instruction is a branch, dequeue FTQ and handle commit as needed
    // If commiting instruction is not a branch, FTQ is not changed. 


    /////////////////////////////
    // BACKEND POINTER CONTROL //
    /////////////////////////////
    

    for(i <- 0 until fetchWidth){
        when(io.predictions(i).valid){
            FTQ(back_index + i.U)   := io.predictions(i).bits
        }
    }

    back_pointer := back_pointer + PopCount(io.predictions.map(_.valid))

    ///////////////////////////
    // FRONT POINTER CONTROL //
    ///////////////////////////

    val front_element_valid             = Wire(Vec(commitWidth, Bool()))
    val commit_is_branch                = Wire(Vec(commitWidth, Bool()))

    for (i <- 0 until commitWidth){
        front_element_valid(i)          :=  FTQ(front_index + i.U).valid
        commit_is_branch(i)             :=  io.commit(i).is_BR && io.commit(i).valid
    }

    // Pointer control


    for (i <- 0 until commitWidth){
        when(front_element_valid(i) && commit_is_branch(i)){ // when front element is valid and commiting instruction is a branch, dequeue
            FTQ(front_index + i.U) := 0.U.asTypeOf(new FTQ_entry(parameters))
        }
    }

    front_pointer := front_pointer + PopCount((0 until commitWidth).map(i => front_element_valid(i) && commit_is_branch(i)))

    //////////////////////
    // BACKEND UPDATES  //
    //////////////////////

    // maintain the status of branch instructions/resolution in the FTQ

    for(i <- 0 until FTQEntries){
        val instruction_PC_match = (FTQ(i).instruction_PC === io.FU_outputs(0).bits.instruction_PC) && FTQ(i).valid   // FIXME: FU_ouputs(0) because port 0 contains the branch unit. Make this a param
        when(instruction_PC_match){
            FTQ(i).is_misprediction := FTQ(i).predicted_expected_PC =/= io.FU_outputs(0).bits.target_address
            FTQ(i).predicted_expected_PC := io.FU_outputs(0).bits.target_address
        }
    }

    ////////////////////
    // ASSIGN OUTPUTS //
    ////////////////////

    for (i <- 0 until commitWidth){
        io.FTQ(i) := FTQ(front_index + i.U)
    }

    /////////////////
    // VALID/READY //
    /////////////////

    val available_FTQ_entries =   FTQEntries.U - (back_pointer - front_pointer)
    val themometor_value = Thermometor(in=available_FTQ_entries, max=FTQEntries)
    for (i <- 0 until dispatchWidth){
        io.predictions(i).ready := themometor_value(dispatchWidth-1,0)(i)
    }


}


