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


# :heavy_check_mark: math/prime-table.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/prime-table.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-09 02:39:23+09:00




## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-math/yosupo-prime-table.test.cpp.html">verify/verify-yosupo-math/yosupo-prime-table.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

// Prime Sieve {2, 3, 5, 7, 11, 13, 17, ...}
vector<int> PrimeTable(int N) {
  vector<bool> sieve(N / 2 + 1, 1);
  for (int p = 5, d = 4, p2 = p * p;; p += d = 6 - d) {
    if ((p2 = p * p) > N) break;
    if (!sieve[p >> 1]) continue;
    for (int q = p2, r = d * p, s = 6 * p; q <= N; q += r = s - r)
      sieve[q >> 1] = 0;
  }
  vector<int> ret{2, 3};
  for (int p = 5, d = 4; p <= N; p += d = 6 - d)
    if (sieve[p >> 1]) ret.push_back(p);
  while (ret.back() > N) ret.pop_back();
  return ret;
}
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/prime-table.hpp"
#include <bits/stdc++.h>
using namespace std;

// Prime Sieve {2, 3, 5, 7, 11, 13, 17, ...}
vector<int> PrimeTable(int N) {
  vector<bool> sieve(N / 2 + 1, 1);
  for (int p = 5, d = 4, p2 = p * p;; p += d = 6 - d) {
    if ((p2 = p * p) > N) break;
    if (!sieve[p >> 1]) continue;
    for (int q = p2, r = d * p, s = 6 * p; q <= N; q += r = s - r)
      sieve[q >> 1] = 0;
  }
  vector<int> ret{2, 3};
  for (int p = 5, d = 4; p <= N; p += d = 6 - d)
    if (sieve[p >> 1]) ret.push_back(p);
  while (ret.back() > N) ret.pop_back();
  return ret;
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

