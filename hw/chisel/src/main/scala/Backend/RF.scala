/* ------------------------------------------------------------------------------------
* Filename: RF.scala
* Author: Hakam Atassi
* Date: May 22 2024
* Description: The "merged" register files. 
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
import getPortCount._

import chisel3.experimental._ // To enable experimental features

// Define the BlackBox module
class NReadWriteSmem extends BlackBox with HasBlackBoxResource {
  val io = IO(new Bundle {

    val clock = Input(Clock())
    val reset = Input(Bool())

    val raddr_0 = Input(UInt(6.W))
    val raddr_1 = Input(UInt(6.W))
    val raddr_2 = Input(UInt(6.W))
    val raddr_3 = Input(UInt(6.W))
    val raddr_4 = Input(UInt(6.W))
    val raddr_5 = Input(UInt(6.W))
    val raddr_6 = Input(UInt(6.W))
    val raddr_7 = Input(UInt(6.W))
    val rdata_0 = Output(UInt(32.W))
    val rdata_1 = Output(UInt(32.W))
    val rdata_2 = Output(UInt(32.W))
    val rdata_3 = Output(UInt(32.W))
    val rdata_4 = Output(UInt(32.W))
    val rdata_5 = Output(UInt(32.W))
    val rdata_6 = Output(UInt(32.W))
    val rdata_7 = Output(UInt(32.W))
    val waddr_0 = Input(UInt(6.W))
    val waddr_1 = Input(UInt(6.W))
    val waddr_2 = Input(UInt(6.W))
    val waddr_3 = Input(UInt(6.W))
    val wen_0 = Input(Bool())
    val wen_1 = Input(Bool())
    val wen_2 = Input(Bool())
    val wen_3 = Input(Bool())
    val wdata_0 = Input(UInt(32.W))
    val wdata_1 = Input(UInt(32.W))
    val wdata_2 = Input(UInt(32.W))
    val wdata_3 = Input(UInt(32.W))
  })

  // Reference the external Verilog file
  addResource("/nReadmWrite.v")
}

/*
class RF(coreConfig:String, physicalRegCount:Int) extends Module{
    val portCount     = getPortCount(coreConfig)
    val portCountBits = log2Ceil(portCount)

    println(portCount)

    val io = IO(new Bundle{
        // inputs
        val RF_inputs      =   Vec(portCount, Flipped(Decoupled(new RF_port(coreConfig=coreConfig, physicalRegCount=physicalRegCount))))
        val FU_write       =   Vec(portCount, Flipped(ValidIO(new FU_output(physicalRegCount))))

        // outputs
        val FU_read       =   Vec(portCount, Decoupled(new FU_input(coreConfig=coreConfig, physicalRegCount=physicalRegCount)))
    })


    val RF_memory = Module(new NReadWriteSmem(depth=physicalRegCount, width=32, readPorts=portCount*2, writePorts=portCount))

    //////////
    // READ //
    //////////
    RF_memory.io.rd_addr(0) := io.RF_inputs(0).bits.RS1.bits
    RF_memory.io.rd_addr(1) := io.RF_inputs(0).bits.RS2.bits

    RF_memory.io.rd_addr(2) := io.RF_inputs(1).bits.RS1.bits
    RF_memory.io.rd_addr(3) := io.RF_inputs(1).bits.RS2.bits

    RF_memory.io.rd_addr(4) := io.RF_inputs(2).bits.RS1.bits
    RF_memory.io.rd_addr(5) := io.RF_inputs(2).bits.RS2.bits

    RF_memory.io.rd_addr(6) := io.RF_inputs(3).bits.RS1.bits
    RF_memory.io.rd_addr(7) := io.RF_inputs(3).bits.RS2.bits

    if(coreConfig.contains("M")){
        RF_memory.io.rd_addr(8) := io.RF_inputs(4).bits.RS1.bits
        RF_memory.io.rd_addr(9) := io.RF_inputs(4).bits.RS2.bits
    }

    io.FU_read(0).bits.RS1_data    := RF_memory.io.data_out(0)
    io.FU_read(0).bits.RS2_data    := RF_memory.io.data_out(1)
    io.FU_read(0).bits.RD          := RegNext(io.RF_inputs(0).bits.RD.bits)

    io.FU_read(1).bits.RS1_data    := RF_memory.io.data_out(2)
    io.FU_read(1).bits.RS2_data    := RF_memory.io.data_out(3)
    io.FU_read(1).bits.RD          := RegNext(io.RF_inputs(1).bits.RD.bits)

    io.FU_read(2).bits.RS1_data    := RF_memory.io.data_out(4)
    io.FU_read(2).bits.RS2_data    := RF_memory.io.data_out(5)
    io.FU_read(2).bits.RD          := RegNext(io.RF_inputs(2).bits.RD.bits)

    io.FU_read(3).bits.RS1_data    := RF_memory.io.data_out(6)
    io.FU_read(3).bits.RS2_data    := RF_memory.io.data_out(7)
    io.FU_read(3).bits.RD          := RegNext(io.RF_inputs(3).bits.RD.bits)

    if(coreConfig.contains("M")){
        io.FU_read(4).bits.RS1_data    := RF_memory.io.data_out(8)
        io.FU_read(4).bits.RS2_data    := RF_memory.io.data_out(9)
        io.FU_read(4).bits.RD          := RegNext(io.RF_inputs(4).bits.RD.bits)
    }


    ///////////
    // WRITE //
    ///////////

    RF_memory.io.wr_addr(0)  :=  io.FU_write(0).bits.RD
    RF_memory.io.wr_en(0)    :=  io.FU_write(0).valid
    RF_memory.io.data_in(0)  :=  io.FU_write(0).bits.data

    RF_memory.io.wr_addr(1)  :=  io.FU_write(1).bits.RD
    RF_memory.io.wr_en(1)    :=  io.FU_write(1).valid
    RF_memory.io.data_in(1)  :=  io.FU_write(1).bits.data

    RF_memory.io.wr_addr(2)  :=  io.FU_write(2).bits.RD
    RF_memory.io.wr_en(2)    :=  io.FU_write(2).valid
    RF_memory.io.data_in(2)  :=  io.FU_write(2).bits.data

    RF_memory.io.wr_addr(3)  :=  io.FU_write(3).bits.RD
    RF_memory.io.wr_en(3)    :=  io.FU_write(3).valid
    RF_memory.io.data_in(3)  :=  io.FU_write(3).bits.data

    // forward non RF data

    for(i <- 0 until portCount){
        io.FU_read(i).bits.RD  := RegNext(io.RF_inputs(i).bits.RD.bits)
        io.FU_read(i).bits.uOp := RegNext(io.RF_inputs(i).bits.uOp)
        io.FU_read(i).valid    := RegNext(io.RF_inputs(i).valid)
    }

    // MISC
    for(i <- 0 until portCount){
        io.RF_inputs(i).ready := io.FU_read(i).ready
    }

}
*/