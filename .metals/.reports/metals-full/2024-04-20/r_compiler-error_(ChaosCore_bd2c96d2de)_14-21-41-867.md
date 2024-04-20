file://<WORKSPACE>/hw/chisel/src/main/scala/Frontend/BP/uDecoder.scala
### java.lang.IndexOutOfBoundsException: 0

occurred in the presentation compiler.

presentation compiler configuration:
Scala version: 3.3.1
Classpath:
<WORKSPACE>/.scala-build/ChaosCore_bd2c96d2de/classes/main [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/scala-lang/scala3-library_3/3.3.1/scala3-library_3-3.3.1.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/scala-lang/scala-library/2.13.10/scala-library-2.13.10.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/com/sourcegraph/semanticdb-javac/0.7.4/semanticdb-javac-0.7.4.jar [exists ]
Options:
-Xsemanticdb -sourceroot <WORKSPACE> -release 17


action parameters:
offset: 3021
uri: file://<WORKSPACE>/hw/chisel/src/main/scala/Frontend/BP/uDecoder.scala
text:
```scala
/* ------------------------------------------------------------------------------------
* Filename: RAS.scala
* Author: Hakam Atassi
* Date: Apr 19 2024
* Description: A control flow instruction only decoder. This module is responsible for generating RAS control logic
* as well as correcting target addresses early in the case of a BTB miss. It decodes 2 instructions at a time. 
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


class branchDecoder extends Module{

    val io = IO(new Bundle{
        // input instruction 
        val instruction         = Input(UInt(32.W))

        val imm                 = Output(UInt(32.W)) // immediate for address computation

        val is_cond_branch      = Output(UInt(32.W))   
        val is_jump             = Output(UInt(32.W))

        // for RAS control
        val is_call             = Output(UInt(32.W))
        val is_ret              = Output(UInt(32.W))
    })

    // instruction fields
    val opcode  = Wire(UInt(7.W))
    val rs1     = Wire(UInt(5.W))
    val rd      = Wire(UInt(5.W))
    val imm     = Wire(UInt(32.W))


    val conditional_branch = Wire(Bool())
    val JAL = Wire(Bool())
    val JALR = Wire(Bool())

    // sub catagories
    val call = Wire(Bool())
    val ret = Wire(Bool())


    // if rd==x1, call (when JAL/JALR)
    // if rs1==x1 & rd == x0, ret (when JALR)


    opcode := io.instruction(6,0)
    rd := io.instruction(11,7)
    rs1 := io.instruction(19,15)


    when(opcode === "0b1101111"){   // JAL
        imm := ???
        when(rd === 1.U){   // call
            call := 1.B
        }
    }.elsewhen(opcode === "0b1100111".U){   // JALR
        imm := ???
        when(rd === 1.U){   // call
            call := 1.B
        }.elsewhen()@@{

        }
    }.elsewhen(opcode === "0b1100011".U){   // cond
        imm := ???
    }.otherwise{
        imm := ???
    }


}

class uDecoder extends Module{

    val io = IO(new Decoder{

        // Instruction inputs
        val instruction_0                   = Input(UInt(32.W))
        val instruction_0_valid             = Input(Bool())

        val instruction_1                   = Input(UInt(32.W))
        val instruction_1_valid             = Input(Bool())

        // Fetch packet address
        val fetch_PC                        = Input(UInt(32.W))

        // BTB inputs
        val BTB_hit                         = Input(Bool())
        val BTB_idx                         = Input(UInt(2.W))

        // TOS inputs
        val TOS_address                     = Input(UInt(32.W))

        // RAS control
        val call_valid                      = Output(Bool())
        val ret_valid                       = Output(Bool())
        val call_addr                       = Output(UInt(32.W))

        // redirect channel
        val uDeocder_target                 = Output(UInt(32.W))
        val uDecoder_redirect               = Output(Bool())

        // instruction queue channel
        val instruction_0_out               = Output(UInt(32.W))
        val instruction_0_out_valid         = Output(Bool())

        val instruction_1_out               = Output(UInt(32.W))
        val instruction_1_out_valid         = Output(UInt(32.W))

    })








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