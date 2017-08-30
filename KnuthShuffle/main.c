#include <stdio.h>
#include <stdlib.h>

void shuffle(int items[], int size, int randoms[]);

int main(int argc, char* argv[]) {
  FILE *f = fopen("input","r");
  int size;
  fscanf(f, "%d", &size);
  int items[100];
  for(int i=0; i<size; i++) {
    fscanf(f, "%d", &items[i]);
  }
  int seed;
  fscanf(f, "%d", &seed);
  int randoms[100];
  srand(seed);
  for(int i=0; i<size-1; i++) {
    randoms[i] = rand();
  }
  shuffle(items, size, randoms);
  for(int i=0; i<size; i++) {
    printf("%d ", items[i]);
  }
  printf("\n");
  return 0;
}
