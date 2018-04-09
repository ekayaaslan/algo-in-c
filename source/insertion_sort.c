#include <util.h>

void insertion_sort(int* items, int size) {
  for(int i=1; i<size; i++) {
    int pivot = items[i];
    for(int j=i; j>0; j--) {
      if(items[j-1] <= pivot) { break; }
      items[j] = items[j-1];
    }
    items[i] = pivot;
  }
}
