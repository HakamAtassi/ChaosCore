#include <cstdint>
#include <iostream>
#include <cmath>
#include <cassert>

using std::cout;

uint32_t priority_encoder(uint32_t val){
  for(int i=31;i>=0;i--){
    if((val >> i) > 0) return i;
  }
  return 0xdeafbeef;
}

// Formula: X_{i+1} = x_i*(2-R*x_i)
float newton_raphson(float dividend, float divisor){
  float initial_guesses[33] = {
    0.50000000000000000000, //0
    0.25000000000000000000, //1
    0.12500000000000000000, //2
    0.06250000000000000000, //3
    0.03125000000000000000, //4
    0.01562500000000000000, //5
    0.00781250000000000000, //6
    0.00390625000000000000, //7
    0.00195312500000000000, //8
    0.00097656250000000000, //9
    0.00048828125000000000, //10
    0.00024414062500000000, //11
    0.00012207031250000000, //12
    0.00006103515625000000, //13
    0.00003051757812500000, //14
    0.00001525878906250000, //15
    0.00000762939453125000, //16
    0.00000381469726562500, //17
    0.00000190734863281250, //18
    0.00000095367431640625, //19
    0.00000047683715820312, //20
    0.00000023841857910156, //21
    0.00000011920928955078, //22
    0.00000005960464477539, //23
    0.00000002980232238770, //24
    0.00000001490116119385, //25
    0.00000000745058059692, //26
    0.00000000372529029846, //27
    0.00000000186264514923, //28
    0.00000000093132257462, //29
    0.00000000046566128731, //30
    0.00000000023283064365, //31
    0.00000000011641532183 //32
  };
  float x_i=initial_guesses[priority_encoder(divisor)];

  for(int iteration = 0; iteration < 10; iteration++){
    x_i=x_i*(2-divisor*x_i);
  }
  return x_i*dividend;
}


float Q32_to_float(uint32_t Q31){
  return Q31 * pow(2,-32);
}

uint32_t Q1_31_Q32_multiply(uint32_t A, uint32_t B) {
    uint64_t temp = (uint64_t)A * ((uint64_t)B<<31);
    uint32_t result = (uint32_t)(temp >> 32);
    return result;
}

uint32_t fixed_point_newton_raphson(uint32_t A, uint32_t B){

  // the below guesses are indexed using the msb pos of B
  uint32_t initial_guesses[33] = {
    0xDEADBEEF, // invalid
    0x80000000, // 0.5
    0x40000000, // 0.25
    0x20000000, // 0.125
    0x10000000, // ...
    0x08000000,
    0x04000000,
    0x02000000,
    0x01000000,
    0x00800000,
    0x00400000,
    0x00200000,
    0x00100000,
    0x00080000,
    0x00040000,
    0x00020000,
    0x00010000,
    0x00008000,
    0x00004000,
    0x00002000,
    0x00001000,
    0x00000800,
    0x00000400,
    0x00000200,
    0x00000100,
    0x00000080,
    0x00000040,
    0x00000020,
    0x00000010,
    0x00000008,
    0x00000004,
    0x00000002,
    0x00000001 
  };

  uint32_t x_i=initial_guesses[priority_encoder(B)];

  uint32_t temp=0;

  for(int iteration = 0; iteration < 10; iteration++){
    temp = 0u-Q1_31_Q32_multiply(B, x_i); // multiply full int with Q.32 (pure fraction)
    temp = ((uint64_t)x_i)*((uint64_t)temp<<1)>>32;  // multiply x_i (Q.32) with temp (Q1.31)
    x_i=temp;
  }
  return x_i;
}

bool compare_floats(float A, float B, float delta){
  float got = A;
  float expected = B;
  if(std::fabs(A-B) < delta){
    return true;
  }
  printf("got %f, expected %f\n", got, expected);
  return false;
}

int main(){
  srand(0x42);
  cout<< "Running Newton-Raphson\n";

  uint32_t A=2;
  uint32_t B=1234560;

  uint32_t result = fixed_point_newton_raphson(A,B);
  float f_result = Q32_to_float(result)*A;

  printf("Result: %1.29f\n",f_result);

  printf("Result: %1.29f\n",newton_raphson(A,B));


}
