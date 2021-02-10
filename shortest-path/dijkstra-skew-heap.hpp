#pragma once

#include "../graph/static-graph.hpp"

template <typename T>
struct SkewHeap {
  struct alignas(32) Node {
    T key;
    int p, l, r;
    Node(const T& k = T()) : key(k), p(-1), l(-1), r(-1) {}
  };

  vector<Node> v;
  int rt = -1;

  SkewHeap(int n) : v(n) {}

  int meld(int x, int y) {
    if (x == -1 || y == -1) return x == -1 ? y : x;
    if (v[x].key > v[y].key) swap(x, y);
    v[x].r = meld(v[x].r, y);
    v[v[x].r].p = x;
    swap(v[x].l, v[x].r);
    return x;
  }

  void pop() { rt = meld(v[rt].l, v[rt].r); }

  void update(int x, const T& k) {
    Node& n = v[x];
    v[x].key = k;
    if (x == rt) return;
    Node& p = v[n.p];
    if (p.key <= k) return;
    (p.l == x ? p.l : p.r) = -1;
    n.p = -1;
    rt = meld(rt, x);
  }

  bool empty() { return rt == -1; }
};

template <typename T>
vector<pair<T, int>> dijkstra_restore(StaticGraph<T>& g, int start = 0) {
  int N = (int)g.size();
  using P = pair<T, int>;
  vector<P> d(N, P{-1, -1});
  SkewHeap<T> Q(N);
  d[start].first = 0;
  Q.v[start].key = 0;
  Q.rt = start;
  while (!Q.empty()) {
    T dc = Q.v[Q.rt].key;
    int cur = Q.rt;
    Q.pop();
    for (auto dst : g[cur]) {
      if (d[dst].first == T(-1)) {
        d[dst] = P{dc + dst.cost, cur};
        Q.v[dst].key = dc + dst.cost;
        Q.rt = Q.meld(Q.rt, dst);
      } else if (dc + dst.cost < d[dst].first) {
        d[dst] = P{dc + dst.cost, cur};
        Q.update(dst, dc + dst.cost);
      }
    }
  }
  return d;
}
/*
 * @brief ダイクストラ法(Skew Heap)
 * @docs docs/shortest-path/dijkstra-skew-heap.md
**/
