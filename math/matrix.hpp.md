---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <class T>\nstruct Matrix {\n  vector<vector<T> > A;\n\n  Matrix()\
    \ {}\n\n  Matrix(int n, int m) : A(n, vector<T>(m, 0)) {}\n\n  Matrix(int n) :\
    \ A(n, vector<T>(n, 0)){};\n\n  int height() const { return (A.size()); }\n\n\
    \  int width() const { return (A[0].size()); }\n\n  inline const vector<T> &operator[](int\
    \ k) const { return (A.at(k)); }\n\n  inline vector<T> &operator[](int k) { return\
    \ (A.at(k)); }\n\n  static Matrix I(int n) {\n    Matrix mat(n);\n    for (int\
    \ i = 0; i < n; i++) mat[i][i] = 1;\n    return (mat);\n  }\n\n  Matrix &operator+=(const\
    \ Matrix &B) {\n    int n = height(), m = width();\n    assert(n == B.height()\
    \ && m == B.width());\n    for (int i = 0; i < n; i++)\n      for (int j = 0;\
    \ j < m; j++) (*this)[i][j] += B[i][j];\n    return (*this);\n  }\n\n  Matrix\
    \ &operator-=(const Matrix &B) {\n    int n = height(), m = width();\n    assert(n\
    \ == B.height() && m == B.width());\n    for (int i = 0; i < n; i++)\n      for\
    \ (int j = 0; j < m; j++) (*this)[i][j] -= B[i][j];\n    return (*this);\n  }\n\
    \n  Matrix &operator*=(const Matrix &B) {\n    int n = height(), m = B.width(),\
    \ p = width();\n    assert(p == B.height());\n    vector<vector<T> > C(n, vector<T>(m,\
    \ 0));\n    for (int i = 0; i < n; i++)\n      for (int j = 0; j < m; j++)\n \
    \       for (int k = 0; k < p; k++)\n          C[i][j] = (C[i][j] + (*this)[i][k]\
    \ * B[k][j]);\n    A.swap(C);\n    return (*this);\n  }\n\n  Matrix &operator^=(long\
    \ long k) {\n    Matrix B = Matrix::I(height());\n    while (k > 0) {\n      if\
    \ (k & 1) B *= *this;\n      *this *= *this;\n      k >>= 1LL;\n    }\n    A.swap(B.A);\n\
    \    return (*this);\n  }\n\n  Matrix operator+(const Matrix &B) const { return\
    \ (Matrix(*this) += B); }\n\n  Matrix operator-(const Matrix &B) const { return\
    \ (Matrix(*this) -= B); }\n\n  Matrix operator*(const Matrix &B) const { return\
    \ (Matrix(*this) *= B); }\n\n  Matrix operator^(const long long k) const { return\
    \ (Matrix(*this) ^= k); }\n\n  friend ostream &operator<<(ostream &os, Matrix\
    \ &p) {\n    int n = p.height(), m = p.width();\n    for (int i = 0; i < n; i++)\
    \ {\n      os << \"[\";\n      for (int j = 0; j < m; j++) {\n        os << p[i][j]\
    \ << (j + 1 == m ? \"]\\n\" : \",\");\n      }\n    }\n    return (os);\n  }\n\
    \n  T determinant() {\n    Matrix B(*this);\n    assert(width() == height());\n\
    \    T ret = 1;\n    for (int i = 0; i < width(); i++) {\n      int idx = -1;\n\
    \      for (int j = i; j < width(); j++) {\n        if (B[j][i] != 0) idx = j;\n\
    \      }\n      if (idx == -1) return (0);\n      if (i != idx) {\n        ret\
    \ *= -1;\n        swap(B[i], B[idx]);\n      }\n      ret *= B[i][i];\n      T\
    \ vv = B[i][i];\n      for (int j = 0; j < width(); j++) {\n        B[i][j] /=\
    \ vv;\n      }\n      for (int j = i + 1; j < width(); j++) {\n        T a = B[j][i];\n\
    \        for (int k = 0; k < width(); k++) {\n          B[j][k] -= B[i][k] * a;\n\
    \        }\n      }\n    }\n    return (ret);\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class T>\nstruct Matrix {\n  vector<vector<T> > A;\n\n  Matrix() {}\n\n  Matrix(int\
    \ n, int m) : A(n, vector<T>(m, 0)) {}\n\n  Matrix(int n) : A(n, vector<T>(n,\
    \ 0)){};\n\n  int height() const { return (A.size()); }\n\n  int width() const\
    \ { return (A[0].size()); }\n\n  inline const vector<T> &operator[](int k) const\
    \ { return (A.at(k)); }\n\n  inline vector<T> &operator[](int k) { return (A.at(k));\
    \ }\n\n  static Matrix I(int n) {\n    Matrix mat(n);\n    for (int i = 0; i <\
    \ n; i++) mat[i][i] = 1;\n    return (mat);\n  }\n\n  Matrix &operator+=(const\
    \ Matrix &B) {\n    int n = height(), m = width();\n    assert(n == B.height()\
    \ && m == B.width());\n    for (int i = 0; i < n; i++)\n      for (int j = 0;\
    \ j < m; j++) (*this)[i][j] += B[i][j];\n    return (*this);\n  }\n\n  Matrix\
    \ &operator-=(const Matrix &B) {\n    int n = height(), m = width();\n    assert(n\
    \ == B.height() && m == B.width());\n    for (int i = 0; i < n; i++)\n      for\
    \ (int j = 0; j < m; j++) (*this)[i][j] -= B[i][j];\n    return (*this);\n  }\n\
    \n  Matrix &operator*=(const Matrix &B) {\n    int n = height(), m = B.width(),\
    \ p = width();\n    assert(p == B.height());\n    vector<vector<T> > C(n, vector<T>(m,\
    \ 0));\n    for (int i = 0; i < n; i++)\n      for (int j = 0; j < m; j++)\n \
    \       for (int k = 0; k < p; k++)\n          C[i][j] = (C[i][j] + (*this)[i][k]\
    \ * B[k][j]);\n    A.swap(C);\n    return (*this);\n  }\n\n  Matrix &operator^=(long\
    \ long k) {\n    Matrix B = Matrix::I(height());\n    while (k > 0) {\n      if\
    \ (k & 1) B *= *this;\n      *this *= *this;\n      k >>= 1LL;\n    }\n    A.swap(B.A);\n\
    \    return (*this);\n  }\n\n  Matrix operator+(const Matrix &B) const { return\
    \ (Matrix(*this) += B); }\n\n  Matrix operator-(const Matrix &B) const { return\
    \ (Matrix(*this) -= B); }\n\n  Matrix operator*(const Matrix &B) const { return\
    \ (Matrix(*this) *= B); }\n\n  Matrix operator^(const long long k) const { return\
    \ (Matrix(*this) ^= k); }\n\n  friend ostream &operator<<(ostream &os, Matrix\
    \ &p) {\n    int n = p.height(), m = p.width();\n    for (int i = 0; i < n; i++)\
    \ {\n      os << \"[\";\n      for (int j = 0; j < m; j++) {\n        os << p[i][j]\
    \ << (j + 1 == m ? \"]\\n\" : \",\");\n      }\n    }\n    return (os);\n  }\n\
    \n  T determinant() {\n    Matrix B(*this);\n    assert(width() == height());\n\
    \    T ret = 1;\n    for (int i = 0; i < width(); i++) {\n      int idx = -1;\n\
    \      for (int j = i; j < width(); j++) {\n        if (B[j][i] != 0) idx = j;\n\
    \      }\n      if (idx == -1) return (0);\n      if (i != idx) {\n        ret\
    \ *= -1;\n        swap(B[i], B[idx]);\n      }\n      ret *= B[i][i];\n      T\
    \ vv = B[i][i];\n      for (int j = 0; j < width(); j++) {\n        B[i][j] /=\
    \ vv;\n      }\n      for (int j = i + 1; j < width(); j++) {\n        T a = B[j][i];\n\
    \        for (int k = 0; k < width(); k++) {\n          B[j][k] -= B[i][k] * a;\n\
    \        }\n      }\n    }\n    return (ret);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix.hpp
  requiredBy: []
  timestamp: '2020-07-28 11:29:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix.hpp
layout: document
redirect_from:
- /library/math/matrix.hpp
- /library/math/matrix.hpp.html
title: math/matrix.hpp
---
