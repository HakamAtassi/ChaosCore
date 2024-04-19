/* ------------------------------------------------------------------------------------
* Filename: next_PC_selector.scala
* Author: Hakam Atassi
* Date: Apr 19 2024
* Description: This module generates the mux sel bits that ultimately decide which of the many generated PCs to take.
* These PCs include (PC+4/PC+8, RAS PC, BTB PC, decoder PC, and misprediction PC, and exception PC)
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


class next_pc_selector extends Module{

    val io = IO(new Bundle{

        // Control logic
        val exception     = Input(Bool())   // exception from backend
        val misprediction = Input(Bool())   // misprediction from BROB/backend
        val redirect      = Input(Bool())   // redirect from uDecoder

        val BTB_hit       = Input(Bool())   // BTB hit from BTB
        val BTB_T_NT      = Input(Bool())   // T_NT from PHT
        val BTB_type      = Input(UInt(2.W))   // branch type from BTB

        // possible PCs
        val exception_PC        = Input(UInt(32.W))
        val misprediction_PC    = Input(UInt(32.W))
        val BTB_PC              = Input(UInt(32.W))
        val redirect_PC         = Input(UInt(32.W))
        val RAS_PC              = Input(UInt(32.W))
        val incremented_PC      = Input(UInt(32.W))

        val PC                  = Output(UInt(32.W))

    })


    // in order of priority:
        // exception -> take exception 
        // misprediction -> taken misprediction
        // redirect -> take redirect (catches target addr errors early. Comes from uDecoder)
        // If BTB hit:
            // if Ret, jump to RAS
            // if Jump, jump to target
        // BTB miss, assume PC=PC+4/8
            // If uDecoder can repair guess next cycle, it will via the redirect PC

    // You may have noticed how the RAS is not used if a BTB hit does not occur. That is because the BP structures
    // Will not be aware that the instruction is a RET until it is decoded 1 cycle later. When that happens, 
    // The uDecoder will request a redirect to the RAS address (which will be the RAS TOS)

    val BTB_conditional = io.BTB_type(1)
    val BTB_ret         = io.BTB_type(0)

    
    when(exception){
        PC := exception_PC
    }.elsewhen(misprediction){
        PC := misprediction_PC
    }.elsewhen(redirect){
        PC := redirect_PC
    }.elsewhen((BTB_hit && BTB_conditional && BTB_T_NT) || (BTB_hit && BTB_jump)){   
        PC := BTB_target
    }.elsewhen(BTB_hit && BTB_ret){
        PC := RAS_PC
    }.otherwise{
        PC := incremented_PC
    }
        
}