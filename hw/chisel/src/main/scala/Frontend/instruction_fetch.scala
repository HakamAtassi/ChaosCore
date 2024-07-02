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

class Q[T <: Data](dataType: T, depth: Int = 16) extends Module{
  val io = IO(new Bundle {
    //val data_in    = Input(dataType)         // input data (bundle)
    //val wr_en      = Input(Bool())           // write element
    //val rd_en      = Input(Bool())           // read element

    val in         = Flipped(Decoupled(dataType)) 
    val out        = Decoupled(dataType)

    //val data_out   = Output(dataType)        // output data (bundle)
    //val full       = Output(Bool())          // queue full
    //val empty      = Output(Bool())          // queue empty

    val flush      = Input(Bool())           // Clear entire queue
  })

  val queue = Module(new Queue(dataType, depth, flow=true, hasFlush=true, useSyncReadMem=true))

  // Connect inputs
  //queue.io.enq.valid := io.wr_en
  //queue.io.enq.bits := io.data_in
  //queue.io.deq.ready := io.rd_en

  queue.io.enq <> io.in
  queue.io.deq <> io.out
  queue.io.flush.get <> io.flush

  // Connect outputs
  //io.data_out := queue.io.deq.bits
  //io.full :=  !queue.io.enq.ready
  //io.empty := !queue.io.deq.valid

}

class instruction_fetch(parameters:Parameters) extends Module{
  import parameters._

    val dataSizeBits                = L1_instructionCacheBlockSizeBytes*8

    val io = IO(new Bundle{
        // FLUSH
        val flush                 =   Input(Bool())
        val commit                =   Flipped(ValidIO(new commit(parameters)))
        val memory_response       =   Flipped(Decoupled(new fetch_packet(parameters)))               // TO CPU

        val memory_request        =   Decoupled(new memory_request(parameters))
        val fetch_packet          =   Decoupled(new fetch_packet(parameters))                     // Fetch packet result (To Decoders)
        val predictions           =   Decoupled(new FTQ_entry(parameters))

        val revert                =   ValidIO(new revert(parameters))
    })

    /////////////
    // Modules //
    /////////////
    val bp                  = Module(new BP(parameters))
    val predecoder          = Module(new predecoder(parameters))
    val PC_gen              = Module(new PC_gen(parameters))

    ////////////
    // Queues //
    ////////////
    val instruction_Q   =   Module(new Q(new fetch_packet(parameters), depth = 16))              // Instantiate queue with fetch_packet data type
    val PC_Q            =   Module(new Q(new memory_request(parameters), depth = 16))            // Queue of predicted PCs
    val BTB_Q           =   Module(new Q(new prediction(parameters), depth = 16))                // Queue of BTB responses

    ///////////////////////
    // INSTRUCTION QUEUE //
    ///////////////////////
    instruction_Q.io.in           <> io.memory_response
    instruction_Q.io.out          <> predecoder.io.fetch_packet
    instruction_Q.io.out.ready    := (BTB_Q.io.out.valid && predecoder.io.fetch_packet.ready)


    ////////////////
    // PREDECODER //
    ////////////////
    predecoder.io.prediction            <> BTB_Q.io.out
    predecoder.io.fetch_packet          <> instruction_Q.io.out
    predecoder.io.RAS_read              <> bp.io.RAS_read
    predecoder.io.final_fetch_packet    <> io.fetch_packet 
    predecoder.io.predictions           <> io.predictions
    predecoder.io.commit                <> io.commit
    
    //////////////
    // PC ARBIT //
    //////////////
    PC_gen.io.commit            <> io.commit
    PC_gen.io.prediction        <> bp.io.prediction
    PC_gen.io.RAS_read          <> bp.io.RAS_read
    PC_gen.io.revert            <> predecoder.io.revert
    PC_gen.io.PC_next.ready     := bp.io.predict.ready && PC_Q.io.in.ready

    ///////////////
    // BTB QUEUE //
    ///////////////
    BTB_Q.io.in                   <> bp.io.prediction
    BTB_Q.io.out                  <> predecoder.io.prediction
    BTB_Q.io.out.ready            := (instruction_Q.io.out.valid && predecoder.io.prediction.ready)
    
    ////////
    // BP //
    ////////
    bp.io.commit            <>  io.commit
    bp.io.predict           <>  PC_Q.io.out
    bp.io.RAS_update        <>  predecoder.io.RAS_update
    bp.io.GHR               <>  predecoder.io.GHR
    bp.io.predict.valid     :=  PC_gen.io.PC_next.fire

    //////////////
    // PC Queue //
    //////////////
    PC_Q.io.in              <> PC_gen.io.PC_next
    PC_Q.io.out             <> io.memory_request
    PC_Q.io.in.valid        := PC_gen.io.PC_next.valid && bp.io.predict.ready

    /////////////
    // FLUSHES //
    /////////////
    BTB_Q.io.flush                :=  io.flush || io.revert.valid
    PC_Q.io.flush                 :=  io.flush || io.revert.valid
    instruction_Q.io.flush        :=  io.flush || io.revert.valid
    bp.io.flush                   :=  io.flush || io.revert.valid
    predecoder.io.flush           :=  io.flush // NO REVERT HERE 

    /////////////
    // OUTPUTS //
    /////////////
    io.fetch_packet         <> predecoder.io.final_fetch_packet
    io.revert := predecoder.io.revert
}