

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
