#include <binary_search_tree.h>

void rbt_reset(int* items, int* _size, int* left, int* right, int* parent, int* color) {
  bst_reset(items, _size, left, right);
}

void recolor_parent(int p, int* left, int* right, int* parent, int* color) {
  color[left [p]] = 0;
  color[right[p]] = 0;
  color[p] = 1;
}

void link(int v, int p, int* child, int* parent) {
  child[p] = v;
  if(v >= 0) {
    parent[v] = p;
  }
}

void link_parent(int p, int q, int* left, int* right, int* parent) {
  if(parent[q] >= 0) {
    int r = parent[q];
    if(left[r] == q) { 
      link(p, r, left, parent);  
    }else{ 
      link(p, r, right, parent);
    }
  }
}

void recolor_left(int v, int* left, int* right, int* parent, int* color) {
  int p = parent[v];
  int q = parent[p];
  if(left[q] == p) {
    color[v] = 0;
    link_parent(p, q, left, right, parent);
    link(right[p], q, left, parent);
    link(q, p, right, parent);
  }else {
    color[p] = 0;
    link_parent(v, q, left, right, parent);
    link(left[v], q, right, parent);
    link(right[v], p, left, parent);
    link(q, v, left, parent);
    link(p, v, right, parent);
  }
}

void recolor_right(int v, int* left, int* right, int* parent, int* color) {
  int p = parent[v];
  int q = parent[p];
  if(right[q] == p) {
    color[v] = 0;
    link_parent(p, q, left, right, parent);
    link(left[p], q, right, parent);
    link(q, p, left, parent);
  }else {
    color[p] = 0;
    link_parent(v, q, left, right, parent);
    link(right[v], q, left, parent);
    link(left[v], p, right, parent);
    link(q, v, right, parent);
    link(p, v, left, parent);
  }
}

void recolor(int v, int* left, int* right, int* parent, int* color) {
  if(parent[v] < 0) { return; }
  int p = parent[v];
  if(left[p] >= 0) {
    if(color[left[p]]) {
      if(right[p] >= 0) {
        if(color[right[p]]) {
          recolor_parent(p, left, right, parent, color);
          recolor(p, left, right, parent, color);
          return;
        }
      }
      if(parent[p] >= 0) {
        int q = parent[p];
        if(color[p]) {
          recolor_left(v, left, right, parent, color);
          recolor(parent[q], left, right, parent, color);
        }
      }
    }
    return;
  }
  if(parent[p] >= 0) {
    int q = parent[p];
    if(color[p]) {
      recolor_right(v, left, right, parent, color);
      recolor(parent[q], left, right, parent, color);
    }
  }
}

void rbt_insert(int item, int* items, int* _size, int* left, int* right, int* parent, int* color) {
  int size = *_size;
  parent[size] = bst_insert(item, items, _size, left, right);
  color[size] = 1; //red
  recolor(size, left, right, parent, color);
}
