void moveToFront(int *L, int *_lptr, int u) {
  int lptr = *_lptr;
  for(int i=lptr; i>0; i--) {
    L[i] = L[i-1];
  }
  L[0] = u;
  *_lptr = 0;
}

void relabel(int *iv, int *ie, int *oe, int *wgt, int *flow, int *H, int u, int n, int *next) {
  int min_heigth = 2 * n;
  int v = next[u];
  while(v != u) {
    if(ie[v] == u) {
      int j = ie[v];
      if(wgt[j] > flow[j]) {
        min_height = u_min(min_height, H[v]);
      }
    }else {
      int j = oe[v];
      if(flow[j] > 0) {
        min_height = u_min(min_height, H[v]);
      }
    }
    v = next[v];
  }
  H[u] = min_height + 1;
}

void push(int *E, int df, int u, int *flow, int *iv, int *ie, int *ov, int *oe, int v) {
  E[v] += df;
  if(iv[v] == u) {
    int j = ie[v];
    flow[j] += df;
  }
  E[u] -= df;
  if(ov[v] == u) {
    int j = oe[v];
    flow[j] -= df;
  }
}

int computeMaxflow(int *oxadj, int *oadj, int *ixadj, int *iadj, int *imap, int *flow, int s) {
  int maxflow = 0;
  for(int j=oxadj[s]; j<oxadj[s+1]; j++) {
    maxflow += flow[j];
  }
  for(int rj=ixadj[s]; rj<ixadj[s+1]; rj++) {
    int j = imap[rj];
    maxflow -= flow[j];
  }
  return maxflow;
}

/* workspace: 9n + 2nnz + 2 */
int pushRelabelMaxFlow(int n, int *xadj, int *adj, int *wgt[], int s, int t, int *flow, int *aux) {
  int *oxadj = xadj;
  int *oadj = adj;
  int *owgt = wgt;
  int *auxptr;
  int nnz = xadj[n];
  int *ixadj = u_alloc(n+2, &auxptr);
  int *iadj = u_alloc(nnz, &auxptr);
  int *imap = u_alloc(nnz, &auxptr); 
  int *H = u_alloc(n, &auxptr);
  int *E = u_alloc(n, &auxptr);
  int *next = u_alloc(n, &auxptr);
  int *L = u_alloc(n, &auxptr);
  int *iv = u_alloc(n, &auxptr);
  int *ie = u_alloc(n, &auxptr);
  int *ov = u_alloc(n, &auxptr);
  int *oe = u_alloc(n, &auxptr);
  /* initialize */
  u_graph_reverse(n, xadj, adj, wgt, ixadj, iadj, imap);
  for(int v=0; v<n; v++) { 
    flow[v] = 0; 
    H[v] = 0;
    E[v] = 0;
    iv[v] = -1;
    ov[v] = -1;
  }
  /* preflow */
  H[s] = n;
  for(int j=oxadj[s]; j<oxadj[s+1]; j++) {
    int w = oadj[j];
    flow[j] += wgt[j];
    E[w] += wgt[j];
    E[s] -= wgt[j];
  }
  for(int rj=ixadj[s]; rj<ixadj[s+1]; rj++) {
    int w = iadj[j];
    int j = imap[rj];
    flow[j] -= E[w];
  }
  int lptr = 0;
  for(int v=0; v<n; v++) {
    if(v != s && v != t) {
        L[lptr ++] = v;
    }
  }
  L[lptr] = -1;
  /* flow */
  lptr = 0;
  int u = L[lptr];
  while(u >= 0) {
    int height = H[u];
    int v = u;
    /* discharge */
    for(int j=oxadj[u]; j<oxadj[u+1]; j++) {
      int w = oadj[j];
      iv[w] = u;
      ie[w] = j;
      next[v] = w;
      v = w;
    }
    for(int rj=ixadj[u]; rj<ixadj[u+1]; rj++) {
      int w = iadj[rj];
      int j = imap[rj];
      ov[w] = u;
      oe[w] = j;
      if(iv[w] != u) {
        next[v] = w;
        v = w;
      }
    }
    next[v] = u;
    v = next[u];
    while(E[u] > 0) {
      if(v == u) {
        relabel(iv, ie, oe, wgt, flow, H, u, n, next);
        v = next[u];
      }else {
        if(H[u] == H[v]+1) {
          if(ie[v] == u) {
            int j = ie[v];
            if(wgt[j] > flow[j]) {
              int df = u_min(E[u], wgt[j]-flow[j]);
              push(E, df, u, flow, iv, ie, ov, oe, v);
              v = next[v];
            }
            continue;
          }
          if(oe[v] == u) {
            int j = oe[v];
            if(flow[j] > 0) {
              int df = u_min(E[u], flow[j]);
              push(E, df, u, flow, iv, ie, ov, oe, v);
            }
            continue;
          }
        }
      }
    }
    if(H[u] > height) {
      moveToFront(L, &lptr, u);
    }
    lptr ++;
    u = L[lptr];
  }
  /* maxflow */
  for(int j=0; j<nnz; j++) {
    if(flow[j] < 0) { flow[j] = 0; }
  }
  return computeMaxflow(oxadj, oadj, ixadj, iadj, imap, flow, s);
} 
