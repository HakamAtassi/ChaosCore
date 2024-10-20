/* ------------------------------------------------------------------------------------
* Filename: decoder.scala
* Author: Hakam Atassi
* Date: May 9 2024
* Description: A single instruction decoder and the N wide fetch packet decoder.
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
import java.io.{File, FileWriter}
import java.rmi.server.UID

import helperFunctions._

class decoder(coreParameters:CoreParameters) extends Module{   // basic decoder and field extraction
    import coreParameters._
    import InstructionType._
    val io = IO(new Bundle{
        val instruction         = Flipped(Decoupled(new Instruction(coreParameters)))

        val decoded_instruction = Decoupled(new decoded_instruction(coreParameters))
    })




    val instruction = io.instruction.bits.instruction

    // Direct instruction fields
    val opcode      = instruction(6, 0)
    val RS1         = instruction(19, 15)
    val RS2         = instruction(24, 20)
    val PRD         = instruction(11, 7)
    val IMM         = getImm(instruction)

    dontTouch(IMM)
    

    val FUNCT3      = instruction(14, 12)
    val FUNCT7      = instruction(31, 25)


    val (instructionType, valid) = InstructionType.safe(opcode(6, 2))
    assert(valid, "Enum state must be valid, got %x!",instruction)


    dontTouch(instructionType)

    //Do we check entire funct7 field or just check for single bit?
    val MULTIPLY    =   (instructionType === OP && FUNCT7 === 0x1.U)


    val SUBTRACT    =   (instructionType === OP && FUNCT7 === 0x20.U) || (instructionType === OP_IMM && FUNCT3 === 0x5.U && FUNCT7 === 0x20.U)


    val IS_IMM   =      (instructionType === OP_IMM)    || 
                        (instructionType === LUI)       || 
                        (instructionType === AUIPC)     || 
                        (instructionType === STORE)     || 
                        (instructionType === LOAD)      || 
                        (instructionType === BRANCH)    || 
                        (instructionType === JAL)       || 
                        (instructionType === JALR)      ||
                        ((instructionType === SYSTEM) && (FUNCT3 === 5.U || FUNCT3 === 6.U || FUNCT3 === 7.U))

    val needs_div            =   (instructionType === OP) && FUNCT7(0)  // FIXME: is this correct??
    val needs_mul            =   (instructionType === OP) && FUNCT7(0)  // FIXME: is this correct??
    val needs_branch_unit    =   (instructionType === BRANCH) || (instructionType === JAL) || (instructionType === JALR) || (instructionType === AUIPC)
    val needs_CSRs           =   (instructionType === SYSTEM) && (FUNCT3 === 0x0.U || FUNCT3 === 0x1.U || FUNCT3 === 0x2.U || FUNCT3 === 0x3.U || FUNCT3 === 0x5.U || FUNCT3 === 0x6.U || FUNCT3 === 0x7.U)
    val needs_ALU            =   ((instructionType === OP) &&
                                 ((FUNCT7 === 0x20.U) || (FUNCT7 === 0x00.U))) || 
                                 (instructionType === OP_IMM) || (instructionType === LUI)



    val ECALL               =   instruction === "b00000000000000000000000001110011".U 
    val MRET                =   instruction === "b00110000001000000000000001110011".U 
    //instruciton === "b00110000001000000000000001110011".U //(instructionType === SYSTEM) && (FUNCT3 === 0x0.U)


    val FENCE               =   ((instructionType === MISC_MEM) && FUNCT3 === 0x0.U)





    // Assign output

    io.decoded_instruction.valid    := io.instruction.valid
    io.instruction.ready            := io.decoded_instruction.ready

    val initialReady = Wire(new sources_ready)
    initialReady.RS1_ready := false.B
    initialReady.RS2_ready := false.B

    io.decoded_instruction.bits.ready_bits      :=   initialReady

    io.decoded_instruction.bits.RD_valid := (instructionType === OP         || 
                                            instructionType === OP_IMM      || 
                                            instructionType === LOAD        || 
                                            instructionType === JAL         || 
                                            instructionType === JALR        || 
                                            instructionType === LUI         || 
                                            instructionType === AUIPC       || 
                                            (instructionType === SYSTEM &&  FUNCT3=/=0.U))     && 
                                            io.instruction.valid

    io.decoded_instruction.bits.RS1_valid            := (instructionType === OP         || 
                                                        instructionType === OP_IMM      || 
                                                        instructionType === LOAD        || 
                                                        instructionType === STORE       || 
                                                        instructionType === JALR        || 
                                                        (needs_CSRs && !IS_IMM) ||
                                                        instructionType === BRANCH)     && 
                                                        io.instruction.valid

    io.decoded_instruction.bits.RS2_valid            := (instructionType === OP         ||
                                                        instructionType === STORE       || 
                                                        instructionType === BRANCH)     && 
                                                        io.instruction.valid


    io.decoded_instruction.bits.RD                   := PRD
    io.decoded_instruction.bits.PRDold               := DontCare
    io.decoded_instruction.bits.PRD                  := DontCare
    io.decoded_instruction.bits.RS1                  := RS1
    io.decoded_instruction.bits.RS2                  := RS2
    io.decoded_instruction.bits.IMM                  := IMM
    io.decoded_instruction.bits.FUNCT3               := FUNCT3
    io.decoded_instruction.bits.MULTIPLY             := MULTIPLY    // Multiply or Divide
    io.decoded_instruction.bits.SUBTRACT             := SUBTRACT    // subtract or arithmetic shift...
    io.decoded_instruction.bits.FENCE                := FENCE       // FLUSH of ANY TYPE    (they all do the same thing)
    io.decoded_instruction.bits.MRET                 := MRET       // FLUSH of ANY TYPE    (they all do the same thing)
    io.decoded_instruction.bits.IS_IMM               := IS_IMM   // subtract or arithmetic shift...





    when(instructionType === LOAD){
        io.decoded_instruction.bits.memory_type              := memory_type_t.LOAD
    }.elsewhen(instructionType === STORE){
        io.decoded_instruction.bits.memory_type              := memory_type_t.STORE
    }.otherwise{
        io.decoded_instruction.bits.memory_type              := memory_type_t.NONE
    }

    val needs_memory         =   (instructionType === STORE) || (instructionType === LOAD)

    io.decoded_instruction.bits.packet_index         := io.instruction.bits.packet_index 
    io.decoded_instruction.bits.instructionType      := instructionType
    io.decoded_instruction.bits.ROB_index            := 0.U
    io.decoded_instruction.bits.MOB_index            := 0.U
    io.decoded_instruction.bits.needs_ALU            := needs_ALU
    io.decoded_instruction.bits.needs_memory         := needs_memory
    io.decoded_instruction.bits.needs_branch_unit    := needs_branch_unit
    io.decoded_instruction.bits.needs_CSRs           := needs_CSRs
    io.decoded_instruction.bits.needs_mul            := needs_mul
    io.decoded_instruction.bits.needs_div            := needs_div
    io.decoded_instruction.bits.ECALL                := ECALL

    io.decoded_instruction.bits.access_width                 := access_width_t.NONE
    io.decoded_instruction.bits.mem_signed  := 0.B
    when(FUNCT3  === "b000".U && needs_memory){ // LB
        io.decoded_instruction.bits.access_width             := access_width_t.B
        io.decoded_instruction.bits.mem_signed  := 1.B
    }.elsewhen(FUNCT3  === "b001".U && needs_memory){   // LHW
        io.decoded_instruction.bits.access_width             := access_width_t.HW
        io.decoded_instruction.bits.mem_signed  := 1.B
    }.elsewhen(FUNCT3  === "b010".U && needs_memory){   // LW
        io.decoded_instruction.bits.access_width             := access_width_t.W
        io.decoded_instruction.bits.mem_signed  := 1.B
    }.elsewhen(FUNCT3  === "b100".U && needs_memory){   // LBU
        io.decoded_instruction.bits.access_width             := access_width_t.B
        io.decoded_instruction.bits.mem_signed  := 0.B
    }.elsewhen(FUNCT3  === "b101".U && needs_memory){   // LHWU
        io.decoded_instruction.bits.access_width             := access_width_t.HW
        io.decoded_instruction.bits.mem_signed  := 0.B
    }

    //io.decoded_instruction.bits.instruction_ID           := DontCare



}


class fetch_packet_decoder(coreParameters:CoreParameters) extends Module{
    import coreParameters._
    val io = IO(new Bundle{
        // FLUSH
        val flush = Flipped(ValidIO(new flush(coreParameters)))

        val fetch_packet         =  Flipped(Decoupled(new fetch_packet(coreParameters)))          // Fetch packet result (To Decoders)

        val decoded_fetch_packet =  Decoupled(new decoded_fetch_packet(coreParameters))
    })

    ////////////////////
    // OUTPUT BUNDLES //
    ////////////////////
    val decoded_fetch_packet    = Wire(Decoupled(new decoded_fetch_packet(coreParameters)))



    val decoders: Seq[decoder] = Seq.tabulate(fetchWidth) { w =>
        Module(new decoder(coreParameters))
    }

    var fetch_packet_ready = 1.B
    for(i <- 0 until fetchWidth){
        decoders(i).io.instruction.bits     := io.fetch_packet.bits.instructions(i)
        decoders(i).io.instruction.valid    := io.fetch_packet.valid && io.fetch_packet.bits.valid_bits(i)
    }
    io.fetch_packet.ready :=  io.decoded_fetch_packet.ready

    // Register outputs //
    for(i <- 0 until fetchWidth){
        decoded_fetch_packet.bits.decoded_instruction(i) := decoders(i).io.decoded_instruction.bits
        decoders(i).io.decoded_instruction.ready         := io.decoded_fetch_packet.ready
        io.fetch_packet.ready                            := io.decoded_fetch_packet.ready
    }

    decoded_fetch_packet.valid                           := io.fetch_packet.valid && !io.flush.valid
    decoded_fetch_packet.bits.fetch_PC                   := io.fetch_packet.bits.fetch_PC
    decoded_fetch_packet.bits.valid_bits                 := io.fetch_packet.bits.valid_bits
    decoded_fetch_packet.bits.GHR                        := io.fetch_packet.bits.GHR
    decoded_fetch_packet.bits.NEXT                       := io.fetch_packet.bits.NEXT
    decoded_fetch_packet.bits.TOS                        := io.fetch_packet.bits.TOS

    decoded_fetch_packet.bits.free_list_front_pointer    := DontCare // This is fine. Allocated during rename


    //////////////////
    // SKID BUFFERS //
    //////////////////

    val decoded_fetch_packet_out_Q                      = Module(new Queue(new decoded_fetch_packet(coreParameters), 2, flow=false, hasFlush=true, useSyncReadMem=false))

    decoded_fetch_packet.valid                          := (io.fetch_packet.fire) && !io.flush.valid

    decoded_fetch_packet.bits.prediction                := io.fetch_packet.bits.prediction

    decoded_fetch_packet_out_Q.io.enq                   <> decoded_fetch_packet
    decoded_fetch_packet_out_Q.io.deq                   <> io.decoded_fetch_packet
    decoded_fetch_packet_out_Q.io.deq.ready             := io.decoded_fetch_packet.ready
    decoded_fetch_packet_out_Q.io.flush.get             := io.flush.valid




    io.fetch_packet.ready                               := RegNext(io.decoded_fetch_packet.ready)







}
