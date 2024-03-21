import cocotb
from cocotb.triggers import FallingEdge
from cocotb.queue import QueueEmpty, Queue
import enum
import logging
import sys

from pyuvm import utility_classes

logging.basicConfig(level=logging.NOTSET)
logger = logging.getLogger()
logger.setLevel(logging.DEBUG)


sys.path.append('model')
from model.utils import *
from model.cacheMem import *
sys.path.append('..')

@enum.unique
class Ops(enum.IntEnum):
    """Legal ops for the cache"""
    LB  = 0
    LHW = 1
    LW  = 2

    NOP = 3

    SB  = 4
    SHW = 5
    SW  = 6

    ALLOCATE = 7

    FW = 8



def get_int(signal):
    try:
        sig = int(signal.value)
    except ValueError:
        sig = 0
    return sig


class cacheBFM(metaclass=utility_classes.Singleton):
    def __init__(self):
        self.dut = cocotb.top
        self.driver_queue = Queue(maxsize=1)
        self.cmd_mon_queue = Queue(maxsize=0)
        self.result_mon_queue = Queue(maxsize=0)

    async def send_op(self, addr, data, cache_line, cmd, valid, ready):
        command_tuple = (addr, data, cache_line, cmd, valid, ready)
        await self.driver_queue.put(command_tuple)

    async def get_cmd(self):
        cmd = await self.cmd_mon_queue.get()
        return cmd

    async def get_result(self):
        result = await self.result_mon_queue.get()
        return result

    async def reset(self):
        await FallingEdge(self.dut.clock)
        self.dut.reset.value = 1
        self.dut.io_controller_addr.value = 0
        self.dut.io_controller_data.value = 0
        self.dut.io_controller_cache_line.value = 0
        self.dut.io_controller_cmd.value = 0
        self.dut.io_controller_valid.value = 0
        self.dut.io_cache_ready.value = 0
        await FallingEdge(self.dut.clock)
        self.dut.reset.value = 0
        await FallingEdge(self.dut.clock)

    async def driver_bfm(self):
        self.dut.io_controller_addr.value = 0
        self.dut.io_controller_data.value = 0
        self.dut.io_controller_cache_line.value = 0
        self.dut.io_controller_cmd.value = 0
        self.dut.io_controller_valid.value = 0
        self.dut.io_cache_ready.value = 0

        while True:
            await FallingEdge(self.dut.clock)
            valid = get_int(self.dut.io_controller_valid)
            if valid == 0:
                try:
                    (addr, data, cache_line, cmd, valid, ready) = self.driver_queue.get_nowait()
                    self.dut.io_controller_addr.value = addr
                    self.dut.io_controller_data.value = data
                    self.dut.io_controller_cache_line.value = cache_line
                    self.dut.io_controller_cmd.value = cmd
                    self.dut.io_controller_valid.value = 1
                    await FallingEdge(self.dut.clock)
                    self.dut.io_controller_valid.value = 0
                except QueueEmpty:
                    pass

    async def cmd_mon_bfm(self):
        while True:
            await FallingEdge(self.dut.clock)
            valid = get_int(self.dut.io_controller_valid)
            if valid == 1:
                cmd_tuple = (get_int(self.dut.io_controller_addr.value),
                             get_int(self.dut.io_controller_data.value),
                             get_int(self.dut.io_controller_cache_line.value),
                             get_int(self.dut.io_controller_cmd.value),
                             get_int(self.dut.io_controller_valid.value),
                             get_int(self.dut.io_controller_ready.value),
                             
                             )
                self.cmd_mon_queue.put_nowait(cmd_tuple)

    async def result_mon_bfm(self):
        while True:
            await FallingEdge(self.dut.clock)
            valid = get_int(self.dut.io_cache_valid)
            if valid == 1:
                result_tuple = (get_int(self.dut.io_cache_addr.value),
                                get_int(self.dut.io_cache_dout.value),
                                get_int(self.dut.io_cache_evict_line.value),
                                get_int(self.dut.io_cache_evict_line.value),
                                get_int(self.dut.io_cache_hit.value)
                                )
                self.result_mon_queue.put_nowait(result_tuple)

    def start_bfm(self):
        cocotb.start_soon(self.driver_bfm())
        cocotb.start_soon(self.cmd_mon_bfm())
        cocotb.start_soon(self.result_mon_bfm())


def copyDataMemory(dut, model,blockSize=32, sets=64, ways=4):
    # copies memory from model to dut

    # init data memory
    for i in range(blockSize):
        for way in range(ways):
            for set in range(sets):
                addr = way*sets + set
                getattr(dut, f"data_memory_{blockSize-1-i}").ram_ext.Memory[addr].value = getByte(model.dataMemory[addr], i)

def copyTagMemory(dut, model,blockSize=32, sets=64, ways=4):
    # copies memory from model to dut
    # init data memory
    for i in range(blockSize):
        for way in range(ways):
            for set in range(sets):
                addr = way*sets + set
                dut.tag_memory.ram_ext.Memory[set].value = model.tagMemory[set]
                #getattr(dut, f"data_memory_{blockSize-1-i}").ram_ext.Memory[addr].value = getByte(model.dataMemory[addr], i)

def copyDirtyMemory(dut, model,blockSize=32, sets=64, ways=4):
    # copies memory from model to dut
    # init data memory
    for i in range(blockSize):
        for way in range(ways):
            for set in range(sets):
                addr = way*sets + set
                dut.dirty_memory.mem_ext.Memory[set].value = model.dirtyMemory[set]

def copyPLRUMemory(dut, model,blockSize=32, sets=64, ways=4):
    # copies memory from model to dut
    # init data memory
    for i in range(blockSize):
        for way in range(ways):
            for set in range(sets):
                addr = way*sets + set
                dut.PLRU_memory.mem_ext.Memory[set].value = model.PLRUMemory[set]

def printDmem(dut,lineSizeBytes, ways, sets):
    print("DUT DATA MEM")
    #print(f"## ##: ", end="")
    #for byte in range(lineSizeBytes):
        #print(f"{lineSizeBytes-1-byte:0{2}} ", end="")
    #print("<= byte")
    #for way in range(ways):
        #for set in range(sets):
            #print(f"{way:02} {set:02}: ", end="")
            #for i in range(lineSizeBytes):
                #addr = way*sets + set
                #memoryByte = int(getattr(dut, f"data_memory_{lineSizeBytes-1-i}").ram_ext.Memory[addr].value)
                #print(f"{memoryByte:0{2}x} ",end="")
            #print("")

    for way in range(ways):
        for set in range(sets):
            print(f"{way:02} {set:02}: ", end="")
            line = 0
            for i in range(lineSizeBytes):
                addr = way*sets + set
                memoryByte = int(getattr(dut, f"data_memory_{i}").ram_ext.Memory[addr].value)
                line =  ((line<<(8)) | (memoryByte))
            print(f"{line:064x}")

def printTags(dut,lineSizeBytes, ways, sets):
    tagLine=0
    tagSize = int(np.ceil(32 - np.log2(lineSizeBytes) - np.log2(sets)))
    print("DUT TAG MEM")
    for set in range(sets):
        print(f"{set:02}: ",end="")
        data = int(dut.tag_memory.ram_ext.Memory[set].value)
        tag0 = data & 0x1F_FFFF
        tag1 = (data>>21) & 0x1F_FFFF
        tag2 = (data>>42) & 0x1F_FFFF
        tag3 = (data>>63) & 0x1F_FFFF
        #print(f"{set:02}: {hex(tag3)} {hex(tag2)} {hex(tag1)} {hex(tag0)}")
        print(f"{hex(data)}")

def printPLRU(dut,lineSizeBytes, ways, sets):
    tagLine=0
    tagSize = int(np.ceil(32 - np.log2(lineSizeBytes) - np.log2(sets)))
    print("DUT PLRU MEM")
    for set in range(sets):
        print(f"{set:02}: ",end="")
        data = int(dut.PLRU_memory.mem_ext.Memory[set].value)
        print(f"{hex(data)}")

def printDirty(dut,lineSizeBytes, ways, sets):
    tagLine=0
    tagSize = int(np.ceil(32 - np.log2(lineSizeBytes) - np.log2(sets)))
    print("DUT Dirty MEM")
    for set in range(sets):
        print(f"{set:02}: ",end="")
        data = int(dut.dirty_memory.mem_ext.Memory[set].value)
        print(f"{hex(data)}")