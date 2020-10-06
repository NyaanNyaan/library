---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: data-structure-2d/wavelet-matrix.hpp
    title: data-structure-2d/wavelet-matrix.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/aplusb
    links:
    - https://judge.yosupo.jp/problem/aplusb
  bundledCode: "#line 1 \"verify/verify-unit-test/wavelet-matrix.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <bits/stdc++.h>\n\
    \n#line 3 \"data-structure-2d/wavelet-matrix.hpp\"\n#include <immintrin.h>\nusing\
    \ namespace std;\n\nstruct bit_vector {\n  using u32 = uint32_t;\n  using i64\
    \ = int64_t;\n  using u64 = uint64_t;\n\n  static constexpr u32 w = 64;\n  vector<u64>\
    \ block;\n  vector<u32> count;\n  u32 n, zeros;\n\n  inline u32 get(u32 i) const\
    \ { return u32(block[i / w] >> (i % w)) & 1u; }\n  inline void set(u32 i) { block[i\
    \ / w] |= 1LL << (i % w); }\n\n  bit_vector() {}\n  bit_vector(int _n) { init(_n);\
    \ }\n  __attribute__((optimize(\"O3\", \"unroll-loops\"))) void init(int _n) {\n\
    \    n = zeros = _n;\n    block.resize(n / w + 1, 0);\n    count.resize(block.size(),\
    \ 0);\n  }\n\n  __attribute__((target(\"popcnt\"))) void build() {\n    for (u32\
    \ i = 1; i < block.size(); ++i)\n      count[i] = count[i - 1] + _mm_popcnt_u64(block[i\
    \ - 1]);\n    zeros = rank0(n);\n  }\n\n  inline u32 rank0(u32 i) const { return\
    \ i - rank1(i); }\n  __attribute__((target(\"bmi2,popcnt\"))) inline u32 rank1(u32\
    \ i) const {\n    return count[i / w] + _mm_popcnt_u64(_bzhi_u64(block[i / w],\
    \ i % w));\n  }\n};\n\ntemplate <typename T>\nstruct WaveletMatrix {\n  using\
    \ u32 = uint32_t;\n  using i64 = int64_t;\n  using u64 = uint64_t;\n\n  int n,\
    \ lg;\n  vector<T> a;\n  vector<bit_vector> bv;\n\n  WaveletMatrix(u32 _n) : n(_n),\
    \ a(_n) {}\n  WaveletMatrix(const vector<T>& _a) : n(_a.size()), a(_a) { build();\
    \ }\n\n  __attribute__((optimize(\"O3\"))) void build() {\n    lg = __lg(max<T>(*max_element(begin(a),\
    \ end(a)), 1)) + 1;\n    bv.assign(lg, n);\n    vector<T> cur = a, nxt(n);\n \
    \   for (int h = lg - 1; h >= 0; --h) {\n      for (int i = 0; i < n; ++i)\n \
    \       if ((cur[i] >> h) & 1) bv[h].set(i);\n      bv[h].build();\n      array<decltype(begin(nxt)),\
    \ 2> it{begin(nxt), begin(nxt) + bv[h].zeros};\n      for (int i = 0; i < n; ++i)\
    \ *it[bv[h].get(i)]++ = cur[i];\n      swap(cur, nxt);\n    }\n    return;\n \
    \ }\n\n  void set(u32 i, const T& x) { a[i] = x; }\n\n  inline pair<u32, u32>\
    \ succ0(int l, int r, int h) const {\n    return make_pair(bv[h].rank0(l), bv[h].rank0(r));\n\
    \  }\n\n  inline pair<u32, u32> succ1(int l, int r, int h) const {\n    u32 l0\
    \ = bv[h].rank0(l);\n    u32 r0 = bv[h].rank0(r);\n    u32 zeros = bv[h].zeros;\n\
    \    return make_pair(l + zeros - l0, r + zeros - r0);\n  }\n\n  // return a[k]\n\
    \  T access(u32 k) const {\n    T ret = 0;\n    for (int h = lg - 1; h >= 0; --h)\
    \ {\n      u32 f = bv[h].get(k);\n      ret |= f ? T(1) << h : 0;\n      k = f\
    \ ? bv[h].rank1(k) + bv[h].zeros : bv[h].rank0(k);\n    }\n    return ret;\n \
    \ }\n\n  // k-th (0-indexed) smallest number in a[l, r)\n  T kth_smallest(u32\
    \ l, u32 r, u32 k) const {\n    T res = 0;\n    for (int h = lg - 1; h >= 0; --h)\
    \ {\n      u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n      if (k < r0 - l0)\n\
    \        l = l0, r = r0;\n      else {\n        k -= r0 - l0;\n        res |=\
    \ (T)1 << h;\n        l += bv[h].zeros - l0;\n        r += bv[h].zeros - r0;\n\
    \      }\n    }\n    return res;\n  }\n\n  // k-th (0-indexed) largest number\
    \ in a[l, r)\n  T kth_largest(int l, int r, int k) {\n    return kth_smallest(l,\
    \ r, r - l - k - 1);\n  }\n\n  // count i s.t. (l <= i < r) && (v[i] < upper)\n\
    \  int range_freq(int l, int r, T upper) {\n    if(upper >= (T(1) << lg)) return\
    \ r - l;\n    int ret = 0;\n    for (int h = lg - 1; h >= 0; --h) {\n      bool\
    \ f = (upper >> h) & 1;\n      u32 l0 = bv[h].rank0(l), r0 = bv[h].rank0(r);\n\
    \      if (f) {\n        ret += r0 - l0;\n        l += bv[h].zeros - l0;\n   \
    \     r += bv[h].zeros - r0;\n      } else {\n        l = l0;\n        r = r0;\n\
    \      }\n    }\n    return ret;\n  }\n\n  int range_freq(int l, int r, T lower,\
    \ T upper) {\n    return range_freq(l, r, upper) - range_freq(l, r, lower);\n\
    \  }\n\n  // max v[i] s.t. (l <= i < r) && (v[i] < upper)\n  T prev_value(int\
    \ l, int r, T upper) {\n    int cnt = range_freq(l, r, upper);\n    return cnt\
    \ == 0 ? T(-1) : kth_smallest(l, r, cnt - 1);\n  }\n\n  // min v[i] s.t. (l <=\
    \ i < r) && (lower <= v[i])\n  T next_value(int l, int r, T lower) {\n    int\
    \ cnt = range_freq(l, r, lower);\n    return cnt == r - l ? T(-1) : kth_smallest(l,\
    \ r, cnt);\n  }\n};\n#line 6 \"verify/verify-unit-test/wavelet-matrix.test.cpp\"\
    \n\nuint64_t rng() {\n  static uint64_t x_ =\n      chrono::duration_cast<chrono::nanoseconds>(\n\
    \          chrono::high_resolution_clock::now().time_since_epoch())\n        \
    \  .count();\n  return x_ ^= (x_ << 7), x_ ^= (x_ >> 9);\n}\n\nint randint(int\
    \ l, int r) {\n  assert(l < r);\n  return rng() % (r - l) + l;\n}\n\nvoid test(int\
    \ n, int q, bool all_zero = false, bool large = false) {\n  assert(n > 0);\n \
    \ WaveletMatrix<int> wm(n);\n  vector<int> v(n, 0);\n  vector<int> buffer;\n\n\
    \  if (large) {\n    for (int i = 0; i < n; ++i) v[i] = randint(0, 1 << 30);\n\
    \  } else if (!all_zero) {\n    iota(begin(v), end(v), 0);\n  }\n\n  mt19937_64\
    \ mt;\n  shuffle(begin(v), end(v), mt);\n  for (int i = n; i--;) wm.set(i, v[i]);\n\
    \  wm.build();\n\n  // access\n  for (int Q = q; Q--;) {\n    int i = randint(0,\
    \ n);\n    assert(wm.access(i) == v[i]);\n  }\n\n  // kth-smallest / kth-largest\n\
    \  for (int Q = q; Q--;) {\n    int len = randint(1, n + 1);\n    int l = randint(0,\
    \ n - len + 1);\n    int r = l + len;\n    int k = randint(0, len);\n\n    buffer.clear();\n\
    \    copy(begin(v) + l, begin(v) + r, back_inserter(buffer));\n    sort(begin(buffer),\
    \ end(buffer));\n\n    assert(wm.kth_smallest(l, r, k) == buffer[k]);\n    assert(wm.kth_largest(l,\
    \ r, k) == buffer[len - k - 1]);\n  }\n\n  // range-freq\n  for (int Q = q; Q--;)\
    \ {\n    int len = randint(1, n + 1);\n    int l = randint(0, n - len + 1);\n\
    \    int r = l + len;\n    int lower, upper;\n    do {\n      lower = randint(0,\
    \ n + 5);\n      upper = randint(0, n + 5);\n      if (lower > upper) swap(lower,\
    \ upper);\n    } while (lower != upper);\n\n    buffer.clear();\n    copy(begin(v)\
    \ + l, begin(v) + r, back_inserter(buffer));\n    sort(begin(buffer), end(buffer));\n\
    \n    int up = lower_bound(begin(buffer), end(buffer), upper) - begin(buffer);\n\
    \    assert(wm.range_freq(l, r, upper) == up);\n    int lo = lower_bound(begin(buffer),\
    \ end(buffer), lower) - begin(buffer);\n    assert(wm.range_freq(l, r, lower,\
    \ upper) == up - lo);\n\n    int pv = len - 1;\n    while (pv != -1 and buffer[pv]\
    \ >= upper) --pv;\n    assert(wm.prev_value(l, r, upper) == (pv == -1 ? -1 : buffer[pv]));\n\
    \n    int nv = 0;\n    while (nv != len and buffer[nv] < lower) ++nv;\n    assert(wm.next_value(l,\
    \ r, lower) == (nv == len ? -1 : buffer[nv]));\n  }\n}\n\nint main() {\n  test(63,\
    \ 1000);\n  test(64, 1000);\n  test(65, 1000);\n  test(63, 1000, true);\n  test(64,\
    \ 1000, true);\n  test(65, 1000, true);\n  test(63, 1000, false, true);\n  test(64,\
    \ 1000, false, true);\n  test(65, 1000, false, true);\n  for (int i = 100; i--;)\
    \ {\n    test(1, 1);\n    test(1, 1, true);\n    test(1, 1, false, true);\n  \
    \  test(2, 10);\n    test(2, 10, true);\n    test(2, 10, false, true);\n  }\n\n\
    \  test(65535, 10);\n  test(65536, 10);\n  test(65537, 10);\n  test(65535, 10,\
    \ false, true);\n  test(65536, 10, false, true);\n  test(65537, 10, false, true);\n\
    \  \n  int a, b;\n  cin >> a >> b;\n  cout << (a + b) << endl;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/aplusb\"\n\n#include <bits/stdc++.h>\n\
    \n#include \"../../data-structure-2d/wavelet-matrix.hpp\"\n\nuint64_t rng() {\n\
    \  static uint64_t x_ =\n      chrono::duration_cast<chrono::nanoseconds>(\n \
    \         chrono::high_resolution_clock::now().time_since_epoch())\n         \
    \ .count();\n  return x_ ^= (x_ << 7), x_ ^= (x_ >> 9);\n}\n\nint randint(int\
    \ l, int r) {\n  assert(l < r);\n  return rng() % (r - l) + l;\n}\n\nvoid test(int\
    \ n, int q, bool all_zero = false, bool large = false) {\n  assert(n > 0);\n \
    \ WaveletMatrix<int> wm(n);\n  vector<int> v(n, 0);\n  vector<int> buffer;\n\n\
    \  if (large) {\n    for (int i = 0; i < n; ++i) v[i] = randint(0, 1 << 30);\n\
    \  } else if (!all_zero) {\n    iota(begin(v), end(v), 0);\n  }\n\n  mt19937_64\
    \ mt;\n  shuffle(begin(v), end(v), mt);\n  for (int i = n; i--;) wm.set(i, v[i]);\n\
    \  wm.build();\n\n  // access\n  for (int Q = q; Q--;) {\n    int i = randint(0,\
    \ n);\n    assert(wm.access(i) == v[i]);\n  }\n\n  // kth-smallest / kth-largest\n\
    \  for (int Q = q; Q--;) {\n    int len = randint(1, n + 1);\n    int l = randint(0,\
    \ n - len + 1);\n    int r = l + len;\n    int k = randint(0, len);\n\n    buffer.clear();\n\
    \    copy(begin(v) + l, begin(v) + r, back_inserter(buffer));\n    sort(begin(buffer),\
    \ end(buffer));\n\n    assert(wm.kth_smallest(l, r, k) == buffer[k]);\n    assert(wm.kth_largest(l,\
    \ r, k) == buffer[len - k - 1]);\n  }\n\n  // range-freq\n  for (int Q = q; Q--;)\
    \ {\n    int len = randint(1, n + 1);\n    int l = randint(0, n - len + 1);\n\
    \    int r = l + len;\n    int lower, upper;\n    do {\n      lower = randint(0,\
    \ n + 5);\n      upper = randint(0, n + 5);\n      if (lower > upper) swap(lower,\
    \ upper);\n    } while (lower != upper);\n\n    buffer.clear();\n    copy(begin(v)\
    \ + l, begin(v) + r, back_inserter(buffer));\n    sort(begin(buffer), end(buffer));\n\
    \n    int up = lower_bound(begin(buffer), end(buffer), upper) - begin(buffer);\n\
    \    assert(wm.range_freq(l, r, upper) == up);\n    int lo = lower_bound(begin(buffer),\
    \ end(buffer), lower) - begin(buffer);\n    assert(wm.range_freq(l, r, lower,\
    \ upper) == up - lo);\n\n    int pv = len - 1;\n    while (pv != -1 and buffer[pv]\
    \ >= upper) --pv;\n    assert(wm.prev_value(l, r, upper) == (pv == -1 ? -1 : buffer[pv]));\n\
    \n    int nv = 0;\n    while (nv != len and buffer[nv] < lower) ++nv;\n    assert(wm.next_value(l,\
    \ r, lower) == (nv == len ? -1 : buffer[nv]));\n  }\n}\n\nint main() {\n  test(63,\
    \ 1000);\n  test(64, 1000);\n  test(65, 1000);\n  test(63, 1000, true);\n  test(64,\
    \ 1000, true);\n  test(65, 1000, true);\n  test(63, 1000, false, true);\n  test(64,\
    \ 1000, false, true);\n  test(65, 1000, false, true);\n  for (int i = 100; i--;)\
    \ {\n    test(1, 1);\n    test(1, 1, true);\n    test(1, 1, false, true);\n  \
    \  test(2, 10);\n    test(2, 10, true);\n    test(2, 10, false, true);\n  }\n\n\
    \  test(65535, 10);\n  test(65536, 10);\n  test(65537, 10);\n  test(65535, 10,\
    \ false, true);\n  test(65536, 10, false, true);\n  test(65537, 10, false, true);\n\
    \  \n  int a, b;\n  cin >> a >> b;\n  cout << (a + b) << endl;\n}"
  dependsOn:
  - data-structure-2d/wavelet-matrix.hpp
  isVerificationFile: true
  path: verify/verify-unit-test/wavelet-matrix.test.cpp
  requiredBy: []
  timestamp: '2020-10-06 19:07:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: verify/verify-unit-test/wavelet-matrix.test.cpp
layout: document
redirect_from:
- /verify/verify/verify-unit-test/wavelet-matrix.test.cpp
- /verify/verify/verify-unit-test/wavelet-matrix.test.cpp.html
title: verify/verify-unit-test/wavelet-matrix.test.cpp
---
