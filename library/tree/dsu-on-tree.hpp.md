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


# :warning: tree/dsu-on-tree.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/dsu-on-tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 11:29:32+09:00




## Depends on

* :question: <a href="../graph/graph-template.hpp.html">graph/graph-template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../graph/graph-template.hpp"

template <typename G, typename UPDATE, typename QUERY, typename CLEAR,
          typename RESET>
struct DSUonTree {
  G &g;
  int N;
  vector<int> sub_sz, euler, li, ri;
  int idx;
  UPDATE &update;
  QUERY &query;
  CLEAR &clear;
  RESET &reset;

  DSUonTree(G &_g, UPDATE &_update, QUERY &_query, CLEAR &_clear, RESET &_reset)
      : g(_g),
        N(_g.size()),
        sub_sz(_g.size()),
        euler(_g.size()),
        li(_g.size()),
        ri(_g.size()),
        idx(0),
        update(_update),
        query(_query),
        clear(_clear),
        reset(_reset) {
    dfs1();
    dfs2();
  }

  int dfs1(int cur = 0, int par = -1) {
    sub_sz[cur] = 1;
    if ((int)g[cur].size() >= 2 and g[cur][0] == par) {
      swap(g[cur][0], g[cur][1]);
    }
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      sub_sz[cur] += dfs1(dst, cur);
      if (sub_sz[dst] > sub_sz[g[cur][0]]) swap(dst, g[cur][0]);
    }
    return sub_sz[cur];
  }

  void dfs2(int cur = 0, int par = -1) {
    euler[idx] = cur;
    li[cur] = idx++;
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      dfs2(dst, cur);
    }
    ri[cur] = idx;
  }

  void dsu(int cur = 0, int par = -1, int keep = 1) {
    // light edge -> run dfs and clear data
    for (int i = 1; i < (int)g[cur].size(); i++)
      if (g[cur][i] != par) dsu(g[cur][i], cur, false);

    // heavy edge -> run dfs and reserve data
    if (sub_sz[cur] != 1) dsu(g[cur][0], cur, true);

    // light edge -> reserve data
    if (sub_sz[cur] != 1)
      for (int i = ri[g[cur][0]]; i < ri[cur]; i++) update(euler[i]);

    // current node -> reserve data
    update(cur);

    // answer queries related to subtree of current node
    query(cur);

    // if keep is false, clear all data
    if (!keep) {
      for (int i = li[cur]; i < ri[cur]; i++) clear(euler[i]);
      reset();
    }
    return;
  }

  void run() { dsu(); }
};

/*
  // reflect data of node i
  auto update = [&](int i) {

  };
  // answer queries of subtree i
  auto query = [&](int i) {

  };
  // below two function are called if all data must be deleted
  // delete data of node i (if necesarry)
  auto clear = [&](int i) {

  };
  // delete data related to all (if necesarry)
  auto reset = [&]() {

  };
  DSUonTree<decltype(g), decltype(update), decltype(query), decltype(clear),
            decltype(reset)>
      dsu(g, update, query, clear, reset);
  dsu.run();
*/
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "tree/dsu-on-tree.hpp"
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
#line 6 "tree/dsu-on-tree.hpp"

template <typename G, typename UPDATE, typename QUERY, typename CLEAR,
          typename RESET>
struct DSUonTree {
  G &g;
  int N;
  vector<int> sub_sz, euler, li, ri;
  int idx;
  UPDATE &update;
  QUERY &query;
  CLEAR &clear;
  RESET &reset;

  DSUonTree(G &_g, UPDATE &_update, QUERY &_query, CLEAR &_clear, RESET &_reset)
      : g(_g),
        N(_g.size()),
        sub_sz(_g.size()),
        euler(_g.size()),
        li(_g.size()),
        ri(_g.size()),
        idx(0),
        update(_update),
        query(_query),
        clear(_clear),
        reset(_reset) {
    dfs1();
    dfs2();
  }

  int dfs1(int cur = 0, int par = -1) {
    sub_sz[cur] = 1;
    if ((int)g[cur].size() >= 2 and g[cur][0] == par) {
      swap(g[cur][0], g[cur][1]);
    }
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      sub_sz[cur] += dfs1(dst, cur);
      if (sub_sz[dst] > sub_sz[g[cur][0]]) swap(dst, g[cur][0]);
    }
    return sub_sz[cur];
  }

  void dfs2(int cur = 0, int par = -1) {
    euler[idx] = cur;
    li[cur] = idx++;
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      dfs2(dst, cur);
    }
    ri[cur] = idx;
  }

  void dsu(int cur = 0, int par = -1, int keep = 1) {
    // light edge -> run dfs and clear data
    for (int i = 1; i < (int)g[cur].size(); i++)
      if (g[cur][i] != par) dsu(g[cur][i], cur, false);

    // heavy edge -> run dfs and reserve data
    if (sub_sz[cur] != 1) dsu(g[cur][0], cur, true);

    // light edge -> reserve data
    if (sub_sz[cur] != 1)
      for (int i = ri[g[cur][0]]; i < ri[cur]; i++) update(euler[i]);

    // current node -> reserve data
    update(cur);

    // answer queries related to subtree of current node
    query(cur);

    // if keep is false, clear all data
    if (!keep) {
      for (int i = li[cur]; i < ri[cur]; i++) clear(euler[i]);
      reset();
    }
    return;
  }

  void run() { dsu(); }
};

/*
  // reflect data of node i
  auto update = [&](int i) {

  };
  // answer queries of subtree i
  auto query = [&](int i) {

  };
  // below two function are called if all data must be deleted
  // delete data of node i (if necesarry)
  auto clear = [&](int i) {

  };
  // delete data related to all (if necesarry)
  auto reset = [&]() {

  };
  DSUonTree<decltype(g), decltype(update), decltype(query), decltype(clear),
            decltype(reset)>
      dsu(g, update, query, clear, reset);
  dsu.run();
*/

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

