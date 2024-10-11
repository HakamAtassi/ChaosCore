---
layout: default
parent: Core Architecture
title: AXI
nav_order: 2
---




## Cache Bus Access types

ChaosCore L1 caches have 2 main types of accesses to the system bus: Cache line transfers (read/writes) and Word/Subword accesses. Cache access types can further be catagorized by cache type:

I$: The I\$ only every requests full cache line reads from the system bus. There are no exceptions.
D\$: The D\$ can either request full cache line read/writes from the system bus (cache evictions and allocates), and read/writes to non-cacheable regions of memory. Cacheable word/subword accesses are treated as a miss-R/W combo (and therefore fall into the full cache line transfer category).

As such, AXI Cache Nodes are only required to handle full cache line transfers and Word/Subword reads/writes. Any other memory requests combos are not required for complete functionality. 

## AXI Node

ChaosCore implements the trait `AXICacheNode`. This trait provides L1 caches a port into the shared system bus. Modules that "mix in" this trait are provided with an AXI implementation of the following characatersitcs:

* AXI write requests and read requests are mutually exclusive, ie, when a write or read is in progress, no other writes or reads are accepted until the ongoing request responds. (that is, is unpipelined, to avoid memory consistency issues).
* Supports single and multi beat incr operations
* Either reads/writes complete cache lines or read/writes words/subwords
* Stalls when a recieved response is never used by the master. 

### API 

* On reads, the AXI master completes the address phase, then moves to the response phase while it waits for and reconstructs its data. It then buffers the response in a 1 entry queue of width equal to the cache line size. Further reads are prohibited until the response queue is read out. 
* On writes, the AXI master issues the write request in the address phase. During the write phase, the desired write data is buffered. The AXI master then moves to the data phase, where it performs the beats. Once all beats have been transfered, it moves to the resp phase, where it awaits an OKAY signal from the slave. The master then returns to the address phase
* The AXI Cache Node is only capable of either full cache line movement or single word/subword movement. Word and subword transfers are handled in much the same way. The only difference is that cache line writes always have a fully high STRB, while subword writes have their strobe determined by the transaction type.