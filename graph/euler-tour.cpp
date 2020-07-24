#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

// euler tour of node
struct EulerTour {
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

    int size(int k) { return -data[find(k)]; }

    int same(int x, int y) { return find(x) == find(y); }
  };

  struct SegmentTree_RangeMin {
    int size;
    using P = pair<int, int>;
    vector<P> seg;
    P UNIT = P(1 << 30, -1);

    SegmentTree_RangeMin() {}

    SegmentTree_RangeMin(int N) {
      size = 1;
      while (size < N) size <<= 1;
      seg.assign(2 * size, UNIT);
    }

    void set(int k, P x) { seg[k + size] = x; }

    void build() {
      for (int k = size - 1; k > 0; k--) {
        seg[k] = min(seg[2 * k], seg[2 * k + 1]);
      }
    }

    // query to [a, b)
    P query(int a, int b) {
      P L = UNIT, R = UNIT;
      for (a += size, b += size; a < b; a >>= 1, b >>= 1) {
        if (a & 1) L = min(L, seg[a++]);
        if (b & 1) R = min(seg[--b], R);
      }
      return min(L, R);
    }
  };

  using G = vector<vector<int>>;

  UnionFind uf;
  vector<int> down, up, tour, par, depth;
  int i_;
  SegmentTree_RangeMin lca_seg;

  EulerTour(G &g)
      : uf(g.size()),
        down(g.size(), -1),
        up(g.size()),
        tour(g.size() * 2),
        par(g.size()),
        depth(g.size(), -1),
        i_(0),
        lca_seg(2 * g.size()) {
    vector<int> isroot(g.size(), 1);
    for (int i = 0; i < (int)g.size(); i++) {
      for (auto &d : g[i]) isroot[d] = 0;
    }
    for (int i = 0; i < (int)g.size(); i++) {
      if (!isroot[i]) continue;
      dfs(g, i, -1);
    }
    lca_seg.build();
  }

  void dfs(G &g, int c, int p) {
    down[c] = i_;
    par[c] = p;
    depth[c] = ~p ? depth[p] + 1 : 0;
    lca_seg.set(i_, {depth[c], c});
    tour[i_++] = c;
    if (~p) uf.unite(c, p);
    for (auto &d : g[c]) {
      if (d == p) continue;
      dfs(g, d, c);
    }
    up[c] = i_;
    if (~p) lca_seg.set(i_, {depth[p], p});
    tour[i_++] = c;
  }

  int lca(int a, int b) {
    if (!uf.same(a, b)) return -1;
    if (down[a] > down[b]) swap(a, b);
    return lca_seg.query(down[a], down[b] + 1).second;
  }

  template <typename F>
  void node_query(int a, int b, F &f) {
    int l = lca(a, b);
    assert(l != -1);
    f(down[l], down[a] + 1);
    f(down[l] + 1, down[b] + 1);
  }

  template <typename F>
  void edge_query(int a, int b, F &f) {
    int l = lca(a, b);
    assert(l != -1);
    f(down[l] + 1, down[a] + 1);
    f(down[l] + 1, down[b] + 1);
  }
};