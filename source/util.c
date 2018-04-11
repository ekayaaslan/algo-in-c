#include <stdlib.h>

void u_swap(int* items, int i, int j) {
  if(i != j) {
    int temp = items[i];
    items[i] = items[j];
    items[j] = temp;
  }
}

int u_min(int x, int y) {
  return (x<y)? x: y;
}

int* u_alloc(int size, int **_ptr) {
  int* ptr = *_ptr;
  *_ptr = ptr + size;
  return ptr;
}

void u_random(int seed) {
  srand(seed);
}

int u_next(int n) {
  return rand() % n;
}

void u_reverse(int* items, int size) {
  for(int i=0; i<size/2; i++) {
    u_swap(items, i, (size-1)-i);
  }
}
