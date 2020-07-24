#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

#include "./graph-template.cpp"
#include "../data-structure/union-find.cpp"

template <typename T>
T kruskal(int N, Edges<T> &es) {
  sort(begin(es), end(es),
       [&](edge<T> a, edge<T> b) { return a.cost < b.cost; });
  UnionFind uf(N);
  T ret = 0;
  for (edge<T> &e : es) {
    if (uf.same(e.src, e.to)) continue;
    ret += e.cost;
    uf.unite(e.src, e.to);
  }
  return ret;
}