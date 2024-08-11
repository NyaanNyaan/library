#pragma once

struct UnionFind {
  vector<int> data;
  UnionFind(int N) : data(N, -1) {}

  int find(int k) { return data[k] < 0 ? k : data[k] = find(data[k]); }

  int unite(int x, int y) {
    if ((x = find(x)) == (y = find(y))) return false;
    if (data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    return true;
  }

  // f(x, y) : x に y をマージ
  template<typename F>
  int unite(int x, int y,const F &f) {
    if ((x = find(x)) == (y = find(y))) return false;
    if (data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    f(x, y);
    return true;
  }

  int size(int k) { return -data[find(k)]; }

  int same(int x, int y) { return find(x) == find(y); }
};

/**
 * @brief Union Find(Disjoint Set Union)
 * @docs docs/data-structure/union-find.md
 */
