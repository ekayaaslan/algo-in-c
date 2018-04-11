#include <util.h>
#include <graph.h>

void graph_topological_order(int n, int* xadj, int* adj, int* perm, int* aux) {
  graph_dfs_postorder(n, xadj, adj, perm, aux);
  u_reverse(perm, n);
}
