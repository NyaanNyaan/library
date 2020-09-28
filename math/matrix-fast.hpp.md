---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/matrix-fast.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate <class T, int H, int W>\nstruct Matrix {\n  using\
    \ Array = array<array<T, W>, H>;\n  Array A;\n\n  Matrix() : A({}) {}\n\n  int\
    \ height() const { return H; }\n\n  int width() const { return W; }\n\n  inline\
    \ const array<T, W> &operator[](int k) const { return A[k]; }\n\n  inline array<T,\
    \ W> &operator[](int k) { return A[k]; }\n\n  static Matrix I() {\n    assert(H\
    \ == W);\n    Matrix mat;\n    for (int i = 0; i < H; i++) mat[i][i] = 1;\n  \
    \  return (mat);\n  }\n\n  Matrix &operator+=(const Matrix &B) {\n    for (int\
    \ i = 0; i < H; i++)\n      for (int j = 0; j < W; j++) A[i][j] += B[i][j];\n\
    \    return (*this);\n  }\n\n  Matrix &operator-=(const Matrix &B) {\n    for\
    \ (int i = 0; i < H; i++)\n      for (int j = 0; j < W; j++) A[i][j] -= B[i][j];\n\
    \    return (*this);\n  }\n\n  Matrix &operator*=(const Matrix &B) {\n    assert(H\
    \ == W);\n    Matrix C;\n    for (int i = 0; i < H; i++)\n      for (int j = 0;\
    \ j < H; j++)\n        for (int k = 0; k < H; k++) C[i][j] = (C[i][j] + A[i][k]\
    \ * B[k][j]);\n    A.swap(C.A);\n    return (*this);\n  }\n\n  Matrix &operator^=(long\
    \ long k) {\n    Matrix B = Matrix::I();\n    while (k > 0) {\n      if (k & 1)\
    \ B *= *this;\n      *this *= *this;\n      k >>= 1LL;\n    }\n    A.swap(B.A);\n\
    \    return (*this);\n  }\n\n  Matrix operator+(const Matrix &B) const { return\
    \ (Matrix(*this) += B); }\n\n  Matrix operator-(const Matrix &B) const { return\
    \ (Matrix(*this) -= B); }\n\n  Matrix operator*(const Matrix &B) const { return\
    \ (Matrix(*this) *= B); }\n\n  Matrix operator^(const long long k) const { return\
    \ (Matrix(*this) ^= k); }\n\n  friend ostream &operator<<(ostream &os, Matrix\
    \ &p) {\n    for (int i = 0; i < H; i++) {\n      os << \"[\";\n      for (int\
    \ j = 0; j < W; j++) {\n        os << p[i][j] << (j + 1 == W ? \"]\\n\" : \",\"\
    );\n      }\n    }\n    return (os);\n  }\n\n  T determinant() {\n    Matrix B(*this);\n\
    \    assert(H == W);\n    T ret = 1;\n    for (int i = 0; i < H; i++) {\n    \
    \  int idx = -1;\n      for (int j = i; j < W; j++) {\n        if (B[j][i] !=\
    \ 0) idx = j;\n      }\n      if (idx == -1) return (0);\n      if (i != idx)\
    \ {\n        ret *= -1;\n        swap(B[i], B[idx]);\n      }\n      ret *= B[i][i];\n\
    \      T vv = B[i][i];\n      for (int j = 0; j < W; j++) {\n        B[i][j] /=\
    \ vv;\n      }\n      for (int j = i + 1; j < H; j++) {\n        T a = B[j][i];\n\
    \        for (int k = 0; k < W; k++) {\n          B[j][k] -= B[i][k] * a;\n  \
    \      }\n      }\n    }\n    return (ret);\n  }\n};\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <class T, int H, int W>\nstruct Matrix {\n  using Array = array<array<T, W>,\
    \ H>;\n  Array A;\n\n  Matrix() : A({}) {}\n\n  int height() const { return H;\
    \ }\n\n  int width() const { return W; }\n\n  inline const array<T, W> &operator[](int\
    \ k) const { return A[k]; }\n\n  inline array<T, W> &operator[](int k) { return\
    \ A[k]; }\n\n  static Matrix I() {\n    assert(H == W);\n    Matrix mat;\n   \
    \ for (int i = 0; i < H; i++) mat[i][i] = 1;\n    return (mat);\n  }\n\n  Matrix\
    \ &operator+=(const Matrix &B) {\n    for (int i = 0; i < H; i++)\n      for (int\
    \ j = 0; j < W; j++) A[i][j] += B[i][j];\n    return (*this);\n  }\n\n  Matrix\
    \ &operator-=(const Matrix &B) {\n    for (int i = 0; i < H; i++)\n      for (int\
    \ j = 0; j < W; j++) A[i][j] -= B[i][j];\n    return (*this);\n  }\n\n  Matrix\
    \ &operator*=(const Matrix &B) {\n    assert(H == W);\n    Matrix C;\n    for\
    \ (int i = 0; i < H; i++)\n      for (int j = 0; j < H; j++)\n        for (int\
    \ k = 0; k < H; k++) C[i][j] = (C[i][j] + A[i][k] * B[k][j]);\n    A.swap(C.A);\n\
    \    return (*this);\n  }\n\n  Matrix &operator^=(long long k) {\n    Matrix B\
    \ = Matrix::I();\n    while (k > 0) {\n      if (k & 1) B *= *this;\n      *this\
    \ *= *this;\n      k >>= 1LL;\n    }\n    A.swap(B.A);\n    return (*this);\n\
    \  }\n\n  Matrix operator+(const Matrix &B) const { return (Matrix(*this) += B);\
    \ }\n\n  Matrix operator-(const Matrix &B) const { return (Matrix(*this) -= B);\
    \ }\n\n  Matrix operator*(const Matrix &B) const { return (Matrix(*this) *= B);\
    \ }\n\n  Matrix operator^(const long long k) const { return (Matrix(*this) ^=\
    \ k); }\n\n  friend ostream &operator<<(ostream &os, Matrix &p) {\n    for (int\
    \ i = 0; i < H; i++) {\n      os << \"[\";\n      for (int j = 0; j < W; j++)\
    \ {\n        os << p[i][j] << (j + 1 == W ? \"]\\n\" : \",\");\n      }\n    }\n\
    \    return (os);\n  }\n\n  T determinant() {\n    Matrix B(*this);\n    assert(H\
    \ == W);\n    T ret = 1;\n    for (int i = 0; i < H; i++) {\n      int idx = -1;\n\
    \      for (int j = i; j < W; j++) {\n        if (B[j][i] != 0) idx = j;\n   \
    \   }\n      if (idx == -1) return (0);\n      if (i != idx) {\n        ret *=\
    \ -1;\n        swap(B[i], B[idx]);\n      }\n      ret *= B[i][i];\n      T vv\
    \ = B[i][i];\n      for (int j = 0; j < W; j++) {\n        B[i][j] /= vv;\n  \
    \    }\n      for (int j = i + 1; j < H; j++) {\n        T a = B[j][i];\n    \
    \    for (int k = 0; k < W; k++) {\n          B[j][k] -= B[i][k] * a;\n      \
    \  }\n      }\n    }\n    return (ret);\n  }\n};"
  dependsOn: []
  isVerificationFile: false
  path: math/matrix-fast.hpp
  requiredBy: []
  timestamp: '2020-07-28 11:29:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/matrix-fast.hpp
layout: document
redirect_from:
- /library/math/matrix-fast.hpp
- /library/math/matrix-fast.hpp.html
title: math/matrix-fast.hpp
---
