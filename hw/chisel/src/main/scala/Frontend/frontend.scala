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
    val architecturalRegBits = log2Ceil(architecturalRegCount)
    val RATCheckpointBits    = log2Ceil(RATCheckpointCount)

    val portCount = getPortCount(parameters)

    val io = IO(new Bundle{
        // FLUSH //
        val flush                           =   Input(Bool())

        // DRAM CHANNELS //
        val memory_request                  =   Decoupled(new memory_request(parameters))
        val memory_response                 =   Flipped(Decoupled(new fetch_packet(parameters)))
        
        // COMMIT // 
        val commit                          =   Flipped(ValidIO(new commit(parameters)))
        
        // PREDICTIONS //
        val predictions                     =   Decoupled(new FTQ_entry(parameters))

        // INSTRUCTION OUT //
        val renamed_decoded_fetch_packet    =   Decoupled(new decoded_fetch_packet(parameters))

        // RD FREE //
        val FU_outputs                      =   Vec(portCount, Flipped(ValidIO(new FU_output(parameters))))



        val revert                = ValidIO(new revert(parameters))
    })


    //////////////
    // Pipeline //////////////////////////////////////////////////////////////
    // Instruction fetch => Decoders => Queue => Rename => Backend/Allocate //
    //////////////////////////////////////////////////////////////////////////

    val instruction_fetch   = Module(new instruction_fetch(parameters))
    val decoders            = Module(new fetch_packet_decoder(parameters))

    val instruction_queue   = Module(new Q(new decoded_fetch_packet(parameters), depth = 16))
    val FTQ_queue           = Module(new Q(new FTQ_entry(parameters), depth = 16))

    val rename              = Module(new rename(parameters))

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
    decoders.io.decoded_fetch_packet.ready := FTQ_queue.io.in.ready && instruction_queue.io.in.ready





    ///////////////
    // FTQ INPUT //
    ///////////////
    decoders.io.predictions_in <> instruction_fetch.io.predictions
    decoders.io.flush := io.flush

    
    ////////////
    // RENAME //
    ////////////


    instruction_queue.io.flush := flush


    rename.io.FU_outputs           <>     io.FU_outputs
    rename.io.flush                <>     io.flush
    rename.io.commit               <>     io.commit

    ////////////
    // OUTPUT //
    ////////////

    io.renamed_decoded_fetch_packet <> rename.io.renamed_decoded_fetch_packet


    ///////////////
    // FTQ QUEUE //
    ///////////////
    FTQ_queue.io.in <> decoders.io.predictions_out
    FTQ_queue.io.in.valid := decoders.io.predictions_out.valid && instruction_queue.io.in.ready

    FTQ_queue.io.out <> io.predictions
    FTQ_queue.io.flush := io.flush 

    ///////////////////////
    // INSTRUCTION QUEUE //
    ///////////////////////
    instruction_queue.io.in         <> decoders.io.decoded_fetch_packet
    instruction_queue.io.in.valid   := decoders.io.decoded_fetch_packet.valid && FTQ_queue.io.in.ready
    instruction_queue.io.flush      <> io.flush


    rename.io.decoded_fetch_packet <> instruction_queue.io.out


    

}