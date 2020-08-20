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


# :heavy_check_mark: 高速素因数分解(Miller Rabin/Pollard's Rho) <small>(math/prime-factor.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#7e676e9e663beb40fd133f5ee24487c2">math</a>
* <a href="{{ site.github.repository_url }}/blob/master/math/prime-factor.hpp">View this file on GitHub</a>
    - Last commit date: 2020-08-09 01:48:03+09:00




## 高速な素因数分解

ミラーラビン素数判定法とポラード・ロー素因数分解法を組み合わせることで$\mathrm{O}(N^{\frac{1}{4}}\log N)$で素因数分解を行うライブラリ。

#### ミラー・ラビン素数判定法(Miller-Rabin primality test)

ミラーラビン素数判定法とは、与えられた数が素数かを高速に判定する乱択アルゴリズム(実用上は決定的アルゴリズム)である。

まず、任意の奇素数$p$について、

$x^2\equiv 1 \mod p \leftrightarrow x=1,-1 \mod p$

が成り立つ。(証明は左辺を因数分解すると示せる。)ここで$p-1=2^s\cdot d$とおくと、上記の事実から

$$ a^d \equiv 1 \mod p$$

またはある$r(0 \leq r \leq s - 1)$について

$$a ^ {2^r \cdot d} \equiv -1 \mod p$$

が成り立つことが示せる。この命題の対偶を取ると、「奇数$n$についてある数$a$が存在し、『$a^d \not \equiv 1 \mod n$』かつ『任意の$r(0 \leq r \leq s - 1)$について$a ^ {2^r \cdot d} \equiv -1 \mod p$』ならば$n$は合成数」となる。

ミラーラビン法では$a$をランダムにいくつか選んで$a^{2^r\cdot d}\mod n$の値を調べ、いずれかの$a$で合成数と判定されたら$n$は合成数、そうでない場合は$n$が素数であると判定するアルゴリズムである。

実際に$a$をランダムに選ぶと誤判定が発生しうるが、$a=2, 325, 9375, 28178, 450775, 9780504, 1795265022$を選ぶと$n < 2^{64}$である$n$について正確に判定できることが知られており([参照](http://miller-rabin.appspot.com/))、実用上は上記の$a$を選んで実験することで決定的な素数判定が可能となる。

#### ポラード・ロー素因数分解法(Pollard's rho algorithm)

後で書く

## Depends on

* :question: <a href="../modint/arbitrary-prime-modint.hpp.html">modint/arbitrary-prime-modint.hpp</a>
* :heavy_check_mark: <a href="../modint/modint-montgomery64.hpp.html">modint/modint-montgomery64.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-math/yosupo-factrization.test.cpp.html">verify/verify-yosupo-math/yosupo-factrization.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "../modint/arbitrary-prime-modint.hpp"
#include "../modint/modint-montgomery64.hpp"

template <typename mint>
bool miller_rabin(uint64_t n, vector<uint64_t> as) {
  mint::set_mod(n);
  uint64_t d = n - 1;
  while (d % 2 == 0) d /= 2;
  mint e{1}, rev{int64_t(n - 1)};
  for (uint64_t a : as) {
    if (n <= a) break;
    uint64_t t = d;
    mint y = mint(a).pow(t);
    while (t != n - 1 && y != e && y != rev) {
      y *= y;
      t *= 2;
    }
    if (y != rev && t % 2 == 0) return false;
  }
  return true;
}

bool is_prime(uint64_t n) {
  if (n == 2) return true;
  if (n <= 1 || n % 2 == 0) return false;
  if (n < (1LL << 30))
    return miller_rabin<ArbitraryLazyMontgomeryModInt>(n, {2, 7, 61});
  else
    return miller_rabin<montgomery64>(
        n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}

template <typename mint>
uint64_t pollard_rho(uint64_t n) {
  if (is_prime(n)) return n;
  if (n % 2 == 0) return 2;
  mint::set_mod(n);
  uint64_t d;
  mint one{1}, c{1};
  auto f = [&](mint x) { return x * x + c; };
  for (;; c += one) {
    mint x{2}, y{2};
    do {
      x = f(x), y = f(f(y));
      d = __gcd<uint64_t>((x - y).get(), n);
    } while (d == 1);
    if (d < n) return d;
  }
  assert(0);
}

vector<uint64_t> prime_factor(uint64_t n) {
  if (n <= 1) return {};
  uint64_t p;
  if (n <= (1LL << 30))
    p = pollard_rho<ArbitraryLazyMontgomeryModInt>(n);
  else
    p = pollard_rho<montgomery64>(n);
  if (p == n) return {p};
  auto l = prime_factor(p);
  auto r = prime_factor(n / p);
  copy(begin(r), end(r), back_inserter(l));
  return l;
}

/**
 * @brief 高速素因数分解(Miller Rabin/Pollard's Rho)
 * @docs docs/prime-factorization.md
 */

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "math/prime-factor.hpp"
#include <bits/stdc++.h>
using namespace std;

#line 3 "modint/arbitrary-prime-modint.hpp"
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
#line 3 "modint/modint-montgomery64.hpp"
using namespace std;

struct montgomery64 {
  using mint = montgomery64;
  using i64 = int64_t;
  using u64 = uint64_t;
  using u128 = __uint128_t;

  static u64 mod;
  static u64 r;
  static u64 n2;

  static u64 get_r() {
    u64 ret = mod;
    for (i64 i = 0; i < 5; ++i) ret *= 2 - mod * ret;
    return ret;
  }

  static void set_mod(u64 m) {
    assert(m < (1LL << 62));
    assert((m & 1) == 1);
    mod = m;
    n2 = -u128(m) % m;
    r = get_r();
    assert(r * mod == 1);
  }

  u64 a;

  montgomery64() : a(0) {}
  montgomery64(const int64_t &b) : a(reduce((u128(b) + mod) * n2)){};

  static u64 reduce(const u128 &b) {
    return (b + u128(u64(b) * u64(-r)) * mod) >> 64;
  }

  mint &operator+=(const mint &b) {
    if (i64(a += b.a - 2 * mod) < 0) a += 2 * mod;
    return *this;
  }

  mint &operator-=(const mint &b) {
    if (i64(a -= b.a) < 0) a += 2 * mod;
    return *this;
  }

  mint &operator*=(const mint &b) {
    a = reduce(u128(a) * b.a);
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

  mint pow(u128 n) const {
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
    b = montgomery64(t);
    return (is);
  }

  mint inverse() const { return pow(mod - 2); }

  u64 get() const {
    u64 ret = reduce(a);
    return ret >= mod ? ret - mod : ret;
  }

  static u64 get_mod() { return mod; }
};
typename montgomery64::u64 montgomery64::mod, montgomery64::r, montgomery64::n2;
#line 7 "math/prime-factor.hpp"

template <typename mint>
bool miller_rabin(uint64_t n, vector<uint64_t> as) {
  mint::set_mod(n);
  uint64_t d = n - 1;
  while (d % 2 == 0) d /= 2;
  mint e{1}, rev{int64_t(n - 1)};
  for (uint64_t a : as) {
    if (n <= a) break;
    uint64_t t = d;
    mint y = mint(a).pow(t);
    while (t != n - 1 && y != e && y != rev) {
      y *= y;
      t *= 2;
    }
    if (y != rev && t % 2 == 0) return false;
  }
  return true;
}

bool is_prime(uint64_t n) {
  if (n == 2) return true;
  if (n <= 1 || n % 2 == 0) return false;
  if (n < (1LL << 30))
    return miller_rabin<ArbitraryLazyMontgomeryModInt>(n, {2, 7, 61});
  else
    return miller_rabin<montgomery64>(
        n, {2, 325, 9375, 28178, 450775, 9780504, 1795265022});
}

template <typename mint>
uint64_t pollard_rho(uint64_t n) {
  if (is_prime(n)) return n;
  if (n % 2 == 0) return 2;
  mint::set_mod(n);
  uint64_t d;
  mint one{1}, c{1};
  auto f = [&](mint x) { return x * x + c; };
  for (;; c += one) {
    mint x{2}, y{2};
    do {
      x = f(x), y = f(f(y));
      d = __gcd<uint64_t>((x - y).get(), n);
    } while (d == 1);
    if (d < n) return d;
  }
  assert(0);
}

vector<uint64_t> prime_factor(uint64_t n) {
  if (n <= 1) return {};
  uint64_t p;
  if (n <= (1LL << 30))
    p = pollard_rho<ArbitraryLazyMontgomeryModInt>(n);
  else
    p = pollard_rho<montgomery64>(n);
  if (p == n) return {p};
  auto l = prime_factor(p);
  auto r = prime_factor(n / p);
  copy(begin(r), end(r), back_inserter(l));
  return l;
}

/**
 * @brief 高速素因数分解(Miller Rabin/Pollard's Rho)
 * @docs docs/prime-factorization.md
 */

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

