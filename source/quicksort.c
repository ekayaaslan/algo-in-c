#include <stack.h>
#include <shuffle.h>
#include <partition.h>

void quicksort_rec(int* items, int lo, int hi) {
  int indices[4];
  if(lo >= hi) { return; }
  int pivot = items[lo];
  bentley_mcilroy_3way_partition(items+lo, hi-lo+1, pivot, indices);
  int midlo = indices[1]-1;
  int midhi = indices[2];
  if(midlo-lo < hi-midhi) {
    quicksort_rec(items, lo, midlo);
    quicksort_rec(items, midhi, hi);
  }else {
    quicksort_rec(items, midhi, hi);
    quicksort_rec(items, lo, midlo);
  }
}

void quicksort(int* items, int size, int seed) {
  knuth_shuffle(items, size, seed);
  quicksort_rec(items, 0, size-1);
}
