import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path
import os

from model_utils import *
from cocotb_utils import *



@cocotb.test()
async def test_reset(dut):
    #Set seed
    random.seed(0x42)

    #Start lock
    await cocotb.start(generateClock(dut))

@cocotb.test()
async def test_rename0(dut):
    #Set seed
    random.seed(0x42)

    #Start lock
    await cocotb.start(generateClock(dut))

    dut.reset.value = 1
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    dut.reset.value = 0
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)


    getattr(dut, f"io_renamed_decoded_fetch_packet_ready").value                                = 1

    await RisingEdge(dut.clock)

#    for i in range(64): # drain free list
        #getattr(dut, f"io_decoded_fetch_packet_valid").value                                        = 1
        #getattr(dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{0}_RD").value              = 1
        #getattr(dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{0}_RD_valid").value        = 1
        #getattr(dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{0}_RS1").value             = 0
        #getattr(dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{0}_RS2").value             = 0
        #getattr(dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{0}_RS1_valid").value       = 0
        #getattr(dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{0}_RS2_valid").value       = 0
        #await RisingEdge(dut.clock)

    #getattr(dut, f"io_decoded_fetch_packet_valid").value                                        = 0
    #getattr(dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{0}_RD").value              = 0
    #getattr(dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{0}_RD_valid").value        = 0
    #getattr(dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{0}_RS1").value             = 0
    #getattr(dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{0}_RS2").value             = 0
    #getattr(dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{0}_RS1_valid").value       = 0
    #getattr(dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{0}_RS2_valid").value       = 0

    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    for i in range(32):
        getattr(dut, f"io_commit_valid").value                      = 1
        getattr(dut, f"io_commit_bits_is_misprediction").value      = 0
        getattr(dut, f"io_partial_commit_valid_{0}").value          = 1
        getattr(dut, f"io_partial_commit_ROB_index").value          = 0
        getattr(dut, f"io_partial_commit_MOB_index_{0}").value      = 0

        getattr(dut, f"io_partial_commit_RD_{0}").value             = 0
        getattr(dut, f"io_partial_commit_PRD_{0}").value            = i

        getattr(dut, f"io_partial_commit_PRDold_{0}").value         = 0
        getattr(dut, f"io_partial_commit_RD_valid_{0}").value       = 1

        await RisingEdge(dut.clock)

    getattr(dut, f"io_commit_valid").value                      = 1
    getattr(dut, f"io_commit_bits_is_misprediction").value      = 1
    getattr(dut, f"io_partial_commit_valid_{0}").value          = 1
    getattr(dut, f"io_partial_commit_ROB_index").value          = 0
    getattr(dut, f"io_partial_commit_MOB_index_{0}").value      = 0

    getattr(dut, f"io_partial_commit_RD_{0}").value             = 0
    getattr(dut, f"io_partial_commit_PRD_{0}").value            = 0

    getattr(dut, f"io_partial_commit_PRDold_{0}").value         = 3
    getattr(dut, f"io_partial_commit_RD_valid_{0}").value       = 1

    await RisingEdge(dut.clock)

    getattr(dut, f"io_commit_valid").value                      = 0
    getattr(dut, f"io_commit_bits_is_misprediction").value      = 0
    getattr(dut, f"io_partial_commit_valid_{0}").value          = 0
    getattr(dut, f"io_partial_commit_ROB_index").value          = 0
    getattr(dut, f"io_partial_commit_MOB_index_{0}").value      = 0
    getattr(dut, f"io_partial_commit_RD_{0}").value             = 0
    getattr(dut, f"io_partial_commit_PRD_{0}").value            = 0
    getattr(dut, f"io_partial_commit_PRDold_{0}").value         = 0
    getattr(dut, f"io_partial_commit_RD_valid_{0}").value       = 0


    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)






# INPUTS
#io_decoded_fetch_packet_valid
#io_decoded_fetch_packet_bits_decoded_instruction_0_RD,
#io_decoded_fetch_packet_bits_decoded_instruction_0_RD_valid,
#io_decoded_fetch_packet_bits_decoded_instruction_0_RS1,
#io_decoded_fetch_packet_bits_decoded_instruction_0_RS2,
#io_decoded_fetch_packet_bits_decoded_instruction_0_RS1_valid,
#io_decoded_fetch_packet_bits_decoded_instruction_0_RS2_valid,

# commit
#io_commit_valid,
#io_commit_bits_is_misprediction,

#io_partial_commit_valid_0,
#io_partial_commit_ROB_index,
#io_partial_commit_MOB_index_0,
#io_partial_commit_PRD_0,
#io_partial_commit_PRDold_0,
#io_partial_commit_RD_valid_0,
#io_partial_commit_RD_0,

#io_flush,
#io_commit_valid,
#io_commit_bits_fetch_PC,
#io_commit_bits_T_NT,
#io_commit_bits_ROB_index,
#io_commit_bits_br_type,
#io_commit_bits_fetch_packet_index,
#io_commit_bits_is_misprediction,
#io_commit_bits_expected_PC,
#io_commit_bits_GHR,
#io_commit_bits_TOS,
#io_commit_bits_NEXT,
#io_commit_bits_free_list_front_pointer,
#io_commit_bits_RD_0,
#io_commit_bits_RD_1,
#io_commit_bits_RD_2,
#io_commit_bits_RD_3,
#io_commit_bits_PRD_0,
#io_commit_bits_PRD_1,
#io_commit_bits_PRD_2,
#io_commit_bits_PRD_3,
#io_commit_bits_RD_valid_0,
#io_commit_bits_RD_valid_1,
#io_commit_bits_RD_valid_2,
#io_commit_bits_RD_valid_3,
#io_partial_commit_valid_0,
#io_partial_commit_valid_1,
#io_partial_commit_valid_2,
#io_partial_commit_valid_3,
#io_partial_commit_ROB_index,
#io_partial_commit_MOB_index_0,
#io_partial_commit_MOB_index_1,
#io_partial_commit_MOB_index_2,
#io_partial_commit_MOB_index_3,
#io_partial_commit_PRD_0,
#io_partial_commit_PRD_1,
#io_partial_commit_PRD_2,
#io_partial_commit_PRD_3,
#io_partial_commit_PRDold_0,
#io_partial_commit_PRDold_1,
#io_partial_commit_PRDold_2,
#io_partial_commit_PRDold_3,
#io_partial_commit_RD_valid_0,
#io_partial_commit_RD_valid_1,
#io_partial_commit_RD_valid_2,
#io_partial_commit_RD_valid_3,
#io_partial_commit_RD_0,
#io_partial_commit_RD_1,
#io_partial_commit_RD_2,
#io_partial_commit_RD_3,


#io_decoded_fetch_packet_ready,
#io_decoded_fetch_packet_valid,
#io_decoded_fetch_packet_bits_fetch_PC,
#io_decoded_fetch_packet_bits_decoded_instruction_0_ready_bits_RS1_ready,
#io_decoded_fetch_packet_bits_decoded_instruction_0_ready_bits_RS2_ready,
#io_decoded_fetch_packet_bits_decoded_instruction_0_RD,
#io_decoded_fetch_packet_bits_decoded_instruction_0_PRD,
#io_decoded_fetch_packet_bits_decoded_instruction_0_PRDold,
#io_decoded_fetch_packet_bits_decoded_instruction_0_RD_valid,
#io_decoded_fetch_packet_bits_decoded_instruction_0_RS1,
#io_decoded_fetch_packet_bits_decoded_instruction_0_RS1_valid,
#io_decoded_fetch_packet_bits_decoded_instruction_0_RS2,
#io_decoded_fetch_packet_bits_decoded_instruction_0_RS2_valid,
#io_decoded_fetch_packet_bits_decoded_instruction_0_IMM,
#io_decoded_fetch_packet_bits_decoded_instruction_0_FUNCT3,
#io_decoded_fetch_packet_bits_decoded_instruction_0_packet_index,
#io_decoded_fetch_packet_bits_decoded_instruction_0_ROB_index,
#io_decoded_fetch_packet_bits_decoded_instruction_0_MOB_index,
#io_decoded_fetch_packet_bits_decoded_instruction_0_instructionType,
#io_decoded_fetch_packet_bits_decoded_instruction_0_portID,
#io_decoded_fetch_packet_bits_decoded_instruction_0_RS_type,
#io_decoded_fetch_packet_bits_decoded_instruction_0_needs_ALU,
#io_decoded_fetch_packet_bits_decoded_instruction_0_needs_branch_unit,
#io_decoded_fetch_packet_bits_decoded_instruction_0_needs_CSRs,
#io_decoded_fetch_packet_bits_decoded_instruction_0_SUBTRACT,
#io_decoded_fetch_packet_bits_decoded_instruction_0_MULTIPLY,
#io_decoded_fetch_packet_bits_decoded_instruction_0_IS_IMM,
#io_decoded_fetch_packet_bits_decoded_instruction_0_memory_type,
#io_decoded_fetch_packet_bits_decoded_instruction_0_access_width,
#io_decoded_fetch_packet_bits_decoded_instruction_1_ready_bits_RS1_ready,
#io_decoded_fetch_packet_bits_decoded_instruction_1_ready_bits_RS2_ready,
#io_decoded_fetch_packet_bits_decoded_instruction_1_RD,
#io_decoded_fetch_packet_bits_decoded_instruction_1_PRD,
#io_decoded_fetch_packet_bits_decoded_instruction_1_PRDold,
#io_decoded_fetch_packet_bits_decoded_instruction_1_RD_valid,
#io_decoded_fetch_packet_bits_decoded_instruction_1_RS1,
#io_decoded_fetch_packet_bits_decoded_instruction_1_RS1_valid,
#io_decoded_fetch_packet_bits_decoded_instruction_1_RS2,
#io_decoded_fetch_packet_bits_decoded_instruction_1_RS2_valid,
#input  [20:0] io_decoded_fetch_packet_bits_decoded_instruction_1_IMM,
#io_decoded_fetch_packet_bits_decoded_instruction_1_FUNCT3,
#io_decoded_fetch_packet_bits_decoded_instruction_1_packet_index,
#io_decoded_fetch_packet_bits_decoded_instruction_1_ROB_index,
#io_decoded_fetch_packet_bits_decoded_instruction_1_MOB_index,
#io_decoded_fetch_packet_bits_decoded_instruction_1_instructionType,
#io_decoded_fetch_packet_bits_decoded_instruction_1_portID,
#io_decoded_fetch_packet_bits_decoded_instruction_1_RS_type,
#io_decoded_fetch_packet_bits_decoded_instruction_1_needs_ALU,
#io_decoded_fetch_packet_bits_decoded_instruction_1_needs_branch_unit,
#io_decoded_fetch_packet_bits_decoded_instruction_1_needs_CSRs,
#io_decoded_fetch_packet_bits_decoded_instruction_1_SUBTRACT,
#io_decoded_fetch_packet_bits_decoded_instruction_1_MULTIPLY,
#io_decoded_fetch_packet_bits_decoded_instruction_1_IS_IMM,
#io_decoded_fetch_packet_bits_decoded_instruction_1_memory_type,
#io_decoded_fetch_packet_bits_decoded_instruction_1_access_width,
#io_decoded_fetch_packet_bits_decoded_instruction_2_ready_bits_RS1_ready,
#io_decoded_fetch_packet_bits_decoded_instruction_2_ready_bits_RS2_ready,
#io_decoded_fetch_packet_bits_decoded_instruction_2_RD,
#io_decoded_fetch_packet_bits_decoded_instruction_2_PRD,
#io_decoded_fetch_packet_bits_decoded_instruction_2_PRDold,
#io_decoded_fetch_packet_bits_decoded_instruction_2_RD_valid,
#io_decoded_fetch_packet_bits_decoded_instruction_2_RS1,
#io_decoded_fetch_packet_bits_decoded_instruction_2_RS1_valid,
#io_decoded_fetch_packet_bits_decoded_instruction_2_RS2,
#io_decoded_fetch_packet_bits_decoded_instruction_2_RS2_valid,
#input  [20:0] io_decoded_fetch_packet_bits_decoded_instruction_2_IMM,
#io_decoded_fetch_packet_bits_decoded_instruction_2_FUNCT3,
#io_decoded_fetch_packet_bits_decoded_instruction_2_packet_index,
#io_decoded_fetch_packet_bits_decoded_instruction_2_ROB_index,
#io_decoded_fetch_packet_bits_decoded_instruction_2_MOB_index,
#io_decoded_fetch_packet_bits_decoded_instruction_2_instructionType,
#io_decoded_fetch_packet_bits_decoded_instruction_2_portID,
#io_decoded_fetch_packet_bits_decoded_instruction_2_RS_type,
#io_decoded_fetch_packet_bits_decoded_instruction_2_needs_ALU,
#io_decoded_fetch_packet_bits_decoded_instruction_2_needs_branch_unit,
#io_decoded_fetch_packet_bits_decoded_instruction_2_needs_CSRs,
#io_decoded_fetch_packet_bits_decoded_instruction_2_SUBTRACT,
#io_decoded_fetch_packet_bits_decoded_instruction_2_MULTIPLY,
#io_decoded_fetch_packet_bits_decoded_instruction_2_IS_IMM,
#io_decoded_fetch_packet_bits_decoded_instruction_2_memory_type,
#io_decoded_fetch_packet_bits_decoded_instruction_2_access_width,
#io_decoded_fetch_packet_bits_decoded_instruction_3_ready_bits_RS1_ready,
#io_decoded_fetch_packet_bits_decoded_instruction_3_ready_bits_RS2_ready,
#io_decoded_fetch_packet_bits_decoded_instruction_3_RD,
#io_decoded_fetch_packet_bits_decoded_instruction_3_PRD,
#io_decoded_fetch_packet_bits_decoded_instruction_3_PRDold,
#io_decoded_fetch_packet_bits_decoded_instruction_3_RD_valid,
#io_decoded_fetch_packet_bits_decoded_instruction_3_RS1,
#io_decoded_fetch_packet_bits_decoded_instruction_3_RS1_valid,
#io_decoded_fetch_packet_bits_decoded_instruction_3_RS2,
#io_decoded_fetch_packet_bits_decoded_instruction_3_RS2_valid,
#input  [20:0] io_decoded_fetch_packet_bits_decoded_instruction_3_IMM,
#io_decoded_fetch_packet_bits_decoded_instruction_3_FUNCT3,
#io_decoded_fetch_packet_bits_decoded_instruction_3_packet_index,
#io_decoded_fetch_packet_bits_decoded_instruction_3_ROB_index,
#io_decoded_fetch_packet_bits_decoded_instruction_3_MOB_index,
#io_decoded_fetch_packet_bits_decoded_instruction_3_instructionType,
#io_decoded_fetch_packet_bits_decoded_instruction_3_portID,
#io_decoded_fetch_packet_bits_decoded_instruction_3_RS_type,
#io_decoded_fetch_packet_bits_decoded_instruction_3_needs_ALU,
#io_decoded_fetch_packet_bits_decoded_instruction_3_needs_branch_unit,
#io_decoded_fetch_packet_bits_decoded_instruction_3_needs_CSRs,
#io_decoded_fetch_packet_bits_decoded_instruction_3_SUBTRACT,
#io_decoded_fetch_packet_bits_decoded_instruction_3_MULTIPLY,
#io_decoded_fetch_packet_bits_decoded_instruction_3_IS_IMM,
#io_decoded_fetch_packet_bits_decoded_instruction_3_memory_type,
#io_decoded_fetch_packet_bits_decoded_instruction_3_access_width,
#io_decoded_fetch_packet_bits_valid_bits_0,
#io_decoded_fetch_packet_bits_valid_bits_1,
#io_decoded_fetch_packet_bits_valid_bits_2,
#io_decoded_fetch_packet_bits_valid_bits_3,
#input  [15:0] io_decoded_fetch_packet_bits_GHR,
#io_decoded_fetch_packet_bits_TOS,
#io_decoded_fetch_packet_bits_NEXT,
#io_decoded_fetch_packet_bits_prediction_hit,
#io_decoded_fetch_packet_bits_prediction_target,
#io_decoded_fetch_packet_bits_prediction_br_type,
#io_decoded_fetch_packet_bits_prediction_T_NT,
#io_decoded_fetch_packet_bits_free_list_front_pointer,
#io_FU_outputs_0_valid,
#io_FU_outputs_0_bits_PRD,
#io_FU_outputs_0_bits_RD_data,
#io_FU_outputs_0_bits_RD_valid,
#io_FU_outputs_0_bits_fetch_PC,
#io_FU_outputs_0_bits_branch_taken,
#io_FU_outputs_0_bits_target_address,
#io_FU_outputs_0_bits_branch_valid,
#io_FU_outputs_0_bits_address,
#io_FU_outputs_0_bits_memory_type,
#io_FU_outputs_0_bits_access_width,
#io_FU_outputs_0_bits_is_unsigned,
#io_FU_outputs_0_bits_wr_data,
#io_FU_outputs_0_bits_MOB_index,
#io_FU_outputs_0_bits_ROB_index,
#io_FU_outputs_0_bits_fetch_packet_index,
#io_FU_outputs_1_valid,
#io_FU_outputs_1_bits_PRD,
#io_FU_outputs_1_bits_RD_data,
#io_FU_outputs_1_bits_RD_valid,
#io_FU_outputs_1_bits_fetch_PC,
#io_FU_outputs_1_bits_branch_taken,
#io_FU_outputs_1_bits_target_address,
#io_FU_outputs_1_bits_branch_valid,
#io_FU_outputs_1_bits_address,
#io_FU_outputs_1_bits_memory_type,
#io_FU_outputs_1_bits_access_width,
#io_FU_outputs_1_bits_is_unsigned,
#io_FU_outputs_1_bits_wr_data,
#io_FU_outputs_1_bits_MOB_index,
#io_FU_outputs_1_bits_ROB_index,
#io_FU_outputs_1_bits_fetch_packet_index,
#io_FU_outputs_2_valid,
#io_FU_outputs_2_bits_PRD,
#io_FU_outputs_2_bits_RD_data,
#io_FU_outputs_2_bits_RD_valid,
#io_FU_outputs_2_bits_fetch_PC,
#io_FU_outputs_2_bits_branch_taken,
#io_FU_outputs_2_bits_target_address,
#io_FU_outputs_2_bits_branch_valid,
#io_FU_outputs_2_bits_address,
#io_FU_outputs_2_bits_memory_type,
#io_FU_outputs_2_bits_access_width,
#io_FU_outputs_2_bits_is_unsigned,
#io_FU_outputs_2_bits_wr_data,
#io_FU_outputs_2_bits_MOB_index,
#io_FU_outputs_2_bits_ROB_index,
#io_FU_outputs_2_bits_fetch_packet_index,
#io_FU_outputs_3_valid,
#io_FU_outputs_3_bits_PRD,
#io_FU_outputs_3_bits_RD_data,
#io_FU_outputs_3_bits_RD_valid,
#io_FU_outputs_3_bits_fetch_PC,
#io_FU_outputs_3_bits_branch_taken,
#io_FU_outputs_3_bits_target_address,
#io_FU_outputs_3_bits_branch_valid,
#io_FU_outputs_3_bits_address,
#io_FU_outputs_3_bits_memory_type,
#io_FU_outputs_3_bits_access_width,
#io_FU_outputs_3_bits_is_unsigned,
#io_FU_outputs_3_bits_wr_data,
#io_FU_outputs_3_bits_MOB_index,
#io_FU_outputs_3_bits_ROB_index,
#io_FU_outputs_3_bits_fetch_packet_index,
#io_renamed_decoded_fetch_packet_ready,
#io_renamed_decoded_fetch_packet_valid,
#output [31:0] io_renamed_decoded_fetch_packet_bits_fetch_PC,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_ready_bits_RS1_ready,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_ready_bits_RS2_ready,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_RD,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_PRD,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_PRDold,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_RD_valid,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_RS1,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_RS1_valid,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_RS2,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_RS2_valid,
#output [20:0] io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_IMM,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_FUNCT3,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_packet_index,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_ROB_index,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_MOB_index,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_instructionType,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_portID,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_RS_type,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_needs_ALU,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_needs_branch_unit,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_needs_CSRs,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_SUBTRACT,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_MULTIPLY,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_IS_IMM,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_memory_type,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_access_width,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_ready_bits_RS1_ready,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_ready_bits_RS2_ready,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_RD,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_PRD,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_PRDold,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_RD_valid,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_RS1,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_RS1_valid,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_RS2,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_RS2_valid,
#output [20:0] io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_IMM,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_FUNCT3,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_packet_index,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_ROB_index,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_MOB_index,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_instructionType,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_portID,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_RS_type,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_needs_ALU,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_needs_branch_unit,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_needs_CSRs,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_SUBTRACT,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_MULTIPLY,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_IS_IMM,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_memory_type,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_access_width,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_ready_bits_RS1_ready,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_ready_bits_RS2_ready,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_RD,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_PRD,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_PRDold,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_RD_valid,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_RS1,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_RS1_valid,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_RS2,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_RS2_valid,
#output [20:0] io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_IMM,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_FUNCT3,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_packet_index,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_ROB_index,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_MOB_index,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_instructionType,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_portID,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_RS_type,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_needs_ALU,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_needs_branch_unit,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_needs_CSRs,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_SUBTRACT,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_MULTIPLY,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_IS_IMM,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_memory_type,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_access_width,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_ready_bits_RS1_ready,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_ready_bits_RS2_ready,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_RD,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_PRD,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_PRDold,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_RD_valid,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_RS1,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_RS1_valid,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_RS2,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_RS2_valid,
#output [20:0] io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_IMM,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_FUNCT3,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_packet_index,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_ROB_index,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_MOB_index,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_instructionType,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_portID,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_RS_type,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_needs_ALU,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_needs_branch_unit,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_needs_CSRs,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_SUBTRACT,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_MULTIPLY,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_IS_IMM,
## io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_memory_type,
#io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_access_width,
#io_renamed_decoded_fetch_packet_bits_valid_bits_0,
#io_renamed_decoded_fetch_packet_bits_valid_bits_1,
#io_renamed_decoded_fetch_packet_bits_valid_bits_2,
#io_renamed_decoded_fetch_packet_bits_valid_bits_3,
#output [15:0] io_renamed_decoded_fetch_packet_bits_GHR,
## io_renamed_decoded_fetch_packet_bits_TOS,
#io_renamed_decoded_fetch_packet_bits_NEXT,
#io_renamed_decoded_fetch_packet_bits_prediction_hit,
#output [31:0] io_renamed_decoded_fetch_packet_bits_prediction_target,
## io_renamed_decoded_fetch_packet_bits_prediction_br_type,
#io_renamed_decoded_fetch_packet_bits_prediction_T_NT,
## io_renamed_decoded_fetch_packet_bits_free_list_front_pointer