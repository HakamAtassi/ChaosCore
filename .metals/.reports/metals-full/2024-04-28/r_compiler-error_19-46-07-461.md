file://<WORKSPACE>/hw/chisel/src/main/scala/Frontend/frontend.scala
### java.lang.IndexOutOfBoundsException: 0

occurred in the presentation compiler.

presentation compiler configuration:
Scala version: 3.3.1
Classpath:
<HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/scala-lang/scala3-library_3/3.3.1/scala3-library_3-3.3.1.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/scala-lang/scala-library/2.13.10/scala-library-2.13.10.jar [exists ]
Options:



action parameters:
offset: 2762
uri: file://<WORKSPACE>/hw/chisel/src/main/scala/Frontend/frontend.scala
text:
```scala
/* ------------------------------------------------------------------------------------
* Filename: frontend.scala
* Author: Hakam Atassi
* Date: Mar 12 2024
* Description: The fetch & pre-decode portions of the cores frontend.
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
import chisel3.util._

class Q[T <: Data](dataType: T, depth: Int = 16) extends Module {
  val io = IO(new Bundle {
    val data_in    = Input(dataType)         // input data (bundle)
    val wr_en      = Input(Bool())           // write element
    val rd_en      = Input(Bool())           // read element
    val clear      = Input(Bool())           // Clear entire queue
    val data_out   = Output(dataType)        // output data (bundle)
    val full       = Output(Bool())          // queue full
    val empty      = Output(Bool())          // queue empty
  })

  val queue = Module(new Queue(dataType, depth))

  // Connect inputs
  queue.io.enq.valid := io.wr_en
  queue.io.enq.bits := io.data_in
  queue.io.deq.ready := io.rd_en

  // Connect outputs
  io.data_out := queue.io.deq.bits
  io.full := !queue.io.enq.ready
  io.empty := !queue.io.deq.valid

  // Reset logic
  when(io.clear) {
    queue.reset := true.B
  }.otherwise {
    queue.reset := false.B
  }
}

class skidbuffer[T <: Data](datatype: T) extends Module{
  val io = IO(new Bundle{
    val in   = Flipped(Decoupled(T))
    val out  = Decoupled(T)
  })

  object State extends ChiselEnum {
    val passthrough, buffer = Value
  }

  val buffer = Reg(datatype)
  val state = RegInit(State.sNone)

  switch(state){
    is(){

    }
    is()@@
  }

}


class Frontend(GHRWidth:Int=16, fetchWidth:Int=4, RASEntries:Int=128, BTBEntries:Int=4096, L1_instructionCacheWays:Int=2, 
               L1_instructionCacheSets:Int=64, L1_instructionCacheBlockSizeBytes:Int=32) extends Module{

    val dataSizeBits                = L1_instructionCacheBlockSizeBytes*8

    val io = IO(new Bundle{
        // Inputs: A series of PCs and control signals
        val misprediction_PC  =   Flipped(Decoupled(UInt(32.W)))                              // Input
        val exception_PC      =   Flipped(Decoupled(UInt(32.W)))                              // Input
        
        val commit            =   new commit(fetchWidth=fetchWidth)                           // Input
        val mispredict        =   new mispredict(GHRWidth=GHRWidth, RASEntries=RASEntries)    // Input

        val cache_addr        =   Decoupled(UInt(32.W))                                       // outputs to DRAM
        val dram_data         =   Flipped(Decoupled(UInt(dataSizeBits.W)))                    // inputs from DRAM
        
        val fetch_packet      =   Decoupled(new fetch_packet(fetchWidth=fetchWidth))             // Fetch packet result (To Decoders)
    })

    /////////////
    // Modules //
    /////////////
    val instruction_cache   = Module(new L1_instruction_cache(fetchWidth=fetchWidth, ways=L1_instructionCacheWays, sets=L1_instructionCacheSets, blockSizeBytes=L1_instructionCacheBlockSizeBytes))
    val bp                  = Module(new BP(GHRWidth=GHRWidth, fetchWidth=fetchWidth, RASEntries=RASEntries, BTBEntries=BTBEntries))
    val predecoder          = Module(new decode_validate(fetchWidth=fetchWidth, GHRWidth=16, RASEntries=128))


    ////////////
    // Queues //
    ////////////
    val instruction_Q   =   Module(new Q(new fetch_packet(fetchWidth=fetchWidth), depth = 16))              // Instantiate queue with fetch_packet data type
    val PC_Q            =   Module(new Q(UInt(32.W)))                                                       // Queue of predicted PCs
    val BTB_Q           =   Module(new Q(new prediction(fetchWidth=fetchWidth, GHRWidth=GHRWidth)))         // Queue of BTB responses

    ///////////
    // Wires //
    ///////////
    val predict_PC     =   Wire(Decoupled(UInt(32.W)))
    val PC             =   RegInit(UInt(32.W), 0.U)


    ///////////////////
    // PC GENERATION //
    ///////////////////

    when(predict_PC.ready){
      PC := PC + 16.U /* FIXME: Not implemented*/
    }.otherwise{
      PC := PC 
    }

    predict_PC.bits  := PC
    predict_PC.valid := 1.B && predict_PC.ready /*FIXME: incomplete. Valid only high when the value itself is valid and is ready to be accepted. */
    predict_PC.ready := (!PC_Q.io.full) && bp.io.predict.ready

    //////////////
    // PC Queue //
    //////////////

    PC_Q.io.wr_en       :=  predict_PC.valid         // Write to PC_Q whenever the PC is valid
    PC_Q.io.data_in     :=  predict_PC.bits
    PC_Q.io.rd_en       :=  (!PC_Q.io.empty && instruction_cache.io.cpu_addr.ready)  // Read from PC_Q whenever I$ is ready
    PC_Q.io.clear       :=  0.B /* TODO: */

    ///////////////////////
    // INSTRUCTION QUEUE //
    ///////////////////////
    instruction_Q.io.wr_en       :=  instruction_cache.io.resp_valid    // FIXME: resp_valid should really be apart of fetch_packet
    instruction_Q.io.data_in     :=  instruction_cache.io.cache_data
    instruction_Q.io.rd_en       :=  (!BTB_Q.io.empty && !instruction_Q.io.empty && predecoder.io.fetch_packet.ready)
    instruction_Q.io.clear       :=  0.B

    ///////////////
    // BTB QUEUE //
    ///////////////

    BTB_Q.io.wr_en               :=  bp.io.prediction.valid
    BTB_Q.io.data_in             :=  bp.io.prediction.bits
    BTB_Q.io.rd_en               :=  (!instruction_Q.io.empty && !BTB_Q.io.empty && predecoder.io.prediction.ready)
    BTB_Q.io.clear               :=  0.B
  
    ///////////////////////
    // INSTRUCTION CACHE //
    ///////////////////////

    // Attach PC_Q to instruction cache
    instruction_cache.io.cpu_addr.bits     :=   PC_Q.io.data_out 
    instruction_cache.io.cpu_addr.valid    :=   (!PC_Q.io.empty)

    // Dram resp
    io.cache_addr.bits                          :=   instruction_cache.io.cache_addr.bits     //  TO DRAM 
    io.cache_addr.valid                         :=   instruction_cache.io.cache_addr.valid    //  TO DRAM
    instruction_cache.io.dram_data.valid        :=   io.dram_data.valid                       //  FROM DRAM
    instruction_cache.io.dram_data.bits         :=   io.dram_data.bits                        //  FROM DRAM

    instruction_cache.io.cache_addr.ready       := io.cache_addr.ready                        // Is DRAM ready for request ?
    io.dram_data.ready                          := instruction_cache.io.dram_data.ready       // Is Cache ready to accept DRAM response ?

    // kill 
    instruction_cache.io.kill              := 0.B


    ////////
    // BP //
    ////////

    // BP inputs (external)
    bp.io.commit            :=  io.commit
    bp.io.mispredict        :=  io.mispredict

    // BP inputs (internal)
    bp.io.predict.bits      :=  predict_PC.bits
    bp.io.predict.valid     :=  predict_PC.valid
    bp.io.RAS_update        :=  predecoder.io.RAS_update
    bp.io.revert            :=  predecoder.io.revert

    bp.io.prediction.ready  := !BTB_Q.io.empty

    ////////////////
    // PREDECODER //
    ////////////////

    predecoder.io.prediction.bits       := BTB_Q.io.data_out
    predecoder.io.prediction.valid      := !BTB_Q.io.empty
    predecoder.io.fetch_packet.bits     := instruction_Q.io.data_out /* FIXME: This should be decoupled...*/
    predecoder.io.fetch_packet.valid    := !instruction_Q.io.empty
    predecoder.io.RAS_read              := bp.io.RAS_read


    /////////////
    // OUTPUTS //
    /////////////
    
    io.misprediction_PC.ready := 1.U
    io.exception_PC.ready := 1.U

    io.fetch_packet.bits := predecoder.io.final_fetch_packet.bits
    io.fetch_packet.valid := predecoder.io.final_fetch_packet.valid
    predecoder.io.final_fetch_packet.ready := io.fetch_packet.ready

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
	scala.meta.internal.pc.ScalaPresentationCompiler.signatureHelp$$anonfun$1(ScalaPresentationCompiler.scala:414)
```
#### Short summary: 

java.lang.IndexOutOfBoundsException: 0