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
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"inner/inner-hash.hpp\"\n\nnamespace inner {\nusing u64 =\
    \ unsigned long long;\nusing u128 = __uint128_t;\n\ntemplate <int BASE_NUM>\n\
    struct Hash : array<u64, BASE_NUM> {\n  using array<u64, BASE_NUM>::operator[];\n\
    \  static constexpr int n = BASE_NUM;\n\n  Hash() : array<u64, BASE_NUM>() {}\n\
    \n  static constexpr u64 md = (1ull << 61) - 1;\n\n  static u64 cast(const int64_t\
    \ &a) { return a < 0 ? a + md : a; }\n\n  static inline constexpr u64 modmul(const\
    \ u64 &a, const u64 &b) {\n    u128 ret = u128(a) * b;\n    ret = (ret & md) +\
    \ (ret >> 61);\n    return ret >= md ? ret - md : ret;\n  }\n  static inline constexpr\
    \ u64 modfma(const u64 &a, const u64 &b, const u64 &c) {\n    u128 ret = u128(a)\
    \ * b + c;\n    ret = (ret & md) + (ret >> 61);\n    return ret >= md ? ret -\
    \ md : ret;\n  }\n  constexpr static Hash set(u64 a) {\n    Hash res;\n    for\
    \ (int i = 0; i < n; i++) res[i] = a;\n    return res;\n  }\n  Hash &operator+=(const\
    \ Hash &r) {\n    for (int i = 0; i < n; i++)\n      if (((*this)[i] += r[i])\
    \ >= md) (*this)[i] -= md;\n    return *this;\n  }\n  Hash &operator+=(const u64\
    \ &r) {\n    for (int i = 0; i < n; i++)\n      if (((*this)[i] += r) >= md) (*this)[i]\
    \ -= md;\n    return *this;\n  }\n  Hash &operator-=(const Hash &r) {\n    for\
    \ (int i = 0; i < n; i++)\n      if (((*this)[i] += md - r[i]) >= md) (*this)[i]\
    \ -= md;\n    return *this;\n  }\n  Hash &operator-=(const u64 &r) {\n    for\
    \ (int i = 0; i < n; i++)\n      if (((*this)[i] += md - r) >= md) (*this)[i]\
    \ -= md;\n    return *this;\n  }\n  inline Hash &operator*=(const Hash &r) {\n\
    \    for (int i = 0; i < n; i++) (*this)[i] = modmul((*this)[i], r[i]);\n    return\
    \ *this;\n  }\n  Hash operator+(const Hash &r) { return Hash(*this) += r; }\n\
    \  Hash operator+(const u64 &r) { return Hash(*this) += r; }\n  Hash operator-(const\
    \ Hash &r) { return Hash(*this) -= r; }\n  Hash operator-(const u64 &r) { return\
    \ Hash(*this) -= r; }\n  inline Hash operator*(const Hash &r) { return Hash(*this)\
    \ *= r; }\n  Hash operator-() const {\n    Hash res;\n    for (int i = 0; i <\
    \ n; i++) res[i] = (*this)[i] == 0 ? 0 : md - (*this)[i];\n    return res;\n \
    \ }\n  friend Hash pfma(const Hash &a, const Hash &b, const Hash &c) {\n    Hash\
    \ res;\n    for (int i = 0; i < n; i++) res[i] = modfma(a[i], b[i], c[i]);\n \
    \   return res;\n  }\n  friend Hash pfma(const Hash &a, const Hash &b, const u64\
    \ &c) {\n    Hash res;\n    for (int i = 0; i < n; i++) res[i] = modfma(a[i],\
    \ b[i], c);\n    return res;\n  }\n\n  static Hash get_basis() {\n    constexpr\
    \ u64 ds[] = {2, 3, 5, 7, 11, 13, 31, 41, 61, 151, 331, 1321};\n    static auto\
    \ rand_time =\n        chrono::duration_cast<chrono::nanoseconds>(\n         \
    \   chrono::high_resolution_clock::now().time_since_epoch())\n            .count();\n\
    \    static mt19937_64 rng(rand_time);\n\n    auto modpow = [&](u64 a, u64 b)\
    \ {\n      u64 r = 1;\n      for (a %= md; b; a = modmul(a, a), b >>= 1) r = modmul(r,\
    \ a);\n      return r;\n    };\n    auto isPrimitive = [&](u64 x) {\n      for\
    \ (auto &d : ds)\n        if (modpow(x, (md - 1) / d) <= 1) return false;\n  \
    \    return true;\n    };\n\n    Hash h;\n    for (int i = 0; i < n; i++) {\n\
    \      while (isPrimitive(h[i] = rng() % (md - 1) + 1) == false)\n        ;\n\
    \    }\n    return h;\n  }\n};\n\n}  // namespace inner\n"
  code: "#pragma once\n\nnamespace inner {\nusing u64 = unsigned long long;\nusing\
    \ u128 = __uint128_t;\n\ntemplate <int BASE_NUM>\nstruct Hash : array<u64, BASE_NUM>\
    \ {\n  using array<u64, BASE_NUM>::operator[];\n  static constexpr int n = BASE_NUM;\n\
    \n  Hash() : array<u64, BASE_NUM>() {}\n\n  static constexpr u64 md = (1ull <<\
    \ 61) - 1;\n\n  static u64 cast(const int64_t &a) { return a < 0 ? a + md : a;\
    \ }\n\n  static inline constexpr u64 modmul(const u64 &a, const u64 &b) {\n  \
    \  u128 ret = u128(a) * b;\n    ret = (ret & md) + (ret >> 61);\n    return ret\
    \ >= md ? ret - md : ret;\n  }\n  static inline constexpr u64 modfma(const u64\
    \ &a, const u64 &b, const u64 &c) {\n    u128 ret = u128(a) * b + c;\n    ret\
    \ = (ret & md) + (ret >> 61);\n    return ret >= md ? ret - md : ret;\n  }\n \
    \ constexpr static Hash set(u64 a) {\n    Hash res;\n    for (int i = 0; i < n;\
    \ i++) res[i] = a;\n    return res;\n  }\n  Hash &operator+=(const Hash &r) {\n\
    \    for (int i = 0; i < n; i++)\n      if (((*this)[i] += r[i]) >= md) (*this)[i]\
    \ -= md;\n    return *this;\n  }\n  Hash &operator+=(const u64 &r) {\n    for\
    \ (int i = 0; i < n; i++)\n      if (((*this)[i] += r) >= md) (*this)[i] -= md;\n\
    \    return *this;\n  }\n  Hash &operator-=(const Hash &r) {\n    for (int i =\
    \ 0; i < n; i++)\n      if (((*this)[i] += md - r[i]) >= md) (*this)[i] -= md;\n\
    \    return *this;\n  }\n  Hash &operator-=(const u64 &r) {\n    for (int i =\
    \ 0; i < n; i++)\n      if (((*this)[i] += md - r) >= md) (*this)[i] -= md;\n\
    \    return *this;\n  }\n  inline Hash &operator*=(const Hash &r) {\n    for (int\
    \ i = 0; i < n; i++) (*this)[i] = modmul((*this)[i], r[i]);\n    return *this;\n\
    \  }\n  Hash operator+(const Hash &r) { return Hash(*this) += r; }\n  Hash operator+(const\
    \ u64 &r) { return Hash(*this) += r; }\n  Hash operator-(const Hash &r) { return\
    \ Hash(*this) -= r; }\n  Hash operator-(const u64 &r) { return Hash(*this) -=\
    \ r; }\n  inline Hash operator*(const Hash &r) { return Hash(*this) *= r; }\n\
    \  Hash operator-() const {\n    Hash res;\n    for (int i = 0; i < n; i++) res[i]\
    \ = (*this)[i] == 0 ? 0 : md - (*this)[i];\n    return res;\n  }\n  friend Hash\
    \ pfma(const Hash &a, const Hash &b, const Hash &c) {\n    Hash res;\n    for\
    \ (int i = 0; i < n; i++) res[i] = modfma(a[i], b[i], c[i]);\n    return res;\n\
    \  }\n  friend Hash pfma(const Hash &a, const Hash &b, const u64 &c) {\n    Hash\
    \ res;\n    for (int i = 0; i < n; i++) res[i] = modfma(a[i], b[i], c);\n    return\
    \ res;\n  }\n\n  static Hash get_basis() {\n    constexpr u64 ds[] = {2, 3, 5,\
    \ 7, 11, 13, 31, 41, 61, 151, 331, 1321};\n    static auto rand_time =\n     \
    \   chrono::duration_cast<chrono::nanoseconds>(\n            chrono::high_resolution_clock::now().time_since_epoch())\n\
    \            .count();\n    static mt19937_64 rng(rand_time);\n\n    auto modpow\
    \ = [&](u64 a, u64 b) {\n      u64 r = 1;\n      for (a %= md; b; a = modmul(a,\
    \ a), b >>= 1) r = modmul(r, a);\n      return r;\n    };\n    auto isPrimitive\
    \ = [&](u64 x) {\n      for (auto &d : ds)\n        if (modpow(x, (md - 1) / d)\
    \ <= 1) return false;\n      return true;\n    };\n\n    Hash h;\n    for (int\
    \ i = 0; i < n; i++) {\n      while (isPrimitive(h[i] = rng() % (md - 1) + 1)\
    \ == false)\n        ;\n    }\n    return h;\n  }\n};\n\n}  // namespace inner\n"
  dependsOn: []
  isVerificationFile: false
  path: inner/inner-hash.hpp
  requiredBy:
  - string/rolling-hash.hpp
  - string/rolling-hash-2d.hpp
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-string/yosupo-zalgo-rollinghash.test.cpp
  - verify/verify-yosupo-string/yosupo-enumerate-palindromes-roriha.test.cpp
  - verify/verify-aoj-alds/verify-aoj-alds-14-c.test.cpp
documentation_of: inner/inner-hash.hpp
layout: document
redirect_from:
- /library/inner/inner-hash.hpp
- /library/inner/inner-hash.hpp.html
title: inner/inner-hash.hpp
---
