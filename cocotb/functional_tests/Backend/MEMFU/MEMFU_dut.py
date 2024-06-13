import sys
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, Timer, ReadOnly

# Add helper functions as needed

def generate_null_FU_inputs():

    FU_inputs = {}

    FU_inputs["valid"] = 0
    FU_inputs["RS1_ready"] = 0
    FU_inputs["RS2_ready"] = 0
    FU_inputs["RD"] = 0
    FU_inputs["RD_valid"] = 0
    FU_inputs["RS1"] = 0
    FU_inputs["RS1_valid"] = 0
    FU_inputs["RS2"] = 0
    FU_inputs["RS2_valid"] = 0
    FU_inputs["IMM"] = 0
    FU_inputs["FUNCT3"] = 0
    FU_inputs["packet_index"] = 0
    FU_inputs["ROB_index"] = 0
    FU_inputs["instructionType"] = 0
    FU_inputs["portID"] = 0
    FU_inputs["RS_type"] = 0
    FU_inputs["needs_ALU"] = 0
    FU_inputs["needs_branch_unit"] = 0
    FU_inputs["needs_CSRs"] = 0
    FU_inputs["SUBTRACT"] = 0
    FU_inputs["MULTIPLY"] = 0
    FU_inputs["IMMEDIATE"] = 0
    FU_inputs["IS_LOAD"] = 0
    FU_inputs["IS_STORE"] = 0
    FU_inputs["RS1_data"] = 0
    FU_inputs["RS2_data"] = 0
    FU_inputs["PC"] = 0

    return FU_inputs


class MEMFU_dut:
    def __init__(self, dut, DRAM, DRAM_line_size=32):    # modify as needed (parameters, etc...)
        self.dut = dut
        self.DRAM = DRAM

        # Control signals
        self.DRAM_request       = False
        self.DRAM_request_addr  = 0x0
        self.DRAM_request_size  = DRAM_line_size

    def clock(self):            # Do not touch
        return self.dut.clock

    async def reset(self):      # Do not touch
        self.dut.reset.value = 0
        await RisingEdge(self.dut.clock)
        self.dut.reset.value = 1
        await RisingEdge(self.dut.clock)
        self.dut.reset.value = 0


    def write_FU(self, FU_inputs = generate_null_FU_inputs()):

        getattr(self.dut, f"io_FU_input_valid").value = FU_inputs["valid"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_ready_bits_RS1_ready").value = FU_inputs["RS1_ready"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_ready_bits_RS2_ready").value = FU_inputs["RS2_ready"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RD").value = FU_inputs["RD"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RD_valid").value = FU_inputs["RD_valid"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RS1").value = FU_inputs["RS1"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RS1_valid").value = FU_inputs["RS2_valid"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RS2").value = FU_inputs["RS2"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RS2_valid").value = FU_inputs["RS2_valid"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_IMM").value = FU_inputs["IMM"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_FUNCT3").value = FU_inputs["FUNCT3"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_packet_index").value = FU_inputs["packet_index"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_ROB_index").value = FU_inputs["ROB_index"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_instructionType").value = FU_inputs["instructionType"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_portID").value = FU_inputs["portID"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_RS_type").value = FU_inputs["RS_type"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_needs_ALU").value = FU_inputs["needs_ALU"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_needs_branch_unit").value = FU_inputs["needs_branch_unit"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_needs_CSRs").value = FU_inputs["needs_CSRs"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_SUBTRACT").value = FU_inputs["SUBTRACT"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_MULTIPLY").value = FU_inputs["MULTIPLY"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_IMMEDIATE").value = FU_inputs["IMMEDIATE"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_IS_LOAD").value = FU_inputs["IS_LOAD"]
        getattr(self.dut, f"io_FU_input_bits_decoded_instruction_IS_STORE").value = FU_inputs["IS_STORE"]
        getattr(self.dut, f"io_FU_input_bits_RS1_data").value = FU_inputs["RS1_data"]
        getattr(self.dut, f"io_FU_input_bits_RS2_data").value = FU_inputs["RS2_data"]
        getattr(self.dut, f"io_FU_input_bits_PC").value = FU_inputs["PC"]

    def get_DRAM_outputs(self):
        outputs = {}
        outputs["resp_ready"]       = int(getattr(self.dut, f"io_memory_response_ready").value)
        outputs["request_valid"]    = int(getattr(self.dut, f"io_memory_request_valid").value)
        outputs["request_addr"]     = int(getattr(self.dut, f"io_memory_request_bits_addr").value)
        outputs["request_wr_data"]  = int(getattr(self.dut, f"io_memory_request_bits_wr_data").value)
        outputs["request_wr_en"]    = int(getattr(self.dut, f"io_memory_request_bits_wr_en").value)

        return outputs





    def get_FU_outputs(self):
        outputs = {}

        outputs["ready"]                = int(getattr(self.dut, f"io_FU_input_ready").value)
        outputs["valid"]                = int(getattr(self.dut, f"io_FU_output_valid").value)
        outputs["RD"]                   = int(getattr(self.dut, f"io_FU_output_bits_RD").value)
        outputs["RD_data"]              = int(getattr(self.dut, f"io_FU_output_bits_RD_data").value)
        outputs["RD_valid"]             = int(getattr(self.dut, f"io_FU_output_bits_RD_valid").value)
        outputs["instruction_PC"]       = int(getattr(self.dut, f"io_FU_output_bits_instruction_PC").value)
        outputs["branch_taken"]         = int(getattr(self.dut, f"io_FU_output_bits_branch_taken").value)
        outputs["target_address"]       = int(getattr(self.dut, f"io_FU_output_bits_target_address").value)
        outputs["branch_valid"]         = int(getattr(self.dut, f"io_FU_output_bits_branch_valid").value)
        outputs["ROB_index"]            = int(getattr(self.dut, f"io_FU_output_bits_ROB_index").value)
        outputs["fetch_packet_index"]   = int(getattr(self.dut, f"io_FU_output_bits_fetch_packet_index").value)

        return outputs

    def write_dram_resp(self, data=0, valid = 0):
        self.dut.io_memory_response_valid.value = valid
        self.dut.io_memory_response_bits_data.value = data



    def get_FU_ready(self):
        return self.dut.io_FU_input_ready.value



    async def update(self):

        await RisingEdge(self.dut.clock)

        # Clear writes from prev cycle (so you dont write twice)
        self.write_dram_resp()

        if(self.DRAM_request):
            data = self.DRAM.read(address=self.DRAM_request_addr, size=self.DRAM_request_size)
            self.write_dram_resp(data, 1)

        await ReadOnly()
        self.DRAM_request       =   self.get_DRAM_outputs()["request_valid"]
        self.DRAM_request_addr  =   self.get_DRAM_outputs()["request_addr"]


    def set_DRAM_ready(self, ready):
        self.dut.io_memory_request_ready.value = ready