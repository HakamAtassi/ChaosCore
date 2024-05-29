/* ------------------------------------------------------------------------------------
* Filename: hash_BTB.scala
* Author: Hakam Atassi
* Date: Apr 19 2024
* Description: A branch target buffer implemented as a hash table for 2-wide execution. 
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

import helperFunctions._

// FIXME: not parameterized for fetchwidth...
class hash_BTB(parameters:Parameters) extends Module{
// FIXME: tag bits may be wrong here...
    import parameters._
    
    val BTBIndexBits = getBTBTagBits(BTBSize=BTBEntries, fetchWidth=fetchWidth)

    val validBits = 1
    val tagBits = 32 - BTBIndexBits
    val targetBits = 32
    val typeBits = 2    // [ret jump]. If [0,0] => Cond branch
    val brMaskBits = fetchWidth


    val entryWidth = validBits + tagBits + targetBits + typeBits + brMaskBits

    val io = IO(new Bundle{

        //prediction-input
        val predict_PC          = Input(UInt(32.W))
        val predict_valid       = Input(Bool())

        //prediction-output
        // ??
        val BTB_valid    = Output(Bool())
        val BTB_target   = Output(UInt(32.W))
        val BTB_type     = Output(UInt(typeBits.W))
        val BTB_br_mask  = Output(UInt(brMaskBits.W))
        val BTB_hit      = Output(Bool())

        //commit-input
        val commit_PC       = Input(UInt(32.W))

        val commit_target      = Input(UInt(32.W))
        val commit_br_type     = Input(UInt(typeBits.W))
        val commit_br_mask     = Input(UInt(brMaskBits.W))

        val commit_valid    = Input(Bool())

        //val fetch_packet_data = Decoupled(UInt(32.W))  // output
    })


    val BTB_valid_output      = Wire(UInt(validBits.W))
    val BTB_tag_output        = Wire(UInt(tagBits.W))
    val BTB_target_output     = Wire(UInt(targetBits.W))
    val BTB_type_output       = Wire(UInt(typeBits.W))
    val BTB_br_mask_output     = Wire(UInt(brMaskBits.W))

    val commit_input_tag = shiftDownByTagBits(io.commit_PC)
    val predict_input_tag = shiftDownByTagBits(io.predict_PC)

    // memory // 

    val BTB_memory = Module(new SDPReadWriteSmem(depth = BTBEntries, width = entryWidth))

    val prediction_BTB_address = io.predict_PC(BTBIndexBits + log2Ceil(fetchWidth) + 2, log2Ceil(fetchWidth) + 2)
    val prediction_BTB_output = Wire(UInt(entryWidth.W))

    val commit_BTB_address = io.commit_PC(BTBIndexBits + log2Ceil(fetchWidth) + 2, log2Ceil(fetchWidth) + 2)

    dontTouch(commit_input_tag)

    // FIXME: update this
    BTB_memory.io.enable := 1.B

    BTB_memory.io.rd_addr := prediction_BTB_address

    BTB_memory.io.wr_addr := commit_BTB_address
    BTB_memory.io.wr_en   := io.commit_valid
    BTB_memory.io.data_in := Cat(1.U, commit_input_tag, io.commit_target, io.commit_br_type, io.commit_br_mask)

    prediction_BTB_output := BTB_memory.io.data_out


    ////////////////////////////////////
    // Hit logic and assignment logic // 
    ////////////////////////////////////


    BTB_valid_output    := prediction_BTB_output(entryWidth-1)
    BTB_tag_output      := prediction_BTB_output(entryWidth-1-validBits, entryWidth-1-validBits-tagBits+1)
    BTB_target_output   := prediction_BTB_output(entryWidth-1-validBits-tagBits, entryWidth-1-validBits-tagBits-targetBits+1)
    BTB_type_output     := prediction_BTB_output(entryWidth-1-validBits-tagBits-targetBits, entryWidth-1-validBits-tagBits-targetBits-typeBits+1)
    BTB_br_mask_output  := prediction_BTB_output(entryWidth-1-validBits-tagBits-targetBits-typeBits, entryWidth-1-validBits-tagBits-targetBits-typeBits-brMaskBits+1)


    dontTouch(BTB_tag_output)

    // OUTPUTS
    io.BTB_valid    := RegNext(io.predict_valid)    // Hit signal
    io.BTB_hit      := (RegNext(predict_input_tag) === BTB_tag_output) && BTB_valid_output.asBool
    io.BTB_target   := BTB_target_output
    io.BTB_type     := BTB_type_output
    io.BTB_br_mask  := BTB_br_mask_output

}
