
/* ------------------------------------------------------------------------------------
* Filename: instruction_cache.scala
* Author: Hakam Atassi
* Date: Oct 30
* Description: A basic configurable cache structure for use in the L2, TLB, and similar
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
//import chisel3.experimental.ChiselEnum



// Note: Basic cache only returns items on the granularity of full items. That is, partial items (like bytes of a word) are handled externally
class basic_cache(val basicCacheParameters:BasicCacheParameters, hasKill:Boolean=false) extends Module{
    
    val io = IO(new Bundle{
        //val kill = Bool() // FIXME: if haskill

        // CPU <> CACHE CHANNELS
        val CPU_request = Flipped(Decoupled(new Bundle{
            val addr    = UInt(32.W)
            val wr_data = UInt(32.W)
            val wr_en   = Bool()
        }))
        val CPU_response = Decoupled(UInt(basicCacheParameters.blockSizeBits.W))


        // CACHE <> CPU CHANNELS
        val cache_request = Flipped(Decoupled(new Bundle{
            val addr    = UInt(32.W)
            val wr_data = UInt(basicCacheParameters.blockSizeBits.W)
            val wr_en   = Bool()
        }))
        val cache_response = Decoupled(UInt(basicCacheParameters.blockSizeBits.W))
    })

    ///////////////////
    // INIT MEMORIES //
    ///////////////////

    // Required: 
  	val valid_memory  = RegInit(VecInit.tabulate(basicCacheParameters.sets, basicCacheParameters.ways){(x, y) => 0.B })
  	val dirty_memory  = RegInit(VecInit.tabulate(basicCacheParameters.sets, basicCacheParameters.ways){(x, y) => 0.B})
	val tag_memories  = Seq.fill(basicCacheParameters.ways)(SyncReadMem(basicCacheParameters.sets, UInt(basicCacheParameters.tagBits.W)))
	val data_memories = Seq.fill(basicCacheParameters.blockSizeBytes)(SyncReadMem(basicCacheParameters.sets, UInt(8.W)))

/*
    def write_data_memories(way_oh:UInt, set:UInt, data:UInt, width:access_width_t): UInt = {
        // way?
        for((memory, i) <- data_memories.zipWithIndex){
            when(){
                data_memories.write(set, data)
            }
        }
    }
    */

    def allocate_data_memories(way_oh:Vec[Bool], set:UInt, data:UInt):Unit = {
        var _data = data
        for((memory, i) <- data_memories.zipWithIndex){
            when(way_oh(i) === 1.B){
                data_memories.reverse(i).write(set, data(7,0))
            }
            _data = _data>>8;
        }
    }






    ////////////////////////////////
    // MEMORY INTERACTION HELPERS //
    ////////////////////////////////





    // LRU memory
  	val LRU_memory      = RegInit(VecInit.tabulate(basicCacheParameters.sets, basicCacheParameters.ways){(x, y) => 0.B })

    val LRU             = Vec(basicCacheParameters.ways, Bool())
    val hit_oh          = Vec(basicCacheParameters.ways, Bool())
    val LRU_next        = Vec(basicCacheParameters.ways, Bool())
    val allocate_way_oh = Vec(basicCacheParameters.ways, Bool())

    def update_LRU(hit_oh: Vec[Bool], LRU: Vec[Bool]): Vec[Bool] = {
        val updated_LRU = Wire(Vec(hit_oh.length, Bool()))
        updated_LRU := hit_oh.zipWithIndex.map { case (bit, i) => bit || LRU(i) }
        when(updated_LRU.asUInt.andR) {
            updated_LRU := hit_oh
        }
        updated_LRU
    }

    def get_allocate_way(LRU:Vec[Bool]):Vec[Bool] = {
        var allocate_way = Vec(LRU.length, Bool())
        for(i <- 0 until hit_oh.length){
            when(LRU(i) === 0.B){
            }
        }
        allocate_way
    }


    val tags = tag_memories.map(mem => mem.read(basicCacheParameters.getSet(io.CPU_request.bits.addr)))
    // Fixme this now needs index to check for valid bits
    
    //tags.map(_ === RegNext(basicCacheParameters.getTag(io.CPU_request.bits.addr))) && RegNext(io.valid(basicCacheParameters.getSet(io.CPU_request.addr.bits))) && RegNext(io.addr.fire)


    val hit = hit_oh.reduce(_ || _)
    val miss = !hit_oh.reduce(_ || _)

    val eviction_dirty = 0.B
    // dirty???


    // buffer for when waiting from DRAM response
    class miss_buffer extends Bundle{
        val addr = UInt(32.W)
        val data = UInt(32.W)
        val way  = Vec(basicCacheParameters.ways, Bool())
    }

    object cacheState extends ChiselEnum{
        val Active, Evict, Request, Allocate, Kill, Replay, Stall = Value
    }

    
    //io.mem_request := 0.U.asTypeOf(io.mem_request)
    //io.mem_response := 0.U.asTypeOf(io.mem_response)
    io.CPU_request.ready := 0.B

    val last_valid_request_addr = RegInit(UInt(32.W))

    when(io.CPU_request.fire){  // buffer previous request
        last_valid_request_addr := io.CPU_request.bits
    }

    // FIXME: what if you have an output but the CPU didnt accept it??
    // where/how to handle reads/writes?
    // what about evictions for dirty lines?

    // FIXME: eventually make this so that you can have tag lookup take place in a seperate cycle 
    // and use that information (hit way) to index the memory


    val cache_state     = RegInit(cacheState(), cacheState.Active)




    switch(cache_state){
        is(cacheState.Active){
            //val data_array_out = data_memories(PriorityEncoder(hit_oh)).write(io.cpu_request.addr, io.cpu_request.data)  // this needs to write a single word/byte/etc
            io.CPU_request.ready := 1.B
            when(miss){
                io.CPU_request.ready  := 0.B  // set cache unready
                allocate_way_oh := get_allocate_way(LRU)
                when(eviction_dirty){
                    cache_state := cacheState.Evict
                }.otherwise{
                    cache_state := cacheState.Request
                }
            }.elsewhen(hit){
                // update LRU
                //LRU_memory(RegNext(io.CPU_request.bits.addr)) := update_LRU(hit_oh)

                // output data/write new data
                when(RegNext(io.CPU_request.bits.wr_en)){
                    // Hit was a write
                    //data_memories(PriorityEncoder(hit_oh)).write(io.CPU_request.bits.addr, io.CPU_request.bits.data)  // this needs to write a single word/byte/etc
                    //dirty_memory(RegNext(basicCacheParameters.getSet(io.CPU_request.bits.addr)))(PriorityEncoder(hit_oh)) := 1.B
                }.otherwise{
                    // Hit was a read
                    //io.CPU_response.data := (data_array_out<< ?? )(??, ??)
                }
            }
        }


        is(cacheState.Evict){   // Evict dirty line (if needed)
            // Set invalid bit for evicted line
            // clear dirty bit for evicted line
            when(io.cache_request.fire){  // place dirty data on bus, wait for it to be accepted
                cache_state := cacheState.Allocate
            }
        }

        is(cacheState.Request){
            // Request new line from system
            when(io.cache_request.fire){ // wait for memory request to be accepted
                // goto allocate
                cache_state := cacheState.Allocate
            }
        }

        is(cacheState.Allocate){
            when(io.cache_request.fire){ // memory responded
                // goto replay
                cache_state := cacheState.Replay
                allocate_data_memories(allocate_way_oh, basicCacheParameters.getSet(last_valid_request_addr), io.cache_response.bits)
                // TODO: Tag?
                // TODO: Valid?
                cache_state := cacheState.Replay
            }
        }

        is(cacheState.Replay){
            // re-do request
            // goto active
            cache_state := cacheState.Active
        }

        is(cacheState.Kill){
        }
    }
}
