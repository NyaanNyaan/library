#pragma once

#include "../atcoder/maxflow.hpp"

namespace BipartiteGraphImpl {
using namespace atcoder;
struct BipartiteGraph : mf_graph<long long> {
  int L, R, s, t;
  bool is_flow;

  explicit BipartiteGraph(int N, int M)
      : mf_graph<long long>(N + M + 2),
        L(N),
        R(M),
        s(N + M),
        t(N + M + 1),
        is_flow(false) {
    for (int i = 0; i < L; i++) mf_graph<long long>::add_edge(s, i, 1);
    for (int i = 0; i < R; i++) mf_graph<long long>::add_edge(i + L, t, 1);
  }

  int add_edge(int n, int m, long long cap = 1) override {
    assert(0 <= n && n < L);
    assert(0 <= m && m < R);
    return mf_graph<long long>::add_edge(n, m + L, cap);
  }

  long long flow() {
    is_flow = true;
    return mf_graph<long long>::flow(s, t);
  }

  vector<pair<int, int>> MaximumMatching() {
    if (!is_flow) flow();
    auto es = mf_graph<long long>::edges();
    vector<pair<int, int>> ret;
    for (auto &e : es) {
      if (e.flow > 0 && e.from != s && e.to != t) {
        ret.emplace_back(e.from, e.to - L);
      }
    }
    return ret;
  }

  // call after calclating flow !
  pair<vector<int>, vector<int>> MinimumVertexCover() {
    if (!is_flow) flow();
    auto colored = PreCalc();
    vector<int> nl, nr;
    for (int i = 0; i < L; i++)
      if (!colored[i]) nl.push_back(i);
    for (int i = 0; i < R; i++)
      if (colored[i + L]) nr.push_back(i);
    return make_pair(nl, nr);
  }

  // call after calclating flow !
  pair<vector<int>, vector<int>> MaximumIndependentSet() {
    if (!is_flow) flow();
    auto colored = PreCalc();
    vector<int> nl, nr;
    for (int i = 0; i < L; i++)
      if (colored[i]) nl.push_back(i);
    for (int i = 0; i < R; i++)
      if (!colored[i + L]) nr.push_back(i);
    return make_pair(nl, nr);
  }

  vector<pair<int, int>> MinimumEdgeCover() {
    if (!is_flow) flow();
    auto es = MaximumMatching();
    vector<bool> useL(L), useR(R);
    for (auto &p : es) {
      useL[p.first] = true;
      useR[p.second] = true;
    }
    for (auto &e : mf_graph<long long>::edges()) {
      if (e.flow > 0 || e.from == s || e.to == t) continue;
      if (useL[e.from] == false || useR[e.to - L] == false) {
        es.emplace_back(e.from, e.to - L);
        useL[e.from] = useR[e.to - L] = true;
      }
    }
    return es;
  }

 private:
  vector<bool> PreCalc() {
    vector<vector<int>> ag(L + R);
    vector<bool> used(L, false);
    for (auto &e : mf_graph<long long>::edges()) {
      if (e.from == s || e.to == t) continue;
      if (e.flow > 0) {
        ag[e.to].push_back(e.from);
        used[e.from] = true;
      } else {
        ag[e.from].push_back(e.to);
      }
    }
    vector<bool> colored(L + R, false);
    auto dfs = [&](auto rc, int cur) -> void {
      for (auto &d : ag[cur]) {
        if (!colored[d]) colored[d] = true, rc(rc, d);
      }
    };
    for (int i = 0; i < L; i++)
      if (!used[i]) colored[i] = true, dfs(dfs, i);
    return colored;
  }
};

}  // namespace BipartiteGraphImpl

using BipartiteGraphImpl::BipartiteGraph;

/**
 * @brief 二部グラフのフロー
 * @docs docs/flow/flow-on-bipartite-graph.md
 */
