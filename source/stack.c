void s_push(int item, int *items, int *_size) {
  int size = *_size;
  items[size] = item;
  *_size = size+1;
}

int s_pop(int *items, int *_size) {
  int size = *_size;
  int item = items[size-1];
  *_size = size-1;
  return item;
}

void s_reset(int *items, int *_size) {
  *_size = 0;
} 
