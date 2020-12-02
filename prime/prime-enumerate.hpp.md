---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: multiplicative-function/divisor-multiple-transform.hpp
    title: "\u500D\u6570\u5909\u63DB\u30FB\u7D04\u6570\u5909\u63DB"
  - icon: ':heavy_check_mark:'
    path: multiplicative-function/gcd-convolution.hpp
    title: "GCD\u7573\u307F\u8FBC\u307F"
  - icon: ':warning:'
    path: multiplicative-function/mf-famous-series.hpp
    title: multiplicative-function/mf-famous-series.hpp
  - icon: ':heavy_check_mark:'
    path: multiplicative-function/prime-counting-o2d3.hpp
    title: "\u7D20\u6570\u30AB\u30A6\u30F3\u30C8( $\\mathrm{O}(N^{\\frac{2}{3}})$\
      \ )"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-counting-primes-2.test.cpp
    title: verify/verify-yosupo-math/yosupo-counting-primes-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-prime-table.test.cpp
    title: verify/verify-yosupo-math/yosupo-prime-table.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0125.test.cpp
    title: verify/verify-yuki/yuki-0125.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0886.test.cpp
    title: verify/verify-yuki/yuki-0886.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0890.test.cpp
    title: verify/verify-yuki/yuki-0890.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-0896.test.cpp
    title: verify/verify-yuki/yuki-0896.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"prime/prime-enumerate.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n// Prime Sieve {2, 3, 5, 7, 11, 13, 17, ...}\nvector<int>\
    \ prime_enumerate(int N) {\n  vector<bool> sieve(N / 3 + 1, 1);\n  for (int p\
    \ = 5, d = 4, i = 1, sqn = sqrt(N); p <= sqn; p += d = 6 - d, i++) {\n    if (!sieve[i])\
    \ continue;\n    for (int q = p * p / 3, r = d * p / 3 + (d * p % 3 == 2), s =\
    \ 2 * p,\n             qe = sieve.size();\n         q < qe; q += r = s - r)\n\
    \      sieve[q] = 0;\n  }\n  vector<int> ret{2, 3};\n  for (int p = 5, d = 4,\
    \ i = 1; p <= N; p += d = 6 - d, i++)\n    if (sieve[i]) ret.push_back(p);\n \
    \ while (!ret.empty() && ret.back() > N) ret.pop_back();\n  return ret;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Prime\
    \ Sieve {2, 3, 5, 7, 11, 13, 17, ...}\nvector<int> prime_enumerate(int N) {\n\
    \  vector<bool> sieve(N / 3 + 1, 1);\n  for (int p = 5, d = 4, i = 1, sqn = sqrt(N);\
    \ p <= sqn; p += d = 6 - d, i++) {\n    if (!sieve[i]) continue;\n    for (int\
    \ q = p * p / 3, r = d * p / 3 + (d * p % 3 == 2), s = 2 * p,\n             qe\
    \ = sieve.size();\n         q < qe; q += r = s - r)\n      sieve[q] = 0;\n  }\n\
    \  vector<int> ret{2, 3};\n  for (int p = 5, d = 4, i = 1; p <= N; p += d = 6\
    \ - d, i++)\n    if (sieve[i]) ret.push_back(p);\n  while (!ret.empty() && ret.back()\
    \ > N) ret.pop_back();\n  return ret;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: prime/prime-enumerate.hpp
  requiredBy:
  - multiplicative-function/prime-counting-o2d3.hpp
  - multiplicative-function/mf-famous-series.hpp
  - multiplicative-function/gcd-convolution.hpp
  - multiplicative-function/divisor-multiple-transform.hpp
  timestamp: '2020-09-18 02:20:07+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-prime-table.test.cpp
  - verify/verify-yosupo-math/yosupo-counting-primes-2.test.cpp
  - verify/verify-yuki/yuki-0886.test.cpp
  - verify/verify-yuki/yuki-0890.test.cpp
  - verify/verify-yuki/yuki-0896.test.cpp
  - verify/verify-yuki/yuki-0125.test.cpp
documentation_of: prime/prime-enumerate.hpp
layout: document
redirect_from:
- /library/prime/prime-enumerate.hpp
- /library/prime/prime-enumerate.hpp.html
title: prime/prime-enumerate.hpp
---
