---
layout: default
title: MOB
parent: Core Architecture
nav_order: 7
---


The ChaosCore MOB is a fairly aggressive memory unit due to its ability to execute loads despite earlier, unresolved stores. 


The ChaosCore MOB is a particularly complex module. There are several reasons for this, but most notably, it is due to the fact that loads must place their result on the CDB in short order to help resolve dependancies and avoid stalling the core, despite the fact that this data is "speculative". Speculative, in this context, refers to the fact that the load data may be uninformed of a store to the same address that has not yet been placed in the MOB by the MEMRS (due to a longer dependancy). Coupled with the fact that the D$ is also an out of order component, managing memory operations becomes a very meticulouis process. 

In order to maintain the performance of the out of order core while respecting memory ordering, the broadcasting of results to the CDB must be decoupled from the updating the ROB status of the memory operations. More specifically, loads output their data to the CDB following a response from the cache to that MOB entry. Simultaniously, loads output their competion status to the ROB when all earlier stores have resolved, at which point, the violation status of the load is guaranteed to be correct. 


Stores, in contast, function a little differently- They are marked as complete by the ROB when output by the AGU and check future loads for conflicts. The store does not actually execute until they are marked as committed by the ROB. 


Loads are not marked as complete until its violation bit is valid, which will occur when all previous stores have resolved, and when the load has also broadcasted its result.



# Port list

```
input flush                         // clear MOB on exception/misprediction

input reserve                       // Reserve spot for memory operation
output reserved_pointers            // Provide pointers to reserved memory operations

input AGU                           // Memory operation data/address from AGU
input commit                        // core commit signal

output complete                     // Update ROB entries (mark memory ops as complete)
output MOB                          // Output data to CDB

input backend_memory_response       // D$ request
output backend_memory_request       // D$ response
```



# Operation

The general operation of the MOB is outlined in the following phases/states:

1) Reserve
2) update
3) request
4) output
5) complete
6) commit
7) clear?





The described operation is implemented by providing each entry with a few state bits. The operation of the state machine depends on whether the entry is a load or store. The state diagram for each entry is outlined below:


**TODO**



loads notify the ROB that they are complete when they have broadcasted their result to the CDB, and when their entry in the indetermination matrix indicaets all previous stores have had their address resolved (and as such would have set the violatio bit as needed). Stores notify the ROB that they are complete when their address has resolved and when they have looked up the MOB for violations as needed. Unlike loads, however, stores are not send to the D$ until they have comitted and until the D$ port is free.


To put matters succintly, incoming stores look up the MOB for possible collisions. If a violation is found, set the violation bit of the offending load. The violation bit cannot be trusted until ALL earlier stores have computed their addresses. The validation of each violation bit is performed/maintained by an indetermination matrix. 






# Verification

A functional MOB has the following properties

When a MOB outputs wrong load data, it's ROB output indicates a violation
Stores do not occur until after they commit
Instructions cannot commit until after they complete
Stores must occur in order
memory state as a result of the MOB should not be altered (should match theoretical memory)


# More implementation replated things. 
Construction a stream of NOPS, loads, and stores
for the golden model, simply execute them one at a time for reference
For the DUT, convert them to a series of fetch packets and feed them into the MOB.


## cache response driving
Just a byte array. each response has a random generated latency. Make sure this random generated latency doesnt interfere with stores and cause random memory consistency violations. 
For the fetch packet driver, when a violation is found, replay the instruction stream from that fetch packet. 


at the end of the simulation, compare both memory states to ensure that they match.


Things that need to be checked: 
I think I should consider adding a 64 bit "ID" register for debug to help link the outputs to the inputs since the module is out of order.

Monitor the D$ request queue to ensure that stores occur in program order, and they they only occur after commit. 
Monitor the output of the MOB to ensure that the data is either incorrect, or that an invalidation request is made. 
Monitor the ROB complete channel to ensure that executed fetch packets are eventually marked complete. 
Monitor the ready channel to ensure that the MOB is not full for no reason, etc...



...

To help verify the MOB, each instruction is provided with a 64 bit ID (purely for verification).
This enables the verification to be reduced to the following 3 properties.

1) Loads return the correct Data.
2) Loads return incorrect Data and are replayed. 
3) Stores complete in the order they are requested.
4) The number of available entries = number of reserved entries - number of freed entries (how do you know the number of freed entries?) ? (this is wrong but something like this?)

if all of these conditions hold, the MOB likely works. Though, there are a few nuances.

an instruction ID can return more than once, if, for example, it is in a replayed instruction packet. 
An instruction ID cannot store more than once, as stores dont occur until commit (and commits dont happen twice).


If a load keeps replaying and never returns the correct data, the MOB is evidently broken.
If stores execute out of order, even if to different addresses, the MOB is also considered broken.

The problem here is that stores should just forward their data as soon as their address is resolved. So, when a store address is recieved, it computes the data it needs to forward and writes it to the conflicting MOB entries. At this point, the store is deemed "complete" and is free to write its data to the D$ and clear its MOB entry when committed. 




_________________________________________







