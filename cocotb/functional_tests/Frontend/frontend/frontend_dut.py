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
            await ReadOnly()
            for i in range(4):
                if(self.get_decoder_outputs()["valid"][i]):
                    return 
            await self.update()



    # FTQ output to be valid
    # Each queue being full
    # Each queue being ready


"""
output         io_DRAM_resp_ready,
input          io_DRAM_resp_valid,
input  [255:0] io_DRAM_resp_bits_data,
input          io_DRAM_request_ready,
output         io_DRAM_request_valid,
output [31:0]  io_DRAM_request_bits_addr,
               io_DRAM_request_bits_wr_data,
output         io_DRAM_request_bits_wr_en,
input          io_commit_0_valid,
input  [31:0]  io_commit_0_instruction_PC,
input          io_commit_0_T_NT,
               io_commit_0_is_BR,
               io_commit_0_is_misprediction,
input  [31:0]  io_commit_0_expected_PC,
input  [15:0]  io_commit_0_GHR,
input  [6:0]   io_commit_0_TOS,
                io_commit_0_NEXT,
input  [3:0]   io_commit_0_RAT_IDX,
input          io_commit_1_valid,
input  [31:0]  io_commit_1_instruction_PC,
input          io_commit_1_T_NT,
               io_commit_1_is_BR,
               io_commit_1_is_misprediction,
input  [31:0]  io_commit_1_expected_PC,
input  [15:0]  io_commit_1_GHR,
input  [6:0]   io_commit_1_TOS,
               io_commit_1_NEXT,
input  [3:0]   io_commit_1_RAT_IDX,
input          io_commit_2_valid,
input  [31:0]  io_commit_2_instruction_PC,
input          io_commit_2_T_NT,
               io_commit_2_is_BR,
               io_commit_2_is_misprediction,
input  [31:0]  io_commit_2_expected_PC,
input  [15:0]  io_commit_2_GHR,
input  [6:0]   io_commit_2_TOS,
               io_commit_2_NEXT,
input  [3:0]   io_commit_2_RAT_IDX,
input          io_commit_3_valid,
input  [31:0]  io_commit_3_instruction_PC,
input          io_commit_3_T_NT,
               io_commit_3_is_BR,
               io_commit_3_is_misprediction,
input  [31:0]  io_commit_3_expected_PC,
input  [15:0]  io_commit_3_GHR,
input  [6:0]   io_commit_3_TOS,
               io_commit_3_NEXT,
input  [3:0]   io_commit_3_RAT_IDX,
input          io_predictions_0_ready,
output         io_predictions_0_valid,
               io_predictions_0_bits_valid,
output [31:0]  io_predictions_0_bits_instruction_PC,
output         io_predictions_0_bits_is_misprediction,
output [31:0]  io_predictions_0_bits_predicted_expected_PC,
output [15:0]  io_predictions_0_bits_GHR,
output [6:0]   io_predictions_0_bits_NEXT,
               io_predictions_0_bits_TOS,
output [3:0]   io_predictions_0_bits_RAT_IDX,
input          io_predictions_1_ready,
output         io_predictions_1_valid,
               io_predictions_1_bits_valid,
output [31:0]  io_predictions_1_bits_instruction_PC,
output         io_predictions_1_bits_is_misprediction,
output [31:0]  io_predictions_1_bits_predicted_expected_PC,
output [15:0]  io_predictions_1_bits_GHR,
output [6:0]   io_predictions_1_bits_NEXT,
               io_predictions_1_bits_TOS,
output [3:0]   io_predictions_1_bits_RAT_IDX,
input          io_predictions_2_ready,
output         io_predictions_2_valid,
               io_predictions_2_bits_valid,
output [31:0]  io_predictions_2_bits_instruction_PC,
output         io_predictions_2_bits_is_misprediction,
output [31:0]  io_predictions_2_bits_predicted_expected_PC,
output [15:0]  io_predictions_2_bits_GHR,
output [6:0]   io_predictions_2_bits_NEXT,
               io_predictions_2_bits_TOS,
output [3:0]   io_predictions_2_bits_RAT_IDX,
input          io_predictions_3_ready,
output         io_predictions_3_valid,
               io_predictions_3_bits_valid,
output [31:0]  io_predictions_3_bits_instruction_PC,
output         io_predictions_3_bits_is_misprediction,
output [31:0]  io_predictions_3_bits_predicted_expected_PC,
output [15:0]  io_predictions_3_bits_GHR,
output [6:0]   io_predictions_3_bits_NEXT,
               io_predictions_3_bits_TOS,
output [3:0]   io_predictions_3_bits_RAT_IDX,
input          io_renamed_decoded_fetch_packet_0_ready,
output         io_renamed_decoded_fetch_packet_0_valid,
               io_renamed_decoded_fetch_packet_0_bits_ready_bits_RS1_ready,
               io_renamed_decoded_fetch_packet_0_bits_ready_bits_RS2_ready,
output [5:0]   io_renamed_decoded_fetch_packet_0_bits_RD,
output         io_renamed_decoded_fetch_packet_0_bits_RD_valid,
output [5:0]   io_renamed_decoded_fetch_packet_0_bits_RS1,
output         io_renamed_decoded_fetch_packet_0_bits_RS1_valid,
output [5:0]   io_renamed_decoded_fetch_packet_0_bits_RS2,
output         io_renamed_decoded_fetch_packet_0_bits_RS2_valid,
output [31:0]  io_renamed_decoded_fetch_packet_0_bits_IMM,
output [2:0]   io_renamed_decoded_fetch_packet_0_bits_FUNCT3,
output [3:0]   io_renamed_decoded_fetch_packet_0_bits_packet_index,
output [5:0]   io_renamed_decoded_fetch_packet_0_bits_ROB_index,
output [4:0]   io_renamed_decoded_fetch_packet_0_bits_instructionType,
output [1:0]   io_renamed_decoded_fetch_packet_0_bits_portID,
               io_renamed_decoded_fetch_packet_0_bits_RS_type,
output         io_renamed_decoded_fetch_packet_0_bits_needs_ALU,
               io_renamed_decoded_fetch_packet_0_bits_needs_branch_unit,
               io_renamed_decoded_fetch_packet_0_bits_needs_CSRs,
               io_renamed_decoded_fetch_packet_0_bits_SUBTRACT,
               io_renamed_decoded_fetch_packet_0_bits_MULTIPLY,
               io_renamed_decoded_fetch_packet_0_bits_IMMEDIATE,
               io_renamed_decoded_fetch_packet_0_bits_IS_LOAD,
               io_renamed_decoded_fetch_packet_0_bits_IS_STORE,
input          io_renamed_decoded_fetch_packet_1_ready,
output         io_renamed_decoded_fetch_packet_1_valid,
               io_renamed_decoded_fetch_packet_1_bits_ready_bits_RS1_ready,
               io_renamed_decoded_fetch_packet_1_bits_ready_bits_RS2_ready,
output [5:0]   io_renamed_decoded_fetch_packet_1_bits_RD,
output         io_renamed_decoded_fetch_packet_1_bits_RD_valid,
output [5:0]   io_renamed_decoded_fetch_packet_1_bits_RS1,
output         io_renamed_decoded_fetch_packet_1_bits_RS1_valid,
output [5:0]   io_renamed_decoded_fetch_packet_1_bits_RS2,
output         io_renamed_decoded_fetch_packet_1_bits_RS2_valid,
output [31:0]  io_renamed_decoded_fetch_packet_1_bits_IMM,
output [2:0]   io_renamed_decoded_fetch_packet_1_bits_FUNCT3,
output [3:0]   io_renamed_decoded_fetch_packet_1_bits_packet_index,
output [5:0]   io_renamed_decoded_fetch_packet_1_bits_ROB_index,
output [4:0]   io_renamed_decoded_fetch_packet_1_bits_instructionType,
output [1:0]   io_renamed_decoded_fetch_packet_1_bits_portID,
               io_renamed_decoded_fetch_packet_1_bits_RS_type,
output         io_renamed_decoded_fetch_packet_1_bits_needs_ALU,
               io_renamed_decoded_fetch_packet_1_bits_needs_branch_unit,
               io_renamed_decoded_fetch_packet_1_bits_needs_CSRs,
               io_renamed_decoded_fetch_packet_1_bits_SUBTRACT,
               io_renamed_decoded_fetch_packet_1_bits_MULTIPLY,
               io_renamed_decoded_fetch_packet_1_bits_IMMEDIATE,
               io_renamed_decoded_fetch_packet_1_bits_IS_LOAD,
               io_renamed_decoded_fetch_packet_1_bits_IS_STORE,
input          io_renamed_decoded_fetch_packet_2_ready,
output         io_renamed_decoded_fetch_packet_2_valid,
               io_renamed_decoded_fetch_packet_2_bits_ready_bits_RS1_ready,
               io_renamed_decoded_fetch_packet_2_bits_ready_bits_RS2_ready,
output [5:0]   io_renamed_decoded_fetch_packet_2_bits_RD,
output         io_renamed_decoded_fetch_packet_2_bits_RD_valid,
output [5:0]   io_renamed_decoded_fetch_packet_2_bits_RS1,
output         io_renamed_decoded_fetch_packet_2_bits_RS1_valid,
output [5:0]   io_renamed_decoded_fetch_packet_2_bits_RS2,
output         io_renamed_decoded_fetch_packet_2_bits_RS2_valid,
output [31:0]  io_renamed_decoded_fetch_packet_2_bits_IMM,
output [2:0]   io_renamed_decoded_fetch_packet_2_bits_FUNCT3,
output [3:0]   io_renamed_decoded_fetch_packet_2_bits_packet_index,
output [5:0]   io_renamed_decoded_fetch_packet_2_bits_ROB_index,
output [4:0]   io_renamed_decoded_fetch_packet_2_bits_instructionType,
output [1:0]   io_renamed_decoded_fetch_packet_2_bits_portID,
               io_renamed_decoded_fetch_packet_2_bits_RS_type,
output         io_renamed_decoded_fetch_packet_2_bits_needs_ALU,
               io_renamed_decoded_fetch_packet_2_bits_needs_branch_unit,
               io_renamed_decoded_fetch_packet_2_bits_needs_CSRs,
               io_renamed_decoded_fetch_packet_2_bits_SUBTRACT,
               io_renamed_decoded_fetch_packet_2_bits_MULTIPLY,
               io_renamed_decoded_fetch_packet_2_bits_IMMEDIATE,
               io_renamed_decoded_fetch_packet_2_bits_IS_LOAD,
               io_renamed_decoded_fetch_packet_2_bits_IS_STORE,
input          io_renamed_decoded_fetch_packet_3_ready,
output         io_renamed_decoded_fetch_packet_3_valid,
               io_renamed_decoded_fetch_packet_3_bits_ready_bits_RS1_ready,
               io_renamed_decoded_fetch_packet_3_bits_ready_bits_RS2_ready,
output [5:0]   io_renamed_decoded_fetch_packet_3_bits_RD,
output         io_renamed_decoded_fetch_packet_3_bits_RD_valid,
output [5:0]   io_renamed_decoded_fetch_packet_3_bits_RS1,
output         io_renamed_decoded_fetch_packet_3_bits_RS1_valid,
output [5:0]   io_renamed_decoded_fetch_packet_3_bits_RS2,
output         io_renamed_decoded_fetch_packet_3_bits_RS2_valid,
output [31:0]  io_renamed_decoded_fetch_packet_3_bits_IMM,
output [2:0]   io_renamed_decoded_fetch_packet_3_bits_FUNCT3,
output [3:0]   io_renamed_decoded_fetch_packet_3_bits_packet_index,
output [5:0]   io_renamed_decoded_fetch_packet_3_bits_ROB_index,
output [4:0]   io_renamed_decoded_fetch_packet_3_bits_instructionType,
output [1:0]   io_renamed_decoded_fetch_packet_3_bits_portID,
               io_renamed_decoded_fetch_packet_3_bits_RS_type,
output         io_renamed_decoded_fetch_packet_3_bits_needs_ALU,
               io_renamed_decoded_fetch_packet_3_bits_needs_branch_unit,
               io_renamed_decoded_fetch_packet_3_bits_needs_CSRs,
               io_renamed_decoded_fetch_packet_3_bits_SUBTRACT,
               io_renamed_decoded_fetch_packet_3_bits_MULTIPLY,
               io_renamed_decoded_fetch_packet_3_bits_IMMEDIATE,
               io_renamed_decoded_fetch_packet_3_bits_IS_LOAD,
               io_renamed_decoded_fetch_packet_3_bits_IS_STORE,
input          io_MEMRS_ready_0,
               io_MEMRS_ready_1,
               io_MEMRS_ready_2,
               io_MEMRS_ready_3,
               io_INTRS_ready_0,
               io_INTRS_ready_1,
               io_INTRS_ready_2,
               io_INTRS_ready_3,
               io_ROB_packet_0_ready,
output         io_ROB_packet_0_valid,
               io_ROB_packet_0_bits_valid,
               io_ROB_packet_0_bits_is_branch,
input          io_ROB_packet_1_ready,
output         io_ROB_packet_1_valid,
               io_ROB_packet_1_bits_valid,
               io_ROB_packet_1_bits_is_branch,
input          io_ROB_packet_2_ready,
output         io_ROB_packet_2_valid,
               io_ROB_packet_2_bits_valid,
               io_ROB_packet_2_bits_is_branch,
input          io_ROB_packet_3_ready,
output         io_ROB_packet_3_valid,
               io_ROB_packet_3_bits_valid,
               io_ROB_packet_3_bits_is_branch,
input          io_FU_outputs_0_valid,
input  [63:0]  io_FU_outputs_0_bits_RD,
input  [31:0]  io_FU_outputs_0_bits_RD_data,
input          io_FU_outputs_0_bits_RD_valid,
input  [31:0]  io_FU_outputs_0_bits_instruction_PC,
input          io_FU_outputs_0_bits_branch_taken,
input  [31:0]  io_FU_outputs_0_bits_target_address,
input          io_FU_outputs_0_bits_branch_valid,
input  [5:0]   io_FU_outputs_0_bits_ROB_index,
input  [1:0]   io_FU_outputs_0_bits_fetch_packet_index,
input          io_FU_outputs_1_valid,
input  [63:0]  io_FU_outputs_1_bits_RD,
input  [31:0]  io_FU_outputs_1_bits_RD_data,
input          io_FU_outputs_1_bits_RD_valid,
input  [31:0]  io_FU_outputs_1_bits_instruction_PC,
input          io_FU_outputs_1_bits_branch_taken,
input  [31:0]  io_FU_outputs_1_bits_target_address,
input          io_FU_outputs_1_bits_branch_valid,
input  [5:0]   io_FU_outputs_1_bits_ROB_index,
input  [1:0]   io_FU_outputs_1_bits_fetch_packet_index,
input          io_FU_outputs_2_valid,
input  [63:0]  io_FU_outputs_2_bits_RD,
input  [31:0]  io_FU_outputs_2_bits_RD_data,
input          io_FU_outputs_2_bits_RD_valid,
input  [31:0]  io_FU_outputs_2_bits_instruction_PC,
input          io_FU_outputs_2_bits_branch_taken,
input  [31:0]  io_FU_outputs_2_bits_target_address,
input          io_FU_outputs_2_bits_branch_valid,
input  [5:0]   io_FU_outputs_2_bits_ROB_index,
input  [1:0]   io_FU_outputs_2_bits_fetch_packet_index,
input          io_FU_outputs_3_valid,
input  [63:0]  io_FU_outputs_3_bits_RD,
input  [31:0]  io_FU_outputs_3_bits_RD_data,
input          io_FU_outputs_3_bits_RD_valid,
input  [31:0]  io_FU_outputs_3_bits_instruction_PC,
input          io_FU_outputs_3_bits_branch_taken,
input  [31:0]  io_FU_outputs_3_bits_target_address,
input          io_FU_outputs_3_bits_branch_valid,
input  [5:0]   io_FU_outputs_3_bits_ROB_index,
input  [1:0]   io_FU_outputs_3_bits_fetch_packet_index
"""