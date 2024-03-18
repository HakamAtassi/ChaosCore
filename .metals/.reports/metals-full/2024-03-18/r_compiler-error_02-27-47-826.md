file://<WORKSPACE>/hw/chisel/src/main/scala/memories/memories.scala
### java.lang.IndexOutOfBoundsException: 0

occurred in the presentation compiler.

presentation compiler configuration:
Scala version: 3.3.1
Classpath:
<HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/scala-lang/scala3-library_3/3.3.1/scala3-library_3-3.3.1.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/scala-lang/scala-library/2.13.10/scala-library-2.13.10.jar [exists ]
Options:



action parameters:
offset: 1168
uri: file://<WORKSPACE>/hw/chisel/src/main/scala/memories/memories.scala
text:
```scala
// I copied these from the internet. No license applies

import chisel3._
import circt.stage.ChiselStage
import chisel3.util._
import java.io.{File, FileWriter}
import java.rmi.server.UID

// Classic SRAM.
// 1 R/W port. 
/*
class ReadWriteSmem(depth:Int, width: Int) extends Module {
  val io = IO(new Bundle {
    val enable = Input(Bool())
    val wr_en = Input(Bool())
    val addr = Input(UInt(log2Ceil(depth).W))
    val data_in = Input(UInt(width.W))
    val data_out = Output(UInt(width.W))
  })

  val mem = SyncReadMem(depth, UInt(width.W))
  io.data_out := DontCare
  when(io.enable) {
    when (io.wr_en) { mem.write(io.addr, io.data_in) }
      .otherwise    { io.data_out := mem.read(io.addr, io.enable) }
  }
}
*/

class ReadWriteSmem(depth:Int, width: Int) extends Module {
  val io = IO(new Bundle {
    val enable = Input(Bool())
    val wr_en = Input(Bool())
    val addr = Input(UInt(log2Ceil(depth).W))
    val data_in = Input(UInt(width.W))
    val data_out = Output(UInt(width.W))
  })


  val mem = SyncReadMem(depth)
  val read_data_flop = Reg(UInt(width.W))

  read_data_flop := mem.read(io.addr, io.enable)

  when(io.wr_en){
    mem.write()@@
  }

}

// Simple dual port memory
// 1 dedicated read, 1 dedicated write
class SDPReadWriteSmem(depth: Int, width: Int) extends Module {
  val io = IO(new Bundle {
    val enable = Input(Bool())

    // Read
    val rd_addr = Input(UInt(log2Ceil(depth).W))
    val data_out = Output(UInt(width.W))
    
    // Write
    val wr_addr = Input(UInt(log2Ceil(depth).W))
    val wr_en = Input(Bool())
    val data_in = Input(UInt(width.W))
  })

  val mem = SyncReadMem(depth, UInt(width.W))
  io.data_out := DontCare

  /////////////////////
  // HAZARD HANDLING //
  /////////////////////

  val hazard_reg = RegInit(Bool(), 0.B)
  val din_buff = RegInit(UInt(width.W), 0.U)

  hazard_reg := (io.rd_addr === io.wr_addr) && io.wr_en
  din_buff := io.data_in

  //////////////////
  // READ & WRITE //
  //////////////////

  val data_out = Wire(UInt(width.W))
  data_out :=0.U

  when(io.enable) {
    when(io.wr_en) {
      mem.write(io.wr_addr, io.data_in)
    }

    data_out := mem.read(io.rd_addr, io.enable)
  }

    io.data_out := Mux(hazard_reg, din_buff, data_out) // Forward buffered data if hazard
}


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

  println(s"${name},\twidth: ${width}, depth: ${depth}")

  // Create the true dual-port memory
  val mem = SyncReadMem(depth, UInt(width.W))


  // Operations for Port A
  when(io.writeEnableA) {
    mem.write(io.addrA, io.writeDataA)
  }
  io.readDataA := mem.read(io.addrA, io.writeEnableA)

  // Operations for Port B
  when(io.writeEnableB) {
    mem.write(io.addrB, io.writeDataB)
  }
  io.readDataB := mem.read(io.addrB, io.writeEnableB)
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