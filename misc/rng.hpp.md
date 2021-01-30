---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':question:'
    path: matrix/black-box-linear-algebra.hpp
    title: Black Box Linear Algebra
  - icon: ':heavy_check_mark:'
    path: modulo/mod-kth-root.hpp
    title: kth root(Tonelli-Shanks algorithm)
  - icon: ':heavy_check_mark:'
    path: prime/fast-factorize.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Miller Rabin/Pollard's Rho)"
  - icon: ':heavy_check_mark:'
    path: rbst/treap.hpp
    title: "\u9045\u5EF6\u4F1D\u642C\u53CD\u8EE2\u53EF\u80FDTreap"
  - icon: ':heavy_check_mark:'
    path: tree/pruefer-code.hpp
    title: Pruefer Code
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/dijkstra.test.cpp
    title: verify/verify-unit-test/dijkstra.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/factorize.test.cpp
    title: verify/verify-unit-test/factorize.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/math.test.cpp
    title: verify/verify-unit-test/math.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/multiplicative-function.test.cpp
    title: verify/verify-unit-test/multiplicative-function.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/orderedmap.test.cpp
    title: verify/verify-unit-test/orderedmap.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/osak.test.cpp
    title: verify/verify-unit-test/osak.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/radix-heap.test.cpp
    title: verify/verify-unit-test/radix-heap.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/run-length-encoding.test.cpp
    title: verify/verify-unit-test/run-length-encoding.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/segment-tree-beats.test.cpp
    title: verify/verify-unit-test/segment-tree-beats.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/semiring.test.cpp
    title: verify/verify-unit-test/semiring.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/set-function.test.cpp
    title: verify/verify-unit-test/set-function.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/simulated-annealing.test.cpp
    title: verify/verify-unit-test/simulated-annealing.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/tree-path.test.cpp
    title: verify/verify-unit-test/tree-path.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum-treap.test.cpp
    title: verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum-treap.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-vertex-add-path-sum-euler-tour.test.cpp
    title: verify/verify-yosupo-ds/yosupo-vertex-add-path-sum-euler-tour.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-determinant-of-matrix-bbla.test.cpp
    title: verify/verify-yosupo-math/yosupo-determinant-of-matrix-bbla.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-determinant-of-sparse-matrix-bbla.test.cpp
    title: verify/verify-yosupo-math/yosupo-determinant-of-sparse-matrix-bbla.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-factorization.test.cpp
    title: verify/verify-yosupo-math/yosupo-factorization.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
    title: verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0103.test.cpp
    title: verify/verify-yuki/yuki-0103.test.cpp
  - icon: ':x:'
    path: verify/verify-yuki/yuki-1112-sparse.test.cpp
    title: verify/verify-yuki/yuki-1112-sparse.test.cpp
  - icon: ':x:'
    path: verify/verify-yuki/yuki-1112.test.cpp
    title: verify/verify-yuki/yuki-1112.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/rng.hpp\"\n\nnamespace my_rand {\n\n// [0, 2^64 - 1)\n\
    uint64_t rng() {\n  static uint64_t x_ =\n      uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                   chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                   .count()) *\n      10150724397891781847ULL;\n  x_ ^= x_ <<\
    \ 7;\n  return x_ ^= x_ >> 9;\n}\n\n// [l, r)\nint64_t randint(int64_t l, int64_t\
    \ r) {\n  assert(l < r);\n  return l + rng() % (r - l);\n}\n\n// choose n numbers\
    \ from [l, r) without overlapping\nvector<int64_t> randset(int64_t l, int64_t\
    \ r, int64_t n) {\n  assert(l <= r && n <= r - l);\n  unordered_set<int64_t> s;\n\
    \  for (int64_t i = n; i; --i) {\n    int64_t m = randint(l, r + 1 - i);\n   \
    \ if (s.find(m) != s.end()) m = r - i;\n    s.insert(m);\n  }\n  vector<int64_t>\
    \ ret;\n  for (auto& x : s) ret.push_back(x);\n  return ret;\n}\n\n// [0.0, 1.0)\n\
    double rnd() {\n  union raw_cast {\n    double t;\n    uint64_t u;\n  };\n  constexpr\
    \ uint64_t p = uint64_t(1023 - 64) << 52;\n  return rng() * ((raw_cast*)(&p))->t;\n\
    }\n\ntemplate <typename T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n\
    \  for (int loop = 0; loop < 2; loop++)\n    for (int i = 0; i < n; i++) swap(v[i],\
    \ v[randint(0, n)]);\n}\n\n}  // namespace my_rand\n\nusing my_rand::randint;\n\
    using my_rand::randset;\nusing my_rand::randshf;\nusing my_rand::rnd;\nusing my_rand::rng;\n"
  code: "#pragma once\n\nnamespace my_rand {\n\n// [0, 2^64 - 1)\nuint64_t rng() {\n\
    \  static uint64_t x_ =\n      uint64_t(chrono::duration_cast<chrono::nanoseconds>(\n\
    \                   chrono::high_resolution_clock::now().time_since_epoch())\n\
    \                   .count()) *\n      10150724397891781847ULL;\n  x_ ^= x_ <<\
    \ 7;\n  return x_ ^= x_ >> 9;\n}\n\n// [l, r)\nint64_t randint(int64_t l, int64_t\
    \ r) {\n  assert(l < r);\n  return l + rng() % (r - l);\n}\n\n// choose n numbers\
    \ from [l, r) without overlapping\nvector<int64_t> randset(int64_t l, int64_t\
    \ r, int64_t n) {\n  assert(l <= r && n <= r - l);\n  unordered_set<int64_t> s;\n\
    \  for (int64_t i = n; i; --i) {\n    int64_t m = randint(l, r + 1 - i);\n   \
    \ if (s.find(m) != s.end()) m = r - i;\n    s.insert(m);\n  }\n  vector<int64_t>\
    \ ret;\n  for (auto& x : s) ret.push_back(x);\n  return ret;\n}\n\n// [0.0, 1.0)\n\
    double rnd() {\n  union raw_cast {\n    double t;\n    uint64_t u;\n  };\n  constexpr\
    \ uint64_t p = uint64_t(1023 - 64) << 52;\n  return rng() * ((raw_cast*)(&p))->t;\n\
    }\n\ntemplate <typename T>\nvoid randshf(vector<T>& v) {\n  int n = v.size();\n\
    \  for (int loop = 0; loop < 2; loop++)\n    for (int i = 0; i < n; i++) swap(v[i],\
    \ v[randint(0, n)]);\n}\n\n}  // namespace my_rand\n\nusing my_rand::randint;\n\
    using my_rand::randset;\nusing my_rand::randshf;\nusing my_rand::rnd;\nusing my_rand::rng;\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/rng.hpp
  requiredBy:
  - rbst/treap.hpp
  - tree/pruefer-code.hpp
  - matrix/black-box-linear-algebra.hpp
  - modulo/mod-kth-root.hpp
  - prime/fast-factorize.hpp
  timestamp: '2020-12-08 00:23:55+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/verify-unit-test/segment-tree-beats.test.cpp
  - verify/verify-unit-test/math.test.cpp
  - verify/verify-unit-test/tree-path.test.cpp
  - verify/verify-unit-test/dijkstra.test.cpp
  - verify/verify-unit-test/set-function.test.cpp
  - verify/verify-unit-test/simulated-annealing.test.cpp
  - verify/verify-unit-test/multiplicative-function.test.cpp
  - verify/verify-unit-test/orderedmap.test.cpp
  - verify/verify-unit-test/semiring.test.cpp
  - verify/verify-unit-test/radix-heap.test.cpp
  - verify/verify-unit-test/factorize.test.cpp
  - verify/verify-unit-test/run-length-encoding.test.cpp
  - verify/verify-unit-test/osak.test.cpp
  - verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
  - verify/verify-yosupo-math/yosupo-determinant-of-sparse-matrix-bbla.test.cpp
  - verify/verify-yosupo-math/yosupo-factorization.test.cpp
  - verify/verify-yosupo-math/yosupo-determinant-of-matrix-bbla.test.cpp
  - verify/verify-yuki/yuki-1112-sparse.test.cpp
  - verify/verify-yuki/yuki-0103.test.cpp
  - verify/verify-yuki/yuki-1112.test.cpp
  - verify/verify-yosupo-ds/yosupo-vertex-add-path-sum-euler-tour.test.cpp
  - verify/verify-yosupo-ds/yosupo-dynamic-sequence-range-affine-range-sum-treap.test.cpp
documentation_of: misc/rng.hpp
layout: document
redirect_from:
- /library/misc/rng.hpp
- /library/misc/rng.hpp.html
title: misc/rng.hpp
---
