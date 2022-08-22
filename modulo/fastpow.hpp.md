---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modulo/fastpow.hpp\"\n\n\ntemplate <typename T, int LOG\
    \ = 21>\nstruct FastPow {\n  static constexpr long long B0 = 1LL << LOG;\n  static\
    \ constexpr long long B1 = 1LL << (LOG * 2);\n  static constexpr long long mask\
    \ = B0 - 1;\n  vector<T> p0, p1, p2;\n  FastPow(T base, T I = 1) : p0(B0), p1(B0),\
    \ p2(B0) {\n    T x = I;\n    for (int i = 0; i < B0; i++) p0[i] = x, x *= base;\n\
    \    base = x, x = I;\n    for (int i = 0; i < B0; i++) p1[i] = x, x *= base;\n\
    \    base = x, x = I;\n    for (int i = 0; i < B0; i++) p2[i] = x, x *= base;\n\
    \  }\n  T operator()(long long e) {\n    assert(0 <= e);\n    if (e < B0) return\
    \ p0[e];\n    if (e < B1) return p0[e & mask] * p1[(e >> LOG) & mask];\n    return\
    \ p0[e & mask] * p1[(e >> LOG) & mask] * p2[(e >> (LOG * 2)) & mask];\n  }\n};\n"
  code: "#pragma once\n\n\ntemplate <typename T, int LOG = 21>\nstruct FastPow {\n\
    \  static constexpr long long B0 = 1LL << LOG;\n  static constexpr long long B1\
    \ = 1LL << (LOG * 2);\n  static constexpr long long mask = B0 - 1;\n  vector<T>\
    \ p0, p1, p2;\n  FastPow(T base, T I = 1) : p0(B0), p1(B0), p2(B0) {\n    T x\
    \ = I;\n    for (int i = 0; i < B0; i++) p0[i] = x, x *= base;\n    base = x,\
    \ x = I;\n    for (int i = 0; i < B0; i++) p1[i] = x, x *= base;\n    base = x,\
    \ x = I;\n    for (int i = 0; i < B0; i++) p2[i] = x, x *= base;\n  }\n  T operator()(long\
    \ long e) {\n    assert(0 <= e);\n    if (e < B0) return p0[e];\n    if (e < B1)\
    \ return p0[e & mask] * p1[(e >> LOG) & mask];\n    return p0[e & mask] * p1[(e\
    \ >> LOG) & mask] * p2[(e >> (LOG * 2)) & mask];\n  }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: modulo/fastpow.hpp
  requiredBy: []
  timestamp: '2022-08-22 19:46:43+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: modulo/fastpow.hpp
layout: document
redirect_from:
- /library/modulo/fastpow.hpp
- /library/modulo/fastpow.hpp.html
title: modulo/fastpow.hpp
---
