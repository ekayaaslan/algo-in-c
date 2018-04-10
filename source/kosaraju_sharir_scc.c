#include <util.h>
#include <graph.h>
#include <depth_first_search.h>
#include <tree.h>

void get_reverse_postorder(int n, int* xadj, int* adj, int* perm, int* aux) {
  int* auxptr = aux;
  int* child = u_alloc(n, &auxptr);
  int* next = u_alloc(n, &auxptr);
  depth_first_search_tree(n, xadj, adj, child, next, auxptr);
  tree_preorder_prev(n, child, next, perm, auxptr);
}

int kosraju_sharir_scc(int n, int* xadj, int* adj, int* component, int* aux) {
  int nnz = xadj[n];
  int* auxptr = aux;
  int* rxadj = u_alloc(n+2, &auxptr);
  int* radj = u_alloc(nnz, &auxptr);
  int* perm = u_alloc(n, &auxptr);
  int* parent = u_alloc(n, &auxptr);
  graph_reverse(n, xadj, adj, rxadj, radj, auxptr);
  get_reverse_postorder(n, rxadj, radj, perm, auxptr);
  depth_first_search_treep_perm(n, xadj, adj, perm, parent, auxptr);
  return tree_components(n, parent, component, auxptr);
}
