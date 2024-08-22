


# MOB Verification

The job of the MOB is to aid in the execution of memory operations out-of-order. Namely, its job is twofold: to buffer stores till commit, wherein they are fired to memory, and to enable the execution of loads despite earlier pending stores to the same address that have not yet committed. As far as the verification is concerned, the MOB's operation can be viewed as a 4 stage process:

1) reserve:
    - When a memory instruction is decoded, it must also reserve a position in the MOB. During the reservation process, the MOB also outputs a pointer to the MOB entries for use when the address/memory of the instruction is determined. This stage simply buffers any informtion from the decode stage that is needed to peform the load/store.
2) Update:
    - When the AGU computes the memory address/data, this information is passed to the MOB to update the corresponding entry. This essentially informs the MOB with everything that is required to actually perform the memory operation. 
3) Execute:
    - During this stage, the memory operation is requested from memory. If this operation is a store, it returns nothing. If this operation is a load, the memory subsytem will, at some point in the future, return the data and the MOB index. 
5) Output: 
    - During this stage, the MOB will first check if earlier MOB entries have any colliding stores, and will then output the memory request, merged as necessary. 
6) Commit:
    - This occurs in paralell to the above operations. When the front of the MOB has compelted, it commits, and updates any ROB state as needed. Violations or normal commits are handled here. 

Notes:
    - For memory operations, Loads/Stores are not marked as complete by FUs as would be the case traditionally. Instead, Loads/Stores are marked complete by the MOB (though they still must project their valid bits to the RS, just not to the ROB). Instructions are marked as complete when they are at the front of the MOB, are actually complete, and have not experienced a memory violation. Upon the detection of a memory violation, the violation bit in the ROB is marked, the pipeline is flushed, and the memory operations at that fetch packet are reattempted. 



# TODO: 
something to drive requests
something to drive responses (DRAM emulation with random latency)
a way to keep track of violations/commits
a way to keep track of the correctness of output based on what the MOB is aware of at that time