import sys
from cocotb.clock import Clock
from tabulate import tabulate
from cocotb.triggers import RisingEdge, FallingEdge, Timer, ReadOnly

# Add helper functions as needed

def generate_null_backend_packet():
    backend_packet = {}

    backend_packet["backend_packet_valid"] = 0
    backend_packet["fetch_PC"] = 0
    backend_packet["io_backend_packet_bits_RAT_IDX"] = 0

    backend_packet["RS1_ready"]             = [0, 0, 0, 0]
    backend_packet["RS2_ready"]             = [0, 0, 0, 0]
    backend_packet["RD"]                    = [0, 0, 0, 0]
    backend_packet["RD_valid"]              = [0, 0, 0, 0]
    backend_packet["RS1"]                   = [0, 0, 0, 0]
    backend_packet["RS1_valid"]             = [0, 0, 0, 0]
    backend_packet["RS2"]                   = [0, 0, 0, 0]
    backend_packet["RS2_valid"]             = [0, 0, 0, 0]
    backend_packet["IMM"]                   = [0, 0, 0, 0]
    backend_packet["FUNCT3"]                = [0, 0, 0, 0]
    backend_packet["packet_index"]          = [0, 0, 0, 0]
    backend_packet["ROB_index"]             = [0, 0, 0, 0]
    backend_packet["instructionType"]       = [0, 0, 0, 0]
    backend_packet["portID"]                = [0, 0, 0, 0]
    backend_packet["RS_type"]               = [0, 0, 0, 0]
    backend_packet["needs_ALU"]             = [0, 0, 0, 0]
    backend_packet["needs_branch_unit"]     = [0, 0, 0, 0]
    backend_packet["needs_CSRs"]            = [0, 0, 0, 0]
    backend_packet["SUBTRACT"]              = [0, 0, 0, 0]
    backend_packet["MULTIPLY"]              = [0, 0, 0, 0]
    backend_packet["IMMEDIATE"]             = [0, 0, 0, 0]
    backend_packet["IS_LOAD"]               = [0, 0, 0, 0]
    backend_packet["IS_STORE"]              = [0, 0, 0, 0]
    backend_packet["valid"]                 = [0, 0, 0, 0]

    return backend_packet

class backend_dut:
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

    def set_DRAM_ready(self, ready):
        self.dut.io_DRAM_request_ready.value = ready

    def write_decoded_instruction(self, decoded_instructions_inputs=generate_null_backend_packet()):


        getattr(self.dut, f"io_backend_packet_valid").value             =   decoded_instructions_inputs["backend_packet_valid"]
        getattr(self.dut, f"io_backend_packet_bits_fetch_PC").value     =   decoded_instructions_inputs["fetch_PC"]
        #getattr(self.dut, f"io_backend_packet_bits_RAT_IDX").value      =   decoded_instructions_inputs["RAT_IDX"]

        for i in range(4):
            getattr(self.dut, f"io_backend_packet_bits_decoded_instruction_{i}_ready_bits_RS1_ready").value =   decoded_instructions_inputs["RS1_ready"][i]
            getattr(self.dut, f"io_backend_packet_bits_decoded_instruction_{i}_ready_bits_RS2_ready").value =   decoded_instructions_inputs["RS2_ready"][i]
            getattr(self.dut, f"io_backend_packet_bits_decoded_instruction_{i}_RD").value   =   decoded_instructions_inputs["RD"][i]
            getattr(self.dut, f"io_backend_packet_bits_decoded_instruction_{i}_RD_valid").value =   decoded_instructions_inputs["RD_valid"][i]
            getattr(self.dut, f"io_backend_packet_bits_decoded_instruction_{i}_RS1").value  =   decoded_instructions_inputs["RS1"][i]
            getattr(self.dut, f"io_backend_packet_bits_decoded_instruction_{i}_RS1_valid").value    =   decoded_instructions_inputs["RS1_valid"][i]
            getattr(self.dut, f"io_backend_packet_bits_decoded_instruction_{i}_RS2").value  =   decoded_instructions_inputs["RS2"][i]
            getattr(self.dut, f"io_backend_packet_bits_decoded_instruction_{i}_RS2_valid").value    =   decoded_instructions_inputs["RS2_valid"][i]
            getattr(self.dut, f"io_backend_packet_bits_decoded_instruction_{i}_IMM").value  =   decoded_instructions_inputs["IMM"][i]
            getattr(self.dut, f"io_backend_packet_bits_decoded_instruction_{i}_FUNCT3").value   =   decoded_instructions_inputs["FUNCT3"][i]
            getattr(self.dut, f"io_backend_packet_bits_decoded_instruction_{i}_packet_index").value =   decoded_instructions_inputs["packet_index"][i]
            getattr(self.dut, f"io_backend_packet_bits_decoded_instruction_{i}_ROB_index").value    =   decoded_instructions_inputs["ROB_index"][i]
            getattr(self.dut, f"io_backend_packet_bits_decoded_instruction_{i}_instructionType").value  =   decoded_instructions_inputs["instructionType"][i]
            getattr(self.dut, f"io_backend_packet_bits_decoded_instruction_{i}_portID").value   =   decoded_instructions_inputs["portID"][i]
            getattr(self.dut, f"io_backend_packet_bits_decoded_instruction_{i}_RS_type").value  =   decoded_instructions_inputs["RS_type"][i]
            getattr(self.dut, f"io_backend_packet_bits_decoded_instruction_{i}_needs_ALU").value    =   decoded_instructions_inputs["needs_ALU"][i]
            getattr(self.dut, f"io_backend_packet_bits_decoded_instruction_{i}_needs_branch_unit").value    =   decoded_instructions_inputs["needs_branch_unit"][i]
            getattr(self.dut, f"io_backend_packet_bits_decoded_instruction_{i}_needs_CSRs").value   =   decoded_instructions_inputs["needs_CSRs"][i]
            getattr(self.dut, f"io_backend_packet_bits_decoded_instruction_{i}_SUBTRACT").value =   decoded_instructions_inputs["SUBTRACT"][i]
            getattr(self.dut, f"io_backend_packet_bits_decoded_instruction_{i}_MULTIPLY").value =   decoded_instructions_inputs["MULTIPLY"][i]
            getattr(self.dut, f"io_backend_packet_bits_decoded_instruction_{i}_IMMEDIATE").value    =   decoded_instructions_inputs["IMMEDIATE"][i]
            getattr(self.dut, f"io_backend_packet_bits_decoded_instruction_{i}_IS_LOAD").value  =   decoded_instructions_inputs["IS_LOAD"][i]
            getattr(self.dut, f"io_backend_packet_bits_decoded_instruction_{i}_IS_STORE").value =   decoded_instructions_inputs["IS_STORE"][i]
            getattr(self.dut, f"io_backend_packet_bits_valid_bits_{i}").value   =   decoded_instructions_inputs["valid"][i]

    def write_commit(self):
        pass

    def get_outputs(self):
        outputs = {}

        outputs["MEMRS_ready"] = [0]*4
        outputs["INTRS_ready"] = [0]*4

        outputs["valid"]                    = [0]*4
        outputs["RD"]                  = [0]*4
        outputs["RD_data"]             = [0]*4
        outputs["RD_valid"]            = [0]*4
        outputs["instruction_PC"]      = [0]*4
        outputs["branch_taken"]        = [0]*4
        outputs["target_address"]      = [0]*4
        outputs["branch_valid"]        = [0]*4
        outputs["ROB_index"]           = [0]*4
        outputs["fetch_packet_index"]  = [0]*4

        for i in range(4):
            outputs["MEMRS_ready"][i] = getattr(self.dut, f"io_MEMRS_ready_{i}")
            outputs["INTRS_ready"][i] = getattr(self.dut, f"io_INTRS_ready_{i}")

            outputs["valid"][i]                = getattr(self.dut, f"io_FU_outputs_{i}_valid")
            outputs["RD"][i]                   = getattr(self.dut, f"io_FU_outputs_{i}_bits_RD")
            outputs["RD_data"][i]              = getattr(self.dut, f"io_FU_outputs_{i}_bits_RD_data")
            outputs["RD_valid"][i]             = getattr(self.dut, f"io_FU_outputs_{i}_bits_RD_valid")
            outputs["instruction_PC"][i]       = getattr(self.dut, f"io_FU_outputs_{i}_bits_instruction_PC")
            outputs["branch_taken"][i]         = getattr(self.dut, f"io_FU_outputs_{i}_bits_branch_taken")
            outputs["target_address"][i]       = getattr(self.dut, f"io_FU_outputs_{i}_bits_target_address")
            outputs["branch_valid"][i]         = getattr(self.dut, f"io_FU_outputs_{i}_bits_branch_valid")
            outputs["ROB_index"][i]            = getattr(self.dut, f"io_FU_outputs_{i}_bits_ROB_index")
            outputs["fetch_packet_index"][i]   = getattr(self.dut, f"io_FU_outputs_{i}_bits_fetch_packet_index")

        return outputs


    def get_INTRS_contents(self):
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
            reservation_station["RS1_ready"][i]             = int(getattr(self.dut, f"INT_RS.reservation_station_{i}_decoded_instruction_ready_bits_RS1_ready").value)
            reservation_station["RS2_ready"][i]             = int(getattr(self.dut, f"INT_RS.reservation_station_{i}_decoded_instruction_ready_bits_RS2_ready").value)
            reservation_station["RD"][i]                    = int(getattr(self.dut, f"INT_RS.reservation_station_{i}_decoded_instruction_RD").value)
            reservation_station["RD_valid"][i]              = int(getattr(self.dut, f"INT_RS.reservation_station_{i}_decoded_instruction_RD_valid").value)
            reservation_station["RS1"][i]                   = int(getattr(self.dut, f"INT_RS.reservation_station_{i}_decoded_instruction_RS1").value)
            reservation_station["RS2"][i]                   = int(getattr(self.dut, f"INT_RS.reservation_station_{i}_decoded_instruction_RS2").value)
            reservation_station["IMM"][i]                   = int(getattr(self.dut, f"INT_RS.reservation_station_{i}_decoded_instruction_IMM").value)
            reservation_station["FUNCT3"][i]                = int(getattr(self.dut, f"INT_RS.reservation_station_{i}_decoded_instruction_FUNCT3").value)
            reservation_station["packet_index"][i]          = int(getattr(self.dut, f"INT_RS.reservation_station_{i}_decoded_instruction_packet_index").value)
            reservation_station["ROB_index"][i]             = int(getattr(self.dut, f"INT_RS.reservation_station_{i}_decoded_instruction_ROB_index").value)
            reservation_station["instructionType"][i]       = int(getattr(self.dut, f"INT_RS.reservation_station_{i}_decoded_instruction_instructionType").value)
            reservation_station["portID"][i]                = int(getattr(self.dut, f"INT_RS.reservation_station_{i}_decoded_instruction_portID").value)
            reservation_station["needs_branch_unit"][i]     = int(getattr(self.dut, f"INT_RS.reservation_station_{i}_decoded_instruction_needs_branch_unit").value)
            reservation_station["SUBTRACT"][i]              = int(getattr(self.dut, f"INT_RS.reservation_station_{i}_decoded_instruction_SUBTRACT").value)
            reservation_station["MULTIPLY"][i]              = int(getattr(self.dut, f"INT_RS.reservation_station_{i}_decoded_instruction_MULTIPLY").value)
            reservation_station["IMMEDIATE"][i]             = int(getattr(self.dut, f"INT_RS.reservation_station_{i}_decoded_instruction_IMMEDIATE").value)
            reservation_station["valid"][i]                 = int(getattr(self.dut, f"INT_RS.reservation_station_{i}_valid").value)
            reservation_station["needs_ALU"][i]             = getattr(self.dut, f"INT_RS.reservation_station_{i}_decoded_instruction_needs_ALU").value

            #reservation_station["needs_CSRs"][i]            = getattr(self.dut, f"INT_RS.reservation_station_{i}_decoded_instruction_needs_CSRs").value
            #reservation_station["RS1_valid"][i]             = getattr(self.dut, f"INT_RS.reservation_station_{i}_decoded_instruction_RS1_valid").value
            #reservation_station["RS2_valid"][i]             = getattr(self.dut, f"INT_RS.reservation_station_{i}_decoded_instruction_RS2_valid").value
            #reservation_station["RS_type"][i]               = getattr(self.dut, f"INT_RS.reservation_station_{i}_decoded_instruction_RS_type").value
            #reservation_station["IS_LOAD"][i]               = getattr(self.dut, f"INT_RS.reservation_station_{i}_decoded_instruction_IS_LOAD").value
            #reservation_station["IS_STORE"][i]              = getattr(self.dut, f"INT_RS.reservation_station_{i}_decoded_instruction_IS_STORE").value
            #reservation_station["commited"][i]              = getattr(self.dut, f"INT_RS.reservation_station_{i}_commited").value
        return reservation_station

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
            reservation_station["RS1_ready"][i]             = getattr(self.dut, f"MEM_RS.reservation_station_{i}_decoded_instruction_ready_bits_RS1_ready").value
            reservation_station["RS2_ready"][i]             = getattr(self.dut, f"MEM_RS.reservation_station_{i}_decoded_instruction_ready_bits_RS2_ready").value
            reservation_station["RD"][i]                    = getattr(self.dut, f"MEM_RS.reservation_station_{i}_decoded_instruction_RD").value
            #reservation_station["RD_valid"][i]              = getattr(self.dut, f"MEM_RS.reservation_station_{i}_decoded_instruction_RD_valid").value
            reservation_station["RS1"][i]                   = getattr(self.dut, f"MEM_RS.reservation_station_{i}_decoded_instruction_RS1").value
            #reservation_station["RS1_valid"][i]             = getattr(self.dut, f"MEM_RS.reservation_station_{i}_decoded_instruction_RS1_valid").value
            reservation_station["RS2"][i]                   = getattr(self.dut, f"MEM_RS.reservation_station_{i}_decoded_instruction_RS2").value
            #reservation_station["RS2_valid"][i]             = getattr(self.dut, f"MEM_RS.reservation_station_{i}_decoded_instruction_RS2_valid").value
            reservation_station["IMM"][i]                   = getattr(self.dut, f"MEM_RS.reservation_station_{i}_decoded_instruction_IMM").value
            reservation_station["FUNCT3"][i]                = getattr(self.dut, f"MEM_RS.reservation_station_{i}_decoded_instruction_FUNCT3").value
            reservation_station["packet_index"][i]          = getattr(self.dut, f"MEM_RS.reservation_station_{i}_decoded_instruction_packet_index").value
            reservation_station["ROB_index"][i]             = getattr(self.dut, f"MEM_RS.reservation_station_{i}_decoded_instruction_ROB_index").value
            #reservation_station["instructionType"][i]       = getattr(self.dut, f"MEM_RS.reservation_station_{i}_decoded_instruction_instructionType").value
            #reservation_station["portID"][i]                = getattr(self.dut, f"MEM_RS.reservation_station_{i}_decoded_instruction_portID").value
            #reservation_station["RS_type"][i]               = getattr(self.dut, f"MEM_RS.reservation_station_{i}_decoded_instruction_RS_type").value
            #reservation_station["needs_ALU"][i]             = getattr(self.dut, f"MEM_RS.reservation_station_{i}_decoded_instruction_needs_ALU").value
            #reservation_station["needs_branch_unit"][i]     = getattr(self.dut, f"MEM_RS.reservation_station_{i}_decoded_instruction_needs_branch_unit").value
            #reservation_station["needs_CSRs"][i]            = getattr(self.dut, f"MEM_RS.reservation_station_{i}_decoded_instruction_needs_CSRs").value
            #reservation_station["SUBTRACT"][i]              = getattr(self.dut, f"MEM_RS.reservation_station_{i}_decoded_instruction_SUBTRACT").value
            #reservation_station["MULTIPLY"][i]              = getattr(self.dut, f"MEM_RS.reservation_station_{i}_decoded_instruction_MULTIPLY").value
            #reservation_station["IMMEDIATE"][i]             = getattr(self.dut, f"MEM_RS.reservation_station_{i}_decoded_instruction_IMMEDIATE").value
            reservation_station["IS_LOAD"][i]               = getattr(self.dut, f"MEM_RS.reservation_station_{i}_decoded_instruction_IS_LOAD").value
            reservation_station["IS_STORE"][i]              = getattr(self.dut, f"MEM_RS.reservation_station_{i}_decoded_instruction_IS_STORE").value
            reservation_station["commited"][i]              = getattr(self.dut, f"MEM_RS.reservation_station_{i}_commited").value
            reservation_station["valid"][i]                 = getattr(self.dut, f"MEM_RS.reservation_station_{i}_valid").value

        return reservation_station


    def get_PRF(self):
        PRF = [0]*64
        for i in range(64):
            PRF[i] = int(getattr(self.dut, f"INT_PRF.mem_ext.Memory")[i].value)
        return PRF

    def get_FU_inputs(self):
        pass

    def get_FU_inputs(self, FU):
        FU_inputs = {}

        FU_inputs["input_valid"]        = int(getattr(self.dut, f"FU{FU}.io_FU_input_valid").value)
        FU_inputs["RD"]                 = int(getattr(self.dut, f"FU{FU}.io_FU_input_bits_decoded_instruction_RD").value)
        FU_inputs["RD_valid"]           = int(getattr(self.dut, f"FU{FU}.io_FU_input_bits_decoded_instruction_RD_valid").value)
        FU_inputs["IMM"]                = int(getattr(self.dut, f"FU{FU}.io_FU_input_bits_decoded_instruction_IMM").value)
        FU_inputs["FUNCT3"]             = int(getattr(self.dut, f"FU{FU}.io_FU_input_bits_decoded_instruction_FUNCT3").value)
        FU_inputs["packet_index"]       = int(getattr(self.dut, f"FU{FU}.io_FU_input_bits_decoded_instruction_packet_index").value)
        FU_inputs["ROB_index"]          = int(getattr(self.dut, f"FU{FU}.io_FU_input_bits_decoded_instruction_ROB_index").value)
        FU_inputs["instructionType"]    = int(getattr(self.dut, f"FU{FU}.io_FU_input_bits_decoded_instruction_instructionType").value)
        FU_inputs["SUBTRACT"]           = int(getattr(self.dut, f"FU{FU}.io_FU_input_bits_decoded_instruction_SUBTRACT").value)
        FU_inputs["MULTIPLY"]           = int(getattr(self.dut, f"FU{FU}.io_FU_input_bits_decoded_instruction_MULTIPLY").value)
        FU_inputs["IMMEDIATE"]          = int(getattr(self.dut, f"FU{FU}.io_FU_input_bits_decoded_instruction_IMMEDIATE").value)
        FU_inputs["RS1_data"]           = int(getattr(self.dut, f"FU{FU}.io_FU_input_bits_RS1_data").value)
        FU_inputs["RS2_data"]           = int(getattr(self.dut, f"FU{FU}.io_FU_input_bits_RS2_data").value)
        #FU_inputs["branch_unit"]        = getattr(self.dut, f"FU{FU}.io_FU_input_bits_decoded_instruction_needs_branch_unit").value
        #FU_inputs["bits_PC"]            = getattr(self.dut, f"FU{FU}.io_FU_input_bits_PC").value

        return FU_inputs

    def get_FU_outputs(self, FU):
        FU_outputs = {}

        FU_outputs["valid"]                 = int(getattr(self.dut, f"FU{FU}.io_FU_output_valid").value)
        FU_outputs["RD"]                    = int(getattr(self.dut, f"FU{FU}.io_FU_output_bits_RD").value)
        FU_outputs["RD_data"]               = int(getattr(self.dut, f"FU{FU}.io_FU_output_bits_RD_data").value)
        FU_outputs["RD_valid"]              = int(getattr(self.dut, f"FU{FU}.io_FU_output_bits_RD_valid").value)
        FU_outputs["instruction_PC"]        = int(getattr(self.dut, f"FU{FU}.io_FU_output_bits_instruction_PC").value)
        #FU_outputs["branch_taken"]          = int(getattr(self.dut, f"FU{FU}.io_FU_output_bits_branch_taken").value)
        #FU_outputs["target_address"]        = int(getattr(self.dut, f"FU{FU}.io_FU_output_bits_target_address").value)
        #FU_outputs["branch_valid"]          = int(getattr(self.dut, f"FU{FU}.io_FU_output_bits_branch_valid").value)
        FU_outputs["ROB_index"]             = int(getattr(self.dut, f"FU{FU}.io_FU_output_bits_ROB_index").value)
        FU_outputs["fetch_packet_index"]    = int(getattr(self.dut, f"FU{FU}.io_FU_output_bits_fetch_packet_index").value)

        return FU_outputs

    def print_ports():
        pass




    #########################
    ## INTERFACE TO MEMORY ##
    #########################
        
    def read_output(self):
        outputs = {}
        outputs["resp_ready"]           = int(self.dut.io_DRAM_resp_ready.value)
        outputs["request_valid"]        = int(self.dut.io_DRAM_request_valid.value)
        outputs["request_addr"]         = int(self.dut.io_DRAM_request_bits_addr.value)
        outputs["request_wr_en"]        = int(self.dut.io_DRAM_request_bits_wr_en.value)

        return outputs

    def write_dram_resp(self, data=0, valid = 0):
        self.dut.io_DRAM_resp_valid.value = valid
        self.dut.io_DRAM_resp_bits_data.value = data

    async def update(self):

        await RisingEdge(self.dut.clock)

        # Clear writes from prev cycle (so you dont write twice)
        self.write_dram_resp()

        if(self.DRAM_request):
            data = self.DRAM.read(address=self.DRAM_request_addr, size=self.DRAM_request_size)
            self.write_dram_resp(data, 1)

        await ReadOnly()
        self.DRAM_request       =   self.read_output()["request_valid"]
        self.DRAM_request_addr  =   self.read_output()["request_addr"]

