#include <util.h>
#include <graph.h>
#include <stack.h>

/* aux: 4n+nnz+2 */
int kosraju_sharir_scc(int n, int* xadj, int* adj, int* part, int* aux) {
  int nnz = xadj[n];
  int* auxptr = aux;
  int* rxadj = u_alloc(n+2, &auxptr);
  int* radj = u_alloc(nnz, &auxptr);
  int* perm = u_alloc(n, &auxptr);
  graph_reverse(n, xadj, adj, rxadj, radj);
  graph_topological_order(n, rxadj, radj, perm, aux);
  return graph_connected_components_perm(n, xadj, adj, perm, part, auxptr);
}
