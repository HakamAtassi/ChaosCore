import sys
from cocotb.clock import Clock
from cocotb.triggers import RisingEdge, Timer

# Add helper functions as needed

def generateNullPrediction():
    prediction_inputs = {}

    prediction_inputs["input_valid"]            = 0
    prediction_inputs["entry_valid"]            = 0
    prediction_inputs["instruction_PC"]         = 0
    prediction_inputs["is_misprediction"]       = 0
    prediction_inputs["predicted_expected_PC"]  = 0
    prediction_inputs["GHR"]                    = 0
    prediction_inputs["NEXT"]                   = 0
    prediction_inputs["TOS"]                    = 0

    return prediction_inputs

def generateNullFUInput():
    FU_result = {}

    FU_result["RD"]                         =   0
    FU_result["RD_data"]                    =   0
    FU_result["RD_valid"]                   =   0
    FU_result["instruction_PC"]             =   0
    FU_result["branch_taken"]               =   0
    FU_result["target_address"]             =   0
    FU_result["branch_valid"]               =   0
    FU_result["ROB_index"]                  =   0
    FU_result["fetch_packet_index"]         =   0

    return FU_result

def generateNullCommit():
    commit_inputs = {}
    commit_inputs["valid"]       =   0
    commit_inputs["is_branch"]   =   0

    return commit_inputs

class FTQ_dut:
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

    # complete class body...

    # Suggestions: 

    def send_FU_result(self, FU_input): # Transmit input from branch FU
        self.dut.io_FU_output_RD.value                                        =   FU_input["RD"]
        self.dut.io_FU_output_RD_data.value                                   =   FU_input["RD_data"]
        self.dut.io_FU_output_RD_valid.value                                  =   FU_input["RD_valid"]
        self.dut.io_FU_output_instruction_PC.value                            =   FU_input["instruction_PC"]
        self.dut.io_FU_output_branch_taken.value                              =   FU_input["branch_taken"]
        self.dut.io_FU_output_target_address.value                            =   FU_input["target_address"]
        self.dut.io_FU_output_branch_valid.value                              =   FU_input["branch_valid"]
        self.dut.io_FU_output_ROB_index.value                                 =   FU_input["ROB_index"]
        self.dut.io_FU_output_fetch_packet_index.value                        =   FU_input["fetch_packet_index"]

    def send_frontend_prediction(self, prediction_inputs):  # buffer frontend prediction
    
        self.dut.io_branch_prediction_valid.value                             =   prediction_inputs["input_valid"]
        self.dut.io_branch_prediction_bits_valid.value                        =   prediction_inputs["entry_valid"]
        self.dut.io_branch_prediction_bits_instruction_PC.value               =   prediction_inputs["instruction_PC"]
        self.dut.io_branch_prediction_bits_is_misprediction.value             =   prediction_inputs["is_misprediction"]
        self.dut.io_branch_prediction_bits_predicted_expected_PC.value        =   prediction_inputs["predicted_expected_PC"]
        self.dut.io_branch_prediction_bits_GHR.value                          =   prediction_inputs["GHR"]
        self.dut.io_branch_prediction_bits_NEXT.value                         =   prediction_inputs["NEXT"]
        self.dut.io_branch_prediction_bits_TOS.value                          =   prediction_inputs["TOS"]


    def send_commit(self, commit_inputs):  # commit to frontend & check if misprediction.
        self.dut.io_commit_valid.value                              =   commit_inputs["valid"]
        self.dut.io_commit_is_branch.value                          =   commit_inputs["is_branch"]

    def get_outputs(self):
        outputs = {}
        outputs["ready"] = self.dut.io_branch_prediction_ready.value
        outputs["valid"] = self.dut.io_misprediction_valid.value
        outputs["is_misprediction"] = self.dut.io_misprediction_is_misprediction.value
        outputs["expected_PC"] = self.dut.io_misprediction_expected_PC.value
        outputs["GHR"] = self.dut.io_misprediction_GHR.value
        outputs["NEXT"] = self.dut.io_misprediction_NEXT.value
        outputs["TOS"] = self.dut.io_misprediction_TOS.value
        return outputs


    def get_FTQ_entry(self, i):
        FTQ_entry = {}
        FTQ_entry["valid"]                      = (int(getattr(self.dut, f"FTQ_{i}_valid").value))
        FTQ_entry["instruction_PC"]             = (int(getattr(self.dut, f"FTQ_{i}_instruction_PC").value))
        FTQ_entry["is_misprediction"]           = (int(getattr(self.dut, f"FTQ_{i}_is_misprediction").value))
        FTQ_entry["predicted_expected_PC"]      = (int(getattr(self.dut, f"FTQ_{i}_predicted_expected_PC").value))
        FTQ_entry["GHR"]                        = (int(getattr(self.dut, f"FTQ_{i}_GHR").value))
        FTQ_entry["NEXT"]                       = (int(getattr(self.dut, f"FTQ_{i}_NEXT").value))
        FTQ_entry["TOS"]                        = (int(getattr(self.dut, f"FTQ_{i}_TOS").value))
        return FTQ_entry

    def get_FTQ(self):
        FTQ=[]
        for i in range(16):
            FTQ.append(self.get_FTQ_entry(i))
        return FTQ

    def get_front_pointer(self):
        front_pointer = int(self.dut.front_pointer.value)
        return front_pointer
    
    def get_back_pointer(self):
        back_pointer = int(self.dut.back_pointer.value)
        return back_pointer

    def print_FTQ(self):
        FTQ = self.get_FTQ()
        print(f"{'Entry':<5} {'Valid':<5} {'Fetch PC':<10} {'Mispred':<9} {'Pred. PC':<10} {'GHR':<5} {'NEXT':<5} {'TOS':<5}")
        print("-" * 60)
        for i, entry in enumerate(FTQ):
            print(f"{i:<5} {hex(entry['valid']):<5} {hex(entry['instruction_PC']):<10} {hex(entry['is_misprediction']):<9} {hex(entry['predicted_expected_PC']):<10} {hex(entry['GHR']):<5} {hex(entry['NEXT']):<5} {hex(entry['TOS']):<5}")

        print(f"Front pointer {self.get_front_pointer()}")
        print(f"Back pointer {self.get_back_pointer()}")


    # Module set outputs ready

    # Module Write functions

    # Module Read functions

    # Module print visualizers

