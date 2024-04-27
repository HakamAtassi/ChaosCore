/* ------------------------------------------------------------------------------------
* Filename: frontend.scala
* Author: Hakam Atassi
* Date: Mar 12 2024
* Description: The fetch & pre-decode portions of the cores frontend.
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

import chisel3._
import chisel3.util._

class Q[T <: Data](dataType: T, depth: Int = 16) extends Module {
  val io = IO(new Bundle {
    val data_in    = Input(dataType)         // input data (bundle)
    val wr_en      = Input(Bool())           // write element
    val rd_en      = Input(Bool())           // read element
    val clear      = Input(Bool())           // Clear entire queue
    val data_out   = Output(dataType)        // output data (bundle)
    val full       = Output(Bool())          // queue full
    val empty      = Output(Bool())          // queue empty
  })

  val queue = Module(new Queue(dataType, depth))

  // Connect inputs
  queue.io.enq.valid := io.wr_en
  queue.io.enq.bits := io.data_in
  queue.io.deq.ready := io.rd_en

  // Connect outputs
  io.data_out := queue.io.deq.bits
  io.full := queue.io.enq.ready && !io.wr_en
  io.empty := queue.io.deq.valid && !io.rd_en

  // Reset logic
  when(io.clear) {
    queue.reset := true.B
  }.otherwise {
    queue.reset := false.B
  }
}


class Frontend(GHRWidth:Int=16, fetchWidth:Int=4, RASEntries:Int=128, BTBEntries:Int=4096, L1_instructionCacheWays:Int=2, 
               L1_instructionCacheSets:Int=64, L1_instructionCacheBlockSizeBytes:Int=32) extends Module{

    val io = IO(new Bundle{
        // Inputs: A series of PCs and control signals
        val misprediction_PC = Flipped(Decoupled(UInt(32.W)))   // Input
        val exception_PC     = Flipped(Decoupled(UInt(32.W)))   // Input
        
        val commit          =   new commit(fetchWidth=fetchWidth)                           // Input
        val mispredict      =   new mispredict(GHRWidth=GHRWidth, RASEntries=RASEntries)    //

        // Outputs: Validated Fetch Packet + Prediction information
        //val fetch_packet = Output(new fetch_packet(fetchWidth=fetchWidth))
        //val fetch_packet = Flipped(Decoupled(32.W))   //TODO: needs to output prediction information as well 

        // TODO: need to add dram access here
    })

    /////////////
    // Modules //
    /////////////
    //val instruction_cache   = Module(new L1_instruction_cache(fetchWidth=fetchWidth, ways=L1_instructionCacheWays, sets=L1_instructionCacheSets, blockSizeBytes=L1_instructionCacheBlockSizeBytes))
    val bp                  = Module(new BP(GHRWidth=GHRWidth, fetchWidth=fetchWidth, RASEntries=RASEntries, BTBEntries=BTBEntries))
    //val predecoder          = Module(new decode_validate(fetchWidth=fetchWidth, GHRWidth=16, RASEntries=128))

    ////////////
    // Queues //
    ////////////
    //val instruction_Q   =   Module(new Q(new fetch_packet(width=fetchWidth), depth = 16))               // Instantiate queue with fetch_packet data type
    //val PC_Q            =   Module(new Q(UInt(32.W)))                                                   // Queue of predicted PCs
    //val BTB_Q           =   Module(new Q(new prediction(fetchWidth=fetchWidth, GHRWidth=GHRWidth)))       // Queue of BTB responses

    ///////////
    // Wires //
    ///////////
    //val predict_PC     =   Wire(Decoupled(UInt(32.W)))
    //val predict_PC  = Wire(UInt(32.W))

    
    ////////////////////
    // PC ARBITRATION //
    ////////////////////

    //predict_PC.bits  := 0.U
    //predict_PC.valid := 0.B
    //predict_PC.ready := 0.B


    //////////
    // PC_Q //
    //////////

    //PC_Q.io.wr_en       :=  predict_PC.valid         // Write to PC_Q whenever the PC is valid
    //PC_Q.io.data_in     :=  predict_PC.bits
    //PC_Q.io.rd_en       :=  instruction_cache.io.cpu_addr.ready  // Read from PC_Q whenever I$ is ready

    //PC_Q.io.clear       :=  0.B /* TODO: */

    ///////////////////
    // instruction_Q //
    ///////////////////

    // connect instruction queue
    //instruction_Q.io.wr_en       :=  instruction_cache.io.resp_valid    // FIXME: resp_valid should really be apart of fetch_packet
    //instruction_Q.io.data_in     :=  instruction_cache.io.cache_data
    //instruction_Q.io.rd_en       :=  (!instruction_Q.io.empty && !BTB_Q.io.empty)
    //instruction_Q.io.clear       :=  0.B

    ///////////
    // BTB_Q //
    ///////////

    //BTB_Q.io.wr_en               :=  bp.io.predict.valid
    //BTB_Q.io.data_in             :=  bp.io.prediction
    //BTB_Q.io.rd_en               :=  (!instruction_Q.io.empty && !BTB_Q.io.empty)
    //BTB_Q.io.clear               :=  0.B


    ///////////////
    // I$ Access //
    ///////////////

    // FIXME: update for actual addresses. 
    //instruction_cache.io.cpu_addr.bits     :=   0.U
    //instruction_cache.io.cpu_addr.valid    :=   0.B

    //// Dram resp
    //instruction_cache.io.dram_data.bits    :=   0.U
    //instruction_cache.io.dram_data.valid   :=   0.B

    //// Dram req
    //instruction_cache.io.cache_addr.ready  :=  0.B

    //// kill 
    //instruction_cache.io.kill              := 0.B


    ////////////////////////////
    // INIT INSTRUCTION CACHE //
    ////////////////////////////
    

    ////////////////////////
    // INIT BP STRUCTURES //
    ////////////////////////


    // BP inputs (external)
    //bp.io.commit        :=  io.commit
    //bp.io.mispredict    :=  io.mispredict

    //// BP inputs (internal)
    ////bp.io.predict.bits      :=  predict_PC.bits
    ////bp.io.predict.valid     :=  predict_PC.valid

    //bp.io.predict.bits := 0.B
    //bp.io.predict.valid := 0.U
    
    //bp.io.RAS_update        :=  predecoder.io.RAS_update
    //bp.io.revert            :=  predecoder.io.revert

    



/*

    ///////////////////////////////
    // INIT PREDECODE STRUCTURES //
    ///////////////////////////////

*/

    
    //io.misprediction_PC.ready := 1.U
    //io.exception_PC.ready := 1.U



}