#include <stdio.h>

int greatestCommonDivisor(int number1, int number2, int ret[]);

int main(int argc, char* argv[]) {
  int ret[1];
  greatestCommonDivisor(1,5,ret);
  printf("GCD(%d, %d) = %d\n",1,5,ret[0]);
  greatestCommonDivisor(345,2225,ret);
  printf("GCD(%d, %d) = %d\n",345,2225,ret[0]);
  return 0;
}
