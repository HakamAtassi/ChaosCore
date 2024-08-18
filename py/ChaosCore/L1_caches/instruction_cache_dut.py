import sys
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly




class instruction_cache_dut:
    def __init__(self, dut):
        self.L1_instruction_cache = dut

    #################
    # CLOCK / RESET #
    #################

    async def clock(self):  # Do not touch
        await RisingEdge(self.L1_instruction_cache.clock)

    async def reset(self):  # Do not touch
        await RisingEdge(self.L1_instruction_cache.clock)
        self.L1_instruction_cache.reset.value = 1
        await RisingEdge(self.L1_instruction_cache.clock)
        self.L1_instruction_cache.reset.value = 0

    async def kill(self):  
        self.L1_instruction_cache.io_kill.value = 1
        await RisingEdge(self.L1_instruction_cache.clock)
        self.L1_instruction_cache.io_kill.value = 0

    def write_CPU_read_request(self, address=0, valid=0):
        """perform a CPU read request"""
        self.L1_instruction_cache.io_CPU_request_valid.value          = valid
        self.L1_instruction_cache.io_CPU_request_bits_addr.value      = address
        self.L1_instruction_cache.io_CPU_request_bits_wr_data.value   = 0
        self.L1_instruction_cache.io_CPU_request_bits_wr_en.value     = 0


    def read_CPU_read_request(self):
        """perform a CPU read request"""
        cache_request = {
            "valid": self.L1_instruction_cache.io_CPU_request_valid,
            "ready": self.L1_instruction_cache.io_CPU_request_ready,
            "bits": {
                "addr": self.L1_instruction_cache.io_CPU_request_ready,
            }
        }
        return cache_request


    
    def read_CPU_read_response(self):
        """read the cache response data"""
        cache_response          = {}
        cache_response["bits"]  = {}
        cache_response["valid"] = self.L1_instruction_cache.io_CPU_response_valid.value
        cache_response["ready"] = self.L1_instruction_cache.io_CPU_response_ready.value
        cache_response["bits"]["fetch_PC"] = (int(self.L1_instruction_cache.io_CPU_response_bits_fetch_PC.value))
        cache_response["bits"]["valid_bits"]    = [0]*4
        cache_response["bits"]["instruction"]   = [0]*4
        cache_response["bits"]["packet_index"]  = [0]*4
        cache_response["bits"]["ROB_index"]     = [0]*4
        for i in range(4):
            cache_response["bits"]["valid_bits"][i]   = (int(getattr(self.L1_instruction_cache, f"io_CPU_response_bits_valid_bits_{i}").value))
            cache_response["bits"]["instruction"][i]  = (int(getattr(self.L1_instruction_cache, f"io_CPU_response_bits_instructions_{i}_instruction").value))
            cache_response["bits"]["packet_index"][i] = (int(getattr(self.L1_instruction_cache, f"io_CPU_response_bits_instructions_{i}_packet_index").value))
            cache_response["bits"]["ROB_index"][i]    = (int(getattr(self.L1_instruction_cache, f"io_CPU_response_bits_instructions_{i}_ROB_index").value))

        cache_response["bits"]["GHR"] = self.L1_instruction_cache.io_CPU_response_bits_GHR.value
        cache_response["bits"]["NEXT"] = self.L1_instruction_cache.io_CPU_response_bits_NEXT.value
        cache_response["bits"]["TOS"] = self.L1_instruction_cache.io_CPU_response_bits_TOS.value

        return cache_response


    def read_AXI_AR(self):
        """Read the values of the AXI AR ports"""
        AXI_IO = {}
        AXI_IO["bits"] = {}
        AXI_IO["valid"]                 = self.L1_instruction_cache.m_axi_arvalid.value
        AXI_IO["bits"]["arid"]          = self.L1_instruction_cache.m_axi_arid.value
        AXI_IO["bits"]["araddr"]        = self.L1_instruction_cache.m_axi_araddr.value
        AXI_IO["bits"]["arlen"]         = self.L1_instruction_cache.m_axi_arlen.value
        AXI_IO["bits"]["arsize"]        = self.L1_instruction_cache.m_axi_arsize.value
        AXI_IO["bits"]["arburst"]       = self.L1_instruction_cache.m_axi_arburst.value
        AXI_IO["bits"]["arlock"]        = self.L1_instruction_cache.m_axi_arlock.value
        AXI_IO["bits"]["arcache"]       = self.L1_instruction_cache.m_axi_arcache.value
        AXI_IO["bits"]["arprot"]        = self.L1_instruction_cache.m_axi_arprot.value
        AXI_IO["bits"]["arqos"]         = self.L1_instruction_cache.m_axi_arqos.value
        AXI_IO["bits"]["arregion"]      = self.L1_instruction_cache.m_axi_arregion.value
        AXI_IO["bits"]["aruser"]        = self.L1_instruction_cache.m_axi_aruser.value
        return AXI_IO

    def set_AXI_AR_ready(self, ready):
        self.L1_instruction_cache.m_axi_arready.value    =   ready


    def write_AXI_R(self, AXI_IO):
        """Write data to the AXI R ports"""
        AXI_IO = AXI_IO
        self.L1_instruction_cache.AXI_port_AXI_R_valid.value                  = AXI_IO["AXI_R"]["valid"]
        self.L1_instruction_cache.AXI_port_AXI_R_bits_rid.value               = AXI_IO["AXI_R"]["bits"]["rid"]
        self.L1_instruction_cache.AXI_port_AXI_R_bits_rdata.value             = AXI_IO["AXI_R"]["bits"]["rdata"]
        self.L1_instruction_cache.AXI_port_AXI_R_bits_rresp.value             = AXI_IO["AXI_R"]["bits"]["rresp"]
        self.L1_instruction_cache.AXI_port_AXI_R_bits_rlast.value             = AXI_IO["AXI_R"]["bits"]["rlast"]
        self.L1_instruction_cache.AXI_port_AXI_R_bits_ruser.value             = AXI_IO["AXI_R"]["bits"]["ruser"]

    def set_CPU_response(self, ready):
        self.L1_instruction_cache.io_CPU_response_ready.value                 = ready



