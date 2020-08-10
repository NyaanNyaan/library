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


# :x: tree/centroid-decomposition.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/centroid-decomposition.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-11 00:13:26+09:00




## Required by

* :x: <a href="frequency-table-of-tree-distance.hpp.html">tree/frequency-table-of-tree-distance.hpp</a>


## Verified with

* :x: <a href="../../verify/verify/verify-yosupo-graph/yosupo-frequency-table-of-tree-distance.test.cpp.html">verify/verify-yosupo-graph/yosupo-frequency-table-of-tree-distance.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename G>
struct CentroidDecomposition {
  const G &g;
  vector<int> sub;
  vector<bool> v;
  vector<vector<int>> tree;
  int root;

  CentroidDecomposition(const G &g_, int isbuild = true) : g(g_) {
    sub.resize(g.size(), 0);
    v.resize(g.size(), false);
    if (isbuild) build();
  }

  void build() {
    tree.resize(g.size());
    root = build_dfs(0);
  }

  int get_size(int cur, int par) {
    sub[cur] = 1;
    for (auto &dst : g[cur]) {
      if (dst == par || v[dst]) continue;
      sub[cur] += get_size(dst, cur);
    }
    return sub[cur];
  }

  int get_centroid(int cur, int par, int mid) {
    for (auto &dst : g[cur]) {
      if (dst == par || v[dst]) continue;
      if (sub[dst] > mid) return get_centroid(dst, cur, mid);
    }
    return cur;
  }

  int build_dfs(int cur) {
    int centroid = get_centroid(cur, -1, get_size(cur, -1) / 2);
    v[centroid] = true;
    for (auto &dst : g[centroid]) {
      if (!v[dst]) {
        int nxt = build_dfs(dst);
        if (centroid != nxt) tree[centroid].emplace_back(nxt);
      }
    }
    v[centroid] = false;
    return centroid;
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "tree/centroid-decomposition.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename G>
struct CentroidDecomposition {
  const G &g;
  vector<int> sub;
  vector<bool> v;
  vector<vector<int>> tree;
  int root;

  CentroidDecomposition(const G &g_, int isbuild = true) : g(g_) {
    sub.resize(g.size(), 0);
    v.resize(g.size(), false);
    if (isbuild) build();
  }

  void build() {
    tree.resize(g.size());
    root = build_dfs(0);
  }

  int get_size(int cur, int par) {
    sub[cur] = 1;
    for (auto &dst : g[cur]) {
      if (dst == par || v[dst]) continue;
      sub[cur] += get_size(dst, cur);
    }
    return sub[cur];
  }

  int get_centroid(int cur, int par, int mid) {
    for (auto &dst : g[cur]) {
      if (dst == par || v[dst]) continue;
      if (sub[dst] > mid) return get_centroid(dst, cur, mid);
    }
    return cur;
  }

  int build_dfs(int cur) {
    int centroid = get_centroid(cur, -1, get_size(cur, -1) / 2);
    v[centroid] = true;
    for (auto &dst : g[centroid]) {
      if (!v[dst]) {
        int nxt = build_dfs(dst);
        if (centroid != nxt) tree[centroid].emplace_back(nxt);
      }
    }
    v[centroid] = false;
    return centroid;
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

