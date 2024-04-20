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
offset: 9517
uri: file://<WORKSPACE>/hw/chisel/src/main/scala/Frontend/BP/uDecoder.scala
text:
```scala
/* ------------------------------------------------------------------------------------
* Filename: uDecoder.scala
* Author: Hakam Atassi
* Date: Apr 20 2024
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

        val is_branch           = Output(Bool())   // is the instruction a control flow instruction
        val is_cond_branch      = Output(Bool())   
        val is_jump             = Output(Bool())

        // for RAS control
        val is_call             = Output(Bool())
        val is_ret              = Output(Bool())
    })

    // instruction fields
    val opcode  = Wire(UInt(7.W))
    val rs1     = Wire(UInt(5.W))
    val rd      = Wire(UInt(5.W))

    val conditional_branch = Wire(Bool())
    val JAL = Wire(Bool())
    val JALR = Wire(Bool())


    // if rd==x1, call (when JAL/JALR)
    // if rs1==x1 & rd == x0, ret (when JALR)

    opcode := io.instruction(6,0)
    rd := io.instruction(11,7)
    rs1 := io.instruction(19,15)

    when(opcode === "0b1101111"){   // JAL
        io.is_branch    := 1.B
        io.is_cond_branch := 0.B
        io.is_jump := 1.B
        io.imm := Cat(io.instruction(31), io.instruction(19,12), io.instruction(20), io.instruction(30,21)).asSInt().asUInt
        when(rd === 1.U){   // call
            io.is_call := 1.B
        }
    }.elsewhen(opcode === "0b1100111".U){   // JALR
        io.is_branch    := 1.B
        io.is_cond_branch := 0.B
        io.is_jump := 1.B
        io.imm := io.instruction(31,20).asSInt().asUInt
        when(rd === 1.U){   // call
            io.is_call := 1.B
        }.elsewhen(rd === 0.U && rs1 === 1.U &&  imm === 0.U){
            io.is_ret := 1.B
        }
    }.elsewhen(opcode === "0b1100011".U){   // cond
        io.is_cond_branch := 1.B
        io.is_branch    := 1.B
        io.is_jump := 0.B
        io.imm := Cat(io.instruction(31), io.instruction(7), io.instruction(30,25), io.instruction(11,8)).asSInt().asUInt
    }.otherwise{
        io.is_cond_branch := 0.B
        io.is_jump := 0.B
        io.is_branch    := 0.B
        io.imm := 0.U
    }


}

class uDecoder extends Module{
    /* 
    
    The purpose of the uDecoder is 3 fold:
        First is to steer branches in the more likely direction early before a misprediction forces a pipeline flush. For instance,
        consider the case where the PHT suggests taking a branch, but a BTB miss causes an ambiguous target address. The uDecoder
        will decode the branch and redirect the frontend to this target address, inserting only a single pipeline bubble.

        Second, it is responsible for pushing and popping off the RAS on the detection of Call and Ret instructions. 

        Third, it is responsible for deciding which instructions ultimately get queued to the frontend decoders. This means keeping
        track of misprediction, exceptions, redirections (by the uDecoder iteself) resulting from events such as case 1. It also means only appending the 
        second instruction when the first one is a branch if it is predicted not taken. 
    
     */

    val io = IO(new Decoder{

        // Instruction inputs
        val instruction_0                   = Input(UInt(32.W))
        val instruction_0_valid             = Input(Bool())

        val instruction_1                   = Input(UInt(32.W))
        val instruction_1_valid             = Input(Bool())

        // Fetch packet address
        val next_fetch_PC                   = Input(UInt(32.W))     // PC currently going into the I$
        val current_fetch_PC                = Input(UInt(32.W))     // PC that corresponds to current instructions 

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

    // Core idea: if PC_expected_valid === 1.B && PC_expected && PC_expected===PC_next
        // set next instruction to valid (send it to decode)
        // otherwise, ignore next instruction (mark it invalid), redirect, and try again.

    // TODO: what about exceptions and mispredictions?


    val next_instruction_valid = RegInit(UInt(1.W), 1.U)

    //////////////////////////
    // Instantiate Decoders //
    //////////////////////////

    val imm_0                 = RegInit(UInt(32.W), 0.U)
    val is_branch_0           = RegInit(Bool(), 0.U)
    val is_cond_branch_0      = RegInit(Bool(), 0.U)
    val is_jump_0             = RegInit(Bool(), 0.U)
    val is_call_0             = RegInit(Bool(), 0.U)
    val is_ret_0              = RegInit(Bool(), 0.U)

    val instruction_0_expected_PC       = Wire(UInt(32.W), 0.U)
    val instruction_0_expected_PC_valid = Wire(Bool())


    val imm_1                 = RegInit(UInt(32.W), 0.U)
    val is_branch_1           = RegInit(Bool(), 0.U)
    val is_cond_branch_1      = RegInit(Bool(), 0.U)
    val is_jump_1             = RegInit(Bool(), 0.U)
    val is_call_1             = RegInit(Bool(), 0.U)
    val is_ret_1              = RegInit(Bool(), 0.U)

    val instruction_1_expected_PC       = Wire(UInt(32.W), 0.U)
    val instruction_1_expected_PC_valid = Wire(Bool())



    val decoder0 = branchDecoder()  // Instruction 0 decoder

    decoder0.io.instruction := io.instruction_0
    imm_0               := decoder0.io.imm
    is_branch_0         := decoder0.io.is_branch
    is_cond_branch_0    := decoder0.io.is_cond_branch
    is_jump_0           := decoder0.io.is_jump
    is_call_0           := decoder0.io.is_call
    is_ret_0            := decoder0.io.is_ret


    val decoder1 = branchDecoder()  // Instruction 1 decoder

    decoder1.io.instruction := io.instruction_1
    imm_1                   := decoder1.io.imm
    is_branch_1             := decoder1.io.is_branch
    is_cond_branch_1        := decoder1.io.is_cond_branch
    is_jump_1               := decoder1.io.is_jump
    is_call_1               := decoder1.io.is_call
    is_ret_1                := decoder1.io.is_ret


    /////////////////////////
    // next_PC calculation //
    /////////////////////////

    // instruction[0]
    when(is_JAL_0 || is_cond_branch_0){ 
        instruction_0_expected_PC := current_fetch_PC + imm_0
        instruction_0_expected_PC_valid := 1.B
    }.elsewhen(is_JALR_0){
        instruction_0_expected_PC_valid := 0.B
    }
    .otherwise{
        instruction_0_expected_PC := current_fetch_PC + 4.U
        instruction_0_expected_PC_valid := 1.B
    }


    // instruction[1]
    when(is_JAL_1 || is_cond_branch_1){
        instruction_1_expected_PC := current_fetch_PC + imm_1
        instruction_1_expected_PC_valid := 1.B
    }.elsewhen(is_JALR_1){
        instruction_1_expected_PC_valid := 0.B
    }
    .otherwise{
        instruction_1_expected_PC := current_fetch_PC + 4.U
        instruction_1_expected_PC_valid := 1.B
    }

    ////////////////////////
    // next_PC validation //
    ////////////////////////

    when(instruction_0_expected_PC != instruction_1_actual_PC){         // when the expected PC of instruction 0 does not match the actual PC of instruction 1, @@
        //
    }
    
    .elsewhen(instruction_1_expected_PC != next_fetch_PC){   // when the expected PC of instruction 1 does not match the actual PC of the next fetch packet

    }.otherwise{    // All is good...

    }

    /////////
    // FSM //
    /////////

    when(/*input instructions are valid*/){
        next_instruction_valid := /* the wire checking if the next_PC makes sense*/
    }.elsewhen{
        next_instruction_valid := next_instruction_valid    // Do nothing (wait till inputs are valid)
    }


    // Assign outputs as valid
    // TODO


    // perform redirect as needed
    // TODO

    // control RAS as needed
    // TODO


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