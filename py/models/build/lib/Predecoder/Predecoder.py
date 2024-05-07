from Channels import *
from model_utils import *

class Predecoder:
    def __init__(self, start_address):
        self.expected_address = start_address

    def validate(self, fetch_packet, RAS_read, prediction):
        # step 1: check if current fetch packet matches expected PC
        packet_valid = (fetch_packet.PC == self.expected_address)

        # if packet valid
            # step 2: validate current instructions based on branches, branch status, and overall packet valid (pre-decode)
            # step 3: update expected address for next packet
            # step 4: update RAS as needed
            # return (validatedFetchPacket, RASUpdate (on call/ret), Redirect(null))

        # if packet not valid
            # step 2: request redirect/revert/etc...
                # That is, output a kill request, the expected PC, the GHR, and dont output instructions
            # return (validatedFetchPacket (null), RASUpdate (null), Redirect)

        if(packet_valid):    # if packet valid
            self.expected_address = self.get_next_address(fetch_packet, RAS_read, prediction)
            self.validate_fetch_packet(fetch_packet, prediction)
            RAS_update = self.get_RAS_update(fetch_packet)
            return (RAS_update, Revert.null())
        elif(not packet_valid):  # if packet not valid
            revert = Revert((self.next_address, prediction.GHR, 1))
            return (RAS_update.null(), revert)

        assert False, "Packet neither valid nor invalid"

    def get_next_address(self, fetch_packet, RAS_read, prediction):
        """get the next address based on fetch packet contents"""
        next_address = fetch_packet.PC + 16     # FIXME: is this always +16 or can it be less (is PC always aligned??)?
        for instruction in fetch_packet.instructions:
            if(instruction.valid):
                if(is_ret(instruction)):
                    next_address = RAS_read.ret_addr
                    break
                if(is_jal(instruction)):    # always taken if valid
                    next_address = instruction.PC + instruction.imm
                    break
                if(is_jalr(instruction) and prediction.BTB_hit and (prediction.BTB_br_mask == (0b1000>>instruction.index))):
                    next_address = prediction.BTB_target
                    break
                if(is_jalr(instruction) and prediction.BTB_hit and (prediction.BTB_br_mask == (0b1000>>instruction.index)) and prediction.PHT_T_NT):
                    next_address = prediction.BTB_target
                    break
                if(is_branch(instruction)):
                    next_address = prediction.BTB_target
                    break
        return next_address

    def validate_fetch_packet(self, fetch_packet, prediction):
        """validate/invalidate instructions based on fetch packet contents"""
        valid = 1
        for instruction in fetch_packet.instructions:   # all instructions following a taken branch are invalidated
            instruction.valid=valid
            if(instruction.valid):
                if(is_jal(instruction)):
                    valid=0
                if(is_ret(instruction)):
                    valid=0
                if(is_jalr(instruction) and prediction.BTB_hit and (prediction.BTB_br_mask == (0b1000>>instruction.index))):
                    valid=0
                if(is_jalr(instruction) and prediction.BTB_hit and (prediction.BTB_br_mask == (0b1000>>instruction.index)) and prediction.T_NT):
                    valid=0

    def get_RAS_update(self, fetch_packet):
        """generate RASUpdate request based on fetch packet contents"""
        for instruction in fetch_packet.instructions:
            if(instruction.valid and is_call(instruction)):
                call_addr = instruction.PC + 4
                return RAS_update(1, 0, call_addr)    # push to RAS
            if(instruction.valid and is_ret(instruction)):
                return RAS_update(0, 1, 0x0)          # pop from RAS
        return RAS_update.null()