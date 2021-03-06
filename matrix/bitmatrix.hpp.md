---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: verify/verify-yuki/yuki-1340-bitmatrix.test.cpp
    title: verify/verify-yuki/yuki-1340-bitmatrix.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 2 \"matrix/bitmatrix.hpp\"\n\ntemplate <size_t MAX_H, size_t\
    \ MAX_W>\nstruct BitMatrix {\n  int H, W;\n  bitset<MAX_W> A[MAX_H];\n  BitMatrix()\
    \ : H(MAX_H), W(MAX_W) {}\n  BitMatrix(int h, int w) : H(h), W(w) {}\n  inline\
    \ bitset<MAX_W> &operator[](int i) { return A[i]; }\n  inline const bitset<MAX_W>\
    \ &operator[](int i) const { return A[i]; }\n  int height() { return H; }\n  int\
    \ size() { return H; }\n  int width() { return W; }\n\n  static BitMatrix I(int\
    \ n) {\n    BitMatrix mat(n, n);\n    for (int i = 0; i < n; i++) mat[i][i] =\
    \ true;\n    return (mat);\n  }\n\n  BitMatrix &operator*=(const BitMatrix &B)\
    \ {\n    BitMatrix C(H, B.W);\n    for (int i = 0; i < H; i++) {\n      for (int\
    \ j = 0; j < W; j++) {\n        if (A[i][j]) C[i] |= B[j];\n      }\n    }\n \
    \   swap(A, C.A);\n    return *this;\n  }\n  BitMatrix &operator^=(long long k)\
    \ {\n    BitMatrix B = BitMatrix::I(height());\n    while (k) {\n      if (k &\
    \ 1) B *= *this;\n      *this *= *this;\n      k >>= 1;\n    }\n    swap(A, B.A);\n\
    \    return (*this);\n  }\n\n  BitMatrix operator*(BitMatrix &B) const { return\
    \ BitMatrix(*this) *= B; }\n  BitMatrix operator^(const long long k) const { return\
    \ BitMatrix(*this) ^= k; }\n};\n"
  code: "#pragma once\n\ntemplate <size_t MAX_H, size_t MAX_W>\nstruct BitMatrix {\n\
    \  int H, W;\n  bitset<MAX_W> A[MAX_H];\n  BitMatrix() : H(MAX_H), W(MAX_W) {}\n\
    \  BitMatrix(int h, int w) : H(h), W(w) {}\n  inline bitset<MAX_W> &operator[](int\
    \ i) { return A[i]; }\n  inline const bitset<MAX_W> &operator[](int i) const {\
    \ return A[i]; }\n  int height() { return H; }\n  int size() { return H; }\n \
    \ int width() { return W; }\n\n  static BitMatrix I(int n) {\n    BitMatrix mat(n,\
    \ n);\n    for (int i = 0; i < n; i++) mat[i][i] = true;\n    return (mat);\n\
    \  }\n\n  BitMatrix &operator*=(const BitMatrix &B) {\n    BitMatrix C(H, B.W);\n\
    \    for (int i = 0; i < H; i++) {\n      for (int j = 0; j < W; j++) {\n    \
    \    if (A[i][j]) C[i] |= B[j];\n      }\n    }\n    swap(A, C.A);\n    return\
    \ *this;\n  }\n  BitMatrix &operator^=(long long k) {\n    BitMatrix B = BitMatrix::I(height());\n\
    \    while (k) {\n      if (k & 1) B *= *this;\n      *this *= *this;\n      k\
    \ >>= 1;\n    }\n    swap(A, B.A);\n    return (*this);\n  }\n\n  BitMatrix operator*(BitMatrix\
    \ &B) const { return BitMatrix(*this) *= B; }\n  BitMatrix operator^(const long\
    \ long k) const { return BitMatrix(*this) ^= k; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: matrix/bitmatrix.hpp
  requiredBy: []
  timestamp: '2021-02-01 14:29:22+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - verify/verify-yuki/yuki-1340-bitmatrix.test.cpp
documentation_of: matrix/bitmatrix.hpp
layout: document
redirect_from:
- /library/matrix/bitmatrix.hpp
- /library/matrix/bitmatrix.hpp.html
title: matrix/bitmatrix.hpp
---
