from model_utils import *


class predecoder_model:
    def __init__(self):
        self.input_prediction_ = 0
        self.input_fetch_packet = 0
        self.input_RAS_read = 0
        self.input_commit = 0

        # state stuff
        self.expected_PC = 0
        self.is_misprediction = 0
        self.is_reversion = 0
        self.GHR = 0

        # outputs

        self.final_fetch_packet = {}

    # inputs
    def prediction(self, prediction):
        self.input_prediction = prediction

    def fetch_packet(self, fetch_packet):
        self.input_fetch_packet = fetch_packet

    def RAS_read(self, RAS_read):
        self.input_RAS_read = RAS_read

    def commit(self, commit):
        self.input_commit = commit



    def GHR(self):
        # TODO:
        pass

    def get_dominant_branch(self):
        taken_index = 0
        taken_instruction = 0
        taken = 0
        taken_address = 0

        for i in range(4):
            instruction = self.input_fetch_packet["instruction"][i]
            is_ret      = get_is_ret(instruction)
            is_call     = get_is_call(instruction)
            is_jal      = get_is_jal(instruction)
            is_jalr     = get_is_jalr(instruction)
            is_branch   = get_is_branch(instruction)
            is_BTB_hit  = self.input_prediction["hit"] & self.input_prediction["valid"]
            is_T_NT     = self.input_prediction["T_NT"]
            taken_index = i

            if(is_call): # IDK
                taken_address = 0   # FIXME: 
                taken = 1
                break
            if(is_ret):
                taken_address = self.input_RAS_read["ret_addr"]
                taken = 1
                break
            if(is_jal):
                imm = LogicArray(instruction, Range(31, 'downto', 0))[31:20].integer
                imm = signed(imm, 12)
                instruction_PC = self.input_fetch_packet["fetch_PC"]
                taken_address = instruction_PC + i*4 + imm
                taken = 1
                break
            if(is_jalr):    # IDK
                taken = 1
                break
            if(is_branch and is_BTB_hit and is_T_NT):
                taken_address = self.input_prediction["target_address"]
                taken = 1
                break

        return (taken_index, taken, taken_address)



    def RAS_update(self):
        (taken_index, taken, taken_address) = self.get_dominant_branch()
        instruction = self.input_fetch_packet["instruction"][taken_index]

        RAS_update = {}
        RAS_update["call_addr"] = 0
        RAS_update["call"] = 0
        RAS_update["ret"] = 0

        is_ret = self.is_ret(instruction)
        is_call = self.is_call(instruction)

        if is_ret:
            RAS_update["ret"] = 1
        if is_call:
            RAS_update["call"] = 1
            RAS_update["call_addr"] = (
                self.input_fetch_packet["fetch_PC"] + taken_index * 4
            )

        return RAS_update

    def predictions(self):  # To FTQ

        (taken_index, taken, taken_address) = self.get_dominant_branch()
        instruction = self.input_fetch_packet["instruction"][taken_index]

        is_jal      = get_is_jal(instruction)
        is_jalr     = get_is_jalr(instruction)
        is_branch   = get_is_branch(instruction)

        predictions = {}

        predictions["valid"] = is_branch | is_jal | is_jalr

        predictions["fetch_PC"] = self.input_fetch_packet["fetch_PC"]
        predictions["is_misprediction"] = 0
        predictions["predicted_PC"] = taken_address
        predictions["T_NT"] = taken
        #predictions["br_type"] =   # FIXME: ?
        #predictions["GHR"] = # FIXME:
        #predictions["NEXT"] = 
        #predictions["TOS"] = 
        predictions["dominant_index"] = taken_index
        predictions["resolved_PC"] = self.input_fetch_packet["fetch_PC"] + 16


        return predictions

    def update_expected_PC(self):

        (fetch_packet_index, taken, taken_address) = self.get_dominant_branch()
        if(not taken and self.input_fetch_packet["valid"]):
            self.expected_PC = self.expected_PC + 16
        else:
            self.expected_PC = taken_address


    def get_is_misprediction(self):
        return self.input_commit["valid"] & self.input_commit["is_misprediction"]

    def get_is_reversion(self):
        PC_mismatch = self.input_fetch_packet["valid"] & (self.input_fetch_packet["fetch_PC"] != self.expected_PC)
        return PC_mismatch 


    def inputs(self, prediction, fetch_packet, RAS_read, commit):
        # place inputs 
        self.prediction(prediction)
        self.fetch_packet(fetch_packet)
        self.RAS_read(RAS_read)
        self.commit(commit)


        self.is_misprediction = self.get_is_misprediction()
        self.is_reversion = self.get_is_reversion()



        # set outputs 

        self.final_fetch_packet = self.get_final_fetch_packet()

        #


        self.update_expected_PC()



    # outputs
    def revert(self):

        current_PC = self.input_fetch_packet["fetch_PC"]

        PC_mismatch = self.expected_PC != current_PC
        self.is_reversion = PC_mismatch and not self.is_misprediction

        revert = {}

        revert["valid"] = self.is_reversion
        revert["GHR"] = self.GHR
        revert["PC"] = self.expected_PC

        return revert

    def get_final_fetch_packet(self):
        final_fetch_packet = {}

        (fetch_packet_index, taken, taken_address) = self.get_dominant_branch()

        final_fetch_packet["valid"] = int(
            not self.is_reversion
            and not self.is_misprediction and self.input_fetch_packet["valid"]
        )

        final_fetch_packet["valid_bits"] = [0] * 4

        for i in range(0, fetch_packet_index + 1):
            final_fetch_packet["valid_bits"][i] = self.input_fetch_packet["valid_bits"][i]

        final_fetch_packet["fetch_PC"] = self.input_fetch_packet["fetch_PC"]
        final_fetch_packet["instruction"] = self.input_fetch_packet["instruction"]
        final_fetch_packet["packet_index"] = self.input_fetch_packet["packet_index"]
        final_fetch_packet["ROB_index"] = self.input_fetch_packet["ROB_index"]

        return final_fetch_packet
