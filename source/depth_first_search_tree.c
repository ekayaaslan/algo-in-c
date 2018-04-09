#include <stack.h>
#include <util.h>

int depth_first_search_tree(int n, int* xadj, int* adj, int s, int* parent, int* aux) {
  int* auxptr = aux;
  int* active = u_alloc(n, &auxptr);
  int* visit = u_alloc(n, &auxptr);
  for(int v=0; v<n; v++) { 
    parent[v] = -1;
    visit[v] = 0;
  }
  int asize;
  s_reset(active, &asize);
  s_push(s, active, &asize);
  visit[s] = 1;
  while(asize > 0) {
    int v = s_pop(active, &asize);
    for(int j=xadj[v]; j<xadj[v+1]; j++) {
      int w = adj[j];
      if(!visit[w]) {
        s_push(w, active, &asize);
        visit[w] = 1;
        parent[w] = v;
      }
    }
  }
  return 0;
}
