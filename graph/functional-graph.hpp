#pragma once

#include <cassert>
#include <utility>
#include <vector>
using namespace std;

#include "../data-structure/union-find.hpp"
#include "../internal/internal-type-traits.hpp"
#include "graph-template.hpp"

namespace FunctionalGraphImpl {

ENABLE_HAS_VAR(cost)

// 全ての頂点の出次数が 1
template <typename T = int>
struct FunctionalGraph {
  int N;
  WeightedGraph<T> g;
  vector<int> to, represent;
  vector<T> weight;

  FunctionalGraph() = default;

  FunctionalGraph(int n, const vector<int>& adj,
                  const vector<T>& w = vector<int>{})
      : N(n), g(N + 1), to(N + 1, -1), represent(N + 1, -1), weight(N + 1) {
    assert((int)adj.size() == N);
    assert((int)w.size() == N or w.empty());
    for (auto& x : adj) assert(0 <= x and x < N);

    UnionFind uf(N);
    for (int i = 0; i < N; i++) {
      int j = adj[i];
      to[i] = j, weight[i] = w.empty() ? T{1} : w[i];
      if (uf.same(i, j)) {
        g[N].emplace_back(N, i, weight[i]);
      } else {
        uf.unite(i, j);
        g[j].emplace_back(j, i, weight[i]);
      }
    }
    calc_represent(N, -1);
  }

  // _g は無向グラフ
  template <typename G>
  FunctionalGraph(int n, const G& _g)
      : N(n), g(N + 1), to(N + 1, -1), represent(N + 1, -1), weight(N + 1) {
    constexpr bool cost_flag = has_cost_v<typename G::value_type::value_type>;
    WeightedGraph<T> h(n);
    UnionFind uf(N);
    for (int i = 0; i < N; i++) {
      for (auto& j : _g[i]) {
        if (i > j) continue;
        T cost;
        if constexpr (cost_flag) {
          cost = j.cost;
        } else {
          cost = 1;
        }
        if (uf.same(i, j)) {
          // i -> j 向きということにして, i を根とする
          g[N].emplace_back(N, i, 0);
          to[i] = j, weight[i] = cost;
        } else {
          uf.unite(i, j);
          h[i].emplace_back(i, j, cost);
          h[j].emplace_back(j, i, cost);
        }
      }
    }

    auto dfs = [&](auto rc, int c, int p) -> void {
      for (auto& d : h[c]) {
        if (d == p) continue;
        T cost;
        if constexpr (cost_flag) {
          cost = d.cost;
        } else {
          cost = 1;
        }
        to[d] = c, weight[d] = cost;
        g[c].emplace_back(c, d, cost);
        rc(rc, d, c);
      }
    };
    for (auto& r : g[N]) dfs(dfs, r, -1);

    calc_represent(N, -1);
  }

  vector<vector<int>> get_loops() const {
    vector<vector<int>> res;
    for (auto r : g[N]) {
      vector<int> cur{r};
      for (int i = to[r]; i != r; i = to[i]) {
        cur.push_back(i);
      }
      res.push_back(cur);
    }
    return res;
  }

  // (u, {weight of u-v}) (v, {weight of v-w}), (w, ...) ...
  vector<vector<pair<int, T>>> get_loops_with_weight() const {
    vector<vector<pair<int, T>>> res;
    for (auto r : g[N]) {
      vector<pair<int, T>> cur{make_pair(r, weight[r])};
      for (int i = to[r]; i != r; i = to[i]) {
        cur.emplace_back(i, weight[i]);
      }
      res.push_back(cur);
    }
    return res;
  }

 private:
  void calc_represent(int c, int r) {
    represent[c] = r;
    for (auto& d : g[c]) calc_represent(d, r == -1 ? d : r);
  }
};

}  // namespace FunctionalGraphImpl

using FunctionalGraphImpl::FunctionalGraph;
