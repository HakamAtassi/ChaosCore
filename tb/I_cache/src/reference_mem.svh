`ifndef REFERENCE_MEM
`define REFERENCE_MEM

class memory extends uvm_object;

    `uvm_object_utils(memory)  

    reg [31:0] mem [16383:0];
    integer index;

    function new(string name = "");
        super.new(name);
    endfunction
endclass

`endif