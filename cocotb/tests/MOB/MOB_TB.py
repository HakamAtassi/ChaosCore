
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



class MOB_TB:
    def __init__(self, dut, memory_capacity=512*(2**20)):
        # Top level Module #
        self.MOB = MOB_dut(dut=dut)

        # For now, use 256MB of random data
        self.memory_capacity = memory_capacity

        self.golden_memory = bytearray([0]*self.memory_capacity)

    def init_sequence(self):
        ## INIT MEMORY
        for i in range(self.memory_capacity):
            random_byte = random.getrandbits(8)
            self.golden_memory[i] = random_byte 


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


    ###############
    # CACHE READY #
    ###############

    #def write_CPU_response_ready(self, ready):
        #self.L1_data_cache.write_CPU_response_ready(ready)

    #def get_CPU_request_ready(self):
        #return self.L1_data_cache.io_CPU_request_ready.value

    #async def wait_cache_hit(self):
        #for _ in range(100000):
            #await self.clock()
            #if (int(self.read_CPU_response()["valid"])):
                #return
        #assert False, "Error: Cache did not return for 1000 cycles"


    ##async def self_checking_request(self, address,data,access_type, access_width,valid):
    #async def self_checking_request(self, valid, addr, data, memory_type, access_width, MOB_index):

        #expected_response = None

        ## Place request on DUT
        #await self.write_CPU_request(valid, addr, data, memory_type, access_width, MOB_index)

        ## Monitor request
        #cache_request_valid = self.L1_data_cache.read_CPU_request()["valid"]
        #cache_request_ready = self.L1_data_cache.read_CPU_request()["ready"]

        ## Monitor response
        #cache_response_valid = self.L1_data_cache.read_CPU_response()["valid"]
        #cache_response_ready = self.L1_data_cache.read_CPU_response()["ready"]

        #if (cache_request_valid and cache_request_ready):
            #monitored_address       = int(self.L1_data_cache.read_CPU_request()["bits"]["addr"])
            #monitored_memory_type   = memory_type_t(self.L1_data_cache.read_CPU_request()["bits"]["memory_type"])
            #monitored_access_width  = access_width_t(int(self.L1_data_cache.read_CPU_request()["bits"]["access_width"]))
            #monitored_MOB_index     = int(self.L1_data_cache.read_CPU_request()["bits"]["MOB_index"])
            #monitored_data          = int(self.L1_data_cache.read_CPU_request()["bits"]["data"])

            #access_width_map = {
                #access_width_t.B: 1,
                #access_width_t.HW: 2,
                #access_width_t.W: 4
            #}


            #monitored_access_width_bytes = access_width_map[monitored_access_width]

            #if(monitored_access_width == access_width_t.B):
                #data = data & 0xFF
            #if(monitored_access_width == access_width_t.HW):
                #data = data & 0xFFFF
            #if(monitored_access_width == access_width_t.W):
                #data = data & 0xFFFF_FFFF



            #expected_response = {}
            #if(monitored_memory_type == memory_type_t.STORE):
                ## perform store to model memory
                ##print(f"request addr {hex(monitored_address)}")
                #print(f"write to {hex(monitored_address)} @ {cocotb.utils.get_sim_time('ns')} <= {hex(data)}")
                #self.golden_memory[monitored_address:monitored_address + monitored_access_width_bytes] = data.to_bytes(monitored_access_width_bytes, 'little')
                #pass

            #elif(monitored_memory_type == memory_type_t.LOAD):
                ## perform load from memory model

                ##print(f"request addr {hex(monitored_address)}")
                ##print(f"expected data: {hex(int.from_bytes(self.golden_memory[monitored_address:monitored_address+monitored_access_width_bytes], 'little'))}")
                #expected_response = {
                    #"valid": 1,
                    #"bits": {
                        #"data": int.from_bytes(self.golden_memory[monitored_address:monitored_address+monitored_access_width_bytes], 'little'),
                        #"MOB_index": monitored_MOB_index,
                    #}
                #}

                #self.expected_response_Q_table.setdefault(monitored_address, []).append(expected_response)

        ## if cache response is accepted, compare with golden response queue
        #if (cache_response_valid and cache_response_ready):
            ## compare output with expected
            #got_response = self.L1_data_cache.read_CPU_response()
            #try:
                #cache_response_address = self.L1_data_cache.read_CPU_response()["bits"]["addr"]
                #expected_response = self.expected_response_Q_table[cache_response_address].pop(0)

                #if not self.expected_response_Q_table[cache_response_address]:  # delete queue entry if empty 
                    #del self.expected_response_Q_table[cache_response_address]

            #except(IndexError):
                #print(f"Error! Cache returned valid without outstanding read request.")
                #print(f"Please ensure that the cache only returns on request, and once per request.")
                #exit(1)

            #try: 
                ## how do you perform assertions for the D$ if it responds out of order?
                #assert expected_response["bits"]["data"] == got_response["bits"]["data"], \
                #f"Expected response data {hex(expected_response['bits']['data'])} does not match {hex(got_response['bits']['data'])}"

                #assert expected_response["bits"]["MOB_index"] == got_response["bits"]["MOB_index"], \
                #f"Expected response MOB_index {expected_response['bits']['MOB_index']} does not match {got_response['bits']['MOB_index']}"

            #except(AssertionError):
                ## wait a few extra cycles before terminating
                #print(f"Assertion failed. Terminating test.")
                #await self.clock()
                #await self.clock()
                #await self.clock()
                #assert False
                #exit(1)
