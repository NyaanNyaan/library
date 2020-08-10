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


# :heavy_check_mark: graph/graph-template.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/graph-template.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 11:29:32+09:00




## Required by

* :warning: <a href="dimension-expanded-graph.hpp.html">graph/dimension-expanded-graph.hpp</a>
* :heavy_check_mark: <a href="graph-utility.hpp.html">graph/graph-utility.hpp</a>
* :heavy_check_mark: <a href="kruskal.hpp.html">graph/kruskal.hpp</a>
* :heavy_check_mark: <a href="lowlink.hpp.html">graph/lowlink.hpp</a>
* :heavy_check_mark: <a href="strongly-connected-components.hpp.html">graph/strongly-connected-components.hpp</a>
* :heavy_check_mark: <a href="topological-sort.hpp.html">graph/topological-sort.hpp</a>
* :warning: <a href="../math/grundy-number.hpp.html">math/grundy-number.hpp</a>
* :heavy_check_mark: <a href="../shortest-path/bellman-ford.hpp.html">shortest-path/bellman-ford.hpp</a>
* :heavy_check_mark: <a href="../shortest-path/dijkstra.hpp.html">shortest-path/dijkstra.hpp</a>
* :heavy_check_mark: <a href="../shortest-path/restore-shortest-path.hpp.html">shortest-path/restore-shortest-path.hpp</a>
* :heavy_check_mark: <a href="../shortest-path/warshall-floyd.hpp.html">shortest-path/warshall-floyd.hpp</a>
* :heavy_check_mark: <a href="../tree/cartesian-tree.hpp.html">tree/cartesian-tree.hpp</a>
* :warning: <a href="../tree/dsu-on-tree.hpp.html">tree/dsu-on-tree.hpp</a>
* :warning: <a href="../tree/euler-tour.hpp.html">tree/euler-tour.hpp</a>
* :heavy_check_mark: <a href="../tree/heavy-light-decomposition.hpp.html">tree/heavy-light-decomposition.hpp</a>
* :heavy_check_mark: <a href="../tree/rerooting.hpp.html">tree/rerooting.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-aoj-dsl/aoj-dsl-3-d-cartesiantree.test.cpp.html">verify/verify-aoj-dsl/aoj-dsl-3-d-cartesiantree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-aoj-grl/aoj-grl-1-a.test.cpp.html">verify/verify-aoj-grl/aoj-grl-1-a.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-aoj-grl/aoj-grl-1-b.test.cpp.html">verify/verify-aoj-grl/aoj-grl-1-b.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-aoj-grl/aoj-grl-1-c.test.cpp.html">verify/verify-aoj-grl/aoj-grl-1-c.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-aoj-grl/aoj-grl-2-a.test.cpp.html">verify/verify-aoj-grl/aoj-grl-2-a.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-aoj-grl/aoj-grl-3-a.test.cpp.html">verify/verify-aoj-grl/aoj-grl-3-a.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-aoj-grl/aoj-grl-3-b.test.cpp.html">verify/verify-aoj-grl/aoj-grl-3-b.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-aoj-grl/aoj-grl-3-c.test.cpp.html">verify/verify-aoj-grl/aoj-grl-3-c.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-aoj-grl/aoj-grl-4-a.test.cpp.html">verify/verify-aoj-grl/aoj-grl-4-a.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-aoj-grl/aoj-grl-4-b.test.cpp.html">verify/verify-aoj-grl/aoj-grl-4-b.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-aoj-grl/aoj-grl-5-a-rerooting.test.cpp.html">verify/verify-aoj-grl/aoj-grl-5-a-rerooting.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-aoj-grl/aoj-grl-5-a.test.cpp.html">verify/verify-aoj-grl/aoj-grl-5-a.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-aoj-grl/aoj-grl-5-b.test.cpp.html">verify/verify-aoj-grl/aoj-grl-5-b.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-aoj-grl/aoj-grl-5-c.test.cpp.html">verify/verify-aoj-grl/aoj-grl-5-c.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-aoj-grl/aoj-grl-5-d.test.cpp.html">verify/verify-aoj-grl/aoj-grl-5-d.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-aoj-grl/aoj-grl-5-e.test.cpp.html">verify/verify-aoj-grl/aoj-grl-5-e.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-ds/yosupo-vertex-add-path-sum.test.cpp.html">verify/verify-yosupo-ds/yosupo-vertex-add-path-sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum.test.cpp.html">verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp.html">verify/verify-yosupo-ds/yosupo-vertex-set-path-composite.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-graph/yosupo-cartesian.test.cpp.html">verify/verify-yosupo-graph/yosupo-cartesian.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-graph/yosupo-diameter.test.cpp.html">verify/verify-yosupo-graph/yosupo-diameter.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-graph/yosupo-frequency-table-of-tree-distance.test.cpp.html">verify/verify-yosupo-graph/yosupo-frequency-table-of-tree-distance.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-graph/yosupo-lowest-common-ancestor.test.cpp.html">verify/verify-yosupo-graph/yosupo-lowest-common-ancestor.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-graph/yosupo-shortest-path.test.cpp.html">verify/verify-yosupo-graph/yosupo-shortest-path.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-graph/yosupo-strongly-connected-components.test.cpp.html">verify/verify-yosupo-graph/yosupo-strongly-connected-components.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
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
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graph/graph-template.hpp"
#include <bits/stdc++.h>
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

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

