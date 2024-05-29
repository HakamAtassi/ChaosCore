import sys
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, Timer

# Add helper functions as needed


class instruction_cache_dut:
    def __init__(self, dut, ways, sets):    # modify as needed (parameters, etc...)
        self.sets = sets
        self.ways = ways
        self.dut = dut

    def clock(self):            # Do not touch
        return self.dut.clock

    async def reset(self):      # Do not touch
        self.dut.reset.value = 0
        await RisingEdge(self.dut.clock)
        self.dut.reset.value = 1
        await RisingEdge(self.dut.clock)
        self.dut.reset.value = 0
        await RisingEdge(self.dut.clock)

    # Set outputs Ready
    def set_cache_ready(self, ready):
        self.dut.io_cache_data_ready.value = ready

    def set_dram_ready(self, ready):
        self.dut.io_DRAM_request_ready.value = ready

    # Write
    def write_cache_CPU(self, addr=0, valid=0):  # Write to cache from CPU
        self.dut.io_cpu_addr_bits.value  = addr
        self.dut.io_cpu_addr_valid.value = valid

    def kill_cache(self, kill):       # Kill current cache request
        self.dut.io_kill = kill

    def write_cache_DRAM(self, data=0, valid=0): # Write to cache from DRAM 
        self.dut.io_DRAM_resp_valid.value = valid
        self.dut.io_DRAM_resp_bits_data.value = data

    # Get
    def get_output(self):
        outputs = {}

        outputs["valid"] = self.dut.io_cache_data_valid.value

        outputs["Ready"] = self.dut.io_cpu_addr_ready.value

        outputs["fetch_PC"] = self.dut.io_cache_data_bits_fetch_PC.value

        outputs["instruction_valid"] = [0]*4
        outputs["instruction_valid"][0] = self.dut.io_cache_data_bits_valid_bits_0.value
        outputs["instruction_valid"][1] = self.dut.io_cache_data_bits_valid_bits_1.value
        outputs["instruction_valid"][2] = self.dut.io_cache_data_bits_valid_bits_2.value
        outputs["instruction_valid"][3] = self.dut.io_cache_data_bits_valid_bits_3.value

        outputs["instruction"]  = [0]*4
        outputs["packet_index"] = [0]*4
        outputs["ROB_index"]    = [0]*4

        outputs["instruction"][0]   = self.dut.io_cache_data_bits_instructions_0_instruction.value
        outputs["packet_index"][0]  = self.dut.io_cache_data_bits_instructions_0_packet_index.value
        outputs["ROB_index"][0]     = self.dut.io_cache_data_bits_instructions_0_ROB_index.value

        outputs["instruction"][1]   = self.dut.io_cache_data_bits_instructions_1_instruction.value
        outputs["packet_index"][1]  = self.dut.io_cache_data_bits_instructions_1_packet_index.value
        outputs["ROB_index"][1]     = self.dut.io_cache_data_bits_instructions_1_ROB_index.value

        outputs["instruction"][2]   = self.dut.io_cache_data_bits_instructions_2_instruction.value
        outputs["packet_index"][2]  = self.dut.io_cache_data_bits_instructions_2_packet_index.value
        outputs["ROB_index"][2]     = self.dut.io_cache_data_bits_instructions_2_ROB_index.value

        outputs["instruction"][3]   = self.dut.io_cache_data_bits_instructions_3_instruction.value
        outputs["packet_index"][3]  = self.dut.io_cache_data_bits_instructions_3_packet_index.value
        outputs["ROB_index"][3]     = self.dut.io_cache_data_bits_instructions_3_ROB_index.value

        outputs["DRAM_request_valid"]   =   self.dut.io_DRAM_request_valid.value
        outputs["DRAM_request_addr"]    =   self.dut.io_DRAM_request_bits_addr.value
        return outputs

    def get_data_mem(self):
        pass
    
    def print_data_mem(self):
        for i in range(self.sets):
            way0_data = hex(getattr(self.dut, f"data_memory_0.ram_ext.Memory")[i].value)
            way1_data = hex(getattr(self.dut, f"data_memory_1.ram_ext.Memory")[i].value)
            print(f"set: {i} {way0_data} {way1_data}")


    def get_tag_mem(self):
        pass

    def get_valid_mem(self):
        pass

    def get_LRU_mem(self):
        pass

    # Visualize cache state
    def print_cache(self):
        pass

  
#output        io_cpu_addr_ready,
#input         io_cpu_addr_valid,
#input  [31:0] io_cpu_addr_bits,
#input         io_kill,
#output        io_DRAM_resp_ready,
#input         io_DRAM_resp_valid,
#input  [31:0] io_DRAM_resp_bits_data,
#input         io_cache_data_ready,    # Done
#output        io_cache_data_valid,    
#output [31:0] io_cache_data_bits_fetch_PC,
#output        io_cache_data_bits_valid_bits_0,
            #io_cache_data_bits_valid_bits_1,
            #io_cache_data_bits_valid_bits_2,
            #io_cache_data_bits_valid_bits_3,
#output [31:0] io_cache_data_bits_instructions_0_instruction,
#output [3:0]  io_cache_data_bits_instructions_0_packet_index,
#output [5:0]  io_cache_data_bits_instructions_0_ROB_index,
#output [31:0] io_cache_data_bits_instructions_1_instruction,
#output [3:0]  io_cache_data_bits_instructions_1_packet_index,
#output [5:0]  io_cache_data_bits_instructions_1_ROB_index,
#output [31:0] io_cache_data_bits_instructions_2_instruction,
#output [3:0]  io_cache_data_bits_instructions_2_packet_index,
#output [5:0]  io_cache_data_bits_instructions_2_ROB_index,
#output [31:0] io_cache_data_bits_instructions_3_instruction,
#output [3:0]  io_cache_data_bits_instructions_3_packet_index,
#output [5:0]  io_cache_data_bits_instructions_3_ROB_index,
#input         io_DRAM_request_ready,
#output        io_DRAM_request_valid,

#output [31:0] io_DRAM_request_bits_addr,
            #io_DRAM_request_bits_wr_data,
#output        io_DRAM_request_bits_wr_en
