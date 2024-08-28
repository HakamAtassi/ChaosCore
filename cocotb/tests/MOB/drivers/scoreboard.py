




# The MOB reference model detects accepted inputs into the MOB
# organizes them based on the fetch packet/ROB index, etc
# And executed them against an identical memory in program order. 
# It then attaches an expected response to each load
# When the MOB commits a fetch packet
# its most recent results for that fetch packet are compared
# If they match, the MOB is good to go 
# If they do not match, the MOB is broken


# For stores, just make sure they execute in program order

from enum import Enum
from cocotb.triggers import RisingEdge

class memory_type_t(Enum):
    NONE = 0
    LOAD = 1
    STORE = 2

class access_width_t(Enum):
    NONE = 0
    B = 1  # Byte
    HW = 2 # Half-word
    W = 3  # Word



class MOB_scoreboard:
    
    def __init__(self, dut, memory, memory_operations):
        self.MOB = dut

        self.memory  = bytearray(memory)

        self.memory_operations = memory_operations
        
        # 64 possible fetch packets, each with 4 possible responses
        self.reference_memory_accesses = []

        self.reserved_instructions = []

        self.commit_counter = 0

        #self.MOB_results = [0]*64

        self.MOB_results = [[{
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
                "violation": 0,
                "memory_violation": 0,
            
        }
        } for _ in range(4)] for _ in range(64)]

        self.committed_MOB_results = []

        self.compute_reference()


    def compute_reference(self):
        # one fetch packet at a time, perform the memory operations
        # and generate a queue of their results


        access_width_map = [0, 1, 2, 4]
        #print(len(self.memory_operations))
        for i in range(0, len(self.memory_operations)):

            fetch_packet = [{
                "data" : 0,
                "addr" : 0
            } for _ in range(4)]

            #print(self.memory_operations[i])

            for j in range(4):
                # extract memory operation
                valid       = self.memory_operations[i][j]["valid"]
                wr_en       = self.memory_operations[i][j]["memory_type"] == memory_type_t.STORE.value
                addr        = self.memory_operations[i][j]["address"]
                data        = self.memory_operations[i][j]["wr_data"]
                byte_count  = access_width_map[int(self.memory_operations[i][j]["access_width"])]
                if(byte_count == 1): data = data & 0xFF
                if(byte_count == 2): data = data & 0xFFFF
                if(byte_count == 3): data = data & 0xFFFF_FFFF

                if(valid and wr_en): # this causes my program to freeze
                    self.memory[addr:addr+byte_count] = data.to_bytes(byte_count, byteorder="little")
                    #print(f"(write) mem[{hex(addr)}:{hex(addr+byte_count)}] = {hex(data)}")
                elif(valid):
                    #print(f"(read) mem[{hex(addr)}] = {hex(int.from_bytes(self.memory[addr:addr+byte_count], "little"))}")
                    expected = {
                        "data": int.from_bytes(self.memory[addr:addr+byte_count], "little"),
                        "addr": addr
                    }
                    fetch_packet[j]=expected

            self.reference_memory_accesses.append(fetch_packet)

        #for i in self.reference_memory_accesses:
            #print(i)
                     


    def read_MOB_outputs(self):
        return {
            "valid": int(self.MOB.io_MOB_output_valid.value),
            "bits": {
                "RD": int(self.MOB.io_MOB_output_bits_RD.value),
                "RD_data": int(self.MOB.io_MOB_output_bits_RD_data.value),
                "RD_valid": int(self.MOB.io_MOB_output_bits_RD_valid.value),
                "fetch_PC": int(self.MOB.io_MOB_output_bits_fetch_PC.value),
                "branch_taken": int(self.MOB.io_MOB_output_bits_branch_taken.value),
                "target_address": int(self.MOB.io_MOB_output_bits_target_address.value),
                "branch_valid": int(self.MOB.io_MOB_output_bits_branch_valid.value),
                "address": int(self.MOB.io_MOB_output_bits_address.value),
                "memory_type": int(self.MOB.io_MOB_output_bits_memory_type.value),
                "access_width": int(self.MOB.io_MOB_output_bits_access_width.value),
                "is_unsigned": int(self.MOB.io_MOB_output_bits_is_unsigned.value),
                "wr_data": int(self.MOB.io_MOB_output_bits_wr_data.value),
                "MOB_index": int(self.MOB.io_MOB_output_bits_MOB_index.value),
                "ROB_index": int(self.MOB.io_MOB_output_bits_ROB_index.value),
                "fetch_packet_index": int(self.MOB.io_MOB_output_bits_fetch_packet_index.value),
            }
        }


    def read_commit(self):
        return {
            "valid": int(self.MOB.io_commit_valid.value),
            "bits": {
                "fetch_PC": int(self.MOB.io_commit_bits_fetch_PC.value),
                "T_NT": int(self.MOB.io_commit_bits_T_NT.value),
                "ROB_index": int(self.MOB.io_commit_bits_ROB_index.value),
                "br_type": int(self.MOB.io_commit_bits_br_type.value),
                "fetch_packet_index": int(self.MOB.io_commit_bits_fetch_packet_index.value),
                "is_misprediction": int(self.MOB.io_commit_bits_is_misprediction.value),
                "expected_PC": int(self.MOB.io_commit_bits_expected_PC.value),
                "GHR": int(self.MOB.io_commit_bits_GHR.value),
                "TOS": int(self.MOB.io_commit_bits_TOS.value),
                "NEXT": int(self.MOB.io_commit_bits_NEXT.value),
                "free_list_front_pointer": int(self.MOB.io_commit_bits_free_list_front_pointer.value),
                "RDold": [int(getattr(self.MOB, f"io_commit_bits_RDold_{i}").value) for i in range(4)],
                "RD": [int(getattr(self.MOB, f"io_commit_bits_RD_{i}").value) for i in range(4)],
                "RD_valid": [int(getattr(self.MOB, f"io_commit_bits_RD_valid_{i}").value) for i in range(4)],
            }
        }



    async def update(self):


        # each output packet has a fetch_packet_index and a ROB index
        # use this info to reconstruct the stream of instructions

        # when a fetch packet commits, move it from the response queue thing
        # to a committed queue. The MOB can output a response for a certain instruction many times
        # whenever this happens, just update the entry


        # every cycle compare theorical responses to comitted responses. 

        if(self.read_MOB_outputs()["valid"]):

            # every time the MOB outputs a result, place it in an entry that corresponds to that
            # ROB index (ie, reconstruct the results of the fetch packet)

            MOB_output = self.read_MOB_outputs()
            #print(MOB_output)
            #print(self.MOB_results[0])
            ROB_index = MOB_output["bits"]["ROB_index"]
            fetch_packet_index = MOB_output["bits"]["fetch_packet_index"]
            self.MOB_results[ROB_index][fetch_packet_index] = MOB_output
            #print(self.MOB_results[ROB_index][0])
            #print(self.MOB_results[ROB_index][1])
            #print(self.MOB_results[ROB_index][2])
            #print(self.MOB_results[ROB_index][3])

            # Found MOB output
            #print("======================")
            #print(f"Found MOB output")
            #print(f"MOB INDEX {MOB_output["bits"]["MOB_index"]}")
            #print(f"ROB INDEX {MOB_output["bits"]["ROB_index"]}")
            #print(f"FETCH PACKET INDEX {MOB_output["bits"]["fetch_packet_index"]}")
            #print("======================")



        if(self.read_commit()["valid"]):
            ## remove entry from MOB_results and place into commit entry queue
            ## MOB ROB index
            ROB_index = self.read_commit()["bits"]["ROB_index"]

            #print(f"committing {ROB_index}")

            self.committed_MOB_results.append(self.MOB_results[ROB_index])
            self.MOB_results[ROB_index] =[{
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
                "violation": 0,
                "memory_violation": 0,
            
        }} for _ in range(4)]

            #print("==========")
            #print(f"Committing MOB entry {ROB_index}")
            ##print(f"{self.MOB_results[ROB_index]}")
            #print(f"ENTRY 0 {self.committed_MOB_results[-1][0]}")
            #print(f"ENTRY 1 {self.committed_MOB_results[-1][1]}")
            #print(f"ENTRY 2 {self.committed_MOB_results[-1][2]}")
            #print(f"ENTRY 3 {self.committed_MOB_results[-1][3]}")
            #print("==========")






        ## compare against theoretical output 
        if len(self.committed_MOB_results) and len(self.reference_memory_accesses):
            got = self.committed_MOB_results.pop(0)
            expected = self.reference_memory_accesses.pop(0)
            #print(f"expected {expected} =?= got {got}")
            try:
                for i in range(4):
                    assert expected[i]["addr"] == got[i]["bits"]["address"]
                    assert expected[i]["data"] == got[i]["bits"]["RD_data"]

                print(f"Passed fetch packet {self.commit_counter}")
                self.commit_counter += 1

            except(AssertionError):
                print("== EXPECTED ==")
                for i in range(4):
                    print(f"MEM[{hex(expected[i]["addr"])}] = {hex(expected[i]["data"])}")
                print("== GOT ==")
                for i in range(4):
                    print(f"MEM[{hex(got[i]["bits"]["address"])}] = {hex(got[i]["bits"]["RD_data"])}")

                #await RisingEdge(self.MOB.clock)
                #await RisingEdge(self.MOB.clock)
                #await RisingEdge(self.MOB.clock)
                assert False

