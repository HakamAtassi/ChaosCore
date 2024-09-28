#include "utils/utils.c"
#include "utils/CSR.h"
#include <stdint.h>



int main() {

    printf("Running\n");
//    // Read initial instret  
    //int initial_instret = read_instret();
    ////int initial_cycle = read_cycle();

    //// Perform a few instructions
    //int a = 0;
    
    //a++;  // Increment operation


    ////printf("%0llu \n", a);
    ////printf("%0d \n", a);

    //// Read the new instret
    //int new_instret = read_instret();
    ////int new_cycle = read_cycle();
    //write_mepc(0x123);
    //int mepc = read_mepc();

    //// Print the difference in instret (instructions retired)
    //printf("Initial instret: %0d\n", initial_instret);
    //printf("New instret: %0d\n", new_instret);
    //printf("Instructions retired: %0d\n", new_instret - initial_instret);
    ////printf("cycles: %0d\n", new_cycle - initial_cycle);
    //printf("mepc: %0d\n", mepc);

    //printf("a: %0d \n", a);


    int _mtvec = read_csr(mtvec);
    printf("%0x\n", _mtvec);

    asm volatile("ecall");

    return 0;
}
