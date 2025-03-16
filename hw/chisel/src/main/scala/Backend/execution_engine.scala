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

        val backend_memory_request              =   Decoupled(new backend_memory_request(coreParameters))
        val backend_memory_response             =   Flipped(Decoupled(new backend_memory_response(coreParameters)))

        val INT_FU_input        =   Vec(INT_consumer_count, Flipped(Decoupled(new read_decoded_instruction(coreParameters))))
        val FP_FU_input         =   Vec(FP_consumer_count,  Flipped(Decoupled(new read_decoded_instruction(coreParameters))))

        val INT_producers       =   Vec(INT_consumer_count, Decoupled(new FU_output(coreParameters)))
        val FP_producers        =   Vec(FP_consumer_count,  Decoupled(new FU_output(coreParameters)))

        val irq_software_i                      = Input(Bool())      //msip
        val irq_timer_i                         = Input(Bool())      //mtip
        val irq_external_i                      = Input(Bool())      //meip
        val debug_req_i                         = Input(Bool())      //debug
        val irq_nm_i                            = Input(Bool())      //nmi
    }); dontTouch(io)

    val CSR_port = IO(Output(new CSR_out(coreParameters)))

    // FUs + MOB //
    val FUs: Seq[FU] = Seq.tabulate(FUParamSeq.length) { i => Module(new FU(FUParamSeq(i))(coreParameters))}
    val MOB   =  Module(new simple_MOB(coreParameters))

    // FIXME: temp
    io.FP_producers := DontCare
    FUs(4).io := DontCare
    FUs(5).io := DontCare

    io.FP_FU_input := DontCare


    // FIXME: the FP and INT producer outputs here are missing an offset. How do I fix that?
    // Connect INT producers 
    for(i <- 0 until FUParamSeq.length){
        FUs(i).io.flush             <> io.flush
        FUs(i).io.commit            <> io.commit

        // connect FU inputs
        // FIXME: offsets missing from here
        if(FUParamSeq(i).INT_consumer){
            FUs(i).io.FU_input     <> io.INT_FU_input(i)
        }
        
        //else if(FUParamSeq(i).FP_consumer){
            ////FUs(i).io.FU_input     <> io.FP_FU_input(i)
        //}

    }



    // connect CSR stuff
    for(i <- 0 until FUParamSeq.length){
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

  val INT_producers = FUParamSeq.zipWithIndex.flatMap { case (param, i) =>
        if (param.INT_producer) Some(FUs(i).io.FU_output)
        else if (param.MEM_producer) Some(MOB.io.INT_MOB_output)
        else None
    }

    val FP_producers = FUParamSeq.zipWithIndex.flatMap { case (param, i) =>
        if (param.FP_producer) Some(FUs(i).io.FU_output)
        else if (param.MEM_producer) Some(MOB.io.FP_MOB_output)
        else None
    }

    for(i <- 0 until FP_producer_count) {io.FP_producers(i) <> FP_producers(i)}
    for(i <- 0 until INT_producer_count){io.INT_producers(i) <> INT_producers(i)}


    val AGU_index = FUParamSeq.indexWhere(_.supportsAddressGeneration)


    println(INT_producers)






    // MOB connections
    MOB.io.AGU_output <> FUs(AGU_index).io.FU_output
    

    // reserve mem ops
    for (i <- 0 until fetchWidth){
        MOB.io.reserve(i)     <> io.backend_packet(i)
        MOB.io.reserve(i).bits     := io.backend_packet(i).bits
        MOB.io.reserve(i).valid    := io.backend_packet(i).bits.needs_MEM_RS && io.backend_packet(i).valid
        io.reserve(i).ready        := MOB.io.reserve(i).ready
    }

    MOB.io.backend_memory_request     <> io.backend_memory_request

    MOB.io.backend_memory_response <> io.backend_memory_response

    // inform MEM_RS about location of allocated entries for mem ops for AGU WB
    for(i <- 0 until fetchWidth){
        //MEM_RS(0).io.backend_packet(i).bits.MOB_index := MOB.io.reserved_pointers(i).bits
        io.reserved_pointers(i) <> MOB.io.reserved_pointers(i)
    }


    // replace FU_output for AGU with MOB output
    //FUs(AGU_index).io.FU_output  := FP_producers(AGU_index)


    //for(i <- 0 until INT_producer_count){
        //io.INT_producers(i) <> FUs(i).io.FU_output
    //}


    //for(i <- 0 until FP_producer_count){
        //io.FP_FU_output(i) <> io.FP_FU_output(i)
    //}





    ////////////////
    // AGU <> MOB //
    ////////////////

    MOB.io.commit   <> io.commit
    MOB.io.flush    <> io.flush

    //io.mtvec :=  FUs(0).io.mtvec


}
