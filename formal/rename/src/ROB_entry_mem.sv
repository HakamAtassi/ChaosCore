// Generated by CIRCT firtool-1.62.0
// Standard header to adapt well known macros for prints and assertions.

// Users can define 'PRINTF_COND' to add an extra gate to prints.
`ifndef PRINTF_COND_
  `ifdef PRINTF_COND
    `define PRINTF_COND_ (`PRINTF_COND)
  `else  // PRINTF_COND
    `define PRINTF_COND_ 1
  `endif // PRINTF_COND
`endif // not def PRINTF_COND_

// Users can define 'ASSERT_VERBOSE_COND' to add an extra gate to assert error printing.
`ifndef ASSERT_VERBOSE_COND_
  `ifdef ASSERT_VERBOSE_COND
    `define ASSERT_VERBOSE_COND_ (`ASSERT_VERBOSE_COND)
  `else  // ASSERT_VERBOSE_COND
    `define ASSERT_VERBOSE_COND_ 1
  `endif // ASSERT_VERBOSE_COND
`endif // not def ASSERT_VERBOSE_COND_

// Users can define 'STOP_COND' to add an extra gate to stop conditions.
`ifndef STOP_COND_
  `ifdef STOP_COND
    `define STOP_COND_ (`STOP_COND)
  `else  // STOP_COND
    `define STOP_COND_ 1
  `endif // STOP_COND
`endif // not def STOP_COND_

module ROB_entry_mem(
  input        clock,
  input  [5:0] io_addrA,
  input        io_writeDataA_valid,
               io_writeDataA_is_branch,
  input  [1:0] io_writeDataA_memory_type,
  input  [3:0] io_writeDataA_MOB_index,
  input        io_writeDataA_RD_valid,
  input  [4:0] io_writeDataA_RD,
  input  [6:0] io_writeDataA_PRDold,
               io_writeDataA_PRD,
  input        io_writeEnableA,
  input  [5:0] io_addrB,
  output       io_readDataB_valid,
               io_readDataB_is_branch,
  output [1:0] io_readDataB_memory_type,
  output [3:0] io_readDataB_MOB_index,
  output       io_readDataB_RD_valid,
  output [4:0] io_readDataB_RD,
  output [6:0] io_readDataB_PRDold,
               io_readDataB_PRD
);

  wire [27:0] _mem_ext_R0_data;
  mem_64x28 mem_ext (
    .R0_addr (io_addrB),
    .R0_en   (1'h1),
    .R0_clk  (clock),
    .R0_data (_mem_ext_R0_data),
    .W0_addr (io_addrA),
    .W0_en   (io_writeEnableA),
    .W0_clk  (clock),
    .W0_data
      ({io_writeDataA_PRD,
        io_writeDataA_PRDold,
        io_writeDataA_RD,
        io_writeDataA_RD_valid,
        io_writeDataA_MOB_index,
        io_writeDataA_memory_type,
        io_writeDataA_is_branch,
        io_writeDataA_valid})
  );
  assign io_readDataB_valid = _mem_ext_R0_data[0];
  assign io_readDataB_is_branch = _mem_ext_R0_data[1];
  assign io_readDataB_memory_type = _mem_ext_R0_data[3:2];
  assign io_readDataB_MOB_index = _mem_ext_R0_data[7:4];
  assign io_readDataB_RD_valid = _mem_ext_R0_data[8];
  assign io_readDataB_RD = _mem_ext_R0_data[13:9];
  assign io_readDataB_PRDold = _mem_ext_R0_data[20:14];
  assign io_readDataB_PRD = _mem_ext_R0_data[27:21];
endmodule

