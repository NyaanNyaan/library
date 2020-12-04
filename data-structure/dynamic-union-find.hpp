#pragma once

#include "../hashmap/hashmap.hpp"

struct DynamicUnionFind {
  HashMap<int, int> m;
  DynamicUnionFind() = default;

  int data(int k) {
    auto it = m.find(k);
    return it == m.end() ? m[k] = -1 : it->second;
  }
  int find(int k) {
    int n = data(k);
    return n < 0 ? k : m[k] = find(n);
  }

  int unite(int x, int y) {
    x = find(x), y = find(y);
    if (x == y) return false;
    auto itx = m.find(x), ity = m.find(y);
    if (itx->second > ity->second) swap(itx, ity), swap(x, y);
    itx->second += ity->second;
    ity->second = x;
    return true;
  }

  template <typename F>
  int unite(int x, int y, const F& f) {
    x = find(x), y = find(y);
    if (x == y) return false;
    auto itx = m.find(x), ity = m.find(y);
    if (itx->second > ity->second) swap(itx, ity), swap(x, y);
    itx->second += ity->second;
    ity->second = x;
    f(x, y);
    return true;
  }

  int size(int k) { return -data(find(k)); }

  int same(int x, int y) { return find(x) == find(y); }

  void clear() { m.clear(); }
};

/**
 * @brief 動的Union Find
 * @docs docs/data-structure/dynamic-union-find.md
 */
