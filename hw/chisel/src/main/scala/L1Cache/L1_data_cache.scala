
/* ------------------------------------------------------------------------------------
* Filename: L1_Cache.scala
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
	 @param data_way: The hit cache line
	 @param address: Address of the cache request
	 @param Operation: LW/LHW/LB
	 @return: The formatted data extracted from the cache line
	 */
  def apply(data_way: UInt, address: UInt, operation: access_width_t.Type): UInt = {
	val word_offset:UInt = address / 4.U		// The "word address". ie, word 1, word 2, word 3.
	val byte_offset:UInt = address % 4.U		// The byte offset within that word, if any. Ex, word 2, byte 0. 

    val word_shamt:UInt = (word_offset+1.U)*32.U-1.U
	
	val access_word:UInt = (data_way>>word_shamt)(32, 0)
	var output:UInt = 0.U

	when(operation === access_width_t.W){
		output = access_word
	}.elsewhen(operation === access_width_t.HW){
		val byte_shamt:UInt =  byte_offset*16.U
		output = (access_word>>byte_shamt)(15, 0)
	}.elsewhen(operation === access_width_t.B){
		val byte_shamt:UInt = (byte_offset*8.U)
		output = (access_word>>byte_shamt)(7,0)
	}
	output
  }
}

object update_PLRU {
	/**
	* @param PLRU: the current read out PLRU state
	* @param hit_way_OH: the OH equality result of the PLRU memories
	* @return: the updated PLRU result
	*/
	def apply(PLRU:UInt, tag_hit_OH:Vec[Bool]):UInt = {
		var updated_PLRU:UInt = 0.U
		when((PLRU | tag_hit_OH.asUInt).andR === 1.U){
			updated_PLRU = tag_hit_OH.asUInt
		}.otherwise{
			updated_PLRU = PLRU | tag_hit_OH.asUInt
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
		val backend_memory_request	= Flipped(Decoupled(new backend_memory_request(coreParameters)))
		val backend_memory_response	= Decoupled(new backend_memory_response(coreParameters))

		// FIXME: flush/kill ??

	})

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
	val miss_tag					= Wire(UInt(log2Ceil(L1_DataCacheTagBits).W))		// The tag of the request that missed
	val miss_way					= Wire(UInt(log2Ceil(L1_DataCacheWays).W))			// The way the missed request will be allocated into upon response, based on PLRU
	val miss_MOB_index				= Wire(UInt(log2Ceil(MOBEntries).W))

	// The active request may either be from the CPU directly of from the replay logic
	val active_valid				= Wire(Bool())										// Current request valid?
	val active_address				= Wire(UInt(32.W))									// The currently active request address
	val active_set					= Wire(UInt(log2Ceil(L1_DataCacheSets).W))
	val active_tag					= Wire(UInt(log2Ceil(L1_DataCacheTagBits).W))
	val active_memory_type			= Wire(memory_type_t())
	val active_access_width			= Wire(access_width_t())
	val active_MOB_index			= Wire(UInt(log2Ceil(MOBEntries).W))

	val backend_request_valid		= Wire(Bool())										// Current request valid?
	val backend_address				= Wire(UInt(32.W))									// The currently active request address
	val backend_set					= Wire(UInt(log2Ceil(L1_DataCacheSets).W))
	val backend_tag					= Wire(UInt(log2Ceil(L1_DataCacheTagBits).W))
	val backend_memory_type			= Wire(memory_type_t())
	val backend_access_width		= Wire(access_width_t())

	val replay_request_valid		= Wire(Bool())										// Current request valid?
	val replay_address				= Wire(UInt(32.W))									// The currently active request address
	val replay_set					= Wire(UInt(log2Ceil(L1_DataCacheSets).W))
	val replay_tag					= Wire(UInt(log2Ceil(L1_DataCacheTagBits).W))
	val replay_memory_type			= Wire(memory_type_t())
	val replay_access_width			= Wire(access_width_t())

	val allocate_way_OH				= Wire(Vec(L1_DataCacheWays, Bool()))
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

	//////////////////////////////
	// Helper signal assignment //
	//////////////////////////////


	active_valid				:=	DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY || (io.backend_memory_request.valid)
	active_address				:=	Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY, replay_address,		backend_address)
	active_set					:=	Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY, replay_set, 			backend_set)
	active_tag					:=	Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY, replay_tag, 			backend_tag)
	active_memory_type			:=	Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY, replay_memory_type, 	backend_memory_type)
	active_access_width			:=	Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.REPLAY, replay_access_width, backend_access_width)


	valid_hit			:= tag_hit_OH.reduce(_ || _)	&& RegNext(io.backend_memory_request.valid)
	valid_miss			:= !tag_hit_OH.reduce(_ || _)	&& RegNext(io.backend_memory_request.valid)

	valid_write_hit		:=	valid_hit && RegNext(active_memory_type === memory_type_t.STORE)
	valid_write_miss	:=	valid_miss && RegNext(active_memory_type=== memory_type_t.STORE)

	valid_read_hit 		:=	valid_hit && RegNext(active_memory_type=== memory_type_t.LOAD)
	valid_read_miss		:=	valid_miss && RegNext(active_memory_type=== memory_type_t.LOAD)

	hit_address			:=	RegNext(active_address)
	hit_set				:=	RegNext(active_set)
	hit_tag				:=	RegNext(active_tag)
	hit_MOB_index		:=	RegNext(active_MOB_index)
	hit_way				:= 	PriorityEncoderOH(tag_hit_OH.asUInt)	// FIXME: OH or non OH for priority encoder

	miss_address		:= RegNext(active_address)
	miss_set			:= RegNext(active_set)
	miss_tag			:= RegNext(active_tag)
	miss_MOB_index		:= RegNext(active_MOB_index)
	miss_way			:= PriorityEncoderOH(~(tag_hit_OH.asUInt))	// miss way == allocate way == the rightmost/leftmost way with a 0 PLRU bit


	//backend_request_valid
	backend_address 	:=	io.backend_memory_request.bits.addr
	backend_set			:=	get_decomposed_dcache_address(coreParameters, io.backend_memory_request.bits.addr).set
	backend_tag			:=  get_decomposed_dcache_address(coreParameters, io.backend_memory_request.bits.addr).tag
	backend_memory_type	:=  io.backend_memory_request.bits.memory_type
	backend_access_width:=  io.backend_memory_request.bits.access_width


	//allocate_cache_line			= Wire(UInt((L1_DataCacheBlockSizeBytes*8).W))

	//MSHR_replay_done			= Wire(Bool())

	//output_valid				= Wire(Bool())
	//output_data					= Wire(UInt(32.W))
	//output_address				= Wire(UInt(32.W))
	//output_operation			= Wire(access_width_t())
	//output_MOB_index			= Wire(UInt(log2Ceil(MOBEntries).W))

	///////////////////
	// REQUEST QUEUE //
	///////////////////
	// FIXME: how many queue entries

	class AXI_request_Q_entry extends Bundle{
		val write_valid		=	Bool()
		val write_address	=	UInt(32.W)
		val write_data		=	UInt((L1_DataCacheBlockSizeBytes*8).W)
		val write_bytes		=	UInt(log2Ceil(128).W)	// Max number of bytes per transfer is 128

		val read_valid		=	Bool()
		val read_address	=	UInt(32.W)
		val read_bytes		= 	UInt(log2Ceil(128).W)
	}

	// There can only be N outstanding addresses.
	// Even though each address may have several related requests
	// The address will only be requested once
	// Meaning the AXI request queue will only ever need to be MSHREntries deep
	val AXI_request_Q				=	Module(new Queue(new AXI_request_Q_entry, L1_MSHREntries, flow=false, hasFlush=false, useSyncReadMem=true))	// FIXME: needs flush/kill
	
	val write_request_valid			=	AXI_request_Q.io.deq.valid	&&	AXI_request_Q.io.deq.bits.write_valid
	val write_request_address		=	AXI_request_Q.io.deq.bits.write_address
	val write_request_data			=	AXI_request_Q.io.deq.bits.write_data
	val write_request_bytes			=	AXI_request_Q.io.deq.bits.read_bytes

	val read_request_valid 			=	AXI_request_Q.io.deq.valid	&&	AXI_request_Q.io.deq.bits.read_valid
	val read_request_address		=	AXI_request_Q.io.deq.bits.read_address
	val read_request_bytes			=	AXI_request_Q.io.deq.bits.read_bytes


	when(write_request_valid){
		AXI_write_request(	write_request_address, 
							write_request_data, 
							write_request_bytes)
	}

	when(read_request_valid){
		AXI_read_request(	read_request_address, 
							read_request_bytes)
	}

	/////////////////////
	// RESPONSE QUEUES //
	/////////////////////

	val cacheable_response_Q		=	Module(new Queue(UInt((L1_DataCacheBlockSizeBytes*8).W), 1, flow=false, hasFlush=false, useSyncReadMem=true))	//FIXME: needs flush/kill
	val non_cacheable_response_Q	=	Module(new Queue(UInt(32.W), 1, flow=false, hasFlush=false, useSyncReadMem=true))	//FIXME: needs flush/kill

	///////////////////
	// DATA MEMORIES //
	///////////////////
	// Array of N memories, each 1 byte wide and sets*ways long (Bmem).

	val data_memories 			= Seq.fill(L1_DataCacheBlockSizeBytes)(Module(new ReadWriteSmem(depth=L1_DataCacheSets*L1_DataCacheWays, width=8)))
	val data_way 				= Wire(UInt((L1_DataCacheBlockSizeBytes*8).W))
	val data_memories_wr_en 	= Wire(Vec(L1_DataCacheBlockSizeBytes, Bool()))
	val data_memories_data_in 	= Wire(Vec(L1_DataCacheBlockSizeBytes, UInt(8.W)))

	// Assign data_memory_wr_en
	for(i <- 0 until L1_DataCacheBlockSizeBytes){
		val word_offset 			= get_decomposed_dcache_address(coreParameters, io.backend_memory_request.bits.addr).word_offset
		val half_word_offset 		= get_decomposed_dcache_address(coreParameters, io.backend_memory_request.bits.addr).half_word_offset
		val byte_offset 			= get_decomposed_dcache_address(coreParameters, io.backend_memory_request.bits.addr).byte_offset

		val word_offset_match 		= (word_offset === (i / 4).U) && (active_memory_type === memory_type_t.STORE) && (active_access_width === access_width_t.W)
		val half_word_offset_match 	= (word_offset === (i / 2).U) && (active_memory_type === memory_type_t.STORE) && (active_access_width === access_width_t.HW)
		val byte_offset_match 		= (word_offset === (i / 1).U) && (active_memory_type === memory_type_t.STORE) && (active_access_width === access_width_t.B)

		data_memories_wr_en(i) 		:= (DATA_CACHE_STATE === DATA_CACHE_STATES.ALLOCATE) || (word_offset_match || half_word_offset_match || byte_offset_match)
	}

	for(i <- 0 until L1_DataCacheBlockSizeBytes){
		//data_memories_data_in(i) 	:= Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.ALLOCATE, allocate_cache_line((i+1)*8 - 1, i*8), io.backend_memory_request.bits.data(((i+1)%4)*8-1, (i%4)*8))
		data_memories_data_in(i) 	:= Mux(DATA_CACHE_STATE === DATA_CACHE_STATES.ALLOCATE, (allocate_cache_line>>(i*8))(7,0), (io.backend_memory_request.bits.data>>(i%4)*8)(7,0)) //(((i+1)%4)*8-1, (i%4)*8))
	}

	for((data_memory, i) <- data_memories.zipWithIndex){
		data_memory.io.enable		:= 1.B
		data_memory.io.addr			:= active_address 
		data_memory.io.wr_en		:= data_memories_wr_en(i)
		data_memory.io.data_in		:= data_memories_data_in(i)
	}

	data_way	:=	Cat(data_memories.map(_.io.data_out).reverse)




	//////////////////
	// TAG MEMORIES //
	//////////////////
	// Array of Way memories, each tag size bits wide (Bmem).

	val tag_memories = Seq.fill(L1_DataCacheWays)(Module(new ReadWriteSmem(depth=L1_DataCacheSets, width=L1_DataCacheTagBits)))

	for(i <- 0 until L1_DataCacheWays){
		tag_hit_OH(i) := tag_memories(i).io.data_out === RegNext(active_tag)
	}

	for(i <- 0 until L1_DataCacheWays){
		// Write new tag on DRAM response
		tag_memories(i).io.enable	:= 1.B
	}
	
	for(i <- 0 until L1_DataCacheWays){
		// on allocate, update TAG
		tag_memories(i).io.wr_en 	:= (DATA_CACHE_NEXT_STATE === DATA_CACHE_STATES.ALLOCATE) && allocate_way_OH(i)
		tag_memories(i).io.addr 	:= active_set
		tag_memories(i).io.data_in	:= allocate_tag
	}


	//////////////////
	// VALID MEMORY //
	//////////////////
	// Memory of "way" width, sets length (Regs).

	val valid_memory = VecInit.fill(L1_DataCacheSets, L1_DataCacheWays)(0.B)

	// update on allocate
	when(DATA_CACHE_STATE === DATA_CACHE_STATES.ALLOCATE){
		// Data is valid after being allocated
		valid_memory(allocate_set)(allocate_way) := 1.B
	}

	when(valid_miss){
		// Invalidate the cache line as it is now scheduled for write back and is considered in-flight. Writes to this line, for instance, will be discarded
		valid_memory(miss_set)(miss_way)	:= 0.B
	}

	///////////////////
	// PLRU MEMORIES //
	///////////////////
	// Memory of "way" width, sets length (Regs).

	val PLRU_memory = RegInit(VecInit(Seq.fill(L1_DataCacheSets)(0.U(L1_DataCacheWays.W))))

	// update on hit (read or write)
	when(valid_hit){
		PLRU_memory(hit_set) := 0.U //update_PLRU(PLRU = PLRU_memory(hit_set), tag_hit_OH = tag_hit_OH)
	}
	// clearing PLRU on allocate is not needed (you allocate to the 0 PLRU bit, ie, no change)

	//////////////////
	// DIRTY MEMORY //
	//////////////////
	// Memory of "way" width, sets length (Regs)

	val dirty_memory = VecInit.fill(L1_DataCacheSets, L1_DataCacheWays)(0.B)

	// update on hit (writes only)
	when(valid_write_hit){
		dirty_memory(PriorityEncoder(tag_hit_OH))(hit_set) := 1.B
	}

	// clear on allocate
	when(DATA_CACHE_STATE === DATA_CACHE_STATES.ALLOCATE){
		dirty_memory(allocate_way)(allocate_set) := 0.B
	}

	///////////
	// MSHRs //
	///////////

	val MSHRs 				= Reg(Vec(L1_MSHREntries, new MSHR_entry(coreParameters)))
	val MSHR_ptr_width		= (log2Ceil(L1_MSHREntries)+1)
	val MSHR_front_pointer 	= RegInit(UInt(MSHR_ptr_width.W), 0.U)
	val MSHR_back_pointer	= RegInit(UInt(MSHR_ptr_width.W), 0.U)

	val MSHR_front_index 	= MSHR_front_pointer(MSHR_ptr_width-2, 0)
	val MSHR_back_index 	= MSHR_back_pointer(MSHR_ptr_width-2, 0)

	// FIXME: handle queue stuff

	// On miss, check MSHR for pre-existing entry

	val valid_MSHR_hit  = Wire(Bool())
	val valid_MSHR_miss = Wire(Bool())

	var hit_MSHR = new MSHR_entry(coreParameters)

	valid_MSHR_hit := 0.B
	when(valid_miss){
		for(MSHR <- MSHRs){
			when(MSHR.address === miss_address){
				valid_MSHR_hit := 1.B
				hit_MSHR = MSHR
			}
		}
	}

	// If found, append 
	// If not found, allocate new entry

	when(valid_miss && valid_MSHR_hit){
		// append MSHR entry
		val miss_backend_memory_request = new backend_memory_request(coreParameters)	// TODO: 
		hit_MSHR.queue(miss_backend_memory_request)
	}.elsewhen(valid_miss && valid_MSHR_miss){
		// allocate new MSHR entry
	}


	MSHR_replay_done := 0.B
	when(DATA_CACHE_NEXT_STATE === DATA_CACHE_STATES.REPLAY){
		// On replay, send requests one after the other in a burst fashion. 
		when(MSHRs(MSHR_front_index).empty){
			MSHR_replay_done := 1.B
			MSHR_front_pointer := MSHR_front_pointer + 1.U
		}
	}

	//FIXME: Allocate way and miss way are inconsistent
	//allocate_way_OH			= Wire(Vec(L1_DataCacheWays, Bool()))
	//allocate_way				= Wire(UInt(log2Ceil(L1_DataCacheWays).W))
	allocate_address			:= MSHRs(MSHR_front_index).address
	allocate_set				:= get_decomposed_dcache_address(coreParameters, MSHRs(MSHR_front_index).address).set
	allocate_tag				:= get_decomposed_dcache_address(coreParameters, MSHRs(MSHR_front_index).address).tag

	//////////////////////////
	// NON CACHEABLE BUFFER //
	//////////////////////////
	// TODO: 


	////////////////////////////////////////////////////
	// AXI RESPONSE BUFFERS (CACHEABLE/NON-CACHEABLE) //
	////////////////////////////////////////////////////

	val (axi_response, axi_response_valid) = AXI_read

	val axi_response_ID = 0.U	// FIXME: need to also read AXI response ID

	// CACHEABLE
	// On AXI response, queue entries into line fill buffer

	cacheable_response_Q.io.enq.valid := axi_response_valid && (axi_response_ID === AXI_CACHEABLE_RESPONSE_ID.U).asBool
	cacheable_response_Q.io.enq.bits  := axi_response

	// NON-CACHEABLE
	// On AXI response, queue entries into non cacheable response

	non_cacheable_response_Q.io.enq.valid := axi_response_valid && (axi_response_ID === AXI_NON_CACHEABLE_RESPONSE_ID.U).asBool
	non_cacheable_response_Q.io.enq.bits  := axi_response


	/////////
	// FSM //
	/////////

	DATA_CACHE_NEXT_STATE := DATA_CACHE_STATE

	switch(DATA_CACHE_STATE){
		is(DATA_CACHE_STATES.ACTIVE){
			when(non_cacheable_response_Q.io.deq.valid){
				// output non cacheable response
			}.elsewhen(cacheable_response_Q.io.deq.valid){
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




	////////////
	// OUTPUT //
	////////////

	// Reads always output the data and the MOB index
	// When in ACTIVE, non-cacheable reads have complete priority over normal DRAM reads
	// In either case, the output valid occurs 2 cycles after a hit is detected


	non_cacheable_response_Q.io.deq.ready := 0.B

	when(DATA_CACHE_STATE === DATA_CACHE_STATES.ALLOCATE && non_cacheable_response_Q.io.deq.valid){
		output_data := non_cacheable_response_Q.io.deq.bits
		non_cacheable_response_Q.io.deq.ready := 1.B
	}.elsewhen(non_cacheable_response_Q.io.deq.valid){
		output_data := 0.U //RegNext(format_dcache_word(data_way, output_address, output_operation))
	}

    output_valid		:=	ShiftRegister(valid_hit, 2)
    output_MOB_index	:=	hit_MOB_index



	////////
	// IO //
	////////

    io.backend_memory_response.valid					:=	output_valid
    io.backend_memory_response.bits.data				:=	output_data
    io.backend_memory_response.bits.MOB_index			:=	output_MOB_index


}


// TODO: mob index stuff
// general output stuff
// MSHR update stuff
// AXI stuff
// non cacheable buffer stuff
