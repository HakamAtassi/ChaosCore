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
offset: 4633
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
import latchExpectedPC.State.wire_reg
import latchExpectedPC.State.wire_wire
import validate_packet.State.packet_invalid
import validate_packet.State.packet_valid


object latchExpectedPC {
    object State extends ChiselEnums{
        val wire_wire, wire_reg = Value
    }
}

object validate_packet {
    object State extends ChiselEnums{
        val packet_invalid, packet_valid = Value
    }
}


class decode_validate(width:Int = 4) extends Module{

    val io = IO(new Bundle{
        val BTB_resp     = Input(new BTB_resp())
        val fetch_packet = Input(new fetch_packet())
        val input_valid  = Input(Bool())

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

   
    val metadata_out    = new metadata()
    // assign default value to metadata
    metadata_out := 0.U
    for(i <- 0 until width){    // reverse this
        when(decoder_T_NT(i) === 1.B){
            metadata_out := decoder_metadata(i)
        }
    }


    /////////
    // FSM //
    /////////

    // FSM 1
    // compare wires or wire and reg?
    // When a cycle occurs and there is no input, latch the expected PC for later comparison

    val FSM1_state = RegInit(wire_reg)

    switch(FSM1_state){
        is(wire_wire){
            when(io.valid === 0.B){
                FSM1_state := wire_wire
            }
        }
        is(wire_reg){
            // Start here
            when(io.valid === 1.B){
                FSM1_state := wire_wire
            }
        }
    }


    // TODO: assign expected_PC


    // FSM 2
    // When a comparison takes place and the PCs match, output packet on the next cycle. 
    val FSM2_state = RegInit(packet_valid)

    switch(FSM2_state){
        is(packet_invalid){
            when()@@
        }
        is(packet_valid){
            
        }
    }


    ///////////////////////////////////


    // Select PC based on metadata
    

    // If need BTB, use BTB (non ret JALR)
    // If need RAS, use RAS (Ret)
    // If need computed, use computed (BR)

    val use_BTB      = Wire(Bool())
    val use_RAS      = Wire(Bool())
    val use_computed = Wire(Bool())

    val PC_next = Wire(UInt(32.W))

    use_BTB      := metadata_out.JALR && !metadata_out.Ret
    use_RAS      := metadata_out.Ret
    use_computed := metadata_out.BR || metadata_out.JAL 


    when(use_BTB){PC_next := metadata_out.BTB_target}
    .elsewhen(use_RAS){PC_next := metadata_out.RAS}
    .elsewhen(use_computed){PC_next := metadata_out.instruction_PC + metadata_out.Imm}
    .otherwise{PC_next := fetch_PC + (width*4)}


    // validate instructions

    // Set all valid bits to 0.
    for(i <- 0 until width){
        io.final_fetch_packet.valid_bits(i) := 0.B
    }

    // "validator"
    // iterate and valid as you go along.
    val validate_flag = Wire(Bool())
    validate_flag := 0.B
    for(i <- 0 until width){
        when(validate_flag && io.fetch_packet.valid_bits(i) && packet_valid){  // instructions are valid if no previous taken branch, was valid on input, and the packet as a whole is valid
            io.final_fetch_packet.valid_bits(i) := 1.B  // validate on output
        }
        when(decoder_T_NT(i) === 1.B){  // all instructions after taken branch are invalid
            validate_flag := 0.B    // branch occurred. All following branches invalid.
        }

        io.final_fetch_packet.instructions(i) := io.fetch_packet.instructions(i)    // pass along actual instruction
    }
    io.final_fetch_packet.fetch_PC := io.fetch_packet.fetch_PC  // Pass along fetch PC




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