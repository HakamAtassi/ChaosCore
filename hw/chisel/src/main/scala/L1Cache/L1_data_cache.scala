/* ------------------------------------------------------------------------------------
* Filename: L1_data_cache.scala
* Author: Hakam Atassi
* Date: Mar 12 2024
* Description: A lockup free L1 AXI data cache.
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


object format_dcache_word {
def apply(data_way: UInt, address: UInt, operation: access_width_t.Type): UInt = {
  val word_offset = (address & 31.U) / 4.U  // Word address within the cache line
  val word_shamt = word_offset * 32.U
  val access_word = (data_way >> word_shamt)(31, 0)

  val result = Wire(UInt(32.W))

  result := access_word

  when(operation === access_width_t.W){
    result := access_word
  }.elsewhen(operation === access_width_t.HW){
    val halfword_offset = (address & 2.U) * 8.U  // Aligns to 16 bits within the word
    result := (access_word >> halfword_offset)(15, 0)
  }.elsewhen(operation === access_width_t.B){
    val byte_offset = address & 3.U  // Corrects byte offset within the word
    result := (access_word >> (byte_offset * 8.U))(7, 0)
  }

  result
}

}



object update_PLRU {
	/**
	* @param PLRU: the current read out PLRU state
	* @param hit_way_OH: the OH equality result of the PLRU memories
	* @return: the updated PLRU result
	*/
	def apply(coreParameters:CoreParameters)(PLRU:UInt, tag_hit_OH:UInt):UInt = {
		import coreParameters._
		val updated_PLRU = Wire(UInt(4.W))	// FIXME: Make this a param for L1_data cache ways

		val result = Wire(UInt(4.W))

		updated_PLRU := PLRU | tag_hit_OH.asUInt

		when(updated_PLRU.andR === 1.B){
			result := 0.U
		}.otherwise{
			result := updated_PLRU
		}

		//printf("%x | %x = %x\n",PLRU, tag_hit_OH.asUInt, (PLRU | Cat(tag_hit_OH.reverse)))
		//printf("%x | %x = %x\n",PLRU, tag_hit_OH.asUInt, result)
		result
	}
}


case class data_cache_address_packet(tag:UInt, set:UInt, word_offset:UInt, half_word_offset:UInt, byte_offset:UInt)

object get_decomposed_dcache_address{
  def apply(coreParameters:CoreParameters, address:UInt):data_cache_address_packet={
	import coreParameters._

	val set_bits                    = log2Ceil(L1_DataCacheSets)
	val tag_bits                    = 32 - log2Ceil(L1_DataCacheBlockSizeBytes)-set_bits    // 32 - bits required to index set - bits required to index within line - 2 bits due to 4 byte aligned data

	val masked_addr = address(log2Ceil(L1_DataCacheBlockSizeBytes)-1, 0)


	val decomposed_dcache_address = new data_cache_address_packet(
		tag = address(31, 31-tag_bits+1),
		set = address(31-tag_bits, 31-tag_bits-set_bits+1),
		word_offset = (masked_addr / 4.U),
		half_word_offset = (masked_addr / 2.U),
		byte_offset = (masked_addr / 1.U)
	)

	decomposed_dcache_address
  }
}



object DATA_CACHE_STATES extends ChiselEnum {
	val ACTIVE, STALL, ALLOCATE, REPLAY = Value // FIXME: 
}

class L1_data_cache(val coreParameters:CoreParameters, val nocParameters:NOCParameters) extends Module with AXICacheNode{
	import coreParameters._
	import nocParameters._
	val io = IO(new Bundle{
		// CPU PORT(s)
		val CPU_request		= Flipped(Decoupled(new backend_memory_request(coreParameters)))
		val CPU_response	= Decoupled(new backend_memory_response(coreParameters))

		// FIXME: flush/kill ??

	}); dontTouch(io)

	io.CPU_response.bits.addr := 0.U

	val DATA_CACHE_STATE 			= RegInit(DATA_CACHE_STATES(), DATA_CACHE_STATES.ACTIVE)
	val DATA_CACHE_NEXT_STATE		= Wire(DATA_CACHE_STATES())

	val tag_hit_OH 					= Wire(Vec(L1_DataCacheWays, Bool()))

	// valid hit due to a valid active request (replay or CPU)
	val valid_hit  					= Wire(Bool())
	val valid_miss 					= Wire(Bool())

	val valid_write_hit  			= Wire(Bool())
	val valid_write_miss 			= Wire(Bool())

	val valid_read_hit  			= Wire(Bool())
	val valid_read_miss 			= Wire(Bool())

	val hit_address					= Wire(UInt(32.W))
	val hit_set						= Wire(UInt(log2Ceil(L1_DataCacheSets).W))
	val hit_tag						= Wire(UInt(log2Ceil(L1_DataCacheTagBits).W))
	val hit_way						= Wire(UInt(log2Ceil(L1_DataCacheWays).W))
	val hit_MOB_index				= Wire(UInt(log2Ceil(MOBEntries).W))

	// Meaningful only when valid_miss is high. 
	val miss_address				= Wire(UInt(32.W))
	val miss_set					= Wire(UInt(log2Ceil(L1_DataCacheSets).W))			// The set of the request that missed
	val miss_tag					= Wire(UInt(log2Ceil(L1_DataCacheTagBits).W))		// The tag of the request that missed (based on the input address)
	val miss_way					= Wire(UInt(log2Ceil(L1_DataCacheWays).W))			// The way the missed request will be allocated into upon response, based on PLRU
	val miss_MOB_index				= Wire(UInt(log2Ceil(MOBEntries).W))

	// The data required for performing a writeback when 
	val writeback_data				= Wire(UInt((L1_DataCacheBlockSizeBytes*8).W))
	val writeback_tag				= Wire(UInt(L1_DataCacheTagBits.W))
	val writeback_address			= Wire(UInt(32.W))
	val writeback_dirty				= Wire(Bool())

	// The active request may either be from the CPU directly of from the replay logic
	val active_valid				= Wire(Bool())										// Current request valid?
	val active_cacheable			= Wire(Bool())										// Current request cacheable?
	val active_address				= Wire(UInt(32.W))									// The currently active request address
	val active_set					= Wire(UInt(log2Ceil(L1_DataCacheSets).W))
	val active_tag					= Wire(UInt(L1_DataCacheTagBits.W))
	val active_memory_type			= Wire(memory_type_t())
	val active_access_width			= Wire(access_width_t())
	val active_MOB_index			= Wire(UInt(log2Ceil(MOBEntries).W))
	val active_data					= Wire(UInt(32.W))									// The currently active request address

	val active_non_cacheable		= Wire(Bool())
	val active_non_cacheable_read	= Wire(Bool())
	val active_non_cacheable_write	= Wire(Bool())
	val active_cacheable_write_read	= Wire(Bool())

	val backend_request_valid		= Wire(Bool())										// Current request valid?
	val backend_address				= Wire(UInt(32.W))									// The currently active request address
	val backend_set					= Wire(UInt(log2Ceil(L1_DataCacheSets).W))
	val backend_tag					= Wire(UInt(log2Ceil(L1_DataCacheTagBits).W))
	val backend_memory_type			= Wire(memory_type_t())
	val backend_access_width		= Wire(access_width_t())
	val backend_MOB_index			= Wire(UInt(log2Ceil(MOBEntries).W))

	val replay_request_valid		= Wire(Bool())										// Current request valid?
	val replay_address				= Wire(UInt(32.W))									// The currently active request address
	val replay_set					= Wire(UInt(log2Ceil(L1_DataCacheSets).W))
	val replay_tag					= Wire(UInt(log2Ceil(L1_DataCacheTagBits).W))
	val replay_memory_type			= Wire(memory_type_t())
	val replay_access_width			= Wire(access_width_t())
	val replay_data					= Wire(UInt(32.W))
	val replay_MOB_index			= Wire(UInt(log2Ceil(MOBEntries).W))

	val allocate_address			= Wire(UInt(32.W))
	val allocate_set				= Wire(UInt(log2Ceil(L1_DataCacheSets).W))
	val allocate_tag				= Wire(UInt(log2Ceil(L1_DataCacheTagBits).W))
	val allocate_way				= Wire(UInt(log2Ceil(L1_DataCacheWays).W))

	val allocate_cache_line			= Wire(UInt((L1_DataCacheBlockSizeBytes*8).W))

	val MSHR_replay_done			= Wire(Bool())

	val output_valid				= Wire(Bool())
	val output_data					= Wire(UInt(32.W))
	val output_address				= Wire(UInt(32.W))
	val output_operation			= Wire(access_width_t())
	val output_MOB_index			= Wire(UInt(log2Ceil(MOBEntries).W))

	val data_way 					= Wire(UInt((L1_DataCacheBlockSizeBytes*8).W))

	val evict_way 					= Wire(UInt(log2Ceil(L1_DataCacheWays).W))

	val valid_vec					= Wire(Vec(L1_DataCacheWays, Bool()))

	val valid_MSHR_hit  			= Wire(Bool())
	val valid_MSHR_miss 			= Wire(Bool())
	var hit_MSHR 					= new MSHR_entry(coreParameters)
	var hit_MSHR_index 				= Wire(UInt(log2Ceil(L1_MSHREntries).W))

	val cacheable_AXI_response_valid	=	 Wire(Bool())

	//////////////////////////////
	// Helper signal assignment //
	//////////////////////////////

	active_valid				:=	DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY || (io.CPU_request.fire)
	active_address				:=	Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY, replay_address,		backend_address)
	active_cacheable			:=	((active_address & "h80000000".U) === 0.U) && active_valid
	active_set					:=	Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY, replay_set, 			backend_set)
	active_tag					:=	Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY, replay_tag, 			backend_tag)
	active_memory_type			:=	Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY, replay_memory_type, 	backend_memory_type)
	active_access_width			:=	Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY, replay_access_width, backend_access_width)
	active_MOB_index			:=	Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY, replay_MOB_index, 	backend_MOB_index)


	valid_hit			:= tag_hit_OH.reduce(_ || _)	&& (RegNext(io.CPU_request.fire) || RegNext(DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY)) && RegNext(active_cacheable)
	valid_miss			:= !tag_hit_OH.reduce(_ || _)	&& (RegNext(io.CPU_request.fire) || RegNext(DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY)) && RegNext(active_cacheable)

	valid_write_hit		:=	valid_hit && RegNext(active_memory_type === memory_type_t.STORE)
	valid_write_miss	:=	valid_miss && RegNext(active_memory_type=== memory_type_t.STORE)

	valid_read_hit 		:=	valid_hit && RegNext(active_memory_type=== memory_type_t.LOAD)
	valid_read_miss		:=	valid_miss && RegNext(active_memory_type=== memory_type_t.LOAD)

	hit_address			:=	RegNext(active_address)
	hit_set				:=	RegNext(active_set)
	hit_tag				:=	RegNext(active_tag)
	hit_MOB_index		:=	RegNext(active_MOB_index)
	hit_way				:= 	PriorityEncoder(tag_hit_OH.asUInt)	// FIXME: OH or non OH for priority encoder

	dontTouch(hit_way)
	dontTouch(allocate_way)

	miss_address		:= RegNext(active_address)
	miss_set			:= RegNext(active_set)
	miss_tag			:= RegNext(active_tag)
	miss_MOB_index		:= RegNext(active_MOB_index)
	miss_way			:= PriorityEncoderOH(~(tag_hit_OH.asUInt))	// miss way == allocate way == the rightmost/leftmost way with a 0 PLRU bit


	backend_request_valid 	:= 	io.CPU_request.valid
	backend_address 		:=	io.CPU_request.bits.addr
	backend_set				:=	get_decomposed_dcache_address(coreParameters, io.CPU_request.bits.addr).set
	backend_tag				:=  get_decomposed_dcache_address(coreParameters, io.CPU_request.bits.addr).tag
	backend_memory_type		:=  io.CPU_request.bits.memory_type
	backend_access_width	:=  io.CPU_request.bits.access_width
	backend_MOB_index		:=  io.CPU_request.bits.MOB_index


	// FIXME: todo
	output_data					:= 0.U
	output_address				:= 0.U
	output_operation			:= access_width_t.NONE
	output_MOB_index			:= 0.U

	///////////////////
	// REQUEST QUEUE //
	///////////////////

    val blockSizeBytes = L1_instructionCacheBlockSizeBytes
    val byteOffsetBits = log2Ceil(blockSizeBytes)                                          // Bits needed to each byte in a cache line
    val dram_addr_mask = ((1.U << 32.U) - (1.U << byteOffsetBits))

	val non_cacheable_request_bytes 	= Wire(UInt(2.W))


	// Requests are non cacheable if MSB is set
	active_non_cacheable				:= ((io.CPU_request.bits.addr & "h80000000".U) =/= 0.U)	&& active_valid
	active_non_cacheable_read			:= active_memory_type === memory_type_t.LOAD  && active_non_cacheable
	active_non_cacheable_write			:= (active_memory_type === memory_type_t.STORE) && active_non_cacheable
	active_cacheable_write_read			:= ((io.CPU_request.bits.addr & "h80000000".U) === 0.U) && active_valid

	////////////
	// QUEUES //
	////////////
	// Outgoing request queues //
	val cacheable_request_Q			= 	Module(new Queue(new AXI_request_Q_entry, 8, flow=false, hasFlush=false, useSyncReadMem=true))						// FIXME: needs flush/kill
	val non_cacheable_request_Q		=	Module(new Queue(new AXI_request_Q_entry, 8, flow=false, hasFlush=false, useSyncReadMem=true))						// FIXME: needs flush/kill
	val AXI_request_Q				= 	Module(new Queue(new AXI_request_Q_entry, 2, flow=false, hasFlush=false, useSyncReadMem=true))						// FIXME: needs flush/kill

	// Incoming response queues	//
	val cacheable_response_Q		=	Module(new Queue(new backend_memory_response(coreParameters), 8, flow=false, hasFlush=false, useSyncReadMem=true))	//FIXME: needs flush/kill
	val non_cacheable_response_Q	=	Module(new Queue(new backend_memory_response(coreParameters), 8, flow=false, hasFlush=false, useSyncReadMem=true))	//FIXME: needs flush/kill

	// Output skid buffer //
	val CPU_response_skid_buffer	=	Module(new Queue(new backend_memory_response(coreParameters), 3, flow=true, hasFlush=false, useSyncReadMem=true))	// FIXME: needs flush/kill

	///////////////////
	// DATA MEMORIES //
	///////////////////
	// Array of N memories, each 1 byte wide and sets*ways long (Bmem).

	val data_memories 				= Seq.fill(L1_DataCacheBlockSizeBytes)(Module(new ReadWriteSmem(depth=L1_DataCacheSets*L1_DataCacheWays, width=8)))
	val data_memories_wr_en 		= Wire(Vec(L1_DataCacheBlockSizeBytes, Bool()))
	val data_memories_data_in 		= Wire(Vec(L1_DataCacheBlockSizeBytes, UInt(8.W)))


	//val word_offset_match 		= Wire(Bool())
	//val half_word_offset_match 	= Wire(Bool())
	//val byte_offset_match 		= Wire(Bool())


	val word_offset 			= get_decomposed_dcache_address(coreParameters, active_address).word_offset
	val half_word_offset 		= get_decomposed_dcache_address(coreParameters, active_address).half_word_offset
	val byte_offset 			= get_decomposed_dcache_address(coreParameters, active_address).byte_offset


	// Assign data_memory_wr_en
	for(i <- 0 until L1_DataCacheBlockSizeBytes){

		data_memories_wr_en(i) 		:= (DATA_CACHE_STATE === DATA_CACHE_STATES.ALLOCATE) || (RegNext(
			(word_offset 		=== (i / 4).U) && (active_memory_type === memory_type_t.STORE) && (active_access_width === access_width_t.W)	||
			(half_word_offset 	=== (i / 2).U) && (active_memory_type === memory_type_t.STORE) && (active_access_width === access_width_t.HW)	||
			(byte_offset 		=== (i / 1).U) && (active_memory_type === memory_type_t.STORE) && (active_access_width === access_width_t.B)	) && valid_hit)
	}



	active_data := Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY, replay_data, io.CPU_request.bits.data)


	dontTouch(word_offset)
	dontTouch(half_word_offset)
	dontTouch(byte_offset)
	dontTouch(data_memories_wr_en)
	dontTouch(allocate_cache_line)

	when(RegNext(active_access_width === access_width_t.W)){
		for(i <- 0 until L1_DataCacheBlockSizeBytes){
			data_memories_data_in(i) 	:= Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.ALLOCATE, (allocate_cache_line>>(i*8))(7,0), RegNext(((active_data)>>(i%4)*8)(7,0))) 
		}
	}.elsewhen(RegNext(active_access_width === access_width_t.HW)){
		for(i <- 0 until L1_DataCacheBlockSizeBytes){
			data_memories_data_in(i) 	:= Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.ALLOCATE, (allocate_cache_line>>(i*8))(7,0), RegNext(((active_data)>>(i%2)*8)(7,0))) 
		}
	}.elsewhen(RegNext(active_access_width === access_width_t.B)){
		for(i <- 0 until L1_DataCacheBlockSizeBytes){
			data_memories_data_in(i) 	:= Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.ALLOCATE, (allocate_cache_line>>(i*8))(7,0), RegNext(((active_data)>>(i%1)*8)(7,0))) 
		}
	}.otherwise{
		for(i <- 0 until L1_DataCacheBlockSizeBytes){
			data_memories_data_in(i) 	:= 0.U
		}
	}

	val data_memory_allocate_address 	= Cat(allocate_way, allocate_set)
	val data_memory_active_address 		= Cat(hit_way, RegNext(active_set))
	val data_memory_evict_address		= Cat(evict_way, RegNext(active_set))

	dontTouch(data_memory_allocate_address)
	dontTouch(data_memory_active_address)
	dontTouch(data_memory_evict_address)


	for((data_memory, i) <- data_memories.zipWithIndex){
		data_memory.io.enable		:= 1.B

		// Data memories have 3 possible address inputs:
		// 1: On a hit, the address input is the set/way stuff based on the input from the CPU
		// 2: On a miss, the address input is the set/way based on the data that is to be evicted
		// 3: On response, the address input is based on the MSHR entry
		when(valid_miss){
			data_memory.io.addr			:= data_memory_evict_address
		}.elsewhen(DATA_CACHE_STATE === DATA_CACHE_STATES.ALLOCATE){ // Allocate taking place
			data_memory.io.addr			:= data_memory_allocate_address 
		}.otherwise{	// normal access
			data_memory.io.addr			:= data_memory_active_address
		}
		data_memory.io.wr_en		:= data_memories_wr_en(i)
		data_memory.io.data_in		:= data_memories_data_in(i)
	}

	data_way		:=	Cat(data_memories.map(_.io.data_out).reverse)
	writeback_data 	:=	data_way


	//////////////////
	// TAG MEMORIES //
	//////////////////
	// Array of Way memories, each tag size bits wide (Bmem).

	dontTouch(allocate_address)

	val tag_memories = Seq.fill(L1_DataCacheWays)(Module(new ReadWriteSmem(depth=L1_DataCacheSets, width=L1_DataCacheTagBits)))


	for(i <- 0 until L1_DataCacheWays){
		tag_hit_OH(i) := (tag_memories(i).io.data_out === RegNext(active_tag)) && valid_vec(i)
	}

	dontTouch(active_tag)
	dontTouch(data_memory_active_address)
	dontTouch(active_non_cacheable)

	for(i <- 0 until L1_DataCacheWays){
		// Write new tag on DRAM response
		tag_memories(i).io.enable	:= 1.B
	}

	
	for(i <- 0 until L1_DataCacheWays){
		// on allocate, update TAG
		tag_memories(i).io.wr_en 	:= 0.U
		tag_memories(i).io.data_in	:= 0.U
		tag_memories(i).io.addr 	:= Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.ALLOCATE, allocate_set, active_set)
		when(allocate_way === i.U){
			tag_memories(i).io.wr_en 	:= (DATA_CACHE_STATE === DATA_CACHE_STATES.ALLOCATE) 
			tag_memories(i).io.data_in	:= allocate_tag
		}
	}

	// writeback tag is the tag at the way that will be allocated to on DRAM response


	//////////////////
	// VALID MEMORY //
	//////////////////
	// Memory of "way" width, sets length (Regs).

  	val valid_memory = RegInit(VecInit.tabulate(L1_DataCacheSets, L1_DataCacheWays){ (x, y) => 0.B })


	when(valid_miss){
		// Invalidate the cache line as it is now scheduled for write back and is considered in-flight. Writes to this line, for instance, will be discarded
		valid_memory(RegNext(active_set))(evict_way)	:= 0.B
	}

	// update on allocate
	when(DATA_CACHE_STATE === DATA_CACHE_STATES.ALLOCATE){
		// Data is valid after being allocated
		valid_memory(allocate_set)(allocate_way) := 1.B
	}

	for(i <- 0 until L1_DataCacheWays){
		valid_vec(i) := RegNext(valid_memory(active_set)(i))
	}



	///////////////////
	// PLRU MEMORIES //
	///////////////////
	// Memory of "way" width, sets length (Regs).

	val PLRU_memory = RegInit(VecInit(Seq.fill(L1_DataCacheSets)(0.U(L1_DataCacheWays.W))))

	dontTouch(hit_set)

	// update on hit (read or write)
	when(valid_hit){
		PLRU_memory(hit_set) := update_PLRU(coreParameters)(PLRU = PLRU_memory(hit_set), tag_hit_OH = tag_hit_OH.asUInt)
	}

	//when(RegNext(io.CPU_request.fire)){
		//PLRU_memory(RegNext(active_set)) := update_PLRU(coreParameters)(PLRU = PLRU_memory(RegNext(active_set)), tag_hit_OH = Mux(valid_hit, tag_hit_OH.asUInt, (1.U<<(evict_way))))
	//}
	// clearing PLRU on allocate is not needed (you allocate to the 0 PLRU bit, ie, no change)


	val PLRU 	= Wire(UInt(L1_DataCacheWays.W))
	PLRU 		:= (PLRU_memory(RegNext(active_set)))
	evict_way 	:= PriorityEncoder(~PLRU)

	dontTouch(evict_way)
	dontTouch(PLRU)

	//////////////////
	// DIRTY MEMORY //
	//////////////////
	// Memory of "way" width, sets length (Regs)

  	val dirty_memory = RegInit(VecInit.tabulate(L1_DataCacheSets, L1_DataCacheWays){ (x, y) => 0.B })

	dontTouch(dirty_memory)
	dontTouch(valid_write_hit)

	// update on hit (writes only)
	when(valid_write_hit){
		dirty_memory(RegNext(active_set))(PriorityEncoder(tag_hit_OH)) := 1.B
	}

	// clear on allocate
	when(DATA_CACHE_STATE === DATA_CACHE_STATES.ALLOCATE){
		dirty_memory(allocate_set)(allocate_way) := 0.B
	}

	//////////////////////////
	// IN FLIGHT WRITE MISS //
	//////////////////////////
	// Memory of "way" width, sets length (Regs)

  	val inflight_write_miss = RegInit(VecInit.tabulate(L1_DataCacheSets, L1_DataCacheWays){ (x, y) => 0.B })
  	val inflight_write_miss_next = VecInit.tabulate(L1_DataCacheSets, L1_DataCacheWays){ (x, y) => 0.B }

	for(i <- 0 until L1_DataCacheSets){
		for(j <- 0 until L1_DataCacheWays){
			inflight_write_miss_next(i)(j) := inflight_write_miss(i)(j)
		}
	}


	// update on write_miss
	when(RegNext(io.CPU_request.bits.memory_type === memory_type_t.STORE) && valid_miss){
		inflight_write_miss_next(RegNext(active_set))(evict_way) := 1.B
	}

	// reset on response
	when(valid_hit){
		inflight_write_miss_next(RegNext(active_set))(hit_way) := 0.B
	}
	
	// update regs
	for(i <- 0 until L1_DataCacheSets){
		for(j <- 0 until L1_DataCacheWays){
			inflight_write_miss(i)(j) := inflight_write_miss_next(i)(j)
		}
	}




	val writeback_set = Wire(UInt(log2Ceil(L1_DataCacheSets).W)) //RegNext(active_set)

	writeback_set := RegNext(active_set)

	writeback_dirty 	:= dirty_memory(RegNext(active_set))(evict_way) && valid_miss
	writeback_tag 		:= VecInit(tag_memories.map(_.io.data_out))(evict_way)
	writeback_address 	:= Cat(writeback_tag, writeback_set, 0.U((log2Ceil(L1_DataCacheBlockSizeBytes)).W))

	dontTouch(writeback_tag)
	dontTouch(writeback_data)
	dontTouch(writeback_dirty)


	/////////////////////////////////
	// MSHRs & Non-Cacheable Buffer//
	/////////////////////////////////


	val MSHRs 				= Reg(Vec(L1_MSHREntries, new MSHR_entry(coreParameters)))
	val MSHR_ptr_width		= (log2Ceil(L1_MSHREntries)+1)
	val MSHR_front_pointer 	= RegInit(UInt(MSHR_ptr_width.W), 0.U)
	val MSHR_back_pointer	= RegInit(UInt(MSHR_ptr_width.W), 0.U)

	val MSHR_front_index 	= MSHR_front_pointer(MSHR_ptr_width-2, 0)
	val MSHR_back_index 	= MSHR_back_pointer(MSHR_ptr_width-2, 0)

	val MSHR_front_pointer_next = Wire(UInt(MSHR_ptr_width.W))
	val MSHR_back_pointer_next	= Wire(UInt(MSHR_ptr_width.W))

	val MSHR_front_index_next 	= MSHR_front_pointer_next(MSHR_ptr_width-2, 0)
	val MSHR_back_index_next 	= MSHR_back_pointer_next(MSHR_ptr_width-2, 0)

	// update non-cacheable buffer on non-cacheable request
	val non_cacheable_buffer 				= Reg(Vec(L1_NonCacheableBufferEntries, new backend_memory_request(coreParameters)))
	val non_cacheable_buffer_pointer_width	= log2Ceil(L1_NonCacheableBufferEntries) + 1
	val non_cacheable_buffer_front_pointer 	= RegInit(UInt(non_cacheable_buffer_pointer_width.W), 0.U)
	val non_cacheable_buffer_back_pointer 	= RegInit(UInt(non_cacheable_buffer_pointer_width.W), 0.U)

	val non_cacheable_buffer_front_index 	= non_cacheable_buffer_front_pointer(non_cacheable_buffer_pointer_width - 2, 0)
	val non_cacheable_buffer_back_index 	= non_cacheable_buffer_front_pointer(non_cacheable_buffer_pointer_width - 2, 0)

	val non_cacheable_buffer_front 			= non_cacheable_buffer(non_cacheable_buffer_front_index)

	dontTouch(non_cacheable_buffer)

	// Queue non_cacheable buffer on non-cacheable request

	// On miss, check MSHR for pre-existing entry

	hit_MSHR_index := 0.U

	valid_MSHR_hit := 0.B
	valid_MSHR_miss := 0.B
	when(valid_miss){
		valid_MSHR_miss := 1.B
		for((mshr, i) <- MSHRs.zipWithIndex){
			when((mshr.address === (miss_address & dram_addr_mask)) && mshr.valid){
				hit_MSHR_index	:= i.U
				valid_MSHR_hit := 1.B
				valid_MSHR_miss := 0.B
				hit_MSHR = mshr
			}
		}
	}

	// If found, append 
	// If not found, allocate new entry

	val miss_backend_memory_request = Wire(new backend_memory_request(coreParameters))
	miss_backend_memory_request := RegNext(io.CPU_request.bits) //0.U.asTypeOf(new backend_memory_request(coreParameters))
	
	///////////////////////////
	// AXI RESPONSE HANDLING //
	///////////////////////////

	MSHR_front_pointer_next := MSHR_front_pointer 
	MSHR_back_pointer_next	:= MSHR_back_pointer

	// Response is cacheable
	when(valid_miss && valid_MSHR_hit){
		// append MSHR entry
		MSHRs(hit_MSHR_index).miss_requests(MSHRs(hit_MSHR_index).back_pointer) := miss_backend_memory_request
		MSHRs(hit_MSHR_index).back_pointer := MSHRs(hit_MSHR_index).back_pointer + 1.U
	}.elsewhen(valid_miss && valid_MSHR_miss){
		// allocate new MSHR entry
		MSHRs(MSHR_back_index).allocate_way := evict_way
		MSHRs(MSHR_back_index).valid	:= 1.B
		MSHRs(MSHR_back_index).address := miss_backend_memory_request.addr & dram_addr_mask
        MSHRs(MSHR_back_index).miss_requests(MSHRs(MSHR_back_index).back_pointer) := miss_backend_memory_request
		MSHRs(MSHR_back_index).back_pointer := MSHRs(MSHR_back_index).back_pointer + 1.U
		MSHR_back_pointer_next := MSHR_back_pointer + 1.U
	}
	MSHR_back_pointer := MSHR_back_pointer_next

	// Response is non-cacheable
	// TODO: construct input from buffer
	// updated buffer

	when(active_non_cacheable_read){
		non_cacheable_buffer(non_cacheable_buffer_front_index) := io.CPU_request.bits
		non_cacheable_buffer_back_pointer := non_cacheable_buffer_front_pointer + 1.U
		//FIXME: non_cacheable_buffer never dequeues...
	}




	MSHR_replay_done := 0.B
	when(DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY){
		// On replay, send requests one after the other in a burst fashion. 
		MSHRs(MSHR_front_index).dequeue
		when(MSHRs(MSHR_front_index).last){
			MSHR_replay_done := 1.B
			MSHR_front_pointer_next := MSHR_front_pointer + 1.U

			// clear the MSHR entry
			MSHRs(MSHR_front_index).clear
		}
	}

	MSHR_front_pointer := MSHR_front_pointer_next

	//FIXME: Allocate way and miss way are inconsistent
	allocate_way				:= MSHRs(MSHR_front_index).allocate_way
	allocate_address			:= MSHRs(MSHR_front_index).address
	allocate_set				:= get_decomposed_dcache_address(coreParameters, MSHRs(MSHR_front_index).address).set
	allocate_tag				:= get_decomposed_dcache_address(coreParameters, MSHRs(MSHR_front_index).address).tag

	//////////////////////////
	// NON CACHEABLE BUFFER //
	//////////////////////////

	// non-cacheable requests take priority over cacheable requests
	// On request, if cacheable, check if hit/miss. check MSHRs as needed, etc...
	// If MSHR hit, update MSHR. Move on. 
	// If MSHR miss, write to MSHR, cacheable request Q. 
	// == non-cacheable == //
	// If input is non-cacheable, write to non-cacheable request queue immediately. 
	// == output scheduling == //
	// Schedule cacheable/non-cacheable requests in round-robin fashion.
	// Cacheable request ID == 0, non-cacheable ID == 1
	// == Response handling == //
	// Response ID == 0? Go into allocate, then replay outstanding misses. 
		// Write responses to cacheable response Q.
	// Response ID == 1? Simply forward response as is. 
		// Write responses to non-cacheable response Q.
	// Schedule output as round-robin between the two Queues.




	// free and output from non-cacheable buffer on non-cacheable response
	
	
	// FIXME: for easy area savings, change this so that the non-cachable request queu only has 32 bits of write data
	class AXI_request_Q_entry extends Bundle{
		val write_valid		=	Bool()
		val write_address	=	UInt(32.W)
		val write_data		=	UInt((L1_DataCacheBlockSizeBytes*8).W)
		val write_ID		=	UInt(ID_WIDTH.W)
		val write_bytes		=	UInt(log2Ceil(128).W)	// Max number of bytes per transfer is 128

		val read_valid		=	Bool()
		val read_address	=	UInt(32.W)
		val read_ID			=	UInt(ID_WIDTH.W)
		val read_bytes		= 	UInt(log2Ceil(128).W)
	}


	// Outgoing request queues
	// FIXME: change these to shift regs
	// These are shifted by 2 after a miss because you need 1 cycle to get the miss data (tag lookup)
	// And another to read out potential eviction data

	// Buffer cacheable requests //
	// format request //
	dontTouch(active_cacheable_write_read)
	// Memory requests occur when a cache miss takes place or when there is a non-cacheable request
	cacheable_request_Q.io.enq.valid 	 			:=  RegNext(RegNext(active_cacheable_write_read) && valid_miss && valid_MSHR_miss)
	cacheable_request_Q.io.enq.bits.write_valid		:=	RegNext(RegNext(active_cacheable_write_read) && writeback_dirty)
	cacheable_request_Q.io.enq.bits.write_address	:=	RegNext(writeback_address)
	cacheable_request_Q.io.enq.bits.write_data		:=	writeback_data
	cacheable_request_Q.io.enq.bits.write_ID		:=	RegNext(0.U)
	cacheable_request_Q.io.enq.bits.write_bytes		:=	RegNext(L1_DataCacheBlockSizeBytes.U)

	// Read missing line
	cacheable_request_Q.io.enq.bits.read_valid		:=	RegNext(RegNext(active_cacheable_write_read))
	cacheable_request_Q.io.enq.bits.read_address	:=	RegNext(RegNext(active_address) & dram_addr_mask)
	cacheable_request_Q.io.enq.bits.read_ID			:=	RegNext(0.U)
	cacheable_request_Q.io.enq.bits.read_bytes		:=	RegNext(L1_DataCacheBlockSizeBytes.U)


	// Buffer non-cacheable requests //
	// format request //
	when(io.CPU_request.bits.access_width === access_width_t.W)				{non_cacheable_request_bytes := 4.U}
	.elsewhen(io.CPU_request.bits.access_width === access_width_t.HW)		{non_cacheable_request_bytes := 2.U}
	.otherwise																{non_cacheable_request_bytes := 1.U}

	dontTouch(writeback_address)
	// Memory requests occur when a cache miss takes place or when there is a non-cacheable request
	non_cacheable_request_Q.io.enq.valid 				:=	(active_non_cacheable_read  || active_non_cacheable_write) && active_valid
	non_cacheable_request_Q.io.enq.bits.write_valid		:=	active_non_cacheable_write
	non_cacheable_request_Q.io.enq.bits.write_address	:=	(active_address)
	non_cacheable_request_Q.io.enq.bits.write_data		:=	(active_data)
	non_cacheable_request_Q.io.enq.bits.write_ID		:=	1.U
	non_cacheable_request_Q.io.enq.bits.write_bytes		:=	non_cacheable_request_bytes

	// Read missing line
	non_cacheable_request_Q.io.enq.bits.read_valid		:=	active_non_cacheable_read
	non_cacheable_request_Q.io.enq.bits.read_address	:=	active_address
	non_cacheable_request_Q.io.enq.bits.read_ID			:=	1.U
	non_cacheable_request_Q.io.enq.bits.read_bytes		:=	non_cacheable_request_bytes


	// Arbitrate and format AXI request // 
  	val AXI_request_arb = Module(new Arbiter(new AXI_request_Q_entry, 2))

  	AXI_request_arb.io.in(0) <> non_cacheable_request_Q.io.deq
  	AXI_request_arb.io.in(1) <> cacheable_request_Q.io.deq

	val write_request_valid			=	AXI_request_Q.io.deq.valid	&&	AXI_request_Q.io.deq.bits.write_valid
	val write_request_address		=	AXI_request_Q.io.deq.bits.write_address
	val write_request_data			=	AXI_request_Q.io.deq.bits.write_data
	val write_request_ID			=	AXI_request_Q.io.deq.bits.write_ID
	val write_request_bytes			=	AXI_request_Q.io.deq.bits.read_bytes

	val read_request_valid 			=	AXI_request_Q.io.deq.valid	&&	AXI_request_Q.io.deq.bits.read_valid
	val read_request_address		=	AXI_request_Q.io.deq.bits.read_address
	val read_request_ID				=	AXI_request_Q.io.deq.bits.read_ID
	val read_request_bytes			=	AXI_request_Q.io.deq.bits.read_bytes

	AXI_request_Q.io.enq <> AXI_request_arb.io.out

	// Perform AXI request
	when(write_request_valid && read_request_valid){
		// when performing read/write pair, both channels must be ready
		AXI_request_Q.io.deq.ready := 	AXI_write_request(write_request_address, write_request_ID, write_request_data, write_request_bytes) && 
										AXI_read_request(read_request_address, read_request_ID, read_request_bytes)
	}.elsewhen(read_request_valid){
		// When performing single read, read channel must be ready
		AXI_request_Q.io.deq.ready := AXI_read_request(read_request_address, read_request_ID, read_request_bytes)
	}.elsewhen(write_request_valid){
		// When performing single write, write channel must be ready
		AXI_request_Q.io.deq.ready := AXI_write_request(write_request_address, write_request_ID, write_request_data, write_request_bytes)
	}.otherwise{
		AXI_request_Q.io.deq.ready 				:=	0.B 
	}




	/////////
	// FSM //
	/////////

	DATA_CACHE_NEXT_STATE := DATA_CACHE_STATE

	switch(DATA_CACHE_STATE){
		is(DATA_CACHE_STATES.ACTIVE){
			when(non_cacheable_response_Q.io.deq.valid){
				// output non cacheable response
			}.elsewhen(cacheable_AXI_response_valid){ // FIXME: shouldnt this just be the output of the response arb?
				DATA_CACHE_NEXT_STATE := DATA_CACHE_STATES.ALLOCATE
			}
		}

		is(DATA_CACHE_STATES.STALL){
			//when(/*resources available*/){
			//}
		}

		is(DATA_CACHE_STATES.ALLOCATE){
			DATA_CACHE_NEXT_STATE := DATA_CACHE_STATES.REPLAY
		}

		is(DATA_CACHE_STATES.REPLAY){
			when(MSHR_replay_done){
				DATA_CACHE_NEXT_STATE := DATA_CACHE_STATES.ACTIVE
			}
		}
	}



	DATA_CACHE_STATE := DATA_CACHE_NEXT_STATE

	replay_request_valid	:=	0.B //FIXME: 
	replay_address			:=	MSHRs(MSHR_front_index).front.addr
	replay_set				:=	get_decomposed_dcache_address(coreParameters, MSHRs(MSHR_front_index).front.addr).set
	replay_tag				:=	get_decomposed_dcache_address(coreParameters, MSHRs(MSHR_front_index).front.addr).tag
	replay_memory_type		:=	MSHRs(MSHR_front_index).front.memory_type
	replay_access_width		:=	MSHRs(MSHR_front_index).front.access_width
    replay_data				:=	MSHRs(MSHR_front_index).front.data
	replay_MOB_index		:=	MSHRs(MSHR_front_index).front.MOB_index


	////////////
	// OUTPUT //
	////////////
	// Reads always output the data and the MOB index
	// When in ACTIVE, non-cacheable reads have complete priority over normal DRAM reads
	// In either case, the output valid occurs 2 cycles after a hit is detected



	non_cacheable_response_Q.io.deq.ready := 0.B

	val output_cacheable  = ShiftRegister(active_cacheable, 2)
	output_address		 := ShiftRegister(active_address, 2)
	output_operation	 := ShiftRegister(active_access_width, 2)


	dontTouch(output_address)
	output_data := format_dcache_word(data_way, output_address, output_operation)

	dontTouch(data_way)
	

	dontTouch(output_data)
	dontTouch(output_operation)
	dontTouch(output_cacheable)

	// Output valid is not needed on writes
	output_valid		:=	ShiftRegister(valid_read_hit, 1)
	output_MOB_index	:=	ShiftRegister(active_MOB_index, 2) //hit_MOB_index

	////////////////////////////////////////////////////
	// AXI RESPONSE BUFFERS (CACHEABLE/NON-CACHEABLE) //
	////////////////////////////////////////////////////
	val (axi_response, axi_response_valid) = AXI_read
	val axi_response_ID = axi_response.ID

	allocate_cache_line		:=	RegNext(axi_response.data)

	cacheable_AXI_response_valid := axi_response_valid && (axi_response_ID === 0.U)

	// CACHEABLE
	// On AXI response, queue entries into line fill buffer

	cacheable_response_Q.io.enq.valid 			:= output_valid
	cacheable_response_Q.io.enq.bits.addr  		:= output_address
	cacheable_response_Q.io.enq.bits.data  		:= output_data
	cacheable_response_Q.io.enq.bits.MOB_index  := output_MOB_index
	cacheable_response_Q.io.deq.ready 			:= 1.B		// FIXME: not always ready

	// NON-CACHEABLE
	// On AXI response, queue entries into non cacheable response
	dontTouch(io)
	dontTouch(axi_response_valid)
	dontTouch(axi_response.data)
	dontTouch(output_valid)

	non_cacheable_response_Q.io.enq.valid 			:= axi_response_valid && (axi_response_ID === AXI_NON_CACHEABLE_RESPONSE_ID.U).asBool
	// FIXME: why top 32 bits??
	non_cacheable_response_Q.io.enq.bits.addr  		:= non_cacheable_buffer_front.addr
	non_cacheable_response_Q.io.enq.bits.data  		:= axi_response.data(255,256-32)	// non cacheable responses are always 32 bits 
	non_cacheable_response_Q.io.enq.bits.MOB_index  := non_cacheable_buffer_front.MOB_index
	non_cacheable_response_Q.io.deq.ready 			:= 1.B	// FIXME: not always ready

	// arbitrate port outputs
	// Round Robin between cacheable and non-cacheable

  	val backend_response_arb = Module(new Arbiter(new backend_memory_response(coreParameters), 2))
  	backend_response_arb.io.in(0) <> non_cacheable_response_Q.io.deq
  	backend_response_arb.io.in(1) <> cacheable_response_Q.io.deq

	backend_response_arb.io.out <> CPU_response_skid_buffer.io.enq

	////////
	// IO //
	////////
	CPU_response_skid_buffer.io.deq <> io.CPU_response


	// cache is ready when:
	// Cache is active and...
	// MSHR conds:
	// MSHR has entry available
	// MSHR has no entry available but input address matches an adderess in the MSHR
	// Queues:
	// input is non-cacheable and non-cacheable request queue has an entry available
	// input is cacheable and cacheable request queue has an entry available

	val input_cacheable = ((io.CPU_request.bits.addr & "h80000000".U) === 0.U)
	val input_non_cacheable = ((io.CPU_request.bits.addr & "h80000000".U) =/= 0.U)


	// MSHR resource conds
	val MSHR_full_next = Wire(Bool())	// The cache only cares about if the MSHR will be full next cycle
	val MSHR_full_and_input_match = Wire(Bool())

	// input queue checks
	val input_cacheable_and_Q_available = Wire(Bool())
	val input_non_cacheable_and_Q_available = Wire(Bool())

	dontTouch(MSHR_front_index)
	dontTouch(MSHR_back_index)

	MSHR_full_next := (MSHR_front_pointer_next =/= MSHR_back_pointer_next) && (MSHR_front_index_next === MSHR_back_index_next)

	dontTouch(MSHR_front_index_next)
	dontTouch(MSHR_back_index_next)

	MSHR_full_and_input_match := MSHR_full_next && (MSHRs.map(MSHR_entry => (MSHR_entry.address === io.CPU_request.bits.addr) && !MSHR_entry.full).reduce(_ || _))

	input_cacheable_and_Q_available := input_cacheable && cacheable_request_Q.io.enq.ready
	input_non_cacheable_and_Q_available := input_non_cacheable && non_cacheable_request_Q.io.enq.ready

	dontTouch(input_cacheable)
	dontTouch(input_cacheable_and_Q_available)
	dontTouch(input_non_cacheable_and_Q_available)

	io.CPU_request.ready		:= (!MSHR_full_next || MSHR_full_and_input_match) && 
									(input_cacheable_and_Q_available || input_non_cacheable_and_Q_available) && 
									(DATA_CACHE_STATE === DATA_CACHE_STATES.ACTIVE) &&
									!(DATA_CACHE_NEXT_STATE === DATA_CACHE_STATES.ALLOCATE) && // you dont want to accept a new input (that may miss) when you have a response from the DRAM
									!(inflight_write_miss_next(active_set).reduce(_ || _))
}

// MAJOR ISSUE:
// If you have a write miss and a read miss back to back, the write miss will request to read data,
// and will not update its PLRU/dirty, etc untill the dram responds with the data. 
// Meanwhile, the read data will request 

// Problem 1: PLRU is updated too late. this makes write miss read miss conflicts pretty likely (since they will alias to the same set & way)
// Fix 1: make the PLRU update on cache access and not on hit. 

// Problem 2: write miss => read/write miss to the same set back to back causes the write data to be discarded/dropped

// On miss write => look up cache for where to place data, request data, update MSHR
// On miss read (to same set) => look up cache for where to place data. Data will be found not dirty. Send request to DRAM and SMHR
// On write data response, allocate line, and write new data. 
// On read response, overwrite previously just allocated line to same set and way. 
// Data from miss write has now been lost...

// The underlying problem is that the second request, the read, has no knowledge about the fact that first request is a write. 
// As such, it sees a clean line (despite the fact that it will soon be filled with a new line, and will have a write replay) that does not need to be evicted
// If the second request did somehow know about its in-flight write status, the problem is still not solved becaues that line cant be evicted since its data is still being fetched



// Fix 2: When a miss is detected, before requesting a read/write from DRAM, check if that line's data is in flight, or is busy. 
// If a miss collides with a line (wants to allocate to a line) that is currently busy, wait for that operation to complete before beforing an AXI read and possible write.
// When this collision is detected, buffer the request 


// Simpler solution to this problem


// Basically, there is a memory consistency issue when there is a write miss to some set/way followed by a read/write miss to the same set/way
// That arrises because the second miss is unable to evict data that has not yet been recieved. 
// In other words, when the first write miss occurs, there is a 50/100 cycle window that, if contains another allocate to the same way/set as the first miss
// will simply overwrite the first wire request data in the cache, meaning the write data is lost. 

// Luckily, the only way this can occur is if the set/way that was just allocated to goes from the most recently used to the least recently used, making it subject to eviction.
// Since this type of access pattern is fairly uncommon, when a miss request to an outstanding write set, the cache is locked up until the line has been allocated, in which the request is replayed,
// including checking for an eviction and requesting the data from DRAM


// The simplest solution to the problem:
// When the cache recieves a request to a set that currently has an in-flight write miss request, do not accept the request (mark cache unready).
// Note that this is regardless of the way, and regardless of the request is actually a hit or a miss. 
// This requires a buffer that stores an "in flight write miss" for each set. 
// This bit is set when a write miss takes place, and is cleared on replay. 
// If a CPU request address indicates an inflight write miss for any way in that set, the cache is just marked unready. 
