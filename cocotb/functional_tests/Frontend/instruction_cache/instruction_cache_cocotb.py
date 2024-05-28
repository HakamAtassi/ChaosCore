import sys
import random
import numpy as np
from cocotb.clock import Clock
import cocotb
from cocotb.triggers import RisingEdge, FallingEdge, Timer, ReadOnly, ReadWrite
from pathlib import Path

from cocotb_utils import *
from model_utils import *
from instruction_cache_dut import *


# Test general Read/Write abilities

@cocotb.test()
async def reset(dut):

    await cocotb.start(generateClock(dut)) 

    dut = instruction_cache_dut(dut, sets=64, ways=2)  # wrap dut with helper class
    await dut.reset()   # reset module

    await RisingEdge(dut.clock())

@cocotb.test()
async def write_read_DRAM_ready(dut):
    """CPU requests a read from the cache while the cache and DRAM are both ready"""

    await cocotb.start(generateClock(dut)) 

    dut = instruction_cache_dut(dut, sets=64, ways=2)  # wrap dut with helper class
    await dut.reset()   # reset module
    await RisingEdge(dut.clock())

    dut.set_dram_ready(1)
    dut.set_cache_ready(1)
    await RisingEdge(dut.clock())

    dut.write_cache_CPU(addr=0xdead, valid=1)
    await RisingEdge(dut.clock())
    dut.write_cache_CPU()
    await ReadOnly()
    outputs = dut.get_output()
    assert outputs["DRAM_request_valid"] == 1       # Cache requesting from DRAM

    await RisingEdge(dut.clock())                   
    dut.write_cache_DRAM(0x42, 1)                   # DRAM returning response
    await RisingEdge(dut.clock())
    dut.write_cache_DRAM()
    dut.write_cache_CPU(addr=0xdead, valid=1)       # Request same data

    await RisingEdge(dut.clock())
    dut.write_cache_CPU()
    await ReadOnly()

    outputs = dut.get_output()
    assert outputs["DRAM_request_valid"] == 0       # should not be requesting dram
    assert outputs["valid"] == 1                    # output should be valid


@cocotb.test()
async def write_read_DRAM_not_ready(dut):
    """CPU requests a read from the cache while the cache is ready but the DRAM is not for some cycles"""
    await cocotb.start(generateClock(dut)) 

    dut = instruction_cache_dut(dut, sets=64, ways=2)  # wrap dut with helper class
    await dut.reset()   # reset module
    await RisingEdge(dut.clock())

    dut.set_dram_ready(0)                           # DRAM not ready
    dut.set_cache_ready(1)
    await RisingEdge(dut.clock())

    dut.write_cache_CPU(addr=0xdead, valid=1)
    await RisingEdge(dut.clock())
    dut.write_cache_CPU()


    await ReadOnly()

    outputs = dut.get_output()
    assert outputs["DRAM_request_valid"] == 1       # Cache requesting from DRAM

    await RisingEdge(dut.clock()); await ReadOnly(); outputs = dut.get_output()
    assert outputs["DRAM_request_valid"] == 1       # Cache requesting from DRAM
    await RisingEdge(dut.clock()); await ReadOnly(); outputs = dut.get_output()
    assert outputs["DRAM_request_valid"] == 1       # Cache requesting from DRAM
    await RisingEdge(dut.clock()); await ReadOnly(); outputs = dut.get_output()
    assert outputs["DRAM_request_valid"] == 1       # Cache requesting from DRAM

    await RisingEdge(dut.clock())
    dut.set_dram_ready(1)                           # DRAM now ready

    await RisingEdge(dut.clock()); await ReadOnly(); outputs = dut.get_output()
    assert outputs["DRAM_request_valid"] == 0, "TESTADSF"       # Cache DRAM request complete




    await RisingEdge(dut.clock())                   
    dut.write_cache_DRAM(0x42, 1)                   # DRAM returning response
    await RisingEdge(dut.clock())
    dut.write_cache_DRAM()
    dut.write_cache_CPU(addr=0xdead, valid=1)       # Request same data

    await RisingEdge(dut.clock())
    dut.write_cache_CPU()
    await ReadOnly()

    outputs = dut.get_output()
    assert outputs["DRAM_request_valid"] == 0       # should not be requesting dram
    assert outputs["valid"] == 1                    # output should be valid



@cocotb.test()
async def read_all_alignments(dut):
    """First allocates a line, then tests reads at all possible indices of that line."""

    await cocotb.start(generateClock(dut)) 

    dut = instruction_cache_dut(dut, sets=64, ways=2)  # wrap dut with helper class
    await dut.reset()   # reset module
    await RisingEdge(dut.clock())

    dut.set_dram_ready(1)
    dut.set_cache_ready(1)
    await RisingEdge(dut.clock())

    dut.write_cache_CPU(addr=0xdea0, valid=1)
    await RisingEdge(dut.clock())
    dut.write_cache_CPU()

    await RisingEdge(dut.clock())

    dut.write_cache_DRAM(0x0000_0049_0000_0048_0000_0047_0000_0046_0000_0045_0000_0044_0000_0043_0000_0042, 1)                   # DRAM returning response
    await RisingEdge(dut.clock())
    dut.write_cache_DRAM()
    dut.write_cache_CPU(addr=0xdea0, valid=1)       # Request same data
    await RisingEdge(dut.clock())
    dut.write_cache_CPU()
    await ReadOnly()

    outputs = dut.get_output()
    assert outputs["DRAM_request_valid"] == 0       # should not be requesting dram
    assert outputs["valid"] == 1                    # output should be valid

    await RisingEdge(dut.clock());

    # Read first word
    dut.write_cache_CPU(addr=0xdea0, valid=1); await RisingEdge(dut.clock()); dut.write_cache_CPU();
    await ReadOnly()

    assert dut.get_output()["instruction_valid"][0] == 1
    assert dut.get_output()["instruction"][0] == 0x42


    assert dut.get_output()["instruction_valid"][1] == 1
    assert dut.get_output()["instruction"][1] == 0x43

    assert dut.get_output()["instruction_valid"][2] == 1
    assert dut.get_output()["instruction"][2] == 0x44

    assert dut.get_output()["instruction_valid"][3] == 1
    assert dut.get_output()["instruction"][3] == 0x45

    await RisingEdge(dut.clock());

    # Read second word
    dut.write_cache_CPU(addr=0xdea4, valid=1); await RisingEdge(dut.clock()); dut.write_cache_CPU();
    await ReadOnly()

    assert dut.get_output()["instruction_valid"][0] == 0
    assert dut.get_output()["instruction"][0] == 0x42


    assert dut.get_output()["instruction_valid"][1] == 1
    assert dut.get_output()["instruction"][1] == 0x43

    assert dut.get_output()["instruction_valid"][2] == 1
    assert dut.get_output()["instruction"][2] == 0x44

    assert dut.get_output()["instruction_valid"][3] == 1
    assert dut.get_output()["instruction"][3] == 0x45

    await RisingEdge(dut.clock());

    # Read third word
    dut.write_cache_CPU(addr=0xdea8, valid=1); await RisingEdge(dut.clock()); dut.write_cache_CPU();
    await ReadOnly()

    assert dut.get_output()["instruction_valid"][0] == 0
    assert dut.get_output()["instruction"][0] == 0x42


    assert dut.get_output()["instruction_valid"][1] == 0
    assert dut.get_output()["instruction"][1] == 0x43

    assert dut.get_output()["instruction_valid"][2] == 1
    assert dut.get_output()["instruction"][2] == 0x44

    assert dut.get_output()["instruction_valid"][3] == 1
    assert dut.get_output()["instruction"][3] == 0x45


    await RisingEdge(dut.clock());

    # Read fourth word
    dut.write_cache_CPU(addr=0xdeac, valid=1); await RisingEdge(dut.clock()); dut.write_cache_CPU();
    await ReadOnly()

    assert dut.get_output()["instruction_valid"][0] == 0
    assert dut.get_output()["instruction"][0] == 0x42

    assert dut.get_output()["instruction_valid"][1] == 0
    assert dut.get_output()["instruction"][1] == 0x43

    assert dut.get_output()["instruction_valid"][2] == 0
    assert dut.get_output()["instruction"][2] == 0x44

    assert dut.get_output()["instruction_valid"][3] == 1
    assert dut.get_output()["instruction"][3] == 0x45

    await RisingEdge(dut.clock());

    # Read fifth word
    dut.write_cache_CPU(addr=0xdeb0, valid=1); await RisingEdge(dut.clock()); dut.write_cache_CPU();
    await ReadOnly()

    assert dut.get_output()["instruction_valid"][0] == 1
    assert dut.get_output()["instruction"][0] == 0x46

    assert dut.get_output()["instruction_valid"][1] == 1
    assert dut.get_output()["instruction"][1] == 0x47

    assert dut.get_output()["instruction_valid"][2] == 1
    assert dut.get_output()["instruction"][2] == 0x48

    assert dut.get_output()["instruction_valid"][3] == 1
    assert dut.get_output()["instruction"][3] == 0x49

    await RisingEdge(dut.clock());

    # Read fifth word
    dut.write_cache_CPU(addr=0xdeb4, valid=1); await RisingEdge(dut.clock()); dut.write_cache_CPU();
    await ReadOnly()

    assert dut.get_output()["instruction_valid"][0] == 0
    assert dut.get_output()["instruction"][0] == 0x46

    assert dut.get_output()["instruction_valid"][1] == 1
    assert dut.get_output()["instruction"][1] == 0x47

    assert dut.get_output()["instruction_valid"][2] == 1
    assert dut.get_output()["instruction"][2] == 0x48

    assert dut.get_output()["instruction_valid"][3] == 1
    assert dut.get_output()["instruction"][3] == 0x49

    await RisingEdge(dut.clock());

    # Read fifth word
    dut.write_cache_CPU(addr=0xdeb8, valid=1); await RisingEdge(dut.clock()); dut.write_cache_CPU();
    await ReadOnly()

    assert dut.get_output()["instruction_valid"][0] == 0
    assert dut.get_output()["instruction"][0] == 0x46

    assert dut.get_output()["instruction_valid"][1] == 0
    assert dut.get_output()["instruction"][1] == 0x47

    assert dut.get_output()["instruction_valid"][2] == 1
    assert dut.get_output()["instruction"][2] == 0x48

    assert dut.get_output()["instruction_valid"][3] == 1
    assert dut.get_output()["instruction"][3] == 0x49

    await RisingEdge(dut.clock());

    # Read fifth word
    dut.write_cache_CPU(addr=0xdebc, valid=1); await RisingEdge(dut.clock()); dut.write_cache_CPU();
    await ReadOnly()

    assert dut.get_output()["instruction_valid"][0] == 0
    assert dut.get_output()["instruction"][0] == 0x46

    assert dut.get_output()["instruction_valid"][1] == 0
    assert dut.get_output()["instruction"][1] == 0x47

    assert dut.get_output()["instruction_valid"][2] == 0
    assert dut.get_output()["instruction"][2] == 0x48

    assert dut.get_output()["instruction_valid"][3] == 1
    assert dut.get_output()["instruction"][3] == 0x49


@cocotb.test()
async def write_read_read(dut):
    """CPU requets a read from the cache while the cache and DRAM are both ready. First read should miss. Second should return 1CC later."""
    await cocotb.start(generateClock(dut)) 

    dut = instruction_cache_dut(dut, sets=64, ways=2)  # wrap dut with helper class
    await dut.reset()   # reset module
    await RisingEdge(dut.clock())

    dut.set_dram_ready(1)
    dut.set_cache_ready(1)
    await RisingEdge(dut.clock())

    dut.write_cache_CPU(addr=0xdea0, valid=1)
    await RisingEdge(dut.clock())
    dut.write_cache_CPU()

    await RisingEdge(dut.clock())

    dut.write_cache_DRAM(0x0000_0045_0000_0044_0000_0043_0000_0042, 1)                   # DRAM returning response
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    await ReadOnly()

    assert dut.get_output()["instruction_valid"][0] == 1
    assert dut.get_output()["instruction"][0] == 0x42

    await ReadWrite()

    dut.write_cache_DRAM()
    dut.write_cache_CPU(addr=0xdea0, valid=1)       # Request same data
    await RisingEdge(dut.clock())
    dut.write_cache_CPU()
    await ReadOnly()

    outputs = dut.get_output()
    assert outputs["DRAM_request_valid"] == 0       # should not be requesting dram
    assert outputs["valid"] == 1                    # output should be valid

    await RisingEdge(dut.clock());

    # Read first word
    dut.write_cache_CPU(addr=0xdea0, valid=1); await RisingEdge(dut.clock()); dut.write_cache_CPU();
    await ReadOnly()

    assert dut.get_output()["instruction_valid"][0] == 1
    assert dut.get_output()["instruction"][0] == 0x42



# Test LRU
#generateAddr(tag, set, byteOffset, sets, blockSize)
@cocotb.test()
async def write_read_read(dut):
    """CPU requets a read from the cache while the cache and DRAM are both ready. First read should miss. Second should return 1CC later."""
    await cocotb.start(generateClock(dut)) 

    dut = instruction_cache_dut(dut, sets=64, ways=2)  # wrap dut with helper class
    await dut.reset()   # reset module
    await RisingEdge(dut.clock())

    dut.set_dram_ready(1)
    dut.set_cache_ready(1)
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())

    
    addr0=generateAddr(tag=0x42, set=0, byteOffset=0, sets=64, blockSize=32)
    addr1=generateAddr(tag=0x43, set=0, byteOffset=0, sets=64, blockSize=32)
    addr2=generateAddr(tag=0x44, set=0, byteOffset=0, sets=64, blockSize=32)

    ####################################
    # Load into cache the first address
    dut.write_cache_CPU(addr=addr0, valid=1)
    await RisingEdge(dut.clock())
    dut.write_cache_CPU()
    await RisingEdge(dut.clock())
    dut.write_cache_DRAM(0xdead, 1)                   # DRAM returning response
    await RisingEdge(dut.clock())
    dut.write_cache_DRAM()
    await RisingEdge(dut.clock())
    ###################################
    # Test read
    dut.write_cache_CPU(addr=addr0, valid=1)
    await RisingEdge(dut.clock())
    dut.write_cache_CPU()
    await ReadOnly()
    assert dut.get_output()["instruction_valid"][0] == 1
    assert dut.get_output()["instruction"][0] == 0xdead
    #####################################
    await RisingEdge(dut.clock())
    await RisingEdge(dut.clock())
    ####################################
    # Load into cache the second address
    dut.write_cache_CPU(addr=addr1, valid=1)
    await RisingEdge(dut.clock())
    dut.write_cache_CPU()
    await RisingEdge(dut.clock())
    dut.write_cache_DRAM(0xc0de, 1)                   # DRAM returning response
    await RisingEdge(dut.clock())
    dut.write_cache_DRAM()
    await RisingEdge(dut.clock())
    ###################################
    # Test read
    dut.write_cache_CPU(addr=addr1, valid=1)
    await RisingEdge(dut.clock())
    dut.write_cache_CPU()
    await ReadOnly()
    assert dut.get_output()["instruction_valid"][0] == 1
    assert dut.get_output()["instruction"][0] == 0xc0de
    #####################################
    await RisingEdge(dut.clock())
    #####################################
    # Test both reads
    dut.write_cache_CPU(addr=addr0, valid=1)
    await RisingEdge(dut.clock())
    dut.write_cache_CPU()
    await ReadOnly()
    assert dut.get_output()["instruction_valid"][0] == 1
    assert dut.get_output()["instruction"][0] == 0xdead
    #   
    await RisingEdge(dut.clock())
    #
    dut.write_cache_CPU(addr=addr1, valid=1)
    await RisingEdge(dut.clock())
    dut.write_cache_CPU()
    await ReadOnly()
    assert dut.get_output()["instruction_valid"][0] == 1
    assert dut.get_output()["instruction"][0] == 0xc0de
    #####################################
    await RisingEdge(dut.clock())
    #####################################
    # Load into cache the third address
    dut.write_cache_CPU(addr=addr2, valid=1)
    await RisingEdge(dut.clock())
    dut.write_cache_CPU()
    await RisingEdge(dut.clock())
    dut.write_cache_DRAM(0xbeef, 1)                   # DRAM returning response
    await RisingEdge(dut.clock())
    dut.write_cache_DRAM()
    await RisingEdge(dut.clock())
    #####################################
    # Test both reads
    dut.write_cache_CPU(addr=addr1, valid=1)
    await RisingEdge(dut.clock())
    dut.write_cache_CPU()
    await ReadOnly()
    assert dut.get_output()["instruction_valid"][0] == 1
    assert dut.get_output()["instruction"][0] == 0xc0de
    #   
    await RisingEdge(dut.clock())
    #
    dut.write_cache_CPU(addr=addr2, valid=1)
    await RisingEdge(dut.clock())
    dut.write_cache_CPU()
    await ReadOnly()
    assert dut.get_output()["instruction_valid"][0] == 1
    assert dut.get_output()["instruction"][0] == 0xbeef


# Test Read/Write and packet alignment


# Test Kill 


# Test Conflicts/size/eviction