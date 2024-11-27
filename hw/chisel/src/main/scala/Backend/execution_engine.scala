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

        val partial_commit  =   Input(new partial_commit(coreParameters))
        val commit          =   Flipped(ValidIO(new commit(coreParameters)))

        val FU_input        =   Vec(portCount, Flipped(Decoupled(new read_decoded_instruction(coreParameters))))
        
        val FU_output       =   Vec(portCount, ValidIO(new FU_output(coreParameters)))

        //val mtvec = Output(UInt(32.W))
    })


    val CSR_port = IO(Output(new CSR_out(coreParameters)))

    // FUs
    val FUs: Seq[FU] = Seq.tabulate(FUParamSeq.length) { i => Module(new FU(FUParamSeq(i))(coreParameters))}


    for(i <- 0 until portCount){
        FUs(i).io.flush             <> io.flush
        FUs(i).io.partial_commit    <> io.partial_commit
        FUs(i).io.commit            <> io.commit
        FUs(i).io.FU_input          <> io.FU_input(i)
        FUs(i).io.FU_output         <> io.FU_output(i)

        FUs(i).CSR_port.foreach { _ =>
            FUs(i).CSR_port.get <> CSR_port
        }
    }


    //io.mtvec :=  FUs(0).io.mtvec


}