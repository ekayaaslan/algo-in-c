int sort(int items[], int size) {
  for(int i=1; i<size; i++) {
    int item = items[i];
    int index = i;
    while(item < items[index-1]) {
      items[index] = items[index-1];
      index --;
      if(index == 0) {
        break;
      }
    }
    items[index] = item;
  }
  return 0;
}
