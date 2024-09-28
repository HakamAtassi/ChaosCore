---
layout: default
title: CSRs
parent: Core Architecture
nav_order: 6
---




CSRs are kind of tricky. Here are some notes to help bring this page together.


* First, CSR reads and writes flush the pipeline. 
    * This is to avoid the case of bogus CSRR back to back reads of a timer or something similar. 

* Since any instruction can (or should have the capacity to) cause an exception, all instructions require the mstatus for which they executed under. 
* This can just be broadcasted out of the CSR unit. Any changes to mstatus would be flushing any instructions with improper ordering relative to an MSTATUS change anyway.

When an exception occurs, the pipeline is flushed. The frontend redirects to MTVEC. MEPC is set to the excepting PC. MSTATUS is updated. The trap handler is executed. Eventually, mret is executed. 
