class cache_base_test extends uvm_test;

    `uvm_component_utils(cache_base_test)

    cache_env env;

    function new(string name, uvm_component parent);
        super.new(name, parent);
    endfunction

endclass