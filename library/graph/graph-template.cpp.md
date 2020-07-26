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


# :heavy_check_mark: graph/graph-template.cpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/graph-template.cpp">View this file on GitHub</a>
    - Last commit date: 2020-07-26 22:43:08+09:00




## Depends on

* :heavy_check_mark: <a href="../competitive-template.cpp.html">competitive-template.cpp</a>


## Required by

* :heavy_check_mark: <a href="cartesian-tree.cpp.html">graph/cartesian-tree.cpp</a>
* :warning: <a href="dimension-expanded-graph.cpp.html">graph/dimension-expanded-graph.cpp</a>
* :warning: <a href="euler-tour.cpp.html">graph/euler-tour.cpp</a>
* :heavy_check_mark: <a href="heavy-light-decomposition.cpp.html">graph/heavy-light-decomposition.cpp</a>
* :heavy_check_mark: <a href="kruskal.cpp.html">graph/kruskal.cpp</a>
* :heavy_check_mark: <a href="lowlink.cpp.html">graph/lowlink.cpp</a>
* :heavy_check_mark: <a href="strongly-connected-components.cpp.html">graph/strongly-connected-components.cpp</a>
* :heavy_check_mark: <a href="topological-sort.cpp.html">graph/topological-sort.cpp</a>
* :heavy_check_mark: <a href="../shortest-path/bellman-ford.cpp.html">shortest-path/bellman-ford.cpp</a>
* :heavy_check_mark: <a href="../shortest-path/dijkstra.cpp.html">shortest-path/dijkstra.cpp</a>
* :heavy_check_mark: <a href="../shortest-path/warshall-floyd.cpp.html">shortest-path/warshall-floyd.cpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify-aoj-dsl/aoj-dsl-3-d-cartesiantree.test.cpp.html">verify-aoj-dsl/aoj-dsl-3-d-cartesiantree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify-aoj-grl/aoj-grl-1-a.test.cpp.html">verify-aoj-grl/aoj-grl-1-a.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify-aoj-grl/aoj-grl-1-b.test.cpp.html">verify-aoj-grl/aoj-grl-1-b.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify-aoj-grl/aoj-grl-1-c.test.cpp.html">verify-aoj-grl/aoj-grl-1-c.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify-aoj-grl/aoj-grl-2-a.test.cpp.html">verify-aoj-grl/aoj-grl-2-a.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify-aoj-grl/aoj-grl-3-a.test.cpp.html">verify-aoj-grl/aoj-grl-3-a.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify-aoj-grl/aoj-grl-3-b.test.cpp.html">verify-aoj-grl/aoj-grl-3-b.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify-aoj-grl/aoj-grl-3-c.test.cpp.html">verify-aoj-grl/aoj-grl-3-c.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify-aoj-grl/aoj-grl-4-a.test.cpp.html">verify-aoj-grl/aoj-grl-4-a.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify-aoj-grl/aoj-grl-4-b.test.cpp.html">verify-aoj-grl/aoj-grl-4-b.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

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
    g[x].pb(y);
    if (!is_directed) g[y].pb(x);
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
Edges<T> esgraph(int N, int M, int is_weighted = true,
                         bool is_1origin = true) {
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

// Depth of Rooted Tree
// unvisited nodes : d = -1
vector<int> Depth(UnweightedGraph &g, int start = 0) {
  vector<int> d(g.size(), -1);
  auto dfs = [&](auto rec, int cur, int par = -1) -> void {
    d[cur] = par == -1 ? 0 : d[par] + 1;
    each(dst, g[cur]) {
      if (dst == par) continue;
      rec(rec, dst, cur);
    }
  };
  dfs(dfs, start);
  return d;
}

// Diameter of Tree
pair<int, int> Diameter(UnweightedGraph &g, int start = 0) {
  auto d = Depth(g, start);
  int u = max_element(begin(d), end(d)) - begin(d);
  d = Depth(g, u);
  int v = max_element(begin(d), end(d)) - begin(d);
  return make_pair(u, v);
}

template <typename G>
vector<int> path(G &g, int u, int v) {
  vi ret;
  int end = 0;
  auto dfs = [&](auto rec, int cur, int par = -1) -> void {
    ret.pb(cur);
    if (cur == v) {
      end = 1;
      return;
    }
    each(dst, g[cur]) {
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.3/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 306, in update
    raise BundleErrorAt(path, i + 1, "unable to process #include in #if / #ifdef / #ifndef other than include guards")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/graph-template.cpp: line 3: unable to process #include in #if / #ifdef / #ifndef other than include guards

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

