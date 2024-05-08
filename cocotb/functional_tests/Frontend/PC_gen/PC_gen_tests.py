import sys
import random
import numpy as np
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, FallingEdge, Timer
from pathlib import Path

from InstructionCache import *
from SimpleDRAM import *

from cocotb_utils import *      # import verif utils
from model_utils import *
from PCGenDut import *
from Channels import *

SETS = 64
WAYS = 2
BLOCKSIZE = 32
FETCHWIDTH = 4


@cocotb.test()
async def instruction_cache_kill_miss_test(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    dut = PCGenDut(dut)

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())


    commit_request = Commit(address = 0xdeadbeef,
                             GHR=0xdead,
                             target=0xdeadbeef,
                             br_type=0b11,
                             br_mask=0b1111,
                             T_NT=0b1,
                             misprediction=1,
                             misprediction_PC=0x4,
                             TOS=0,
                             NEXT=0,
                             valid=1
                             )
    prediction_request = Prediction(BTB_resp=BTB_resp.null(), PHT_T_NT=0, GHR=0, valid=0)

    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    dut.commit(commit=commit_request)
    await RisingEdge(dut.clock())
    dut.commit(commit=Commit.null())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())