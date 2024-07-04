import sys
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, ReadOnly

# Add helper functions as needed


class SOC_dut:
    def __init__(self, dut, DRAM, DRAM_line_size=32):    # modify as needed (parameters, etc...)
        self.dut = dut
        self.DRAM = DRAM

        # Control signals
        self.DRAM_request       = False
        self.DRAM_request_addr  = 0x0
        self.DRAM_request_size  = DRAM_line_size
        #...

    def clock(self):            # Do not touch
        return self.dut.clock

    async def reset(self):      # Do not touch
        self.dut.reset.value = 0
        await RisingEdge(self.dut.clock)
        self.dut.reset.value = 1
        await RisingEdge(self.dut.clock)
        self.dut.reset.value = 0





    def set_dram_ready(self, ready):
        getattr(self.dut ,f"io_frontend_memory_request_ready").value = ready
        getattr(self.dut ,f"io_backend_memory_request_ready").value = ready

    #def set_cache_ready(self, ready):
        #getattr(self.dut ,f"io_cache_data_ready").value = ready



    def write_dram_resp(self, data=0, valid=0):
        self.dut.io_frontend_memory_response_valid.value = valid
        self.dut.io_frontend_memory_response_bits_data.value = data

    def read_frontend_output(self):
        outputs = {}
        outputs["resp_ready"]           = int(self.dut.io_frontend_memory_response_ready.value)
        outputs["request_valid"]        = int(self.dut.io_frontend_memory_request_valid.value)
        outputs["request_addr"]         = int(self.dut.io_frontend_memory_request_bits_addr.value)
        outputs["request_wr_en"]        = int(self.dut.io_frontend_memory_request_bits_wr_en.value)

        return outputs

    def get_instruction_fetch_output(self):

        outputs = {}

        outputs["valid"]            = int(getattr(self.dut, f"frontend.instruction_fetch.io_fetch_packet_valid").value)
        #outputs["fetch_PC"]         = int(getattr(self.dut, f"frontend.instruction_fetch.io_fetch_packet_bits_fetch_PC").value)
        #outputs["valid"]            = int(getattr(self.dut, f"frontend.instruction_fetch.io_predictions_valid").value)
        #outputs["fetch_PC"]         = int(getattr(self.dut, f"frontend.instruction_fetch.io_predictions_bits_fetch_PC").value)
        outputs["predicted_PC"]     = int(getattr(self.dut, f"frontend.instruction_fetch.io_predictions_bits_predicted_PC").value)
        outputs["T_NT"]             = int(getattr(self.dut, f"frontend.instruction_fetch.io_predictions_bits_T_NT").value)
        outputs["br_type"]          = int(getattr(self.dut, f"frontend.instruction_fetch.io_predictions_bits_br_type").value)
        outputs["GHR"]              = int(getattr(self.dut, f"frontend.instruction_fetch.io_predictions_bits_GHR").value)
        outputs["NEXT"]             = int(getattr(self.dut, f"frontend.instruction_fetch.io_predictions_bits_NEXT").value)
        outputs["TOS"]              = int(getattr(self.dut, f"frontend.instruction_fetch.io_predictions_bits_TOS").value)
        outputs["resolved_PC"]      = int(getattr(self.dut, f"frontend.instruction_fetch.io_predictions_bits_resolved_PC").value)


        outputs["valid_bits"]        = [0,0,0,0]
        outputs["instruction"]       = [0,0,0,0]
        outputs["packet_index"]      = [0,0,0,0]
        outputs["ROB_index"]         = [0,0,0,0]

        for i in range(4):
            outputs["valid_bits"][i]        = int(getattr(self.dut, f"frontend.instruction_fetch.io_fetch_packet_bits_valid_bits_{i}"))
            outputs["instruction"][i]       = int(getattr(self.dut, f"frontend.instruction_fetch.io_fetch_packet_bits_instructions_{i}_instruction"))
            outputs["packet_index"][i]      = int(getattr(self.dut, f"frontend.instruction_fetch.io_fetch_packet_bits_instructions_{i}_packet_index"))
            outputs["ROB_index"][i]         = int(getattr(self.dut, f"frontend.instruction_fetch.io_fetch_packet_bits_instructions_{i}_ROB_index"))

        return outputs


    def get_frontend_output(self):
        outputs = {}

        outputs["RS1_ready"]    = [0] * 4
        outputs["RS2_ready"]    = [0] * 4
        outputs["RD"]           = [0] * 4
        outputs["RD_valid"]     = [0] * 4
        outputs["RS1"]          = [0] * 4
        outputs["RS1_valid"]    = [0] * 4
        outputs["RS2"]          = [0] * 4
        outputs["RS2_valid"]    = [0] * 4
        outputs["IMM"]          = [0] * 4
        outputs["FUNCT3"]       = [0] * 4
        outputs["packet_index"] = [0] * 4
        outputs["ROB_index"]    = [0] * 4
        outputs["instructionType"] = [0] * 4
        outputs["portID"]       = [0] * 4
        outputs["RS_type"]      = [0] * 4
        outputs["needs_ALU"]    = [0] * 4
        outputs["needs_branch_unit"] = [0] * 4
        outputs["needs_CSRs"]   = [0] * 4
        outputs["SUBTRACT"]     = [0] * 4
        outputs["MULTIPLY"]     = [0] * 4
        outputs["IMMEDIATE"]    = [0] * 4
        outputs["is_load"]      = [0] * 4
        outputs["is_store"]     = [0] * 4
        outputs["valid_bits"]   = [0] * 4

        outputs["fetch_packet_valid"]                   = int(getattr(self.dut, f"frontend.io_renamed_decoded_fetch_packet_valid").value)
        outputs["fetch_PC"]                             = int(getattr(self.dut, f"frontend.io_renamed_decoded_fetch_packet_bits_fetch_PC").value)


        for i in range(4):
            #outputs["RS1_ready"][i]                     = int(getattr(self.dut, f"frontend.io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_ready_bits_RS1_ready").value)
            #outputs["RS2_ready"][i]                     = int(getattr(self.dut, f"frontend.io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_ready_bits_RS2_ready").value)
            outputs["RD"][i]                            = int(getattr(self.dut, f"frontend.io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RD").value)
            outputs["RD_valid"][i]                      = int(getattr(self.dut, f"frontend.io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RD_valid").value)
            outputs["RS1"][i]                           = int(getattr(self.dut, f"frontend.io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RS1").value)
            outputs["RS1_valid"][i]                     = int(getattr(self.dut, f"frontend.io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RS1_valid").value)
            outputs["RS2"][i]                           = int(getattr(self.dut, f"frontend.io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RS2").value)
            outputs["RS2_valid"][i]                     = int(getattr(self.dut, f"frontend.io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RS2_valid").value)
            outputs["IMM"][i]                           = int(getattr(self.dut, f"frontend.io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_IMM").value)
            outputs["FUNCT3"][i]                        = int(getattr(self.dut, f"frontend.io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_FUNCT3").value)
            outputs["packet_index"][i]                  = int(getattr(self.dut, f"frontend.io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_packet_index").value)
            #outputs["ROB_index"][i]                     = int(getattr(self.dut, f"frontend.io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_ROB_index").value)
            outputs["instructionType"][i]               = int(getattr(self.dut, f"frontend.io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_instructionType").value)
            outputs["portID"][i]                        = int(getattr(self.dut, f"frontend.io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_portID").value)
            outputs["RS_type"][i]                       = int(getattr(self.dut, f"frontend.io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_RS_type").value)
            outputs["needs_ALU"][i]                     = int(getattr(self.dut, f"frontend.io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_ALU").value)
            outputs["needs_branch_unit"][i]             = int(getattr(self.dut, f"frontend.io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_branch_unit").value)
            outputs["needs_CSRs"][i]                    = int(getattr(self.dut, f"frontend.io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_needs_CSRs").value)
            outputs["SUBTRACT"][i]                      = int(getattr(self.dut, f"frontend.io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_SUBTRACT").value)
            outputs["MULTIPLY"][i]                      = int(getattr(self.dut, f"frontend.io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_MULTIPLY").value)
            outputs["IMMEDIATE"][i]                     = int(getattr(self.dut, f"frontend.io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_IMMEDIATE").value)
            outputs["is_load"][i]                       = int(getattr(self.dut, f"frontend.io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_is_load").value)
            outputs["is_store"][i]                      = int(getattr(self.dut, f"frontend.io_renamed_decoded_fetch_packet_bits_decoded_instruction_{i}_is_store").value)
            outputs["valid_bits"][i]                    = int(getattr(self.dut, f"frontend.io_renamed_decoded_fetch_packet_bits_valid_bits_{i}").value)

        return outputs


#    async def update(self):
        ## await cycle
        ## if needs memory (from prev cycle)
            ## send data from dram model
        ## await ReadOnly()
        ## set mem addr flag, size, etc

        #await RisingEdge(self.dut.clock)

        ## Clear writes from prev cycle (so you dont write twice)
        #self.write_dram_resp()

        #if(self.DRAM_request):
            #data = self.DRAM.read(address=self.DRAM_request_addr, size=self.DRAM_request_size)

            #data = int.from_bytes(data, byteorder="little")
            #self.write_dram_resp(data, 1)

        #await ReadOnly()

        #self.DRAM_request       =   self.read_frontend_output()["request_valid"]
        #self.DRAM_request_addr  =   self.read_frontend_output()["request_addr"]


    def get_PRF(self):
        PRF = [0]*64
        for i in range(64):
            PRF[i] = int(getattr(self.dut, f"backend.INT_PRF.mem_ext.Memory")[i].value)
        return PRF

    def read_reset(self):
        return self.dut.reset.value
    
    # IMEM 
    def read_imem_request_valid(self):
        return self.dut.io_frontend_memory_request_valid.value

    def read_imem_request_ready(self):
        return self.dut.io_frontend_memory_request_ready.value

    def read_imem_request_addr(self):
        return self.dut.io_frontend_memory_request_bits_addr.value

    def write_imem_request_ready(self, ready):
        self.dut.io_frontend_memory_request_ready.value = ready

    def write_imem_response(self, data=0, valid=0):
        self.dut.io_frontend_memory_response_valid.value        = valid
        self.dut.io_frontend_memory_response_bits_data.value    = data if valid else 0

    # -------------
    # DMEM CONTROL
    # -------------
    def read_dmem_request_valid(self):
        return int(self.dut.io_backend_memory_request_valid.value)

    def read_dmem_request_ready(self):
        return int(self.dut.io_backend_memory_request_ready.value)

    def read_dmem_request_addr(self):
        return int(self.dut.io_backend_memory_request_bits_addr.value)

    def read_dmem_request_wr_en(self):
        return int(self.dut.io_backend_memory_request_bits_wr_en.value)

    def read_dmem_request_data(self):
        return int(self.dut.io_backend_memory_request_bits_wr_data.value)

    def write_dmem_request_ready(self, ready):
        self.dut.io_backend_memory_request_ready.value = ready

    def write_dmem_response(self, data=0, valid=0):
        self.dut.io_backend_memory_response_valid.value = valid
        self.dut.io_backend_memory_response_bits_data.value = data if valid else 0

    async def update(self):  # clock cycle with memory handling

        # clear previous responses
        self.write_imem_response()
        self.write_dmem_response()

        # handle imem read requests
        if (self.read_imem_request_ready() and self.read_imem_request_valid() and not self.read_reset()):
            addr = self.read_imem_request_addr()
                
            data = self.DRAM.read(address=addr & 0xFFFFFFF0, size=32)
            data = int.from_bytes(data, byteorder="little")
            self.write_imem_response(data, 1)

        # handle dmem read/write requests
        if self.read_dmem_request_ready() and self.read_dmem_request_valid() and not self.read_reset():
            wr_en   = self.read_dmem_request_wr_en()
            data    = self.read_dmem_request_data()
            addr    = self.read_dmem_request_addr()

            if(addr == 0x8000_0000):
                await RisingEdge(self.clock())
                return 
            if wr_en:  # write
                # FIXME: size depends on instruction
                self.DRAM.write(address=addr, data=data, size=4)
            else:  # read
                # FIXME: size depends on instruction
                data = self.DRAM.read(address=addr, size=4)
                data = int.from_bytes(data, byteorder="little")
                self.write_dmem_response(data, 1)

        await RisingEdge(self.clock())