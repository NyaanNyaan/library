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
  bundledCode: "#line 2 \"matrix/gauss-elimination.hpp\"\n\ntemplate <typename mint>\n\
    std::pair<int, mint> GaussElimination(vector<vector<mint>> &a,\n             \
    \                         int pivot_end = -1,\n                              \
    \        bool diagonalize = false) {\n  int H = a.size(), W = a[0].size();\n \
    \ int rank = 0, je = pivot_end;\n  if (je == -1) je = W;\n  mint det = 1;\n  for\
    \ (int j = 0; j < je; j++) {\n    int idx = -1;\n    for (int i = rank; i < H;\
    \ i++) {\n      if (a[i][j] != mint(0)) {\n        idx = i;\n        break;\n\
    \      }\n    }\n    if (idx == -1) {\n      det = 0;\n      continue;\n    }\n\
    \    if (rank != idx) {\n      det = -det;\n      swap(a[rank], a[idx]);\n   \
    \ }\n    det *= a[rank][j];\n    if (diagonalize && a[rank][j] != mint(1)) {\n\
    \      mint coeff = a[rank][j].inverse();\n      for (int k = j; k < W; k++) a[rank][k]\
    \ *= coeff;\n    }\n    int is = diagonalize ? 0 : rank + 1;\n    for (int i =\
    \ is; i < H; i++) {\n      if (i == rank) continue;\n      if (a[i][j] != mint(0))\
    \ {\n        mint coeff = a[i][j] / a[rank][j];\n        for (int k = j; k < W;\
    \ k++) a[i][k] -= a[rank][k] * coeff;\n      }\n    }\n    rank++;\n  }\n  return\
    \ make_pair(rank, det);\n}\n"
  code: "#pragma once\n\ntemplate <typename mint>\nstd::pair<int, mint> GaussElimination(vector<vector<mint>>\
    \ &a,\n                                      int pivot_end = -1,\n           \
    \                           bool diagonalize = false) {\n  int H = a.size(), W\
    \ = a[0].size();\n  int rank = 0, je = pivot_end;\n  if (je == -1) je = W;\n \
    \ mint det = 1;\n  for (int j = 0; j < je; j++) {\n    int idx = -1;\n    for\
    \ (int i = rank; i < H; i++) {\n      if (a[i][j] != mint(0)) {\n        idx =\
    \ i;\n        break;\n      }\n    }\n    if (idx == -1) {\n      det = 0;\n \
    \     continue;\n    }\n    if (rank != idx) {\n      det = -det;\n      swap(a[rank],\
    \ a[idx]);\n    }\n    det *= a[rank][j];\n    if (diagonalize && a[rank][j] !=\
    \ mint(1)) {\n      mint coeff = a[rank][j].inverse();\n      for (int k = j;\
    \ k < W; k++) a[rank][k] *= coeff;\n    }\n    int is = diagonalize ? 0 : rank\
    \ + 1;\n    for (int i = is; i < H; i++) {\n      if (i == rank) continue;\n \
    \     if (a[i][j] != mint(0)) {\n        mint coeff = a[i][j] / a[rank][j];\n\
    \        for (int k = j; k < W; k++) a[i][k] -= a[rank][k] * coeff;\n      }\n\
    \    }\n    rank++;\n  }\n  return make_pair(rank, det);\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: matrix/gauss-elimination.hpp
  requiredBy:
  - fps/find-p-recursive.hpp
  - matrix/inverse-matrix.hpp
  - matrix/linear-equation.hpp
  timestamp: '2021-06-17 21:43:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-linear-equation-2.test.cpp
  - verify/verify-yosupo-math/yosupo-inverse-matrix.test.cpp
  - verify/verify-yuki/yuki-1533.test.cpp
  - verify/verify-unit-test/inverse-matrix.test.cpp
  - verify/verify-unit-test/gauss-elimination.test.cpp
  - verify/verify-unit-test/p-recursive.test.cpp
documentation_of: matrix/gauss-elimination.hpp
layout: document
redirect_from:
- /library/matrix/gauss-elimination.hpp
- /library/matrix/gauss-elimination.hpp.html
title: matrix/gauss-elimination.hpp
---
