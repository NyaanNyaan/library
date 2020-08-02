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


# :heavy_check_mark: shortest-path/dijkstra.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#d53d0f39583bbf03056486512d3e44bc">shortest-path</a>
* <a href="{{ site.github.repository_url }}/blob/master/shortest-path/dijkstra.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 11:29:32+09:00




## Depends on

* :heavy_check_mark: <a href="../graph/graph-template.hpp.html">graph/graph-template.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-aoj-grl/aoj-grl-1-a.test.cpp.html">verify/verify-aoj-grl/aoj-grl-1-a.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-graph/yosupo-shortest-path.test.cpp.html">verify/verify-yosupo-graph/yosupo-shortest-path.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../graph/graph-template.hpp"

// unreachable -> -1 
template<typename T>
vector<T> dijkstra(WeightedGraph<T> &g, int start = 0){ 
  using P = pair<T , int>;
  int N = (int)g.size();
  T INF = numeric_limits<T>::max() / 2;
  vector<T> d(N , INF);
  priority_queue<P , vector<P> , greater<P> > Q;
  d[start] = 0;
  Q.emplace(0 , start);
  while(!Q.empty()){
    P p = Q.top(); Q.pop();
    int cur = p.second;
    if(d[cur] < p.first) continue;
    for(auto dst : g[cur]){
      if( d[cur] + dst.cost < d[dst]){
        d[dst] = d[cur] + dst.cost;
        Q.emplace(d[dst] , dst);
      }
    }
  }
  return d;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "shortest-path/dijkstra.hpp"
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
#line 6 "shortest-path/dijkstra.hpp"

// unreachable -> -1 
template<typename T>
vector<T> dijkstra(WeightedGraph<T> &g, int start = 0){ 
  using P = pair<T , int>;
  int N = (int)g.size();
  T INF = numeric_limits<T>::max() / 2;
  vector<T> d(N , INF);
  priority_queue<P , vector<P> , greater<P> > Q;
  d[start] = 0;
  Q.emplace(0 , start);
  while(!Q.empty()){
    P p = Q.top(); Q.pop();
    int cur = p.second;
    if(d[cur] < p.first) continue;
    for(auto dst : g[cur]){
      if( d[cur] + dst.cost < d[dst]){
        d[dst] = d[cur] + dst.cost;
        Q.emplace(d[dst] , dst);
      }
    }
  }
  return d;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

