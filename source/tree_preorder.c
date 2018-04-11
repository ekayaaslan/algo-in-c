#include <stack.h>
#include <util.h>
#include <tree.h>

void tree_preorder(int n, int* child, int* next, int* perm, int* aux) {
  int* auxptr = aux;
  int* active = u_alloc(n, &auxptr);
  int* parent = u_alloc(n, &auxptr);
  tree_parent(n, child, next, parent);
  int size, rsize;
  s_reset(active, &size);
  rs_reset(active, n, &rsize);
  int p = 0;
  for(int i=0; i<n; i++) {
    if(parent[i] < 0) {
      s_push(i, active, &size);
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
  }
}
