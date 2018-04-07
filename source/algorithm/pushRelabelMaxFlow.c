#define MIN(X,Y) ((X) < (Y)? (X): (Y))
#define MAX(X,Y) ((X) > (Y)? (X): (Y))

void moveToFront(int L[], int index, int pivot) {
  for(int i=index; i>0; i--) {
    L[i] = L[i-1];
  }
  L[0] = pivot;
}

void relabel(int vin[], int ein[], int eout[], int weight[], int flow[], int H[], int pivot, int size, int next[]) {
  int minHeight = 2 * size;
  int vertex = next[pivot];
  while(vertex != pivot) {
    int edge = (vin[vertex]==pivot)? ein[vertex]: eout[vertex];
    int w = (vin[vertex]==pivot)? weight[edge]: 0;
    int f = (vin[vertex]==pivot)? flow[edge]: -flow[edge];
    if(w > f) {
      minHeight = MIN(minHeight, H[vertex]);
    }
    vertex = next[vertex];
  }
  H[pivot] = minHeight + 1;
}

void push(int E[], int w, int f, int pivot, int flow[], int vin[], int ein[], int vout[], int eout[], int vertex) {
  int deltaf = MIN(E[pivot], w-f);
  E[vertex] += deltaf;
  if(vin[vertex] == pivot) {
    flow[ein[vertex]] += deltaf;
  }
  E[pivot] -= deltaf;
  if(vout[vertex] == pivot) {
    flow[eout[vertex]] -= deltaf;
  }
}

void computeMaxflow(int maxflow[], int outxadj[], int outadj[], int inxadj[], int inadj[], int inmap[], int flow[], int source) {
  int edge;
  maxflow[0] = 0;
  edge = outxadj[source];
  while(edge < outxadj[source+1]) {
    maxflow[0] += flow[edge];
    edge ++;
  }
  edge = inxadj[source];
  while(edge < inxadj[source+1]) {
    maxflow[0] -= flow[inmap[edge]];
    edge ++;
  }
}

void transpose(int size, int outxadj[], int outadj[], int inoutweight[], int inxadj[], int inadj[], int inmap[]) {
  for(int i=0; i<size+2; i++) { inxadj[i] = 0; }
  for(int vertex=0; vertex<size; vertex++) {
    int edge = outxadj[vertex];
    while(edge < outxadj[vertex+1]) {
      int neighbor = outadj[edge];
      inxadj[neighbor+2] ++;
      edge ++;
    }
  }
  for(int vertex=0; vertex<size; vertex++) {
    inxadj[vertex+2] += inxadj[vertex+1];
  }
  for(int vertex=0; vertex<size; vertex++) {
    int edge = outxadj[vertex];
    while(edge < outxadj[vertex+1]) {
      int neighbor = outadj[edge];
      int inEdge = inxadj[neighbor+1];
      inadj[inEdge] = vertex;
      inmap[inEdge] = edge;
      inxadj[neighbor+1] ++;
      edge ++;
    }
  }
}

/* workspace: 9n + 2m + 2 */
int pushRelabelMaxFlow(int size, int xadj[], int adj[], int weight[], int source, int terminal, int flow[], int maxflow[], int workspace[]) {
  int *outxadj = xadj;
  int *outadj = adj;
  int *outweight = weight;
  int *wsptr = workspace;
  int *inxadj = wsptr; wsptr+=size+2;
  int *inadj = wsptr; wsptr+=xadj[size];
  int *inmap = wsptr; wsptr+=xadj[size];
  int *H = wsptr; wsptr+=size;
  int *E = wsptr; wsptr+=size;
  int *next = wsptr; wsptr+=size;
  int *L = wsptr; wsptr+=size;
  int *vin = wsptr; wsptr+=size;
  int *ein = wsptr; wsptr+=size;
  int *vout = wsptr; wsptr+=size;
  int *eout = wsptr; wsptr+=size;
  int edge;
  /* initialize */
  transpose(size, outxadj, outadj, outweight, inxadj, inadj, inmap);
  for(int vertex=0; vertex<size; vertex++) { 
    flow[vertex] = 0; 
    H[vertex] = 0;
    E[vertex] = 0;
    vin[vertex] = -1;
    vout[vertex] = -1;
  }
  /* preflow */
  H[source] = size;
  edge = outxadj[source];
  while(edge < outxadj[source+1]) {
    int vertex = outadj[edge];
    int weight = outweight[edge];
    flow[edge] += weight;
    E[vertex] += weight;
    E[source] -= weight;
    edge ++;
  }
  edge = inxadj[source];
  while(edge < inxadj[source+1]) {
    int vertex = inadj[edge];
    flow[inmap[edge]] -= E[vertex];
    edge ++;
  }
  int index = 0;
  for(int vertex=0; vertex<size; vertex++) {
    if(vertex != source) {
      if(vertex != terminal) {
        L[index ++] = vertex;
      }
    }
  }
  L[index] = -1;
  /* flow */
  index = 0;
  int pivot = L[index];
  while(pivot >= 0) {
    int height = H[pivot];
    int vertex = pivot;
    /* discharge */
    edge = outxadj[pivot];
    while(edge < outxadj[pivot+1]) {
      int neighbor = outadj[edge];
      vin[neighbor] = pivot;
      ein[neighbor] = edge;
      next[vertex] = neighbor;
      vertex = neighbor;
      edge ++;
    }
    edge = inxadj[pivot];
    while(edge < inxadj[pivot+1]) {
      int neighbor = inadj[edge];
      vout[neighbor] = pivot;
      eout[neighbor] = inmap[edge];
      if(vin[neighbor] != pivot) {
        next[vertex] = neighbor;
        vertex = neighbor;
      }
      edge ++;
    }
    next[vertex] = pivot;
    vertex = next[pivot];
    while(E[pivot] > 0) {
      if(vertex == pivot) {
        relabel(vin, ein, eout, weight, flow, H, pivot, size, next);
        vertex = next[pivot];
      }else {
        int flagChange = 0;
        if(vin[vertex] == pivot || vout[vertex] == pivot) {
          int j = (vin[vertex]==pivot)? ein[vertex]: eout[vertex];
          int w = (vin[vertex]==pivot)? weight[j]: 0;
          int f = (vin[vertex]==pivot)? flow[j]: -flow[j];
          if(w > f) {
            if(H[pivot] == H[vertex]+1) {
              push(E, w, f, pivot, flow, vin, ein, vout, eout, vertex);
              flagChange = 1;
            }
          }
        }
        if(flagChange) {
          vertex = next[vertex];
        }
      }
    }
    if(H[pivot] > height) {
      moveToFront(L, index, pivot);
      index = 0;
    }
    index ++;
    pivot = L[index];
  }
  /* maxflow */
  for(int edge=0; edge<xadj[size]; edge++) {
    flow[edge] = MAX(flow[edge], 0);
  }
  computeMaxflow(maxflow, outxadj, outadj, inxadj, inadj, inmap, flow, source);
  return 0;
} 
