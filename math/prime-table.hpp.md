---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/prime-counting-o2d3.hpp
    title: "\u7D20\u6570\u30AB\u30A6\u30F3\u30C8( $\\mathrm{O}(N^{\\frac{2}{3}})$\
      \ )"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-counting-primes-2.test.cpp
    title: verify/verify-yosupo-math/yosupo-counting-primes-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-prime-table.test.cpp
    title: verify/verify-yosupo-math/yosupo-prime-table.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"math/prime-table.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\n// Prime Sieve {2, 3, 5, 7, 11, 13, 17, ...}\nvector<int>\
    \ PrimeTable(int N) {\n  vector<bool> sieve(N / 3 + 1, 1);\n  for (int p = 5,\
    \ d = 4, i = 1, sqn = int(sqrt(N) + 0.1); p <= sqn;\n       p += d = 6 - d, i++)\
    \ {\n    if (!sieve[i]) continue;\n    for (int q = p * p / 3, r = d * p / 3 +\
    \ (d * p % 3 == 2), s = 2 * p,\n             qe = sieve.size();\n         q <\
    \ qe; q += r = s - r)\n      sieve[q] = 0;\n  }\n  vector<int> ret{2, 3};\n  for\
    \ (int p = 5, d = 4, i = 1; p <= N; p += d = 6 - d, i++)\n    if (sieve[i]) ret.push_back(p);\n\
    \  while (!ret.empty() && ret.back() > N) ret.pop_back();\n  return ret;\n}\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n// Prime\
    \ Sieve {2, 3, 5, 7, 11, 13, 17, ...}\nvector<int> PrimeTable(int N) {\n  vector<bool>\
    \ sieve(N / 3 + 1, 1);\n  for (int p = 5, d = 4, i = 1, sqn = int(sqrt(N) + 0.1);\
    \ p <= sqn;\n       p += d = 6 - d, i++) {\n    if (!sieve[i]) continue;\n   \
    \ for (int q = p * p / 3, r = d * p / 3 + (d * p % 3 == 2), s = 2 * p,\n     \
    \        qe = sieve.size();\n         q < qe; q += r = s - r)\n      sieve[q]\
    \ = 0;\n  }\n  vector<int> ret{2, 3};\n  for (int p = 5, d = 4, i = 1; p <= N;\
    \ p += d = 6 - d, i++)\n    if (sieve[i]) ret.push_back(p);\n  while (!ret.empty()\
    \ && ret.back() > N) ret.pop_back();\n  return ret;\n}"
  dependsOn: []
  isVerificationFile: false
  path: math/prime-table.hpp
  requiredBy:
  - math/prime-counting-o2d3.hpp
  timestamp: '2020-08-09 16:04:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-counting-primes-2.test.cpp
  - verify/verify-yosupo-math/yosupo-prime-table.test.cpp
documentation_of: math/prime-table.hpp
layout: document
redirect_from:
- /library/math/prime-table.hpp
- /library/math/prime-table.hpp.html
title: math/prime-table.hpp
---
