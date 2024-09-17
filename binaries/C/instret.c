#include "utils/utils.c"
#include <stdint.h>

#define instret  0xc02  // CSR for low 32 bits of the instruction retirement counter
#define instreth 0xc82  // CSR for high 32 bits of the instruction retirement counter

int read_instret() {
    int instret_low;

    // Read the low 32 bits of instret
    asm volatile("csrr %0, %1" : "=r"(instret_low) : "i"(instret));

    // Read the high 32 bits of instret
    //asm volatile("csrr %0, %1" : "=r"(instret_high) : "i"(instreth));

    // Combine the high and low bits into a 64-bit result
    return instret_low;
}

int main() {

    printf("Running\n");
    // Read initial instret  
    int initial_instret = read_instret();

    // Perform a few instructions
    int a = 0;
    
    a++;  // Increment operation


    //printf("%0llu \n", a);
    //printf("%0d \n", a);

    // Read the new instret
    int new_instret = read_instret();

    // Print the difference in instret (instructions retired)
    printf("Initial instret: %0d\n", initial_instret);
    printf("New instret: %0d\n", new_instret);
    printf("Instructions retired: %0d\n", new_instret - initial_instret);


    printf("%0d \n", a);


    return 0;
}
