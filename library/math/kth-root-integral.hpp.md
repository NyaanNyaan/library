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


# :heavy_check_mark: $\mathrm{floor}(a^{\frac{1}{k}})$ <small>(math/kth-root-integral.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/kth-root-integral.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 23:29:15+09:00




## $\mathrm{floor}(a^{\frac{1}{k}})$

#### 概要

整数$a$の$k$乗根(切り捨て)を求めるライブラリ。

$a,k$の値によって`powl`関数が上下両方に誤差を発生しうることに注意して実装する。

#### 使い方

- `kth_root_integral(a, k)`　:　$a$の$k$乗根を求める。


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-math/yosupo-kth-root-integral.test.cpp.html">verify/verify-yosupo-math/yosupo-kth-root-integral.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

uint64_t kth_root_integral(uint64_t a, uint64_t k) {
  if (a <= 1 || k == 1) return a;
  if (64 <= k) return 1;
  auto check = [&](__uint128_t n) {
    __uint128_t x = 1, m = n;
    for (int p = k; p; p >>= 1, m *= m)
      if (p & 1) x *= m;
    return x <= a;
  };
  uint64_t n = powl(a, (long double)(1.0) / k);
  while (!check(n)) --n;
  while (check(n + 1)) ++n;
  return n;
}

/**
 * @brief $\mathrm{floor}(a^{\frac{1}{k}})$
 * @docs docs/math/kth-root-integral.md
 */

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/kth-root-integral.hpp"
#include <bits/stdc++.h>
using namespace std;

uint64_t kth_root_integral(uint64_t a, uint64_t k) {
  if (a <= 1 || k == 1) return a;
  if (64 <= k) return 1;
  auto check = [&](__uint128_t n) {
    __uint128_t x = 1, m = n;
    for (int p = k; p; p >>= 1, m *= m)
      if (p & 1) x *= m;
    return x <= a;
  };
  uint64_t n = powl(a, (long double)(1.0) / k);
  while (!check(n)) --n;
  while (check(n + 1)) ++n;
  return n;
}

/**
 * @brief $\mathrm{floor}(a^{\frac{1}{k}})$
 * @docs docs/math/kth-root-integral.md
 */

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

