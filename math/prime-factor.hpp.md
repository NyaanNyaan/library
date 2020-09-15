---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: misc/rng.hpp
    title: misc/rng.hpp
  - icon: ':heavy_check_mark:'
    path: modint/arbitrary-prime-modint.hpp
    title: modint/arbitrary-prime-modint.hpp
  - icon: ':heavy_check_mark:'
    path: modint/modint-montgomery64.hpp
    title: modint/modint-montgomery64.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-factrization.test.cpp
    title: verify/verify-yosupo-math/yosupo-factrization.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    _deprecated_at_docs: docs/math/prime-factorization.md
    document_title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Miller Rabin/Pollard's\
      \ Rho)"
    links: []
  bundledCode: "#line 2 \"math/prime-factor.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n#line 3 \"misc/rng.hpp\"\nusing namespace std;\n\nunsigned\
    \ long long rng() {\n  static unsigned long long x_ = 88172645463325252ULL;\n\
    \  x_ = x_ ^ (x_ << 7);\n  return x_ = x_ ^ (x_ >> 9);\n}\n#line 3 \"modint/arbitrary-prime-modint.hpp\"\
    \nusing namespace std;\n\nstruct ArbitraryLazyMontgomeryModInt {\n  using mint\
    \ = ArbitraryLazyMontgomeryModInt;\n  using i32 = int32_t;\n  using u32 = uint32_t;\n\
    \  using u64 = uint64_t;\n\n  static u32 mod;\n  static u32 r;\n  static u32 n2;\n\
    \n  static u32 get_r() {\n    u32 ret = mod;\n    for (i32 i = 0; i < 4; ++i)\
    \ ret *= 2 - mod * ret;\n    return ret;\n  }\n\n  static void set_mod(u32 m)\
    \ {\n    assert(m < (1 << 30));\n    assert((m & 1) == 1);\n    mod = m;\n   \
    \ n2 = -u64(m) % m;\n    r = get_r();\n    assert(r * mod == 1);\n  }\n\n  u32\
    \ a;\n\n  ArbitraryLazyMontgomeryModInt() : a(0) {}\n  ArbitraryLazyMontgomeryModInt(const\
    \ int64_t &b)\n      : a(reduce(u64(b % mod + mod) * n2)){};\n\n  static u32 reduce(const\
    \ u64 &b) {\n    return (b + u64(u32(b) * u32(-r)) * mod) >> 32;\n  }\n\n  mint\
    \ &operator+=(const mint &b) {\n    if (i32(a += b.a - 2 * mod) < 0) a += 2 *\
    \ mod;\n    return *this;\n  }\n\n  mint &operator-=(const mint &b) {\n    if\
    \ (i32(a -= b.a) < 0) a += 2 * mod;\n    return *this;\n  }\n\n  mint &operator*=(const\
    \ mint &b) {\n    a = reduce(u64(a) * b.a);\n    return *this;\n  }\n\n  mint\
    \ &operator/=(const mint &b) {\n    *this *= b.inverse();\n    return *this;\n\
    \  }\n\n  mint operator+(const mint &b) const { return mint(*this) += b; }\n \
    \ mint operator-(const mint &b) const { return mint(*this) -= b; }\n  mint operator*(const\
    \ mint &b) const { return mint(*this) *= b; }\n  mint operator/(const mint &b)\
    \ const { return mint(*this) /= b; }\n  bool operator==(const mint &b) const {\n\
    \    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n  }\n\
    \  bool operator!=(const mint &b) const {\n    return (a >= mod ? a - mod : a)\
    \ != (b.a >= mod ? b.a - mod : b.a);\n  }\n  mint operator-() const { return mint()\
    \ - mint(*this); }\n\n  mint pow(u64 n) const {\n    mint ret(1), mul(*this);\n\
    \    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n\
    \ >>= 1;\n    }\n    return ret;\n  }\n\n  friend ostream &operator<<(ostream\
    \ &os, const mint &b) {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream\
    \ &is, mint &b) {\n    int64_t t;\n    is >> t;\n    b = ArbitraryLazyMontgomeryModInt(t);\n\
    \    return (is);\n  }\n\n  mint inverse() const { return pow(mod - 2); }\n\n\
    \  u32 get() const {\n    u32 ret = reduce(a);\n    return ret >= mod ? ret -\
    \ mod : ret;\n  }\n\n  static u32 get_mod() { return mod; }\n};\ntypename ArbitraryLazyMontgomeryModInt::u32\
    \ ArbitraryLazyMontgomeryModInt::mod;\ntypename ArbitraryLazyMontgomeryModInt::u32\
    \ ArbitraryLazyMontgomeryModInt::r;\ntypename ArbitraryLazyMontgomeryModInt::u32\
    \ ArbitraryLazyMontgomeryModInt::n2;\n#line 3 \"modint/modint-montgomery64.hpp\"\
    \nusing namespace std;\n\nstruct montgomery64 {\n  using mint = montgomery64;\n\
    \  using i64 = int64_t;\n  using u64 = uint64_t;\n  using u128 = __uint128_t;\n\
    \n  static u64 mod;\n  static u64 r;\n  static u64 n2;\n\n  static u64 get_r()\
    \ {\n    u64 ret = mod;\n    for (i64 i = 0; i < 5; ++i) ret *= 2 - mod * ret;\n\
    \    return ret;\n  }\n\n  static void set_mod(u64 m) {\n    assert(m < (1LL <<\
    \ 62));\n    assert((m & 1) == 1);\n    mod = m;\n    n2 = -u128(m) % m;\n   \
    \ r = get_r();\n    assert(r * mod == 1);\n  }\n\n  u64 a;\n\n  montgomery64()\
    \ : a(0) {}\n  montgomery64(const int64_t &b) : a(reduce((u128(b) + mod) * n2)){};\n\
    \n  static u64 reduce(const u128 &b) {\n    return (b + u128(u64(b) * u64(-r))\
    \ * mod) >> 64;\n  }\n\n  mint &operator+=(const mint &b) {\n    if (i64(a +=\
    \ b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n  }\n\n  mint &operator-=(const\
    \ mint &b) {\n    if (i64(a -= b.a) < 0) a += 2 * mod;\n    return *this;\n  }\n\
    \n  mint &operator*=(const mint &b) {\n    a = reduce(u128(a) * b.a);\n    return\
    \ *this;\n  }\n\n  mint &operator/=(const mint &b) {\n    *this *= b.inverse();\n\
    \    return *this;\n  }\n\n  mint operator+(const mint &b) const { return mint(*this)\
    \ += b; }\n  mint operator-(const mint &b) const { return mint(*this) -= b; }\n\
    \  mint operator*(const mint &b) const { return mint(*this) *= b; }\n  mint operator/(const\
    \ mint &b) const { return mint(*this) /= b; }\n  bool operator==(const mint &b)\
    \ const {\n    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n\
    \  }\n  bool operator!=(const mint &b) const {\n    return (a >= mod ? a - mod\
    \ : a) != (b.a >= mod ? b.a - mod : b.a);\n  }\n  mint operator-() const { return\
    \ mint() - mint(*this); }\n\n  mint pow(u128 n) const {\n    mint ret(1), mul(*this);\n\
    \    while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n\
    \ >>= 1;\n    }\n    return ret;\n  }\n\n  friend ostream &operator<<(ostream\
    \ &os, const mint &b) {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream\
    \ &is, mint &b) {\n    int64_t t;\n    is >> t;\n    b = montgomery64(t);\n  \
    \  return (is);\n  }\n\n  mint inverse() const { return pow(mod - 2); }\n\n  u64\
    \ get() const {\n    u64 ret = reduce(a);\n    return ret >= mod ? ret - mod :\
    \ ret;\n  }\n\n  static u64 get_mod() { return mod; }\n};\ntypename montgomery64::u64\
    \ montgomery64::mod, montgomery64::r, montgomery64::n2;\n#line 8 \"math/prime-factor.hpp\"\
    \n\ntemplate <typename mint>\nbool miller_rabin(uint64_t n, vector<uint64_t> as)\
    \ {\n  mint::set_mod(n);\n  uint64_t d = n - 1;\n  while (d % 2 == 0) d /= 2;\n\
    \  mint e{1}, rev{int64_t(n - 1)};\n  for (uint64_t a : as) {\n    if (n <= a)\
    \ break;\n    uint64_t t = d;\n    mint y = mint(a).pow(t);\n    while (t != n\
    \ - 1 && y != e && y != rev) {\n      y *= y;\n      t *= 2;\n    }\n    if (y\
    \ != rev && t % 2 == 0) return false;\n  }\n  return true;\n}\n\nbool is_prime(uint64_t\
    \ n) {\n  if (n == 2) return true;\n  if (n <= 1 || n % 2 == 0) return false;\n\
    \  if (n < (1LL << 30))\n    return miller_rabin<ArbitraryLazyMontgomeryModInt>(n,\
    \ {2, 7, 61});\n  else\n    return miller_rabin<montgomery64>(\n        n, {2,\
    \ 325, 9375, 28178, 450775, 9780504, 1795265022});\n}\n\ntemplate <typename mint>\n\
    uint64_t pollard_rho(uint64_t n) {\n  if (is_prime(n)) return n;\n  if (n % 2\
    \ == 0) return 2;\n  mint::set_mod(n);\n  uint64_t d;\n  mint one{1}, c{1};\n\
    \  auto f = [&](mint x) { return x * x + c; };\n  while(1) {\n    do {\n     \
    \ c = rng() % mint::get_mod();\n    } while (c == 0);\n    mint x{2}, y{2};\n\
    \    do {\n      x = f(x), y = f(f(y));\n      d = __gcd<uint64_t>((x - y).get(),\
    \ n);\n    } while (d == 1);\n    if (d < n) return d;\n  }\n  assert(0);\n}\n\
    \nvector<uint64_t> prime_factor(uint64_t n) {\n  if (n <= 1) return {};\n  uint64_t\
    \ p;\n  if (n <= (1LL << 30))\n    p = pollard_rho<ArbitraryLazyMontgomeryModInt>(n);\n\
    \  else\n    p = pollard_rho<montgomery64>(n);\n  if (p == n) return {p};\n  auto\
    \ l = prime_factor(p);\n  auto r = prime_factor(n / p);\n  copy(begin(r), end(r),\
    \ back_inserter(l));\n  return l;\n}\n\n/**\n * @brief \u9AD8\u901F\u7D20\u56E0\
    \u6570\u5206\u89E3(Miller Rabin/Pollard's Rho)\n * @docs docs/math/prime-factorization.md\n\
    \ */\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"../misc/rng.hpp\"\n#include \"../modint/arbitrary-prime-modint.hpp\"\n#include\
    \ \"../modint/modint-montgomery64.hpp\"\n\ntemplate <typename mint>\nbool miller_rabin(uint64_t\
    \ n, vector<uint64_t> as) {\n  mint::set_mod(n);\n  uint64_t d = n - 1;\n  while\
    \ (d % 2 == 0) d /= 2;\n  mint e{1}, rev{int64_t(n - 1)};\n  for (uint64_t a :\
    \ as) {\n    if (n <= a) break;\n    uint64_t t = d;\n    mint y = mint(a).pow(t);\n\
    \    while (t != n - 1 && y != e && y != rev) {\n      y *= y;\n      t *= 2;\n\
    \    }\n    if (y != rev && t % 2 == 0) return false;\n  }\n  return true;\n}\n\
    \nbool is_prime(uint64_t n) {\n  if (n == 2) return true;\n  if (n <= 1 || n %\
    \ 2 == 0) return false;\n  if (n < (1LL << 30))\n    return miller_rabin<ArbitraryLazyMontgomeryModInt>(n,\
    \ {2, 7, 61});\n  else\n    return miller_rabin<montgomery64>(\n        n, {2,\
    \ 325, 9375, 28178, 450775, 9780504, 1795265022});\n}\n\ntemplate <typename mint>\n\
    uint64_t pollard_rho(uint64_t n) {\n  if (is_prime(n)) return n;\n  if (n % 2\
    \ == 0) return 2;\n  mint::set_mod(n);\n  uint64_t d;\n  mint one{1}, c{1};\n\
    \  auto f = [&](mint x) { return x * x + c; };\n  while(1) {\n    do {\n     \
    \ c = rng() % mint::get_mod();\n    } while (c == 0);\n    mint x{2}, y{2};\n\
    \    do {\n      x = f(x), y = f(f(y));\n      d = __gcd<uint64_t>((x - y).get(),\
    \ n);\n    } while (d == 1);\n    if (d < n) return d;\n  }\n  assert(0);\n}\n\
    \nvector<uint64_t> prime_factor(uint64_t n) {\n  if (n <= 1) return {};\n  uint64_t\
    \ p;\n  if (n <= (1LL << 30))\n    p = pollard_rho<ArbitraryLazyMontgomeryModInt>(n);\n\
    \  else\n    p = pollard_rho<montgomery64>(n);\n  if (p == n) return {p};\n  auto\
    \ l = prime_factor(p);\n  auto r = prime_factor(n / p);\n  copy(begin(r), end(r),\
    \ back_inserter(l));\n  return l;\n}\n\n/**\n * @brief \u9AD8\u901F\u7D20\u56E0\
    \u6570\u5206\u89E3(Miller Rabin/Pollard's Rho)\n * @docs docs/math/prime-factorization.md\n\
    \ */\n"
  dependsOn:
  - misc/rng.hpp
  - modint/arbitrary-prime-modint.hpp
  - modint/modint-montgomery64.hpp
  isVerificationFile: false
  path: math/prime-factor.hpp
  requiredBy: []
  timestamp: '2020-09-01 02:18:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-factrization.test.cpp
documentation_of: math/prime-factor.hpp
layout: document
redirect_from:
- /library/math/prime-factor.hpp
- /library/math/prime-factor.hpp.html
title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Miller Rabin/Pollard's Rho)"
---
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