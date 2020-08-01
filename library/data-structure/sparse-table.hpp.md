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


# :heavy_check_mark: data-structure/sparse-table.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/sparse-table.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 11:29:32+09:00




## Required by

* :heavy_check_mark: <a href="../string/suffix-array.hpp.html">string/suffix-array.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-ds/yosupo-static-rmq.test.cpp.html">verify/verify-yosupo-ds/yosupo-static-rmq.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify-yosupo-other/yosupo-number-of-substrings.test.cpp.html">verify-yosupo-other/yosupo-number-of-substrings.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify-yosupo-other/yosupo-suffix-array.test.cpp.html">verify-yosupo-other/yosupo-suffix-array.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify-yosupo-other/yosupo-zalgo-suffixarray.test.cpp.html">verify-yosupo-other/yosupo-zalgo-suffixarray.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct SparseTable {
  vector<vector<T> > table;
  vector<int> log_table;

  inline T f(T a, T b) { return min(a, b); }

  SparseTable(const vector<T> &v) {
    int b = 0;
    while ((1 << b) <= (int)v.size()) ++b;
    table.assign(b, vector<T>(1 << b));
    for (int i = 0; i < (int)v.size(); i++) {
      table[0][i] = v[i];
    }
    for (int i = 1; i < b; i++) {
      for (int j = 0; j + (1 << i) <= (1 << b); j++) {
        table[i][j] = f(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
      }
    }
    log_table.resize(v.size() + 1);
    for (int i = 2; i < (int)log_table.size(); i++) {
      log_table[i] = log_table[i >> 1] + 1;
    }
  }

  // [l, r)
  inline T query(int l, int r) {
    int b = log_table[r - l];
    return f(table[b][l], table[b][r - (1 << b)]);
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data-structure/sparse-table.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct SparseTable {
  vector<vector<T> > table;
  vector<int> log_table;

  inline T f(T a, T b) { return min(a, b); }

  SparseTable(const vector<T> &v) {
    int b = 0;
    while ((1 << b) <= (int)v.size()) ++b;
    table.assign(b, vector<T>(1 << b));
    for (int i = 0; i < (int)v.size(); i++) {
      table[0][i] = v[i];
    }
    for (int i = 1; i < b; i++) {
      for (int j = 0; j + (1 << i) <= (1 << b); j++) {
        table[i][j] = f(table[i - 1][j], table[i - 1][j + (1 << (i - 1))]);
      }
    }
    log_table.resize(v.size() + 1);
    for (int i = 2; i < (int)log_table.size(); i++) {
      log_table[i] = log_table[i >> 1] + 1;
    }
  }

  // [l, r)
  inline T query(int l, int r) {
    int b = log_table[r - l];
    return f(table[b][l], table[b][r - (1 << b)]);
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

