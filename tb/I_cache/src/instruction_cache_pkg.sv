package instruction_cache_pkg;
    import uvm_pkg::*;
    virtual interface instruction_cache_if global_cache_if;


`include "cache_env.svh"
`include "cache_base_test.svh"

//agents
`include "cache_agent.svh"
`include "cpu_io_driver.svh"
`include "dram_axi_driver.svh"



endpackage