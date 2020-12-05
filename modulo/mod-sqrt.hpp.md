---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: modint/arbitrary-prime-modint.hpp
    title: modint/arbitrary-prime-modint.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/fps-sqrt.hpp
    title: "\u5E73\u65B9\u6839"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-sqrt.test.cpp
    title: verify/verify-yosupo-fps/yosupo-sqrt.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-mod-sqrt.test.cpp
    title: verify/verify-yosupo-math/yosupo-mod-sqrt.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/modulo/mod-sqrt.md
    document_title: mod sqrt(Tonelli-Shanks algorithm)
    links: []
  bundledCode: "#line 2 \"modint/arbitrary-prime-modint.hpp\"\n\n\n\nstruct ArbitraryLazyMontgomeryModInt\
    \ {\n  using mint = ArbitraryLazyMontgomeryModInt;\n  using i32 = int32_t;\n \
    \ using u32 = uint32_t;\n  using u64 = uint64_t;\n\n  static u32 mod;\n  static\
    \ u32 r;\n  static u32 n2;\n\n  static u32 get_r() {\n    u32 ret = mod;\n   \
    \ for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;\n    return ret;\n  }\n\n\
    \  static void set_mod(u32 m) {\n    assert(m < (1 << 30));\n    assert((m & 1)\
    \ == 1);\n    mod = m;\n    n2 = -u64(m) % m;\n    r = get_r();\n    assert(r\
    \ * mod == 1);\n  }\n\n  u32 a;\n\n  ArbitraryLazyMontgomeryModInt() : a(0) {}\n\
    \  ArbitraryLazyMontgomeryModInt(const int64_t &b)\n      : a(reduce(u64(b % mod\
    \ + mod) * n2)){};\n\n  static u32 reduce(const u64 &b) {\n    return (b + u64(u32(b)\
    \ * u32(-r)) * mod) >> 32;\n  }\n\n  mint &operator+=(const mint &b) {\n    if\
    \ (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n  }\n\n  mint\
    \ &operator-=(const mint &b) {\n    if (i32(a -= b.a) < 0) a += 2 * mod;\n   \
    \ return *this;\n  }\n\n  mint &operator*=(const mint &b) {\n    a = reduce(u64(a)\
    \ * b.a);\n    return *this;\n  }\n\n  mint &operator/=(const mint &b) {\n   \
    \ *this *= b.inverse();\n    return *this;\n  }\n\n  mint operator+(const mint\
    \ &b) const { return mint(*this) += b; }\n  mint operator-(const mint &b) const\
    \ { return mint(*this) -= b; }\n  mint operator*(const mint &b) const { return\
    \ mint(*this) *= b; }\n  mint operator/(const mint &b) const { return mint(*this)\
    \ /= b; }\n  bool operator==(const mint &b) const {\n    return (a >= mod ? a\
    \ - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n  }\n  bool operator!=(const\
    \ mint &b) const {\n    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a -\
    \ mod : b.a);\n  }\n  mint operator-() const { return mint() - mint(*this); }\n\
    \n  mint pow(u64 n) const {\n    mint ret(1), mul(*this);\n    while (n > 0) {\n\
    \      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>= 1;\n    }\n    return\
    \ ret;\n  }\n\n  friend ostream &operator<<(ostream &os, const mint &b) {\n  \
    \  return os << b.get();\n  }\n\n  friend istream &operator>>(istream &is, mint\
    \ &b) {\n    int64_t t;\n    is >> t;\n    b = ArbitraryLazyMontgomeryModInt(t);\n\
    \    return (is);\n  }\n\n  mint inverse() const { return pow(mod - 2); }\n\n\
    \  u32 get() const {\n    u32 ret = reduce(a);\n    return ret >= mod ? ret -\
    \ mod : ret;\n  }\n\n  static u32 get_mod() { return mod; }\n};\ntypename ArbitraryLazyMontgomeryModInt::u32\
    \ ArbitraryLazyMontgomeryModInt::mod;\ntypename ArbitraryLazyMontgomeryModInt::u32\
    \ ArbitraryLazyMontgomeryModInt::r;\ntypename ArbitraryLazyMontgomeryModInt::u32\
    \ ArbitraryLazyMontgomeryModInt::n2;\n#line 3 \"modulo/mod-sqrt.hpp\"\n\nint64_t\
    \ mod_sqrt(const int64_t &a, const int64_t &p) {\n  assert(0 <= a && a < p);\n\
    \  if (a < 2) return a;\n  using mint = ArbitraryLazyMontgomeryModInt;\n  mint::set_mod(p);\n\
    \  if (mint(a).pow((p - 1) >> 1) != 1) return -1;\n  mint b = 1, one = 1;\n  while\
    \ (b.pow((p - 1) >> 1) == 1) b += one;\n  int64_t m = p - 1, e = 0;\n  while (m\
    \ % 2 == 0) m >>= 1, e += 1;\n  mint x = mint(a).pow((m - 1) >> 1);\n  mint y\
    \ = mint(a) * x * x;\n  x *= a;\n  mint z = mint(b).pow(m);\n  while (y != 1)\
    \ {\n    int64_t j = 0;\n    mint t = y;\n    while (t != one) {\n      j += 1;\n\
    \      t *= t;\n    }\n    z = z.pow(int64_t(1) << (e - j - 1));\n    x *= z;\n\
    \    z *= z;\n    y *= z;\n    e = j;\n  }\n  return x.get();\n}\n\n/**\n * @brief\
    \ mod sqrt(Tonelli-Shanks algorithm)\n * @docs docs/modulo/mod-sqrt.md\n */\n"
  code: "#pragma once\n#include \"../modint/arbitrary-prime-modint.hpp\"\n\nint64_t\
    \ mod_sqrt(const int64_t &a, const int64_t &p) {\n  assert(0 <= a && a < p);\n\
    \  if (a < 2) return a;\n  using mint = ArbitraryLazyMontgomeryModInt;\n  mint::set_mod(p);\n\
    \  if (mint(a).pow((p - 1) >> 1) != 1) return -1;\n  mint b = 1, one = 1;\n  while\
    \ (b.pow((p - 1) >> 1) == 1) b += one;\n  int64_t m = p - 1, e = 0;\n  while (m\
    \ % 2 == 0) m >>= 1, e += 1;\n  mint x = mint(a).pow((m - 1) >> 1);\n  mint y\
    \ = mint(a) * x * x;\n  x *= a;\n  mint z = mint(b).pow(m);\n  while (y != 1)\
    \ {\n    int64_t j = 0;\n    mint t = y;\n    while (t != one) {\n      j += 1;\n\
    \      t *= t;\n    }\n    z = z.pow(int64_t(1) << (e - j - 1));\n    x *= z;\n\
    \    z *= z;\n    y *= z;\n    e = j;\n  }\n  return x.get();\n}\n\n/**\n * @brief\
    \ mod sqrt(Tonelli-Shanks algorithm)\n * @docs docs/modulo/mod-sqrt.md\n */\n"
  dependsOn:
  - modint/arbitrary-prime-modint.hpp
  isVerificationFile: false
  path: modulo/mod-sqrt.hpp
  requiredBy:
  - fps/fps-sqrt.hpp
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-mod-sqrt.test.cpp
  - verify/verify-yosupo-fps/yosupo-sqrt.test.cpp
documentation_of: modulo/mod-sqrt.hpp
layout: document
redirect_from:
- /library/modulo/mod-sqrt.hpp
- /library/modulo/mod-sqrt.hpp.html
title: mod sqrt(Tonelli-Shanks algorithm)
---
## mod sqrt(Tonelli-Shanks algorithm)

整数$a$、素数$p$に対して$x^2 \equiv a \mod p$を満たす$x$を$\mathrm{O}(\log ^2 p)$で計算するライブラリ。

#### 概要

[37zigenさんの記事](https://37zigen.com/tonelli-shank-%e3%81%ae%e3%82%a2%e3%83%ab%e3%82%b4%e3%83%aa%e3%82%ba%e3%83%a0/)を大きく参考にした。

まず、オイラーの規準により

$$a^\frac{p-1}{2} \equiv 1 \mod p$$

であることが$a$が平方剰余を持つ必要十分条件である。以降は$a$が平方剰余を持つ場合のみ考える。

$\mod p$上の原始根を$r$と置き、$x\equiv r^y,a\equiv r^b$とすると上の等式は

$$x^2 \equiv a \mod p \leftrightarrow 2y \equiv b \mod p-1$$

と言い換えられる。よって原始根がわかれば解は求まるが、離散対数問題を解く部分が$\mathrm{O}(\sqrt{p})$程度の計算量となり遅い。そこで、原始根を計算せずにうまく$a$を利用して$x$を計算できるように工夫をする。(つまり、$\mod p-1$の世界での計算を$\mod p$の世界での計算にうまく置き換えて解く。)

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
