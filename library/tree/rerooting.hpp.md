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


# :heavy_check_mark: tree/rerooting.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/rerooting.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 11:29:32+09:00




## Depends on

* :question: <a href="../graph/graph-template.hpp.html">graph/graph-template.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify-aoj-grl/aoj-grl-5-a-rerooting.test.cpp.html">verify-aoj-grl/aoj-grl-5-a-rerooting.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify-aoj-grl/aoj-grl-5-b.test.cpp.html">verify-aoj-grl/aoj-grl-5-b.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../graph/graph-template.hpp"

// Rerooting
// f1(c1, c2) ... merge value of child node
// f2(memo[i], chd, par) ... return value from child node to parent node
// memo[i] ... result of subtree rooted i
// dp[i] ... result of tree rooted i
template <typename T, typename G, typename F1, typename F2>
struct Rerooting {
  const G &g;
  const F1 f1;
  const F2 f2;
  vector<T> memo, dp;
  T I;

  Rerooting(const G &g, const F1 f1, const F2 f2, const T &I)
      : g(g), f1(f1), f2(f2), memo(g.size(), I), dp(g.size(), I), I(I) {
    dfs(0, -1);
    efs(0, -1, I);
  }

  const T &operator[](int i) const { return dp[i]; }

  void dfs(int cur, int par) {
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      dfs(dst, cur);
      memo[cur] = f1(memo[cur], f2(memo[dst], dst, cur));
    }
  }

  void efs(int cur, int par, const T &pval) {
    // get cumulative sum
    vector<T> buf;
    for (auto dst : g[cur]) {
      if (dst == par) continue;
      buf.push_back(f2(memo[dst], dst, cur));
    }
    vector<T> head(buf.size() + 1), tail(buf.size() + 1);
    head[0] = tail[buf.size()] = I;
    for (int i = 0; i < (int)buf.size(); i++) head[i + 1] = f1(head[i], buf[i]);
    for (int i = (int)buf.size() - 1; i >= 0; i--)
      tail[i] = f1(tail[i + 1], buf[i]);

    // update
    dp[cur] = par == -1 ? head.back() : f1(pval, head.back());

    // propagate
    int idx = 0;
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      efs(dst, cur, f2(f1(pval, f1(head[idx], tail[idx + 1])), cur, dst));
      idx++;
    }
  }
};

/*

using T = ;
// identify element of f1, and answer of leaf
T I = ;
// merge value of child node
auto f1 = [&](T x, T y) -> T {

};
// return value from child node to parent node
auto f2 = [&](T x, int chd, int par) -> T {

};
Rerooting<T, decltype(g), decltype(f1), decltype(f2)> dp(g, f1, f2, I);

*/
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "tree/rerooting.hpp"
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
#line 6 "tree/rerooting.hpp"

// Rerooting
// f1(c1, c2) ... merge value of child node
// f2(memo[i], chd, par) ... return value from child node to parent node
// memo[i] ... result of subtree rooted i
// dp[i] ... result of tree rooted i
template <typename T, typename G, typename F1, typename F2>
struct Rerooting {
  const G &g;
  const F1 f1;
  const F2 f2;
  vector<T> memo, dp;
  T I;

  Rerooting(const G &g, const F1 f1, const F2 f2, const T &I)
      : g(g), f1(f1), f2(f2), memo(g.size(), I), dp(g.size(), I), I(I) {
    dfs(0, -1);
    efs(0, -1, I);
  }

  const T &operator[](int i) const { return dp[i]; }

  void dfs(int cur, int par) {
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      dfs(dst, cur);
      memo[cur] = f1(memo[cur], f2(memo[dst], dst, cur));
    }
  }

  void efs(int cur, int par, const T &pval) {
    // get cumulative sum
    vector<T> buf;
    for (auto dst : g[cur]) {
      if (dst == par) continue;
      buf.push_back(f2(memo[dst], dst, cur));
    }
    vector<T> head(buf.size() + 1), tail(buf.size() + 1);
    head[0] = tail[buf.size()] = I;
    for (int i = 0; i < (int)buf.size(); i++) head[i + 1] = f1(head[i], buf[i]);
    for (int i = (int)buf.size() - 1; i >= 0; i--)
      tail[i] = f1(tail[i + 1], buf[i]);

    // update
    dp[cur] = par == -1 ? head.back() : f1(pval, head.back());

    // propagate
    int idx = 0;
    for (auto &dst : g[cur]) {
      if (dst == par) continue;
      efs(dst, cur, f2(f1(pval, f1(head[idx], tail[idx + 1])), cur, dst));
      idx++;
    }
  }
};

/*

using T = ;
// identify element of f1, and answer of leaf
T I = ;
// merge value of child node
auto f1 = [&](T x, T y) -> T {

};
// return value from child node to parent node
auto f2 = [&](T x, int chd, int par) -> T {

};
Rerooting<T, decltype(g), decltype(f1), decltype(f2)> dp(g, f1, f2, I);

*/

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

