package instruction_cache_pkg;
    import uvm_pkg::*;
    virtual interface instruction_cache_if global_cache_if;


`include "cache_env.svh"
`include "cache_base_test.svh"

//agents
`include "cache_agent.svh"
`include "cpu_io_agent.svh"
`include "dram_axi_agent.svh"

`include "cache_resp.svh"
`include "cache_req.svh"
`include "cpu_io_sequencer.svh"
`include "cpu_io_monitor.svh"
`include "cpu_io_driver.svh"


endpackage