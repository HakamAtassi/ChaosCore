#include "utils/utils.c"
#include "utils/CSR.h"

int main()
{
    asm volatile("li sp, 0x82000000");

    while(1){};

}