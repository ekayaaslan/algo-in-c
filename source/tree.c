#include <stack.h>
#include <util.h>

void tree_sibling(int n, int* parent, int* child, int* next) {
  for(int v=0; v<n; v++) { 
    child[v] = -1;
    next[v] = -1;
  }
  for(int v=0; v<n; v++) {
    if(parent[v] >= 0) {
      int p = parent[v];
      next[v] = child[p];
      child[p] = v;
    }
  }
}

void tree_preorder(int n, int* child, int* next, int root, int* perm, int* aux) {
  int* auxptr = aux;
  int* child = u_alloc(n, &auxptr);
  int* next = u_alloc(n, &auxptr);
  int* active = u_alloc(n, &auxptr);
  int size, rsize;
  s_reset(active, &size);
  rs_reset(active, n, &rsize);
  s_push(root, active, &size);
  int p = 0;
  while(size > 0) {
    int v = s_pop(active, &size);
    perm[p ++] = v;
    for(int w=child[v]; w >= 0; w=next[w]) {
      rs_push(w, active, n, &rsize);
    }
    while(rsize > 0) {
      int w = rs_pop(active, n, &rsize);
      s_push(w, active, &size);
    }
  }
}

void tree_postorder(int n, int* child, int* next, int root, int* perm, int* aux) {
  int* auxptr = aux;
  int* child = u_alloc(n, &auxptr);
  int* next = u_alloc(n, &auxptr);
  int* active = u_alloc(n, &auxptr);
  int size;
  s_reset(active, &size);
  s_push(root, active, &size);
  int p = n;
  while(size > 0) {
    int v = s_pop(active, &size);
    perm[-- p] = v;
    for(int w=child[v]; w >= 0; w=next[w]) {
      s_push(w, active, &size);
    }
  }
}
