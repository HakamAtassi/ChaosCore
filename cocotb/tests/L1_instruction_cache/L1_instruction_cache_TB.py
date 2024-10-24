
from cocotbext.axi import AxiBus, AxiRam
from L1_caches import instruction_cache_dut
from cocotbext.axi import AxiBus, AxiMaster
from cocotbext.axi import AxiBus, AxiSlave, MemoryRegion
from cocotbext.axi import AxiBus, AxiRam
from cocotb.triggers import RisingEdge, ReadOnly
import random


class L1_instruction_cache_TB:
    def __init__(self, dut, memory_capacity=256*(2**20)):
        # Top level Module #
        self.L1_instruction_cache = instruction_cache_dut(dut)

        # init AXI slave memory
        # For now, use 256MB of random data
        self.memory_capacity = memory_capacity # Memory capacity in bytes
        self.axi_ram = AxiRam(AxiBus.from_prefix(dut, "m_axi"), dut.clock, dut.reset, size=self.memory_capacity)

        # create a byte array for use as a reference
        self.golden_memory = bytearray([0]*self.memory_capacity)

        # Expected response queues
        self.expected_read_responses = []

    def init_sequence(self):
        # INIT MEMORY
        for i in range(self.memory_capacity):
            random_byte = random.getrandbits(8)
            self.axi_ram.write(i, random_byte.to_bytes(1))
            self.golden_memory[i] = random_byte #random_byte.to_bytes(1)
        self.golden_memory = bytes(self.golden_memory)  # make memory read only (I$ is read only)

        # Assert golden memory and AXI memory are equal

    #################
    # RESET & CLOCK #
    #################

    async def reset(self):
        await self.L1_instruction_cache.reset()

    async def clock(self):
        await self.L1_instruction_cache.clock()

    ######################
    # CACHE READ REQUEST #
    ######################

    async def write_CPU_read_request(self, address, valid):
        self.L1_instruction_cache.write_CPU_read_request(address, valid)
        await self.L1_instruction_cache.clock()
        self.L1_instruction_cache.write_CPU_read_request()

    async def kill(self):
        await self.L1_instruction_cache.kill()

    def CPU_read_response(self):
        return self.L1_instruction_cache.read_CPU_read_response()

    def set_CPU_response(self, ready):
        self.L1_instruction_cache.set_CPU_response(ready)

    async def wait_cache_hit(self):
        for _ in range(100000):
            await self.clock()
            if (int(self.L1_instruction_cache.read_CPU_read_response()["valid"])):
                return

        assert False, "Error: Cache did not return for 1000 cycles"

    def get_valid_bits(self, address):
        return [1,1,1,1]

    async def self_checking_request(self, address, valid):

        expected_response = None

        # Place request on DUT
        await self.write_CPU_read_request(address=address, valid=valid)

        # Monitor request
        cache_request_valid = self.L1_instruction_cache.read_CPU_read_request()["valid"]
        cache_request_ready = self.L1_instruction_cache.read_CPU_read_request()["ready"]

        # Monitor response
        cache_response_valid = self.L1_instruction_cache.read_CPU_read_response()["valid"]
        cache_response_ready = self.L1_instruction_cache.read_CPU_read_response()["ready"]

        if (cache_request_valid and cache_request_ready):
            # cache DUT request accepted
            # Construct expected response and queue it
            monitored_address = self.L1_instruction_cache.read_CPU_read_request()["bits"]["addr"]
            monitored_address_masked = self.L1_instruction_cache.read_CPU_read_request()["bits"]["addr"] & 0xFFFF_FFF0
            expected_response = {
                "valid": 1,
                "bits": {
                    "fetch_PC": address ,  # No idea if this is correct
                    "instruction": [
                        int.from_bytes(self.golden_memory[monitored_address_masked:monitored_address_masked+4], 'little'),
                        int.from_bytes(self.golden_memory[monitored_address_masked+4:monitored_address_masked+8], 'little'),
                        int.from_bytes(self.golden_memory[monitored_address_masked+8:monitored_address_masked+12], 'little'),
                        int.from_bytes(self.golden_memory[monitored_address_masked+12:monitored_address_masked+16], 'little')
                    ],
                    "valid_bits": self.get_valid_bits(monitored_address),
                    "packet_index":
                    [
                        0,
                        1,
                        2,
                        3
                    ],
                }
            }

            self.expected_read_responses.append(expected_response)

        # if cache response is accepted, compare with golden response queue
        if (cache_response_valid and cache_response_ready):
            # compare output with expected
            got_response = self.L1_instruction_cache.read_CPU_read_response()
            try:
                expected_response = self.expected_read_responses.pop(0)
            except (IndexError):
                print(f"Error! Cache returned valid without outstanding read request.")
                print(f"Please ensure that the cache only returns on request, and once per request.")
                exit(1)

            try: 
                assert expected_response["bits"]["fetch_PC"] == got_response["bits"]["fetch_PC"], f"Error! fetch PCs do not match. Expected {hex(expected_response['bits']['fetch_PC'])} got {hex(got_response['bits']['fetch_PC'])}"
                assert expected_response["bits"]["instruction"] == got_response["bits"]["instruction"], f"Error! instructions do not match. Expected {expected_response['bits']['instruction']} got {got_response['bits']['instruction']}"


                #expected_hex = [hex(instr) for instr in expected_response["bits"]["instruction"]]
                #got_hex = [hex(instr) for instr in got_response["bits"]["instruction"]]
                #assert expected_response["bits"]["instruction"] == got_response["bits"]["instruction"], \
                #f"Error! Instructions do not match. Expected {expected_hex} got {got_hex}"
                #assert expected_response["bits"]["valid_bits"] == got_response["bits"]["valid_bits"], f"Error! instruction validation incorrect. Expected {expected_response['bits']['valid_bits']} got {got_response['bits']['valid_bits']}"
            except(AssertionError):
                # wait a few extra cycles before terminating
                print(f"Assertion failed. Terminating test.")
                await self.clock()
                await self.clock()
                await self.clock()
                assert False
                exit(1)

