---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: multiplicative-function/divisor-multiple-transform.hpp
    title: "\u500D\u6570\u5909\u63DB\u30FB\u7D04\u6570\u5909\u63DB"
  - icon: ':heavy_check_mark:'
    path: prime/prime-enumerate.hpp
    title: prime/prime-enumerate.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-gcd-convolution.test.cpp
    title: verify/verify-yosupo-math/yosupo-gcd-convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0886.test.cpp
    title: verify/verify-yuki/yuki-0886.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "GCD\u7573\u307F\u8FBC\u307F"
    links: []
  bundledCode: "#line 2 \"multiplicative-function/gcd-convolution.hpp\"\n\n\n\n#line\
    \ 2 \"multiplicative-function/divisor-multiple-transform.hpp\"\n\n#include <map>\n\
    #include <vector>\nusing namespace std;\n\n#line 2 \"prime/prime-enumerate.hpp\"\
    \n\n// Prime Sieve {2, 3, 5, 7, 11, 13, 17, ...}\nvector<int> prime_enumerate(int\
    \ N) {\n  vector<bool> sieve(N / 3 + 1, 1);\n  for (int p = 5, d = 4, i = 1, sqn\
    \ = sqrt(N); p <= sqn; p += d = 6 - d, i++) {\n    if (!sieve[i]) continue;\n\
    \    for (int q = p * p / 3, r = d * p / 3 + (d * p % 3 == 2), s = 2 * p,\n  \
    \           qe = sieve.size();\n         q < qe; q += r = s - r)\n      sieve[q]\
    \ = 0;\n  }\n  vector<int> ret{2, 3};\n  for (int p = 5, d = 4, i = 1; p <= N;\
    \ p += d = 6 - d, i++)\n    if (sieve[i]) ret.push_back(p);\n  while (!ret.empty()\
    \ && ret.back() > N) ret.pop_back();\n  return ret;\n}\n#line 8 \"multiplicative-function/divisor-multiple-transform.hpp\"\
    \n\nstruct divisor_transform {\n  template <typename T>\n  static void zeta_transform(vector<T>\
    \ &a) {\n    int N = a.size() - 1;\n    auto sieve = prime_enumerate(N);\n   \
    \ for (auto &p : sieve)\n      for (int k = 1; k * p <= N; ++k) a[k * p] += a[k];\n\
    \  }\n  template <typename T>\n  static void mobius_transform(vector<T> &a) {\n\
    \    int N = a.size() - 1;\n    auto sieve = prime_enumerate(N);\n    for (auto\
    \ &p : sieve)\n      for (int k = N / p; k > 0; --k) a[k * p] -= a[k];\n  }\n\n\
    \  template <typename I, typename T>\n  static void zeta_transform(map<I, T> &a)\
    \ {\n    for (auto p = rbegin(a); p != rend(a); p++)\n      for (auto &x : a)\
    \ {\n        if (p->first == x.first) break;\n        if (p->first % x.first ==\
    \ 0) p->second += x.second;\n      }\n  }\n  template <typename I, typename T>\n\
    \  static void mobius_transform(map<I, T> &a) {\n    for (auto &x : a) {\n   \
    \   for (auto p = rbegin(a); p != rend(a); p++) {\n        if (x.first == p->first)\
    \ break;\n        if (p->first % x.first == 0) p->second -= x.second;\n      }\n\
    \    }\n  }\n};\n\nstruct multiple_transform {\n  template <typename T>\n  static\
    \ void zeta_transform(vector<T> &a) {\n    int N = a.size() - 1;\n    auto sieve\
    \ = prime_enumerate(N);\n    for (auto &p : sieve)\n      for (int k = N / p;\
    \ k > 0; --k) a[k] += a[k * p];\n  }\n  template <typename T>\n  static void mobius_transform(vector<T>\
    \ &a) {\n    int N = a.size() - 1;\n    auto sieve = prime_enumerate(N);\n   \
    \ for (auto &p : sieve)\n      for (int k = 1; k * p <= N; ++k) a[k] -= a[k *\
    \ p];\n  }\n\n  template <typename I, typename T>\n  static void zeta_transform(map<I,\
    \ T> &a) {\n    for (auto &x : a)\n      for (auto p = rbegin(a); p->first !=\
    \ x.first; p++)\n        if (p->first % x.first == 0) x.second += p->second;\n\
    \  }\n  template <typename I, typename T>\n  static void mobius_transform(map<I,\
    \ T> &a) {\n    for (auto p1 = rbegin(a); p1 != rend(a); p1++)\n      for (auto\
    \ p2 = rbegin(a); p2 != p1; p2++)\n        if (p2->first % p1->first == 0) p1->second\
    \ -= p2->second;\n  }\n};\n\n/**\n * @brief \u500D\u6570\u5909\u63DB\u30FB\u7D04\
    \u6570\u5909\u63DB\n * @docs docs/multiplicative-function/divisor-multiple-transform.md\n\
    \ */\n#line 6 \"multiplicative-function/gcd-convolution.hpp\"\n\ntemplate <typename\
    \ mint>\nvector<mint> gcd_convolution(const vector<mint>& a, const vector<mint>&\
    \ b) {\n  assert(a.size() == b.size());\n  auto s = a, t = b;\n  multiple_transform::zeta_transform(s);\n\
    \  multiple_transform::zeta_transform(t);\n  for (int i = 0; i < (int)a.size();\
    \ i++) s[i] *= t[i];\n  multiple_transform::mobius_transform(s);\n  return s;\n\
    }\n\n/**\n * @brief GCD\u7573\u307F\u8FBC\u307F\n */\n"
  code: "#pragma once\n\n\n\n#include \"divisor-multiple-transform.hpp\"\n\ntemplate\
    \ <typename mint>\nvector<mint> gcd_convolution(const vector<mint>& a, const vector<mint>&\
    \ b) {\n  assert(a.size() == b.size());\n  auto s = a, t = b;\n  multiple_transform::zeta_transform(s);\n\
    \  multiple_transform::zeta_transform(t);\n  for (int i = 0; i < (int)a.size();\
    \ i++) s[i] *= t[i];\n  multiple_transform::mobius_transform(s);\n  return s;\n\
    }\n\n/**\n * @brief GCD\u7573\u307F\u8FBC\u307F\n */\n"
  dependsOn:
  - multiplicative-function/divisor-multiple-transform.hpp
  - prime/prime-enumerate.hpp
  isVerificationFile: false
  path: multiplicative-function/gcd-convolution.hpp
  requiredBy: []
  timestamp: '2023-08-30 23:05:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-0886.test.cpp
  - verify/verify-yosupo-math/yosupo-gcd-convolution.test.cpp
documentation_of: multiplicative-function/gcd-convolution.hpp
layout: document
redirect_from:
- /library/multiplicative-function/gcd-convolution.hpp
- /library/multiplicative-function/gcd-convolution.hpp.html
title: "GCD\u7573\u307F\u8FBC\u307F"
---
