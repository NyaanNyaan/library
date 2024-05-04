---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: internal/internal-hash.hpp
    title: "\u30CF\u30C3\u30B7\u30E5\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: tree/centroid.hpp
    title: tree/centroid.hpp
  - icon: ':heavy_check_mark:'
    path: tree/rooted-tree-hash.hpp
    title: "\u6839\u4ED8\u304D\u6728\u306E\u30CF\u30C3\u30B7\u30E5"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-2821.test.cpp
    title: verify/verify-aoj-other/aoj-2821.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"tree/tree-hash.hpp\"\n\n#line 2 \"tree/centroid.hpp\"\n\n\
    #include <utility>\n#include <vector>\nusing namespace std;\n\ntemplate <typename\
    \ G>\nvector<int> centroid(const G &g) {\n  const int N = (int)g.size();\n\n \
    \ vector<pair<int, int> > st;\n  st.emplace_back(0, -1);\n  vector<int> sz(N),\
    \ par(N);\n  while (!st.empty()) {\n    auto p = st.back();\n    if (sz[p.first]\
    \ == 0) {\n      sz[p.first] = 1;\n      for (auto &to : g[p.first])\n       \
    \ if (to != p.second) st.emplace_back(to, p.first);\n    } else {\n      for (auto\
    \ &to : g[p.first])\n        if (to != p.second) sz[p.first] += sz[to];\n    \
    \  par[p.first] = p.second;\n      st.pop_back();\n    }\n  }\n\n  vector<int>\
    \ ret;\n  int size = N;\n  for (int i = 0; i < N; i++) {\n    int val = N - sz[i];\n\
    \    for (auto &to : g[i])\n      if (to != par[i]) val = max(val, sz[to]);\n\
    \    if (val < size) size = val, ret.clear();\n    if (val == size) ret.emplace_back(i);\n\
    \  }\n\n  return ret;\n}\n#line 2 \"tree/rooted-tree-hash.hpp\"\n\n#include <array>\n\
    #include <chrono>\n#include <random>\n#line 7 \"tree/rooted-tree-hash.hpp\"\n\
    using namespace std;\n\n#line 2 \"internal/internal-hash.hpp\"\n\nnamespace internal\
    \ {\nusing i64 = long long;\nusing u64 = unsigned long long;\nusing u128 = __uint128_t;\n\
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
    \u30B7\u30E5\u69CB\u9020\u4F53\n * @docs docs/internal/internal-hash.md\n */\n\
    #line 10 \"tree/rooted-tree-hash.hpp\"\n\ntemplate <typename G>\nstruct RootedTreeHash\
    \ {\n  using Hash = internal::Hash<1>;\n\n  const G& g;\n  int n;\n  vector<Hash>\
    \ hash;\n  vector<int> depth;\n\n  static vector<Hash>& xs() {\n    static vector<Hash>\
    \ _xs;\n    return _xs;\n  }\n\n  RootedTreeHash(const G& _g, int root = 0) :\
    \ g(_g), n(g.size()) {\n    hash.resize(n);\n    depth.resize(n, 0);\n    while\
    \ ((int)xs().size() <= n) xs().push_back(Hash::get_basis());\n    dfs(root, -1);\n\
    \  }\n\n private:\n  int dfs(int c, int p) {\n    int dep = 0;\n    for (auto&\
    \ d : g[c]) {\n      if (d != p) dep = max(dep, dfs(d, c) + 1);\n    }\n    Hash\
    \ x = xs()[dep], h = Hash::set(1);\n    for (auto& d : g[c]) {\n      if (d !=\
    \ p) h = h * (x + hash[d]);\n    }\n    hash[c] = h;\n    return depth[c] = dep;\n\
    \  }\n};\n\n/**\n * @brief \u6839\u4ED8\u304D\u6728\u306E\u30CF\u30C3\u30B7\u30E5\
    \n */\n#line 5 \"tree/tree-hash.hpp\"\n\ntemplate <typename G>\nvector<typename\
    \ RootedTreeHash<G>::Hash> tree_hash(const G& g) {\n  using Hash = typename RootedTreeHash<G>::Hash;\n\
    \  auto cs = centroid(g);\n  if ((int)cs.size() == 1) cs.push_back(cs[0]);\n \
    \ vector<Hash> hs;\n  for (auto& c : cs) hs.push_back(RootedTreeHash{g, c}.hash[c]);\n\
    \  sort(begin(hs), end(hs));\n  return hs;\n}\n"
  code: "#pragma once\n\n#include \"centroid.hpp\"\n#include \"rooted-tree-hash.hpp\"\
    \n\ntemplate <typename G>\nvector<typename RootedTreeHash<G>::Hash> tree_hash(const\
    \ G& g) {\n  using Hash = typename RootedTreeHash<G>::Hash;\n  auto cs = centroid(g);\n\
    \  if ((int)cs.size() == 1) cs.push_back(cs[0]);\n  vector<Hash> hs;\n  for (auto&\
    \ c : cs) hs.push_back(RootedTreeHash{g, c}.hash[c]);\n  sort(begin(hs), end(hs));\n\
    \  return hs;\n}\n"
  dependsOn:
  - tree/centroid.hpp
  - tree/rooted-tree-hash.hpp
  - internal/internal-hash.hpp
  isVerificationFile: false
  path: tree/tree-hash.hpp
  requiredBy: []
  timestamp: '2024-05-04 15:53:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-other/aoj-2821.test.cpp
documentation_of: tree/tree-hash.hpp
layout: document
redirect_from:
- /library/tree/tree-hash.hpp
- /library/tree/tree-hash.hpp.html
title: tree/tree-hash.hpp
---
