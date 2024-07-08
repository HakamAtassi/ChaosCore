import sys
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly


class ChaosCore_dut:
    def __init__(self, dut, imem, dmem):  # modify as needed (parameters, etc...)
        self.ChaosCore = dut

        # Backend Modules #

        self.imem = imem
        self.dmem = dmem

    def clock(self):  # Do not touch
        return self.ChaosCore.clock

    async def reset(self):  # Do not touch
        await RisingEdge(self.ChaosCore.clock)
        self.ChaosCore.reset.value = 1
        await RisingEdge(self.ChaosCore.clock)
        self.ChaosCore.reset.value = 0

    def read_reset(self):
        return self.ChaosCore.reset.value

    # -----------------
    # ADDRESSING LOGIC
    # -----------------

    def get_fetch_packet_valid_bits(self, fetch_PC):
        index = fetch_PC & 0xF
        if index == 0:
            return [1, 1, 1, 1]
        elif index == 4:
            return [0, 1, 1, 1]
        elif index == 8:
            return [0, 0, 1, 1]
        elif index == 12:
            return [0, 0, 0, 1]
        assert False, "Fetch PC not aligned to instruction"

    def get_aligned_PC(self, fetch_PC):
        return fetch_PC & 0xFFFF_FFF0

    # -------------
    # IMEM CONTROL
    # -------------

    def read_imem_request_valid(self):
        return self.ChaosCore.io_frontend_memory_request_valid.value

    def read_imem_request_ready(self):
        return self.ChaosCore.io_frontend_memory_request_ready.value

    def read_imem_request_addr(self):
        return self.ChaosCore.io_frontend_memory_request_bits_addr.value

    def write_imem_request_ready(self, ready):
        self.ChaosCore.io_frontend_memory_request_ready.value = ready

    def write_imem_response(self, data: bytearray = None, valid=0):

        fetch_PC = self.read_imem_request_addr()
        valid_bits = self.get_fetch_packet_valid_bits(fetch_PC)

        self.ChaosCore.io_frontend_memory_response_valid.value                              = valid if valid else 0
        self.ChaosCore.io_frontend_memory_response_bits_fetch_PC.value                      = (fetch_PC if valid else 0)
        self.ChaosCore.io_frontend_memory_response_bits_valid_bits_0.value                  = (valid_bits[0] if valid else 0)
        self.ChaosCore.io_frontend_memory_response_bits_valid_bits_1.value                  = (valid_bits[1] if valid else 0)
        self.ChaosCore.io_frontend_memory_response_bits_valid_bits_2.value                  = (valid_bits[2] if valid else 0)
        self.ChaosCore.io_frontend_memory_response_bits_valid_bits_3.value                  = (valid_bits[3] if valid else 0)
        self.ChaosCore.io_frontend_memory_response_bits_instructions_0_instruction.value    = (int.from_bytes(data[0:4], byteorder="little") if valid else 0)
        self.ChaosCore.io_frontend_memory_response_bits_instructions_0_packet_index.value   = (0 if valid else 0)
        self.ChaosCore.io_frontend_memory_response_bits_instructions_0_ROB_index.value      = (0 if valid else 0)
        self.ChaosCore.io_frontend_memory_response_bits_instructions_1_instruction.value    = (int.from_bytes(data[4:8], byteorder="little") if valid else 0)
        self.ChaosCore.io_frontend_memory_response_bits_instructions_1_packet_index.value   = (1 if valid else 0)
        self.ChaosCore.io_frontend_memory_response_bits_instructions_1_ROB_index.value      = (0 if valid else 0)
        self.ChaosCore.io_frontend_memory_response_bits_instructions_2_instruction.value    = (int.from_bytes(data[8:12], byteorder="little") if valid else 0)
        self.ChaosCore.io_frontend_memory_response_bits_instructions_2_packet_index.value   = (2 if valid else 0)
        self.ChaosCore.io_frontend_memory_response_bits_instructions_2_ROB_index.value      = (0 if valid else 0)
        self.ChaosCore.io_frontend_memory_response_bits_instructions_3_instruction.value    = (int.from_bytes(data[12:16], byteorder="little") if valid else 0)
        self.ChaosCore.io_frontend_memory_response_bits_instructions_3_packet_index.value   = (3 if valid else 0)
        self.ChaosCore.io_frontend_memory_response_bits_instructions_3_ROB_index.value      = (0 if valid else 0)

    # -------------
    # DMEM CONTROL
    # -------------

    def read_dmem_request_valid(self):
        return int(self.ChaosCore.io_backend_memory_request_valid.value)

    def read_dmem_request_ready(self):
        return int(self.ChaosCore.io_backend_memory_request_ready.value)

    def read_dmem_request_addr(self):
        return int(self.ChaosCore.io_backend_memory_request_bits_addr.value)

    def read_dmem_request_wr_en(self):
        return int(self.ChaosCore.io_backend_memory_request_bits_wr_en.value)

    def read_dmem_request_data(self):
        return int(self.ChaosCore.io_backend_memory_request_bits_wr_data.value)

    def write_dmem_request_ready(self, ready):
        self.ChaosCore.io_backend_memory_request_ready.value = ready

    def write_dmem_response(self, data=0, valid=0):
        self.ChaosCore.io_backend_memory_response_valid.value = valid
        self.ChaosCore.io_backend_memory_response_bits_data.value = data if valid else 0

    async def update(self):  # clock cycle with memory handling

        # clear previous responses
        self.write_imem_response()
        self.write_dmem_response()

        # handle imem read requests
        if (self.read_imem_request_ready() and self.read_imem_request_valid() and not self.read_reset()):
            try:
                addr = self.read_imem_request_addr()
                data = self.imem.read(address=self.get_aligned_PC(addr), size=16)
                self.write_imem_response(data, 1)
            except:
                pass


        # handle dmem read/write requests
        if self.read_dmem_request_ready() and self.read_dmem_request_valid() and not self.read_reset():
            wr_en = self.read_dmem_request_wr_en()
            data = self.read_dmem_request_data()
            addr = self.read_dmem_request_addr()
            if wr_en:  # write
                # FIXME: size depends on instruction
                if(addr==0x8000_0000):
                    print(chr(data))
                else:
                    self.dmem.write(address=addr, data=data, size=4)


            else:  # read
                try:
                    # FIXME: size depends on instruction
                    data = self.dmem.read(address=addr, size=4)
                    data = int.from_bytes(data, byteorder="little")
                    self.write_dmem_response(data, 1)
                except:
                    pass

        await RisingEdge(self.clock())
