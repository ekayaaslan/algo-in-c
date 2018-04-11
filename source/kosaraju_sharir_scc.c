#include <util.h>
#include <graph.h>
#include <stack.h>
#include <graph_connected_components.h>

int get_reverse_postorder(int n, int* xadj, int* adj, int* perm, int* aux) {
  int* auxptr = aux;
  int* active = u_alloc(n, &auxptr);
  int* visit = u_alloc(n, &auxptr);
  for(int v=0; v<n; v++) { 
    visit[v] = 0;
  }
  int p = n;
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
          perm[-- p] = v;
        }
      }      
    }
  }
  return n-p;
}

/* aux: 4n+nnz+2 */
int kosraju_sharir_scc(int n, int* xadj, int* adj, int* component, int* aux) {
  int nnz = xadj[n];
  int* auxptr = aux;
  int* rxadj = u_alloc(n+2, &auxptr);
  int* radj = u_alloc(nnz, &auxptr);
  int* perm = u_alloc(n, &auxptr);
  graph_reverse(n, xadj, adj, rxadj, radj);
  get_reverse_postorder(n, rxadj, radj, perm, auxptr);
  return graph_connected_components_perm(n, xadj, adj, perm, component, auxptr);
}
