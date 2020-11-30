---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
  bundledCode: "#line 2 \"string/rolling-hash.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate <typename Str = string, int BASE_NUM = 1>\nstruct\
    \ RollingHash {\n  using u64 = unsigned long long;\n  using u128 = __uint128_t;\n\
    \n  static constexpr u64 md = (1ull << 61) - 1;\n\n  static inline constexpr u64\
    \ modmul(const u64 &a, const u64 &b) {\n    u128 ret = u128(a) * b;\n    ret =\
    \ (ret & md) + (ret >> 61);\n    return ret >= md ? ret - md : ret;\n  }\n  static\
    \ inline constexpr u64 modfma(const u64 &a, const u64 &b, const u64 &c) {\n  \
    \  u128 ret = u128(a) * b + c;\n    ret = (ret & md) + (ret >> 61);\n    return\
    \ ret >= md ? ret - md : ret;\n  }\n\n  struct Hash : array<u64, BASE_NUM> {\n\
    \    using array<u64, BASE_NUM>::operator[];\n\n    Hash() : array<u64, BASE_NUM>()\
    \ {}\n    constexpr static Hash set(u64 a) {\n      Hash res;\n      for (int\
    \ i = 0; i < BASE_NUM; i++) res[i] = a;\n      return res;\n    }\n    Hash &operator+=(const\
    \ Hash &r) {\n      for (int i = 0; i < BASE_NUM; i++)\n        if (((*this)[i]\
    \ += r[i]) >= md) (*this)[i] -= md;\n      return *this;\n    }\n    Hash &operator+=(const\
    \ u64 &r) {\n      for (int i = 0; i < BASE_NUM; i++)\n        if (((*this)[i]\
    \ += r) >= md) (*this)[i] -= md;\n      return *this;\n    }\n    Hash &operator-=(const\
    \ Hash &r) {\n      for (int i = 0; i < BASE_NUM; i++)\n        if (((*this)[i]\
    \ += md - r[i]) >= md) (*this)[i] -= md;\n      return *this;\n    }\n    Hash\
    \ &operator-=(const u64 &r) {\n      for (int i = 0; i < BASE_NUM; i++)\n    \
    \    if (((*this)[i] += md - r) >= md) (*this)[i] -= md;\n      return *this;\n\
    \    }\n    inline Hash &operator*=(const Hash &r) {\n      for (int i = 0; i\
    \ < BASE_NUM; i++) (*this)[i] = modmul((*this)[i], r[i]);\n      return *this;\n\
    \    }\n    Hash operator+(const Hash &r) { return Hash(*this) += r; }\n    Hash\
    \ operator+(const u64 &r) { return Hash(*this) += r; }\n    Hash operator-(const\
    \ Hash &r) { return Hash(*this) -= r; }\n    Hash operator-(const u64 &r) { return\
    \ Hash(*this) -= r; }\n    inline Hash operator*(const Hash &r) { return Hash(*this)\
    \ *= r; }\n    Hash operator-() const {\n      Hash res;\n      for (int i = 0;\
    \ i < BASE_NUM; i++)\n        res[i] = (*this)[i] == 0 ? 0 : md - (*this)[i];\n\
    \      return res;\n    }\n    friend Hash pfma(const Hash &a, const Hash &b,\
    \ const Hash &c) {\n      Hash res;\n      for (int i = 0; i < BASE_NUM; i++)\
    \ res[i] = modfma(a[i], b[i], c[i]);\n      return res;\n    }\n    friend Hash\
    \ pfma(const Hash &a, const Hash &b, const u64 &c) {\n      Hash res;\n      for\
    \ (int i = 0; i < BASE_NUM; i++) res[i] = modfma(a[i], b[i], c);\n      return\
    \ res;\n    }\n  };\n\n  static Hash get_basis() {\n    constexpr u64 ds[] = {2,\
    \ 3, 5, 7, 11, 13, 31, 41, 61, 151, 331, 1321};\n    static auto rand_time =\n\
    \        chrono::duration_cast<chrono::nanoseconds>(\n            chrono::high_resolution_clock::now().time_since_epoch())\n\
    \            .count();\n    static mt19937_64 rng(rand_time);\n\n    auto modpow\
    \ = [&](u64 a, u64 b) {\n      u64 r = 1;\n      for (a %= md; b; a = modmul(a,\
    \ a), b >>= 1) r = modmul(r, a);\n      return r;\n    };\n    auto isPrimitive\
    \ = [&](u64 x) {\n      for (auto &d : ds)\n        if (modpow(x, (md - 1) / d)\
    \ <= 1) return false;\n      return true;\n    };\n\n    Hash h;\n    for (int\
    \ i = 0; i < BASE_NUM; i++) {\n      while (isPrimitive(h[i] = rng() % (md - 1)\
    \ + 1) == false)\n        ;\n    }\n    return h;\n  }\n\n  Str data;\n  vector<Hash>\
    \ hs, pw;\n  int s;\n  static Hash basis;\n\n  RollingHash() { build(string());\
    \ }\n\n  RollingHash(const Str &S) { build(S); }\n\n  void build(const Str &S)\
    \ {\n    data = S;\n    s = S.size();\n    hs.resize(s + 1);\n    pw.resize(s\
    \ + 1);\n    pw[0] = Hash::set(1);\n    hs[0] = Hash::set(0);\n    for (int i\
    \ = 1; i <= s; i++) {\n      pw[i] = pw[i - 1] * basis;\n      hs[i] = pfma(hs[i\
    \ - 1], basis, u64(S[i - 1]));\n    }\n  }\n\n  Hash get(int l, int r = -1) const\
    \ {\n    if (r == -1) r = s;\n    return pfma(hs[l], -pw[r - l], hs[r]);\n  }\n\
    \n  static Hash get_hash(const Str &T) {\n    Hash ret = Hash::set(0);\n    for\
    \ (int i = 0; i < (int)T.size(); i++) ret = pfma(ret, basis, u64(T[i]));\n   \
    \ return ret;\n  }\n\n  int find(Str &T, int lower = 0) const {\n    auto ths\
    \ = get_hash(T);\n    for (int i = lower; i <= s - (int)T.size(); i++)\n     \
    \ if (ths == get(i, i + (int)T.size())) return i;\n    return -1;\n  }\n\n  friend\
    \ int LCP(const RollingHash &a, const RollingHash &b, int al, int bl) {\n    int\
    \ ok = 0, ng = min(a.size() - al, b.size() - bl) + 1;\n    while (ok + 1 < ng)\
    \ {\n      int med = (ok + ng) / 2;\n      (a.get(al, med + al) == b.get(bl, med\
    \ + bl) ? ok : ng) = med;\n    }\n    return ok;\n  }\n\n  friend int strcmp(const\
    \ RollingHash &a, const RollingHash &b, int al, int bl,\n                    int\
    \ ar = -1, int br = -1) {\n    if (ar == -1) ar = a.size();\n    if (br == -1)\
    \ br = b.size();\n    int n = min<int>({LCP(a, b, al, bl), ar - al, br - bl});\n\
    \    return al + n == ar\n               ? bl + n == br ? 0 : 1\n            \
    \   : bl + n == br ? -1 : a.data[al + n] < b.data[bl + n] ? 1 : -1;\n  }\n\n \
    \ int size() const { return s; }\n};\n\ntemplate <typename Str, int BASE_NUM>\n\
    typename RollingHash<Str, BASE_NUM>::Hash RollingHash<Str, BASE_NUM>::basis =\n\
    \    RollingHash<Str, BASE_NUM>::get_basis();\nusing roriha = RollingHash<string,\
    \ 1>;\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename Str = string, int BASE_NUM = 1>\nstruct RollingHash {\n  using u64\
    \ = unsigned long long;\n  using u128 = __uint128_t;\n\n  static constexpr u64\
    \ md = (1ull << 61) - 1;\n\n  static inline constexpr u64 modmul(const u64 &a,\
    \ const u64 &b) {\n    u128 ret = u128(a) * b;\n    ret = (ret & md) + (ret >>\
    \ 61);\n    return ret >= md ? ret - md : ret;\n  }\n  static inline constexpr\
    \ u64 modfma(const u64 &a, const u64 &b, const u64 &c) {\n    u128 ret = u128(a)\
    \ * b + c;\n    ret = (ret & md) + (ret >> 61);\n    return ret >= md ? ret -\
    \ md : ret;\n  }\n\n  struct Hash : array<u64, BASE_NUM> {\n    using array<u64,\
    \ BASE_NUM>::operator[];\n\n    Hash() : array<u64, BASE_NUM>() {}\n    constexpr\
    \ static Hash set(u64 a) {\n      Hash res;\n      for (int i = 0; i < BASE_NUM;\
    \ i++) res[i] = a;\n      return res;\n    }\n    Hash &operator+=(const Hash\
    \ &r) {\n      for (int i = 0; i < BASE_NUM; i++)\n        if (((*this)[i] +=\
    \ r[i]) >= md) (*this)[i] -= md;\n      return *this;\n    }\n    Hash &operator+=(const\
    \ u64 &r) {\n      for (int i = 0; i < BASE_NUM; i++)\n        if (((*this)[i]\
    \ += r) >= md) (*this)[i] -= md;\n      return *this;\n    }\n    Hash &operator-=(const\
    \ Hash &r) {\n      for (int i = 0; i < BASE_NUM; i++)\n        if (((*this)[i]\
    \ += md - r[i]) >= md) (*this)[i] -= md;\n      return *this;\n    }\n    Hash\
    \ &operator-=(const u64 &r) {\n      for (int i = 0; i < BASE_NUM; i++)\n    \
    \    if (((*this)[i] += md - r) >= md) (*this)[i] -= md;\n      return *this;\n\
    \    }\n    inline Hash &operator*=(const Hash &r) {\n      for (int i = 0; i\
    \ < BASE_NUM; i++) (*this)[i] = modmul((*this)[i], r[i]);\n      return *this;\n\
    \    }\n    Hash operator+(const Hash &r) { return Hash(*this) += r; }\n    Hash\
    \ operator+(const u64 &r) { return Hash(*this) += r; }\n    Hash operator-(const\
    \ Hash &r) { return Hash(*this) -= r; }\n    Hash operator-(const u64 &r) { return\
    \ Hash(*this) -= r; }\n    inline Hash operator*(const Hash &r) { return Hash(*this)\
    \ *= r; }\n    Hash operator-() const {\n      Hash res;\n      for (int i = 0;\
    \ i < BASE_NUM; i++)\n        res[i] = (*this)[i] == 0 ? 0 : md - (*this)[i];\n\
    \      return res;\n    }\n    friend Hash pfma(const Hash &a, const Hash &b,\
    \ const Hash &c) {\n      Hash res;\n      for (int i = 0; i < BASE_NUM; i++)\
    \ res[i] = modfma(a[i], b[i], c[i]);\n      return res;\n    }\n    friend Hash\
    \ pfma(const Hash &a, const Hash &b, const u64 &c) {\n      Hash res;\n      for\
    \ (int i = 0; i < BASE_NUM; i++) res[i] = modfma(a[i], b[i], c);\n      return\
    \ res;\n    }\n  };\n\n  static Hash get_basis() {\n    constexpr u64 ds[] = {2,\
    \ 3, 5, 7, 11, 13, 31, 41, 61, 151, 331, 1321};\n    static auto rand_time =\n\
    \        chrono::duration_cast<chrono::nanoseconds>(\n            chrono::high_resolution_clock::now().time_since_epoch())\n\
    \            .count();\n    static mt19937_64 rng(rand_time);\n\n    auto modpow\
    \ = [&](u64 a, u64 b) {\n      u64 r = 1;\n      for (a %= md; b; a = modmul(a,\
    \ a), b >>= 1) r = modmul(r, a);\n      return r;\n    };\n    auto isPrimitive\
    \ = [&](u64 x) {\n      for (auto &d : ds)\n        if (modpow(x, (md - 1) / d)\
    \ <= 1) return false;\n      return true;\n    };\n\n    Hash h;\n    for (int\
    \ i = 0; i < BASE_NUM; i++) {\n      while (isPrimitive(h[i] = rng() % (md - 1)\
    \ + 1) == false)\n        ;\n    }\n    return h;\n  }\n\n  Str data;\n  vector<Hash>\
    \ hs, pw;\n  int s;\n  static Hash basis;\n\n  RollingHash() { build(string());\
    \ }\n\n  RollingHash(const Str &S) { build(S); }\n\n  void build(const Str &S)\
    \ {\n    data = S;\n    s = S.size();\n    hs.resize(s + 1);\n    pw.resize(s\
    \ + 1);\n    pw[0] = Hash::set(1);\n    hs[0] = Hash::set(0);\n    for (int i\
    \ = 1; i <= s; i++) {\n      pw[i] = pw[i - 1] * basis;\n      hs[i] = pfma(hs[i\
    \ - 1], basis, u64(S[i - 1]));\n    }\n  }\n\n  Hash get(int l, int r = -1) const\
    \ {\n    if (r == -1) r = s;\n    return pfma(hs[l], -pw[r - l], hs[r]);\n  }\n\
    \n  static Hash get_hash(const Str &T) {\n    Hash ret = Hash::set(0);\n    for\
    \ (int i = 0; i < (int)T.size(); i++) ret = pfma(ret, basis, u64(T[i]));\n   \
    \ return ret;\n  }\n\n  int find(Str &T, int lower = 0) const {\n    auto ths\
    \ = get_hash(T);\n    for (int i = lower; i <= s - (int)T.size(); i++)\n     \
    \ if (ths == get(i, i + (int)T.size())) return i;\n    return -1;\n  }\n\n  friend\
    \ int LCP(const RollingHash &a, const RollingHash &b, int al, int bl) {\n    int\
    \ ok = 0, ng = min(a.size() - al, b.size() - bl) + 1;\n    while (ok + 1 < ng)\
    \ {\n      int med = (ok + ng) / 2;\n      (a.get(al, med + al) == b.get(bl, med\
    \ + bl) ? ok : ng) = med;\n    }\n    return ok;\n  }\n\n  friend int strcmp(const\
    \ RollingHash &a, const RollingHash &b, int al, int bl,\n                    int\
    \ ar = -1, int br = -1) {\n    if (ar == -1) ar = a.size();\n    if (br == -1)\
    \ br = b.size();\n    int n = min<int>({LCP(a, b, al, bl), ar - al, br - bl});\n\
    \    return al + n == ar\n               ? bl + n == br ? 0 : 1\n            \
    \   : bl + n == br ? -1 : a.data[al + n] < b.data[bl + n] ? 1 : -1;\n  }\n\n \
    \ int size() const { return s; }\n};\n\ntemplate <typename Str, int BASE_NUM>\n\
    typename RollingHash<Str, BASE_NUM>::Hash RollingHash<Str, BASE_NUM>::basis =\n\
    \    RollingHash<Str, BASE_NUM>::get_basis();\nusing roriha = RollingHash<string,\
    \ 1>;\n"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling-hash.hpp
  requiredBy: []
  timestamp: '2020-11-30 18:57:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-string/yosupo-zalgo-rollinghash.test.cpp
  - verify/verify-yosupo-string/yosupo-enumerate-palindromes-roriha.test.cpp
documentation_of: string/rolling-hash.hpp
layout: document
redirect_from:
- /library/string/rolling-hash.hpp
- /library/string/rolling-hash.hpp.html
title: string/rolling-hash.hpp
---
