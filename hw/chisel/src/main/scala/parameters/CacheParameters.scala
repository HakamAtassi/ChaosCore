/* ------------------------------------------------------------------------------------
* Filename: CacheParameters.scala
* Author: Hakam Atassi
* Date: Oct 28
* Description: A reusable parameter file for cache like structures
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

/*
case class CacheParameters(
    
    cacheLineSizeBytes:Int = 32,
    cacheWays:Int = 4,
    cacheSets:Int = 64,
    

    
){


    // TODO: move cache info to a case class
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


    def getSet(address:UInt):UInt = {
       address(31-tagBits, 31-tagBits-setBits+1)
    }


    def getTag(address:UInt):UInt = {
        address(31, 31-tagBits+1)
    }

    def getSizeKB():UInt = {
        consumedKB
    }

    /*
    def get_decomposed_icache_address(address:UInt):instruction_cache_address_packet={
        val instruction_offset_bits     = log2Ceil(fetchWidth)
        val fetch_packet_bits           = log2Ceil(cacheLineSizeBytes/4/fetchWidth)

        //decomposed_icache_address.fetch_packet        := address(31-tagBits-setBits, 31-tagBits-setBits-fetchPacketBits+1) 
        decomposed_icache_address.instruction_offset  := address(2+instruction_offset_bits, 2) // The offset within the packet
        decomposed_icache_address
    }
    */

}
*/


