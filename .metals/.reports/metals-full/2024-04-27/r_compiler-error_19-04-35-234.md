file://<WORKSPACE>/hw/chisel/src/main/scala/Frontend/BP/BP.scala
### java.lang.IndexOutOfBoundsException: 0

occurred in the presentation compiler.

presentation compiler configuration:
Scala version: 3.3.1
Classpath:
<HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/scala-lang/scala3-library_3/3.3.1/scala3-library_3-3.3.1.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/scala-lang/scala-library/2.13.10/scala-library-2.13.10.jar [exists ]
Options:



action parameters:
offset: 4043
uri: file://<WORKSPACE>/hw/chisel/src/main/scala/Frontend/BP/BP.scala
text:
```scala
/* ------------------------------------------------------------------------------------
* Filename: BP.scala
* Author: Hakam Atassi
* Date: Apr 26 2024
* Description: A wrapper for the primary branch prediction structures (ie, RAS, BTB, GSHARE, GHR)
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

class BP(GHRWidth:Int = 16, fetchWidth:Int = 4, RASEntries:Int=128, BTBEntries:Int = 4096) extends Module{
    val io = IO(new Bundle{
        // Predict Channel
        val predict     = Flipped(Decoupled(UInt(32.W)))

        // Commit Channel 
        val commit      = new commit(fetchWidth=fetchWidth) // common case. Update BTB, PHT

        // Mispredict Channel 
        val mispredict  = new mispredict(GHRWidth=GHRWidth, RASEntries=RASEntries)

        // Revert Channel
        val RAS_update  = new RAS_update(GHRWidth=GHRWidth)

        // GHR Channel
        val revert      = new revert(GHRWidth=GHRWidth)

        // Prediction Channel (output)
        val prediction  = new prediction(fetchWidth=fetchWidth, GHRWidth=GHRWidth, RASEntries=RASEntries)    // Output of predictions
    })


    val GHR = RegInit(UInt(GHRWidth.W),0.U)
    /////////////////
    // Init gshare //
    /////////////////
    val gshare = Module(new gshare(GHR_width=GHRWidth))

    // predict port
    gshare.io.predict_GHR               := GHR
    gshare.io.predict_PC                := io.predict.bits
    gshare.io.predict_valid             := io.predict.valid

    // commit port
    gshare.io.commit_GHR                := io.commit.GHR
    gshare.io.commit_PC                 := io.commit.PC
    gshare.io.commit_valid              := io.commit.valid
    gshare.io.commit_branch_direction   := io.commit.T_NT

    //////////////
    // Init BTB //
    //////////////
    val BTB = Module(new hash_BTB(entries=BTBEntries))
    // Reminder: BTB only updates on taken branches...

    // predict port
    BTB.io.predict_PC       := io.predict.bits
    BTB.io.predict_valid    := io.predict.valid

    // FIXME: this updates blindly. Where is taken only commit handled?????
    // FIXME: commit_tag not done.
    // commit port
    BTB.io.commit_PC        := io.commit.PC
    
    BTB.io.commit_tag              :=   io.commit.tag
    BTB.io.commit_target           :=   io.commit.target
    BTB.io.commit_br_type          :=   io.commit.br_type
    BTB.io.commit_br_mask          :=   io.commit.br_mask
    BTB.io.commit_valid            :=   io.commit.valid


    ///////////////////////////////
    // Init Return-Address-Stack //
    ///////////////////////////////
    val RAS = Module(new RAS(entries=RASEntries))

    RAS.io.revert_NEXT  := 0.U
    RAS.io.revert_TOS   := 0.U
    RAS.io.revert_valid := 0.U


    when(io.mispredict.valid){  // if mispred, @@
        // mispredict port
        RAS.io.revert_NEXT  :=   io.mispredict.NEXT
        RAS.io.revert_TOS   :=   io.mispredict.TOS
        RAS.io.revert_valid :=   io.mispredict.valid
    }.otherwise{
        // update port
        RAS.io.wr_addr      := io.RAS_update.call_addr
        RAS.io.wr_valid     := io.RAS_update.call
        RAS.io.rd_valid     := io.RAS_update.ret
    }

    /////////
    // GHR //
    /////////
    
    val is_cond_branch = 0.U
        //BTB.io.valid   // FIXME: not implemented

    when(io.mispredict.valid){
        GHR := io.mispredict.GHR
    }.elsewhen(io.revert.valid){
        GHR := io.revert.GHR
    }.otherwise{
        GHR := (GHR<<1) | (is_cond_branch & gshare.io.T_NT.asUInt)
    }


    // Assign outputs

    // RAS
    io.RAS_update.ret_addr := RAS.io.ret_addr
    io.RAS_update.NEXT     := RAS.io.NEXT
    io.RAS_update.TOS      := RAS.io.TOS

    // BTB
    io.prediction.valid     := (BTB.io.BTB_valid && gshare.io.valid)
    io.prediction.target    := BTB.io.BTB_target
    io.prediction.br_type   := BTB.io.BTB_type
    io.prediction.br_mask   := BTB.io.BTB_br_mask
    io.prediction.GHR       := GHR
    io.prediction.T_NT      := gshare.io.T_NT

    io.predict.ready        := io.prediction.ready     // if cant output prediction, cannot receive new prediction


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