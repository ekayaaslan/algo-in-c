int minof(int x, int y) {
  return (x<y)? x: y;
}

void swap(int items[], int i, int j) {
  if(i != j) {
    int temp = items[i];
    items[i] = items[j];
    items[j] = temp;
  }
}

int bentyleyMcIlroy3wayPartitioning(int items[], int size, int indices[], int pivot) {
  int lo = 0;
  int hi = size-1;
  int elo = lo;
  int ehi = hi;
  while(lo < hi) {
    if(items[lo] <= pivot) {
      if(items[lo] == pivot) { 
        swap(items, lo, elo ++);
      }
      lo ++;
      continue;
    }
    if(items[hi] >= pivot) {
      if(items[hi] == pivot) {
        swap(items, hi, ehi --);
      }
      hi --;
      continue;
    }
    swap(items, lo ++, hi --);
  }
  if(lo == hi) {
    int item = items[lo];
    if(item < pivot) { lo ++; }
    if(item > pivot) { hi --; }
    if(item == pivot) {
      swap(items, lo ++, elo ++);
    }
  }
  int minlo = minof(elo, lo-elo);
  for(int i=0; i<minlo; i++) {
    swap(items, i, lo-1-i);
  }
  int minhi = minof(size-ehi, ehi-hi);
  for(int i=0; i<minhi; i++) {
    swap(items, hi+1+i, size-1-i);
  }
  indices[0] = 0;
  indices[1] = lo-elo;
  indices[2] = size-(ehi-hi);
  indices[3] = size;
  return 0;
}
