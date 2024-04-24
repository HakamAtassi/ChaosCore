file://<WORKSPACE>/hw/chisel/src/main/scala/Frontend/BP/branch_decoder.scala
### java.lang.IndexOutOfBoundsException: 0

occurred in the presentation compiler.

presentation compiler configuration:
Scala version: 3.3.1
Classpath:
<WORKSPACE>/.scala-build/ChaosCore_bd2c96d2de/classes/main [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/scala-lang/scala3-library_3/3.3.1/scala3-library_3-3.3.1.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/scala-lang/scala-library/2.13.10/scala-library-2.13.10.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/com/sourcegraph/semanticdb-javac/0.7.4/semanticdb-javac-0.7.4.jar [exists ]
Options:
-Xsemanticdb -sourceroot <WORKSPACE> -release 17


action parameters:
offset: 4279
uri: file://<WORKSPACE>/hw/chisel/src/main/scala/Frontend/BP/branch_decoder.scala
text:
```scala
/* ------------------------------------------------------------------------------------
* Filename: branch_decoder.scala
* Author: Hakam Atassi
* Date: Apr 23 2024
* Description: A small decoder that determines if an indiv. instruction is a branch, and if so, is it taken (in isolation).
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

class branch_decoder(index:Int=0) extends Module{

    val io = IO(new Bundle{
        val fetch_PC    = Input(UInt(32.W))

        val instruction = Input(UInt(32.W))
        val valid       = Input(Bool())
        
        val BTB_resp    = Input(new BTB_resp())

        val T_NT        = Output(Bool())

        val metadata    = Output(new metadata())
        val PC_pred     = Output(UInt(32.W))

    })


    val opcode = io.instruction(6, 0)
    val RS1 = io.instruction(19, 15)
    val RD = io.instruction(11, 7)
    val imm = Wire(SInt(32.W))

    val JAL     = (opcode === "b1101111".U)     // Always taken if valid    
    val JALR    = (opcode === "b1100111".U)     // Only taken if Ret || BTB has target
    val BR      = (opcode === "b1100011".U)     // Taken based on prediction 

    // Sub types
    val Call = (JAL && RD === 1.U) || (JALR && RD === 1.U)       // Either JAL or JALR with RD = x1
    val Ret = (JALR && RS1 === 1.U && imm === 0.U)               // JALR with RS1 = x1 & imm = 0

    val fetch_PC_adjusted = Wire(UInt(32.W))

    fetch_PC_adjusted := io.fetch_PC + (index*4).U

    // JALR and BR are sort of opposite instructions, because JALR is always taken but needs to get its address from a buffer somewhere.
    // BR has its address available in the instruction encoding, but depends on both PHT for T_NT prediction and BTB for dominant index. 
    // Note that since 1 packet can have several branches, so simplify things, predictions depend on the BTB to inform BP of the dominant branch
    // if that is not available, default to NT. 

    // Assign imm
    when (BR) {
        imm := Cat(io.instruction(31), io.instruction(7), io.instruction(30, 25), io.instruction(11, 8)).asSInt
    }.elsewhen (JAL) {
        imm := Cat(io.instruction(31), io.instruction(19, 12), io.instruction(20), io.instruction(30, 21)).asSInt
    }.elsewhen (JALR) {
        imm := io.instruction(31, 20).asSInt
    }.otherwise {
        imm := 0.S
    }

    

    // Assign T/NT
    // Every branch has a direction and address. For taken to be 1, the direction must be taken and the address must be available...

    // Rember, if T/NT is low, the address of this instruction will not be selected. 
    // This means that the logic can be a little looser, skipping the T_NT check for address assigning. 
    // If none of the decodes output T/NT, a seperate MUX input will provide PC+4/8/16/etc...
    when (JAL) {
        io.T_NT := io.valid // JAL addr == PC+imm. dir is always 1. Therefore, taken if valid (everything available).
    }.elsewhen (JALR) {
        io.T_NT := io.valid && (Ret || (io.BTB_resp.hit && io.BTB_resp.idx()@@))  // Direction is always 1. Address is hit or miss. Only taken if addr is available.
    }.elsewhen (BR) {
        io.T_NT := io.valid && io.BTB_resp.idx  // Address is PC + Imm. Only taken if PHT is 1. However,
        // BR also depends on BTB idx since, unlike JAL and JALR, where priority can be easily arbitrated based on what comes first,
        // Branches may or may not be taken. Therefore, for the branch to be taken, it must also be the dominant one (where as with JAL, the first one is the dominant one).
    }.otherwise {
        io.T_NT := 0.U  // Not a control flow instruction, not taken. 
    }


    // Assign metadata
    io.metadata.JAL             :=  JAL 
    io.metadata.JALR            :=  JALR
    io.metadata.BR              :=  BR
    io.metadata.Call            :=  Call
    io.metadata.Ret             :=  Ret
    io.metadata.Imm             :=  imm
    io.metadata.instruction_PC  :=  fetch_PC_adjusted
    io.metadata.RAS             :=  io.BTB_resp.RAS



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