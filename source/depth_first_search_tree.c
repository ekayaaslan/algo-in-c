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

int depthFirstSearchTree(int n, int *xadj, int *adj, int source, int *parent, int *aux) {
  int *auxptr = aux;
  int *active = u_alloc(size, &auxptr);
  int *visit = u_alloc(size, &auxptr);
  for(int v=0; v<n; v++) { 
    parent[v] = -1;
    visit[v] = 0;
  }
  int asize;
  s_reset(active, &asize);
  active[asize ++] = source;
  s_push(source, active, &asize);
  visit[source] = 1;
  while(asize > 0) {
    int v = s_pop(active, &asize);
    for(int j=xadj[v]; j<xadj[v+1]; j++) {
      int w = adj[j];
      if(!visited[w]) {
        s_push(w, active, &asize);
        visit[w] = 1;
        parent[w] = v;
      }
    }
  }
  return 0;
}
