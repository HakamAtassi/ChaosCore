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
import circt.stage.ChiselStage
import chisel3.util._



class LRU(ways:Int) {
    // A struct to manage the LRU
    def LRU_entry={

    }
}

class LRU(ways:Int) extends Bundle{
    val bits = VecInit(ways, Bool())
}



class basic_cache[T <: Data](val basicCacheParameters:BasicCacheParameters[T]) extends Module{
    
    val io = IO(new Bundle{
        val CPU_request = Flipped(Decoupled(UInt(32.W)))
        val CPU_response = Decoupled(basicCacheParameters.entry.cloneType) // Use cloneType for Chisel compatibility

        //val mem_request
        //val mem_response
    })

    ///////////////////
    // INIT MEMORIES //
    ///////////////////

    // Required: 
  	val valid_memory = RegInit(VecInit.tabulate(basicCacheParameters.sets, basicCacheParameters.ways){(x, y) => 0.B })
	val data_memories = Seq.fill(L1_cacheLineSizeBytes)(SyncReadMem(basicCacheParameters.sets, basicCacheParameters.entry.cloneType))
	val tag_memories = Seq.fill(L1_cacheLineSizeBytes)(SyncReadMem(basicCacheParameters.sets, UInt(basicCacheParameters.tagBits.W)))
    
    // LRU memory
  	val LRU_memory = RegInit(VecInit.tabulate(L1_DataCacheSets, L1_DataCacheWays){(x, y) => 0.B })
    def udpate_LRU(hit_oh:Vec[Bool])=Vec[Bool]{
        LRU_next := Mux((LRU | hit_oh).andR, hit_oh, LRU | hit_oh)
    }


    val tags = tag_memories.map(mem => mem.read(io.addr.bits))
    // Fixme this now needs index to check for valid bits
    val hit_oh = tag.map(_ === RegNext(basicCacheParameters(io.addr.bits).getTag)) && RegNext(io.addr.fire) && RegNext(io.valid(basicCacheParameters(io.addr.bits).getSet))
    val hit = hit_oh.reduce(_ || _)
    val data = Mux1H(hit_oh, dataEntries)

    // dirty???


    // buffer for when waiting from DRAM response
    class miss_buffer extends Bundle{
        val addr = UInt(32.W)
        val data = new basicCacheParameters.entry.cloneType
        val way  = Vec(basicCacheParameters.ways, Bool())
    }

    object cacheState extends ChiselEnum{
        val Active, Request, Allocate, Kill, Replay, Stall = Value
    }


    
    io.mem_request := 0.U.asTypeOf()
    io.mem_response := 0.U.asTypeOf()
    io.cpu_request.ready := 1.B

    val last_valid_request = RegInit(UInt(32.W))

    when(io.CPU_request.fire){
        last_valid_request := io.CPU_request.bits
    }


    // FIXME: what if you have an output but the CPU didnt accept it??
    // where/how to handle reads/writes?
    // what about evictions for dirty lines?

    switch(cache_state){
        is(cacheState.Active){

            when(miss){
                io.CPU_request.ready  := 0.B  // set cache unready
                io.mem_request.valid  := 1.B // request from memory
                io.mem_request.bits   := CPU_response // go to request state
                io.mem_response.ready := 1.B // set cache as ready for response
            }
        }

        is(cacheState.Request){
            when(io.mem_response.fire){ // wait for memory request to be accepted
                // goto allocate
                cache_state := cacheState.Allocate
            }
        }

        is(cacheState.Allocate){
            when(io.mem_response.fire){ // memory responded
                // allocate TODO:
                // goto replay
                cache_state := cacheState.Replay
            }
        }

        is(cacheState.Replay){
            // re-do request
            // goto active
        }

        is(cacheState.Kill){
        }
    }


}