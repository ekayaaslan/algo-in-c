int insert(int item, int items[], int size[]) {
  items[size[0]] = item;
  size[0] ++;
  return 0;
}

int remove(int items[], int size[], int ret[], int random) {
  int at = random%size[0];
  ret[0] = items[at];
  size[0] --;
  items[at] = items[size[0]];
  return 0;
}

int reset(int items[], int size[]) {
  size[0] = 0;
}
