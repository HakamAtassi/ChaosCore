

# TODO



1) _Fix the instruction queue_
2) Fix predecode validate outputting predictions to the FTQ
3) Fix commit logic in rob/BRU
4) Fix the clearing on mispredict
5) Implement Ready bits in the rename stage
6) An actual memory subsystem
7) Right now checkpoints are created per fetch packet. If the Nth instruction is mispredicted, you jump to the first instruction in the fetch packet and replay from there. Ensure this actually works. Otherwise, N checkpoints will need to be made per cycle, which is very expensive.


# Test

1) test that invalid instructions are propograted correctly

## instruction queue
1) Test instruction queue is can read and write at the same time
2) Test that it doesnt queue invalid instructions
3) Test write-through if queue is not needed (optional)
4) 


1) Fix the core
2) run yosys formal when we think it works
3) add optimizations as needed (branch prediction, LSQ, MMU, multibanked data cache, etc...)
4) Multicore ???


# Manycore chess accelerator
Hardware
Software
Compiler (optional?)


# Chess game software stuff
Video component (Chessboard, pieces, user interface, menu, etc...)
Integration (OS memory, Accelerator access, DMA, etc...)

## video component

0) How does SDL2 integrate with RISC???
    - try building with RISCV GNU + spike
    - Green light
    - or just google to see if anyone else did this

1) SDL2
2) Menu, user I/O
3) Chess board/pieces, etc...
4) C++
5) https://www.youtube.com/@Bisqwit/featured
6) Make/CMAKE for building project
7) Library of sprites and images and stuff






eventually

6) user vs bot mode
7) CTF mode in menu ???
8) Rating bar (strength of the BOT/accelerator)
9) idk ???




# Timeline

## Non-negotionable

Core must work by July 30th

Semester 1: Core + Accelerator working + game "beta" working + possible core optimization
Semester 2: Integration, CTF game mode stuff + possible core optimization

