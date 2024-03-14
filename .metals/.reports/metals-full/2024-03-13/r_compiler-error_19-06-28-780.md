file://<WORKSPACE>/hw/chisel/src/main/scala/L1Cache/L1_cache_mem.scala
### java.lang.IndexOutOfBoundsException: 0

occurred in the presentation compiler.

presentation compiler configuration:
Scala version: 3.3.1
Classpath:
<HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/scala-lang/scala3-library_3/3.3.1/scala3-library_3-3.3.1.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/scala-lang/scala-library/2.13.10/scala-library-2.13.10.jar [exists ]
Options:



action parameters:
offset: 10863
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


object CPU_CMD extends ChiselEnum{
  val read, write = Value
}


class RMW(ways:Int = 4, sets:Int = 64, blockSizeBytes:Int = 64) extends Module{
  // This module performs writes to cache lines and updates the PLRU bits as needed
  val depth = sets
  val validBits = 1
  val dirtyBits = 1
  val PLRUBits  = 1
  val dataBits  = blockSizeBytes*8
  val tagBits = 32 - log2Ceil(sets) - log2Ceil(blockSizeBytes)

  val io = IO(new Bundle{
    val cache_mem_hit = Input(Vec(ways, Bool()))  // Hit signals directly out of the ways

    val cpu_cmd  = Input(CPU_CMD())
    val cpu_addr = Input(UInt(32.W))
    val cpu_data = Input(UInt(32.W))

    val cache_line_valid_in = Input(Vec(ways, Bool()))
    val cache_line_dirty_in = Input(Vec(ways, Bool()))
    val cache_line_PLRU_in  = Input(Vec(ways, Bool()))
    val cache_line_tag_in   = Input(Vec(ways, UInt(tagBits.W)))
    val cache_line_data_in   = Input(Vec(ways, UInt(dataBits.W))) 

    val wr_en = Output(Vec(ways, Bool()))
    val dout = Output(Vec(ways, UInt(dataBits.W)))
  })



    // FIXME: this module only works for full word modification!

    //////////////////////
    // UPDATE PLRU BITS //
    //////////////////////
    // PLRU: Mark hit way as set. if this causes everything to be set (all 1s), reset all PLRU and only set hit way (ie, refresh PLRU bits)
    // In hardware, this translates to ORing PLRU bits with HIT bits. If ANDing all the bits results in a 1, the new PLRU is just the hit[3:0] signal.

    val PLRU_OR_HIT = Wire(Vec(ways, Bool()))
    for(i <- 0 until ways) { PLRU_OR_HIT(i) := io.cache_line_PLRU_in(i) | io.cache_mem_hit(i)}

    val PLRU_next = Wire(Vec(ways, Bool())) 
    PLRU_next := Mux(PLRU_OR_HIT.reduce(_ & _), io.cache_mem_hit, PLRU_OR_HIT)  //TODO: rename this to modified_cache_PLRU
    
    //////////////////
    // UPDATE VALID //
    //////////////////
    // Valid is only asserted by the DMEM side controller (since its set upon allocation only). 
    // No change
    
    /////////////////////////
    // Update Data & DIRTY //
    /////////////////////////
    // Update data if wr_en is set
    // Each word in each cache line has a mux that is controlled by a one how write signal of some sort

    // FIXME: needs to be updated for bytes. right now only works for words
    val modified_words       = Wire(Vec(ways, Vec(16, UInt(32.W))))
    val modified_cache_data  = Wire(Vec(ways, UInt(dataBits.W)))
    val modified_cache_dirty = Wire(Vec(ways, UInt(1.W)))
    val write_oh             = Wire(Vec(16, Bool()))
    val write                = Wire(Bool())
    val byte_select          = Wire(UInt(4.W))


    byte_select := io.cpu_addr(5, 2) >> 2  // the word in the cache line being modified  
    write_oh := VecInit(Seq.tabulate(16){ i => (byte_select === i.U) })
    write := (io.cpu_cmd === CPU_CMD.write)
    for(way <- 0 until ways){for(i <- 0 until 16){modified_words(way)(i) := Mux((write_oh(i).asBool && write), io.cache_line_data_in(way)((i+1)*32-1,(i*32)), io.cpu_data)}}
    for(way <- 0 until ways) {modified_cache_data(way) := Cat(Seq.tabulate(16)(i => modified_words(way)(i)).reverse)}
    for(way <- 0 until ways){modified_cache_dirty(way) := Mux((write && io.cache_mem_hit(way)), 1.U, io.cache_line_dirty_in(way))}


    ///////////////////
    // ASSIGN OUTPUT //
    ///////////////////
    // CACHE LINE STRUCTURE [VALID, DIRTY, PLRU, TAG, DATA] 

    // Pack vectors and set wr_en accordingly
    for(way <- 0 until ways){io.dout(way) := io.cache_line_valid_in(way).asUInt ## modified_cache_dirty(way).asUInt ## PLRU_next(way).asUInt ## io.cache_line_tag_in(way) ## modified_cache_data(way)}
    io.wr_en := io.cache_mem_hit  // The cache way that is written to is the one that hit
}

class L1_cache_mem(ways:Int = 4, sets:Int = 64, blockSizeBytes:Int = 64) extends Module{
    val io = IO(new Bundle{
        // Inputs from CPU (forwarded by controller)
        val cpu_addr    =     Input(UInt(32.W))
        val cpu_data     =     Input(UInt(32.W))
        val cpu_valid   =     Input(Bool())
        val cpu_cmd     =     Input(CPU_CMD()) // either read or write

        // Inputs from Controller
        // val controller_addr    =     Input(UInt(32.W))
        // val controller_din     =     Input(UInt(32.W))
        // val controller_valid   =     Input(Bool())
        // val controller_cmd   =       Input(???)  // either allocate or idle (i think)

        // Outputs
        val cache_dout  =     Output(UInt(32.W))
        val cache_addr  =     Output(UInt(32.W)) 
        val cache_valid =     Output(Bool())
        val cache_hit   =     Output(Bool())

    })

    //////////////////////////
    // CALCULATE PARAMETERS //
    //////////////////////////

    // CACHE LINE STRUCTURE [VALID, DIRTY, PLRU, TAG, DATA] 
    val depth = sets
    val validBits = 1
    val dirtyBits = 1
    val PLRUBits  = 1
    val dataBits  = blockSizeBytes*8
    val tagBits = 32 - log2Ceil(sets) - log2Ceil(blockSizeBytes)
    val width = (validBits + tagBits + dirtyBits + PLRUBits) + dataBits  // 512 for data, Tag + valid + dirty + PLRU for metadeta
    println("Buidling L1 Cache")
    println(s"Cache Config: Ways=${ways}, Sets=${sets}, Block Size=${blockSizeBytes}B")
    println(s"Tag size = ${tagBits}")

    val memories: Seq[TrueDualPortMemory] = Seq.tabulate(ways) { w =>
        Module(new TrueDualPortMemory(depth=depth, width=width))
    }

    // Delay cache request to match mem latency (shift register(s))
    val memLatency = 1 // assume memory latency of 1 cycle (for now)
    val outputLatency = 3 // assume output latency is 1 cycle (for now)
    val delayed_cpu_addr = ShiftRegister(io.cpu_addr, memLatency, true.B)
    val delayed_cpu_valid = ShiftRegister(io.cpu_valid, memLatency, true.B)

    ////////////////////
    // CONNECT MEMORY //
    ////////////////////

    // Rename bmem output (cache line)
    val cache_mem_dout  = Wire(Vec(ways, UInt(dataBits.W)))
    val cpu_addr_tag_delayed = Wire(UInt(tagBits.W))
    cpu_addr_tag_delayed := delayed_cpu_addr(31, (31-tagBits))

    for(i <- 0 until ways){
        // DP RAM TOP (MEM) SIDE
        // FIXME: Temp
        memories(i).io.addrA := 0.U
        memories(i).io.writeDataA := 0.U
        memories(i).io.writeEnableA := 0.U

        // DP RAM BOTTOM (CPU) SIDE
        //memories(i).io.writeEnableB := RMW.io.wr_en(i)
        //memories(i).io.writeDataB   := RMW.io.dout(i)
        //memories(i).io.writeEnableB := 0.U
        //memories(i).io.writeDataB   := 0.U
        memories(i).io.addrB        := io.cache_addr

        cache_mem_dout(i)           := memories(i).io.readDataB
    }

    /////////////////
    // RENAME DOUT //
    /////////////////

    val cache_mem_valid = Wire(Vec(ways, Bool()))
    val cache_mem_dirty = Wire(Vec(ways, Bool()))
    val cache_mem_PLRU  = Wire(Vec(ways, Bool()))
    val cache_mem_tag   = Wire(Vec(ways, UInt(tagBits.W)))
    val cache_mem_data  = Wire(Vec(ways, UInt(tagBits.W)))

    for(i <- 0 until ways){
      cache_mem_valid(i)  :=  memories(i).io.readDataA(width-1)
      cache_mem_dirty(i)  :=  memories(i).io.readDataA(width-2)
      cache_mem_PLRU(i)   :=  memories(i).io.readDataA(width-3)
      cache_mem_tag(i)    :=  memories(i).io.readDataA((width-4),(width-4-tagBits))
      cache_mem_data(i)   :=  memories(i).io.readDataA((width-5-tagBits),(0))
    }

    ///////////////
    // CHECK HIT //
    ///////////////

    val cache_mem_hit   = Wire(Vec(ways, Bool()))
    for(i <- 0 until ways){
      cache_mem_hit(i)   :=  cache_mem_valid(i).asBool & delayed_cpu_valid & (cache_mem_tag(i) ===  cpu_addr_tag_delayed).asUInt
    }

    val cache_hit = Wire(Bool())
    cache_hit := cache_mem_hit.asUInt.orR  // assign cache hit

    // TODO: valid
    // TODO: ready
    
    io.cache_valid := ShiftRegister(io.cpu_valid.asUInt, outputLatency, true.B).asBool // FIXME: not always true (ie, on stalls due to MSHR)
    io.cache_addr  := ShiftRegister(io.cpu_addr, outputLatency, true.B) // FIXME: not always true (ie, on stalls due to MSHR)
    io.cache_hit   := ShiftRegister(cache_hit, outputLatency-memLatency, true.B).asBool // FIXME: not always true (ie, on stalls due to MSHR)


    //TODO: Do PLRU update on hits (need to build PLRU circuit)
    
    //////////////////////////////
    // Instantiate PLRU circuit //
    //////////////////////////////
    val RMW = Module(new RMW(ways=4, sets=64, blockSizeBytes=64))

    val RMW_delayed_cpu_addr = RegInit(UInt(32.W),0.U)
    val RMW_delayed_cpu_data = RegInit(UInt(32.W),0.U)
    val RMW_delayed_cpu_cmd = Reg(CPU_CMD())

    RMW_delayed_cpu_addr       := io.cpu_addr
    RMW_delayed_cpu_data       := io.cpu_data
    RMW_delayed_cpu_cmd        := io.cpu_cmd

    RMW.io.cpu_addr            := RMW_delayed_cpu_addr
    RMW.io.cpu_data            := RMW_delayed_cpu_data
    RMW.io.cpu_cmd             := RMW_delayed_cpu_cmd

    RMW.io.cache_mem_hit       := cache_mem_hit
    RMW.io.cache_line_valid_in := cache_mem_valid
    RMW.io.cache_line_dirty_in := cache_mem_dirty
    RMW.io.cache_line_PLRU_in  := cache_mem_PLRU
    RMW.io.cache_line_tag_in   := cache_mem_tag
    RMW.io.cache_line_data_in  := cache_mem_dirty


    for (@@)
    memories(i).io.writeEnableB := RMW.io.wr_en(i)
    memories(i).io.writeDataB   := RMW.io.dout(i)

    //////////////////////////
    // CONNECT PLRU circuit //
    //////////////////////////


    // Assign dout
    val hit_cache_line_data = RegInit(UInt(dataBits.W),0.U)
    hit_cache_line_data := Mux1H(cache_mem_hit, cache_mem_data)   // Get hit cache line


    // seperate cache line data into words
    val byte_select = ShiftRegister(io.cpu_addr(5, 2) >> 2, 2, 1.B)
    val words = VecInit((0 until 16).map(i => hit_cache_line_data(32*(i+1)-1, 32*i).asUInt)) // Seperate cache line into 32 bit words
    val dout = RegInit(UInt(32.W),0.U)
    val dout_cases = (0 until 16).map(i => (byte_select === i.U) -> words(i))

    dout := MuxCase(0.U, dout_cases)

    io.cache_dout := dout // Assign cache dout

}

object Main extends App{

    var L1_cache_mem = ChiselStage.emitSystemVerilog(gen=new L1_cache_mem(ways=4, sets=64, blockSizeBytes=64), firtoolOpts=Array("-disable-all-randomization"))

    //println(non_restoring_divider)

    var file = new File("../verilog/L1Cache/L1_cache_mem.v")

    var fw = new FileWriter(file)

    try {
      fw.write(L1_cache_mem)
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