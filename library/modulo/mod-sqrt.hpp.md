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


# :heavy_check_mark: mod sqrt(Tonelli-Shanks algorithm) <small>(modulo/mod-sqrt.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5dcb4a1ea5a35da52691d50c8313c333">modulo</a>
* <a href="{{ site.github.repository_url }}/blob/master/modulo/mod-sqrt.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 23:36:22+09:00





## mod sqrt(Tonelli-Shanks algorithm)

整数$a$、素数$p$に対して$x^2 \equiv a \mod p$を満たす$x$を$\mathrm{O}(\log ^2 p)$で計算するライブラリ。

#### 概要

[37zigenさんの記事](https://37zigen.com/tonelli-shank-%e3%81%ae%e3%82%a2%e3%83%ab%e3%82%b4%e3%83%aa%e3%82%ba%e3%83%a0/)を大きく参考にした。

まず、オイラーの規準により

$$a^\frac{p-1}{2} \equiv 1 \mod p$$

であることが$a$が平方剰余を持つ必要十分条件である。以降は$a$が平方剰余を持つ場合のみ考える。

$\mod p$上の原始根を$r$と置き、$x\equiv r^y,a\equiv r^b$とすると上の等式は

$$x^2 \equiv a \mod p \leftrightarrow 2y \equiv b \mod p-1$$

と言い換えられる。よって原始根がわかれば解は求まるが、原始根の計算には$\mathrm{O}(\sqrt p \log p\log \log p)$程度の計算量が必要になる。そこで、原始根を計算せずにうまく$a$を利用して$x$を計算できるように工夫をする。(つまり、$\mod p-1$の世界での計算を$\mod p$の世界での計算にうまく置き換えて解く。)

$p - 1 =s\cdot 2^t$($t$は奇数)を満たすように$s,t$を取ると、中国剰余定理より

$$2y \equiv b \mod s \wedge 2y \equiv b \mod 2^t$$

となる$y$を見つければ良いとわかる。ここで、$x,y$の初期値として

$$x_0=a^\frac{s+1}{2} \rightarrow y_0 = \frac{s+1}{2}b\mod p-1$$

を取ると、$2y_0 \equiv b \mod s, 2y_0 \equiv (s+1)b \mod 2^t$となり、$\mod s$は求める$y$に一致するので、$sb$だけずれている$\mod t$の方をうまく微調整すればよいとわかる。

ここで、$u^\frac{p-1}{2} \not\equiv 1\mod p$である$u$を乱択で選ぶと、

$$\mathrm{Ind}_r u^s \equiv0 \mod s,\ \mathrm{Ind}_r u^s \equiv 1 \mod 2$$

が従う。よって$x$に$u^s$を掛けると、$y \mod s$は変わらず$y \mod 2^t$の1ビット目が反転することになる。この$u^s$を利用して誤差を調整する。

まず、現在の$y$の誤差項$2y-b\mod 2^t$の最下位ビットは、現在の$a^{-1}x^2$を自乗していって$1$になるまでにかかった回数を$t'$としたときに$t-t'$ビット目になる。最下位ビットが分かれば、$x$に$\mathrm{pow}(u^s,2^{t-t'-1})$を掛けることで最下位ビットを$0$にすることが出来る。このアルゴリズムを用いて小さいビットから0にしていき、$a^{-1}x^2 \equiv 1$になるまで繰り返せば$x$を求めることが出来る。

計算量は、誤差調整の1回あたり$\mathrm{O}(\log p)$で最大$t=\mathrm{O}(\log p)$回かかるので全体で$\mathrm{O}(\log ^2 p)$となる。


## Depends on

* :heavy_check_mark: <a href="../modint/arbitrary-prime-modint.hpp.html">modint/arbitrary-prime-modint.hpp</a>


## Required by

* :heavy_check_mark: <a href="../fps/fps-sqrt.hpp.html">平方根 <small>(fps/fps-sqrt.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-fps/yosupo-sqrt.test.cpp.html">verify/verify-yosupo-fps/yosupo-sqrt.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-math/yosupo-mod-sqrt.test.cpp.html">verify/verify-yosupo-math/yosupo-mod-sqrt.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include "../modint/arbitrary-prime-modint.hpp"

int64_t mod_sqrt(const int64_t &a, const int64_t &p) {
  assert(0 <= a && a < p);
  if (a < 2) return a;
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

/**
 * @brief mod sqrt(Tonelli-Shanks algorithm)
 * @docs docs/modulo/mod-sqrt.md
 */

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
#line 3 "modulo/mod-sqrt.hpp"

int64_t mod_sqrt(const int64_t &a, const int64_t &p) {
  assert(0 <= a && a < p);
  if (a < 2) return a;
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

/**
 * @brief mod sqrt(Tonelli-Shanks algorithm)
 * @docs docs/modulo/mod-sqrt.md
 */

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

