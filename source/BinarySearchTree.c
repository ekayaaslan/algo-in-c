void bst_insert(int item, int *item, int *_size, int *left, int *right) {
  int size = *_size;
  int c = 0;
  while(c < size) {
    if(item < items[c]) {
      if(left[c] != -1) { c = left[c]; }
      else { left[c] = size; break; }
    }else {
      if(right[c] != -1) { c = right[c]; }
      else { right[c] = size; break; }
    }
  }
  items[size] = item;
  left[size] = -1;
  right[size] = -1;
  *_size = size+1;
}

int bst_contains(int item, int *item, int size, int *left, int *right) {
  if(size == 0) { return 0; }
  int c = 0;
  while(c != -1) {
    if(items[c] == item) { return 1; }
    c = (item < items[c])? left[c]: right[c];
  }
  return 0;
}
