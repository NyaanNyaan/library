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


# :warning: graph/dimension-expanded-graph.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/dimension-expanded-graph.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 11:29:32+09:00




## Depends on

* :question: <a href="graph-template.hpp.html">graph/graph-template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "./graph-template.hpp"

template <int DIM>
struct DimensionExpandedGraph {
  using i64 = long long;
  using A = array<int, DIM>;

  int N;
  A g_size, coeff;

  template <typename... T>
  DimensionExpandedGraph(const T &... t) : N(1), g_size({t...}) {
    set_coeff();
  }

  void set_coeff() {
    coeff.fill(1);
    for (int i = 0; i < DIM; i++) {
      for (int j = 0; j < i; j++) coeff[j] *= g_size[i];
      N *= g_size[i];
    }
  }

  int id(const A &a) {
    int ret = 0;
    for (int i = 0; i < DIM; i++) ret += a[i] * coeff[i];
    return ret;
  }

  int id_(int, int n) { return n; }
  template <typename T, typename... U>
  int id_(int idx, int n, T &&t, U &&... u) {
    n += coeff[idx++] * t;
    return id_(idx, n, forward<U>(u)...);
  }
  template <typename... T>
  int id(const T &... t) {
    return id_(0, 0, t...);
  }

  int ok(const A &a) {
    for (int i = 0; i < DIM; i++)
      if (a[i] < 0 or g_size[i] <= a[i]) return 0;
    return 1;
  }

  int ok_(int) { return 1; }
  template <typename T, typename... U>
  int ok_(int idx, T &&t, U &&... u) {
    if (t < 0 or g_size[idx++] <= t) return 0;
    return ok_(idx, forward<U>(u)...);
  }
  template <typename... T>
  int ok(const T &... t) {
    return ok_(0, t...);
  }

  template <typename F>
  vector<i64> bfs(F f, A s = {}) {
    vector<i64> dist(N, -1);
    queue<A> Q;
    dist[id(s)] = 0;
    Q.push(s);
    while (!Q.empty()) {
      A c = Q.front();
      Q.pop();
      f(c, [&](A d) {
        if (dist[id(d)] == -1) {
          dist[id(d)] = dist[id(c)] + 1;
          Q.push(d);
        }
      });
    }
    return dist;
  }

  template <typename F>
  vector<i64> bfs01(F f, A s = {}) {
    vector<i64> dist(N, -1);
    deque<A> Q;
    dist[id(s)] = 0;
    Q.push_back(s);
    while (!Q.empty()) {
      A c = Q.front();
      Q.pop_front();
      f(c, [&](A d, i64 w) {
        if (dist[id(d)] == -1) {
          dist[id(d)] = dist[id(c)] + w;
          if (w == 0)
            Q.push_front(d);
          else
            Q.push_back(d);
        }
      });
    }
    return dist;
  }

  template <typename F>
  vector<i64> dijkstra(F f, A s = {}) {
    vector<i64> dist(N, -1);
    using P = pair<i64, A>;
    priority_queue<P, vector<P>, greater<P>> Q;
    Q.emplace(dist[id(s)] = 0, s);
    while (!Q.empty()) {
      i64 d;
      A c;
      tie(d, c) = Q.top();
      Q.pop();
      if (dist[id(c)] < d) continue;
      f(c, [&](A d, i64 w) {
        if (dist[id(d)] == -1 or dist[id(d)] > dist[id(c)] + w) {
          Q.emplace(dist[id(d)] = dist[id(c)] + w, d);
        }
      });
    }
    return dist;
  }
};

struct GridGraph : DimensionExpandedGraph<2> {
  vector<string> str;
  char ng;
  int is_8_direction;

  template <typename... T>
  GridGraph(const T &... t) : ng('#'), is_8_direction(false) {
    N = 1;
    g_size = A({t...});
    set_coeff();
  }

  operator vector<string> &() { return str; }

  template <typename F>
  void adjacent(pair<int,int> c, F f) {
    int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
    int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
    int i, j;
    tie(i, j) = c;
    for (int k = 0; k < is_8_direction ? 8 : 4; k++) {
      int di = i + dx[k], dj = dy[k];
      if (ok(di, dj) and str[di][dj] != ng) f(di, dj);
    }
  }

  template <typename F>
  vector<i64> bfs(F f, A s = {}){
    vector<i64> dist(N, -1);
    queue<A> Q;
    dist[id(s)] = 0;
    Q.push(s);
    while (!Q.empty()) {
      A c = Q.front();
      Q.pop();
      adjacent(c, [&](A d) {
        if (dist[id(d)] == -1) {
          dist[id(d)] = dist[id(c)] + 1;
          Q.push(d);
        }
      });
    }
    return dist;
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graph/dimension-expanded-graph.hpp"
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
#line 6 "graph/dimension-expanded-graph.hpp"

template <int DIM>
struct DimensionExpandedGraph {
  using i64 = long long;
  using A = array<int, DIM>;

  int N;
  A g_size, coeff;

  template <typename... T>
  DimensionExpandedGraph(const T &... t) : N(1), g_size({t...}) {
    set_coeff();
  }

  void set_coeff() {
    coeff.fill(1);
    for (int i = 0; i < DIM; i++) {
      for (int j = 0; j < i; j++) coeff[j] *= g_size[i];
      N *= g_size[i];
    }
  }

  int id(const A &a) {
    int ret = 0;
    for (int i = 0; i < DIM; i++) ret += a[i] * coeff[i];
    return ret;
  }

  int id_(int, int n) { return n; }
  template <typename T, typename... U>
  int id_(int idx, int n, T &&t, U &&... u) {
    n += coeff[idx++] * t;
    return id_(idx, n, forward<U>(u)...);
  }
  template <typename... T>
  int id(const T &... t) {
    return id_(0, 0, t...);
  }

  int ok(const A &a) {
    for (int i = 0; i < DIM; i++)
      if (a[i] < 0 or g_size[i] <= a[i]) return 0;
    return 1;
  }

  int ok_(int) { return 1; }
  template <typename T, typename... U>
  int ok_(int idx, T &&t, U &&... u) {
    if (t < 0 or g_size[idx++] <= t) return 0;
    return ok_(idx, forward<U>(u)...);
  }
  template <typename... T>
  int ok(const T &... t) {
    return ok_(0, t...);
  }

  template <typename F>
  vector<i64> bfs(F f, A s = {}) {
    vector<i64> dist(N, -1);
    queue<A> Q;
    dist[id(s)] = 0;
    Q.push(s);
    while (!Q.empty()) {
      A c = Q.front();
      Q.pop();
      f(c, [&](A d) {
        if (dist[id(d)] == -1) {
          dist[id(d)] = dist[id(c)] + 1;
          Q.push(d);
        }
      });
    }
    return dist;
  }

  template <typename F>
  vector<i64> bfs01(F f, A s = {}) {
    vector<i64> dist(N, -1);
    deque<A> Q;
    dist[id(s)] = 0;
    Q.push_back(s);
    while (!Q.empty()) {
      A c = Q.front();
      Q.pop_front();
      f(c, [&](A d, i64 w) {
        if (dist[id(d)] == -1) {
          dist[id(d)] = dist[id(c)] + w;
          if (w == 0)
            Q.push_front(d);
          else
            Q.push_back(d);
        }
      });
    }
    return dist;
  }

  template <typename F>
  vector<i64> dijkstra(F f, A s = {}) {
    vector<i64> dist(N, -1);
    using P = pair<i64, A>;
    priority_queue<P, vector<P>, greater<P>> Q;
    Q.emplace(dist[id(s)] = 0, s);
    while (!Q.empty()) {
      i64 d;
      A c;
      tie(d, c) = Q.top();
      Q.pop();
      if (dist[id(c)] < d) continue;
      f(c, [&](A d, i64 w) {
        if (dist[id(d)] == -1 or dist[id(d)] > dist[id(c)] + w) {
          Q.emplace(dist[id(d)] = dist[id(c)] + w, d);
        }
      });
    }
    return dist;
  }
};

struct GridGraph : DimensionExpandedGraph<2> {
  vector<string> str;
  char ng;
  int is_8_direction;

  template <typename... T>
  GridGraph(const T &... t) : ng('#'), is_8_direction(false) {
    N = 1;
    g_size = A({t...});
    set_coeff();
  }

  operator vector<string> &() { return str; }

  template <typename F>
  void adjacent(pair<int,int> c, F f) {
    int dx[] = {1, 0, -1, 0, 1, 1, -1, -1};
    int dy[] = {0, 1, 0, -1, 1, -1, 1, -1};
    int i, j;
    tie(i, j) = c;
    for (int k = 0; k < is_8_direction ? 8 : 4; k++) {
      int di = i + dx[k], dj = dy[k];
      if (ok(di, dj) and str[di][dj] != ng) f(di, dj);
    }
  }

  template <typename F>
  vector<i64> bfs(F f, A s = {}){
    vector<i64> dist(N, -1);
    queue<A> Q;
    dist[id(s)] = 0;
    Q.push(s);
    while (!Q.empty()) {
      A c = Q.front();
      Q.pop();
      adjacent(c, [&](A d) {
        if (dist[id(d)] == -1) {
          dist[id(d)] = dist[id(c)] + 1;
          Q.push(d);
        }
      });
    }
    return dist;
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

