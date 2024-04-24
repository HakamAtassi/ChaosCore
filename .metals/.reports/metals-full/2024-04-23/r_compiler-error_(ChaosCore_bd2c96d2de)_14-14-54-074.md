file://<WORKSPACE>/hw/chisel/src/main/scala/Frontend/BP/decode_validate.scala
### java.lang.IndexOutOfBoundsException: 0

occurred in the presentation compiler.

presentation compiler configuration:
Scala version: 3.3.1
Classpath:
<WORKSPACE>/.scala-build/ChaosCore_bd2c96d2de/classes/main [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/scala-lang/scala3-library_3/3.3.1/scala3-library_3-3.3.1.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/org/scala-lang/scala-library/2.13.10/scala-library-2.13.10.jar [exists ], <HOME>/.cache/coursier/v1/https/repo1.maven.org/maven2/com/sourcegraph/semanticdb-javac/0.7.4/semanticdb-javac-0.7.4.jar [exists ]
Options:
-Xsemanticdb -sourceroot <WORKSPACE> -release 17


action parameters:
offset: 3159
uri: file://<WORKSPACE>/hw/chisel/src/main/scala/Frontend/BP/decode_validate.scala
text:
```scala
/* ------------------------------------------------------------------------------------
* Filename: decode_validate.scala
* Author: Hakam Atassi
* Date: Apr 23 2024
* Description: A module resposible for controlling the RAS and validating the flow of instructions into the decoders/backend
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

class decode_validate(width:Int = 4) extends Module{

    val io = IO(new Bundle{
        val BTB_resp     = Input(new BTB_resp())
        val fetch_packet = Input(new fetch_packet())

        // TODO:RAS control output...
        val kill = Output(Bool())

        // TODO: redirect

        // TODO: output instruction fetch packet

        val final_fetch_packet = Output(new fetch_packet())

    })



    /////////////
    // STAGE 1 //
    /////////////
    
    // Assign decoders register outputs
    // Assign decoders in first stage




    val decoders: Seq[branch_decoder] = Seq.tabulate(width) { w =>
        Module(new branch_decoder(index=width))
    }   // FIXME: this is fucked

    val decoder_metadata         = Wire(Vec(width, new metadata()))
    val decoder_T_NT             = Wire(Vec(width, Bool()))

    for(i <- 0 until width){
        decoders(i).io.fetch_PC        :=  io.fetch_packet.fetch_PC
        decoders(i).io.instruction     :=  io.fetch_packet.instructions(i)
        decoders(i).io.valid           :=  io.fetch_packet.valid_bits(i)
        decoders(i).io.BTB_resp        :=  io.BTB_resp
        //
        decoder_metadata(i)         :=  decoders(i).io.metadata
        decoder_T_NT(i)             :=  decoders(i).io.T_NT
    }

    val T_NT_reg = Reg(decoder_T_NT)
    val metadata = Reg(decoder_metadata)


    /////////////
    // STAGE 2 //
    /////////////

    // Select dominant branch; select expected PC
    // Control RAS
    // Validate instructions
    // Assign outputs


    for (@@)    


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