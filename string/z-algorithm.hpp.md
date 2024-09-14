---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/run-enumerate.hpp
    title: string/run-enumerate.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-string/yosupo-run-enumerate.test.cpp
    title: verify/verify-yosupo-string/yosupo-run-enumerate.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-string/yosupo-z-algorithm.test.cpp
    title: verify/verify-yosupo-string/yosupo-z-algorithm.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: Z algorithm
    links: []
  bundledCode: "#line 2 \"string/z-algorithm.hpp\"\n\ntemplate <typename Container>\n\
    vector<int> z_algorithm(const Container& s) {\n  int n = s.size();\n  if(n ==\
    \ 0) return {};\n  vector<int> a(n);\n  a[0] = n;\n  int i = 1, j = 0;\n  while\
    \ (i < n) {\n    while (i + j < n && s[j] == s[i + j]) j++;\n    a[i] = j;\n \
    \   if (j == 0) {\n      i++;\n      continue;\n    }\n    int k = 1;\n    while\
    \ (i + k < n && k + a[k] < j) a[i + k] = a[k], k++;\n    i += k, j -= k;\n  }\n\
    \  return a;\n}\n\n/**\n * @brief Z algorithm\n */\n"
  code: "#pragma once\n\ntemplate <typename Container>\nvector<int> z_algorithm(const\
    \ Container& s) {\n  int n = s.size();\n  if(n == 0) return {};\n  vector<int>\
    \ a(n);\n  a[0] = n;\n  int i = 1, j = 0;\n  while (i < n) {\n    while (i + j\
    \ < n && s[j] == s[i + j]) j++;\n    a[i] = j;\n    if (j == 0) {\n      i++;\n\
    \      continue;\n    }\n    int k = 1;\n    while (i + k < n && k + a[k] < j)\
    \ a[i + k] = a[k], k++;\n    i += k, j -= k;\n  }\n  return a;\n}\n\n/**\n * @brief\
    \ Z algorithm\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: string/z-algorithm.hpp
  requiredBy:
  - string/run-enumerate.hpp
  timestamp: '2024-09-14 20:40:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-string/yosupo-z-algorithm.test.cpp
  - verify/verify-yosupo-string/yosupo-run-enumerate.test.cpp
documentation_of: string/z-algorithm.hpp
layout: document
redirect_from:
- /library/string/z-algorithm.hpp
- /library/string/z-algorithm.hpp.html
title: Z algorithm
---
