import sys
import random
import numpy as np
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer
from pathlib import Path

from cocotb_utils import *
from model_utils import *
from BTBDut import *
from HashBTB import *

@cocotb.test()
async def simple_miss_commit_hit(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)

    # extend dut
    dut = BTBDut(dut)
    model = HashBTB(entries=4096)

    dut.predict(address=0xdeadbeef, valid=1)
    await FallingEdge(dut.clock())
    dut.predict(address=0xdeadbeef, valid=0)

    assert dut.is_output_valid() == 1, "Output should be valid"
    assert dut.get_output() == model.predict(address=0xdeadbeef), "Dut and Model diverge"


    dut.commit(address=0xdeadbeef, target=0xdeadc0de, type=0b11, br_mask=0b0001, valid=1)
    await FallingEdge(dut.clock())
    dut.commit(address=0x0, target=0x0, type=0b11, br_mask=0b0001, valid=0)

    model.commit(address=0xdeadbeef, target=0xdeadc0de, type=0b11, br_mask=0b0001)


    dut.predict(address=0xdeadbeef, valid=1)
    await FallingEdge(dut.clock())
    dut.predict(address=0xdeadbeef, valid=0)

    assert dut.get_output() == model.predict(address=0xdeadbeef), "Dut and Model diverge"


    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())
    await FallingEdge(dut.clock())


@cocotb.test()
async def test_miss_hit_all_addresses(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)
    await FallingEdge(dut.clock)

    # extend dut
    dut = BTBDut(dut)
    model = HashBTB(entries=4096)


    for i in range(4096):
        address = random.randint(0,(1<<16) - 1)
        address = (address<<16) | (i<<4)

        target_address = random.randint(0,  (1<<32) - 1)

        dut.predict(address=address, valid=1)
        await FallingEdge(dut.clock())
        dut.predict(address=address, valid=0)

        assert dut.is_output_valid() == 1, "Output should be valid"
        if(dut.get_output()[0]):
            assert dut.get_output() == model.predict(address=address), "Dut and Model diverge"

        model_state = model.get_target_state()
        dut_state = dut.get_target_state()

        print(f"test {i}")
        assert model_state == dut_state, "target state diverge"

        dut.commit(address=address, target=target_address, type=0b11, br_mask=0b0001, valid=1)
        await FallingEdge(dut.clock())
        dut.commit(address=0, target=0, type=0b11, br_mask=0b0001, valid=0)

        model.commit(address=address, target=target_address, type=0b11, br_mask=0b0001)


        dut.predict(address=address, valid=1)
        await FallingEdge(dut.clock())
        dut.predict(address=address, valid=0)

        assert dut.get_output() == model.predict(address=address), "Dut and Model diverge"


        await FallingEdge(dut.clock())
        await FallingEdge(dut.clock())
        await FallingEdge(dut.clock())
        await FallingEdge(dut.clock())

