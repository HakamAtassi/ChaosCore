/* ------------------------------------------------------------------------------------
* Filename: RAS.scala
* Author: Hakam Atassi
* Date: Apr 19 2024
* Description: A checkpointed return address stack. STRONGLY inspired from 
* "Recovery Requirements of Branch Prediction Storage Structures in the Presence of Mispredicted-Path Execution" by Stephan Jourdan and Yale Patt. 
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


class RAS(parameters:Parameters) extends Module{
    import parameters._

    val nextBits = log2Ceil(RASEntries)
    val tosBits  = log2Ceil(RASEntries)
    val nosBits  = log2Ceil(RASEntries)

    val entryWidth  = nosBits + 32

    val io = IO(new Bundle{

        // inputs
        val wr_addr  = Input(UInt(32.W))    // Call
        val wr_valid = Input(Bool())        // Call addr
        val rd_valid = Input(Bool())        // Ret

        val revert_NEXT     = Input(UInt(nextBits.W))
        val revert_TOS      = Input(UInt(tosBits.W))
        val revert_valid    = Input(Bool())

        // output
        val ret_addr  = Output(UInt(32.W))             // Ret addr
        val NEXT     = Output(UInt(nextBits.W))       // To checkpoint
        val TOS      = Output(UInt(tosBits.W))        // ...

    })

    /*
        Brief outline of operation:
        There are 2 pointers into the memory block, NEXT and TOS.
        NEXT indicates the next position to write to. TOS indicates the top of the stack. 
        Why are these different?
        Consider the series of operations: Call, Branch, Ret, Call
        The first call pushes to the stack. This increments both NEXT and TOS. 
        A branch then takes place. This does not directly impact the RAS, subsequent Calls/Rets may corrupt the stack if the branch is mispredicted.
        Then a Ret occurs. The Ret increments the TOS in typical stack fashion. NEXT, however, is not. This is to maintain the return address
        in case the earlier branch was found to be mispredicted.
        The final Call now writes to an entirely new stack entry. NEXT is once more incremented.
        Note how rets do not entirely deallocate stack entries. Instead, it keeps the entries in the stack such that an earlier stack state can be reverted to
        quite easily by restoring the stack pointers. 
    */


    val NEXT    = RegInit(UInt(nextBits.W), 0.U)
    val TOS     = RegInit(UInt(tosBits.W), 0.U)
    val NOS     = Wire(UInt(nosBits.W))

    val RAS_memory = Module(new SDPReadWriteSmem(depth=RASEntries, width=entryWidth))

    // write to TOS
    when(io.revert_valid === 1.B){   // revert (misprediction)
        TOS := io.revert_TOS
    }.elsewhen(io.wr_valid === 1.B){   // call (push to stack)
        TOS := NEXT
    }.elsewhen(io.rd_valid){ // ret (pop from stack)
        TOS := NOS
    }.otherwise{
        TOS := TOS
    }

    // for TOS forwarding
    //TOS := tos_mux_out  // 1 cycle delay

    RAS_memory.io.enable := 1.B

    // Read port
    when(io.wr_valid){
        RAS_memory.io.rd_addr := NEXT
    }.elsewhen(io.rd_valid){
        RAS_memory.io.rd_addr := NOS
    }.elsewhen(io.revert_valid){
        RAS_memory.io.rd_addr := io.revert_TOS
    }.otherwise{
        RAS_memory.io.rd_addr := TOS
    }
    //RAS_memory.io.rd_addr := Mux(io.wr_valid, NEXT, TOS)
    io.ret_addr := RAS_memory.io.data_out(31,0)

    // Write port
    RAS_memory.io.wr_addr := NEXT
    RAS_memory.io.data_in := Cat(TOS, io.wr_addr) // each RAS entry contains the address and a link to the next entry on the stack
    RAS_memory.io.wr_en   := io.wr_valid

    // assign next-on-stack
    NOS := RAS_memory.io.data_out(31+nosBits, 32)    

    io.NEXT := NEXT
    io.TOS := TOS
    when(io.revert_valid === 1.B){        // revert (misprediction)
        NEXT := io.revert_NEXT
    }.elsewhen(io.wr_valid === 1.B){   // call (push to stack)
        NEXT := NEXT + 1.U
    }.otherwise{
        NEXT := NEXT // move to next entry
    }   // Reads do not affect NEXT by design

}