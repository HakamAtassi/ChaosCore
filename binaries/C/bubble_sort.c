#include "utils/utils.c"

int main()
{
    int x[] = {7,4,1,3,2};


    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5 - i - 1; j++) {
            if (x[j] > x[j + 1]) {           
                int temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
            }
        }
    }


    putchar(x[0]+'0');
    putchar(x[1]+'0');
    putchar(x[2]+'0');
    putchar(x[3]+'0');
    putchar(x[4]+'0');

    while(1){};
}
