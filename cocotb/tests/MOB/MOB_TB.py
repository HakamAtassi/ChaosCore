
from cocotbext.axi import AxiBus, AxiRam
import cocotb
from L1_caches import data_cache_dut
from cocotbext.axi import AxiBus, AxiMaster
from cocotbext.axi import AxiBus, AxiSlave, MemoryRegion
from cocotbext.axi import AxiBus, AxiRam
from cocotb.triggers import RisingEdge, ReadOnly
from enum import Enum
from MOB import MOB_dut
import random

from model_utils import *
from MOB import *

from drivers.drivers import *


from models.memory import memory_model
from drivers.scoreboard import *


class MOB_TB:
    def __init__(self, dut, memory_capacity):
        # Top level Module #
        self.MOB = MOB_dut(dut=dut)

        # For now, use 256MB of random data
        self.memory_capacity = memory_capacity

        random_bytes = bytearray(random.getrandbits(8) for _ in range(self.memory_capacity))
        self.mem = bytearray(random_bytes)


        # Generate pool memory addresses
        address_pool = [random.getrandbits(5) * 4 for _ in range(100)]

        # generate pool of memory operations
        
        memory_operations = []
        for i in range(10000):
            fetch_packet = []
            for i in range(4):
                fetch_packet.append(generate_load_store(address_pool))
            memory_operations.append(fetch_packet)

        # construct drivers (reserve/AGU) port       
        self.drivers = MOB_driver(dut, memory_operations)

        # construct memory model
        self.memory = memory_model(dut, self.mem)

        self.scoreboard = MOB_scoreboard(dut, self.mem, memory_operations)





    #################
    # RESET & CLOCK #
    #################

    async def reset(self):
        await self.MOB.reset()

    async def clock(self):
        await self.MOB.clock()

    ###########
    # RESERVE #
    ###########

    async def write_reserve(self, reserve):
        self.MOB.write_reserve(reserve)
        await self.clock()
        reserve = [{} for _ in range(4)]

        self.MOB.write_reserve([{
                "valid": 0,
                "bits": {
                    "ready_bits_RS1_ready": 0,
                    "ready_bits_RS2_ready": 0,
                    "RDold": 0,
                    "RD": 0,
                    "RD_valid": 0,
                    "RS1": 0,
                    "RS1_valid": 0,
                    "RS2": 0,
                    "RS2_valid": 0,
                    "IMM": 0,
                    "FUNCT3": 0,
                    "packet_index": 0,
                    "ROB_index": 0,
                    "MOB_index": 0,
                    "FTQ_index": 0,
                    "instructionType": 0,
                    "portID": 0,
                    "RS_type": 0,
                    "needs_ALU": 0,
                    "needs_branch_unit": 0,
                    "needs_CSRs": 0,
                    "SUBTRACT": 0,
                    "MULTIPLY": 0,
                    "IS_IMM": 0,
                    "memory_type": 0,
                    "access_width": 0,
                }
            } for _ in range(4)])

    async def write_AGU_output(self, AGU_output):
        self.MOB.write_AGU_output(AGU_output)
        await self.clock()
        self.MOB.write_AGU_output({
        "valid": 0,
        "bits": {
            "RD": 0,
            "RD_data": 0,
            "RD_valid": 0,
            "fetch_PC": 0,
            "branch_taken": 0,
            "target_address": 0,
            "branch_valid": 0,
            "address": 0,
            "memory_type": 0,
            "access_width":0,
            "is_unsigned": 0,
            "wr_data": 0,
            "MOB_index": 0,
            "ROB_index": 0,
            "FTQ_index": 0,
            "fetch_packet_index": 0,
            "violation": 0
        }
        })

    async def write_backend_memory_response(self, backend_response):
        self.MOB.write_backend_memory_response(backend_response)
        await self.clock()
        self.MOB.write_backend_memory_response({
            "valid" : 0,
            "bits": {
                "addr" : 0,
                "data" : 0,
                "MOB_index" : 0,
            }
        })


    async def read_MOB_output(self):
        return self.MOB.read_MOB_output(None)


    async def update(self):
        

        driver_task = cocotb.start(self.drivers.update())
        memory_task = cocotb.start(self.memory.update())
        scoreboard_task = cocotb.start(self.scoreboard.update())

        await self.clock()

        await driver_task
        await memory_task
        await scoreboard_task



