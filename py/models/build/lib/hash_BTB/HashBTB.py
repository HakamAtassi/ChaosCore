import numpy as np

class HashBTB:
    def __init__(self, entires):
        self.entires        = entires
        self.tag_mem        = [0] * entires
        self.target_mem     = [0] * entires
        self.type_mem       = [0] * entires
        self.br_mask_mem    = [0] * entires
        self.valid_mem      = [0] * entires

        self.address_bits = int(np.log2(entires))
        self.address_mask = (1<<self.address_bits) - 1

    def get_masked_address(self, address):
        return address & self.address_mask

    def address_to_tag(self, address):
        return (address>>self.address_bits)

    def predict(self, address):
        masked_address = self.get_masked_address(address)
        current_tag = self.address_to_tag(address)

        tag     = self.tag_mem[masked_address]
        target  = self.target_mem[masked_address]
        type    = self.type_mem[masked_address]
        valid   = self.br_mask_mem[masked_address]
        br_mask = self.valid_mem[masked_address]

        hit = ((current_tag == tag) and valid)

        return (hit, target, type, br_mask)

        
    def commit(self, address, target, type, br_mask):
        masked_address = self.get_masked_address(address)
        current_tag = self.address_to_tag(address)

        self.tag_mem[masked_address]        = current_tag
        self.target_mem[masked_address]     = target
        self.type_mem[masked_address]       = type
        self.br_mask_mem[masked_address]    = br_mask
        self.valid_mem[masked_address]      = 1



