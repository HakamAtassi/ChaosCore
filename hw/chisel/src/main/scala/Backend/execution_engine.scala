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

        val INT_producers       =   Vec(INT_producer_count, Decoupled(new FU_output(coreParameters)))

        val FP_producers = if (coreConfig.contains("F")) Some(Vec(FP_producer_count, Decoupled(new FU_output(coreParameters)))) else None


        val irq_software_i                      = Input(Bool())      //msip
        val irq_timer_i                         = Input(Bool())      //mtip
        val irq_external_i                      = Input(Bool())      //meip
        val debug_req_i                         = Input(Bool())      //debug
        val irq_nm_i                            = Input(Bool())      //nmi
    }); dontTouch(io)

    val CSR_port = IO(Output(new CSR_out(coreParameters)))

    // FUs + MOB //
    val INT_FUs: Seq[FU] = Seq.tabulate(INT_FUParamSeq.length) { i => Module(new FU(INT_FUParamSeq(i))(coreParameters))}
    val FP_FUs: Seq[FU] = Seq.tabulate(FP_FUParamSeq.length) { i => Module(new FU(FP_FUParamSeq(i))(coreParameters))}
    val MOB   =  Module(new simple_MOB(coreParameters))

    // Connect INT producers 
    for(i <- 0 until INT_FUParamSeq.length){
        INT_FUs(i).io.flush        <> io.flush
        INT_FUs(i).io.commit       <> io.commit
        INT_FUs(i).io.FU_input     <> io.INT_FU_input(i)
        
    }

    for(i <- 0 until FP_FUParamSeq.length){
        FP_FUs(i).io.flush        <> io.flush
        FP_FUs(i).io.commit       <> io.commit
        FP_FUs(i).io.FU_input     <> io.FP_FU_input(i)
    }
        



    // connect CSR stuff
    // FIXME: this can be cleaned up
    for(i <- 0 until INT_FUParamSeq.length){
        INT_FUs(i).CSR_port.foreach { _ =>
            INT_FUs(i).CSR_port.get <> CSR_port
            INT_FUs(i).irq_software_i.get                 := io.irq_software_i    
            INT_FUs(i).irq_timer_i.get                    := io.irq_timer_i
            INT_FUs(i).irq_external_i.get                 := io.irq_external_i
            INT_FUs(i).debug_req_i.get                    := io.debug_req_i
            INT_FUs(i).irq_nm_i.get                       := io.irq_nm_i
        }
    }

    /////////////////////////////
    // CREATE INT/FP producers //
    /////////////////////////////

    var INT_producers = Seq.empty[DecoupledIO[FU_output]]

    INT_FUParamSeq.zipWithIndex.foreach { case (param, i) =>
        if (param.INT_producer) INT_producers = INT_producers :+ INT_FUs(i).io.FU_output
    }

    // Add MOB output to seq
    INT_producers = INT_producers :+ MOB.io.INT_MOB_output

    

    if(coreConfig.contains("F")){
        var FP_producers = Seq.empty[DecoupledIO[FU_output]]
        FP_FUParamSeq.zipWithIndex.foreach { case (param, i) =>
            if (param.FP_producer) FP_producers = FP_producers :+ FP_FUs(i).io.FU_output
        }

        // Add MOB output to seq
        FP_producers = FP_producers :+ MOB.io.FP_MOB_output.get
        for(i <- 0 until FP_producers.length) {io.FP_producers.get(i) <> FP_producers(i)}
    }



    for(i <- 0 until INT_producers.length){io.INT_producers(i) <> INT_producers(i)}


    val AGU_index = INT_FUParamSeq.indexWhere(_.supportsAddressGeneration)



    // MOB connections
    MOB.io.AGU_output <> INT_FUs(AGU_index).io.FU_output
    

    // reserve mem ops
    for (i <- 0 until fetchWidth){
        MOB.io.reserve(i)     <> io.backend_packet(i)
        MOB.io.reserve(i).bits     := io.backend_packet(i).bits
        MOB.io.reserve(i).valid    := io.backend_packet(i).bits.needs_MEM_RS && io.backend_packet(i).valid
        io.reserve(i).ready        := MOB.io.reserve(i).ready
    }

    MOB.io.backend_memory_request  <> io.backend_memory_request

    MOB.io.backend_memory_response <> io.backend_memory_response

    // inform MEM_RS about location of allocated entries for mem ops for AGU WB
    for(i <- 0 until fetchWidth){
        //MEM_RS(0).io.backend_packet(i).bits.MOB_index := MOB.io.reserved_pointers(i).bits
        io.reserved_pointers(i) <> MOB.io.reserved_pointers(i)
    }



    ////////////////
    // AGU <> MOB //
    ////////////////

    MOB.io.commit   <> io.commit
    MOB.io.flush    <> io.flush

    //io.mtvec :=  FUs(0).io.mtvec


}
