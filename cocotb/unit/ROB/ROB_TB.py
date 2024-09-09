
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

        self.model_ROB = [{
            # shared ROB info
            "valid" : 0,
            "fetch_PC": 0,
            #"expected_PC": 0,
            #"GHR":0, 
            # etc...

            # FU entries
            "bits":[{
                "complete":0,
                "valid" : 0,    # ROB row valid
                #"PRD" : 0,
                #"RD_data" : 0,
                #"RD_valid" :0,
                #"fetch_PC" : 0,
                #"branch_taken" :0,
                #"target_address" :0,
                #"branch_valid" : 0,
                #"address" : 0,
                #"memory_type" : 0,
                #"access_width" :0,
                #"is_unasigned" :0,
                #"wr_data" : 0,
                #"MOB_index" : 0,
                #"ROB_index" : 0,
                #"fetch_packet_index" :0
            } for i in range(4)]
        } for i in range(64)]

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
        self.dut_partial_commit_queue = []
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
            "valid": getattr(self.ROB, f"io_ROB_packet_valid").value,
            "ready": getattr(self.ROB, f"io_ROB_packet_ready").value,
            "bits": {
                "decoded_instruction": [{
                    "ready_bits": {
                        "RS1_ready": getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_ready_bits_RS1_ready").value,
                        "RS2_ready": getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_ready_bits_RS2_ready").value
                    },
                    "RD": getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_PRDold").value,
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
                "fetch_PC": self.ROB.io_ROB_packet_bits_fetch_PC.value,
                "prediction": {
                    #"hit": self.ROB.io_ROB_packet_bits_prediction_hit.value,
                    "target": self.ROB.io_ROB_packet_bits_prediction_target.value,
                    "br_type": self.ROB.io_ROB_packet_bits_prediction_br_type.value,
                    #"GHR": self.ROB.io_ROB_packet_bits_prediction_GHR.value,
                    "T_NT": self.ROB.io_ROB_packet_bits_prediction_T_NT.value,
                    "free_list_front_pointer": self.ROB.io_ROB_packet_bits_free_list_front_pointer.value
                }
            }
        }
        return ROB_packet

    def write_ROB_packet(self, ROB_packet):
        getattr(self.ROB, "io_ROB_packet_valid").value = ROB_packet["valid"]
        getattr(self.ROB, "io_ROB_packet_bits_fetch_PC").value = ROB_packet["bits"]["fetch_PC"]
        for i in range(4):
            #getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_ready_bits_RS1_ready").value             = ROB_packet["bits"]["decoded_instruction"][i]["ready_bits"]["RS1_ready"][i]
            #getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_ready_bits_RS2_ready").value             = ROB_packet["bits"]["decoded_instruction"][i]["ready_bits"]["RS2_ready"][i]
            getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_RD").value               = ROB_packet["bits"]["decoded_instruction"][i]["RD"]
            getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_PRD").value              = ROB_packet["bits"]["decoded_instruction"][i]["PRD"]
            #getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_PRDold").value           = ROB_packet["bits"]["decoded_instruction"][i]["PRDold"]
            getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_RD_valid").value         = ROB_packet["bits"]["decoded_instruction"][i]["RD_valid"]
            getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_RS1").value              = ROB_packet["bits"]["decoded_instruction"][i]["RS1"]
            #getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_RS1_valid").value        = ROB_packet["bits"]["decoded_instruction"][i]["RS1_valid"]
            getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_RS2").value              = ROB_packet["bits"]["decoded_instruction"][i]["RS2"]
            #getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_RS2_valid,").value       = ROB_packet["bits"]["decoded_instruction"][i]["RS2_valid"]
            getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_IMM").value              = ROB_packet["bits"]["decoded_instruction"][i]["IMM"]
            #getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_FUNCT3").value           = ROB_packet["bits"]["decoded_instruction"][i]["FUNCT3"]
            getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_packet_index").value     = ROB_packet["bits"]["decoded_instruction"][i]["packet_index"]
            getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_ROB_index").value        = ROB_packet["bits"]["decoded_instruction"][i]["ROB_index"]
            getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_MOB_index").value        = ROB_packet["bits"]["decoded_instruction"][i]["MOB_index"]
            getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_instructionType").value  = ROB_packet["bits"]["decoded_instruction"][i]["instructionType"]
            getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_portID").value           = ROB_packet["bits"]["decoded_instruction"][i]["portID"]
            getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_RS_type").value          = ROB_packet["bits"]["decoded_instruction"][i]["RS_type"]
            getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_needs_ALU").value        = ROB_packet["bits"]["decoded_instruction"][i]["needs_ALU"]
            getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_needs_branch_unit").value= ROB_packet["bits"]["decoded_instruction"][i]["needs_branch_unit"]
            getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_needs_CSRs").value       = ROB_packet["bits"]["decoded_instruction"][i]["needs_CSRs"]
            getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_SUBTRACT").value         = ROB_packet["bits"]["decoded_instruction"][i]["SUBTRACT"]
            getattr(self.ROB, f"io_ROB_packet_bits_valid_bits_{i}").value                           = ROB_packet["bits"]["valid_bits"][i]
            getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_MULTIPLY").value         = ROB_packet["bits"]["decoded_instruction"][i]["MULTIPLY"]
            getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_IS_IMM").value           = ROB_packet["bits"]["decoded_instruction"][i]["IS_IMM"]
            getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_memory_type").value      = ROB_packet["bits"]["decoded_instruction"][i]["memory_type"]

            getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_memory_type").value      = ROB_packet["bits"]["decoded_instruction"][i]["memory_type"]

            #getattr(self.ROB, f"io_ROB_packet_bits_prediction_hit").value                       =     ROB_packet["bits"]["prediction"]["hit"]
            getattr(self.ROB, f"io_ROB_packet_bits_prediction_target").value                    =     ROB_packet["bits"]["prediction"]["target"]
            getattr(self.ROB, f"io_ROB_packet_bits_prediction_br_type").value                   =     ROB_packet["bits"]["prediction"]["br_type"]
            getattr(self.ROB, f"io_ROB_packet_bits_prediction_T_NT").value                      =     ROB_packet["bits"]["prediction"]["T_NT"]


            #getattr(self.ROB, f"io_ROB_packet_bits_decoded_instruction_{i}_access_width").value     = ROB_packet["bits"]["decoded_instruction"][i]["access_width"]


    def read_partial_commit(self):
        return {
            "valid":    [getattr(self.ROB, f"io_partial_commit_valid_{i}").value for i in range(4)],
            "ROB_index": getattr(self.ROB, f"io_partial_commit_ROB_index").value,
            "MOB_index": [getattr(self.ROB, f"io_partial_commit_MOB_index_{i}").value for i in range(4)],
            "MOB_valid": [getattr(self.ROB, f"io_partial_commit_MOB_valid_{i}").value for i in range(4)],
            "commit_RD": [getattr(self.ROB, f"io_partial_commit_RD_{i}").value for i in range(4)],
            "RD_valid":  [getattr(self.ROB, f"io_partial_commit_RD_valid_{i}").value for i in range(4)],
            "PRD":       [getattr(self.ROB, f"io_partial_commit_PRD_{i}").value for i in range(4)],
            "PRDold":    [getattr(self.ROB, f"io_partial_commit_PRDold_{i}").value for i in range(4)],
        }

    def read_commit(self):
        return{
            "valid":self.ROB.io_commit_valid.value,
            "fetch_PC":self.ROB.io_commit_bits_fetch_PC.value,
            "T_NT":self.ROB.io_commit_bits_T_NT.value,
            "ROB_index":self.ROB.io_commit_bits_ROB_index.value,
            "br_type":self.ROB.io_commit_bits_br_type.value,
            "fetch_packet_index":self.ROB.io_commit_bits_fetch_packet_index.value,
            "is_misprediction":self.ROB.io_commit_bits_is_misprediction.value,
            "expected_PC":self.ROB.io_commit_bits_expected_PC.value,
            "GHR":self.ROB.io_commit_bits_GHR.value,
            "TOS":self.ROB.io_commit_bits_TOS.value,
            "NEXT":self.ROB.io_commit_bits_NEXT.value,
            "free_list_front_pointer":self.ROB.io_commit_bits_free_list_front_pointer.value,
            "RD":[self.ROB.io_commit_bits_RD_0.value for i in range(4)],
            "PRD":[self.ROB.io_commit_bits_PRD_0.value for i in range(4)],
            "RD_valid":[self.ROB.io_commit_bits_RD_valid_0.value for i in range(4)],
        }




    def generate_ROB_packet(self):
        #val BRANCH      = Value("b11000".U)
        #val JALR        = Value("b11001".U)
        #val JAL         = Value("b11011".U)
        
        #val LOAD        = Value("b00000".U)
        #val STORE       = Value("b01000".U)

        is_branch = 0#random.randint(0, 1)
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
                    "PRD": random.randint(0, 65),
                    "RD_valid": random.randint(0, 1),
                    "RS1": random.randint(0, 65),
                    "RS1_valid": random.randint(0, 1),
                    "RS2": random.randint(0, 65),
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
                    random.randint(0, 1) for i in range(4)
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

    def read_ROB_index(self):
        return int(getattr(self.ROB, f"io_ROB_index").value)

    def read_FUs(self):

        return [{
            "valid" : getattr(self.ROB, f"io_FU_outputs_{i}_valid").value,
            "bits":{
                "PRD" : getattr(self.ROB, f"io_FU_outputs_{i}_bits_PRD").value,
                "RD_data" : getattr(self.ROB, f"io_FU_outputs_{i}_bits_RD_data").value,
                "RD_valid" : getattr(self.ROB, f"io_FU_outputs_{i}_bits_RD_valid").value,
                "fetch_PC" : getattr(self.ROB, f"io_FU_outputs_{i}_bits_fetch_PC").value,
                "branch_taken" : getattr(self.ROB, f"io_FU_outputs_{i}_bits_branch_taken").value,
                "target_address" : getattr(self.ROB, f"io_FU_outputs_{i}_bits_target_address").value,
                "branch_valid" : getattr(self.ROB, f"io_FU_outputs_{i}_bits_branch_valid").value,
                "address" : getattr(self.ROB, f"io_FU_outputs_{i}_bits_address").value,
                "memory_type" : getattr(self.ROB, f"io_FU_outputs_{i}_bits_memory_type").value,
                "access_width" : getattr(self.ROB, f"io_FU_outputs_{i}_bits_access_width").value,
                "is_unasigned" : getattr(self.ROB, f"io_FU_outputs_{i}_bits_is_unsigned").value,
                "wr_data" : getattr(self.ROB, f"io_FU_outputs_{i}_bits_wr_data").value,
                "MOB_index" : getattr(self.ROB, f"io_FU_outputs_{i}_bits_MOB_index").value,
                "ROB_index" : getattr(self.ROB, f"io_FU_outputs_{i}_bits_ROB_index").value,
                "fetch_packet_index" : getattr(self.ROB, f"io_FU_outputs_{i}_bits_fetch_packet_index").value,
            }
        } for i in range(4)]

    def write_FU(self, FU, index):
        getattr(self.ROB, f"io_FU_outputs_{index}_valid").value                = FU["valid"]
        getattr(self.ROB, f"io_FU_outputs_{index}_bits_PRD").value             = int(FU["bits"]["PRD"])
        getattr(self.ROB, f"io_FU_outputs_{index}_bits_RD_data").value         = int(FU["bits"]["RD_data"])
        getattr(self.ROB, f"io_FU_outputs_{index}_bits_RD_valid").value        = int(FU["bits"]["RD_valid"])
        getattr(self.ROB, f"io_FU_outputs_{index}_bits_fetch_PC").value        = int(FU["bits"]["fetch_PC"])
        getattr(self.ROB, f"io_FU_outputs_{index}_bits_branch_taken").value    = int(FU["bits"]["branch_taken"])
        getattr(self.ROB, f"io_FU_outputs_{index}_bits_target_address").value  = int(FU["bits"]["target_address"])
        getattr(self.ROB, f"io_FU_outputs_{index}_bits_branch_valid").value    = int(FU["bits"]["branch_valid"])
        getattr(self.ROB, f"io_FU_outputs_{index}_bits_address").value         = int(FU["bits"]["address"])
        getattr(self.ROB, f"io_FU_outputs_{index}_bits_memory_type").value     = int(FU["bits"]["memory_type"])
        getattr(self.ROB, f"io_FU_outputs_{index}_bits_access_width").value    = int(FU["bits"]["access_width"])
        #getattr(self.ROB, f"io_FU_outputs_{index}_bits_is_unsigned").value     = int(FU["bits"]["is_unsigned"])
        getattr(self.ROB, f"io_FU_outputs_{index}_bits_wr_data").value         = int(FU["bits"]["wr_data"])
        getattr(self.ROB, f"io_FU_outputs_{index}_bits_MOB_index").value       = int(FU["bits"]["MOB_index"])
        getattr(self.ROB, f"io_FU_outputs_{index}_bits_ROB_index").value       = int(FU["bits"]["ROB_index"])
        getattr(self.ROB, f"io_FU_outputs_{index}_bits_fetch_packet_index").value              = int(FU["bits"]["fetch_packet_index"])





    def compute_FU(self, decoded_instruction):
        FU_input = {
            "valid":1,
            "bits": {
                "PRD" : decoded_instruction["PRD"],
                "RD_data" : 0, 
                "RD_valid" :  0, 
                "fetch_PC" : 0,
                "branch_taken" : 0,
                "target_address" : 0,
                "branch_valid" : 0,
                "address" : 0,
                "memory_type" : 0,
                "access_width" : 0,
                "is_unsigned" : 0,
                "wr_data" : 0,
                "MOB_index" : 0,
                "ROB_index" : self.read_ROB_index(),
                "fetch_packet_index" : decoded_instruction["packet_index"],
            }
        }

        return FU_input


    def update_prediction(self, ROB_packet):

        #expected_PC = 0
        #if(ROB_packet["valid"]):
            #for i in range(4):
                #if(ROB_packet[i]["decoded_instruction"]):
                    #pass

        return ROB_packet

    


    def drivers(self):

        # CLEAR inputs #

        for i in range(4):
            self.write_FU(
                {
                "valid" : 0,
                "bits" : {
                    "PRD": 0,
                    "RD_data": 0,
                    "RD_valid": 0,
                    "fetch_PC": 0,
                    "branch_taken": 0,
                    "target_address": 0,
                    "branch_valid": 0,
                    "address": 0,
                    "memory_type": 0,
                    "access_width": 0,
                    "is_unsigned": 0,
                    "wr_data": 0,
                    "MOB_index": 0,
                    "ROB_index": 0,
                    "fetch_packet_index": 0,
                }
                }, i)

            

        self.write_ROB_packet({
            "valid": 0,
            "ready": 0,
            "bits": {
                "decoded_instruction": [{
                    "ready_bits": {
                        "RS1_ready": 0,
                        "RS2_ready": 0,
                    },
                    "RD": 0,
                    "PRD": 0,
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
                    "instructionType": 0,
                    "portID": 0,
                    "RS_type": 0,
                    "needs_ALU": 0,
                    "needs_branch_unit": 0,
                    "needs_CSRs": 0,
                    "SUBTRACT": 0,
                    "MULTIPLY": 0,
                    "IS_IMM": 0,
                    "memory_type": 0
                } for i in range(4)],
                "valid_bits": [
                    0 for i in range(4)
                ],
                "GHR": 0,
                "TOS": 0,
                "NEXT": 0,
                "fetch_PC": 0,
                "prediction": {
                    "hit": 0,
                    "target": 0,
                    "br_type": 0,
                    "GHR": 0,
                    "T_NT": 0,
                    "free_list_front_pointer": 0,
                }
            }
        })







        # DRIVE inputs #

        # generate entries for ROB packet
        generated_ROB_packet = self.generate_ROB_packet()

        # update prediction
        generated_ROB_packet = self.update_prediction(generated_ROB_packet)

        self.ROB_packet_queue.append(generated_ROB_packet)


        if(random.randint(0, 1)):
            if self.FU0_pool:
                elem = random.choice(self.FU0_pool)
                self.FU0_pool.remove(elem)
                self.FU0_queue.append(elem)

            if self.FU1_pool:
                elem = random.choice(self.FU1_pool)
                self.FU1_pool.remove(elem)
                self.FU1_queue.append(elem)

            if self.FU2_pool:
                elem = random.choice(self.FU2_pool)
                self.FU2_pool.remove(elem)
                self.FU2_queue.append(elem)

            if self.FU3_pool:
                elem = random.choice(self.FU3_pool)
                self.FU3_pool.remove(elem)
                self.FU3_queue.append(elem)

        #################
        # DRIVE SIGNALS #
        #################

        # drive ROB packet
        self.write_ROB_packet(self.ROB_packet_queue[0])

        

        # drive FU
        try:self.write_FU(self.FU0_queue[0], 0)
        except(IndexError):pass

        try: self.write_FU(self.FU1_queue[0], 1)
        except(IndexError):pass

        try: self.write_FU(self.FU2_queue[0], 2)
        except(IndexError):pass

        try: self.write_FU(self.FU3_queue[0], 3)
        except(IndexError):pass

        #################
        # UPDATE QUEUES #
        #################

        ROB_packet_accepted = int(self.read_ROB_packet()["valid"]) and int(self.read_ROB_packet()["ready"])


        try: self.ROB_packet_queue.pop(0)
        except: pass

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

        monitored_ROB_packet = self.read_ROB_packet()
        if(monitored_ROB_packet["valid"] and monitored_ROB_packet["ready"]):
            self.model_ROB[self.ROB_back_pointer%64]["valid"] = 1
            self.model_ROB[self.ROB_back_pointer%64]["fetch_PC"] = monitored_ROB_packet["bits"]["fetch_PC"]
            self.ROB_back_pointer += 1

        # When a ROB packet is monitored, generate the expected FU output and append it to the FU pool
        if(monitored_ROB_packet["valid"] and monitored_ROB_packet["ready"]):

            for i in range(4):
                if(monitored_ROB_packet["bits"]["valid_bits"][i]):

                    FU_input = self.compute_FU(monitored_ROB_packet["bits"]["decoded_instruction"][i])



                    getattr(self, f"FU{i}_pool").append(FU_input)


        ##############
        # MONITOR FU #
        ##############
        # monitor the resolved FU inputs to the ROB

        read_FUs = self.read_FUs()

        monitored_FU0 = read_FUs[0]; FU0_ROB_index = monitored_FU0["bits"]["ROB_index"]; FU0_packet_index = int(monitored_FU0["bits"]["fetch_packet_index"])
        monitored_FU1 = read_FUs[1]; FU1_ROB_index = monitored_FU1["bits"]["ROB_index"]; FU1_packet_index = int(monitored_FU1["bits"]["fetch_packet_index"])
        monitored_FU2 = read_FUs[2]; FU2_ROB_index = monitored_FU2["bits"]["ROB_index"]; FU2_packet_index = int(monitored_FU2["bits"]["fetch_packet_index"])
        monitored_FU3 = read_FUs[3]; FU3_ROB_index = monitored_FU3["bits"]["ROB_index"]; FU3_packet_index = int(monitored_FU3["bits"]["fetch_packet_index"])


        if(monitored_FU0["valid"]):
            self.model_ROB[FU0_ROB_index]["bits"][FU0_packet_index]["complete"]= 1#monitored_FU0

        if(monitored_FU1["valid"]):
            self.model_ROB[FU1_ROB_index]["bits"][FU1_packet_index]["complete"]= 1#monitored_FU1

        if(monitored_FU2["valid"]):
            self.model_ROB[FU2_ROB_index]["bits"][FU2_packet_index]["complete"]= 1#monitored_FU2

        if(monitored_FU3["valid"]):
            self.model_ROB[FU3_ROB_index]["bits"][FU3_packet_index]["complete"]= 1#monitored_FU3

        # check for model commit, update if it occurred



        ##################
        # MONITOR COMMIT #
        ##################

        monitored_commit = self.read_commit()

        if(monitored_commit["valid"]):
            self.dut_commit_queue.append(monitored_commit)


        monitored_partial_commit = self.read_partial_commit()

        if(monitored_commit["valid"]):
            self.dut_partial_commit_queue.append(monitored_partial_commit)


    def checkers(self):

        # check for model commit
        row_valid = self.model_ROB[self.ROB_front_pointer % 64]["valid"]
        model_can_commit = row_valid
        for i in range(4):
            entry = self.model_ROB[self.ROB_front_pointer % 64]["bits"][i]
    
            if entry["valid"] and not entry["complete"]:
                model_can_commit = False
                break  # No need to check further if any valid entry is incomplete
        
        if(model_can_commit):
            self.model_commit_queue.append({
                "valid": 1,
                "ROB_index": self.ROB_front_pointer % 64,
                "fetch_PC": int(self.model_ROB[self.ROB_front_pointer%64]["fetch_PC"])
            })



            self.model_ROB[self.ROB_front_pointer%64] = {
                # shared ROB info
                "valid" : 0,    # ROB row valid
                "fetch_PC": 0,
                #"expected_PC": 0,
                #"GHR":0, 
                # etc...

                # FU entries
                "bits":[{
                    "complete":0,
                    "valid":0       # ROB entry valid
                    #"PRD" : 0,
                    #"RD_data" : 0,
                    #"RD_valid" :0,
                    #"fetch_PC" : 0,
                    #"branch_taken" :0,
                    #"target_address" :0,
                    #"branch_valid" : 0,
                    #"address" : 0,
                    #"memory_type" : 0,
                    #"access_width" :0,
                    #"is_unasigned" :0,
                    #"wr_data" : 0,
                    #"MOB_index" : 0,
                    #"ROB_index" : 0,
                    #"fetch_packet_index" :0
                } for i in range(4)]
            }

            self.ROB_front_pointer+=1
    


        # Compare dut commit to model commit
        if(len(self.dut_commit_queue)):
            dut_commit = self.dut_commit_queue[0]
            model_commit = self.model_commit_queue[0]
            #print(model_commit)
            #print(dut_commit)
            assert int(dut_commit["ROB_index"]) == int(model_commit["ROB_index"]), f"Model commit index {int(model_commit["ROB_index"])} =/= dut commit index {int(dut_commit["ROB_index"])}"
            assert int(dut_commit["fetch_PC"]) == int(model_commit["fetch_PC"]) , f"Model fetch PC {hex(int(model_commit["fetch_PC"]))} did not match {hex(int(dut_commit["fetch_PC"]))} did not match"


            self.dut_commit_queue.pop(0)
            assert self.model_commit_queue.pop(0), "dut committed but model did not. "


    async def verify(self):

        for _ in range(50_000):
            self.drivers()
            self.checkers()
            self.monitors()

            await self.clock()