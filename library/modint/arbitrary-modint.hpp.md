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


# :x: modint/arbitrary-modint.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#fb97f878c938d7517d3d9f7de68146e9">modint</a>
* <a href="{{ site.github.repository_url }}/blob/master/modint/arbitrary-modint.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-28 11:29:32+09:00




## Required by

* :x: <a href="../ntt/arbitrary-ntt.hpp.html">ntt/arbitrary-ntt.hpp</a>


## Verified with

* :x: <a href="../../verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt-arbitrarymodint.test.cpp.html">verify-yosupo-ntt/yosupo-convolution-arbitraryntt-arbitrarymodint.test.cpp</a>
* :x: <a href="../../verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt-arbitraryprimemodint.test.cpp.html">verify-yosupo-ntt/yosupo-convolution-arbitraryntt-arbitraryprimemodint.test.cpp</a>
* :x: <a href="../../verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt.test.cpp.html">verify-yosupo-ntt/yosupo-convolution-arbitraryntt.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

struct ArbitraryModInt {
  int x;

  ArbitraryModInt() : x(0) {}

  ArbitraryModInt(int64_t y)
      : x(y >= 0 ? y % get_mod() : (get_mod() - (-y) % get_mod()) % get_mod()) {
  }

  static int &get_mod() {
    static int mod = 0;
    return mod;
  }

  static void set_mod(int md) { get_mod() = md; }

  ArbitraryModInt &operator+=(const ArbitraryModInt &p) {
    if ((x += p.x) >= get_mod()) x -= get_mod();
    return *this;
  }

  ArbitraryModInt &operator-=(const ArbitraryModInt &p) {
    if ((x += get_mod() - p.x) >= get_mod()) x -= get_mod();
    return *this;
  }

  ArbitraryModInt &operator*=(const ArbitraryModInt &p) {
    unsigned long long a = (unsigned long long)x * p.x;
    unsigned xh = (unsigned)(a >> 32), xl = (unsigned)a, d, m;
    asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(get_mod()));
    x = m;
    return *this;
  }

  ArbitraryModInt &operator/=(const ArbitraryModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ArbitraryModInt operator-() const { return ArbitraryModInt(-x); }

  ArbitraryModInt operator+(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) += p;
  }

  ArbitraryModInt operator-(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) -= p;
  }

  ArbitraryModInt operator*(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) *= p;
  }

  ArbitraryModInt operator/(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) /= p;
  }

  bool operator==(const ArbitraryModInt &p) const { return x == p.x; }

  bool operator!=(const ArbitraryModInt &p) const { return x != p.x; }

  ArbitraryModInt inverse() const {
    int a = x, b = get_mod(), u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ArbitraryModInt(u);
  }

  ArbitraryModInt pow(int64_t n) const {
    ArbitraryModInt ret(1), mul(x);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ArbitraryModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ArbitraryModInt &a) {
    int64_t t;
    is >> t;
    a = ArbitraryModInt(t);
    return (is);
  }
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "modint/arbitrary-modint.hpp"
#include <bits/stdc++.h>
using namespace std;

struct ArbitraryModInt {
  int x;

  ArbitraryModInt() : x(0) {}

  ArbitraryModInt(int64_t y)
      : x(y >= 0 ? y % get_mod() : (get_mod() - (-y) % get_mod()) % get_mod()) {
  }

  static int &get_mod() {
    static int mod = 0;
    return mod;
  }

  static void set_mod(int md) { get_mod() = md; }

  ArbitraryModInt &operator+=(const ArbitraryModInt &p) {
    if ((x += p.x) >= get_mod()) x -= get_mod();
    return *this;
  }

  ArbitraryModInt &operator-=(const ArbitraryModInt &p) {
    if ((x += get_mod() - p.x) >= get_mod()) x -= get_mod();
    return *this;
  }

  ArbitraryModInt &operator*=(const ArbitraryModInt &p) {
    unsigned long long a = (unsigned long long)x * p.x;
    unsigned xh = (unsigned)(a >> 32), xl = (unsigned)a, d, m;
    asm("divl %4; \n\t" : "=a"(d), "=d"(m) : "d"(xh), "a"(xl), "r"(get_mod()));
    x = m;
    return *this;
  }

  ArbitraryModInt &operator/=(const ArbitraryModInt &p) {
    *this *= p.inverse();
    return *this;
  }

  ArbitraryModInt operator-() const { return ArbitraryModInt(-x); }

  ArbitraryModInt operator+(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) += p;
  }

  ArbitraryModInt operator-(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) -= p;
  }

  ArbitraryModInt operator*(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) *= p;
  }

  ArbitraryModInt operator/(const ArbitraryModInt &p) const {
    return ArbitraryModInt(*this) /= p;
  }

  bool operator==(const ArbitraryModInt &p) const { return x == p.x; }

  bool operator!=(const ArbitraryModInt &p) const { return x != p.x; }

  ArbitraryModInt inverse() const {
    int a = x, b = get_mod(), u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ArbitraryModInt(u);
  }

  ArbitraryModInt pow(int64_t n) const {
    ArbitraryModInt ret(1), mul(x);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ArbitraryModInt &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ArbitraryModInt &a) {
    int64_t t;
    is >> t;
    a = ArbitraryModInt(t);
    return (is);
  }
};

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

