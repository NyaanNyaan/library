---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math/semiring.hpp\"\n#include <bits/stdc++.h>\nusing namespace\
    \ std;\n\ntemplate <typename T, typename F, typename G>\nstruct semiring {\n \
    \ T x;\n  static T id0, id1;\n  static F add;\n  static G mul;\n  semiring() :\
    \ x(id0) {}\n  semiring(T y) : x(y) {}\n\n  semiring &operator+=(const semiring\
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
    \ N; i++)\n      for (int j = 0; j < N; j++)\n        for (int k = 0; k < N; k++)\
    \ C[i][j] = (C[i][j] + A[i][k] * B[k][j]);\n    A.swap(C.A);\n    return (*this);\n\
    \  }\n\n  Mat &operator^=(long long k) {\n    Mat B = Mat::I();\n    while (k\
    \ > 0) {\n      if (k & 1) B *= *this;\n      *this *= *this;\n      k >>= 1LL;\n\
    \    }\n    A.swap(B.A);\n    return (*this);\n  }\n\n  Mat operator+(const Mat\
    \ &B) const { return (Mat(*this) += B); }\n\n  Mat operator*(const Mat &B) const\
    \ { return (Mat(*this) *= B); }\n\n  Mat operator^(const long long k) const {\
    \ return (Mat(*this) ^= k); }\n};\n\n// old version (using std::vector)\n/*\n\
    template <typename T, typename F, typename G>\nstruct Mat {\n  using rig = semiring<T,\
    \ F, G>;\n  vector<vector<rig> > A;\n  Mat() {}\n  Mat(int n, int m) : A(n, vector<rig>(m,\
    \ rig::id0)) {}\n  Mat(int n) : A(n, vector<rig>(n, rig::id0)){};\n\n  int height()\
    \ const { return (A.size()); }\n\n  int width() const { return (A[0].size());\
    \ }\n\n  inline const vector<rig> &operator[](int k) const { return (A.at(k));\
    \ }\n\n  inline vector<rig> &operator[](int k) { return (A.at(k)); }\n\n  static\
    \ Mat I(int n) {\n    Mat m(n);\n    for (int i = 0; i < n; i++) m[i][i] = rig::id1;\n\
    \    return (m);\n  }\n\n  Mat &operator+=(const Mat &B) {\n    int n = height(),\
    \ m = width();\n    assert(n == B.height() && m == B.width());\n    for (int i\
    \ = 0; i < n; i++)\n      for (int j = 0; j < m; j++) (*this)[i][j] += B[i][j];\n\
    \    return (*this);\n  }\n\n  Mat &operator*=(const Mat &B) {\n    int n = height(),\
    \ m = B.width(), p = width();\n    assert(p == B.height());\n    vector<vector<rig>\
    \ > C(n, vector<rig>(m, rig::id0));\n    for (int i = 0; i < n; i++)\n      for\
    \ (int j = 0; j < m; j++)\n        for (int k = 0; k < p; k++)\n          C[i][j]\
    \ = (C[i][j] + (*this)[i][k] * B[k][j]);\n    A.swap(C);\n    return (*this);\n\
    \  }\n\n  Mat &operator^=(long long k) {\n    Mat B = Mat::I(height());\n    while\
    \ (k > 0) {\n      if (k & 1) B *= *this;\n      *this *= *this;\n      k >>=\
    \ 1LL;\n    }\n    A.swap(B.A);\n    return (*this);\n  }\n\n  Mat operator+(const\
    \ Mat &B) const { return (Mat(*this) += B); }\n\n  Mat operator*(const Mat &B)\
    \ const { return (Mat(*this) *= B); }\n\n  Mat operator^(const long long k) const\
    \ { return (Mat(*this) ^= k); }\n};\n*/\n\n// max-plus semiring\n/**\nusing U\
    \ = long long;\nU ID0 = -infLL;\nU ID1 = 0;\nauto Add = [](U a, U b) -> U { return\
    \ max(a, b); };\nauto Mul = [](U a, U b) -> U { return a + b; };\n//*/\n\n// min-plus\
    \ semiring\n/**\nusing U = ll;\nU ID0 = infLL;\nU ID1 = 0;\nauto Add = [](U a,\
    \ U b) -> U { return min(a, b); };\nauto Mul = [](U a, U b) -> U { return a +\
    \ b; };\n//*/\n\n// xor-and semiring\n/**/\nusing U = unsigned long long;\nconstexpr\
    \ U ID0 = 0;\nconstexpr U ID1 = U(-1);\nauto Add = [](U a, U b) -> U { return\
    \ a ^ b; };\nauto Mul = [](U a, U b) -> U { return a & b; };\n//*/\n\ntemplate\
    \ <typename T, typename F, typename G>\nT semiring<T, F, G>::id0 = ID0;\ntemplate\
    \ <typename T, typename F, typename G>\nT semiring<T, F, G>::id1 = ID1;\ntemplate\
    \ <typename T, typename F, typename G>\nF semiring<T, F, G>::add = Add;\ntemplate\
    \ <typename T, typename F, typename G>\nG semiring<T, F, G>::mul = Mul;\nusing\
    \ rig = semiring<U, decltype(Add), decltype(Mul)>;\ntemplate <int N>\nusing mat\
    \ = Mat<U, decltype(Add), decltype(Mul), N>;\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\ntemplate\
    \ <typename T, typename F, typename G>\nstruct semiring {\n  T x;\n  static T\
    \ id0, id1;\n  static F add;\n  static G mul;\n  semiring() : x(id0) {}\n  semiring(T\
    \ y) : x(y) {}\n\n  semiring &operator+=(const semiring &p) {\n    if (x == id0)\
    \ return *this = p;\n    if (p == id0) return *this;\n    return *this = add(x,\
    \ p.x);\n  }\n\n  semiring &operator*=(const semiring &p) {\n    if (x == id0\
    \ || p == id0) return *this = id0;\n    if (x == id1) return *this = p;\n    if\
    \ (p == id1) return *this;\n    return *this = mul(x, p.x);\n  }\n\n  semiring\
    \ operator+(const semiring &p) const { return semiring(*this) += p; }\n\n  semiring\
    \ operator*(const semiring &p) const { return semiring(*this) *= p; }\n\n  bool\
    \ operator==(const semiring &p) const { return x == p.x; }\n\n  bool operator!=(const\
    \ semiring &p) const { return x != p.x; }\n\n  friend ostream &operator<<(ostream\
    \ &os, const semiring &p) {\n    return os << p.x;\n  }\n};\n\ntemplate <typename\
    \ T, typename F, typename G, int N>\nstruct Mat {\n  using rig = semiring<T, F,\
    \ G>;\n  using Array = array<array<rig, N>, N>;\n  Array A;\n  Mat() {\n    for\
    \ (int i = 0; i < N; i++) A[i].fill(rig::id0);\n  }\n  int height() const { return\
    \ N; }\n\n  int width() const { return N; }\n\n  inline const array<rig, N> &operator[](int\
    \ k) const { return A[k]; }\n\n  inline array<rig, N> &operator[](int k) { return\
    \ A[k]; }\n\n  static Mat I() {\n    Mat m;\n    for (int i = 0; i < N; i++) m[i][i]\
    \ = rig::id1;\n    return (m);\n  }\n\n  Mat &operator+=(const Mat &B) {\n   \
    \ for (int i = 0; i < N; i++)\n      for (int j = 0; j < N; j++) A[i][j] += B[i][j];\n\
    \    return (*this);\n  }\n\n  Mat &operator*=(const Mat &B) {\n    Mat C;\n \
    \   for (int i = 0; i < N; i++)\n      for (int j = 0; j < N; j++)\n        for\
    \ (int k = 0; k < N; k++) C[i][j] = (C[i][j] + A[i][k] * B[k][j]);\n    A.swap(C.A);\n\
    \    return (*this);\n  }\n\n  Mat &operator^=(long long k) {\n    Mat B = Mat::I();\n\
    \    while (k > 0) {\n      if (k & 1) B *= *this;\n      *this *= *this;\n  \
    \    k >>= 1LL;\n    }\n    A.swap(B.A);\n    return (*this);\n  }\n\n  Mat operator+(const\
    \ Mat &B) const { return (Mat(*this) += B); }\n\n  Mat operator*(const Mat &B)\
    \ const { return (Mat(*this) *= B); }\n\n  Mat operator^(const long long k) const\
    \ { return (Mat(*this) ^= k); }\n};\n\n// old version (using std::vector)\n/*\n\
    template <typename T, typename F, typename G>\nstruct Mat {\n  using rig = semiring<T,\
    \ F, G>;\n  vector<vector<rig> > A;\n  Mat() {}\n  Mat(int n, int m) : A(n, vector<rig>(m,\
    \ rig::id0)) {}\n  Mat(int n) : A(n, vector<rig>(n, rig::id0)){};\n\n  int height()\
    \ const { return (A.size()); }\n\n  int width() const { return (A[0].size());\
    \ }\n\n  inline const vector<rig> &operator[](int k) const { return (A.at(k));\
    \ }\n\n  inline vector<rig> &operator[](int k) { return (A.at(k)); }\n\n  static\
    \ Mat I(int n) {\n    Mat m(n);\n    for (int i = 0; i < n; i++) m[i][i] = rig::id1;\n\
    \    return (m);\n  }\n\n  Mat &operator+=(const Mat &B) {\n    int n = height(),\
    \ m = width();\n    assert(n == B.height() && m == B.width());\n    for (int i\
    \ = 0; i < n; i++)\n      for (int j = 0; j < m; j++) (*this)[i][j] += B[i][j];\n\
    \    return (*this);\n  }\n\n  Mat &operator*=(const Mat &B) {\n    int n = height(),\
    \ m = B.width(), p = width();\n    assert(p == B.height());\n    vector<vector<rig>\
    \ > C(n, vector<rig>(m, rig::id0));\n    for (int i = 0; i < n; i++)\n      for\
    \ (int j = 0; j < m; j++)\n        for (int k = 0; k < p; k++)\n          C[i][j]\
    \ = (C[i][j] + (*this)[i][k] * B[k][j]);\n    A.swap(C);\n    return (*this);\n\
    \  }\n\n  Mat &operator^=(long long k) {\n    Mat B = Mat::I(height());\n    while\
    \ (k > 0) {\n      if (k & 1) B *= *this;\n      *this *= *this;\n      k >>=\
    \ 1LL;\n    }\n    A.swap(B.A);\n    return (*this);\n  }\n\n  Mat operator+(const\
    \ Mat &B) const { return (Mat(*this) += B); }\n\n  Mat operator*(const Mat &B)\
    \ const { return (Mat(*this) *= B); }\n\n  Mat operator^(const long long k) const\
    \ { return (Mat(*this) ^= k); }\n};\n*/\n\n// max-plus semiring\n/**\nusing U\
    \ = long long;\nU ID0 = -infLL;\nU ID1 = 0;\nauto Add = [](U a, U b) -> U { return\
    \ max(a, b); };\nauto Mul = [](U a, U b) -> U { return a + b; };\n//*/\n\n// min-plus\
    \ semiring\n/**\nusing U = ll;\nU ID0 = infLL;\nU ID1 = 0;\nauto Add = [](U a,\
    \ U b) -> U { return min(a, b); };\nauto Mul = [](U a, U b) -> U { return a +\
    \ b; };\n//*/\n\n// xor-and semiring\n/**/\nusing U = unsigned long long;\nconstexpr\
    \ U ID0 = 0;\nconstexpr U ID1 = U(-1);\nauto Add = [](U a, U b) -> U { return\
    \ a ^ b; };\nauto Mul = [](U a, U b) -> U { return a & b; };\n//*/\n\ntemplate\
    \ <typename T, typename F, typename G>\nT semiring<T, F, G>::id0 = ID0;\ntemplate\
    \ <typename T, typename F, typename G>\nT semiring<T, F, G>::id1 = ID1;\ntemplate\
    \ <typename T, typename F, typename G>\nF semiring<T, F, G>::add = Add;\ntemplate\
    \ <typename T, typename F, typename G>\nG semiring<T, F, G>::mul = Mul;\nusing\
    \ rig = semiring<U, decltype(Add), decltype(Mul)>;\ntemplate <int N>\nusing mat\
    \ = Mat<U, decltype(Add), decltype(Mul), N>;"
  dependsOn: []
  isVerificationFile: false
  path: math/semiring.hpp
  requiredBy: []
  timestamp: '2020-07-28 11:29:32+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math/semiring.hpp
layout: document
redirect_from:
- /library/math/semiring.hpp
- /library/math/semiring.hpp.html
title: math/semiring.hpp
---
