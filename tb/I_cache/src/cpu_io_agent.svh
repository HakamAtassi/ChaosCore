
class cpu_io_agent extends cache_agent;

    `uvm_component_utils(cpu_io_agent)

    cpu_io_driver driver;
    cpu_io_monitor monitor;

    function new(string name, uvm_component parent);
        super.new(name, parent);
    endfunction

endclass