#include <stack.h>
#include <util.h>
#include <tree.h>
#include <depth_first_search.h>

int graph_connected_components(int n, int* xadj, int* adj, int* component, int* aux) {
  int* auxptr = aux;
  int* parent = u_alloc(n, &auxptr);
  depth_first_search_treep(n, xadj, adj, parent, auxptr);
  return tree_components(n, parent, component, auxptr);
}
