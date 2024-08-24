import random
from cocotb.triggers import ReadOnly


# the reserve driver is quite simple
# it basically takes a memory operation
# and places it on the reservation bus.
# if accepted, it reads the MOB pointer value and places it in the mem packet
# it then returns an updated mem packet, which it then waits to be randomly selected for writing to the AGU port.

# memory requests is an array that consists of a memory request packet, or a None that is functionally a NOP/not a memory operation

class MOB_driver:
    def __init__(self, dut, memory_operations):
        self.dut = dut
        self.memory_operations = memory_operations
        self.AGU_pool = []


    async def update(self):
        # Drive reserve one at at a time (in program order)
        for i in range(4):
            # write inputs 
            getattr(self.dut, f"io_reserve_{i}_valid").value =  self.memory_operations[i]["valid"]
            getattr(self.dut, f"io_reserve_{i}_bits_memory_type").value =   self.memory_operations[i]["memory_type"]
            getattr(self.dut, f"io_reserve_{i}_bits_access_width").value =  self.memory_operations[i]["access_width"]
            getattr(self.dut, f"io_reserve_{i}_bits_ready_bits_RS1_ready").value =  0
            getattr(self.dut, f"io_reserve_{i}_bits_ready_bits_RS2_ready").value =  0
            getattr(self.dut, f"io_reserve_{i}_bits_RDold").value =     0
            getattr(self.dut, f"io_reserve_{i}_bits_RD").value =    0
            getattr(self.dut, f"io_reserve_{i}_bits_RD_valid").value =  0
            getattr(self.dut, f"io_reserve_{i}_bits_RS1").value =   0
            getattr(self.dut, f"io_reserve_{i}_bits_RS1_valid").value =    0
            getattr(self.dut, f"io_reserve_{i}_bits_RS2").value =   0
            getattr(self.dut, f"io_reserve_{i}_bits_RS2_valid").value =   0
            getattr(self.dut, f"io_reserve_{i}_bits_IMM").value =   0
            getattr(self.dut, f"io_reserve_{i}_bits_FUNCT3").value =   0
            getattr(self.dut, f"io_reserve_{i}_bits_packet_index").value =  0
            getattr(self.dut, f"io_reserve_{i}_bits_ROB_index").value =     0
            getattr(self.dut, f"io_reserve_{i}_bits_MOB_index").value =     0
            getattr(self.dut, f"io_reserve_{i}_bits_FTQ_index").value =     0
            getattr(self.dut, f"io_reserve_{i}_bits_instructionType").value =   0
            getattr(self.dut, f"io_reserve_{i}_bits_portID").value =    0
            getattr(self.dut, f"io_reserve_{i}_bits_RS_type").value =   0
            getattr(self.dut, f"io_reserve_{i}_bits_needs_ALU").value =     0
            getattr(self.dut, f"io_reserve_{i}_bits_needs_branch_unit").value =     0
            getattr(self.dut, f"io_reserve_{i}_bits_needs_CSRs").value =    0
            getattr(self.dut, f"io_reserve_{i}_bits_SUBTRACT").value = 0
            getattr(self.dut, f"io_reserve_{i}_bits_MULTIPLY").value =  0
            getattr(self.dut, f"io_reserve_{i}_bits_IS_IMM").value =    0

        
        # Drive AGU in random order (and random latency)

        if(random.uniform(0, 1) < 0.6):
            if(len(self.AGU_pool) != 0):
                AGU = random.choice(self.AGU_pool)
                self.AGU_pool.remove(AGU)

                getattr(self.dut, f"io_AGU_output_valid").value = 1
                getattr(self.dut, f"io_AGU_output_bits_RD_data").value =  0
                getattr(self.dut, f"io_AGU_output_bits_MOB_index").value = AGU["MOB_index"]
                getattr(self.dut, f"io_AGU_output_bits_address").value =    AGU["address"]
                getattr(self.dut, f"io_AGU_output_bits_RD").value = 0
                getattr(self.dut, f"io_AGU_output_bits_RD_valid").value =   0
                getattr(self.dut, f"io_AGU_output_bits_fetch_PC").value =   0
                getattr(self.dut, f"io_AGU_output_bits_branch_taken").value =   0
                getattr(self.dut, f"io_AGU_output_bits_target_address").value = 0
                getattr(self.dut, f"io_AGU_output_bits_branch_valid").value =   0
                getattr(self.dut, f"io_AGU_output_bits_memory_type").value =    0
                getattr(self.dut, f"io_AGU_output_bits_access_width").value =   0
                getattr(self.dut, f"io_AGU_output_bits_is_unsigned").value =    0
                getattr(self.dut, f"io_AGU_output_bits_wr_data").value =    AGU["wr_data"]
                getattr(self.dut, f"io_AGU_output_bits_ROB_index").value =  0
                getattr(self.dut, f"io_AGU_output_bits_FTQ_index").value =  0
                getattr(self.dut, f"io_AGU_output_bits_fetch_packet_index").value = 0
                getattr(self.dut, f"io_AGU_output_bits_violation").value =  0
                getattr(self.dut, f"io_AGU_output_bits_memory_violation").value =   0


        await ReadOnly()

        for i in range(4):

            valid = int(getattr(self.dut, f"io_reserve_{i}_valid").value)
            ready = int(getattr(self.dut, f"io_reserve_{i}_ready").value)

            if(valid == 0):
                accepted_mem_request = self.memory_operations.pop(0)
            #pointer_valid = getattr(self.dut, f"io_reserved_pointers_{i}_valid").value
            # FIXME: do I also need to check for pointer accepted?
            if(valid and ready):
                accepted_mem_request = self.memory_operations.pop(0)
                accepted_mem_request["MOB_index"] = int(getattr(self.dut, f"io_reserved_pointers_{i}_bits").value)
                self.AGU_pool.append(accepted_mem_request)

            



        

