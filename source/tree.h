#ifndef _TREE_H_
#define _TREE_H_

int tree_components(int n, int* parent, int* component, int* aux);
int tree_preorder_prev(int n, int* child, int* prev, int* perm, int* aux);

#endif
