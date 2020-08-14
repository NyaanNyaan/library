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


# :heavy_check_mark: shortest-path/restore-shortest-path.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#d53d0f39583bbf03056486512d3e44bc">shortest-path</a>
* <a href="{{ site.github.repository_url }}/blob/master/shortest-path/restore-shortest-path.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-02 18:11:02+09:00




## Depends on

* :question: <a href="../graph/graph-template.hpp.html">graph/graph-template.hpp</a>
* :heavy_check_mark: <a href="../graph/graph-utility.hpp.html">graph/graph-utility.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-graph/yosupo-shortest-path.test.cpp.html">verify/verify-yosupo-graph/yosupo-shortest-path.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../graph/graph-utility.hpp"

// restore shortest path from S to G
template <typename T>
vector<int> restore_shortest_path(WeightedGraph<T> &g, vector<T> &d, int S,
                                  int G) {
  int N = g.size();
  WeightedGraph<T> rev(g.size());
  for (int i = 0; i < N; i++)
    for (auto &e : g[i]) rev[e.to].emplace_back(e.to, i, e.cost);
  vector<int> ret;
  ret.push_back(G);
  int p = G;
  T dist = d[G];
  vector<int> vis(N, 0);
  vis[G] = 1;
  do {
    int nxt = -1;
    T nval = numeric_limits<T>::max() / 2;
    for (auto &e : rev[p]) {
      if (vis[e.to] || d[e.to] + e.cost != dist) continue;
      if (d[e.to] < nval) nval = d[e.to], nxt = e.to;
    }
    ret.push_back((vis[nxt] = 1, dist = nval, p = nxt));
  } while (p != S);
  reverse(begin(ret), end(ret));
  return ret;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "shortest-path/restore-shortest-path.hpp"
#include <bits/stdc++.h>
using namespace std;

#line 3 "graph/graph-utility.hpp"
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
#line 6 "graph/graph-utility.hpp"

// Depth of Rooted Tree
// unvisited nodes : d = -1
vector<int> Depth(const UnweightedGraph &g, int start = 0) {
  vector<int> d(g.size(), -1);
  auto dfs = [&](auto rec, int cur, int par = -1) -> void {
    d[cur] = par == -1 ? 0 : d[par] + 1;
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      rec(rec, dst, cur);
    }
  };
  dfs(dfs, start);
  return d;
}

// Depth of Rooted Weighted Tree
// unvisited nodes : d = -1
template <typename T>
vector<T> Depth(const WeightedGraph<T> &g, int start = 0) {
  vector<T> d(g.size(), -1);
  auto dfs = [&](auto rec, int cur, T val, int par = -1) -> void {
    d[cur] = val;
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      rec(rec, dst, val + dst.cost, cur);
    }
  };
  dfs(dfs, start, 0);
  return d;
}

// Diameter of Tree
// return value : { {u, v}, length }
pair<pair<int, int>, int> Diameter(const UnweightedGraph &g) {
  auto d = Depth(g, 0);
  int u = max_element(begin(d), end(d)) - begin(d);
  d = Depth(g, u);
  int v = max_element(begin(d), end(d)) - begin(d);
  return make_pair(make_pair(u, v), d[v]);
}

// Diameter of Weighted Tree
// return value : { {u, v}, length }
template <typename T>
pair<pair<int, int>, T> Diameter(const WeightedGraph<T> &g) {
  auto d = Depth(g, 0);
  int u = max_element(begin(d), end(d)) - begin(d);
  d = Depth(g, u);
  int v = max_element(begin(d), end(d)) - begin(d);
  return make_pair(make_pair(u, v), d[v]);
}

// nodes on the path u-v ( O(N) )
template <typename G>
vector<int> Path(G &g, int u, int v) {
  vi ret;
  int end = 0;
  auto dfs = [&](auto rec, int cur, int par = -1) -> void {
    ret.push_back(cur);
    if (cur == v) {
      end = 1;
      return;
    }
    for (int dst : g[cur]) {
      if (dst == par) continue;
      rec(rec, dst, cur);
      if (end) return;
    }
    if (end) return;
    ret.pop_back();
  };
  dfs(dfs, u);
  return ret;
}
#line 6 "shortest-path/restore-shortest-path.hpp"

// restore shortest path from S to G
template <typename T>
vector<int> restore_shortest_path(WeightedGraph<T> &g, vector<T> &d, int S,
                                  int G) {
  int N = g.size();
  WeightedGraph<T> rev(g.size());
  for (int i = 0; i < N; i++)
    for (auto &e : g[i]) rev[e.to].emplace_back(e.to, i, e.cost);
  vector<int> ret;
  ret.push_back(G);
  int p = G;
  T dist = d[G];
  vector<int> vis(N, 0);
  vis[G] = 1;
  do {
    int nxt = -1;
    T nval = numeric_limits<T>::max() / 2;
    for (auto &e : rev[p]) {
      if (vis[e.to] || d[e.to] + e.cost != dist) continue;
      if (d[e.to] < nval) nval = d[e.to], nxt = e.to;
    }
    ret.push_back((vis[nxt] = 1, dist = nval, p = nxt));
  } while (p != S);
  reverse(begin(ret), end(ret));
  return ret;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

