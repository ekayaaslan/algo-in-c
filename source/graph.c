void graph_reverse(int n, int* xadj, int* adj, int* rxadj, int* radj) {
  for(int i=0; i<n+2; i++) { rxadj[i] = 0; }
  for(int v=0,j=0; v<n; v++) {
    for(; j<xadj[v+1]; j++) {
      int w = adj[j];
      rxadj[w+2] ++;
    }
  }
  for(int v=0; v<n; v++) {
    rxadj[v+2] += rxadj[v+1];
  }
  for(int v=0,j=0; v<n; v++) {
    for(; j<xadj[v+1]; j++) {
      int w = adj[j];
      int rj = rxadj[w+1];
      radj[rj] = v;
      rxadj[w+1] ++;
    }
  }
}

void graph_reverse_map(int n, int* xadj, int* adj, int* rxadj, int* radj, int* rmap) {
  for(int i=0; i<n+2; i++) { rxadj[i] = 0; }
  for(int v=0,j=0; v<n; v++) {
    for(; j<xadj[v+1]; j++) {
      int w = adj[j];
      rxadj[w+2] ++;
    }
  }
  for(int v=0; v<n; v++) {
    rxadj[v+2] += rxadj[v+1];
  }
  for(int v=0,j=0; v<n; v++) {
    for(; j<xadj[v+1]; j++) {
      int w = adj[j];
      int rj = rxadj[w+1];
      radj[rj] = v;
      rmap[rj] = j;
      rxadj[w+1] ++;
    }
  }
}
