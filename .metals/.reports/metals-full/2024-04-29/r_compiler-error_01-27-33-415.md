file://<WORKSPACE>/hw/chisel/src/main/scala/Frontend/BP/PC_arbit.scala
### dotty.tools.dotc.core.TypeError$$anon$1: Toplevel definition PC is defined in
  <WORKSPACE>/hw/chisel/src/main/scala/Frontend/frontend.scala
and also in
  <WORKSPACE>/hw/chisel/src/main/scala/Frontend/BP/PC_arbit.scala
One of these files should be removed from the classpath.

occurred in the presentation compiler.

presentation compiler configuration:
Scala version: 3.3.1
Classpath:
<HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/scala-lang/scala3-library_3/3.3.1/scala3-library_3-3.3.1.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/scala-lang/scala-library/2.13.10/scala-library-2.13.10.jar [exists ]
Options:



action parameters:
offset: 2338
uri: file://<WORKSPACE>/hw/chisel/src/main/scala/Frontend/BP/PC_arbit.scala
text:
```scala
/* ------------------------------------------------------------------------------------
* Filename: PC_arbit.scala
* Author: Hakam Atassi
* Date: Apr 2024
* Description: A module that arbitrates the PCs based on the BTB, Misprediction, Exception, Redirect, and +16 signals
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

class PC_arbit(GHRWidth:Int = 16, fetchWidth:Int = 4, RASEntries:Int=128, startPC:UInt="h80000000".U) extends Module{

    val io = IO(new Bundle{
        val mispredict  = new mispredict(GHRWidth=GHRWidth, RASEntries=RASEntries)                        // external mispredict
        val prediction  = Flipped(Decoupled(new prediction(fetchWidth=fetchWidth, GHRWidth=GHRWidth)))    // BTB response
        val revert      = new revert(GHRWidth=GHRWidth)                                                   // Pre-decoder revert request
        // TODO: Exception:...                                                                            // exception

        val PC_next     = Decoupled(UInt(32.W))
        val RAS_read    = F@@new RAS_read(RASEntries=RASEntries)
    })

    // if PC_next ready
        // if mispredict: go to mispredict addr
        // if exception: go to exception addr
        // if revert: go to revert addr
        // if BTB type isntruction
            // if ret, go to RAS
            // if br, go to target
            // ...
        // if none of the above
            // go to next fetch width aligned PC

    //val sel_exception   = Wire(Bool())
    val sel_mispred     = Wire(Bool())
    val sel_revert      = Wire(Bool())
    val sel_ret         = Wire(Bool())
    val sel_target      = Wire(Bool())
    val sel_PC_4        = Wire(Bool())

    val PC                   = RegInit(UInt(32.W), startPC)
    val aligned_PC_increment = Wire(UInt(log2Ceil(fetchWidth).W))
    val instruction_index    = Wire(UInt(log2Ceil(fetchWidth).W))
    


    //sel_exception      := io.exception.valid
    sel_mispred        := io.mispredict.valid 
    sel_revert         := io.revert.valid

    sel_ret            := io.prediction.valid && io.prediction.bits.hit && (io.prediction.bits.br_type ===0.U)   // FIXME: br_type wrong
    sel_target         := io.prediction.valid && io.prediction.bits.hit && (io.prediction.bits.br_type ===0.U)   // FIXME: br_type wrong

    sel_PC_4           := 1.B   // if none of the above (default)


    // TODO: assign aligned increment
    instruction_index := PC(log2Ceil(fetchWidth) + 2,2)
    aligned_PC_increment    := (fetchWidth.U-instruction_index)<<2


    when(io.PC_next.ready){
        PC := io.PC_next.bits + aligned_PC_increment
    }.otherwise{
        PC := io.PC_next.bits
    }
    
    
    io.prediction.ready := 1.B  // FIXME: when is this actually ready
    io.PC_next.valid    := 1.B


        
    when(sel_mispred)       {io.PC_next.bits := io.mispredict.PC}
    //.elsewhen(sel_exception){io.PC_next.bits := io.exception.PC}
    .elsewhen(sel_revert)   {io.PC_next.bits := io.revert.PC}
    .elsewhen(sel_ret)      {io.PC_next.bits := io.RAS_read.ret_addr}
    .elsewhen(sel_target)   {io.PC_next.bits := io.prediction.bits.target}
    .elsewhen(sel_PC_4)     {io.PC_next.bits := PC}
    .otherwise              {io.PC_next.bits := 0.U}

}
```



#### Error stacktrace:

```

```
#### Short summary: 

dotty.tools.dotc.core.TypeError$$anon$1: Toplevel definition PC is defined in
  <WORKSPACE>/hw/chisel/src/main/scala/Frontend/frontend.scala
and also in
  <WORKSPACE>/hw/chisel/src/main/scala/Frontend/BP/PC_arbit.scala
One of these files should be removed from the classpath.