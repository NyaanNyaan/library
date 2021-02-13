---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: matrix/matrix-tree.hpp
    title: "\u884C\u5217\u6728\u5B9A\u7406(\u30E9\u30D7\u30E9\u30B7\u30A2\u30F3\u884C\
      \u5217)"
  - icon: ':heavy_check_mark:'
    path: matrix/polynomial-matrix-determinant.hpp
    title: "\u591A\u9805\u5F0F\u884C\u5217\u306E\u884C\u5217\u5F0F"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/debug.test.cpp
    title: verify/verify-unit-test/debug.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-determinant-matrixlib.test.cpp
    title: verify/verify-yosupo-math/yosupo-determinant-matrixlib.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1303.test.cpp
    title: verify/verify-yuki/yuki-1303.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: "\u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA"
    links: []
  bundledCode: "#line 2 \"matrix/matrix.hpp\"\n\n\n\ntemplate <class T>\nstruct Matrix\
    \ {\n  vector<vector<T> > A;\n\n  Matrix() = default;\n  Matrix(int n, int m)\
    \ : A(n, vector<T>(m, T())) {}\n  Matrix(int n) : A(n, vector<T>(n, T())){};\n\
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
    \ > C(n, vector<T>(m, 0));\n    for (int i = 0; i < n; i++)\n      for (int k\
    \ = 0; k < p; k++)\n        for (int j = 0; j < m; j++) C[i][j] += (*this)[i][k]\
    \ * B[k][j];\n    A.swap(C);\n    return (*this);\n  }\n\n  Matrix &operator^=(long\
    \ long k) {\n    Matrix B = Matrix::I(H());\n    while (k > 0) {\n      if (k\
    \ & 1) B *= *this;\n      *this *= *this;\n      k >>= 1LL;\n    }\n    A.swap(B.A);\n\
    \    return (*this);\n  }\n\n  Matrix operator+(const Matrix &B) const { return\
    \ (Matrix(*this) += B); }\n\n  Matrix operator-(const Matrix &B) const { return\
    \ (Matrix(*this) -= B); }\n\n  Matrix operator*(const Matrix &B) const { return\
    \ (Matrix(*this) *= B); }\n\n  Matrix operator^(const long long k) const { return\
    \ (Matrix(*this) ^= k); }\n\n  friend ostream &operator<<(ostream &os, const Matrix\
    \ &p) {\n    int n = p.H(), m = p.W();\n    for (int i = 0; i < n; i++) {\n  \
    \     os << (i ? \"   \" : \"\") << \"[\";\n      for (int j = 0; j < m; j++)\
    \ {\n        os << p[i][j] << (j + 1 == m ? \"]\\n\" : \",\");\n      }\n    }\n\
    \    return (os);\n  }\n\n  T determinant() const {\n    Matrix B(*this);\n  \
    \  assert(H() == W());\n    T ret = 1;\n    for (int i = 0; i < H(); i++) {\n\
    \      int idx = -1;\n      for (int j = i; j < W(); j++) {\n        if (B[j][i]\
    \ != 0) {\n          idx = j;\n          break;\n        }\n      }\n      if\
    \ (idx == -1) return 0;\n      if (i != idx) {\n        ret *= T(-1);\n      \
    \  swap(B[i], B[idx]);\n      }\n      ret *= B[i][i];\n      T inv = T(1) / B[i][i];\n\
    \      for (int j = 0; j < W(); j++) {\n        B[i][j] *= inv;\n      }\n   \
    \   for (int j = i + 1; j < H(); j++) {\n        T a = B[j][i];\n        if (a\
    \ == 0) continue;\n        for (int k = i; k < W(); k++) {\n          B[j][k]\
    \ -= B[i][k] * a;\n        }\n      }\n    }\n    return ret;\n  }\n};\n\n/**\n\
    \ * @brief \u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA\n */\n"
  code: "#pragma once\n\n\n\ntemplate <class T>\nstruct Matrix {\n  vector<vector<T>\
    \ > A;\n\n  Matrix() = default;\n  Matrix(int n, int m) : A(n, vector<T>(m, T()))\
    \ {}\n  Matrix(int n) : A(n, vector<T>(n, T())){};\n\n  int H() const { return\
    \ A.size(); }\n\n  int W() const { return A[0].size(); }\n\n  int size() const\
    \ { return A.size(); }\n\n  inline const vector<T> &operator[](int k) const {\
    \ return A[k]; }\n\n  inline vector<T> &operator[](int k) { return A[k]; }\n\n\
    \  static Matrix I(int n) {\n    Matrix mat(n);\n    for (int i = 0; i < n; i++)\
    \ mat[i][i] = 1;\n    return (mat);\n  }\n\n  Matrix &operator+=(const Matrix\
    \ &B) {\n    int n = H(), m = W();\n    assert(n == B.H() && m == B.W());\n  \
    \  for (int i = 0; i < n; i++)\n      for (int j = 0; j < m; j++) (*this)[i][j]\
    \ += B[i][j];\n    return (*this);\n  }\n\n  Matrix &operator-=(const Matrix &B)\
    \ {\n    int n = H(), m = W();\n    assert(n == B.H() && m == B.W());\n    for\
    \ (int i = 0; i < n; i++)\n      for (int j = 0; j < m; j++) (*this)[i][j] -=\
    \ B[i][j];\n    return (*this);\n  }\n\n  Matrix &operator*=(const Matrix &B)\
    \ {\n    int n = H(), m = B.W(), p = W();\n    assert(p == B.H());\n    vector<vector<T>\
    \ > C(n, vector<T>(m, 0));\n    for (int i = 0; i < n; i++)\n      for (int k\
    \ = 0; k < p; k++)\n        for (int j = 0; j < m; j++) C[i][j] += (*this)[i][k]\
    \ * B[k][j];\n    A.swap(C);\n    return (*this);\n  }\n\n  Matrix &operator^=(long\
    \ long k) {\n    Matrix B = Matrix::I(H());\n    while (k > 0) {\n      if (k\
    \ & 1) B *= *this;\n      *this *= *this;\n      k >>= 1LL;\n    }\n    A.swap(B.A);\n\
    \    return (*this);\n  }\n\n  Matrix operator+(const Matrix &B) const { return\
    \ (Matrix(*this) += B); }\n\n  Matrix operator-(const Matrix &B) const { return\
    \ (Matrix(*this) -= B); }\n\n  Matrix operator*(const Matrix &B) const { return\
    \ (Matrix(*this) *= B); }\n\n  Matrix operator^(const long long k) const { return\
    \ (Matrix(*this) ^= k); }\n\n  friend ostream &operator<<(ostream &os, const Matrix\
    \ &p) {\n    int n = p.H(), m = p.W();\n    for (int i = 0; i < n; i++) {\n  \
    \     os << (i ? \"   \" : \"\") << \"[\";\n      for (int j = 0; j < m; j++)\
    \ {\n        os << p[i][j] << (j + 1 == m ? \"]\\n\" : \",\");\n      }\n    }\n\
    \    return (os);\n  }\n\n  T determinant() const {\n    Matrix B(*this);\n  \
    \  assert(H() == W());\n    T ret = 1;\n    for (int i = 0; i < H(); i++) {\n\
    \      int idx = -1;\n      for (int j = i; j < W(); j++) {\n        if (B[j][i]\
    \ != 0) {\n          idx = j;\n          break;\n        }\n      }\n      if\
    \ (idx == -1) return 0;\n      if (i != idx) {\n        ret *= T(-1);\n      \
    \  swap(B[i], B[idx]);\n      }\n      ret *= B[i][i];\n      T inv = T(1) / B[i][i];\n\
    \      for (int j = 0; j < W(); j++) {\n        B[i][j] *= inv;\n      }\n   \
    \   for (int j = i + 1; j < H(); j++) {\n        T a = B[j][i];\n        if (a\
    \ == 0) continue;\n        for (int k = i; k < W(); k++) {\n          B[j][k]\
    \ -= B[i][k] * a;\n        }\n      }\n    }\n    return ret;\n  }\n};\n\n/**\n\
    \ * @brief \u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: matrix/matrix.hpp
  requiredBy:
  - matrix/polynomial-matrix-determinant.hpp
  - matrix/matrix-tree.hpp
  timestamp: '2020-12-05 07:59:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/debug.test.cpp
  - verify/verify-yuki/yuki-1303.test.cpp
  - verify/verify-yosupo-math/yosupo-determinant-matrixlib.test.cpp
documentation_of: matrix/matrix.hpp
layout: document
redirect_from:
- /library/matrix/matrix.hpp
- /library/matrix/matrix.hpp.html
title: "\u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA"
---
