class cpu_io_sequencer extends uvm_sequencer;

    `uvm_component_utils(cpu_io_sequencer)

    function new(string name, uvm_component parent);
        super.new(name, parent);
    endfunction

endclass