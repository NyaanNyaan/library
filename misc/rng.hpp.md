---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: misc/simulated-annealing.hpp
    title: misc/simulated-annealing.hpp
  - icon: ':heavy_check_mark:'
    path: modulo/mod-kth-root.hpp
    title: kth root(Tonelli-Shanks algorithm)
  - icon: ':heavy_check_mark:'
    path: prime/fast-factorize.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3(Miller Rabin/Pollard's Rho)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/osak.test.cpp
    title: verify/verify-unit-test/osak.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-factorization.test.cpp
    title: verify/verify-yosupo-math/yosupo-factorization.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
    title: verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/rng.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nnamespace my_rand {\n\nuint64_t rng() {\n#ifdef NyaanDebug\n  static\
    \ uint64_t x_ =\n      chrono::duration_cast<chrono::nanoseconds>(\n         \
    \ chrono::high_resolution_clock::now().time_since_epoch())\n          .count();\n\
    #else\n  static uint64_t x_ = 88172645463325252ULL;\n#endif\n  x_ = x_ ^ (x_ <<\
    \ 7);\n  return x_ = x_ ^ (x_ >> 9);\n}\n\n// [l, r)\nint64_t randint(int64_t\
    \ l, int64_t r) {\n  assert(l < r);\n  return l + rng() % (r - l);\n}\n\n//\n\
    vector<int64_t> randset(int64_t l, int64_t r, int64_t n) {\n  assert(l <= r &&\
    \ n <= r - l);\n  unordered_set<int64_t> s;\n  for (int64_t i = n; i; --i) {\n\
    \    int64_t m = randint(l, r + 1 - i);\n    if (s.find(m) != s.end()) m = r -\
    \ i;\n    s.insert(m);\n  }\n  vector<int64_t> ret;\n  for (auto& x : s) ret.push_back(x);\n\
    \  return ret;\n}\n\n}  // namespace my_rand\n\nusing my_rand::randint;\nusing\
    \ my_rand::randset;\nusing my_rand::rng;\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nnamespace\
    \ my_rand {\n\nuint64_t rng() {\n#ifdef NyaanDebug\n  static uint64_t x_ =\n \
    \     chrono::duration_cast<chrono::nanoseconds>(\n          chrono::high_resolution_clock::now().time_since_epoch())\n\
    \          .count();\n#else\n  static uint64_t x_ = 88172645463325252ULL;\n#endif\n\
    \  x_ = x_ ^ (x_ << 7);\n  return x_ = x_ ^ (x_ >> 9);\n}\n\n// [l, r)\nint64_t\
    \ randint(int64_t l, int64_t r) {\n  assert(l < r);\n  return l + rng() % (r -\
    \ l);\n}\n\n//\nvector<int64_t> randset(int64_t l, int64_t r, int64_t n) {\n \
    \ assert(l <= r && n <= r - l);\n  unordered_set<int64_t> s;\n  for (int64_t i\
    \ = n; i; --i) {\n    int64_t m = randint(l, r + 1 - i);\n    if (s.find(m) !=\
    \ s.end()) m = r - i;\n    s.insert(m);\n  }\n  vector<int64_t> ret;\n  for (auto&\
    \ x : s) ret.push_back(x);\n  return ret;\n}\n\n}  // namespace my_rand\n\nusing\
    \ my_rand::randint;\nusing my_rand::randset;\nusing my_rand::rng;\n"
  dependsOn: []
  isVerificationFile: false
  path: misc/rng.hpp
  requiredBy:
  - prime/fast-factorize.hpp
  - modulo/mod-kth-root.hpp
  - misc/simulated-annealing.hpp
  timestamp: '2020-10-17 00:29:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-factorization.test.cpp
  - verify/verify-yosupo-math/yosupo-kth-root-mod.test.cpp
  - verify/verify-unit-test/osak.test.cpp
documentation_of: misc/rng.hpp
layout: document
redirect_from:
- /library/misc/rng.hpp
- /library/misc/rng.hpp.html
title: misc/rng.hpp
---
