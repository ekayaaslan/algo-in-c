#include <stack.h>
#include <util.h>

void depth_first_search_tree(int n, int* xadj, int* adj, int* child, int *next, int* aux) {
  int* auxptr = aux;
  int* active = u_alloc(n, &auxptr);
  int* visit = u_alloc(n, &auxptr);
  for(int v=0; v<n; v++) { 
    child[v] = -1;
    next[v] = -1;
    visit[v] = 0;
  }
  int size;
  s_reset(active, &size);
  for(int i=0; i<n; i++) {
    int v = order[i];
    if(!visit[v]) {
      s_push(v, active, &size);
      visit[v] = 1;
      while(size > 0) {
        int v = s_pop(active, &size);
        for(int j=xadj[v]; j<xadj[v+1]; j++) {
          int w = adj[j];
          if(!visit[w]) {
            s_push(w, active, &size);
            visit[w] = 1;
            next[w] = child[v];
            child[v] = w;
          }
        }
      }      
    }
  }
}
