///* ------------------------------------------------------------------------------------
//* Filename: frontend.scala
//* Author: Hakam Atassi
//* Date: Jun 1 2024
//* Description: A module that allocates instructions from the frontend into the backend
//* License: MIT
//*
//* Copyright (c) 2024 by Hakam Atassi
//*
//* Permission is hereby granted, free of charge, to any person obtaining a copy
//* of this software and associated documentation files (the "Software"), to deal
//* in the Software without restriction, including without limitation the rights
//* to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//* copies of the Software, and to permit persons to whom the Software is
//* furnished to do so, subject to the following conditions:
//* 
//* The above copyright notice and this permission notice shall be included in all
//* copies or substantial portions of the Software.
//*
//* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//* IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//* FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//* AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//* LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
//* SOFTWARE.
//* ------------------------------------------------------------------------------------ 
//*/

//package ChaosCore

//import chisel3._
//import chisel3.util._


//class allocator(parameters:Parameters) extends Module{
    //import parameters._

    //val portCount = getPortCount(parameters)
    //val portCountBits = log2Ceil(portCount)


    //val io = IO(new Bundle{

        //// INSTRUCTION //
        //val renamed_decoded_fetch_packet    =   Vec(fetchWidth, Flipped(Decoupled(new decoded_instruction(parameters))))
        
        //// ALLOCATE //
        //// Backend
        //val backend_packet                  =   Output(Vec(dispatchWidth, new backend_packet(parameters)))

        //// ALLOCATE //
        //// Frontend


    //})
    //io.renamed_decoded_fetch_packet.ready := DontCare


    //// Step 1: Assign backend + ROB packets based on available resources (This just sets/resets backend_packet valid bits)
    //// Step 2: Ready bits???
    

    //var max_int_instructions = PopCount(io.INTRS_ready)
    //var max_mem_instructions = PopCount(io.MEMRS_ready)

    //var max_rob_entries      = PopCount(io.ROB_packet.map)  //???

    //for(i <- 0 until dispatchWidth){
        //when(io.renamed_decoded_fetch_packet.valid && io.renamed_decoded_fetch_packet.RS_type === RS_types.INT && max_int_instructions > 0.U){
            //io.backend_packet(i)        := io.renamed_decoded_fetch_packet(i).bits.decoded_instruction
            //io.backend_packet(i).ready  := 1.B
            //max_int_instructions        := max_int_instructions - 1.U
        //}.elsewhen(io.renamed_decoded_fetch_packet.valid && io.renamed_decoded_fetch_packet.RS_type === RS_types.MEM && max_mem_instructions > 0.U){
            //io.backend_packet(i)        := io.renamed_decoded_fetch_packet(i).bits.decoded_instruction
            //io.backend_packet(i).ready  := 1.B
            //max_mem_instructions        := max_mem_instructions - 1.U
        //}.otherwise{
            //io.backend_packet(i).ready  := 0.B
            //io.backend_packet(i).bits   := 0.U.asTypeOf(new backend_packet(parameters))
        //}
    //}



    /////////////////////////
    //// ASSIGN ROB PACKET //
    /////////////////////////

    //for(i <- 0 until dispatchWidth){
        //io.ROB_packet     := DontCare
    //}

    ////////////////////////////
    //// ASSIGN SOURCES READY //
    ////////////////////////////

    //val ready_reg = RegInit(UInt(physicalRegCount.W), ((1<<physicalRegCount)-1).U)

    //for(i <- 0 until dispatchWidth){ // Assign ready bits for instructions
        //val ready_bits = Wire(new sources_ready())
        //ready_bits.RS1_ready := ready_reg(io.backend_packet(i).decoded_instruction.RS1)
        //ready_bits.RS2_ready := ready_reg(io.backend_packet(i).decoded_instruction.RS2)
        //io.backend_packet(i).ready_bits             := ready_bits
    //}



    //// TODO: set not ready on allocate


    ///////////////////////////
    //// UPDATE READY STATUS //
    ///////////////////////////


    //// TODO: set ready on complete


//}