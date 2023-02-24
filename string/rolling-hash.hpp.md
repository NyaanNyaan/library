---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: inner/inner-hash.hpp
    title: "\u30CF\u30C3\u30B7\u30E5\u69CB\u9020\u4F53"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/string-search.test.cpp
    title: verify/verify-unit-test/string-search.test.cpp
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
    _deprecated_at_docs: docs/string/rolling-hash.md
    document_title: Rolling Hash
    links: []
  bundledCode: "#line 2 \"string/rolling-hash.hpp\"\n\n#line 2 \"inner/inner-hash.hpp\"\
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
    \u4F53\n * @docs docs/inner/inner-hash.md\n */\n#line 4 \"string/rolling-hash.hpp\"\
    \n\ntemplate <typename Str, int BASE_NUM = 2>\nstruct RollingHash {\n  using Hash\
    \ = inner::Hash<BASE_NUM>;\n  Str data;\n  vector<Hash> hs, pw;\n  int s;\n  static\
    \ Hash basis;\n\n  RollingHash(const Str &S = Str()) { build(S); }\n\n  void build(const\
    \ Str &S) {\n    data = S;\n    s = S.size();\n    hs.resize(s + 1);\n    pw.resize(s\
    \ + 1);\n    pw[0] = Hash::set(1);\n    hs[0] = Hash::set(0);\n    for (int i\
    \ = 1; i <= s; i++) {\n      pw[i] = pw[i - 1] * basis;\n      hs[i] = pfma(hs[i\
    \ - 1], basis, S[i - 1]);\n    }\n  }\n\n  Hash get(int l, int r = -1) const {\n\
    \    if (r == -1) r = s;\n    return pfma(hs[l], -pw[r - l], hs[r]);\n  }\n\n\
    \  // T \u306E hash \u3092\u8FD4\u3059\n  static Hash get_hash(const Str &T) {\n\
    \    Hash ret = Hash::set(0);\n    for (int i = 0; i < (int)T.size(); i++) ret\
    \ = pfma(ret, basis, T[i]);\n    return ret;\n  }\n\n  // a + b \u306E hash \u3092\
    \u8FD4\u3059\n  // \u5F15\u6570 : a, b, b \u306E\u9577\u3055\n  static Hash unite(Hash\
    \ a, Hash b, long long bsize) {\n    return pfma(a, basis.pow(bsize), b);\n  }\n\
    \n  int find(Str &T, int lower = 0) const {\n    auto ths = get_hash(T);\n   \
    \ for (int i = lower; i <= s - (int)T.size(); i++)\n      if (ths == get(i, i\
    \ + (int)T.size())) return i;\n    return -1;\n  }\n\n  static int lcp(const RollingHash\
    \ &a, const RollingHash &b, int al, int bl) {\n    int ok = 0, ng = min(a.size()\
    \ - al, b.size() - bl) + 1;\n    while (ok + 1 < ng) {\n      int med = (ok +\
    \ ng) / 2;\n      (a.get(al, med + al) == b.get(bl, med + bl) ? ok : ng) = med;\n\
    \    }\n    return ok;\n  }\n\n  static int strcmp(const RollingHash &a, const\
    \ RollingHash &b, int al, int bl,\n                    int ar = -1, int br = -1)\
    \ {\n    if (ar == -1) ar = a.size();\n    if (br == -1) br = b.size();\n    int\
    \ n = min<int>({lcp(a, b, al, bl), ar - al, br - bl});\n    return al + n == ar\
    \                      ? bl + n == br ? 0 : -1\n           : bl + n == br    \
    \                ? 1\n           : a.data[al + n] < b.data[bl + n] ? -1\n    \
    \                                         : 1;\n  }\n\n  int size() const { return\
    \ s; }\n};\n\ntemplate <typename Str, int BASE_NUM>\ntypename RollingHash<Str,\
    \ BASE_NUM>::Hash RollingHash<Str, BASE_NUM>::basis =\n    inner::Hash<BASE_NUM>::get_basis();\n\
    using roriha = RollingHash<string, 2>;\n\n/**\n * @brief Rolling Hash\n * @docs\
    \ docs/string/rolling-hash.md\n */\n"
  code: "#pragma once\n\n#include \"../inner/inner-hash.hpp\"\n\ntemplate <typename\
    \ Str, int BASE_NUM = 2>\nstruct RollingHash {\n  using Hash = inner::Hash<BASE_NUM>;\n\
    \  Str data;\n  vector<Hash> hs, pw;\n  int s;\n  static Hash basis;\n\n  RollingHash(const\
    \ Str &S = Str()) { build(S); }\n\n  void build(const Str &S) {\n    data = S;\n\
    \    s = S.size();\n    hs.resize(s + 1);\n    pw.resize(s + 1);\n    pw[0] =\
    \ Hash::set(1);\n    hs[0] = Hash::set(0);\n    for (int i = 1; i <= s; i++) {\n\
    \      pw[i] = pw[i - 1] * basis;\n      hs[i] = pfma(hs[i - 1], basis, S[i -\
    \ 1]);\n    }\n  }\n\n  Hash get(int l, int r = -1) const {\n    if (r == -1)\
    \ r = s;\n    return pfma(hs[l], -pw[r - l], hs[r]);\n  }\n\n  // T \u306E hash\
    \ \u3092\u8FD4\u3059\n  static Hash get_hash(const Str &T) {\n    Hash ret = Hash::set(0);\n\
    \    for (int i = 0; i < (int)T.size(); i++) ret = pfma(ret, basis, T[i]);\n \
    \   return ret;\n  }\n\n  // a + b \u306E hash \u3092\u8FD4\u3059\n  // \u5F15\
    \u6570 : a, b, b \u306E\u9577\u3055\n  static Hash unite(Hash a, Hash b, long\
    \ long bsize) {\n    return pfma(a, basis.pow(bsize), b);\n  }\n\n  int find(Str\
    \ &T, int lower = 0) const {\n    auto ths = get_hash(T);\n    for (int i = lower;\
    \ i <= s - (int)T.size(); i++)\n      if (ths == get(i, i + (int)T.size())) return\
    \ i;\n    return -1;\n  }\n\n  static int lcp(const RollingHash &a, const RollingHash\
    \ &b, int al, int bl) {\n    int ok = 0, ng = min(a.size() - al, b.size() - bl)\
    \ + 1;\n    while (ok + 1 < ng) {\n      int med = (ok + ng) / 2;\n      (a.get(al,\
    \ med + al) == b.get(bl, med + bl) ? ok : ng) = med;\n    }\n    return ok;\n\
    \  }\n\n  static int strcmp(const RollingHash &a, const RollingHash &b, int al,\
    \ int bl,\n                    int ar = -1, int br = -1) {\n    if (ar == -1)\
    \ ar = a.size();\n    if (br == -1) br = b.size();\n    int n = min<int>({lcp(a,\
    \ b, al, bl), ar - al, br - bl});\n    return al + n == ar                   \
    \   ? bl + n == br ? 0 : -1\n           : bl + n == br                    ? 1\n\
    \           : a.data[al + n] < b.data[bl + n] ? -1\n                         \
    \                    : 1;\n  }\n\n  int size() const { return s; }\n};\n\ntemplate\
    \ <typename Str, int BASE_NUM>\ntypename RollingHash<Str, BASE_NUM>::Hash RollingHash<Str,\
    \ BASE_NUM>::basis =\n    inner::Hash<BASE_NUM>::get_basis();\nusing roriha =\
    \ RollingHash<string, 2>;\n\n/**\n * @brief Rolling Hash\n * @docs docs/string/rolling-hash.md\n\
    \ */\n"
  dependsOn:
  - inner/inner-hash.hpp
  isVerificationFile: false
  path: string/rolling-hash.hpp
  requiredBy: []
  timestamp: '2023-01-31 00:28:06+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/string-search.test.cpp
  - verify/verify-yosupo-string/yosupo-zalgo-rollinghash.test.cpp
  - verify/verify-yosupo-string/yosupo-enumerate-palindromes-roriha.test.cpp
documentation_of: string/rolling-hash.hpp
layout: document
redirect_from:
- /library/string/rolling-hash.hpp
- /library/string/rolling-hash.hpp.html
title: Rolling Hash
---
## Rolling Hash

列の一致判定を前計算$\mathrm{O}(n)$クエリ$\mathrm{O}(1)$で処理するライブラリ。

#### 使い方

- `RollingHash<Str>(S)`: コンストラクタ。Sを対象としたRollingHashを構築する。$\mathrm{O}(\lvert S\rvert)$
- `build(S)`: Sを対象としたRollingHashを構築する。$\mathrm{O}(\lvert S\rvert)$
- `get(l, r)`: 区間[l, r)のハッシュを返す。$\mathrm{O}(1)$
- `get_hash(T)`: Tのハッシュ値を返す。$\mathrm{O}(\lvert T\rvert)$
- `find(T, lower = 0)`: Sのlower文字目以降で初めてTが出てくる位置を返す。(存在しない場合は-1を返す。)$\mathrm{O}(\lvert S\rvert)$
- `LCP(a, b, al, bl)`: aのal文字目から始まるsuffixとbのb文字目から始まるsuffixのLCPを返す。$\mathrm{O}(\log (\lvert S\rvert+\lvert T\rvert))$
- `strcmp(a, b, al, bl, ar=-1, br=-1)`: a[al, ar)とb[bl, br)の大小を比較する。(返り値はstd::strcmpの仕様に準ずる。)$\mathrm{O}(\log (\lvert S\rvert+\lvert T\rvert))$
- `size()`: Sのサイズを返す。
