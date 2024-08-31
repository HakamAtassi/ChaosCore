import random
import re
import numpy as np
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer, ReadOnly
from pathlib import Path


import cocotb
import pytest
from cocotb.clock import Clock
from cocotb.handle import SimHandleBase
from cocotb.queue import Queue
from cocotb.triggers import RisingEdge
from cocotb.types import LogicArray, Range


async def generateClock(dut):
    while(1):
        dut.clock.value = 0
        await Timer(1, units="ns")
        dut.clock.value = 1
        await Timer(1, units="ns")

async def reset(dut):
    dut.reset.value = 0
    await RisingEdge(dut.clock)
    dut.reset.value = 1
    await RisingEdge(dut.clock)
    dut.reset.value = 0



def generate_random_commit_request(addr_set):
    #commit = generate_random_commit_request()
    #revert = generate_random_revert_request()
    #predict = generate_random_predict_request()
    #RAS_update = generate_random_RAS_update()

    address = random.choice(addr_set)
    commit_GHR = random.randint(0, ((1<<16)-1))
    T_NT = random.randint(0, 1)
    target = random.choice(addr_set)
    br_type = random.choice([0,0b11])
    br_mask = random.choice([0,0b1111])
    valid = random.randint(0, 1)

    misprediction = random.randint(0, 1)
    TOS, NEXT = 0, 0
    if(misprediction):
        #TOS, NEXT = random.choice(past_states)
        NEXT = random.randint(1, 127)   # FIXME: this is not really valid
        TOS = random.randint(0, NEXT-1)
    
    return (address, commit_GHR, T_NT, target, br_type, br_mask, misprediction, TOS, NEXT, valid)

def generate_random_revert_request(addr_set):
    address = random.choice(addr_set)
    commit_GHR = random.randint(0, ((1<<16)-1))
    valid = random.randint(0, 1)
    return (address, commit_GHR, valid)

def generate_random_predict_request(addr_set):
    address = random.choice(addr_set)
    valid = random.randint(0, 1)
    return (address, valid)

def generate_random_RAS_update(addr_set):
    call = random.randint(0, 1)
    ret = random.randint(0, 1-call)
    ret_addr = random.choice(addr_set)
    return (call, ret, ret_addr)


def generate_address_set(count=1000):
    addresses = []
    
    # Generate aligned addresses
    for i in range(count):
        aligned_address = random.randint(0x80000000, 0xFFFFFFFF) & 0xFFFFFFF0  # Align to 16-byte boundary
        addresses.append(aligned_address)
    
    # Generate misaligned addresses
    for i in range(count // 4):  # Add about 1/4 of the addresses as misaligned
        aligned_address = random.choice(addresses)
        offset = random.choice([4, 8, 12])  # Misalignment offsets
        misaligned_address = aligned_address + offset
        addresses.append(misaligned_address)
    
    # Generate addresses starting at higher addresses
    for i in range(count):
        higher_address = random.randint(0x80000000, 0xFFFFFFFF) & 0xFFFFFFF0  # Align to 16-byte boundary
        addresses.append(higher_address)

    
    return addresses

###########
# MONITOR #
###########

class Monitor:
    def __init__(self, clock, data, valid):
        self.values = Queue()
        self.clock = clock
        self.data = data
        self.valid = valid
        self.coro = None

    def start(self):
        if self.coro is not None:
            raise RuntimeError("Monitor already started")
        self.coro = cocotb.start_soon(self.run())

    def stop(self):
        if self.coro is None:
            raise RuntimeError("Monitor never started")
        self.coro.kill()
        self.coro = None

    async def run(self):
        while True:
            await ReadOnly()
            if self.valid.value != 1:
                await RisingEdge(self.valid)
                continue
            self.values.put_nowait(self.sample())
            await RisingEdge(self.clock)
    
    def sample(self): 
        return self.data()




def compare_decoded_fetch_packet(model_decoded_fetch_packet, dut_decoded_fetch_packet):
    assert model_decoded_fetch_packet["valid"] == dut_decoded_fetch_packet["valid"]
    assert model_decoded_fetch_packet["valid_bits"] == dut_decoded_fetch_packet["valid_bits"]

    for i in range(4):
        compare_RS1 = model_decoded_fetch_packet["RS1_valid"][i]
        if(compare_RS1):
            assert model_decoded_fetch_packet["RS1"][i]            == dut_decoded_fetch_packet["RS1"][i]
            assert model_decoded_fetch_packet["RS1_valid"][i]      == dut_decoded_fetch_packet["RS1_valid"][i]

        compare_RS2 = model_decoded_fetch_packet["RS2_valid"][i]
        if(compare_RS2):
            assert model_decoded_fetch_packet["RS2"][i]            == dut_decoded_fetch_packet["RS2"][i]
            assert model_decoded_fetch_packet["RS2_valid"][i]      == dut_decoded_fetch_packet["RS2_valid"][i]

        compare_RD = model_decoded_fetch_packet["RD_valid"][i]
        if(compare_RD):
            assert model_decoded_fetch_packet["RD_valid"][i]       == dut_decoded_fetch_packet["RD_valid"][i]
            assert model_decoded_fetch_packet["PRD"][i]             == dut_decoded_fetch_packet["PRD"][i]

        compare_imm = model_decoded_fetch_packet["IS_IMM"][i]
        if(compare_imm):
            assert model_decoded_fetch_packet["IMM"][i]            == dut_decoded_fetch_packet["IMM"][i]
            assert model_decoded_fetch_packet["IS_IMM"][i]         == dut_decoded_fetch_packet["IS_IMM"][i]

        assert model_decoded_fetch_packet["needs_ALU"][i]          == dut_decoded_fetch_packet["needs_ALU"][i]
        assert model_decoded_fetch_packet["needs_branch_unit"][i]  == dut_decoded_fetch_packet["needs_branch_unit"][i]


def extract_signals(dut, base_name, t_hex=None): # add an int/hex option
    result = []
    pattern = fr"io_{base_name}_(\d+)_(.+)"  # Note the 'r' before the string
    
    # Get all attributes of dut that match the pattern
    matching_attrs = [attr for attr in dir(dut) if re.match(pattern, attr)]
    
    # Find the maximum index
    max_index = max([int(re.match(pattern, attr).group(1)) for attr in matching_attrs])
    
    for i in range(max_index + 1):
        entry = {"valid": None, "ready":None, "bits": {}}
        
        for attr in matching_attrs:
            match = re.match(pattern, attr)
            if match and int(match.group(1)) == i:
                if match.group(2) == "valid":
                    entry["valid"] = int(getattr(dut, attr).value)
                if match.group(2) == "ready":
                    entry["ready"] = int(getattr(dut, attr).value)
                elif match.group(2).startswith("bits_"):
                    bit_name = match.group(2)[5:]  # Remove 'bits_' prefix
                    entry["bits"][bit_name] = int(getattr(dut, attr).value)
                    if t_hex:
                        entry["bits"][bit_name] = hex(entry["bits"][bit_name])

        
        result.append(entry)
    
    return result

def write_signals(dut, base_name, data_dict):
    pattern = fr"io_{base_name}_(\d+)_(.+)"
    
    # Get all attributes of dut that match the pattern
    matching_attrs = [attr for attr in dir(dut) if re.match(pattern, attr)]
    
    for attr in matching_attrs:
        match = re.match(pattern, attr)
        
        if match:
            index = int(match.group(1))
            field = match.group(2)
            
            if index < len(data_dict):
                if field == "valid":
                    getattr(dut, attr).value= data_dict[index].get("valid", 0)
                elif field.startswith("bits_"):
                    bit_name = field[5:]  # Remove 'bits_' prefix
                    value = data_dict[index].get("bits", {}).get(bit_name, 0)
                    getattr(dut, attr).value =  value
            else:
                # Set to 0 if index is out of range of provided data
                getattr(dut, attr).value = 0



