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


# :warning: math/prime-counting-faster.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/prime-counting-faster.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-19 23:44:33+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include <bits/stdc++.h>
using namespace std;

namespace PrimeCounting {
using i64 = long long;
static inline i64 my_div(i64 n, i64 p) { return double(n) / p; };

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) i64
prime_counting(i64 N) {
  i64 N2 = sqrt(N);
  i64 NdN2 = my_div(N, N2);

  vector<i64> hl(NdN2);
  for (int i = 1; i < NdN2; i++) hl[i] = my_div(N, i) - 1;

  vector<int> hs(N2 + 1);
  iota(begin(hs), end(hs), -1);

  for (int x = 2, pi = 0; x <= N2; ++x) {
    if (hs[x] == hs[x - 1]) continue;
    i64 x2 = i64(x) * x;
    i64 imax = min<i64>(NdN2, my_div(N, x2) + 1);
    i64 ix = x;
    for (i64 i = 1; i < imax; ++i) {
      hl[i] -= (ix < NdN2 ? hl[ix] : hs[my_div(N, ix)]) - pi;
      ix += x;
    }
    for (int n = N2; n >= x2; n--) {
      hs[n] -= hs[my_div(n, x)] - pi;
    }
    ++pi;
  }
  return hl[1];
}

}  // namespace PrimeCounting
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 1 "math/prime-counting-faster.hpp"
#include <bits/stdc++.h>
using namespace std;

namespace PrimeCounting {
using i64 = long long;
static inline i64 my_div(i64 n, i64 p) { return double(n) / p; };

__attribute__((target("avx2"), optimize("O3", "unroll-loops"))) i64
prime_counting(i64 N) {
  i64 N2 = sqrt(N);
  i64 NdN2 = my_div(N, N2);

  vector<i64> hl(NdN2);
  for (int i = 1; i < NdN2; i++) hl[i] = my_div(N, i) - 1;

  vector<int> hs(N2 + 1);
  iota(begin(hs), end(hs), -1);

  for (int x = 2, pi = 0; x <= N2; ++x) {
    if (hs[x] == hs[x - 1]) continue;
    i64 x2 = i64(x) * x;
    i64 imax = min<i64>(NdN2, my_div(N, x2) + 1);
    i64 ix = x;
    for (i64 i = 1; i < imax; ++i) {
      hl[i] -= (ix < NdN2 ? hl[ix] : hs[my_div(N, ix)]) - pi;
      ix += x;
    }
    for (int n = N2; n >= x2; n--) {
      hs[n] -= hs[my_div(n, x)] - pi;
    }
    ++pi;
  }
  return hl[1];
}

}  // namespace PrimeCounting

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

