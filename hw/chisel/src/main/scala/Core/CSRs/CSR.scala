

// There are 3 priv levels

// User (0)
// Supervisor (1)
// Machine (3)


// For now the core only really needs Machine and User.
// Supervisor is needed for OS 
// The ZICSR extension refers to the CSR interaction instruction
// CSR addresses are 12 bits. 
// top 2 bits encode R/W


/*
*
*   IMPLEMENTED CSRs
*   
*   User level CSRs
*   cycle: increments every cycle
*   time: timer based on freq and cycle count   
*   instret: instructions retired counter
*   + Custom performance counters
*   
*   Machine level CSRs
*   mvendor id
*   march id
*   mimpid
*   mhardid
*   mconfigptr
*   
*   // Machine Trap Handling
*   mstatus
*   misa
*   medeleg
*   mideleg
*   mie
*   mtvec
*   mcounteren
*   mstatush
*   medelegh
*
*
*   // Machine Trap Handling
*   mscratch
*   mepc
*   mcause
*   mtval
*   mip
*   mtinst
*   mtval2
*
*
*
*
*
* Counters are implemented as regs.
* Other CSRs are implemnted in BMEM
*
*
*
*/
