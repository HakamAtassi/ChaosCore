// See LICENSE for license details.

#include "dataset.h"
#include <stddef.h>

#include "../utils/utils.c"
#include "../utils/test_utils.c"

#pragma GCC optimize ("unroll-loops")

void matmul(const size_t lda,  const data_t A[], const data_t B[], data_t C[])
{
  size_t i, j, k;
 
    for(i=0;i<DIM_SIZE;i++){
        for(j=0;j<DIM_SIZE;j++){
            for(k=0;k<DIM_SIZE;k++){
                C[i*DIM_SIZE + j] = A[i*DIM_SIZE + k] * B[k*DIM_SIZE + j];
            }
        }
    }

}

  
int main( int argc, char* argv[] )
{
   static data_t results_data[ARRAY_SIZE];

   matmul(DIM_SIZE, input1_data, input2_data, results_data);
 
   int correct = verify(ARRAY_SIZE, results_data, verify_data);

    printf("correct : %0d\n", correct);
}
