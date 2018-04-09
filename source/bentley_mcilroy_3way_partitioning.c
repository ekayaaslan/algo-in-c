void bentley_mcilroy_3way_partitioning(int *items, int size, int pivot, int *indices) {
  int lo = 0;
  int hi = size-1;
  int elo = lo;
  int ehi = hi;
  while(lo < hi) {
    if(items[lo] <= pivot) {
      if(items[lo] == pivot) { 
        u_swap(items, lo, elo ++);
      }
      lo ++;
      continue;
    }
    if(items[hi] >= pivot) {
      if(items[hi] == pivot) {
        u_swap(items, hi, ehi --);
      }
      hi --;
      continue;
    }
    u_swap(items, lo ++, hi --);
  }
  if(lo == hi) {
    int item = items[lo];
    if(item < pivot) { lo ++; }
    if(item > pivot) { hi --; }
    if(item == pivot) {
      u_swap(items, lo ++, elo ++);
    }
  }
  int minlo = u_min(elo, lo-elo);
  for(int i=0; i<minlo; i++) {
    u_swap(items, i, lo-1-i);
  }
  int minhi = u_min(size-ehi, ehi-hi);
  for(int i=0; i<minhi; i++) {
    u_swap(items, hi+1+i, size-1-i);
  }
  indices[0] = 0;
  indices[1] = lo-elo;
  indices[2] = size-(ehi-hi);
  indices[3] = size;
}
