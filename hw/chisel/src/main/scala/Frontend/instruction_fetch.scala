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
  io.full :=  !queue.io.enq.ready
  io.empty := !queue.io.deq.valid

  // Reset logic
  queue.reset := io.clear || reset.asBool
}

class skidbuffer[T <: Data](datatype: T) extends Module{
  val io = IO(new Bundle{
    val in   = Flipped(Decoupled(datatype))
    val out  = Decoupled(datatype)
  })

  object State extends ChiselEnum {
    val passthrough, stall = Value
  }

  val buffer = Reg(datatype)
  val state = RegInit(State.passthrough)

  when(io.in.valid){
    buffer  := io.in.bits
  }

  switch(state){
    is(State.passthrough){
      io.in.ready := 1.B
      when(io.out.ready === 1.B){
        io.out.bits   := io.in.bits // Pass data along
        io.out.valid  := 1.B
      }.otherwise{
        state := State.stall
      }
    }
    is(State.stall){
      io.in.ready := 0.B
      when(io.out.ready === 0.B){
        io.out.bits   := buffer
        io.out.valid  := 1.B
      }.otherwise{
        state := State.passthrough
      }

    }
  }

}

// TODO: handle mispredict
// TODO: handle kills/reverts/clears

class instruction_fetch(parameters:Parameters) extends Module{
  import parameters._

    val dataSizeBits                = L1_instructionCacheBlockSizeBytes*8

    val io = IO(new Bundle{

        //val PC                = Flipped(Decoupled(UInt(32.W)))

        // Inputs: A series of PCs and control signals
        val misprediction_PC  =   Flipped(Decoupled(UInt(32.W)))                              // Input
        val exception_PC      =   Flipped(Decoupled(UInt(32.W)))                              // Input
        val dram_data         =   Flipped(Decoupled(UInt(dataSizeBits.W)))                    // inputs from DRAM
        val commit            =   Flipped(Decoupled(new commit(fetchWidth=fetchWidth)))       // Input
        
        // outputs
        val cache_addr        =   Decoupled(UInt(32.W))                                       // outputs to DRAM
        val fetch_packet      =   Decoupled(new fetch_packet(parameters))                     // Fetch packet result (To Decoders)
        

    })

    /////////////
    // Modules //
    /////////////
    val instruction_cache   = Module(new L1_instruction_cache(parameters))
    val bp                  = Module(new BP(GHRWidth=GHRWidth, fetchWidth=fetchWidth, RASEntries=RASEntries, BTBEntries=BTBEntries))
    val predecoder          = Module(new decode_validate(parameters))
    val PC_gen              = Module(new PC_arbit(GHRWidth=GHRWidth, fetchWidth=fetchWidth, RASEntries=RASEntries, startPC=startPC))

    ////////////
    // Queues //
    ////////////
    val instruction_Q   =   Module(new Q(new fetch_packet(parameters), depth = 16))              // Instantiate queue with fetch_packet data type
    val PC_Q            =   Module(new Q(UInt(32.W)))                                                       // Queue of predicted PCs
    val BTB_Q           =   Module(new Q(new prediction(fetchWidth=fetchWidth, GHRWidth=GHRWidth)))         // Queue of BTB responses

    ///////////
    // Wires //
    ///////////
    //val predict_PC     =   Wire(Decoupled(UInt(32.W)))
    val clear            =   Wire(Bool())
    clear := io.commit.bits.misprediction || predecoder.io.revert.valid // && exception ... //FIXME: 

    //////////////
    // PC Queue //
    //////////////
    //PC_Q.io.wr_en       :=  io.PC.valid         // Write to PC_Q whenever the PC is valid
    //PC_Q.io.data_in     :=  io.PC.bits
    PC_Q.io.wr_en       :=  PC_gen.io.PC_next.valid
    PC_Q.io.data_in     :=  PC_gen.io.PC_next.bits
    PC_Q.io.rd_en       :=  (instruction_cache.io.cpu_addr.ready)  
    PC_Q.io.clear       :=  clear

    ///////////////////////
    // INSTRUCTION QUEUE //
    ///////////////////////
    instruction_Q.io.wr_en       :=  instruction_cache.io.cache_data.valid    // Good
    instruction_Q.io.data_in     :=  instruction_cache.io.cache_data.bits
    instruction_Q.io.rd_en       :=  (!BTB_Q.io.empty && predecoder.io.fetch_packet.ready)
    instruction_Q.io.clear       :=  clear

    ///////////////
    // BTB QUEUE //
    ///////////////
    BTB_Q.io.wr_en               :=  bp.io.prediction.valid
    BTB_Q.io.data_in             :=  bp.io.prediction.bits
    BTB_Q.io.rd_en               :=  (!instruction_Q.io.empty && predecoder.io.prediction.ready)
    BTB_Q.io.clear               :=  clear
  
    ///////////////////////
    // INSTRUCTION CACHE //
    ///////////////////////
    instruction_cache.io.cache_data.ready     :=   !instruction_Q.io.full


    // Attach PC_Q to instruction cache
    instruction_cache.io.cpu_addr.bits     :=   PC_Q.io.data_out
    instruction_cache.io.cpu_addr.valid    :=   (!PC_Q.io.empty)

    // Dram resp
    io.cache_addr.bits                          :=   instruction_cache.io.cache_addr.bits     //  TO DRAM 
    io.cache_addr.valid                         :=   instruction_cache.io.cache_addr.valid    //  TO DRAM
    instruction_cache.io.dram_data.valid        :=   io.dram_data.valid                       //  FROM DRAM
    instruction_cache.io.dram_data.bits         :=   io.dram_data.bits                        //  FROM DRAM

    instruction_cache.io.cache_addr.ready       := io.cache_addr.ready                        // Is DRAM ready for request ?
    io.dram_data.ready                          := instruction_cache.io.dram_data.ready       // Is Cache ready to accept DRAM response ?

    // kill 
    instruction_cache.io.kill                   := clear

    ////////
    // BP //
    ////////

    // BP inputs (external)
    bp.io.commit.bits       :=  io.commit.bits
    bp.io.commit.valid      :=  io.commit.valid

    // BP inputs (internal)
    bp.io.predict.bits      :=  PC_gen.io.PC_next.bits
    bp.io.predict.valid     :=  PC_gen.io.PC_next.valid

    bp.io.RAS_update        :=  predecoder.io.RAS_update

    bp.io.revert.bits       :=  predecoder.io.revert.bits
    bp.io.revert.valid      :=  predecoder.io.revert.valid

    bp.io.prediction.ready  := !BTB_Q.io.full

    // Outputs
    predecoder.io.RAS_read  := bp.io.RAS_read

    ////////////////
    // PREDECODER //
    ////////////////
    predecoder.io.prediction.bits    :=   BTB_Q.io.data_out
    predecoder.io.prediction.valid   :=   !BTB_Q.io.empty

    predecoder.io.fetch_packet.bits  :=   instruction_Q.io.data_out 
    predecoder.io.fetch_packet.valid :=   !instruction_Q.io.empty

    predecoder.io.RAS_read           :=   bp.io.RAS_read

    predecoder.io.final_fetch_packet.ready := io.fetch_packet.ready
    
    //////////////
    // PC ARBIT //
    //////////////
    PC_gen.io.commit.bits      := io.commit.bits
    PC_gen.io.commit.valid     := io.commit.valid

    PC_gen.io.prediction.bits  := bp.io.prediction.bits
    PC_gen.io.prediction.valid := bp.io.prediction.valid
    
    PC_gen.io.RAS_read         := bp.io.RAS_read
    PC_gen.io.PC_next.ready    := !PC_Q.io.full && bp.io.predict.ready

    PC_gen.io.revert.bits      := predecoder.io.revert.bits
    PC_gen.io.revert.valid     := predecoder.io.revert.valid


    // FIXME: PC_gen readies not connected


    /////////////
    // OUTPUTS //
    /////////////
    
    io.misprediction_PC.ready  := 1.U
    io.exception_PC.ready      := 1.U
    io.commit.ready            := 1.U
    //io.mispredict.ready        := 1.U
    predecoder.io.revert.ready := 1.U
    //PC_gen.io.revert.ready && bp.io.revert.ready // FIXME: when is revert ready??

    io.fetch_packet.bits := predecoder.io.final_fetch_packet.bits
    io.fetch_packet.valid := predecoder.io.final_fetch_packet.valid
    predecoder.io.final_fetch_packet.ready := io.fetch_packet.ready

}