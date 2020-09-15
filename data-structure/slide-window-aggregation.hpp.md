---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ds/yosupo-swag.test.cpp
    title: verify/verify-yosupo-ds/yosupo-swag.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    links: []
  bundledCode: "#line 2 \"data-structure/slide-window-aggregation.hpp\"\n#include\
    \ <bits/stdc++.h>\nusing namespace std;\n\ntemplate <typename T, typename F>\n\
    struct SlideWindowAggregation {\n  stack<T> a0, a1;\n  stack<T> r0, r1;\n  F f;\n\
    \  T I, f0, f1;\n\n  SlideWindowAggregation(F f_, T I_) : f(f_), I(I_), f0(I_),\
    \ f1(I_) {}\n\n private:\n  void push_s0(const T &x) {\n    a0.push(x);\n    r0.push(f0\
    \ = f(x, f0));\n  }\n  void push_s1(const T &x) {\n    a1.push(x);\n    r1.push(f1\
    \ = f(f1, x));\n  }\n  void transfer() {\n    while (!a1.empty()) {\n      push_s0(a1.top());\n\
    \      a1.pop();\n    }\n    while (!r1.empty()) r1.pop();\n    f1 = I;\n  }\n\
    \n public:\n  void push(const T &x) {\n    if (a0.empty()) {\n      push_s0(x);\n\
    \      transfer();\n    } else {\n      push_s1(x);\n    }\n  }\n  void pop()\
    \ {\n    if (a0.empty()) transfer();\n    a0.pop();\n    r0.pop();\n    f0 = r0.empty()\
    \ ? I : r0.top();\n  }\n  T query() { return f(f0, f1); }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename T, typename F>\nstruct SlideWindowAggregation {\n  stack<T> a0, a1;\n\
    \  stack<T> r0, r1;\n  F f;\n  T I, f0, f1;\n\n  SlideWindowAggregation(F f_,\
    \ T I_) : f(f_), I(I_), f0(I_), f1(I_) {}\n\n private:\n  void push_s0(const T\
    \ &x) {\n    a0.push(x);\n    r0.push(f0 = f(x, f0));\n  }\n  void push_s1(const\
    \ T &x) {\n    a1.push(x);\n    r1.push(f1 = f(f1, x));\n  }\n  void transfer()\
    \ {\n    while (!a1.empty()) {\n      push_s0(a1.top());\n      a1.pop();\n  \
    \  }\n    while (!r1.empty()) r1.pop();\n    f1 = I;\n  }\n\n public:\n  void\
    \ push(const T &x) {\n    if (a0.empty()) {\n      push_s0(x);\n      transfer();\n\
    \    } else {\n      push_s1(x);\n    }\n  }\n  void pop() {\n    if (a0.empty())\
    \ transfer();\n    a0.pop();\n    r0.pop();\n    f0 = r0.empty() ? I : r0.top();\n\
    \  }\n  T query() { return f(f0, f1); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/slide-window-aggregation.hpp
  requiredBy: []
  timestamp: '2020-08-09 17:31:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ds/yosupo-swag.test.cpp
documentation_of: data-structure/slide-window-aggregation.hpp
layout: document
redirect_from:
- /library/data-structure/slide-window-aggregation.hpp
- /library/data-structure/slide-window-aggregation.hpp.html
title: data-structure/slide-window-aggregation.hpp
---
