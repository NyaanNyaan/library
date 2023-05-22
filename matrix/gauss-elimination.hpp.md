---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/find-p-recursive.hpp
    title: "P-recursive\u306E\u9AD8\u901F\u8A08\u7B97"
  - icon: ':heavy_check_mark:'
    path: matrix/inverse-matrix.hpp
    title: matrix/inverse-matrix.hpp
  - icon: ':heavy_check_mark:'
    path: matrix/linear-equation.hpp
    title: matrix/linear-equation.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-2171-bigrational.test.cpp
    title: verify/verify-aoj-other/aoj-2171-bigrational.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-aoj-other/aoj-2171.test.cpp
    title: verify/verify-aoj-other/aoj-2171.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/gauss-elimination.test.cpp
    title: verify/verify-unit-test/gauss-elimination.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/inverse-matrix.test.cpp
    title: verify/verify-unit-test/inverse-matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/p-recursive.test.cpp
    title: verify/verify-unit-test/p-recursive.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-inverse-matrix.test.cpp
    title: verify/verify-yosupo-math/yosupo-inverse-matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-linear-equation-2.test.cpp
    title: verify/verify-yosupo-math/yosupo-linear-equation-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1533.test.cpp
    title: verify/verify-yuki/yuki-1533.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"matrix/gauss-elimination.hpp\"\n\n#include <utility>\n#include\
    \ <vector>\nusing namespace std;\n\n// {rank, det(\u975E\u6B63\u65B9\u884C\u5217\
    \u306E\u5834\u5408\u306F\u672A\u5B9A\u7FA9)} \u3092\u8FD4\u3059\n// \u578B\u304C\
    \ double \u3084 Rational \u3067\u3082\u52D5\u304F\u306F\u305A\uFF1F(\u672A\u691C\
    \u8A3C)\n//\n// pivot \u5019\u88DC : [0, pivot_end)\ntemplate <typename T>\nstd::pair<int,\
    \ T> GaussElimination(vector<vector<T>> &a, int pivot_end = -1,\n            \
    \                       bool diagonalize = false) {\n  int H = a.size(), W = a[0].size(),\
    \ rank = 0;\n  if (pivot_end == -1) pivot_end = W;\n  T det = 1;\n  for (int j\
    \ = 0; j < pivot_end; j++) {\n    int idx = -1;\n    for (int i = rank; i < H;\
    \ i++) {\n      if (a[i][j] != T(0)) {\n        idx = i;\n        break;\n   \
    \   }\n    }\n    if (idx == -1) {\n      det = 0;\n      continue;\n    }\n \
    \   if (rank != idx) det = -det, swap(a[rank], a[idx]);\n    det *= a[rank][j];\n\
    \    if (diagonalize && a[rank][j] != T(1)) {\n      T coeff = T(1) / a[rank][j];\n\
    \      for (int k = j; k < W; k++) a[rank][k] *= coeff;\n    }\n    int is = diagonalize\
    \ ? 0 : rank + 1;\n    for (int i = is; i < H; i++) {\n      if (i == rank) continue;\n\
    \      if (a[i][j] != T(0)) {\n        T coeff = a[i][j] / a[rank][j];\n     \
    \   for (int k = j; k < W; k++) a[i][k] -= a[rank][k] * coeff;\n      }\n    }\n\
    \    rank++;\n  }\n  return make_pair(rank, det);\n}\n"
  code: "#pragma once\n\n#include <utility>\n#include <vector>\nusing namespace std;\n\
    \n// {rank, det(\u975E\u6B63\u65B9\u884C\u5217\u306E\u5834\u5408\u306F\u672A\u5B9A\
    \u7FA9)} \u3092\u8FD4\u3059\n// \u578B\u304C double \u3084 Rational \u3067\u3082\
    \u52D5\u304F\u306F\u305A\uFF1F(\u672A\u691C\u8A3C)\n//\n// pivot \u5019\u88DC\
    \ : [0, pivot_end)\ntemplate <typename T>\nstd::pair<int, T> GaussElimination(vector<vector<T>>\
    \ &a, int pivot_end = -1,\n                                   bool diagonalize\
    \ = false) {\n  int H = a.size(), W = a[0].size(), rank = 0;\n  if (pivot_end\
    \ == -1) pivot_end = W;\n  T det = 1;\n  for (int j = 0; j < pivot_end; j++) {\n\
    \    int idx = -1;\n    for (int i = rank; i < H; i++) {\n      if (a[i][j] !=\
    \ T(0)) {\n        idx = i;\n        break;\n      }\n    }\n    if (idx == -1)\
    \ {\n      det = 0;\n      continue;\n    }\n    if (rank != idx) det = -det,\
    \ swap(a[rank], a[idx]);\n    det *= a[rank][j];\n    if (diagonalize && a[rank][j]\
    \ != T(1)) {\n      T coeff = T(1) / a[rank][j];\n      for (int k = j; k < W;\
    \ k++) a[rank][k] *= coeff;\n    }\n    int is = diagonalize ? 0 : rank + 1;\n\
    \    for (int i = is; i < H; i++) {\n      if (i == rank) continue;\n      if\
    \ (a[i][j] != T(0)) {\n        T coeff = a[i][j] / a[rank][j];\n        for (int\
    \ k = j; k < W; k++) a[i][k] -= a[rank][k] * coeff;\n      }\n    }\n    rank++;\n\
    \  }\n  return make_pair(rank, det);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: matrix/gauss-elimination.hpp
  requiredBy:
  - fps/find-p-recursive.hpp
  - matrix/inverse-matrix.hpp
  - matrix/linear-equation.hpp
  timestamp: '2023-05-22 22:29:25+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-1533.test.cpp
  - verify/verify-yosupo-math/yosupo-linear-equation-2.test.cpp
  - verify/verify-yosupo-math/yosupo-inverse-matrix.test.cpp
  - verify/verify-unit-test/inverse-matrix.test.cpp
  - verify/verify-unit-test/gauss-elimination.test.cpp
  - verify/verify-unit-test/p-recursive.test.cpp
  - verify/verify-aoj-other/aoj-2171.test.cpp
  - verify/verify-aoj-other/aoj-2171-bigrational.test.cpp
documentation_of: matrix/gauss-elimination.hpp
layout: document
redirect_from:
- /library/matrix/gauss-elimination.hpp
- /library/matrix/gauss-elimination.hpp.html
title: matrix/gauss-elimination.hpp
---
