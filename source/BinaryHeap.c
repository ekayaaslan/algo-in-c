void upheap(int at, int items[]) {
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

void downheap(int at, int items[], int size) {
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

int insert(int item, int items[], int size[]) {
  items[size[0]] = item;
  size[0] ++;
  upheap(size[0]-1, items);
  return 0;
}

int remove(int items[], int size[], int ret[]) {
  ret[0] = items[0];
  if(size[0] > 1) {
    items[0] = items[size[0]-1];
    size[0] --;
    downheap(0, items, size[0]);
  }else {
    size[0] = 0;
  }
  return 0;
}

int build(int items[], int size) {
  for(int i=size/2-1; i>=0; i--) {
    downheap(i, items, size);
  }
  return 0;
}

int updateAt(int at, int item, int items[], int size) {
  if(item < items[at]) {
    items[at] = item;
    downheap(at, items, size);
  }else {
    items[at] = item;
    upheap(at, items);
  }
  return 0;
}

int removeAt(int at, int items[], int size[]) {
  if(at < size[0]-1) {
    int item = items[size[0]-1];
    size[0] --;
    updateAt(at, item, items, size[0]);
  }else {
    size[0] --;
  }
  return 0;
}