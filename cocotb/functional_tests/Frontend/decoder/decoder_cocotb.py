import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path

from cocotb_utils import *
from decoder_dut import *

import random 

@cocotb.test()
async def test_reset(dut):

    await cocotb.start(generateClock(dut)) 

    dut = decoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

@cocotb.test()
async def test_instruction_fields(dut):
    await cocotb.start(generateClock(dut)) 

    dut = decoder_dut(dut)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())
    

    for i in range(10000):
    
        instruction = random.randint(0,0xffffffff)
        decoder_model = decoder_sw(1, instruction, 1, 1, 1)
        
        if decoder_model.valid and \
            decoder_model.opcode != ENV:
            
            await ReadWrite()
                
            print(hex(instruction))
            dut.input_instruction(instruction)
            
            await RisingEdge(dut.clock()); await ReadOnly(); outputs = dut.get_output()
            
            for field in ["RS1", "RS2", "RD", "IMM", "FUNCT3", 
                          "RD_valid", "RS1_valid", "RS2_valid",
                          "MULTIPLY", "SUBTRACT", "IMMEDIATE"]:
                
                if getattr(decoder_model,"valid"):
                    
                    if field == "IMM":
                        if getattr(decoder_model,"IMMEDIATE"):
                            assert outputs[field] == getattr(decoder_model,field)
                    else:
                        assert outputs[field] == getattr(decoder_model,field)
    