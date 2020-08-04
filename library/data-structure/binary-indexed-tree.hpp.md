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


# :heavy_check_mark: data-structure/binary-indexed-tree.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/binary-indexed-tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 11:29:32+09:00




## Required by

* :heavy_check_mark: <a href="range-sum-range-add-bit.hpp.html">data-structure/range-sum-range-add-bit.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-aoj-dsl/aoj-dsl-2-b-bit.test.cpp.html">verify/verify-aoj-dsl/aoj-dsl-2-b-bit.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-aoj-dsl/aoj-dsl-2-e-imos.test.cpp.html">verify/verify-aoj-dsl/aoj-dsl-2-e-imos.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-aoj-dsl/aoj-dsl-2-g-bit.test.cpp.html">verify/verify-aoj-dsl/aoj-dsl-2-g-bit.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-ds/yosupo-point-add-range-sum.test.cpp.html">verify/verify-yosupo-ds/yosupo-point-add-range-sum.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-ds/yosupo-static-range-inversions-query.test.cpp.html">verify/verify-yosupo-ds/yosupo-static-range-inversions-query.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BinaryIndexedTree {
  int N;
  int max_2beki;
  vector<T> data;

  BinaryIndexedTree(int size) {
    N = ++size;
    data.assign(N + 3, 0);
    max_2beki = 1;
    while (max_2beki * 2 <= N) max_2beki *= 2;
  }

  // get sum of [0,k]
  T sum(int k) const {
    if (k < 0) return 0;  // return 0 if k < 0
    T ret = 0;
    for (++k; k > 0; k -= k & -k) ret += data[k];
    return ret;
  }

  // getsum of [l,r]
  inline T sum(int l, int r) const { return sum(r) - sum(l - 1); }

  // get value of k
  inline T operator[](int k) const { return sum(k) - sum(k - 1); }

  // data[k] += x
  void add(int k, T x) {
    for (++k; k < N; k += k & -k) data[k] += x;
  }

  // range add x to [l,r]
  void imos(int l, int r, T x) {
    add(l, x);
    add(r + 1, -x);
  }

  // minimize i s.t. sum(i) >= w
  int lower_bound(T w) {
    if (w <= 0) return 0;
    int x = 0;
    for (int k = max_2beki; k > 0; k /= 2) {
      if (x + k <= N - 1 && data[x + k] < w) {
        w -= data[x + k];
        x += k;
      }
    }
    return x;
  }

  // minimize i s.t. sum(i) > w
  int upper_bound(T w) {
    if (w < 0) return 0;
    int x = 0;
    for (int k = max_2beki; k > 0; k /= 2) {
      if (x + k <= N - 1 && data[x + k] <= w) {
        w -= data[x + k];
        x += k;
      }
    }
    return x;
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data-structure/binary-indexed-tree.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct BinaryIndexedTree {
  int N;
  int max_2beki;
  vector<T> data;

  BinaryIndexedTree(int size) {
    N = ++size;
    data.assign(N + 3, 0);
    max_2beki = 1;
    while (max_2beki * 2 <= N) max_2beki *= 2;
  }

  // get sum of [0,k]
  T sum(int k) const {
    if (k < 0) return 0;  // return 0 if k < 0
    T ret = 0;
    for (++k; k > 0; k -= k & -k) ret += data[k];
    return ret;
  }

  // getsum of [l,r]
  inline T sum(int l, int r) const { return sum(r) - sum(l - 1); }

  // get value of k
  inline T operator[](int k) const { return sum(k) - sum(k - 1); }

  // data[k] += x
  void add(int k, T x) {
    for (++k; k < N; k += k & -k) data[k] += x;
  }

  // range add x to [l,r]
  void imos(int l, int r, T x) {
    add(l, x);
    add(r + 1, -x);
  }

  // minimize i s.t. sum(i) >= w
  int lower_bound(T w) {
    if (w <= 0) return 0;
    int x = 0;
    for (int k = max_2beki; k > 0; k /= 2) {
      if (x + k <= N - 1 && data[x + k] < w) {
        w -= data[x + k];
        x += k;
      }
    }
    return x;
  }

  // minimize i s.t. sum(i) > w
  int upper_bound(T w) {
    if (w < 0) return 0;
    int x = 0;
    for (int k = max_2beki; k > 0; k /= 2) {
      if (x + k <= N - 1 && data[x + k] <= w) {
        w -= data[x + k];
        x += k;
      }
    }
    return x;
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

