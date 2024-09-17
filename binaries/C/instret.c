#include "utils/utils.c"
#include <stdint.h>

#define instret  0xc02  // CSR for low 32 bits of the instruction retirement counter
#define instreth 0xc82  // CSR for high 32 bits of the instruction retirement counter

uint64_t read_instret() {
    uint64_t instret_low;
    uint64_t instret_high;

    // Read the low 32 bits of instret
    asm volatile("csrr %0, %1" : "=r"(instret_low) : "i"(instret));

    // Read the high 32 bits of instret
    asm volatile("csrr %0, %1" : "=r"(instret_high) : "i"(instreth));

    // Combine the high and low bits into a 64-bit result
    return (instret_high << 32) | instret_low;
}

int main() {

    printf("Running\n");
    // Read initial instret  
    uint64_t initial_instret = read_instret();

    // Perform a few instructions
    int a = 0;
    
    a++;  // Increment operation


    //printf("%0llu \n", a);
    //printf("%0d \n", a);

    // Read the new instret
    uint64_t new_instret = read_instret();

    // Print the difference in instret (instructions retired)
    printf("Initial instret: %0llu\n", initial_instret);
    printf("New instret: %0llu\n", new_instret);
    printf("Instructions retired: %0llu\n", new_instret - initial_instret);


    printf("%0d \n", a);


    return 0;
}
