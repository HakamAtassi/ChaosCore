from InstructionCache import *
from SimpleDRAM import *

if __name__ == "__main__":
    print("test")
    cache = InstructionCache(sets=64, ways=2, blockSize=32, fetchWidth=4)
    #dram = SimpleDRAM()
    #dram.write(address=0, size=1, data=0x42)
    #print(dram.read(address=0, size=1))


