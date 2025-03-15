/* ------------------------------------------------------------------------------------
* Filename: execution_engine.scala
* Author: Hakam Atassi
* Date: Sep 5 2024
* Description: The wrapper containing all the FUs.
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

class execution_engine(coreParameters:CoreParameters) extends Module{
    import coreParameters._

    val io = IO(new Bundle{
        val flush           =   Flipped(ValidIO(new flush(coreParameters)))

        val commit          =   Flipped(ValidIO(new commit(coreParameters)))


        // MOB STUFF
        val reserve                 =      Vec(fetchWidth, Flipped(Decoupled(new decoded_instruction(coreParameters))))         // reserve entry (rename)
        val reserved_pointers       =      Vec(fetchWidth, ValidIO(UInt(log2Ceil(MOBEntries).W)))                               // pointer to allocated entry
        val backend_packet          =      Vec(fetchWidth, Flipped(Decoupled(new decoded_instruction(coreParameters))))

        val INT_FU_input        =   Vec(FUParamSeq.INT_consumer_count, Flipped(Decoupled(new read_decoded_instruction(coreParameters))))
        val FP_FU_input         =   Vec(FUParamSeq.FP_consumer_count,  Flipped(Decoupled(new read_decoded_instruction(coreParameters))))

        val INT_producers       =   Vec(FUParamSeq.INT_consumer_count, Decoupled(new FU_output(coreParameters)))
        val FP_producers        =   Vec(FUParamSeq.FP_consumer_count,  Decoupled(new FU_output(coreParameters)))

        val irq_software_i                      = Input(Bool())      //msip
        val irq_timer_i                         = Input(Bool())      //mtip
        val irq_external_i                      = Input(Bool())      //meip
        val debug_req_i                         = Input(Bool())      //debug
        val irq_nm_i                            = Input(Bool())      //nmi
    })

    val CSR_port = IO(Output(new CSR_out(coreParameters)))

    // FUs + MOB //
    val FUs: Seq[FU] = Seq.tabulate(FUParamSeq.length) { i => Module(new FU(FUParamSeq(i))(coreParameters))}
    val MOB   =  Module(new simple_MOB(coreParameters))


    val FU_inputs  = Seq(io.INT_FU_input.toSeq, io.FP_FU_input.toSeq).flatten
    val FU_outputs = Seq(io.INT_FU_output.toSeq, io.FP_FU_output.toSeq).flatten

    for(i <- 0 until FUParamSeq.length){
        FUs(i).io.flush             <> io.flush
        FUs(i).io.commit            <> io.commit
        FUs(i).io.FU_input          <> FU_inputs(i)
        FUs(i).io.FU_output         <> FU_outputs(i)

        FUs(i).CSR_port.foreach { _ =>
            FUs(i).CSR_port.get <> CSR_port
            FUs(i).irq_software_i.get                 := io.irq_software_i    
            FUs(i).irq_timer_i.get                    := io.irq_timer_i
            FUs(i).irq_external_i.get                 := io.irq_external_i
            FUs(i).debug_req_i.get                    := io.debug_req_i
            FUs(i).irq_nm_i.get                       := io.irq_nm_i
        }
    }


    // create sequence of INT/FP producers
    //val INT_producers = FUParamSeq.get_INT_producers(FUs)
    //val FP_producers = FUParamSeq.get_FP_producers(FUs)

  val INT_producers = FUParamSeq.zipWithIndex.flatMap { case (param, i) =>
        if (param.INT_producer) Some(FUs(i))
        else if (param.MEM_producer) Some(MOB.io.INT_FU_output)
        else None
    }

    val FP_producers = FUParamSeq.zipWithIndex.flatMap { case (param, i) =>
        if (param.FP_producer) Some(FUs(i))
        else if (param.MEM_producer) Some(MOB.io.FP_FU_output)
        else None
    }

    for(i <- until INT_producers){io.INT_producers <> INT_producers(i)}
    for(i <- until FP_producers) {io.FP_producers <> FP_producers(i)}


    val AGU_index = FUParamSeq.getFirst(supportsAddressGeneration)

    // MOB connections
    MOB.io.AGU_output <> FUs(AGU_index).io.FU_output
    

    // reserve mem ops
    for (i <- 0 until fetchWidth){
        MOB.io.reserve(i).bits     := io.backend_packet(i).bits
        MOB.io.reserve(i).valid    := io.backend_packet(i).bits.needs_MEM_RS && io.backend_packet(i).valid
    }

    // inform MEM_RS about location of allocated entries for mem ops for AGU WB
    for(i <- 0 until fetchWidth){
        MEM_RS(0).io.backend_packet(i).bits.MOB_index := MOB.io.reserved_pointers(i).bits
    }


    // replace FU_output for AGU with MOB output
    FUs(AGU_index).io.FU_output  := FU_outputs(i)


    for(i <- 0 until FUParamSeq.INT_producer_count){
        io.INT_FU_output(i) <> io.INT_FU_output(i)
    }

    for(i <- 0 until FUParamSeq.FP_producer_count){
        io.FP_FU_output(i) <> io.FP_FU_output(i)
    }





    ////////////////
    // AGU <> MOB //
    ////////////////

    MOB.io.commit   <> io.commit
    MOB.io.flush    <> io.flush

    //io.mtvec :=  FUs(0).io.mtvec


}
