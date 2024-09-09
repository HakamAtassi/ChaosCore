


# testplan


Generate an input, attempt to write to ROB.

If accepted, update stim packet with ROB index. allocate each instruction into a pool. 

at some random point in the future, mark the packet as complete.
When a packet is detected as being marked complete, update the packet in the model. 

When a packet commits, check that packet in the model to make sure its actually committable. Also check for any required branches/mispredictions


# drivers

The IO of the ROB contains 

// inputs
val flush                       =   Input(Bool())
val ROB_packet                  =   Flipped(Decoupled(new decoded_fetch_packet(coreParameters)))
val FU_outputs                  =   Vec(portCount, Flipped(ValidIO(new FU_output(coreParameters))))
val PC_file_exec_addr           =   Input(UInt(log2Ceil(ROBEntries).W))

// outputs
val commit                      =   ValidIO(new commit(coreParameters))
val ROB_index                   =   Output(UInt(log2Ceil(ROBEntries).W))
val PC_file_exec_data           =   Output(UInt(32.W))


## ROB packet 
Each fetch packet has the following entries


* fetch_PC                  ; the PC of the fetch packet
* decoded_instruction       ; the vector of decoded instructions
* valid bits                ; the valid bits of each instruction
* GHR                       ; GHR for the predictor
* TOS                       ; the TOS of the RAS
* NEXT                      ; the NEXT of the RAS
* prediction                ; the frontend prediction for this packet
* free_list_front_pointer   ; the front pointer of the free list in the rename stage


Populate the instructions mostly randomly


1) Generate random fetch packet
2) Generate validity
3) Iterate over fetch packet, get actual fetch PC. choose mispred or not. update prediction
4) write to ROB_packet queue
6) drive from ROB_packet queue
7) when ROB packet accepted, place instructions into corresponding FU pool based on port 
8) randomly select from each FU pool and place into FU queue
9) drive from FU queue






# monitors

## Allocate monitor
If an allocation is accepted, allocate it in the SW model.

## FU output monitor
If an FU is indicating a complete insturction, update the model

## Commit monitor
When a commit occurs, clear that entry from the model and place it in a committed ROB entry queue. Place the monitored commit entry in a dut committed queue.
...
update model result Q with commit
update dut result Q with commit

## Ready monitor
update model result Q with full (outstanding entries <64)
update dut result Q with full (based on ready bit)


# properties

These read from the above queues and ensure that responses match

## Commit checkers
Ensure that committed ROB entries match. Ex, both have committed that entry, both indicate the same mispred status, etc...

## ROB Index checker
Ensure that the ROB index updates whenever it accepts a packet. 

## Ready checker
Ensure that the number of accepted and uncommitted packets is never larger than 64


