#pragma once

#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>

using namespace std;

namespace TwoSatImpl {
namespace internal {

template <class E>
struct csr {
  vector<int> start;
  vector<E> elist;
  csr(int n, const vector<pair<int, E>>& edges)
      : start(n + 1), elist(edges.size()) {
    for (auto e : edges) {
      start[e.first + 1]++;
    }
    for (int i = 1; i <= n; i++) {
      start[i] += start[i - 1];
    }
    auto counter = start;
    for (auto e : edges) {
      elist[counter[e.first]++] = e.second;
    }
  }
};

struct scc_graph {
 public:
  scc_graph(int n) : _n(n) {}

  int num_vertices() { return _n; }

  void add_edge(int from, int to) { edges.push_back({from, {to}}); }

  pair<int, vector<int>> scc_ids() {
    auto g = csr<edge>(_n, edges);
    int now_ord = 0, group_num = 0;
    vector<int> visited, low(_n), ord(_n, -1), ids(_n);
    visited.reserve(_n);
    auto dfs = [&](auto self, int v) -> void {
      low[v] = ord[v] = now_ord++;
      visited.push_back(v);
      for (int i = g.start[v]; i < g.start[v + 1]; i++) {
        auto to = g.elist[i].to;
        if (ord[to] == -1) {
          self(self, to);
          low[v] = min(low[v], low[to]);
        } else {
          low[v] = min(low[v], ord[to]);
        }
      }
      if (low[v] == ord[v]) {
        while (true) {
          int u = visited.back();
          visited.pop_back();
          ord[u] = _n;
          ids[u] = group_num;
          if (u == v) break;
        }
        group_num++;
      }
    };
    for (int i = 0; i < _n; i++) {
      if (ord[i] == -1) dfs(dfs, i);
    }
    for (auto& x : ids) {
      x = group_num - 1 - x;
    }
    return {group_num, ids};
  }

  vector<vector<int>> scc() {
    auto ids = scc_ids();
    int group_num = ids.first;
    vector<int> counts(group_num);
    for (auto x : ids.second) counts[x]++;
    vector<vector<int>> groups(ids.first);
    for (int i = 0; i < group_num; i++) {
      groups[i].reserve(counts[i]);
    }
    for (int i = 0; i < _n; i++) {
      groups[ids.second[i]].push_back(i);
    }
    return groups;
  }

  void add_node_size(int m) { _n += m; }
  int size() { return _n; }

 private:
  int _n;
  struct edge {
    int to;
  };
  vector<pair<int, edge>> edges;
};

}  // namespace internal

struct two_sat {
 public:
  two_sat() : _n(0), scc(0) {}
  two_sat(int n) : _n(n), scc(2 * n) {}

  int add_var() {
    scc.add_node_size(2);
    return _n++;
  }

  // (not i) は ~i で渡す
  void add_clause(int i, int j) {
    i = max(2 * i, -1 - 2 * i);
    j = max(2 * j, -1 - 2 * j);
    assert(0 <= i && i < 2 * _n);
    assert(0 <= j && j < 2 * _n);
    scc.add_edge(i ^ 1, j);
    scc.add_edge(j ^ 1, i);
  }
  void if_then(int i, int j) { add_clause(~i, j); }
  void set_val(int i) { add_clause(i, i); }

  // (not i) は ~i で渡す
  void at_most_one(const vector<int>& nodes) {
    if ((int)nodes.size() <= 1) return;
    int cur = ~nodes[0];
    for (int i = 2; i < (int)nodes.size(); i++) {
      int nxt = add_var(), n_i = ~nodes[i];
      add_clause(cur, n_i);
      add_clause(cur, nxt);
      add_clause(n_i, nxt);
      cur = ~nxt;
    }
    add_clause(cur, ~nodes[1]);
  }

  bool satisfiable() {
    _answer.resize(_n);
    auto id = scc.scc_ids().second;
    for (int i = 0; i < _n; i++) {
      if (id[2 * i] == id[2 * i + 1]) return false;
      _answer[i] = id[2 * i] < id[2 * i + 1];
    }
    return true;
  }
  vector<bool> answer() {
    assert((int)_answer.size() == _n);
    return _answer;
  }

 private:
  int _n;
  vector<bool> _answer;
  internal::scc_graph scc;
};

}  // namespace TwoSatImpl

using TwoSatImpl::two_sat;
