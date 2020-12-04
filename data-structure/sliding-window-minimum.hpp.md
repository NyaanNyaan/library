---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-dsl/aoj-dsl-3-d.test.cpp
    title: verify/verify-aoj-dsl/aoj-dsl-3-d.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"data-structure/sliding-window-minimum.hpp\"\n\n// return\
    \ dat | dat[i] := ( answer of range [i - K, i) )\n// T : data type\n// f : compare\
    \ function\n// K : width of window\ntemplate <typename T, typename F>\nvector<T>\
    \ SlideWindowMinimum(vector<T> &v, F f, int K) {\n  vector<T> dat;\n  int N =\
    \ v.size();\n  dat.resize(N + 1);\n  dat[0] = 0;\n  deque<int> q;\n  for (int\
    \ i = 0; i < K - 1; i++) {\n    while (!q.empty() && (f(v[i], v[q.back()]) ==\
    \ v[i])) q.pop_back();\n    q.push_back(i);\n    dat[i + 1] = v[q.front()];\n\
    \  }\n  for (int i = K; i < N + 1; i++) {\n    T cur = v[i - 1];\n    while (!q.empty()\
    \ && (f(cur, v[q.back()]) == cur)) q.pop_back();\n    q.push_back(i - 1);\n  \
    \  dat[i] = v[q.front()];\n    if (q.front() == i - K) q.pop_front();\n  }\n \
    \ return dat;\n}\n"
  code: "#pragma once\n\n// return dat | dat[i] := ( answer of range [i - K, i) )\n\
    // T : data type\n// f : compare function\n// K : width of window\ntemplate <typename\
    \ T, typename F>\nvector<T> SlideWindowMinimum(vector<T> &v, F f, int K) {\n \
    \ vector<T> dat;\n  int N = v.size();\n  dat.resize(N + 1);\n  dat[0] = 0;\n \
    \ deque<int> q;\n  for (int i = 0; i < K - 1; i++) {\n    while (!q.empty() &&\
    \ (f(v[i], v[q.back()]) == v[i])) q.pop_back();\n    q.push_back(i);\n    dat[i\
    \ + 1] = v[q.front()];\n  }\n  for (int i = K; i < N + 1; i++) {\n    T cur =\
    \ v[i - 1];\n    while (!q.empty() && (f(cur, v[q.back()]) == cur)) q.pop_back();\n\
    \    q.push_back(i - 1);\n    dat[i] = v[q.front()];\n    if (q.front() == i -\
    \ K) q.pop_front();\n  }\n  return dat;\n}"
  dependsOn: []
  isVerificationFile: false
  path: data-structure/sliding-window-minimum.hpp
  requiredBy: []
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-aoj-dsl/aoj-dsl-3-d.test.cpp
documentation_of: data-structure/sliding-window-minimum.hpp
layout: document
redirect_from:
- /library/data-structure/sliding-window-minimum.hpp
- /library/data-structure/sliding-window-minimum.hpp.html
title: data-structure/sliding-window-minimum.hpp
---
