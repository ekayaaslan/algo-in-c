#ifndef _GRAPH_CONNECTED_COMPONENTS_H_
#define _GRAPH_CONNECTED_COMPONENTS_H_

int graph_connected_components(int n, int* xadj, int* adj, int* component, int* aux);
int graph_connected_components_perm(int n, int* xadj, int* adj, int* perm, int* component, int* aux);

#endif
