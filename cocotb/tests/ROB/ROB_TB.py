
import cocotb
from cocotb.triggers import RisingEdge, ReadOnly
from enum import Enum
import random

from model_utils import *
from cocotb_utils import *



class ROB_TB:
    def __init__(self, dut):
        # Top level Module #
        self.ROB = dut

        self.model_ROB = [0]*64 # this stores the models ROB entries
        self.ROB_front_pointer = 0
        self.ROB_back_pointer = 0


        #########
        # POOLS #
        #########

        self.FU0_pool = []
        self.FU1_pool = []
        self.FU2_pool = []
        self.FU3_pool = []


        ##########
        # QUEUES #
        ##########

        self.ROB_packet_queue = []

        self.FU0_queue = []
        self.FU1_queue = []
        self.FU2_queue = []
        self.FU3_queue = []

        self.dut_commit_queue = []
        self.model_commit_queue = []



    #################
    # RESET & CLOCK #
    #################

    async def reset(self):
        self.ROB.reset.value = 1
        await self.clock()
        await self.clock()
        self.ROB.reset.value = 0
        await self.clock()

    async def clock(self):
        await RisingEdge(self.ROB.clock)


    def read_ROB_packet(self):
        ROB_packet = {
            "valid": 0,
            "ready": 0,
            "bits": {
                "decoded_instruction": [{
                    "ready_bits": {
                        "RS1_ready": getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_ready_bits_RS1_ready").value,
                        "RS2_ready": getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_ready_bits_RS2_ready").value
                    },
                    "RD": getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_RDold").value,
                    "PRD": getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_RD").value,
                    "RD_valid": getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_RD_valid").value,
                    "RS1": getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_RS1").value,
                    "RS1_valid": getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_RS1_valid").value,
                    "RS2": getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_RS2").value,
                    "RS2_valid": getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_RS2_valid").value,
                    "IMM": getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_IMM").value,
                    "FUNCT3": getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_FUNCT3").value,
                    "packet_index": getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_packet_index").value,
                    "ROB_index": getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_ROB_index").value,
                    "MOB_index": getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_MOB_index").value,
                    "instructionType": getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_instructionType").value,
                    "portID": getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_portID").value,
                    "RS_type": getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_RS_type").value,
                    "needs_ALU": getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_needs_ALU").value,
                    "needs_branch_unit": getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_needs_branch_unit").value,
                    "needs_CSRs": getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_needs_CSRs").value,
                    "SUBTRACT": getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_SUBTRACT").value,
                    "MULTIPLY": getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_MULTIPLY").value,
                    "IS_IMM": getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_IS_IMM").value,
                    "memory_type": getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_memory_type").value
                } for i in range(4)],
                "valid_bits": [
                    getattr(self.ROB, f"io_ROB_packet_bits_valid_bits_{i}").value for i in range(4)
                ],
                "GHR": self.ROB.io_ROB_packet_bits_GHR.value,
                "TOS": self.ROB.io_ROB_packet_bits_TOS.value,
                "NEXT": self.ROB.io_ROB_packet_bits_NEXT.value,
                "prediction": {
                    "hit": self.ROB.io_ROB_packet_bits_prediction_hit.value,
                    "target": self.ROB.io_ROB_packet_bits_prediction_target.value,
                    "br_type": self.ROB.io_ROB_packet_bits_prediction_br_type.value,
                    "GHR": self.ROB.io_ROB_packet_bits_prediction_GHR.value,
                    "T_NT": self.ROB.io_ROB_packet_bits_prediction_T_NT.value,
                    "free_list_front_pointer": self.ROB.io_ROB_packet_bits_free_list_front_pointer.value
                }
            }
        }
        return ROB_packet

    def generate_ROB_packet(self):
        #val BRANCH      = Value("b11000".U)
        #val JALR        = Value("b11001".U)
        #val JAL         = Value("b11011".U)
        
        #val LOAD        = Value("b00000".U)
        #val STORE       = Value("b01000".U)

        is_branch = random.randint(0, 1)
        is_mem = random.randint(0, 1-is_branch)
        memory_type = 0

        instruction_type = 0
        if(is_mem):
            memory_type = random.choice([1, 2])
            if(memory_type == 1):
                instruction_type = 0b0
            else:
                instruction_type = 0b01000


        port = random.randint(0,3)
        if(is_branch):
            port = 0
            instruction_type = random.choice([0b11000, 0b11001, 0b11011])

        if(is_mem):
            port = 3



        ROB_packet = {
            "valid": random.randint(0, 1),
            "ready": 0,
            "bits": {
                "decoded_instruction": [{
                    "ready_bits": {
                        "RS1_ready": random.randint(0, 1),
                        "RS2_ready": random.randint(0, 1)
                    },
                    "RD": random.randint(0, 31),
                    "PRD": random.randint(0, 31),
                    "RD_valid": random.randint(0, 1),
                    "RS1": random.randint(0, 31),
                    "RS1_valid": random.randint(0, 1),
                    "RS2": random.randint(0, 31),
                    "RS2_valid": random.randint(0, 1),
                    "IMM": random.randint(0, 0xFFFF),
                    "FUNCT3": random.randint(0, 0xF),
                    "packet_index": i,
                    "ROB_index": 0,
                    "MOB_index": 0,
                    "instructionType": instruction_type,
                    "portID": port,
                    "RS_type": 0,
                    "needs_ALU": 0,
                    "needs_branch_unit": is_branch,
                    "needs_CSRs": 0,
                    "SUBTRACT": 0,
                    "MULTIPLY": 0,
                    "IS_IMM": 0,
                    "memory_type": memory_type
                } for i in range(4)],
                "valid_bits": [
                    0 for i in range(4)
                ],
                "GHR": random.randint(0, 0xFF),
                "TOS": random.randint(0, 0xF),
                "NEXT": random.randint(0, 0xF),
                "fetch_PC": random.randint(0, 1024)*0x10,
                "prediction": {
                    "hit": 0,
                    "target": 0,
                    "br_type": 0,
                    "GHR": 0,
                    "T_NT": 0,
                    "free_list_front_pointer": 0,
                }
            }
        }
        return ROB_packet




    def update_prediction(self, ROB_packet):

        expected_PC = 0
        if(ROB_packet["valid"]):
            for i in range(4):
                if(ROB_packet[i]["decoded_instruction"])



        pass

    


    def drivers(self):

        # generate entries for ROB packet
        generated_ROB_packet = self.generate_ROB_packet()

        # update prediction
        generated_ROB_packet = self.update_prediction(generated_ROB_packet)

        self.ROB_packet_queue.append(generated_ROB_packet)

        #################
        # DRIVE SIGNALS #
        #################

        # drive ROB packet
        write_signals(self.ROB, "ROB_packet", self.ROB_packet_queue[0])

        # drive FU
        try:write_signals(self.ROB, "FU_outputs_0", self.FU0_queue[0])
        except(IndexError):pass

        try:write_signals(self.ROB, "FU_outputs_1", self.FU1_queue[0])
        except(IndexError):pass

        try:write_signals(self.ROB, "FU_outputs_2", self.FU2_queue[0])
        except(IndexError):pass

        try:write_signals(self.ROB, "FU_outputs_3", self.FU3_queue[0])
        except(IndexError):pass



        #################
        # UPDATE QUEUES #
        #################

        ROB_packet_accepted = (extract_signals(self.ROB, "ROB_packet")["valid"] and extract_signals(self.dut, "ROB_packet")["ready"]) or extract_signals(self.dut, "ROB_packet")["ready"]

        # only update rob packet queue if accepted
        if(ROB_packet_accepted): self.ROB_packet_queue.pop(0)

        # FU always accepted
        try: self.FU0_queue.pop(0)
        except: pass

        try: self.FU1_queue.pop(0)
        except: pass

        try: self.FU2_queue.pop(0)
        except: pass

        try: self.FU3_queue.pop(0)
        except: pass





    def monitors(self):

        ######################
        # MONITOR ROB PACKET #
        ######################

        monitored_ROB_packet = extract_signals(self.ROB, "ROB_packet")
        if(monitored_ROB_packet["valid"] and monitored_ROB_packet["ready"]):
            self.model_ROB[self.ROB_back_pointer%64] = monitored_ROB_packet
            self.ROB_back_pointer += 1


        # TODO: based on the monitored FU values, insert elements to the FU port pools


        ##############
        # MONITOR FU #
        ##############

        monitored_FU0 = extract_signals(self.ROB, "FU_outputs_0"); FU0_ROB_index = monitored_FU0["bits"]["ROB_index"]
        monitored_FU1 = extract_signals(self.ROB, "FU_outputs_1"); FU1_ROB_index = monitored_FU1["bits"]["ROB_index"]
        monitored_FU2 = extract_signals(self.ROB, "FU_outputs_2"); FU2_ROB_index = monitored_FU2["bits"]["ROB_index"]
        monitored_FU3 = extract_signals(self.ROB, "FU_outputs_3"); FU3_ROB_index = monitored_FU3["bits"]["ROB_index"]


        if(monitored_FU0["valid"]):
            self.model_ROB[FU0_ROB_index]

        if(monitored_FU1["valid"]):
            self.model_ROB[FU1_ROB_index]

        if(monitored_FU2["valid"]):
            self.model_ROB[FU2_ROB_index]

        if(monitored_FU3["valid"]):
            self.model_ROB[FU3_ROB_index]


        # check for model commit, update if it occurred



        ##################
        # MONITOR COMMIT #
        ##################

        monitored_commit = extract_signals(self.ROB, "commit")

        if(monitored_commit["valid"]):
            self.dut_commit_queue.append(monitored_commit)




    def checkers(self):


        # Compare dut commit to model commit

        pass


    async def verify(self):

        for _ in range(10000):
            self.checkers()
            #self.drivers()
            #self.monitors()

            await self.clock()