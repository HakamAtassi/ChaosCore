/* ------------------------------------------------------------------------------------
* Filename: PC_FSM.scala
* Author: Hakam Atassi
* Date: Apr 19 2024
* Description: An FSM responsible for incrementing and realigning the PC to fetch packets 
* on non-branch (or non-taken branch) instructions 
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

class PC_FSM extends Module{

    val io = IO(new Bundle{

        val increment      = Input(Bool())
        val PC             = Input(UInt(32.W))
        
        val PC_next        = Output(UInt(32.W))
    })


    val PC_aligned = Wire(Bool())

    PC_aligned := ~io.PC(2)   // Since 2 wide, lower 2 bits must be 0 (instructions are 32 bit aligned, thats a given), and 3rd bit must be 0 for aligned address

    when(io.increment){
        when(PC_aligned){
            io.PC_next := io.PC + 8 // if PC is aligned, increment to next aligned address
        }.otherwise{
            io.PC_next := io.PC + 4 // if PC is not aligned, incrementing by 4 re-alignes it
        }
    }.elsewhen{
        io.PC_next := io.PC
    }

}