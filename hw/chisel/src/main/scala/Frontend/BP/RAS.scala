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

import chisel3._
import circt.stage.ChiselStage
import chisel3.util._
import java.io.{File, FileWriter}
import java.rmi.server.UID


class RAS(entires:Int = 128) extends Module{

    // FIXME: are these correct??
    val nextBits = log2Ceil(entires)
    val tosBits  = log2Ceil(entires)
    val nosBits  = log2Ceil(entires)

    val entryWidth  = nosBits + 32

    val io = IO(new Bundle{

        // inputs
        val call_addr  = Input(UInt(32.W))
        val call_valid = Input(Bool())
        val ret_valid  = Input(Bool())

        val revert_NEXT     = Input(UInt(nextBits.W))
        val revert_TOS      = Input(UInt(tosBits.W))
        val revert_valid    = Input(Bool())

        // output
        val ret_addr = Output(UInt(32.W))             // Rer addr
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
        Note how rets do not entirely deallocate stack entires. Instead, it keeps the entires in the stack such that an earlier stack state can be reverted to
        quite easily by restoring the stack pointers. 
    */


    val NEXT    = RegInit(UInt(nextBits.W), 0.U)
    val TOS     = RegInit(UInt(nextBits.W), 0.U)
    val NOS     = Wire(UInt(nextBits.W))

    val RAS_memory = SDPReadWriteSmem(depth=entires, width=entryWidth)

    // Read port
    RAS_memory.io.rd_addr := TOS
    io.ret_addr := data_out(31,0)

    // Write port
    RAS_memory.io.wr_addr := NEXT
    RAS_memory.io.wr_data := Cat(io.call_addr, TOS) // each RAS entry contains the address and a link to the next entry on the stack
    RAS_memory.io.wr_en   := io.call & io.call_valid

    // assign next-on-stack
    NOS := RAS_memory.io.data_out(32+nosBits, 32)    


    when(io.revert_valid == 1.B){   // revert (misprediction)
        NEXT := io.revert_NEXT
        TOS  := io.revert_TOS
    }.elsewhen(io.call_valid == 1.B){   // call (push to stack)
        TOS := NEXT
        NEXT := NEXT + 1.U
    }.elsewhen(io.ret_valid){ // ret (pop from stack)
        TOS := NOS // move to next entry
    }

}