#ifndef _DEPTH_FIRST_SEARCH_H_
#define _DEPTH_FIRST_SEARCH_H_

void depth_first_search_tree(int n, int* xadj, int* adj, int* child, int *next, int* aux);
void depth_first_search_treep(int n, int* xadj, int* adj, int* parent, int* aux);
void depth_first_search_treep_perm(int n, int* xadj, int* adj, int* perm, int* parent, int* aux);

#endif
