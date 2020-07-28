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


# :warning: math/rational-number.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/rational-number.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 11:29:32+09:00




## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

struct RationalNumber {
  pair<long long, long long> a;

  RationalNumber(pair<long long, long long> p) { a = init(p.first, p.second); }
  RationalNumber(long long x, long long y) { a = init(x, y); }

  pair<long long, long long> init(long long x, long long y) {
    if (x == 0 && y == 0) return pair<long long, long long>(0, 0);
    long long g = this->gcd(abs(x), abs(y));
    x /= g;
    y /= g;
    if (x < 0) x = -x, y = -y;
    if (x == 0 && y < 0) y = -y;
    return pair<long long, long long>(x, y);
  }

  long long gcd(long long x, long long y) {
    long long z;
    if (x > y) swap(x, y);
    while (x) {
      x = y % (z = x);
      y = z;
    }
    return y;
  }
  bool zero() const { return a.first == 0 && a.second == 0; }
  RationalNumber orth() const { return RationalNumber{-a.second, a.first}; }
};
namespace std {
bool operator<(const RationalNumber &x, const RationalNumber &y) {
  return x.a < y.a;
}
bool operator==(const RationalNumber &x, const RationalNumber &y) {
  return x.a == y.a;
}
bool operator!=(const RationalNumber &x, const RationalNumber &y) {
  return x.a != y.a;
}
}  // namespace std
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/rational-number.hpp"
#include <bits/stdc++.h>
using namespace std;

struct RationalNumber {
  pair<long long, long long> a;

  RationalNumber(pair<long long, long long> p) { a = init(p.first, p.second); }
  RationalNumber(long long x, long long y) { a = init(x, y); }

  pair<long long, long long> init(long long x, long long y) {
    if (x == 0 && y == 0) return pair<long long, long long>(0, 0);
    long long g = this->gcd(abs(x), abs(y));
    x /= g;
    y /= g;
    if (x < 0) x = -x, y = -y;
    if (x == 0 && y < 0) y = -y;
    return pair<long long, long long>(x, y);
  }

  long long gcd(long long x, long long y) {
    long long z;
    if (x > y) swap(x, y);
    while (x) {
      x = y % (z = x);
      y = z;
    }
    return y;
  }
  bool zero() const { return a.first == 0 && a.second == 0; }
  RationalNumber orth() const { return RationalNumber{-a.second, a.first}; }
};
namespace std {
bool operator<(const RationalNumber &x, const RationalNumber &y) {
  return x.a < y.a;
}
bool operator==(const RationalNumber &x, const RationalNumber &y) {
  return x.a == y.a;
}
bool operator!=(const RationalNumber &x, const RationalNumber &y) {
  return x.a != y.a;
}
}  // namespace std

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

