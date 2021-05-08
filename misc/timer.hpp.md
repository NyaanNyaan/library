---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: marathon/simulated-annealing.hpp
    title: Simulated Annealing
  - icon: ':heavy_check_mark:'
    path: trial/fast-gcd.hpp
    title: "\u9AD8\u901FGCD"
  - icon: ':heavy_check_mark:'
    path: trial/fast-inv.hpp
    title: "\u9AD8\u901Fmodulo\u9006\u5143"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/fast-inv-gcd.test.cpp
    title: verify/verify-unit-test/fast-inv-gcd.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/mf.test.cpp
    title: verify/verify-unit-test/mf.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/multipoint-binomial-sum.test.cpp
    title: verify/verify-unit-test/multipoint-binomial-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/simulated-annealing.test.cpp
    title: verify/verify-unit-test/simulated-annealing.test.cpp
  - icon: ':x:'
    path: verify/verify-unit-test/strassen.test.cpp
    title: verify/verify-unit-test/strassen.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/timer.hpp\"\n\nstruct Timer {\n  chrono::high_resolution_clock::time_point\
    \ st;\n\n  Timer() { reset(); }\n\n  void reset() { st = chrono::high_resolution_clock::now();\
    \ }\n\n  chrono::milliseconds::rep elapsed() {\n    auto ed = chrono::high_resolution_clock::now();\n\
    \    return chrono::duration_cast<chrono::milliseconds>(ed - st).count();\n  }\n\
    };\n"
  code: "#pragma once\n\nstruct Timer {\n  chrono::high_resolution_clock::time_point\
    \ st;\n\n  Timer() { reset(); }\n\n  void reset() { st = chrono::high_resolution_clock::now();\
    \ }\n\n  chrono::milliseconds::rep elapsed() {\n    auto ed = chrono::high_resolution_clock::now();\n\
    \    return chrono::duration_cast<chrono::milliseconds>(ed - st).count();\n  }\n\
    };"
  dependsOn: []
  isVerificationFile: false
  path: misc/timer.hpp
  requiredBy:
  - trial/fast-gcd.hpp
  - trial/fast-inv.hpp
  - marathon/simulated-annealing.hpp
  timestamp: '2020-12-08 00:23:55+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/verify-unit-test/mf.test.cpp
  - verify/verify-unit-test/fast-inv-gcd.test.cpp
  - verify/verify-unit-test/simulated-annealing.test.cpp
  - verify/verify-unit-test/multipoint-binomial-sum.test.cpp
  - verify/verify-unit-test/strassen.test.cpp
documentation_of: misc/timer.hpp
layout: document
redirect_from:
- /library/misc/timer.hpp
- /library/misc/timer.hpp.html
title: misc/timer.hpp
---
