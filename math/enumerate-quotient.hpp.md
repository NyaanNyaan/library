---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/enumerate-quotient.test.cpp
    title: verify/verify-unit-test/enumerate-quotient.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-counting-primes-4.test.cpp
    title: verify/verify-yosupo-math/yosupo-counting-primes-4.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u5546\u306E\u5217\u6319"
    links: []
  bundledCode: "#line 2 \"math/enumerate-quotient.hpp\"\n\n// { (q, l, r) : forall\
    \ x in (l,r], floor(N/x) = q }\n// \u3092\u5F15\u6570\u306B\u53D6\u308B\u95A2\u6570\
    f(q, l, r)\u3092\u6E21\u3059\u3002\u7BC4\u56F2\u304C\u5DE6\u306B\u534A\u958B\u306A\
    \u306E\u306B\u6CE8\u610F\ntemplate <typename T, typename F>\nvoid enumerate_quotient(T\
    \ N, const F& f) {\n  T sq = sqrt(N), upper = N, quo = 0;\n  while (upper > sq)\
    \ {\n    T thres = N / (++quo + 1);\n    f(quo, thres, upper);\n    upper = thres;\n\
    \  }\n  while (upper > 0) {\n    f(N / upper, upper - 1, upper);\n    upper--;\n\
    \  }\n}\n\n/**\n *  @brief \u5546\u306E\u5217\u6319\n */\n"
  code: "#pragma once\n\n// { (q, l, r) : forall x in (l,r], floor(N/x) = q }\n//\
    \ \u3092\u5F15\u6570\u306B\u53D6\u308B\u95A2\u6570f(q, l, r)\u3092\u6E21\u3059\
    \u3002\u7BC4\u56F2\u304C\u5DE6\u306B\u534A\u958B\u306A\u306E\u306B\u6CE8\u610F\
    \ntemplate <typename T, typename F>\nvoid enumerate_quotient(T N, const F& f)\
    \ {\n  T sq = sqrt(N), upper = N, quo = 0;\n  while (upper > sq) {\n    T thres\
    \ = N / (++quo + 1);\n    f(quo, thres, upper);\n    upper = thres;\n  }\n  while\
    \ (upper > 0) {\n    f(N / upper, upper - 1, upper);\n    upper--;\n  }\n}\n\n\
    /**\n *  @brief \u5546\u306E\u5217\u6319\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: math/enumerate-quotient.hpp
  requiredBy: []
  timestamp: '2021-08-10 23:14:36+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-counting-primes-4.test.cpp
  - verify/verify-unit-test/enumerate-quotient.test.cpp
documentation_of: math/enumerate-quotient.hpp
layout: document
redirect_from:
- /library/math/enumerate-quotient.hpp
- /library/math/enumerate-quotient.hpp.html
title: "\u5546\u306E\u5217\u6319"
---
