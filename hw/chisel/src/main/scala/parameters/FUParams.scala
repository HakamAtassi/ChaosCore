/* ------------------------------------------------------------------------------------
* Filename: AddressMap.scala
* Author: Hakam Atassi
* Date: Sep 5 2024
* Description: The top level address mapping of the system
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



// FIXME: add int_producer, fp_producer, mem_producer
case class FUParams(
    supportsInt: Boolean = false, 
    supportsINT2FP: Boolean = false, 
    supportsFP: Boolean = false,
    supportsFP2INT: Boolean = false,
    supportsIntMult: Boolean = false,
    supportsIntDiv: Boolean = false,
    supportsBranch: Boolean = false,
    supportsCSRs: Boolean = false,
    supportsAddressGeneration: Boolean = false,


    INTRS_MEMRS_port:Int=0,             // RS index
    RS1_RS2_indices:Seq[Int]=Seq(0, 0),      // RS1 RS2 index
    PRFRD:Int=0                         // PRD writeback index
) {

    val is_INTFU:Boolean = supportsInt || supportsIntMult || supportsIntDiv || supportsBranch
    val is_MEMFU:Boolean = supportsAddressGeneration
    val is_FPU:Boolean = supportsFP
    val is_branch:Boolean = supportsBranch

    val INT_consumer: Boolean   = is_INTFU || supportsINT2FP || is_MEMFU    // does this FU produce int results (that are useable)  // FIXME: supports branch? should this be included?
    val FP_consumer: Boolean    = is_FPU   || supportsFP2INT  // does this FU produce int results (that are useable)  // FIXME: supports branch? should this be included?

    // below is a more abstract representation of FUs once they have produced their result.
    val INT_producer: Boolean   = is_INTFU || supportsFP2INT    // does this FU produce int results (that are useable)  // FIXME: supports branch? should this be included?
    val FP_producer: Boolean    = is_FPU   || supportsINT2FP  // does this FU produce int results (that are useable)  // FIXME: supports branch? should this be included?
    val MEM_producer: Boolean   = is_MEMFU    // does this FU produce int results (that are useable)  // FIXME: supports branch? should this be included?


    //require(
        //supportsInt || supportsIntMult || supportsIntDiv || supportsBranch || supportsCSRs || supportsAddressGeneration,
        //"At least one of the functional unit supports must be true.")

    require(
        !(supportsAddressGeneration && (supportsIntMult || supportsIntDiv || supportsBranch || supportsInt || supportsCSRs)),
        "FU cannot be an AGU and something else. Ie, AGUs are mutually exclusive from all other FU types"
    )


    require(
        !(is_INTFU && is_MEMFU), "FU cannot be INTFU and MEMFU at the same time. Please either disable all INT functionality or disable address generation for this FU."
        )
}
