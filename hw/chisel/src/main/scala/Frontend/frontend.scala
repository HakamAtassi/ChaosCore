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

    val dataSizeBits                = L1_instructionCacheBlockSizeBytes*8

    val io = IO(new Bundle{

        val misprediction_PC  =   Flipped(Decoupled(UInt(32.W)))                              // Input
        val exception_PC      =   Flipped(Decoupled(UInt(32.W)))                              // Input
        val dram_data         =   Flipped(Decoupled(UInt(dataSizeBits.W)))                    // inputs from DRAM
        val commit            =   Flipped(Decoupled(new commit(fetchWidth=fetchWidth)))       // Input
        
        // outputs
        val cache_addr        =   Decoupled(UInt(32.W))                                       // outputs to DRAM

        val renamed_decoded_fetch_packet =  Decoupled(Vec(fetchWidth, new decoded_instruction(coreConfig=coreConfig, fetchWidth=fetchWidth, ROBEntires=ROBEntires, physicalRegCount=physicalRegCount)))



        // outputs to DRAM

        // inputs from DRAM

        // outputs to cache

    })

    io.renamed_decoded_fetch_packet.bits := DontCare
    io.renamed_decoded_fetch_packet.valid := DontCare

    io.misprediction_PC.ready  := DontCare
    io.exception_PC.ready      := DontCare
    io.dram_data.ready         := DontCare
    io.commit.ready            := DontCare

    io.cache_addr := DontCare
    io.cache_addr.valid := DontCare

    //////////////
    // Pipeline //////////////////////////////////////////////////////
    // Instruction fetch => Decoders => Renamer => Backend/Allocate //
    //////////////////////////////////////////////////////////////////

    ///////////////////////
    // INSTRUCTION FETCH //
    ///////////////////////


    val instruction_fetch = Module(new instruction_fetch(parameters))

    instruction_fetch.io.misprediction_PC.bits  :=   io.misprediction_PC.bits
    instruction_fetch.io.exception_PC.bits      :=   io.exception_PC.bits
    instruction_fetch.io.dram_data.bits         :=   io.dram_data.bits
    instruction_fetch.io.commit.bits            :=   io.commit.bits

    instruction_fetch.io.misprediction_PC.valid  :=   io.misprediction_PC.valid
    instruction_fetch.io.exception_PC.valid      :=   io.exception_PC.valid
    instruction_fetch.io.dram_data.valid         :=   io.dram_data.valid
    instruction_fetch.io.commit.valid            :=   io.commit.valid

    instruction_fetch.io.cache_addr.ready := DontCare
    instruction_fetch.io.fetch_packet.ready := DontCare

    //////////////
    // DECODERS //
    //////////////

    val decoders = Module(new fetch_packet_decoder(parameters)) // N wide decode

    decoders.io.fetch_packet.bits := instruction_fetch.io.fetch_packet.bits

    decoders.io.fetch_packet.valid := DontCare

    decoders.io.decoded_fetch_packet.ready:= DontCare


    ////////////
    // RENAME //
    ////////////

    val renamer = Module(new renamer(parameters))

    renamer.io.decoded_fetch_packet.bits := decoders.io.decoded_fetch_packet.bits
    renamer.io.decoded_fetch_packet.valid := decoders.io.decoded_fetch_packet.valid
    renamer.io.renamed_decoded_fetch_packet.ready := DontCare

    renamer.io.commit_RD                 :=     DontCare
    renamer.io.commit_RD_valid           :=     DontCare
    renamer.io.create_checkpoint         :=     DontCare
    renamer.io.restore_checkpoint        :=     DontCare
    renamer.io.restore_checkpoint_value  :=     DontCare
    renamer.io.free_checkpoint           :=     DontCare

    //active_checkpoint_value   = Output(UInt(RATCheckpointBits.W))   // What checkpoint is currently being used
    //checkpoints_full          = Output(Bool())                      // No more checkpoints available




    ////////////
    // OUTPUT //
    ////////////

    io.renamed_decoded_fetch_packet.bits := renamer.io.renamed_decoded_fetch_packet.bits
    io.renamed_decoded_fetch_packet.valid := renamer.io.renamed_decoded_fetch_packet.valid

}