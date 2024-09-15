package ChaosCore

import chisel3._
import circt.stage.ChiselStage 

import chisel3.util._

class instruction_mem(coreParameters:CoreParameters, addressMap:AddressMap, nocParameters:NOCParameters) extends Module{
    val io = IO(new Bundle{
        val CPU_request         =     Flipped(Decoupled(new frontend_memory_request(coreParameters))) 
        val CPU_response        =     Decoupled(new fetch_packet(coreParameters))    
        val kill                =     Input(Bool())
    })
    // This module instantiates ChaosCore, connects caches, and propegates its AXI ports

    //CACHE
    val instruction_cache = Module(new L1_instruction_cache(coreParameters, nocParameters))


    //AXI INTERCONNECTS
    val axi_interconnect = Module(new axi_interconnect_2x2(nocParameters))
    val instruction_cache_AXI_port = new AXIFullIO(nocParameters)


    val AXI_debug_printer = Module(new AXI_debug_printer(nocParameters, addressMap))

    //DRAM
    val m_axi = IO(new VerilogAXIFullIO(nocParameters))
    val dram_AXI = m_axi.viewAs[AXIFullIO]


    //CACHE <> CORE
    io.CPU_request <> instruction_cache.io.CPU_request
    io.CPU_response <> instruction_cache.io.CPU_response
    io.kill <> instruction_cache.io.kill



    // CACHE <> AXI //
    val instruction_cache_AXI_port = new AXIFullIO(nocParameters)
    instruction_cache.AXI_port <> instruction_cache_AXI_port
    instruction_cache_AXI_port <> axi_interconnect.io.m_AXI_port(0)

    // NOC <> IO (DRAM)
    axi_interconnect.io.s_AXI_port(0) <> dram_AXI

    // NOC <> UART
    axi_interconnect.io.s_AXI_port(1) <> AXI_debug_printer.AXI_port
}