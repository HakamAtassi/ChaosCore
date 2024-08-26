import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly, ReadWrite, Timer
from pathlib import Path
import os

from cocotb_utils import *

from model_utils import *

from RS_TB import *



@cocotb.test()
async def test_fuzz(dut):
    # Set seed
    random.seed(0x42)

    pass

 #   # Start lock
    await cocotb.start(generateClock(dut))

    TB = RS_TB(dut)

    ## Bring up TB
    await TB.reset()     # Reset

    await TB.clock()


    for _ in range(10000):
        await TB.update()


    #for _ in range(30):
        #await TB.post_simulation()

    #print(TB.driver.accepted_instructions_hash_map)

    

