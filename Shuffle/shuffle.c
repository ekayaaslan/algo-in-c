void shuffle(int items[], int size, int randoms[]) {
  for(int i=0; i<size-1; i++) {
    int item = items[i];
    int j = i + randoms[i]%(size-i);
    items[i] = items[j];
    items[j] = item;
  }
}
