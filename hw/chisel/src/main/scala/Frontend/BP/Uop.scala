/* ------------------------------------------------------------------------------------
* Filename: Uop.scala
* Author: Hakam Atassi
* Date: Apr 23 2024
* Description: An enum of all the possible Uops exiting the decoder(s)
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


//object instructionType extends ChiselEnum {
    //val R,
        //I,
        //S,
        //B, 
        //U,
        //J = Value
//} 


//object Uop extends ChiselEnum {
    //val LUI,
        //AUIPC,
        //JAL,
        //JALR,
        //BEQ,
        //BNE,
        //BLT,
        //BGE,
        //BLTU,
        //BGEU,
        //LB,
        //LH,
        //LW,
        //LBU,
        //LHU,
        //SB,
        //SH,
        //SW,
        //ADDI,
        //SLTI,
        //SLTIU,
        //XORI,
        //ORI,
        //ANDI,
        //SLLI,
        //SRLI,
        //SRAI,
        //ADD,
        //SUB,
        //SLL,
        //SLT,
        //SLTU,
        //XOR,
        //SRL,
        //SRA,
        //OR,
        //AND,
        //FENCE,
        //ECALL,
        //EBREAK = Value

//} 


object Uop extends ChiselEnum {
    val 
        LUI,
        AUIPC,
        JAL,
        JALR,
        BRANCH,
        LOAD,
        STORE,
        IMM_ARITH,
        REG_ARITH,
        FENCE,
        ECALL,
        EBREAK = Value

} 

