


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
        return self.dut.io_prediction_valid.value
    
    def set_prediction_read(self, ready):
        self.dut.io_prediction_ready.value = ready
        

    # Read outputs
    def get_RAS(self):
        NEXT = int(self.dut.io_RAS_read_NEXT.value)
        TOS = int(self.dut.io_RAS_read_TOS.value)
        ret_addr = int(self.dut.io_RAS_read_ret_addr.value)
        return (TOS, NEXT, ret_addr)

    def get_prediction(self):
        hit = self.dut.io_prediction_bits_hit.value
        target = hex(self.dut.io_prediction_bits_target.value)
        br_type = self.dut.io_prediction_bits_br_type.value
        br_mask = self.dut.io_prediction_bits_br_mask.value
        GHR = self.dut.io_prediction_bits_GHR.value
        T_NT = self.dut.io_prediction_bits_T_NT.value
        return ((hit, target, br_type, br_mask), T_NT, GHR)

    # Place inputs
    def predict(self, PC, valid):     # request prediction
        self.dut.io_predict_valid.value = valid
        self.dut.io_predict_bits.value = PC

    def commit(self, PC, GHR, T_NT, target, br_type, br_mask, misprediction, TOS, NEXT, valid):     # request prediction
        self.dut.io_commit_valid.value                  = valid
        self.dut.io_commit_bits_PC.value                = PC
        self.dut.io_commit_bits_GHR.value               = GHR
        self.dut.io_commit_bits_T_NT.value              = T_NT
        self.dut.io_commit_bits_target.value            = target
        self.dut.io_commit_bits_br_type.value           = br_type
        self.dut.io_commit_bits_br_mask.value           = br_mask
        self.dut.io_commit_bits_misprediction.value     = misprediction
        self.dut.io_commit_bits_TOS.value               = TOS
        self.dut.io_commit_bits_NEXT.value              = NEXT

    def RAS_revert(self,PC, GHR, valid):
        self.dut.io_revert_valid.value      = valid
        self.dut.io_revert_bits_GHR.value   = GHR
        self.dut.io_revert_bits_PC.value    = PC

    def RAS_update(self,call, ret, call_addr):
        self.dut.io_RAS_update_call_addr.value    = call_addr
        self.dut.io_RAS_update_call.value         = call
        self.dut.io_RAS_update_ret.value          = ret

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