
# L1 Data Cache

The ChaosCore L1 Data Cache is a non-blocking PLRU cache. It supports a parameterizable number of outstanding misses (MSHRs) block size, and way count. Provide data for what increasing each fo these does to performance. 


## Operation

The L1 data cache pipeline for hits is very simple. On the first cycle, the request address is translated into its consituent parts (tag, set, byteoffset). Then the tag, valid, PLRU, and dirty memories are then accessed during this same initial cycle. Using information on the hit way, the data memory is accessed. At this time, the PLRU and dirty memories are updated. One cycle later, the data is passed through for formatter to extract the desired byte, word, or halfword. 

Write hits need not to be formatted. As such, the last format cycle is not used and the latency of the request is 2 cycles.

## Cache Misses
The handling of cache misses is where much of the complexity of the ChaosCore cache lies. After a request to data that does not exist in the cache is made, a `valid_miss` signal is raised. This signal then buffers the required miss information into an MSHR structure that buffers the request address, data (if any), MOB index, access type, and allocation information, such as `allocate_way` in order to allocate data without re-accessing memories on DRAM response. While the `valid_miss` flag is still raised, the data cache's `AXICacheNode` will perform a simultainous read and write request from the system. Since AXI uses sepreate channels to for reads and writes, a cache miss can request the evicted line be written to the system while it also requests the missed line be read from memory. Since these two lines are never conflicting by construction, this is a safe AXI request. At this point, is it critically important that the evicted cache line be marked invalid. This is to avoid further updates to the cache line, which is currently being written to the dram (is in-flight) is not updated by more recent instructions.

## DRAM response

On DRAM response, the MSHRs are looked up to find all accesses to the returned cache line. This lookup then returns the allocate way & set, informing the cache line where it belongs in the cache. Following the allocation of the cache line, the outstanding misses are replayed, returning their responses as if they were requested from the CPU once again. 

## MSHRs
AXI transactions with the same ID are returned in-order. This means that the MSHR is a queue, catagorized by address, that is in sync with the responses returned by the system. This assumption is only violated when the response is of a different ID, which only occurs when responses to non-cacheable memory are made, which is handled separately (AXI returns the request ID on responses so this case is easy to identify). Never the less, each MSHR entry contains all the misses that occured at a specific address, in the order they took place. Meaning MSHR entry 1 may pertain to address 0xdeadbeef, where the contents of the MSHR contain the requests to that address in sequential program order.

The cache is marked unready and the front entry of the MSHR is replayed one request at a time, until that MSHR entry is free. (MSHR load to store forwarding?)



## Cacheability
Not all accesses to memory can be fetched from the Cache/DRAM. Some memory accesses write or read from the device directly. This introduces the need for CPU requests to be checked for cacheablity. Non-cacheable requests are first buffered in a local structure, then requested directly from the memory. One the none-cacheable response returns, its data is placed in the local buffer and is scheduled to write its result as soon as the output port is free. One written to the CPU response port, it is freed from the local buffer and operation proceeds as normal. Writes to non-cacheable memory need not be scheduled and are just cleared from the structure as soon as the AXI write is ACKed. 
