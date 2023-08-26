---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math/enumerate-quotient.hpp
    title: "\u5546\u306E\u5217\u6319"
  - icon: ':heavy_check_mark:'
    path: multiplicative-function/enumerate-sum-of-multiplicative-function.hpp
    title: "\u4E57\u6CD5\u7684\u95A2\u6570\u306Eprefix sum \u306E\u5217\u6319"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/enumerate-quotient.test.cpp
    title: verify/verify-unit-test/enumerate-quotient.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/math.test.cpp
    title: verify/verify-unit-test/math.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-counting-primes-4.test.cpp
    title: verify/verify-yosupo-math/yosupo-counting-primes-4.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-enumerate-quotient.test.cpp
    title: verify/verify-yosupo-math/yosupo-enumerate-quotient.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-sum-of-totient-3.test.cpp
    title: verify/verify-yosupo-math/yosupo-sum-of-totient-3.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-2262.test.cpp
    title: verify/verify-yuki/yuki-2262.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-2266.test.cpp
    title: verify/verify-yuki/yuki-2266.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/isqrt.hpp\"\n\n#include <cmath>\nusing namespace std;\n\
    \n// floor(sqrt(n)) \u3092\u8FD4\u3059 (\u305F\u3060\u3057 n \u304C\u8CA0\u306E\
    \u5834\u5408\u306F 0 \u3092\u8FD4\u3059)\nlong long isqrt(long long n) {\n  if\
    \ (n <= 0) return 0;\n  long long x = sqrt(n);\n  while ((x + 1) * (x + 1) <=\
    \ n) x++;\n  while (x * x > n) x--;\n  return x;\n}\n"
  code: "#pragma once\n\n#include <cmath>\nusing namespace std;\n\n// floor(sqrt(n))\
    \ \u3092\u8FD4\u3059 (\u305F\u3060\u3057 n \u304C\u8CA0\u306E\u5834\u5408\u306F\
    \ 0 \u3092\u8FD4\u3059)\nlong long isqrt(long long n) {\n  if (n <= 0) return\
    \ 0;\n  long long x = sqrt(n);\n  while ((x + 1) * (x + 1) <= n) x++;\n  while\
    \ (x * x > n) x--;\n  return x;\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: math/isqrt.hpp
  requiredBy:
  - math/enumerate-quotient.hpp
  - multiplicative-function/enumerate-sum-of-multiplicative-function.hpp
  timestamp: '2023-04-10 22:57:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-2266.test.cpp
  - verify/verify-yuki/yuki-2262.test.cpp
  - verify/verify-unit-test/math.test.cpp
  - verify/verify-unit-test/enumerate-quotient.test.cpp
  - verify/verify-yosupo-math/yosupo-counting-primes-4.test.cpp
  - verify/verify-yosupo-math/yosupo-sum-of-totient-3.test.cpp
  - verify/verify-yosupo-math/yosupo-enumerate-quotient.test.cpp
documentation_of: math/isqrt.hpp
layout: document
redirect_from:
- /library/math/isqrt.hpp
- /library/math/isqrt.hpp.html
title: math/isqrt.hpp
---
