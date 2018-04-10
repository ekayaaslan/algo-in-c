int bst_insert(int item, int* items, int* _size, int* left, int* right) {
  int size = *_size;
  int p = -1;
  if(size > 0) {
    p = 0;
    while(p < size) {
      if(item < items[p]) {
        if(left[p] != -1) { p = left[p]; }
        else { left[p] = size; break; }
      }else {
        if(right[p] != -1) { p = right[p]; }
        else { right[p] = size; break; }
      }
    }
  }
  items[size] = item;
  left[size] = -1;
  right[size] = -1;
  *_size = size+1;
  return p;
}

int bst_contains(int item, int* items, int size, int* left, int* right) {
  if(size == 0) { return 0; }
  int c = 0;
  while(c != -1) {
    if(items[c] == item) { return 1; }
    c = (item < items[c])? left[c]: right[c];
  }
  return 0;
}

void bst_reset(int* items, int* _size, int* left, int* right) {
  *_size = 0;
}
