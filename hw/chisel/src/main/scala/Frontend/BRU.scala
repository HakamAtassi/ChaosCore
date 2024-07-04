/* ------------------------------------------------------------------------------------
* Filename: BRU.scala
* Author: Hakam Atassi
* Date: May 16 2024
* Description: A fetch target queue that stores active branch predictions and a unit that validates them upon commit
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

// "branch resolution unit"
class BRU(parameters:Parameters) extends Module{
    import parameters._

    val io = IO(new Bundle{
        // FTQ //
        val FTQ         =   Input(new FTQ_entry(parameters))

        // COMMIT //
        val ROB_output  =   Input(new ROB_output(parameters))

        // Output 
        val commit      =   ValidIO(new commit(parameters))
    })

    val commit_valid        = Wire(Bool())
    val commit_row_complete = Wire(Vec(fetchWidth, Bool()))  // all valid instructions in that row are complete

    for(i <- 0 until fetchWidth){
        val is_completed    = (io.ROB_output.complete(i) && io.ROB_output.ROB_entries(i).valid)
        val is_invalid      = (!io.ROB_output.ROB_entries(i).valid)
        val is_load         = io.ROB_output.ROB_entries(i).is_load
        val is_store        = io.ROB_output.ROB_entries(i).is_store
        commit_row_complete(i) := is_completed || is_invalid || /*is_load ||*/ is_store
    }
    commit_valid := io.ROB_output.row_valid && commit_row_complete.reduce(_ && _)

    // when commit is taking place
    // if FTQ indicates a misprediction
    // output mispredict and other metadata

    io.commit.bits.GHR                           := io.FTQ.GHR
    io.commit.bits.TOS                           := io.FTQ.TOS
    io.commit.bits.NEXT                          := io.FTQ.NEXT
    io.commit.bits.RAT_index                     := io.ROB_output.RAT_index
    io.commit.bits.ROB_index                     := io.ROB_output.ROB_index
    io.commit.bits.free_list_front_pointer       := io.ROB_output.free_list_front_pointer
    io.commit.bits.fetch_PC                      := io.ROB_output.fetch_PC

    for(i <- 0 until fetchWidth){
        io.commit.bits.RD(i)                     := io.ROB_output.ROB_entries(i).RD
        io.commit.bits.RD_valid(i)               := io.ROB_output.ROB_entries(i).RD_valid
    }

    val branch_commit = Wire(Bool())

    io.commit.valid := commit_valid
    branch_commit := io.commit.valid && (io.ROB_output.fetch_PC === io.FTQ.fetch_PC) && io.FTQ.valid

    io.commit.bits.is_misprediction      := 0.B
    io.commit.bits.T_NT                  := 0.B
    io.commit.bits.br_type               := _br_type.NONE
    io.commit.bits.fetch_packet_index    := 0.U
    io.commit.bits.expected_PC           := 0.B

    when(branch_commit){
        io.commit.bits.is_misprediction      := (io.FTQ.predicted_PC =/= io.FTQ.resolved_PC) && branch_commit
        io.commit.bits.T_NT                  := io.FTQ.T_NT
        io.commit.bits.br_type               := io.FTQ.br_type
        io.commit.bits.fetch_packet_index    := DontCare
        io.commit.bits.expected_PC           := io.FTQ.resolved_PC
        io.commit.bits.fetch_packet_index    := io.FTQ.dominant_index
    }

}


