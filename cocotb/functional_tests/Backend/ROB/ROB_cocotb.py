import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path

from ROB_tb import *

from cocotb_utils import *
from ROB.signals import *

@cocotb.test()
async def test_reset(dut):

    await cocotb.start(generateClock(dut)) 

    dut = ROB_dut(dut)    # Wrap Dut

    ROB_tb = ROB_TB(dut)  # Init TB

    ROB_tb.reset()

    ROB_tb.start()


    # Drive signals...


    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())





@cocotb.test()
async def test_fuzz_allocate(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    dut = ROB_dut(dut)    # Wrap Dut

    ROB_tb = ROB_TB(dut)  # Init TB

    await ROB_tb.reset()

    ROB_tb.start()


    # Drive signals...


    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    random_ROB_packet = generate_null_allocate()

    for i in range(1000):

        random_ROB_packet["valid"]                        =  random.randint(0,1)
        random_ROB_packet["fetch_PC"]                     =  random.randint(0,0xFFFFFFFF)
        random_ROB_packet["RS1_ready"]                    =  [0]*4
        random_ROB_packet["RS2_ready"]                    =  [0]*4
        random_ROB_packet["RD"]                           =  [0]*4
        random_ROB_packet["RD_valid"]                     =  [0]*4
        random_ROB_packet["RS1"]                          =  [0]*4
        random_ROB_packet["RS1_valid"]                    =  [0]*4
        random_ROB_packet["RS2"]                          =  [0]*4
        random_ROB_packet["RS2_valid"]                    =  [0]*4
        random_ROB_packet["IMM"]                          =  [0]*4
        random_ROB_packet["FUNCT3"]                       =  [0]*4
        random_ROB_packet["packet_index"]                 =  [0]*4
        random_ROB_packet["ROB_index"]                    =  [0]*4
        random_ROB_packet["instructionType"]              =  [0]*4
        random_ROB_packet["portID"]                       =  [0]*4
        random_ROB_packet["RS_type"]                      =  [0]*4
        random_ROB_packet["needs_ALU"]                    =  [0]*4
        random_ROB_packet["needs_branch_unit"]            =  [0]*4
        random_ROB_packet["needs_CSRs"]                   =  [0]*4
        random_ROB_packet["SUBTRACT"]                     =  [0]*4
        random_ROB_packet["MULTIPLY"]                     =  [0]*4
        random_ROB_packet["IMMEDIATE"]                    =  [0]*4
        random_ROB_packet["IS_LOAD"]                      =  [0]*4
        random_ROB_packet["IS_STORE"]                     =  [0]*4
        random_ROB_packet["valid_bits"]                   =  [random.randint(0, 1) for _ in range(4)]


        dut.write_ROB_packet(random_ROB_packet)
        await RisingEdge(dut.clock())



# ROB test

def generate_load_store_bits():
    load = [0,0,0,0]
    store = [0,0,0,0]

    for i in range(4):
        load[i] = random.choices([1, 0], weights=[0.3, 0.7], k=1)
        if(load[i]): store[i] = 0
        else: random.choices([1, 0], weights=[0.3, 0.7], k=1)

    return load, store


def generate_random_ROB_packet(valid:bool):

    random_ROB_packet = generate_null_allocate()
    
    # shared data
    random_ROB_packet["valid"]                        =  valid
    random_ROB_packet["fetch_PC"]                     =  random.randint(0,0xFFFFFFFF/16)*16
    
    # RS1
    random_ROB_packet["RS1_ready"]                    =  [0]*4
    random_ROB_packet["RS1_valid"]                    =  [0]*4
    random_ROB_packet["RS1"]                          =  [0]*4

    random_ROB_packet["RS2_ready"]                    =  [0]*4
    random_ROB_packet["RS2"]                          =  [0]*4
    random_ROB_packet["RS2_valid"]                    =  [0]*4


    random_ROB_packet["RD"]                           =  [0]*4
    random_ROB_packet["RD_valid"]                     =  [0]*4


    random_ROB_packet["IMM"]                          =  [0]*4
    random_ROB_packet["FUNCT3"]                       =  [0]*4
    random_ROB_packet["instructionType"]              =  [0]*4

    random_ROB_packet["ROB_index"]                    =  [0]*4
    random_ROB_packet["packet_index"]                 =  [0,1,2,3]
    random_ROB_packet["portID"]                       =  [random.randint(0,3) for _ in range(4)]


    random_ROB_packet["RS_type"]                      =  [0]*4
    random_ROB_packet["needs_ALU"]                    =  [0]*4
    random_ROB_packet["needs_branch_unit"]            =  [0]*4
    random_ROB_packet["needs_CSRs"]                   =  [0]*4
    random_ROB_packet["SUBTRACT"]                     =  [0]*4
    random_ROB_packet["MULTIPLY"]                     =  [0]*4
    random_ROB_packet["IMMEDIATE"]                    =  [0]*4

    random_ROB_packet["IS_LOAD"]                      = [random.choices([1, 0], weights=[0.3, 0.7], k=1) for _ in range(4)]
    
    for i in range(4):
        if(not random_ROB_packet["IS_LOAD"][i]):
            random_ROB_packet["IS_STORE"][i]         = random.choices([1, 0], weights=[0.3, 0.7], k=1)

    random_ROB_packet["valid_bits"]                   =  [random.randint(0, 1) for _ in range(4)]

    return random_ROB_packet


current_ROB_index = 0

def generate_random_FU_output(valid:bool):




    pass

def generate_random_commit():
    pass

def generate_random_index():
    pass


