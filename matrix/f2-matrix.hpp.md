---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-determinant-of-matrix-mod-2.test.cpp
    title: verify/verify-yosupo-math/yosupo-determinant-of-matrix-mod-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-inverse-matrix-mod-2.test.cpp
    title: verify/verify-yosupo-math/yosupo-inverse-matrix-mod-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-matrix-product-mod-2.test.cpp
    title: verify/verify-yosupo-math/yosupo-matrix-product-mod-2.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1340-bitmatrix.test.cpp
    title: verify/verify-yuki/yuki-1340-bitmatrix.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"matrix/f2-matrix.hpp\"\n\n#include <array>\n#include <bitset>\n\
    using namespace std;\n\nnamespace std {\ntemplate <size_t N>\nbool operator<(const\
    \ bitset<N> &a, const bitset<N> &b) {\n  int f = (a ^ b)._Find_first();\n  return\
    \ f == N ? false : a[f];\n}\n}  // namespace std\n\ntemplate <size_t H_MAX, size_t\
    \ W_MAX>\nstruct F2_Matrix {\n  using Mat = F2_Matrix;\n\n  int H, W;\n  array<bitset<W_MAX>,\
    \ H_MAX> A;\n  F2_Matrix(int h = H_MAX, int w = W_MAX) : H(h), W(w) {\n    assert(0\
    \ <= h and h <= (int)H_MAX);\n    assert(0 <= w and w <= (int)W_MAX);\n    for\
    \ (int i = 0; i < (int)H_MAX; i++) A[i].reset();\n  }\n  inline bitset<W_MAX>\
    \ &operator[](int i) { return A[i]; }\n  inline const bitset<W_MAX> &operator[](int\
    \ i) const { return A[i]; }\n\n  static Mat I(int n) {\n    Mat a(n, n);\n   \
    \ for (int i = 0; i < n; i++) a[i][i] = true;\n    return a;\n  }\n\n  // (AND,\
    \ XOR) \u534A\u74B0\n  // (AND, OR) \u534A\u74B0\u306B\u306F operator/ \u3092\u5272\
    \u308A\u5F53\u3066\u305F\n  Mat &operator*=(const Mat &B) {\n    Mat C(H, B.W);\n\
    \    for (int i = 0; i < H; i++) {\n      for (int j = 0; j < W; j++) {\n    \
    \    if (A[i][j]) C[i] ^= B[j];\n      }\n    }\n    swap(A, C.A);\n    return\
    \ *this;\n  }\n  Mat operator*(const Mat &B) const { return Mat(*this) *= B; }\n\
    \n  // (AND, OR) \u534A\u74B0\n  friend Mat and_or_product(const Mat &A, const\
    \ Mat &B) {\n    Mat C(A.H, B.W);\n    for (int i = 0; i < A.H; i++) {\n     \
    \ for (int j = 0; j < A.W; j++) {\n        if (A[i][j]) C[i] |= B[j];\n      }\n\
    \    }\n    return C;\n  }\n\n  // [0, wr) \u306E\u7BC4\u56F2\u3067\u6383\u304D\
    \u51FA\u3057, rank \u3092\u8FD4\u3059\n  int sweep(int wr = -1) {\n    if (wr\
    \ == -1) wr = W;\n    int t = 0;\n    for (int u = 0; u < wr; u++) {\n      int\
    \ piv = -1;\n      for (int i = t; i < H; i++) {\n        if (A[i][u]) {\n   \
    \       piv = i;\n          break;\n        }\n      }\n      if (piv == -1) continue;\n\
    \      if (piv != t) swap(A[piv], A[t]);\n      for (int i = 0; i < H; i++) {\n\
    \        if (i != t && A[i][u]) A[i] ^= A[t];\n      }\n      t++;\n    }\n  \
    \  return t;\n  }\n\n  pair<bool, Mat> inverse() const {\n    assert(H == W);\n\
    \    int N = H;\n    F2_Matrix<H_MAX, W_MAX * 2> c(H, W * 2);\n    for (int i\
    \ = 0; i < N; i++) {\n      c[i][i + N] = 1;\n      for (int j = 0; j < N; j++)\
    \ {\n        c[i][j] = A[i][j];\n      }\n    }\n    int r = c.sweep(N);\n   \
    \ if (r != N) return {false, Mat{N, N}};\n    Mat b(H, W);\n    for (int i = 0;\
    \ i < N; i++) {\n      for (int j = 0; j < N; j++) {\n        b[i][j] = c[i][j\
    \ + N];\n      }\n    }\n    return {true, b};\n  }\n\n  int determinant() const\
    \ {\n    assert(H == W);\n    F2_Matrix<H_MAX, W_MAX> c{*this};\n    int r = c.sweep();\n\
    \    return r == H ? 1 : 0;\n  }\n\n  bool operator<(const Mat &rhs) const {\n\
    \    if (H != rhs.H) return H < rhs.H;\n    if (W != rhs.W) return W < rhs.W;\n\
    \    return A < rhs.A;\n  }\n  bool operator==(const Mat &rhs) const {\n    return\
    \ H == rhs.H and W == rhs.W and A == rhs.A;\n  }\n\n  friend ostream &operator<<(ostream\
    \ &os, const Mat &b) {\n    for (int i = 0; i < b.H; i++) {\n      os << \"[ \"\
    ;\n      for (int j = 0; j < b.W; j++) {\n        os << b[i][j] << \", \";\n \
    \     }\n      os << \"],\\n\";\n    }\n    return os;\n  }\n};\n"
  code: "#pragma once\n\n#include <array>\n#include <bitset>\nusing namespace std;\n\
    \nnamespace std {\ntemplate <size_t N>\nbool operator<(const bitset<N> &a, const\
    \ bitset<N> &b) {\n  int f = (a ^ b)._Find_first();\n  return f == N ? false :\
    \ a[f];\n}\n}  // namespace std\n\ntemplate <size_t H_MAX, size_t W_MAX>\nstruct\
    \ F2_Matrix {\n  using Mat = F2_Matrix;\n\n  int H, W;\n  array<bitset<W_MAX>,\
    \ H_MAX> A;\n  F2_Matrix(int h = H_MAX, int w = W_MAX) : H(h), W(w) {\n    assert(0\
    \ <= h and h <= (int)H_MAX);\n    assert(0 <= w and w <= (int)W_MAX);\n    for\
    \ (int i = 0; i < (int)H_MAX; i++) A[i].reset();\n  }\n  inline bitset<W_MAX>\
    \ &operator[](int i) { return A[i]; }\n  inline const bitset<W_MAX> &operator[](int\
    \ i) const { return A[i]; }\n\n  static Mat I(int n) {\n    Mat a(n, n);\n   \
    \ for (int i = 0; i < n; i++) a[i][i] = true;\n    return a;\n  }\n\n  // (AND,\
    \ XOR) \u534A\u74B0\n  // (AND, OR) \u534A\u74B0\u306B\u306F operator/ \u3092\u5272\
    \u308A\u5F53\u3066\u305F\n  Mat &operator*=(const Mat &B) {\n    Mat C(H, B.W);\n\
    \    for (int i = 0; i < H; i++) {\n      for (int j = 0; j < W; j++) {\n    \
    \    if (A[i][j]) C[i] ^= B[j];\n      }\n    }\n    swap(A, C.A);\n    return\
    \ *this;\n  }\n  Mat operator*(const Mat &B) const { return Mat(*this) *= B; }\n\
    \n  // (AND, OR) \u534A\u74B0\n  friend Mat and_or_product(const Mat &A, const\
    \ Mat &B) {\n    Mat C(A.H, B.W);\n    for (int i = 0; i < A.H; i++) {\n     \
    \ for (int j = 0; j < A.W; j++) {\n        if (A[i][j]) C[i] |= B[j];\n      }\n\
    \    }\n    return C;\n  }\n\n  // [0, wr) \u306E\u7BC4\u56F2\u3067\u6383\u304D\
    \u51FA\u3057, rank \u3092\u8FD4\u3059\n  int sweep(int wr = -1) {\n    if (wr\
    \ == -1) wr = W;\n    int t = 0;\n    for (int u = 0; u < wr; u++) {\n      int\
    \ piv = -1;\n      for (int i = t; i < H; i++) {\n        if (A[i][u]) {\n   \
    \       piv = i;\n          break;\n        }\n      }\n      if (piv == -1) continue;\n\
    \      if (piv != t) swap(A[piv], A[t]);\n      for (int i = 0; i < H; i++) {\n\
    \        if (i != t && A[i][u]) A[i] ^= A[t];\n      }\n      t++;\n    }\n  \
    \  return t;\n  }\n\n  pair<bool, Mat> inverse() const {\n    assert(H == W);\n\
    \    int N = H;\n    F2_Matrix<H_MAX, W_MAX * 2> c(H, W * 2);\n    for (int i\
    \ = 0; i < N; i++) {\n      c[i][i + N] = 1;\n      for (int j = 0; j < N; j++)\
    \ {\n        c[i][j] = A[i][j];\n      }\n    }\n    int r = c.sweep(N);\n   \
    \ if (r != N) return {false, Mat{N, N}};\n    Mat b(H, W);\n    for (int i = 0;\
    \ i < N; i++) {\n      for (int j = 0; j < N; j++) {\n        b[i][j] = c[i][j\
    \ + N];\n      }\n    }\n    return {true, b};\n  }\n\n  int determinant() const\
    \ {\n    assert(H == W);\n    F2_Matrix<H_MAX, W_MAX> c{*this};\n    int r = c.sweep();\n\
    \    return r == H ? 1 : 0;\n  }\n\n  bool operator<(const Mat &rhs) const {\n\
    \    if (H != rhs.H) return H < rhs.H;\n    if (W != rhs.W) return W < rhs.W;\n\
    \    return A < rhs.A;\n  }\n  bool operator==(const Mat &rhs) const {\n    return\
    \ H == rhs.H and W == rhs.W and A == rhs.A;\n  }\n\n  friend ostream &operator<<(ostream\
    \ &os, const Mat &b) {\n    for (int i = 0; i < b.H; i++) {\n      os << \"[ \"\
    ;\n      for (int j = 0; j < b.W; j++) {\n        os << b[i][j] << \", \";\n \
    \     }\n      os << \"],\\n\";\n    }\n    return os;\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: matrix/f2-matrix.hpp
  requiredBy: []
  timestamp: '2024-08-10 13:03:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-1340-bitmatrix.test.cpp
  - verify/verify-yosupo-math/yosupo-matrix-product-mod-2.test.cpp
  - verify/verify-yosupo-math/yosupo-determinant-of-matrix-mod-2.test.cpp
  - verify/verify-yosupo-math/yosupo-inverse-matrix-mod-2.test.cpp
documentation_of: matrix/f2-matrix.hpp
layout: document
redirect_from:
- /library/matrix/f2-matrix.hpp
- /library/matrix/f2-matrix.hpp.html
title: matrix/f2-matrix.hpp
---
