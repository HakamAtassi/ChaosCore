/* ------------------------------------------------------------------------------------
* Filename: frontend.scala
* Author: Hakam Atassi
* Date: Jun 1 2024
* Description: A module that allocates instructions from the frontend into the backend
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


class allocator(parameters:Parameters) extends Module{
    import parameters._

    val portCount = getPortCount(parameters)
    val portCountBits = log2Ceil(portCount)

    val io = IO(new Bundle{

        // INSTRUCTION //
        val renamed_decoded_fetch_packet    =   Flipped(Decoupled(Vec(fetchWidth, new decoded_instruction(parameters))))
        
        // ALLOCATE //
        // Backend
        val backend_packet                  =   Output(Vec(dispatchWidth, new backend_packet(parameters)))
        val MEMRS_ready                     =   Input(Vec(dispatchWidth, Bool()))
        val INTRS_ready                     =   Input(Vec(dispatchWidth, Bool()))

        // ALLOCATE //
        // Frontend
        val ROB_packet                      =   Decoupled(Vec(portCount, new ROB_entry(parameters)))

    })


    io.renamed_decoded_fetch_packet.ready := DontCare


    io.backend_packet := DontCare

    for(i <- 0 until dispatchWidth){
        io.backend_packet(i).decoded_instruction    := io.renamed_decoded_fetch_packet.bits(i)
        io.backend_packet(i).ready_bits             := DontCare
    }




    io.ROB_packet     := DontCare


}