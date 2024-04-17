file://<WORKSPACE>/hw/chisel/src/main/scala/Frontend/instruction_cache.scala
### java.lang.IndexOutOfBoundsException: 0

occurred in the presentation compiler.

presentation compiler configuration:
Scala version: 3.3.1
Classpath:
<HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/scala-lang/scala3-library_3/3.3.1/scala3-library_3-3.3.1.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/scala-lang/scala-library/2.13.10/scala-library-2.13.10.jar [exists ]
Options:



action parameters:
offset: 4169
uri: file://<WORKSPACE>/hw/chisel/src/main/scala/Frontend/instruction_cache.scala
text:
```scala
/* ------------------------------------------------------------------------------------
* Filename: L1_Cache.scala
* Author: Hakam Atassi
* Date: Mar 12 2024
* Description: A blocking single cycle latency instruction cache with no self CPU write port (no self modifying functionality).
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
    val Active, Miss, Replay, Allocate = Value
}


class L1_instruction_memory(ways:Int=2, sets:Int = 64, blockSizeBytes:Int = 64, fetchWidth:Int=2) extends Module{

    // CACHE LINE STRUCTURE [VALID, TAG, DATA] 
    // LRU goes in separate memory
    val depth               = sets
    val setBits             = log2Ceil(sets)                    // Bits needed to address sets
    val wayBits             = log2Ceil(ways)                    // Bits needed to address ways
    val validBits           = 1                                 // number of valid bits
    val LRUBits             = 1                                 // number of LRU bits (per way)
    val dataSizeBits        = blockSizeBytes*8                  // number of raw data bits

    val instructionsPerLine = blockSizeBytes/4                  // number of instructions per cache line (no compressed instruction support)
    val fetchPacketsPerLine = instructionsPerLine/fetchWidth    // number of fetch packets per cache line

    //val wordOffsetBits      = log2Ceil(blockSizeBytes/4)      // number of bits needed to address each word in the cache line
    //val halfWordOffsetBits  = log2Ceil(blockSizeBytes/2)      // number of bits needed to address each half-word in the cache line

    val fetchPacketOffsetBits  = log2Ceil(fetchPacketsPerLine)  // number of fetch packets per cache line



    val tagBits = 32 - log2Ceil(sets) - log2Ceil(instructionsPerLine) - 2 // For sets=64 and instr. per line = 16, tag is 20 bits (last 2 bits are always 00 for isntructions)
    val wayDataWidth = (validBits + tagBits + LRUBits) + dataSizeBits 
    println("Buidling L1 Cache")
    println(s"Cache Config: Ways=${ways}, Sets=${sets}, Block Size=${blockSizeBytes}B")
    println(s"Tag size = ${tagBits}")
    println(s"Line width = ${wayDataWidth}")


    val io = IO(new Bundle{
        val cpu_addr           =     Flipped(Decoupled(UInt(32.W)))     // inputs from CPU
        val dram_data          =     Flipped(UInt(32.W))                // inputs from DRAM

        // Outputs
        val cache_data         =     Decoupled(UInt(32.W))              // outputs to CPU
        val cache_addr         =     Decoupled(UInt(32.W))              // outputs to DRAM
    })


    val hit_oh = Wire(UInt(ways.W))

    val LRU = Wire(UInt(ways.W))
    val LRU_next = Wire(UInt(ways.W))

    LRU_next := Mux((LRU | hit_oh).andR, hit_oh, LRU | hit_oh)





    /////////
    // FSM //
    /////////
    //TODO: 
    val cache_state =  cacheState()@@   // Is this how you do it?

    switch(cache_state){
        is(Active){

        }
        is(Miss){

        }
        is(Replay){

        }
        is(Allocate){

        }
    }

    ////////////////
    // LRU MEMORY //
    ////////////////

    val LRU_memory = Module(new SDPReadWriteSmem(depth = sets, width = ways))
    //TODO: connect up

    //TODO: add LRU FSM 


    ///////////////////
    // DATA MEMORIES //
    ///////////////////

    val data_memory: Seq[ReadWriteSmem] = Seq.tabulate(ways) { w =>
        Module(new ReadWriteSmem(depth=sets, width=wayDataWidth))
    }




}
```



#### Error stacktrace:

```
scala.collection.LinearSeqOps.apply(LinearSeq.scala:131)
	scala.collection.LinearSeqOps.apply$(LinearSeq.scala:128)
	scala.collection.immutable.List.apply(List.scala:79)
	dotty.tools.dotc.util.Signatures$.countParams(Signatures.scala:501)
	dotty.tools.dotc.util.Signatures$.applyCallInfo(Signatures.scala:186)
	dotty.tools.dotc.util.Signatures$.computeSignatureHelp(Signatures.scala:94)
	dotty.tools.dotc.util.Signatures$.signatureHelp(Signatures.scala:63)
	scala.meta.internal.pc.MetalsSignatures$.signatures(MetalsSignatures.scala:17)
	scala.meta.internal.pc.SignatureHelpProvider$.signatureHelp(SignatureHelpProvider.scala:51)
	scala.meta.internal.pc.ScalaPresentationCompiler.signatureHelp$$anonfun$1(ScalaPresentationCompiler.scala:398)
```
#### Short summary: 

java.lang.IndexOutOfBoundsException: 0