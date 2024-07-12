

# Problems

1) Exceptions are completely unimplemented
2) No commit RAT
3) On exception, copy commit RAT to active RAT checkpoint (how do exceptions update RAT? in what way?)
4) CSR access must be ordered



# Mispredictions

On mispredictions, the RAT can be restored and the free list can be also fully restored from checkpoint.
The fetch packet can then replay with the correct information, so the free list is correctly updated.

On exceptions, the RAT is copied (and modified with currently commiting instructions) from the 
committ RAT. The free list is also restored, but the difference is that instructions after and including 
the exception are both considered "freed" (not a complete reversion), and do not update the commit RAT. 