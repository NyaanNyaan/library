---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/rolling-hash-2d.hpp
    title: "\u4E8C\u6B21\u5143Rolling Hash"
  - icon: ':heavy_check_mark:'
    path: string/rolling-hash.hpp
    title: Rolling Hash
  - icon: ':heavy_check_mark:'
    path: tree/tree-hash.hpp
    title: "\u6839\u4ED8\u304D\u6728\u306E\u30CF\u30C3\u30B7\u30E5"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-alds/verify-aoj-alds-14-c.test.cpp
    title: verify/verify-aoj-alds/verify-aoj-alds-14-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-1613.test.cpp
    title: verify/verify-aoj-other/aoj-1613.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/inner-hash.test.cpp
    title: verify/verify-unit-test/inner-hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/string-search.test.cpp
    title: verify/verify-unit-test/string-search.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-tree-hash.test.cpp
    title: verify/verify-yosupo-graph/yosupo-tree-hash.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-string/yosupo-enumerate-palindromes-roriha.test.cpp
    title: verify/verify-yosupo-string/yosupo-enumerate-palindromes-roriha.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-string/yosupo-zalgo-rollinghash.test.cpp
    title: verify/verify-yosupo-string/yosupo-zalgo-rollinghash.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1789.test.cpp
    title: verify/verify-yuki/yuki-1789.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/internal/internal-hash.md
    document_title: "\u30CF\u30C3\u30B7\u30E5\u69CB\u9020\u4F53"
    links: []
  bundledCode: "#line 2 \"internal/internal-hash.hpp\"\n\nnamespace internal {\nusing\
    \ i64 = long long;\nusing u64 = unsigned long long;\nusing u128 = __uint128_t;\n\
    \ntemplate <int BASE_NUM = 2>\nstruct Hash : array<u64, BASE_NUM> {\n  using array<u64,\
    \ BASE_NUM>::operator[];\n  static constexpr int n = BASE_NUM;\n\n  Hash() : array<u64,\
    \ BASE_NUM>() {}\n\n  static constexpr u64 md = (1ull << 61) - 1;\n\n  constexpr\
    \ static Hash set(const i64 &a) {\n    Hash res;\n    fill(begin(res), end(res),\
    \ cast(a));\n    return res;\n  }\n  Hash &operator+=(const Hash &r) {\n    for\
    \ (int i = 0; i < n; i++)\n      if (((*this)[i] += r[i]) >= md) (*this)[i] -=\
    \ md;\n    return *this;\n  }\n  Hash &operator+=(const i64 &r) {\n    u64 s =\
    \ cast(r);\n    for (int i = 0; i < n; i++)\n      if (((*this)[i] += s) >= md)\
    \ (*this)[i] -= md;\n    return *this;\n  }\n  Hash &operator-=(const Hash &r)\
    \ {\n    for (int i = 0; i < n; i++)\n      if (((*this)[i] += md - r[i]) >= md)\
    \ (*this)[i] -= md;\n    return *this;\n  }\n  Hash &operator-=(const i64 &r)\
    \ {\n    u64 s = cast(r);\n    for (int i = 0; i < n; i++)\n      if (((*this)[i]\
    \ += md - s) >= md) (*this)[i] -= md;\n    return *this;\n  }\n  Hash &operator*=(const\
    \ Hash &r) {\n    for (int i = 0; i < n; i++) (*this)[i] = modmul((*this)[i],\
    \ r[i]);\n    return *this;\n  }\n  Hash &operator*=(const i64 &r) {\n    u64\
    \ s = cast(r);\n    for (int i = 0; i < n; i++) (*this)[i] = modmul((*this)[i],\
    \ s);\n    return *this;\n  }\n\n  Hash operator+(const Hash &r) { return Hash(*this)\
    \ += r; }\n  Hash operator+(const i64 &r) { return Hash(*this) += r; }\n  Hash\
    \ operator-(const Hash &r) { return Hash(*this) -= r; }\n  Hash operator-(const\
    \ i64 &r) { return Hash(*this) -= r; }\n  Hash operator*(const Hash &r) { return\
    \ Hash(*this) *= r; }\n  Hash operator*(const i64 &r) { return Hash(*this) *=\
    \ r; }\n  Hash operator-() const {\n    Hash res;\n    for (int i = 0; i < n;\
    \ i++) res[i] = (*this)[i] == 0 ? 0 : md - (*this)[i];\n    return res;\n  }\n\
    \  friend Hash pfma(const Hash &a, const Hash &b, const Hash &c) {\n    Hash res;\n\
    \    for (int i = 0; i < n; i++) res[i] = modfma(a[i], b[i], c[i]);\n    return\
    \ res;\n  }\n  friend Hash pfma(const Hash &a, const Hash &b, const i64 &c) {\n\
    \    Hash res;\n    u64 s = cast(c);\n    for (int i = 0; i < n; i++) res[i] =\
    \ modfma(a[i], b[i], s);\n    return res;\n  }\n\n  Hash pow(long long e) {\n\
    \    Hash a{*this}, res{Hash::set(1)};\n    for (; e; a *= a, e >>= 1) {\n   \
    \   if (e & 1) res *= a;\n    }\n    return res;\n  }\n\n  static Hash get_basis()\
    \ {\n    static auto rand_time =\n        chrono::duration_cast<chrono::nanoseconds>(\n\
    \            chrono::high_resolution_clock::now().time_since_epoch())\n      \
    \      .count();\n    static mt19937_64 rng(rand_time);\n    Hash h;\n    for\
    \ (int i = 0; i < n; i++) {\n      while (isPrimitive(h[i] = rng() % (md - 1)\
    \ + 1) == false)\n        ;\n    }\n    return h;\n  }\n\n private:\n  static\
    \ u64 modpow(u64 a, u64 b) {\n    u64 r = 1;\n    for (a %= md; b; a = modmul(a,\
    \ a), b >>= 1) r = modmul(r, a);\n    return r;\n  }\n  static bool isPrimitive(u64\
    \ x) {\n    for (auto &d : vector<u64>{2, 3, 5, 7, 11, 13, 31, 41, 61, 151, 331,\
    \ 1321})\n      if (modpow(x, (md - 1) / d) <= 1) return false;\n    return true;\n\
    \  }\n  static inline constexpr u64 cast(const long long &a) {\n    return a <\
    \ 0 ? a + md : a;\n  }\n  static inline constexpr u64 modmul(const u64 &a, const\
    \ u64 &b) { \n    u128 d = u128(a) * b;\n    u64 ret = (u64(d) & md) + u64(d >>\
    \ 61);\n    return ret >= md ? ret - md : ret;\n  }\n  static inline constexpr\
    \ u64 modfma(const u64 &a, const u64 &b, const u64 &c) {\n    u128 d = u128(a)\
    \ * b + c;\n    u64 ret = (d >> 61) + (u64(d) & md);\n    return ret >= md ? ret\
    \ - md : ret;\n  }\n};\n\n}  // namespace internal\n\n/**\n * @brief \u30CF\u30C3\
    \u30B7\u30E5\u69CB\u9020\u4F53\n * @docs docs/internal/internal-hash.md\n */\n"
  code: "#pragma once\n\nnamespace internal {\nusing i64 = long long;\nusing u64 =\
    \ unsigned long long;\nusing u128 = __uint128_t;\n\ntemplate <int BASE_NUM = 2>\n\
    struct Hash : array<u64, BASE_NUM> {\n  using array<u64, BASE_NUM>::operator[];\n\
    \  static constexpr int n = BASE_NUM;\n\n  Hash() : array<u64, BASE_NUM>() {}\n\
    \n  static constexpr u64 md = (1ull << 61) - 1;\n\n  constexpr static Hash set(const\
    \ i64 &a) {\n    Hash res;\n    fill(begin(res), end(res), cast(a));\n    return\
    \ res;\n  }\n  Hash &operator+=(const Hash &r) {\n    for (int i = 0; i < n; i++)\n\
    \      if (((*this)[i] += r[i]) >= md) (*this)[i] -= md;\n    return *this;\n\
    \  }\n  Hash &operator+=(const i64 &r) {\n    u64 s = cast(r);\n    for (int i\
    \ = 0; i < n; i++)\n      if (((*this)[i] += s) >= md) (*this)[i] -= md;\n   \
    \ return *this;\n  }\n  Hash &operator-=(const Hash &r) {\n    for (int i = 0;\
    \ i < n; i++)\n      if (((*this)[i] += md - r[i]) >= md) (*this)[i] -= md;\n\
    \    return *this;\n  }\n  Hash &operator-=(const i64 &r) {\n    u64 s = cast(r);\n\
    \    for (int i = 0; i < n; i++)\n      if (((*this)[i] += md - s) >= md) (*this)[i]\
    \ -= md;\n    return *this;\n  }\n  Hash &operator*=(const Hash &r) {\n    for\
    \ (int i = 0; i < n; i++) (*this)[i] = modmul((*this)[i], r[i]);\n    return *this;\n\
    \  }\n  Hash &operator*=(const i64 &r) {\n    u64 s = cast(r);\n    for (int i\
    \ = 0; i < n; i++) (*this)[i] = modmul((*this)[i], s);\n    return *this;\n  }\n\
    \n  Hash operator+(const Hash &r) { return Hash(*this) += r; }\n  Hash operator+(const\
    \ i64 &r) { return Hash(*this) += r; }\n  Hash operator-(const Hash &r) { return\
    \ Hash(*this) -= r; }\n  Hash operator-(const i64 &r) { return Hash(*this) -=\
    \ r; }\n  Hash operator*(const Hash &r) { return Hash(*this) *= r; }\n  Hash operator*(const\
    \ i64 &r) { return Hash(*this) *= r; }\n  Hash operator-() const {\n    Hash res;\n\
    \    for (int i = 0; i < n; i++) res[i] = (*this)[i] == 0 ? 0 : md - (*this)[i];\n\
    \    return res;\n  }\n  friend Hash pfma(const Hash &a, const Hash &b, const\
    \ Hash &c) {\n    Hash res;\n    for (int i = 0; i < n; i++) res[i] = modfma(a[i],\
    \ b[i], c[i]);\n    return res;\n  }\n  friend Hash pfma(const Hash &a, const\
    \ Hash &b, const i64 &c) {\n    Hash res;\n    u64 s = cast(c);\n    for (int\
    \ i = 0; i < n; i++) res[i] = modfma(a[i], b[i], s);\n    return res;\n  }\n\n\
    \  Hash pow(long long e) {\n    Hash a{*this}, res{Hash::set(1)};\n    for (;\
    \ e; a *= a, e >>= 1) {\n      if (e & 1) res *= a;\n    }\n    return res;\n\
    \  }\n\n  static Hash get_basis() {\n    static auto rand_time =\n        chrono::duration_cast<chrono::nanoseconds>(\n\
    \            chrono::high_resolution_clock::now().time_since_epoch())\n      \
    \      .count();\n    static mt19937_64 rng(rand_time);\n    Hash h;\n    for\
    \ (int i = 0; i < n; i++) {\n      while (isPrimitive(h[i] = rng() % (md - 1)\
    \ + 1) == false)\n        ;\n    }\n    return h;\n  }\n\n private:\n  static\
    \ u64 modpow(u64 a, u64 b) {\n    u64 r = 1;\n    for (a %= md; b; a = modmul(a,\
    \ a), b >>= 1) r = modmul(r, a);\n    return r;\n  }\n  static bool isPrimitive(u64\
    \ x) {\n    for (auto &d : vector<u64>{2, 3, 5, 7, 11, 13, 31, 41, 61, 151, 331,\
    \ 1321})\n      if (modpow(x, (md - 1) / d) <= 1) return false;\n    return true;\n\
    \  }\n  static inline constexpr u64 cast(const long long &a) {\n    return a <\
    \ 0 ? a + md : a;\n  }\n  static inline constexpr u64 modmul(const u64 &a, const\
    \ u64 &b) { \n    u128 d = u128(a) * b;\n    u64 ret = (u64(d) & md) + u64(d >>\
    \ 61);\n    return ret >= md ? ret - md : ret;\n  }\n  static inline constexpr\
    \ u64 modfma(const u64 &a, const u64 &b, const u64 &c) {\n    u128 d = u128(a)\
    \ * b + c;\n    u64 ret = (d >> 61) + (u64(d) & md);\n    return ret >= md ? ret\
    \ - md : ret;\n  }\n};\n\n}  // namespace internal\n\n/**\n * @brief \u30CF\u30C3\
    \u30B7\u30E5\u69CB\u9020\u4F53\n * @docs docs/internal/internal-hash.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: internal/internal-hash.hpp
  requiredBy:
  - string/rolling-hash.hpp
  - string/rolling-hash-2d.hpp
  - tree/tree-hash.hpp
  timestamp: '2023-08-10 13:25:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-alds/verify-aoj-alds-14-c.test.cpp
  - verify/verify-aoj-other/aoj-1613.test.cpp
  - verify/verify-yosupo-graph/yosupo-tree-hash.test.cpp
  - verify/verify-yosupo-string/yosupo-enumerate-palindromes-roriha.test.cpp
  - verify/verify-yosupo-string/yosupo-zalgo-rollinghash.test.cpp
  - verify/verify-yuki/yuki-1789.test.cpp
  - verify/verify-unit-test/string-search.test.cpp
  - verify/verify-unit-test/inner-hash.test.cpp
documentation_of: internal/internal-hash.hpp
layout: document
redirect_from:
- /library/internal/internal-hash.hpp
- /library/internal/internal-hash.hpp.html
title: "\u30CF\u30C3\u30B7\u30E5\u69CB\u9020\u4F53"
---
## ハッシュ構造体

$2^{61}-1$ を法とするハッシュのライブラリ。

ハッシュは単位的環としていて実装されている。また、ハッシュに $\mathbb{Z} / (2^{61} - 1) \mathbb{Z}$ 上の要素を作用させることもできる。

#### 関数

- `Hash set(long long a)`: `a`に対応するハッシュを生成。
- `Hash get_basis()`: ランダムなハッシュを生成。(要素は原始根であることが保証される。)
- `+,-,*,+=,-=,*=`: 加算・減算・乗算用の関数。
- `Hash pfma(Hash a, Hash b, T c)`: `fma` 用の関数。`T` は` hash` または `long long` 。
