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


# :heavy_check_mark: modulo/mod-sqrt.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5dcb4a1ea5a35da52691d50c8313c333">modulo</a>
* <a href="{{ site.github.repository_url }}/blob/master/modulo/mod-sqrt.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-31 20:35:22+09:00




## Depends on

* :heavy_check_mark: <a href="../modint/arbitrary-prime-modint.hpp.html">modint/arbitrary-prime-modint.hpp</a>


## Required by

* :heavy_check_mark: <a href="../fps/sqrt.hpp.html">平方根 <small>(fps/sqrt.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify-yosupo-fps/yosupo-sqrt.test.cpp.html">verify-yosupo-fps/yosupo-sqrt.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify-yosupo-math/yosupo-mod-sqrt.test.cpp.html">verify-yosupo-math/yosupo-mod-sqrt.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#include "../modint/arbitrary-prime-modint.hpp"

int64_t mod_sqrt(const int64_t &a, const int64_t &p) {
  if (a == 0) return 0;
  if (p == 2) return a;
  using mint = ArbitraryLazyMontgomeryModInt;
  mint::set_mod(p);
  if (mint(a).pow((p - 1) >> 1) != 1) return -1;
  mint b = 1, one = 1;
  while (b.pow((p - 1) >> 1) == 1) b += one;
  int64_t m = p - 1, e = 0;
  while (m % 2 == 0) m >>= 1, e += 1;
  mint x = mint(a).pow((m - 1) >> 1);
  mint y = mint(a) * x * x;
  x *= a;
  mint z = mint(b).pow(m);
  while (y != 1) {
    int64_t j = 0;
    mint t = y;
    while (t != one) {
      j += 1;
      t *= t;
    }
    z = z.pow(int64_t(1) << (e - j - 1));
    x *= z;
    z *= z;
    y *= z;
    e = j;
  }
  return x.get();
}

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "modint/arbitrary-prime-modint.hpp"
#include <bits/stdc++.h>
using namespace std;

struct ArbitraryLazyMontgomeryModInt {
  using mint = ArbitraryLazyMontgomeryModInt;
  using i32 = int32_t;
  using u32 = uint32_t;
  using u64 = uint64_t;

  static u32 mod;
  static u32 r;
  static u32 n2;

  static u32 get_r() {
    u32 ret = mod;
    for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;
    return ret;
  }

  static void set_mod(u32 m) {
    assert(m < (1 << 30));
    assert((m & 1) == 1);
    mod = m;
    n2 = -u64(m) % m;
    r = get_r();
    assert(r * mod == 1);
  }

  u32 a;

  ArbitraryLazyMontgomeryModInt() : a(0) {}
  ArbitraryLazyMontgomeryModInt(const int64_t &b)
      : a(reduce(u64(b % mod + mod) * n2)){};

  static u32 reduce(const u64 &b) {
    return (b + u64(u32(b) * u32(-r)) * mod) >> 32;
  }

  mint &operator+=(const mint &b) {
    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;
    return *this;
  }

  mint &operator-=(const mint &b) {
    if (i32(a -= b.a) < 0) a += 2 * mod;
    return *this;
  }

  mint &operator*=(const mint &b) {
    a = reduce(u64(a) * b.a);
    return *this;
  }

  mint &operator/=(const mint &b) {
    *this *= b.inverse();
    return *this;
  }

  mint operator+(const mint &b) const { return mint(*this) += b; }
  mint operator-(const mint &b) const { return mint(*this) -= b; }
  mint operator*(const mint &b) const { return mint(*this) *= b; }
  mint operator/(const mint &b) const { return mint(*this) /= b; }
  bool operator==(const mint &b) const {
    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);
  }
  bool operator!=(const mint &b) const {
    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);
  }
  mint operator-() const { return mint() - mint(*this); }

  mint pow(u64 n) const {
    mint ret(1), mul(*this);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const mint &b) {
    return os << b.get();
  }

  friend istream &operator>>(istream &is, mint &b) {
    int64_t t;
    is >> t;
    b = ArbitraryLazyMontgomeryModInt(t);
    return (is);
  }

  mint inverse() const { return pow(mod - 2); }

  u32 get() const {
    u32 ret = reduce(a);
    return ret >= mod ? ret - mod : ret;
  }

  static u32 get_mod() { return mod; }
};
typename ArbitraryLazyMontgomeryModInt::u32 ArbitraryLazyMontgomeryModInt::mod;
typename ArbitraryLazyMontgomeryModInt::u32 ArbitraryLazyMontgomeryModInt::r;
typename ArbitraryLazyMontgomeryModInt::u32 ArbitraryLazyMontgomeryModInt::n2;
#line 2 "modulo/mod-sqrt.hpp"

int64_t mod_sqrt(const int64_t &a, const int64_t &p) {
  if (a == 0) return 0;
  if (p == 2) return a;
  using mint = ArbitraryLazyMontgomeryModInt;
  mint::set_mod(p);
  if (mint(a).pow((p - 1) >> 1) != 1) return -1;
  mint b = 1, one = 1;
  while (b.pow((p - 1) >> 1) == 1) b += one;
  int64_t m = p - 1, e = 0;
  while (m % 2 == 0) m >>= 1, e += 1;
  mint x = mint(a).pow((m - 1) >> 1);
  mint y = mint(a) * x * x;
  x *= a;
  mint z = mint(b).pow(m);
  while (y != 1) {
    int64_t j = 0;
    mint t = y;
    while (t != one) {
      j += 1;
      t *= t;
    }
    z = z.pow(int64_t(1) << (e - j - 1));
    x *= z;
    z *= z;
    y *= z;
    e = j;
  }
  return x.get();
}

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

