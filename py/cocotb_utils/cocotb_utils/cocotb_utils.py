import random
import numpy as np
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer
from pathlib import Path


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