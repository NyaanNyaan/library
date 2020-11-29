---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "\u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA(std::array\u7248)"
    links: []
  bundledCode: "#line 2 \"matrix/matrix-fast.hpp\"\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n\ntemplate <typename T, int H, int W>\nstruct Matrix {\n  using\
    \ Array = array<array<T, W>, H>;\n  Array A;\n\n  Matrix() : A() {\n    for (int\
    \ i = 0; i < H; i++)\n      for (int j = 0; j < W; j++) a[i][j] = T();\n  }\n\n\
    \  int height() const { return H; }\n\n  int width() const { return W; }\n\n \
    \ inline const array<T, W> &operator[](int k) const { return A[k]; }\n\n  inline\
    \ array<T, W> &operator[](int k) { return A[k]; }\n\n  static Matrix I() {\n \
    \   assert(H == W);\n    Matrix mat;\n    for (int i = 0; i < H; i++) mat[i][i]\
    \ = 1;\n    return (mat);\n  }\n\n  Matrix &operator+=(const Matrix &B) {\n  \
    \  for (int i = 0; i < H; i++)\n      for (int j = 0; j < W; j++) A[i][j] += B[i][j];\n\
    \    return (*this);\n  }\n\n  Matrix &operator-=(const Matrix &B) {\n    for\
    \ (int i = 0; i < H; i++)\n      for (int j = 0; j < W; j++) A[i][j] -= B[i][j];\n\
    \    return (*this);\n  }\n\n  Matrix &operator*=(const Matrix &B) {\n    assert(W\
    \ == B.H);\n    Matrix C;\n    for (int i = 0; i < H; i++)\n      for (int k =\
    \ 0; k < W; k++)\n        for (int j = 0; j < B.W; j++) C[i][j] += A[i][k] * B[k][j];\n\
    \    A.swap(C.A);\n    return (*this);\n  }\n\n  Matrix &operator^=(long long\
    \ k) {\n    Matrix B = Matrix::I();\n    while (k > 0) {\n      if (k & 1) B *=\
    \ *this;\n      *this *= *this;\n      k >>= 1LL;\n    }\n    A.swap(B.A);\n \
    \   return (*this);\n  }\n\n  Matrix operator+(const Matrix &B) const { return\
    \ (Matrix(*this) += B); }\n\n  Matrix operator-(const Matrix &B) const { return\
    \ (Matrix(*this) -= B); }\n\n  Matrix operator*(const Matrix &B) const { return\
    \ (Matrix(*this) *= B); }\n\n  Matrix operator^(const long long k) const { return\
    \ (Matrix(*this) ^= k); }\n\n  friend ostream &operator<<(ostream &os, Matrix\
    \ &p) {\n    for (int i = 0; i < H; i++) {\n      os << \"[\";\n      for (int\
    \ j = 0; j < W; j++) {\n        os << p[i][j] << (j + 1 == W ? \"]\\n\" : \",\"\
    );\n      }\n    }\n    return (os);\n  }\n\n  T determinant() {\n    Matrix B(*this);\n\
    \    assert(H == W);\n    T ret = 1;\n    for (int i = 0; i < H; i++) {\n    \
    \  int idx = -1;\n      for (int j = i; j < W; j++) {\n        if (B[j][i] !=\
    \ 0) {\n          idx = j;\n          break;\n        }\n      }\n      if (idx\
    \ == -1) return 0;\n      if (i != idx) {\n        ret *= T(-1);\n        swap(B[i],\
    \ B[idx]);\n      }\n      ret *= B[i][i];\n      T inv = T(1) / B[i][i];\n  \
    \    for (int j = 0; j < W; j++) {\n        B[i][j] *= inv;\n      }\n      for\
    \ (int j = i + 1; j < H; j++) {\n        T a = B[j][i];\n        if (a == 0) continue;\n\
    \        for (int k = i; k < W; k++) {\n          B[j][k] -= B[i][k] * a;\n  \
    \      }\n      }\n    }\n    return (ret);\n  }\n};\n\n/**\n * @brief \u884C\u5217\
    \u30E9\u30A4\u30D6\u30E9\u30EA(std::array\u7248)\n */\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename T, int H, int W>\nstruct Matrix {\n  using Array = array<array<T,\
    \ W>, H>;\n  Array A;\n\n  Matrix() : A() {\n    for (int i = 0; i < H; i++)\n\
    \      for (int j = 0; j < W; j++) a[i][j] = T();\n  }\n\n  int height() const\
    \ { return H; }\n\n  int width() const { return W; }\n\n  inline const array<T,\
    \ W> &operator[](int k) const { return A[k]; }\n\n  inline array<T, W> &operator[](int\
    \ k) { return A[k]; }\n\n  static Matrix I() {\n    assert(H == W);\n    Matrix\
    \ mat;\n    for (int i = 0; i < H; i++) mat[i][i] = 1;\n    return (mat);\n  }\n\
    \n  Matrix &operator+=(const Matrix &B) {\n    for (int i = 0; i < H; i++)\n \
    \     for (int j = 0; j < W; j++) A[i][j] += B[i][j];\n    return (*this);\n \
    \ }\n\n  Matrix &operator-=(const Matrix &B) {\n    for (int i = 0; i < H; i++)\n\
    \      for (int j = 0; j < W; j++) A[i][j] -= B[i][j];\n    return (*this);\n\
    \  }\n\n  Matrix &operator*=(const Matrix &B) {\n    assert(W == B.H);\n    Matrix\
    \ C;\n    for (int i = 0; i < H; i++)\n      for (int k = 0; k < W; k++)\n   \
    \     for (int j = 0; j < B.W; j++) C[i][j] += A[i][k] * B[k][j];\n    A.swap(C.A);\n\
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
    \      for (int j = i; j < W; j++) {\n        if (B[j][i] != 0) {\n          idx\
    \ = j;\n          break;\n        }\n      }\n      if (idx == -1) return 0;\n\
    \      if (i != idx) {\n        ret *= T(-1);\n        swap(B[i], B[idx]);\n \
    \     }\n      ret *= B[i][i];\n      T inv = T(1) / B[i][i];\n      for (int\
    \ j = 0; j < W; j++) {\n        B[i][j] *= inv;\n      }\n      for (int j = i\
    \ + 1; j < H; j++) {\n        T a = B[j][i];\n        if (a == 0) continue;\n\
    \        for (int k = i; k < W; k++) {\n          B[j][k] -= B[i][k] * a;\n  \
    \      }\n      }\n    }\n    return (ret);\n  }\n};\n\n/**\n * @brief \u884C\u5217\
    \u30E9\u30A4\u30D6\u30E9\u30EA(std::array\u7248)\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: matrix/matrix-fast.hpp
  requiredBy: []
  timestamp: '2020-11-29 14:35:17+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: matrix/matrix-fast.hpp
layout: document
redirect_from:
- /library/matrix/matrix-fast.hpp
- /library/matrix/matrix-fast.hpp.html
title: "\u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA(std::array\u7248)"
---
