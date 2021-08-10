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
  - icon: ':warning:'
    path: tree/tree-hash.hpp
    title: "\u6839\u4ED8\u304D\u6728\u306E\u30CF\u30C3\u30B7\u30E5"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-alds/verify-aoj-alds-14-c.test.cpp
    title: verify/verify-aoj-alds/verify-aoj-alds-14-c.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-string/yosupo-enumerate-palindromes-roriha.test.cpp
    title: verify/verify-yosupo-string/yosupo-enumerate-palindromes-roriha.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-string/yosupo-zalgo-rollinghash.test.cpp
    title: verify/verify-yosupo-string/yosupo-zalgo-rollinghash.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/inner/inner-hash.md
    document_title: "\u30CF\u30C3\u30B7\u30E5\u69CB\u9020\u4F53"
    links: []
  bundledCode: "#line 2 \"inner/inner-hash.hpp\"\n\nnamespace inner {\nusing u64 =\
    \ unsigned long long;\nusing u128 = __uint128_t;\n\ntemplate <int BASE_NUM = 2>\n\
    struct Hash : array<u64, BASE_NUM> {\n  using array<u64, BASE_NUM>::operator[];\n\
    \  static constexpr int n = BASE_NUM;\n\n  Hash() : array<u64, BASE_NUM>() {}\n\
    \n  static constexpr u64 md = (1ull << 61) - 1;\n\n  constexpr static Hash set(const\
    \ long long &a) {\n    Hash res;\n    for (int i = 0; i < n; i++) res[i] = cast(a);\n\
    \    return res;\n  }\n  Hash &operator+=(const Hash &r) {\n    for (int i = 0;\
    \ i < n; i++)\n      if (((*this)[i] += r[i]) >= md) (*this)[i] -= md;\n    return\
    \ *this;\n  }\n  Hash &operator+=(const u64 &r) {\n    for (int i = 0; i < n;\
    \ i++)\n      if (((*this)[i] += r) >= md) (*this)[i] -= md;\n    return *this;\n\
    \  }\n  Hash &operator-=(const Hash &r) {\n    for (int i = 0; i < n; i++)\n \
    \     if (((*this)[i] += md - r[i]) >= md) (*this)[i] -= md;\n    return *this;\n\
    \  }\n  Hash &operator-=(const u64 &r) {\n    for (int i = 0; i < n; i++)\n  \
    \    if (((*this)[i] += md - r) >= md) (*this)[i] -= md;\n    return *this;\n\
    \  }\n  inline Hash &operator*=(const Hash &r) {\n    for (int i = 0; i < n; i++)\
    \ (*this)[i] = modmul((*this)[i], r[i]);\n    return *this;\n  }\n  Hash operator+(const\
    \ Hash &r) { return Hash(*this) += r; }\n  Hash operator+(const u64 &r) { return\
    \ Hash(*this) += r; }\n  Hash operator-(const Hash &r) { return Hash(*this) -=\
    \ r; }\n  Hash operator-(const u64 &r) { return Hash(*this) -= r; }\n  inline\
    \ Hash operator*(const Hash &r) { return Hash(*this) *= r; }\n  Hash operator-()\
    \ const {\n    Hash res;\n    for (int i = 0; i < n; i++) res[i] = (*this)[i]\
    \ == 0 ? 0 : md - (*this)[i];\n    return res;\n  }\n  friend Hash pfma(const\
    \ Hash &a, const Hash &b, const Hash &c) {\n    Hash res;\n    for (int i = 0;\
    \ i < n; i++) res[i] = modfma(a[i], b[i], c[i]);\n    return res;\n  }\n  friend\
    \ Hash pfma(const Hash &a, const Hash &b, const long long &c) {\n    Hash res;\n\
    \    for (int i = 0; i < n; i++) res[i] = modfma(a[i], b[i], cast(c));\n    return\
    \ res;\n  }\n\n  static Hash get_basis() {\n    static auto rand_time =\n    \
    \    chrono::duration_cast<chrono::nanoseconds>(\n            chrono::high_resolution_clock::now().time_since_epoch())\n\
    \            .count();\n    static mt19937_64 rng(rand_time);\n    Hash h;\n \
    \   for (int i = 0; i < n; i++) {\n      while (isPrimitive(h[i] = rng() % (md\
    \ - 1) + 1) == false)\n        ;\n    }\n    return h;\n  }\n\n private:\n  static\
    \ u64 modpow(u64 a, u64 b) {\n    u64 r = 1;\n    for (a %= md; b; a = modmul(a,\
    \ a), b >>= 1) r = modmul(r, a);\n    return r;\n  }\n  static bool isPrimitive(u64\
    \ x) {\n    for (auto &d : vector<u64>{2, 3, 5, 7, 11, 13, 31, 41, 61, 151, 331,\
    \ 1321})\n      if (modpow(x, (md - 1) / d) <= 1) return false;\n    return true;\n\
    \  }\n  static inline constexpr u64 cast(const long long &a) {\n    return a <\
    \ 0 ? a + md : a;\n  }\n  static inline constexpr u64 modmul(const u64 &a, const\
    \ u64 &b) {\n    u128 ret = u128(a) * b;\n    ret = (ret & md) + (ret >> 61);\n\
    \    return ret >= md ? ret - md : ret;\n  }\n  static inline constexpr u64 modfma(const\
    \ u64 &a, const u64 &b, const u64 &c) {\n    u128 ret = u128(a) * b + c;\n   \
    \ ret = (ret & md) + (ret >> 61);\n    return ret >= md ? ret - md : ret;\n  }\n\
    };\n\n}  // namespace inner\n\n/**\n * @brief \u30CF\u30C3\u30B7\u30E5\u69CB\u9020\
    \u4F53\n * @docs docs/inner/inner-hash.md\n */\n"
  code: "#pragma once\n\nnamespace inner {\nusing u64 = unsigned long long;\nusing\
    \ u128 = __uint128_t;\n\ntemplate <int BASE_NUM = 2>\nstruct Hash : array<u64,\
    \ BASE_NUM> {\n  using array<u64, BASE_NUM>::operator[];\n  static constexpr int\
    \ n = BASE_NUM;\n\n  Hash() : array<u64, BASE_NUM>() {}\n\n  static constexpr\
    \ u64 md = (1ull << 61) - 1;\n\n  constexpr static Hash set(const long long &a)\
    \ {\n    Hash res;\n    for (int i = 0; i < n; i++) res[i] = cast(a);\n    return\
    \ res;\n  }\n  Hash &operator+=(const Hash &r) {\n    for (int i = 0; i < n; i++)\n\
    \      if (((*this)[i] += r[i]) >= md) (*this)[i] -= md;\n    return *this;\n\
    \  }\n  Hash &operator+=(const u64 &r) {\n    for (int i = 0; i < n; i++)\n  \
    \    if (((*this)[i] += r) >= md) (*this)[i] -= md;\n    return *this;\n  }\n\
    \  Hash &operator-=(const Hash &r) {\n    for (int i = 0; i < n; i++)\n      if\
    \ (((*this)[i] += md - r[i]) >= md) (*this)[i] -= md;\n    return *this;\n  }\n\
    \  Hash &operator-=(const u64 &r) {\n    for (int i = 0; i < n; i++)\n      if\
    \ (((*this)[i] += md - r) >= md) (*this)[i] -= md;\n    return *this;\n  }\n \
    \ inline Hash &operator*=(const Hash &r) {\n    for (int i = 0; i < n; i++) (*this)[i]\
    \ = modmul((*this)[i], r[i]);\n    return *this;\n  }\n  Hash operator+(const\
    \ Hash &r) { return Hash(*this) += r; }\n  Hash operator+(const u64 &r) { return\
    \ Hash(*this) += r; }\n  Hash operator-(const Hash &r) { return Hash(*this) -=\
    \ r; }\n  Hash operator-(const u64 &r) { return Hash(*this) -= r; }\n  inline\
    \ Hash operator*(const Hash &r) { return Hash(*this) *= r; }\n  Hash operator-()\
    \ const {\n    Hash res;\n    for (int i = 0; i < n; i++) res[i] = (*this)[i]\
    \ == 0 ? 0 : md - (*this)[i];\n    return res;\n  }\n  friend Hash pfma(const\
    \ Hash &a, const Hash &b, const Hash &c) {\n    Hash res;\n    for (int i = 0;\
    \ i < n; i++) res[i] = modfma(a[i], b[i], c[i]);\n    return res;\n  }\n  friend\
    \ Hash pfma(const Hash &a, const Hash &b, const long long &c) {\n    Hash res;\n\
    \    for (int i = 0; i < n; i++) res[i] = modfma(a[i], b[i], cast(c));\n    return\
    \ res;\n  }\n\n  static Hash get_basis() {\n    static auto rand_time =\n    \
    \    chrono::duration_cast<chrono::nanoseconds>(\n            chrono::high_resolution_clock::now().time_since_epoch())\n\
    \            .count();\n    static mt19937_64 rng(rand_time);\n    Hash h;\n \
    \   for (int i = 0; i < n; i++) {\n      while (isPrimitive(h[i] = rng() % (md\
    \ - 1) + 1) == false)\n        ;\n    }\n    return h;\n  }\n\n private:\n  static\
    \ u64 modpow(u64 a, u64 b) {\n    u64 r = 1;\n    for (a %= md; b; a = modmul(a,\
    \ a), b >>= 1) r = modmul(r, a);\n    return r;\n  }\n  static bool isPrimitive(u64\
    \ x) {\n    for (auto &d : vector<u64>{2, 3, 5, 7, 11, 13, 31, 41, 61, 151, 331,\
    \ 1321})\n      if (modpow(x, (md - 1) / d) <= 1) return false;\n    return true;\n\
    \  }\n  static inline constexpr u64 cast(const long long &a) {\n    return a <\
    \ 0 ? a + md : a;\n  }\n  static inline constexpr u64 modmul(const u64 &a, const\
    \ u64 &b) {\n    u128 ret = u128(a) * b;\n    ret = (ret & md) + (ret >> 61);\n\
    \    return ret >= md ? ret - md : ret;\n  }\n  static inline constexpr u64 modfma(const\
    \ u64 &a, const u64 &b, const u64 &c) {\n    u128 ret = u128(a) * b + c;\n   \
    \ ret = (ret & md) + (ret >> 61);\n    return ret >= md ? ret - md : ret;\n  }\n\
    };\n\n}  // namespace inner\n\n/**\n * @brief \u30CF\u30C3\u30B7\u30E5\u69CB\u9020\
    \u4F53\n * @docs docs/inner/inner-hash.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: inner/inner-hash.hpp
  requiredBy:
  - tree/tree-hash.hpp
  - string/rolling-hash.hpp
  - string/rolling-hash-2d.hpp
  timestamp: '2021-04-30 22:00:26+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-alds/verify-aoj-alds-14-c.test.cpp
  - verify/verify-yosupo-string/yosupo-zalgo-rollinghash.test.cpp
  - verify/verify-yosupo-string/yosupo-enumerate-palindromes-roriha.test.cpp
documentation_of: inner/inner-hash.hpp
layout: document
redirect_from:
- /library/inner/inner-hash.hpp
- /library/inner/inner-hash.hpp.html
title: "\u30CF\u30C3\u30B7\u30E5\u69CB\u9020\u4F53"
---
## ハッシュ構造体

$2^{61}-1$を法とするハッシュのライブラリ。

#### 使い方

- `Hash set(long long a)`: `a`に対応するハッシュを生成。
- `Hash get_basis()`: ランダムなハッシュを生成。(要素は原始根でないことが保証される。)
- `+,-,*,+=,-=,*=`: 加算・減算・乗算用の関数。
- `Hash pfma(Hash a,Hash b,T c)`: `fma`用の関数。(あまり効果はない)`T`は`hash`または`long long`。
