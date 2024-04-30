class SimpleDRAM:
    def __init__(self, sizeKB=16):
        self.memory = bytearray(sizeKB*(1<<10))

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
