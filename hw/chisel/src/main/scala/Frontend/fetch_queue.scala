/* ------------------------------------------------------------------------------------
* Filename: fetch_queue.scala
* Author: Alisher Rakhimov
* Date: Oct 17 2024
* Description: The components of the frontend that generate the stream of (raw) instructions
* License: MIT
*
* Copyright (c) 2024 by Alisher Rakhimov
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

class instruction_aligner(coreParameters:CoreParameters) extends Module{
    import coreParameters._

    val io = IO(new Bundle{
        //val flush                 =   Input(Bool())
        val mem_fetch_packet                   =   Flipped(Decoupled(new fetch_packet(coreParameters)))           
        val aligned_fetch_packet                   =   Decoupled(new fetch_packet(coreParameters))           
    })

    val expanders = for (i <- 0 until fetchWidth*2) yield
    {
        val expander = Module(new RVC_expander(coreParameters))
        expander.io := DontCare
        //dontTouch(expander.io)
        expander
    }


    val fetch_reg = Reg(new fetch_packet(coreParameters))

    val aligned_fetch_packet_1 = Wire(new fetch_packet(coreParameters))
    val aligned_fetch_packet_2 = Reg(new fetch_packet(coreParameters))

    val is_RVC = Wire(Vec(fetchWidth*2, Bool()))
    val ready_reg = RegInit(Bool(),1.B)

    val lower_bits = RegInit(0.U(16.W))
    val lower_bits_valid = RegInit(Bool(),0.B)

    lower_bits_valid := lower_bits(1,0) === 3.U


    val instructions = Wire(Vec(4, UInt(32.W)))   

    lower_bits_valid := 0.B
    aligned_fetch_packet_1 := fetch_reg
    for(i <- 0 until fetchWidth){
        is_RVC(i*2) := 0.B
        is_RVC(i*2 + 1) := 0.B
        instructions(i) := 0.B
        aligned_fetch_packet_1.valid_bits(i) := 1.B
        aligned_fetch_packet_2.valid_bits(i) := 1.B
        when(fetch_reg.valid_bits(i)){
            instructions(i) := fetch_reg.instructions(i).instruction
            is_RVC(i*2) := instructions(i)(1,0) =/= 3.U
            is_RVC(i*2 +1) := instructions(i)(17,16) =/= 3.U
        }

        if (i < fetchWidth/2){
            when (lower_bits_valid){
                aligned_fetch_packet_1.instructions(i*2).instruction := Cat(instructions(i)(15, 0), lower_bits)
                aligned_fetch_packet_1.valid_bits(i*2) := 1.B
            }

            when(is_RVC(i*2) && !lower_bits_valid){
                expanders(i*2).io.compressed_instr := instructions(i)(15, 0)
                aligned_fetch_packet_1.instructions(i*2).instruction := expanders(i*2).io.instruction
                aligned_fetch_packet_1.valid_bits(i*2) := 1.B
            }.elsewhen(fetch_reg.valid_bits(i)){
                aligned_fetch_packet_1.instructions(i*2).instruction := instructions(i*2)
                aligned_fetch_packet_1.valid_bits(i*2) := 1.B
            }

            when(is_RVC(i*2 + 1)){
                expanders(i*2 + 1).io.compressed_instr := instructions(i)(31, 16)
                aligned_fetch_packet_1.instructions(i*2 + 1).instruction := expanders(i*2 + 1).io.instruction
                aligned_fetch_packet_1.valid_bits(i*2 + 1) := 1.B
            }.elsewhen(fetch_reg.valid_bits(i)){
                aligned_fetch_packet_1.instructions(i*2 + 1).instruction := Cat(instructions(i+1)(15,0), instructions(i)(31,16))
                aligned_fetch_packet_1.valid_bits(i*2 + 1) := 1.B
            }
        } else {

            when(is_RVC(i*2)){
                expanders(i*2).io.compressed_instr := instructions(i)(15, 0)
                aligned_fetch_packet_2.instructions((i-2)*2).instruction := expanders(i*2).io.instruction
                aligned_fetch_packet_2.valid_bits((i-2)*2) := 1.B
            }.elsewhen(fetch_reg.valid_bits(i)){
                aligned_fetch_packet_2.instructions((i-2)*2).instruction := instructions(i)
                aligned_fetch_packet_2.valid_bits((i-2)*2) := 1.B
            }

            when(is_RVC(i*2 + 1)){
                expanders(i*2 + 1).io.compressed_instr := instructions(i)(31, 16)
                aligned_fetch_packet_2.instructions((i-2)*2 + 1).instruction := expanders(i*2 + 1).io.instruction
                aligned_fetch_packet_2.valid_bits((i-2)*2 + 1) := 1.B
            }.elsewhen(fetch_reg.valid_bits(i)){
                if(i < fetchWidth - 1){
                    aligned_fetch_packet_2.instructions((i-2)*2 + 1).instruction := Cat(instructions(i+1)(15,0), instructions(i)(31,16))
                } else {
                    aligned_fetch_packet_2.valid_bits((i-2)*2 + 1) := 0.B 
                    lower_bits := instructions(i)(31,16)
                    lower_bits_valid := 1.B
                }
                aligned_fetch_packet_2.valid_bits((i-2)*2 + 1) := 1.B
            }
        }
    }

    io.aligned_fetch_packet.bits := DontCare
    io.aligned_fetch_packet.valid := 0.B
    when (io.mem_fetch_packet.fire){
        fetch_reg := io.mem_fetch_packet.bits
        ready_reg := 0.B
    }.elsewhen(RegNext(io.mem_fetch_packet.fire)){
        io.aligned_fetch_packet.bits := aligned_fetch_packet_1
        ready_reg := 1.B
        io.aligned_fetch_packet.valid := 1.B
    }.elsewhen(RegNext(RegNext(io.mem_fetch_packet.fire))){
        io.aligned_fetch_packet.bits := aligned_fetch_packet_2
        io.aligned_fetch_packet.valid := 1.B
    }
    io.mem_fetch_packet.ready := ready_reg
}


class fetch_queue(coreParameters:CoreParameters) extends Module{
    import coreParameters._

    val io = IO(new Bundle{
        val flush                 =   Input(Bool())
        val enq                   =   Flipped(Decoupled(new fetch_packet(coreParameters)))           
        val deq                   =   Decoupled(new fetch_packet(coreParameters))           
    })

    val instruction_Q   =   Module(new Queue(new fetch_packet(coreParameters), 32, flow=true, hasFlush=true, useSyncReadMem=true))
    val aligner         =   Module(new instruction_aligner(coreParameters))
    

    aligner.io.mem_fetch_packet.valid     := io.enq.valid
    aligner.io.aligned_fetch_packet.ready := instruction_Q.io.enq.ready
    aligner.io.mem_fetch_packet.bits      := io.enq.bits

    instruction_Q.io.enq.bits             := aligner.io.aligned_fetch_packet.bits
    instruction_Q.io.enq.valid            := aligner.io.aligned_fetch_packet.valid
    instruction_Q.io.flush.get            := io.flush
    instruction_Q.io.deq                  <> io.deq

    io.enq.ready                          := aligner.io.mem_fetch_packet.ready

}