/* ------------------------------------------------------------------------------------
* Filename: coreParameters.scala
* Author: Hakam Atassi
* Date: Apr 23 2024
* Description: The ChaosCore Top level Config File
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


case class CoreParameters(

    DEBUG: Boolean = false,

    // FIXME: add a requirement here than makes sure that the core config actually makes sense
    coreConfig: String = "RV32IM",  // core extension (IMAF, etc...)

    fetchWidth: Int = 4,   // up to how many instructions does the core fetch each cycle


    GHRWidth: Int = 16,
    RASEntries: Int = 128,
    BTBEntries: Int = 4096,
    startPC: UInt = "h80000000".U,
    FTQEntries:Int  = 16,

    ROBEntries: Int = 64,    // FIXME: 128 causes area scaling problems in the RAT

    architecturalRegCount: Int = 32,  // RV32...
    RATCheckpointCount:    Int = 16,  // How many checkpoints of the RAT is supported? (this should be a proportion of the ROB size)

    physicalRegCount:      Int = 65,  // 64 physical regs + x0 (not renamed)

    RSEntries: Int = 16, // How many entires per reservation station (these are very expensive)


    L1_cacheLineSizeBytes: Int = 32,

    // Instruction Cache params
    L1_instructionCacheWays: Int = 2,
    L1_instructionCacheSets: Int = 64,

    // Data Cache params
    L1_DataCacheWays: Int = 4,
    L1_DataCacheSets: Int = 64,

    L1_MSHREntries: Int = 4,                    // number of MSHR rows (unique miss addresses)
    L1_NonCacheableBufferEntries: Int = 4,      // number of MSHR rows (unique miss addresses)
    L1_MSHRWidth: Int = 8,                      // width of MSHR rows (misses per address)

    // Execution params
    ALUportCount:Int = 3,
    MEMportCount:Int = 1,
    FPUportCount:Int = 0,  // not used if not "F"



    /////////
    // MOB //
    /////////
    MOBWBPortCount:Int = 1, // The number of ports the MOB has to write back to the PRF


    instruction_queue_depth:Int = 8,

    speculative:Boolean = true,   // this does nothing yet

    MOBEntries:Int = 16,
    //MOBForceInOrder:Boolean = true,  // can loads execute if not all previous (load+store) addresses have been resolved?


    /////////////////////////////
    // EXECUTION ENGINE PARAMS //
    /////////////////////////////

    // Add as many FUs as desired. 
    FUParamSeq: Seq[FUParams] = Seq(
        FUParams(supportsInt=true, supportsMult=false, supportsDiv=false, supportsBranch=true, supportsAddressGeneration=false),
        FUParams(supportsInt=true, supportsMult=true, supportsDiv=true, supportsBranch=false, supportsAddressGeneration=false),
        FUParams(supportsInt=true, supportsMult=false, supportsDiv=false, supportsBranch=false, supportsAddressGeneration=false),
        FUParams(supportsInt=false, supportsMult=false, supportsDiv=false, supportsBranch=false, supportsAddressGeneration=true),
    )

    // TODO: 
    // Add requirement that there can only be 1 AGU, and that there are no mults or divs currently. 
    
){


    ///////////////////////////////////
    // DO NOT TOUCH THESE PARAMETERS //
    ///////////////////////////////////

    val physicalRegBits: Int      = log2Ceil(physicalRegCount)      // N regs but x0 does not exist as a physical reg
    val architecturalRegBits: Int = log2Ceil(architecturalRegCount)
    val RATCheckpointBits:Int     = log2Ceil(RATCheckpointCount)


    val userXLEN:Int = if (coreConfig.startsWith("RV32")) {
        32
    } else if (coreConfig.startsWith("RV64")) {
        64
    } else {
        throw new IllegalArgumentException("Invalid base architecture in coreConfig: " + coreConfig)
    }


    ////////////////
    // DATA CACHE //
    ////////////////
    val L1_DataCacheTagBits:Int = 32 - log2Ceil(L1_DataCacheSets) - log2Ceil(L1_cacheLineSizeBytes)


    ////////
    // FU //
    ////////

    val portCount:Int = FUParamSeq.length   // total number of ports from the reservation stations to the functional units

    val INTRSPortCount: Int = FUParamSeq.count(_.is_INTFU)
    val MEMRSPortCount: Int = FUParamSeq.count(_.is_MEMFU)

    val WBPortCount: Int = INTRSPortCount + MOBWBPortCount


    //val FURSPortCount:Int = // total number of FUs that connect to the INTRS  // TODO:

    val portedFUParamSeq = generateFUPorts(FUParamSeq)



    ////////////////
    // EXTENSIONS //
    ////////////////

    //coreConfig: String = "RV32IM",  // core extension (IMAF, etc...)
    val userExtensions = coreConfig.substring(4)  // Extract extensions

    val has_mul = userExtensions.contains("M")

    //////////////////
    // REQUIREMENTS //
    //////////////////

    val supportedExtensions = Seq("I", "IM", "IMA", "32G")

    require(supportedExtensions.contains(userExtensions), 
    s"Invalid extensions: $userExtensions. Supported extensions are: ${supportedExtensions.mkString(", ")}")




}


