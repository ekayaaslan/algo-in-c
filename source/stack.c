void s_push(int item, int* items, int* _size) {
  int size = *_size;
  items[size] = item;
  *_size = size+1;
}

int s_pop(int* items, int* _size) {
  int size = *_size;
  int item = items[size-1];
  *_size = size-1;
  return item;
}

int s_peek(int* items, int size) {
  return items[size-1];
}

void s_reset(int* items, int* _size) {
  *_size = 0;
} 

void rs_push(int item, int* items, int cap, int* _size) {
  int size = *_size;
  items[(cap-1)-size] = item;
  *_size = size+1;
}

int rs_pop(int* items, int cap, int* _size) {
  int size = *_size;
  int item = items[cap-size];
  *_size = size-1;
  return item;
}

void rs_reset(int* items, int cap, int* _size) {
  *_size = 0;
}
