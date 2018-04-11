#ifndef _GRAPH_H_
#define _GRAPH_H_

void graph_reverse_map(int n, int *xadj, int *adj, int *rxadj, int *radj, int *rmap);
void graph_reverse(int n, int *xadj, int *adj, int *rxadj, int *radj);
int graph_connected_components(int n, int* xadj, int* adj, int* component, int* aux);
int graph_connected_components_perm(int n, int* xadj, int* adj, int* perm, int* component, int* aux);
void graph_depth_first_search(int n, int* xadj, int* adj, int* parent, int* aux);
void graph_topological_order(int n, int* xadj, int* adj, int* perm, int* aux);
void graph_dfs_preorder(int n, int* xadj, int* adj, int* perm, int* aux);
void graph_dfs_postorder(int n, int* xadj, int* adj, int* perm, int* aux);

#endif
