#include "../utils/utils.c"
#include "../utils/test_utils.c"
//#include "dataset1.h"

int main()
{


    #define DATA_SIZE 5
    #define type int

    type input_data[DATA_SIZE] = {5,7,3,2,5};


    for (int i = 0; i < DATA_SIZE; i++) {
        for (int j = 0; j < DATA_SIZE - i - 1; j++) {
            if (input_data[j] > input_data[j + 1]) {           
                int temp = input_data[j];
                input_data[j] = input_data[j + 1];
                input_data[j + 1] = temp;
            }
        }
    }

    // Add verification stage
    //return verify( DATA_SIZE, input_data, verify_data );

    putchar('0'+input_data[0]);
    putchar('0'+input_data[1]);
    putchar('0'+input_data[2]);
    putchar('0'+input_data[3]);
    putchar('0'+input_data[4]);

    return 0;
}