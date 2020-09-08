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


# :heavy_check_mark: data-structure/range-sum-range-add-bit.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/range-sum-range-add-bit.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-08 23:53:33+09:00




## Depends on

* :heavy_check_mark: <a href="binary-indexed-tree.hpp.html">data-structure/binary-indexed-tree.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-aoj-dsl/aoj-dsl-2-g-bit.test.cpp.html">verify/verify-aoj-dsl/aoj-dsl-2-g-bit.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "binary-indexed-tree.hpp"

template <typename T>
struct RangeAddRangeSumBIT {
  BinaryIndexedTree<T> a, b;
  RangeAddRangeSumBIT(int N) : a(N + 1), b(N + 1) {}

  // add x to [l, r)
  void add(int l, int r, T x) {
    a.add(l, x);
    a.add(r, -x);
    b.add(l, x * (1 - l));
    b.add(r, x * (r - 1));
  }

  // return sum of [l, r)
  T sum(T l, T r) {
    --r, --l;
    return a.sum(r) * r + b.sum(r) - a.sum(l) * l - b.sum(l);
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data-structure/range-sum-range-add-bit.hpp"
#include <bits/stdc++.h>
using namespace std;

#line 3 "data-structure/binary-indexed-tree.hpp"
using namespace std;

template <typename T>
struct BinaryIndexedTree {
  int N;
  int max_2beki;
  vector<T> data;

  BinaryIndexedTree(int size) {
    N = size + 3;
    data.assign(N + 1, 0);
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
#line 6 "data-structure/range-sum-range-add-bit.hpp"

template <typename T>
struct RangeAddRangeSumBIT {
  BinaryIndexedTree<T> a, b;
  RangeAddRangeSumBIT(int N) : a(N + 1), b(N + 1) {}

  // add x to [l, r)
  void add(int l, int r, T x) {
    a.add(l, x);
    a.add(r, -x);
    b.add(l, x * (1 - l));
    b.add(r, x * (r - 1));
  }

  // return sum of [l, r)
  T sum(T l, T r) {
    --r, --l;
    return a.sum(r) * r + b.sum(r) - a.sum(l) * l - b.sum(l);
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

