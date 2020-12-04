#pragma once

#include "../atcoder/maxflow.hpp"

namespace BipartiteGraph {
using namespace atcoder;
template <typename Cap>
struct Matching : mf_graph<Cap> {
  int L, R, s, t;

  explicit Matching(int N, int M)
      : mf_graph<Cap>(N + M + 2), L(N), R(M), s(N + M), t(N + M + 1) {
    for (int i = 0; i < L; i++) mf_graph<Cap>::add_edge(s, i, 1);
    for (int i = 0; i < R; i++) mf_graph<Cap>::add_edge(i + L, t, 1);
  }

  int add_edge(int n, int m, int cap = 1) override {
    assert(0 <= n && n < L);
    assert(0 <= m && m < R);
    return mf_graph<Cap>::add_edge(n, m + L, cap);
  }

  Cap flow() { return mf_graph<Cap>::flow(s, t); }

  vector<pair<int, int>> edges() {
    auto es = mf_graph<Cap>::edges();
    vector<pair<int, int>> ret;
    for (auto &e : es) {
      if (e.flow > 0 && e.from != s && e.to != t) {
        ret.emplace_back(e.from, e.to - L);
      }
    }
    return ret;
  }
};

}  // namespace BipartiteGraph
