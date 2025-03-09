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
    val portCount = FUParamSeq.length

    val io = IO(new Bundle{
        val flush           =   Flipped(ValidIO(new flush(coreParameters)))

        val commit          =   Flipped(ValidIO(new commit(coreParameters)))

        // FIXME: Split this into INT_FU_input, FP_FU_input, MEM_FU_input to aliviate the ordering issue
        val INT_FU_input        =   Vec(INTportCount, Flipped(Decoupled(new read_decoded_instruction(coreParameters))))
        val MEM_FU_input        =   Vec(MEMportCount, Flipped(Decoupled(new read_decoded_instruction(coreParameters))))
        val FP_FU_input         =   Vec(FPportCount,  Flipped(Decoupled(new read_decoded_instruction(coreParameters))))

        val INT_FU_output       =   Vec(INTportCount, Decoupled(new FU_output(coreParameters)))
        val MEM_FU_output       =   Vec(MEMportCount, Decoupled(new FU_output(coreParameters)))
        val FP_FU_output        =   Vec(FPportCount,  Decoupled(new FU_output(coreParameters)))

        val irq_software_i                      = Input(Bool())      //msip
        val irq_timer_i                         = Input(Bool())      //mtip
        val irq_external_i                      = Input(Bool())      //meip
        val debug_req_i                         = Input(Bool())      //debug
        val irq_nm_i                            = Input(Bool())      //nmi
    })

    val CSR_port = IO(Output(new CSR_out(coreParameters)))

    // FUs
    val FUs: Seq[FU] = Seq.tabulate(FUParamSeq.length) { i => Module(new FU(FUParamSeq(i))(coreParameters))}

    for(i <- 0 until portCount){
        FUs(i).io.flush             <> io.flush
        FUs(i).io.commit            <> io.commit
        FUs(i).io.FU_input          <> io.FU_input(i)
        FUs(i).io.FU_output         <> Seq(io.INT_FU_output, io.MEM_FU_input, FP_FU_input)(i)

        FUs(i).CSR_port.foreach { _ =>
            FUs(i).CSR_port.get <> CSR_port
            FUs(i).irq_software_i.get                 := io.irq_software_i    
            FUs(i).irq_timer_i.get                    := io.irq_timer_i
            FUs(i).irq_external_i.get                 := io.irq_external_i
            FUs(i).debug_req_i.get                    := io.debug_req_i
            FUs(i).irq_nm_i.get                       := io.irq_nm_i
        }
    }


    //io.mtvec :=  FUs(0).io.mtvec


}
