void u_swap(int* items, int i, int j) {
  if(i != j) {
    int temp = items[i];
    items[i] = items[j];
    items[j] = temp;
  }
}

int u_min(int x, int y) {
  return (x<y)? x: y;
}

int* u_alloc(int size, int **_ptr) {
  int* ptr = *_ptr;
  *_ptr = ptr + size;
  return ptr;
}
