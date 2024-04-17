/* ------------------------------------------------------------------------------------
* Filename: L1_Cache.scala
* Author: Hakam Atassi
* Date: Mar 12 2024
* Description: A blocking single cycle latency instruction cache with no self CPU write port (no self modifying functionality).
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


object cacheState extends ChiselEnum{
    val Active, Miss, Replay, Allocate = Value
}


class L1_instruction_memory(ways:Int=2, sets:Int = 64, blockSizeBytes:Int = 64, fetchWidth:Int=2) extends Module{

    // CACHE LINE STRUCTURE [VALID, TAG, DATA] 
    // LRU goes in separate memory
    val depth               = sets
    val setBits             = log2Ceil(sets)                    // Bits needed to address sets
    val wayBits             = log2Ceil(ways)                    // Bits needed to address ways
    val validBits           = 1                                 // number of valid bits
    val LRUBits             = 1                                 // number of LRU bits (per way)
    val dataSizeBits        = blockSizeBytes*8                  // number of raw data bits

    val instructionsPerLine = blockSizeBytes/4                  // number of instructions per cache line (no compressed instruction support)
    val fetchPacketsPerLine = instructionsPerLine/fetchWidth    // number of fetch packets per cache line

    //val wordOffsetBits      = log2Ceil(blockSizeBytes/4)      // number of bits needed to address each word in the cache line
    //val halfWordOffsetBits  = log2Ceil(blockSizeBytes/2)      // number of bits needed to address each half-word in the cache line


    val fetchPacketOffsetBits  = log2Ceil(fetchPacketsPerLine)  // number of fetch packets per cache line



    val tagBits = 32 - log2Ceil(sets) - log2Ceil(instructionsPerLine) - 2 // For sets=64 and instr. per line = 16, tag is 20 bits (last 2 bits are always 00 for isntructions)
    val wayDataWidth = (validBits + tagBits) + dataSizeBits 
    println("Buidling L1 Cache")
    println(s"Cache Config: Ways=${ways}, Sets=${sets}, Block Size=${blockSizeBytes}B")
    println(s"Tag size = ${tagBits}")
    println(s"Line width = ${wayDataWidth}")


    val io = IO(new Bundle{
        val cpu_addr           =     Flipped(Decoupled(UInt(32.W)))     // inputs from CPU
        val dram_data          =     Flipped(Decoupled(UInt(32.W)))     // inputs from DRAM

        // Outputs
        val cache_data         = Vec(fetchWidth, Decoupled(UInt(32.W)))



                                                                        // FIXME: cache returns much more than 32 bits
        val cache_addr         =     Decoupled(UInt(32.W))              // outputs to DRAM
    })




    /////////
    // FSM //
    /////////

    val stall = Wire(Bool())
    val miss = Wire(Bool())

    val cache_state =  RegInit(cacheState(), cacheState.Active)   // Is this how you do it?
    val current_addr = Wire(UInt(32.W))

    val replay_addr = RegInit(UInt(32.W), 0.U)

    // FIXME: control is super messed up due to FSM latency...

    switch(cache_state){
        is(cacheState.Active){

            //TODO: buffer request
            replay_addr := replay_addr

            when(miss===1.B){ // Buffer current request, stall cache, go to wait state
                cache_state := cacheState.Miss
            }

        }
        is(cacheState.Miss){    // Stall till DRAM response
            when(io.dram_data.valid===1.U){cache_state := cacheState.Miss}            
        }
        is(cacheState.Allocate){    // Allocate data
            cache_state := cacheState.Replay
        }
        is(cacheState.Replay){ // Replay request
            cache_state := cacheState.Active
        }
    }

    // Address arbitration
    current_addr := Mux(cache_state===cacheState.Replay || cache_state===cacheState.Allocate , replay_addr, io.cpu_addr.bits)


    stall := (cache_state =/= cacheState.Active) || (miss)  // cache is stalled when the FSM is not in active or when a miss just occured 

    ////////////////
    // LRU MEMORY //
    ////////////////

    val LRU_memory = Module(new SDPReadWriteSmem(depth = sets, width = ways))
    val LRU = Wire(UInt(ways.W))
    val hit_oh = Wire(UInt(ways.W))
    val LRU_next = Wire(UInt(ways.W))
    val allocate_way = Wire(UInt(ways.W))

    LRU_memory.io.enable := 1.B

    LRU_memory.io.rd_addr := current_addr

    LRU_memory.io.wr_addr := RegNext(current_addr)
    LRU_memory.io.wr_en   := RegNext(hit_oh.orR)
    LRU_memory.io.data_in := RegNext(LRU_next)

    LRU := LRU_memory.io.data_out

    hit_oh :=0.U // FIXME: implement this

    LRU_next := Mux((LRU | hit_oh).andR, hit_oh, LRU | hit_oh)



    when(LRU(0) === 0.U){  // FIXME: update this for parameter ways
      allocate_way := 0.U
    }.otherwise{
      allocate_way := 2.U
    }

    


    ///////////////////
    // DATA MEMORIES //
    ///////////////////

    val data_memory: Seq[ReadWriteSmem] = Seq.tabulate(ways) { w =>
        Module(new ReadWriteSmem(depth=sets, width=wayDataWidth))
    }

    val data_way = Wire(Vec(ways, UInt(wayDataWidth.W)))
    val hit_oh_vec = Wire(Vec(ways, UInt(1.W)))
    val hit        = Wire(Bool())
    val delayed_current_addr = RegNext(current_addr)
    val delayed_current_address_tag = delayed_current_addr(31, 31-tagBits)

    for (way <- 0 until ways){
        data_memory(way).io.enable := 1.B

        data_memory(way).io.addr := current_addr
        data_way(way) := data_memory(way).io.data_out

        data_memory(way).io.wr_en := 1.U   // FIXME: connects to dram
        data_memory(way).io.data_in := 0.U  //FIXME: connects to dram
    }

    // Rename outputs for readability
    val memory_valid_vec = Wire(Vec(ways, UInt(1.W)))
    val memory_tags_vec  = Wire(Vec(ways, UInt(tagBits.W)))
    val memory_instr_vec = Wire(Vec(ways, UInt(dataSizeBits.W)))

    for (way <- 0 until ways){
        memory_valid_vec(way)  := data_way(way)(dataSizeBits-1)
        memory_tags_vec(way)   := data_way(way)(dataSizeBits-2, dataSizeBits-2-tagBits)
        memory_instr_vec(way)  := data_way(way)(dataSizeBits-2-tagBits, 0)
    }

    for (way <- 0 until ways) {
      hit_oh_vec(way) := (memory_tags_vec(way) === delayed_current_address_tag) && memory_valid_vec(way).asBool
    }

    hit_oh := hit_oh_vec.reverse.reduce(_ ## _)


    hit := hit_oh.orR & RegNext(io.cpu_addr.valid)
    miss := (~hit_oh.orR) & RegNext(io.cpu_addr.valid)



    /////////////////////////////////////
    // Fetch Packet Selecting & Output //
    /////////////////////////////////////



    val hit_instruction_data = Wire(UInt(wayDataWidth.W)) //TODO: not implemented

    val instruction_vec = Wire(Vec(instructionsPerLine, UInt(32.W)))   

    val packet_index = Wire(UInt(fetchPacketOffsetBits.W))
    packet_index := delayed_current_addr(fetchPacketOffsetBits+2,2)


    val muxCases = (0 until ways).map { i =>
        (hit_oh(i), data_way(i))
    }

    hit_instruction_data := MuxCase(data_way(0), muxCases)

    for(instruction <- 0 until instructionsPerLine){
        instruction_vec(instruction) := hit_instruction_data((instruction+1)*32-1, (instruction)*32)
    }





    // Large mux, likely critical path...

    

    for(i <- 0 until fetchWidth){
        io.cache_data(i).bits := instruction_vec((packet_index<<fetchWidth)+i.U)
    }

    //
    


    // TEMP

    //io.cache_data(0).bits := 0.U
    io.cache_data(0).valid := 0.U

    //io.cache_data(1).bits := 0.U
    io.cache_data(1).valid := 0.U

    io.cache_addr.bits := 0.U
    io.cache_addr.valid := 0.U


    io.cpu_addr.ready := 0.U
    io.dram_data.ready := 0.U

}


object Main extends App{

    var L1_cache_mem = ChiselStage.emitSystemVerilog(gen=new L1_instruction_memory(ways=2, sets=64, blockSizeBytes=32), firtoolOpts=Array("-disable-all-randomization", "-strip-debug-info"))

    println(L1_cache_mem)

    var file = new File("../verilog/Frontend/instruction_cache.v")

    var fw = new FileWriter(file)

    try {
      fw.write(L1_cache_mem)
    } finally {
      fw.close()
    }

}

