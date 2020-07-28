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


# :heavy_check_mark: data-structure/dynamic-union-find.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/dynamic-union-find.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 11:29:32+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/verify-aoj-dsl/aoj-dsl-1-a-dynamic.test.cpp.html">verify-aoj-dsl/aoj-dsl-1-a-dynamic.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

struct DynamicUnionFind {
  unordered_map<int, int> m;
  DynamicUnionFind() {}

  int data(int k) {
    auto itk = m.find(k);
    return itk == m.end() ? m[k] = -1 : itk->second;
  }
  int find(int k) {
    int datk = data(k);
    return datk < 0 ? k : m[k] = find(datk);
  }

  int unite(int x, int y) {
    if ((x = find(x)) == (y = find(y))) return false;
    auto itx = m.find(x), ity = m.find(y);
    if (itx->second > ity->second) {
      ity->second += itx->second;
      itx->second = y;
    } else {
      itx->second += ity->second;
      ity->second = x;
    }
    return true;
  }

  int size(int k) { return -data(find(k)); }

  int same(int x, int y) { return find(x) == find(y); }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data-structure/dynamic-union-find.hpp"
#include <bits/stdc++.h>
using namespace std;

struct DynamicUnionFind {
  unordered_map<int, int> m;
  DynamicUnionFind() {}

  int data(int k) {
    auto itk = m.find(k);
    return itk == m.end() ? m[k] = -1 : itk->second;
  }
  int find(int k) {
    int datk = data(k);
    return datk < 0 ? k : m[k] = find(datk);
  }

  int unite(int x, int y) {
    if ((x = find(x)) == (y = find(y))) return false;
    auto itx = m.find(x), ity = m.find(y);
    if (itx->second > ity->second) {
      ity->second += itx->second;
      itx->second = y;
    } else {
      itx->second += ity->second;
      ity->second = x;
    }
    return true;
  }

  int size(int k) { return -data(find(k)); }

  int same(int x, int y) { return find(x) == find(y); }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

