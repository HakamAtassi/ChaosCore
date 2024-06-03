import sys
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly

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

    def read_output(self):
        outputs = {}
        outputs["resp_ready"]           = int(self.dut.io_DRAM_resp_ready.value)
        outputs["request_valid"]        = int(self.dut.io_DRAM_request_valid.value)
        outputs["request_addr"]         = int(self.dut.io_DRAM_request_bits_addr.value)
        outputs["request_wr_en"]        = int(self.dut.io_DRAM_request_bits_wr_en.value)
        return outputs
    
    def get_cache(self):
        cache = []
        for way in range(2):
            data=[]
            for set in range(64):
                line = int(getattr(self.dut, f"instruction_fetch.instruction_cache.data_memory_{way}.ram_ext.Memory")[set].value)
                data.append(line)
            cache.append(data)
        return cache


    def get_PC_Q(self):
        queue = []
        for i in range(16):
            line = int(getattr(self.dut, f"instruction_fetch.PC_Q.queue.ram_ext.Memory").value[i])
            queue.append(line)
        return queue

    def print_cache(self):
        cache = self.get_cache()
        for way in range(2):
            print(f"way {way}")
            for set in range(64):
                print(f"{set}: {hex(cache[way][set])}")


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