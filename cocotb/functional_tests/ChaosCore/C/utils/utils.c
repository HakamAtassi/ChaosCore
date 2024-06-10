
void printf(int ASCII)
{
    // This function prints to the memory mapped UART address
    volatile unsigned int* ptr = (volatile unsigned int*)0x8000000;
    *ptr = ASCII;
}