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

class instruction_queue[T <: Data](gen: T, parameters: Parameters) extends Module {
  import parameters._

  val io = IO(new Bundle {
    // input
    val in = Vec(fetchWidth, Flipped(Decoupled(gen)))

    // output
    val out = Vec(dispatchWidth, Decoupled(gen))
  })


    ////////////////////////
    // MODULE ASSUMPTIONS //
    ////////////////////////
    require(isPow2(instruction_queue_depth), "Instruction Queue entires not a power of 2")

    ///////////////////////
    // INSTRUCTION QUEUE //
    //////////////////////

    val queue = RegInit(VecInit(Seq.fill(instruction_queue_depth)(0.U.asTypeOf(gen))))
    val valid = RegInit(VecInit(Seq.fill(instruction_queue_depth)(0.B)))

    val pointer_size    = log2Ceil(instruction_queue_depth)+1
    val front_pointer   = RegInit(UInt(pointer_size.W), 0.U)
    val back_pointer    = RegInit(UInt(pointer_size.W), 0.U)

    val front_index     = front_pointer(pointer_size-2, 0)
    val back_index      = back_pointer(pointer_size-2, 0)

    
    /////////////
    // ENQUEUE //
    /////////////

    // FIXME: I think this eliminates the need for the RAT WAW handler
    val valid_in_bits = io.in.map(_.valid)

    for(i <- 0 until fetchWidth){
        when(io.in(i).valid & io.in(i).ready){
            queue(back_index + PopCount(valid_in_bits.take(i))) := io.in(i).bits
            valid(back_index + PopCount(valid_in_bits.take(i))) := true.B
        }
    }

    back_pointer    :=  back_pointer + PopCount(valid_in_bits)  // FIXME: what if not ready

    /////////////
    // DEQUEUE //
    /////////////

    // Assign data
    for(i <- 0 until dispatchWidth){
        io.out(i).bits  := queue(front_index + i.U)
        io.out(i).valid := valid(front_index + i.U)
    }

    // Assign ready 
    for (i <- 0 until fetchWidth) {
        io.in(i).ready := !valid(back_index + i.U)
    }

    // Move pointer & clear

    val ready_in_bits = io.out.map(_.ready)

    for(i <- 0 until dispatchWidth){
        // last condition is to ignore all ready bits after a 0 (non thermometor encoded)
        when(io.out(i).valid & io.out(i).ready & ready_in_bits.take(i+1).reduce(_ && _)){
            queue(front_index + i.U)    := 0.U.asTypeOf(gen)
            valid(front_index + i.U)    := 0.B
            front_pointer               := front_pointer + 1.U
        }
    }
}



class frontend(parameters:Parameters) extends Module{
    import parameters._

    val dataSizeBits         = L1_instructionCacheBlockSizeBytes*8
    val physicalRegBits      = log2Ceil(physicalRegCount)
    val architecturalRegBits = log2Ceil(architecturalRegCount)
    val RATCheckpointBits    = log2Ceil(RATCheckpointCount)

    val portCount = getPortCount(parameters)

    val io = IO(new Bundle{
        // FLUSH //
        val flush                   =   Input(Bool())

        // DRAM CHANNELS //
        val memory_request                    =   Decoupled(new memory_request(parameters))
        val memory_response                   =   Flipped(Decoupled(new fetch_packet(parameters)))
        
        // COMMIT // 
        val commit                          =   Input(new commit(parameters))
        
        // PREDICTIONS //
        val predictions                     =   Decoupled(new FTQ_entry(parameters))

        // INSTRUCTION OUT //
        val renamed_decoded_fetch_packet    =   Decoupled(new decoded_fetch_packet(parameters))

        // RD FREE //
        val FU_outputs                      =   Vec(portCount, Flipped(ValidIO(new FU_output(parameters))))

    })


    //////////////
    // Pipeline //////////////////////////////////////////////////////////////
    // Instruction fetch => Decoders => Queue => Rename => Backend/Allocate //
    //////////////////////////////////////////////////////////////////////////

    val instruction_fetch   = Module(new instruction_fetch(parameters))
    val decoders            = Module(new fetch_packet_decoder(parameters))

    val instruction_queue   = Module(new Q(new decoded_fetch_packet(parameters), depth = 16))

    val rename              = Module(new rename(parameters))

    val flush = io.commit.is_misprediction && io.commit.valid

    ///////////////////////
    // INSTRUCTION FETCH //
    ///////////////////////

    instruction_fetch.io.commit               <>   io.commit
    instruction_fetch.io.memory_response      <>   io.memory_response
    instruction_fetch.io.memory_request       <>   io.memory_request

    instruction_fetch.io.flush                <>   io.flush
    ///////////////
    // FTQ INPUT //
    ///////////////

    instruction_fetch.io.predictions <> io.predictions

    //////////////
    // DECODERS //
    //////////////

    decoders.io.fetch_packet <> instruction_fetch.io.fetch_packet
    decoders.io.flush <> io.flush

    ///////////////////////
    // INSTRUCTION QUEUE //
    ///////////////////////

    instruction_queue.io.in <> decoders.io.decoded_fetch_packet

    // Control how many entries to allocate

    
    ////////////
    // RENAME //
    ////////////

    rename.io.decoded_fetch_packet <> instruction_queue.io.out

    instruction_queue.io.flush := flush 


    rename.io.FU_outputs           <>     io.FU_outputs
    rename.io.flush                <>     io.flush
    rename.io.commit               <>     io.commit

    ////////////
    // OUTPUT //
    ////////////

    io.renamed_decoded_fetch_packet <> rename.io.renamed_decoded_fetch_packet

    

}