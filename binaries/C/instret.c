#include "utils/utils.c"
#include <stdint.h>


#define cycle  0xc00  // CSR for low 32 bits of the instruction retirement counter
#define cycleh 0xc80  // CSR for high 32 bits of the instruction retirement counter

#define instret  0xc02  // CSR for low 32 bits of the instruction retirement counter
#define instreth 0xc82  // CSR for high 32 bits of the instruction retirement counter


#define MEPC 0x341  

int read_instret() {
    int instret_low;

    // Read the low 32 bits of instret
    asm volatile("csrr %0, %1" : "=r"(instret_low) : "i"(instret));

    // Read the high 32 bits of instret
    //asm volatile("csrr %0, %1" : "=r"(instret_high) : "i"(instreth));

    // Combine the high and low bits into a 64-bit result
    return instret_low;
}

int read_cycle() {
    int cycle_low;

    // Read the low 32 bits of instret
    asm volatile("csrr %0, %1" : "=r"(cycle_low) : "i"(cycle));

    // Read the high 32 bits of instret
    //asm volatile("csrr %0, %1" : "=r"(instret_high) : "i"(instreth));

    // Combine the high and low bits into a 64-bit result
    return cycle_low;
}



int read_mepc() {
    int mepc;

    // Read the low 32 bits of instret
    asm volatile("csrr %0, %1" : "=r"(mepc) : "i"(MEPC));

    // Combine the high and low bits into a 64-bit result
    return mepc;
}

void write_mepc(uint32_t value) {
    asm volatile("csrw mepc, %0" :: "r" (value));
}


int main() {

    printf("Running\n");
    // Read initial instret  
    int initial_instret = read_instret();
    //int initial_cycle = read_cycle();

    // Perform a few instructions
    int a = 0;
    
    a++;  // Increment operation


    //printf("%0llu \n", a);
    //printf("%0d \n", a);

    // Read the new instret
    int new_instret = read_instret();
    //int new_cycle = read_cycle();
    write_mepc(0x123);
    int mepc = read_mepc();

    // Print the difference in instret (instructions retired)
    printf("Initial instret: %0d\n", initial_instret);
    printf("New instret: %0d\n", new_instret);
    printf("Instructions retired: %0d\n", new_instret - initial_instret);
    //printf("cycles: %0d\n", new_cycle - initial_cycle);
    printf("mepc: %0d\n", mepc);

    printf("a: %0d \n", a);

    return 0;
}
