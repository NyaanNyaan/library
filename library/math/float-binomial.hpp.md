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


# :warning: math/float-binomial.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/float-binomial.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 11:29:32+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

struct float_bicom {
  vector<long double> fac;
  float_bicom(int MAX) {
    fac.resize(MAX + 1, 0.0);
    fac[0] = 0.0;
    for (int i = 1; i <= MAX; i++) {
      fac[i] = fac[i - 1] + log(i);
    }
  }
  long double C(int n, int k) {
    if (n < k || k < 0 || n < 0) return 0.0;
    return exp(fac[n] - fac[n - k] - fac[k]);
  }
  long double P(int n, int k) {
    if (n < k || k < 0 || n < 0) return 0.0;
    return exp(fac[n] - fac[n - k]);
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/float-binomial.hpp"
#include <bits/stdc++.h>
using namespace std;

struct float_bicom {
  vector<long double> fac;
  float_bicom(int MAX) {
    fac.resize(MAX + 1, 0.0);
    fac[0] = 0.0;
    for (int i = 1; i <= MAX; i++) {
      fac[i] = fac[i - 1] + log(i);
    }
  }
  long double C(int n, int k) {
    if (n < k || k < 0 || n < 0) return 0.0;
    return exp(fac[n] - fac[n - k] - fac[k]);
  }
  long double P(int n, int k) {
    if (n < k || k < 0 || n < 0) return 0.0;
    return exp(fac[n] - fac[n - k]);
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

