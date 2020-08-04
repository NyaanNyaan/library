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


# :heavy_check_mark: tree/heavy-light-decomposition.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/heavy-light-decomposition.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-05 01:07:13+09:00




## Depends on

* :heavy_check_mark: <a href="../graph/graph-template.hpp.html">graph/graph-template.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-aoj-dsl/aoj-dsl-3-d-cartesiantree.test.cpp.html">verify/verify-aoj-dsl/aoj-dsl-3-d-cartesiantree.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-aoj-grl/aoj-grl-5-c.test.cpp.html">verify/verify-aoj-grl/aoj-grl-5-c.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-aoj-grl/aoj-grl-5-d.test.cpp.html">verify/verify-aoj-grl/aoj-grl-5-d.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-aoj-grl/aoj-grl-5-e.test.cpp.html">verify/verify-aoj-grl/aoj-grl-5-e.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-ds/yosupo-vertex-add-path-sum.test.cpp.html">verify/verify-yosupo-ds/yosupo-vertex-add-path-sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum.test.cpp.html">verify/verify-yosupo-ds/yosupo-vertex-add-subtree-sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-graph/yosupo-lowest-common-ancestor.test.cpp.html">verify/verify-yosupo-graph/yosupo-lowest-common-ancestor.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../graph/graph-template.hpp"

template <typename G>
struct HeavyLightDecomposition {
  G& g;
  int idx;
  vector<int> size, depth, in, out, nxt, par;
  HeavyLightDecomposition(G& g, int root = 0)
      : g(g),
        idx(0),
        size(g.size(), 0),
        depth(g.size(), 0),
        in(g.size(), -1),
        out(g.size(), -1),
        nxt(g.size(), root),
        par(g.size(), root) {
    dfs_sz(root);
    dfs_hld(root);
  }

  void build(int root) {
    dfs_sz(root);
    dfs_hld(root);
  }

  void dfs_sz(int cur) {
    size[cur] = 1;
    for (auto& dst : g[cur]) {
      if (dst == par[cur]) {
        if (g[cur].size() >= 2 && int(dst) == int(g[cur][0]))
          swap(g[cur][0], g[cur][1]);
        else
          continue;
      }
      depth[dst] = depth[cur] + 1;
      par[dst] = cur;
      dfs_sz(dst);
      size[cur] += size[dst];
      if (size[dst] > size[g[cur][0]]) {
        swap(dst, g[cur][0]);
      }
    }
  }

  void dfs_hld(int cur) {
    in[cur] = idx++;
    for (auto dst : g[cur]) {
      if (dst == par[cur]) continue;
      nxt[dst] = (int(dst) == int(g[cur][0]) ? nxt[cur] : int(dst));
      dfs_hld(dst);
    }
    out[cur] = idx;
  }

  template <typename F>
  void edge_query(int u, int v, const F& f) {
    while (1) {
      if (in[u] > in[v]) swap(u, v);
      if (nxt[u] != nxt[v]) {
        f(in[nxt[v]], in[v] + 1);
        v = par[nxt[v]];
      } else {
        if (u != v) f(in[u] + 1, in[v] + 1);
        break;
      }
    }
  }

  /*
  // 非可換 monoid query 未verify
  template <typename F>
  void uncommutable_edge_query(int u, int v, const F& f) {
    while (1) {
      if (nxt[u] != nxt[v]) {
        if (in[u] > in[v]) {
          f(in[u], in[nxt[u]] + 1, true);
          u = par[nxt[u]];
        } else {
          f(in[nxt[v]], in[v] + 1, false);
          v = par[nxt[v]];
        }
      } else {
        if (u != v) f(in[u] + 1, in[v] + 1);
        break;
      }
    }
  }
  */

  template <typename F>
  void node_query(int u, int v, const F& f) {
    while (1) {
      if (in[u] > in[v]) swap(u, v);
      if (nxt[u] != nxt[v]) {
        f(in[nxt[v]], in[v] + 1);
        v = par[nxt[v]];
      } else {
        f(in[u], in[v] + 1);
        break;
      }
    }
  }

  // 非可換 monoid query 未verify
  template <typename F>
  void uncommutable_node_query(int u, int v, const F& f) {
    while (1) {
      if (nxt[u] != nxt[v]) {
        if (in[u] > in[v]) {
          f(in[u], in[nxt[u]] + 1, true);
          u = par[nxt[u]];
        } else {
          f(in[nxt[v]], in[v] + 1, false);
          v = par[nxt[v]];
        }
      } else {
        f(in[u], in[v] + 1, true);
        break;
      }
    }
  }

  template <typename F>
  void sub_edge_query(int u, const F& f) {
    f(in[u] + 1, out[u]);
  }

  template <typename F>
  void sub_node_query(int u, const F& f) {
    f(in[u], out[u]);
  }

  int lca(int a, int b) {
    while (nxt[a] != nxt[b]) {
      if (in[a] < in[b]) swap(a, b);
      a = par[nxt[a]];
    }
    return depth[a] < depth[b] ? a : b;
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "tree/heavy-light-decomposition.hpp"
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
#line 6 "tree/heavy-light-decomposition.hpp"

template <typename G>
struct HeavyLightDecomposition {
  G& g;
  int idx;
  vector<int> size, depth, in, out, nxt, par;
  HeavyLightDecomposition(G& g, int root = 0)
      : g(g),
        idx(0),
        size(g.size(), 0),
        depth(g.size(), 0),
        in(g.size(), -1),
        out(g.size(), -1),
        nxt(g.size(), root),
        par(g.size(), root) {
    dfs_sz(root);
    dfs_hld(root);
  }

  void build(int root) {
    dfs_sz(root);
    dfs_hld(root);
  }

  void dfs_sz(int cur) {
    size[cur] = 1;
    for (auto& dst : g[cur]) {
      if (dst == par[cur]) {
        if (g[cur].size() >= 2 && int(dst) == int(g[cur][0]))
          swap(g[cur][0], g[cur][1]);
        else
          continue;
      }
      depth[dst] = depth[cur] + 1;
      par[dst] = cur;
      dfs_sz(dst);
      size[cur] += size[dst];
      if (size[dst] > size[g[cur][0]]) {
        swap(dst, g[cur][0]);
      }
    }
  }

  void dfs_hld(int cur) {
    in[cur] = idx++;
    for (auto dst : g[cur]) {
      if (dst == par[cur]) continue;
      nxt[dst] = (int(dst) == int(g[cur][0]) ? nxt[cur] : int(dst));
      dfs_hld(dst);
    }
    out[cur] = idx;
  }

  template <typename F>
  void edge_query(int u, int v, const F& f) {
    while (1) {
      if (in[u] > in[v]) swap(u, v);
      if (nxt[u] != nxt[v]) {
        f(in[nxt[v]], in[v] + 1);
        v = par[nxt[v]];
      } else {
        if (u != v) f(in[u] + 1, in[v] + 1);
        break;
      }
    }
  }

  /*
  // 非可換 monoid query 未verify
  template <typename F>
  void uncommutable_edge_query(int u, int v, const F& f) {
    while (1) {
      if (nxt[u] != nxt[v]) {
        if (in[u] > in[v]) {
          f(in[u], in[nxt[u]] + 1, true);
          u = par[nxt[u]];
        } else {
          f(in[nxt[v]], in[v] + 1, false);
          v = par[nxt[v]];
        }
      } else {
        if (u != v) f(in[u] + 1, in[v] + 1);
        break;
      }
    }
  }
  */

  template <typename F>
  void node_query(int u, int v, const F& f) {
    while (1) {
      if (in[u] > in[v]) swap(u, v);
      if (nxt[u] != nxt[v]) {
        f(in[nxt[v]], in[v] + 1);
        v = par[nxt[v]];
      } else {
        f(in[u], in[v] + 1);
        break;
      }
    }
  }

  // 非可換 monoid query 未verify
  template <typename F>
  void uncommutable_node_query(int u, int v, const F& f) {
    while (1) {
      if (nxt[u] != nxt[v]) {
        if (in[u] > in[v]) {
          f(in[u], in[nxt[u]] + 1, true);
          u = par[nxt[u]];
        } else {
          f(in[nxt[v]], in[v] + 1, false);
          v = par[nxt[v]];
        }
      } else {
        f(in[u], in[v] + 1, true);
        break;
      }
    }
  }

  template <typename F>
  void sub_edge_query(int u, const F& f) {
    f(in[u] + 1, out[u]);
  }

  template <typename F>
  void sub_node_query(int u, const F& f) {
    f(in[u], out[u]);
  }

  int lca(int a, int b) {
    while (nxt[a] != nxt[b]) {
      if (in[a] < in[b]) swap(a, b);
      a = par[nxt[a]];
    }
    return depth[a] < depth[b] ? a : b;
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

