


# Data Cache Test Plan

The data cache is a surprisingly sophisticated part of the design and as such warrants its own deticated verification environment.

# Verification Strategy

The data cache really consists of two primary functionalities that must operate correctly for the design to operate correctly. The first of which is the AXI interface that communicates with the memory/SOC. The second is the actual functionality of the cache. 

# AXI Verification
The data cache will only ever access the bus to either request a new line and (potentially) write back an old line, or to access non-cacheable data. As such, the testbench will be constantly monitoring and checking the AXI side of the cache to ensure its adhereance with the AXI specification. 

The data cache only performs a few fairly simple AXI transactions. The first is a plain AXI read request. When a cache line misses, and its corresponding location in the cache is either invalid or not dirty, the cache will simply request a cache line from memory through an INCR burst with ID=0. If the cache must write back a line, then it will place a read request on the AXI_R channel and a write request on the AXI_AW/AXI_W channel simultaniously. Both of these requests are bursts of the size of the cache line. 

On occasion, the cache will request a read or a write to an address that is non-cacheable. This situation will simply convert the cache request to an AXI request and place it on the bus. This means that the transaction will be of size 8/16/32 bits as opposed to 256/512 bits. 

In any case, regardless of the origin of the transaction, it is naturally critically important that the AXI port of the cache is valid as to avoid corrupting memory or stalling the bus.


## AXI Memory Unit/Model

# Cache Verification
In addition to ensuring correct AXI functionality, the data cache must also be verified. Though the cache is an out-of-order unit, meaning memory operations may occur in a sequence different to that in which they were requested, from the prespective of the programmer (more accurately the user of the cache), memory sequential consistency must be maintained. To verify that this is in fact the case, the cache is verified by reflecting all of its requests in the order in which they were reflected through the use of a "magic memory" that has no concept of cache hits or misses. This magic memory will always instantly generate accurate memory responses in *actual* program order. Consequently, this magic memory may fall out of sync with the memory state of the cache, but that is by design and will be leveraged to ensure cache functionality. 

This also means that the AXI memory module used in the testbench must be initialized to the same data as the AXI magic memory. This is handled during the initialization of the testbench. 