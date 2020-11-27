---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"string/rolling-hash.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate <typename Str>\nstruct RollingHash {\n  using u32\
    \ = uint32_t;\n  using u64 = unsigned long long;\n\n  static constexpr u64 rmod\
    \ = (1ull << 61) - 1;\n\n  static constexpr u64 modmul(const u64 a, const u64\
    \ b) {\n    u64 l1 = (u32)a, h1 = a >> 32, l2 = (u32)b, h2 = b >> 32;\n    u64\
    \ l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;\n    u64 ret = (l & rmod) +\
    \ (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3);\n    if (ret > rmod) ret\
    \ = (ret & rmod) + (ret >> 61);\n    if (ret >= rmod) ret -= rmod;\n    return\
    \ ret;\n  }\n\n  static constexpr u64 modfma(const u64 a, const u64 b, const u64\
    \ c) {\n    u64 l1 = (u32)a, h1 = a >> 32, l2 = (u32)b, h2 = b >> 32;\n    u64\
    \ l = l1 * l2, m = l1 * h2 + l2 * h1, h = h1 * h2;\n    u64 ret =\n        (l\
    \ & rmod) + (l >> 61) + (h << 3) + (m >> 29) + (m << 35 >> 3) + c;\n    if (ret\
    \ > rmod) ret = (ret & rmod) + (ret >> 61);\n    if (ret >= rmod) ret -= rmod;\n\
    \    return ret;\n  }\n\n  static constexpr P get_basis() {\n    vector<u64> ds\
    \ = {2, 3, 5, 7, 11, 13, 31, 41, 61, 151, 331, 1321};\n    auto rand_time =\n\
    \        chrono::duration_cast<chrono::nanoseconds>(\n            chrono::high_resolution_clock::now().time_since_epoch())\n\
    \            .count();\n    mt19937_64 rng(rand_time);\n\n    auto modpow = [&](u64\
    \ a, u64 b) {\n      a %= rmod;\n      u64 r = 1;\n      for (; b; a = modmul(a,\
    \ a), b >>= 1) r = modmul(r, a);\n      return r;\n    };\n    auto isPrimitive\
    \ = [&](u64 x) {\n      for (u64 &d : ds)\n        if (modpow(x, (rmod - 1) /\
    \ d) == 1) return false;\n      return true;\n    };\n\n    u64 a = 1, b = 1;\n\
    \    do {\n      a = rng() % (rmod - 1) + 1, b = rng() % (rmod - 1) + 1;\n   \
    \   while (isPrimitive(a, ds) == false) a = rng() % rmod;\n      while (isPrimitive(b,\
    \ ds) == false) b = rng() % rmod;\n    } while (a == b);\n    return P(a, b);\n\
    \  }\n\n  struct P : pair<u64, u64> {\n    template <typename Args... args>\n\
    \    P(Args... args) : pair<u64, u64>(args...) {}\n\n    P &operator+=(const P\
    \ &r) {\n      if ((this->first += r.first) >= rmod) this->first -= rmod;\n  \
    \    if ((this->second += r.second) >= rmod) this->second -= rmod;\n      return\
    \ *this;\n    }\n    P &operator-=(const P &r) {\n      if ((this->first += rmod\
    \ - r.first) >= rmod) this->first -= rmod;\n      if ((this->second += rmod -\
    \ r.second) >= rmod) this->second -= rmod;\n      return *this;\n    }\n    P\
    \ &operator*=(const P &r) {\n      this->first = modmul(this->first, r.first);\n\
    \      this->second = modmul(this->second, r.second);\n      return *this;\n \
    \   }\n    P operator+(const P &r) { return P(*this) += r; }\n    P operator-(const\
    \ P &r) { return P(*this) -= r; }\n    P operator*(const P &r) { return P(*this)\
    \ *= r; }\n    P operator-() { return P(0, 0) - (*this); }\n    P friend fma(const\
    \ P &a, const P &b, const P &c) {\n      return P{modfma(a.first, b.first, c.first),\n\
    \               modfma(a.first, b.second, c.second)};\n    }\n  };\n\n  const\
    \ Str &data;\n  vector<P> hs, pw;\n  int s;\n  static P basis;\n\n  RollingHash()\
    \ = default;\n\n  RollingHash(const Str &S) { build(S); }\n\n  void build(const\
    \ Str &S) {\n    data = S;\n    s = S.size();\n    hs.resize(s + 1);\n    pw.resize(s\
    \ + 1);\n    pw[0] = P(1, 1), hs[0] = P(0, 0);\n    for (int i = 1; i <= s; i++)\
    \ {\n      pw[i] = pw[i - 1] * basis;\n      hs[i] = fma(hs[i - 1], basis[i],\
    \ P(S[i - 1], S[i - 1]));\n    }\n  }\n\n  P get(const int &l, const int &r) const\
    \ {\n    return -fma(hs[l], pw[r - 1], -hs[r]);\n  }\n\n  static P get_hash(Str\
    \ &T) const {\n    P ret = P(0, 0);\n    for (int i = 0; i < (int)T.size(); i++)\
    \ ret = fma(ret, basis, {T[i], T[i]});\n    return ret;\n  }\n\n  int find(Str\
    \ &T) const {\n    auto ths = get_hash(T);\n    for (int i = 0; i <= s - (int)T.size();\
    \ i++)\n      if (ths == get(i, i + (int)T.size())) return i;\n    return -1;\n\
    \  }\n\n  vector<int> find_all(Str &T) const {\n    auto t_hash = get_hash(T);\n\
    \    vector<int> ret;\n    for (int i = 0; i <= s - (int)T.size(); i++)\n    \
    \  if (t_hash == get(i, i + (int)T.size())) ret.push_back(i);\n    return ret;\n\
    \  }\n\n  int LongestCommonPrefix(RollingHash<Str> &t, int al, int bl) const {\n\
    \    int ok = 0, ng = min(s - al, t.s - bl) + 1;\n    while (ok + 1 < ng) {\n\
    \      int med = (ok + ng) / 2;\n      (get(al, med + al) == t.get(bl, med + bl)\
    \ ? ok : ng) = med;\n    }\n    return ok;\n  }\n\n  int strcmp(RollingHash<Str>\
    \ &t, int al, int bl, int ar = -1,\n             int br = -1) const {\n    if\
    \ (ar == -1) ar = s;\n    if (br == -1) br = t.s;\n    int n = min<int>({LongestCommonPrefix(t,\
    \ al, bl), ar - al, br - bl});\n    if (al + n == ar) return (bl + n == br) ?\
    \ 0 : 1;\n    if (bl + n == br) return -1;\n    return (data[al + n] < t.data[bl\
    \ + n]) ? 1 : -1;\n  }\n\n  int LongestCommonSubString() const {\n    auto f =\
    \ [&](int len) {\n      map<P, int> m;\n      for (int i = 0; i <= s - len; i++)\n\
    \        if ((m[get(i, i + len)] += 1) != 1) return true;\n      return false;\n\
    \    };\n    int ok = 0, ng = s;\n    while (ok + 1 < ng) {\n      int med = (ok\
    \ + ng) / 2;\n      (f(med) ? ok : ng) = med;\n    }\n    return ok;\n  }\n};\n\
    \ntemplate <typename Str>\ntypename RollingHash<Str>::P RollingHash<Str>::basis\
    \ =\n    RollingHash<Str>::get_basis();\nusing Roriha = RollingHash<string>;\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename Str>\nstruct RollingHash {\n  using u32 = uint32_t;\n  using u64 =\
    \ unsigned long long;\n\n  static constexpr u64 rmod = (1ull << 61) - 1;\n\n \
    \ static constexpr u64 modmul(const u64 a, const u64 b) {\n    u64 l1 = (u32)a,\
    \ h1 = a >> 32, l2 = (u32)b, h2 = b >> 32;\n    u64 l = l1 * l2, m = l1 * h2 +\
    \ l2 * h1, h = h1 * h2;\n    u64 ret = (l & rmod) + (l >> 61) + (h << 3) + (m\
    \ >> 29) + (m << 35 >> 3);\n    if (ret > rmod) ret = (ret & rmod) + (ret >> 61);\n\
    \    if (ret >= rmod) ret -= rmod;\n    return ret;\n  }\n\n  static constexpr\
    \ u64 modfma(const u64 a, const u64 b, const u64 c) {\n    u64 l1 = (u32)a, h1\
    \ = a >> 32, l2 = (u32)b, h2 = b >> 32;\n    u64 l = l1 * l2, m = l1 * h2 + l2\
    \ * h1, h = h1 * h2;\n    u64 ret =\n        (l & rmod) + (l >> 61) + (h << 3)\
    \ + (m >> 29) + (m << 35 >> 3) + c;\n    if (ret > rmod) ret = (ret & rmod) +\
    \ (ret >> 61);\n    if (ret >= rmod) ret -= rmod;\n    return ret;\n  }\n\n  static\
    \ constexpr P get_basis() {\n    vector<u64> ds = {2, 3, 5, 7, 11, 13, 31, 41,\
    \ 61, 151, 331, 1321};\n    auto rand_time =\n        chrono::duration_cast<chrono::nanoseconds>(\n\
    \            chrono::high_resolution_clock::now().time_since_epoch())\n      \
    \      .count();\n    mt19937_64 rng(rand_time);\n\n    auto modpow = [&](u64\
    \ a, u64 b) {\n      a %= rmod;\n      u64 r = 1;\n      for (; b; a = modmul(a,\
    \ a), b >>= 1) r = modmul(r, a);\n      return r;\n    };\n    auto isPrimitive\
    \ = [&](u64 x) {\n      for (u64 &d : ds)\n        if (modpow(x, (rmod - 1) /\
    \ d) == 1) return false;\n      return true;\n    };\n\n    u64 a = 1, b = 1;\n\
    \    do {\n      a = rng() % (rmod - 1) + 1, b = rng() % (rmod - 1) + 1;\n   \
    \   while (isPrimitive(a, ds) == false) a = rng() % rmod;\n      while (isPrimitive(b,\
    \ ds) == false) b = rng() % rmod;\n    } while (a == b);\n    return P(a, b);\n\
    \  }\n\n  struct P : pair<u64, u64> {\n    template <typename Args... args>\n\
    \    P(Args... args) : pair<u64, u64>(args...) {}\n\n    P &operator+=(const P\
    \ &r) {\n      if ((this->first += r.first) >= rmod) this->first -= rmod;\n  \
    \    if ((this->second += r.second) >= rmod) this->second -= rmod;\n      return\
    \ *this;\n    }\n    P &operator-=(const P &r) {\n      if ((this->first += rmod\
    \ - r.first) >= rmod) this->first -= rmod;\n      if ((this->second += rmod -\
    \ r.second) >= rmod) this->second -= rmod;\n      return *this;\n    }\n    P\
    \ &operator*=(const P &r) {\n      this->first = modmul(this->first, r.first);\n\
    \      this->second = modmul(this->second, r.second);\n      return *this;\n \
    \   }\n    P operator+(const P &r) { return P(*this) += r; }\n    P operator-(const\
    \ P &r) { return P(*this) -= r; }\n    P operator*(const P &r) { return P(*this)\
    \ *= r; }\n    P operator-() { return P(0, 0) - (*this); }\n    P friend fma(const\
    \ P &a, const P &b, const P &c) {\n      return P{modfma(a.first, b.first, c.first),\n\
    \               modfma(a.first, b.second, c.second)};\n    }\n  };\n\n  const\
    \ Str &data;\n  vector<P> hs, pw;\n  int s;\n  static P basis;\n\n  RollingHash()\
    \ = default;\n\n  RollingHash(const Str &S) { build(S); }\n\n  void build(const\
    \ Str &S) {\n    data = S;\n    s = S.size();\n    hs.resize(s + 1);\n    pw.resize(s\
    \ + 1);\n    pw[0] = P(1, 1), hs[0] = P(0, 0);\n    for (int i = 1; i <= s; i++)\
    \ {\n      pw[i] = pw[i - 1] * basis;\n      hs[i] = fma(hs[i - 1], basis[i],\
    \ P(S[i - 1], S[i - 1]));\n    }\n  }\n\n  P get(const int &l, const int &r) const\
    \ {\n    return -fma(hs[l], pw[r - 1], -hs[r]);\n  }\n\n  static P get_hash(Str\
    \ &T) const {\n    P ret = P(0, 0);\n    for (int i = 0; i < (int)T.size(); i++)\
    \ ret = fma(ret, basis, {T[i], T[i]});\n    return ret;\n  }\n\n  int find(Str\
    \ &T) const {\n    auto ths = get_hash(T);\n    for (int i = 0; i <= s - (int)T.size();\
    \ i++)\n      if (ths == get(i, i + (int)T.size())) return i;\n    return -1;\n\
    \  }\n\n  vector<int> find_all(Str &T) const {\n    auto t_hash = get_hash(T);\n\
    \    vector<int> ret;\n    for (int i = 0; i <= s - (int)T.size(); i++)\n    \
    \  if (t_hash == get(i, i + (int)T.size())) ret.push_back(i);\n    return ret;\n\
    \  }\n\n  int LongestCommonPrefix(RollingHash<Str> &t, int al, int bl) const {\n\
    \    int ok = 0, ng = min(s - al, t.s - bl) + 1;\n    while (ok + 1 < ng) {\n\
    \      int med = (ok + ng) / 2;\n      (get(al, med + al) == t.get(bl, med + bl)\
    \ ? ok : ng) = med;\n    }\n    return ok;\n  }\n\n  int strcmp(RollingHash<Str>\
    \ &t, int al, int bl, int ar = -1,\n             int br = -1) const {\n    if\
    \ (ar == -1) ar = s;\n    if (br == -1) br = t.s;\n    int n = min<int>({LongestCommonPrefix(t,\
    \ al, bl), ar - al, br - bl});\n    if (al + n == ar) return (bl + n == br) ?\
    \ 0 : 1;\n    if (bl + n == br) return -1;\n    return (data[al + n] < t.data[bl\
    \ + n]) ? 1 : -1;\n  }\n\n  int LongestCommonSubString() const {\n    auto f =\
    \ [&](int len) {\n      map<P, int> m;\n      for (int i = 0; i <= s - len; i++)\n\
    \        if ((m[get(i, i + len)] += 1) != 1) return true;\n      return false;\n\
    \    };\n    int ok = 0, ng = s;\n    while (ok + 1 < ng) {\n      int med = (ok\
    \ + ng) / 2;\n      (f(med) ? ok : ng) = med;\n    }\n    return ok;\n  }\n};\n\
    \ntemplate <typename Str>\ntypename RollingHash<Str>::P RollingHash<Str>::basis\
    \ =\n    RollingHash<Str>::get_basis();\nusing Roriha = RollingHash<string>;\n"
  dependsOn: []
  isVerificationFile: false
  path: string/rolling-hash.hpp
  requiredBy: []
  timestamp: '2020-11-28 01:47:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/rolling-hash.hpp
layout: document
redirect_from:
- /library/string/rolling-hash.hpp
- /library/string/rolling-hash.hpp.html
title: string/rolling-hash.hpp
---
