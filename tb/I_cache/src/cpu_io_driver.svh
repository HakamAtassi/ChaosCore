`ifndef CPU_IO_DRIVER
`define CPU_IO_DRIVER

class cpu_io_driver extends uvm_driver;

    `uvm_component_utils(cpu_io_driver)

    function new(string name, uvm_component parent);
        super.new(name, parent);
    endfunction

    task run_phase(uvm_phase phase);
        // dut_vif.reset = 1;
        // @(posedge dut_vif.clock);
        // #1;
        // dut_vif.reset = 0;
        
        // forever begin
        //     seq_item_port.get_next_item(req);

        //     dut_vif.cmd  = req.cmd;
        //     dut_vif.addr = req.addr;
        //     dut_vif.data = req.data;
        //     @(posedge dut_vif.clock);

        //     seq_item_port.item_done();
        // end
    endtask

endclass

`endif