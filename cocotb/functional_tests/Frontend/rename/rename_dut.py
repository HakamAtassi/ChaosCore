import sys
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, Timer, ReadOnly

# Add helper functions as needed

def generate_null_rename_inputs():
    rename_inputs = {}

    rename_inputs["valid"] = 0
    rename_inputs["fetch_PC"] = 0

    rename_inputs["RS1_ready"] = [0, 0, 0, 0]
    rename_inputs["RS2_ready"] = [0, 0, 0, 0]
    rename_inputs["RD"] = [0, 0, 0, 0]
    rename_inputs["RD_valid"] = [0, 0, 0, 0]
    rename_inputs["RS1"] = [0, 0, 0, 0]
    rename_inputs["RS1_valid"] = [0, 0, 0, 0]
    rename_inputs["RS2"] = [0, 0, 0, 0]
    rename_inputs["RS2_valid"] = [0, 0, 0, 0]
    rename_inputs["IMM"] = [0, 0, 0, 0]
    rename_inputs["FUNCT3"] = [0, 0, 0, 0]
    rename_inputs["packet_index"] = [0, 0, 0, 0]
    rename_inputs["ROB_index"] = [0, 0, 0, 0]
    rename_inputs["instructionType"] = [0, 0, 0, 0]
    rename_inputs["portID"] = [0, 0, 0, 0]
    rename_inputs["RS_type"] = [0, 0, 0, 0]
    rename_inputs["needs_ALU"] = [0, 0, 0, 0]
    rename_inputs["needs_branch_unit"] = [0, 0, 0, 0]
    rename_inputs["needs_CSRs"] = [0, 0, 0, 0]
    rename_inputs["SUBTRACT"] = [0, 0, 0, 0]
    rename_inputs["MULTIPLY"] = [0, 0, 0, 0]
    rename_inputs["IMMEDIATE"] = [0, 0, 0, 0]
    rename_inputs["IS_LOAD"] = [0, 0, 0, 0]
    rename_inputs["IS_STORE"] = [0, 0, 0, 0]
    rename_inputs["valid_bit"] = [0,0,0,0]

    return rename_inputs

def generate_null_FU_inputs():

    FU_inputs = {}
    FU_inputs["valid"] = [0,0,0,0]
    FU_inputs["bits_RD"] = [0,0,0,0]
    FU_inputs["bits_RD_data"] = [0,0,0,0]
    FU_inputs["bits_RD_valid"] = [0,0,0,0]
    FU_inputs["bits_instruction_PC"] = [0,0,0,0]
    FU_inputs["bits_branch_taken"] = [0,0,0,0]
    FU_inputs["bits_target_address"] = [0,0,0,0]
    FU_inputs["bits_branch_valid"] = [0,0,0,0]
    FU_inputs["bits_ROB_index"] = [0,0,0,0]
    FU_inputs["bits_fetch_packet_index"] = [0,0,0,0]

    return FU_inputs

class rename_dut:
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

    def rename(self, rename_inputs=generate_null_rename_inputs()):
        # Set the main fetch packet valid and fetch PC
        getattr(self.dut, f"io_decoded_fetch_packet_valid").value = rename_inputs["valid"]
        getattr(self.dut, f"io_decoded_fetch_packet_bits_fetch_PC").value = rename_inputs["fetch_PC"]

        # Iterate over the instructions and set the values
        for i in range(4):
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_ready_bits_RS1_ready").value = rename_inputs["RS1_ready"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_ready_bits_RS2_ready").value = rename_inputs["RS2_ready"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RD").value = rename_inputs["RD"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RD_valid").value = rename_inputs["RD_valid"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS1").value = rename_inputs["RS1"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS1_valid").value = rename_inputs["RS1_valid"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS2").value = rename_inputs["RS2"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS2_valid").value = rename_inputs["RS2_valid"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_IMM").value = rename_inputs["IMM"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_FUNCT3").value = rename_inputs["FUNCT3"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_packet_index").value = rename_inputs["packet_index"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_ROB_index").value = rename_inputs["ROB_index"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_instructionType").value = rename_inputs["instructionType"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_portID").value = rename_inputs["portID"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_RS_type").value = rename_inputs["RS_type"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_ALU").value = rename_inputs["needs_ALU"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_branch_unit").value = rename_inputs["needs_branch_unit"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_CSRs").value = rename_inputs["needs_CSRs"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_SUBTRACT").value = rename_inputs["SUBTRACT"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_MULTIPLY").value = rename_inputs["MULTIPLY"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_IMMEDIATE").value = rename_inputs["IMMEDIATE"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_IS_LOAD").value = rename_inputs["IS_LOAD"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_decoded_instruction_{i}_IS_STORE").value = rename_inputs["IS_STORE"][i]
            getattr(self.dut, f"io_decoded_fetch_packet_bits_valid_bits_{i}").value = rename_inputs["valid_bit"][i]

    def write_FU(self, FU_inputs):

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

    def create_checkpoint(self, valid):
        self.dut.io_create_checkpoint.value = valid

    def set_input_ready(self):
        pass

    def get_outputs(self):

        outputs = {}

        outputs["valid"] = getattr(self.dut, f"io_renamed_decoded_fetch_packet_valid").value
        outputs["fetch_PC"] = getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_fetch_PC").value

        outputs["RS1_ready"] = [0, 0, 0, 0]
        outputs["RS2_ready"] = [0, 0, 0, 0]
        outputs["RD"] = [0, 0, 0, 0]
        outputs["RD_valid"] = [0, 0, 0, 0]
        outputs["RS1"] = [0, 0, 0, 0]
        outputs["RS1_valid"] = [0, 0, 0, 0]
        outputs["RS2"] = [0, 0, 0, 0]
        outputs["RS2_valid"] = [0, 0, 0, 0]
        outputs["IMM"] = [0, 0, 0, 0]
        outputs["FUNCT3"] = [0, 0, 0, 0]
        outputs["packet_index"] = [0, 0, 0, 0]
        outputs["ROB_index"] = [0, 0, 0, 0]
        outputs["instructionType"] = [0, 0, 0, 0]
        outputs["portID"] = [0, 0, 0, 0]
        outputs["RS_type"] = [0, 0, 0, 0]
        outputs["needs_ALU"] = [0, 0, 0, 0]
        outputs["needs_branch_unit"] = [0, 0, 0, 0]
        outputs["needs_CSRs"] = [0, 0, 0, 0]
        outputs["SUBTRACT"] = [0, 0, 0, 0]
        outputs["MULTIPLY"] = [0, 0, 0, 0]
        outputs["IMMEDIATE"] = [0, 0, 0, 0]
        outputs["IS_LOAD"] = [0, 0, 0, 0]
        outputs["IS_STORE"] = [0, 0, 0, 0]


        outputs["checkpoint_value"] = getattr(self.dut, f"io_active_checkpoint_value")
        outputs["checkpoint_full"] = getattr(self.dut, f"io_checkpoints_full")
        outputs["RAT_IDX"] = getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_RAT_IDX")
        outputs["fetch_packet_ready"] = getattr(self.dut, f"io_decoded_fetch_packet_ready")

        for i in range(4):
            outputs["RS1_ready"][i] = getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_ready_bits_RS1_ready").value
            outputs["RS2_ready"][i] = getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_ready_bits_RS2_ready").value
            outputs["RD"][i] = getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RD").value
            outputs["RD_valid"][i] = getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RD_valid").value
            outputs["RS1"][i] = getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RS1").value
            outputs["RS1_valid"][i] = getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RS1_valid").value
            outputs["RS2"][i] = getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RS2").value
            outputs["RS2_valid"][i] = getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RS2_valid").value
            outputs["IMM"][i] = getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_IMM").value
            outputs["FUNCT3"][i] = getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_FUNCT3").value
            outputs["packet_index"][i] = getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_packet_index").value
            outputs["ROB_index"][i] = getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_ROB_index").value
            outputs["instructionType"][i] = getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_instructionType").value
            outputs["portID"][i] = getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_portID").value
            outputs["RS_type"][i] = getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RS_type").value
            outputs["needs_ALU"][i] = getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_ALU").value
            outputs["needs_branch_unit"][i] = getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_branch_unit").value
            outputs["needs_CSRs"][i] = getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_CSRs").value
            outputs["SUBTRACT"][i] = getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_SUBTRACT").value
            outputs["MULTIPLY"][i] = getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_MULTIPLY").value
            outputs["IMMEDIATE"][i] = getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_IMMEDIATE").value
            outputs["IS_LOAD"][i] = getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_IS_LOAD").value
            outputs["IS_STORE"][i] = getattr(self.dut, f"io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_IS_STORE").value

        return outputs

    def get_RAT(self, RAT_idx):

        RAT = [0]*32

        for i in range(32):
            RAT[i] = int(getattr(self.dut, f"RAT.RAT_memories_{RAT_idx}_{i}").value)
        return RAT

    def print_RAT(self, RAT_idx):
        print(f"checkpoint {RAT_idx}")
        for i in range(32):
            print(f"{i}: {self.get_RAT(RAT_idx)[i]}")
        pass



"""

  output        io_decoded_fetch_packet_ready,
  input         io_decoded_fetch_packet_valid,
  input  [31:0] io_decoded_fetch_packet_bits_fetch_PC,
  input         io_decoded_fetch_packet_bits_decoded_instruction_0_ready_bits_RS1_ready,
                io_decoded_fetch_packet_bits_decoded_instruction_0_ready_bits_RS2_ready,
  input  [5:0]  io_decoded_fetch_packet_bits_decoded_instruction_0_RD,
  input         io_decoded_fetch_packet_bits_decoded_instruction_0_RD_valid,
  input  [5:0]  io_decoded_fetch_packet_bits_decoded_instruction_0_RS1,
  input         io_decoded_fetch_packet_bits_decoded_instruction_0_RS1_valid,
  input  [5:0]  io_decoded_fetch_packet_bits_decoded_instruction_0_RS2,
  input         io_decoded_fetch_packet_bits_decoded_instruction_0_RS2_valid,
  input  [31:0] io_decoded_fetch_packet_bits_decoded_instruction_0_IMM,
  input  [2:0]  io_decoded_fetch_packet_bits_decoded_instruction_0_FUNCT3,
  input  [3:0]  io_decoded_fetch_packet_bits_decoded_instruction_0_packet_index,
  input  [5:0]  io_decoded_fetch_packet_bits_decoded_instruction_0_ROB_index,
  input  [4:0]  io_decoded_fetch_packet_bits_decoded_instruction_0_instructionType,
  input  [1:0]  io_decoded_fetch_packet_bits_decoded_instruction_0_portID,
                io_decoded_fetch_packet_bits_decoded_instruction_0_RS_type,
  input         io_decoded_fetch_packet_bits_decoded_instruction_0_needs_ALU,
                io_decoded_fetch_packet_bits_decoded_instruction_0_needs_branch_unit,
                io_decoded_fetch_packet_bits_decoded_instruction_0_needs_CSRs,
                io_decoded_fetch_packet_bits_decoded_instruction_0_SUBTRACT,
                io_decoded_fetch_packet_bits_decoded_instruction_0_MULTIPLY,
                io_decoded_fetch_packet_bits_decoded_instruction_0_IMMEDIATE,
                io_decoded_fetch_packet_bits_decoded_instruction_0_IS_LOAD,
                io_decoded_fetch_packet_bits_decoded_instruction_0_IS_STORE,
                io_decoded_fetch_packet_bits_decoded_instruction_1_ready_bits_RS1_ready,
                io_decoded_fetch_packet_bits_decoded_instruction_1_ready_bits_RS2_ready,
  input  [5:0]  io_decoded_fetch_packet_bits_decoded_instruction_1_RD,
  input         io_decoded_fetch_packet_bits_decoded_instruction_1_RD_valid,
  input  [5:0]  io_decoded_fetch_packet_bits_decoded_instruction_1_RS1,
  input         io_decoded_fetch_packet_bits_decoded_instruction_1_RS1_valid,
  input  [5:0]  io_decoded_fetch_packet_bits_decoded_instruction_1_RS2,
  input         io_decoded_fetch_packet_bits_decoded_instruction_1_RS2_valid,
  input  [31:0] io_decoded_fetch_packet_bits_decoded_instruction_1_IMM,
  input  [2:0]  io_decoded_fetch_packet_bits_decoded_instruction_1_FUNCT3,
  input  [3:0]  io_decoded_fetch_packet_bits_decoded_instruction_1_packet_index,
  input  [5:0]  io_decoded_fetch_packet_bits_decoded_instruction_1_ROB_index,
  input  [4:0]  io_decoded_fetch_packet_bits_decoded_instruction_1_instructionType,
  input  [1:0]  io_decoded_fetch_packet_bits_decoded_instruction_1_portID,
                io_decoded_fetch_packet_bits_decoded_instruction_1_RS_type,
  input         io_decoded_fetch_packet_bits_decoded_instruction_1_needs_ALU,
                io_decoded_fetch_packet_bits_decoded_instruction_1_needs_branch_unit,
                io_decoded_fetch_packet_bits_decoded_instruction_1_needs_CSRs,
                io_decoded_fetch_packet_bits_decoded_instruction_1_SUBTRACT,
                io_decoded_fetch_packet_bits_decoded_instruction_1_MULTIPLY,
                io_decoded_fetch_packet_bits_decoded_instruction_1_IMMEDIATE,
                io_decoded_fetch_packet_bits_decoded_instruction_1_IS_LOAD,
                io_decoded_fetch_packet_bits_decoded_instruction_1_IS_STORE,
                io_decoded_fetch_packet_bits_decoded_instruction_2_ready_bits_RS1_ready,
                io_decoded_fetch_packet_bits_decoded_instruction_2_ready_bits_RS2_ready,
  input  [5:0]  io_decoded_fetch_packet_bits_decoded_instruction_2_RD,
  input         io_decoded_fetch_packet_bits_decoded_instruction_2_RD_valid,
  input  [5:0]  io_decoded_fetch_packet_bits_decoded_instruction_2_RS1,
  input         io_decoded_fetch_packet_bits_decoded_instruction_2_RS1_valid,
  input  [5:0]  io_decoded_fetch_packet_bits_decoded_instruction_2_RS2,
  input         io_decoded_fetch_packet_bits_decoded_instruction_2_RS2_valid,
  input  [31:0] io_decoded_fetch_packet_bits_decoded_instruction_2_IMM,
  input  [2:0]  io_decoded_fetch_packet_bits_decoded_instruction_2_FUNCT3,
  input  [3:0]  io_decoded_fetch_packet_bits_decoded_instruction_2_packet_index,
  input  [5:0]  io_decoded_fetch_packet_bits_decoded_instruction_2_ROB_index,
  input  [4:0]  io_decoded_fetch_packet_bits_decoded_instruction_2_instructionType,
  input  [1:0]  io_decoded_fetch_packet_bits_decoded_instruction_2_portID,
                io_decoded_fetch_packet_bits_decoded_instruction_2_RS_type,
  input         io_decoded_fetch_packet_bits_decoded_instruction_2_needs_ALU,
                io_decoded_fetch_packet_bits_decoded_instruction_2_needs_branch_unit,
                io_decoded_fetch_packet_bits_decoded_instruction_2_needs_CSRs,
                io_decoded_fetch_packet_bits_decoded_instruction_2_SUBTRACT,
                io_decoded_fetch_packet_bits_decoded_instruction_2_MULTIPLY,
                io_decoded_fetch_packet_bits_decoded_instruction_2_IMMEDIATE,
                io_decoded_fetch_packet_bits_decoded_instruction_2_IS_LOAD,
                io_decoded_fetch_packet_bits_decoded_instruction_2_IS_STORE,
                io_decoded_fetch_packet_bits_decoded_instruction_3_ready_bits_RS1_ready,
                io_decoded_fetch_packet_bits_decoded_instruction_3_ready_bits_RS2_ready,
  input  [5:0]  io_decoded_fetch_packet_bits_decoded_instruction_3_RD,
  input         io_decoded_fetch_packet_bits_decoded_instruction_3_RD_valid,
  input  [5:0]  io_decoded_fetch_packet_bits_decoded_instruction_3_RS1,
  input         io_decoded_fetch_packet_bits_decoded_instruction_3_RS1_valid,
  input  [5:0]  io_decoded_fetch_packet_bits_decoded_instruction_3_RS2,
  input         io_decoded_fetch_packet_bits_decoded_instruction_3_RS2_valid,
  input  [31:0] io_decoded_fetch_packet_bits_decoded_instruction_3_IMM,
  input  [2:0]  io_decoded_fetch_packet_bits_decoded_instruction_3_FUNCT3,
  input  [3:0]  io_decoded_fetch_packet_bits_decoded_instruction_3_packet_index,
  input  [5:0]  io_decoded_fetch_packet_bits_decoded_instruction_3_ROB_index,
  input  [4:0]  io_decoded_fetch_packet_bits_decoded_instruction_3_instructionType,
  input  [1:0]  io_decoded_fetch_packet_bits_decoded_instruction_3_portID,
                io_decoded_fetch_packet_bits_decoded_instruction_3_RS_type,
  input         io_decoded_fetch_packet_bits_decoded_instruction_3_needs_ALU,
                io_decoded_fetch_packet_bits_decoded_instruction_3_needs_branch_unit,
                io_decoded_fetch_packet_bits_decoded_instruction_3_needs_CSRs,
                io_decoded_fetch_packet_bits_decoded_instruction_3_SUBTRACT,
                io_decoded_fetch_packet_bits_decoded_instruction_3_MULTIPLY,
                io_decoded_fetch_packet_bits_decoded_instruction_3_IMMEDIATE,
                io_decoded_fetch_packet_bits_decoded_instruction_3_IS_LOAD,
                io_decoded_fetch_packet_bits_decoded_instruction_3_IS_STORE,
                io_decoded_fetch_packet_bits_valid_bits_0,
                io_decoded_fetch_packet_bits_valid_bits_1,
                io_decoded_fetch_packet_bits_valid_bits_2,
                io_decoded_fetch_packet_bits_valid_bits_3,
  input  [3:0]  io_decoded_fetch_packet_bits_RAT_IDX,
  input         io_renamed_decoded_fetch_packet_ready,
  output        io_renamed_decoded_fetch_packet_valid,
  output [31:0] io_renamed_decoded_fetch_packet_bits_fetch_PC,
  output        io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_ready_bits_RS1_ready,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_ready_bits_RS2_ready,
  output [5:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_RD,
  output        io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_RD_valid,
  output [5:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_RS1,
  output        io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_RS1_valid,
  output [5:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_RS2,
  output        io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_RS2_valid,
  output [31:0] io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_IMM,
  output [2:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_FUNCT3,
  output [3:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_packet_index,
  output [5:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_ROB_index,
  output [4:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_instructionType,
  output [1:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_portID,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_RS_type,
  output        io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_needs_ALU,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_needs_branch_unit,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_needs_CSRs,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_SUBTRACT,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_MULTIPLY,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_IMMEDIATE,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_IS_LOAD,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_0_IS_STORE,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_ready_bits_RS1_ready,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_ready_bits_RS2_ready,
  output [5:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_RD,
  output        io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_RD_valid,
  output [5:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_RS1,
  output        io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_RS1_valid,
  output [5:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_RS2,
  output        io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_RS2_valid,
  output [31:0] io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_IMM,
  output [2:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_FUNCT3,
  output [3:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_packet_index,
  output [5:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_ROB_index,
  output [4:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_instructionType,
  output [1:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_portID,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_RS_type,
  output        io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_needs_ALU,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_needs_branch_unit,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_needs_CSRs,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_SUBTRACT,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_MULTIPLY,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_IMMEDIATE,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_IS_LOAD,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_1_IS_STORE,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_ready_bits_RS1_ready,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_ready_bits_RS2_ready,
  output [5:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_RD,
  output        io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_RD_valid,
  output [5:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_RS1,
  output        io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_RS1_valid,
  output [5:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_RS2,
  output        io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_RS2_valid,
  output [31:0] io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_IMM,
  output [2:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_FUNCT3,
  output [3:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_packet_index,
  output [5:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_ROB_index,
  output [4:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_instructionType,
  output [1:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_portID,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_RS_type,
  output        io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_needs_ALU,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_needs_branch_unit,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_needs_CSRs,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_SUBTRACT,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_MULTIPLY,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_IMMEDIATE,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_IS_LOAD,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_2_IS_STORE,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_ready_bits_RS1_ready,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_ready_bits_RS2_ready,
  output [5:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_RD,
  output        io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_RD_valid,
  output [5:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_RS1,
  output        io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_RS1_valid,
  output [5:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_RS2,
  output        io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_RS2_valid,
  output [31:0] io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_IMM,
  output [2:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_FUNCT3,
  output [3:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_packet_index,
  output [5:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_ROB_index,
  output [4:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_instructionType,
  output [1:0]  io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_portID,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_RS_type,
  output        io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_needs_ALU,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_needs_branch_unit,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_needs_CSRs,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_SUBTRACT,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_MULTIPLY,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_IMMEDIATE,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_IS_LOAD,
                io_renamed_decoded_fetch_packet_bits_decoded_instruction_3_IS_STORE,
                io_renamed_decoded_fetch_packet_bits_valid_bits_0,
                io_renamed_decoded_fetch_packet_bits_valid_bits_1,
                io_renamed_decoded_fetch_packet_bits_valid_bits_2,
                io_renamed_decoded_fetch_packet_bits_valid_bits_3,
  output [3:0]  io_renamed_decoded_fetch_packet_bits_RAT_IDX,
  input         io_FU_outputs_0_valid,
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
  input         io_create_checkpoint,
  output [3:0]  io_active_checkpoint_value,
  input         io_restore_checkpoint,
  input  [3:0]  io_restore_checkpoint_value,
  input         io_free_checkpoint,
  output        io_checkpoints_full
"""