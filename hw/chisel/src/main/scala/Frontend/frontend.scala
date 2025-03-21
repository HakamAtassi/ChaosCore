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

    val architecturalRegBits = log2Ceil(architecturalRegCount)
    val RATCheckpointBits    = log2Ceil(RATCheckpointCount)

    val portCount = getPortCount(coreParameters)

    val io = IO(new Bundle{
        // FLUSH //
        val flush = Flipped(ValidIO(new flush(coreParameters)))


        // DRAM CHANNELS //
        val memory_request                  =   Decoupled(new frontend_memory_request(coreParameters))
        val memory_response                 =   Flipped(Decoupled(new fetch_packet(coreParameters)))
        
        // COMMIT // 
        val commit                          =   Flipped(ValidIO(new commit(coreParameters)))

        // INSTRUCTION OUT //
        val renamed_decoded_fetch_packet    =   Decoupled(new decoded_fetch_packet(coreParameters))

        // UPDATE //
        val INT_producers                   =   Vec(INT_producer_count, Flipped(Decoupled(new FU_output(coreParameters))))
        val FP_producers                    =   if (coreConfig.contains("F")) Some(Vec(FP_producer_count, Flipped(Decoupled(new FU_output(coreParameters))))) else None

        val revert                          =   ValidIO(new revert(coreParameters))
    }); dontTouch(io)


    //////////////
    // Pipeline //////////////////////////////////////////////////////////////
    // Instruction fetch => Decoders => Queue => Rename => Backend/Allocate //
    //////////////////////////////////////////////////////////////////////////

    val instruction_fetch   = Module(new instruction_fetch_v3(coreParameters))
    val decoders            = Module(new fetch_packet_decoder(coreParameters))
    
    val instruction_queue   = Module(new Queue(new decoded_fetch_packet(coreParameters), 16, flow=false, hasFlush=true, useSyncReadMem=true))

    val INT_rename          = Module(new rename(data_type="Int")(coreParameters))

    val FP_rename           = if(coreConfig.contains("F")) Some(Module(new rename(data_type="Float")(coreParameters))) else None

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
    decoders.io.decoded_fetch_packet.ready := instruction_queue.io.enq.ready

    decoders.io.flush := io.flush

    
    ////////////
    // RENAME //
    ////////////
    instruction_queue.io.flush.get := flush


    ////////////
    // OUTPUT //
    ////////////




    ///////////////////////
    // INSTRUCTION QUEUE //
    ///////////////////////
    instruction_queue.io.enq         <> decoders.io.decoded_fetch_packet
    instruction_queue.io.enq.valid   := decoders.io.decoded_fetch_packet.valid 
    instruction_queue.io.flush.get   <> io.flush.valid
    

    INT_rename.io.FU_outputs           <>     io.INT_producers
    INT_rename.io.flush                <>     io.flush

    INT_rename.io.commit                    <>     io.commit
    INT_rename.io.commit.bits               <>     io.commit.bits.get_INT_view

    INT_rename.io.decoded_fetch_packet      <> instruction_queue.io.deq
    INT_rename.io.decoded_fetch_packet.bits <> instruction_queue.io.deq.bits.get_INT_view


    /////////////////////
    // FP rename stuff //
    /////////////////////
    // dumped here cuz I'm lazy
    if(coreConfig.contains("F")){
        FP_rename.get.io.FU_outputs           <>     io.FP_producers.get
        FP_rename.get.io.flush                <>     io.flush
        

        FP_rename.get.io.commit               <>     io.commit
        FP_rename.get.io.commit.bits          <>     io.commit.bits.get_FP_view

        FP_rename.get.io.decoded_fetch_packet <>     instruction_queue.io.deq

        FP_rename.get.io.decoded_fetch_packet           <> instruction_queue.io.deq
        FP_rename.get.io.decoded_fetch_packet.bits      := instruction_queue.io.deq.bits.get_FP_view
    }


    // merge output of renamers into a single renamed output fetch packet
    io.renamed_decoded_fetch_packet         <>     INT_rename.io.renamed_decoded_fetch_packet   // FIXME: temporary. fix this to account for FP_rename valid
    for(i <- 0 until fetchWidth){

        if(coreConfig.contains("F")){io.renamed_decoded_fetch_packet.ready      <>     FP_rename.get.io.renamed_decoded_fetch_packet.ready}

        if(coreConfig.contains("F")){
            when(FP_rename.get.io.renamed_decoded_fetch_packet.bits.decoded_instruction(i).needs_FPU){ // instruction is float...
                io.renamed_decoded_fetch_packet.bits.decoded_instruction(i)         <>     FP_rename.get.io.renamed_decoded_fetch_packet.bits.decoded_instruction(i)
            }.otherwise{    // instruction is non-float
                io.renamed_decoded_fetch_packet.bits.decoded_instruction(i)         <>     INT_rename.io.renamed_decoded_fetch_packet.bits.decoded_instruction(i)
            }
        }else{
            {   // instruction is non float (F not enabled)
                io.renamed_decoded_fetch_packet.bits.decoded_instruction(i)         <>     INT_rename.io.renamed_decoded_fetch_packet.bits.decoded_instruction(i)
            }
        }




    }


    // FIXME: remove this    
    if(coreConfig.contains("F")) io.FP_producers.get.foreach(_ := DontCare)


    

}