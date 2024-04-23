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

import chisel3._
import circt.stage.ChiselStage
import chisel3.util._
import java.io.{File, FileWriter}
import java.rmi.server.UID


// TODO: Add parameters file and use it to configure all the modules...


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
    VerilogGenerator.generateVerilog(new L1_instruction_cache(fetchWidth=2, ways = 2, sets = 64, blockSizeBytes = 32), "../verilog/Frontend/instruction_cache.v")
    VerilogGenerator.generateVerilog(new decode_validate(width=4), "../verilog/Frontend/BP/decode_validate.v")
}
