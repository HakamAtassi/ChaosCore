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


case class FUParams(
    supportsInt: Boolean = false, 
    supportsMult: Boolean = false,
    supportsDiv: Boolean = false,
    supportsBranch: Boolean = false,
    supportsCSRs: Boolean = false,
    supportsAddressGeneration: Boolean = false,

    INTRS_MEMRS_port:Int=0,             // RS index
    RS1_RS2_indices:Seq[Int]=Seq(0, 0),      // RS1 RS2 index
    PRFRD:Int=0                         // PRD writeback index
) {

    val is_INTFU:Boolean = supportsInt || supportsMult || supportsDiv || supportsBranch
    val is_MEMFU:Boolean = supportsAddressGeneration

    require(
        supportsInt || supportsMult || supportsDiv || supportsBranch || supportsCSRs || supportsAddressGeneration,
        "At least one of the functional unit supports must be true.")

    require(
        !(supportsAddressGeneration && (supportsMult || supportsDiv || supportsBranch || supportsInt || supportsCSRs)),
        "FU cannot be an AGU and something else. Ie, AGUs are mutually exclusive from all other FU types"
    )


    require(
        !(is_INTFU && is_MEMFU), "FU cannot be INTFU and MEMFU at the same time. Please either disable all INT functionality or disable address generation for this FU."
        )
}
