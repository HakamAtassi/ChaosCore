/* ------------------------------------------------------------------------------------
* Filename: instruction_cache.scala
* Author: Hakam Atassi
* Date: Apr 17 2024
* Description: A blocking single cycle latency instruction cache with no CPU write port (no self modifying functionality). Configurable width (2-wide, 4-wide).
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

import Thermometor._

object cacheState extends ChiselEnum{
    val Active, Allocate, Replay, Stall = Value
}
class instruction_validator(fetchWidth: Int) extends Module {
  val io = IO(new Bundle {
    val instruction_index = Input(UInt(log2Ceil(fetchWidth).W))
    val instruction_output = Output(UInt(fetchWidth.W))
  })

  val lookupTable = fetchWidth match {
    case 2 =>
      // Define the lookup table for fetchWidth = 2
      VecInit(
        "b11".U(fetchWidth.W), // 0 -> 11
        "b01".U(fetchWidth.W)  // 1 -> 01
      )
    case 4 =>
      // Define the lookup table for fetchWidth = 4
      VecInit(
        "b1111".U(fetchWidth.W), // 00 -> 1111
        "b0111".U(fetchWidth.W), // 01 -> 0111
        "b0011".U(fetchWidth.W), // 10 -> 0011
        "b0001".U(fetchWidth.W)  // 11 -> 0001
      )
    case _ =>
      VecInit(Seq.fill(fetchWidth)(0.U(fetchWidth.W)))
  }

  io.instruction_output := lookupTable(io.instruction_index)
}

// TODO: need a module that converts L1 miss to a proper DRAM request. 

class instruction_cache(parameters:Parameters) extends Module{
    import parameters._


    val ways = L1_instructionCacheWays
    val sets = L1_instructionCacheSets

    val blockSizeBytes = L1_instructionCacheBlockSizeBytes

    val depth                       = sets
    val byteOffsetBits              = log2Ceil(blockSizeBytes)                                          // Bits needed to each byte in a cache line
    val setBits                     = log2Ceil(sets)                                                    // Bits needed to address sets
    val wayBits                     = log2Ceil(ways)                                                    // Bits needed to address ways
    val validBits                   = 1                                                                 // number of valid bits
    val LRUBits                     = ways                                                              // number of LRU bits (per way)
    val dataSizeBits                = blockSizeBytes*8                                                  // number of raw data bits
    val instructionsPerLine         = blockSizeBytes/4                                                  // number of instructions per cache line (no compressed instruction support)
    val fetchPacketsPerLine         = instructionsPerLine/fetchWidth                                    // number of fetch packets per cache line
    val fetchPacketBits             = log2Ceil(fetchPacketsPerLine)                                     // number of bits needed to address fetch packet in cache line (fetches always packet aligned)
    val instructionBits             = log2Ceil(instructionsPerLine)                                     // number of bits needed to address fetch packet in cache line (fetches always packet aligned)
    val instructionsPerPacketBits   = log2Ceil(fetchWidth)                                              // number of bits needed to address each instruction in a fetch packet
    val tagBits                     = 32 - setBits - fetchPacketBits - instructionsPerPacketBits - 2    // 32 - bits required to index set - bits required to index within line - 2 bits due to 4 byte aligned data
    val wayDataWidth                = validBits + tagBits + dataSizeBits                              // width of the data line

    val consumedKB                  = (sets*ways*wayDataWidth + sets*LRUBits)/8.0/1024.0 


    println(s"Buidling L1 Cache")
    println(s"Cache Config: Fetch Width=${fetchWidth}, Ways=${ways}, Sets=${sets}, Block Size=${blockSizeBytes}B")
    println(s"Consumed memory: ${consumedKB}KB")


    val io = IO(new Bundle{
        // Inputs
        val cpu_addr            =     Flipped(Decoupled(UInt(32.W)))                        // inputs from CPU
        val kill                =     Input(Bool())                                         // Kill in progress request(s) 

        val DRAM_resp           =     Flipped(Decoupled(Input(new DRAM_resp(parameters))))  // FROM DRAM

        // Outputs
        val cache_data          =     Decoupled(new fetch_packet(parameters))               // TO CPU
        val DRAM_request        =     Decoupled(new DRAM_request(parameters))               // TO DRAM
    })



    val cache_state     = RegInit(cacheState(), cacheState.Active)

    val current_data    = Wire(new instruction_cache_data_line(parameters))
    val fetch_PC_buf    = RegInit(UInt(32.W), 0.U)

    val miss            = Wire(Bool())
    val hit             = Wire(Bool())

    //
    val LRU_memory      = Module(new SDPReadWriteSmem(depth = sets, width = ways))
    val LRU             = Wire(UInt(ways.W))
    val hit_oh          = Wire(UInt(ways.W))
    val LRU_next        = Wire(UInt(ways.W))
    val allocate_way    = Wire(UInt(ways.W))

    // 
    val replay_address          = RegInit(UInt(32.W), 0.U)

    val current_packet          = Wire(new instruction_cache_address_packet(parameters))


    val data_memory: Seq[icache_ReadWriteSmem[instruction_cache_data_line]] = Seq.tabulate(ways) { w =>
        Module(new icache_ReadWriteSmem(depth=sets, dataType=new instruction_cache_data_line(parameters)))
    }

    val hit_oh_vec  = Wire(Vec(ways, UInt(1.W)))

    val hit_instruction_data = Wire(UInt(wayDataWidth.W)) 
    val instruction_vec      = Wire(Vec(instructionsPerLine, UInt(32.W)))   
    val aligned_packet_index = Wire(UInt(fetchPacketBits.W))

    val dram_addr_mask = ((1.U << 32.U) - (1.U << byteOffsetBits))

    /////////
    // FSM //
    /////////

    val request_valid   = RegInit(Bool(), 0.B)
    val request_addr    = RegInit(UInt(32.W), 0.B)
    val request_data    = RegInit(UInt(32.W), 0.B)
    val request_wr_en   = RegInit(Bool(), 0.B)
    val resp_ready      = RegInit(Bool(), 0.B)
    val cache_valid     = RegInit(Bool(), 0.B)

    //RegInit(Bool(), 0.B)
    

    io.DRAM_resp.ready           := resp_ready

    io.DRAM_request.valid        := request_valid
    io.DRAM_request.bits.addr    := request_addr
    io.DRAM_request.bits.wr_data := request_data
    io.DRAM_request.bits.wr_en   := request_wr_en

    io.cache_data.valid     := cache_valid || hit

    val already_requested = RegInit(Bool(), 0.B)

    switch(cache_state){

        is(cacheState.Active){  // Wait for request

            when(miss===1.B && io.kill === 0.U){           // Buffer current request, stall cache, go to wait state

                request_addr             := RegNext(io.cpu_addr.bits) & dram_addr_mask
                request_valid            := 1.B
                resp_ready               := 1.B

                cache_state              := cacheState.Allocate

            }.otherwise{
                replay_address := io.cpu_addr.bits  // if miss, buffer address
                fetch_PC_buf    :=  io.cpu_addr.bits
            }
        }

        is(cacheState.Allocate){    // wait for response

            when(io.DRAM_request.ready && io.DRAM_request.valid){   // DRAM request accepted
                request_addr             := 0.U
                request_valid            := 0.B
            }

            when(io.DRAM_resp.valid && io.DRAM_resp.ready){         // DRAM response accepted
                resp_ready  := 0.U  // Data received; no longer ready
                cache_valid := 1.B
                cache_state := cacheState.Replay    // Allow cycle for cache replay
            }

            when(io.kill === 1.U){
                cache_state := cacheState.Active    // Ignore miss, go back to active.
            }
        }

        is(cacheState.Replay){
            when(io.cache_data.valid && io.cache_data.ready){   // Cache output accepted
                cache_valid := 0.B
                cache_state     := cacheState.Active    // Go back to active after replay
            }
        }


    }

    // Address arbitration

    val current_address = Wire(UInt(32.W))
    dontTouch(current_address)

    current_address     := Mux(cache_state=/=cacheState.Active || miss, replay_address, io.cpu_addr.bits) // During allocate and replay, current address is from buffered request. 
    current_packet      := get_decomposed_icache_address(parameters, current_address)
    dontTouch(current_packet)
    
    // For a new input to be accepted:
    // cache must be active
    // cache must not have just received a miss
    // output must be disposable 
    io.cpu_addr.ready := (cache_state === cacheState.Active) && !miss 


    ////////////////
    // LRU MEMORY //
    ////////////////

    LRU_memory.io.enable  := 1.B
    LRU_memory.io.rd_addr := current_packet.set
    LRU_memory.io.wr_addr := RegNext(current_packet.set)
    LRU_memory.io.wr_en   := hit
    LRU_memory.io.data_in := LRU_next

    LRU := LRU_memory.io.data_out

    LRU_next := Mux((LRU | hit_oh).andR, hit_oh, LRU | hit_oh)

    allocate_way := 0.U
    for(i <- 0 until ways){
        when(LRU(i) === 0.U){
            allocate_way := (1.U<<i)
        }
    }

    ///////////////////
    // DATA MEMORIES //
    ///////////////////

    current_data.valid  := 1.B
    current_data.tag    := get_decomposed_icache_address(parameters, replay_address).tag
    current_data.data   := io.DRAM_resp.bits.data

    ///////////////////////////////
    // ASSIGN DATA MEMORY READS //
    ///////////////////////////////

    val data_way    = Wire(Vec(ways, new instruction_cache_data_line(parameters)))
    for (way <- 0 until ways){
        data_memory(way).io.enable  := 1.B
        data_memory(way).io.addr    := current_packet.set
        data_way(way)               := data_memory(way).io.data_out
    }

    //////////////////////////////
    // ASSIGN DATA MEMORY WRITES //
    //////////////////////////////
    
    for (way <- 0 until ways){
        data_memory(way).io.wr_en   := io.DRAM_resp.valid & allocate_way(way) && (cache_state === cacheState.Allocate)
        data_memory(way).io.data_in := current_data
    }


    for (way <- 0 until ways) {
      hit_oh_vec(way) := (data_way(way).tag === RegNext(current_packet.tag)) && data_way(way).valid
    }

    hit_oh := hit_oh_vec.reverse.reduce(_ ## _)


    val replay_valid = Wire(Bool())
    replay_valid := cache_state === cacheState.Replay

    hit     := (hit_oh.orR & (RegNext(io.cpu_addr.valid && cache_state === cacheState.Active) | replay_valid)) & !RegNext(io.kill) & !RegNext(reset.asBool)
    miss    := (~hit_oh.orR) & (RegNext(io.cpu_addr.valid) | replay_valid) & !RegNext(io.kill) & !RegNext(reset.asBool)

    /////////////////////////////////////
    // Fetch Packet Selecting & Output //
    /////////////////////////////////////

    aligned_packet_index := RegNext(current_packet.fetch_packet) & ~(fetchWidth.U * 4.U -1.U)


    hit_instruction_data := 0.U         // Get instruction vector of the hit way (if any)
    for (i <- 0 until ways){
        when(hit_oh(i)===1.B){
            hit_instruction_data := data_way(i).data
        }
    }

    for(instruction <- 0 until instructionsPerLine){    // split hit line into its constituent instructions
        instruction_vec(instruction) := hit_instruction_data((instruction+1)*32-1, (instruction)*32)    
    }



    for(i <- 0 until fetchWidth){
        io.cache_data.bits.instructions(i).instruction  := instruction_vec(RegNext(current_packet.fetch_packet)*fetchWidth.U + i.U)   
        io.cache_data.bits.instructions(i).packet_index := i.U
        io.cache_data.bits.instructions(i).ROB_index    := 0.U
    }

    val validator = Module(new instruction_validator(fetchWidth=fetchWidth))
    validator.io.instruction_index := current_packet.instruction_offset

    for(i <- 0 until fetchWidth){
        io.cache_data.bits.valid_bits(i):=validator.io.instruction_output(fetchWidth-1-i) && io.cache_data.valid
    }


    io.cache_data.bits.fetch_PC := fetch_PC_buf

    // FIXME: 
    validator.io.instruction_index := current_packet.instruction_offset

}