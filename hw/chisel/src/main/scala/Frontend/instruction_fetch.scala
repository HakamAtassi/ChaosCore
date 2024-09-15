/* ------------------------------------------------------------------------------------
* Filename: instruction_fetch.scala
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

class instruction_fetch(coreParameters:CoreParameters) extends Module{
  import coreParameters._

    val dataSizeBits                = L1_cacheLineSizeBytes*8

    val io = IO(new Bundle{
        // FLUSH
        val flush                 =   Input(Bool())
        val commit                =   Flipped(ValidIO(new commit(coreParameters)))
        val memory_response       =   Flipped(Decoupled(new fetch_packet(coreParameters)))               // TO CPU

        val memory_request        =   Decoupled(new frontend_memory_request(coreParameters))
        val fetch_packet          =   Decoupled(new fetch_packet(coreParameters))                     // Fetch packet result (To Decoders)

        val revert                =   ValidIO(new revert(coreParameters))
    })

    /////////////
    // Modules //
    /////////////
    val bp                  = Module(new BP(coreParameters))
    val predecoder          = Module(new predecoder(coreParameters))
    val PC_gen              = Module(new PC_gen(coreParameters))

    ////////////
    // Queues //
    ////////////
    val instruction_Q   =   Module(new Queue(new fetch_packet(coreParameters), 16, flow=true, hasFlush=true, useSyncReadMem=true))
    val PC_Q            =   Module(new Queue(new frontend_memory_request(coreParameters), 16, flow=true, hasFlush=true, useSyncReadMem=true))
    val BTB_Q           =   Module(new Queue(new prediction(coreParameters), 16, flow=true, hasFlush=true, useSyncReadMem=true))

    ///////////////////////
    // INSTRUCTION QUEUE //
    ///////////////////////
    instruction_Q.io.enq          <> io.memory_response
    instruction_Q.io.deq          <> predecoder.io.fetch_packet
    instruction_Q.io.deq.ready    := (predecoder.io.prediction.ready && predecoder.io.fetch_packet.ready && BTB_Q.io.deq.valid)


    ////////////////
    // PREDECODER //
    ////////////////
    predecoder.io.prediction            <> BTB_Q.io.deq
    predecoder.io.final_fetch_packet    <> io.fetch_packet 
    predecoder.io.fetch_packet          <> instruction_Q.io.deq
    predecoder.io.RAS_read              <> bp.io.RAS_read
    predecoder.io.commit                <> io.commit
    
    //////////////
    // PC ARBIT //
    //////////////
    PC_gen.io.commit            <> io.commit
    PC_gen.io.prediction        <> bp.io.prediction
    PC_gen.io.RAS_read          <> bp.io.RAS_read
    PC_gen.io.revert            <> predecoder.io.revert
    PC_gen.io.PC_next.ready     := bp.io.predict.ready && PC_Q.io.enq.ready

    ///////////////
    // BTB QUEUE //
    ///////////////
    BTB_Q.io.enq                  <> bp.io.prediction
    BTB_Q.io.deq                  <> predecoder.io.prediction
    BTB_Q.io.deq.ready            := (predecoder.io.prediction.ready && predecoder.io.fetch_packet.ready && instruction_Q.io.deq.valid)
    
    ////////
    // BP //
    ////////
    bp.io.commit            <>  io.commit
    bp.io.predict           <>  PC_gen.io.PC_next//PC_Q.io.deq
    bp.io.RAS_update        <>  predecoder.io.RAS_update
    bp.io.GHR               <>  predecoder.io.GHR
    bp.io.predict.valid     :=  PC_gen.io.PC_next.fire

    //////////////
    // PC Queue //
    //////////////
    PC_Q.io.enq              <> PC_gen.io.PC_next
    PC_Q.io.deq              <> io.memory_request
    PC_Q.io.enq.valid        := PC_gen.io.PC_next.valid && bp.io.predict.ready

    /////////////
    // FLUSHES //
    /////////////
    BTB_Q.io.flush.get                :=  io.flush || io.revert.valid
    PC_Q.io.flush.get                 :=  io.flush || io.revert.valid
    instruction_Q.io.flush.get        :=  io.flush || io.revert.valid
    bp.io.flush                       :=  io.flush || io.revert.valid
    predecoder.io.flush               :=  io.flush // NO REVERT HERE 

    /////////////
    // OUTPUTS //
    /////////////
    io.fetch_packet         <> predecoder.io.final_fetch_packet
    io.revert := predecoder.io.revert
}