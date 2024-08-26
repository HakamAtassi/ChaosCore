


# MOB Verification

The verification of the MOB is nuanced because it schedules loads and stores out of order, and can also return incorrect load data so long as it is later corrected by indicating a load violation to the ROB. Additionally, the MOB interfaces with many components that must be modeled accurately to achieve a simulation that effectively stresses the MOB. 

At a high level, the verification of the MOB is split into two relatively independant properties. The first property is that the result of the most recent loads of a certain fetch packet must be correct after that fetch packet is comitted. Though a load may output incorrect data, that data must be corrected (via a replay) prior to that fetch packet's commit. As such, a fetch packet may execute an arbitrary number of times, so long as the most recent execution prior to it's commit is 100% accurate. 

The second property is that all stores can only execute once, in program order, with correct data. 


## Implementation

Unfortunately, the verification of the MOB requires quite a bit of surrounding infrastructure. This includes a model of the ROB and Memory, sequencers/drivers for the reserve/AGU inputs, and a monitor on the FU output channel (to read load results) and Memory channel (to read store requests). The role of the ROB model in this context is to just be functionally accurate. The AGU & Reserve drivers, however, must stress the MOB effectively, testing burst allocations and resolutions, long latency resolutions, etc. This applies to the memory model as well, with the added complexity of possible out of order responses. Further, it is also important to generate random addresses that will actually incur conflicts with one-another, which is very unlikely with completely random fuzzing.



## Memory Model

The MOB testbench Memory component is used to mimic the behaviour of the ChaosCore DRAM. Since the D$ in ChaosCore is capable of returning responses out of order, the memory component in the testbench returns responses out of order as well. 

Generally the testbench memory operates by monitoring the memory request lines. When a request is detected, it queues it in a structure that maps cache lines to memory requests. Every cycle, the response is determined by randomly selecting a cache line to service and performing the corresponding request. The memory also provides a flush feature that performs all outstanding memory requests such that the final memory state can be quickly determined

The memory model is also capable of randomizing hits and misses, as well as their corresponding latencies.


