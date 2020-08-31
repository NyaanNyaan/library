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


# :warning: math/enamurate-multiplicative-function.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/enamurate-multiplicative-function.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-31 22:48:29+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

// f(n, p, c) : n = pow(p, c), f is multiplicative function
template <typename mint, typename F>
vector<mint> enamurate_multiplicative_function(const F& func, int n) {
  assert(n < (1LL << 30));
  vector<mint> f(n + 1, mint(0));
  if (!p) {
    f[0] = 1;
    return std::move(f);
  }
  f[1] = 1;
  vector<bool> sieve(n + 1, false);
  vector<int> ps;
  for (int i = 2; i <= n; i++) {
    if (!sieve[i]) {
      f[i] = func(i, i, 1);
      ps.push_back(i);
    }
    for (int j = 0; j < (int)ps.size() && i * ps[j] <= n; j++) {
      sieve[i * ps[j]] = 1;
      if (i % ps[j] == 0) {
        int c = 0, x = i, y = 1;
        while (x % ps[j] == 0) x /= ps[j], y *= ps[j], ++c;
        if (x == 1)
          f[i * ps[j]] = func(i * ps[j], i, c + 1);
        else
          f[i * ps[j]] = f[x] * f[y];
        break;
      } else
        f[i * ps[j]] = f[i] * f[ps[j]];
    }
  }
  return std::move(f);
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/enamurate-multiplicative-function.hpp"
#include <bits/stdc++.h>
using namespace std;

// f(n, p, c) : n = pow(p, c), f is multiplicative function
template <typename mint, typename F>
vector<mint> enamurate_multiplicative_function(const F& func, int n) {
  assert(n < (1LL << 30));
  vector<mint> f(n + 1, mint(0));
  if (!p) {
    f[0] = 1;
    return std::move(f);
  }
  f[1] = 1;
  vector<bool> sieve(n + 1, false);
  vector<int> ps;
  for (int i = 2; i <= n; i++) {
    if (!sieve[i]) {
      f[i] = func(i, i, 1);
      ps.push_back(i);
    }
    for (int j = 0; j < (int)ps.size() && i * ps[j] <= n; j++) {
      sieve[i * ps[j]] = 1;
      if (i % ps[j] == 0) {
        int c = 0, x = i, y = 1;
        while (x % ps[j] == 0) x /= ps[j], y *= ps[j], ++c;
        if (x == 1)
          f[i * ps[j]] = func(i * ps[j], i, c + 1);
        else
          f[i * ps[j]] = f[x] * f[y];
        break;
      } else
        f[i * ps[j]] = f[i] * f[ps[j]];
    }
  }
  return std::move(f);
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

