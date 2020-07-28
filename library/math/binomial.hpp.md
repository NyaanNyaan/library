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


# :warning: math/binomial.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/binomial.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-29 04:39:16+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Binomial {
  vector<T> fac_, finv_, inv_;
  Binomial(int MAX) : fac_(MAX + 10), finv_(MAX + 10), inv_(MAX + 10) {
    MAX += 9;
    fac_[0] = finv_[0] = inv_[0] = 1;
    for (int i = 1; i <= MAX; i++) fac_[i] = fac_[i - 1] * i;
    finv_[MAX] = fac_[MAX].inverse();
    for (int i = MAX - 1; i > 0; i--) finv_[i] = finv_[i + 1] * (i + 1);
    for (int i = 1; i <= MAX; i++) inv_[i] = finv_[i] * fac_[i - 1];
  }

  inline T fac(int i) { return fac_[i]; }
  inline T finv(int i) { return finv_[i]; }
  inline T inv(int i) { return inv_[i]; }

  T C(int n, int r) {
    if (n < r || r < 0) return T(0);
    return fac_[n] * finv_[n - r] * finv_[r];
  }

  T C_naive(int n, int r) {
    if (n < r || r < 0) return T(0);
    T ret = 1;
    for (T i = 1; i <= r; i += T(1)) {
      ret *= n--;
      ret *= i.inverse();
    }
    return ret;
  }

  T P(int n, int r) {
    if (n < r || r < 0) return T(0);
    return fac_[n] * finv_[n - r];
  }

  T H(int n, int r) const {
    if (n < 0 || r < 0) return (0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/binomial.hpp"
#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Binomial {
  vector<T> fac_, finv_, inv_;
  Binomial(int MAX) : fac_(MAX + 10), finv_(MAX + 10), inv_(MAX + 10) {
    MAX += 9;
    fac_[0] = finv_[0] = inv_[0] = 1;
    for (int i = 1; i <= MAX; i++) fac_[i] = fac_[i - 1] * i;
    finv_[MAX] = fac_[MAX].inverse();
    for (int i = MAX - 1; i > 0; i--) finv_[i] = finv_[i + 1] * (i + 1);
    for (int i = 1; i <= MAX; i++) inv_[i] = finv_[i] * fac_[i - 1];
  }

  inline T fac(int i) { return fac_[i]; }
  inline T finv(int i) { return finv_[i]; }
  inline T inv(int i) { return inv_[i]; }

  T C(int n, int r) {
    if (n < r || r < 0) return T(0);
    return fac_[n] * finv_[n - r] * finv_[r];
  }

  T C_naive(int n, int r) {
    if (n < r || r < 0) return T(0);
    T ret = 1;
    for (T i = 1; i <= r; i += T(1)) {
      ret *= n--;
      ret *= i.inverse();
    }
    return ret;
  }

  T P(int n, int r) {
    if (n < r || r < 0) return T(0);
    return fac_[n] * finv_[n - r];
  }

  T H(int n, int r) const {
    if (n < 0 || r < 0) return (0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

