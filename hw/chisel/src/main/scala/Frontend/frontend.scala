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

    val io = IO(new Bundle{

        val misprediction_PC                =   Flipped(Decoupled(UInt(32.W)))                              // Input
        val exception_PC                    =   Flipped(Decoupled(UInt(32.W)))                              // Input
        val commit                          =   Flipped(Decoupled(new commit(fetchWidth=fetchWidth)))       // Input

        // From DRAM
        val DRAM_resp                       =   Flipped(Decoupled(Input(new DRAM_resp())))
        
        // To DRAM
        val DRAM_request                    =   Decoupled(new DRAM_request())

        // To backend
        val renamed_decoded_fetch_packet    =   Decoupled(Vec(fetchWidth, new decoded_instruction(coreConfig=coreConfig, fetchWidth=fetchWidth, ROBEntires=ROBEntires, physicalRegCount=physicalRegCount)))

        //// Instruction input (commit)
        val commit_RD                 =   Input(Vec(fetchWidth, UInt(physicalRegBits.W))) // From RAT
        val commit_RD_valid           =   Input(Vec(fetchWidth, Bool())) // From RAT

        //// checkpoint (create/restore)
        val create_checkpoint         = Input(Bool())
        val active_checkpoint_value   = Output(UInt(RATCheckpointBits.W))   // What checkpoint is currently being used

        val restore_checkpoint        = Input(Bool())                       // Restore to previous valid RAT
        val restore_checkpoint_value  = Input(UInt(RATCheckpointBits.W))    // ...
        
        val free_checkpoint           = Input(Bool())                       // Normal branch commit. Just dealloc. checkpoint

        val checkpoints_full          = Output(Bool())                      // No more checkpoints available
    })


    io.misprediction_PC.ready  := 1.B
    io.exception_PC.ready      := 1.B
    io.commit.ready            := 1.B


    //////////////
    // Pipeline //////////////////////////////////////////////////////
    // Instruction fetch => Decoders => Renamer => Backend/Allocate //
    //////////////////////////////////////////////////////////////////

    val instruction_fetch = Module(new instruction_fetch(parameters))
    val decoders = Module(new fetch_packet_decoder(parameters)) // N wide decode
    val renamer = Module(new renamer(parameters))

    ///////////////////////
    // INSTRUCTION FETCH //
    ///////////////////////


    instruction_fetch.io.misprediction_PC.bits  :=   io.misprediction_PC.bits
    instruction_fetch.io.exception_PC.bits      :=   io.exception_PC.bits
    instruction_fetch.io.DRAM_resp.bits         :=   io.DRAM_resp.bits
    instruction_fetch.io.commit.bits            :=   io.commit.bits

    instruction_fetch.io.misprediction_PC.valid  :=   io.misprediction_PC.valid
    instruction_fetch.io.exception_PC.valid      :=   io.exception_PC.valid
    instruction_fetch.io.DRAM_resp.valid         :=   io.DRAM_resp.valid

    instruction_fetch.io.commit.valid            :=   io.commit.valid

    io.DRAM_resp.ready := instruction_fetch.io.DRAM_resp.ready
    instruction_fetch.io.DRAM_request.ready         :=   io.DRAM_request.ready

    io.DRAM_request.bits    := instruction_fetch.io.DRAM_request.bits
    io.DRAM_request.valid   := instruction_fetch.io.DRAM_request.valid

    instruction_fetch.io.fetch_packet.ready := decoders.io.fetch_packet.ready

    //////////////
    // DECODERS //
    //////////////


    decoders.io.fetch_packet.bits := instruction_fetch.io.fetch_packet.bits

    decoders.io.fetch_packet.valid := instruction_fetch.io.fetch_packet.valid

    decoders.io.decoded_fetch_packet.ready:= 1.B


    ////////////
    // RENAME //
    ////////////

    renamer.io.decoded_fetch_packet.bits := decoders.io.decoded_fetch_packet.bits
    renamer.io.decoded_fetch_packet.valid := decoders.io.decoded_fetch_packet.valid
    renamer.io.renamed_decoded_fetch_packet.ready := 1.B

    renamer.io.commit_RD                 :=     io.commit_RD
    renamer.io.commit_RD_valid           :=     io.commit_RD_valid
    renamer.io.create_checkpoint         :=     io.create_checkpoint
    renamer.io.restore_checkpoint        :=     io.restore_checkpoint
    renamer.io.restore_checkpoint_value  :=     io.restore_checkpoint_value
    renamer.io.free_checkpoint           :=     io.free_checkpoint

    io.checkpoints_full                  :=     renamer.io.checkpoints_full
    io.active_checkpoint_value           :=     renamer.io.active_checkpoint_value
    ////////////
    // OUTPUT //
    ////////////

    io.renamed_decoded_fetch_packet.bits := renamer.io.renamed_decoded_fetch_packet.bits
    io.renamed_decoded_fetch_packet.valid := renamer.io.renamed_decoded_fetch_packet.valid

}