int insert(int item, int items[], int size[], int root[], int left[], int right[], int parent[]) {
  if(size[0] == 0) {
    items[0] = item;
    left[0] = -1;
    right[0] = -1;
    root[0] = 0;
    parent[0] = -1;
  }else {
    int at = size[0];
    items[at] = item;
    left[at] = -1;
    right[at] = -1;
    int cur = root[0];
    while(1) {
      if(item < items[cur]) {
        if(left[cur] != -1) {
          cur = left[cur];
        }else {
          parent[at] = cur;
          left[cur] = at;
          break;
        }
      }else {
        if(right[cur] != -1) {
          cur = right[cur];
        }else {
          parent[at] = cur;
          right[cur] = at;
          break;
        }
      }
    }
  }
  size[0] ++;
  return 0;
}

int remove(int at, int items[], int size[], int root[], int left[], int right[], int parent[]) {
  int ret[1];
  int item = items[at];
  if(size[0] == 1) {
    root[0] = -1;
  }else {
    int rep;
    if(right[at] != -1) {
      int min = right[at];
      while(left[min] != -1) {
        min = left[min];
      }
      left[min] = left[at];
      if(left[at] != -1) {
        parent[left[at]] = min;
      }
      if(min != right[at]) {
        left[parent[min]] = right[min];
        if(right[min] != -1) {
          parent[right[min]] = parent[min];
        }
        right[min] = right[at];
        parent[right[at]] = min;
      }
      rep = min;
    }else {
      int max = left[at];
      while(right[max] != -1) {
        max = right[max];
      }
      right[max] = right[at];
      if(right[at] != -1) {
        parent[right[at]] = max;
      }
      if(max != left[at]) {
        right[parent[max]] = left[max];
        if(left[max] != -1) {
          parent[left[max]] = parent[max];
        }
        left[max] = left[at];
        parent[left[at]] = max;
      }
      rep = max;
    }
    if(at == root[0]) {
      root[0] = rep;
      parent[rep] = -1;
    }else {
      parent[rep] = parent[at];
      int itemp = items[parent[at]];
      if(items[rep] < itemp) {
        left[parent[at]] = rep;
      }else {
        right[parent[at]] = rep;
      }
    }
  }
  if(at < size[0]-1) {
    int s = size[0]-1;
    items[at] = items[s];
    left[at] = left[s];
    right[at] = right[s];
    parent[at] = parent[s];
    if(root[0] == s) {
      root[0] = at;
    }else {
      int itemp = items[parent[s]];
      if(items[at] < itemp) {
        left[parent[s]] = at;
      }else {
        right[parent[s]] = at;
      }
    }
  }
  size[0] --;
  return 0;
}

int find(int item, int items[], int size, int root, int left[], int right[], int ret[]) {
  ret[0] = -1;
  if(size > 0) {
    int cur = root;
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

int reset(int items[], int size[], int root[], int left[], int right[], int parent[]) {
  size[0] = 0;
  root[0] = -1;
}
