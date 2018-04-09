void pq_upheap(int at, int* items) {
  int item = items[at];
  int cur = at;
  while(cur > 0) {
    int next = cur/2;
    if(items[next] >= item) {
      break;
    }
    items[cur] = items[next];
    cur = next;
  }
  items[cur] = item;
}

void pq_downheap(int at, int* items, int size) {
  int item = items[at];
  int cur = at;
  while(cur < size/2) {
    int next = 2*cur+1;
    if(next+1 < size) {
      if(items[next+1] > items[next]) {
        next = next+1;
      }
    }
    if(items[next] <= item) {
      break;
    }
    items[cur] = items[next];
    cur = next;
  }
  items[cur] = item;
}

void pq_insert(int item, int* items, int* _size) {
  int size = *_size;
  items[size] = item;
  pq_upheap(size, items);
  *_size = size+1;
}

int pq_remove(int* items, int* _size) {
  int item = items[0];
  int size = *_size;
  if(size > 1) {
    items[0] = items[size-1];
    pq_downheap(0, items, size);
  }
  *_size = size-1;
  return item;
}

void pq_build(int* items, int size) {
  for(int i=size/2-1; i>=0; i--) {
    pq_downheap(i, items, size);
  }
}

void pq_update_at(int at, int item, int* items, int size) {
  if(item < items[at]) {
    items[at] = item;
    pq_downheap(at, items, size);
  }else {
    items[at] = item;
    pq_upheap(at, items);
  }
}

void pq_remove_at(int at, int* items, int* _size) {
  int size = *_size;
  if(at < size-1) {
    int item = items[size-1];
    pq_update_at(at, item, items, size-1);
  }
  *_size = size-1;
}

void pq_reset(int* items, int* _size) {
  *_size = 0;
}

