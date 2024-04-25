import random
import numpy as np
import cocotb
from utils import *
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer

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
    await RisingEdge(dut.clock)

async def requestRead(dut, address):
    dut.io_cpu_addr_valid.value = 1
    dut.io_cpu_addr_bits.value = address
    await RisingEdge(dut.clock)
    dut.io_cpu_addr_valid.value = 0


async def generateDramResp(dut, dramData="Random", dramLantecy="Random"):

    if(dramLantecy=="Random"):
        for step in range(random.randint(0,150)):
            await RisingEdge(dut.clock)
    else:
        for step in range(dramLantecy):
            await RisingEdge(dut.clock)

    if(dramData == "Random"):
        dut.io_dram_data_bits.value = random.randint(0,(2**256)-1)
    else:
        dut.io_dram_data_bits.value = dramData

    dut.io_dram_data_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_dram_data_valid.value = 0

def placeInstruction(dut, fetch_PC, instrs, valid_bits):
    dut.io_fetch_packet_fetch_PC.value  = fetch_PC  # what PC is this?
    dut.io_fetch_packet_instructions_0.value  = instrs[0]
    dut.io_fetch_packet_instructions_1.value  = instrs[1]
    dut.io_fetch_packet_instructions_2.value  = instrs[2]
    dut.io_fetch_packet_instructions_3.value  = instrs[3]

    dut.io_fetch_packet_valid_bits_0.value  = valid_bits[0]
    dut.io_fetch_packet_valid_bits_1.value  = valid_bits[1]
    dut.io_fetch_packet_valid_bits_2.value  = valid_bits[2]
    dut.io_fetch_packet_valid_bits_3.value  = valid_bits[3]

def placeBTB(dut, hit, idx, T_NT, RAS, target, GHR ):
    dut.io_BTB_resp_hit.value       = hit
    dut.io_BTB_resp_idx.value       = idx
    dut.io_BTB_resp_T_NT.value      = T_NT
    dut.io_BTB_resp_RAS.value       = RAS
    dut.io_BTB_resp_target.value    = target
    dut.io_BTB_resp_GHR.value       = GHR


@cocotb.test()
async def test0(dut):

    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await RisingEdge(dut.clock)

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    add = generateADD(0,0,0)
    instrs=[add, add, add, add]
    valid=[1,1,1,1]

    placeInstruction(dut, 0x0, instrs, valid)
    placeBTB(dut, 0, 0, 0, 0, 0, 0 )
    dut.io_input_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_input_valid.value = 0
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    # All inputs should be passed through
    assert dut.io_final_fetch_packet_valid_bits_0.value == 1
    assert dut.io_final_fetch_packet_valid_bits_1.value == 1
    assert dut.io_final_fetch_packet_valid_bits_2.value == 1
    assert dut.io_final_fetch_packet_valid_bits_3.value == 1

    assert dut.io_final_fetch_packet_instructions_0.value ==  instrs[0]
    assert dut.io_final_fetch_packet_instructions_1.value ==  instrs[1]
    assert dut.io_final_fetch_packet_instructions_2.value ==  instrs[2]
    assert dut.io_final_fetch_packet_instructions_3.value ==  instrs[3]

    await RisingEdge(dut.clock)


@cocotb.test()
async def test1(dut):

    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await RisingEdge(dut.clock)

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    add0 = generateADD(3,0,0)
    add1 = generateADD(6,0,0)
    add2 = generateADD(0,7,0)
    add3 = generateADD(0,0,9)
    instrs=[add0, add1, add2, add3]
    valid=[1,1,1,1]

    placeInstruction(dut, 0x0, instrs, valid)
    placeBTB(dut, 0, 0, 0, 0, 0, 0 )
    dut.io_input_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_input_valid.value = 0
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    # All inputs should be passed through
    assert dut.io_final_fetch_packet_valid_bits_0.value == 1
    assert dut.io_final_fetch_packet_valid_bits_1.value == 1
    assert dut.io_final_fetch_packet_valid_bits_2.value == 1
    assert dut.io_final_fetch_packet_valid_bits_3.value == 1

    assert dut.io_final_fetch_packet_instructions_0.value ==  instrs[0]
    assert dut.io_final_fetch_packet_instructions_1.value ==  instrs[1]
    assert dut.io_final_fetch_packet_instructions_2.value ==  instrs[2]
    assert dut.io_final_fetch_packet_instructions_3.value ==  instrs[3]

    await RisingEdge(dut.clock)

@cocotb.test()
async def testUncondTaken(dut):

    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await RisingEdge(dut.clock)

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    add0 = generateADD(3,0,0)
    add1 = generateADD(6,0,0)
    JAL = generateJAL(0)
    add2 = generateADD(6,0,0)
    instrs=[add0, add1, JAL, add2]
    valid=[1,1,1,1]

    placeInstruction(dut, 0x0, instrs, valid)
    placeBTB(dut, 0, 0, 0, 0, 0, 0 )
    dut.io_input_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_input_valid.value = 0
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    # All inputs should be passed through
    assert dut.io_final_fetch_packet_valid_bits_0.value == 1
    assert dut.io_final_fetch_packet_valid_bits_1.value == 1
    assert dut.io_final_fetch_packet_valid_bits_2.value == 1
    assert dut.io_final_fetch_packet_valid_bits_3.value == 0

    assert dut.io_final_fetch_packet_instructions_0.value ==  instrs[0]
    assert dut.io_final_fetch_packet_instructions_1.value ==  instrs[1]
    assert dut.io_final_fetch_packet_instructions_2.value ==  instrs[2]
    assert dut.io_final_fetch_packet_instructions_3.value ==  instrs[3]

    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    add0 = generateADD(0,0,0)
    add1 = generateADD(0,0,0)
    JAL = generateJAL(0)
    add2 = generateADD(0,0,0)
    instrs=[JAL, add1, JAL, add2]
    valid=[1,1,1,1]

    placeInstruction(dut, 0x0, instrs, valid)
    placeBTB(dut, 0, 0, 0, 0, 0, 0 )
    dut.io_input_valid.value = 1
    await RisingEdge(dut.clock)
    dut.io_input_valid.value = 0
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    # All inputs should be passed through
    assert dut.io_final_fetch_packet_valid_bits_0.value == 1
    assert dut.io_final_fetch_packet_valid_bits_1.value == 0
    assert dut.io_final_fetch_packet_valid_bits_2.value == 0
    assert dut.io_final_fetch_packet_valid_bits_3.value == 0

    assert dut.io_final_fetch_packet_instructions_0.value ==  instrs[0]
    assert dut.io_final_fetch_packet_instructions_1.value ==  instrs[1]
    assert dut.io_final_fetch_packet_instructions_2.value ==  instrs[2]
    assert dut.io_final_fetch_packet_instructions_3.value ==  instrs[3]

    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)



@cocotb.test()
async def testNextPC(dut):

    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await RisingEdge(dut.clock)

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    add = generateADD(0,0,0)
    instrs=[add, add, add, add]
    valid=[1,1,1,1]
    placeInstruction(dut, 0x0, instrs, valid)
    placeBTB(dut, 0, 0, 0, 0, 0, 0 )
    dut.io_input_valid.value = 1
    dut.io_fetch_packet_fetch_PC.value = 0x00


    await RisingEdge(dut.clock)
    dut.io_input_valid.value = 0
    await RisingEdge(dut.clock)

    add = generateADD(4,0,4)
    instrs=[add, add, add, add]
    valid=[1,1,1,1]
    placeInstruction(dut, 0x0, instrs, valid)
    placeBTB(dut, 0, 0, 0, 0, 0, 0 )
    dut.io_input_valid.value = 1
    dut.io_fetch_packet_fetch_PC.value = 0x42

    await RisingEdge(dut.clock)
    dut.io_input_valid.value = 0

    await FallingEdge(dut.clock)
    assert dut.io_final_fetch_packet_valid_bits_0.value == 0
    assert dut.io_final_fetch_packet_valid_bits_1.value == 0
    assert dut.io_final_fetch_packet_valid_bits_2.value == 0
    assert dut.io_final_fetch_packet_valid_bits_3.value == 0


    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)



@cocotb.test()
async def testNextPC2(dut):

    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await RisingEdge(dut.clock)

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    add = generateADD(0,0,0)
    instrs=[add, add, add, add]
    valid=[1,1,1,1]
    placeInstruction(dut, 0x0, instrs, valid)
    placeBTB(dut, 0, 0, 0, 0, 0, 0 )
    dut.io_input_valid.value = 1
    dut.io_fetch_packet_fetch_PC.value = 0x00
    await RisingEdge(dut.clock)

    add = generateADD(4,0,4)
    instrs=[add, add, add, add]
    valid=[1,1,1,1]
    placeInstruction(dut, 0x0, instrs, valid)
    placeBTB(dut, 0, 0, 0, 0, 0, 0 )
    dut.io_input_valid.value = 1
    dut.io_fetch_packet_fetch_PC.value = 0x10

    await RisingEdge(dut.clock)
    dut.io_input_valid.value = 0

    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)


@cocotb.test()
async def testNextPC3(dut):

    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await RisingEdge(dut.clock)

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    add = generateADD(0,0,0)
    JAL = 0x00a0006f
    instrs=[add, add, JAL, add]
    valid=[1,1,1,1]
    placeInstruction(dut, 0x0, instrs, valid)
    placeBTB(dut, 0, 0, 0, 0, 0, 0 )
    dut.io_input_valid.value = 1
    dut.io_fetch_packet_fetch_PC.value = 0x00
    await RisingEdge(dut.clock)

    add = generateADD(4,0,4)
    instrs=[add, add, add, add]
    valid=[1,1,1,1]
    placeInstruction(dut, 0x0, instrs, valid)
    placeBTB(dut, 0, 0, 0, 0, 0, 0 )
    dut.io_input_valid.value = 1
    dut.io_fetch_packet_fetch_PC.value = 10+8

    await RisingEdge(dut.clock)
    dut.io_input_valid.value = 0

    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)