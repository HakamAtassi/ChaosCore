/* ------------------------------------------------------------------------------------
* Filename: frontend.scala
* Author: Hakam Atassi
* Date: Mar 12 2024
* Description: The components of the frontend that generate the stream of (raw) instructions
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



class frontend(parameters:Parameters) extends Module{
    import parameters._

    val dataSizeBits         = L1_instructionCacheBlockSizeBytes*8
    val physicalRegBits      = log2Ceil(physicalRegCount)
    val architecturalRegBits = log2Ceil(architecturalRegCount)
    val RATCheckpointBits    = log2Ceil(RATCheckpointCount)

    val portCount = getPortCount(parameters)

    val io = IO(new Bundle{

        // DRAM CHANNELS //
        val DRAM_resp                       =   Flipped(Decoupled(Input(new DRAM_resp(parameters))))  // FROM DRAM
        val DRAM_request                    =   Decoupled(new DRAM_request(parameters))               // TO DRAM

        // COMMIT // 
        val commit                          =   Input(Vec(commitWidth, new commit(parameters)))
        
        // PREDICTIONS //
        val predictions                     =   Vec(fetchWidth, Decoupled(new FTQ_entry(parameters)))

        // INSTRUCTION OUT //
        val renamed_decoded_fetch_packet    =   Decoupled(Vec(fetchWidth, new decoded_instruction(parameters)))

        // RD FREE //
        val FU_outputs                      =   Vec(portCount, Flipped(ValidIO(new FU_output(parameters))))





        /////////////////
        // OLD SIGNALS //
        /////////////////

        //val exception_PC                    =   Flipped(Decoupled(UInt(32.W)))                              // Input
        //val commit                          =   Flipped(Decoupled(new commit(parameters)))                  // Input
        //val ROB_commit                      =   Output(Vec(commitWidth, new ROB_entry(parameters)))
        // To backend
        //// Instruction input (commit)
        //// checkpoint (create/restore)
        //val create_checkpoint               = Input(Bool())
        //val active_checkpoint_value         = Output(UInt(RATCheckpointBits.W))   // What checkpoint is currently being used
        //val restore_checkpoint              = Input(Bool())                       // Restore to previous valid RAT
        //val restore_checkpoint_value        = Input(UInt(RATCheckpointBits.W))    // ...
        //val free_checkpoint                 = Input(Bool())                       // Normal branch commit. Just dealloc. checkpoint
        //val checkpoints_full                = Output(Bool())                      // No more checkpoints available
    })


    //io.exception_PC.ready      := 1.B
    //io.commit.ready            := 1.B

    val commit                          =  Wire(Decoupled(new commit(parameters)))
    commit := DontCare

    //////////////
    // Pipeline //////////////////////////////////////////////////////
    // Instruction fetch => Decoders => Renamer => Backend/Allocate //
    //////////////////////////////////////////////////////////////////

    val instruction_fetch   = Module(new instruction_fetch(parameters))
    val decoders            = Module(new fetch_packet_decoder(parameters)) // N wide decode
    val renamer             = Module(new renamer(parameters))


    ///////////////////////
    // INSTRUCTION FETCH //
    ///////////////////////

    val misprediction_commit = findMispredictionCommit(io.commit, parameters)

    //instruction_fetch.io.misprediction_PC.bits      :=   misprediction_commit.expected_PC //:=   io.commit.expected_PC
    //instruction_fetch.io.exception_PC.bits          :=   DontCare //io.exception_PC.bits
    //instruction_fetch.io.misprediction_PC.valid     :=   misprediction_commit.valid //io.commit.valid
    //instruction_fetch.io.exception_PC.valid         :=   DontCare //io.exception_PC.valid

    instruction_fetch.io.commit               <>   io.commit //io.commit.bits

    //commit.valid

    instruction_fetch.io.DRAM_resp            <>   io.DRAM_resp
    instruction_fetch.io.DRAM_request         <>   io.DRAM_request

    ///////////////
    // FTQ INPUT //
    ///////////////

    instruction_fetch.io.predictions <> io.predictions

    //////////////
    // DECODERS //
    //////////////

    decoders.io.fetch_packet <> instruction_fetch.io.fetch_packet


    ////////////
    // RENAME //
    ////////////

    renamer.io.decoded_fetch_packet <> decoders.io.decoded_fetch_packet


    renamer.io.FU_outputs           <>     io.FU_outputs

    renamer.io.create_checkpoint         :=     1.B //DontCare //io.create_checkpoint
    renamer.io.restore_checkpoint        :=     1.B //DontCare //io.restore_checkpoint
    renamer.io.restore_checkpoint_value  :=     1.B //DontCare //io.restore_checkpoint_value
    renamer.io.free_checkpoint           :=     1.B //DontCare //io.free_checkpoint

    //io.checkpoints_full                  :=     renamer.io.checkpoints_full
    //io.active_checkpoint_value           :=     renamer.io.active_checkpoint_value
    ////////////
    // OUTPUT //
    ////////////

    io.renamed_decoded_fetch_packet <> renamer.io.renamed_decoded_fetch_packet

}