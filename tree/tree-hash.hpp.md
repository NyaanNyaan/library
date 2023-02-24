---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: inner/inner-hash.hpp
    title: "\u30CF\u30C3\u30B7\u30E5\u69CB\u9020\u4F53"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-1613.test.cpp
    title: verify/verify-aoj-other/aoj-1613.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1789.test.cpp
    title: verify/verify-yuki/yuki-1789.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u6839\u4ED8\u304D\u6728\u306E\u30CF\u30C3\u30B7\u30E5"
    links: []
  bundledCode: "#line 2 \"tree/tree-hash.hpp\"\n\n#line 2 \"inner/inner-hash.hpp\"\
    \n\nnamespace inner {\nusing i64 = long long;\nusing u64 = unsigned long long;\n\
    using u128 = __uint128_t;\n\ntemplate <int BASE_NUM = 2>\nstruct Hash : array<u64,\
    \ BASE_NUM> {\n  using array<u64, BASE_NUM>::operator[];\n  static constexpr int\
    \ n = BASE_NUM;\n\n  Hash() : array<u64, BASE_NUM>() {}\n\n  static constexpr\
    \ u64 md = (1ull << 61) - 1;\n\n  constexpr static Hash set(const i64 &a) {\n\
    \    Hash res;\n    fill(begin(res), end(res), cast(a));\n    return res;\n  }\n\
    \  Hash &operator+=(const Hash &r) {\n    for (int i = 0; i < n; i++)\n      if\
    \ (((*this)[i] += r[i]) >= md) (*this)[i] -= md;\n    return *this;\n  }\n  Hash\
    \ &operator+=(const i64 &r) {\n    u64 s = cast(r);\n    for (int i = 0; i < n;\
    \ i++)\n      if (((*this)[i] += s) >= md) (*this)[i] -= md;\n    return *this;\n\
    \  }\n  Hash &operator-=(const Hash &r) {\n    for (int i = 0; i < n; i++)\n \
    \     if (((*this)[i] += md - r[i]) >= md) (*this)[i] -= md;\n    return *this;\n\
    \  }\n  Hash &operator-=(const i64 &r) {\n    u64 s = cast(r);\n    for (int i\
    \ = 0; i < n; i++)\n      if (((*this)[i] += md - s) >= md) (*this)[i] -= md;\n\
    \    return *this;\n  }\n  Hash &operator*=(const Hash &r) {\n    for (int i =\
    \ 0; i < n; i++) (*this)[i] = modmul((*this)[i], r[i]);\n    return *this;\n \
    \ }\n  Hash &operator*=(const i64 &r) {\n    u64 s = cast(r);\n    for (int i\
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
    \ u64 &b) {\n    u128 ret = u128(a) * b;\n    ret = (ret & md) + (ret >> 61);\n\
    \    return ret >= md ? ret - md : ret;\n  }\n  static inline constexpr u64 modfma(const\
    \ u64 &a, const u64 &b, const u64 &c) {\n    u128 ret = u128(a) * b + c;\n   \
    \ ret = (ret & md) + (ret >> 61);\n    return ret >= md ? ret - md : ret;\n  }\n\
    };\n\n}  // namespace inner\n\n/**\n * @brief \u30CF\u30C3\u30B7\u30E5\u69CB\u9020\
    \u4F53\n * @docs docs/inner/inner-hash.md\n */\n#line 4 \"tree/tree-hash.hpp\"\
    \n\ntemplate <typename G>\nstruct TreeHash {\n  using Hash = inner::Hash<3>;\n\
    \n  const G& g;\n  int n;\n  vector<Hash> hash;\n  vector<int> depth;\n\n  static\
    \ vector<Hash>& xs() {\n    static vector<Hash> _xs;\n    return _xs;\n  }\n\n\
    \  TreeHash(const G& _g, int root = 0) : g(_g), n(g.size()) {\n    hash.resize(n);\n\
    \    depth.resize(n, 0);\n    while ((int)xs().size() <= n) xs().push_back(Hash::get_basis());\n\
    \    dfs(root, -1);\n  }\n\n private:\n  int dfs(int c, int p) {\n    int dep\
    \ = 0;\n    for (auto& d : g[c]) {\n      if (d != p) dep = max(dep, dfs(d, c)\
    \ + 1);\n    }\n    Hash x = xs()[dep], h = Hash::set(1);\n    for (auto& d :\
    \ g[c]) {\n      if (d != p) h = h * (x + hash[d]);\n    }\n    hash[c] = h;\n\
    \    return depth[c] = dep;\n  }\n};\n\n/**\n * @brief \u6839\u4ED8\u304D\u6728\
    \u306E\u30CF\u30C3\u30B7\u30E5\n */\n"
  code: "#pragma once\n\n#include \"../inner/inner-hash.hpp\"\n\ntemplate <typename\
    \ G>\nstruct TreeHash {\n  using Hash = inner::Hash<3>;\n\n  const G& g;\n  int\
    \ n;\n  vector<Hash> hash;\n  vector<int> depth;\n\n  static vector<Hash>& xs()\
    \ {\n    static vector<Hash> _xs;\n    return _xs;\n  }\n\n  TreeHash(const G&\
    \ _g, int root = 0) : g(_g), n(g.size()) {\n    hash.resize(n);\n    depth.resize(n,\
    \ 0);\n    while ((int)xs().size() <= n) xs().push_back(Hash::get_basis());\n\
    \    dfs(root, -1);\n  }\n\n private:\n  int dfs(int c, int p) {\n    int dep\
    \ = 0;\n    for (auto& d : g[c]) {\n      if (d != p) dep = max(dep, dfs(d, c)\
    \ + 1);\n    }\n    Hash x = xs()[dep], h = Hash::set(1);\n    for (auto& d :\
    \ g[c]) {\n      if (d != p) h = h * (x + hash[d]);\n    }\n    hash[c] = h;\n\
    \    return depth[c] = dep;\n  }\n};\n\n/**\n * @brief \u6839\u4ED8\u304D\u6728\
    \u306E\u30CF\u30C3\u30B7\u30E5\n */\n"
  dependsOn:
  - inner/inner-hash.hpp
  isVerificationFile: false
  path: tree/tree-hash.hpp
  requiredBy: []
  timestamp: '2023-01-31 00:28:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-1789.test.cpp
  - verify/verify-aoj-other/aoj-1613.test.cpp
documentation_of: tree/tree-hash.hpp
layout: document
redirect_from:
- /library/tree/tree-hash.hpp
- /library/tree/tree-hash.hpp.html
title: "\u6839\u4ED8\u304D\u6728\u306E\u30CF\u30C3\u30B7\u30E5"
---
