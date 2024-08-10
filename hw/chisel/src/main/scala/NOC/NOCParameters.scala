package ChaosCore

import chisel3._
import circt.stage.ChiselStage 
import chisel3.util._



case class NOCParameters(

    /////////////////////////////
    // INTERCONNECT PARAMETERS //
    /////////////////////////////

    S_COUNT:Int = 2,
    // Number of AXI outputs (master interfaces)
    M_COUNT:Int = 2,
    // Width of data bus in bits
    DATA_WIDTH:Int = 32,
    // Width of address bus in bits
    ADDR_WIDTH:Int = 32,
    // Width of wstrb (width of data bus in words)
    STRB_WIDTH:Int = (32/8),
    // Width of ID signal
    ID_WIDTH:Int = 8,
    // Propagate awuser signal
    AWUSER_ENABLE:Int = 0,
    // Width of awuser signal
    AWUSER_WIDTH:Int = 1,
    // Propagate wuser signal
    WUSER_ENABLE:Int = 0,
    // Width of wuser signal
    WUSER_WIDTH:Int = 1,
    // Propagate buser signal
    BUSER_ENABLE:Int = 0,
    // Width of buser signal
    BUSER_WIDTH:Int = 1,
    // Propagate aruser signal
    ARUSER_ENABLE:Int = 0,
    // Width of aruser signal
    ARUSER_WIDTH:Int = 1,
    // Propagate ruser signal
    RUSER_ENABLE:Int = 0,
    // Width of ruser signal
    RUSER_WIDTH:Int = 1,
    // Propagate ID field
    FORWARD_ID:Int = 0,
    // Number of regions per master interface
    M_REGIONS:Int = 1,
    // Master interface base addresses
    // M_COUNT concatenated fields of M_REGIONS concatenated fields of ADDR_WIDTH bits
    // set to zero for default addressing based on M_ADDR_WIDTH
    M_BASE_ADDR:Int = 0,
    // Master interface address widths
    // M_COUNT concatenated fields of M_REGIONS concatenated fields of 32 bits
    // Read connections between interfaces
    // M_COUNT concatenated fields of S_COUNT bits
    // Write connections between interfaces
    // M_COUNT concatenated fields of S_COUNT bits
    // Secure master (fail operations based on awprot/arprot)
    // M_COUNT bits


    M_ADDR_WIDTH:Int    = 32,
    M_CONNECT_READ:Int  = 2,
    M_SECURE:Int        = 0,

    M_CONNECT_WRITE:Int = 2,

    // DRAM and peripherals return separately but in-order

    AXI_CACHEABLE_RESPONSE_ID:Int = 0, 
    AXI_NON_CACHEABLE_RESPONSE_ID:Int = 1,

    PIPELINE_OUTPUT:Int = 0, // register the output of the RAM

    // ADDRESS PARAMETERS 
    
    // DRAM parameters
    DRAM_BASE_ADDR:Int = 0x0,
    DRAM_ADDR_WIDTH:Int = 0x800000,
    DRAM_CONNECT_READ:Int = 1,
    DRAM_CONNECT_WRITE:Int = 1,
    DRAM_SECURE:Int =  0,

    // UART params
    UART0_BASE_ADDR:Int = 0x80000000,
    UART0_ADDR_WIDTH:Int = 1,              
    UART0_CONNECT_READ:Int = 1,
    UART0_CONNECT_WRITE:Int = 1,
    UART0_SECURE:Int =  0,



    /////////////////////////////
    // INTERCONNECT PARAMETERS //
    /////////////////////////////

){
    val DATA_WIDTH_BYTES:Int = DATA_WIDTH/8;
}