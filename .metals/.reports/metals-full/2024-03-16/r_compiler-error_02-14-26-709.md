file://<WORKSPACE>/hw/chisel/src/main/scala/L1Cache/L1_cache_mem_v2.scala
### java.lang.IndexOutOfBoundsException: 0

occurred in the presentation compiler.

presentation compiler configuration:
Scala version: 3.3.1
Classpath:
<HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/scala-lang/scala3-library_3/3.3.1/scala3-library_3-3.3.1.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/scala-lang/scala-library/2.13.10/scala-library-2.13.10.jar [exists ]
Options:



action parameters:
offset: 10829
uri: file://<WORKSPACE>/hw/chisel/src/main/scala/L1Cache/L1_cache_mem_v2.scala
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


object CONTROLLER_CMD extends ChiselEnum {
  val LB   =  Value("b000".U)
  val LHW  =  Value("b001".U)
  val LW   =  Value("b010".U)

  val NOP  =  Value("b011".U)

  val SB   =  Value("b100".U)
  val SHW   =  Value("b101".U)
  val SW   =  Value("b110".U)

  val ALLOCATE = Value("b111".U)
}




class L1_cache_mem(ways:Int = 4, sets:Int = 64, blockSizeBytes:Int = 64) extends Module{
    // CACHE LINE STRUCTURE [VALID, DIRTY, PLRU, TAG, DATA] 
    val depth = sets
    val setBits = log2Ceil(sets)
    val wayBits = log2Ceil(ways)
    val validBits = 1
    val dirtyBits = 1
    val PLRUBits  = 1
    val dataSizeBits  = blockSizeBytes*8
    val dataBits = log2Ceil(blockSizeBytes)
    val wordOffsetBits     = log2Ceil(blockSizeBytes/4)
    val halfWordOffsetBits = log2Ceil(blockSizeBytes/2)
    val byteOffsetBits     = log2Ceil(blockSizeBytes)


    val tagBits = 32 - log2Ceil(sets) - log2Ceil(blockSizeBytes)
    val width = (validBits + tagBits + dirtyBits + PLRUBits) + dataBits  // 512 for data, Tag + valid + dirty + PLRU for metadeta
    println("Buidling L1 Cache")
    println(s"Cache Config: Ways=${ways}, Sets=${sets}, Block Size=${blockSizeBytes}B")
    println(s"Tag size = ${tagBits}")
    println(s"Line width = ${width}")
    val io = IO(new Bundle{
        // Inputs from CPU (forwarded by controller)
        val controller_addr    =     Input(UInt(32.W))
        val controller_data    =     Input(UInt(32.W))
        val controller_valid   =     Input(Bool())
        val controller_cmd     =     Input(CONTROLLER_CMD()) 

        // Inputs from Controller
        // val controller_addr    =     Input(UInt(32.W))
        // val controller_din     =     Input(UInt(32.W))
        // val controller_valid   =     Input(Bool())
        // val controller_cmd     =     Input(???)  

        // Outputs
        val cache_dout  =     Output(UInt(32.W))
        val cache_addr  =     Output(UInt(32.W)) 
        val cache_valid =     Output(Bool())
        val cache_hit   =     Output(Bool())
    })


    //////////////////
    // Global Wires //
    //////////////////

    val controller_set              = Wire(UInt(setBits.W))
    val controller_tag              = Wire(UInt(tagBits.W))
    val controller_byte_offset      = Wire(UInt(byteOffsetBits.W))
    val controller_half_word_offset = Wire(UInt(halfWordOffsetBits.W))
    val controller_word_offset      = Wire(UInt(wordOffsetBits.W))
    val hit = Wire(Bool())
    val delayed_controller_tag = RegInit(UInt(tagBits.W), 0.U)
    val hit_oh = Wire(UInt(ways.W))

    // FIXME: check all of this
    controller_set              := io.controller_addr(dataBits+setBits-1,dataBits)
    controller_tag              := io.controller_addr(tagBits+dataBits+setBits-1,dataBits+setBits)
    controller_byte_offset      := io.controller_addr(byteOffsetBits,0)       // When addressing bytes, all bits matter
    controller_half_word_offset := io.controller_addr(halfWordOffsetBits+1,1) // when addressing half words, all but last bit matter due to enforced half word alignment
    controller_word_offset      := io.controller_addr(wordOffsetBits+2,2)     // when addressing words, all but last 2 bits matter due to word alignment

    //TODO: cache_way missing


    /////////////////
    // CMD DECODER //
    /////////////////

    val tag_wr_en = Wire(Bool())
    val plru_wr_en = RegInit(Bool(), 0.B)
    val allocate = RegInit(Bool(), 0.B)

    // tag only writes upon allocate. Delay since tag pos depends on the result of PLRU mem
    tag_wr_en := (io.controller_cmd === CONTROLLER_CMD.ALLOCATE)

    // plru updates only on reads/writes, not allocate, since the allocated way goes into the most significant 0 anyway
    plru_wr_en := (io.controller_cmd =/= CONTROLLER_CMD.NOP && io.controller_cmd =/=CONTROLLER_CMD.NOP)

    // allocate signal set one cycle after request, since the eviction line must be read out first
    allocate := (io.controller_cmd === CONTROLLER_CMD.ALLOCATE)



    /////////////////
    // PLRU Memory //
    /////////////////
    val PLRU_memory = Module(new SDPReadWriteSmem(depth = sets, width = ways))

    val delayed_controller_set = RegNext(controller_tag)
    val plru_out = Wire(UInt(4.W))
    val plru_in = Wire(UInt(4.W))
    val plru_oh  = Wire(UInt(ways.W))


    // Enable
    PLRU_memory.io.enable := 1.B

    // Read port
    PLRU_memory.io.rd_addr := controller_set
    plru_out := PLRU_memory.io.data_out
    
    // Write port
    PLRU_memory.io.wr_en := (plru_wr_en && hit)
    PLRU_memory.io.wr_addr := delayed_controller_set
    PLRU_memory.io.data_in := plru_in


    // PLRU bits update logic

    plru_in := Mux((plru_out & hit_oh).andR, hit_oh, hit_oh | plru_out)
    
    // plru_oh assignment is as follows:
      // Bit N is set if Bits (N-1),0 of plru_out are all set

    // FIXME: Only works for 4 ways    
    plru_oh := Cat(~plru_in(3), plru_in(3) & ~plru_in(2), plru_in(3) & plru_in(2) & ~plru_in(1),  plru_in(3) & plru_in(2) & plru_in(1) & ~plru_in(0))


    ////////////////
    // Tag Memory //
    ////////////////
    val tag_memory = Module(new ReadWriteSmem(depth=(sets), width= tagBits * ways))
    val tag_vector_out = Wire(Vec(ways, UInt(tagBits.W)))
    val tag_vector_in = Wire(Vec(ways, UInt(tagBits.W)))
    val cache_hit_way = Wire(UInt(4.W))
    val cache_addr    = Wire(UInt((setBits+wayBits).W))

    //FIXME: cache will need to be stalled on allocate to allow read modify write of tag (to avoid dp memory)

    tag_memory.io.enable := 1.B
    tag_memory.io.wr_en := tag_wr_en
    tag_memory.io.addr := controller_set 

    // update on allocate as needed
    for(way <- 0 until ways){tag_vector_out(way) := tag_memory.io.data_out((way+1)*tagBits-1,way*tagBits)}
    
    tag_vector_in(0) := Mux(plru_oh(3), controller_tag, tag_vector_out(0))
    tag_vector_in(1) := Mux(plru_oh(2), controller_tag, tag_vector_out(1))
    tag_vector_in(2) := Mux(plru_oh(1), controller_tag, tag_vector_out(2))
    tag_vector_in(3) := Mux(plru_oh(0), controller_tag, tag_vector_out(3))

    tag_memory.io.data_in := Cat(tag_vector_in(3), tag_vector_in(2), tag_vector_in(1), tag_vector_in(0))

    // Check hit

    delayed_controller_tag := controller_tag


    val hit_oh_cat = Wire(UInt(ways.W)) // Assuming 'ways' is defined earlier
    hit_oh_cat := 0.U // Initialize the concatenated output

    for (way <- 0 until ways) {
      hit_oh_cat := hit_oh_cat ## (delayed_controller_tag === tag_vector_out(way))
    }

    hit_oh := hit_oh_cat

    hit := hit_oh.orR

    cache_hit_way := PriorityEncoder(hit_oh)

    cache_addr             := cache_hit_way ## controller_set       // The address used to index the cache data memory

    ///////////////////
    // Data Memories //
    ///////////////////

    val delayed_controller_byte_offset = RegNext(io.controller_addr(dataBits,0))  // Delay the input address
    val delayed_controller_cmd = RegNext(io.controller_cmd)  // Delay the input address

    val data_memory: Seq[ReadWriteSmem] = Seq.tabulate(blockSizeBytes) { w =>
        Module(new ReadWriteSmem(depth=(sets * ways), width=8))
    }

    // Write enable(s):
      // The write enables for each sram is designed to essentially be "does the current request write to this memory"
      // This simplifies the data input shifting and masking for LB and LHW
    
    val data_memory_wr_en = Wire(Vec(blockSizeBytes, Bool()))   // vector of wr enables

    //FIXME: this can be simplified
    for (word <- 0 until blockSizeBytes/4){ // Break enables into words
      data_memory_wr_en(word*4+0) :=  allocate || (delayed_controller_cmd===CONTROLLER_CMD.SB && delayed_controller_byte_offset===(word*4 + 0).U) || (delayed_controller_cmd===CONTROLLER_CMD.SHW && delayed_controller_byte_offset===(word*4 + 0).U) || (delayed_controller_cmd===CONTROLLER_CMD.SW  && delayed_controller_byte_offset===(word*4).U) // Enabled if SB to 1st byte, SHW to bottom half word, or SW
      data_memory_wr_en(word*4+1) :=  allocate || (delayed_controller_cmd===CONTROLLER_CMD.SB && delayed_controller_byte_offset===(word*4 + 1).U) || (delayed_controller_cmd===CONTROLLER_CMD.SHW && delayed_controller_byte_offset===(word*4 + 0).U) || (delayed_controller_cmd===CONTROLLER_CMD.SW  && delayed_controller_byte_offset===(word*4).U) // Enabled if SB to 2nd byte, SHW to bottom half word, or SW
      data_memory_wr_en(word*4+2) :=  allocate || (delayed_controller_cmd===CONTROLLER_CMD.SB && delayed_controller_byte_offset===(word*4 + 2).U) || (delayed_controller_cmd===CONTROLLER_CMD.SHW && delayed_controller_byte_offset===(word*4 + 2).U) || (delayed_controller_cmd===CONTROLLER_CMD.SW  && delayed_controller_byte_offset===(word*4).U) // Enabled if SB to 3rd byte, SHW to top half word, or SW
      data_memory_wr_en(word*4+3) :=  allocate || (delayed_controller_cmd===CONTROLLER_CMD.SB && delayed_controller_byte_offset===(word*4 + 3).U) || (delayed_controller_cmd===CONTROLLER_CMD.SHW && delayed_controller_byte_offset===(word*4 + 2).U) || (delayed_controller_cmd===CONTROLLER_CMD.SW  && delayed_controller_byte_offset===(word*4).U) // Enabled if SB to 4th byte, SHW to top half word, or SW
    }

    for(@@)




  /////////////////////////////
    io.cache_dout := 0.U
    io.cache_addr := 0.U
    io.cache_valid := 0.U
    io.cache_hit := 0.U
}



object Main extends App{

    var L1_cache_mem = ChiselStage.emitSystemVerilog(gen=new L1_cache_mem(ways=4, sets=64, blockSizeBytes=32), firtoolOpts=Array("-disable-all-randomization"))

    println(L1_cache_mem)

    var file = new File("../verilog/L1Cache/L1_cache_mem_v2.v")

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