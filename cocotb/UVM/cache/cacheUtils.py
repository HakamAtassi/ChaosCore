import cocotb
from cocotb.triggers import FallingEdge
from cocotb.queue import QueueEmpty, Queue
import enum
import logging

from pyuvm import utility_classes

logging.basicConfig(level=logging.NOTSET)
logger = logging.getLogger()
logger.setLevel(logging.DEBUG)

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