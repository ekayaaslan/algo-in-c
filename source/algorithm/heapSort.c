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

int heapSort(int items[], int size) {
  for(int i=size/2-1; i>=0; i--) {
    downheap(i, items, size);
  }
  for(int i=size-1; i>0; i--) {
    int item = items[i];
    items[i] = items[0];
    items[0] = item;
    downheap(0, items, i);
  }
  return 0;
}
