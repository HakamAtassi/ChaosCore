import sys
import random
import cocotb.triggers
import numpy as np
import cocotb
from cocotb.triggers import Timer
from cocotb.triggers import RisingEdge, Timer, ReadOnly, ReadWrite
from pathlib import Path

from cocotb_utils import *
from model_utils import *

from RSDut import *


@cocotb.test()
async def simple_reset(dut):
    random.seed(0x42)

    await cocotb.start(generateClock(dut)) 

    await reset(dut)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)
    await RisingEdge(dut.clock)


# Test allocation #

@cocotb.test()
async def allocate_1_RS_not_ready(dut):
    random.seed(0x42)
    await cocotb.start(generateClock(dut)) 
    await reset(dut)
    await RisingEdge(dut.clock)

    dut = RSDut(dut)

    dut.set_ports_ready()


    for i in range(20):

        dut.write_RS(RD_valid  =[1,0,0,0], 
                    RD         =[4,0,0,0], 
                    RS1_ready  =[0,0,0,0],  
                    RS1        =[4,0,0,0], 
                    RS2_ready  =[0,0,0,0], 
                    RS2        =[5,0,0,0], 
                    valid      =[1,0,0,0])

        await RisingEdge(dut.clock())
        dut.write_RS()
        await ReadOnly()
        RS = dut.get_RS()
        #dut.print_RS()

        assert RS[i]["valid"]     == 1

        #assert RS[i]["RS1_valid"] == 1
        assert RS[i]["RS1"]  == 4

        #assert RS[i]["RS2_valid"] == 1
        assert RS[i]["RS2"]  == 5

        await ReadWrite()

@cocotb.test()
async def allocate_2_RS_not_ready(dut):
    random.seed(0x42)
    await cocotb.start(generateClock(dut)) 
    await reset(dut)
    await RisingEdge(dut.clock)

    dut = RSDut(dut)

    dut.set_ports_ready()


    for i in range(0,10,2):

        dut.write_RS(RD_valid   =[1,1,0,0], 
                    RD         =[4,9,0,0], 
                    RS1_ready  =[0,0,0,0],  
                    RS1   =[4,9,0,0], 
                    RS2_ready  =[0,0,0,0], 
                    RS2   =[5,10,0,0], 
                    valid      =[1,1,0,0])

        await RisingEdge(dut.clock())
        await ReadOnly()
        RS = dut.get_RS()

        assert RS[i]["valid"]     == 1

        assert RS[i]["RS1"]  == 4

        assert RS[i]["RS2"]  == 5

        #
        assert RS[i+1]["valid"]     == 1

        assert RS[i+1]["RS1"]  == 9

        assert RS[i+1]["RS2"]  == 10

        await ReadWrite()

@cocotb.test()
async def allocate_3_RS_not_ready(dut):
    # TODO
    random.seed(0x42)
    await cocotb.start(generateClock(dut)) 
    await reset(dut)
    await RisingEdge(dut.clock)

@cocotb.test()
async def allocate_4_RS_not_ready(dut):
    # TODO
    random.seed(0x42)
    await cocotb.start(generateClock(dut)) 
    await reset(dut)
    await RisingEdge(dut.clock)


# Test Broadcast update #

@cocotb.test()
async def single_broadcast_good(dut):
    random.seed(0x42)
    await cocotb.start(generateClock(dut)) 
    await reset(dut)
    await RisingEdge(dut.clock)

    dut = RSDut(dut)

    dut.set_ports_ready()


    dut.write_RS(RD_valid  =[1,0,0,0], 
                RD         =[4,0,0,0], 
                RS1_ready  =[1,0,0,0],  
                RS1        =[4,0,0,0], 
                RS2_ready  =[0,0,0,0], 
                RS2        =[5,0,0,0], 
                valid      =[1,0,0,0])

    await RisingEdge(dut.clock())

    dut.write_RS(valid = [0,0,0,0])
    dut.broadcast(RD=[5,0,0,0], data=[0x42,0,0,0], valid=[1,0,0,0])

    await ReadOnly()

    #dut.print_RS()
    #dut.print_outputs()

    RS = dut.get_RS()
    assert RS[0]["valid"] == 1
    assert RS[0]["RS1_ready"] == 1

    RS = dut.get_RS()
    ports = dut.get_ports()

    dut.print_outputs()

    assert ports[0]["valid"] == 1
    

    await RisingEdge(dut.clock())
    await ReadOnly()

    RS = dut.get_RS()

    assert RS[0]["valid"] == 0
    assert RS[0]["RS1_ready"] == 0
    assert RS[0]["RS2_ready"] == 0

    

@cocotb.test()
async def single_broadcast_bad(dut):
    random.seed(0x42)
    await cocotb.start(generateClock(dut)) 
    await reset(dut)
    await RisingEdge(dut.clock)

    dut = RSDut(dut)

    dut.set_ports_ready()


    dut.write_RS(RD_valid  =[1,0,0,0], 
                RD         =[4,0,0,0], 
                RS1_ready  =[0,0,0,0],  
                RS1   =[4,0,0,0], 
                RS2_ready  =[0,0,0,0], 
                RS2   =[5,0,0,0], 
                valid      =[1,0,0,0])

    await RisingEdge(dut.clock())


    await ReadOnly()
    RS = dut.get_RS()

    assert RS[0]["valid"] == 1
    assert RS[0]["RS1_ready"] == 0
    assert RS[0]["RS2_ready"] == 0
    
    await ReadWrite()
    dut.broadcast(RD=[1,0,0,0], data=[0x42,0,0,0], valid=[1,0,0,0])

    await RisingEdge(dut.clock())
    await ReadOnly()

    RS = dut.get_RS()

    assert RS[0]["valid"] == 1
    assert RS[0]["RS1_ready"] == 0
    assert RS[0]["RS2_ready"] == 0
   
    await ReadWrite()
    dut.broadcast(RD=[7,0,0,0], data=[0x42,0,0,0], valid=[1,0,0,0])

    await ReadOnly()

    RS = dut.get_RS()

    assert RS[0]["valid"] == 1
    assert RS[0]["RS1_ready"] == 0
    assert RS[0]["RS2_ready"] == 0

    await RisingEdge(dut.clock())
    await ReadOnly()


#FIXME: what if an element is placed into the RS at the same time is receiving a broadcast from an FU

# Test Port Assignment #

@cocotb.test()
async def dispatch_uOp0(dut):
    random.seed(0x42)
    await cocotb.start(generateClock(dut)) 
    await reset(dut)
    await RisingEdge(dut.clock)

    dut = RSDut(dut)

    dut.set_ports_ready()


    dut.write_RS(RD_valid  =[1,0,0,0], 
                RD         =[4,0,0,0], 
                RS1_ready  =[1,0,0,0],  
                RS1   =[4,0,0,0], 
                RS2_ready  =[1,0,0,0], 
                RS2   =[5,0,0,0], 
                valid      =[1,0,0,0])

    await RisingEdge(dut.clock())

    await ReadOnly()
    RS = dut.get_RS()
    ports = dut.get_ports()


    assert RS[0]["valid"] == 1
    assert RS[0]["RS1_ready"] == 1
    assert RS[0]["RS2_ready"] == 1

    assert ports[0]["valid"] == 1


    await RisingEdge(dut.clock())
    await ReadOnly()
    RS = dut.get_RS()
    assert RS[0]["valid"] == 0


@cocotb.test()
async def dispatch_uOp1(dut):
    random.seed(0x42)
    await cocotb.start(generateClock(dut)) 
    await reset(dut)
    await RisingEdge(dut.clock)

    dut = RSDut(dut)

    dut.set_ports_ready()


    dut.write_RS(RD_valid  =[1,0,0,0], 
                RD         =[4,0,0,0], 
                RS1_ready  =[1,0,0,0],  
                RS1        =[4,0,0,0], 
                RS2_ready  =[1,0,0,0], 
                RS2        =[5,0,0,0], 
                portID     =[1,0,0,0], 
                valid      =[1,0,0,0])

    await RisingEdge(dut.clock())

    dut.write_RS(valid = [0,0,0,0])

    await ReadOnly()
    RS = dut.get_RS()
    ports = dut.get_ports()


    assert RS[0]["valid"] == 1
    assert RS[0]["RS1_ready"] == 1
    assert RS[0]["RS2_ready"] == 1


    assert ports[1]["valid"] == 1




    await RisingEdge(dut.clock())
    await ReadOnly()
    RS = dut.get_RS()
    #dut.print_RS()
    #dut.print_outputs()
    assert RS[0]["valid"] == 0

@cocotb.test()
async def dispatch_uOp0_uOp1(dut):
    random.seed(0x42)
    await cocotb.start(generateClock(dut)) 
    await reset(dut)
    await RisingEdge(dut.clock)

    dut = RSDut(dut)

    dut.set_ports_ready()


    dut.write_RS(RD_valid  =[1,1,0,0], 
                RD         =[4,14,0,0], 
                RS1_ready  =[1,1,0,0],  
                RS1        =[4,14,0,0], 
                RS2_ready  =[1,1,0,0], 
                RS2        =[5,15,0,0], 
                portID     =[1,0,0,0], 
                valid      =[1,1,0,0])

    await RisingEdge(dut.clock())

    await ReadOnly()
    RS = dut.get_RS()
    ports = dut.get_ports()


    assert RS[0]["valid"] == 1
    assert RS[0]["RS1_ready"] == 1
    assert RS[0]["RS2_ready"] == 1

    assert ports[0]["valid"]     == 1
    assert ports[0]["RS1"]  == 14
    assert ports[0]["RS2"]  == 15


    assert ports[1]["valid"]     == 1
    assert ports[1]["RS1"]  == 4
    assert ports[1]["RS2"]  == 5



    await RisingEdge(dut.clock())
    await ReadOnly()
    RS = dut.get_RS()
    assert RS[0]["valid"] == 0

@cocotb.test()
async def dispatch_uOp0_uOp0(dut):
    random.seed(0x42)
    await cocotb.start(generateClock(dut)) 
    await reset(dut)
    await RisingEdge(dut.clock)

    dut = RSDut(dut)

    dut.set_ports_ready()


    dut.write_RS(RD_valid  =[1,1,0,0], 
                RD         =[4,14,0,0], 
                RS1_ready  =[1,1,0,0],  
                RS1   =[4,14,0,0], 
                RS2_ready  =[1,1,0,0], 
                RS2   =[5,15,0,0], 
                portID        =[0,0,0,0], 
                valid      =[1,1,0,0])

    await RisingEdge(dut.clock())

    dut.write_RS(valid = [0,0,0,0])

    await ReadOnly()
    RS = dut.get_RS()
    ports = dut.get_ports()


    assert RS[0]["valid"] == 1
    assert RS[0]["RS1_ready"] == 1
    assert RS[0]["RS2_ready"] == 1

    assert RS[1]["valid"] == 1
    assert RS[1]["RS1_ready"] == 1
    assert RS[1]["RS2_ready"] == 1

    assert ports[0]["valid"]     == 1
    assert ports[0]["RS1"]  == 14
    assert ports[0]["RS2"]  == 15


    await RisingEdge(dut.clock())
    await ReadOnly()
    RS = dut.get_RS()
    assert RS[0]["valid"] == 1
    assert RS[1]["valid"] == 0


@cocotb.test()
async def dispatch_uOp1_uOp1(dut):
    random.seed(0x42)
    await cocotb.start(generateClock(dut)) 
    await reset(dut)
    await RisingEdge(dut.clock)

    dut = RSDut(dut)

    dut.set_ports_ready()


    dut.write_RS(RD_valid  =[1,1,0,0], 
                RD         =[4,14,0,0], 
                RS1_ready  =[1,1,0,0],  
                RS1   =[4,14,0,0], 
                RS2_ready  =[1,1,0,0], 
                RS2   =[5,15,0,0], 
                portID     =[1,1,0,0], 
                valid      =[1,1,0,0])

    await RisingEdge(dut.clock())

    dut.write_RS(valid      =[0,0,0,0])

    await ReadOnly()
    RS = dut.get_RS()
    ports = dut.get_ports()

    assert RS[0]["valid"] == 1
    assert RS[0]["RS1_ready"] == 1
    assert RS[0]["RS2_ready"] == 1

    assert RS[1]["valid"] == 1
    assert RS[1]["RS1_ready"] == 1
    assert RS[1]["RS2_ready"] == 1


    assert ports[1]["valid"]     == 1
    assert ports[1]["RD_valid"]  == 1
    assert ports[1]["RS1"]  == 14
    assert ports[1]["RS2"]  == 15


    await RisingEdge(dut.clock())
    await ReadOnly()

    RS = dut.get_RS()
    #dut.print_RS()
    #dut.print_outputs()
    assert RS[0]["valid"] == 1
    assert RS[0]["RD"] == 4
    assert RS[1]["valid"] == 0

@cocotb.test()
async def dispatch_uOp0_uOp1_uOp2_uOp3(dut):
    random.seed(0x42)
    await cocotb.start(generateClock(dut)) 
    await reset(dut)
    await RisingEdge(dut.clock)

    dut = RSDut(dut)

    dut.set_ports_ready()


    dut.write_RS(RD_valid  =[1,1,1,1], 
                RD         =[4,14,24,34], 
                RS1_ready  =[1,1,1,1],  
                RS1   =[4,14,24,34], 
                RS2_ready  =[1,1,1,1], 
                RS2   =[5,15,25,35], 
                portID        =[0,1,2,3], 
                valid      =[1,1,1,1])

    await RisingEdge(dut.clock())

    await ReadOnly()
    RS = dut.get_RS()
    ports = dut.get_ports()



    assert RS[0]["valid"] == 1
    assert RS[0]["RS1_ready"] == 1
    assert RS[0]["RS2_ready"] == 1

    assert RS[1]["valid"] == 1
    assert RS[1]["RS1_ready"] == 1
    assert RS[1]["RS2_ready"] == 1

    assert RS[2]["valid"] == 1
    assert RS[2]["RS1_ready"] == 1
    assert RS[2]["RS2_ready"] == 1

    assert RS[3]["valid"] == 1
    assert RS[3]["RS1_ready"] == 1
    assert RS[3]["RS2_ready"] == 1


    assert ports[0]["valid"]     == 1
    assert ports[0]["RD_valid"]  == 1
    assert ports[0]["RS1"]  == 4
    assert ports[0]["RS2"]  == 5

    assert ports[1]["valid"]     == 1
    assert ports[1]["RD_valid"]  == 1
    assert ports[1]["RS1"]  == 14
    assert ports[1]["RS2"]  == 15

    assert ports[2]["valid"]     == 1
    assert ports[2]["RD_valid"]  == 1
    assert ports[2]["RS1"]  == 24
    assert ports[2]["RS2"]  == 25

    assert ports[3]["valid"]     == 1
    assert ports[3]["RD_valid"]  == 1
    assert ports[3]["RS1"]  == 34
    assert ports[3]["RS2"]  == 35

    await RisingEdge(dut.clock())
    await ReadOnly()
    RS = dut.get_RS()
    assert RS[0]["valid"] == 0
    assert RS[1]["valid"] == 0

