file://<WORKSPACE>/hw/chisel/src/main/scala/L1Cache/L1_cache_mem.scala
### java.lang.IndexOutOfBoundsException: 0

occurred in the presentation compiler.

presentation compiler configuration:
Scala version: 3.3.1
Classpath:
<HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/scala-lang/scala3-library_3/3.3.1/scala3-library_3-3.3.1.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/scala-lang/scala-library/2.13.10/scala-library-2.13.10.jar [exists ]
Options:



action parameters:
offset: 2737
uri: file://<WORKSPACE>/hw/chisel/src/main/scala/L1Cache/L1_cache_mem.scala
text:
```scala
/* ------------------------------------------------------------------------------------
* Filename: L1_Cache.scala
* Author: Hakam Atassi
* Date: Mar 12 2024
* Description: (Part of) A lockup-free L1 Cache. This module contains the memory component. 
* It only returns hit/miss based on the data available in the memories. It does not perform allocation.
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


class L1_cache_mem(ways:Int = 4, sets:Int = 64, blockSizeBytes:Int = 64) extends Module{
    val io = IO(new Bundle{
        val cpu_addr    =     Input(UInt(32.W))
        val cpu_data    =     Input(UInt(32.W))
        val cpu_valid   =     Input(Bool())

        val cache_dout  =     Output(UInt(32.W))
        val cache_addr  =     Output(UInt(32.W)) 
        val cache_valid =     Output(Bool())
        val cache_hit   =     Output(Bool())
    })

    println("Buidling L1 Cache")
    println(s"Cache Config: Ways=${ways}, Sets=${sets}, Block Size=${blockSizeBytes}B")


    val tagSize = 32 - log2Ceil(sets) - log2Ceil(blockSizeBytes)
    println(s"Tag size = ${tagSize}")

    val depth = sets
    val validBit = 1
    val dirtyBit = 1
    val PLRUBit  = 1
    val dataBits  = blockSizeBytes*8

    val width = (tagSize + validBit + dirtyBit + PLRUBit) + dataBits  // 512 for data, Tag + valid + dirty + PLRU for metadeta

    val memories: Seq[TrueDualPortMemory] = Seq.tabulate(ways) { w =>
        Module(new TrueDualPortMemory(, @@depth, width))
    }

    
    for(i <- 0 until ways){
        memories(i).io.addrB := io.cache_addr
    }


/*
class TrueDualPortMemory(depth: Int, width: Int) extends Module {
  val io = IO(new Bundle {
    // Port A
    val addrA = Input(UInt(log2Ceil(depth).W))
    val writeDataA = Input(UInt(width.W))
    val writeEnableA = Input(Bool())
    val readDataA = Output(UInt(width.W))

    // Port B
    val addrB = Input(UInt(log2Ceil(depth).W))
    val writeDataB = Input(UInt(width.W))
    val writeEnableB = Input(Bool())
    val readDataB = Output(UInt(width.W))
  })
*/

  // Temp

    io.cache_dout  := 0.U
    io.cache_addr  := 0.U
    io.cache_valid := 0.U
    io.cache_hit   := 0.U

    for(i <- 0 until ways){
        memories(i).io.addrA := 0.U
        memories(i).io.writeDataA := 0.U
        memories(i).io.writeEnableA := 0.U

        //memories(i).io.addrB := 0.U
        memories(i).io.writeDataB := 0.U
        memories(i).io.writeEnableB := 0.U
    }

}

object Main extends App{

    var non_restoring_divider = ChiselStage.emitSystemVerilog(gen=new L1_cache_mem(ways=4, sets=64, blockSizeBytes=64), firtoolOpts=Array("-disable-all-randomization", "-strip-debug-info"))

    println(non_restoring_divider)

  var file = new File("../verilog/L1Cache/L1_cache_mem.v")

  var fw = new FileWriter(file)

  try {
    fw.write(non_restoring_divider)
  } finally {
    fw.close()
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