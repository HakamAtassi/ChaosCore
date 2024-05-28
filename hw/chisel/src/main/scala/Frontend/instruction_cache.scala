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
    val Active, Allocate, Replay = Value
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
        val cpu_addr            =     Flipped(Decoupled(UInt(32.W)))              // inputs from CPU
        val kill                =     Input(UInt(1.W))                            // Kill in progress request(s) 
                                                                                  // FIXME: this should be a bool
        val DRAM_resp           =     Flipped(Decoupled(Input(new DRAM_resp())))  // FROM DRAM

        // Outputs
        val cache_data          =     Decoupled(new fetch_packet(parameters))     // TO CPU
        val DRAM_request        =     Decoupled(new DRAM_request())               // TO DRAM
    })


    val miss            = Wire(Bool())

    val cache_state     = RegInit(cacheState(), cacheState.Active)
    val current_addr    = Wire(UInt(32.W))
    val current_data    = Wire(UInt(wayDataWidth.W))

    val replay_addr     = RegInit(UInt(32.W), 0.U)
    val replay_tag      = RegInit(UInt(tagBits.W), 0.U)
    val replay_valid    = RegInit(UInt(1.W), 0.U)



    val fetch_PC_buf    = RegInit(UInt(32.W), 0.U)

    val hit             = Wire(Bool())

    val current_addr_tag                = Wire(UInt(tagBits.W))
    val current_addr_set                = Wire(UInt(setBits.W))
    val current_addr_fetch_packet       = Wire(UInt(fetchPacketBits.W))
    val current_addr_instruction_offset = Wire(UInt(instructionBits.W))

    //
    val LRU_memory      = Module(new SDPReadWriteSmem(depth = sets, width = ways))
    val LRU             = Wire(UInt(ways.W))
    val hit_oh          = Wire(UInt(ways.W))
    val LRU_next        = Wire(UInt(ways.W))
    val allocate_way    = Wire(UInt(ways.W))


    val data_memory: Seq[ReadWriteSmem] = Seq.tabulate(ways) { w =>
        Module(new ReadWriteSmem(depth=sets, width=wayDataWidth))
    }

    val data_way    = Wire(Vec(ways, UInt(wayDataWidth.W)))
    val hit_oh_vec  = Wire(Vec(ways, UInt(1.W)))

    // Rename outputs for readability
    val memory_valid_vec = Wire(Vec(ways, UInt(1.W)))
    val memory_tags_vec  = Wire(Vec(ways, UInt(tagBits.W)))
    val memory_instr_vec = Wire(Vec(ways, UInt(dataSizeBits.W)))

    val hit_instruction_data = Wire(UInt(wayDataWidth.W)) 
    val instruction_vec      = Wire(Vec(instructionsPerLine, UInt(32.W)))   
    val packet_index         = RegInit(UInt(fetchPacketBits.W), 0.U)
    val aligned_packet_index = Wire(UInt(fetchPacketBits.W))

    val dram_addr_mask = ((1.U << 32.U) - (1.U << byteOffsetBits))

    // Address assignments
    // FIXME: There is a bug somewhere here I know it
    current_addr_tag                    := current_addr(31, 31-tagBits+1)
    current_addr_set                    := current_addr(31-tagBits, 31-tagBits-setBits+1)
    current_addr_fetch_packet           := current_addr(31-tagBits-setBits, 31-tagBits-setBits-fetchPacketBits+1)
    current_addr_instruction_offset     := current_addr(2+instructionsPerLine, 2) // The offset within the packet


    /////////
    // FSM //
    /////////
    
    io.DRAM_resp.ready           := 0.U
    io.DRAM_request.valid        := 0.U
    io.DRAM_request.bits.addr    := 0.U
    io.DRAM_request.bits.wr_data := 0.U
    io.DRAM_request.bits.wr_en   := 0.B

    when(io.cpu_addr.valid === 1.B){replay_addr := io.cpu_addr.bits}

    switch(cache_state){
        is(cacheState.Active){
            replay_tag := RegNext(io.cpu_addr.bits(31, 31-tagBits+1))
            io.DRAM_resp.ready  := 0.U   // cache not ready for data from DRAM in active state
            replay_valid        := 0.U
            when((miss===1.B && io.kill === 0.U)){           // Buffer current request, stall cache, go to wait state
                // Request data from DRAM
                cache_state := cacheState.Allocate
                io.DRAM_request.bits.addr   := RegNext(io.cpu_addr.bits) & dram_addr_mask
                io.DRAM_request.valid       := 1.U
                io.DRAM_resp.ready          := 1.U
            }
            when(!miss){
                packet_index := current_addr_fetch_packet
                fetch_PC_buf := io.cpu_addr.bits
            }.otherwise{
                packet_index := packet_index
                fetch_PC_buf := fetch_PC_buf
            }
        }
        is(cacheState.Allocate){            // Stall till DRAM response. On Response, allocate.
            io.DRAM_resp.ready          := 1.U      // Ready to accept DRAM data
            io.DRAM_request.valid       := 1.U      // ...
            io.DRAM_request.bits.addr   := RegNext(io.DRAM_request.bits.addr)      // Only Request once...
            when(io.DRAM_request.ready){
                io.DRAM_request.bits.addr   := 0.U      // Only Request once...
                io.DRAM_request.valid       := 0.U      // ...
            }

            replay_valid        := 0.U
            when(io.kill === 1.U){
                cache_state := cacheState.Active    // Ignore miss, go back to active.
            }.elsewhen(io.DRAM_resp.valid===1.U){ // Data received
                replay_valid        := 1.U  // Perform replay of cache miss
                io.DRAM_resp.ready  := 0.U  // Data received; no longer ready
                cache_state := cacheState.Replay    // Allow cycle for cache replay
            }
        }
        is(cacheState.Replay){                      // Replay initial request. Go back to active
            cache_state     := cacheState.Active    // Go back to active after replay
            replay_valid    := 0.U                  // Replay done
        }
    }

    // Address arbitration
    current_addr := Mux(cache_state=/=cacheState.Active || miss, replay_addr, io.cpu_addr.bits) // During allocate and replay, current address is from buffered request. 
    current_data := Cat(1.U, replay_tag, io.DRAM_resp.bits.data)                             // 1 Bit valid, N bit tag, N bit data

    // For a new input to be accepted:
    // cache must be active
    // cache must not have just received a miss
    // output must be disposable 
    io.cpu_addr.ready := (cache_state === cacheState.Active) && !miss 
    //&& io.cache_data.ready                  // Even in active, cache can be non-ready due to detected miss



    ////////////////
    // LRU MEMORY //
    ////////////////

    LRU_memory.io.enable  := 1.B
    LRU_memory.io.rd_addr := current_addr_set
    LRU_memory.io.wr_addr := RegNext(current_addr_set)
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

    for (way <- 0 until ways){
        data_memory(way).io.enable  := 1.B

        data_memory(way).io.addr    := current_addr_set
        data_way(way)               := data_memory(way).io.data_out

        data_memory(way).io.wr_en   := io.DRAM_resp.valid & allocate_way(way)
        data_memory(way).io.data_in := current_data
    }

    // Memory:  N Bits
    // Valid:   Bit (N-1)
    // Tag:     Bit (N-validBits-1, N-validBits-1-tagBits+1)
    for (way <- 0 until ways){
        memory_valid_vec(way)  := data_way(way)(wayDataWidth-1)
        memory_tags_vec(way)   := data_way(way)(wayDataWidth-1-validBits, wayDataWidth-1-validBits-tagBits+1)
        memory_instr_vec(way)  := data_way(way)(wayDataWidth-1-validBits-tagBits, 0)
    }

    dontTouch(memory_tags_vec)

    for (way <- 0 until ways) {
      hit_oh_vec(way) := (memory_tags_vec(way) === RegNext(current_addr_tag)) && memory_valid_vec(way).asBool
    }

    hit_oh := hit_oh_vec.reverse.reduce(_ ## _)


    hit     := (hit_oh.orR & (RegNext(io.cpu_addr.valid) | RegNext(replay_valid))) & !RegNext(io.kill) & !RegNext(reset.asBool)
    miss    := (~hit_oh.orR) & (RegNext(io.cpu_addr.valid) | RegNext(replay_valid)) & !RegNext(io.kill) & !RegNext(reset.asBool)



    /////////////////////////////////////
    // Fetch Packet Selecting & Output //
    /////////////////////////////////////

    //packet_index := RegNext(current_addr_fetch_packet)  
    aligned_packet_index := packet_index & ~(fetchWidth.U * 4.U -1.U)


    hit_instruction_data := 0.U         // Get instruction vector of the hit way (if any)
    for (i <- 0 until ways){
        when(hit_oh(i)===1.B){
            hit_instruction_data := memory_instr_vec(i)
        }
    }

    for(instruction <- 0 until instructionsPerLine){    // split hit line into its constituent instructions
        instruction_vec(instruction) := hit_instruction_data((instruction+1)*32-1, (instruction)*32)    
    }

    io.cache_data.bits.instructions := DontCare

    for(i <- 0 until fetchWidth){
        io.cache_data.bits.instructions(i).instruction:= instruction_vec(packet_index*fetchWidth.U + i.U)   
    }

    dontTouch(current_addr_instruction_offset)




    val validator = Module(new instruction_validator(fetchWidth=fetchWidth))
    validator.io.instruction_index := current_addr_instruction_offset

    for(i <- 0 until fetchWidth){
        io.cache_data.bits.valid_bits(i):= RegNext(validator.io.instruction_output(fetchWidth-1-i)) && hit && (io.kill === 0.U)  // only valid if not hit
    }



    io.cache_data.valid   := hit && (io.kill === 0.U)

    io.cache_data.bits.fetch_PC := fetch_PC_buf

    // FIXME: 
    
    validator.io.instruction_index := current_addr_instruction_offset



    // Kill handling
    // Kills essentially mean that a redirect or similar is taking place. Any in-progress computations/reads/writes/etc and invalidated after a kill
    // However, transactions are defined by internal state and output.
    // So, any input is still processed. If a module is connected to a fifo on its input, the fifo is responsible for invalidating its output during a kill.
    // The cache is responsible for invalidating any in progress reads and invalidating current outputs.

    // If output is valid but kill is requested: invalidate output
    // If fetch in progress but kill is requested: kill in progress request, go back to active
    // The above can happen at the same time in any combination...


    // when kill is high, current input should not be high...
    // This leaves 2 possible cases:
    // Either previous input resulted in a high output, which is invalid if kill is high.
    // Or a previous input resulted in the current state to be "allocate" or is about to go into allocate (miss)
    

    // So, output is invalid if kill is high
    // Or revert state/do send to active on kill


}