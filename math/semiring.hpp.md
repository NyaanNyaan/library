---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/semiring.test.cpp
    title: verify/verify-unit-test/semiring.test.cpp
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
    \ {\n    if (x == I0()) return *this = p;\n    if (p == I0()) return *this;\n\
    \    return *this = add(x, p.x);\n  }\n\n  semiring &operator*=(const semiring\
    \ &p) {\n    if (x == I0() || p == I0()) return *this = I0();\n    if (x == I1())\
    \ return *this = p;\n    if (p == I1()) return *this;\n    return *this = mul(x,\
    \ p.x);\n  }\n\n  semiring operator+(const semiring &p) const { return semiring(*this)\
    \ += p; }\n  semiring operator*(const semiring &p) const { return semiring(*this)\
    \ *= p; }\n  bool operator==(const semiring &p) const { return x == p.x; }\n \
    \ bool operator!=(const semiring &p) const { return x != p.x; }\n  friend ostream\
    \ &operator<<(ostream &os, const semiring &p) {\n    return os << p.x;\n  }\n\
    };\n\ntemplate <typename rig, int N>\nstruct Mat {\n  using Array = array<array<rig,\
    \ N>, N>;\n  Array A;\n\n  Mat() {\n    for (int i = 0; i < N; i++) A[i].fill(rig::id0());\n\
    \  }\n  int height() const { return N; }\n  int width() const { return N; }\n\
    \  inline const array<rig, N> &operator[](int k) const { return A[k]; }\n  inline\
    \ array<rig, N> &operator[](int k) { return A[k]; }\n\n  static Mat I() {\n  \
    \  Mat m;\n    for (int i = 0; i < N; i++) m[i][i] = rig::id1();\n    return m;\n\
    \  }\n\n  Mat &operator+=(const Mat &B) {\n    for (int i = 0; i < N; i++)\n \
    \     for (int j = 0; j < N; j++) A[i][j] += B[i][j];\n    return (*this);\n \
    \ }\n\n  Mat &operator*=(const Mat &B) {\n    Mat C;\n    for (int i = 0; i <\
    \ N; i++)\n      for (int k = 0; k < N; k++)\n        for (int j = 0; j < N; j++)\
    \ C[i][j] += A[i][k] * B[k][j];\n    A.swap(C.A);\n    return (*this);\n  }\n\n\
    \  Mat &operator^=(long long k) {\n    Mat B = Mat::I();\n    for (; k; *this\
    \ *= *this, k >>= 1)\n      if (k & 1) B *= *this;\n    A.swap(B.A);\n    return\
    \ (*this);\n  }\n\n  Mat operator+(const Mat &B) const { return (Mat(*this) +=\
    \ B); }\n  Mat operator*(const Mat &B) const { return (Mat(*this) *= B); }\n \
    \ Mat operator^(long long k) const { return (Mat(*this) ^= k); }\n\n  friend ostream\
    \ &operator<<(ostream &os, Mat &p) {\n    for (int i = 0; i < N; i++) {\n    \
    \  os << \"[\";\n      for (int j = 0; j < N; j++) {\n        os << p[i][j] <<\
    \ (j == N - 1 ? \"]\\n\" : \",\");\n      }\n    }\n    return (os);\n  }\n};\n\
    \n/**\n * @brief \u534A\u74B0\u30E9\u30A4\u30D6\u30E9\u30EA\n * @docs docs/math/semiring.md\n\
    \ */\n"
  code: "#pragma once\n\ntemplate <typename T, T (*add)(T, T), T (*mul)(T, T), T (*I0)(),\
    \ T (*I1)()>\nstruct semiring {\n  T x;\n  semiring() : x(I0()) {}\n  semiring(T\
    \ y) : x(y) {}\n  static T id0() { return I0(); }\n  static T id1() { return I1();\
    \ }\n\n  semiring &operator+=(const semiring &p) {\n    if (x == I0()) return\
    \ *this = p;\n    if (p == I0()) return *this;\n    return *this = add(x, p.x);\n\
    \  }\n\n  semiring &operator*=(const semiring &p) {\n    if (x == I0() || p ==\
    \ I0()) return *this = I0();\n    if (x == I1()) return *this = p;\n    if (p\
    \ == I1()) return *this;\n    return *this = mul(x, p.x);\n  }\n\n  semiring operator+(const\
    \ semiring &p) const { return semiring(*this) += p; }\n  semiring operator*(const\
    \ semiring &p) const { return semiring(*this) *= p; }\n  bool operator==(const\
    \ semiring &p) const { return x == p.x; }\n  bool operator!=(const semiring &p)\
    \ const { return x != p.x; }\n  friend ostream &operator<<(ostream &os, const\
    \ semiring &p) {\n    return os << p.x;\n  }\n};\n\ntemplate <typename rig, int\
    \ N>\nstruct Mat {\n  using Array = array<array<rig, N>, N>;\n  Array A;\n\n \
    \ Mat() {\n    for (int i = 0; i < N; i++) A[i].fill(rig::id0());\n  }\n  int\
    \ height() const { return N; }\n  int width() const { return N; }\n  inline const\
    \ array<rig, N> &operator[](int k) const { return A[k]; }\n  inline array<rig,\
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
    \ j = 0; j < N; j++) {\n        os << p[i][j] << (j == N - 1 ? \"]\\n\" : \",\"\
    );\n      }\n    }\n    return (os);\n  }\n};\n\n/**\n * @brief \u534A\u74B0\u30E9\
    \u30A4\u30D6\u30E9\u30EA\n * @docs docs/math/semiring.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: math/semiring.hpp
  requiredBy: []
  timestamp: '2021-01-01 21:25:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-unit-test/semiring.test.cpp
documentation_of: math/semiring.hpp
layout: document
redirect_from:
- /library/math/semiring.hpp
- /library/math/semiring.hpp.html
title: "\u534A\u74B0\u30E9\u30A4\u30D6\u30E9\u30EA"
---
#### テンプレート

```
// max-plus semiring
/**/
using U = long long;
U ID0 = -4e18;
U ID1 = 0;
auto Add = [](U a, U b) -> U { return max(a, b); };
auto Mul = [](U a, U b) -> U { return a + b; };
//*/

// min-plus semiring
/**
using U = long long;
U ID0 = 4e18;
U ID1 = 0;
auto Add = [](U a, U b) -> U { return min(a, b); };
auto Mul = [](U a, U b) -> U { return a + b; };
//*/

// xor-and semiring
/**
using U = unsigned long long;
constexpr U ID0 = 0;
constexpr U ID1 = U(-1);
auto Add = [](U a, U b) -> U { return a ^ b; };
auto Mul = [](U a, U b) -> U { return a & b; };
//*/

template <typename T, typename F, typename G>
T semiring<T, F, G>::id0 = ID0;
template <typename T, typename F, typename G>
T semiring<T, F, G>::id1 = ID1;
template <typename T, typename F, typename G>
F semiring<T, F, G>::add = Add;
template <typename T, typename F, typename G>
G semiring<T, F, G>::mul = Mul;
using rig = semiring<U, decltype(Add), decltype(Mul)>;
template <int N>
using mat = Mat<U, decltype(Add), decltype(Mul), N>;

```