import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path
import os

from cocotb_utils import *
from ChaosCore import ChaosCore_dut
from SimpleDRAM import *
from ChaosCore_TB import *


@cocotb.test()
async def test_increment(dut):

    await cocotb.start(generateClock(dut))

    base_dir = os.path.dirname(__file__)
    bin = "../../binaries/bin/hello_world.bin"
    bin = os.path.join(base_dir, bin)

    imem = SimpleDRAM(bin=bin)
    dmem = SimpleDRAM()

    # wrap dut with helper class
    dut = ChaosCore_dut(dut, imem=imem, dmem=dmem)

    ChaosCore_tb = ChaosCore_TB(dut)

    dut.write_dmem_request_ready(1)
    dut.write_imem_request_ready(1)


    await ChaosCore_tb.reset()

    #ChaosCore_tb.PC_gen_start()
    #ChaosCore_tb.predecoder_start()
    #ChaosCore_tb.fetch_packet_decoder_start()



    for _ in range(1000):
        await ChaosCore_tb.update()

    #ChaosCore_tb.PC_gen_stop()
    #ChaosCore_tb.predecoder_stop()
    #ChaosCore_tb.fetch_packet_decoder_stop()

    assert False