---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: math/isqrt.hpp
    title: math/isqrt.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: multiplicative-function/count-square-free.hpp
    title: "\u7121\u5E73\u65B9\u6570\u306E\u6570\u3048\u4E0A\u3052"
  - icon: ':heavy_check_mark:'
    path: multiplicative-function/enumerate-sum-of-multiplicative-function.hpp
    title: "\u4E57\u6CD5\u7684\u95A2\u6570\u306Eprefix sum \u306E\u5217\u6319"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/enumerate-quotient.test.cpp
    title: verify/verify-unit-test/enumerate-quotient.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-count-squarefrees.test.cpp
    title: verify/verify-yosupo-math/yosupo-count-squarefrees.test.cpp
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
    document_title: "\u5546\u306E\u5217\u6319"
    links: []
  bundledCode: "#line 2 \"math/enumerate-quotient.hpp\"\n\n#line 2 \"math/isqrt.hpp\"\
    \n\n#include <cmath>\nusing namespace std;\n\n// floor(sqrt(n)) \u3092\u8FD4\u3059\
    \ (\u305F\u3060\u3057 n \u304C\u8CA0\u306E\u5834\u5408\u306F 0 \u3092\u8FD4\u3059\
    )\nlong long isqrt(long long n) {\n  if (n <= 0) return 0;\n  long long x = sqrt(n);\n\
    \  while ((x + 1) * (x + 1) <= n) x++;\n  while (x * x > n) x--;\n  return x;\n\
    }\n#line 4 \"math/enumerate-quotient.hpp\"\n\nnamespace EnumerateQuotientImpl\
    \ {\nlong long fast_div(long long a, long long b) { return 1.0 * a / b; };\nlong\
    \ long slow_div(long long a, long long b) { return a / b; };\n}  // namespace\
    \ EnumerateQuotientImpl\n\n// { (q, l, r) : forall x in (l,r], floor(N/x) = q\
    \ }\n// \u3092\u5F15\u6570\u306B\u53D6\u308B\u95A2\u6570f(q, l, r)\u3092\u6E21\
    \u3059\u3002\u7BC4\u56F2\u304C\u5DE6\u306B\u534A\u958B\u306A\u306E\u306B\u6CE8\
    \u610F\n// \u5546\u306F\u5C0F\u3055\u3044\u65B9\u304B\u3089\u8D70\u67FB\u3059\u308B\
    \ntemplate <typename T, typename F>\nvoid enumerate_quotient(T N, const F& f)\
    \ {\n  T sq = isqrt(N);\n\n#define FUNC(d)                       \\\n  T upper\
    \ = N, quo = 0;               \\\n  while (upper > sq) {                \\\n \
    \   T thres = d(N, (++quo + 1));      \\\n    f(quo, thres, upper);          \
    \   \\\n    upper = thres;                    \\\n  }                        \
    \           \\\n  while (upper > 0) {                 \\\n    f(d(N, upper), upper\
    \ - 1, upper); \\\n    upper--;                          \\\n  }\n\n  if (N <=\
    \ 1e12) {\n    FUNC(EnumerateQuotientImpl::fast_div);\n  } else {\n    FUNC(EnumerateQuotientImpl::slow_div);\n\
    \  }\n#undef FUNC\n}\n\n/**\n *  @brief \u5546\u306E\u5217\u6319\n */\n"
  code: "#pragma once\n\n#include \"isqrt.hpp\"\n\nnamespace EnumerateQuotientImpl\
    \ {\nlong long fast_div(long long a, long long b) { return 1.0 * a / b; };\nlong\
    \ long slow_div(long long a, long long b) { return a / b; };\n}  // namespace\
    \ EnumerateQuotientImpl\n\n// { (q, l, r) : forall x in (l,r], floor(N/x) = q\
    \ }\n// \u3092\u5F15\u6570\u306B\u53D6\u308B\u95A2\u6570f(q, l, r)\u3092\u6E21\
    \u3059\u3002\u7BC4\u56F2\u304C\u5DE6\u306B\u534A\u958B\u306A\u306E\u306B\u6CE8\
    \u610F\n// \u5546\u306F\u5C0F\u3055\u3044\u65B9\u304B\u3089\u8D70\u67FB\u3059\u308B\
    \ntemplate <typename T, typename F>\nvoid enumerate_quotient(T N, const F& f)\
    \ {\n  T sq = isqrt(N);\n\n#define FUNC(d)                       \\\n  T upper\
    \ = N, quo = 0;               \\\n  while (upper > sq) {                \\\n \
    \   T thres = d(N, (++quo + 1));      \\\n    f(quo, thres, upper);          \
    \   \\\n    upper = thres;                    \\\n  }                        \
    \           \\\n  while (upper > 0) {                 \\\n    f(d(N, upper), upper\
    \ - 1, upper); \\\n    upper--;                          \\\n  }\n\n  if (N <=\
    \ 1e12) {\n    FUNC(EnumerateQuotientImpl::fast_div);\n  } else {\n    FUNC(EnumerateQuotientImpl::slow_div);\n\
    \  }\n#undef FUNC\n}\n\n/**\n *  @brief \u5546\u306E\u5217\u6319\n */\n"
  dependsOn:
  - math/isqrt.hpp
  isVerificationFile: false
  path: math/enumerate-quotient.hpp
  requiredBy:
  - multiplicative-function/enumerate-sum-of-multiplicative-function.hpp
  - multiplicative-function/count-square-free.hpp
  timestamp: '2023-04-10 23:43:04+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-enumerate-quotient.test.cpp
  - verify/verify-yosupo-math/yosupo-sum-of-totient-3.test.cpp
  - verify/verify-yosupo-math/yosupo-counting-primes-4.test.cpp
  - verify/verify-yosupo-math/yosupo-count-squarefrees.test.cpp
  - verify/verify-unit-test/enumerate-quotient.test.cpp
  - verify/verify-yuki/yuki-2262.test.cpp
  - verify/verify-yuki/yuki-2266.test.cpp
documentation_of: math/enumerate-quotient.hpp
layout: document
redirect_from:
- /library/math/enumerate-quotient.hpp
- /library/math/enumerate-quotient.hpp.html
title: "\u5546\u306E\u5217\u6319"
---
