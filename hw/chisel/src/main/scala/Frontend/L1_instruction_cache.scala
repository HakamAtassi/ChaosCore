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
import chisel3.util._
import java.io.{File, FileWriter}
import java.rmi.server.UID
//import chisel3.experimental.ChiselEnum


object cacheState extends ChiselEnum{
    val Active, Request, Allocate, Kill, Replay, Stall = Value
}

class instruction_validator(fetchWidth: Int) extends Module {
  val io = IO(new Bundle {
    val instruction_index = Input(UInt(log2Ceil(fetchWidth).W))
    val instruction_output = Output(UInt(fetchWidth.W))
  })
    // instruction offset -> valid mask
    //fetch width = 2
        // 0 -> 11
        // 1 -> 01

    // fetch width = 4
        //00 -> 1111
        //01 -> 0111
        //10 -> 0011
        //11 -> 0001

    val masks = VecInit(Seq.tabulate(fetchWidth)(i => ((1 << (fetchWidth - i)) - 1).U(fetchWidth.W)))
    io.instruction_output := masks(io.instruction_index)
}

class L1_instruction_cache(val coreParameters:CoreParameters, val nocParameters:NOCParameters) extends Module with AXICacheNode{
    import coreParameters._

    val ways = L1_instructionCacheWays
    val sets = L1_instructionCacheSets

    val blockSizeBytes = L1_cacheLineSizeBytes

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
    val consumedKBData              = (sets*ways*dataSizeBits)/8.0/1024.0 


    println("========================================")
    println("========== BUILDING L1 I-CACHE =========")
    println("========================================")
    println("Parameters:")
    println("-----------------------------------------")
    println(f"Fetch Width     : ${fetchWidth}%-10d")
    println(f"Ways            : ${ways}%-10d")
    println(f"Sets            : ${sets}%-10d")
    println(f"Block Size      : ${blockSizeBytes} B")
    println("-----------------------------------------")
    println(f"Total Consumed Memory (data): ${consumedKBData}%.2f KB")
    println(f"Total Consumed Memory : ${consumedKB}%.2f KB")
    println("=========================================")
    println("\n\n")


    val io = IO(new Bundle{
        val CPU_request         =     Flipped(Decoupled(new frontend_memory_request(coreParameters)))            // Inputs from CPU
        val CPU_response        =     Decoupled(new fetch_packet(coreParameters))                       // TO CPU
        val flush               =     Flipped(ValidIO(new flush(coreParameters)))
    })



    ////////////////////
    // OUTPUT BUNDLES //
    ////////////////////
    val CPU_response         = Wire(Decoupled(new fetch_packet(coreParameters)))
    CPU_response := DontCare

    val cache_state     = RegInit(cacheState(), cacheState.Active)

    val current_data    = Wire(new instruction_cache_data_line(coreParameters))
    val fetch_PC_buf    = RegInit(new frontend_memory_request(coreParameters), 0.U.asTypeOf(new frontend_memory_request(coreParameters)))//RegInit(UInt(32.W), 0.U)

    val miss            = Wire(Bool())
    val hit             = Wire(Bool())

    //
    val LRU_memory      = Module(new SDPReadWriteSmem(depth = sets, width = ways))
    val LRU             = Wire(UInt(ways.W))
    val hit_oh          = Wire(UInt(ways.W))
    val LRU_next        = Wire(UInt(ways.W))
    val allocate_way    = Wire(UInt(ways.W))

    // 
    val replay_address          = RegInit(new frontend_memory_request(coreParameters), 0.U.asTypeOf(new frontend_memory_request(coreParameters)))

    val current_packet          = Wire(new instruction_cache_address_packet(coreParameters))


    val data_memory: Seq[icache_ReadWriteSmem[instruction_cache_data_line]] = Seq.tabulate(ways) { w =>
        Module(new icache_ReadWriteSmem(depth=sets, dataType=new instruction_cache_data_line(coreParameters)))
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


	val axi_response = Wire(UInt((L1_cacheLineSizeBytes*8).W))
	val axi_response_valid = Wire(Bool())

    axi_response := 0.U
    axi_response_valid := 0.B

    val already_requested = RegInit(Bool(), 0.B)


    switch(cache_state){

        is(cacheState.Active){  // Wait for request

            when(miss===1.B && io.flush.valid === 0.U){           // Buffer current request, stall cache, go to wait state
		        val read_accepted = AXI_read_request(request_addr, 0.U, L1_cacheLineSizeBytes.U)
                when(read_accepted){
                    cache_state              := cacheState.Allocate
                }.otherwise{
                    cache_state              := cacheState.Request
                }
            }.otherwise{
                request_addr   := io.CPU_request.bits.addr & dram_addr_mask
                replay_address := io.CPU_request.bits  // if miss, buffer address
                fetch_PC_buf   := io.CPU_request.bits
            }
        }

        is(cacheState.Request){
            val read_accepted = AXI_read_request(request_addr, 0.U, L1_cacheLineSizeBytes.U)
            when(read_accepted){
                cache_state              := cacheState.Allocate
            }
        }

        is(cacheState.Allocate){    // wait for response
            when(io.flush.valid === 1.U){
                cache_state := cacheState.Kill    // Ignore miss, go back to active.
                cache_valid := 0.B
            }.otherwise{
	            val (_axi_response, _axi_response_valid) = AXI_read
                axi_response := _axi_response.data
                axi_response_valid := _axi_response_valid
                when(axi_response_valid){         // DRAM response accepted
                    cache_state := cacheState.Replay    // Allow cycle for cache replay
                }
            }
        }

        is(cacheState.Kill){    // wait for response
            val (_axi_response, _axi_response_valid) = AXI_read
            axi_response := _axi_response.data
            axi_response_valid := _axi_response_valid
            when(axi_response_valid){         // DRAM response accepted
                cache_state := cacheState.Active    // Allow cycle for cache replay
            }
        }

        is(cacheState.Replay){
            when(io.flush.valid === 1.U){
                cache_state := cacheState.Active    // Ignore miss, go back to active.
                cache_valid := 0.B
            }.otherwise{
                when(CPU_response.valid && CPU_response.ready){   // Cache output accepted
                    cache_valid := 0.B
                    cache_state     := cacheState.Active    // Go back to active after replay
                }
            }
        }


    }

    // Address arbitration

    val current_address = Wire(new frontend_memory_request(coreParameters)) //Wire(UInt(32.W))

    current_address     := Mux(cache_state=/=cacheState.Active || miss, replay_address, io.CPU_request.bits) // During allocate and replay, current address is from buffered request. 
    current_packet      := get_decomposed_icache_address(coreParameters, current_address.addr)
    

    dontTouch(current_address)
    dontTouch(current_packet)
    

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
    current_data.tag    := get_decomposed_icache_address(coreParameters, replay_address.addr).tag
    current_data.data   := axi_response

    ///////////////////////////////
    // ASSIGN DATA MEMORY READS //
    ///////////////////////////////

    val data_way    = Wire(Vec(ways, new instruction_cache_data_line(coreParameters)))
    for (way <- 0 until ways){
        data_memory(way).io.enable  := 1.B
        data_memory(way).io.addr    := current_packet.set
        data_way(way)               := data_memory(way).io.data_out
    }

    ///////////////////////////////
    // ASSIGN DATA MEMORY WRITES //
    ///////////////////////////////
    
    for (way <- 0 until ways){
        data_memory(way).io.wr_en   := axi_response_valid & allocate_way(way) && (cache_state === cacheState.Allocate)
        data_memory(way).io.data_in := current_data
    }


    for (way <- 0 until ways) {
      hit_oh_vec(way) := (data_way(way).tag === RegNext(current_packet.tag)) && data_way(way).valid
    }

    hit_oh := hit_oh_vec.reverse.reduce(_ ## _)


    val replay_valid = Wire(Bool())
    replay_valid := cache_state === cacheState.Replay

    hit     := (hit_oh.orR & (RegNext(io.CPU_request.fire && cache_state === cacheState.Active) | replay_valid)) & !RegNext(io.flush.valid) & !RegNext(reset.asBool)
    miss    := (~hit_oh.orR) & (RegNext(io.CPU_request.fire) | replay_valid) & !RegNext(io.flush.valid) & !RegNext(reset.asBool)

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

    dontTouch(instruction_vec)

    for(i <- 0 until fetchWidth){
        CPU_response.bits.instructions(i).instruction  := instruction_vec(RegNext(current_packet.fetch_packet)*fetchWidth.U + i.U)   
        CPU_response.bits.instructions(i).packet_index := i.U
        CPU_response.bits.instructions(i).ROB_index    := 0.U
    }

    val validator = Module(new instruction_validator(fetchWidth=fetchWidth))

    validator.io.instruction_index := get_decomposed_icache_address(coreParameters, CPU_response.bits.fetch_PC).instruction_offset //current_packet.instruction_offset

    for(i <- 0 until fetchWidth){
        CPU_response.bits.valid_bits(i):= validator.io.instruction_output(fetchWidth-1-i) && CPU_response.valid
    }

    //////////////////
    // SKID BUFFERS //
    //////////////////
    // predecoded instruction & FTQ outputs passed through a skid buffer

    CPU_response.valid     := (cache_valid || hit) && !(io.flush.valid || RegNext(io.flush.valid))

    // For a new input to be accepted:
    // cache must be active
    // cache must not have just received a miss
    // output must be disposable 
    io.CPU_request.ready := (cache_state === cacheState.Active) && !miss //&& io.CPU_response.ready

    // FIXME: critical path here...
    val CPU_response_skid_buffer         = Module(new Queue(new fetch_packet(coreParameters), 2, flow=false, hasFlush=true, useSyncReadMem=false))

    CPU_response_skid_buffer.io.enq                  <> CPU_response
    CPU_response_skid_buffer.io.flush.get            <> io.flush.valid

    CPU_response.bits.fetch_PC := fetch_PC_buf.addr

    CPU_response_skid_buffer.io.deq                  <> io.CPU_response
    

}