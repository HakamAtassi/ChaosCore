

# TODO



1) Fix the instruction queue
2) Fix predecode validate outputting predictions to the FTQ
3) Fix commit logic in rob/BRU
4) Fix the clearing on mispredict
5) Implement Ready bits in the rename stage
6) An actual memory subsystem




# Test

1) test that invalid instructions are propograted correctly

## instruction queue
1) Test instruction queue is can read and write at the same time
2) Test that it doesnt queue invalid instructions
3) Test write-through if queue is not needed (optional)
4) 
