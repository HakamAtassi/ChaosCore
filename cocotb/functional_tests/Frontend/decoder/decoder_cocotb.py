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
    
    portID = 0    

    for i in range(10000):
    
        instruction = random.randint(0,0xffffffff)
        decoder_model = decoder_sw(1, instruction, 1, 1, 1)
        
        if decoder_model.valid and \
            decoder_model.opcode != ENV:
            
            await RisingEdge(dut.clock()); await ReadWrite()
                
            #print(hex(instruction))
            dut.input_instruction(instruction)
            
            await ReadOnly(); outputs = dut.get_output()
            
            for field in outputs.keys():
                
                if getattr(decoder_model,"valid"):
                    
                    if field == "IMM":
                        if getattr(decoder_model,"IMMEDIATE"):
                            assert outputs[field] == getattr(decoder_model,field)
                            
                    if field == "portID":
                        if  outputs["needs_ALU"]:
                            assert outputs[field] == portID
                            portID = (portID + 1)%3
                    else:
                        assert outputs[field] == getattr(decoder_model,field)
    
    
# @cocotb.test()
# async def test_fetch_packet_decoder(dut):
#     await cocotb.start(generateClock(dut)) 

#     dut = fetch_pkt_decoder_dut(dut)  # wrap dut with helper class
#     await dut.reset()   # reset module

#     await RisingEdge(dut.clock())
    
#     fetch_PC = 0x0
#     valid_bits = [0 for _ in range(dut.FETCH_WIDTH)]
#     instructions = [random.randint(0,0xffffffff) for _ in range(dut.FETCH_WIDTH)]
#     packet_indices = [0 for _ in range(dut.FETCH_WIDTH)]
#     ROB_indices = [0 for _ in range(dut.FETCH_WIDTH)]
#     decoded_fetch_pkt_rdy_bits = [0 for _ in range(dut.FETCH_WIDTH)]
#     dut.fetch_packet(fetch_PC,
#                      valid_bits,
#                      decoded_fetch_pkt_rdy_bits,
#                      instructions,
#                      packet_indices,
#                      ROB_indices)
#     await ReadOnly()
#     outputs = dut.get_output()
    
#     fetch_packet_ready = 1
#     for i in range(dut.FETCH_WIDTH):
#         fetch_packet_ready &= decoded_fetch_pkt_rdy_bits
        
#     assert outputs["fetch_packet_ready"] == fetch_packet_ready
    
#     await RisingEdge(dut.clock()); await ReadOnly(); outputs = dut.get_output()
    
    
    
    
    