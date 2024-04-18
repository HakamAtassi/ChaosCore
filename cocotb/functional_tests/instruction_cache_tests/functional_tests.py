import random
import cocotb
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




@cocotb.test()
async def functionalTest0(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await RisingEdge(dut.clock)
    await reset(dut)

    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    assert dut.io_cpu_addr_ready.value == 1, "Ready not high after reset. "
    await RisingEdge(dut.clock)

    await requestRead(dut, 0xFFFFFFFF)
    await generateDramResp(dut)

    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)


    await requestRead(dut, 0xFFFFFFFF)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)


    await requestRead(dut, 0xFFFFFFF0)
    await generateDramResp(dut)

    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)

    await requestRead(dut, 0xFFFFFFF0)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
