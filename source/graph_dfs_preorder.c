#include <stack.h>
#include <util.h>

void graph_dfs_postorder(int n, int* xadj, int* adj, int* perm, int* aux) {
  int* auxptr = aux;
  int* active = u_alloc(n, &auxptr);
  int* visit = u_alloc(n, &auxptr);
  for(int v=0; v<n; v++) {
    visit[v] = 0;
  }
  int p = 0;
  int size;
  s_reset(active, &size);
  for(int v=0; v<n; v++) {
    if(!visit[v]) {
      s_push(v, active, &size);
      visit[v] = 1;
      while(size > 0) {
        int v = s_peek(active, size);
        if(visit[v] == 1) {
          visit[v] = 2;
          for(int j=xadj[v]; j<xadj[v+1]; j++) {
            int w = adj[j];
            if(!visit[w]) {
              s_push(w, active, &size);
              visit[w] = 1;
            }
          }
        }else {
          s_pop(active, &size);
          perm[p ++] = v;
        }
      }      
    }
  }
}
