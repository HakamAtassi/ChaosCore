from BP import *

class BPDut:
    def __init__(self, dut):
        self.dut = dut
    
    #####################
    ### SIGNAL ACCESS ###
    #####################

    def clock(self):
        return self.dut.clock

    # Ready signals
    def is_predict_ready(self):
        return self.dut.io_predict_ready.value

    def is_commit_ready(self):
        return self.dut.io_commit_ready.value

    def is_revert_ready(self):
        return self.dut.io_revert_ready.value

    # Valid signals
    def is_prediction_valid(self):
        return int(self.dut.io_prediction_valid.value)

    def is_predict_valid(self):
        return int(self.dut.io_predict_valid.value)
    
    def set_prediction_read(self, ready):
        self.dut.io_prediction_ready.value = ready

    def is_commit_valid(self):
        return int(self.dut.io_commit_valid.value)

        

    # Read outputs
    def get_RAS(self):
        NEXT = int(self.dut.io_RAS_read_NEXT.value)
        TOS = int(self.dut.io_RAS_read_TOS.value)
        ret_addr = int(self.dut.io_RAS_read_ret_addr.value)
        return (TOS, NEXT, ret_addr)

    def get_prediction(self):
        hit = self.dut.io_prediction_bits_hit.value
        target = hex(self.dut.io_prediction_bits_target.value)
        br_type = int(self.dut.io_prediction_bits_br_type.value)
        br_mask = int(self.dut.io_prediction_bits_br_mask.value)
        GHR = int(self.dut.io_prediction_bits_GHR.value)
        T_NT = int(self.dut.io_prediction_bits_T_NT.value)
        valid = self.dut.io_prediction_valid.value
        return prediction((hit, target, br_type, br_mask, T_NT, GHR, valid))

    # Place inputs
    def predict(self, predict_msg):     # request prediction
        (address, valid) = predict_msg.get()
        self.dut.io_predict_valid.value = valid
        self.dut.io_predict_bits.value = address

    def commit(self, commit_msg):
        (PC, GHR, T_NT, target, br_type, br_mask, misprediction, TOS, NEXT, valid) = commit_msg.get()
        self.dut.io_commit_bits_PC.value                = PC
        self.dut.io_commit_bits_GHR.value               = GHR
        self.dut.io_commit_bits_T_NT.value              = T_NT
        self.dut.io_commit_bits_target.value            = target
        self.dut.io_commit_bits_br_type.value           = br_type
        self.dut.io_commit_bits_br_mask.value           = br_mask
        self.dut.io_commit_bits_misprediction.value     = misprediction
        self.dut.io_commit_bits_TOS.value               = TOS
        self.dut.io_commit_bits_NEXT.value              = NEXT
        self.dut.io_commit_valid.value                  = valid


    def RAS_revert(self, revert_msg):
        (PC, GHR, valid) = revert_msg.get()
        self.dut.io_revert_valid.value      = valid
        self.dut.io_revert_bits_GHR.value   = GHR
        self.dut.io_revert_bits_PC.value    = PC

    def RAS_update(self, RAS_update_msg):
        (call, ret, call_addr) = RAS_update_msg.get()
        self.dut.io_RAS_update_call_addr.value    = call_addr
        self.dut.io_RAS_update_call.value         = call
        self.dut.io_RAS_update_ret.value          = ret

    def get_PHT_line(self, line):
        return int(self.dut.gshare.PHT.mem_ext.Memory[line].value)

    def get_PHT_state(self):
        PHT_state=[]
        for i in range((1<<16)):
            PHT_state.append(self.get_PHT_line(i))
        return PHT_state

    ################
    ## GET INPUTS ##
    ################

    def get_commit(self):
        PC = self.dut.io_commit_bits_PC.value
        GHR = self.dut.io_commit_bits_GHR.value
        T_NT = self.dut.io_commit_bits_T_NT.value
        target = self.dut.io_commit_bits_target.value
        br_type = self.dut.io_commit_bits_br_type.value
        br_mask = self.dut.io_commit_bits_br_mask.value
        misprediction = self.dut.io_commit_bits_misprediction.value
        TOS = self.dut.io_commit_bits_TOS.value
        NEXT = self.dut.io_commit_bits_NEXT.value
        valid = self.dut.io_commit_valid.value     
        return commit((PC, GHR, T_NT, target, br_type, br_mask, misprediction, TOS, NEXT, valid))

    def get_RAS_update(self):
        call_addr = self.dut.io_RAS_update_call_addr.value
        call = self.dut.io_RAS_update_call.value
        ret = self.dut.io_RAS_update_ret.value
        return RAS_update((call, ret, call_addr))

    def get_predict(self):
        valid = self.dut.io_predict_valid.value
        addr = self.dut.io_predict_bits.value
        return predict((addr, valid))

    def get_revert(self):
        valid = self.dut.io_revert_valid.value      
        GHR = self.dut.io_revert_bits_GHR.value 
        PC = self.dut.io_revert_bits_PC.value 
        return revert((PC, GHR, valid))
"""    
module BP(
  input         clock,
                reset,
  output        io_predict_ready,
  input         io_predict_valid,
  input  [31:0] io_predict_bits,
  output        io_commit_ready,
  input         io_commit_valid,
  input  [31:0] io_commit_bits_PC,
  input  [15:0] io_commit_bits_GHR,
  input         io_commit_bits_T_NT,
  input  [31:0] io_commit_bits_target,
  input  [1:0]  io_commit_bits_br_type,
  input  [3:0]  io_commit_bits_br_mask,
  input         io_commit_bits_misprediction,
  input  [6:0]  io_commit_bits_TOS,
                io_commit_bits_NEXT,
  input  [31:0] io_RAS_update_call_addr,
  input         io_RAS_update_call,
                io_RAS_update_ret,
  output [6:0]  io_RAS_read_NEXT,
                io_RAS_read_TOS,
  output [31:0] io_RAS_read_ret_addr,
  output        io_revert_ready,
  input         io_revert_valid,
  input  [15:0] io_revert_bits_GHR,
  input  [31:0] io_revert_bits_PC,
  input         io_prediction_ready,
  output        io_prediction_valid,
                io_prediction_bits_hit,
  output [31:0] io_prediction_bits_target,
  output [1:0]  io_prediction_bits_br_type,
  output [3:0]  io_prediction_bits_br_mask,
  output [15:0] io_prediction_bits_GHR,
  output        io_prediction_bits_T_NT
);
"""