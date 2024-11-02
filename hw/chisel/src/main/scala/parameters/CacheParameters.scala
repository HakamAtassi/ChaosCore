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
* @param entry: For normal data cache, use UInt(8.W)
*/


case class BasicCacheParameters(
    blockSizeBytes:Int = 64,
    sets:Int = 64,
    ways:Int = 4,
){


    val depth                       = sets
    val byteOffsetBits              = log2Ceil(blockSizeBytes)                                          // Bits needed to each byte in a cache line
    val setBits                     = log2Ceil(sets)                                                    // Bits needed to address sets
    val wayBits                     = log2Ceil(ways)                                                    // Bits needed to address ways
    val validBits                   = 1                                                                 // number of valid bits
    val LRUBits                     = ways                                                              // number of LRU bits (per way)
    val blockSizeBits               = blockSizeBytes*8
    val tagBits                     = 32 - setBits - byteOffsetBits

    val wayDataWidth                = validBits + tagBits + blockSizeBits                              // width of the data line
    val consumedKB                  = (sets*ways*blockSizeBits+sets*LRUBits)/8.0/1024.0 
    val consumedKBData              = (sets*ways*blockSizeBits)/8.0/1024.0 

    def getTag(address: UInt): UInt = {address(address.getWidth - 1, address.getWidth - tagBits)}
    def getSet(address: UInt): UInt = {address(setBits + byteOffsetBits - 1, byteOffsetBits)}
    def getSizeKB: Double = (sets * ways * (blockSizeBits + tagBits + wayBits + validBits) / 8.0 / 1024.0)


    //type cacheItemType = T                // Define cacheItemType as a type alias for T
    //type cacheBlockType = Vec[T]          // Define cacheBlockType as a type alias for Vec[T]

}