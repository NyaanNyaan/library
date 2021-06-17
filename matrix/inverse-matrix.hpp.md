---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: matrix/gauss-elimination.hpp
    title: matrix/gauss-elimination.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/inverse-matrix.test.cpp
    title: verify/verify-unit-test/inverse-matrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"matrix/inverse-matrix.hpp\"\n\n#line 2 \"matrix/gauss-elimination.hpp\"\
    \n\ntemplate <typename mint>\nstd::pair<int, mint> GaussElimination(vector<vector<mint>>\
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
    \    }\n    rank++;\n  }\n  return make_pair(rank, det);\n}\n#line 4 \"matrix/inverse-matrix.hpp\"\
    \n\ntemplate <typename mint>\nvector<vector<mint>> inverse_matrix(const vector<vector<mint>>&\
    \ a) {\n  int N = a.size();\n  assert(N > 0);\n  assert(N == (int)a[0].size());\n\
    \n  vector<vector<mint>> m(N, vector<mint>(2 * N));\n  for (int i = 0; i < N;\
    \ i++) {\n    copy(begin(a[i]), end(a[i]), begin(m[i]));\n    m[i][N + i] = 1;\n\
    \  }\n\n  auto [rank, det] = GaussElimination(m, N, true);\n  if (rank != N) return\
    \ {};\n\n  vector<vector<mint>> b(N);\n  for (int i = 0; i < N; i++) {\n    copy(begin(m[i])\
    \ + N, end(m[i]), back_inserter(b[i]));\n  }\n  return b;\n}\n"
  code: "#pragma once\n\n#include \"gauss-elimination.hpp\"\n\ntemplate <typename\
    \ mint>\nvector<vector<mint>> inverse_matrix(const vector<vector<mint>>& a) {\n\
    \  int N = a.size();\n  assert(N > 0);\n  assert(N == (int)a[0].size());\n\n \
    \ vector<vector<mint>> m(N, vector<mint>(2 * N));\n  for (int i = 0; i < N; i++)\
    \ {\n    copy(begin(a[i]), end(a[i]), begin(m[i]));\n    m[i][N + i] = 1;\n  }\n\
    \n  auto [rank, det] = GaussElimination(m, N, true);\n  if (rank != N) return\
    \ {};\n\n  vector<vector<mint>> b(N);\n  for (int i = 0; i < N; i++) {\n    copy(begin(m[i])\
    \ + N, end(m[i]), back_inserter(b[i]));\n  }\n  return b;\n}\n"
  dependsOn:
  - matrix/gauss-elimination.hpp
  isVerificationFile: false
  path: matrix/inverse-matrix.hpp
  requiredBy: []
  timestamp: '2021-06-17 21:43:35+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/inverse-matrix.test.cpp
documentation_of: matrix/inverse-matrix.hpp
layout: document
redirect_from:
- /library/matrix/inverse-matrix.hpp
- /library/matrix/inverse-matrix.hpp.html
title: matrix/inverse-matrix.hpp
---
