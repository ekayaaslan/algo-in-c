int insertionSort(int items[], int size) {
  for(int i=1; i<size; i++) {
    int item = items[i];
    int isReplaced = 0;
    for(int j=i; j>0; j--) {
      if(item < items[j-1]) {
        items[j] = items[j-1];
      }else {
        items[j] = item;
        isReplaced = 1;
        break;
      }
    }
    if(!isReplaced) {
      items[0] = item;
    }
  }
  return 0;
}
