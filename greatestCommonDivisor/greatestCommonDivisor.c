int greatestCommonDivisor(int number1, int number2, int ret[]) {
  int a = number1;
  int b = number2;
  int t = b % a;
  while(t > 0) {
    b = a;
    a = t;
    t = b % a; 
  }
  ret[0] = a;
  return 0;
}
