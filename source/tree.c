#include <stack.h>
#include <util.h>

void tree_child(int n, int* parent, int* child, int* next) {
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

int tree_components(int n, int* parent, int* component, int* aux) {
  int* auxptr = aux;
  int* active = u_alloc(n, &auxptr);
  for(int v=0; v<n; v++) { component[v] = -1; }
  int nc = 0;
  int size;
  s_reset(active, &size);
  for(int v=0; v<n; v++) {
    if(component[v] < 0) {
      s_push(v, active, &size);
      int p = parent[v];
      while(p >= 0) {
        if(component[p] < 0) {
          s_push(p, active, &size);
          p = parent[p];
        }else { break; }
      }
      int c = (p<0)? (nc ++): component[p];
      while(size > 0) {
        int w = s_pop(active, &size);
        component[w] = c;
      }
    }
  }
  return nc;
}

void tree_parent(int n, int* child, int* next, int* parent) {
  for(int v=0; v<n; v++) { parent[v] = -1; }
  for(int v=0; v<n; v++) {
    for(int w=child[v]; w>=0; w=next[w]) {
      parent[w] = v;
    }
  }
}

int tree_preorder(int n, int* child, int* next, int* perm, int* aux) {
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
  return n-p;
}

int tree_postorder(int n, int* child, int* next, int* perm, int* aux) {
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
  return p;
}

int tree_preorder_prev(int n, int* child, int* prev, int* perm, int* aux) {
  int* auxptr = aux;
  int* active = u_alloc(n, &auxptr);
  int* parent = u_alloc(n, &auxptr);
  tree_parent(n, child, prev, parent);
  int size;
  s_reset(active, &size);
  int p = 0;
  for(int i=0; i<n; i++) {
    if(parent[i] < 0) {
      s_push(i, active, &size);
      while(size > 0) {
        int v = s_pop(active, &size);
        perm[p ++] = v;
        for(int w=child[v]; w >= 0; w=prev[w]) {
          s_push(w, active, &size);
        }
      }
    }
  }
  return n-p;
}

