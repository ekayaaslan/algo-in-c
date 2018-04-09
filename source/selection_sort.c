#include <util.h>

void selection_sort(int* items, int size) {
  for(int i=0; i<size-1; i++) {
    int min = i;
    for(int j=i+1; j<size; j++) {
      if(items[j] < items[min]) {
        min = j;
      }
    }
    u_swap(items, i, min);
  }
}
