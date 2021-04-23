---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: matrix/matrix.hpp
    title: "\u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA"
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/find-p-recursive.hpp
    title: "P-recursive\u306E\u9AD8\u901F\u8A08\u7B97"
  - icon: ':heavy_check_mark:'
    path: matrix/linear-equation.hpp
    title: matrix/linear-equation.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/gauss-elimination.test.cpp
    title: verify/verify-unit-test/gauss-elimination.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/p-recursive.test.cpp
    title: verify/verify-unit-test/p-recursive.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-linear-equation-2.test.cpp
    title: verify/verify-yosupo-math/yosupo-linear-equation-2.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"matrix/gauss-elimination.hpp\"\n\n#line 2 \"matrix/matrix.hpp\"\
    \n\ntemplate <class T>\nstruct Matrix {\n  vector<vector<T> > A;\n\n  Matrix()\
    \ = default;\n  Matrix(int n, int m) : A(n, vector<T>(m, T())) {}\n  Matrix(int\
    \ n) : A(n, vector<T>(n, T())){};\n\n  int H() const { return A.size(); }\n\n\
    \  int W() const { return A[0].size(); }\n\n  int size() const { return A.size();\
    \ }\n\n  inline const vector<T> &operator[](int k) const { return A[k]; }\n\n\
    \  inline vector<T> &operator[](int k) { return A[k]; }\n\n  static Matrix I(int\
    \ n) {\n    Matrix mat(n);\n    for (int i = 0; i < n; i++) mat[i][i] = 1;\n \
    \   return (mat);\n  }\n\n  Matrix &operator+=(const Matrix &B) {\n    int n =\
    \ H(), m = W();\n    assert(n == B.H() && m == B.W());\n    for (int i = 0; i\
    \ < n; i++)\n      for (int j = 0; j < m; j++) (*this)[i][j] += B[i][j];\n   \
    \ return (*this);\n  }\n\n  Matrix &operator-=(const Matrix &B) {\n    int n =\
    \ H(), m = W();\n    assert(n == B.H() && m == B.W());\n    for (int i = 0; i\
    \ < n; i++)\n      for (int j = 0; j < m; j++) (*this)[i][j] -= B[i][j];\n   \
    \ return (*this);\n  }\n\n  Matrix &operator*=(const Matrix &B) {\n    int n =\
    \ H(), m = B.W(), p = W();\n    assert(p == B.H());\n    vector<vector<T> > C(n,\
    \ vector<T>(m, T{}));\n    for (int i = 0; i < n; i++)\n      for (int k = 0;\
    \ k < p; k++)\n        for (int j = 0; j < m; j++) C[i][j] += (*this)[i][k] *\
    \ B[k][j];\n    A.swap(C);\n    return (*this);\n  }\n\n  Matrix &operator^=(long\
    \ long k) {\n    Matrix B = Matrix::I(H());\n    while (k > 0) {\n      if (k\
    \ & 1) B *= *this;\n      *this *= *this;\n      k >>= 1LL;\n    }\n    A.swap(B.A);\n\
    \    return (*this);\n  }\n\n  Matrix operator+(const Matrix &B) const { return\
    \ (Matrix(*this) += B); }\n\n  Matrix operator-(const Matrix &B) const { return\
    \ (Matrix(*this) -= B); }\n\n  Matrix operator*(const Matrix &B) const { return\
    \ (Matrix(*this) *= B); }\n\n  Matrix operator^(const long long k) const { return\
    \ (Matrix(*this) ^= k); }\n\n  bool operator==(const Matrix &B) const {\n    assert(H()\
    \ == B.H() && W() == B.W());\n    for (int i = 0; i < H(); i++)\n      for (int\
    \ j = 0; j < W(); j++)\n        if (A[i][j] != B[i][j]) return false;\n    return\
    \ true;\n  }\n\n  bool operator!=(const Matrix &B) const {\n    assert(H() ==\
    \ B.H() && W() == B.W());\n    for (int i = 0; i < H(); i++)\n      for (int j\
    \ = 0; j < W(); j++)\n        if (A[i][j] != B[i][j]) return true;\n    return\
    \ false;\n  }\n\n  friend ostream &operator<<(ostream &os, const Matrix &p) {\n\
    \    int n = p.H(), m = p.W();\n    for (int i = 0; i < n; i++) {\n      os <<\
    \ (i ? \"   \" : \"\") << \"[\";\n      for (int j = 0; j < m; j++) {\n      \
    \  os << p[i][j] << (j + 1 == m ? \"]\\n\" : \",\");\n      }\n    }\n    return\
    \ (os);\n  }\n\n  T determinant() const {\n    Matrix B(*this);\n    assert(H()\
    \ == W());\n    T ret = 1;\n    for (int i = 0; i < H(); i++) {\n      int idx\
    \ = -1;\n      for (int j = i; j < W(); j++) {\n        if (B[j][i] != 0) {\n\
    \          idx = j;\n          break;\n        }\n      }\n      if (idx == -1)\
    \ return 0;\n      if (i != idx) {\n        ret *= T(-1);\n        swap(B[i],\
    \ B[idx]);\n      }\n      ret *= B[i][i];\n      T inv = T(1) / B[i][i];\n  \
    \    for (int j = 0; j < W(); j++) {\n        B[i][j] *= inv;\n      }\n     \
    \ for (int j = i + 1; j < H(); j++) {\n        T a = B[j][i];\n        if (a ==\
    \ 0) continue;\n        for (int k = i; k < W(); k++) {\n          B[j][k] -=\
    \ B[i][k] * a;\n        }\n      }\n    }\n    return ret;\n  }\n};\n\n/**\n *\
    \ @brief \u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA\n */\n#line 4 \"matrix/gauss-elimination.hpp\"\
    \n\ntemplate <typename mint>\nstd::pair<int, mint> GaussElimination(vector<vector<mint>>\
    \ &a,\n                                      bool LE = false) {\n  int H = a.size(),\
    \ W = a[0].size();\n  int rank = 0, je = LE ? W - 1 : W;\n  mint det = 1;\n  for\
    \ (int j = 0; j < je; j++) {\n    int idx = -1;\n    for (int i = rank; i < H;\
    \ i++) {\n      if (a[i][j] != mint(0)) {\n        idx = i;\n        break;\n\
    \      }\n    }\n    if (idx == -1) {\n      det = 0;\n      continue;\n    }\n\
    \    if (rank != idx) {\n      det = -det;\n      swap(a[rank], a[idx]);\n   \
    \ }\n    det *= a[rank][j];\n    if (LE && a[rank][j] != mint(1)) {\n      mint\
    \ coeff = a[rank][j].inverse();\n      for (int k = j; k < W; k++) a[rank][k]\
    \ *= coeff;\n    }\n    int is = LE ? 0 : rank + 1;\n    for (int i = is; i <\
    \ H; i++) {\n      if (i == rank) continue;\n      if (a[i][j] != mint(0)) {\n\
    \        mint coeff = a[i][j] / a[rank][j];\n        for (int k = j; k < W; k++)\
    \ a[i][k] -= a[rank][k] * coeff;\n      }\n    }\n    rank++;\n  }\n  return make_pair(rank,\
    \ det);\n}\n"
  code: "#pragma once\n\n#include \"matrix.hpp\"\n\ntemplate <typename mint>\nstd::pair<int,\
    \ mint> GaussElimination(vector<vector<mint>> &a,\n                          \
    \            bool LE = false) {\n  int H = a.size(), W = a[0].size();\n  int rank\
    \ = 0, je = LE ? W - 1 : W;\n  mint det = 1;\n  for (int j = 0; j < je; j++) {\n\
    \    int idx = -1;\n    for (int i = rank; i < H; i++) {\n      if (a[i][j] !=\
    \ mint(0)) {\n        idx = i;\n        break;\n      }\n    }\n    if (idx ==\
    \ -1) {\n      det = 0;\n      continue;\n    }\n    if (rank != idx) {\n    \
    \  det = -det;\n      swap(a[rank], a[idx]);\n    }\n    det *= a[rank][j];\n\
    \    if (LE && a[rank][j] != mint(1)) {\n      mint coeff = a[rank][j].inverse();\n\
    \      for (int k = j; k < W; k++) a[rank][k] *= coeff;\n    }\n    int is = LE\
    \ ? 0 : rank + 1;\n    for (int i = is; i < H; i++) {\n      if (i == rank) continue;\n\
    \      if (a[i][j] != mint(0)) {\n        mint coeff = a[i][j] / a[rank][j];\n\
    \        for (int k = j; k < W; k++) a[i][k] -= a[rank][k] * coeff;\n      }\n\
    \    }\n    rank++;\n  }\n  return make_pair(rank, det);\n}\n"
  dependsOn:
  - matrix/matrix.hpp
  isVerificationFile: false
  path: matrix/gauss-elimination.hpp
  requiredBy:
  - fps/find-p-recursive.hpp
  - matrix/linear-equation.hpp
  timestamp: '2021-03-26 14:37:22+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-linear-equation-2.test.cpp
  - verify/verify-unit-test/p-recursive.test.cpp
  - verify/verify-unit-test/gauss-elimination.test.cpp
documentation_of: matrix/gauss-elimination.hpp
layout: document
redirect_from:
- /library/matrix/gauss-elimination.hpp
- /library/matrix/gauss-elimination.hpp.html
title: matrix/gauss-elimination.hpp
---
