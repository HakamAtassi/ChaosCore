from instructionCache.instructionCache import instructionCache

if __name__ == "__main__":
    print("test")
    cache = instructionCache(sets=64, ways=2, blockSize=32, fetchWidth=4)
    cache.print()
