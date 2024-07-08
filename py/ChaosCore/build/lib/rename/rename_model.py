import copy 

def generate_null_renamed_decoded_fetch_packet():

    renamed_decoded_fetch_packet = {}
    renamed_decoded_fetch_packet["valid"]           = 0
    renamed_decoded_fetch_packet["fetch_PC"]        = 0
    renamed_decoded_fetch_packet["RAT_index"]       = 0

    renamed_decoded_fetch_packet["RS1_ready"]           = [0]*4
    renamed_decoded_fetch_packet["RS2_ready"]           = [0]*4
    renamed_decoded_fetch_packet["RD_valid"]            = [0]*4
    renamed_decoded_fetch_packet["RS1_valid"]           = [0]*4
    renamed_decoded_fetch_packet["RS2_valid"]           = [0]*4

    renamed_decoded_fetch_packet["RD"]                  = [0]*4
    renamed_decoded_fetch_packet["RS1"]                 = [0]*4
    renamed_decoded_fetch_packet["RS2"]                 = [0]*4

    renamed_decoded_fetch_packet["IMM"]                 = [0]*4
    renamed_decoded_fetch_packet["FUNCT3"]              = [0]*4
    renamed_decoded_fetch_packet["packet_index"]        = [0]*4
    renamed_decoded_fetch_packet["instructionType"]     = [0]*4
    renamed_decoded_fetch_packet["portID"]              = [0]*4
    renamed_decoded_fetch_packet["RS_type"]             = [0]*4
    renamed_decoded_fetch_packet["needs_ALU"]           = [0]*4
    renamed_decoded_fetch_packet["needs_branch_unit"]   = [0]*4
    renamed_decoded_fetch_packet["needs_CSRs"]          = [0]*4
    renamed_decoded_fetch_packet["SUBTRACT"]            = [0]*4
    renamed_decoded_fetch_packet["MULTIPLY"]            = [0]*4
    renamed_decoded_fetch_packet["IS_IMM"]              = [0]*4
    renamed_decoded_fetch_packet["is_load"]             = [0]*4
    renamed_decoded_fetch_packet["is_store"]            = [0]*4
    renamed_decoded_fetch_packet["valid_bits"]          = [0]*4

    return renamed_decoded_fetch_packet




class rename_model:

    def __init__(self):
        self.checkpoints = 16

        self.RAT_front_pointer = 0
        self.RAT_back_pointer = 0

        self.RAT_memories   = [[0]*32 for _ in range(self.checkpoints)]
        self.ready_memories = [0]*65
        self.ready_memories[0] = 1
        
        self.free_list      = [i for i in range(1, 65)]
        self.free_list_front_pointer = 0
        self.free_list_back_pointer  = 64


        # I/O
        self.input_flush = 0
        self.input_commit = 0
        self.input_decoded_fetch_packet = 0
        self.input_renamed_decoded_fetch_packet = 0
        self.input_FU_outputs = 0


        self.output_renamed_decoded_fetch_packet = generate_null_renamed_decoded_fetch_packet()


        self.renamed_decoded_fetch_packet_queue = []
        self.RAT_queue = []

    def inputs(self, flush, commit, decoded_fetch_packet, FU_outputs):
        self.input_flush = flush
        self.input_commit = commit
        self.input_decoded_fetch_packet = decoded_fetch_packet
        self.input_renamed_decoded_fetch_packet = generate_null_renamed_decoded_fetch_packet()
        self.input_FU_outputs = FU_outputs

    ######################
    ## HELPER FUNCTIONS ##
    ######################

    def decoded_fetch_packet_ready(self):
        """is the input ready"""
        return self.input_decoded_fetch_packet["ready"]

    def decoded_fetch_packet_valid(self):
        """is the input valid"""
        return self.input_decoded_fetch_packet["valid"]

    def get_is_RAT_full(self):
        """are there any available RAT checkpoints"""
        full = abs(self.RAT_back_pointer - self.RAT_back_pointer) >= 15
        return full

    def get_is_free_list_empty(self):
        empty = abs(self.free_list_back_pointer - self.free_list_front_pointer) < 4
        return empty

    def get_is_branch(self):
        """does the current decoded fetch packet contain a branch"""
        fetch_packet_valid = self.input_decoded_fetch_packet["valid"]
        for i in range(4):
            needs_branch_unit = self.input_decoded_fetch_packet["needs_branch_unit"][i]
            instruction_valid = self.input_decoded_fetch_packet["valid_bits"][i]
            if(needs_branch_unit and instruction_valid and fetch_packet_valid):
                return 1
        return 0

    def get_is_misprediction(self):
        """does the current commit contain a misprediction"""
        valid = self.input_commit["valid"]
        is_misprediction = self.input_commit["is_misprediction"]
        if(valid and is_misprediction):
            return 1
        return 0

    def increment_free_list_back_pointer(self):
        self.free_list_back_pointer +=1
        self.free_list_back_pointer %= 64

    def increment_free_list_front_pointer(self):
        self.free_list_front_pointer +=1
        self.free_list_front_pointer %= 64

    def pop_free_list(self):
        RD = self.free_list[self.free_list_front_pointer]
        self.increment_free_list_front_pointer()
        return RD

    def reallocate_RD(self):
        valid       = self.input_commit["valid"]
        for i in range(4):
            RD_valid    = self.input_commit["RD_valid"][i]
            RD          = self.input_commit["RD"][i]
            if(valid & RD_valid & RD):
                self.increment_free_list_back_pointer()

    def update_ready(self):
        for i in range(4):
            valid = self.input_FU_outputs["valid"][i]
            RD_valid = self.input_FU_outputs["RD_valid"][i]
            RD = self.input_FU_outputs["RD"][i]

            if(valid & RD_valid):
                self.ready_memories[RD] = 1
    
    def rename(self):
        """Output renamed RDs based on RAT mapping"""
        RAT = self.RAT_memories[self.RAT_front_pointer]
        self.output_renamed_decoded_fetch_packet = self.input_decoded_fetch_packet
        valid       = self.input_decoded_fetch_packet["valid"]

        for index in range(4):

            # Read RS1, RS2 & ready bits
            if(self.output_renamed_decoded_fetch_packet["RS1_valid"][index] and valid):
                self.output_renamed_decoded_fetch_packet["RS1"][index]  =   RAT[self.input_decoded_fetch_packet["RS1"][index]]
            if(self.output_renamed_decoded_fetch_packet["RS2_valid"][index] and valid):
                self.output_renamed_decoded_fetch_packet["RS2"][index]  =   RAT[self.input_decoded_fetch_packet["RS2"][index]]

            # rename RD, update mapping & ready bits
            RDold       = self.input_decoded_fetch_packet["RD"][index]
            RD_valid    = self.input_decoded_fetch_packet["RD_valid"][index]

            if(valid and RD_valid and RDold != 0):
                RD = self.pop_free_list()                                                       # Rename RD
                RAT[RDold] = RD                                                                 # update mapping
                self.output_renamed_decoded_fetch_packet["RD"][index] = RD                      # output new name
                self.ready_memories[RD] = 0                                                     # Set RD ready 0
            else:
                self.output_renamed_decoded_fetch_packet["RD"][index] = 0

        assert self.ready_memories[0] == 1, "x0 Not ready for some reason"

        self.RAT_memories[self.RAT_front_pointer] = RAT

        if(self.output_renamed_decoded_fetch_packet["valid"]):
            self.renamed_decoded_fetch_packet_queue.append(self.output_renamed_decoded_fetch_packet)


    def create_checkpoint(self):
        """copy over RAT content. increment RAT pointer."""
        next_RAT_front_pointer = (self.RAT_front_pointer + 1) % self.checkpoints
        self.RAT_memories[next_RAT_front_pointer] = copy.deepcopy(self.RAT_memories[self.RAT_front_pointer])
        self.RAT_front_pointer = next_RAT_front_pointer

    def restore_rat(self):
        """decrement RAT pointer"""
        #print(f"restore to {self.input_commit["RAT_index"]}")
        #print(self.RAT_memories[self.RAT_front_pointer])
        self.RAT_front_pointer = self.input_commit["RAT_index"]
    
    def deallocate_rat(self):
        self.RAT_back_pointer = (self.RAT_back_pointer + 1)  & self.checkpoints
        

    def restore_free_list(self):
        """restore free_list front pointer"""
        self.free_list_front_pointer = self.input_commit["free_list_front_pointer"]

    ##########
    ## EVAL ##
    ##########

    def eval(self):
        input_valid  = self.input_decoded_fetch_packet["valid"]
        output_ready = 1  # assume 1 for now


        if(self.get_is_branch() and input_valid and output_ready and not self.input_flush):
            #print(self.input_decoded_fetch_packet)
            #print(self.RAT_front_pointer)
            #print(self.RAT_memories[self.RAT_front_pointer])
            self.create_checkpoint()    # if branch, create checkpoint
            #print(self.RAT_memories[self.RAT_front_pointer])

        # set ready bits
        if(~self.input_flush):
            self.update_ready()         # if FU valid, set RDs ready

        if (input_valid and output_ready and not self.get_is_free_list_empty() and not self.input_flush):   # renamer can rename (!empty)
            #print(f"{self.input_decoded_fetch_packet}")
            self.rename()


        # Commit stuff
        if (not self.get_is_RAT_full() and not self.input_flush):   # renamer can allocate (!full)
            self.reallocate_RD()        # if commit and not mispred, reallocate RDs
        
        # misprediction
        if(self.get_is_misprediction()):
            self.restore_free_list()
            self.restore_rat()


        self.RAT_queue.append(self.RAT_memories)




        
# very carefully think about skid buffers, valid ready, etc...
# how do you simulate skid buffer?

"""
in order of operations:

## comb update
is valid && ready?      yes: continue, No: return
is misprediction/flush? yes: restore freelist pointer, rat index, return. Else: pass
FU inputs?              yes: set ready bits. No: pass

## read
fetch packet            yes: Get RDs, RS1/RS2, free list front pointer, RAT checkpoint. No: pass

## state update
branch                  yes: increment RAT. No: pass
commit                  yes: reallocate RDs. No: pass

"""

