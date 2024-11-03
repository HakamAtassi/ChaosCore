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

class instruction_validator(fetchWidth: Int) extends Module {
  val io = IO(new Bundle {
    val instruction_index = Input(UInt(log2Ceil(fetchWidth).W))
    val instruction_output = Output(UInt(fetchWidth.W))
  })
    // instruction offset -> valid mask
    //fetch width = 2
        // 0 -> 11
        // 1 -> 01

    // fetch width = 4
        //00 -> 1111
        //01 -> 0111
        //10 -> 0011
        //11 -> 0001

    val masks = VecInit(Seq.tabulate(fetchWidth)(i => ((1 << (fetchWidth - i)) - 1).U(fetchWidth.W)))
    io.instruction_output := masks(io.instruction_index)
}

class instruction_aligner(coreParameters:CoreParameters) extends Module{
    import coreParameters._

    val io = IO(new Bundle{
        //val flush                 =   Input(Bool())
        val mem_rsp                  =   Flipped(Decoupled(new mem_response(coreParameters)))           
        val aligned_fetch_packet                   =   Decoupled(new fetch_packet(coreParameters))           
    })

    val expanders = for (i <- 0 until fetchWidth*2) yield
    {
        val expander = Module(new RVC_expander(coreParameters))
        expander.io := DontCare
        //dontTouch(expander.io)
        expander
    }


    val fetch_reg = Reg(new mem_response(coreParameters))

    val aligned_fetch_packet_1 = Wire(new fetch_packet(coreParameters))
    val aligned_fetch_packet_2 = Wire(new fetch_packet(coreParameters))

    val is_RVC = Wire(Vec(fetchWidth*2, Bool()))
    val upper_bits = Wire(Vec(fetchWidth*2, Bool()))
    val ready_reg = RegInit(Bool(),1.B)

    val lower_bits = RegInit(0.U(16.W))
    val lower_bits_valid = RegInit(Bool(),0.B)

    lower_bits_valid := lower_bits(1,0) === 3.U


    val valid_bits = Wire(Vec(fetchWidth, Bool()))
    val validator = Module(new instruction_validator(fetchWidth=fetchWidth))
    validator.io.instruction_index := get_decomposed_icache_address(coreParameters, io.mem_rsp.bits.fetch_PC).instruction_offset 

    for(i <- 0 until fetchWidth){
        if (i < fetchWidth/2){
            valid_bits(i):= validator.io.instruction_output(fetchWidth-1-i) && io.mem_rsp.valid
        }else{
            valid_bits(i):= RegNext(validator.io.instruction_output(fetchWidth-1-i) && io.mem_rsp.valid)
        }
    }

    aligned_fetch_packet_1.fetch_PC := io.mem_rsp.bits.fetch_PC

    val instructions = Wire(Vec(4, UInt(32.W)))   

    lower_bits_valid := 0.B
    aligned_fetch_packet_1 := DontCare
    aligned_fetch_packet_2 := DontCare

    aligned_fetch_packet_2.fetch_PC := fetch_reg.fetch_PC + get_PC_increment(coreParameters, fetch_reg.fetch_PC)
    for(i <- 0 until fetchWidth){
        aligned_fetch_packet_1.valid_bits(i) := 0.B
        aligned_fetch_packet_2.valid_bits(i) := 0.B
        is_RVC(i*2) := 0.B
        is_RVC(i*2 + 1) := 0.B
        instructions(i) := 0.B
        upper_bits(i*2) := 0.B
        upper_bits(i*2 + 1) := 0.B
        aligned_fetch_packet_1.instructions(i).packet_index := i.U
        aligned_fetch_packet_1.instructions(i).ROB_index    := 0.U

        aligned_fetch_packet_2.instructions(i).packet_index := i.U
        aligned_fetch_packet_2.instructions(i).ROB_index    := 0.U
    }
    for(i <- 0 until fetchWidth){
        when(valid_bits(i)){
            if (i < fetchWidth/2){
                instructions(i) := io.mem_rsp.bits.instruction_data((i+1)*32-1, (i)*32)
            }else{
                instructions(i) := fetch_reg.instruction_data((i+1)*32-1, (i)*32)
            } 
            if (i > 0){
                is_RVC(i*2) := instructions(i)(1,0) =/= 3.U
            }else{
                is_RVC(0) := instructions(i)(1,0) =/= 3.U && !lower_bits_valid
            }
            is_RVC(i*2 +1) := instructions(i)(17,16) =/= 3.U && is_RVC(i*2)
        }
    }

    when(aligned_fetch_packet_1.fetch_PC(1) === 1.B || (is_RVC(0) && aligned_fetch_packet_1.fetch_PC(1) === 0.B)){
        upper_bits(0) := 1.B
    }

    for(i <- 1 until fetchWidth*2){
        when((upper_bits(i-1) === 1.B && is_RVC(i)) || upper_bits(i-1) === 0.B){
            upper_bits(i) := 1.B
        }
    }

    for(i <- 0 until fetchWidth){

        if (i < fetchWidth/2){
            if (i==0){
                when (lower_bits_valid && upper_bits(0)){
                    aligned_fetch_packet_1.instructions(i*2).instruction := Cat(instructions(i)(15, 0), lower_bits)
                    aligned_fetch_packet_1.valid_bits(i*2) := 1.B
                }.elsewhen(is_RVC(0) && upper_bits(0)){
                    expanders(0).io.compressed_instr := instructions(0)(15, 0)
                    aligned_fetch_packet_1.instructions(0).instruction := expanders(0).io.instruction
                    aligned_fetch_packet_1.valid_bits(0) := 1.B
                }.elsewhen(valid_bits(0)){
                    aligned_fetch_packet_1.instructions(0).instruction := instructions(0)
                    aligned_fetch_packet_1.valid_bits(0) := 1.B
                }
            }else{
                when(is_RVC(i*2) && upper_bits(i*2 - 1)){
                    expanders(i*2).io.compressed_instr := instructions(i)(15, 0)
                    aligned_fetch_packet_1.instructions(i*2).instruction := expanders(i*2).io.instruction
                    aligned_fetch_packet_1.valid_bits(i*2) := 1.B
                }.elsewhen(valid_bits(i) && upper_bits(i*2 + 1)){
                    aligned_fetch_packet_1.instructions(i*2).instruction := instructions(i)
                    aligned_fetch_packet_1.valid_bits(i*2) := 1.B
                }.elsewhen(valid_bits(i) && valid_bits(i-1) && upper_bits(i*2)){
                    aligned_fetch_packet_1.instructions(i*2).instruction := Cat(instructions(i)(15,0), instructions(i-1)(31,16))
                    aligned_fetch_packet_1.valid_bits(i*2) := 1.B
                }
            }

            when(is_RVC(i*2 + 1) && upper_bits(i*2)){
                expanders(i*2 + 1).io.compressed_instr := instructions(i)(31, 16)
                aligned_fetch_packet_1.instructions(i*2 + 1).instruction := expanders(i*2 + 1).io.instruction
                aligned_fetch_packet_1.valid_bits(i*2 + 1) := 1.B
            }
            
        } else {

            when(is_RVC(i*2) && upper_bits(i*2 - 1)){
                expanders(i*2).io.compressed_instr := instructions(i)(15, 0)
                aligned_fetch_packet_2.instructions((i-2)*2).instruction := expanders(i*2).io.instruction
                aligned_fetch_packet_2.valid_bits((i-2)*2) := 1.B
            }.elsewhen(valid_bits(i) && upper_bits(i*2 + 1)){
                aligned_fetch_packet_2.instructions((i-2)*2).instruction := instructions(i)
                aligned_fetch_packet_2.valid_bits((i-2)*2) := 1.B
            }.elsewhen(valid_bits(i) && valid_bits(i-1) && upper_bits(i*2)){
                aligned_fetch_packet_2.instructions((i-2)*2).instruction := Cat(instructions(i)(15,0), instructions(i-1)(31,16))
                aligned_fetch_packet_2.valid_bits((i-2)*2) := 1.B
            }

            // when(is_RVC(i*2)){
            //     expanders(i*2).io.compressed_instr := instructions(i)(15, 0)
            //     aligned_fetch_packet_2.instructions((i-2)*2).instruction := expanders(i*2).io.instruction
            //     aligned_fetch_packet_2.valid_bits((i-2)*2) := 1.B
            // }.elsewhen(valid_bits(i)){
            //     aligned_fetch_packet_2.instructions((i-2)*2).instruction := instructions(i)
            //     aligned_fetch_packet_2.valid_bits((i-2)*2) := 1.B
            // }

            when(is_RVC(i*2 + 1) && upper_bits(i*2)){
                expanders(i*2 + 1).io.compressed_instr := instructions(i)(31, 16)
                aligned_fetch_packet_2.instructions((i-2)*2 + 1).instruction := expanders(i*2 + 1).io.instruction
                aligned_fetch_packet_2.valid_bits((i-2)*2 + 1) := 1.B
            }

            if(i == fetchWidth - 1) {
                when(!upper_bits(i*2 + 1)){
                    aligned_fetch_packet_2.valid_bits((i-2)*2 + 1) := 0.B 
                    lower_bits := instructions(i)(31,16)
                    lower_bits_valid := 1.B
                }
            }

            // when(is_RVC(i*2 + 1)){
            //     expanders(i*2 + 1).io.compressed_instr := instructions(i)(31, 16)
            //     aligned_fetch_packet_2.instructions((i-2)*2 + 1).instruction := expanders(i*2 + 1).io.instruction
            //     aligned_fetch_packet_2.valid_bits((i-2)*2 + 1) := 1.B
            // }.elsewhen(valid_bits(i) && !is_RVC(i*2)){
            //     if(i < fetchWidth - 1){
            //         aligned_fetch_packet_2.instructions((i-2)*2 + 1).instruction := Cat(instructions(i+1)(15,0), instructions(i)(31,16))
            //     } else {
            //         aligned_fetch_packet_2.valid_bits((i-2)*2 + 1) := 0.B 
            //         lower_bits := instructions(i)(31,16)
            //         lower_bits_valid := 1.B
            //     }
            //     aligned_fetch_packet_2.valid_bits((i-2)*2 + 1) := 1.B
            // }

        }
    }

    io.aligned_fetch_packet.bits := DontCare
    io.aligned_fetch_packet.valid := 0.B
    when (io.mem_rsp.fire && io.aligned_fetch_packet.ready){
        fetch_reg := io.mem_rsp.bits
        ready_reg := 0.B
        io.aligned_fetch_packet.bits := aligned_fetch_packet_1
        io.aligned_fetch_packet.bits.fetch_PC := io.mem_rsp.bits.fetch_PC
        io.aligned_fetch_packet.valid := 1.B
    }.elsewhen(RegNext(io.mem_rsp.fire) && io.aligned_fetch_packet.ready){
        io.aligned_fetch_packet.bits := aligned_fetch_packet_2
        ready_reg := 1.B
        io.aligned_fetch_packet.valid := 1.B
    }
    io.mem_rsp.ready := ready_reg
}

class aligner_uncompressed(coreParameters:CoreParameters) extends Module{
    import coreParameters._

    val io = IO(new Bundle{
        //val flush                 =   Input(Bool())
        val mem_rsp                            =   Flipped(Decoupled(new mem_response(coreParameters)))
        val aligned_fetch_packet               =   Decoupled(new fetch_packet(coreParameters))           
    })

    io.aligned_fetch_packet.bits := DontCare

    io.aligned_fetch_packet.bits.fetch_PC := io.mem_rsp.bits.fetch_PC

    for(i <- 0 until fetchWidth){
        io.aligned_fetch_packet.bits.instructions(i).instruction  := io.mem_rsp.bits.instruction_data((i+1)*32-1, (i)*32) 
        io.aligned_fetch_packet.bits.instructions(i).packet_index := i.U
        io.aligned_fetch_packet.bits.instructions(i).ROB_index    := 0.U
    }

    val validator = Module(new instruction_validator(fetchWidth=fetchWidth))
    validator.io.instruction_index := get_decomposed_icache_address(coreParameters, io.mem_rsp.bits.fetch_PC).instruction_offset 

    for(i <- 0 until fetchWidth){
        io.aligned_fetch_packet.bits.valid_bits(i):= validator.io.instruction_output(fetchWidth-1-i) && io.mem_rsp.valid
    }

    io.aligned_fetch_packet.valid := io.mem_rsp.valid
    io.mem_rsp.ready := io.aligned_fetch_packet.ready

}

class fetch_queue(coreParameters:CoreParameters) extends Module{
    import coreParameters._

    val io = IO(new Bundle{
        val flush                 =   Input(Bool())
        val enq                   =   Flipped(Decoupled(new mem_response(coreParameters)))           
        val deq                   =   Decoupled(new fetch_packet(coreParameters))           
    })

    val instruction_Q   =   Module(new Queue(new fetch_packet(coreParameters), 32, flow=true, hasFlush=true, useSyncReadMem=true))
    val rvc:Boolean = false
    val aligner         =   Module(new instruction_aligner(coreParameters))
    // if (rvc){
    //     val aligner         =   Module(new instruction_aligner(coreParameters))
    // } else {
    //     val aligner         =   Module(new aligner_uncompressed(coreParameters))
    // }

    aligner.io := DontCare

    aligner.io.mem_rsp.valid     := io.enq.valid
    aligner.io.aligned_fetch_packet.ready := instruction_Q.io.enq.ready
    aligner.io.mem_rsp.bits      := io.enq.bits

    instruction_Q.io.enq.bits             := aligner.io.aligned_fetch_packet.bits
    instruction_Q.io.enq.valid            := aligner.io.aligned_fetch_packet.valid
    instruction_Q.io.flush.get            := io.flush
    instruction_Q.io.deq                  <> io.deq

    io.enq.ready                          := aligner.io.mem_rsp.ready

}