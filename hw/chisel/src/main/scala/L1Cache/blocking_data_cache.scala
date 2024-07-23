
/* ------------------------------------------------------------------------------------
* Filename: L1_Cache.scala
* Author: Hakam Atassi
* Date: Mar 12 2024
* Description: (Part of) A lockup-free L1 Cache. 
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

/*

object format_dcache_data {
  def apply(coreParameters:CoreParameters, data_way: Vec[UInt], address: UInt, operation: access_width_t): UInt = {
    val byte_offset = get_decomposed_dcache_address(address, parameters).byte_offset
    val word_offset = get_decomposed_dcache_address(address, parameters).byte_offset >> 2

    // Step 1: Group all 32 bytes in data way into their corresponding words.
    val words = VecInit(Seq.tabulate(8) { i =>
      val wordBytes = (0 until 4).map(j => data_way(i * 4 + j))
      wordBytes.reduce(Cat(_, _))
    })

    // Step 2: Shift all of these words down by the address's byte offset
    val shifted_words = words.map(_ >> (byte_offset * 8.U))

    // Step 3: Select the desired word
    val selected_word = shifted_words(word_offset)

    // Step 4: Perform mask based on access_width_t = {W, HW, B}
    val result = Wire(UInt(32.W))
    result := 0.U

    switch(operation) {
      is(access_width_t.B) {
        result := selected_word(7, 0)
      }
      is(access_width_t.HW) {
        result := selected_word(15, 0)
      }
      is(access_width_t.W) {
        result := selected_word
      }
    }

    result
  }
}



object cache_state_t extends ChiselEnum {
	val ACTIVE, MISS, STALL, EVICT, ALLOCATE, REPLAY = Value
}

class blocking_data_cache(coreParameters:CoreParameters, nocParameters:NOCParameters) extends Module{
    println("Buidling L1 Data Cache")
    val io = IO(new Bundle{
		// CPU PORT(s)
		val backend_memory_request            = Flipped(Decoupled(new backend_memory_request(coreParameters)))
		val backend_memory_response           = Decoupled(new backend_memory_response(coreParameters))

		// AXI //

		// FIXME: flush ??


    })


	val miss 			= Wire(Bool())
	val hit 			= Wire(Bool())

	val state 			= RegInit(cache_state_t(), cache_state_t.ACTIVE)
	val next_state 		= Wire(cache_state_t())

	// hashed input address
	val input_tag			= 	Wire(UInt(L1_DataCacheTagBits))
	val input_set			=	Wire(UInt(log2Ceil(L1_DataCacheSets)))
	val input_byte_offset	=	Wire(UInt(log2Ceil(L1_DataCacheBlockSizeBytes)))

	val hit_way				=	Wire(UInt(log2Ceil(L1_DataCacheWays)))

	val tag_match_OH 		= Wire(Vec(L1_DataCacheWays, Bool()))
	val updated_PLRU		= Wire(Vec(L1_DataCacheWays, Bool()))

	val read_data           = Wire(Vec(L1_DataCacheWays, UInt(8.W)))



	/////////
	// FSM //
	/////////
	next_state := state

	switch(state){
		is(cache_state_t.ACTIVE){

			for(i <- 0 until L1_DataCacheWays){
				// Read Tag memories
				tag_memories(i).io.enable 		:=		1.B
				tag_memories(i).io.addr 		:=		get_decomposed_dcache_address(io.backend_memory_request.bits.addr).set
				tag_memories(i).io.data_in 		:=		0.U
				tag_memories(i).io.wr_en		:=		0.B

				// Read valid memories
				valid_memories(i).io.enable 	:=		1.B
				valid_memories(i).io.addr 		:=		get_decomposed_dcache_address(io.backend_memory_request.bits.addr).set
				valid_memories(i).io.data_in 	:=		0.U
				valid_memories(i).io.wr_en 		:=		0.B
			}

			for(i <- 0 until L1_DataCacheBlockSizeBytes){
				// Read out data
				valid_memories(i).io.enable 	:=		1.B
				data_memories(i).io.addrA		:=		Cat(hit_way, RegNext(get_decomposed_dcache_address(io.backend_memory_request.bits.addr).set))
				valid_memories(i).io.data_in 	:=		0.U
				valid_memories(i).io.wr_en 		:=		0.B
			}

			// RMW PLRU
			PLRU_memory.io.addrA 			:=		get_decomposed_dcache_address(io.backend_memory_request.bits.addr).set
			PLRU_memory.io.writeEnableA 	:=		0.B
			PLRU_memory.io.writeDataA 		:=		0.U

			PLRU_memory.io.addrB 			:=		RegNext(get_decomposed_dcache_address(io.backend_memory_request.bits.addr).set)
			PLRU_memory.io.writeEnableB 	:=		hit
			PLRU_memory.io.writeDataB 		:=		updated_PLRU


			when(miss){
				next_state := cache_state_t.MISS
			}
		}
		is(cache_state_t.MISS){
			// send request to DRAM

			when(/**/){
				next_state := cache_state_t.STALL
			}
		}
		is(cache_state_t.STALL){
			when(/*complete cache line response ready*/){
				next_state := cache_state_t.STALL
			}
		}
		is(cache_state_t.EVICT){
			// Read out old cache line
			next_state := cache_state_t.ALLOCATE
		}
		is(cache_state_t.ALLOCATE){
			// write new cacheline into cache
			// Send old cache line for writeback

			// write cache line
			// write valid
			// write tag
			// write dirty 
			when(/*Old cache line write back accepted*/){
				next_state := cache_state_t.REPLAY
			}
		}
		is(cache_state_t.REPLAY){
			// Replay the miss request 
			for(i <- 0 until L1_DataCacheWays){
				// Read Tag memories
				tag_memories(i).io.enable 		:=		1.B
				tag_memories(i).io.addr 		:=		get_decomposed_dcache_address(replay_request.bits.addr).set
				tag_memories(i).io.data_in 		:=		0.U
				tag_memories(i).io.wr_en		:=		0.B

				// Read valid memories
				valid_memories(i).io.enable 	:=		1.B
				valid_memories(i).io.addr 		:=		get_decomposed_dcache_address(replay_request.bits.addr).set
				valid_memories(i).io.data_in 	:=		0.U
				valid_memories(i).io.wr_en 		:=		0.B
			}

			for(i <- 0 until L1_DataCacheBlockSizeBytes){
				// Read out data
				valid_memories(i).io.enable 	:=		1.B
				data_memories(i).io.addrA		:=		Cat(???, get_decomposed_dcache_address(replay_request.bits.addr).set)
				valid_memories(i).io.data_in 	:=		0.U
				valid_memories(i).io.wr_en 		:=		0.B
			}

			// Read PLRU (modify in active)
			PLRU_memory.io.addrA 			:=		get_decomposed_dcache_address(replay_request.bits.addr).set
			PLRU_memory.io.writeEnableA 	:=		0.B
			PLRU_memory.io.writeDataA 		:=		0.U

			next_state := cache_state_t.ACTIVE
		}
	}

	state := next_state

	//////////
	// MISC //
	//////////

	hit := RegNext(io.backend_memory_request.valid || (state === cache_state_t.REPLAY)) && tag_match_OH.reduce(_ || _)
	miss := RegNext(io.backend_memory_request.valid || (state === cache_state_t.REPLAY)) && !(tag_match_OH.reduce(_ || _))

	///////////////////
	// DATA MEMORIES //
	///////////////////
    val data_memories = Seq.tabulate(L1_DataCacheBlockSizeBytes) { w =>
        Module(new ReadWriteSmem(depth=L1_DataCacheSets, width=8))
    }

    //FIXME: this output depends on the last viable output that was requested of the dcache, being either from the input or from replay
    io.backend_memory_response.bits.data := RegNext(format_dcache_data(coreParameters, read_data, request_address, operation))  // 

	//////////////////
	// TAG MEMORIES //
	//////////////////
    val tag_memories = Seq.tabulate(L1_DataCacheWays) { w =>
        Module(new ReadWriteSmem(depth=L1_DataCacheSets, width=L1_DataCacheTagBits))
    }

	for(i <- 0 until L1_DataCacheWays){
		tag_match_OH(i) := tag_memories(i).readDataA === RegNext(input_tag)
	}


	////////////////////
	// VALID MEMORIES //
	////////////////////
    val valid_memories = Seq.tabulate(L1_DataCacheWays) { w =>
        Module(new ReadWriteSmem(depth=L1_DataCacheSets, width=1))
    }


	val valid := valid_memories.map(_.readDataA)

	///////////////////
	// PLRU MEMORIES //
	///////////////////
    val PLRU_memory = Module(new TrueDualPortMemory(depth=L1_DataCacheSets, width=L1_DataCacheWays))


	val PLRU := PLRU_memory.map(_.readDataA)

	/////////////////
	// UPDATE PLRU //
	/////////////////

	when((PLRU || (tag_match_OH && valid)).reduce(_ && _)){
		updated_PLRU := tag_match_OH
	}.otherwise{
		updated_PLRU := PLRU || (tag_match_OH && valid) 
	}


	/////////
	// AXI //
	/////////



	io.backend_memory_request.ready := DontCare
	io.backend_memory_response 		:= DontCare

	io.data_cache_A := DontCare
	io.data_cache_D := DontCare



}

*/