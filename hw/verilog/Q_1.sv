// Generated by CIRCT firtool-1.76.0
module Q_1(	// src/main/scala/Frontend/instruction_fetch.scala:35:7
  input         clock,	// src/main/scala/Frontend/instruction_fetch.scala:35:7
                reset,	// src/main/scala/Frontend/instruction_fetch.scala:35:7
  output        io_in_ready,	// src/main/scala/Frontend/instruction_fetch.scala:36:14
  input         io_in_valid,	// src/main/scala/Frontend/instruction_fetch.scala:36:14
  input  [31:0] io_in_bits_addr,	// src/main/scala/Frontend/instruction_fetch.scala:36:14
                io_in_bits_wr_data,	// src/main/scala/Frontend/instruction_fetch.scala:36:14
  input         io_in_bits_wr_en,	// src/main/scala/Frontend/instruction_fetch.scala:36:14
                io_out_ready,	// src/main/scala/Frontend/instruction_fetch.scala:36:14
  output        io_out_valid,	// src/main/scala/Frontend/instruction_fetch.scala:36:14
  output [31:0] io_out_bits_addr,	// src/main/scala/Frontend/instruction_fetch.scala:36:14
                io_out_bits_wr_data,	// src/main/scala/Frontend/instruction_fetch.scala:36:14
  output        io_out_bits_wr_en,	// src/main/scala/Frontend/instruction_fetch.scala:36:14
  input         io_flush	// src/main/scala/Frontend/instruction_fetch.scala:36:14
);

  Queue16_memory_request queue (	// src/main/scala/Frontend/instruction_fetch.scala:51:21
    .clock               (clock),
    .reset               (reset),
    .io_enq_ready        (io_in_ready),
    .io_enq_valid        (io_in_valid),
    .io_enq_bits_addr    (io_in_bits_addr),
    .io_enq_bits_wr_data (io_in_bits_wr_data),
    .io_enq_bits_wr_en   (io_in_bits_wr_en),
    .io_deq_ready        (io_out_ready),
    .io_deq_valid        (io_out_valid),
    .io_deq_bits_addr    (io_out_bits_addr),
    .io_deq_bits_wr_data (io_out_bits_wr_data),
    .io_deq_bits_wr_en   (io_out_bits_wr_en),
    .io_flush            (io_flush)
  );	// src/main/scala/Frontend/instruction_fetch.scala:51:21
endmodule

