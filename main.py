from instructionCache import instructionCache as ic


if __name__ == "__main__":
    print("test")
    cache = ic(sets=64, ways=2, blockSize=32, fetchWidth=4)