/* ------------------------------------------------------------------------------------
* Filename: FPU.scala
* Author: Hakam Atassi
* Date: March 8 2025
* Description: The Core's monolithic floating point unit. 
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
import hardfloat._

//class FPU(FUParam:FUParams)(coreParameters:CoreParameters) extends Module{    // FIXME: needs FUParams...
class FPU(coreParameters:CoreParameters) extends Module{
    import coreParameters._
    //import FUParam._  // FIXME: needs this 
    val io = IO(new Bundle{
        // FLUSH
        val flush         =   Flipped(ValidIO(new flush(coreParameters)))

        // Input
        val FU_input      =   Flipped(Decoupled(new read_decoded_instruction(coreParameters)))
        
        // Output
        val FU_output     =   Decoupled(new FU_output(coreParameters))

        // partial_commit (for CSRs)
        val commit         =   Flipped(ValidIO(new commit(coreParameters)))

    }); dontTouch(io)

    // link to hardfloat docs
    // http://www.jhauser.us/arithmetic/HardFloat-1/doc/HardFloat-Verilog.html


    // need a scoreboarding mechanism of some kind

    // Float instructions: 
    // Load/Store. Full words only
    // Fused mul add, mul sub, neg/pos
    // flt add, flt sub
    // flt div
    // flt mul
    // flt sqr root
    // flt sign injection (normal, neg, xor)
    // flt min, max
    // flt convert to int (to int and uint)
    // flt move to float
    // flt equality
    // flt <, <=
    // flt classify

    // FP formats:
    // fN -> ieee FP32/64 format
    // recFN

    // FPU hardfloat HW
    // Adder: AddRecFN
    // Multiplier: MulRecFN
    // Fused-Multiply-Add: MulAddRecFN
    // Sqrt/Divide: DivSqrtFN_small (only div or square root in pipeline at once, but does both)
    // classify: classifyRecFN
    // Compare: CompareRecFN

    // RecFNToIn    // This lives in FP to Int
    // IntToRecFN   // This lives in a conversion supported ALU

    // Conversions:
    // (FN to Recoded FN -> recFNFromFN)    // input to modules (standard ieee FP to RecFN)
    // (Recoded FN to FN -> fNFromRecFN)    // output of modules (RecFN to standard ieee FP)

    ////////////
    // DECODE //
    ////////////
    val CSRRW               =  io.FU_input.bits.decoded_instruction.CSRRW



    ////////////////
    // SCOREBOARD //
    ////////////////
    // Instructions are only accepted if they are guaranteed to not cause contention on the output bus when they are done. 
    // For instance, dont accept an Add if one cycle from now, a multiply will be writing back (since that will cause output contention)




    /////////////////////
    // INIT FP Modules //
    /////////////////////

    // Make them all the same latency, like Rocket/Boom

    // standard IEEE 32 bit widths
//    val AddRecFN = Module(new AddRecFN(expWidth=8, sigWidth=24))    // 1 cycle
    //val MulRecFN = Module(new MulRecFN(expWidth=8 sigWidth=24))             // 
    //val MulAddRecFN = Module(new MulAddRecFN(expWidth=8 sigWidth=24))
    //val DivSqrtFN_small = Module(new DivSqrtFN_small(expWidth=8 sigWidth=24))
    //val classifyRecFN = Module(new classifyRecFN(expWidth=8 sigWidth=24))
    //val compare = Module(new CompareRecFN(expWidth=8 sigWidth=24))


    //AddRecFN.io         := DontCare
    //MulRecFN.io         := DontCare
    //MulAddRecFN.io      := DontCare
    //DivSqrtFN_small.io  := DontCare
    //classifyRecFN.io    := DontCare
    //compare.io          := DontCare

    
    // this should be optional
    // val RecFNToIn = Module(new RecFNToIN(expWidth=8, sigWidth=24, intWidth=32))


    //////////////////////////////
    // CONVERT FROM NN to RecFN //
    //////////////////////////////

    //val fNRS1 = recFNFromFN(RS1_data)
    //val fNRS2 = recFNFromFN(RS2_data)

 


    // Not a branch unit (all FUs share the same output channel)

    io := DontCare

    //FU_output.io.enq.valid                      :=  RegNext(ALU_input_valid)
    //FU_output.io.enq.bits.branch_valid          :=  0.B
    //FU_output.io.enq.bits.fetch_PC              :=  RegNext(io.FU_input.bits.fetch_PC)
    //FU_output.io.enq.bits.fetch_packet_index    :=  RegNext(io.FU_input.bits.decoded_instruction.packet_index)

    //// Actual Outputs
    //FU_output.io.enq.bits.PRD                   :=  RegNext(io.FU_input.bits.decoded_instruction.PRD)
    //FU_output.io.enq.bits.RD_valid              :=  RegNext(io.FU_input.bits.decoded_instruction.RD_valid)
    //FU_output.io.enq.bits.RD_data               :=  RegNext(arithmetic_result)

    //FU_output.io.enq.bits.MOB_index             :=  RegNext(io.FU_input.bits.decoded_instruction.MOB_index)
    //FU_output.io.enq.bits.address               :=  0.U
    //FU_output.io.enq.bits.ROB_index             :=  RegNext(io.FU_input.bits.decoded_instruction.ROB_index)


}



