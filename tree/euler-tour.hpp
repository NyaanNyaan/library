#pragma once



#include "../graph/graph-template.hpp"

template <typename G>
struct EulerTour {
 private:
  struct RMQ {
    int n, s;
    using P = pair<int, int>;
    vector<P> seg;
    P UNIT = P(1 << 30, -1);

    RMQ(int N) : n(N), s(1) {
      while (s < N) s <<= 1;
      seg.assign(2 * s, UNIT);
    }

    void set(int k, P x) { seg[k + s] = x; }

    P operator[](int k) const { return seg[k + s]; }

    void build() {
      for (int k = s - 1; k > 0; k--) {
        seg[k] = min(seg[2 * k], seg[2 * k + 1]);
      }
    }

    P query(int a, int b) const {
      P R = UNIT;
      for (a += s, b += s; a < b; a >>= 1, b >>= 1) {
        if (a & 1) R = min(R, seg[a++]);
        if (b & 1) R = min(R, seg[--b]);
      }
      return R;
    }

    int size() const { return n; }
  };

  vector<int> down, up;
  int id;
  RMQ rmq;

  void init(G &g, int root) {
    dfs(g, root, -1, 0);
    if (id < rmq.size()) rmq.set(id++, {-1, -1});
    for (int i = 0; i < (int)g.size(); i++) {
      if (down[i] == -1) {
        rmq.set(id++, {-1, -1});
        dfs(g, i, -1, 0);
        if (id < rmq.size()) rmq.set(id++, {-1, -1});
      }
    }
    rmq.build();
  }

  void dfs(G &g, int c, int p, int dp) {
    down[c] = id;
    rmq.set(id++, {dp, c});
    for (auto &d : g[c]) {
      if (d == p) continue;
      dfs(g, d, c, dp + 1);
    }
    up[c] = id;
    if (p != -1) rmq.set(id++, {dp - 1, p});
  }

 public:
  // remind : because of additional node,
  // DS on tour should reserve 2 * n nodes.
  EulerTour(G &g, int root = 0)
      : down(g.size(), -1), up(g.size(), -1), id(0), rmq(2 * g.size()) {
    init(g, root);
  }

  pair<int, int> idx(int i) const { return {down[i], up[i]}; }

  int lca(int a, int b) const {
    if (down[a] > down[b]) swap(a, b);
    return rmq.query(down[a], down[b] + 1).second;
  }

  template <typename F>
  void node_query(int a, int b, const F &f) {
    int l = lca(a, b);
    f(down[l], down[a] + 1);
    f(down[l] + 1, down[b] + 1);
  }

  template <typename F>
  void edge_query(int a, int b, const F &f) {
    int l = lca(a, b);
    f(down[l] + 1, down[a] + 1);
    f(down[l] + 1, down[b] + 1);
  }

  template <typename F>
  void subtree_query(int a, const F &f) {
    f(down[a], up[a]);
  }

  int size() const { return int(rmq.size()); }
};

/**
 * @brief オイラーツアー
 * @docs docs/tree/euler-tour.md
 */
