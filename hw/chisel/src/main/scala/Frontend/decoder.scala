/* ------------------------------------------------------------------------------------
* Filename: decoder.scala
* Author: Hakam Atassi
* Date: May 9 2024
* Description: A single instruction decoder and the N wide fetch packet decoder.
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

import helperFunctions._
import Uop._

/*
class decoder extends Module{   // basic decoder and field extraction
    val io = IO(new Bundle{
        val instruction = Input(UInt(32.W))

        val decoded_instruction = Output(new decoded_instruction())
    })

    val opcode      = io.instruction(6, 0)

    val rs1         = io.instruction(19, 15)
    val rs2         = io.instruction(24, 20)
    val rd          = io.instruction(11, 7)

    val funct3      = io.instruction(14, 12)
    val funct7      = io.instruction(31, 25)

    val imm = getImm(io.instruction)

    // Assignment 

    decoded_instruction.opcode :=  opcode 
    decoded_instruction.rs1    :=  rs1
    decoded_instruction.rs2    :=  rs2
    decoded_instruction.rd     :=  rd
    decoded_instruction.funct3 :=  funct3
    decoded_instruction.funct7 :=  funct7
    decoded_instruction.imm    :=  imm
    
}

class fetch_packet_decoder(fetchWidth:Int) extends Module{
    val io = IO(new Bundle{
        val fetch_packet         =   Decoupled(new fetch_packet(fetchWidth=fetchWidth))          // Fetch packet result (To Decoders)
        val decoded_fetch_packet =   Decoupled(new decoded_fetch_packet(fetchWidth=fetchWidth))
    })

    val decoders: Seq[decoder] = Seq.tabulate(fetchWidth) { w =>
        Module(new decoder(fetchWidth=fetchWidth))
    }

    for(i <- until fetchWidth){
        decoder(i).io.instruction := io.fetch_packet.instructions(i)
    }

    // Register outputs //
    io.decoded_fetch_packet.fetch_PC                := RegNext(io.fetch_packet.fetch_PC)
    io.decoded_fetch_packet.valid_bits              := RegNext(io.fetch_packet.valid_bits)

    for(i <- until fetchWidth){
        io.decoded_fetch_packet.decoded_instructions(i)    := RegNext(decoder(i).io.decoded_instruction)
    }


}
*/