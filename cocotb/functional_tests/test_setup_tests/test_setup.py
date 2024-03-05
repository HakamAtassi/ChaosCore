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


@cocotb.test()
async def testSystem(dut):

    await cocotb.start(generateClock(dut)) 

    await RisingEdge(dut.clock)
    await reset(dut)
    for _ in range(993):
        await RisingEdge(dut.clock)

    await FallingEdge(dut.clock)
    assert dut.counter1_counter.value == 0, "Counter 1 not incremented correctly. Possible system config issue"
