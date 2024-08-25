import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path
import os

from cocotb_utils import *
from MOB_TB import *

from model_utils import *
from MOB import *

from drivers.drivers import *



@cocotb.test()
async def test_reset(dut):
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    MOB = MOB_TB(dut)     # construct TB
    await MOB.reset()     # Reset

    await MOB.clock()
    await MOB.clock()
    await MOB.clock()
    await MOB.clock()

@cocotb.test()
async def test_fuzz(dut):
    # Set seed
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    MOB = MOB_TB(dut)     # construct TB
    await MOB.reset()     # Reset

    await MOB.clock()
    await MOB.clock()
    await MOB.clock()
    await MOB.clock()

    MOB.MOB.MOB.io_backend_memory_request_ready.value = 1


    # reserve a MOB entry

    reserve = [{} for _ in range(4)]

    for i in range(4):
        reserve[i] = {
            "valid": 0,
            "bits": {
                "ready_bits_RS1_ready": 0,
                "ready_bits_RS2_ready": 0,
                "RDold": 0,
                "RD": 0,
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
                "FTQ_index": 0,
                "instructionType": 0,
                "portID": 0,
                "RS_type": 0,
                "needs_ALU": 0,
                "needs_branch_unit": 0,
                "needs_CSRs": 0,
                "SUBTRACT": 0,
                "MULTIPLY": 0,
                "IS_IMM": 0,
                "memory_type": 0,
                "access_width": 0,
            }
        }


    AGU = {
        "valid": 0,
        "bits": {
            "RD": 0,
            "RD_data": 0,
            "RD_valid": 0,
            "fetch_PC": 0,
            "branch_taken": 0,
            "target_address": 0,
            "branch_valid": 0,
            "address": 0,
            "memory_type": 0,
            "access_width":0,
            "is_unsigned": 0,
            "wr_data": 0,
            "MOB_index": 0,
            "ROB_index": 0,
            "FTQ_index": 0,
            "fetch_packet_index": 0,
            "violation": 0
        }
    }

    # Reserve store 0
    reserve[0]["valid"] = 1
    reserve[0]["bits"]["memory_type"] = memory_type_t.STORE.value
    reserve[0]["bits"]["access_width"] = access_width_t.W.value
    reserve[0]["bits"]["RD"] = 5

    await MOB.write_reserve(reserve)

    # Reserve store 1
    reserve[0]["valid"] = 1
    reserve[0]["bits"]["memory_type"] = memory_type_t.STORE.value
    reserve[0]["bits"]["access_width"] = access_width_t.W.value
    reserve[0]["bits"]["RD"] = 5
    await MOB.write_reserve(reserve)

    # Reserve load 0
    reserve[0]["valid"] = 1
    reserve[0]["bits"]["memory_type"] = memory_type_t.LOAD.value
    reserve[0]["bits"]["access_width"] = access_width_t.W.value
    reserve[0]["bits"]["RD"] = 8
    await MOB.write_reserve(reserve)


    await MOB.clock()
    await MOB.clock()
    await MOB.clock()
    await MOB.clock()



    # update AGU for entry 0
    AGU["valid"] = 1
    AGU["bits"]["address"] = 0x40
    AGU["bits"]["wr_data"] = 0xdeadc0de
    AGU["bits"]["memory_type"] = memory_type_t.STORE.value
    AGU["bits"]["MOB_index"] = 0
    await MOB.write_AGU_output(AGU)

    # update AGU for entry 2
    AGU["valid"] = 1
    AGU["bits"]["address"] = 0x40
    AGU["bits"]["wr_data"] = 0
    AGU["bits"]["memory_type"] = memory_type_t.LOAD.value
    AGU["bits"]["MOB_index"] = 2
    await MOB.write_AGU_output(AGU)


    await MOB.clock()
    await MOB.clock()


    await MOB.clock()
    await MOB.clock()
    await MOB.clock()
    await MOB.clock()

    await MOB.write_backend_memory_response({
        "valid" : 1,
        "bits": {
            "addr" : 0x40,
            "data" : 0xdeadbeef,
            "MOB_index" : 2,
        }
    })

    await MOB.clock()
    await MOB.clock()
    await MOB.clock()
    await MOB.clock()

    # update AGU for entry 1 (this should cause a violation)
    AGU["valid"] = 1
    AGU["bits"]["address"] = 0x48
    AGU["bits"]["wr_data"] = 0
    AGU["bits"]["memory_type"] = memory_type_t.STORE.value
    AGU["bits"]["MOB_index"] = 1
    await MOB.write_AGU_output(AGU)


    await MOB.clock()
    await MOB.clock()
    await MOB.clock()




    assert False



@cocotb.test()
async def test_fuzz(dut):
    # Set seed
    memory_capacity = 256*2**10
    random.seed(0x42)

    # Start lock
    await cocotb.start(generateClock(dut))

    # Bring up TB
    MOB = MOB_TB(dut, memory_capacity)     # construct TB


    dut.io_backend_memory_request_ready.value = 1



    await MOB.reset()     # Reset

    for _ in range(5000):

        await MOB.update()

    assert False






    

