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


# :warning: data-structure/dynamic-binary-indexed-tree.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#36397fe12f935090ad150c6ce0c258d4">data-structure</a>
* <a href="{{ site.github.repository_url }}/blob/master/data-structure/dynamic-binary-indexed-tree.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 11:29:32+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

// idx_tはlong longまでを想定
template <typename idx_t, typename data_t>
struct DynamicFenwickTree {
  idx_t N;
  unordered_map<idx_t, data_t> data;
  DynamicFenwickTree(idx_t size) { N = size += 3; }

  // iにxを加算
  void add(idx_t k, data_t x) {
    for (k++; k < N; k += k & -k) data[k] += x;
  }

  // [0,i]のsum
  data_t sum(idx_t k) {
    if (k < 0) return 0;
    data_t ret = 0;
    for (k++; k > 0; k -= k & -k) ret += data[k];
    return ret;
  }

  // [a,b]のsum
  data_t sum(idx_t a, idx_t b) { return sum(b) - sum(a - 1); }

   // get value of k
  data_t operator[](idx_t k) { return sum(k) - sum(k - 1); }

  idx_t lower_bound(data_t w) {
    if (w <= 0) return 0;
    idx_t x = 0;
    for (idx_t k = 1 << (63 - __builtin_clzll((long long)(x))); k > 0; k /= 2) {
      if (x + k <= N - 1 && data[x + k] < w) {
        w -= data[x + k];
        x += k;
      }
    }
    return x;
  }

  void merge(DynamicFenwickTree<idx_t, data_t>& other) {
    if (data.size() < other.data.size()) data.swap(other.data);
    for (auto& x : other.data) data[x.fi] += x.se;
  }
};

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "data-structure/dynamic-binary-indexed-tree.hpp"
#include <bits/stdc++.h>
using namespace std;

// idx_tはlong longまでを想定
template <typename idx_t, typename data_t>
struct DynamicFenwickTree {
  idx_t N;
  unordered_map<idx_t, data_t> data;
  DynamicFenwickTree(idx_t size) { N = size += 3; }

  // iにxを加算
  void add(idx_t k, data_t x) {
    for (k++; k < N; k += k & -k) data[k] += x;
  }

  // [0,i]のsum
  data_t sum(idx_t k) {
    if (k < 0) return 0;
    data_t ret = 0;
    for (k++; k > 0; k -= k & -k) ret += data[k];
    return ret;
  }

  // [a,b]のsum
  data_t sum(idx_t a, idx_t b) { return sum(b) - sum(a - 1); }

   // get value of k
  data_t operator[](idx_t k) { return sum(k) - sum(k - 1); }

  idx_t lower_bound(data_t w) {
    if (w <= 0) return 0;
    idx_t x = 0;
    for (idx_t k = 1 << (63 - __builtin_clzll((long long)(x))); k > 0; k /= 2) {
      if (x + k <= N - 1 && data[x + k] < w) {
        w -= data[x + k];
        x += k;
      }
    }
    return x;
  }

  void merge(DynamicFenwickTree<idx_t, data_t>& other) {
    if (data.size() < other.data.size()) data.swap(other.data);
    for (auto& x : other.data) data[x.fi] += x.se;
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

