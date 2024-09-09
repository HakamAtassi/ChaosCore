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

from ROB_TB import *


def get_ROB_packet():
    return {
    "valid": 0,
    "ready": 0,
    "bits": {
        "decoded_instruction": [{
            "ready_bits": {
                "RS1_ready": 0,
                "RS2_ready": 0,
            },
            "RD": 0,
            "PRD": 0,
            "RD_valid": 0,
            "RS1": 0,
            "RS1_valid": 0,
            "RS2": 0,
            "RS2_valid": 0,
            "IMM": 0,
            "FUNCT3": 0,
            "packet_index": 0,
            "ROB_index": 0,
            "MOB_index": 0,
            "instructionType": 0,
            "portID": 0,
            "RS_type": 0,
            "needs_ALU": 0,
            "needs_branch_unit": 0,
            "needs_CSRs": 0,
            "SUBTRACT": 0,
            "MULTIPLY": 0,
            "IS_IMM": 0,
            "memory_type": 0
        } for i in range(4)],
        "valid_bits": [0 for i in range(4)],
        "GHR": 0,
        "TOS": 0,
        "NEXT": 0,
        "fetch_PC": 0,
        "prediction": {
            "target": 0,
            "br_type": 0,
            "T_NT": 0,
            "free_list_front_pointer": 0
        }
    }
}

def get_FUs():
    return [{
        "valid" : 0,
        "bits": {
            "PRD" : 0,
            "RD_data" : 0,
            "RD_valid" : 0,
            "fetch_PC" : 0,
            "branch_taken" : 0,
            "target_address" : 0,
            "branch_valid" : 0,
            "address" : 0,
            "memory_type" : 0,
            "access_width" : 0,
            "is_unasigned" : 0,
            "wr_data" : 0,
            "MOB_index" : 0,
            "ROB_index" : 0,
            "fetch_packet_index" : 0,
        }
    } for i in range(4)]



@cocotb.test()
async def test_reset(dut):
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))


    ROB = ROB_TB(dut)

    await ROB.reset()


    await ROB.clock()


    ROB_packet = get_ROB_packet()


    ROB.write_ROB_packet(ROB_packet)

    await ROB.clock()
    await ROB.clock()


    # INPUT ROB PACKET #

    ROB_packet["valid"] = 1
    ROB_packet["bits"]["fetch_PC"] = 0xdeadbee0

    ROB_packet["bits"]["prediction"]["target"] = 0x8000bee0
    ROB_packet["bits"]["prediction"]["T_NT"]  = 1

    # instr 0 
    ROB_packet["bits"]["valid_bits"][0] = 1
    ROB_packet["bits"]["decoded_instruction"][0]["needs_branch_unit"]  = 0
    ROB_packet["bits"]["decoded_instruction"][0]["packet_index"]  = 0

    # instr 1
    ROB_packet["bits"]["valid_bits"][1] = 1
    ROB_packet["bits"]["decoded_instruction"][1]["needs_branch_unit"]  = 1
    ROB_packet["bits"]["decoded_instruction"][1]["packet_index"]  = 1

    # instr 2 
    ROB_packet["bits"]["valid_bits"][2] = 1
    ROB_packet["bits"]["decoded_instruction"][2]["needs_branch_unit"]  = 0
    ROB_packet["bits"]["decoded_instruction"][2]["packet_index"]  = 2

    # instr 3 
    ROB_packet["bits"]["valid_bits"][3] = 1
    ROB_packet["bits"]["decoded_instruction"][3]["needs_branch_unit"]  = 0
    ROB_packet["bits"]["decoded_instruction"][3]["packet_index"]  = 3



    # branch related things


    ROB.write_ROB_packet(ROB_packet)
    await ROB.clock()
    ROB.write_ROB_packet(get_ROB_packet())
    await ROB.clock()
    await ROB.clock()

    FUs = get_FUs()


    # FU WB #

    # isntr0 
    FUs[0]["valid"] =1
    FUs[0]["bits"]["ROB_index"] = 0
    FUs[0]["bits"]["fetch_packet_index"] = 1
    FUs[0]["bits"]["branch_valid"] = 1
    FUs[0]["bits"]["target_address"] = 0xfce
    FUs[0]["bits"]["branch_taken"] = 1


    # instr1 
    FUs[1]["valid"] = 1
    FUs[1]["bits"]["ROB_index"] = 0
    FUs[1]["bits"]["fetch_packet_index"] = 0

    # instr2
    FUs[2]["valid"] = 1
    FUs[2]["bits"]["ROB_index"] = 0
    FUs[2]["bits"]["fetch_packet_index"] = 2


    # instr3 
    FUs[3]["valid"] = 1
    FUs[3]["bits"]["ROB_index"] = 0
    FUs[3]["bits"]["fetch_packet_index"] = 3



    ROB.write_FU(FUs[0], 0)
    ROB.write_FU(FUs[1], 1)
    ROB.write_FU(FUs[2], 2)
    ROB.write_FU(FUs[3], 3)


    await ROB.clock()
    ROB.write_FU(get_FUs()[0], 0)
    ROB.write_FU(get_FUs()[1], 1)
    ROB.write_FU(get_FUs()[2], 2)
    ROB.write_FU(get_FUs()[3], 3)
    await ROB.clock()
    await ROB.clock()
    await ROB.clock()
    await ROB.clock()
    await ROB.clock()
    await ROB.clock()


    


    assert False
