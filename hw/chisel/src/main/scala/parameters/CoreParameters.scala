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
import chisel3.util._



object validate_backend{
    def apply(coreConfig:String)(FUParamSeq: Seq[FUParams]): Boolean = {

        val expects_mul = coreConfig.contains("M") || coreConfig.contains("G")

        // There can only be 1 CSR
        val csrUnits = FUParamSeq.count(_.supportsCSRs)
        if (csrUnits != 1) {
            println(s"There must be exactly 1 CSR unit, found $csrUnits.")
            return false
        }

        // There can only be 1 AGU
        val aguUnits = FUParamSeq.count(_.supportsAddressGeneration)
        if (aguUnits != 1) {
            println(s"There must be exactly 1 AGU unit, found $aguUnits.")
            return false
        }

        // There must be at least 1 Branch Unit
        val branchUnits = FUParamSeq.count(_.supportsBranch)
        if (branchUnits < 1) {
            println(s"There must be at least 1 Branch unit, found $branchUnits.")
            return false
        }

        if (branchUnits > 1) {
            println(s"[${Console.YELLOW}ChaosCore Warning${Console.RESET}] You have allocated more than 1 Branch Unit. This is not suggested for FPGA builds")
        }



        val branchPort = FUParamSeq.indexWhere(_.supportsBranch)
        val csrPort = FUParamSeq.indexWhere(_.supportsCSRs)
        val csrBranchOnDifferentPorts = branchPort != csrPort && branchPort >= 0 && csrPort >= 0
        if (csrBranchOnDifferentPorts) {
            println(s"[${Console.YELLOW}ChaosCore Warning${Console.RESET}] The CSR file and Branch Unit are exist in different FUs. This is not suggested for FPGA builds.")
        }

        // There must be at least 1 INT
        val intUnits = FUParamSeq.count(_.supportsInt)
        if (intUnits < 1) {
            println(s"There must be at least 1 INT unit, found $intUnits.")
            return false
        }

        // There must be at least 1 MUL
        val mulUnits = FUParamSeq.count(_.supportsIntMult)
        if(expects_mul){
            if (mulUnits < 1) {
                println(s"There must be at least 1 MUL unit, found $mulUnits.")
                return false
            }
        }

        // There must be at least 1 FPU (if enabled)
        val isFpuEnabled = coreConfig.contains("F")
        if (isFpuEnabled) {
            // MUST HAVE 1 INT2FP and FP2INT 
            if(FUParamSeq.count(_.supportsINT2FP) != 1){
                println(s"FPU requires 1 and exactly 1 INT2FP units.")
                return false
            }

            if(FUParamSeq.count(_.supportsFP2INT) != 1){
                println(s"FPU requires 1 and exactly 1 FP2INT units.")
                return false
            }

            val fpuUnits = FUParamSeq.count(_.supportsFP) // Assuming supportsFPU exists
            if (fpuUnits < 1) {
                println(s"FPU is enabled, but no FPU units were found.")
                return false
            }

            // Make sure units have an FP and an INT
        }else{  // "F" not defined for core. Make sure no FP units defined

        }

        true
    }

}



case class CoreParameters(
    DEBUG: Boolean = true,

    // FIXME: add a requirement here than makes sure that the core config actually makes sense
    coreConfig: String = "RV32IMSUF",  // core extension (IMAF, etc...)
    hartID: Int = 0, // for multicore, this must be assigned on config. 

    //hartIDs:Seq[Int] = Seq(0, 1),


    fetchWidth: Int = 1,   // up to how many instructions does the core fetch each cycle


    GHRWidth: Int = 16,
    RASEntries: Int = 128,
    BTBEntries: Int = 1024,
    startPC: UInt = "h80000000".U,
    FTQEntries:Int  = 16,

    ROBEntries: Int = 64,    // FIXME: 128 causes area scaling problems in the RAT

    architecturalRegCount: Int = 32,  // RV32...
    RATCheckpointCount:    Int = 16,  // How many checkpoints of the RAT is supported? (this should be a proportion of the ROB size)

    physicalRegCount:      Int = 65,  // 64 physical regs + x0 (not renamed)

    RSEntries: Int = 8, // How many entires per reservation station (these are very expensive)


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
    // FIXME: why are these repeated here?
    ALUportCount:Int = 3,
    MEMportCount:Int = 1,
    FPUportCount:Int = 2,  // not used if not "F"   // FIXME: make this parameterizable


    ALUStages: Int = 2, // latency of the ALU unit

    /////////
    // MOB //
    /////////
    MOBWBPortCount:Int = 1, // The number of ports the MOB has to write back to the PRF

    instruction_queue_depth:Int = 8,

    speculative:Boolean = true,

    MOBEntries:Int = 16,
    IQEntries:Int = 4,
    //MOBForceInOrder:Boolean = true,  // can loads execute if not all previous (load+store) addresses have been resolved?

    /////////////////////////////
    // EXECUTION ENGINE PARAMS //
    /////////////////////////////

    // Add as many FUs as desired. 
    // FIXME: check that there is only 1 CSRs, etc...
    // Add other requirements here
    // 
    FUParamSeq: Seq[FUParams] = Seq(
        // ALU + MUL ARITHMETIC UNITS
        FUParams(supportsInt=true, supportsFP=false, supportsFP2INT=false, supportsINT2FP=false, supportsIntMult=false,  supportsIntDiv=false, supportsBranch=false, supportsCSRs=false, supportsAddressGeneration=false),
        FUParams(supportsInt=true, supportsFP=false, supportsFP2INT=false, supportsINT2FP=false, supportsIntMult=true,   supportsIntDiv=true,  supportsBranch=true,  supportsCSRs=true,  supportsAddressGeneration=false),
        FUParams(supportsInt=true, supportsFP=false, supportsFP2INT=false, supportsINT2FP=true, supportsIntMult=false,  supportsIntDiv=false, supportsBranch=false, supportsCSRs=false,  supportsAddressGeneration=false),

        // MEMORY UNITS
        FUParams(supportsInt=false, supportsFP=false, supportsFP2INT=false, supportsINT2FP=false, supportsIntMult=false, supportsIntDiv=false, supportsBranch=false, supportsCSRs=false, supportsAddressGeneration=true),

        // FPUs (these have to go after the memory unit)
        FUParams(supportsInt=false, supportsFP=true, supportsFP2INT=true, supportsINT2FP=false, supportsIntMult=false, supportsIntDiv=false, supportsBranch=false, supportsCSRs=false,  supportsAddressGeneration=false),
        FUParams(supportsInt=false, supportsFP=true, supportsFP2INT=false, supportsINT2FP=false, supportsIntMult=false, supportsIntDiv=false, supportsBranch=false, supportsCSRs=false, supportsAddressGeneration=false),

    )







    // TODO: 
    // Add requirement that there can only be 1 AGU, and that there are no mults or divs currently. 
    
){
    println(s"Building Core $hartID parameters...")

    ///////////////////////////////////
    // DO NOT TOUCH THESE PARAMETERS //
    ///////////////////////////////////

    val physicalRegBits: Int      = log2Ceil(physicalRegCount)      // N regs but x0 does not exist as a physical reg
    val architecturalRegBits: Int = log2Ceil(architecturalRegCount)
    val RATCheckpointBits:Int     = log2Ceil(RATCheckpointCount)


    // FIXME: does nothing
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

    def getDataCacheSizeKB:Int = {
        0
    }

    ////////////////////////
    // Instruction CACHE //
    ///////////////////////
    def getInstructionCacheSizeKB:Int = {
        0
    }


    ////////
    // FU //
    ////////

    val portCount:Int = FUParamSeq.length   // total number of ports from the reservation stations to the functional units

    val INTRSPortCount: Int = FUParamSeq.count(_.is_INTFU)
    val FPRSPortCount: Int = FUParamSeq.count(_.is_FPU)
    val MEMRSPortCount: Int = FUParamSeq.count(_.is_MEMFU)
    val branchPortCount: Int = FUParamSeq.count(_.is_branch)



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

    //val supportedExtensions = Seq("I", "IM", "IMA", "32G")  // FIXME: coreConfig should just be a case class
    //require(supportedExtensions.contains(userExtensions), 
    //s"Invalid extensions: $userExtensions. Supported extensions are: ${supportedExtensions.mkString(", ")}")

    require(validate_backend(coreConfig)(FUParamSeq))   // Ensure minimal required functional units

}


