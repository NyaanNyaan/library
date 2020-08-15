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


# :x: graph/cycle-detection.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/cycle-detection.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-15 17:28:50+09:00




## Depends on

* :question: <a href="graph-template.hpp.html">graph/graph-template.hpp</a>


## Verified with

* :x: <a href="../../verify/verify/verify-yosupo-graph/yosupo-cycle-detection.test.cpp.html">verify/verify-yosupo-graph/yosupo-cycle-detection.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;
#include "./graph-template.hpp"

template <typename G>
vector<pair<int, int>> CycleDetection(const G& g, bool directed = true) {
  vector<int> pidx(g.size(), -1), vis(g.size(), 0);

  vector<pair<int, int>> cycle;
  int finish = 0;
  auto dfs = [&](auto rec, int cur, int pval, int par) -> int {
    pidx[cur] = pval;
    vis[cur] = 1;
    for (auto& dst : g[cur]) {
      if (finish) return -1;
      if (!directed && dst == par) continue;
      if (pidx[dst] == pidx[cur]) {
        cycle.emplace_back(cur, dst);
        return dst;
      }
      if (vis[dst]) continue;
      int nx = rec(rec, dst, pval, cur);
      if (nx != -1) {
        cycle.emplace_back(cur, dst);
        if (cur == nx) {
          finish = 1;
          return -1;
        }
        return nx;
      }
    }
    pidx[cur] = -1;
    return -1;
  };

  for (int i = 0; i < (int)g.size(); i++) {
    if (vis[i]) continue;
    dfs(dfs, i, i, -1);

    if (finish) {
      reverse(begin(cycle), end(cycle));
      return cycle;
    }
  }
  return vector<pair<int, int>>{};
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graph/cycle-detection.hpp"
#include <bits/stdc++.h>
using namespace std;
#line 3 "graph/graph-template.hpp"
using namespace std;

template <typename T>
struct edge {
  int src, to;
  T cost;

  edge(int to, T cost) : src(-1), to(to), cost(cost) {}
  edge(int src, int to, T cost) : src(src), to(to), cost(cost) {}

  edge &operator=(const int &x) {
    to = x;
    return *this;
  }

  operator int() const { return to; }
};
template <typename T>
using Edges = vector<edge<T>>;
template <typename T>
using WeightedGraph = vector<Edges<T>>;
using UnweightedGraph = vector<vector<int>>;

// Input of (Unweighted) Graph
UnweightedGraph graph(int N, int M = -1, bool is_directed = false,
                      bool is_1origin = true) {
  UnweightedGraph g(N);
  if (M == -1) M = N - 1;
  for (int _ = 0; _ < M; _++) {
    int x, y;
    cin >> x >> y;
    if (is_1origin) x--, y--;
    g[x].push_back(y);
    if (!is_directed) g[y].push_back(x);
  }
  return g;
}

// Input of Weighted Graph
template <typename T>
WeightedGraph<T> wgraph(int N, int M = -1, bool is_directed = false,
                        bool is_1origin = true) {
  WeightedGraph<T> g(N);
  if (M == -1) M = N - 1;
  for (int _ = 0; _ < M; _++) {
    int x, y;
    cin >> x >> y;
    T c;
    cin >> c;
    if (is_1origin) x--, y--;
    g[x].eb(x, y, c);
    if (!is_directed) g[y].eb(y, x, c);
  }
  return g;
}

// Input of Edges
template <typename T>
Edges<T> esgraph(int N, int M, int is_weighted = true, bool is_1origin = true) {
  Edges<T> es;
  for (int _ = 0; _ < M; _++) {
    int x, y;
    cin >> x >> y;
    T c;
    if (is_weighted)
      cin >> c;
    else
      c = 1;
    if (is_1origin) x--, y--;
    es.emplace_back(x, y, c);
  }
  return es;
}

// Input of Adjacency Matrix
template <typename T>
vector<vector<T>> adjgraph(int N, int M, T INF, int is_weighted = true,
                           bool is_directed = false, bool is_1origin = true) {
  vector<vector<T>> d(N, vector<T>(N, INF));
  for (int _ = 0; _ < M; _++) {
    int x, y;
    cin >> x >> y;
    T c;
    if (is_weighted)
      cin >> c;
    else
      c = 1;
    if (is_1origin) x--, y--;
    d[x][y] = c;
    if (!is_directed) d[y][x] = c;
  }
  return d;
}
#line 5 "graph/cycle-detection.hpp"

template <typename G>
vector<pair<int, int>> CycleDetection(const G& g, bool directed = true) {
  vector<int> pidx(g.size(), -1), vis(g.size(), 0);

  vector<pair<int, int>> cycle;
  int finish = 0;
  auto dfs = [&](auto rec, int cur, int pval, int par) -> int {
    pidx[cur] = pval;
    vis[cur] = 1;
    for (auto& dst : g[cur]) {
      if (finish) return -1;
      if (!directed && dst == par) continue;
      if (pidx[dst] == pidx[cur]) {
        cycle.emplace_back(cur, dst);
        return dst;
      }
      if (vis[dst]) continue;
      int nx = rec(rec, dst, pval, cur);
      if (nx != -1) {
        cycle.emplace_back(cur, dst);
        if (cur == nx) {
          finish = 1;
          return -1;
        }
        return nx;
      }
    }
    pidx[cur] = -1;
    return -1;
  };

  for (int i = 0; i < (int)g.size(); i++) {
    if (vis[i]) continue;
    dfs(dfs, i, i, -1);

    if (finish) {
      reverse(begin(cycle), end(cycle));
      return cycle;
    }
  }
  return vector<pair<int, int>>{};
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

