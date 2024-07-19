`ifndef VERILATOR
module testbench;
  reg [4095:0] vcdfile;
  reg clock;
`else
module testbench(input clock, output reg genclock);
  initial genclock = 1;
`endif
  reg genclock = 1;
  reg [31:0] cycle = 0;
  reg [1:0] PI_io_commit_bits_fetch_packet_index;
  reg [0:0] PI_io_revert_valid;
  reg [31:0] PI_io_prediction_bits_target;
  reg [0:0] PI_io_commit_bits_RD_valid_2;
  reg [0:0] PI_io_prediction_valid;
  reg [0:0] PI_io_commit_valid;
  reg [31:0] PI_io_revert_bits_PC;
  reg [31:0] PI_io_commit_bits_expected_PC;
  reg [6:0] PI_io_commit_bits_RD_1;
  reg [2:0] PI_io_commit_bits_br_type;
  reg [0:0] PI_io_prediction_bits_T_NT;
  reg [0:0] PI_io_commit_bits_RD_valid_3;
  reg [0:0] PI_io_commit_bits_T_NT;
  reg [3:0] PI_io_commit_bits_RAT_index;
  reg [6:0] PI_io_RAS_read_NEXT;
  reg [7:0] PI_io_commit_bits_free_list_front_pointer;
  reg [6:0] PI_io_commit_bits_NEXT;
  reg [0:0] PI_io_commit_bits_is_misprediction;
  reg [5:0] PI_io_commit_bits_ROB_index;
  reg [15:0] PI_io_prediction_bits_GHR;
  reg [6:0] PI_io_commit_bits_RD_3;
  reg [0:0] PI_io_commit_bits_RD_valid_0;
  reg [0:0] PI_io_PC_next_ready;
  reg [15:0] PI_io_commit_bits_GHR;
  reg [6:0] PI_io_commit_bits_RD_2;
  reg [6:0] PI_io_RAS_read_TOS;
  reg [6:0] PI_io_commit_bits_RD_0;
  reg [31:0] PI_io_RAS_read_ret_addr;
  wire [0:0] PI_clock = clock;
  reg [6:0] PI_io_commit_bits_TOS;
  reg [0:0] PI_reset;
  reg [0:0] PI_io_commit_bits_RD_valid_1;
  reg [0:0] PI_io_prediction_bits_hit;
  reg [31:0] PI_io_commit_bits_fetch_PC;
  reg [2:0] PI_io_prediction_bits_br_type;
  PC_gen UUT (
    .io_commit_bits_fetch_packet_index(PI_io_commit_bits_fetch_packet_index),
    .io_revert_valid(PI_io_revert_valid),
    .io_prediction_bits_target(PI_io_prediction_bits_target),
    .io_commit_bits_RD_valid_2(PI_io_commit_bits_RD_valid_2),
    .io_prediction_valid(PI_io_prediction_valid),
    .io_commit_valid(PI_io_commit_valid),
    .io_revert_bits_PC(PI_io_revert_bits_PC),
    .io_commit_bits_expected_PC(PI_io_commit_bits_expected_PC),
    .io_commit_bits_RD_1(PI_io_commit_bits_RD_1),
    .io_commit_bits_br_type(PI_io_commit_bits_br_type),
    .io_prediction_bits_T_NT(PI_io_prediction_bits_T_NT),
    .io_commit_bits_RD_valid_3(PI_io_commit_bits_RD_valid_3),
    .io_commit_bits_T_NT(PI_io_commit_bits_T_NT),
    .io_commit_bits_RAT_index(PI_io_commit_bits_RAT_index),
    .io_RAS_read_NEXT(PI_io_RAS_read_NEXT),
    .io_commit_bits_free_list_front_pointer(PI_io_commit_bits_free_list_front_pointer),
    .io_commit_bits_NEXT(PI_io_commit_bits_NEXT),
    .io_commit_bits_is_misprediction(PI_io_commit_bits_is_misprediction),
    .io_commit_bits_ROB_index(PI_io_commit_bits_ROB_index),
    .io_prediction_bits_GHR(PI_io_prediction_bits_GHR),
    .io_commit_bits_RD_3(PI_io_commit_bits_RD_3),
    .io_commit_bits_RD_valid_0(PI_io_commit_bits_RD_valid_0),
    .io_PC_next_ready(PI_io_PC_next_ready),
    .io_commit_bits_GHR(PI_io_commit_bits_GHR),
    .io_commit_bits_RD_2(PI_io_commit_bits_RD_2),
    .io_RAS_read_TOS(PI_io_RAS_read_TOS),
    .io_commit_bits_RD_0(PI_io_commit_bits_RD_0),
    .io_RAS_read_ret_addr(PI_io_RAS_read_ret_addr),
    .clock(PI_clock),
    .io_commit_bits_TOS(PI_io_commit_bits_TOS),
    .reset(PI_reset),
    .io_commit_bits_RD_valid_1(PI_io_commit_bits_RD_valid_1),
    .io_prediction_bits_hit(PI_io_prediction_bits_hit),
    .io_commit_bits_fetch_PC(PI_io_commit_bits_fetch_PC),
    .io_prediction_bits_br_type(PI_io_prediction_bits_br_type)
  );
`ifndef VERILATOR
  initial begin
    if ($value$plusargs("vcd=%s", vcdfile)) begin
      $dumpfile(vcdfile);
      $dumpvars(0, testbench);
    end
    #5 clock = 0;
    while (genclock) begin
      #5 clock = 0;
      #5 clock = 1;
    end
  end
`endif
  initial begin
`ifndef VERILATOR
    #1;
`endif
    // UUT.$auto$async2sync.\cc:228:execute$593  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$595  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$597  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$599  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$603  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$605  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$607  = 1'b0;
    // UUT.$auto$async2sync.\cc:228:execute$609  = 1'b0;
    UUT.PC = 32'b00000000000000000000000000000000;
    UUT.PC_next_skid_buffer.full = 1'b0;
    UUT.PC_next_skid_buffer.ram = 65'b00000000000000000000000000000000000000000000000000000000000000000;
    UUT.REG = 32'b00000000000000000000000000000000;
    UUT.hasBeenResetReg = 1'b0;

    // state 0
    PI_io_commit_bits_fetch_packet_index = 2'b00;
    PI_io_revert_valid = 1'b0;
    PI_io_prediction_bits_target = 32'b00000000000000000000000000000000;
    PI_io_commit_bits_RD_valid_2 = 1'b0;
    PI_io_prediction_valid = 1'b0;
    PI_io_commit_valid = 1'b0;
    PI_io_revert_bits_PC = 32'b00000000000000000000000000000000;
    PI_io_commit_bits_expected_PC = 32'b00000000000000000000000000000000;
    PI_io_commit_bits_RD_1 = 7'b0000000;
    PI_io_commit_bits_br_type = 3'b000;
    PI_io_prediction_bits_T_NT = 1'b0;
    PI_io_commit_bits_RD_valid_3 = 1'b0;
    PI_io_commit_bits_T_NT = 1'b0;
    PI_io_commit_bits_RAT_index = 4'b0000;
    PI_io_RAS_read_NEXT = 7'b0000000;
    PI_io_commit_bits_free_list_front_pointer = 8'b00000000;
    PI_io_commit_bits_NEXT = 7'b0000000;
    PI_io_commit_bits_is_misprediction = 1'b0;
    PI_io_commit_bits_ROB_index = 6'b000000;
    PI_io_prediction_bits_GHR = 16'b0000000000000000;
    PI_io_commit_bits_RD_3 = 7'b0000000;
    PI_io_commit_bits_RD_valid_0 = 1'b0;
    PI_io_PC_next_ready = 1'b0;
    PI_io_commit_bits_GHR = 16'b0000000000000000;
    PI_io_commit_bits_RD_2 = 7'b0000000;
    PI_io_RAS_read_TOS = 7'b0000000;
    PI_io_commit_bits_RD_0 = 7'b0000000;
    PI_io_RAS_read_ret_addr = 32'b00000000000000000000000000000000;
    PI_io_commit_bits_TOS = 7'b0000000;
    PI_reset = 1'b1;
    PI_io_commit_bits_RD_valid_1 = 1'b0;
    PI_io_prediction_bits_hit = 1'b0;
    PI_io_commit_bits_fetch_PC = 32'b00000000000000000000000000000000;
    PI_io_prediction_bits_br_type = 3'b000;
  end
  always @(posedge clock) begin
    // state 1
    if (cycle == 0) begin
      PI_io_commit_bits_fetch_packet_index <= 2'b00;
      PI_io_revert_valid <= 1'b1;
      PI_io_prediction_bits_target <= 32'b00000000000000000000000000000000;
      PI_io_commit_bits_RD_valid_2 <= 1'b0;
      PI_io_prediction_valid <= 1'b0;
      PI_io_commit_valid <= 1'b0;
      PI_io_revert_bits_PC <= 32'b00000000000000000000000000000000;
      PI_io_commit_bits_expected_PC <= 32'b00000000000000000000000000000000;
      PI_io_commit_bits_RD_1 <= 7'b0000000;
      PI_io_commit_bits_br_type <= 3'b000;
      PI_io_prediction_bits_T_NT <= 1'b0;
      PI_io_commit_bits_RD_valid_3 <= 1'b0;
      PI_io_commit_bits_T_NT <= 1'b0;
      PI_io_commit_bits_RAT_index <= 4'b0000;
      PI_io_RAS_read_NEXT <= 7'b0000000;
      PI_io_commit_bits_free_list_front_pointer <= 8'b00000000;
      PI_io_commit_bits_NEXT <= 7'b0000000;
      PI_io_commit_bits_is_misprediction <= 1'b1;
      PI_io_commit_bits_ROB_index <= 6'b000000;
      PI_io_prediction_bits_GHR <= 16'b0000000000000000;
      PI_io_commit_bits_RD_3 <= 7'b0000000;
      PI_io_commit_bits_RD_valid_0 <= 1'b0;
      PI_io_PC_next_ready <= 1'b1;
      PI_io_commit_bits_GHR <= 16'b0000000000000000;
      PI_io_commit_bits_RD_2 <= 7'b0000000;
      PI_io_RAS_read_TOS <= 7'b0000000;
      PI_io_commit_bits_RD_0 <= 7'b0000000;
      PI_io_RAS_read_ret_addr <= 32'b10000000000000000000000000000000;
      PI_io_commit_bits_TOS <= 7'b0000000;
      PI_reset <= 1'b0;
      PI_io_commit_bits_RD_valid_1 <= 1'b0;
      PI_io_prediction_bits_hit <= 1'b0;
      PI_io_commit_bits_fetch_PC <= 32'b00000000000000000000000000000000;
      PI_io_prediction_bits_br_type <= 3'b000;
    end

    // state 2
    if (cycle == 1) begin
      PI_io_commit_bits_fetch_packet_index <= 2'b00;
      PI_io_revert_valid <= 1'b0;
      PI_io_prediction_bits_target <= 32'b00000000000000000000000000000000;
      PI_io_commit_bits_RD_valid_2 <= 1'b0;
      PI_io_prediction_valid <= 1'b0;
      PI_io_commit_valid <= 1'b0;
      PI_io_revert_bits_PC <= 32'b00000000000000000000000000000000;
      PI_io_commit_bits_expected_PC <= 32'b00000000000000000000000000000000;
      PI_io_commit_bits_RD_1 <= 7'b0000000;
      PI_io_commit_bits_br_type <= 3'b000;
      PI_io_prediction_bits_T_NT <= 1'b0;
      PI_io_commit_bits_RD_valid_3 <= 1'b0;
      PI_io_commit_bits_T_NT <= 1'b0;
      PI_io_commit_bits_RAT_index <= 4'b0000;
      PI_io_RAS_read_NEXT <= 7'b0000000;
      PI_io_commit_bits_free_list_front_pointer <= 8'b00000000;
      PI_io_commit_bits_NEXT <= 7'b0000000;
      PI_io_commit_bits_is_misprediction <= 1'b0;
      PI_io_commit_bits_ROB_index <= 6'b000000;
      PI_io_prediction_bits_GHR <= 16'b0000000000000000;
      PI_io_commit_bits_RD_3 <= 7'b0000000;
      PI_io_commit_bits_RD_valid_0 <= 1'b0;
      PI_io_PC_next_ready <= 1'b0;
      PI_io_commit_bits_GHR <= 16'b0000000000000000;
      PI_io_commit_bits_RD_2 <= 7'b0000000;
      PI_io_RAS_read_TOS <= 7'b0000000;
      PI_io_commit_bits_RD_0 <= 7'b0000000;
      PI_io_RAS_read_ret_addr <= 32'b00000000000000000000000000000000;
      PI_io_commit_bits_TOS <= 7'b0000000;
      PI_reset <= 1'b0;
      PI_io_commit_bits_RD_valid_1 <= 1'b0;
      PI_io_prediction_bits_hit <= 1'b0;
      PI_io_commit_bits_fetch_PC <= 32'b00000000000000000000000000000000;
      PI_io_prediction_bits_br_type <= 3'b000;
    end

    genclock <= cycle < 2;
    cycle <= cycle + 1;
  end
endmodule
