#pragma once

#include "../string/rolling-hash-on-segment-tree.hpp"
#include "union-find-enumerate.hpp"

struct ParallelUnionFind {
  int n;
  UnionFindEnumerate uf;
  RollingHashonSegmentTree<vector<int>> seg;

  ParallelUnionFind(int _n) : n(_n), uf(n) {
    vector<int> init(n);
    for (int i = 0; i < n; i++) init[i] = i;
    seg = {init};
  }

  // [l1, r1) と [l2, r2) を unite する
  void unite(int l1, int r1, int l2, int r2) {
    assert(0 <= l1 and l1 <= r1 and r1 <= n);
    assert(0 <= l2 and l2 <= r2 and r2 <= n);
    assert(r1 - l1 == r2 - l2);
    while (1) {
      if (seg.same(l1, r1, l2, r2)) break;
      int ok = 0, ng = r1 - l1;
      while (ok + 1 < ng) {
        int m = (ok + ng) / 2;
        (seg.same(l1, l1 + m, l2, l2 + m) ? ok : ng) = m;
      }
      uf.unite(l1 + ok, l2 + ok, [&](int x, int y) {
        for (int z : uf.enumerate(y)) seg.update(z, x);
      });
    }
  }
  // [l1, r1) と [l2, r2) を unite する
  // f(x, y) : x に y をマージ
  template <typename F>
  void unite(int l1, int r1, int l2, int r2, const F& f) {
    assert(0 <= l1 and l1 <= r1 and r1 <= n);
    assert(0 <= l2 and l2 <= r2 and r2 <= n);
    assert(r1 - l1 == r2 - l2);
    while (1) {
      if (seg.same(l1, r1, l2, r2)) break;
      int ok = 0, ng = r1 - l1;
      while (ok + 1 < ng) {
        int m = (ok + ng) / 2;
        (seg.same(l1, l1 + m, l2, l2 + m) ? ok : ng) = m;
      }
      uf.unite(l1 + ok, l2 + ok, [&](int x, int y) {
        for (int z : uf.enumerate(y)) seg.update(z, x);
        f(x, y);
      });
    }
  }

  void unite(int l, int r) { unite(l, l + 1, r, r + 1); }
  int find(int i) { return uf.find(i); }
  int same(int l, int r) { return uf.same(l, r); }
  int size(int i) { return uf.size(i); }
};
