import sys
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, ReadOnly


from enum import Enum

class memory_type_t(Enum):
    NONE = 0
    LOAD = 1
    STORE = 2

class access_width_t(Enum):
    NONE = 0
    B = 1  # Byte
    HW = 2 # Half-word
    W = 3  # Word


class MOB_dut:
    def __init__(self, dut):
        self.MOB = dut

        # Backend Modules #

    async def clock(self):  # Do not touch
        await RisingEdge(self.MOB.clock)

    async def reset(self):  # Do not touch
        await self.clock()
        self.MOB.reset.value = 1
        await self.clock()
        await self.clock()
        await self.clock()
        self.MOB.reset.value = 0

    def read_reset(self):
        return self.MOB.reset.value

    #############
    ## RESERVE ##
    #############


    def write_reserve(self, reserve):
        for i in range(4):
            setattr(self.MOB, f"io_reserve_{i}_valid", reserve[i]["valid"])
            setattr(self.MOB, f"io_reserve_{i}_bits_ready_bits_RS1_ready", reserve[i]["bits"]["ready_bits_RS1_ready"])
            setattr(self.MOB, f"io_reserve_{i}_bits_ready_bits_RS2_ready", reserve[i]["bits"]["ready_bits_RS2_ready"])
            setattr(self.MOB, f"io_reserve_{i}_bits_RDold", reserve[i]["bits"]["RDold"])
            setattr(self.MOB, f"io_reserve_{i}_bits_RD", reserve[i]["bits"]["RD"])
            setattr(self.MOB, f"io_reserve_{i}_bits_RD_valid", reserve[i]["bits"]["RD_valid"])
            setattr(self.MOB, f"io_reserve_{i}_bits_RS1", reserve[i]["bits"]["RS1"])
            setattr(self.MOB, f"io_reserve_{i}_bits_RS1_valid", reserve[i]["bits"]["RS1_valid"])
            setattr(self.MOB, f"io_reserve_{i}_bits_RS2", reserve[i]["bits"]["RS2"])
            setattr(self.MOB, f"io_reserve_{i}_bits_RS2_valid", reserve[i]["bits"]["RS2_valid"])
            setattr(self.MOB, f"io_reserve_{i}_bits_IMM", reserve[i]["bits"]["IMM"])
            setattr(self.MOB, f"io_reserve_{i}_bits_FUNCT3", reserve[i]["bits"]["FUNCT3"])
            setattr(self.MOB, f"io_reserve_{i}_bits_packet_index", reserve[i]["bits"]["packet_index"])
            setattr(self.MOB, f"io_reserve_{i}_bits_ROB_index", reserve[i]["bits"]["ROB_index"])
            setattr(self.MOB, f"io_reserve_{i}_bits_MOB_index", reserve[i]["bits"]["MOB_index"])
            setattr(self.MOB, f"io_reserve_{i}_bits_FTQ_index", reserve[i]["bits"]["FTQ_index"])
            setattr(self.MOB, f"io_reserve_{i}_bits_instructionType", reserve[i]["bits"]["instructionType"])
            setattr(self.MOB, f"io_reserve_{i}_bits_portID", reserve[i]["bits"]["portID"])
            setattr(self.MOB, f"io_reserve_{i}_bits_RS_type", reserve[i]["bits"]["RS_type"])
            setattr(self.MOB, f"io_reserve_{i}_bits_needs_ALU", reserve[i]["bits"]["needs_ALU"])
            setattr(self.MOB, f"io_reserve_{i}_bits_needs_branch_unit", reserve[i]["bits"]["needs_branch_unit"])
            setattr(self.MOB, f"io_reserve_{i}_bits_needs_CSRs", reserve[i]["bits"]["needs_CSRs"])
            setattr(self.MOB, f"io_reserve_{i}_bits_SUBTRACT", reserve[i]["bits"]["SUBTRACT"])
            setattr(self.MOB, f"io_reserve_{i}_bits_MULTIPLY", reserve[i]["bits"]["MULTIPLY"])
            setattr(self.MOB, f"io_reserve_{i}_bits_IS_IMM", reserve[i]["bits"]["IS_IMM"])
            setattr(self.MOB, f"io_reserve_{i}_bits_memory_type", reserve[i]["bits"]["memory_type"])
            setattr(self.MOB, f"io_reserve_{i}_bits_access_width", reserve[i]["bits"]["access_width"])





  #output        io_reserved_pointers_0_valid,
  #output [3:0]  io_reserved_pointers_0_bits,
  #output        io_reserved_pointers_1_valid,
  #output [3:0]  io_reserved_pointers_1_bits,
  #output        io_reserved_pointers_2_valid,
  #output [3:0]  io_reserved_pointers_2_bits,
  #output        io_reserved_pointers_3_valid,
  #output [3:0]  io_reserved_pointers_3_bits,

    def read_reserve(self, reserve):
        reserve = [{} for _ in range(4)]

        for i in range(4):
            reserve[i] = {
                "ready": int(getattr(self.MOB, f"io_reserve_{i}_ready").value),
                "valid": int(getattr(self.MOB, f"io_reserve_{i}_valid").value),
                "bits": {
                    "ready_bits_RS1_ready": int(getattr(self.MOB, f"io_reserve_{i}_bits_ready_bits_RS1_ready").value),
                    "ready_bits_RS2_ready": int(getattr(self.MOB, f"io_reserve_{i}_bits_ready_bits_RS2_ready").value),
                    "RDold": int(getattr(self.MOB, f"io_reserve_{i}_bits_RDold").value),
                    "RD": int(getattr(self.MOB, f"io_reserve_{i}_bits_RD").value),
                    "RD_valid": int(getattr(self.MOB, f"io_reserve_{i}_bits_RD_valid").value),
                    "RS1": int(getattr(self.MOB, f"io_reserve_{i}_bits_RS1").value),
                    "RS1_valid": int(getattr(self.MOB, f"io_reserve_{i}_bits_RS1_valid").value),
                    "RS2": int(getattr(self.MOB, f"io_reserve_{i}_bits_RS2").value),
                    "RS2_valid": int(getattr(self.MOB, f"io_reserve_{i}_bits_RS2_valid").value),
                    "IMM": int(getattr(self.MOB, f"io_reserve_{i}_bits_IMM").value),
                    "FUNCT3": int(getattr(self.MOB, f"io_reserve_{i}_bits_FUNCT3").value),
                    "packet_index": int(getattr(self.MOB, f"io_reserve_{i}_bits_packet_index").value),
                    "ROB_index": int(getattr(self.MOB, f"io_reserve_{i}_bits_ROB_index").value),
                    "MOB_index": int(getattr(self.MOB, f"io_reserve_{i}_bits_MOB_index").value),
                    "FTQ_index": int(getattr(self.MOB, f"io_reserve_{i}_bits_FTQ_index").value),
                    "instructionType": int(getattr(self.MOB, f"io_reserve_{i}_bits_instructionType").value),
                    "portID": int(getattr(self.MOB, f"io_reserve_{i}_bits_portID").value),
                    "RS_type": int(getattr(self.MOB, f"io_reserve_{i}_bits_RS_type").value),
                    "needs_ALU": int(getattr(self.MOB, f"io_reserve_{i}_bits_needs_ALU").value),
                    "needs_branch_unit": int(getattr(self.MOB, f"io_reserve_{i}_bits_needs_branch_unit").value),
                    "needs_CSRs": int(getattr(self.MOB, f"io_reserve_{i}_bits_needs_CSRs").value),
                    "SUBTRACT": int(getattr(self.MOB, f"io_reserve_{i}_bits_SUBTRACT").value),
                    "MULTIPLY": int(getattr(self.MOB, f"io_reserve_{i}_bits_MULTIPLY").value),
                    "IS_IMM": int(getattr(self.MOB, f"io_reserve_{i}_bits_IS_IMM").value),
                    "memory_type": int(getattr(self.MOB, f"io_reserve_{i}_bits_memory_type").value),
                    "access_width": int(getattr(self.MOB, f"io_reserve_{i}_bits_access_width").value),
                }
            }
        return reserve



    def read_reserved_pointers(self):
        reserve = [{} for _ in range(4)]

        for i in range(4):
            reserve[i] = {
                "valid": int(getattr(self.MOB, f"io_reserved_pointers_{i}_valid").value),
                "bits": int(getattr(self.MOB, f"io_reserved_pointers_{i}_bits").value),
            }
        return reserve


                #io_flush,

    def write_AGU_output(self, AGU):
        setattr(self.MOB, f"io_AGU_output_valid", AGU["valid"])
        setattr(self.MOB, f"io_AGU_output_bits_RD", AGU["bits"]["RD"])
        setattr(self.MOB, f"io_AGU_output_bits_RD_data", AGU["bits"]["RD_data"])
        setattr(self.MOB, f"io_AGU_output_bits_RD_valid", AGU["bits"]["RD_valid"])
        setattr(self.MOB, f"io_AGU_output_bits_fetch_PC", AGU["bits"]["fetch_PC"])
        setattr(self.MOB, f"io_AGU_output_bits_branch_taken", AGU["bits"]["branch_taken"])
        setattr(self.MOB, f"io_AGU_output_bits_target_address", AGU["bits"]["target_address"])
        setattr(self.MOB, f"io_AGU_output_bits_branch_valid", AGU["bits"]["branch_valid"])
        setattr(self.MOB, f"io_AGU_output_bits_address", AGU["bits"]["address"])
        setattr(self.MOB, f"io_AGU_output_bits_memory_type", AGU["bits"]["memory_type"])
        setattr(self.MOB, f"io_AGU_output_bits_access_width", AGU["bits"]["access_width"])
        setattr(self.MOB, f"io_AGU_output_bits_is_unsigned", AGU["bits"]["is_unsigned"])
        setattr(self.MOB, f"io_AGU_output_bits_wr_data", AGU["bits"]["wr_data"])
        setattr(self.MOB, f"io_AGU_output_bits_MOB_index", AGU["bits"]["MOB_index"])
        setattr(self.MOB, f"io_AGU_output_bits_ROB_index", AGU["bits"]["ROB_index"])
        setattr(self.MOB, f"io_AGU_output_bits_FTQ_index", AGU["bits"]["FTQ_index"])
        setattr(self.MOB, f"io_AGU_output_bits_fetch_packet_index", AGU["bits"]["fetch_packet_index"])
        setattr(self.MOB, f"io_AGU_output_bits_violation", AGU["bits"]["violation"])



    def read_AGU_output(self):
        AGU = {
            "valid": int(self.MOB.io_AGU_output_valid.value),
            "bits": {
                "RD": int(self.MOB.io_AGU_output_bits_RD.value),
                "RD_data": int(self.MOB.io_AGU_output_bits_RD_data.value),
                "RD_valid": int(self.MOB.io_AGU_output_bits_RD_valid.value),
                "fetch_PC": int(self.MOB.io_AGU_output_bits_fetch_PC.value),
                "branch_taken": int(self.MOB.io_AGU_output_bits_branch_taken.value),
                "target_address": int(self.MOB.io_AGU_output_bits_target_address.value),
                "branch_valid": int(self.MOB.io_AGU_output_bits_branch_valid.value),
                "address": int(self.MOB.io_AGU_output_bits_address.value),
                "memory_type": int(self.MOB.io_AGU_output_bits_memory_type.value),
                "access_width": int(self.MOB.io_AGU_output_bits_access_width.value),
                "is_unsigned": int(self.MOB.io_AGU_output_bits_is_unsigned.value),
                "wr_data": int(self.MOB.io_AGU_output_bits_wr_data.value),
                "MOB_index": int(self.MOB.io_AGU_output_bits_MOB_index.value),
                "ROB_index": int(self.MOB.io_AGU_output_bits_ROB_index.value),
                "FTQ_index": int(self.MOB.io_AGU_output_bits_FTQ_index.value),
                "fetch_packet_index": int(self.MOB.io_AGU_output_bits_fetch_packet_index.value),
                "exception": int(self.MOB.io_AGU_output_bits_exception.value)
            }
        }
        return AGU


    def read_MOB_output(self):
        MOB_output = {
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
                "FTQ_index": int(self.MOB.io_MOB_output_bits_FTQ_index.value),
                "fetch_packet_index": int(self.MOB.io_MOB_output_bits_fetch_packet_index.value),
                "exception": int(self.MOB.io_MOB_output_bits_exception.value)
            }
        }
        return MOB_output

    def write_commit(self, commit):
        self.MOB.io_commit_valid = commit["valid"]
        self.MOB.io_commit_bits_fetch_PC.value = commit["bits"]["fetch_PC"]
        self.MOB.io_commit_bits_T_NT.value = commit["bits"]["T_NT"]
        self.MOB.io_commit_bits_ROB_index.value = commit["bits"]["ROB"]
        self.MOB.io_commit_bits_br_type.value = commit["bits"]["br_type"]
        self.MOB.io_commit_bits_fetch_packet_index.value = commit["bits"]["index"]
        self.MOB.io_commit_bits_is_misprediction.value = commit["bits"]["is_misprediction"]
        self.MOB.io_commit_bits_exception.value = commit["bits"]["exception"]
        self.MOB.io_commit_bits_expected_PC.value = commit["bits"]["expected_PC"]
        self.MOB.io_commit_bits_GHR.value = commit["bits"]["GHR"]
        self.MOB.io_commit_bits_TOS.value = commit["bits"]["TOS"]
        self.MOB.io_commit_bits_RDold_0.value = commit["bits"]["RDold_0"]
        self.MOB.io_commit_bits_RDold_1.value = commit["bits"]["RDold_1"]
        self.MOB.io_commit_bits_RDold_2.value = commit["bits"]["RDold_2"]
        self.MOB.io_commit_bits_RDold_3.value = commit["bits"]["RDold_3"]
        self.MOB.io_commit_bits_RD_0.value = commit["bits"]["RD_0"]
        self.MOB.io_commit_bits_RD_1.value = commit["bits"]["RD_1"]
        self.MOB.io_commit_bits_RD_2.value = commit["bits"]["RD_2"]
        self.MOB.io_commit_bits_RD_3.value = commit["bits"]["RD_3"]
        self.MOB.io_commit_bits_RD_valid_0.value = commit["bits"]["RD_valid_0"]
        self.MOB.io_commit_bits_RD_valid_1.value = commit["bits"]["RD_valid_1"]
        self.MOB.io_commit_bits_RD_valid_2.value = commit["bits"]["RD_valid_2"]
        self.MOB.io_commit_bits_RD_valid_3.value = commit["bits"]["RD_valid_3"]

    def read_commit(self):
        commit = {
            "valid": int(self.MOB.io_commit_valid.value),
            "bits": {
                "fetch_PC": int(self.MOB.io_commit_bits_fetch_PC.value),
                "T_NT": int(self.MOB.io_commit_bits_T_NT.value),
                "ROB": int(self.MOB.io_commit_bits_ROB_index.value),
                "br_type": int(self.MOB.io_commit_bits_br_type.value),
                "index": int(self.MOB.io_commit_bits_fetch_packet_index.value),
                "is_misprediction": int(self.MOB.io_commit_bits_is_misprediction.value),
                "exception": int(self.MOB.io_commit_bits_exception.value),
                "expected_PC": int(self.MOB.io_commit_bits_expected_PC.value),
                "GHR": int(self.MOB.io_commit_bits_GHR.value),
                "TOS": int(self.MOB.io_commit_bits_TOS.value),
                "RDold_0": int(self.MOB.io_commit_bits_RDold_0.value),
                "RDold_1": int(self.MOB.io_commit_bits_RDold_1.value),
                "RDold_2": int(self.MOB.io_commit_bits_RDold_2.value),
                "RDold_3": int(self.MOB.io_commit_bits_RDold_3.value),
                "RD_0": int(self.MOB.io_commit_bits_RD_0.value),
                "RD_1": int(self.MOB.io_commit_bits_RD_1.value),
                "RD_2": int(self.MOB.io_commit_bits_RD_2.value),
                "RD_3": int(self.MOB.io_commit_bits_RD_3.value),
                "RD_valid_0": int(self.MOB.io_commit_bits_RD_valid_0.value),
                "RD_valid_1": int(self.MOB.io_commit_bits_RD_valid_1.value),
                "RD_valid_2": int(self.MOB.io_commit_bits_RD_valid_2.value),
                "RD_valid_3": int(self.MOB.io_commit_bits_RD_valid_3.value)
            }
        }
        return commit



    def read_backend_memory_request(self):
        backend_memory_request = {
            "valid": self.MOB.io_backend_memory_request_valid.value,
            "ready": self.MOB.io_backend_memory_request_ready.value,
            "bits": {
                "addr": self.MOB.io_backend_memory_request_bits_addr.value,
                "data": self.MOB.io_backend_memory_request_bits_data.value,
                "memory_type": self.MOB.io_backend_memory_request_bits_memory_type.value,
                "access_width": self.MOB.io_backend_memory_request_bits_access_width.value,
                "MOB_index": self.MOB.io_backend_memory_request_bits_MOB_index.value,
            }
        }
        return backend_memory_request

    def write_backend_memory_response(self, backend_memory_response):
        setattr(self.MOB, "io_backend_memory_response_valid", backend_memory_response["valid"])
        setattr(self.MOB, "io_backend_memory_response_bits_addr", backend_memory_response["bits"]["addr"])
        setattr(self.MOB, "io_backend_memory_response_bits_data", backend_memory_response["bits"]["data"])
        setattr(self.MOB, "io_backend_memory_response_bits_MOB_index", backend_memory_response["bits"]["MOB_index"])

    def read_backend_memory_response(self):
        backend_memory_response = {
            "valid": self.MOB.io_backend_memory_response_valid.value,
            "ready": self.MOB.io_backend_memory_response_ready.value,
            "bits": {
                "addr": self.MOB.io_backend_memory_response_bits_addr.value,
                "data": self.MOB.io_backend_memory_response_bits_data.value,
                "MOB_index": self.MOB.io_backend_memory_response_bits_MOB_index.value,
            }
        }
        return backend_memory_response


  #input  [31:0] io_fetch_PC,