import sys
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, Timer
from tabulate import tabulate


def generate_null_allocate():
    allocate_input = {}
    allocate_input["valid"] = 0
    allocate_input["fetch_PC"] = [0]*4
    allocate_input["RS1_ready"] = [0]*4
    allocate_input["RS2_ready"] = [0]*4
    allocate_input["RD"] = [0]*4
    allocate_input["RD_valid"] = [0]*4
    allocate_input["RS1"] = [0]*4
    allocate_input["RS1_valid"] = [0]*4
    allocate_input["RS2"] = [0]*4
    allocate_input["RS2_valid"] = [0]*4
    allocate_input["IMM"] = [0]*4
    allocate_input["FUNCT3"] = [0]*4
    allocate_input["packet_index"] = [0]*4
    allocate_input["ROB_index"] = [0]*4
    allocate_input["instructionType"] = [0]*4
    allocate_input["portID"] = [0]*4
    allocate_input["RS_type"] = [0]*4
    allocate_input["needs_ALU"] = [0]*4
    allocate_input["needs_branch_unit"] = [0]*4
    allocate_input["needs_CSRs"] = [0]*4
    allocate_input["SUBTRACT"] = [0]*4
    allocate_input["MULTIPLY"] = [0]*4
    allocate_input["IMMEDIATE"] = [0]*4
    allocate_input["IS_LOAD"] = [0]*4
    allocate_input["IS_STORE"] = [0]*4

    return allocate_input



# Add helper functions as needed

def deconstruct_ROB_entry(ROB_entry):
    ROB_entry = int(ROB_entry)
    entry_struct = {}

    entry_struct["valid"] = (ROB_entry >> 0) & 0b1
    entry_struct["is_branch"] = (ROB_entry >> 1) & 0b1

    return entry_struct


class ROB_dut:
    def __init__(self, dut):    # modify as needed (parameters, etc...)
        self.dut = dut

    def clock(self):            # Do not touch
        return self.dut.clock

    async def reset(self):      # Do not touch
        self.dut.reset.value = 0
        await RisingEdge(self.dut.clock)
        self.dut.reset.value = 1
        await RisingEdge(self.dut.clock)
        self.dut.reset.value = 0





    def write_allocate(self, allocate_input=generate_null_allocate()):

        getattr(self.dut, f"io_ROB_packet_valid").value = allocate_input["valid"]
        for i in range(4):
            getattr(self.dut, f"io_ROB_packet_bits_fetch_PC").value = allocate_input["fetch_PC"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_ready_bits_RS1_ready").value = allocate_input["RS1_ready"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_ready_bits_RS2_ready").value = allocate_input["RS2_ready"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RD").value = allocate_input["RD"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RD_valid").value = allocate_input["RD_valid"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RS1").value = allocate_input["RS1"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RS1_valid").value = allocate_input["RS1_valid"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RS2").value = allocate_input["RS2"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RS2_valid").value = allocate_input["RS2_valid"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_IMM").value = allocate_input["IMM"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_FUNCT3").value = allocate_input["FUNCT3"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_packet_index").value = allocate_input["packet_index"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_ROB_index").value = allocate_input["ROB_index"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_instructionType").value = allocate_input["instructionType"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_portID").value = allocate_input["portID"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_RS_type").value = allocate_input["RS_type"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_needs_ALU").value = allocate_input["needs_ALU"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_needs_branch_unit").value = allocate_input["needs_branch_unit"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_needs_CSRs").value = allocate_input["needs_CSRs"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_SUBTRACT").value = allocate_input["SUBTRACT"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_MULTIPLY").value = allocate_input["MULTIPLY"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_IMMEDIATE").value = allocate_input["IMMEDIATE"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_IS_LOAD").value = allocate_input["IS_LOAD"][i]
            getattr(self.dut, f"io_ROB_packet_bits_decoded_instruction_{i}_IS_STORE").value = allocate_input["IS_STORE"][i]












    def get_ROB_entry(self):
        entry_struct = [{} for _ in range(4)]

        row_valid = {}
        row_valid = [0]*64

        for i in range(64):
            row_valid[i]  = (int(getattr(self.dut, f"ROB_valid_bank.mem_ext.Memory"))>>i)&0b1 # row valid ?

        for bank in range(4):
            entry_struct[bank] = {
                "valid": [0] * 64,
                "is_branch": [0] * 64,
                "busy": [0] * 64
            }

            for i in range(64):
                rob_entry = deconstruct_ROB_entry(getattr(self.dut, f"ROB_entry_banks_{bank}.mem_ext.Memory")[i])
                entry_struct[bank]["valid"][i]      = rob_entry["valid"]        # entry/instruction valid 
                entry_struct[bank]["is_branch"][i]  = rob_entry["is_branch"]    # metadata
                # ...
                entry_struct[bank]["busy"][i]       = (int(getattr(self.dut, f"ROB_busy_banks_{bank}.mem_ext.Memory"))>>i) & 0b1    # entry busy?

        ROB = {}
        ROB["row_valid"] = row_valid
        ROB["entry"] = entry_struct

        return ROB

                

    def get_ROB_valid_bank(self):
        valid_struct = {}
        valid_struct["valid"]       =   [0]*64

        for i in range(64):
            valid_struct["valid"][i]       = getattr(self.dut, f"ROB_valid_bank.mem_ext").Memory[i]

    def print_ROB_entry(self):
        row_valid, ROB_entries = self.get_ROB_entry()

        headers = ["row", "V", "BR", "bsy"]

        tables = []
        for bank in range(4):
            rows = []
            for i in range(64):
                rows.append([i, ROB_entries[bank]["valid"][i], ROB_entries[bank]["is_branch"][i], ROB_entries[bank]["busy"][i]])
            tables.append(tabulate(rows, headers=headers, tablefmt="grid").split("\n"))

        combined_table = ""
        for row_parts in zip(*tables):
            combined_table += "   ".join(row_parts) + "\n"

        print(combined_table)

    def print_ROB_entry(self):
        row_valid = self.get_ROB_entry()["row_valid"]
        ROB_entries = self.get_ROB_entry()["entry"]

        # Create headers for the tabulate table
        headers = ["V", "BR", "BSY"]

        # Create the row_valid table
        row_valid_table = [["i", "V"]] + [[i, row_valid[i]] for i in range(64)]
        row_valid_lines = tabulate(row_valid_table, headers="firstrow", tablefmt="grid").split("\n")

        # Create tables for each bank
        tables = []
        for bank in range(4):
            rows = []
            for i in range(64):
                rows.append([ROB_entries[bank]["valid"][i], ROB_entries[bank]["is_branch"][i], ROB_entries[bank]["busy"][i]])
            tables.append(tabulate(rows, headers=headers, tablefmt="grid").split("\n"))

        # Combine the tables row-wise
        combined_table = ""
        for row_valid_line, *row_parts in zip(row_valid_lines, *tables):
            combined_table += row_valid_line + "   " + "   ".join(row_parts) + "\n"

        # Print the combined table
        print(combined_table)


"""
  input         clock,
                reset,
  output        io_ROB_packet_ready,
  input         io_ROB_packet_valid,
  input  [31:0] io_ROB_packet_bits_fetch_PC,
                io_ROB_packet_bits_decoded_instruction_0_fetch_PC,
  input         io_ROB_packet_bits_decoded_instruction_0_ready_bits_RS1_ready,
                io_ROB_packet_bits_decoded_instruction_0_ready_bits_RS2_ready,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_0_RD,
  input         io_ROB_packet_bits_decoded_instruction_0_RD_valid,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_0_RS1,
  input         io_ROB_packet_bits_decoded_instruction_0_RS1_valid,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_0_RS2,
  input         io_ROB_packet_bits_decoded_instruction_0_RS2_valid,
  input  [31:0] io_ROB_packet_bits_decoded_instruction_0_IMM,
  input  [2:0]  io_ROB_packet_bits_decoded_instruction_0_FUNCT3,
  input  [3:0]  io_ROB_packet_bits_decoded_instruction_0_packet_index,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_0_ROB_index,
  input  [4:0]  io_ROB_packet_bits_decoded_instruction_0_instructionType,
  input  [1:0]  io_ROB_packet_bits_decoded_instruction_0_portID,
                io_ROB_packet_bits_decoded_instruction_0_RS_type,
  input         io_ROB_packet_bits_decoded_instruction_0_needs_ALU,
                io_ROB_packet_bits_decoded_instruction_0_needs_branch_unit,
                io_ROB_packet_bits_decoded_instruction_0_needs_CSRs,
                io_ROB_packet_bits_decoded_instruction_0_SUBTRACT,
                io_ROB_packet_bits_decoded_instruction_0_MULTIPLY,
                io_ROB_packet_bits_decoded_instruction_0_IMMEDIATE,
                io_ROB_packet_bits_decoded_instruction_0_IS_LOAD,
                io_ROB_packet_bits_decoded_instruction_0_IS_STORE,
  input  [31:0] io_ROB_packet_bits_decoded_instruction_1_fetch_PC,
  input         io_ROB_packet_bits_decoded_instruction_1_ready_bits_RS1_ready,
                io_ROB_packet_bits_decoded_instruction_1_ready_bits_RS2_ready,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_1_RD,
  input         io_ROB_packet_bits_decoded_instruction_1_RD_valid,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_1_RS1,
  input         io_ROB_packet_bits_decoded_instruction_1_RS1_valid,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_1_RS2,
  input         io_ROB_packet_bits_decoded_instruction_1_RS2_valid,
  input  [31:0] io_ROB_packet_bits_decoded_instruction_1_IMM,
  input  [2:0]  io_ROB_packet_bits_decoded_instruction_1_FUNCT3,
  input  [3:0]  io_ROB_packet_bits_decoded_instruction_1_packet_index,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_1_ROB_index,
  input  [4:0]  io_ROB_packet_bits_decoded_instruction_1_instructionType,
  input  [1:0]  io_ROB_packet_bits_decoded_instruction_1_portID,
                io_ROB_packet_bits_decoded_instruction_1_RS_type,
  input         io_ROB_packet_bits_decoded_instruction_1_needs_ALU,
                io_ROB_packet_bits_decoded_instruction_1_needs_branch_unit,
                io_ROB_packet_bits_decoded_instruction_1_needs_CSRs,
                io_ROB_packet_bits_decoded_instruction_1_SUBTRACT,
                io_ROB_packet_bits_decoded_instruction_1_MULTIPLY,
                io_ROB_packet_bits_decoded_instruction_1_IMMEDIATE,
                io_ROB_packet_bits_decoded_instruction_1_IS_LOAD,
                io_ROB_packet_bits_decoded_instruction_1_IS_STORE,
  input  [31:0] io_ROB_packet_bits_decoded_instruction_2_fetch_PC,
  input         io_ROB_packet_bits_decoded_instruction_2_ready_bits_RS1_ready,
                io_ROB_packet_bits_decoded_instruction_2_ready_bits_RS2_ready,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_2_RD,
  input         io_ROB_packet_bits_decoded_instruction_2_RD_valid,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_2_RS1,
  input         io_ROB_packet_bits_decoded_instruction_2_RS1_valid,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_2_RS2,
  input         io_ROB_packet_bits_decoded_instruction_2_RS2_valid,
  input  [31:0] io_ROB_packet_bits_decoded_instruction_2_IMM,
  input  [2:0]  io_ROB_packet_bits_decoded_instruction_2_FUNCT3,
  input  [3:0]  io_ROB_packet_bits_decoded_instruction_2_packet_index,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_2_ROB_index,
  input  [4:0]  io_ROB_packet_bits_decoded_instruction_2_instructionType,
  input  [1:0]  io_ROB_packet_bits_decoded_instruction_2_portID,
                io_ROB_packet_bits_decoded_instruction_2_RS_type,
  input         io_ROB_packet_bits_decoded_instruction_2_needs_ALU,
                io_ROB_packet_bits_decoded_instruction_2_needs_branch_unit,
                io_ROB_packet_bits_decoded_instruction_2_needs_CSRs,
                io_ROB_packet_bits_decoded_instruction_2_SUBTRACT,
                io_ROB_packet_bits_decoded_instruction_2_MULTIPLY,
                io_ROB_packet_bits_decoded_instruction_2_IMMEDIATE,
                io_ROB_packet_bits_decoded_instruction_2_IS_LOAD,
                io_ROB_packet_bits_decoded_instruction_2_IS_STORE,
  input  [31:0] io_ROB_packet_bits_decoded_instruction_3_fetch_PC,
  input         io_ROB_packet_bits_decoded_instruction_3_ready_bits_RS1_ready,
                io_ROB_packet_bits_decoded_instruction_3_ready_bits_RS2_ready,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_3_RD,
  input         io_ROB_packet_bits_decoded_instruction_3_RD_valid,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_3_RS1,
  input         io_ROB_packet_bits_decoded_instruction_3_RS1_valid,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_3_RS2,
  input         io_ROB_packet_bits_decoded_instruction_3_RS2_valid,
  input  [31:0] io_ROB_packet_bits_decoded_instruction_3_IMM,
  input  [2:0]  io_ROB_packet_bits_decoded_instruction_3_FUNCT3,
  input  [3:0]  io_ROB_packet_bits_decoded_instruction_3_packet_index,
  input  [5:0]  io_ROB_packet_bits_decoded_instruction_3_ROB_index,
  input  [4:0]  io_ROB_packet_bits_decoded_instruction_3_instructionType,
  input  [1:0]  io_ROB_packet_bits_decoded_instruction_3_portID,
                io_ROB_packet_bits_decoded_instruction_3_RS_type,
  input         io_ROB_packet_bits_decoded_instruction_3_needs_ALU,
                io_ROB_packet_bits_decoded_instruction_3_needs_branch_unit,
                io_ROB_packet_bits_decoded_instruction_3_needs_CSRs,
                io_ROB_packet_bits_decoded_instruction_3_SUBTRACT,
                io_ROB_packet_bits_decoded_instruction_3_MULTIPLY,
                io_ROB_packet_bits_decoded_instruction_3_IMMEDIATE,
                io_ROB_packet_bits_decoded_instruction_3_IS_LOAD,
                io_ROB_packet_bits_decoded_instruction_3_IS_STORE,
                io_ROB_packet_bits_valid_bits_0,
                io_ROB_packet_bits_valid_bits_1,
                io_ROB_packet_bits_valid_bits_2,
                io_ROB_packet_bits_valid_bits_3,
                io_FU_outputs_0_valid,
  input  [63:0] io_FU_outputs_0_bits_RD,
  input  [31:0] io_FU_outputs_0_bits_RD_data,
  input         io_FU_outputs_0_bits_RD_valid,
  input  [31:0] io_FU_outputs_0_bits_instruction_PC,
  input         io_FU_outputs_0_bits_branch_taken,
  input  [31:0] io_FU_outputs_0_bits_target_address,
  input         io_FU_outputs_0_bits_branch_valid,
  input  [5:0]  io_FU_outputs_0_bits_ROB_index,
  input  [1:0]  io_FU_outputs_0_bits_fetch_packet_index,
  input         io_FU_outputs_1_valid,
  input  [63:0] io_FU_outputs_1_bits_RD,
  input  [31:0] io_FU_outputs_1_bits_RD_data,
  input         io_FU_outputs_1_bits_RD_valid,
  input  [31:0] io_FU_outputs_1_bits_instruction_PC,
  input         io_FU_outputs_1_bits_branch_taken,
  input  [31:0] io_FU_outputs_1_bits_target_address,
  input         io_FU_outputs_1_bits_branch_valid,
  input  [5:0]  io_FU_outputs_1_bits_ROB_index,
  input  [1:0]  io_FU_outputs_1_bits_fetch_packet_index,
  input         io_FU_outputs_2_valid,
  input  [63:0] io_FU_outputs_2_bits_RD,
  input  [31:0] io_FU_outputs_2_bits_RD_data,
  input         io_FU_outputs_2_bits_RD_valid,
  input  [31:0] io_FU_outputs_2_bits_instruction_PC,
  input         io_FU_outputs_2_bits_branch_taken,
  input  [31:0] io_FU_outputs_2_bits_target_address,
  input         io_FU_outputs_2_bits_branch_valid,
  input  [5:0]  io_FU_outputs_2_bits_ROB_index,
  input  [1:0]  io_FU_outputs_2_bits_fetch_packet_index,
  input         io_FU_outputs_3_valid,
  input  [63:0] io_FU_outputs_3_bits_RD,
  input  [31:0] io_FU_outputs_3_bits_RD_data,
  input         io_FU_outputs_3_bits_RD_valid,
  input  [31:0] io_FU_outputs_3_bits_instruction_PC,
  input         io_FU_outputs_3_bits_branch_taken,
  input  [31:0] io_FU_outputs_3_bits_target_address,
  input         io_FU_outputs_3_bits_branch_valid,
  input  [5:0]  io_FU_outputs_3_bits_ROB_index,
  input  [1:0]  io_FU_outputs_3_bits_fetch_packet_index,
  output        io_ROB_0_valid,
                io_ROB_0_is_branch,
                io_ROB_1_valid,
                io_ROB_1_is_branch,
                io_ROB_2_valid,
                io_ROB_2_is_branch,
                io_ROB_3_valid,
                io_ROB_3_is_branch,
  input         io_commit_valid,
  input  [31:0] io_commit_fetch_PC,
  input         io_commit_T_NT,
  input  [2:0]  io_commit_br_type,
  input  [1:0]  io_commit_fetch_packet_index,
  input         io_commit_is_misprediction,
  input  [31:0] io_commit_expected_PC,
  input  [15:0] io_commit_GHR,
  input  [6:0]  io_commit_TOS,
                io_commit_NEXT,
  input  [3:0]  io_commit_RAT_IDX,
  input  [5:0]  io_PC_file_exec_addr,
  output [5:0]  io_PC_file_exec_data,
                io_PC_file_commit_data
"""