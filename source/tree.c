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

void tree_parent(int n, int* child, int* next, int* parent) {
  for(int v=0; v<n; v++) { parent[v] = -1; }
  for(int v=0; v<n; v++) {
    for(int w=child[v]; w>=0; w=next[w]) {
      parent[w] = v;
    }
  }
}
