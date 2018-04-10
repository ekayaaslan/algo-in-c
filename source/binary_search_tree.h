#ifndef _BINARY_SEARCH_TREE_H_
#define _BINARY_SEARCH_TREE_H_

int bst_insert(int item, int* items, int* _size, int* left, int* right);
int bst_contains(int item, int* items, int size, int* left, int* right);
void bst_reset(int* items, int* _size, int* left, int* right);

#endif
