#include "utils/utils.c"

int main()
{
    //printf("HELLO, WORLD!");

    asm volatile("ecall");

    printf("done handling ecall\n");

    while(1){};
}