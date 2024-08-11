#include "obj_dir/Vtop_v2.h"
#include "verilated_vcd_c.h"

// #include "obj_dir/verilated.h"
// #include "obj_dir/verilated_vcd_c.h" // Header file for VCD tracing

// #define DUMP

int main(int argc, char **argv) {
  Verilated::commandArgs(argc, argv);
  Verilated::traceEverOn(true);
  Vtop_v2 *top = new Vtop_v2;
  VerilatedVcdC *tfp = new VerilatedVcdC;

  top->trace(tfp, 99);
  tfp->open("dump.vcd");

  top->reset = 1;
  top->clock = 0;

  int k = 0;

  while (k < 10) {
    top->clock = !top->clock;
    top->eval();
    tfp->dump(k);
    k++;
    top->clock = !top->clock;
    top->eval();
    tfp->dump(k);
    k++;
  }

  top->reset = 0;

  // For simplicity, we will simulate a fixed number of cycles. In a more
  // robust system, you'd want to adapt the while loop conditions from the
  // Verilog initial block.

  while (k < 1000) {
    // Clock toggling logic
    top->clock = !top->clock;
    top->eval();
    tfp->dump(k);
    k++;

    top->clock = !top->clock;
    top->eval();
    tfp->dump(k);
    k++;
  }

  tfp->close();
  delete top;
  delete tfp;
  return 0;
}