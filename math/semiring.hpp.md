---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/semiring.test.cpp
    title: verify/verify-unit-test/semiring.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yuki/yuki-1340-semiring.test.cpp
    title: verify/verify-yuki/yuki-1340-semiring.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/math/semiring.md
    document_title: "\u534A\u74B0\u30E9\u30A4\u30D6\u30E9\u30EA"
    links: []
  bundledCode: "#line 2 \"math/semiring.hpp\"\n\ntemplate <typename T, T (*add)(T,\
    \ T), T (*mul)(T, T), T (*I0)(), T (*I1)()>\nstruct semiring {\n  T x;\n  semiring()\
    \ : x(I0()) {}\n  semiring(T y) : x(y) {}\n  static T id0() { return I0(); }\n\
    \  static T id1() { return I1(); }\n\n  semiring &operator+=(const semiring &p)\
    \ {\n    if (x == I0()) return *this = p;\n    if (p.x == I0()) return *this;\n\
    \    return *this = add(x, p.x);\n  }\n\n  semiring &operator*=(const semiring\
    \ &p) {\n    if (x == I0() || p.x == I0()) return *this = I0();\n    if (x ==\
    \ I1()) return *this = p;\n    if (p.x == I1()) return *this;\n    return *this\
    \ = mul(x, p.x);\n  }\n\n  semiring operator+(const semiring &p) const { return\
    \ semiring(*this) += p; }\n  semiring operator*(const semiring &p) const { return\
    \ semiring(*this) *= p; }\n  bool operator==(const semiring &p) const { return\
    \ x == p.x; }\n  bool operator!=(const semiring &p) const { return x != p.x; }\n\
    \  friend ostream &operator<<(ostream &os, const semiring &p) {\n    return os\
    \ << p.x;\n  }\n};\n\ntemplate <typename rig, int N>\nstruct Mat {\n  using Array\
    \ = array<array<rig, N>, N>;\n  Array A;\n\n  Mat() {\n    for (int i = 0; i <\
    \ N; i++) A[i].fill(rig::id0());\n  }\n  int height() const { return N; }\n  int\
    \ width() const { return N; }\n  inline const array<rig, N> &operator[](int k)\
    \ const { return A[k]; }\n  inline array<rig, N> &operator[](int k) { return A[k];\
    \ }\n\n  static Mat I() {\n    Mat m;\n    for (int i = 0; i < N; i++) m[i][i]\
    \ = rig::id1();\n    return m;\n  }\n\n  Mat &operator+=(const Mat &B) {\n   \
    \ for (int i = 0; i < N; i++)\n      for (int j = 0; j < N; j++) A[i][j] += B[i][j];\n\
    \    return (*this);\n  }\n\n  Mat &operator*=(const Mat &B) {\n    Mat C;\n \
    \   for (int i = 0; i < N; i++)\n      for (int k = 0; k < N; k++)\n        for\
    \ (int j = 0; j < N; j++) C[i][j] += A[i][k] * B[k][j];\n    A.swap(C.A);\n  \
    \  return (*this);\n  }\n\n  Mat &operator^=(long long k) {\n    Mat B = Mat::I();\n\
    \    for (; k; *this *= *this, k >>= 1)\n      if (k & 1) B *= *this;\n    A.swap(B.A);\n\
    \    return (*this);\n  }\n\n  Mat operator+(const Mat &B) const { return (Mat(*this)\
    \ += B); }\n  Mat operator*(const Mat &B) const { return (Mat(*this) *= B); }\n\
    \  Mat operator^(long long k) const { return (Mat(*this) ^= k); }\n\n  friend\
    \ ostream &operator<<(ostream &os, Mat &p) {\n    for (int i = 0; i < N; i++)\
    \ {\n      os << \"[\";\n      for (int j = 0; j < N; j++) {\n        os << p[i][j].x\
    \ << (j == N - 1 ? \"]\\n\" : \",\");\n      }\n    }\n    return (os);\n  }\n\
    };\n\n/**\n * @brief \u534A\u74B0\u30E9\u30A4\u30D6\u30E9\u30EA\n * @docs docs/math/semiring.md\n\
    \ */\n"
  code: "#pragma once\n\ntemplate <typename T, T (*add)(T, T), T (*mul)(T, T), T (*I0)(),\
    \ T (*I1)()>\nstruct semiring {\n  T x;\n  semiring() : x(I0()) {}\n  semiring(T\
    \ y) : x(y) {}\n  static T id0() { return I0(); }\n  static T id1() { return I1();\
    \ }\n\n  semiring &operator+=(const semiring &p) {\n    if (x == I0()) return\
    \ *this = p;\n    if (p.x == I0()) return *this;\n    return *this = add(x, p.x);\n\
    \  }\n\n  semiring &operator*=(const semiring &p) {\n    if (x == I0() || p.x\
    \ == I0()) return *this = I0();\n    if (x == I1()) return *this = p;\n    if\
    \ (p.x == I1()) return *this;\n    return *this = mul(x, p.x);\n  }\n\n  semiring\
    \ operator+(const semiring &p) const { return semiring(*this) += p; }\n  semiring\
    \ operator*(const semiring &p) const { return semiring(*this) *= p; }\n  bool\
    \ operator==(const semiring &p) const { return x == p.x; }\n  bool operator!=(const\
    \ semiring &p) const { return x != p.x; }\n  friend ostream &operator<<(ostream\
    \ &os, const semiring &p) {\n    return os << p.x;\n  }\n};\n\ntemplate <typename\
    \ rig, int N>\nstruct Mat {\n  using Array = array<array<rig, N>, N>;\n  Array\
    \ A;\n\n  Mat() {\n    for (int i = 0; i < N; i++) A[i].fill(rig::id0());\n  }\n\
    \  int height() const { return N; }\n  int width() const { return N; }\n  inline\
    \ const array<rig, N> &operator[](int k) const { return A[k]; }\n  inline array<rig,\
    \ N> &operator[](int k) { return A[k]; }\n\n  static Mat I() {\n    Mat m;\n \
    \   for (int i = 0; i < N; i++) m[i][i] = rig::id1();\n    return m;\n  }\n\n\
    \  Mat &operator+=(const Mat &B) {\n    for (int i = 0; i < N; i++)\n      for\
    \ (int j = 0; j < N; j++) A[i][j] += B[i][j];\n    return (*this);\n  }\n\n  Mat\
    \ &operator*=(const Mat &B) {\n    Mat C;\n    for (int i = 0; i < N; i++)\n \
    \     for (int k = 0; k < N; k++)\n        for (int j = 0; j < N; j++) C[i][j]\
    \ += A[i][k] * B[k][j];\n    A.swap(C.A);\n    return (*this);\n  }\n\n  Mat &operator^=(long\
    \ long k) {\n    Mat B = Mat::I();\n    for (; k; *this *= *this, k >>= 1)\n \
    \     if (k & 1) B *= *this;\n    A.swap(B.A);\n    return (*this);\n  }\n\n \
    \ Mat operator+(const Mat &B) const { return (Mat(*this) += B); }\n  Mat operator*(const\
    \ Mat &B) const { return (Mat(*this) *= B); }\n  Mat operator^(long long k) const\
    \ { return (Mat(*this) ^= k); }\n\n  friend ostream &operator<<(ostream &os, Mat\
    \ &p) {\n    for (int i = 0; i < N; i++) {\n      os << \"[\";\n      for (int\
    \ j = 0; j < N; j++) {\n        os << p[i][j].x << (j == N - 1 ? \"]\\n\" : \"\
    ,\");\n      }\n    }\n    return (os);\n  }\n};\n\n/**\n * @brief \u534A\u74B0\
    \u30E9\u30A4\u30D6\u30E9\u30EA\n * @docs docs/math/semiring.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: math/semiring.hpp
  requiredBy: []
  timestamp: '2021-01-01 23:05:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yuki/yuki-1340-semiring.test.cpp
  - verify/verify-unit-test/semiring.test.cpp
documentation_of: math/semiring.hpp
layout: document
redirect_from:
- /library/math/semiring.hpp
- /library/math/semiring.hpp.html
title: "\u534A\u74B0\u30E9\u30A4\u30D6\u30E9\u30EA"
---
## 半環ライブラリ

#### 概要

半環(semiring, rig)とは集合$R$と二つの二項演算(加法$+$と乗法$\cdot$)からなる代数的構造である。$R,+,\cdot$は以下の関係を満たしている。

- $(R, +)$は$0$を単位元とする可換モノイドをなす
- $(R, \cdot)$は$1$を単位元とするモノイドをなす
- $+,\cdot$に対して分配法則が成り立つ
- $\forall r\in R$を$0$倍すると$0$になる

特にmax-plus半環/min-plus半環はトロピカル半環と呼ばれていて、グラフ上の最短経路の計算などに利用される。

#### テンプレート

- `U`: 集合$R$
- `add`: 二項演算$(R,+)$
- `mul`: 二項演算$(R,\cdot)$
- `i0()`: 単位元$0$
- `i1()`: 単位元$1$

```
// max-plus semiring
/**
using U = long long;
U add(U a, U b) { return max(a, b); }
U mul(U a, U b) { return a + b; }
U i0() { return -infLL; }
U i1() { return 0; }
using rig = semiring<U, add, mul, i0, i1>;
//*/

// min-plus semiring
/**
using U = long long;
U add(U a, U b) { return min(a, b); }
U mul(U a, U b) { return a + b; }
U i0() { return infLL; }
U i1() { return 0; }
using rig = semiring<U, add, mul, i0, i1>;
//*/

// max(x + a, b)
// verify: DDCC2020-final-b
/**
using U = pair<long long, long long>;
U add(U a, U b) {
  long long f = max(a.first, b.first);
  long long g = max(a.second, b.second);
  return U(f, g);
}
U mul(U a, U b) {
  long long f = a.first + b.first;
  long long g = max(a.second + b.first, b.second);
  return U(f, g);
}
U i0() { return U(-infLL, -infLL); }
U i1() { return U(0, -infLL); }
using rig = semiring<U, add, mul, i0, i1>;
//*/

// xor-and semiring
/**
using U = unsigned long long;
U add(U a, U b) { return a ^ b; }
U mul(U a, U b) { return a & b; }
U i0() { return 0; }
U i1() { return U(-1); }
using rig = semiring<U, add, mul, i0, i1>;
//*/
```