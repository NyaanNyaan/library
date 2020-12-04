#pragma once

#include "./persistent-array.hpp"

struct PersistentUnionFind {
  PersistentArray<int> arr;
  using Node = decltype(arr)::Node;
  static Node *root;

  PersistentUnionFind(int N) : arr(vector<int>(N, -1)) { root = arr.root; }

  pair<int, int> find_with_size(int i, Node *r = root) {
    int n = arr.get(r, i);
    return n < 0 ? pair<int, int>{i, n} : find_with_size(n, r);
  }
  inline int find(int i, Node *r = root) { return find_with_size(i, r).first; }
  inline int size(int i, Node *r = root) { return -(find_with_size(i, r).second); }
  inline int same(int i, int j, Node *r = root) { return find(i, r) == find(j, r); }

  int unite(int i, int j, Node *r = root) {
    int is, js;
    tie(i, is) = find_with_size(i, r);
    tie(j, js) = find_with_size(j, r);
    if (i == j) return false;
    if (is > js) swap(i, j), swap(is, js);
    r = arr.update(r, i, is + js);
    r = arr.update(r, j, i);
    root = r;
    return true;
  }

  Node *get_root() const { return root; }
};
typename PersistentUnionFind::Node *PersistentUnionFind::root = nullptr;

/**
 * @brief 完全永続Union-Find
 */
