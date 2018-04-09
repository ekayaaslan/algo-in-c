#include <priority_queue.h>
#include <util.h>

void heap_sort(int* items, int size) {
  pq_build(items, size);
  for(int i=size-1; i>0; i--) {
    u_swap(items, i, 0);
    pq_downheap(0, items, i);
  }
}
