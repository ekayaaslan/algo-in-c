int push(int item, int items[], int size[]) {
  items[size[0]] = item;
  size[0] ++;
  return 0;
}

int pop(int items[], int size[], int ret[]) {
  size[0] --;
  ret[0] = items[size[0]];
  return 0;
}

int reset(int items[], int size[]) {
  size[0] = 0;
}

int depthFirstSearchTree(int size, int xadj[], int adj[], int source, int aux[], int parent[]) {
  int *auxptr = aux;
  int *stack = auxptr; auxptr += size;
  int *visited = auxptr; auxptr += size;
  for(int vertex=0; vertex<size; vertex++) { 
    parent[vertex] = -1;
    visited[vertex] = 0;
  }
  int stackSize = 0;
  stack[stackSize ++] = source;
  visited[source] = 1;
  while(stackSize > 0) {
    int vertex = stack[-- stackSize];
    int edge = xadj[vertex];
    while(edge < xadj[vertex+1]) {
      int neighbor = adj[edge];
      if(!visited[neighbor]) {
        stack[stackSize ++] = neighbor;
        visited[neighbor] = 1;
        parent[neighbor] = vertex;
      }
      edge ++;
    }
  }
  return 0;
}
