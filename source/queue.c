void enqueue(int item, int *items, int *_tail, int cap) {
  int tail = *_tail;
  items[tail] = item;
  *_tail = (tail+1) % cap;
}

int dequeue(int *items, int *_head, int cap) {
  int head = *_head;
  int item = items[head];
  *_head = (head+1) % cap;
  return item;
}

void reset(int *items, int *_head, int *_tail) {
  *_head = 0;
  *_tail = 0;
}
