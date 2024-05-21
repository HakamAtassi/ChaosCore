/* ------------------------------------------------------------------------------------
* Filename: top.scala
* Author: Hakam Atassi
* Date: Apr 23 2024
* Description: The ChaosCore Top level
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




object VerilogGenerator {

    def generateVerilog(module: => RawModule, fileName: String): Unit = {
        val elaboratedModule = ChiselStage.emitSystemVerilog(module, firtoolOpts = Array("-disable-all-randomization", "-strip-debug-info"))

        val file = new File(fileName)
        val fw = new FileWriter(file)

        try {
            fw.write(elaboratedModule)
        } finally {
            fw.close()
        }
    }
}

object Main extends App {
    import Parameters._

    //VerilogGenerator.generateVerilog(new L1_instruction_cache(fetchWidth = 4, ways = 2, sets = 64, blockSizeBytes = 32), "../verilog/Frontend/instruction_cache.v")
    //VerilogGenerator.generateVerilog(new gshare(GHR_width = 16), "../verilog/Frontend/BP/gshare.v")
    //VerilogGenerator.generateVerilog(new hash_BTB(entries = 4096), "../verilog/Frontend/BP/hash_BTB.v")
    //VerilogGenerator.generateVerilog(new decode_validate(fetchWidth=4), "../verilog/Frontend/BP/decode_validate.v")
    VerilogGenerator.generateVerilog(new RAS, "../verilog/Frontend/BP/RAS.v")
    //VerilogGenerator.generateVerilog(new BP, "../verilog/Frontend/BP/BP.v")
    //VerilogGenerator.generateVerilog(new PC_arbit(
        //fetchWidth = fetchWidth,
        //GHRWidth = GHRWidth,
        //RASEntries = RASEntries,
        //startPC = startPC)
    //, 
    //"../verilog/Frontend/BP/PC_arbit.v")

    //VerilogGenerator.generateVerilog(new Frontend(
        //GHRWidth = GHRWidth,
        //fetchWidth = fetchWidth,
        //RASEntries = RASEntries,
        //BTBEntries = BTBEntries,
        //L1_instructionCacheWays = L1_instructionCacheWays,
        //L1_instructionCacheSets = L1_instructionCacheSets,
        //L1_instructionCacheBlockSizeBytes = L1_instructionCacheBlockSizeBytes,
        //startPC = startPC
    //), 
    //"../verilog/Frontend/Frontend.v")


    VerilogGenerator.generateVerilog(new free_list(
        fetchWidth = fetchWidth,
        physicalRegCount = physicalRegCount)
    , 
    "../verilog/Frontend/free_list.v")



    VerilogGenerator.generateVerilog(new WAW_handler(
        fetchWidth = fetchWidth,
        physicalRegCount = physicalRegCount, 
        architecturalRegCount = architecturalRegCount
        
        )
    , 
    "../verilog/Frontend/WAW_handler.v")


    VerilogGenerator.generateVerilog(new rename(
        RATCheckpointCount = RATCheckpointCount,
        fetchWidth = fetchWidth,
        physicalRegCount = physicalRegCount, 
        architecturalRegCount = architecturalRegCount
        
        )
    , 
    "../verilog/Frontend/rename.v")


    VerilogGenerator.generateVerilog(new RAT(
        RATCheckpointCount = RATCheckpointCount,
        fetchWidth = fetchWidth,
        physicalRegCount = physicalRegCount, 
        architecturalRegCount = architecturalRegCount
        
        )
    , 
    "../verilog/Frontend/RAT.v")


    VerilogGenerator.generateVerilog(new RS(
        dispatchWidth=dispatchWidth,
        RSEntries=RSEntries,
        physicalRegCount=physicalRegCount,
        coreConfig=coreConfig
        )
    , 
    "../verilog/Backend/RS.v")

}
