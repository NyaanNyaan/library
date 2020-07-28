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


# :warning: tree/euler-tour.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/euler-tour.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 11:29:32+09:00




## Depends on

* :heavy_check_mark: <a href="../graph/graph-template.hpp.html">graph/graph-template.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../graph/graph-template.hpp"

// ** NOT RECOMMEND TO USE **
// euler tour of node 
struct EulerTour {
  struct UnionFind {
    vector<int> data;
    UnionFind(int N) : data(N, -1) {}

    int find(int k) { return data[k] < 0 ? k : data[k] = find(data[k]); }

    int unite(int x, int y) {
      if ((x = find(x)) == (y = find(y))) return false;
      if (data[x] > data[y]) swap(x, y);
      data[x] += data[y];
      data[y] = x;
      return true;
    }

    int size(int k) { return -data[find(k)]; }

    int same(int x, int y) { return find(x) == find(y); }
  };

  struct SegmentTree_RangeMin {
    int size;
    using P = pair<int, int>;
    vector<P> seg;
    P UNIT = P(1 << 30, -1);

    SegmentTree_RangeMin() {}

    SegmentTree_RangeMin(int N) {
      size = 1;
      while (size < N) size <<= 1;
      seg.assign(2 * size, UNIT);
    }

    void set(int k, P x) { seg[k + size] = x; }

    void build() {
      for (int k = size - 1; k > 0; k--) {
        seg[k] = min(seg[2 * k], seg[2 * k + 1]);
      }
    }

    // query to [a, b)
    P query(int a, int b) {
      P L = UNIT, R = UNIT;
      for (a += size, b += size; a < b; a >>= 1, b >>= 1) {
        if (a & 1) L = min(L, seg[a++]);
        if (b & 1) R = min(seg[--b], R);
      }
      return min(L, R);
    }
  };

  using G = vector<vector<int>>;

  UnionFind uf;
  vector<int> down, up, tour, par, depth;
  int i_;
  SegmentTree_RangeMin lca_seg;

  EulerTour(G &g)
      : uf(g.size()),
        down(g.size(), -1),
        up(g.size()),
        tour(g.size() * 2),
        par(g.size()),
        depth(g.size(), -1),
        i_(0),
        lca_seg(2 * g.size()) {
    vector<int> isroot(g.size(), 1);
    for (int i = 0; i < (int)g.size(); i++) {
      for (auto &d : g[i]) isroot[d] = 0;
    }
    for (int i = 0; i < (int)g.size(); i++) {
      if (!isroot[i]) continue;
      dfs(g, i, -1);
    }
    lca_seg.build();
  }

  void dfs(G &g, int c, int p) {
    down[c] = i_;
    par[c] = p;
    depth[c] = ~p ? depth[p] + 1 : 0;
    lca_seg.set(i_, {depth[c], c});
    tour[i_++] = c;
    if (~p) uf.unite(c, p);
    for (auto &d : g[c]) {
      if (d == p) continue;
      dfs(g, d, c);
    }
    up[c] = i_;
    if (~p) lca_seg.set(i_, {depth[p], p});
    tour[i_++] = c;
  }

  int lca(int a, int b) {
    if (!uf.same(a, b)) return -1;
    if (down[a] > down[b]) swap(a, b);
    return lca_seg.query(down[a], down[b] + 1).second;
  }

  template <typename F>
  void node_query(int a, int b, F &f) {
    int l = lca(a, b);
    assert(l != -1);
    f(down[l], down[a] + 1);
    f(down[l] + 1, down[b] + 1);
  }

  template <typename F>
  void edge_query(int a, int b, F &f) {
    int l = lca(a, b);
    assert(l != -1);
    f(down[l] + 1, down[a] + 1);
    f(down[l] + 1, down[b] + 1);
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "tree/euler-tour.hpp"
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
#line 6 "tree/euler-tour.hpp"

// ** NOT RECOMMEND TO USE **
// euler tour of node 
struct EulerTour {
  struct UnionFind {
    vector<int> data;
    UnionFind(int N) : data(N, -1) {}

    int find(int k) { return data[k] < 0 ? k : data[k] = find(data[k]); }

    int unite(int x, int y) {
      if ((x = find(x)) == (y = find(y))) return false;
      if (data[x] > data[y]) swap(x, y);
      data[x] += data[y];
      data[y] = x;
      return true;
    }

    int size(int k) { return -data[find(k)]; }

    int same(int x, int y) { return find(x) == find(y); }
  };

  struct SegmentTree_RangeMin {
    int size;
    using P = pair<int, int>;
    vector<P> seg;
    P UNIT = P(1 << 30, -1);

    SegmentTree_RangeMin() {}

    SegmentTree_RangeMin(int N) {
      size = 1;
      while (size < N) size <<= 1;
      seg.assign(2 * size, UNIT);
    }

    void set(int k, P x) { seg[k + size] = x; }

    void build() {
      for (int k = size - 1; k > 0; k--) {
        seg[k] = min(seg[2 * k], seg[2 * k + 1]);
      }
    }

    // query to [a, b)
    P query(int a, int b) {
      P L = UNIT, R = UNIT;
      for (a += size, b += size; a < b; a >>= 1, b >>= 1) {
        if (a & 1) L = min(L, seg[a++]);
        if (b & 1) R = min(seg[--b], R);
      }
      return min(L, R);
    }
  };

  using G = vector<vector<int>>;

  UnionFind uf;
  vector<int> down, up, tour, par, depth;
  int i_;
  SegmentTree_RangeMin lca_seg;

  EulerTour(G &g)
      : uf(g.size()),
        down(g.size(), -1),
        up(g.size()),
        tour(g.size() * 2),
        par(g.size()),
        depth(g.size(), -1),
        i_(0),
        lca_seg(2 * g.size()) {
    vector<int> isroot(g.size(), 1);
    for (int i = 0; i < (int)g.size(); i++) {
      for (auto &d : g[i]) isroot[d] = 0;
    }
    for (int i = 0; i < (int)g.size(); i++) {
      if (!isroot[i]) continue;
      dfs(g, i, -1);
    }
    lca_seg.build();
  }

  void dfs(G &g, int c, int p) {
    down[c] = i_;
    par[c] = p;
    depth[c] = ~p ? depth[p] + 1 : 0;
    lca_seg.set(i_, {depth[c], c});
    tour[i_++] = c;
    if (~p) uf.unite(c, p);
    for (auto &d : g[c]) {
      if (d == p) continue;
      dfs(g, d, c);
    }
    up[c] = i_;
    if (~p) lca_seg.set(i_, {depth[p], p});
    tour[i_++] = c;
  }

  int lca(int a, int b) {
    if (!uf.same(a, b)) return -1;
    if (down[a] > down[b]) swap(a, b);
    return lca_seg.query(down[a], down[b] + 1).second;
  }

  template <typename F>
  void node_query(int a, int b, F &f) {
    int l = lca(a, b);
    assert(l != -1);
    f(down[l], down[a] + 1);
    f(down[l] + 1, down[b] + 1);
  }

  template <typename F>
  void edge_query(int a, int b, F &f) {
    int l = lca(a, b);
    assert(l != -1);
    f(down[l] + 1, down[a] + 1);
    f(down[l] + 1, down[b] + 1);
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

