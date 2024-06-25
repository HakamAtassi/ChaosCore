
class rename_model:

    def __init__(self):
        self.active_checkpoint = 0

        self.RAT_memories   = [[0]*64 for _ in range(self.checkpoints)]
        self.ready_memories = [[0]*64 for _ in range(self.checkpoints)]
        self.free_list      = [i for i in range(1, 64)]


        self.renamed_decoded_fetch_packet_queue = []


    def inputs(self, flush, commit, decoded_fetch_packet, renamed_decoded_fetch_packet, FU_outputs):
        self.input_flush = flush
        self.input_commit = commit
        self.input_decoded_fetch_packet = decoded_fetch_packet
        self.input_renamed_decoded_fetch_packet = renamed_decoded_fetch_packet
        self.FU_outputs = FU_outputs

    def get_is_branch(self):
        is_branch = 0
        for i in range(4):
            is_branch = is_branch | int(self.input_decoded_fetch_packet["needs_branch_unit"][i])
        return is_branch

    def get_is_misprediction(self):
        pass

    def create_checkpoint(self):
        pass

    def eval(self):

        # Step 0: if prediction in packet, checkpoint everything before updateing
            # Step 0.5: if misprediction (flush), do not update anything (and output is invalid)
        # Step 1: update ready from FU inputs
        # Step 2: update free list from FU inputs
        # Step 3: rename RD from free list (if not x0 and if valid only)
        # Step 4: output RS1, RS2, ready
        # Step 5: output 


        if self.get_is_misprediction():
            return

        if self.get_is_branch():
            self.create_checkpoint()

        
