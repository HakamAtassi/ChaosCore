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

// FIXME: enqueue and dequeue at the same time????
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

        // DRAM CHANNELS //
        val DRAM_resp                       =   Flipped(Decoupled(Input(new DRAM_resp(parameters))))  // FROM DRAM
        val DRAM_request                    =   Decoupled(new DRAM_request(parameters))               // TO DRAM

        // COMMIT // 
        val commit                          =   Input(new commit(parameters))
        
        // PREDICTIONS //
        val predictions                     =   Decoupled(new FTQ_entry(parameters))

        // INSTRUCTION OUT //
        val renamed_decoded_fetch_packet    =   Vec(dispatchWidth, Decoupled(new decoded_instruction(parameters)))

        // ALLOCATE //
        // Backend
        val MEMRS_ready                     =   Input(Vec(dispatchWidth, Bool()))
        val INTRS_ready                     =   Input(Vec(dispatchWidth, Bool()))

        // ALLOCATE //
        // ROB
        val ROB_packet                      =   Vec(dispatchWidth, Decoupled(new ROB_entry(parameters)))
        val fetch_PC                        =   Output(UInt(32.W))

        // RD FREE //
        val FU_outputs                      =   Vec(portCount, Flipped(ValidIO(new FU_output(parameters))))

    })


    //io.exception_PC.ready      := 1.B
    //io.commit.ready            := 1.B

    val commit                          =  Wire(Decoupled(new commit(parameters)))
    commit := DontCare

    io.fetch_PC := DontCare

    //////////////
    // Pipeline //////////////////////////////////////////////////////////////
    // Instruction fetch => Decoders => Queue => Rename => Backend/Allocate //
    //////////////////////////////////////////////////////////////////////////

    val instruction_fetch   = Module(new instruction_fetch(parameters))
    val decoders            = Module(new fetch_packet_decoder(parameters))
    val instruction_queue   = Module(new instruction_queue(new decoded_instruction(parameters), parameters))
    val renamer             = Module(new renamer(parameters))


    ///////////////////////
    // INSTRUCTION FETCH //
    ///////////////////////

    instruction_fetch.io.commit               <>   io.commit
    instruction_fetch.io.DRAM_resp            <>   io.DRAM_resp
    instruction_fetch.io.DRAM_request         <>   io.DRAM_request

    ///////////////
    // FTQ INPUT //
    ///////////////

    instruction_fetch.io.predictions <> io.predictions

    //////////////
    // DECODERS //
    //////////////

    decoders.io.fetch_packet <> instruction_fetch.io.fetch_packet


    ///////////////////////
    // INSTRUCTION QUEUE //
    ///////////////////////

    instruction_queue.io.in <> decoders.io.decoded_fetch_packet

    // Control how many entries to allocate

    
    val is_INTRS = instruction_queue.io.out.map(_.bits.RS_type === RS_types.INT)
    val is_MEMRS = instruction_queue.io.out.map(_.bits.RS_type === RS_types.MEM)


    for(i <- 0 until dispatchWidth) {
        when(is_INTRS(i)) {
            instruction_queue.io.out(i).ready :=  PopCount(is_INTRS.take(i+1)) <= PopCount(io.INTRS_ready)
        } .elsewhen(is_MEMRS(i)) {
            instruction_queue.io.out(i).ready :=  PopCount(is_MEMRS.take(i+1)) <= PopCount(io.MEMRS_ready)
        } .otherwise {
            instruction_queue.io.out(i).ready := 0.B
        }
    }



    ////////////
    // RENAME //
    ////////////

    renamer.io.decoded_fetch_packet <> instruction_queue.io.out


    // In a single cycle, both a "create checkpoint" and "restore checkpoint" can be requested
    // The reason this is possible is because create checkpoint is requested by the frontend (predecoder)
    // And the restore checkpoint is requested by the ROB on a misprediction. 
    // As such, if a restore checkpoint is being requested, it takes priority over create checkpoint because
    // Create checkpoint is not invalid (wrong, as that instruction path is down a mispredicted path)

    // Free checkpoint and restore checkpoint are both requested by the ROB. They can be done in parallell no 
    // problem. ie, one instruction in the FTQ is correct, the following one is wrong. Free the checkpoint for the first
    // while restoring the RAT and other structures to the mispredicted state. This is probably a pretty likely case
    // So make sure its verified correctly. 
    

    renamer.io.FU_outputs           <>     io.FU_outputs

    // FIXME: This needs to be either fine grain or course grain
    // Ex, either be able to free several checkpoints at once
    // Or assign checkpoints to entire fetch packets so that it doesnt matter how many 
    // frees occur each cycle. Fine grain is easier but less area efficient.
    // In other words, this is almost certainly bugged

    // Commit logic
    // Free + Restore

    renamer.io.restore_checkpoint        := 0.B
    renamer.io.restore_checkpoint_value  := 0.U
    renamer.io.free_checkpoint           := 0.B

    when(io.commit.valid && io.commit.is_misprediction){
        renamer.io.restore_checkpoint        :=     1.B 
        renamer.io.restore_checkpoint_value  :=     io.commit.RAT_IDX
        renamer.io.free_checkpoint           :=     1.B 
    }

    // Create logic
    renamer.io.create_checkpoint          :=     0.B
    io.predictions.bits.RAT_IDX           :=     renamer.io.active_checkpoint_value
    when(io.predictions.valid){
        renamer.io.create_checkpoint      :=     1.B 
    }

    //io.checkpoints_full                  :=     renamer.io.checkpoints_full
    //io.active_checkpoint_value           :=     renamer.io.active_checkpoint_value
    ////////////
    // OUTPUT //
    ////////////

    io.renamed_decoded_fetch_packet <> renamer.io.renamed_decoded_fetch_packet

    io.ROB_packet := DontCare

}