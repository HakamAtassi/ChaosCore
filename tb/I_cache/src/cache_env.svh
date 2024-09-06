`include "uvm_macros.svh"
class cache_env extends uvm_env;
    `uvm_component_utils(cache_env)

    function new (string name, uvm_component parent);
        super.new(name, parent);
    endfunction

endclass