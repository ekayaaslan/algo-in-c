int enqueue(int item, int items[], int capacity, int tail[]) {
  items[tail[0]] = item;
  tail[0] = (tail[0]+1)%capacity;
  return 0;
}

int remove(int items[], int capacity, int head[], int ret[]) {
  ret[0] = items[head[0]];
  head[0] = (head[0]+1)%capacity;
  return 0;
}

int reset(int items[], int head[], int tail[]) {
  head[0] = 0;
  tail[0] = 0;
}
