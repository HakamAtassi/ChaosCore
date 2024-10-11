#include "Vtop.h"
#include "Vtop___024root.h"
#include "Vtop_axi_ram.h"
#include "Vtop_top.h"
#include "verilated.h"
#include "verilated_vcd_c.h" // Include for tracing

// #define WAVES

// Global simulation time variable
vluint64_t main_time =
    0; // Verilated time variable (64-bit for large simulations)

// Increment time function for Verilator
double sc_time_stamp() { return main_time; }

int main(int argc, char **argv) {
  // Initialize Verilated model
  Verilated::commandArgs(argc, argv);

#ifdef WAVES
  Verilated::traceEverOn(true); // Enable tracing
#endif
  Vtop *top = new Vtop;

// Set up VCD tracing
#ifdef WAVES
  VerilatedVcdC *tfp = new VerilatedVcdC;
  top->trace(tfp, 99);       // Trace 99 levels of hierarchy
  tfp->open("waveform.vcd"); // Open the dump file
#endif

  // Initialize simulation inputs
  top->clock = 0;
  top->reset = 1;
  top->clock = !top->clock;
  top->eval();
  main_time += 1;
  top->clock = !top->clock;
  top->eval();
  main_time += 1;
  top->clock = !top->clock;
  top->eval();
  main_time += 1;
  top->clock = !top->clock;
  top->eval();
  main_time += 1;
  top->reset = 0;

if (argc < 2) {
    printf("Usage: %s <binary_file>\n", argv[0]);
    return -1;
}

    const char* bin = argv[1];


  // Open the binary memory file in "rb" mode (read binary)
  FILE *mem_file = fopen(bin, "rb");
  if (mem_file == NULL) {
    printf("Failed to open memory file\n");
    return -1;
  }



  // Read the binary file and initialize the memory array
  unsigned int data;
  int addr = 0;
  while (fread(&data, sizeof(data), 1, mem_file) == 1) {
    top->rootp->top->axi_ram_inst->mem[addr++] = data;
  }
  fclose(mem_file);

  printf("Memory initialized from raw binary file: hello_world.bin\n");

  printf("Memory initialized from file binaries/hex/hello_world.hex\n");

  long long max = 0;

  // Simulation loop
  while (!Verilated::gotFinish()) {
    // Toggle clock
    top->clock = !top->clock;

    // Evaluate model
    top->eval();

// Dump signals into VCD trace
#ifdef WAVES
    tfp->dump(main_time);
#endif

    // Increment simulation time
    main_time += 1; // Advance time by 1 unit (or a chosen time step)

    // Add your simulation code here

    // Exit condition (define your own)
    if (max > 1000000) {
      break;
    }
    max++;
  }

  // Finalize simulation
  top->final();
#if WAVES
  tfp->close(); // Close the VCD file
  delete tfp;
#endif
  delete top;
  return 0;
}
