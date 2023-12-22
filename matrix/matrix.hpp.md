---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: matrix/gauss-elimination.hpp
    title: matrix/gauss-elimination.hpp
  - icon: ':heavy_check_mark:'
    path: matrix/inverse-matrix.hpp
    title: matrix/inverse-matrix.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: fps/find-p-recursive.hpp
    title: "P-recursive\u306E\u9AD8\u901F\u8A08\u7B97"
  - icon: ':heavy_check_mark:'
    path: matrix/matrix-tree.hpp
    title: "\u884C\u5217\u6728\u5B9A\u7406(\u30E9\u30D7\u30E9\u30B7\u30A2\u30F3\u884C\
      \u5217)"
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
    path: verify/verify-yuki/yuki-1303.test.cpp
    title: verify/verify-yuki/yuki-1303.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1533.test.cpp
    title: verify/verify-yuki/yuki-1533.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA"
    links: []
  bundledCode: "#line 2 \"matrix/matrix.hpp\"\n\n#line 2 \"matrix/inverse-matrix.hpp\"\
    \n\n#line 2 \"matrix/gauss-elimination.hpp\"\n\n#include <utility>\n#include <vector>\n\
    using namespace std;\n\n// {rank, det(\u975E\u6B63\u65B9\u884C\u5217\u306E\u5834\
    \u5408\u306F\u672A\u5B9A\u7FA9)} \u3092\u8FD4\u3059\n// \u578B\u304C double \u3084\
    \ Rational \u3067\u3082\u52D5\u304F\u306F\u305A\uFF1F(\u672A\u691C\u8A3C)\n//\n\
    // pivot \u5019\u88DC : [0, pivot_end)\ntemplate <typename T>\nstd::pair<int,\
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
    \    rank++;\n  }\n  return make_pair(rank, det);\n}\n#line 4 \"matrix/inverse-matrix.hpp\"\
    \n\ntemplate <typename mint>\nvector<vector<mint>> inverse_matrix(const vector<vector<mint>>&\
    \ a) {\n  int N = a.size();\n  assert(N > 0);\n  assert(N == (int)a[0].size());\n\
    \n  vector<vector<mint>> m(N, vector<mint>(2 * N));\n  for (int i = 0; i < N;\
    \ i++) {\n    copy(begin(a[i]), end(a[i]), begin(m[i]));\n    m[i][N + i] = 1;\n\
    \  }\n\n  auto [rank, det] = GaussElimination(m, N, true);\n  if (rank != N) return\
    \ {};\n\n  vector<vector<mint>> b(N);\n  for (int i = 0; i < N; i++) {\n    copy(begin(m[i])\
    \ + N, end(m[i]), back_inserter(b[i]));\n  }\n  return b;\n}\n#line 4 \"matrix/matrix.hpp\"\
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
    \ false;\n  }\n\n  Matrix inverse() const {\n    assert(H() == W());\n    Matrix\
    \ B(H());\n    B.A = inverse_matrix(A);\n    return B;\n  }\n\n  friend ostream\
    \ &operator<<(ostream &os, const Matrix &p) {\n    int n = p.H(), m = p.W();\n\
    \    for (int i = 0; i < n; i++) {\n      os << (i ? \"   \" : \"\") << \"[\"\
    ;\n      for (int j = 0; j < m; j++) {\n        os << p[i][j] << (j + 1 == m ?\
    \ \"]\\n\" : \",\");\n      }\n    }\n    return (os);\n  }\n\n  T determinant()\
    \ const {\n    Matrix B(*this);\n    assert(H() == W());\n    T ret = 1;\n   \
    \ for (int i = 0; i < H(); i++) {\n      int idx = -1;\n      for (int j = i;\
    \ j < W(); j++) {\n        if (B[j][i] != 0) {\n          idx = j;\n         \
    \ break;\n        }\n      }\n      if (idx == -1) return 0;\n      if (i != idx)\
    \ {\n        ret *= T(-1);\n        swap(B[i], B[idx]);\n      }\n      ret *=\
    \ B[i][i];\n      T inv = T(1) / B[i][i];\n      for (int j = 0; j < W(); j++)\
    \ {\n        B[i][j] *= inv;\n      }\n      for (int j = i + 1; j < H(); j++)\
    \ {\n        T a = B[j][i];\n        if (a == 0) continue;\n        for (int k\
    \ = i; k < W(); k++) {\n          B[j][k] -= B[i][k] * a;\n        }\n      }\n\
    \    }\n    return ret;\n  }\n};\n\n/**\n * @brief \u884C\u5217\u30E9\u30A4\u30D6\
    \u30E9\u30EA\n */\n"
  code: "#pragma once\n\n#include \"inverse-matrix.hpp\"\n\ntemplate <class T>\nstruct\
    \ Matrix {\n  vector<vector<T> > A;\n\n  Matrix() = default;\n  Matrix(int n,\
    \ int m) : A(n, vector<T>(m, T())) {}\n  Matrix(int n) : A(n, vector<T>(n, T())){};\n\
    \n  int H() const { return A.size(); }\n\n  int W() const { return A[0].size();\
    \ }\n\n  int size() const { return A.size(); }\n\n  inline const vector<T> &operator[](int\
    \ k) const { return A[k]; }\n\n  inline vector<T> &operator[](int k) { return\
    \ A[k]; }\n\n  static Matrix I(int n) {\n    Matrix mat(n);\n    for (int i =\
    \ 0; i < n; i++) mat[i][i] = 1;\n    return (mat);\n  }\n\n  Matrix &operator+=(const\
    \ Matrix &B) {\n    int n = H(), m = W();\n    assert(n == B.H() && m == B.W());\n\
    \    for (int i = 0; i < n; i++)\n      for (int j = 0; j < m; j++) (*this)[i][j]\
    \ += B[i][j];\n    return (*this);\n  }\n\n  Matrix &operator-=(const Matrix &B)\
    \ {\n    int n = H(), m = W();\n    assert(n == B.H() && m == B.W());\n    for\
    \ (int i = 0; i < n; i++)\n      for (int j = 0; j < m; j++) (*this)[i][j] -=\
    \ B[i][j];\n    return (*this);\n  }\n\n  Matrix &operator*=(const Matrix &B)\
    \ {\n    int n = H(), m = B.W(), p = W();\n    assert(p == B.H());\n    vector<vector<T>\
    \ > C(n, vector<T>(m, T{}));\n    for (int i = 0; i < n; i++)\n      for (int\
    \ k = 0; k < p; k++)\n        for (int j = 0; j < m; j++) C[i][j] += (*this)[i][k]\
    \ * B[k][j];\n    A.swap(C);\n    return (*this);\n  }\n\n  Matrix &operator^=(long\
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
    \ false;\n  }\n\n  Matrix inverse() const {\n    assert(H() == W());\n    Matrix\
    \ B(H());\n    B.A = inverse_matrix(A);\n    return B;\n  }\n\n  friend ostream\
    \ &operator<<(ostream &os, const Matrix &p) {\n    int n = p.H(), m = p.W();\n\
    \    for (int i = 0; i < n; i++) {\n      os << (i ? \"   \" : \"\") << \"[\"\
    ;\n      for (int j = 0; j < m; j++) {\n        os << p[i][j] << (j + 1 == m ?\
    \ \"]\\n\" : \",\");\n      }\n    }\n    return (os);\n  }\n\n  T determinant()\
    \ const {\n    Matrix B(*this);\n    assert(H() == W());\n    T ret = 1;\n   \
    \ for (int i = 0; i < H(); i++) {\n      int idx = -1;\n      for (int j = i;\
    \ j < W(); j++) {\n        if (B[j][i] != 0) {\n          idx = j;\n         \
    \ break;\n        }\n      }\n      if (idx == -1) return 0;\n      if (i != idx)\
    \ {\n        ret *= T(-1);\n        swap(B[i], B[idx]);\n      }\n      ret *=\
    \ B[i][i];\n      T inv = T(1) / B[i][i];\n      for (int j = 0; j < W(); j++)\
    \ {\n        B[i][j] *= inv;\n      }\n      for (int j = i + 1; j < H(); j++)\
    \ {\n        T a = B[j][i];\n        if (a == 0) continue;\n        for (int k\
    \ = i; k < W(); k++) {\n          B[j][k] -= B[i][k] * a;\n        }\n      }\n\
    \    }\n    return ret;\n  }\n};\n\n/**\n * @brief \u884C\u5217\u30E9\u30A4\u30D6\
    \u30E9\u30EA\n */\n"
  dependsOn:
  - matrix/inverse-matrix.hpp
  - matrix/gauss-elimination.hpp
  isVerificationFile: false
  path: matrix/matrix.hpp
  requiredBy:
  - matrix/matrix-tree.hpp
  - matrix/polynomial-matrix-prefix-prod.hpp
  - matrix/polynomial-matrix-determinant.hpp
  - fps/find-p-recursive.hpp
  timestamp: '2023-12-22 19:57:12+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-1303.test.cpp
  - verify/verify-yuki/yuki-1533.test.cpp
  - verify/verify-unit-test/polynomial-matrix-prod.test.cpp
  - verify/verify-unit-test/p-recursive.test.cpp
  - verify/verify-unit-test/debug.test.cpp
  - verify/verify-unit-test/bigint-gcd.test.cpp
  - verify/verify-unit-test/multipoint-binomial-sum.test.cpp
  - verify/verify-unit-test/gauss-elimination.test.cpp
  - verify/verify-yosupo-math/yosupo-determinant-matrixlib.test.cpp
  - verify/verify-yosupo-fps/yosupo-factorial-p-recursive.test.cpp
documentation_of: matrix/matrix.hpp
layout: document
redirect_from:
- /library/matrix/matrix.hpp
- /library/matrix/matrix.hpp.html
title: "\u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA"
---
