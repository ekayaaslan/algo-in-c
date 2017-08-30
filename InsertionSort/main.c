#include<stdio.h>

int insertionSort(int items[], int size);

int main(int argc, char* argv[]) {
  FILE *f = fopen("input","r");
  int size;
  fscanf(f, "%d", &size);
  int items[100];
  for(int i=0; i<size; i++) {
    fscanf(f, "%d", &items[i]);
  }
  sort(items, size);
  for(int i=0; i<size; i++) {
    printf("%d ", items[i]);
  }
  printf("\n");
  return 0;
}
