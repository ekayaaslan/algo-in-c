void swap(int items[], int i, int j) {
  if(i != j) {
    int temp = items[i];
    items[i] = items[j];
    items[j] = temp;
  }
}

int knuthShuffle(int items[], int size, int randoms[]) {
  for(int i=0; i<size-1; i++) {
    int j = i + randoms[i]%(size-i);
    swap(items, i, j);
  }
  return 0;
}
