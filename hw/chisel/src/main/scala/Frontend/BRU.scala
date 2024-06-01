/* ------------------------------------------------------------------------------------
* Filename: BRU.scala
* Author: Hakam Atassi
* Date: May 16 2024
* Description: A fetch target queue that stores active branch predictions and a unit that validates them upon commit
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
import circt.stage.ChiselStage
import chisel3.util._

// "branch resolution unit"
class BRU(parameters:Parameters) extends Module{
    import parameters._
    val portCount = getPortCount(parameters)

    val io = IO(new Bundle{
        // FTQ //
        val FTQ           =   Flipped(Decoupled(new FTQ_entry(parameters)))    // push made predictions to FTQ

        // COMMIT //
        val ROB_commit    =   Input(Vec(commitWidth, new ROB_entry(parameters)))

        // Output 
        val misprediction =   Output(new misprediction(parameters))
    })

    io.FTQ.ready := DontCare
    io.misprediction := DontCare

}


