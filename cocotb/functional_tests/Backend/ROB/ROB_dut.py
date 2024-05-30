import sys
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, FallingEdge, Timer

# Add helper functions as needed

def generateNullAllocate():
    allocate_inputs = {}
    allocate_inputs["valid"] = 0
    allocate_inputs["instruction_valid"] = [0]*4
    allocate_inputs["is_branch"]         = [0]*4
    return allocate_inputs

def generateNullFUInput():
    FU_inputs = {}

    FU_inputs["valid"]                  =   [0]*4
    FU_inputs["RD"]                     =   [0]*4
    FU_inputs["RD_data"]                =   [0]*4
    FU_inputs["RD_valid"]               =   [0]*4
    FU_inputs["instruction_PC"]         =   [0]*4
    FU_inputs["branch_taken"]           =   [0]*4
    FU_inputs["target_address"]         =   [0]*4
    FU_inputs["branch_valid"]           =   [0]*4
    FU_inputs["ROB_index"]              =   [0]*4
    FU_inputs["fetch_packet_index"]     =   [0]*4
    return FU_inputs

class ROB_dut:
    def __init__(self, dut):    # modify as needed (parameters, etc...)
        self.dut = dut

    def clock(self):            # Do not touch
        return self.dut.clock

    async def reset(self):      # Do not touch
        self.dut.reset.value = 0
        await RisingEdge(self.dut.clock)
        self.dut.reset.value = 1
        await RisingEdge(self.dut.clock)
        self.dut.reset.value = 0
        await RisingEdge(self.dut.clock)

    def send_allocate(self, allocate_inputs=generateNullAllocate()):

        self.dut.io_ROB_allocate_valid.value = allocate_inputs["valid"]
        for i in range(4):
            #io_ROB_allocate_bits_0_valid
            getattr(self.dut, f"io_ROB_allocate_bits_{i}_valid").value         =   allocate_inputs["instruction_valid"][i]
            getattr(self.dut, f"io_ROB_allocate_bits_{i}_is_branch").value     =   allocate_inputs["is_branch"][i]

    def send_FU(self, FU_inputs=generateNullFUInput()):
        # FU_inputs is an array of FU_input dicts

        for i in range(4):
            getattr(self.dut, f"io_FU_outputs_{i}_valid").value                     =   FU_inputs["valid"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_RD").value                   =   FU_inputs["RD"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_RD_data").value              =   FU_inputs["RD_data"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_RD_valid").value             =   FU_inputs["RD_valid"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_instruction_PC").value       =   FU_inputs["instruction_PC"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_branch_taken").value         =   FU_inputs["branch_taken"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_target_address").value       =   FU_inputs["target_address"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_branch_valid").value         =   FU_inputs["branch_valid"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_ROB_index").value            =   FU_inputs["ROB_index"][i]
            getattr(self.dut, f"io_FU_outputs_{i}_bits_fetch_packet_index").value   =   FU_inputs["fetch_packet_index"][i]

    def get_outputs(self):
        ROB_outputs = {}

        for i in range(4):
            ROB_outputs["valid"].append(getattr(self.dut, f"io_commit_{i}_valid").value)
            ROB_outputs["is_branch"].append(getattr(self.dut, f"io_commit_{i}_is_branch").value)

        return ROB_outputs

    def get_front_pointer(self):
        return int(self.dut.front_pointer.value)

    def get_back_pointer(self):
        return int(self.dut.back_pointer.value)

    def get_ROB_entry_row(self, row):
        mem=[]
        for i in range(4):
            mem.append(getattr(self.dut, f"ROB_entry_banks_{i}.mem_ext.Memory")[row].value)
        return mem

    def get_ROB_busy_row(self, row):
        mem=[]
        for i in range(4):
            mem.append((getattr(self.dut, f"ROB_busy_banks_{i}.mem_ext.Memory").value >> row) & 0b1)
        return mem

    def get_ROB_busy_banks(self):
        busy=[]
        for i in range(64):
            busy.append(self.get_ROB_busy_row(i))
        return busy

    def get_ROB_entry_banks(self):
        ROB=[]
        for i in range(64):
            ROB.append(self.get_ROB_entry_row(i))
        return ROB

    def print_ROB(self):
        ROB = self.get_ROB_entry_banks()
        for i in range(64):
            print(f"{ROB[i]}")

    def print_busy(self):
        busy = self.get_ROB_busy_banks()
        for i in range(64):
            print(f"{busy[i]}")
