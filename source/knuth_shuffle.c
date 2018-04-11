#include <util.h>

void knuth_shuffle(int* items, int size, int seed) {
  u_random(seed);
  for(int i=0; i<size-1; i++) {
    int j = i + u_next(size-i);
    u_swap(items, i, j);
  }
}
