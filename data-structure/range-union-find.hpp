#pragma once

struct RangeUnionFind {
  vector<int> data, left, right;
  RangeUnionFind(int N) : data(N, -1) {
    left.resize(N);
    right.resize(N);
    iota(begin(left), end(left), 0);
    iota(begin(right), end(right), 1);
  }

  int find(int k) { return data[k] < 0 ? k : data[k] = find(data[k]); }

  int unite(int x, int y) {
    if ((x = find(x)) == (y = find(y))) return false;
    if (data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    left[x] = min(left[x], left[y]);
    right[x] = max(right[x], right[y]);
    return true;
  }

  // unite [l, r)
  void range_unite(int l, int r) {
    if ((l = max(l, 0)) >= (r = min(r, (int)data.size()))) return;
    int m;
    while ((m = right[find(l)]) < r) {
      assert(left[find(m)] == m);
      unite(l, m);
    }
  }

  int size(int k) { return -data[find(k)]; }

  int same(int x, int y) { return find(x) == find(y); }
};