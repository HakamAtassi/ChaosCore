/* ------------------------------------------------------------------------------------
* Filename: FU.scala
* Author: Hakam Atassi
* Date: May 23 2024
* Description: The Core Functional Units
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

package ChaosCore

import chisel3._

import chisel3.util._


class FU(FUParam:FUParams)(coreParameters:CoreParameters) extends Module{
    import InstructionType._
    import FUParam._
    val io = IO(new Bundle{
        // FLUSH
        val flush         =   Flipped(ValidIO(new flush(coreParameters)))

        // Input
        val FU_input      =   Flipped(Decoupled(new read_decoded_instruction(coreParameters)))
        
        // Output
        val FU_output     =   Decoupled(new FU_output(coreParameters))

        // partial_commit (for CSRs)
        val commit          =   Flipped(ValidIO(new commit(coreParameters)))

    }); dontTouch(io)


    val CSR_port = if (FUParam.supportsCSRs) Some(IO(Output(new CSR_out(coreParameters)))) else None

    val irq_software_i                      = if (FUParam.supportsCSRs) Some(IO(Input(Bool()))) else None
    val irq_timer_i                         = if (FUParam.supportsCSRs) Some(IO(Input(Bool()))) else None
    val irq_external_i                      = if (FUParam.supportsCSRs) Some(IO(Input(Bool()))) else None
    val debug_req_i                         = if (FUParam.supportsCSRs) Some(IO(Input(Bool()))) else None
    val irq_nm_i                            = if (FUParam.supportsCSRs) Some(IO(Input(Bool()))) else None



    val ALU             = if (supportsInt)                  Some(Module(new ALU(coreParameters))) else None
    val branch_unit     = if (supportsBranch)               Some(Module(new branch_unit(coreParameters))) else None
    val AGU             = if (supportsAddressGeneration)    Some(Module(new AGU(coreParameters))) else None
    val mul             = if (supportsMult)                 Some(Module(new mul_unit(coreParameters))) else None   
    val div             = if (supportsDiv)                  Some(Module(new div_unit(coreParameters))) else None
    val CSR             = if (supportsCSRs)                 Some(Module(new CSR_FU(coreParameters))) else None     

    // assign inputs
    ALU.foreach         {ALU => ALU.io.FU_input                     <> io.FU_input }
    branch_unit.foreach {branch_unit => branch_unit.io.FU_input     <> io.FU_input }
    AGU.foreach         { AGU => AGU.io.FU_input                    <> io.FU_input }
    mul.foreach         { mul => mul.io.FU_input                    <> io.FU_input }
    div.foreach         { div => div.io.FU_input                    <> io.FU_input }
    CSR.foreach         { CSR => CSR.io.FU_input                    <> io.FU_input }

    // assign inputs

    ALU.foreach         {ALU => ALU.io.commit                     <> io.commit }
    branch_unit.foreach {branch_unit => branch_unit.io.commit     <> io.commit }
    AGU.foreach         { AGU => AGU.io.commit                    <> io.commit }
    mul.foreach         { mul => mul.io.commit                    <> io.commit }
    div.foreach         { div => div.io.commit                    <> io.commit }
    CSR.foreach         { CSR => CSR.io.commit                    <> io.commit }
    

    // route outputs
    io.FU_output := DontCare

    val FU_outputs = Seq(
        ALU.map(_.io.FU_output),
        branch_unit.map(_.io.FU_output),
        AGU.map(_.io.FU_output),
        mul.map(_.io.FU_output),
        div.map(_.io.FU_output),
        CSR.map(_.io.FU_output)
    ).flatten

    val arbiter = Module(new Arbiter(chiselTypeOf(io.FU_output.bits), FU_outputs.length))

    FU_outputs.zip(arbiter.io.in).foreach { case (fu_output, arb_input) =>
        fu_output <> arb_input
    }

    // Connect arbiter output to io.FU_output
    arbiter.io.out <> io.FU_output

    // Handle CSR-specific connections (unchanged)
    if (CSR.isDefined) {
        CSR_port.get <> CSR.get.CSR_port
        irq_software_i.get <> CSR.get.irq_software_i
        irq_timer_i.get <> CSR.get.irq_timer_i
        irq_external_i.get <> CSR.get.irq_external_i
        debug_req_i.get <> CSR.get.debug_req_i
        irq_nm_i.get <> CSR.get.irq_nm_i
    }



    //////////////////
    // ASSIGN FLUSH //
    //////////////////
    if(ALU.isDefined){ALU.get.io.flush                  <> io.flush}
    if(branch_unit.isDefined){branch_unit.get.io.flush  <> io.flush}
    if(AGU.isDefined){AGU.get.io.flush                  <> io.flush}
    if(mul.isDefined){mul.get.io.flush                  <> io.flush}
    if(div.isDefined){div.get.io.flush                  <> io.flush}
    if(CSR.isDefined){CSR.get.io.flush                  <> io.flush}

}

