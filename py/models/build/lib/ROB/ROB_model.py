
class ROB_model:
    def __init__(self):
        self.shared_mem = {}
        self.shared_mem["row_valid"]    = [0]*64
        self.shared_mem["fetch_PC"]     = [0]*64
        self.shared_mem["RAT_IDX"]      = [0]*64

        self.WB_mem = [{} for _ in range(4)]
        for i in range(4):
            self.WB_mem[i]["busy"]      = [0]*64
            self.WB_mem[i]["except"]    = [0]*64

        self.entry_mem = [{} for _ in range(4)]
        for i in range(4):
            self.entry_mem[i]["valid"]         = [0]*64
            self.entry_mem[i]["is_branch"]     = [0]*64
            self.entry_mem[i]["is_load"]       = [0]*64
            self.entry_mem[i]["is_store"]      = [0]*64


        self.front_pointer = 0
        self.back_pointer = 0
        self.full = 0

    def is_full(self):
        return self.full

        
    def increment_front_pointer(self): self.front_pointer = (self.front_pointer + 1) % 64
    def increment_back_pointer(self):  self.back_pointer  = (self.back_pointer + 1)  % 64

    def write_ROB_packet(self, allocate_inputs):  # allocate
        #print(f"Writing ROB packet {allocate_inputs} \n")

        print(f"Writing to {self.back_pointer}")
        if(not allocate_inputs["valid"]): return 
        if(self.is_full()): return 

        # write shared mem
        self.shared_mem["fetch_PC"][self.back_pointer] = allocate_inputs["fetch_PC"]
        self.shared_mem["row_valid"][self.back_pointer]    = 1
        #self.shared_mem[self.front_pointer]["RAT_IDX"]  = 

        # write WB_mem
        for i in range(4):
            self.WB_mem[i]["busy"][self.back_pointer] = 0
            self.WB_mem[i]["except"][self.back_pointer] = 0

        # write entry_mem
        for i in range(4):
            self.entry_mem[i]["valid"][self.back_pointer]       = allocate_inputs["valid_bits"][i]
            self.entry_mem[i]["is_branch"][self.back_pointer]   = allocate_inputs["is_branch"][i]
            self.entry_mem[i]["is_load"][self.back_pointer]     = allocate_inputs["IS_LOAD"][i]
            self.entry_mem[i]["is_store"][self.back_pointer]    = allocate_inputs["IS_STORE"][i]

        self.increment_back_pointer()

        self.full = (self.back_pointer == self.front_pointer)

    def read_ROB_packet(self):
        return not self.full

    def write_FU_outputs(self, index, FU_outputs):

        ROB_index = FU_outputs["ROB_index"]
        bank_index = FU_outputs["fetch_packet_index"]

        if(self.WB_mem[bank_index]["busy"][ROB_index] == 0):
            self.WB_mem[bank_index]["busy"][ROB_index] = FU_outputs["valid"]


    def read_ROB_output(self):

        ROB_output = {}

        ROB_output["valid"]             = self.shared_mem["row_valid"][self.front_pointer]
        ROB_output["fetch_PC"]          = self.shared_mem["row_valid"][self.front_pointer]
        ROB_output["RAT_IDX"]           = 0
        ROB_output["ROB_index"]         = self.front_pointer
        
        ROB_output["entry_valid"]   = [0]*4
        ROB_output["is_branch"]     = [0]*4
        ROB_output["is_load"]       = [0]*4
        ROB_output["is_store"]      = [0]*4

        for i in range(4):
            ROB_output["entry_valid"][i]        = self.entry_mem[i]["valid"][self.front_pointer]
            ROB_output["is_branch"][i]          = self.entry_mem[i]["is_branch"][self.front_pointer]
            ROB_output["is_load"][i]            = self.entry_mem[i]["is_load"][self.front_pointer]
            ROB_output["is_store"][i]           = self.entry_mem[i]["is_store"][self.front_pointer]


        can_commit = 1
        for i in range(4):

            is_load_store       = self.entry_mem[i]["is_load"][self.front_pointer] | self.entry_mem[i]["is_store"][self.front_pointer]
            is_entry_valid      = self.entry_mem[i]["valid"][self.front_pointer]
            is_entry_complete   = self.WB_mem[i]["busy"][self.front_pointer]

            can_commit = can_commit & (is_load_store | (is_entry_complete & is_entry_valid))


        if(can_commit): self.increment_front_pointer()

        self.full = 0

        return ROB_output

    def write_commit(self, commit_inputs):
        if(commit_inputs["valid"] & commit_inputs["is_misprediction"]):
            self.back_pointer  = 0
            self.front_pointer = 0

    def read_ROB_index(self):
        return self.back_pointer


    def read_shared_mem(self):
        return self.shared_mem






