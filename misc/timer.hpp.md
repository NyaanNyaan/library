---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/fps-composition-fast.hpp
    title: "\u95A2\u6570\u306E\u5408\u6210( $\\mathrm{O}(N^2)$ )"
  - icon: ':warning:'
    path: misc/simulated-annealing.hpp
    title: misc/simulated-annealing.hpp
  - icon: ':heavy_check_mark:'
    path: modulo/strassen.hpp
    title: modulo/strassen.hpp
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
    path: verify/verify-yosupo-fps/yosupo-composition-fast.test.cpp
    title: verify/verify-yosupo-fps/yosupo-composition-fast.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"misc/timer.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\nstruct Timer {\n  chrono::high_resolution_clock::time_point st;\n\n\
    \  Timer() { reset(); }\n\n  void reset() { st = chrono::high_resolution_clock::now();\
    \ }\n\n  chrono::milliseconds::rep elapsed() {\n    auto ed = chrono::high_resolution_clock::now();\n\
    \    return chrono::duration_cast<chrono::milliseconds>(ed - st).count();\n  }\n\
    };\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\nstruct Timer\
    \ {\n  chrono::high_resolution_clock::time_point st;\n\n  Timer() { reset(); }\n\
    \n  void reset() { st = chrono::high_resolution_clock::now(); }\n\n  chrono::milliseconds::rep\
    \ elapsed() {\n    auto ed = chrono::high_resolution_clock::now();\n    return\
    \ chrono::duration_cast<chrono::milliseconds>(ed - st).count();\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: misc/timer.hpp
  requiredBy:
  - misc/simulated-annealing.hpp
  - modulo/strassen.hpp
  - fps/fps-composition-fast.hpp
  - trial/fast-inv.hpp
  - trial/fast-gcd.hpp
  timestamp: '2020-07-28 11:29:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-fps/yosupo-composition-fast.test.cpp
  - verify/verify-unit-test/fast-inv-gcd.test.cpp
documentation_of: misc/timer.hpp
layout: document
redirect_from:
- /library/misc/timer.hpp
- /library/misc/timer.hpp.html
title: misc/timer.hpp
---
