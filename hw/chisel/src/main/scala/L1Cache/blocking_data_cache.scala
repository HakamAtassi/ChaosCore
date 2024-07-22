
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

object cache_state_t extends ChiselEnum {
	val ACTIVE, MISS, STALL, EVICT, ALLOCATE, REPLAY = Value
}

class blocking_data_cache(coreParameters:CoreParameters, nocParameters:NOCParameters) extends Module{
    println("Buidling L1 Data Cache")
    val io = IO(new Bundle{
		// CPU PORT(s)
		val backend_memory_request            = Flipped(Decoupled(new backend_memory_request(coreParameters)))
		val backend_memory_response           = Decoupled(new backend_memory_response(coreParameters))

		// DRAM PORT(s)
		val data_cache_A                      =	Decoupled(new TileLink_Channel_A())   	// D$ Request
		val data_cache_D                      = Flipped(Decoupled(new TileLink_Channel_D()))   			// Bus granted request

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

	////////////////////////
	// GENERATE ADDRESSES //
	////////////////////////
	// Possible states: ACTIVE, EVICT, ALLOCATE, REPLAY
	// Active: current_address == input_address
	// EVICT: current_address == miss_address
	// ALLOCATE: current_address == allocate_address
	// REPLAY: current_address == replay_address


	///////////////////
	// DATA MEMORIES //
	///////////////////
    val data_memories = Seq.tabulate(L1_DataCacheBlockSizeBytes) { w =>
        Module(new ReadWriteSmem(depth=L1_DataCacheSets, width=8))
    }

	// data memory has 3 modes:
	// Evict, Allocate, Replay
	for(i <- 0 until L1_DataCacheBlockSizeBytes){
		data_memories(i).io.addrA 			:= //??? // {way, set}
		data_memories(i).io.writeDataA 	:= current_write_data(i)
		data_memories(i).io.writeEnableA 	:= current_write_enable(i)
	}


	val read_data := data_memories.map(_.readDataA)



	//////////////////
	// TAG MEMORIES //
	//////////////////
    val tag_memories = Seq.tabulate(L1_DataCacheWays) { w =>
        Module(new ReadWriteSmem(depth=L1_DataCacheSets, width=L1_DataCacheTagBits))
    }

	for(i <- 0 until L1_DataCacheWays){
		tag_memories(i).addrA 			:= 
		tag_memories(i).writeDataA 		:= 
		tag_memories(i).writeEnableA	:= 
	}

	tag_match_OH := tag_memories.map(_.readDataA === RegNext(input_tag)).toVec

	////////////////////
	// VALID MEMORIES //
	////////////////////
    val valid_memories = Seq.tabulate(L1_DataCacheWays) { w =>
        Module(new ReadWriteSmem(depth=L1_DataCacheSets, width=1))
    }

	for(i <- 0 until L1_DataCacheWays){
		valid_memories(i).addrA 		:=	
		valid_memories(i).writeDataA 	:=	
		valid_memories(i).writeEnableA	:=	
	}

	val valid := valid_memories.map(_.readDataA)

	///////////////////
	// PLRU MEMORIES //
	///////////////////
    val PLRU_memory = Module(new TrueDualPortMemory(depth=L1_DataCacheSets, width=L1_DataCacheWays))

	for(i <- 0 until L1_DataCacheWays){
		PLRU_memory(i).addrA 		:=	
		PLRU_memory(i).writeDataA 	:=	
		PLRU_memory(i).writeEnableA	:=	
	}

	val PLRU := PLRU_memory.map(_.readDataA)

	/////////////////
	// UPDATE PLRU //
	/////////////////

	when((PLRU || (tag_match_OH && valid)).reduce(_ && _)){
		updated_PLRU := tag_match_OH
	}.otherwise{
		updated_PLRU := PLRU || (tag_match_OH && valid) 
	}

	//////////////
	// HIT/MISS //
	//////////////

	hit  := RegNext(io.backend_memory_request.valid) &&   (tag_match_OH && valid).reduce(_ || _)
	miss := RegNext(io.backend_memory_request.valid) && !((tag_match_OH && valid).reduce(_ || _))

	//////////////
	// TILELINK //
	//////////////



	io.backend_memory_request.ready := DontCare
	io.backend_memory_response 		:= DontCare

	io.data_cache_A := DontCare
	io.data_cache_D := DontCare



}