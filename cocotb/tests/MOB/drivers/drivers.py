import random
from cocotb.triggers import ReadOnly
import cocotb


# the reserve driver is quite simple
# it basically takes a memory operation
# and places it on the reservation bus.
# if accepted, it reads the MOB pointer value and places it in the mem packet
# it then returns an updated mem packet, which it then waits to be randomly selected for writing to the AGU port.

# memory requests is an array that consists of a memory request packet, or a None that is functionally a NOP/not a memory operation

import random
from enum import Enum

import cocotb.utils


class memory_type_t(Enum):
    NONE = 0
    LOAD = 1
    STORE = 2

class access_width_t(Enum):
    NONE = 0
    B = 1  # Byte
    HW = 2 # Half-word
    W = 3  # Word



# Generate a random load/store operation
def generate_load_store(address_pool):
    memory_type = random.choice([memory_type_t.LOAD.value, memory_type_t.STORE.value])
    access_width, possible_offsets = random.choice([
        (access_width_t.B.value, [0, 1, 2, 3]), 
        (access_width_t.HW.value, [0, 2]), 
        (access_width_t.W.value, [0])
    ])

    if(random.uniform(0, 1) < 0.4):
        load_store = {
            "valid": 1,
            "memory_type": memory_type,
            "access_width": access_width,
            "wr_data": random.getrandbits(32) if memory_type== 0b10 else 0,
            "RD": random.randint(0, 63),
            "address": random.choice(possible_offsets) + random.choice(address_pool),
            "MOB_index": 0
        }
    else:
        load_store = {
            "valid": 0,
            "memory_type": 0,
            "access_width": 0,
            "wr_data": 0,
            "RD": 0,
            "address": 0,
            "MOB_index": 0
        }
    
    return load_store


class MOB_driver:
    def __init__(self, dut, memory_operations):
        self.dut = dut
        self.memory_operations = memory_operations

        #for i in self.memory_operations:
            #print(i)

        self.AGU_pool = []

        self.uncommitted_pool = []

        self.ROB_entries = [[{
            "accepted": 0,
            "valid": 0,
            "complete": 0,
            "violation": 0} for _ in range(4)] for _ in range(64)]


        self.ROB_front_pointer = 0
        self.ROB_back_pointer = 0

#        for i in range(0, len(memory_operations), 4):
            #print(f"Group {i//4}:")
            #for op in memory_operations[i:i + 4]:
                #print(f"{op}")
            #print("-" * 20)  # Separator between groups



    async def update(self):
        # Drive reserve one at at a time (in program order)

        for i in range(4):
            # write inputs 
            getattr(self.dut, f"io_reserve_{i}_valid").value =  self.memory_operations[0][i]["valid"]
            getattr(self.dut, f"io_reserve_{i}_bits_memory_type").value =   self.memory_operations[0][i]["memory_type"]
            getattr(self.dut, f"io_reserve_{i}_bits_access_width").value =  self.memory_operations[0][i]["access_width"]
            getattr(self.dut, f"io_reserve_{i}_bits_ready_bits_RS1_ready").value =  0
            getattr(self.dut, f"io_reserve_{i}_bits_ready_bits_RS2_ready").value =  0
            getattr(self.dut, f"io_reserve_{i}_bits_RDold").value =     0
            getattr(self.dut, f"io_reserve_{i}_bits_RD").value =    self.memory_operations[0][i]["RD"]
            getattr(self.dut, f"io_reserve_{i}_bits_RD_valid").value =  0
            getattr(self.dut, f"io_reserve_{i}_bits_RS1").value =   0
            getattr(self.dut, f"io_reserve_{i}_bits_RS1_valid").value =    0
            getattr(self.dut, f"io_reserve_{i}_bits_RS2").value =   0
            getattr(self.dut, f"io_reserve_{i}_bits_RS2_valid").value =   0
            getattr(self.dut, f"io_reserve_{i}_bits_IMM").value =   0
            getattr(self.dut, f"io_reserve_{i}_bits_FUNCT3").value =   0
            getattr(self.dut, f"io_reserve_{i}_bits_packet_index").value =  i
            getattr(self.dut, f"io_reserve_{i}_bits_ROB_index").value =     self.ROB_back_pointer % 64
            getattr(self.dut, f"io_reserve_{i}_bits_MOB_index").value =     0
            getattr(self.dut, f"io_reserve_{i}_bits_instructionType").value =   0
            getattr(self.dut, f"io_reserve_{i}_bits_portID").value =    0
            getattr(self.dut, f"io_reserve_{i}_bits_RS_type").value =   0
            getattr(self.dut, f"io_reserve_{i}_bits_needs_ALU").value =     0
            getattr(self.dut, f"io_reserve_{i}_bits_needs_branch_unit").value =     0
            getattr(self.dut, f"io_reserve_{i}_bits_needs_CSRs").value =    0
            getattr(self.dut, f"io_reserve_{i}_bits_SUBTRACT").value = 0
            getattr(self.dut, f"io_reserve_{i}_bits_MULTIPLY").value =  0
            getattr(self.dut, f"io_reserve_{i}_bits_IS_IMM").value =    0


            # When driving the reserve packet, determine which entries need to resolve before committing
            #self.ROB_entries[self.ROB_back_pointer % 64][i]["valid"] = self.memory_operations[0][i]["valid"]
            # non memory operations are just considered invalid



        #self.ROB_back_pointer = self.ROB_back_pointer + 1



        
        # Drive AGU in random order (and random latency)
        getattr(self.dut, f"io_AGU_output_valid").value = 0
        getattr(self.dut, f"io_AGU_output_bits_RD_data").value =  0
        getattr(self.dut, f"io_AGU_output_bits_MOB_index").value = 0
        getattr(self.dut, f"io_AGU_output_bits_address").value =   0
        getattr(self.dut, f"io_AGU_output_bits_RD").value = 0
        getattr(self.dut, f"io_AGU_output_bits_RD_valid").value =   0
        getattr(self.dut, f"io_AGU_output_bits_fetch_PC").value =   0
        getattr(self.dut, f"io_AGU_output_bits_branch_taken").value =   0
        getattr(self.dut, f"io_AGU_output_bits_target_address").value = 0
        getattr(self.dut, f"io_AGU_output_bits_branch_valid").value =   0
        getattr(self.dut, f"io_AGU_output_bits_memory_type").value =    0
        getattr(self.dut, f"io_AGU_output_bits_access_width").value =   0
        getattr(self.dut, f"io_AGU_output_bits_is_unsigned").value =    0
        getattr(self.dut, f"io_AGU_output_bits_wr_data").value =   0
        getattr(self.dut, f"io_AGU_output_bits_ROB_index").value =  0
        getattr(self.dut, f"io_AGU_output_bits_fetch_packet_index").value = 0


        print(self.AGU_pool)
        if random.uniform(0, 1) < 0.6:
            if len(self.AGU_pool) != 0:
                #index = random.randint(0, len(self.AGU_pool) - 1)
                #AGU = self.AGU_pool.pop(index)

                AGU = self.AGU_pool.pop(0)

                getattr(self.dut, f"io_AGU_output_valid").value = AGU["valid"]
                getattr(self.dut, f"io_AGU_output_bits_RD_data").value =  0
                getattr(self.dut, f"io_AGU_output_bits_MOB_index").value = AGU["MOB_index"]
                getattr(self.dut, f"io_AGU_output_bits_address").value =    AGU["address"]
                getattr(self.dut, f"io_AGU_output_bits_RD").value = 0
                getattr(self.dut, f"io_AGU_output_bits_RD_valid").value =   0
                getattr(self.dut, f"io_AGU_output_bits_fetch_PC").value =   0
                getattr(self.dut, f"io_AGU_output_bits_branch_taken").value =   0
                getattr(self.dut, f"io_AGU_output_bits_target_address").value = 0
                getattr(self.dut, f"io_AGU_output_bits_branch_valid").value =   0
                getattr(self.dut, f"io_AGU_output_bits_memory_type").value =    AGU["memory_type"]
                getattr(self.dut, f"io_AGU_output_bits_access_width").value =   0
                getattr(self.dut, f"io_AGU_output_bits_is_unsigned").value =    0
                getattr(self.dut, f"io_AGU_output_bits_wr_data").value =    AGU["wr_data"]
                getattr(self.dut, f"io_AGU_output_bits_ROB_index").value =  0
                getattr(self.dut, f"io_AGU_output_bits_FTQ_index").value =  0
                getattr(self.dut, f"io_AGU_output_bits_fetch_packet_index").value = 0


            # Check for commit
            # each entry must be either valid, complete or invalid



        #print(f"ROB[{self.ROB_front_pointer%64}] : {self.ROB_entries[self.ROB_front_pointer%64]}")
        #print("")
        

        entry_valid = [self.ROB_entries[self.ROB_front_pointer % 64][i]["valid"] for i in range(4)]
        entry_complete = [self.ROB_entries[self.ROB_front_pointer % 64][i]["complete"] for i in range(4)]
        entry_accepted = [self.ROB_entries[self.ROB_front_pointer % 64][i]["accepted"] for i in range(4)]
        entry_accepted = [self.ROB_entries[self.ROB_front_pointer % 64][i]["accepted"] for i in range(4)]

        # Entry i is good to go if it's either valid and complete, or not valid
        good_to_go = [
            ((entry_valid[i] == 1 and entry_complete[i] == 1) or entry_valid[i] == 0) and entry_accepted[i] == 1
            for i in range(4)
        ]




        # All entries must be good to go for can_commit to be True
        can_commit = all(good_to_go)
        replay = any([self.ROB_entries[self.ROB_front_pointer % 64][i]["violation"] for i in range(4)])

#        print(f"writing to ROB {self.ROB_front_pointer}")
        ##print(f"MOB front {self.ROB_entries[0]}")
        #print(entry_accepted)
        #print(entry_valid)
        #print(entry_complete)
        #print(good_to_go)
        #print(can_commit)
        #print("----------")

        
        self.dut.io_commit_valid.value = 0
        self.dut.io_commit_bits_ROB_index.value = self.ROB_front_pointer % 64


        self.dut.io_flush.value = 0
        if(can_commit and replay):
            print("FLUSH")
            self.dut.io_flush.value = 1
            self.memory_operations = self.uncommitted_pool + self.memory_operations # realloacte the instructions that you performed but never committed
            self.AGU_pool = []

            self.ROB_entries[self.ROB_front_pointer] = [{
                        "valid": 0,
                        "complete": 0,
                        "violation": 0,
                        "accepted": 0,
                    } for i in range(4)]


            self.ROB_back_pointer = self.ROB_front_pointer

            #self.ROB_back_pointer = self.ROB_front_pointer

        
        elif can_commit:
            self.uncommitted_pool.pop(0)

            #print(f"Can commit {self.ROB_front_pointer}")
            #print(f"{self.ROB_entries[self.ROB_front_pointer%64]}")
            #print("")
            #print("")
            # FIXME: need to decide if I should replay from certain fetch packet or keep going here
            # FIXME: which means I also need to control flush
            # Drive commit signals
            self.dut.io_commit_valid.value = 1
            self.dut.io_commit_bits_ROB_index.value = self.ROB_front_pointer % 64
            self.dut.io_commit_bits_fetch_PC.value = 0
            self.dut.io_commit_bits_T_NT.value = 0
            self.dut.io_commit_bits_br_type.value = 0
            self.dut.io_commit_bits_fetch_packet_index.value = 0
            self.dut.io_commit_bits_is_misprediction.value = 0
            self.dut.io_commit_bits_exception.value = 0
            self.dut.io_commit_bits_expected_PC.value = 0
            self.dut.io_commit_bits_GHR.value = 0
            self.dut.io_commit_bits_TOS.value = 0
            self.dut.io_commit_bits_NEXT.value = 0
            self.dut.io_commit_bits_free_list_front_pointer.value = 0
            
            # Set RDold values
            for i in range(4):
                getattr(self.dut, f"io_commit_bits_RDold_{i}").value = 0
            
            # Set RD and RD_valid values
            for i in range(4):
                getattr(self.dut, f"io_commit_bits_RD_{i}").value = 0
                getattr(self.dut, f"io_commit_bits_RD_valid_{i}").value = 0

            # Update the ROB front pointer
            self.ROB_front_pointer += 1




        await ReadOnly()




        ###########################
        # FETCH PACKET ACCETPED ? #
        ###########################
        
        fetch_packet_accepted   = True
        input_ROB_index         = None



        for i in range(4):
            valid           = int(getattr(self.dut, f"io_reserve_{i}_valid").value)
            ready           = int(getattr(self.dut, f"io_reserve_{i}_ready").value)

            input_ROB_index = int(getattr(self.dut, f"io_reserve_{i}_bits_ROB_index").value)
            if(not ((valid and ready) or not valid)):
                fetch_packet_accepted   = False
                input_ROB_index = int(getattr(self.dut, f"io_reserve_{i}_bits_ROB_index").value)

        ############################
        # UPDATE INSTRUCTION VALID #
        ############################

        if fetch_packet_accepted:

            self.ROB_back_pointer = self.ROB_back_pointer + 1
            self.ROB_entries[input_ROB_index] = [{
                        "valid": int(getattr(self.dut, f"io_reserve_{i}_valid").value) and int(getattr(self.dut, f"io_reserve_{i}_ready").value),
                        "complete": 0,
                        "violation": 0,
                        "accepted": 1,
                    } for i in range(4)]

            #print(f"{self.ROB_entries[input_ROB_index]} @ entry {input_ROB_index}")
            


        #if(input_ROB_index != None):
            #print(f"MOB[{input_ROB_index}] {self.ROB_entries[input_ROB_index]}")




        ###################
        # UPDATE COMPLETE #
        ###################

        complete_valid                  = int(self.dut.io_complete_valid.value)
        complete_ROB_index              = int(self.dut.io_complete_bits_ROB_index.value)
        complete_fetch_packet_index     = int(self.dut.io_complete_bits_fetch_packet_index.value)
        complete_violation              = int(self.dut.io_complete_bits_violation.value)

        if(complete_valid): 
            #print(f"Complete {complete_ROB_index} ")
            self.ROB_entries[complete_ROB_index][complete_fetch_packet_index]["complete"] = 1
            self.ROB_entries[complete_ROB_index][complete_fetch_packet_index]["violation"] = complete_violation




        if(fetch_packet_accepted):
            accepted_mem_request = self.memory_operations.pop(0)

            self.uncommitted_pool.append(accepted_mem_request)

            for i in range(4):
                if(int(getattr(self.dut, f"io_reserve_{i}_valid"))):
                    accepted_mem_request[i]["MOB_index"] = int(getattr(self.dut, f"io_reserved_pointers_{i}_bits").value)
                    self.AGU_pool.append(accepted_mem_request[i])
                    #self.ROB_entries[input_ROB_index]["bits"][i]["valid"] = valid

            #print(accepted_mem_request)


