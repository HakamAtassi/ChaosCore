`ifndef CACHE_BASE_TEST
`define CACHE_BASE_TEST


`include "cache_env.svh"

class env_config;
    virtual instruction_cache_if cache_vif;
    function new();
        
    endfunction 
endclass 

class cache_base_test extends uvm_test;

    `uvm_component_utils(cache_base_test)

    cache_env env;
    env_config env_cfg;

    function new(string name, uvm_component parent);
        super.new(name, parent);
        env_cfg = new();
    endfunction

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);
        if(!uvm_config_db #(virtual instruction_cache_if)::get(this, "", "cache_vif", env_cfg.cache_vif)) begin 
            `uvm_error("TEST", "Failed to get cache interface") 
        end
        uvm_config_db#(env_config)::set(this, "env", "env_cfg", env_cfg);
        env = cache_env::type_id::create("env",this);
    endfunction

endclass

`endif