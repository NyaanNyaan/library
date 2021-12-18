---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: inner/inner-hash.hpp
    title: "\u30CF\u30C3\u30B7\u30E5\u69CB\u9020\u4F53"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-alds/verify-aoj-alds-14-c.test.cpp
    title: verify/verify-aoj-alds/verify-aoj-alds-14-c.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/string/rolling-hash-2d.md
    document_title: "\u4E8C\u6B21\u5143Rolling Hash"
    links: []
  bundledCode: "#line 2 \"string/rolling-hash-2d.hpp\"\n\n#line 2 \"inner/inner-hash.hpp\"\
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
    \  static Hash get_basis() {\n    static auto rand_time =\n        chrono::duration_cast<chrono::nanoseconds>(\n\
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
    \u4F53\n * @docs docs/inner/inner-hash.md\n */\n#line 4 \"string/rolling-hash-2d.hpp\"\
    \n\ntemplate <typename Str, int BASE_NUM = 2>\nstruct RollingHash2D {\n  using\
    \ Hash = inner::Hash<BASE_NUM>;\n  using u64 = unsigned long long;\n  vector<Str>\
    \ data;\n  vector<vector<Hash>> hs;\n  vector<Hash> pw[2];\n  int h, w;\n  static\
    \ Hash basis[2];\n\n  RollingHash2D(const vector<Str> &S = vector<Str>()) { build(S);\
    \ }\n\n  void build(const vector<Str> &S) {\n    data = S;\n    h = S.size();\n\
    \    w = S[0].size();\n    pw[0].resize(h + 1);\n    pw[1].resize(w + 1);\n  \
    \  pw[0][0] = pw[1][0] = Hash::set(1);\n    for (int i = 1; i <= h; i++) pw[0][i]\
    \ = pw[0][i - 1] * basis[0];\n    for (int i = 1; i <= w; i++) pw[1][i] = pw[1][i\
    \ - 1] * basis[1];\n    hs.resize(h + 1, vector<Hash>(w + 1));\n    hs[0][0] =\
    \ Hash::set(0);\n    for (int i = 1; i <= h; i++) {\n      hs[i][0] = Hash::set(0);\n\
    \      for (int j = 1; j <= w; j++)\n        hs[i][j] = pfma(hs[i][j - 1], basis[1],\
    \ S[i - 1][j - 1]);\n    }\n    for (int j = 1; j <= w; j++) {\n      hs[0][j]\
    \ = Hash::set(0);\n      for (int i = 1; i <= h; i++)\n        hs[i][j] = pfma(hs[i\
    \ - 1][j], basis[0], hs[i][j]);\n    }\n  }\n\n  Hash get(int u, int l, int d,\
    \ int r) {\n    return hs[d][r] - hs[u][r] * pw[0][d - u] - hs[d][l] * pw[1][r\
    \ - l] +\n           hs[u][l] * pw[0][d - u] * pw[1][r - l];\n  }\n\n  static\
    \ Hash get_hash(const vector<Str> &T) {\n    Hash ret = Hash::set(0);\n    for\
    \ (int i = 0; i < (int)T.size(); i++) {\n      Hash h = Hash::set(0);\n      for\
    \ (int j = 0; j < (int)T[0].size(); j++)\n        h = pfma(h, basis[1], T[i][j]);\n\
    \      ret = pfma(ret, basis[0], h);\n    }\n    return ret;\n  }\n};\n\ntemplate\
    \ <typename Str, int BASE_NUM>\ntypename RollingHash2D<Str, BASE_NUM>::Hash\n\
    \    RollingHash2D<Str, BASE_NUM>::basis[2] = {\n        inner::Hash<BASE_NUM>::get_basis(),\
    \ inner::Hash<BASE_NUM>::get_basis()};\nusing roriha2d = RollingHash2D<string,\
    \ 1>;\n\n/**\n * @brief \u4E8C\u6B21\u5143Rolling Hash\n * @docs docs/string/rolling-hash-2d.md\n\
    \ */\n"
  code: "#pragma once\n\n#include \"../inner/inner-hash.hpp\"\n\ntemplate <typename\
    \ Str, int BASE_NUM = 2>\nstruct RollingHash2D {\n  using Hash = inner::Hash<BASE_NUM>;\n\
    \  using u64 = unsigned long long;\n  vector<Str> data;\n  vector<vector<Hash>>\
    \ hs;\n  vector<Hash> pw[2];\n  int h, w;\n  static Hash basis[2];\n\n  RollingHash2D(const\
    \ vector<Str> &S = vector<Str>()) { build(S); }\n\n  void build(const vector<Str>\
    \ &S) {\n    data = S;\n    h = S.size();\n    w = S[0].size();\n    pw[0].resize(h\
    \ + 1);\n    pw[1].resize(w + 1);\n    pw[0][0] = pw[1][0] = Hash::set(1);\n \
    \   for (int i = 1; i <= h; i++) pw[0][i] = pw[0][i - 1] * basis[0];\n    for\
    \ (int i = 1; i <= w; i++) pw[1][i] = pw[1][i - 1] * basis[1];\n    hs.resize(h\
    \ + 1, vector<Hash>(w + 1));\n    hs[0][0] = Hash::set(0);\n    for (int i = 1;\
    \ i <= h; i++) {\n      hs[i][0] = Hash::set(0);\n      for (int j = 1; j <= w;\
    \ j++)\n        hs[i][j] = pfma(hs[i][j - 1], basis[1], S[i - 1][j - 1]);\n  \
    \  }\n    for (int j = 1; j <= w; j++) {\n      hs[0][j] = Hash::set(0);\n   \
    \   for (int i = 1; i <= h; i++)\n        hs[i][j] = pfma(hs[i - 1][j], basis[0],\
    \ hs[i][j]);\n    }\n  }\n\n  Hash get(int u, int l, int d, int r) {\n    return\
    \ hs[d][r] - hs[u][r] * pw[0][d - u] - hs[d][l] * pw[1][r - l] +\n           hs[u][l]\
    \ * pw[0][d - u] * pw[1][r - l];\n  }\n\n  static Hash get_hash(const vector<Str>\
    \ &T) {\n    Hash ret = Hash::set(0);\n    for (int i = 0; i < (int)T.size();\
    \ i++) {\n      Hash h = Hash::set(0);\n      for (int j = 0; j < (int)T[0].size();\
    \ j++)\n        h = pfma(h, basis[1], T[i][j]);\n      ret = pfma(ret, basis[0],\
    \ h);\n    }\n    return ret;\n  }\n};\n\ntemplate <typename Str, int BASE_NUM>\n\
    typename RollingHash2D<Str, BASE_NUM>::Hash\n    RollingHash2D<Str, BASE_NUM>::basis[2]\
    \ = {\n        inner::Hash<BASE_NUM>::get_basis(), inner::Hash<BASE_NUM>::get_basis()};\n\
    using roriha2d = RollingHash2D<string, 1>;\n\n/**\n * @brief \u4E8C\u6B21\u5143\
    Rolling Hash\n * @docs docs/string/rolling-hash-2d.md\n */\n"
  dependsOn:
  - inner/inner-hash.hpp
  isVerificationFile: false
  path: string/rolling-hash-2d.hpp
  requiredBy: []
  timestamp: '2021-12-18 14:04:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-alds/verify-aoj-alds-14-c.test.cpp
documentation_of: string/rolling-hash-2d.hpp
layout: document
redirect_from:
- /library/string/rolling-hash-2d.hpp
- /library/string/rolling-hash-2d.hpp.html
title: "\u4E8C\u6B21\u5143Rolling Hash"
---
## 二次元Rolling Hash

二次元の列の一致判定を前計算$\mathrm{O}(n)$クエリ$\mathrm{O}(1)$で処理するライブラリ。

#### 使い方

- `RollingHash<Str>(S)`: コンストラクタ。Sを対象としたRollingHashを構築する。$\mathrm{O}(\lvert S\lvert)$
- `build(S)`: Sを対象としたRollingHashを構築する。$\mathrm{O}(\lvert S\lvert)$
- `get(l, r)`: 区間[l, r)のハッシュを返す。$\mathrm{O}(1)$
- `get_hash(T)`: Tのハッシュ値を返す。$\mathrm{O}(\lvert T\lvert)$
