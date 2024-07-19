
void putchar(int ASCII)
{
    volatile unsigned int* ptr = (unsigned int*)0x80000000;
    *ptr = ASCII;
}

void printf(const char* str)
{
    while(*str){
        putchar(*str);
        str++;
    }
}