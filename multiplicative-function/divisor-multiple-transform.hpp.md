---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: prime/prime-enumerate.hpp
    title: prime/prime-enumerate.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: multiplicative-function/mf-famous-series.hpp
    title: multiplicative-function/mf-famous-series.hpp
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"multiplicative-function/divisor-multiple-transform.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n\n#line 3 \"prime/prime-enumerate.hpp\"\
    \nusing namespace std;\n\n// Prime Sieve {2, 3, 5, 7, 11, 13, 17, ...}\nvector<int>\
    \ prime_enumerate(int N) {\n  vector<bool> sieve(N / 3 + 1, 1);\n  for (int p\
    \ = 5, d = 4, i = 1, sqn = sqrt(N); p <= sqn; p += d = 6 - d, i++) {\n    if (!sieve[i])\
    \ continue;\n    for (int q = p * p / 3, r = d * p / 3 + (d * p % 3 == 2), s =\
    \ 2 * p,\n             qe = sieve.size();\n         q < qe; q += r = s - r)\n\
    \      sieve[q] = 0;\n  }\n  vector<int> ret{2, 3};\n  for (int p = 5, d = 4,\
    \ i = 1; p <= N; p += d = 6 - d, i++)\n    if (sieve[i]) ret.push_back(p);\n \
    \ while (!ret.empty() && ret.back() > N) ret.pop_back();\n  return ret;\n}\n#line\
    \ 6 \"multiplicative-function/divisor-multiple-transform.hpp\"\n\nstruct divisor_transform\
    \ {\n  template <typename T>\n  static void zeta_transform(vector<T> &a) {\n \
    \   int N = a.size() - 1;\n    auto sieve = prime_enumerate(N);\n    for (auto\
    \ &p : sieve)\n      for (int k = 1; k * p <= N; ++k) a[k * p] += a[k];\n  }\n\
    \  template <typename T>\n  static void mobius_transform(T &a) {\n    int N =\
    \ a.size() - 1;\n    auto sieve = prime_enumerate(N);\n    for (auto &p : sieve)\n\
    \      for (int k = N / p; k > 0; --k) a[k * p] -= a[k];\n  }\n\n  template <typename\
    \ T>\n  static void zeta_transform(map<long long, T> &a) {\n    for (auto &x :\
    \ a)\n      for (auto &y : a) {\n        if (x == y) break;\n        if (x.first\
    \ % y.first == 0) x.second += y.second;\n      }\n  }\n  template <typename T>\n\
    \  static void mobius_transform(map<long long, T> &a) {\n    for (auto &x : a)\n\
    \      for (auto &y : a) {\n        if (x == y) break;\n        if (x.first %\
    \ y.first == 0) x.second -= y.second;\n      }\n  }\n};\n\nstruct multiple_transform\
    \ {\n  template <typename T>\n  static void zeta_transform(vector<T> &a) {\n \
    \   int N = a.size() - 1;\n    auto sieve = prime_enumerate(N);\n    for (auto\
    \ &p : sieve)\n      for (int k = N / p; k > 0; --k) a[k] += a[k * p];\n  }\n\
    \  template <typename T>\n  static void mobius_transform(vector<T> &a) {\n   \
    \ int N = a.size() - 1;\n    auto sieve = prime_enumerate(N);\n    for (auto &p\
    \ : sieve)\n      for (int k = 1; k * p <= N; ++k) a[k] -= a[k * p];\n  }\n\n\
    \  template <typename T>\n  static void zeta_transform(map<long long, T> &a) {\n\
    \    for (auto p1 = rbegin(a); p1 != rend(a); p1++)\n      for (auto p2 = rbegin(a);\
    \ p2 != p1; p2++)\n        if (p2->first % p1->first == 0) p1->second += p2->second;\n\
    \  }\n  template <typename T>\n  static void mobius_transform(map<long long, T>\
    \ &a) {\n    for (auto p1 = rbegin(a); p1 != rend(a); p1++)\n      for (auto p2\
    \ = rbegin(a); p2 != p1; p2++)\n        if (p2->first % p1->first == 0) p1->second\
    \ -= p2->second;\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"../prime/prime-enumerate.hpp\"\n\nstruct divisor_transform {\n  template <typename\
    \ T>\n  static void zeta_transform(vector<T> &a) {\n    int N = a.size() - 1;\n\
    \    auto sieve = prime_enumerate(N);\n    for (auto &p : sieve)\n      for (int\
    \ k = 1; k * p <= N; ++k) a[k * p] += a[k];\n  }\n  template <typename T>\n  static\
    \ void mobius_transform(T &a) {\n    int N = a.size() - 1;\n    auto sieve = prime_enumerate(N);\n\
    \    for (auto &p : sieve)\n      for (int k = N / p; k > 0; --k) a[k * p] -=\
    \ a[k];\n  }\n\n  template <typename T>\n  static void zeta_transform(map<long\
    \ long, T> &a) {\n    for (auto &x : a)\n      for (auto &y : a) {\n        if\
    \ (x == y) break;\n        if (x.first % y.first == 0) x.second += y.second;\n\
    \      }\n  }\n  template <typename T>\n  static void mobius_transform(map<long\
    \ long, T> &a) {\n    for (auto &x : a)\n      for (auto &y : a) {\n        if\
    \ (x == y) break;\n        if (x.first % y.first == 0) x.second -= y.second;\n\
    \      }\n  }\n};\n\nstruct multiple_transform {\n  template <typename T>\n  static\
    \ void zeta_transform(vector<T> &a) {\n    int N = a.size() - 1;\n    auto sieve\
    \ = prime_enumerate(N);\n    for (auto &p : sieve)\n      for (int k = N / p;\
    \ k > 0; --k) a[k] += a[k * p];\n  }\n  template <typename T>\n  static void mobius_transform(vector<T>\
    \ &a) {\n    int N = a.size() - 1;\n    auto sieve = prime_enumerate(N);\n   \
    \ for (auto &p : sieve)\n      for (int k = 1; k * p <= N; ++k) a[k] -= a[k *\
    \ p];\n  }\n\n  template <typename T>\n  static void zeta_transform(map<long long,\
    \ T> &a) {\n    for (auto p1 = rbegin(a); p1 != rend(a); p1++)\n      for (auto\
    \ p2 = rbegin(a); p2 != p1; p2++)\n        if (p2->first % p1->first == 0) p1->second\
    \ += p2->second;\n  }\n  template <typename T>\n  static void mobius_transform(map<long\
    \ long, T> &a) {\n    for (auto p1 = rbegin(a); p1 != rend(a); p1++)\n      for\
    \ (auto p2 = rbegin(a); p2 != p1; p2++)\n        if (p2->first % p1->first ==\
    \ 0) p1->second -= p2->second;\n  }\n};\n"
  dependsOn:
  - prime/prime-enumerate.hpp
  isVerificationFile: false
  path: multiplicative-function/divisor-multiple-transform.hpp
  requiredBy:
  - multiplicative-function/mf-famous-series.hpp
  timestamp: '2020-12-02 11:16:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: multiplicative-function/divisor-multiple-transform.hpp
layout: document
redirect_from:
- /library/multiplicative-function/divisor-multiple-transform.hpp
- /library/multiplicative-function/divisor-multiple-transform.hpp.html
title: multiplicative-function/divisor-multiple-transform.hpp
---
