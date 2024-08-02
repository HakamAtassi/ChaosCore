`timescale 1ns/1ps

`include "/Users/hakamatassi/Repos/ChaosCore/hw/verilog/AXI_master_slave.sv"
`include "/Users/hakamatassi/Repos/ChaosCore/hw/verilog/AXI_master.sv"
`include "/Users/hakamatassi/Repos/ChaosCore/hw/verilog/axi_ram.v"
`include "/Users/hakamatassi/Repos/ChaosCore/hw/verilog/Queue1_UInt256.sv"

module AXI_master_slave_tb;

  // Clock and Reset signals
  reg clock;
  reg reset;

  // Instantiate the module under test (MUT)
  AXI_master_slave uut (
    .clock(clock),
    .reset(reset)
  );

  // Clock generation
  initial begin
    clock = 0;
    forever #5 clock = ~clock; // 100 MHz clock (10 ns period)
  end

  // Reset generation
  initial begin
    reset = 1;
    #20; // Keep reset high for 20 ns
    reset = 0;
  end

  // Simulation control
  initial begin
    // Run the simulation for a certain time
    #1000;
    $finish;
  end

  // Optionally, add waveform dump for simulation analysis
  //initial begin
    //$dumpfile("tb_AXI_master_slave.vcd");
    //$dumpvars(0, tb_AXI_master_slave);
  //end

endmodule
