
class ROB_model:
    def __init__(self):

        self.row_valid_mem    = [0]*64

        self.shared_mem = {}
        self.shared_mem["fetch_PC"]                     = [0]*64
        self.shared_mem["RAT_index"]                    = [0]*64
        self.shared_mem["free_list_front_pointer"]      = [0]*64

        self.WB_mem = {}
        for i in range(4):
            self.WB_mem["busy"]      = [0]*64
            self.WB_mem["except"]    = [0]*64

        self.entry_mem = {}

        self.entry_mem["valid"]         =   [0]*64
        self.entry_mem["is_branch"]     =   [0]*64
        self.entry_mem["is_load"]       =   [0]*64
        self.entry_mem["is_store"]      =   [0]*64
        for i in range(4):
            self.entry_mem["valid"][i]         = [0]*4
            self.entry_mem["is_branch"][i]     = [0]*4
            self.entry_mem["is_load"][i]       = [0]*4
            self.entry_mem["is_store"][i]      = [0]*4


        self.front_pointer = 0
        self.back_pointer = 0
        self.full = 0


        ###################
        ## OUTPUT QUEUES ##
        ###################

        # only queue when valid

        self.ROB_output_queue           = []
        self.ROB_index_queue            = []
        self.PC_file_exec_data_queue    = []


    def inputs(self, flush, ROB_packet, FU0_outputs, FU1_outputs, FU2_outputs, FU3_outputs, commit, PC_file_exec_addr):
        self.flush              = flush 
        self.ROB_packet         = ROB_packet
        self.FU0_outputs        = FU0_outputs
        self.FU1_outputs        = FU1_outputs
        self.FU2_outputs        = FU2_outputs
        self.FU3_outputs        = FU3_outputs
        self.commit             = commit
        self.PC_file_exec_addr  = PC_file_exec_addr

    def eval(self):

        # Read ROB index
        self.read_ROB_index()

        # Read PC file
        self.read_PC_file()
        
        # read ROB output
        self.read_ROB_output()


        
        # write ROB_packet as needed (allocate)
        self.write_ROB_packet()

        # Update Row (busy/except)
        self.FU_WB()

        # commit as needed
        self.do_commit()



        if(self.flush):
            self.front_pointer  = 0
            self.back_pointer   = 0
            self.row_valid_mem = [0]*64
            #return 



    def write_ROB_packet(self):
        input_valid = self.ROB_packet["valid"]

        if(self.full):      return 
        if(input_valid == 0):   return 

        
        # update shared mem
        self.shared_mem["fetch_PC"][self.back_pointer]                     = self.ROB_packet["fetch_PC"]
        self.shared_mem["RAT_index"][self.back_pointer]                    = self.ROB_packet["RAT_index"]
        self.shared_mem["free_list_front_pointer"][self.back_pointer]      = self.ROB_packet["free_list_front_pointer"]

        # update busy/except mem
        self.WB_mem["busy"][self.back_pointer]                             = 0
        self.WB_mem["except"][self.back_pointer]                           = 0

        # update row_valid mem
        self.row_valid_mem[self.back_pointer]                              = input_valid

        # update entry mem
        self.entry_mem["valid"][self.back_pointer]                                        = self.ROB_packet["valid_bits"]
        self.entry_mem["is_branch"][self.back_pointer]                                    = self.ROB_packet["needs_branch_unit"]
        self.entry_mem["is_load"][self.back_pointer]                                      = self.ROB_packet["is_load"]
        self.entry_mem["is_store"][self.back_pointer]                                     = self.ROB_packet["is_store"]

        self.back_pointer = (self.back_pointer + 1) % 64

        #update full
        self.full = abs(self.back_pointer - self.front_pointer) >= 63

    def do_commit(self):
        input_valid = self.commit["valid"]
        if(input_valid == 0): return 

        self.row_valid_mem[self.front_pointer] = 0
        self.front_pointer = (self.front_pointer + 1) % 64

    def FU_WB(self):
        FU0_ROB_index = self.FU0_outputs["ROB_index"]
        FU1_ROB_index = self.FU1_outputs["ROB_index"]
        FU2_ROB_index = self.FU2_outputs["ROB_index"]
        FU3_ROB_index = self.FU3_outputs["ROB_index"]

        FU0_valid = self.FU0_outputs["valid"]
        FU1_valid = self.FU1_outputs["valid"]
        FU2_valid = self.FU2_outputs["valid"]
        FU3_valid = self.FU3_outputs["valid"]

        if(FU0_valid): self.WB_mem["busy"][FU0_ROB_index] = 1
        if(FU1_valid): self.WB_mem["busy"][FU1_ROB_index] = 1
        if(FU2_valid): self.WB_mem["busy"][FU2_ROB_index] = 1
        if(FU3_valid): self.WB_mem["busy"][FU3_ROB_index] = 1

    def read_PC_file(self):
        fetch_PC_out = self.shared_mem["fetch_PC"][self.PC_file_exec_addr]
        self.PC_file_exec_data_queue.append(fetch_PC_out)

    def read_ROB_index(self):
        ROB_index = self.back_pointer
        self.ROB_index_queue.append(ROB_index)

    def read_ROB_output(self):
        ROB_output = {}

        ROB_output["row_valid"]                     = self.row_valid_mem[self.front_pointer]
        ROB_output["fetch_PC"]                      = self.shared_mem["fetch_PC"][self.front_pointer]
        ROB_output["RAT_index"]                     = self.shared_mem["RAT_index"][self.front_pointer]
        ROB_output["free_list_front_pointer"]       = self.shared_mem["free_list_front_pointer"][self.front_pointer]
        ROB_output["ROB_index"]                     = self.back_pointer

        ROB_output["entry_valid"]   = [0]*4
        ROB_output["is_branch"]     = [0]*4
        ROB_output["is_load"]       = [0]*4
        ROB_output["is_store"]      = [0]*4

        ROB_output["entry_valid"]        = self.entry_mem["valid"][self.front_pointer]
        ROB_output["is_branch"]          = self.entry_mem["is_branch"][self.front_pointer]
        ROB_output["is_load"]            = self.entry_mem["is_load"][self.front_pointer]
        ROB_output["is_store"]           = self.entry_mem["is_store"][self.front_pointer]

        #print(f"row valid {ROB_output["row_valid"]}")
        if(ROB_output["row_valid"]): self.ROB_output_queue.append(ROB_output)
