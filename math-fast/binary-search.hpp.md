---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/fast-bs.test.cpp
    title: verify/verify-unit-test/fast-bs.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math-fast/binary-search.hpp\"\n\n#include <vector>\nusing\
    \ namespace std;\n\ntemplate <typename T, typename C>\nint fast_bs(const vector<T>&\
    \ v, const T& x, const C& comp) {\n  if (v.empty() or comp(x, v[0])) return 0;\n\
    \  const T* p = v.data();\n  int s = v.size();\n  int t = 63 - __builtin_clzll(s);\n\
    \  int b = s - (1 << t);\n  int l = comp(x, p[b]) ? 0 : b;\n  if (t == 0) return\
    \ l + 1;\n  for (int d = 1 << (t - 1); d; d /= 2) {\n    l = comp(x, p[l + d])\
    \ ? l : l + d;\n  }\n  return l + 1;\n}\n\ntemplate <typename T>\nint fast_lb(const\
    \ vector<T>& v, const T& x) {\n  return fast_bs(v, x, std::less_equal<T>{});\n\
    }\n\ntemplate <typename T>\nint fast_ub(const vector<T>& v, const T& x) {\n  return\
    \ fast_bs(v, x, std::less<T>{});\n}\n"
  code: "#pragma once\n\n#include <vector>\nusing namespace std;\n\ntemplate <typename\
    \ T, typename C>\nint fast_bs(const vector<T>& v, const T& x, const C& comp) {\n\
    \  if (v.empty() or comp(x, v[0])) return 0;\n  const T* p = v.data();\n  int\
    \ s = v.size();\n  int t = 63 - __builtin_clzll(s);\n  int b = s - (1 << t);\n\
    \  int l = comp(x, p[b]) ? 0 : b;\n  if (t == 0) return l + 1;\n  for (int d =\
    \ 1 << (t - 1); d; d /= 2) {\n    l = comp(x, p[l + d]) ? l : l + d;\n  }\n  return\
    \ l + 1;\n}\n\ntemplate <typename T>\nint fast_lb(const vector<T>& v, const T&\
    \ x) {\n  return fast_bs(v, x, std::less_equal<T>{});\n}\n\ntemplate <typename\
    \ T>\nint fast_ub(const vector<T>& v, const T& x) {\n  return fast_bs(v, x, std::less<T>{});\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: math-fast/binary-search.hpp
  requiredBy: []
  timestamp: '2023-05-22 22:45:10+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/fast-bs.test.cpp
documentation_of: math-fast/binary-search.hpp
layout: document
redirect_from:
- /library/math-fast/binary-search.hpp
- /library/math-fast/binary-search.hpp.html
title: math-fast/binary-search.hpp
---
