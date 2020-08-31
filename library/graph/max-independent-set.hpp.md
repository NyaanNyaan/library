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


# :heavy_check_mark: graph/max-independent-set.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/max-independent-set.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-01 01:49:02+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-graph/yosupo-max-independent-set.test.cpp.html">verify/verify-yosupo-graph/yosupo-max-independent-set.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

template <int m>
vector<int> max_independent_set(const vector<vector<int>> &g) {
  constexpr int M = (m + 63) / 64 * 64;
  int N = g.size();
  vector<bitset<M>> bs(N);
  for (int i = 0; i < N; i++)
    for (auto &j : g[i]) bs[i][j] = bs[j][i] = 1;
  bitset<M> res, cur, ignore;
  auto dfs = [&](auto rec, int i) -> void {
    if (i == N) {
      if (cur.count() > res.count()) res = cur;
      return;
    }
    if ((bs[i] & cur).any() || (bs[i] & ~ignore).count() >= 2) {
      ignore[i] = 1;
      rec(rec, i + 1);
      ignore[i] = 0;
    }
    if ((bs[i] & cur).none()) {
      cur[i] = 1;
      rec(rec, i + 1);
      cur[i] = 0;
    }
  };
  dfs(dfs, 0);
  vector<int> res2;
  for (int i = 0; i < N; i++)
    if (res[i]) res2.push_back(i);
  return res2;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "graph/max-independent-set.hpp"
#include <bits/stdc++.h>
using namespace std;

template <int m>
vector<int> max_independent_set(const vector<vector<int>> &g) {
  constexpr int M = (m + 63) / 64 * 64;
  int N = g.size();
  vector<bitset<M>> bs(N);
  for (int i = 0; i < N; i++)
    for (auto &j : g[i]) bs[i][j] = bs[j][i] = 1;
  bitset<M> res, cur, ignore;
  auto dfs = [&](auto rec, int i) -> void {
    if (i == N) {
      if (cur.count() > res.count()) res = cur;
      return;
    }
    if ((bs[i] & cur).any() || (bs[i] & ~ignore).count() >= 2) {
      ignore[i] = 1;
      rec(rec, i + 1);
      ignore[i] = 0;
    }
    if ((bs[i] & cur).none()) {
      cur[i] = 1;
      rec(rec, i + 1);
      cur[i] = 0;
    }
  };
  dfs(dfs, 0);
  vector<int> res2;
  for (int i = 0; i < N; i++)
    if (res[i]) res2.push_back(i);
  return res2;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

