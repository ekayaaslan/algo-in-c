int greatest_common_divisor(int x, int y) {
  int a = x;
  int b = y;
  int t = b % a;
  while(t > 0) {
    b = a;
    a = t;
    t = b % a; 
  }
  return a;
}
