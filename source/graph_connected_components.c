#include <stack.h>
#include <util.h>

int graph_connected_components(int n, int* xadj, int* adj, int* component, int* aux) {
  int* auxptr = aux;
  int* active = u_alloc(n, &auxptr);
  for(int v=0; v<n; v++) {
    component[v] = -1;
  }
  int size;
  int nc = 0;
  s_reset(active, &size);
  for(int v=0; v<n; v++) {
    if(component[v] < 0) {
      s_push(v, active, &size);
      component[v] = nc;
      while(size > 0) {
        int v = s_pop(active, &size);
        for(int j=xadj[v]; j<xadj[v+1]; j++) {
          int w = adj[j];
          if(component[w] < 0) {
            s_push(w, active, &size);
            component[w] = nc;
          }
        }
      }
      nc ++;      
    }
  }
  return nc;
}

int graph_connected_components_perm(int n, int* xadj, int* adj, int* perm, int* component, int* aux) {
  int* auxptr = aux;
  int* active = u_alloc(n, &auxptr);
  for(int v=0; v<n; v++) {
    component[v] = -1;
  }
  int size;
  int nc = 0;
  s_reset(active, &size);
  for(int i=0; i<n; i++) {
    int v = perm[i];
    if(component[v] < 0) {
      s_push(v, active, &size);
      component[v] = nc;
      while(size > 0) {
        int v = s_pop(active, &size);
        for(int j=xadj[v]; j<xadj[v+1]; j++) {
          int w = adj[j];
          if(component[w] < 0) {
            s_push(w, active, &size);
            component[w] = nc;
          }
        }
      }
      nc ++;      
    }
  }
  return nc;
}
