---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: matrix/gauss-elimination.hpp
    title: matrix/gauss-elimination.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/find-p-recursive.hpp
    title: "P-recursive\u306E\u9AD8\u901F\u8A08\u7B97"
  - icon: ':heavy_check_mark:'
    path: matrix/matrix-tree.hpp
    title: "\u884C\u5217\u6728\u5B9A\u7406(\u30E9\u30D7\u30E9\u30B7\u30A2\u30F3\u884C\
      \u5217)"
  - icon: ':heavy_check_mark:'
    path: matrix/matrix.hpp
    title: "\u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA"
  - icon: ':heavy_check_mark:'
    path: matrix/polynomial-matrix-determinant.hpp
    title: "\u591A\u9805\u5F0F\u884C\u5217\u306E\u884C\u5217\u5F0F"
  - icon: ':heavy_check_mark:'
    path: matrix/polynomial-matrix-prefix-prod.hpp
    title: "\u591A\u9805\u5F0F\u884C\u5217\u306Eprefix product"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/bigint-gcd.test.cpp
    title: verify/verify-unit-test/bigint-gcd.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/debug.test.cpp
    title: verify/verify-unit-test/debug.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/gauss-elimination.test.cpp
    title: verify/verify-unit-test/gauss-elimination.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/inverse-matrix.test.cpp
    title: verify/verify-unit-test/inverse-matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/multipoint-binomial-sum.test.cpp
    title: verify/verify-unit-test/multipoint-binomial-sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/p-recursive.test.cpp
    title: verify/verify-unit-test/p-recursive.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/polynomial-matrix-prod.test.cpp
    title: verify/verify-unit-test/polynomial-matrix-prod.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-factorial-p-recursive.test.cpp
    title: verify/verify-yosupo-fps/yosupo-factorial-p-recursive.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-determinant-matrixlib.test.cpp
    title: verify/verify-yosupo-math/yosupo-determinant-matrixlib.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-inverse-matrix.test.cpp
    title: verify/verify-yosupo-math/yosupo-inverse-matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-pow-of-matrix.test.cpp
    title: verify/verify-yosupo-math/yosupo-pow-of-matrix.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1303.test.cpp
    title: verify/verify-yuki/yuki-1303.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1533.test.cpp
    title: verify/verify-yuki/yuki-1533.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"matrix/inverse-matrix.hpp\"\n\n#line 2 \"matrix/gauss-elimination.hpp\"\
    \n\n#include <utility>\n#include <vector>\nusing namespace std;\n\n// {rank, det(\u975E\
    \u6B63\u65B9\u884C\u5217\u306E\u5834\u5408\u306F\u672A\u5B9A\u7FA9)} \u3092\u8FD4\
    \u3059\n// \u578B\u304C double \u3084 Rational \u3067\u3082\u52D5\u304F\u306F\u305A\
    \uFF1F(\u672A\u691C\u8A3C)\n//\n// pivot \u5019\u88DC : [0, pivot_end)\ntemplate\
    \ <typename T>\nstd::pair<int, T> GaussElimination(vector<vector<T>> &a, int pivot_end\
    \ = -1,\n                                   bool diagonalize = false) {\n  if\
    \ (a.empty()) return {0, 1};\n  int H = a.size(), W = a[0].size(), rank = 0;\n\
    \  if (pivot_end == -1) pivot_end = W;\n  T det = 1;\n  for (int j = 0; j < pivot_end;\
    \ j++) {\n    int idx = -1;\n    for (int i = rank; i < H; i++) {\n      if (a[i][j]\
    \ != T(0)) {\n        idx = i;\n        break;\n      }\n    }\n    if (idx ==\
    \ -1) {\n      det = 0;\n      continue;\n    }\n    if (rank != idx) det = -det,\
    \ swap(a[rank], a[idx]);\n    det *= a[rank][j];\n    if (diagonalize && a[rank][j]\
    \ != T(1)) {\n      T coeff = T(1) / a[rank][j];\n      for (int k = j; k < W;\
    \ k++) a[rank][k] *= coeff;\n    }\n    int is = diagonalize ? 0 : rank + 1;\n\
    \    for (int i = is; i < H; i++) {\n      if (i == rank) continue;\n      if\
    \ (a[i][j] != T(0)) {\n        T coeff = a[i][j] / a[rank][j];\n        for (int\
    \ k = j; k < W; k++) a[i][k] -= a[rank][k] * coeff;\n      }\n    }\n    rank++;\n\
    \  }\n  return make_pair(rank, det);\n}\n#line 4 \"matrix/inverse-matrix.hpp\"\
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
  requiredBy:
  - fps/find-p-recursive.hpp
  - matrix/polynomial-matrix-prefix-prod.hpp
  - matrix/matrix.hpp
  - matrix/polynomial-matrix-determinant.hpp
  - matrix/matrix-tree.hpp
  timestamp: '2024-05-03 21:06:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-determinant-matrixlib.test.cpp
  - verify/verify-yosupo-math/yosupo-inverse-matrix.test.cpp
  - verify/verify-yosupo-math/yosupo-pow-of-matrix.test.cpp
  - verify/verify-unit-test/p-recursive.test.cpp
  - verify/verify-unit-test/inverse-matrix.test.cpp
  - verify/verify-unit-test/multipoint-binomial-sum.test.cpp
  - verify/verify-unit-test/debug.test.cpp
  - verify/verify-unit-test/polynomial-matrix-prod.test.cpp
  - verify/verify-unit-test/gauss-elimination.test.cpp
  - verify/verify-unit-test/bigint-gcd.test.cpp
  - verify/verify-yosupo-fps/yosupo-factorial-p-recursive.test.cpp
  - verify/verify-yuki/yuki-1303.test.cpp
  - verify/verify-yuki/yuki-1533.test.cpp
documentation_of: matrix/inverse-matrix.hpp
layout: document
redirect_from:
- /library/matrix/inverse-matrix.hpp
- /library/matrix/inverse-matrix.hpp.html
title: matrix/inverse-matrix.hpp
---