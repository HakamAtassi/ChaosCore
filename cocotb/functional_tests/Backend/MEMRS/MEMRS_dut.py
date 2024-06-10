import sys
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, Timer
from tabulate import tabulate

# Add helper functions as needed

def generate_null_allocate_inputs():
    allocate_inputs = {}
    allocate_inputs["valid"] = [0, 0, 0, 0]
    allocate_inputs["RS1_ready"] = [0, 0, 0, 0]
    allocate_inputs["RS2_ready"] = [0, 0, 0, 0]
    allocate_inputs["RD"] = [0, 0, 0, 0]
    allocate_inputs["RD_valid"] = [0, 0, 0, 0]
    allocate_inputs["RS1"] = [0, 0, 0, 0]
    allocate_inputs["RS1_valid"] = [0, 0, 0, 0]
    allocate_inputs["RS2"] = [0, 0, 0, 0]
    allocate_inputs["RS2_valid"] = [0, 0, 0, 0]
    allocate_inputs["IMM"] = [0, 0, 0, 0]
    allocate_inputs["FUNCT3"] = [0, 0, 0, 0]
    allocate_inputs["packet_index"] = [0, 0, 0, 0]
    allocate_inputs["ROB_index"] = [0, 0, 0, 0]
    allocate_inputs["instructionType"] = [0, 0, 0, 0]
    allocate_inputs["portID"] = [0, 0, 0, 0]
    allocate_inputs["RS_type"] = [0, 0, 0, 0]
    allocate_inputs["needs_ALU"] = [0, 0, 0, 0]
    allocate_inputs["needs_branch_unit"] = [0, 0, 0, 0]
    allocate_inputs["needs_CSRs"] = [0, 0, 0, 0]
    allocate_inputs["SUBTRACT"] = [0, 0, 0, 0]
    allocate_inputs["MULTIPLY"] = [0, 0, 0, 0]
    allocate_inputs["IMMEDIATE"] = [0, 0, 0, 0]
    allocate_inputs["IS_LOAD"] = [0, 0, 0, 0]
    allocate_inputs["IS_STORE"] = [0, 0, 0, 0]
    return allocate_inputs

def generate_null_FU_inputs():
    FU_inputs = {}

    FU_inputs["valid"] = [0,0,0,0]
    FU_inputs["RD"] = [0,0,0,0]
    FU_inputs["RD_data"] = [0,0,0,0]
    FU_inputs["RD_valid"] = [0,0,0,0]
    FU_inputs["instruction_PC"] = [0,0,0,0]
    FU_inputs["branch_taken"] = [0,0,0,0]
    FU_inputs["target_address"] = [0,0,0,0]
    FU_inputs["branch_valid"] = [0,0,0,0]
    FU_inputs["ROB_index"] = [0,0,0,0]
    FU_inputs["fetch_packet_index"] = [0,0,0,0]

    return FU_inputs

def generate_null_commit_input():

    commit_inputs = {}
    
    commit_inputs["valid"] = 0
    commit_inputs["fetch_PC"] = 0
    commit_inputs["T_NT"] = 0
    commit_inputs["ROB_index"] = 0
    commit_inputs["br_type"] = 0
    commit_inputs["fetch_packet_index"] = 0
    commit_inputs["is_misprediction"] = 0
    commit_inputs["expected_PC"] = 0
    commit_inputs["GHR"] = 0
    commit_inputs["TOS"] = 0
    commit_inputs["NEXT"] = 0
    commit_inputs["RAT_IDX"] = 0

    return commit_inputs

class MEMRS_dut:
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


    def write_commit(self, commit_input=generate_null_commit_input()):
        getattr(self.dut, f"io_commit_valid").value = commit_input["valid"]
        getattr(self.dut, f"io_commit_fetch_PC").value = commit_input["fetch_PC"]
        getattr(self.dut, f"io_commit_T_NT").value = commit_input["T_NT"]
        getattr(self.dut, f"io_commit_ROB_index").value = commit_input["ROB_index"]
        getattr(self.dut, f"io_commit_br_type").value = commit_input["br_type"]
        getattr(self.dut, f"io_commit_fetch_packet_index").value = commit_input["fetch_packet_index"]
        getattr(self.dut, f"io_commit_is_misprediction").value = commit_input["is_misprediction"]
        getattr(self.dut, f"io_commit_expected_PC").value = commit_input["expected_PC"]
        getattr(self.dut, f"io_commit_GHR").value = commit_input["GHR"]
        getattr(self.dut, f"io_commit_TOS").value = commit_input["TOS"]
        getattr(self.dut, f"io_commit_NEXT").value = commit_input["NEXT"]
        getattr(self.dut, f"io_commit_RAT_IDX").value = commit_input["RAT_IDX"]

    def write_allocate(self, allocate_inputs=generate_null_allocate_inputs()):
        for i in range(4):
            getattr(self.dut, f"io_backend_packet_{i}_valid").value = allocate_inputs["valid"][i]
            getattr(self.dut, f"io_backend_packet_{i}_bits_ready_bits_RS1_ready").value = allocate_inputs["RS1_ready"][i]
            getattr(self.dut, f"io_backend_packet_{i}_bits_ready_bits_RS2_ready").value = allocate_inputs["RS2_ready"][i]
            getattr(self.dut, f"io_backend_packet_{i}_bits_RD").value = allocate_inputs["RD"][i]
            getattr(self.dut, f"io_backend_packet_{i}_bits_RD_valid").value = allocate_inputs["RD_valid"][i]
            getattr(self.dut, f"io_backend_packet_{i}_bits_RS1").value = allocate_inputs["RS1"][i]
            getattr(self.dut, f"io_backend_packet_{i}_bits_RS1_valid").value = allocate_inputs["RS1_valid"][i]
            getattr(self.dut, f"io_backend_packet_{i}_bits_RS2").value = allocate_inputs["RS2"][i]
            getattr(self.dut, f"io_backend_packet_{i}_bits_RS2_valid").value = allocate_inputs["RS2_valid"][i]
            getattr(self.dut, f"io_backend_packet_{i}_bits_IMM").value = allocate_inputs["IMM"][i]
            getattr(self.dut, f"io_backend_packet_{i}_bits_FUNCT3").value = allocate_inputs["FUNCT3"][i]
            getattr(self.dut, f"io_backend_packet_{i}_bits_packet_index").value = allocate_inputs["packet_index"][i]
            getattr(self.dut, f"io_backend_packet_{i}_bits_ROB_index").value = allocate_inputs["ROB_index"][i]
            getattr(self.dut, f"io_backend_packet_{i}_bits_instructionType").value = allocate_inputs["instructionType"][i]
            getattr(self.dut, f"io_backend_packet_{i}_bits_portID").value = allocate_inputs["portID"][i]
            getattr(self.dut, f"io_backend_packet_{i}_bits_RS_type").value = allocate_inputs["RS_type"][i]
            getattr(self.dut, f"io_backend_packet_{i}_bits_needs_ALU").value = allocate_inputs["needs_ALU"][i]
            getattr(self.dut, f"io_backend_packet_{i}_bits_needs_branch_unit").value = allocate_inputs["needs_branch_unit"][i]
            getattr(self.dut, f"io_backend_packet_{i}_bits_needs_CSRs").value = allocate_inputs["needs_CSRs"][i]
            getattr(self.dut, f"io_backend_packet_{i}_bits_SUBTRACT").value = allocate_inputs["SUBTRACT"][i]
            getattr(self.dut, f"io_backend_packet_{i}_bits_MULTIPLY").value = allocate_inputs["MULTIPLY"][i]
            getattr(self.dut, f"io_backend_packet_{i}_bits_IMMEDIATE").value = allocate_inputs["IMMEDIATE"][i]
            getattr(self.dut, f"io_backend_packet_{i}_bits_IS_LOAD").value = allocate_inputs["IS_LOAD"][i]
            getattr(self.dut, f"io_backend_packet_{i}_bits_IS_STORE").value = allocate_inputs["IS_STORE"][i]

    def write_FU(self, FU_inputs=generate_null_FU_inputs()):
        for i in range(4):
            getattr(self.dut, f"io_FU_outputs_{i}_valid").value = FU_inputs["valid"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_RD").value = FU_inputs["RD"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_RD_data").value = FU_inputs["RD_data"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_RD_valid").value = FU_inputs["RD_valid"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_instruction_PC").value = FU_inputs["instruction_PC"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_branch_taken").value = FU_inputs["branch_taken"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_target_address").value = FU_inputs["target_address"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_branch_valid").value = FU_inputs["branch_valid"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_ROB_index").value = FU_inputs["ROB_index"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_fetch_packet_index").value = FU_inputs["fetch_packet_index"][i]

    def get_MEMRS_contents(self):
        reservation_station = {}
        reservation_station["RS1_ready"] = [0]*16
        reservation_station["RS2_ready"] = [0]*16
        reservation_station["RD"] = [0]*16
        reservation_station["RD_valid"] = [0]*16
        reservation_station["RS1"] = [0]*16
        reservation_station["RS1_valid"] = [0]*16
        reservation_station["RS2"] = [0]*16
        reservation_station["RS2_valid"] = [0]*16
        reservation_station["IMM"] = [0]*16
        reservation_station["FUNCT3"] = [0]*16
        reservation_station["packet_index"] = [0]*16
        reservation_station["ROB_index"] = [0]*16
        reservation_station["instructionType"] = [0]*16
        reservation_station["portID"] = [0]*16
        reservation_station["RS_type"] = [0]*16
        reservation_station["needs_ALU"] = [0]*16
        reservation_station["needs_branch_unit"] = [0]*16
        reservation_station["needs_CSRs"] = [0]*16
        reservation_station["SUBTRACT"] = [0]*16
        reservation_station["MULTIPLY"] = [0]*16
        reservation_station["IMMEDIATE"] = [0]*16
        reservation_station["IS_LOAD"] = [0]*16
        reservation_station["IS_STORE"] = [0]*16
        reservation_station["commited"] = [0]*16
        reservation_station["valid"] = [0]*16

        for i in range(16):
            reservation_station["RS1_ready"][i] = getattr(self.dut, f"reservation_station_{i}_decoded_instruction_ready_bits_RS1_ready").value
            reservation_station["RS2_ready"][i] = getattr(self.dut, f"reservation_station_{i}_decoded_instruction_ready_bits_RS2_ready").value
            reservation_station["RD"][i] = getattr(self.dut, f"reservation_station_{i}_decoded_instruction_RD").value
            reservation_station["RD_valid"][i] = getattr(self.dut, f"reservation_station_{i}_decoded_instruction_RD_valid").value
            reservation_station["RS1"][i] = getattr(self.dut, f"reservation_station_{i}_decoded_instruction_RS1").value
            reservation_station["RS1_valid"][i] = getattr(self.dut, f"reservation_station_{i}_decoded_instruction_RS1_valid").value
            reservation_station["RS2"][i] = getattr(self.dut, f"reservation_station_{i}_decoded_instruction_RS2").value
            reservation_station["RS2_valid"][i] = getattr(self.dut, f"reservation_station_{i}_decoded_instruction_RS2_valid").value
            reservation_station["IMM"][i] = getattr(self.dut, f"reservation_station_{i}_decoded_instruction_IMM").value
            reservation_station["FUNCT3"][i] = getattr(self.dut, f"reservation_station_{i}_decoded_instruction_FUNCT3").value
            reservation_station["packet_index"][i] = getattr(self.dut, f"reservation_station_{i}_decoded_instruction_packet_index").value
            reservation_station["ROB_index"][i] = getattr(self.dut, f"reservation_station_{i}_decoded_instruction_ROB_index").value
            reservation_station["instructionType"][i] = getattr(self.dut, f"reservation_station_{i}_decoded_instruction_instructionType").value
            reservation_station["portID"][i] = getattr(self.dut, f"reservation_station_{i}_decoded_instruction_portID").value
            reservation_station["RS_type"][i] = getattr(self.dut, f"reservation_station_{i}_decoded_instruction_RS_type").value
            reservation_station["needs_ALU"][i] = getattr(self.dut, f"reservation_station_{i}_decoded_instruction_needs_ALU").value
            reservation_station["needs_branch_unit"][i] = getattr(self.dut, f"reservation_station_{i}_decoded_instruction_needs_branch_unit").value
            reservation_station["needs_CSRs"][i] = getattr(self.dut, f"reservation_station_{i}_decoded_instruction_needs_CSRs").value
            reservation_station["SUBTRACT"][i] = getattr(self.dut, f"reservation_station_{i}_decoded_instruction_SUBTRACT").value
            reservation_station["MULTIPLY"][i] = getattr(self.dut, f"reservation_station_{i}_decoded_instruction_MULTIPLY").value
            reservation_station["IMMEDIATE"][i] = getattr(self.dut, f"reservation_station_{i}_decoded_instruction_IMMEDIATE").value
            reservation_station["IS_LOAD"][i] = getattr(self.dut, f"reservation_station_{i}_decoded_instruction_IS_LOAD").value
            reservation_station["IS_STORE"][i] = getattr(self.dut, f"reservation_station_{i}_decoded_instruction_IS_STORE").value
            reservation_station["commited"][i] = getattr(self.dut, f"reservation_station_{i}_commited").value
            reservation_station["valid"][i] = getattr(self.dut, f"reservation_station_{i}_valid").value

        return reservation_station

    def get_allocate_ready(self):
        ready = [0,0,0,0]
        for i in range(4):
            ready[i] = getattr(self.dut, f"io_backend_packet_{i}_ready").value
        return ready
    
    def get_output(self):
        outputs = {}
        outputs["valid"] = getattr(self.dut, f"io_RF_inputs_3_valid").value
        outputs["RS1_ready"] = getattr(self.dut, f"io_RF_inputs_3_bits_ready_bits_RS1_ready").value
        outputs["RS2_ready"] = getattr(self.dut, f"io_RF_inputs_3_bits_ready_bits_RS2_ready").value
        outputs["RD"] = getattr(self.dut, f"io_RF_inputs_3_bits_RD").value
        outputs["RD_valid"] = getattr(self.dut, f"io_RF_inputs_3_bits_RD_valid").value
        outputs["RS1"] = getattr(self.dut, f"io_RF_inputs_3_bits_RS1").value
        outputs["RS1_valid"] = getattr(self.dut, f"io_RF_inputs_3_bits_RS1_valid").value
        outputs["RS2"] = getattr(self.dut, f"io_RF_inputs_3_bits_RS2").value
        outputs["RS2_valid"] = getattr(self.dut, f"io_RF_inputs_3_bits_RS2_valid").value
        outputs["IMM"] = getattr(self.dut, f"io_RF_inputs_3_bits_IMM").value
        outputs["FUNCT3"] = getattr(self.dut, f"io_RF_inputs_3_bits_FUNCT3").value
        outputs["packet_index"] = getattr(self.dut, f"io_RF_inputs_3_bits_packet_index").value
        outputs["ROB_index"] = getattr(self.dut, f"io_RF_inputs_3_bits_ROB_index").value
        outputs["instructionType"] = getattr(self.dut, f"io_RF_inputs_3_bits_instructionType").value
        outputs["portID"] = getattr(self.dut, f"io_RF_inputs_3_bits_portID").value
        outputs["RS_type"] = getattr(self.dut, f"io_RF_inputs_3_bits_RS_type").value
        outputs["needs_ALU"] = getattr(self.dut, f"io_RF_inputs_3_bits_needs_ALU").value
        outputs["needs_branch_unit"] = getattr(self.dut, f"io_RF_inputs_3_bits_needs_branch_unit").value
        outputs["needs_CSRs"] = getattr(self.dut, f"io_RF_inputs_3_bits_needs_CSRs").value
        outputs["SUBTRACT"] = getattr(self.dut, f"io_RF_inputs_3_bits_SUBTRACT").value
        outputs["MULTIPLY"] = getattr(self.dut, f"io_RF_inputs_3_bits_MULTIPLY").value
        outputs["IMMEDIATE"] = getattr(self.dut, f"io_RF_inputs_3_bits_IMMEDIATE").value
        outputs["IS_LOAD"] = getattr(self.dut, f"io_RF_inputs_3_bits_IS_LOAD").value
        outputs["IS_STORE"] = getattr(self.dut, f"io_RF_inputs_3_bits_IS_STORE").value
        return outputs

    def print_MEMRS(self):
        MEMRS = self.get_MEMRS_contents()
        
        # Create a new dictionary with modified headers
        modified_MEMRS = {}
        for key, value in MEMRS.items():
            modified_key = key.replace('_', '\n')
            modified_MEMRS[modified_key] = value
        
        print(tabulate(modified_MEMRS, headers="keys"))


