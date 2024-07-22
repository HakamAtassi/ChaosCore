package ChaosCore

import chisel3._
import circt.stage.ChiselStage 
import chisel3.util._




case class NOCParameters(

    w:Int = 32,     // 32 Byte bus
    a:Int = 32,     // 32 bit address space
    z:Int = 6,      // Transfer size always 32 bytes (256 bits/cache line)
    o:Int = 0,      // Not needed 
    i:Int = 0,      // Not needed

    /////////////////////////////
    // INTERCONNECT PARAMETERS //
    /////////////////////////////
    instruction_cache_TL_ID:Int = 1,
    data_cache_TL_ID:Int        = 2,
    debug_printer_TL_ID:Int     = 3,

){

}