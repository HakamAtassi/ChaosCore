from Channels import *

class Predecoder:
    def __init__(self, start_address):
        self.expected_address = start_address

    def validate(self, fetch_packet, RAS_read, BTB_resp):
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
            self.next_address = self.get_next_address(fetch_packet, RAS_read, BTBResp)
            validated_fetch_packet = self.validate_fetch_packet(fetch_packet)
            RAS_update = self.get_RAS_update(fetch_packet, BTB_resp)
            return (validated_fetch_packet, RAS_update, Revert.null())
        elif(not packet_valid):  # if packet not valid
            revert = Revert((self.next_address, BTB_resp.GHR, 1))
            return (fetch_packet.null(), RAS_update.null(), revert)

        assert False, "Packet neither valid nor invalid"

    def get_next_address(self, fetch_packet, RAS_read, BTB_resp):
        """get the next address based on fetch packet contents"""
        next_address = fetch_packet.PC + 16     # FIXME: is this always +16 or can it be less (is PC always aligned??)?
        for instruction in fetch_packet.instructions:
            if(instruction.valid):
                if(instruction.JAL):    # always taken if valid
                    next_address = fetch_packet.PC + instruction.index + instruction.imm
                    break
                if(instruction.ret):
                    next_address = RAS_read.address
                    break
                if(instruction.JALR and BTB_resp.hit and (BTB_resp.br_mask == (0b1000>>instruction.index))):
                    next_address = BTB_resp.target
                    break
                if(instruction.JALR and BTB_resp.hit and (BTB_resp.br_mask == (0b1000>>instruction.index)) and prediction.T_NT):
                    next_address = BTB_resp.target
                    break
        return next_address
    def validate_fetch_packet(self, fetch_packet, BTB_resp):
        """validate/invalidate instructions based on fetch packet contents"""
        valid = 1
        for instruction in fetch_packet.instructions:   # all instructions following a taken branch are invalidated
            instruction.valid=valid
            if(instruction.valid):
                if(instruction.JAL):
                    valid=0
                if(instruction.ret):
                    valid=0
                if(instruction.JALR and BTB_resp.hit and (BTB_resp.br_mask == (0b1000>>instruction.index))):
                    valid=0
                if(instruction.JALR and BTB_resp.hit and (BTB_resp.br_mask == (0b1000>>instruction.index)) and prediction.T_NT):
                    valid=0

    def get_RAS_update(self, fetch_packet):
        """generate RASUpdate request based on fetch packet contents"""
        valid = 1
        for instruction in fetch_packet.instructions:
            if(instruction.valid and instruction.call):
                call_addr = instruction.PC + 4
                return RAS_update((1, 0, call_addr))    # push to RAS
            if(instruction.valid and instruction.ret):
                return RAS_update((0, 1, 0x0))          # pop from RAS
        return RAS_update.null()