/* ------------------------------------------------------------------------------------
* Filename: FP_decoder.scala
* Author: Hakam Atassi
* Date: Mar 15 2025
* Description: The FP component of the instruction decoder
* License: MIT
*
* Copyright (c) 2025 by Hakam Atassi
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
import java.io.{File, FileWriter}
import java.rmi.server.UID

import helperFunctions._

import chisel3.util.experimental.decode._

object decode_FP {
    def apply:Map[BitPat, BitPat] = {



        // helper fields
        // "1" and "0" => are concatenated to a bit string which is then converted to an int
        // "?" is a dont care
        val Y = "1"
        val N = "0"
        val R_NONE = "?????"
        val RS3_NONE = "?????"
        val RM_NONE = "???"
        val FUNCT7_NONE = "???????"
        val FUNCT3_NONE = "???"
        val IMM_NONE = "????????????"

        def binString(n:UInt): String = {
            n.litValue.toString(2).reverse.padTo(n.getWidth, '0').reverse
        }

        // INSTRUCTION STEERING //
        // needs ALU
        // needs branch unit
        // needs CSR
        // needs memory
        // needs mul
        // needs div
        // needs FPU

        // OPERAND //
        // RS1 valid
        // RS2 valid
        // RD valid
        // IMM
        // Unsigned
        
        // INSTRUCTION TYPE //
        // Arithmetic (add/sub/div/mul/etc)
        // Load
        // Store
        // CTRL (branch)
        // CSR R/W
        // XRET ?
        // ENV (ECALL/EBREAK)
        // FENCE ?


        // MISC //
        // FLUSH

        Map( // (Hint: Scroll right to see mappings)
                //                                                                                                                                                                                                                          // INSTRUCTION STEERING //                      // EXEC.//                      // INSTRUCTION TYPE //                                            // MISC //    // FP //
                //                                                                                                                                                                                                                          needs ALU unit                                  RS1 valid                       ADD/SUB                                                           FLUSH         RS3 valid
                //                                                                                                                                                                                                                          |   needs branch unit                           |   RS2 valid                   |   MUL/DIV/SQRT                                                  |             |   FMA/FMS
                //                                                                                                                                                                                                                          |   |   needs CSR unit                          |   |   RD valid                |   |   Mem load                                                  |             |   |
                //                                                                                                                                                                                                                          |   |   |   needs memory unit                   |   |   |   IMM                 |   |   |   Mem Store                                             |             |   |   Sign Inject
                //                                                                                                                                                                                                                          |   |   |   |   needs mul unit                  |   |   |   |   Unsigned        |   |   |   |   ctrl                                              |             |   |   |   Min/Max
                //                                                                                                                                                                                                                          |   |   |   |   |   needs div unit              |   |   |   |   |               |   |   |   |   |   XRET                                          |             |   |   |   |   Convert 
                //                                                                                                                                                                                                                          |   |   |   |   |   |   needs_FPU               |   |   |   |   |               |   |   |   |   |   |   CSRRW                                     |             |   |   |   |   |   Move
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   ENV                                   |             |   |   |   |   |   |   Compare
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   FENCE                             |             |   |   |   |   |   |   |   Classify
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   LUI                           |             |   |   |   |   |   |   |   |   FP RS
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   |   AUIPC                     |             |   |   |   |   |   |   |   |   |   FP RD 
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   |   |   JAL                   |             |   |   |   |   |   |   |   |   |   |   
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   |   |   |   JALR              |             |   |   |   |   |   |   |   |   |   |   
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   |   |   |   |                 |             |   |   |   |   |   |   |   |   |   |   
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   |   |   |   |                 |             |   |   |   |   |   |   |   |   |   |    
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   |   |   |   |                 |             |   |   |   |   |   |   |   |   |   |   
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   |   |   |   |                 |             |   |   |   |   |   |   |   |   |   |   
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   |   |   |   |                 |             |   |   |   |   |   |   |   |   |   |   
                //                                                                                                                                                                                                                          |   |   |   |   |   |   |                       |   |   |   |   |               |   |   |   |   |   |   |   |   |   |   |   |   |                 |             |   |   |   |   |   |   |   |   |   |             
                BitPat("b1"+ IMM_NONE + R_NONE + "010" + R_NONE + s"00001")                                                                                                                                                 -> BitPat("b" + N + N + N + Y + N + N + N +                     Y + N + Y + N + N +             N + N + Y + N + N + N + N + N + N + N + N + N + N +               N           + N + N + N + N + N + N + N + N + N + Y ), // FLW  //FIXME: for renaming, these need to be FP (so they mark the correct RD, etc, but must also read the correct RSs and go to the AGU)
                BitPat("b1"+ R_NONE + R_NONE + R_NONE + "010" + R_NONE + s"01001")                                                                                                                                          -> BitPat("b" + N + N + N + N + N + N + N +                     Y + Y + N + N + N +             N + N + N + Y + N + N + N + N + N + N + N + N + N +               N           + N + N + N + N + N + N + N + N + N + N ), // FSW
                BitPat("b1"+ R_NONE + "00" + R_NONE + R_NONE + RM_NONE + R_NONE + s"10000")                                                                                                                                 -> BitPat("b" + N + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N           + Y + Y + N + N + N + N + N + N + Y + Y ), // FMADD.S
                BitPat("b1"+ R_NONE + "00" + R_NONE + R_NONE + RM_NONE + R_NONE + s"10001")                                                                                                                                 -> BitPat("b" + N + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N           + Y + Y + N + N + N + N + N + N + Y + Y ), // FMSUB.S
                BitPat("b1"+ R_NONE + "00" + R_NONE + R_NONE + RM_NONE + R_NONE + s"10010")                                                                                                                                 -> BitPat("b" + N + N + N + N + N + N + Y +                     Y + Y + Y + N + Y +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N           + Y + Y + N + N + N + N + N + N + Y + Y ), // FNMSUB.S
                BitPat("b1"+ R_NONE + "00" + R_NONE + R_NONE + RM_NONE + R_NONE + s"10011")                                                                                                                                 -> BitPat("b" + N + N + N + N + N + N + Y +                     Y + Y + Y + N + Y +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N           + Y + Y + N + N + N + N + N + N + Y + Y ), // FNMADD.S
                BitPat("b1"+ "0000000" + R_NONE + R_NONE + RM_NONE + R_NONE + "10100")                                                                                                                                      -> BitPat("b" + N + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             Y + N + N + N + N + N + N + N + N + N + N + N + N +               N           + N + N + N + N + N + N + N + N + Y + Y ), // FADD.S
                BitPat("b1"+ "0000100" + R_NONE + R_NONE + RM_NONE + R_NONE + "10100")                                                                                                                                      -> BitPat("b" + N + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             Y + N + N + N + N + N + N + N + N + N + N + N + N +               N           + N + N + N + N + N + N + N + N + Y + Y ), // FSUB.S
                BitPat("b1"+ "0001000" + R_NONE + R_NONE + RM_NONE + R_NONE + "10100")                                                                                                                                      -> BitPat("b" + N + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + Y + N + N + N + N + N + N + N + N + N + N + N +               N           + N + N + N + N + N + N + N + N + Y + Y ), // FMUL.S
                BitPat("b1"+ "0001100" + R_NONE + R_NONE + RM_NONE + R_NONE + "10100")                                                                                                                                      -> BitPat("b" + N + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + Y + N + N + N + N + N + N + N + N + N + N + N +               N           + N + N + N + N + N + N + N + N + Y + Y ), // FDIV.S
                BitPat("b1"+ "0101100" + "00000" + R_NONE + RM_NONE + R_NONE + "10100")                                                                                                                                     -> BitPat("b" + N + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + Y + N + N + N + N + N + N + N + N + N + N + N +               N           + N + N + N + N + N + N + N + N + Y + Y ), // FSQRT.S
                BitPat("b1"+ "0010000" + R_NONE + R_NONE + "000" + R_NONE + "10100")                                                                                                                                        -> BitPat("b" + N + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N           + N + N + Y + N + N + N + N + N + Y + Y ), // FSGNJ.S
                BitPat("b1"+ "0010000" + R_NONE + R_NONE + "001" + R_NONE + "10100")                                                                                                                                        -> BitPat("b" + N + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N           + N + N + Y + N + N + N + N + N + Y + Y ), // FSGNJN.S
                BitPat("b1"+ "0010000" + R_NONE + R_NONE + "010" + R_NONE + "10100")                                                                                                                                        -> BitPat("b" + N + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N           + N + N + Y + N + N + N + N + N + Y + Y ), // FSGNJX.S
                BitPat("b1"+ "0010100" + R_NONE + R_NONE + "000" + R_NONE + "10100")                                                                                                                                        -> BitPat("b" + N + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N           + N + N + N + Y + N + N + N + N + Y + Y ), // FMIN.S
                BitPat("b1"+ "0010100" + R_NONE + R_NONE + "001" + R_NONE + "10100")                                                                                                                                        -> BitPat("b" + N + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N           + N + N + N + Y + N + N + N + N + Y + Y ), // FMAX.S
                BitPat("b1"+ "1010000" + R_NONE + R_NONE + "010" + R_NONE + "10100")                                                                                                                                        -> BitPat("b" + N + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N           + N + N + N + N + N + N + Y + N + Y + Y ), // FEQ.S
                BitPat("b1"+ "1010000" + R_NONE + R_NONE + "001" + R_NONE + "10100")                                                                                                                                        -> BitPat("b" + N + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N           + N + N + N + N + N + N + Y + N + Y + Y ), // FLT.S
                BitPat("b1"+ "1010000" + R_NONE + R_NONE + "000" + R_NONE + "10100")                                                                                                                                        -> BitPat("b" + N + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N           + N + N + N + N + N + N + Y + N + Y + Y ), // FLE.S
                BitPat("b1"+ "1110000" + "00000" + R_NONE + "001" + R_NONE + "10100")                                                                                                                                       -> BitPat("b" + N + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N           + N + N + N + N + N + N + N + Y + Y + Y ), // FCLASS.S
                BitPat("b1"+ "1110000" + "00000" + R_NONE + "000" + R_NONE + "10100")                                                                                                                                       -> BitPat("b" + N + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N           + N + N + N + N + Y + N + N + N + Y + Y ), // FMV.X.W      (Move Float to Int)
                BitPat("b1"+ "1111000" + "00000" + R_NONE + "000" + R_NONE + "10100")                                                                                                                                       -> BitPat("b" + N + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N           + N + N + N + N + N + N + N + N + Y + Y ), // FMV.W.X      (Move Int to Float)
                BitPat("b1"+ "1100000" + "00000" + R_NONE + RM_NONE + R_NONE + "10100")                                                                                                                                     -> BitPat("b" + N + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N           + N + N + N + N + Y + N + N + N + N + N ), // FCVT.W.S     (Flt Convert to SInt)
                BitPat("b1"+ "1100000" + "00001" + R_NONE + RM_NONE + R_NONE + "10100")                                                                                                                                     -> BitPat("b" + N + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N           + N + N + N + N + Y + N + N + N + N + N ), // FCVT.WU.S    (Flt Convert to UInt)
                BitPat("b1"+ "1101000" + "00000" + R_NONE + RM_NONE + R_NONE + "10100")                                                                                                                                     -> BitPat("b" + N + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N           + N + N + N + N + N + N + N + N + N + N ), // FCVT.S.W     (Flt Conv from Sign Int)
                BitPat("b1"+ "1101000" + "00001" + R_NONE + RM_NONE + R_NONE + "10100")                                                                                                                                     -> BitPat("b" + N + N + N + N + N + N + Y +                     Y + Y + Y + N + N +             N + N + N + N + N + N + N + N + N + N + N + N + N +               N           + N + N + N + N + N + N + N + N + N + N ), // FCVT.S.WU    (Flt Conv from Uns Int)

            )
    }
}