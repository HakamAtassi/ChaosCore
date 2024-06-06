import sys
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly
from tabulate import tabulate

from SimpleDRAM import *
# Add helper functions as needed


class frontend_dut:
    def __init__(self, dut, DRAM, DRAM_line_size=32):    # modify as needed (parameters, etc...)
        self.dut = dut
        self.DRAM = DRAM

        # Control signals
        self.DRAM_request       = False
        self.DRAM_request_addr  = 0x0
        self.DRAM_request_size  = DRAM_line_size
        #...

    def clock(self):            # Do not touch
        return self.dut.clock

    async def reset(self):      # Do not touch
        self.dut.reset.value = 0
        await RisingEdge(self.dut.clock)
        self.dut.reset.value = 1
        await RisingEdge(self.dut.clock)
        self.dut.reset.value = 0

    # complete class body...


    def write_dram_resp(self, data=0, valid = 0):
        self.dut.io_DRAM_resp_valid.value = valid
        self.dut.io_DRAM_resp_bits_data.value = data
        #input          io_DRAM_request_ready,

    def set_DRAM_ready(self, ready=0):
        self.dut.io_DRAM_request_ready.value = ready

    def read_output(self):
        outputs = {}
        outputs["resp_ready"]           = int(self.dut.io_DRAM_resp_ready.value)
        outputs["request_valid"]        = int(self.dut.io_DRAM_request_valid.value)
        outputs["request_addr"]         = int(self.dut.io_DRAM_request_bits_addr.value)
        outputs["request_wr_en"]        = int(self.dut.io_DRAM_request_bits_wr_en.value)

        return outputs

    def get_renamed_decoded_fetch_packet(self):
        outputs = {}
        outputs["valid"]            = [0] * 4
        outputs["RS1_ready"]        = [0] * 4
        outputs["RS2_ready"]        = [0] * 4
        outputs["RD"]               = [0] * 4
        outputs["RD_valid"]         = [0] * 4
        outputs["RS1"]              = [0] * 4
        outputs["RS1_valid"]        = [0] * 4
        outputs["RS2"]              = [0] * 4
        outputs["RS2_valid"]        = [0] * 4
        outputs["IMM"]              = [0] * 4
        outputs["FUNCT3"]           = [0] * 4
        outputs["packet_index"]     = [0] * 4
        outputs["ROB_index"]        = [0] * 4
        outputs["instructionType"]  = [0] * 4
        outputs["portID"]           = [0] * 4
        outputs["RS_type"]          = [0] * 4
        outputs["needs_ALU"]        = [0] * 4
        outputs["needs_branch_unit"] = [0] * 4
        outputs["needs_CSRs"]       = [0] * 4
        outputs["SUBTRACT"]         = [0] * 4
        outputs["MULTIPLY"]         = [0] * 4
        outputs["IMMEDIATE"]        = [0] * 4
        outputs["IS_LOAD"]          = [0] * 4
        outputs["IS_STORE"]         = [0] * 4

        for i in range(4):
            outputs["valid"][i] = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_{i}_valid").value)
            outputs["RS1_ready"][i] = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_{i}_bits_ready_bits_RS1_ready").value)
            outputs["RS2_ready"][i] = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_{i}_bits_ready_bits_RS2_ready").value)
            outputs["RD"][i] = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_{i}_bits_RD").value)
            outputs["RD_valid"][i] = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_{i}_bits_RD_valid").value)
            outputs["RS1"][i] = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_{i}_bits_RS1").value)
            outputs["RS1_valid"][i] = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_{i}_bits_RS1_valid").value)
            outputs["RS2"][i] = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_{i}_bits_RS2").value)
            outputs["RS2_valid"][i] = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_{i}_bits_RS2_valid").value)
            outputs["IMM"][i] = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_{i}_bits_IMM").value)
            outputs["FUNCT3"][i] = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_{i}_bits_FUNCT3").value)
            outputs["packet_index"][i] = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_{i}_bits_packet_index").value)
            outputs["ROB_index"][i] = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_{i}_bits_ROB_index").value)
            outputs["instructionType"][i] = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_{i}_bits_instructionType").value)
            outputs["portID"][i] = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_{i}_bits_portID").value)
            outputs["RS_type"][i] = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_{i}_bits_RS_type").value)
            outputs["needs_ALU"][i] = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_{i}_bits_needs_ALU").value)
            outputs["needs_branch_unit"][i] = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_{i}_bits_needs_branch_unit").value)
            outputs["needs_CSRs"][i] = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_{i}_bits_needs_CSRs").value)
            outputs["SUBTRACT"][i] = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_{i}_bits_SUBTRACT").value)
            outputs["MULTIPLY"][i] = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_{i}_bits_MULTIPLY").value)
            outputs["IMMEDIATE"][i] = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_{i}_bits_IMMEDIATE").value)
            outputs["IS_LOAD"][i] = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_{i}_bits_IS_LOAD").value)
            outputs["IS_STORE"][i] = int(getattr(self.dut, f"io_renamed_decoded_fetch_packet_{i}_bits_IS_STORE").value)

        return outputs



    def print_renamed_decoded_fetch_packet(self):
        outputs = self.get_renamed_decoded_fetch_packet()
        headers = ["Data Name"] + [f"Entry {i}" for i in range(len(outputs["valid"]))]
        table = []

        for key in outputs:
            row = [key] + outputs[key]
            table.append(row)

        print(tabulate(table, headers=headers, tablefmt="grid"))


    def print_decoder_outputs(self):
        outputs = self.get_decoder_outputs()
        headers = ["Data Name"] + [f"Entry {i}" for i in range(len(outputs["valid"]))]
        table = []

        for key in outputs:
            row = [key] + outputs[key]
            table.append(row)

        print(tabulate(table, headers=headers, tablefmt="grid"))

    def get_decoder_outputs(self):
        outputs = {}
        outputs["valid"] = [0] * 4
        outputs["RD"] = [0] * 4
        outputs["RD_valid"] = [0] * 4
        outputs["RS1"] = [0] * 4
        outputs["RS2"] = [0] * 4
        outputs["IMM"] = [0] * 4
        outputs["FUNCT3"] = [0] * 4
        outputs["packet_index"] = [0] * 4
        outputs["ROB_index"] = [0] * 4
        outputs["instructionType"] = [0] * 4
        outputs["portID"] = [0] * 4
        outputs["RS_type"] = [0] * 4
        outputs["needs_ALU"] = [0] * 4
        outputs["needs_branch_unit"] = [0] * 4
        outputs["SUBTRACT"] = [0] * 4
        outputs["MULTIPLY"] = [0] * 4
        outputs["IMMEDIATE"] = [0] * 4
        outputs["IS_LOAD"] = [0] * 4
        outputs["IS_STORE"] = [0] * 4

        for i in range(4):
            outputs["valid"][i]             = int(getattr(self.dut, f"decoders.io_decoded_fetch_packet_{i}_valid").value)
            outputs["RD"][i]                = int(getattr(self.dut, f"decoders.io_decoded_fetch_packet_{i}_bits_RD").value)
            outputs["RD_valid"][i]          = int(getattr(self.dut, f"decoders.io_decoded_fetch_packet_{i}_bits_RD_valid").value)
            outputs["RS1"][i]               = int(getattr(self.dut, f"decoders.io_decoded_fetch_packet_{i}_bits_RS1").value)
            outputs["RS2"][i]               = int(getattr(self.dut, f"decoders.io_decoded_fetch_packet_{i}_bits_RS2").value)
            outputs["IMM"][i]               = int(getattr(self.dut, f"decoders.io_decoded_fetch_packet_{i}_bits_IMM").value)
            outputs["FUNCT3"][i]            = int(getattr(self.dut, f"decoders.io_decoded_fetch_packet_{i}_bits_FUNCT3").value)
            outputs["packet_index"][i]      = int(getattr(self.dut, f"decoders.io_decoded_fetch_packet_{i}_bits_packet_index").value)
            outputs["ROB_index"][i]         = int(getattr(self.dut, f"decoders.io_decoded_fetch_packet_{i}_bits_ROB_index").value)
            outputs["instructionType"][i]   = int(getattr(self.dut, f"decoders.io_decoded_fetch_packet_{i}_bits_instructionType").value)
            outputs["portID"][i]            = int(getattr(self.dut, f"decoders.io_decoded_fetch_packet_{i}_bits_portID").value)
            outputs["RS_type"][i]           = int(getattr(self.dut, f"decoders.io_decoded_fetch_packet_{i}_bits_RS_type").value)
            outputs["needs_ALU"][i]         = int(getattr(self.dut, f"decoders.io_decoded_fetch_packet_{i}_bits_needs_ALU").value)
            outputs["needs_branch_unit"][i] = int(getattr(self.dut, f"decoders.io_decoded_fetch_packet_{i}_bits_needs_branch_unit").value)
            outputs["SUBTRACT"][i]          = int(getattr(self.dut, f"decoders.io_decoded_fetch_packet_{i}_bits_SUBTRACT").value)
            outputs["MULTIPLY"][i]          = int(getattr(self.dut, f"decoders.io_decoded_fetch_packet_{i}_bits_MULTIPLY").value)
            outputs["IMMEDIATE"][i]         = int(getattr(self.dut, f"decoders.io_decoded_fetch_packet_{i}_bits_IMMEDIATE").value)
            outputs["IS_LOAD"][i]           = int(getattr(self.dut, f"decoders.io_decoded_fetch_packet_{i}_bits_IS_LOAD").value)
            outputs["IS_STORE"][i]          = int(getattr(self.dut, f"decoders.io_decoded_fetch_packet_{i}_bits_IS_STORE").value)

        return outputs

    
    #####################
    ## CACHE FUNCTIONS ##
    #####################

    def get_cache_data(self):
        cache = []
        for way in range(2):
            data=[]
            for set in range(64):
                line = int(getattr(self.dut, f"instruction_fetch.instruction_cache.data_memory_{way}.ram_ext.Memory")[set].value)
                data.append(line)
            cache.append(data)
        return cache


    def get_cache_outputs(self):
        outputs = {}
        outputs["cpu_addr_ready"] = self.dut.instruction_fetch.instruction_cache.io_cpu_addr_ready.value
        return outputs

    def get_cache_hit(self):
        return int(self.dut.instruction_fetch.instruction_cache.hit.value)

    def print_cache(self):
        cache = self.get_cache_data()
        for way in range(2):
            print(f"way {way}")
            for set in range(64):
                print(f"{set}: {hex(cache[way][set])}")

    ##########
    ## PC_Q ##
    ##########

    def get_PC_Q(self):
        queue = []
        for i in range(16):
            line = int(getattr(self.dut, f"instruction_fetch.PC_Q.queue.ram_ext.Memory").value[i])
            queue.append(line)
        return queue


    ###################
    ## INSTRUCTION_Q ##
    ###################

    def get_instruction_Q(self):
        queue = []
        for i in range(16):
            line = hex(int(getattr(self.dut, f"instruction_fetch.instruction_Q.queue.ram_ext.Memory").value[i]))
            queue.append(line)
        return queue

    def get_PC(self):
        PC = int(self.dut.instruction_fetch.PC_gen.io_PC_next_bits.value)
        return PC


    async def update(self):
        # await cycle
        # if needs memory (from prev cycle)
            # send data from dram model
        # await ReadOnly()
        # set mem addr flag, size, etc

        await RisingEdge(self.dut.clock)

        # Clear writes from prev cycle (so you dont write twice)
        self.write_dram_resp()

        if(self.DRAM_request):
            data = self.DRAM.read(address=self.DRAM_request_addr, size=self.DRAM_request_size)
            self.write_dram_resp(data, 1)

        await ReadOnly()

        self.DRAM_request       =   self.read_output()["request_valid"]
        self.DRAM_request_addr  =   self.read_output()["request_addr"]

    
    ####################
    ## WAIT FUNCTIONS ##
    ####################

    # What useful things may you want to wait for (but dont care how long it takes to get there)?

    async def wait_frontend_output_valid(self):
        while(1):
            await ReadOnly()
            for i in range(4):
                if(self.get_renamed_decoded_fetch_packet()["valid"][i]):
                    return 
            await self.update()

    async def wait_cache_request_valid(self):
        while(1):
            await ReadOnly()
            if(self.read_output()["request_valid"]):
                return 
            await self.update()

    async def wait_decoder_outputs_valid(self):
        while(1):
            for i in range(4):
                await ReadOnly()
                if(self.get_decoder_outputs()["valid"][i]):
                    return 
            await self.update()



    # FTQ output to be valid
    # Each queue being full
    # Each queue being ready

