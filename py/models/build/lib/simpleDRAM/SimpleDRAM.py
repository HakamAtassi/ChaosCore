class SimpleDRAM:
    def __init__(self, sizeKB=16):
        self.memory = bytearray(sizeKB*(1<<10))

    def read(self, address, size):
        if address + size > len(self.memory):
            raise ValueError("Memory read out of bounds")
        data = self.memory[address:address + size]
        return hex(int.from_bytes(data, "little"))

    def write(self, address, data, size):
        if address + size > len(self.memory):
            self.memory.extend(b'\x00' * (address + size - len(self.memory)))
        if isinstance(data, int):
            data = data.to_bytes(size, byteorder="little")  # Assuming writing 1 byte

        self.memory[address:address + size] = data
