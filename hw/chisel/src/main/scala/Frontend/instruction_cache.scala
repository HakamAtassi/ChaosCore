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
import chisel3._
import circt.stage.ChiselStage
import chisel3.util._
import java.io.{File, FileWriter}
import java.rmi.server.UID


object cacheState extends ChiselEnum{
    val Active, Allocate, Replay = Value
}


// FIXME: this only works for width=2 or 4.
class instruction_validator(fetchWidth: Int = 4) extends Module {
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

class L1_instruction_cache(fetchWidth:Int=4, ways:Int=2, sets:Int = 64, blockSizeBytes:Int = 64) extends Module{


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
    val wayDataWidth                = (validBits + tagBits) + dataSizeBits                              // width of the data line
    val consumedKB                  = (64*ways*wayDataWidth + sets*LRUBits)/8/1024 



    println(s"Buidling L1 Cache")
    println(s"Cache Config: Fetch Width=${fetchWidth}, Ways=${ways}, Sets=${sets}, Block Size=${blockSizeBytes}B")
    println(s"Consumed memory: ${consumedKB}KB")


    val io = IO(new Bundle{
        val cpu_addr           =     Flipped(Decoupled(UInt(32.W)))               // inputs from CPU
        val dram_data          =     Flipped(Decoupled(UInt(dataSizeBits.W)))     // inputs from DRAM
        val kill               =     Input(UInt(1.W))                             // Kill in progress request(s) 
                                                                                  // FIXME: this should be a bool

        // Outputs
        val cache_data         =     Output(new fetch_packet(width=fetchWidth))
        val resp_valid         =     Output(Bool())

        val cache_addr         =     Decoupled(UInt(32.W))                        // outputs to DRAM
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
    val packet_index         = Wire(UInt(fetchPacketBits.W))
    val aligned_packet_index = Wire(UInt(fetchPacketBits.W))


    dontTouch(current_addr_tag)
    dontTouch(current_addr_set)
    dontTouch(current_addr_instruction_offset)

    // Address assignments
    // FIXME: There is a bug somewhere here I know it
    current_addr_tag                    := current_addr(31, 31-tagBits+1)
    current_addr_set                    := current_addr(31-tagBits, 31-tagBits-setBits+1)
    current_addr_fetch_packet           := current_addr(31-tagBits-setBits, 31-tagBits-setBits-fetchPacketBits+1)
    current_addr_instruction_offset     := current_addr(2+instructionsPerLine, 2) // The offset within the packet

    /////////
    // FSM //
    /////////
    
    io.cache_addr.bits  := 0.U
    io.cache_addr.valid := 0.U
    io.dram_data.ready  := 0.U

    switch(cache_state){
        is(cacheState.Active){
            fetch_PC_buf := io.cpu_addr.bits
            replay_addr := io.cpu_addr.bits
            replay_tag := io.cpu_addr.bits(31, 31-tagBits+1)
            io.dram_data.ready := 0.U   // cache not ready for data from DRAM in active state
            when((miss===1.B) && (io.kill === 0.U)){           // Buffer current request, stall cache, go to wait state
                // Request data from DRAM
                cache_state := cacheState.Allocate
                io.cache_addr.bits  := replay_addr
                io.cache_addr.valid := 1.U
                io.dram_data.ready  := 1.U
            }
        }
        is(cacheState.Allocate){            // Stall till DRAM response. On Response, allocate.
            io.cache_addr.bits  := 0.U      // Only Request once...
            io.cache_addr.valid := 0.U      // ...
            io.dram_data.ready  := 1.U      // Ready to accept DRAM data
            when(io.kill === 1.U){
                cache_state := cacheState.Active    // Ignore miss, go back to active.
            }.elsewhen(io.dram_data.valid===1.U){ // Data received
                replay_valid        := 1.U  // Perform replay of cache miss
                io.dram_data.ready  := 0.U  // Data received; no longer ready
                cache_state := cacheState.Replay    // Allow cycle for cache replay
            }
        }
        is(cacheState.Replay){                      // Replay initial request. Go back to active
            cache_state     := cacheState.Active    // Go back to active after replay
            replay_valid    := 0.U                  // Replay done
        }
    }

    // Address arbitration
    current_addr := Mux(cache_state=/=cacheState.Active, replay_addr, io.cpu_addr.bits) // During allocate and replay, current address is from buffered request. 
    current_data := Cat(1.U, replay_tag, io.dram_data.bits)                             // 1 Bit valid, N bit tag, N bit data

    io.cpu_addr.ready := (cache_state === cacheState.Active) && !miss                   // Even in active, cache can be non-ready due to detected miss

    ////////////////
    // LRU MEMORY //
    ////////////////

    LRU_memory.io.enable := 1.B

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
        data_memory(way).io.enable := 1.B

        data_memory(way).io.addr    := current_addr_set
        data_way(way)               := data_memory(way).io.data_out

        data_memory(way).io.wr_en   := io.dram_data.valid & allocate_way(way)
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

    for (way <- 0 until ways) {
      hit_oh_vec(way) := (memory_tags_vec(way) === RegNext(current_addr_tag)) && memory_valid_vec(way).asBool
    }

    hit_oh := hit_oh_vec.reverse.reduce(_ ## _)


    hit     := (hit_oh.orR & (RegNext(io.cpu_addr.valid) | RegNext(replay_valid)))
    miss    := (~hit_oh.orR) & (RegNext(io.cpu_addr.valid) | RegNext(replay_valid))



    /////////////////////////////////////
    // Fetch Packet Selecting & Output //
    /////////////////////////////////////

    packet_index := RegNext(current_addr_fetch_packet)  
    aligned_packet_index := packet_index & ~(fetchWidth.U * 4.U -1.U)


    hit_instruction_data := 0.U         // Get instruction vector of the hit way (if any)
    for (i <- 0 until ways){
        when(hit_oh(i)===1.B){
            hit_instruction_data := memory_instr_vec(i)
        }
    }

    for(instruction <- 0 until instructionsPerLine){    // split hit line into its constituent instructions
        instruction_vec(instructionsPerLine-1-instruction) := hit_instruction_data((instruction+1)*32-1, (instruction)*32)    
    }


    for(i <- 0 until fetchWidth){
        io.cache_data.instructions(i):= instruction_vec(packet_index*fetchWidth.U + i.U)   
    }

    val validator = Module(new instruction_validator(fetchWidth=fetchWidth))
    validator.io.instruction_index := current_addr_instruction_offset

    for(i <- 0 until fetchWidth){
        io.cache_data.valid_bits(i):= RegNext(validator.io.instruction_output(fetchWidth-1-i)) && hit && (io.kill === 0.U)  // only valid if not hit
    }
    io.resp_valid   := hit && (io.kill === 0.U)

    io.cache_data.fetch_PC := fetch_PC_buf

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