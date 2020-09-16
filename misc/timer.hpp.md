---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: misc/simulated-annealing.hpp
    title: misc/simulated-annealing.hpp
  - icon: ':x:'
    path: modulo/strassen.hpp
    title: modulo/strassen.hpp
  - icon: ':x:'
    path: fps/fps-composition-fast.hpp
    title: "\u95A2\u6570\u306E\u5408\u6210( $\\mathrm{O}(N^2)$ )"
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yosupo-fps/yosupo-composition.test.cpp
    title: verify/verify-yosupo-fps/yosupo-composition.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
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
  timestamp: '2020-07-28 11:29:32+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yosupo-fps/yosupo-composition.test.cpp
documentation_of: misc/timer.hpp
layout: document
redirect_from:
- /library/misc/timer.hpp
- /library/misc/timer.hpp.html
title: misc/timer.hpp
---
