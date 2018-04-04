int insert(int item, int items[], int size[]) {
  items[size[0]] = item;
  size[0] ++;
  return 0;
}

int remove(int items[], int size[], int ret[]) {
  size[0] --;
  ret[0] = items[size[0]];
  return 0;
}

int reset(int items[], int size[]) {
  size[0] = 0;
}
