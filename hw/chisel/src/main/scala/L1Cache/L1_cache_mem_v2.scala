/* ------------------------------------------------------------------------------------
* Filename: L1_Cache.scala
* Author: Hakam Atassi
* Date: Mar 12 2024
* Description: (Part of) A lockup-free L1 Cache. This module contains the memory component. 
* It only returns hit/miss based on the data available in the memories. It does not perform allocation.
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


object CONTROLLER_CMD extends ChiselEnum {
  val LB   =  Value("b000".U)
  val LHW  =  Value("b001".U)
  val LW   =  Value("b010".U)

  val NOP  =  Value("b011".U)

  val SB   =  Value("b100".U)
  val SHW   =  Value("b101".U)
  val SW   =  Value("b110".U)

  val ALLOCATE = Value("b111".U)

  val FW = Value("b1000".U)
}



//FIXME: this should be named L1_data_mem
class L1_cache_mem(ways:Int, sets:Int, blockSizeBytes:Int) extends Module{
    // CACHE LINE STRUCTURE [VALID, DIRTY, PLRU, TAG, DATA] 
    val depth = sets
    val setBits = log2Ceil(sets)
    val wayBits = log2Ceil(ways)
    val validBits = 1
    val dirtyBits = 1
    val PLRUBits  = 1
    val dataSizeBits  = blockSizeBytes*8
    val dataBits = log2Ceil(blockSizeBytes)
    val wordOffsetBits     = log2Ceil(blockSizeBytes/4)
    val halfWordOffsetBits = log2Ceil(blockSizeBytes/2)
    val byteOffsetBits     = log2Ceil(blockSizeBytes)


    val tagBits = 32 - log2Ceil(sets) - log2Ceil(blockSizeBytes)
    //FIXME: why is dataBits below the log2 of data
    println("Buidling L1 Cache")
    println(s"Cache Config: Ways=${ways}, Sets=${sets}, Block Size=${blockSizeBytes}B")
    println(s"Tag size = ${tagBits}")
    //println(s"Line width = ${width}") //FIXME: this was previously wrong
    val io = IO(new Bundle{
        // Inputs from CPU (forwarded by controller)
        val controller_addr           =     Input(UInt(32.W))
        val controller_data           =     Input(UInt(32.W))
        val controller_cache_line     =     Input(UInt(dataSizeBits.W))
        val controller_valid          =     Input(Bool())
        val controller_ready          =     Output(Bool())
        val controller_cmd            =     Input(CONTROLLER_CMD()) 

        // Inputs from Controller
        // val controller_addr    =     Input(UInt(32.W))
        // val controller_din     =     Input(UInt(32.W))
        // val controller_valid   =     Input(Bool())
        // val controller_cmd     =     Input(???)  

        // Outputs
        val cache_dout                =     Output(UInt(32.W))  // Read data
        val cache_data                =     Output(UInt(32.W))  // Read data
        val cache_addr                =     Output(UInt(32.W))  // Request addr
        val cache_evict_line          =     Output(UInt(dataSizeBits.W)) 
        val cache_valid               =     Output(Bool())
        val cache_ready               =     Output(Bool())
        val cache_hit                 =     Output(Bool())
    })

    io.controller_ready := 1.B
    io.cache_ready := 1.B

    io.cache_data := ShiftRegister(io.controller_data, 3)

    //////////////////
    // Global Wires //
    //////////////////

    val controller_set              = Wire(UInt(setBits.W))
    val controller_tag              = Wire(UInt(tagBits.W))
    val controller_byte_offset      = Wire(UInt(byteOffsetBits.W))
    val controller_half_word_offset = Wire(UInt(halfWordOffsetBits.W))
    val controller_word_offset      = Wire(UInt(wordOffsetBits.W))
    val hit                         = Wire(Bool())
    val delayed_controller_tag      = RegInit(UInt(tagBits.W), 0.U)
    val hit_oh                      = Wire(UInt(ways.W))

    // FIXME: check all of this
    controller_set              := io.controller_addr(dataBits+setBits-1,dataBits)
    controller_tag              := io.controller_addr(tagBits+dataBits+setBits-1,dataBits+setBits)
    controller_byte_offset      := io.controller_addr(byteOffsetBits-1,0)       // When addressing bytes, all bits matter
    controller_half_word_offset := io.controller_addr(halfWordOffsetBits+1,1) // when addressing half words, all but last bit matter due to enforced half word alignment
    controller_word_offset      := io.controller_addr(wordOffsetBits+2,2)     // when addressing words, all but last 2 bits matter due to word alignment

    //TODO: cache_way missing


    /////////////////
    // CMD DECODER //
    /////////////////

    val tag_wr_en = RegInit(Bool(), 0.B)
    val plru_wr_en = RegInit(Bool(), 0.B)
    val allocate = RegInit(Bool(), 0.B)
    val dirty_wr_en = Wire(Bool())

    // tag only writes upon allocate. Delay since tag pos depends on the result of PLRU mem
    tag_wr_en := (io.controller_cmd === CONTROLLER_CMD.ALLOCATE) && io.controller_valid

    // plru updates only on reads/writes, not allocate, since the allocated way goes into the most significant 0 anyway
    plru_wr_en := (io.controller_cmd =/= CONTROLLER_CMD.NOP && io.controller_cmd =/=CONTROLLER_CMD.ALLOCATE) && io.controller_valid

    // allocate signal set one cycle after request, since the eviction line must be read out first
    allocate := (io.controller_cmd === CONTROLLER_CMD.ALLOCATE) & io.controller_valid

    dirty_wr_en := ((io.controller_cmd === CONTROLLER_CMD.SW) || (io.controller_cmd === CONTROLLER_CMD.SHW) || (io.controller_cmd === CONTROLLER_CMD.SB)  || (io.controller_cmd === CONTROLLER_CMD.ALLOCATE)) & io.controller_valid

    dontTouch(dirty_wr_en)

    /////////////////
    // PLRU Memory //
    /////////////////
    val PLRU_memory = Module(new SDPReadWriteSmem(depth = sets, width = ways))

    val delayed_controller_set = RegNext(controller_set)
    val plru_out = Wire(UInt(4.W))
    val plru_in  = Wire(UInt(4.W))
    val plru_oh  = Wire(UInt(ways.W))
    val allocate_way = Wire(UInt(ways.W))


    // Enable
    PLRU_memory.io.enable := 1.B

    // Read port
    PLRU_memory.io.rd_addr := controller_set
    plru_out := PLRU_memory.io.data_out
    
    // Write port
    PLRU_memory.io.wr_en := (plru_wr_en && hit)
    PLRU_memory.io.wr_addr := delayed_controller_set
    PLRU_memory.io.data_in := plru_in


    // PLRU bits update logic
    dontTouch(plru_out)

    plru_in := Mux((hit_oh | plru_out).andR, hit_oh, hit_oh | plru_out)
    
    // plru_oh assignment is as follows:
      // Bit N is set if Bits (N-1),0 of plru_out are all set

    // FIXME: Only works for 4 ways    
    // FIXME: this is reversed. do the opposite
    plru_oh := Cat( ~plru_in(3) & plru_in(2) & plru_in(1) & plru_in(0), ~plru_in(2) & plru_in(1) & plru_in(0), ~plru_in(1) & plru_in(0), ~plru_in(0))

    val allocate_oh = Wire(UInt(ways.W))

    when(plru_out(0) === 0.U){  // FIXME: update this for parameter ways
      allocate_way := 0.U
      allocate_oh := 1.U
    }.elsewhen(plru_out(1) === 0.U){
      allocate_way := 1.U
      allocate_oh := 2.U
    }.elsewhen(plru_out(2) === 0.U){
      allocate_way := 2.U
      allocate_oh := 4.U
    }.otherwise{
      allocate_way := 3.U
      allocate_oh := 8.U
    }

      //allocate_way := PriorityEncoder(plru_in)
      dontTouch(allocate_way)

    //////////////////
    // Valid Memory //
    //////////////////
    
    val valid_memory = Module(new SDPReadWriteSmem(depth = sets, width = ways))
    val valid_out = Wire(UInt(ways.W))

    // read port
    valid_memory.io.enable := 1.B
    valid_memory.io.rd_addr := controller_set
    valid_out := valid_memory.io.data_out

    // write port
    valid_memory.io.wr_en := allocate
    valid_memory.io.wr_addr := delayed_controller_set
    valid_memory.io.data_in := valid_out | allocate_oh


    ////////////////
    // Tag Memory //
    ////////////////
    val tag_memory = Module(new ReadWriteSmem(depth=(sets), width= tagBits * ways))
    val tag_vector_out = Wire(Vec(ways, UInt(tagBits.W)))
    val tag_vector_in = Wire(Vec(ways, UInt(tagBits.W)))
    val cache_hit_way = Wire(UInt(log2Ceil(ways).W))
    val cache_addr    = Wire(UInt((setBits+wayBits).W))
    val valid_delayed = RegNext(io.controller_valid)

    //FIXME: cache will need to be stalled on allocate to allow read modify write of tag (to avoid dp memory)

    tag_memory.io.enable := 1.B
    tag_memory.io.wr_en := tag_wr_en
    tag_memory.io.addr := controller_set 

    // update on allocate as needed
    for(way <- 0 until ways){tag_vector_out(way) := tag_memory.io.data_out((way+1)*tagBits-1,way*tagBits)}
    
    tag_vector_in(0) := Mux(plru_oh(0), controller_tag, tag_vector_out(0))
    tag_vector_in(1) := Mux(plru_oh(1), controller_tag, tag_vector_out(1))
    tag_vector_in(2) := Mux(plru_oh(2), controller_tag, tag_vector_out(2))
    tag_vector_in(3) := Mux(plru_oh(3), controller_tag, tag_vector_out(3))

    tag_memory.io.data_in := Cat(tag_vector_in(3), tag_vector_in(2), tag_vector_in(1), tag_vector_in(0))

    // Check hit

    delayed_controller_tag := controller_tag

    val hit_oh_vec = Wire(Vec(ways, UInt(1.W)))

    for (way <- 0 until ways) {
      hit_oh_vec(way) := (delayed_controller_tag === tag_vector_out(way)).asUInt & valid_out(way)
    }

    dontTouch(delayed_controller_tag)
    dontTouch(hit_oh_vec(0))
    dontTouch(hit_oh_vec(1))
    dontTouch(hit_oh_vec(2))
    dontTouch(hit_oh_vec(3))


    dontTouch(tag_vector_out(0))
    dontTouch(tag_vector_out(1))
    dontTouch(tag_vector_out(2))
    dontTouch(tag_vector_out(3))

    hit_oh := hit_oh_vec.reverse.reduce(_ ## _)

    hit := hit_oh.orR & valid_delayed & valid_out(cache_hit_way)

    dontTouch(plru_oh)

    cache_hit_way := PriorityEncoder(hit_oh)
    dontTouch(cache_hit_way)

    cache_addr             := Mux(allocate, allocate_way ## RegNext(controller_set), cache_hit_way ## RegNext(controller_set))       // The address used to index the cache data memory

    //////////////////
    // Dirty Memory //
    //////////////////

    val dirty_memory = Module(new SDPReadWriteSmem(depth = sets, width = ways))
    val dirty_out = Wire(UInt(ways.W))

    dirty_memory.io.enable := 1.B
    dirty_memory.io.rd_addr := controller_set
    dirty_out := dirty_memory.io.data_out


    dirty_memory.io.wr_addr     := RegNext(controller_set)
    dirty_memory.io.wr_en       := RegNext(dirty_wr_en)
    dirty_memory.io.data_in := Mux(allocate, (~plru_oh & dirty_out), hit_oh | dirty_out)
   
    dontTouch(dirty_out)


    ///////////////////
    // Data Memories //
    ///////////////////

    val delayed_controller_byte_offset = RegNext(controller_byte_offset)  // Delay the input address
    val delayed_controller_cmd         = RegNext(io.controller_cmd)  // Delay the input address
    val delayed_controller_data        = RegNext(io.controller_data)  // Delay the input address
    val delayed_controller_cache_line  = RegNext(io.controller_cache_line)  // Delay the input address

    val data_memory: Seq[ReadWriteSmem] = Seq.tabulate(blockSizeBytes) { w =>
        Module(new ReadWriteSmem(depth=(sets * ways), width=8))
    }

    // Write enable(s):
      // The write enables for each sram is designed to essentially be "does the current request write to this memory"
      // This simplifies the data input shifting and masking for LB and LHW
    
    val data_memory_wr_en = Wire(Vec(blockSizeBytes, Bool()))   // vector of wr enables

    dontTouch(data_memory_wr_en)

    //FIXME: this can be simplified
    for (word <- 0 until blockSizeBytes/4){ // Break enables into words
      // Connect write enables
      // FIXME: CRITICAL! Need to add valid as a condition
      data_memory_wr_en(blockSizeBytes - 1 - (word*4+0)) :=  valid_delayed && (allocate || (delayed_controller_cmd===CONTROLLER_CMD.SB && delayed_controller_byte_offset===(word*4 + 0).U) || (delayed_controller_cmd===CONTROLLER_CMD.SHW && delayed_controller_byte_offset===(word*4 + 0).U) || (delayed_controller_cmd===CONTROLLER_CMD.SW  && delayed_controller_byte_offset===(word*4).U)) // Enabled if SB to 1st byte, SHW to bottom half word, or SW
      data_memory_wr_en(blockSizeBytes - 1 - (word*4+1)) :=  valid_delayed && (allocate || (delayed_controller_cmd===CONTROLLER_CMD.SB && delayed_controller_byte_offset===(word*4 + 1).U) || (delayed_controller_cmd===CONTROLLER_CMD.SHW && delayed_controller_byte_offset===(word*4 + 0).U) || (delayed_controller_cmd===CONTROLLER_CMD.SW  && delayed_controller_byte_offset===(word*4).U)) // Enabled if SB to 2nd byte, SHW to bottom half word, or SW
      data_memory_wr_en(blockSizeBytes - 1 - (word*4+2)) :=  valid_delayed && (allocate || (delayed_controller_cmd===CONTROLLER_CMD.SB && delayed_controller_byte_offset===(word*4 + 2).U) || (delayed_controller_cmd===CONTROLLER_CMD.SHW && delayed_controller_byte_offset===(word*4 + 2).U) || (delayed_controller_cmd===CONTROLLER_CMD.SW  && delayed_controller_byte_offset===(word*4).U)) // Enabled if SB to 3rd byte, SHW to top half word, or SW
      data_memory_wr_en(blockSizeBytes - 1 - (word*4+3)) :=  valid_delayed && (allocate || (delayed_controller_cmd===CONTROLLER_CMD.SB && delayed_controller_byte_offset===(word*4 + 3).U) || (delayed_controller_cmd===CONTROLLER_CMD.SHW && delayed_controller_byte_offset===(word*4 + 2).U) || (delayed_controller_cmd===CONTROLLER_CMD.SW  && delayed_controller_byte_offset===(word*4).U)) // Enabled if SB to 4th byte, SHW to top half word, or SW
    }


    val data_memory_data_in = Wire(Vec(blockSizeBytes, UInt(32.W)))

    val write_data = RegInit(UInt(32.W), 0.U)
    write_data := MuxLookup(io.controller_addr(1, 0), 0.U)(Seq(0.U -> (io.controller_data<<0), 1.U -> (io.controller_data<<8), 2.U -> (io.controller_data<<16), 3.U -> (io.controller_data<<24)))

    dontTouch(data_memory_data_in) //FIXME: wire never used
    for(word <- 0 until blockSizeBytes/4){
      // write data word from cpu or complete cache line from controller?
      data_memory_data_in(blockSizeBytes - 1 - (word*4+0)) := Mux(allocate, delayed_controller_cache_line(word*32+7, word*32), write_data(7, 0))
      data_memory_data_in(blockSizeBytes - 1 - (word*4+1)) := Mux(allocate, delayed_controller_cache_line(word*32+15, word*32+8),  write_data(15, 8))
      data_memory_data_in(blockSizeBytes - 1 - (word*4+2)) := Mux(allocate, delayed_controller_cache_line(word*32+23, word*32+16), write_data(23, 16))
      data_memory_data_in(blockSizeBytes - 1 - (word*4+3)) := Mux(allocate, delayed_controller_cache_line(word*32+31, word*32+24), write_data(31, 24))
    }


    for(i <- 0 until blockSizeBytes){
      // Connect memory ports
      data_memory(i).io.enable  := 1.B
      data_memory(i).io.wr_en   := data_memory_wr_en(i)
      data_memory(i).io.data_in := data_memory_data_in(i)
      data_memory(i).io.addr    := cache_addr
    }


    // Data out
    val word_swizzle_level_0 = Wire(Vec(blockSizeBytes/4, UInt(32.W)))
    val delayed_controller_byte_offset_2 = RegNext(delayed_controller_byte_offset)

    for(word <- 0 until blockSizeBytes/4){
      // Byte select muxing
      val _word = data_memory(word*4+0).io.data_out ## data_memory(word*4+1).io.data_out ## data_memory(word*4+2).io.data_out ## data_memory(word*4+3).io.data_out
      word_swizzle_level_0(blockSizeBytes/4 -1 - word) := MuxLookup(delayed_controller_byte_offset_2(1, 0), 0.U)(Seq(0.U -> (_word>>0), 1.U -> (_word>>8), 2.U -> (_word>>16), 3.U -> (_word>>24)))     
    }

    // Word select muxing
    val data_out_pre_mask = RegInit(UInt(32.W), 0.U)
    data_out_pre_mask := word_swizzle_level_0(delayed_controller_byte_offset_2(log2Ceil(blockSizeBytes/4)-1+2,2))

    val sel_output_mask = ShiftRegister(io.controller_cmd,3)    

    when(sel_output_mask === CONTROLLER_CMD.LW){
      io.cache_dout := data_out_pre_mask.asUInt & "hFFFFFFFF".U(32.W)

    }.elsewhen(sel_output_mask === CONTROLLER_CMD.LHW){
      io.cache_dout := data_out_pre_mask & "hFFFF".U(32.W)
    }.elsewhen(sel_output_mask === CONTROLLER_CMD.LB){
      io.cache_dout := data_out_pre_mask & "hFF".U(32.W)
    }
    .otherwise{
      io.cache_dout := data_out_pre_mask & "h0".U(32.W)
    }

    io.cache_hit := ShiftRegister(hit, 2)

    ////////////////////
    // EVICTION LOGIC //
    ////////////////////

    val eviction_line = RegInit(VecInit(Seq.fill(blockSizeBytes)(0.U(8.W))))

    for (byte <- 0 until blockSizeBytes){
      eviction_line(byte) := data_memory(byte).io.data_out
    }

    io.cache_evict_line := eviction_line.reduce(_ ## _)

    io.cache_addr := ShiftRegister(io.controller_addr, 3)
    io.cache_valid := ShiftRegister(io.controller_valid, 3)

}

/*
object Main extends App{

    var L1_cache_mem = ChiselStage.emitSystemVerilog(gen=new L1_cache_mem(ways=4, sets=64, blockSizeBytes=32), firtoolOpts=Array("-disable-all-randomization", "-strip-debug-info"))

    println(L1_cache_mem)

    var file = new File("../verilog/L1Cache/L1_cache_mem_v2.v")

    var fw = new FileWriter(file)

    try {
      fw.write(L1_cache_mem)
    } finally {
      fw.close()
    }

}
*/