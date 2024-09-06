class monitor extends cache_agent;

    `uvm_component_utils(monitor)

    function new (string name, uvm_component parent);
        super.new(name, parent);
    endfunction

endclass