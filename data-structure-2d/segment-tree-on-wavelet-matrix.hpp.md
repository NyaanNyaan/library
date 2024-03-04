---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-segtree-on-wm.test.cpp
    title: verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-segtree-on-wm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 1 \"data-structure-2d/segment-tree-on-wavelet-matrix.hpp\"\n\
    \n#include <immintrin.h>\n//\n\nstruct bit_vector {\n  using u32 = uint32_t;\n\
    \  using i64 = int64_t;\n  using u64 = uint64_t;\n\n  static constexpr u32 w =\
    \ 64;\n  vector<u64> block;\n  vector<u32> count;\n  u32 n, zeros;\n\n  inline\
    \ u32 get(u32 i) const { return u32(block[i / w] >> (i % w)) & 1u; }\n  inline\
    \ void set(u32 i) { block[i / w] |= 1LL << (i % w); }\n\n  bit_vector() {}\n \
    \ bit_vector(int _n) { init(_n); }\n  __attribute__((optimize(\"O3,unroll-loops\"\
    ))) void init(int _n) {\n    n = zeros = _n;\n    block.resize(n / w + 1, 0);\n\
    \    count.resize(block.size(), 0);\n  }\n\n  __attribute__((target(\"popcnt\"\
    ))) void build() {\n    for (u32 i = 1; i < block.size(); ++i)\n      count[i]\
    \ = count[i - 1] + _mm_popcnt_u64(block[i - 1]);\n    zeros = rank0(n);\n  }\n\
    \n  inline u32 rank0(u32 i) const { return i - rank1(i); }\n\n  __attribute__((target(\"\
    bmi2,popcnt\"))) inline u32 rank1(u32 i) const {\n    return count[i / w] + _mm_popcnt_u64(_bzhi_u64(block[i\
    \ / w], i % w));\n  }\n};\n\ntemplate <typename S, typename T, T (*f)(T, T), T\
    \ (*I)()>\nstruct WaveletMatrix {\n  using u32 = uint32_t;\n  using i64 = int64_t;\n\
    \  using u64 = uint64_t;\n\n  struct SegTree {\n    int N;\n    int size;\n  \
    \  vector<T> data;\n\n    SegTree(int _n) { init(_n); }\n\n    void init(int _N)\
    \ {\n      N = _N;\n      size = 1;\n      while (size < N) size <<= 1;\n    \
    \  data.assign(2 * size, I());\n    }\n\n    void set(int k, T x) { data[k + size]\
    \ = x; }\n\n    void build() {\n      for (int k = size - 1; k > 0; k--) {\n \
    \       data[k] = f(data[2 * k], data[2 * k + 1]);\n      }\n    }\n\n    void\
    \ update(int k, T x) {\n      k += size;\n      data[k] = x;\n      while (k >>=\
    \ 1) {\n        data[k] = f(data[2 * k], data[2 * k + 1]);\n      }\n    }\n\n\
    \    void add(int k, T x) {\n      k += size;\n      data[k] += x;\n      while\
    \ (k >>= 1) {\n        data[k] = f(data[2 * k], data[2 * k + 1]);\n      }\n \
    \   }\n\n    // query to [a, b)\n    T query(int a, int b) const {\n      T L\
    \ = I(), R = I();\n      for (a += size, b += size; a < b; a >>= 1, b >>= 1) {\n\
    \        if (a & 1) L = f(L, data[a++]);\n        if (b & 1) R = f(data[--b],\
    \ R);\n      }\n      return f(L, R);\n    }\n  };\n\n  using P = pair<S, S>;\n\
    \  int n, lg;\n  vector<bit_vector> bv;\n  vector<SegTree> seg;\n  vector<P> ps;\n\
    \  vector<S> ys;\n\n  WaveletMatrix() {}\n\n  void add_point(S x, S y) {\n   \
    \ ps.emplace_back(x, y);\n    ys.emplace_back(y);\n  }\n\n  void build() {\n \
    \   sort(begin(ps), end(ps));\n    ps.erase(unique(begin(ps), end(ps)), end(ps));\n\
    \    n = ps.size();\n    sort(begin(ys), end(ys));\n    ys.erase(unique(begin(ys),\
    \ end(ys)), end(ys));\n    vector<u32> cur(n), nxt(n);\n    for (int i = 0; i\
    \ < n; ++i) cur[i] = yid(ps[i].second);\n    lg = __lg(max(n, 1)) + 1;\n    bv.assign(lg,\
    \ n);\n    seg.assign(lg, n);\n    for (int h = lg - 1; h >= 0; --h) {\n     \
    \ for (int i = 0; i < n; ++i)\n        if ((cur[i] >> h) & 1) bv[h].set(i);\n\
    \      bv[h].build();\n      array<decltype(begin(nxt)), 2> it{begin(nxt), begin(nxt)\
    \ + bv[h].zeros};\n      for (int i = 0; i < n; ++i) *it[bv[h].get(i)]++ = cur[i];\n\
    \      swap(cur, nxt);\n    }\n  }\n\n  int xid(S x) const {\n    return lower_bound(\n\
    \               begin(ps), end(ps), make_pair(x, S()),\n               [](const\
    \ P& a, const P& b) { return a.first < b.first; }) -\n           begin(ps);\n\
    \  }\n\n  int yid(S y) const { return lower_bound(begin(ys), end(ys), y) - begin(ys);\
    \ }\n\n  void add(S x, S y, T val) {\n    int i = lower_bound(begin(ps), end(ps),\
    \ P{x, y}) - begin(ps);\n    for (int h = lg - 1; h >= 0; --h) {\n      int i0\
    \ = bv[h].rank0(i);\n      if (bv[h].get(i))\n        i += bv[h].zeros - i0;\n\
    \      else\n        i = i0;\n      seg[h].add(i, val);\n    }\n  }\n\n  T _sum(int\
    \ l, int r, u32 upper) const {\n    T res = I();\n    for (int h = lg; h--;) {\n\
    \      int l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n      if ((upper >> h) &\
    \ 1) {\n        res = f(res, seg[h].query(l0, r0));\n        l += bv[h].zeros\
    \ - l0;\n        r += bv[h].zeros - r0;\n      } else {\n        l = l0, r = r0;\n\
    \      }\n    }\n    return res;\n  }\n\n  T sum(S L, S D, S R, S U) const {\n\
    \    int l = xid(L), r = xid(R);\n    return _sum(l, r, yid(U)) - _sum(l, r, yid(D));\n\
    \  }\n};\n"
  code: "\n#include <immintrin.h>\n//\n\nstruct bit_vector {\n  using u32 = uint32_t;\n\
    \  using i64 = int64_t;\n  using u64 = uint64_t;\n\n  static constexpr u32 w =\
    \ 64;\n  vector<u64> block;\n  vector<u32> count;\n  u32 n, zeros;\n\n  inline\
    \ u32 get(u32 i) const { return u32(block[i / w] >> (i % w)) & 1u; }\n  inline\
    \ void set(u32 i) { block[i / w] |= 1LL << (i % w); }\n\n  bit_vector() {}\n \
    \ bit_vector(int _n) { init(_n); }\n  __attribute__((optimize(\"O3,unroll-loops\"\
    ))) void init(int _n) {\n    n = zeros = _n;\n    block.resize(n / w + 1, 0);\n\
    \    count.resize(block.size(), 0);\n  }\n\n  __attribute__((target(\"popcnt\"\
    ))) void build() {\n    for (u32 i = 1; i < block.size(); ++i)\n      count[i]\
    \ = count[i - 1] + _mm_popcnt_u64(block[i - 1]);\n    zeros = rank0(n);\n  }\n\
    \n  inline u32 rank0(u32 i) const { return i - rank1(i); }\n\n  __attribute__((target(\"\
    bmi2,popcnt\"))) inline u32 rank1(u32 i) const {\n    return count[i / w] + _mm_popcnt_u64(_bzhi_u64(block[i\
    \ / w], i % w));\n  }\n};\n\ntemplate <typename S, typename T, T (*f)(T, T), T\
    \ (*I)()>\nstruct WaveletMatrix {\n  using u32 = uint32_t;\n  using i64 = int64_t;\n\
    \  using u64 = uint64_t;\n\n  struct SegTree {\n    int N;\n    int size;\n  \
    \  vector<T> data;\n\n    SegTree(int _n) { init(_n); }\n\n    void init(int _N)\
    \ {\n      N = _N;\n      size = 1;\n      while (size < N) size <<= 1;\n    \
    \  data.assign(2 * size, I());\n    }\n\n    void set(int k, T x) { data[k + size]\
    \ = x; }\n\n    void build() {\n      for (int k = size - 1; k > 0; k--) {\n \
    \       data[k] = f(data[2 * k], data[2 * k + 1]);\n      }\n    }\n\n    void\
    \ update(int k, T x) {\n      k += size;\n      data[k] = x;\n      while (k >>=\
    \ 1) {\n        data[k] = f(data[2 * k], data[2 * k + 1]);\n      }\n    }\n\n\
    \    void add(int k, T x) {\n      k += size;\n      data[k] += x;\n      while\
    \ (k >>= 1) {\n        data[k] = f(data[2 * k], data[2 * k + 1]);\n      }\n \
    \   }\n\n    // query to [a, b)\n    T query(int a, int b) const {\n      T L\
    \ = I(), R = I();\n      for (a += size, b += size; a < b; a >>= 1, b >>= 1) {\n\
    \        if (a & 1) L = f(L, data[a++]);\n        if (b & 1) R = f(data[--b],\
    \ R);\n      }\n      return f(L, R);\n    }\n  };\n\n  using P = pair<S, S>;\n\
    \  int n, lg;\n  vector<bit_vector> bv;\n  vector<SegTree> seg;\n  vector<P> ps;\n\
    \  vector<S> ys;\n\n  WaveletMatrix() {}\n\n  void add_point(S x, S y) {\n   \
    \ ps.emplace_back(x, y);\n    ys.emplace_back(y);\n  }\n\n  void build() {\n \
    \   sort(begin(ps), end(ps));\n    ps.erase(unique(begin(ps), end(ps)), end(ps));\n\
    \    n = ps.size();\n    sort(begin(ys), end(ys));\n    ys.erase(unique(begin(ys),\
    \ end(ys)), end(ys));\n    vector<u32> cur(n), nxt(n);\n    for (int i = 0; i\
    \ < n; ++i) cur[i] = yid(ps[i].second);\n    lg = __lg(max(n, 1)) + 1;\n    bv.assign(lg,\
    \ n);\n    seg.assign(lg, n);\n    for (int h = lg - 1; h >= 0; --h) {\n     \
    \ for (int i = 0; i < n; ++i)\n        if ((cur[i] >> h) & 1) bv[h].set(i);\n\
    \      bv[h].build();\n      array<decltype(begin(nxt)), 2> it{begin(nxt), begin(nxt)\
    \ + bv[h].zeros};\n      for (int i = 0; i < n; ++i) *it[bv[h].get(i)]++ = cur[i];\n\
    \      swap(cur, nxt);\n    }\n  }\n\n  int xid(S x) const {\n    return lower_bound(\n\
    \               begin(ps), end(ps), make_pair(x, S()),\n               [](const\
    \ P& a, const P& b) { return a.first < b.first; }) -\n           begin(ps);\n\
    \  }\n\n  int yid(S y) const { return lower_bound(begin(ys), end(ys), y) - begin(ys);\
    \ }\n\n  void add(S x, S y, T val) {\n    int i = lower_bound(begin(ps), end(ps),\
    \ P{x, y}) - begin(ps);\n    for (int h = lg - 1; h >= 0; --h) {\n      int i0\
    \ = bv[h].rank0(i);\n      if (bv[h].get(i))\n        i += bv[h].zeros - i0;\n\
    \      else\n        i = i0;\n      seg[h].add(i, val);\n    }\n  }\n\n  T _sum(int\
    \ l, int r, u32 upper) const {\n    T res = I();\n    for (int h = lg; h--;) {\n\
    \      int l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n      if ((upper >> h) &\
    \ 1) {\n        res = f(res, seg[h].query(l0, r0));\n        l += bv[h].zeros\
    \ - l0;\n        r += bv[h].zeros - r0;\n      } else {\n        l = l0, r = r0;\n\
    \      }\n    }\n    return res;\n  }\n\n  T sum(S L, S D, S R, S U) const {\n\
    \    int l = xid(L), r = xid(R);\n    return _sum(l, r, yid(U)) - _sum(l, r, yid(D));\n\
    \  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure-2d/segment-tree-on-wavelet-matrix.hpp
  requiredBy: []
  timestamp: '2024-03-04 16:48:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-point-add-rectangle-sum-segtree-on-wm.test.cpp
documentation_of: data-structure-2d/segment-tree-on-wavelet-matrix.hpp
layout: document
redirect_from:
- /library/data-structure-2d/segment-tree-on-wavelet-matrix.hpp
- /library/data-structure-2d/segment-tree-on-wavelet-matrix.hpp.html
title: data-structure-2d/segment-tree-on-wavelet-matrix.hpp
---
