/* ------------------------------------------------------------------------------------
* Filename: SOCParameters.scala
* Author: Hakam Atassi
* Date: Apr 23 2024
* Description: The SOC configuration file
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


object printWelcome{
    def apply(): Unit={
        val ChaosCore = """
   _______                      _____               
  / ____| |                    / ____|              
 | |    | |__   ____  ___  ___| |     ___  ____ ___ 
 | |    |  _ \ / _  |/ _ \/ __| |    / _ \| ___/ _ \
 | |____| | | | (_| | (_) \__ \ |___| (_) | | |  __/
  \_____|_| |_|\____|\___/|___/\_____\___/|_|  \___|
        """
        println(ChaosCore)
    }
}

case class SOCParameters(
    //coreParameters:Seq[CoreParameters] = Seq(CoreParameters(hartID=0, startPC="h80000000".U, DEBUG=false), CoreParameters(hartID=1, startPC="h81000000".U)),
    coreParameters:Seq[CoreParameters] = Seq(CoreParameters(hartID=0, startPC="h80000000".U, DEBUG=false)),
    addressMap:AddressMap = AddressMap()
){

    printWelcome()


    // Here, M_COUNT is the number of masters from the perspective of the SOC (the NOC itself views an input as a slave port and therefore swaps M <=> S)
    val nocParameters = NOCParameters(M_COUNT = coreParameters.length*2)    // 2 ports for each core (1 for I$, 1 for D$)


    println("Building ChaosCore")


    //TODO: print addressMap
    //TODO: print nocParameters
    

    println("SOC parameters")
    println(s"[${Console.YELLOW}ChaosCore INFO${Console.RESET}] Cores [${coreParameters.length}]")

    println("Address Map")
    println("TODO")
    //println(s"[${Console.YELLOW}ChaosCore INFO${Console.RESET}] Cores [${coreParameters.length}]")


    for(coreParameters <- coreParameters){
        println(s"Hart ${coreParameters.hartID} parameters")
        println(s"[${Console.YELLOW}ChaosCore INFO${Console.RESET}] L1 D$$ Size [${coreParameters.getDataCacheSizeKB}KB]")
        println(s"[${Console.YELLOW}ChaosCore INFO${Console.RESET}] L1 I$$ Size [${coreParameters.getInstructionCacheSizeKB}KB]")
    }



    //TODO 
    // add things like HartID validation and similar


}


