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


# :heavy_check_mark: math/sum_of_floor.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/sum_of_floor.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-07 03:15:06+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-math/yosupo-sum-of-floor.test.cpp.html">verify/verify-yosupo-math/yosupo-sum-of-floor.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

// sum_{0 <= i < N} (ai + b) // m
template <typename T>
T sum_of_floor(T n, T m, T a, T b) {
  T ret = 0;
  if (a >= m) ret += (n - 1) * n * (a / m) / 2, a %= m;
  if (b >= m) ret += n * (b / m), b %= m;
  T y = (a * n + b) / m;
  if (y == 0) return ret;
  T x = y * m - b;
  ret += (n - (x + a - 1) / a) * y;
  ret += sum_of_floor(y, a, m, (a - x % a) % a);
  return ret;
}

// verify www.codechef.com/viewsolution/36222026
// count x : ax + b mod m < yr, 0 <= x < xr
template <typename T>
T mod_affine_range_counting(T a, T b, T m, T xr, T yr) {
  assert(0 <= yr && yr <= m);
  return sum_of_floor(xr, m, a, b + m) - sum_of_floor(xr, m, a, b + m - yr);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/sum_of_floor.hpp"
#include <bits/stdc++.h>
using namespace std;

// sum_{0 <= i < N} (ai + b) // m
template <typename T>
T sum_of_floor(T n, T m, T a, T b) {
  T ret = 0;
  if (a >= m) ret += (n - 1) * n * (a / m) / 2, a %= m;
  if (b >= m) ret += n * (b / m), b %= m;
  T y = (a * n + b) / m;
  if (y == 0) return ret;
  T x = y * m - b;
  ret += (n - (x + a - 1) / a) * y;
  ret += sum_of_floor(y, a, m, (a - x % a) % a);
  return ret;
}

// verify www.codechef.com/viewsolution/36222026
// count x : ax + b mod m < yr, 0 <= x < xr
template <typename T>
T mod_affine_range_counting(T a, T b, T m, T xr, T yr) {
  assert(0 <= yr && yr <= m);
  return sum_of_floor(xr, m, a, b + m) - sum_of_floor(xr, m, a, b + m - yr);
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

