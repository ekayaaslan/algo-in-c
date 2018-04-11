#ifndef _UTIL_H_
#define _UTIL_H_

void u_swap(int *items, int i, int j);
int u_min(int x, int y);
int* u_alloc(int size, int **_ptr);
void u_random(int seed);
int u_next(int n);
void u_reverse(int* items, int size);

#endif
