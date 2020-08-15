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


# :heavy_check_mark: data-structure/range-union-find.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/range-union-find.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-15 19:54:29+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yuki/yuki-1170.test.cpp.html">verify/verify-yuki/yuki-1170.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

struct RangeUnionFind {
  vector<int> data, left, right;
  RangeUnionFind(int N) : data(N, -1) {
    left.resize(N);
    right.resize(N);
    iota(begin(left), end(left), 0);
    iota(begin(right), end(right), 1);
  }

  int find(int k) { return data[k] < 0 ? k : data[k] = find(data[k]); }

  int unite(int x, int y) {
    if ((x = find(x)) == (y = find(y))) return false;
    if (data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    left[x] = min(left[x], left[y]);
    right[x] = max(right[x], right[y]);
    return true;
  }

  // unite [l, r)
  void range_unite(int l, int r) {
    if ((l = max(l, 0)) >= (r = min(r, (int)data.size()))) return;
    int m;
    while ((m = right[find(l)]) < r) {
      assert(left[find(m)] == m);
      unite(l, m);
    }
  }

  int size(int k) { return -data[find(k)]; }

  int same(int x, int y) { return find(x) == find(y); }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data-structure/range-union-find.hpp"
#include <bits/stdc++.h>
using namespace std;

struct RangeUnionFind {
  vector<int> data, left, right;
  RangeUnionFind(int N) : data(N, -1) {
    left.resize(N);
    right.resize(N);
    iota(begin(left), end(left), 0);
    iota(begin(right), end(right), 1);
  }

  int find(int k) { return data[k] < 0 ? k : data[k] = find(data[k]); }

  int unite(int x, int y) {
    if ((x = find(x)) == (y = find(y))) return false;
    if (data[x] > data[y]) swap(x, y);
    data[x] += data[y];
    data[y] = x;
    left[x] = min(left[x], left[y]);
    right[x] = max(right[x], right[y]);
    return true;
  }

  // unite [l, r)
  void range_unite(int l, int r) {
    if ((l = max(l, 0)) >= (r = min(r, (int)data.size()))) return;
    int m;
    while ((m = right[find(l)]) < r) {
      assert(left[find(m)] == m);
      unite(l, m);
    }
  }

  int size(int k) { return -data[find(k)]; }

  int same(int x, int y) { return find(x) == find(y); }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

