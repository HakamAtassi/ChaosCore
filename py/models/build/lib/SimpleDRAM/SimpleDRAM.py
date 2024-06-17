import random
import os

class SimpleDRAM:
    def __init__(self, sizeKB=16, bin=None):
        random.seed(0x42)
        self.memory = bytearray(sizeKB*(1<<10))
        if(bin):
            self.init_from_bin(bin)

    def init_from_bin(self, bin):

        with open(bin, "rb") as f:
            bin_data = f.read()
            bin_size = len(bin_data)
            if bin_size > len(self.memory):
                raise ValueError("Binary file is larger than memory size")
            self.memory[:bin_size] = bin_data

    def read(self, address, size):
        if address + size > len(self.memory):
            raise ValueError("Writing to Memory Out of Bounds")
        data = self.memory[address:address + size]
        return data

    def write(self, address, data, size):
        if address + size > len(self.memory):
            raise ValueError("Writing to Memory Out of Bounds")
        if isinstance(data, int):
            data = data.to_bytes(size, byteorder="little")  # Assuming writing 1 byte

        self.memory[address:address + size] = data

    def randomize(self):
        random_data = bytearray(random.getrandbits(8) for _ in range(len(self.memory)))
        self.memory[:] = random_data
    
    def print(self):
        for i in range(len(self.memory)):
            print(f"{hex(i)} {hex(self.memory[i])}")
        print("")
        print("")