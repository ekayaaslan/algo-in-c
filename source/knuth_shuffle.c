void knuth_shuffle(int *items, int size, int *randoms) {
  for(int i=0; i<size-1; i++) {
    int j = i + randoms[i] % (size-i);
    u_swap(items, i, j);
  }
}
