#include "utils/utils.c"

int main()
{
    //printf("HELLO, WORLD!");

    int x[] = {1,2,3,4,1};
    int y[] = {1,2,3,4,5};
    int z[] = {0,0,0,0,0};

    //z[0] = x[0]+y[0];
    //z[1] = x[1]+y[1];
    //z[2] = x[2]+y[2];
    //z[3] = x[3]+y[3];
    //z[4] = x[4]+y[4];

    for(int i=0;i<5;i++){
        z[i] = x[i]+y[i];
    }


    putchar(z[0]+'0');
    putchar(z[1]+'0');
    putchar(z[2]+'0');
    putchar(z[3]+'0');
    putchar(z[4]+'0');

    while(1){};
}