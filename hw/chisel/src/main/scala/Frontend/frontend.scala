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


class frontend(coreParameters:CoreParameters) extends Module{
    import coreParameters._

    val dataSizeBits         = L1_instructionCacheBlockSizeBytes*8
    val architecturalRegBits = log2Ceil(architecturalRegCount)
    val RATCheckpointBits    = log2Ceil(RATCheckpointCount)

    val portCount = getPortCount(coreParameters)

    val io = IO(new Bundle{
        // FLUSH //
        val flush                           =   Input(Bool())

        // DRAM CHANNELS //
        val memory_request                  =   Decoupled(new frontend_memory_request(coreParameters))
        val memory_response                 =   Flipped(Decoupled(new fetch_packet(coreParameters)))
        
        // COMMIT // 
        val commit                          =   Flipped(ValidIO(new commit(coreParameters)))
        
        // PREDICTIONS //
        val predictions                     =   Decoupled(new FTQ_entry(coreParameters))

        // INSTRUCTION OUT //
        val renamed_decoded_fetch_packet    =   Decoupled(new decoded_fetch_packet(coreParameters))

        // RD FREE //
        val FU_outputs                      =   Vec(portCount, Flipped(ValidIO(new FU_output(coreParameters))))

        val revert                          =   ValidIO(new revert(coreParameters))
    })


    //////////////
    // Pipeline //////////////////////////////////////////////////////////////
    // Instruction fetch => Decoders => Queue => Rename => Backend/Allocate //
    //////////////////////////////////////////////////////////////////////////

    val instruction_fetch   = Module(new instruction_fetch(coreParameters))
    val decoders            = Module(new fetch_packet_decoder(coreParameters))
    
    val instruction_queue   = Module(new Queue(new decoded_fetch_packet(coreParameters), 16, flow=true, hasFlush=true, useSyncReadMem=true))
    val FTQ_queue           = Module(new Queue(new FTQ_entry(coreParameters), 16, flow=true, hasFlush=true, useSyncReadMem=true))

    val rename              = Module(new rename(coreParameters))

    val flush = io.commit.bits.is_misprediction && io.commit.valid


    io.revert <> instruction_fetch.io.revert


    ///////////////////////
    // INSTRUCTION FETCH //
    ///////////////////////

    instruction_fetch.io.commit               <>   io.commit
    instruction_fetch.io.memory_response      <>   io.memory_response
    instruction_fetch.io.memory_request       <>   io.memory_request

    instruction_fetch.io.flush                :=   io.flush


    //////////////
    // DECODERS //
    //////////////
    decoders.io.fetch_packet <> instruction_fetch.io.fetch_packet
    decoders.io.decoded_fetch_packet.ready := FTQ_queue.io.enq.ready && instruction_queue.io.enq.ready

    ///////////////
    // FTQ INPUT //
    ///////////////
    decoders.io.flush := io.flush
    decoders.io.predictions_in <> instruction_fetch.io.predictions

    ///////////////
    // FTQ QUEUE //
    ///////////////
    FTQ_queue.io.enq <> decoders.io.predictions_out
    FTQ_queue.io.enq.valid := decoders.io.predictions_out.valid && instruction_queue.io.enq.ready
    FTQ_queue.io.flush.get := io.flush 
    
    ////////////
    // RENAME //
    ////////////
    instruction_queue.io.flush.get := flush

    rename.io.FU_outputs           <>     io.FU_outputs
    rename.io.flush                <>     io.flush
    rename.io.commit               <>     io.commit
    rename.io.predictions_in       <>     FTQ_queue.io.deq
    rename.io.predictions_out      <>     io.predictions

    ////////////
    // OUTPUT //
    ////////////
    io.renamed_decoded_fetch_packet <> rename.io.renamed_decoded_fetch_packet


    ///////////////////////
    // INSTRUCTION QUEUE //
    ///////////////////////
    instruction_queue.io.enq         <> decoders.io.decoded_fetch_packet
    instruction_queue.io.enq.valid   := decoders.io.decoded_fetch_packet.valid && FTQ_queue.io.enq.ready
    instruction_queue.io.flush.get   <> io.flush


    rename.io.decoded_fetch_packet <> instruction_queue.io.deq


    

}