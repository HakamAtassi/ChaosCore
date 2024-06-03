import sys
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, Timer

import random

def generate_null_input():
    stimulus = {}
    stimulus["valid"]               = [0,0,0,0]
    stimulus["RS1_ready"]           = [0,0,0,0]
    stimulus["RS2_ready"]           = [0,0,0,0]
    stimulus["RD"]                  = [0,0,0,0]
    stimulus["RD_valid"]            = [0,0,0,0]
    stimulus["RS1"]                 = [0,0,0,0]
    stimulus["RS1_valid"]           = [0,0,0,0]
    stimulus["RS2"]                 = [0,0,0,0]
    stimulus["RS2_valid"]           = [0,0,0,0]
    stimulus["IMM"]                 = [0,0,0,0]
    stimulus["FUNCT3"]              = [0,0,0,0]
    stimulus["packet_index"]        = [0,0,0,0]
    stimulus["ROB_index"]           = [0,0,0,0]
    stimulus["instructionType"]     = [0,0,0,0]
    stimulus["portID"]              = [0,0,0,0]
    stimulus["RS_type"]             = [0,0,0,0]
    stimulus["needs_ALU"]           = [0,0,0,0]
    stimulus["needs_branch_unit"]   = [0,0,0,0]
    stimulus["needs_CSRs"]          = [0,0,0,0]
    stimulus["SUBTRACT"]            = [0,0,0,0]
    stimulus["MULTIPLY"]            = [0,0,0,0]
    stimulus["IMMEDIATE"]           = [0,0,0,0]
    stimulus["IS_LOAD"]             = [0,0,0,0]
    stimulus["IS_STORE"]            = [0,0,0,0]

    return stimulus

def generate_null_read():
    null_read = {}
    null_read["ready"] = [0]*4
    return null_read


class instruction_queue_dut:
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
        await RisingEdge(self.dut.clock)

    # complete class body...

    # Suggestions: 

    def write_fifo(self, inputs):
        for i in range(4):
            getattr(self.dut, f"io_in_{i}_valid").value = inputs["valid"][i]
            getattr(self.dut, f"io_in_{i}_bits_ready_bits_RS1_ready").value = inputs["RS1_ready"][i]
            getattr(self.dut, f"io_in_{i}_bits_ready_bits_RS2_ready").value = inputs["RS2_ready"][i]
            getattr(self.dut, f"io_in_{i}_bits_RD").value = inputs["RD"][i]
            getattr(self.dut, f"io_in_{i}_bits_RD_valid").value = inputs["RD_valid"][i]
            getattr(self.dut, f"io_in_{i}_bits_RS1").value = inputs["RS1"][i]
            getattr(self.dut, f"io_in_{i}_bits_RS1_valid").value = inputs["RS1_valid"][i]
            getattr(self.dut, f"io_in_{i}_bits_RS2").value = inputs["RS2"][i]
            getattr(self.dut, f"io_in_{i}_bits_RS2_valid").value = inputs["RS2_valid"][i]
            getattr(self.dut, f"io_in_{i}_bits_IMM").value = inputs["IMM"][i]
            getattr(self.dut, f"io_in_{i}_bits_FUNCT3").value = inputs["FUNCT3"][i]
            getattr(self.dut, f"io_in_{i}_bits_packet_index").value = inputs["packet_index"][i]
            getattr(self.dut, f"io_in_{i}_bits_ROB_index").value = inputs["ROB_index"][i]
            getattr(self.dut, f"io_in_{i}_bits_instructionType").value = inputs["instructionType"][i]
            getattr(self.dut, f"io_in_{i}_bits_portID").value = inputs["portID"][i]
            getattr(self.dut, f"io_in_{i}_bits_RS_type").value = inputs["RS_type"][i]
            getattr(self.dut, f"io_in_{i}_bits_needs_ALU").value = inputs["needs_ALU"][i]
            getattr(self.dut, f"io_in_{i}_bits_needs_branch_unit").value = inputs["needs_branch_unit"][i]
            getattr(self.dut, f"io_in_{i}_bits_needs_CSRs").value = inputs["needs_CSRs"][i]
            getattr(self.dut, f"io_in_{i}_bits_SUBTRACT").value = inputs["SUBTRACT"][i]
            getattr(self.dut, f"io_in_{i}_bits_MULTIPLY").value = inputs["MULTIPLY"][i]
            getattr(self.dut, f"io_in_{i}_bits_IMMEDIATE").value = inputs["IMMEDIATE"][i]
            getattr(self.dut, f"io_in_{i}_bits_IS_LOAD").value = inputs["IS_LOAD"][i]
            getattr(self.dut, f"io_in_{i}_bits_IS_STORE").value = inputs["IS_STORE"][i]

    def read_fifo(self, inputs):
        for i in range(4):
            getattr(self.dut, f"io_out_{i}_ready").value = inputs["ready"][i]

    def get_outputs(self):
        outputs = {}
        outputs["valid"]        = [0]*4
        outputs["RS1_ready"]    = [0]*4
        outputs["RS2_ready"]    = [0]*4
        outputs["RD"]           = [0]*4
        outputs["RD_valid"]     = [0]*4
        outputs["RS1"]          = [0]*4
        outputs["RS1_valid"]    = [0]*4
        outputs["RS2"]          = [0]*4
        outputs["RS2_valid"]    = [0]*4
        outputs["IMM"]          = [0]*4
        outputs["FUNCT3"]       = [0]*4
        outputs["packet_index"] = [0]*4
        outputs["ROB_index"]    = [0]*4
        outputs["instructionType"] = [0]*4
        outputs["portID"]       = [0]*4
        outputs["RS_type"]      = [0]*4
        outputs["needs_ALU"]    = [0]*4
        outputs["needs_branch_unit"] = [0]*4
        outputs["needs_CSRs"]   = [0]*4
        outputs["SUBTRACT"]     = [0]*4
        outputs["MULTIPLY"]     = [0]*4
        outputs["IMMEDIATE"]    = [0]*4
        outputs["IS_LOAD"]      = [0]*4
        outputs["IS_STORE"]     = [0]*4

        for i in range(4):
            outputs["valid"][i] = getattr(self.dut, f"io_out_{i}_valid").value
            outputs["RS1_ready"][i] = getattr(self.dut, f"io_out_{i}_bits_ready_bits_RS1_ready").value
            outputs["RS2_ready"][i] = getattr(self.dut, f"io_out_{i}_bits_ready_bits_RS2_ready").value
            outputs["RD"][i] = getattr(self.dut, f"io_out_{i}_bits_RD").value
            outputs["RD_valid"][i] = getattr(self.dut, f"io_out_{i}_bits_RD_valid").value
            outputs["RS1"][i] = getattr(self.dut, f"io_out_{i}_bits_RS1").value
            outputs["RS1_valid"][i] = getattr(self.dut, f"io_out_{i}_bits_RS1_valid").value
            outputs["RS2"][i] = getattr(self.dut, f"io_out_{i}_bits_RS2").value
            outputs["RS2_valid"][i] = getattr(self.dut, f"io_out_{i}_bits_RS2_valid").value
            outputs["IMM"][i] = getattr(self.dut, f"io_out_{i}_bits_IMM").value
            outputs["FUNCT3"][i] = getattr(self.dut, f"io_out_{i}_bits_FUNCT3").value
            outputs["packet_index"][i] = getattr(self.dut, f"io_out_{i}_bits_packet_index").value
            outputs["ROB_index"][i] = getattr(self.dut, f"io_out_{i}_bits_ROB_index").value
            outputs["instructionType"][i] = getattr(self.dut, f"io_out_{i}_bits_instructionType").value
            outputs["portID"][i] = getattr(self.dut, f"io_out_{i}_bits_portID").value
            outputs["RS_type"][i] = getattr(self.dut, f"io_out_{i}_bits_RS_type").value
            outputs["needs_ALU"][i] = getattr(self.dut, f"io_out_{i}_bits_needs_ALU").value
            outputs["needs_branch_unit"][i] = getattr(self.dut, f"io_out_{i}_bits_needs_branch_unit").value
            outputs["needs_CSRs"][i] = getattr(self.dut, f"io_out_{i}_bits_needs_CSRs").value
            outputs["SUBTRACT"][i] = getattr(self.dut, f"io_out_{i}_bits_SUBTRACT").value
            outputs["MULTIPLY"][i] = getattr(self.dut, f"io_out_{i}_bits_MULTIPLY").value
            outputs["IMMEDIATE"][i] = getattr(self.dut, f"io_out_{i}_bits_IMMEDIATE").value
            outputs["IS_LOAD"][i] = getattr(self.dut, f"io_out_{i}_bits_IS_LOAD").value
            outputs["IS_STORE"][i] = getattr(self.dut, f"io_out_{i}_bits_IS_STORE").value

        return outputs

    def get_ready(self):
        ready = {}
        ready["ready"] = [0]*4

        for i in range(4):
            ready["ready"][i] = getattr(self.dut, f"io_in_{i}_ready").value

        return ready


    def get_fifo_contents(self):
        FIFO = {}
        FIFO["RS1_ready"]           = [0]*8
        FIFO["RS2_ready"]           = [0]*8
        FIFO["RD"]                  = [0]*8
        FIFO["RD_valid"]            = [0]*8
        FIFO["RS1"]                 = [0]*8
        FIFO["RS1_valid"]           = [0]*8
        FIFO["RS2"]                 = [0]*8
        FIFO["RS2_valid"]           = [0]*8
        FIFO["IMM"]                 = [0]*8
        FIFO["FUNCT3"]              = [0]*8
        FIFO["packet_index"]        = [0]*8
        FIFO["ROB_index"]           = [0]*8
        FIFO["instructionType"]     = [0]*8
        FIFO["portID"]              = [0]*8
        FIFO["RS_type"]             = [0]*8
        FIFO["needs_ALU"]           = [0]*8
        FIFO["needs_branch_unit"]   = [0]*8
        FIFO["needs_CSRs"]          = [0]*8
        FIFO["SUBTRACT"]            = [0]*8
        FIFO["MULTIPLY"]            = [0]*8
        FIFO["IMMEDIATE"]           = [0]*8
        FIFO["IS_LOAD"]             = [0]*8
        FIFO["IS_STORE"]            = [0]*8

        for i in range(8):
            FIFO["RS1_ready"][i]            = int(getattr(self.dut, f"queue_{i}_ready_bits_RS1_ready").value)
            FIFO["RS2_ready"][i]            = int(getattr(self.dut, f"queue_{i}_ready_bits_RS2_ready").value)
            FIFO["RD"][i]                   = int(getattr(self.dut, f"queue_{i}_RD").value)
            FIFO["RD_valid"][i]             = int(getattr(self.dut, f"queue_{i}_RD_valid").value)
            FIFO["RS1"][i]                  = int(getattr(self.dut, f"queue_{i}_RS1").value)
            FIFO["RS1_valid"][i]            = int(getattr(self.dut, f"queue_{i}_RS1_valid").value)
            FIFO["RS2"][i]                  = int(getattr(self.dut, f"queue_{i}_RS2").value)
            FIFO["RS2_valid"][i]            = int(getattr(self.dut, f"queue_{i}_RS2_valid").value)
            FIFO["IMM"][i]                  = int(getattr(self.dut, f"queue_{i}_IMM").value)
            FIFO["FUNCT3"][i]               = int(getattr(self.dut, f"queue_{i}_FUNCT3").value)
            FIFO["packet_index"][i]         = int(getattr(self.dut, f"queue_{i}_packet_index").value)
            FIFO["ROB_index"][i]            = int(getattr(self.dut, f"queue_{i}_ROB_index").value)
            FIFO["instructionType"][i]      = int(getattr(self.dut, f"queue_{i}_instructionType").value)
            FIFO["portID"][i]               = int(getattr(self.dut, f"queue_{i}_portID").value)
            FIFO["RS_type"][i]              = int(getattr(self.dut, f"queue_{i}_RS_type").value)
            FIFO["needs_ALU"][i]            = int(getattr(self.dut, f"queue_{i}_needs_ALU").value)
            FIFO["needs_branch_unit"][i]    = int(getattr(self.dut, f"queue_{i}_needs_branch_unit").value)
            FIFO["needs_CSRs"][i]           = int(getattr(self.dut, f"queue_{i}_needs_CSRs").value)
            FIFO["SUBTRACT"][i]             = int(getattr(self.dut, f"queue_{i}_SUBTRACT").value)
            FIFO["MULTIPLY"][i]             = int(getattr(self.dut, f"queue_{i}_MULTIPLY").value)
            FIFO["IMMEDIATE"][i]            = int(getattr(self.dut, f"queue_{i}_IMMEDIATE").value)
            FIFO["IS_LOAD"][i]              = int(getattr(self.dut, f"queue_{i}_IS_LOAD").value)
            FIFO["IS_STORE"][i]             = int(getattr(self.dut, f"queue_{i}_IS_STORE").value)
        return FIFO

    def print_fifo_contents(self):
        fifo_contents = self.get_fifo_contents()

        # Print header
        print("Entry | RS1_ready | RS2_ready | RD | RD_valid | RS1 | RS1_valid | RS2 | RS2_valid | IMM | FUNCT3 | packet_index | ROB_index | instructionType | portID | RS_type | needs_ALU | needs_branch_unit | needs_CSRs | SUBTRACT | MULTIPLY | IMMEDIATE | IS_LOAD | IS_STORE")

        # Print contents
        for i in range(8):
            print(f"{i} | ", end="")
            print(f"{fifo_contents['RS1_ready'][i]} | ", end="")
            print(f"{fifo_contents['RS2_ready'][i]} | ", end="")
            print(f"{fifo_contents['RD'][i]} | ", end="")
            print(f"{fifo_contents['RD_valid'][i]} | ", end="")
            print(f"{fifo_contents['RS1'][i]} | ", end="")
            print(f"{fifo_contents['RS1_valid'][i]} | ", end="")
            print(f"{fifo_contents['RS2'][i]} | ", end="")
            print(f"{fifo_contents['RS2_valid'][i]} | ", end="")
            print(f"{fifo_contents['IMM'][i]} | ", end="")
            print(f"{fifo_contents['FUNCT3'][i]} | ", end="")
            print(f"{fifo_contents['packet_index'][i]} | ", end="")
            print(f"{fifo_contents['ROB_index'][i]} | ", end="")
            print(f"{fifo_contents['instructionType'][i]} | ", end="")
            print(f"{fifo_contents['portID'][i]} | ", end="")
            print(f"{fifo_contents['RS_type'][i]} | ", end="")
            print(f"{fifo_contents['needs_ALU'][i]} | ", end="")
            print(f"{fifo_contents['needs_branch_unit'][i]} | ", end="")
            print(f"{fifo_contents['needs_CSRs'][i]} | ", end="")
            print(f"{fifo_contents['SUBTRACT'][i]} | ", end="")
            print(f"{fifo_contents['MULTIPLY'][i]} | ", end="")
            print(f"{fifo_contents['IMMEDIATE'][i]} | ", end="")
            print(f"{fifo_contents['IS_LOAD'][i]} | ", end="")
            print(f"{fifo_contents['IS_STORE'][i]}")
    # Module set outputs ready

    # Module Write functions

    # Module Read functions

    # Module print visualizers