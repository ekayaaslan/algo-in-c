#ifndef _TREE_H_
#define _TREE_H_

void tree_child(int n, int* parent, int* child, int* next);
void tree_parent(int n, int* child, int* next, int* parent);
void tree_preorder(int n, int* child, int* next, int* perm, int* aux);
void tree_postorder(int n, int* child, int* next, int* perm, int* aux);

#endif
