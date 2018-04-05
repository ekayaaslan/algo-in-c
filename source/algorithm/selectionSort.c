void swap(int items[], int i, int j) {
  if(i != j) {
    int temp = items[i];
    items[i] = items[j];
    items[j] = temp;
  }
}

int selectionSort(int items[], int size) {
  for(int i=0; i<size-1; i++) {
    int min = i;
    for(int j=i+1; j<size; j++) {
      if(items[j] < items[min]) {
        min = j;
      }
    }
    swap(items, i, min);
  }
  return 0;
}
