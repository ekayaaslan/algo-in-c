#include <stack.h>
#include <util.h>
#include <tree.h>

void tree_postorder(int n, int* child, int* next, int* perm, int* aux) {
  int* auxptr = aux;
  int* active = u_alloc(n, &auxptr);
  int* parent = u_alloc(n, &auxptr);
  tree_parent(n, child, next, parent);
  int size;
  s_reset(active, &size);
  int p = n;
  for(int i=0; i<n; i++) {
    if(parent[i] < 0) {
      s_push(i, active, &size);
      while(size > 0) {
        int v = s_pop(active, &size);
        perm[-- p] = v;
        for(int w=child[v]; w >= 0; w=next[w]) {
          s_push(w, active, &size);
        }
      }
    }
  }
}
