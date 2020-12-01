---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: multiplicative-function/divisor-multiple-transform.hpp
    title: multiplicative-function/divisor-multiple-transform.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"multiplicative-function/mf-famous-series.hpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\n#line 3 \"multiplicative-function/divisor-multiple-transform.hpp\"\
    \nusing namespace std;\n\nstruct divisor_transform {\n  template <typename T>\n\
    \  static constexpr void zeta_transform(vector<T> &a) {\n    int N = a.size()\
    \ - 1;\n    vector<int> sieve(N + 1, true);\n    for (int p = 2; p <= N; p++)\n\
    \      if (sieve[p])\n        for (int k = 1; k * p <= N; ++k) sieve[k * p] =\
    \ false, a[k * p] += a[k];\n  }\n  template <typename T>\n  static constexpr void\
    \ mobius_transform(T &a) {\n    int N = a.size() - 1;\n    vector<int> sieve(N\
    \ + 1, true);\n    for (int p = 2; p <= N; p++)\n      if (sieve[p])\n       \
    \ for (int k = N / p; k > 0; --k) sieve[k * p] = false, a[k * p] -= a[k];\n  }\n\
    \n  template <typename T>\n  static constexpr void zeta_transform(map<long long,\
    \ T> &a) {\n    for (auto &x : a)\n      for (auto &y : a) {\n        if (x ==\
    \ y) break;\n        if (x.first % y.first == 0) x.second += y.second;\n     \
    \ }\n  }\n  template <typename T>\n  static constexpr void mobius_transform(map<long\
    \ long, T> &a) {\n    for (auto &x : a)\n      for (auto &y : a) {\n        if\
    \ (x == y) break;\n        if (x.first % y.first == 0) x.second -= y.second;\n\
    \      }\n  }\n};\n\nstruct multiple_transform {\n  template <typename T>\n  static\
    \ constexpr void zeta_transform(vector<T> &a) {\n    int N = a.size() - 1;\n \
    \   vector<int> sieve(N + 1, true);\n    for (int p = 2; p <= N; ++p)\n      if\
    \ (sieve[p])\n        for (int k = N / p; k > 0; --k) sieve[k * p] = false, a[k]\
    \ += a[k * p];\n  }\n  template <typename T>\n  static constexpr void mobius_transform(vector<T>\
    \ &a) {\n    int N = a.size() - 1;\n    vector<int> sieve(N + 1, true);\n    for\
    \ (int p = 2; p <= N; ++p)\n      if (sieve[p])\n        for (int k = 1; k * p\
    \ <= N; ++k) sieve[k * p] = false, a[k] -= a[k * p];\n  }\n\n  template <typename\
    \ T>\n  static constexpr void zeta_transform(map<long long, T> &a) {\n    for\
    \ (auto it = a.rbegin(); it != a.rend(); it++)\n      for (auto it2 = a.rbegin();\
    \ it2 != it; it2++)\n        if (it2->first % it->first == 0) it->second += it2->second;\n\
    \  }\n  template <typename T>\n  static constexpr void mobius_transform(map<long\
    \ long, T> &a) {\n    for (auto it = a.rbegin(); it != a.rend(); it++)\n     \
    \ for (auto it2 = a.rbegin(); it2 != it; it2++)\n        if (it2->first % it->first\
    \ == 0) it->second -= it2->second;\n  }\n};\n#line 6 \"multiplicative-function/mf-famous-series.hpp\"\
    \n\ntemplate <typename T>\nstatic constexpr vector<T> mobius_function(int N) {\n\
    \  vector<T> a(N + 1, 0);\n  a[1] = 1;\n  divisor_transform::mobius_transform(a);\n\
    \  return a;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"divisor-multiple-transform.hpp\"\n\ntemplate <typename T>\nstatic constexpr\
    \ vector<T> mobius_function(int N) {\n  vector<T> a(N + 1, 0);\n  a[1] = 1;\n\
    \  divisor_transform::mobius_transform(a);\n  return a;\n}\n"
  dependsOn:
  - multiplicative-function/divisor-multiple-transform.hpp
  isVerificationFile: false
  path: multiplicative-function/mf-famous-series.hpp
  requiredBy: []
  timestamp: '2020-12-01 11:28:23+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: multiplicative-function/mf-famous-series.hpp
layout: document
redirect_from:
- /library/multiplicative-function/mf-famous-series.hpp
- /library/multiplicative-function/mf-famous-series.hpp.html
title: multiplicative-function/mf-famous-series.hpp
---
