---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure-2d/wavelet-matrix.hpp\"\n#include <bits/stdc++.h>\n\
    #include <immintrin.h>\n#include <x86intrin.h>\nusing namespace std;\n\nstruct\
    \ bit_vector {\n  using u32 = uint32_t;\n  using i64 = int64_t;\n  using u64 =\
    \ uint64_t;\n\n  static constexpr u32 w = 64;\n  vector<u64> block;\n  vector<u32>\
    \ count;\n  u32 n, zeros;\n\n  inline u32 get(u32 i) const { return u32(block[i\
    \ / w] >> (i % w)) & 1u; }\n  inline void set(u32 i) { block[i / w] |= 1LL <<\
    \ (i % w); }\n\n  bit_vector() {}\n  bit_vector(int _n) { init(_n); }\n  __attribute__((optimize(\"\
    O3\", \"unroll-loops\"))) void init(int _n) {\n    n = zeros = _n;\n    block.resize(n\
    \ / w + 1, 0);\n    count.resize(block.size(), 0);\n  }\n\n  __attribute__((target(\"\
    popcnt\"))) void build() {\n    for (u32 i = 1; i < block.size(); ++i)\n     \
    \ count[i] = count[i - 1] + _popcnt64(block[i - 1]);\n    zeros = rank0(n);\n\
    \  }\n\n  inline u32 rank0(u32 i) const { return i - rank1(i); }\n  __attribute__((target(\"\
    bmi2\", \"popcnt\"))) inline u32 rank1(u32 i) const {\n    return count[i / w]\
    \ + _popcnt64(_bzhi_u64(block[i / w], i % w));\n  }\n};\n\ntemplate <typename\
    \ T>\nstruct WaveletMatrix {\n  using u32 = uint32_t;\n  using i64 = int64_t;\n\
    \  using u64 = uint64_t;\n\n  u32 n, lg;\n  vector<T> a;\n  vector<bit_vector>\
    \ bv;\n\n  WaveletMatrix(u32 _n) : n(_n), a(_n) {}\n  WaveletMatrix(const vector<T>&\
    \ _a) : n(_a.size()), a(_a) { build(); }\n\n  T& operator[](u32 i) { return a[i];\
    \ }\n\n  __attribute__((optimize(\"O3\"))) void build() {\n    lg = __lg(max<T>(*max_element(begin(a),\
    \ end(a)), 1)) + 1;\n    bv.assign(lg, n);\n    vector<T> cur = a, nxt(n);\n \
    \   for (u32 h = lg - 1; h >= 0; --h) {\n      for (u32 i = 0; i < n; ++i)\n \
    \       if ((cur[i] >> h) & 1) bv[h].set(i);\n      bv[h].build();\n      array<decltype(begin(nxt)),\
    \ 2> it{begin(nxt), begin(nxt) + bv[h].zeros};\n      for (u32 i = 0; i < n; ++i)\
    \ *it[bv[h].get(i)]++ = cur[i];\n      swap(cur, nxt);\n    }\n    return;\n \
    \ }\n\n  inline pair<u32, u32> succ0(int l, int r, int h) {\n    return make_pair(bv[h].rank0(l),\
    \ bv[h].rank0(r));\n  }\n\n  inline pair<u32, u32> succ1(int l, int r, int h)\
    \ {\n    u32 l0 = bv[h].rank0(l);\n    u32 r0 = bv[h].rank0(r);\n    u32 zeros\
    \ = bv[h].zeros;\n    return make_pair(l + zeros - l0, r + zeros - r0);\n  }\n\
    \n  // return a[k]\n  T access(u32 k) const {\n    T ret = 0;\n    for (u32 h\
    \ = lg - 1; h >= 0; --h) {\n      u32 f = bv[h].get(k);\n      ret |= f ? T(1)\
    \ << h : 0;\n      k = f ? bv[h].rank1(k) + bv[h].zeros : bv[h].rank0(k);\n  \
    \  }\n    return ret;\n  }\n\n  // k-th (0-indexed) smallest number in a[l, r)\n\
    \  T kth_smallest(u32 l, u32 r, u32 k) const {\n    T res = 0;\n    for (u32 h\
    \ = lg - 1; h >= 0; --h) {\n      u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n\
    \      if (k < r0 - l0)\n        l = l0, r = r0;\n      else {\n        k -= r0\
    \ - l0;\n        res |= (T)1 << h;\n        l += bv[h].zeros - l0;\n        r\
    \ += bv[h].zeros - r0;\n      }\n    }\n    return res;\n  }\n\n  // k-th (0-indexed)\
    \ largest number in a[l, r)\n  T kth_largest(int l, int r, int k) {\n    return\
    \ kth_smallest(l, r, r - l - k - 1);\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\n#include <immintrin.h>\n#include\
    \ <x86intrin.h>\nusing namespace std;\n\nstruct bit_vector {\n  using u32 = uint32_t;\n\
    \  using i64 = int64_t;\n  using u64 = uint64_t;\n\n  static constexpr u32 w =\
    \ 64;\n  vector<u64> block;\n  vector<u32> count;\n  u32 n, zeros;\n\n  inline\
    \ u32 get(u32 i) const { return u32(block[i / w] >> (i % w)) & 1u; }\n  inline\
    \ void set(u32 i) { block[i / w] |= 1LL << (i % w); }\n\n  bit_vector() {}\n \
    \ bit_vector(int _n) { init(_n); }\n  __attribute__((optimize(\"O3\", \"unroll-loops\"\
    ))) void init(int _n) {\n    n = zeros = _n;\n    block.resize(n / w + 1, 0);\n\
    \    count.resize(block.size(), 0);\n  }\n\n  __attribute__((target(\"popcnt\"\
    ))) void build() {\n    for (u32 i = 1; i < block.size(); ++i)\n      count[i]\
    \ = count[i - 1] + _popcnt64(block[i - 1]);\n    zeros = rank0(n);\n  }\n\n  inline\
    \ u32 rank0(u32 i) const { return i - rank1(i); }\n  __attribute__((target(\"\
    bmi2\", \"popcnt\"))) inline u32 rank1(u32 i) const {\n    return count[i / w]\
    \ + _popcnt64(_bzhi_u64(block[i / w], i % w));\n  }\n};\n\ntemplate <typename\
    \ T>\nstruct WaveletMatrix {\n  using u32 = uint32_t;\n  using i64 = int64_t;\n\
    \  using u64 = uint64_t;\n\n  u32 n, lg;\n  vector<T> a;\n  vector<bit_vector>\
    \ bv;\n\n  WaveletMatrix(u32 _n) : n(_n), a(_n) {}\n  WaveletMatrix(const vector<T>&\
    \ _a) : n(_a.size()), a(_a) { build(); }\n\n  T& operator[](u32 i) { return a[i];\
    \ }\n\n  __attribute__((optimize(\"O3\"))) void build() {\n    lg = __lg(max<T>(*max_element(begin(a),\
    \ end(a)), 1)) + 1;\n    bv.assign(lg, n);\n    vector<T> cur = a, nxt(n);\n \
    \   for (u32 h = lg - 1; h >= 0; --h) {\n      for (u32 i = 0; i < n; ++i)\n \
    \       if ((cur[i] >> h) & 1) bv[h].set(i);\n      bv[h].build();\n      array<decltype(begin(nxt)),\
    \ 2> it{begin(nxt), begin(nxt) + bv[h].zeros};\n      for (u32 i = 0; i < n; ++i)\
    \ *it[bv[h].get(i)]++ = cur[i];\n      swap(cur, nxt);\n    }\n    return;\n \
    \ }\n\n  inline pair<u32, u32> succ0(int l, int r, int h) {\n    return make_pair(bv[h].rank0(l),\
    \ bv[h].rank0(r));\n  }\n\n  inline pair<u32, u32> succ1(int l, int r, int h)\
    \ {\n    u32 l0 = bv[h].rank0(l);\n    u32 r0 = bv[h].rank0(r);\n    u32 zeros\
    \ = bv[h].zeros;\n    return make_pair(l + zeros - l0, r + zeros - r0);\n  }\n\
    \n  // return a[k]\n  T access(u32 k) const {\n    T ret = 0;\n    for (u32 h\
    \ = lg - 1; h >= 0; --h) {\n      u32 f = bv[h].get(k);\n      ret |= f ? T(1)\
    \ << h : 0;\n      k = f ? bv[h].rank1(k) + bv[h].zeros : bv[h].rank0(k);\n  \
    \  }\n    return ret;\n  }\n\n  // k-th (0-indexed) smallest number in a[l, r)\n\
    \  T kth_smallest(u32 l, u32 r, u32 k) const {\n    T res = 0;\n    for (u32 h\
    \ = lg - 1; h >= 0; --h) {\n      u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n\
    \      if (k < r0 - l0)\n        l = l0, r = r0;\n      else {\n        k -= r0\
    \ - l0;\n        res |= (T)1 << h;\n        l += bv[h].zeros - l0;\n        r\
    \ += bv[h].zeros - r0;\n      }\n    }\n    return res;\n  }\n\n  // k-th (0-indexed)\
    \ largest number in a[l, r)\n  T kth_largest(int l, int r, int k) {\n    return\
    \ kth_smallest(l, r, r - l - k - 1);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: data-structure-2d/wavelet-matrix.hpp
  requiredBy: []
  timestamp: '2020-09-30 02:23:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: data-structure-2d/wavelet-matrix.hpp
layout: document
redirect_from:
- /library/data-structure-2d/wavelet-matrix.hpp
- /library/data-structure-2d/wavelet-matrix.hpp.html
title: data-structure-2d/wavelet-matrix.hpp
---
