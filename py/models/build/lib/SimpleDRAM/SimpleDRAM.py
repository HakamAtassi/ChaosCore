import random

class SimpleDRAM:
    def __init__(self, sizeKB=16):
        random.seed(0x42)
        self.memory = bytearray(sizeKB*(1<<10))
        self.response_pending = False
        self.remaining_cycles = 0

    def read(self, address, size):
        if address + size > len(self.memory):
            raise ValueError("Writing to Memory Out of Bounds")
        data = self.memory[address:address + size]
        return int.from_bytes(data, "little")

    def write(self, address, data, size):
        if address + size > len(self.memory):
            raise ValueError("Writing to Memory Out of Bounds")
        if isinstance(data, int):
            data = data.to_bytes(size, byteorder="little")  # Assuming writing 1 byte

        self.memory[address:address + size] = data

    def randomize(self):
        random_data = bytearray(random.getrandbits(8) for _ in range(len(self.memory)))
        self.memory[:] = random_data
    
    def update(self, address, size ,valid):
        if valid:
            self.response_pending = True
            self.pending_address = address
            self.remaining_cycles = random.randint(1,100)
        if(self.response_pending):
            if(self.remaining_cycles == 0):
                self.response_pending = False
                return (self.read(self.pending_address, size), 1)
            else:
                self.remaining_cycles -= 1

        return(0,0)



    def print(self):
        for i in range(len(self.memory)):
            print(f"{hex(i)} {hex(self.memory[i])}")
        print("")
        print("")