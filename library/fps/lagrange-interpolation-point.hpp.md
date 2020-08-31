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


# :heavy_check_mark: fps/lagrange-interpolation-point.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#05934928102b17827b8f03ed60c3e6e0">fps</a>
* <a href="{{ site.github.repository_url }}/blob/master/fps/lagrange-interpolation-point.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 22:48:29+09:00




## Depends on

* :heavy_check_mark: <a href="../modulo/binomial.hpp.html">modulo/binomial.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp.html">verify/verify-yosupo-fps/yosupo-sum-of-exp-poly-limit.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp.html">verify/verify-yosupo-fps/yosupo-sum-of-exp-poly.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../modulo/binomial.hpp"

// given  : y(x=0) , y(x=1) , ... , y(k)
// return : y(x)
template <typename mint>
mint lagrange_interpolation(const vector<mint>& y, long long x,
                            const Binomial<mint>& C) {
  int N = (int)y.size() - 1;
  if (x <= N) return y[x];
  mint ret = 0;
  vector<mint> dp(N + 1, 1), pd(N + 1, 1);
  mint a = x, one = 1;
  for (int i = 0; i < N; i++) dp[i + 1] = dp[i] * a, a -= one;
  for (int i = N; i > 0; i--) pd[i - 1] = pd[i] * a, a += one;
  for (int i = 0; i <= N; i++) {
    mint tmp = y[i] * dp[i] * pd[i] * C.finv(i) * C.finv(N - i);
    ret += ((N - i) & 1) ? -tmp : tmp;
  }
  return ret;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "fps/lagrange-interpolation-point.hpp"
#include <bits/stdc++.h>
using namespace std;

#line 3 "modulo/binomial.hpp"
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

  inline T fac(int i) const { return fac_[i]; }
  inline T finv(int i) const { return finv_[i]; }
  inline T inv(int i) const { return inv_[i]; }

  T C(int n, int r) const {
    if (n < r || r < 0) return T(0);
    return fac_[n] * finv_[n - r] * finv_[r];
  }

  T C_naive(int n, int r) const {
    if (n < r || r < 0) return T(0);
    T ret = 1;
    for (T i = 1; i <= r; i += T(1)) {
      ret *= n--;
      ret *= i.inverse();
    }
    return ret;
  }

  T P(int n, int r) const {
    if (n < r || r < 0) return T(0);
    return fac_[n] * finv_[n - r];
  }

  T H(int n, int r) const {
    if (n < 0 || r < 0) return (0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};
#line 6 "fps/lagrange-interpolation-point.hpp"

// given  : y(x=0) , y(x=1) , ... , y(k)
// return : y(x)
template <typename mint>
mint lagrange_interpolation(const vector<mint>& y, long long x,
                            const Binomial<mint>& C) {
  int N = (int)y.size() - 1;
  if (x <= N) return y[x];
  mint ret = 0;
  vector<mint> dp(N + 1, 1), pd(N + 1, 1);
  mint a = x, one = 1;
  for (int i = 0; i < N; i++) dp[i + 1] = dp[i] * a, a -= one;
  for (int i = N; i > 0; i--) pd[i - 1] = pd[i] * a, a += one;
  for (int i = 0; i <= N; i++) {
    mint tmp = y[i] * dp[i] * pd[i] * C.finv(i) * C.finv(N - i);
    ret += ((N - i) & 1) ? -tmp : tmp;
  }
  return ret;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

