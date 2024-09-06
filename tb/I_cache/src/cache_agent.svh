class cache_agent extends uvm_agent;

    virtual interface instruction_cache_if i;

    function new(string name="", uvm_component parent);
        super.new(name, parent);
    endfunction: new

    function void build_phase(uvm_phase phase);
        super.build_phase(phase);

        i = global_cache_if;
    endfunction : build_phase


endclass