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
  /**
   * @param data_way: The hit cache line
   * @param address: Address of the cache request
   * @param operation: LW/LHW/LB
   * @return: The formatted data extracted from the cache line
   */
  def apply(data_way: UInt, address: UInt, operation: access_width_t.Type):UInt = {
    val word_offset = (address & 0x1F.U) / 4.U  // The "word address". ie, word 1, word 2, word 3.
    val byte_offset = address % 4.U  // The byte offset within that word, if any. Ex, word 2, byte 0. 
    val word_shamt = word_offset * 32.U
    
    val access_word = (data_way >> word_shamt)(31, 0)

	val result = Wire(UInt(32.W))

	result := access_word

    //printf("word_offset %x\n", word_offset)
    //printf("data_way %x\n", data_way)
	//printf("access_word: %x\n", access_word)
    //printf("address %x\n", address)
    //printf("word shamrt %d\n", word_shamt)
	//printf("%d\n", operation)
	//printf("result %x\n", result)
    
	when(operation === access_width_t.W){
		result := access_word
	}.elsewhen(operation === access_width_t.HW){
		result := (access_word >> (byte_offset * 16.U))(15, 0)
	}.elsewhen(operation === access_width_t.B){
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
	def apply(PLRU:UInt, tag_hit_OH:Vec[Bool]):UInt = {
		val updated_PLRU = Wire(UInt(4.W))	// FIXME: Make this a param for L1_data cache ways
		when((PLRU | tag_hit_OH.asUInt).andR === 1.U){
			updated_PLRU := tag_hit_OH.asUInt
		}.otherwise{
			updated_PLRU := PLRU | tag_hit_OH.asUInt
		}
		updated_PLRU
	}
}

case class data_cache_address_packet(tag:UInt, set:UInt, word_offset:UInt, half_word_offset:UInt, byte_offset:UInt)

object get_decomposed_dcache_address{
  def apply(coreParameters:CoreParameters, address:UInt):data_cache_address_packet={
	import coreParameters._

	val set_bits                    = log2Ceil(L1_DataCacheSets)
	val tag_bits                    = 32 - log2Ceil(L1_DataCacheBlockSizeBytes)-set_bits    // 32 - bits required to index set - bits required to index within line - 2 bits due to 4 byte aligned data

	val decomposed_dcache_address = new data_cache_address_packet(
		tag = address(31, 31-tag_bits+1),
		set = address(31-tag_bits, 31-tag_bits-set_bits+1),
		word_offset = (address / 4.U),
		half_word_offset = (address / 2.U),
		byte_offset = (address / 1.U)
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
	val is_evict_dirty 				= Wire(Bool())

	val valid_vec					= Wire(Vec(L1_DataCacheWays, Bool()))

	val valid_MSHR_hit  			= Wire(Bool())
	val valid_MSHR_miss 			= Wire(Bool())
	var hit_MSHR 					= new MSHR_entry(coreParameters)
	var hit_MSHR_index 				= Wire(UInt(log2Ceil(L1_MSHREntries).W))

	val cacheable_AXI_response_valid	=	 Wire(Bool())

	//////////////////////////////
	// Helper signal assignment //
	//////////////////////////////

	io.CPU_request.ready		:= 1.B		// FIXME: !

	active_valid				:=	DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY || (io.CPU_request.valid)
	active_address				:=	Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY, replay_address,		backend_address)
	active_cacheable			:=	((active_address & "h80000000".U) === 0.U) && active_valid
	active_set					:=	Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY, replay_set, 			backend_set)
	active_tag					:=	Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY, replay_tag, 			backend_tag)
	active_memory_type			:=	Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY, replay_memory_type, 	backend_memory_type)
	active_access_width			:=	Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY, replay_access_width, backend_access_width)
	active_MOB_index			:=	Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY, replay_MOB_index, 	backend_MOB_index)


	valid_hit			:= tag_hit_OH.reduce(_ || _)	&& (RegNext(io.CPU_request.valid) || RegNext(DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY)) && RegNext(active_cacheable)
	valid_miss			:= !tag_hit_OH.reduce(_ || _)	&& (RegNext(io.CPU_request.valid) || RegNext(DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY)) && RegNext(active_cacheable)

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
	val cacheable_request_Q			= 	Module(new Queue(new AXI_request_Q_entry, 8, flow=false, hasFlush=false, useSyncReadMem=false))						// FIXME: needs flush/kill
	val non_cacheable_request_Q		=	Module(new Queue(new AXI_request_Q_entry, 8, flow=false, hasFlush=false, useSyncReadMem=false))						// FIXME: needs flush/kill
	val AXI_request_Q				= 	Module(new Queue(new AXI_request_Q_entry, 2, flow=false, hasFlush=false, useSyncReadMem=false))						// FIXME: needs flush/kill

	// Incoming response queues	//
	val cacheable_response_Q		=	Module(new Queue(new backend_memory_response(coreParameters), 8, flow=false, hasFlush=false, useSyncReadMem=true))	//FIXME: needs flush/kill
	val non_cacheable_response_Q	=	Module(new Queue(new backend_memory_response(coreParameters), 8, flow=false, hasFlush=false, useSyncReadMem=true))	//FIXME: needs flush/kill

	// Output skid buffer //
	val CPU_response_skid_buffer	=	Module(new Queue(new backend_memory_response(coreParameters), 3, flow=false, hasFlush=false, useSyncReadMem=false))	// FIXME: needs flush/kill

	///////////////////
	// DATA MEMORIES //
	///////////////////
	// Array of N memories, each 1 byte wide and sets*ways long (Bmem).

	val data_memories 				= Seq.fill(L1_DataCacheBlockSizeBytes)(Module(new ReadWriteSmem(depth=L1_DataCacheSets*L1_DataCacheWays, width=8)))
	val data_memories_wr_en 		= Wire(Vec(L1_DataCacheBlockSizeBytes, Bool()))
	val data_memories_data_in 		= Wire(Vec(L1_DataCacheBlockSizeBytes, UInt(8.W)))

	// Assign data_memory_wr_en
	for(i <- 0 until L1_DataCacheBlockSizeBytes){
		val word_offset 			= get_decomposed_dcache_address(coreParameters, io.CPU_request.bits.addr).word_offset
		val half_word_offset 		= get_decomposed_dcache_address(coreParameters, io.CPU_request.bits.addr).half_word_offset
		val byte_offset 			= get_decomposed_dcache_address(coreParameters, io.CPU_request.bits.addr).byte_offset

		val word_offset_match 		= (word_offset === (i / 4).U) && (active_memory_type === memory_type_t.STORE) && (active_access_width === access_width_t.W)
		val half_word_offset_match 	= (word_offset === (i / 2).U) && (active_memory_type === memory_type_t.STORE) && (active_access_width === access_width_t.HW)
		val byte_offset_match 		= (word_offset === (i / 1).U) && (active_memory_type === memory_type_t.STORE) && (active_access_width === access_width_t.B)

		data_memories_wr_en(i) 		:= (DATA_CACHE_STATE === DATA_CACHE_STATES.ALLOCATE) || (word_offset_match || half_word_offset_match || byte_offset_match)
	}

	active_data := Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY, replay_data, io.CPU_request.bits.data)

	for(i <- 0 until L1_DataCacheBlockSizeBytes){
		data_memories_data_in(i) 	:= Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.ALLOCATE, (allocate_cache_line>>(i*8))(7,0), ((active_data)>>(i%4)*8)(7,0)) //(((i+1)%4)*8-1, (i%4)*8))
	}

	val data_memory_allocate_address 	= Cat(allocate_way, allocate_set)
	val data_memory_active_address 		= Cat(hit_way, RegNext(active_set))


	for((data_memory, i) <- data_memories.zipWithIndex){
		data_memory.io.enable		:= 1.B
		//data_memory.io.addr			:= Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.ALLOCATE, allocate_set, RegNext(active_set))
		data_memory.io.addr			:= Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.ALLOCATE, data_memory_allocate_address, data_memory_active_address)
		data_memory.io.wr_en		:= data_memories_wr_en(i)
		data_memory.io.data_in		:= data_memories_data_in(i)
	}

	data_way		:=	Cat(data_memories.map(_.io.data_out).reverse)
	writeback_data 	:=	data_way


	//////////////////
	// TAG MEMORIES //
	//////////////////
	// Array of Way memories, each tag size bits wide (Bmem).

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
	writeback_tag 		:= VecInit(tag_memories.map(_.io.data_out))(miss_way)
	writeback_address 	:= writeback_tag << log2Ceil(L1_DataCacheBlockSizeBytes)


	//////////////////
	// VALID MEMORY //
	//////////////////
	// Memory of "way" width, sets length (Regs).

  	val valid_memory = RegInit(VecInit.tabulate(L1_DataCacheSets, L1_DataCacheWays){ (x, y) => 0.B })

	// update on allocate
	when(DATA_CACHE_STATE === DATA_CACHE_STATES.ALLOCATE){
		// Data is valid after being allocated
		valid_memory(allocate_set)(allocate_way) := 1.B
	}

	when(valid_miss){
		// Invalidate the cache line as it is now scheduled for write back and is considered in-flight. Writes to this line, for instance, will be discarded
		valid_memory(RegNext(active_set))(evict_way)	:= 0.B
	}

	for(i <- 0 until L1_DataCacheWays){
		valid_vec(i) := RegNext(valid_memory(active_set)(i))
	}



	///////////////////
	// PLRU MEMORIES //
	///////////////////
	// Memory of "way" width, sets length (Regs).

	val PLRU_memory = RegInit(VecInit(Seq.fill(L1_DataCacheSets)(0.U(L1_DataCacheWays.W))))

	// update on hit (read or write)
	when(valid_hit){
		PLRU_memory(hit_set) := update_PLRU(PLRU = PLRU_memory(hit_set), tag_hit_OH = tag_hit_OH)
	}
	// clearing PLRU on allocate is not needed (you allocate to the 0 PLRU bit, ie, no change)


	val PLRU 	= Reg(UInt(L1_DataCacheWays.W))
	PLRU 		:= PLRU_memory(active_set)
	evict_way 	:= PriorityEncoder(~PLRU)

	dontTouch(evict_way)
	dontTouch(PLRU)

	//////////////////
	// DIRTY MEMORY //
	//////////////////
	// Memory of "way" width, sets length (Regs)

	val dirty_memory = VecInit.fill(L1_DataCacheSets, L1_DataCacheWays)(0.B)

	// update on hit (writes only)
	when(valid_write_hit){
		dirty_memory(hit_set)(PriorityEncoder(tag_hit_OH)) := 1.B
	}

	// clear on allocate
	when(DATA_CACHE_STATE === DATA_CACHE_STATES.ALLOCATE){
		dirty_memory(allocate_set)(allocate_way) := 0.B
	}

	writeback_dirty 	:= dirty_memory(miss_set)(miss_way)
	is_evict_dirty 		:= dirty_memory(RegNext(active_set))(evict_way)



	/////////////////////////////////
	// MSHRs & Non-Cacheable Buffer//
	/////////////////////////////////


	val MSHRs 				= Reg(Vec(L1_MSHREntries, new MSHR_entry(coreParameters)))
	val MSHR_ptr_width		= (log2Ceil(L1_MSHREntries)+1)
	val MSHR_front_pointer 	= RegInit(UInt(MSHR_ptr_width.W), 0.U)
	val MSHR_back_pointer	= RegInit(UInt(MSHR_ptr_width.W), 0.U)

	val MSHR_front_index 	= MSHR_front_pointer(MSHR_ptr_width-2, 0)
	val MSHR_back_index 	= MSHR_back_pointer(MSHR_ptr_width-2, 0)

	// update non-cacheable buffer on non-cacheable request
	val non_cacheable_buffer 				= Reg(Vec(L1_NonCacheableBufferEntries, new backend_memory_request(coreParameters)))
	val non_cacheable_buffer_front_pointer 	= RegInit(UInt(log2Ceil(L1_NonCacheableBufferEntries).W), 0.U)
	val non_cacheable_buffer_back_pointer 	= RegInit(UInt(log2Ceil(L1_NonCacheableBufferEntries).W), 0.U)

	val non_cacheable_buffer_front_index 	= non_cacheable_buffer_front_pointer(log2Ceil(L1_NonCacheableBufferEntries) - 2, 0)
	val non_cacheable_buffer_back_index 	= non_cacheable_buffer_front_pointer(log2Ceil(L1_NonCacheableBufferEntries) - 2, 0)

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

	// Response is cacheable
	when(valid_miss && valid_MSHR_hit){
		// append MSHR entry
		MSHRs(hit_MSHR_index).miss_requests(MSHRs(hit_MSHR_index).back_pointer) := miss_backend_memory_request
		MSHRs(hit_MSHR_index).back_pointer := MSHRs(hit_MSHR_index).back_pointer + 1.U
	}.elsewhen(valid_miss && valid_MSHR_miss){
		// allocate new MSHR entry
		MSHRs(MSHR_front_index).allocate_way := evict_way
		MSHRs(MSHR_back_index).valid	:= 1.B
		MSHRs(MSHR_back_index).address := miss_backend_memory_request.addr & dram_addr_mask
        MSHRs(MSHR_back_index).miss_requests(MSHRs(MSHR_back_index).back_pointer) := miss_backend_memory_request
		MSHRs(MSHR_back_index).back_pointer := MSHRs(MSHR_back_index).back_pointer + 1.U
		MSHR_back_pointer := MSHR_back_pointer + 1.U
	}

	// Response is non-cacheable
	// TODO: construct input from buffer
	// updated buffer

	when(active_non_cacheable_read){
		non_cacheable_buffer(non_cacheable_buffer_front_index) := io.CPU_request.bits
		non_cacheable_buffer_back_pointer := non_cacheable_buffer_front_pointer + 1.U
	}




	MSHR_replay_done := 0.B
	when(DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY){
		// On replay, send requests one after the other in a burst fashion. 
		MSHRs(MSHR_front_index).dequeue
		when(MSHRs(MSHR_front_index).last){
			MSHR_replay_done := 1.B
			MSHR_front_pointer := MSHR_front_pointer + 1.U

			// clear the MSHR entry
			MSHRs(MSHR_front_index).clear
		}
	}

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

	// Buffer cacheable requests //
	// format request //

	// Memory requests occur when a cache miss takes place or when there is a non-cacheable request
	cacheable_request_Q.io.enq.valid 	 			:=  RegNext(active_cacheable_write_read) && valid_miss && valid_MSHR_miss // buffer cache misses
	cacheable_request_Q.io.enq.bits.write_valid		:=	RegNext(active_cacheable_write_read) && is_evict_dirty
	cacheable_request_Q.io.enq.bits.write_address	:=	writeback_address	//FIXME: ???
	cacheable_request_Q.io.enq.bits.write_data		:=	data_way	// FIXME: this should be evict way...
	cacheable_request_Q.io.enq.bits.write_ID		:=	0.U
	cacheable_request_Q.io.enq.bits.write_bytes		:=	L1_DataCacheBlockSizeBytes.U

	// Read missing line
	cacheable_request_Q.io.enq.bits.read_valid		:=	RegNext(active_cacheable_write_read)
	cacheable_request_Q.io.enq.bits.read_address	:=	RegNext(active_address) & dram_addr_mask
	cacheable_request_Q.io.enq.bits.read_ID			:=	0.U
	cacheable_request_Q.io.enq.bits.read_bytes		:=	L1_DataCacheBlockSizeBytes.U


	// Buffer non-cacheable requests //
	// format request //
	when(io.CPU_request.bits.access_width === access_width_t.W)				{non_cacheable_request_bytes := 4.U}
	.elsewhen(io.CPU_request.bits.access_width === access_width_t.HW)		{non_cacheable_request_bytes := 2.U}
	.otherwise																{non_cacheable_request_bytes := 1.U}

	// Memory requests occur when a cache miss takes place or when there is a non-cacheable request
	non_cacheable_request_Q.io.enq.valid 				:=	(active_non_cacheable_read  || active_non_cacheable_write) && active_valid
	non_cacheable_request_Q.io.enq.bits.write_valid		:=	active_non_cacheable_write
	non_cacheable_request_Q.io.enq.bits.write_address	:=	active_address
	non_cacheable_request_Q.io.enq.bits.write_data		:=	active_data 
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
			}.elsewhen(cacheable_AXI_response_valid){
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


	output_data := format_dcache_word(data_way, output_address, output_operation)
	

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

	allocate_cache_line		:=	axi_response.data

	cacheable_AXI_response_valid := axi_response_valid && (axi_response_ID === 0.U)

	// CACHEABLE
	// On AXI response, queue entries into line fill buffer

	cacheable_response_Q.io.enq.valid 			:= RegNext(valid_hit)
	cacheable_response_Q.io.enq.bits.data  		:= output_data
	cacheable_response_Q.io.enq.bits.MOB_index  := output_MOB_index
	cacheable_response_Q.io.deq.ready 			:= 1.B		// FIXME: not always ready

	// NON-CACHEABLE
	// On AXI response, queue entries into non cacheable response
	dontTouch(io)
	dontTouch(axi_response_valid)
	dontTouch(axi_response.data)

	non_cacheable_response_Q.io.enq.valid 			:= axi_response_valid && (axi_response_ID === AXI_NON_CACHEABLE_RESPONSE_ID.U).asBool
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
}