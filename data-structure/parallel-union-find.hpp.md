---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure/union-find-enumerate.hpp
    title: data-structure/union-find-enumerate.hpp
  - icon: ':heavy_check_mark:'
    path: internal/internal-hash.hpp
    title: "\u30CF\u30C3\u30B7\u30E5\u69CB\u9020\u4F53"
  - icon: ':heavy_check_mark:'
    path: string/rolling-hash-on-segment-tree.hpp
    title: string/rolling-hash-on-segment-tree.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/parallel-union-find.test.cpp
    title: verify/verify-unit-test/parallel-union-find.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/parallel-union-find.hpp\"\n\n#line 2 \"string/rolling-hash-on-segment-tree.hpp\"\
    \n\n#include <vector>\nusing namespace std;\n\n#line 1 \"atcoder/segtree.hpp\"\
    \n\n\n\n#include <algorithm>\n#include <cassert>\n#line 7 \"atcoder/segtree.hpp\"\
    \n\n#line 1 \"atcoder/internal_bit.hpp\"\n\n\n\n#ifdef _MSC_VER\n#include <intrin.h>\n\
    #endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n// @param n `0 <= n`\n\
    // @return minimum non-negative `x` s.t. `n <= 2**x`\nint ceil_pow2(int n) {\n\
    \    int x = 0;\n    while ((1U << x) < (unsigned int)(n)) x++;\n    return x;\n\
    }\n\n// @param n `1 <= n`\n// @return minimum non-negative `x` s.t. `(n & (1 <<\
    \ x)) != 0`\nconstexpr int bsf_constexpr(unsigned int n) {\n    int x = 0;\n \
    \   while (!(n & (1 << x))) x++;\n    return x;\n}\n\n// @param n `1 <= n`\n//\
    \ @return minimum non-negative `x` s.t. `(n & (1 << x)) != 0`\nint bsf(unsigned\
    \ int n) {\n#ifdef _MSC_VER\n    unsigned long index;\n    _BitScanForward(&index,\
    \ n);\n    return index;\n#else\n    return __builtin_ctz(n);\n#endif\n}\n\n}\
    \  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 9 \"atcoder/segtree.hpp\"\
    \n\nnamespace atcoder {\n\ntemplate <class S, S (*op)(S, S), S (*e)()> struct\
    \ segtree {\n  public:\n    segtree() : segtree(0) {}\n    segtree(int n) : segtree(std::vector<S>(n,\
    \ e())) {}\n    segtree(const std::vector<S>& v) : _n(int(v.size())) {\n     \
    \   log = internal::ceil_pow2(_n);\n        size = 1 << log;\n        d = std::vector<S>(2\
    \ * size, e());\n        for (int i = 0; i < _n; i++) d[size + i] = v[i];\n  \
    \      for (int i = size - 1; i >= 1; i--) {\n            update(i);\n       \
    \ }\n    }\n\n    void set(int p, S x) {\n        assert(0 <= p && p < _n);\n\
    \        p += size;\n        d[p] = x;\n        for (int i = 1; i <= log; i++)\
    \ update(p >> i);\n    }\n\n    S get(int p) {\n        assert(0 <= p && p < _n);\n\
    \        return d[p + size];\n    }\n\n    S prod(int l, int r) {\n        assert(0\
    \ <= l && l <= r && r <= _n);\n        S sml = e(), smr = e();\n        l += size;\n\
    \        r += size;\n\n        while (l < r) {\n            if (l & 1) sml = op(sml,\
    \ d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S\
    \ all_prod() { return d[1]; }\n\n    template <bool (*f)(S)> int max_right(int\
    \ l) {\n        return max_right(l, [](S x) { return f(x); });\n    }\n    template\
    \ <class F> int max_right(int l, F f) {\n        assert(0 <= l && l <= _n);\n\
    \        assert(f(e()));\n        if (l == _n) return _n;\n        l += size;\n\
    \        S sm = e();\n        do {\n            while (l % 2 == 0) l >>= 1;\n\
    \            if (!f(op(sm, d[l]))) {\n                while (l < size) {\n   \
    \                 l = (2 * l);\n                    if (f(op(sm, d[l]))) {\n \
    \                       sm = op(sm, d[l]);\n                        l++;\n   \
    \                 }\n                }\n                return l - size;\n   \
    \         }\n            sm = op(sm, d[l]);\n            l++;\n        } while\
    \ ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool (*f)(S)> int\
    \ min_left(int r) {\n        return min_left(r, [](S x) { return f(x); });\n \
    \   }\n    template <class F> int min_left(int r, F f) {\n        assert(0 <=\
    \ r && r <= _n);\n        assert(f(e()));\n        if (r == 0) return 0;\n   \
    \     r += size;\n        S sm = e();\n        do {\n            r--;\n      \
    \      while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(d[r], sm))) {\n\
    \                while (r < size) {\n                    r = (2 * r + 1);\n  \
    \                  if (f(op(d[r], sm))) {\n                        sm = op(d[r],\
    \ sm);\n                        r--;\n                    }\n                }\n\
    \                return r + 1 - size;\n            }\n            sm = op(d[r],\
    \ sm);\n        } while ((r & -r) != r);\n        return 0;\n    }\n\n  private:\n\
    \    int _n, size, log;\n    std::vector<S> d;\n\n    void update(int k) { d[k]\
    \ = op(d[2 * k], d[2 * k + 1]); }\n};\n\n}  // namespace atcoder\n\n\n#line 2\
    \ \"internal/internal-hash.hpp\"\n\nnamespace internal {\nusing i64 = long long;\n\
    using u64 = unsigned long long;\nusing u128 = __uint128_t;\n\ntemplate <int BASE_NUM\
    \ = 2>\nstruct Hash : array<u64, BASE_NUM> {\n  using array<u64, BASE_NUM>::operator[];\n\
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
    \u30B7\u30E5\u69CB\u9020\u4F53\n * @docs docs/internal/internal-hash.md\n */\n\
    #line 8 \"string/rolling-hash-on-segment-tree.hpp\"\n\nnamespace RollingHashonSegmentTreeImpl\
    \ {\n\nconstexpr int BASE_NUM = 1;\nusing Hash = internal::Hash<BASE_NUM>;\nusing\
    \ T = pair<Hash, int>;\n\nvector<Hash> Pow{Hash::set(1)};\nconst Hash Basis =\
    \ Hash::get_basis();\nconst Hash Zero = Hash::set(0);\n\nT op(T a, T b) {\n  while\
    \ (b.second >= (int)Pow.size()) {\n    Hash h = Pow.back();\n    Pow.push_back(h\
    \ * Basis);\n  }\n  Hash h = pfma(a.first, Pow[b.second], b.first);\n  int len\
    \ = a.second + b.second;\n  return make_pair(h, len);\n}\nT e() { return make_pair(Zero,\
    \ 0); }\n\ntemplate <typename Str>\nstruct RollingHashonSegmentTree {\n  using\
    \ Value = typename Str::value_type;\n  int n;\n  atcoder::segtree<T, op, e> seg;\n\
    \n  RollingHashonSegmentTree() : n(0) {}\n\n  RollingHashonSegmentTree(const Str&\
    \ S) : n(S.size()) {\n    vector<T> init(n);\n    for (int i = 0; i < n; i++)\
    \ {\n      init[i] = make_pair(Hash::set(S[i]), 1);\n    }\n    seg = {init};\n\
    \  }\n\n  void update(int i, const Value& v) {\n    assert(0 <= i and i < n);\n\
    \    seg.set(i, make_pair(Hash::set(v), 1));\n  }\n\n  // [l1, r1) \u3068 [l2,\
    \ r2) \u304C\u4E00\u81F4\u3059\u308B\u304B\u3092\u5224\u5B9A\n  bool same(int\
    \ l1, int r1, int l2, int r2) {\n    assert(0 <= l1 and l1 <= r1 and r1 <= n);\n\
    \    assert(0 <= l2 and l2 <= r2 and r2 <= n);\n    if (r1 - l1 != r2 - l2) return\
    \ false;\n    return seg.prod(l1, r1) == seg.prod(l2, r2);\n  }\n};\n}  // namespace\
    \ RollingHashonSegmentTreeImpl\n\nusing RollingHashonSegmentTreeImpl::RollingHashonSegmentTree;\n\
    #line 2 \"data-structure/union-find-enumerate.hpp\"\n\n#line 4 \"data-structure/union-find-enumerate.hpp\"\
    \nusing namespace std;\n\nstruct UnionFindEnumerate {\n  vector<int> data, nxt;\n\
    \  UnionFindEnumerate(int N) : data(N, -1), nxt(N) {\n    for (int i = 0; i <\
    \ N; i++) nxt[i] = i;\n  }\n\n  int find(int k) { return data[k] < 0 ? k : data[k]\
    \ = find(data[k]); }\n\n  int unite(int x, int y) {\n    if ((x = find(x)) ==\
    \ (y = find(y))) return false;\n    if (data[x] > data[y]) swap(x, y);\n    data[x]\
    \ += data[y];\n    data[y] = x;\n    swap(nxt[x], nxt[y]);\n    return true;\n\
    \  }\n\n  // f(x, y) : x \u306B y \u3092\u30DE\u30FC\u30B8\n  template <typename\
    \ F>\n  int unite(int x, int y, const F &f) {\n    if ((x = find(x)) == (y = find(y)))\
    \ return false;\n    if (data[x] > data[y]) swap(x, y);\n    data[x] += data[y];\n\
    \    data[y] = x;\n    f(x, y);\n    swap(nxt[x], nxt[y]);\n    return true;\n\
    \  }\n\n  int size(int k) { return -data[find(k)]; }\n\n  int same(int x, int\
    \ y) { return find(x) == find(y); }\n\n  vector<int> enumerate(int i) {\n    vector<int>\
    \ res{i};\n    for (int j = nxt[i]; j != i; j = nxt[j]) res.push_back(j);\n  \
    \  return res;\n  }\n};\n#line 5 \"data-structure/parallel-union-find.hpp\"\n\n\
    struct ParallelUnionFind {\n  int n;\n  UnionFindEnumerate uf;\n  RollingHashonSegmentTree<vector<int>>\
    \ seg;\n\n  ParallelUnionFind(int _n) : n(_n), uf(n) {\n    vector<int> init(n);\n\
    \    for (int i = 0; i < n; i++) init[i] = i;\n    seg = {init};\n  }\n\n  //\
    \ [l1, r1) \u3068 [l2, r2) \u3092 unite \u3059\u308B\n  void unite(int l1, int\
    \ r1, int l2, int r2) {\n    assert(0 <= l1 and l1 <= r1 and r1 <= n);\n    assert(0\
    \ <= l2 and l2 <= r2 and r2 <= n);\n    assert(r1 - l1 == r2 - l2);\n    while\
    \ (1) {\n      if (seg.same(l1, r1, l2, r2)) break;\n      int ok = 0, ng = r1\
    \ - l1;\n      while (ok + 1 < ng) {\n        int m = (ok + ng) / 2;\n       \
    \ (seg.same(l1, l1 + m, l2, l2 + m) ? ok : ng) = m;\n      }\n      uf.unite(l1\
    \ + ok, l2 + ok, [&](int x, int y) {\n        for (int z : uf.enumerate(y)) seg.update(z,\
    \ x);\n      });\n    }\n  }\n  void unite(int l, int r) { unite(l, l + 1, r,\
    \ r + 1); }\n  int find(int i) { return uf.find(i); }\n  int same(int l, int r)\
    \ { return uf.same(l, r); }\n  int size(int i) { return uf.size(i); }\n};\n"
  code: "#pragma once\n\n#include \"../string/rolling-hash-on-segment-tree.hpp\"\n\
    #include \"union-find-enumerate.hpp\"\n\nstruct ParallelUnionFind {\n  int n;\n\
    \  UnionFindEnumerate uf;\n  RollingHashonSegmentTree<vector<int>> seg;\n\n  ParallelUnionFind(int\
    \ _n) : n(_n), uf(n) {\n    vector<int> init(n);\n    for (int i = 0; i < n; i++)\
    \ init[i] = i;\n    seg = {init};\n  }\n\n  // [l1, r1) \u3068 [l2, r2) \u3092\
    \ unite \u3059\u308B\n  void unite(int l1, int r1, int l2, int r2) {\n    assert(0\
    \ <= l1 and l1 <= r1 and r1 <= n);\n    assert(0 <= l2 and l2 <= r2 and r2 <=\
    \ n);\n    assert(r1 - l1 == r2 - l2);\n    while (1) {\n      if (seg.same(l1,\
    \ r1, l2, r2)) break;\n      int ok = 0, ng = r1 - l1;\n      while (ok + 1 <\
    \ ng) {\n        int m = (ok + ng) / 2;\n        (seg.same(l1, l1 + m, l2, l2\
    \ + m) ? ok : ng) = m;\n      }\n      uf.unite(l1 + ok, l2 + ok, [&](int x, int\
    \ y) {\n        for (int z : uf.enumerate(y)) seg.update(z, x);\n      });\n \
    \   }\n  }\n  void unite(int l, int r) { unite(l, l + 1, r, r + 1); }\n  int find(int\
    \ i) { return uf.find(i); }\n  int same(int l, int r) { return uf.same(l, r);\
    \ }\n  int size(int i) { return uf.size(i); }\n};\n"
  dependsOn:
  - string/rolling-hash-on-segment-tree.hpp
  - internal/internal-hash.hpp
  - data-structure/union-find-enumerate.hpp
  isVerificationFile: false
  path: data-structure/parallel-union-find.hpp
  requiredBy: []
  timestamp: '2024-04-28 09:13:11+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/parallel-union-find.test.cpp
documentation_of: data-structure/parallel-union-find.hpp
layout: document
redirect_from:
- /library/data-structure/parallel-union-find.hpp
- /library/data-structure/parallel-union-find.hpp.html
title: data-structure/parallel-union-find.hpp
---
