#ifndef _TREE_H_
#define _TREE_H_

void tree_child(int n, int* parent, int* child, int* next);
void tree_parent(int n, int* child, int* next, int* parent);
int tree_preorder(int n, int* child, int* next, int* perm, int* aux);
int tree_postorder(int n, int* child, int* next, int* perm, int* aux);

#endif
