import sys
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly




class instruction_cache_dut:
    def __init__(self, dut):
        self.L1_instruction_cache = dut

    #################
    # CLOCK / RESET #
    #################

    def clock(self):  # Do not touch
        return self.ChaosCore.clock

    async def reset(self):  # Do not touch
        await RisingEdge(self.ChaosCore.clock)
        self.ChaosCore.reset.value = 1
        await RisingEdge(self.ChaosCore.clock)
        self.ChaosCore.reset.value = 0

    def write_CPU_read_request(self, address, valid):
        """perform a CPU read request"""
        #self.L1_instruction_cache.io_CPU_request_ready.value          = 
        self.L1_instruction_cache.io_CPU_request_valid.value          = valid
        self.L1_instruction_cache.io_CPU_request_bits_addr.value      = address
        self.L1_instruction_cache.io_CPU_request_bits_wr_data.value   = 0
        self.L1_instruction_cache.io_CPU_request_bits_wr_en.value     = 0
    
    def read_CPU_read_response(self):
      """read the cache response data"""
      cache_response = {}
      cache_response["valid"] = self.L1_instruction_cache.io_CPU_response_valid.value
      cache_response["bits"]["fetch_PC"] = self.L1_instruction_cache.io_CPU_response_bits_fetch_PC.value

      cache_response["bits"]["valid_bits"]    = [0]*4
      cache_response["bits"]["instruction"]   = [0]*4
      cache_response["bits"]["packet_index"]  = [0]*4
      cache_response["bits"]["ROB_index"]     = [0]*4
      for i in range(4):
        cache_response["bits"]["valid_bits"][i]   = getattr(self.L1_instruction_cache, f"io_CPU_response_bits_valid_bits_{i}.value")
        cache_response["bits"]["instruction"][i]  = getattr(self.L1_instruction_cache, f"io_CPU_response_bits_instructions_{i}_instruction.value")
        cache_response["bits"]["packet_index"][i] = getattr(self.L1_instruction_cache, f"io_CPU_response_bits_instructions_{i}_packet_index.value")
        cache_response["bits"]["ROB_index"][i]    = getattr(self.L1_instruction_cache, f"io_CPU_response_bits_instructions_{i}_ROB_index.value")

      cache_response["bits"]["GHR"] = self.L1_instruction_cache.io_CPU_response_bits_GHR.value
      cache_response["bits"]["NEXT"] = self.L1_instruction_cache.io_CPU_response_bits_NEXT.value
      cache_response["bits"]["TOS"] = self.L1_instruction_cache.io_CPU_response_bits_TOS.value

      return cache_response


    def read_AXI_AR(self):
        """Read the values of the AXI AR ports"""
        AXI_IO = AXI_IO
        AXI_IO["AXI_AR"]["valid"]                 = self.L1_instruction_cache.AXI_port_AXI_AR_valid.value
        AXI_IO["AXI_AR"]["bits"]["arid"]          = self.L1_instruction_cache.AXI_port_AXI_AR_bits_arid.value
        AXI_IO["AXI_AR"]["bits"]["araddr"]        = self.L1_instruction_cache.AXI_port_AXI_AR_bits_araddr.value
        AXI_IO["AXI_AR"]["bits"]["arlen"]         = self.L1_instruction_cache.AXI_port_AXI_AR_bits_arlen.value
        AXI_IO["AXI_AR"]["bits"]["arsize"]        = self.L1_instruction_cache.AXI_port_AXI_AR_bits_arsize.value
        AXI_IO["AXI_AR"]["bits"]["arburst"]       = self.L1_instruction_cache.AXI_port_AXI_AR_bits_arburst.value
        AXI_IO["AXI_AR"]["bits"]["arlock"]        = self.L1_instruction_cache.AXI_port_AXI_AR_bits_arlock.value
        AXI_IO["AXI_AR"]["bits"]["arcache"]       = self.L1_instruction_cache.AXI_port_AXI_AR_bits_arcache.value
        AXI_IO["AXI_AR"]["bits"]["arprot"]        = self.L1_instruction_cache.AXI_port_AXI_AR_bits_arprot.value
        AXI_IO["AXI_AR"]["bits"]["arqos"]         = self.L1_instruction_cache.AXI_port_AXI_AR_bits_arqos.value
        AXI_IO["AXI_AR"]["bits"]["arregion"]      = self.L1_instruction_cache.AXI_port_AXI_AR_bits_arregion.value
        AXI_IO["AXI_AR"]["bits"]["aruser"]        = self.L1_instruction_cache.AXI_port_AXI_AR_bits_aruser.value

    def write_AXI_R(self, AXI_IO):
        """Write data to the AXI R ports"""
        AXI_IO = AXI_IO
        self.L1_instruction_cache.AXI_port_AXI_R_valid.value                  = AXI_IO["AXI_R"]["valid"]
        self.L1_instruction_cache.AXI_port_AXI_R_bits_rid.value               = AXI_IO["AXI_R"]["bits"]["rid"]
        self.L1_instruction_cache.AXI_port_AXI_R_bits_rdata.value             = AXI_IO["AXI_R"]["bits"]["rdata"]
        self.L1_instruction_cache.AXI_port_AXI_R_bits_rresp.value             = AXI_IO["AXI_R"]["bits"]["rresp"]
        self.L1_instruction_cache.AXI_port_AXI_R_bits_rlast.value             = AXI_IO["AXI_R"]["bits"]["rlast"]
        self.L1_instruction_cache.AXI_port_AXI_R_bits_ruser.value             = AXI_IO["AXI_R"]["bits"]["ruser"]

                #AXI_port_AXI_AW_ready,
  #output        AXI_port_AXI_AW_valid,
  #output [7:0]  AXI_port_AXI_AW_bits_awid,
  #output [31:0] AXI_port_AXI_AW_bits_awaddr,
  #output [7:0]  AXI_port_AXI_AW_bits_awlen,
  #output [2:0]  AXI_port_AXI_AW_bits_awsize,
  #output [1:0]  AXI_port_AXI_AW_bits_awburst,
  #output        AXI_port_AXI_AW_bits_awlock,
  #output [3:0]  AXI_port_AXI_AW_bits_awcache,
  #output [2:0]  AXI_port_AXI_AW_bits_awprot,
  #output [3:0]  AXI_port_AXI_AW_bits_awqos,
                #AXI_port_AXI_AW_bits_awregion,
  #output        AXI_port_AXI_AW_bits_awuser,
  #input         AXI_port_AXI_W_ready,
  #output        AXI_port_AXI_W_valid,
  #output [31:0] AXI_port_AXI_W_bits_wdata,
  #output [3:0]  AXI_port_AXI_W_bits_wstrb,
  #output        AXI_port_AXI_W_bits_wlast,
                #AXI_port_AXI_W_bits_wuser,
                #AXI_port_AXI_B_ready,
  #input         AXI_port_AXI_B_valid,
  #input  [7:0]  AXI_port_AXI_B_bits_bid,
  #input  [1:0]  AXI_port_AXI_B_bits_bresp,
  #input         AXI_port_AXI_B_bits_buser,
                #AXI_port_AXI_AR_ready,
  #output        AXI_port_AXI_AR_valid,
  #output [7:0]  AXI_port_AXI_AR_bits_arid,
  #output [31:0] AXI_port_AXI_AR_bits_araddr,
  #output [7:0]  AXI_port_AXI_AR_bits_arlen,
  #output [2:0]  AXI_port_AXI_AR_bits_arsize,
  #output [1:0]  AXI_port_AXI_AR_bits_arburst,
  #output        AXI_port_AXI_AR_bits_arlock,
  #output [3:0]  AXI_port_AXI_AR_bits_arcache,
  #output [2:0]  AXI_port_AXI_AR_bits_arprot,
  #output [3:0]  AXI_port_AXI_AR_bits_arqos,
                #AXI_port_AXI_AR_bits_arregion,
  #output        AXI_port_AXI_AR_bits_aruser,
                #AXI_port_AXI_R_ready,
  #input         AXI_port_AXI_R_valid,
  #input  [7:0]  AXI_port_AXI_R_bits_rid,
  #input  [31:0] AXI_port_AXI_R_bits_rdata,
  #input  [1:0]  AXI_port_AXI_R_bits_rresp,
  #input         AXI_port_AXI_R_bits_rlast,
                #AXI_port_AXI_R_bits_ruser,
  #output        io_CPU_response_valid,
  #output [31:0] io_CPU_response_bits_fetch_PC,
  #output        io_CPU_response_bits_valid_bits_0,
                #io_CPU_response_bits_valid_bits_1,
                #io_CPU_response_bits_valid_bits_2,
                #io_CPU_response_bits_valid_bits_3,
  #output [31:0] io_CPU_response_bits_instructions_0_instruction,
  #output [3:0]  io_CPU_response_bits_instructions_0_packet_index,
  #output [5:0]  io_CPU_response_bits_instructions_0_ROB_index,
  #output [31:0] io_CPU_response_bits_instructions_1_instruction,
  #output [3:0]  io_CPU_response_bits_instructions_1_packet_index,
  #output [5:0]  io_CPU_response_bits_instructions_1_ROB_index,
  #output [31:0] io_CPU_response_bits_instructions_2_instruction,
  #output [3:0]  io_CPU_response_bits_instructions_2_packet_index,
  #output [5:0]  io_CPU_response_bits_instructions_2_ROB_index,
  #output [31:0] io_CPU_response_bits_instructions_3_instruction,
  #output [3:0]  io_CPU_response_bits_instructions_3_packet_index,
  #output [5:0]  io_CPU_response_bits_instructions_3_ROB_index,
  #output [15:0] io_CPU_response_bits_GHR,
  #output [6:0]  io_CPU_response_bits_NEXT,
                #io_CPU_response_bits_TOS