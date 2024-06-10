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

    val parameters = Parameters()
    val addressMap = AddressMap()
    VerilogGenerator.generateVerilog(new instruction_cache(parameters), "../verilog/Frontend/instruction_cache.v")


    //VerilogGenerator.generateVerilog(new fetch_packet_decoder(parameters), "../verilog/Frontend/decoders.v")

    //VerilogGenerator.generateVerilog(new free_list(parameters), 
    //"../verilog/Frontend/free_list.v")



    //VerilogGenerator.generateVerilog(new WAW_handler(parameters), 
    //"../verilog/Frontend/WAW_handler.v")


    //VerilogGenerator.generateVerilog(new rename(parameters), 
    //"../verilog/Frontend/rename.v")


    //VerilogGenerator.generateVerilog(new RAT(parameters), 
    //"../verilog/Frontend/RAT.v")


    // VerilogGenerator.generateVerilog(new RS(parameters), 
    // "../verilog/Backend/RS.v")

    VerilogGenerator.generateVerilog(new ROB(parameters), 
    "../verilog/Backend/ROB.v")

    VerilogGenerator.generateVerilog(new MEMRS(parameters), 
    "../verilog/Backend/MEMRS.v")

    //VerilogGenerator.generateVerilog(new RF(
        //coreConfig:String, 
        //physicalRegCount:Int
        //)
    //, 
    //"../verilog/Backend/RF.v")

    VerilogGenerator.generateVerilog(new decoder(parameters), 
    "../verilog/Frontend/decoder.v")

    //VerilogGenerator.generateVerilog(new FU(parameters, true, true), 
    //"../verilog/Backend/FU.v")

    // VerilogGenerator.generateVerilog(new backend(parameters), 
    // "../verilog/Backend/backend.v")

    // VerilogGenerator.generateVerilog(new frontend(parameters), 
    // "../verilog/Frontend/frontend.v")

    // VerilogGenerator.generateVerilog(new predecoder(parameters), 
    // "../verilog/Frontend/BP/predecoder.v")

    // VerilogGenerator.generateVerilog(new FTQ(parameters), 
    // "../verilog/Frontend/FTQ.v")

    // VerilogGenerator.generateVerilog(new BP(parameters), 
    // "../verilog/Frontend/BP/BP.v")

    // VerilogGenerator.generateVerilog(new ROB(parameters), 
    // "../verilog/Backend/ROB.v")

    // VerilogGenerator.generateVerilog(new ChaosCore(parameters), 
    // "../verilog/Core/ChaosCore.v")

    // VerilogGenerator.generateVerilog(new instruction_queue(new decoded_instruction(parameters), parameters), 
    // "../verilog/Frontend/instruction_queue.v")

    VerilogGenerator.generateVerilog(new debug_printer(parameters, addressMap), 
    "../verilog/peripherals/debug_printer.v")

    //VerilogGenerator.generateVerilog(new SOC(parameters, addressMap), 
    //"../verilog/SOC/SOC.v")

    //ChiselStage.emitSystemVerilogFile(new backend(parameters), Array("--split-verilog"))

}

