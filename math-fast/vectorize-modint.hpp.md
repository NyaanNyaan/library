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
  bundledCode: "#line 2 \"math-fast/vectorize-modint.hpp\"\n\n#include <immintrin.h>\n\
    \n#include <array>\n\nusing namespace std;\n\n#pragma GCC optimize(\"O3,unroll-loops\"\
    )\n#pragma GCC target(\"avx2\")\n\ntemplate <typename _mint>\nstruct alignas(32)\
    \ vectorize_modint {\n  using mint = _mint;\n  using m256 = __m256i;\n  using\
    \ vmint = vectorize_modint;\n  m256 x;\n  inline static vmint R = mint::r;\n \
    \ inline static vmint M0 = 0;\n  inline static vmint M1 = mint::get_mod();\n \
    \ inline static vmint M2 = mint::get_mod() * 2;\n  inline static vmint N2 = mint::n2;\n\
    \  vectorize_modint() = default;\n  vectorize_modint(int a) : x(_mm256_set1_epi32(a))\
    \ {}\n  vectorize_modint(const m256& _x) : x(_x) {}\n  vectorize_modint(const\
    \ array<int, 8>& a)\n      : x(_mm256_loadu_si256((m256*)a.data())) {}\n  vectorize_modint(int\
    \ a0, int a1, int a2, int a3, int a4, int a5, int a6,\n                   int\
    \ a7)\n      : x(_mm256_set_epi32(a7, a6, a5, a4, a3, a2, a1, a0)) {}\n  int at(int\
    \ i) const {\n    /*\n    alignas(32) array<int, 8> b;\n    _mm256_store_si256((m256*)b.data(),\
    \ x);\n    return b[i];\n    */\n    return *(reinterpret_cast<const int*>(&x)\
    \ + i);\n  }\n  void set(int i, int val) {\n    /*\n    alignas(32) array<int,\
    \ 8> b;\n    _mm256_store_si256((m256*)b.data(), x);\n    b[i] = val;\n    x =\
    \ _mm256_load_si256((m256*)b.data());\n    */\n    *(reinterpret_cast<int*>(&x)\
    \ + i) = val;\n  }\n  operator const __m256i&() const { return x; }\n  friend\
    \ ostream& operator<<(ostream& os, const vmint& m) {\n    vmint a = mtoi(m);\n\
    \    for (int i = 0; i < 8; i++) os << a.at(i) << (i == 7 ? \"\" : \" \");\n \
    \   return os;\n  }\n  static vmint reduce(const vmint& prod02, const vmint& prod13)\
    \ {\n    m256 unpalo = _mm256_unpacklo_epi32(prod02, prod13);\n    m256 unpahi\
    \ = _mm256_unpackhi_epi32(prod02, prod13);\n    m256 prodlo = _mm256_unpacklo_epi64(unpalo,\
    \ unpahi);\n    m256 prodhi = _mm256_unpackhi_epi64(unpalo, unpahi);\n    m256\
    \ hiplm1 = _mm256_add_epi32(prodhi, M1);\n    m256 prodlohi = _mm256_shuffle_epi32(prodlo,\
    \ 0xF5);\n    m256 lmlr02 = _mm256_mul_epu32(prodlo, R);\n    m256 lmlr13 = _mm256_mul_epu32(prodlohi,\
    \ R);\n    m256 prod02_ = _mm256_mul_epu32(lmlr02, M1);\n    m256 prod13_ = _mm256_mul_epu32(lmlr13,\
    \ M1);\n    m256 unpalo_ = _mm256_unpacklo_epi32(prod02_, prod13_);\n    m256\
    \ unpahi_ = _mm256_unpackhi_epi32(prod02_, prod13_);\n    m256 prod = _mm256_unpackhi_epi64(unpalo_,\
    \ unpahi_);\n    return _mm256_sub_epi32(hiplm1, prod);\n  }\n  static vmint itom(const\
    \ vmint& A) { return A * N2; }\n  static vmint mtoi(const vmint& A) {\n    m256\
    \ A13 = _mm256_shuffle_epi32(A, 0xF5);\n    m256 lmlr02 = _mm256_mul_epu32(A,\
    \ R);\n    m256 lmlr13 = _mm256_mul_epu32(A13, R);\n    m256 prod02_ = _mm256_mul_epu32(lmlr02,\
    \ M1);\n    m256 prod13_ = _mm256_mul_epu32(lmlr13, M1);\n    m256 unpalo_ = _mm256_unpacklo_epi32(prod02_,\
    \ prod13_);\n    m256 unpahi_ = _mm256_unpackhi_epi32(prod02_, prod13_);\n   \
    \ m256 prod = _mm256_unpackhi_epi64(unpalo_, unpahi_);\n    m256 cmp = _mm256_cmpgt_epi32(prod,\
    \ M0);\n    m256 dif = _mm256_and_si256(cmp, M1);\n    return _mm256_sub_epi32(dif,\
    \ prod);\n  }\n  __attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\"\
    ))) friend vmint\n  operator+(const vmint& A, const vmint& B) {\n    m256 apb\
    \ = _mm256_add_epi32(A, B);\n    m256 ret = _mm256_sub_epi32(apb, M2);\n    return\
    \ _mm256_min_epu32(apb, ret);\n  }\n  __attribute__((target(\"avx2\"), optimize(\"\
    O3\", \"unroll-loops\"))) friend vmint\n  operator-(const vmint& A, const vmint&\
    \ B) {\n    m256 amb = _mm256_sub_epi32(A, B);\n    m256 ret = _mm256_add_epi32(amb,\
    \ M2);\n    return _mm256_min_epu32(amb, ret);\n  }\n  __attribute__((target(\"\
    avx2\"), optimize(\"O3\", \"unroll-loops\"))) friend vmint\n  operator*(const\
    \ vmint& A, const vmint& B) {\n    m256 a13 = _mm256_shuffle_epi32(A, 0xF5);\n\
    \    m256 b13 = _mm256_shuffle_epi32(B, 0xF5);\n    m256 prod02 = _mm256_mul_epu32(A,\
    \ B);\n    m256 prod13 = _mm256_mul_epu32(a13, b13);\n    return reduce(prod02,\
    \ prod13);\n  }\n  vmint& operator+=(const vmint& A) { return (*this) = (*this)\
    \ + A; }\n  vmint& operator-=(const vmint& A) { return (*this) = (*this) - A;\
    \ }\n  vmint& operator*=(const vmint& A) { return (*this) = (*this) * A; }\n};\n"
  code: "#pragma once\n\n#include <immintrin.h>\n\n#include <array>\n\nusing namespace\
    \ std;\n\n#pragma GCC optimize(\"O3,unroll-loops\")\n#pragma GCC target(\"avx2\"\
    )\n\ntemplate <typename _mint>\nstruct alignas(32) vectorize_modint {\n  using\
    \ mint = _mint;\n  using m256 = __m256i;\n  using vmint = vectorize_modint;\n\
    \  m256 x;\n  inline static vmint R = mint::r;\n  inline static vmint M0 = 0;\n\
    \  inline static vmint M1 = mint::get_mod();\n  inline static vmint M2 = mint::get_mod()\
    \ * 2;\n  inline static vmint N2 = mint::n2;\n  vectorize_modint() = default;\n\
    \  vectorize_modint(int a) : x(_mm256_set1_epi32(a)) {}\n  vectorize_modint(const\
    \ m256& _x) : x(_x) {}\n  vectorize_modint(const array<int, 8>& a)\n      : x(_mm256_loadu_si256((m256*)a.data()))\
    \ {}\n  vectorize_modint(int a0, int a1, int a2, int a3, int a4, int a5, int a6,\n\
    \                   int a7)\n      : x(_mm256_set_epi32(a7, a6, a5, a4, a3, a2,\
    \ a1, a0)) {}\n  int at(int i) const {\n    /*\n    alignas(32) array<int, 8>\
    \ b;\n    _mm256_store_si256((m256*)b.data(), x);\n    return b[i];\n    */\n\
    \    return *(reinterpret_cast<const int*>(&x) + i);\n  }\n  void set(int i, int\
    \ val) {\n    /*\n    alignas(32) array<int, 8> b;\n    _mm256_store_si256((m256*)b.data(),\
    \ x);\n    b[i] = val;\n    x = _mm256_load_si256((m256*)b.data());\n    */\n\
    \    *(reinterpret_cast<int*>(&x) + i) = val;\n  }\n  operator const __m256i&()\
    \ const { return x; }\n  friend ostream& operator<<(ostream& os, const vmint&\
    \ m) {\n    vmint a = mtoi(m);\n    for (int i = 0; i < 8; i++) os << a.at(i)\
    \ << (i == 7 ? \"\" : \" \");\n    return os;\n  }\n  static vmint reduce(const\
    \ vmint& prod02, const vmint& prod13) {\n    m256 unpalo = _mm256_unpacklo_epi32(prod02,\
    \ prod13);\n    m256 unpahi = _mm256_unpackhi_epi32(prod02, prod13);\n    m256\
    \ prodlo = _mm256_unpacklo_epi64(unpalo, unpahi);\n    m256 prodhi = _mm256_unpackhi_epi64(unpalo,\
    \ unpahi);\n    m256 hiplm1 = _mm256_add_epi32(prodhi, M1);\n    m256 prodlohi\
    \ = _mm256_shuffle_epi32(prodlo, 0xF5);\n    m256 lmlr02 = _mm256_mul_epu32(prodlo,\
    \ R);\n    m256 lmlr13 = _mm256_mul_epu32(prodlohi, R);\n    m256 prod02_ = _mm256_mul_epu32(lmlr02,\
    \ M1);\n    m256 prod13_ = _mm256_mul_epu32(lmlr13, M1);\n    m256 unpalo_ = _mm256_unpacklo_epi32(prod02_,\
    \ prod13_);\n    m256 unpahi_ = _mm256_unpackhi_epi32(prod02_, prod13_);\n   \
    \ m256 prod = _mm256_unpackhi_epi64(unpalo_, unpahi_);\n    return _mm256_sub_epi32(hiplm1,\
    \ prod);\n  }\n  static vmint itom(const vmint& A) { return A * N2; }\n  static\
    \ vmint mtoi(const vmint& A) {\n    m256 A13 = _mm256_shuffle_epi32(A, 0xF5);\n\
    \    m256 lmlr02 = _mm256_mul_epu32(A, R);\n    m256 lmlr13 = _mm256_mul_epu32(A13,\
    \ R);\n    m256 prod02_ = _mm256_mul_epu32(lmlr02, M1);\n    m256 prod13_ = _mm256_mul_epu32(lmlr13,\
    \ M1);\n    m256 unpalo_ = _mm256_unpacklo_epi32(prod02_, prod13_);\n    m256\
    \ unpahi_ = _mm256_unpackhi_epi32(prod02_, prod13_);\n    m256 prod = _mm256_unpackhi_epi64(unpalo_,\
    \ unpahi_);\n    m256 cmp = _mm256_cmpgt_epi32(prod, M0);\n    m256 dif = _mm256_and_si256(cmp,\
    \ M1);\n    return _mm256_sub_epi32(dif, prod);\n  }\n  __attribute__((target(\"\
    avx2\"), optimize(\"O3\", \"unroll-loops\"))) friend vmint\n  operator+(const\
    \ vmint& A, const vmint& B) {\n    m256 apb = _mm256_add_epi32(A, B);\n    m256\
    \ ret = _mm256_sub_epi32(apb, M2);\n    return _mm256_min_epu32(apb, ret);\n \
    \ }\n  __attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\"))) friend\
    \ vmint\n  operator-(const vmint& A, const vmint& B) {\n    m256 amb = _mm256_sub_epi32(A,\
    \ B);\n    m256 ret = _mm256_add_epi32(amb, M2);\n    return _mm256_min_epu32(amb,\
    \ ret);\n  }\n  __attribute__((target(\"avx2\"), optimize(\"O3\", \"unroll-loops\"\
    ))) friend vmint\n  operator*(const vmint& A, const vmint& B) {\n    m256 a13\
    \ = _mm256_shuffle_epi32(A, 0xF5);\n    m256 b13 = _mm256_shuffle_epi32(B, 0xF5);\n\
    \    m256 prod02 = _mm256_mul_epu32(A, B);\n    m256 prod13 = _mm256_mul_epu32(a13,\
    \ b13);\n    return reduce(prod02, prod13);\n  }\n  vmint& operator+=(const vmint&\
    \ A) { return (*this) = (*this) + A; }\n  vmint& operator-=(const vmint& A) {\
    \ return (*this) = (*this) - A; }\n  vmint& operator*=(const vmint& A) { return\
    \ (*this) = (*this) * A; }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: math-fast/vectorize-modint.hpp
  requiredBy: []
  timestamp: '2023-08-12 16:25:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: math-fast/vectorize-modint.hpp
layout: document
redirect_from:
- /library/math-fast/vectorize-modint.hpp
- /library/math-fast/vectorize-modint.hpp.html
title: math-fast/vectorize-modint.hpp
---
