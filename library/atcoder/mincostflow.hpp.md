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


# :warning: atcoder/mincostflow.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#554e0d24f25abaa0e2922c944fbc560c">atcoder</a>
* <a href="{{ site.github.repository_url }}/blob/master/atcoder/mincostflow.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 18:51:36+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <vector>

namespace atcoder {

template <class Cap, class Cost>
struct mcf_graph {
 public:
  mcf_graph() {}
  mcf_graph(int n) : _n(n), g(n) {}

  int add_edge(int from, int to, Cap cap, Cost cost) {
    assert(0 <= from && from < _n);
    assert(0 <= to && to < _n);
    int m = int(pos.size());
    pos.push_back({from, int(g[from].size())});
    g[from].push_back(_edge{to, int(g[to].size()), cap, cost});
    g[to].push_back(_edge{from, int(g[from].size()) - 1, 0, -cost});
    return m;
  }

  struct edge {
    int from, to;
    Cap cap, flow;
    Cost cost;
  };

  edge get_edge(int i) {
    int m = int(pos.size());
    assert(0 <= i && i < m);
    auto _e = g[pos[i].first][pos[i].second];
    auto _re = g[_e.to][_e.rev];
    return edge{
        pos[i].first, _e.to, _e.cap + _re.cap, _re.cap, _e.cost,
    };
  }
  std::vector<edge> edges() {
    int m = int(pos.size());
    std::vector<edge> result(m);
    for (int i = 0; i < m; i++) {
      result[i] = get_edge(i);
    }
    return result;
  }

  std::pair<Cap, Cost> flow(int s, int t) {
    return flow(s, t, std::numeric_limits<Cap>::max());
  }
  std::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {
    return slope(s, t, flow_limit).back();
  }
  std::vector<std::pair<Cap, Cost>> slope(int s, int t) {
    return slope(s, t, std::numeric_limits<Cap>::max());
  }
  std::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
    assert(0 <= s && s < _n);
    assert(0 <= t && t < _n);
    assert(s != t);
    // variants (C = maxcost):
    // -(n-1)C <= dual[s] <= dual[i] <= dual[t] = 0
    // reduced cost (= e.cost + dual[e.from] - dual[e.to]) >= 0 for all edge
    std::vector<Cost> dual(_n, 0), dist(_n);
    std::vector<int> pv(_n), pe(_n);
    std::vector<bool> vis(_n);
    auto dual_ref = [&]() {
      std::fill(dist.begin(), dist.end(), std::numeric_limits<Cost>::max());
      std::fill(pv.begin(), pv.end(), -1);
      std::fill(pe.begin(), pe.end(), -1);
      std::fill(vis.begin(), vis.end(), false);
      struct Q {
        Cost key;
        int to;
        bool operator<(Q r) const { return key > r.key; }
      };
      std::priority_queue<Q> que;
      dist[s] = 0;
      que.push(Q{0, s});
      while (!que.empty()) {
        int v = que.top().to;
        que.pop();
        if (vis[v]) continue;
        vis[v] = true;
        if (v == t) break;
        // dist[v] = shortest(s, v) + dual[s] - dual[v]
        // dist[v] >= 0 (all reduced cost are positive)
        // dist[v] <= (n-1)C
        for (int i = 0; i < int(g[v].size()); i++) {
          auto e = g[v][i];
          if (vis[e.to] || !e.cap) continue;
          // |-dual[e.to] + dual[v]| <= (n-1)C
          // cost <= C - -(n-1)C + 0 = nC
          Cost cost = e.cost - dual[e.to] + dual[v];
          if (dist[e.to] - dist[v] > cost) {
            dist[e.to] = dist[v] + cost;
            pv[e.to] = v;
            pe[e.to] = i;
            que.push(Q{dist[e.to], e.to});
          }
        }
      }
      if (!vis[t]) {
        return false;
      }

      for (int v = 0; v < _n; v++) {
        if (!vis[v]) continue;
        // dual[v] = dual[v] - dist[t] + dist[v]
        //         = dual[v] - (shortest(s, t) + dual[s] - dual[t]) +
        //         (shortest(s, v) + dual[s] - dual[v]) = - shortest(s, t) +
        //         dual[t] + shortest(s, v) = shortest(s, v) - shortest(s, t) >=
        //         0 - (n-1)C
        dual[v] -= dist[t] - dist[v];
      }
      return true;
    };
    Cap flow = 0;
    Cost cost = 0, prev_cost = -1;
    std::vector<std::pair<Cap, Cost>> result;
    result.push_back({flow, cost});
    while (flow < flow_limit) {
      if (!dual_ref()) break;
      Cap c = flow_limit - flow;
      for (int v = t; v != s; v = pv[v]) {
        c = std::min(c, g[pv[v]][pe[v]].cap);
      }
      for (int v = t; v != s; v = pv[v]) {
        auto& e = g[pv[v]][pe[v]];
        e.cap -= c;
        g[v][e.rev].cap += c;
      }
      Cost d = -dual[s];
      flow += c;
      cost += c * d;
      if (prev_cost == d) {
        result.pop_back();
      }
      result.push_back({flow, cost});
      prev_cost = cost;
    }
    return result;
  }

 private:
  int _n;

  struct _edge {
    int to, rev;
    Cap cap;
    Cost cost;
  };

  std::vector<std::pair<int, int>> pos;
  std::vector<std::vector<_edge>> g;
};

}  // namespace atcoder

using namespace atcoder;

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "atcoder/mincostflow.hpp"
#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <vector>

namespace atcoder {

template <class Cap, class Cost>
struct mcf_graph {
 public:
  mcf_graph() {}
  mcf_graph(int n) : _n(n), g(n) {}

  int add_edge(int from, int to, Cap cap, Cost cost) {
    assert(0 <= from && from < _n);
    assert(0 <= to && to < _n);
    int m = int(pos.size());
    pos.push_back({from, int(g[from].size())});
    g[from].push_back(_edge{to, int(g[to].size()), cap, cost});
    g[to].push_back(_edge{from, int(g[from].size()) - 1, 0, -cost});
    return m;
  }

  struct edge {
    int from, to;
    Cap cap, flow;
    Cost cost;
  };

  edge get_edge(int i) {
    int m = int(pos.size());
    assert(0 <= i && i < m);
    auto _e = g[pos[i].first][pos[i].second];
    auto _re = g[_e.to][_e.rev];
    return edge{
        pos[i].first, _e.to, _e.cap + _re.cap, _re.cap, _e.cost,
    };
  }
  std::vector<edge> edges() {
    int m = int(pos.size());
    std::vector<edge> result(m);
    for (int i = 0; i < m; i++) {
      result[i] = get_edge(i);
    }
    return result;
  }

  std::pair<Cap, Cost> flow(int s, int t) {
    return flow(s, t, std::numeric_limits<Cap>::max());
  }
  std::pair<Cap, Cost> flow(int s, int t, Cap flow_limit) {
    return slope(s, t, flow_limit).back();
  }
  std::vector<std::pair<Cap, Cost>> slope(int s, int t) {
    return slope(s, t, std::numeric_limits<Cap>::max());
  }
  std::vector<std::pair<Cap, Cost>> slope(int s, int t, Cap flow_limit) {
    assert(0 <= s && s < _n);
    assert(0 <= t && t < _n);
    assert(s != t);
    // variants (C = maxcost):
    // -(n-1)C <= dual[s] <= dual[i] <= dual[t] = 0
    // reduced cost (= e.cost + dual[e.from] - dual[e.to]) >= 0 for all edge
    std::vector<Cost> dual(_n, 0), dist(_n);
    std::vector<int> pv(_n), pe(_n);
    std::vector<bool> vis(_n);
    auto dual_ref = [&]() {
      std::fill(dist.begin(), dist.end(), std::numeric_limits<Cost>::max());
      std::fill(pv.begin(), pv.end(), -1);
      std::fill(pe.begin(), pe.end(), -1);
      std::fill(vis.begin(), vis.end(), false);
      struct Q {
        Cost key;
        int to;
        bool operator<(Q r) const { return key > r.key; }
      };
      std::priority_queue<Q> que;
      dist[s] = 0;
      que.push(Q{0, s});
      while (!que.empty()) {
        int v = que.top().to;
        que.pop();
        if (vis[v]) continue;
        vis[v] = true;
        if (v == t) break;
        // dist[v] = shortest(s, v) + dual[s] - dual[v]
        // dist[v] >= 0 (all reduced cost are positive)
        // dist[v] <= (n-1)C
        for (int i = 0; i < int(g[v].size()); i++) {
          auto e = g[v][i];
          if (vis[e.to] || !e.cap) continue;
          // |-dual[e.to] + dual[v]| <= (n-1)C
          // cost <= C - -(n-1)C + 0 = nC
          Cost cost = e.cost - dual[e.to] + dual[v];
          if (dist[e.to] - dist[v] > cost) {
            dist[e.to] = dist[v] + cost;
            pv[e.to] = v;
            pe[e.to] = i;
            que.push(Q{dist[e.to], e.to});
          }
        }
      }
      if (!vis[t]) {
        return false;
      }

      for (int v = 0; v < _n; v++) {
        if (!vis[v]) continue;
        // dual[v] = dual[v] - dist[t] + dist[v]
        //         = dual[v] - (shortest(s, t) + dual[s] - dual[t]) +
        //         (shortest(s, v) + dual[s] - dual[v]) = - shortest(s, t) +
        //         dual[t] + shortest(s, v) = shortest(s, v) - shortest(s, t) >=
        //         0 - (n-1)C
        dual[v] -= dist[t] - dist[v];
      }
      return true;
    };
    Cap flow = 0;
    Cost cost = 0, prev_cost = -1;
    std::vector<std::pair<Cap, Cost>> result;
    result.push_back({flow, cost});
    while (flow < flow_limit) {
      if (!dual_ref()) break;
      Cap c = flow_limit - flow;
      for (int v = t; v != s; v = pv[v]) {
        c = std::min(c, g[pv[v]][pe[v]].cap);
      }
      for (int v = t; v != s; v = pv[v]) {
        auto& e = g[pv[v]][pe[v]];
        e.cap -= c;
        g[v][e.rev].cap += c;
      }
      Cost d = -dual[s];
      flow += c;
      cost += c * d;
      if (prev_cost == d) {
        result.pop_back();
      }
      result.push_back({flow, cost});
      prev_cost = cost;
    }
    return result;
  }

 private:
  int _n;

  struct _edge {
    int to, rev;
    Cap cap;
    Cost cost;
  };

  std::vector<std::pair<int, int>> pos;
  std::vector<std::vector<_edge>> g;
};

}  // namespace atcoder

using namespace atcoder;

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

