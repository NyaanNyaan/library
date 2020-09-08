---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: flow/flow-on-bipartite-graph.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#cff5497121104c2b8e0cb41ed2083a9b">flow</a>
* <a href="{{ site.github.repository_url }}/blob/master/flow/flow-on-bipartite-graph.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 18:51:36+09:00




## Depends on

* :heavy_check_mark: <a href="../atcoder/internal_queue.hpp.html">atcoder/internal_queue.hpp</a>
* :heavy_check_mark: <a href="../atcoder/maxflow.hpp.html">atcoder/maxflow.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-graph/yosupo-matching-on-bipartite-graph.test.cpp.html">verify/verify-yosupo-graph/yosupo-matching-on-bipartite-graph.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
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

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "flow/flow-on-bipartite-graph.hpp"
#include <bits/stdc++.h>
#line 7 "atcoder/maxflow.hpp"

#line 3 "atcoder/internal_queue.hpp"

namespace atcoder {

namespace internal {

template <class T>
struct simple_queue {
  std::vector<T> payload;
  int pos = 0;
  void reserve(int n) { payload.reserve(n); }
  int size() const { return int(payload.size()) - pos; }
  bool empty() const { return pos == int(payload.size()); }
  void push(const T& t) { payload.push_back(t); }
  T& front() { return payload[pos]; }
  void clear() {
    payload.clear();
    pos = 0;
  }
  void pop() { pos++; }
};

}  // namespace internal

}  // namespace atcoder
#line 9 "atcoder/maxflow.hpp"

namespace atcoder {

template <class Cap>
struct mf_graph {
 public:
  mf_graph() : _n(0) {}
  mf_graph(int n) : _n(n), g(n) {}

  virtual int add_edge(int from, int to, Cap cap) {
    assert(0 <= from && from < _n);
    assert(0 <= to && to < _n);
    assert(0 <= cap);
    int m = int(pos.size());
    pos.push_back({from, int(g[from].size())});
    g[from].push_back(_edge{to, int(g[to].size()), cap});
    g[to].push_back(_edge{from, int(g[from].size()) - 1, 0});
    return m;
  }

  struct edge {
    int from, to;
    Cap cap, flow;
  };

  edge get_edge(int i) {
    int m = int(pos.size());
    assert(0 <= i && i < m);
    auto _e = g[pos[i].first][pos[i].second];
    auto _re = g[_e.to][_e.rev];
    return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
  }

  std::vector<edge> edges() {
    int m = int(pos.size());
    std::vector<edge> result;
    for (int i = 0; i < m; i++) {
      result.push_back(get_edge(i));
    }
    return result;
  }

  void change_edge(int i, Cap new_cap, Cap new_flow) {
    int m = int(pos.size());
    assert(0 <= i && i < m);
    assert(0 <= new_flow && new_flow <= new_cap);
    auto& _e = g[pos[i].first][pos[i].second];
    auto& _re = g[_e.to][_e.rev];
    _e.cap = new_cap - new_flow;
    _re.cap = new_flow;
  }

  Cap flow(int s, int t) { return flow(s, t, std::numeric_limits<Cap>::max()); }
  Cap flow(int s, int t, Cap flow_limit) {
    assert(0 <= s && s < _n);
    assert(0 <= t && t < _n);

    std::vector<int> level(_n), iter(_n);
    internal::simple_queue<int> que;

    auto bfs = [&]() {
      std::fill(level.begin(), level.end(), -1);
      level[s] = 0;
      que.clear();
      que.push(s);
      while (!que.empty()) {
        int v = que.front();
        que.pop();
        for (auto &e : g[v]) {
          if (e.cap == 0 || level[e.to] >= 0) continue;
          level[e.to] = level[v] + 1;
          if (e.to == t) return;
          que.push(e.to);
        }
      }
    };
    auto dfs = [&](auto self, int v, Cap up) {
      if (v == s) return up;
      Cap res = 0;
      int level_v = level[v];
      for (int& i = iter[v]; i < int(g[v].size()); i++) {
        _edge& e = g[v][i];
        if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
        Cap d = self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));
        if (d <= 0) continue;
        g[v][i].cap += d;
        g[e.to][e.rev].cap -= d;
        res += d;
        if (res == up) break;
      }
      return res;
    };

    Cap flow = 0;
    while (flow < flow_limit) {
      bfs();
      if (level[t] == -1) break;
      std::fill(iter.begin(), iter.end(), 0);
      while (flow < flow_limit) {
        Cap f = dfs(dfs, t, flow_limit - flow);
        if (!f) break;
        flow += f;
      }
    }
    return flow;
  }

  std::vector<bool> min_cut(int s) {
    std::vector<bool> visited(_n);
    internal::simple_queue<int> que;
    que.push(s);
    while (!que.empty()) {
      int p = que.front();
      que.pop();
      visited[p] = true;
      for (auto e : g[p]) {
        if (e.cap && !visited[e.to]) {
          visited[e.to] = true;
          que.push(e.to);
        }
      }
    }
    return visited;
  }

 private:
  int _n;
  struct _edge {
    int to, rev;
    Cap cap;
  };
  std::vector<std::pair<int, int>> pos;
  std::vector<std::vector<_edge>> g;
};

}  // namespace atcoder

using namespace atcoder;
#line 4 "flow/flow-on-bipartite-graph.hpp"

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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

