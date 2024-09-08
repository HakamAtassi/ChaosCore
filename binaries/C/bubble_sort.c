#include "utils/utils.c"

int main()
{
    int x[] = {7,4,2,3,2,1,6,1,5,1,5,7,3,8};
    int n = 14;


    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
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
    putchar(x[5]+'0');
    putchar(x[6]+'0');
    putchar(x[7]+'0');
    putchar(x[8]+'0');
    putchar(x[9]+'0');
    putchar(x[10]+'0');
    putchar(x[11]+'0');
    putchar(x[12]+'0');
    putchar(x[13]+'0');
    putchar(x[14]+'0');

    while(1){};
}
