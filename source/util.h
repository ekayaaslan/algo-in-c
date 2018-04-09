#ifndef _UTIL_H_
#define _UTIL_H_

void u_swap(int *items, int i, int j);
int u_min(int x, int y);
void u_graph_reverse(int n, int *xadj, int *adj, int *wgt, int *rxadj, int *radj, int *rmap);
int* u_alloc(int size, int **_ptr);

#endif
