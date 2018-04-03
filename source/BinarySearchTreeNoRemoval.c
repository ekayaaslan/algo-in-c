int insert(int item, int items[], int size[], int left[], int right[]) {
  int cur = 0;
  while(cur < size[0]) {
    if(item < items[cur]) {
      if(left[cur] != -1) {
        cur = left[cur];
      }else {
        left[cur] = size[0];
        break;
      }
    }else {
      if(right[cur] != -1) {
        cur = right[cur];
      }else {
        right[cur] = size[0];
        break;
      }
    }
  }
  items[size[0]] = item;
  left[size[0]] = -1;
  right[size[0]] = -1;
  size[0] ++;
  return 0;
}

int build(int items[], int size, int left[], int right[]) {
  int sizeb[1];
  sizeb[0] = 0;
  for(int i=0; i<size; i++) {
    insert(items[i], items, sizeb, left, right);
  }
  return 0;
}

int find(int item, int items[], int size, int left[], int right[], int ret[]) {
  ret[0] = -1;
  if(size > 0) {
    int cur = 0;
    while(cur != -1) {
      if(items[cur] == item) {
        ret[0] = cur;
        break;
      }
      if(item < items[cur]) {
        cur = left[cur];
      }else {
        cur = right[cur];
      }
    }
  }
  return 0;
}