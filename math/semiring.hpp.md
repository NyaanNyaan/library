---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/math/semiring.md
    document_title: "\u534A\u74B0\u30E9\u30A4\u30D6\u30E9\u30EA"
    links: []
  bundledCode: "#line 2 \"math/semiring.hpp\"\n\ntemplate <typename T, typename F,\
    \ typename G>\nstruct semiring {\n  T x;\n  static T id0, id1;\n  static F add;\n\
    \  static G mul;\n  semiring() : x(id0) {}\n  semiring(T y) : x(y) {}\n\n  semiring\
    \ &operator+=(const semiring &p) {\n    if (x == id0) return *this = p;\n    if\
    \ (p == id0) return *this;\n    return *this = add(x, p.x);\n  }\n\n  semiring\
    \ &operator*=(const semiring &p) {\n    if (x == id0 || p == id0) return *this\
    \ = id0;\n    if (x == id1) return *this = p;\n    if (p == id1) return *this;\n\
    \    return *this = mul(x, p.x);\n  }\n\n  semiring operator+(const semiring &p)\
    \ const { return semiring(*this) += p; }\n\n  semiring operator*(const semiring\
    \ &p) const { return semiring(*this) *= p; }\n\n  bool operator==(const semiring\
    \ &p) const { return x == p.x; }\n\n  bool operator!=(const semiring &p) const\
    \ { return x != p.x; }\n\n  friend ostream &operator<<(ostream &os, const semiring\
    \ &p) {\n    return os << p.x;\n  }\n};\n\ntemplate <typename T, typename F, typename\
    \ G, int N>\nstruct Mat {\n  using rig = semiring<T, F, G>;\n  using Array = array<array<rig,\
    \ N>, N>;\n  Array A;\n  Mat() {\n    for (int i = 0; i < N; i++) A[i].fill(rig::id0);\n\
    \  }\n  int height() const { return N; }\n\n  int width() const { return N; }\n\
    \n  inline const array<rig, N> &operator[](int k) const { return A[k]; }\n\n \
    \ inline array<rig, N> &operator[](int k) { return A[k]; }\n\n  static Mat I()\
    \ {\n    Mat m;\n    for (int i = 0; i < N; i++) m[i][i] = rig::id1;\n    return\
    \ (m);\n  }\n\n  Mat &operator+=(const Mat &B) {\n    for (int i = 0; i < N; i++)\n\
    \      for (int j = 0; j < N; j++) A[i][j] += B[i][j];\n    return (*this);\n\
    \  }\n\n  Mat &operator*=(const Mat &B) {\n    Mat C;\n    for (int i = 0; i <\
    \ N; i++)\n      for (int k = 0; k < N; k++)\n        for (int j = 0; j < N; j++)\
    \ C[i][j] = (C[i][j] + A[i][k] * B[k][j]);\n    A.swap(C.A);\n    return (*this);\n\
    \  }\n\n  Mat &operator^=(long long k) {\n    Mat B = Mat::I();\n    while (k\
    \ > 0) {\n      if (k & 1) B *= *this;\n      *this *= *this;\n      k >>= 1LL;\n\
    \    }\n    A.swap(B.A);\n    return (*this);\n  }\n\n  Mat operator+(const Mat\
    \ &B) const { return (Mat(*this) += B); }\n\n  Mat operator*(const Mat &B) const\
    \ { return (Mat(*this) *= B); }\n\n  Mat operator^(const long long k) const {\
    \ return (Mat(*this) ^= k); }\n};\n\n/**\n * @brief \u534A\u74B0\u30E9\u30A4\u30D6\
    \u30E9\u30EA\n * @docs docs/math/semiring.md\n */\n"
  code: "#pragma once\n\ntemplate <typename T, typename F, typename G>\nstruct semiring\
    \ {\n  T x;\n  static T id0, id1;\n  static F add;\n  static G mul;\n  semiring()\
    \ : x(id0) {}\n  semiring(T y) : x(y) {}\n\n  semiring &operator+=(const semiring\
    \ &p) {\n    if (x == id0) return *this = p;\n    if (p == id0) return *this;\n\
    \    return *this = add(x, p.x);\n  }\n\n  semiring &operator*=(const semiring\
    \ &p) {\n    if (x == id0 || p == id0) return *this = id0;\n    if (x == id1)\
    \ return *this = p;\n    if (p == id1) return *this;\n    return *this = mul(x,\
    \ p.x);\n  }\n\n  semiring operator+(const semiring &p) const { return semiring(*this)\
    \ += p; }\n\n  semiring operator*(const semiring &p) const { return semiring(*this)\
    \ *= p; }\n\n  bool operator==(const semiring &p) const { return x == p.x; }\n\
    \n  bool operator!=(const semiring &p) const { return x != p.x; }\n\n  friend\
    \ ostream &operator<<(ostream &os, const semiring &p) {\n    return os << p.x;\n\
    \  }\n};\n\ntemplate <typename T, typename F, typename G, int N>\nstruct Mat {\n\
    \  using rig = semiring<T, F, G>;\n  using Array = array<array<rig, N>, N>;\n\
    \  Array A;\n  Mat() {\n    for (int i = 0; i < N; i++) A[i].fill(rig::id0);\n\
    \  }\n  int height() const { return N; }\n\n  int width() const { return N; }\n\
    \n  inline const array<rig, N> &operator[](int k) const { return A[k]; }\n\n \
    \ inline array<rig, N> &operator[](int k) { return A[k]; }\n\n  static Mat I()\
    \ {\n    Mat m;\n    for (int i = 0; i < N; i++) m[i][i] = rig::id1;\n    return\
    \ (m);\n  }\n\n  Mat &operator+=(const Mat &B) {\n    for (int i = 0; i < N; i++)\n\
    \      for (int j = 0; j < N; j++) A[i][j] += B[i][j];\n    return (*this);\n\
    \  }\n\n  Mat &operator*=(const Mat &B) {\n    Mat C;\n    for (int i = 0; i <\
    \ N; i++)\n      for (int k = 0; k < N; k++)\n        for (int j = 0; j < N; j++)\
    \ C[i][j] = (C[i][j] + A[i][k] * B[k][j]);\n    A.swap(C.A);\n    return (*this);\n\
    \  }\n\n  Mat &operator^=(long long k) {\n    Mat B = Mat::I();\n    while (k\
    \ > 0) {\n      if (k & 1) B *= *this;\n      *this *= *this;\n      k >>= 1LL;\n\
    \    }\n    A.swap(B.A);\n    return (*this);\n  }\n\n  Mat operator+(const Mat\
    \ &B) const { return (Mat(*this) += B); }\n\n  Mat operator*(const Mat &B) const\
    \ { return (Mat(*this) *= B); }\n\n  Mat operator^(const long long k) const {\
    \ return (Mat(*this) ^= k); }\n};\n\n/**\n * @brief \u534A\u74B0\u30E9\u30A4\u30D6\
    \u30E9\u30EA\n * @docs docs/math/semiring.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: math/semiring.hpp
  requiredBy: []
  timestamp: '2020-12-13 00:57:06+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
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