---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: math-fast/mat-prod-strassen.hpp
    title: math-fast/mat-prod-strassen.hpp
  - icon: ':heavy_check_mark:'
    path: math-fast/subset-convolution.hpp
    title: math-fast/subset-convolution.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-matrix-product-vectorize-modint.test.cpp
    title: verify/verify-yosupo-math/yosupo-matrix-product-vectorize-modint.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-subset-convolution-fast.test.cpp
    title: verify/verify-yosupo-math/yosupo-subset-convolution-fast.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    document_title: vectorize modint
    links: []
  bundledCode: "#line 2 \"modint/vectorize-modint.hpp\"\n\n#pragma GCC optimize(\"\
    O3,unroll-loops\")\n#pragma GCC target(\"avx2\")\n\nusing m256 = __m256i;\nstruct\
    \ alignas(32) mmint {\n  m256 x;\n  static mmint R, M0, M1, M2, N2;\n\n  mmint()\
    \ : x() {}\n  inline mmint(const m256& _x) : x(_x) {}\n  inline mmint(unsigned\
    \ int a) : x(_mm256_set1_epi32(a)) {}\n  inline mmint(unsigned int a0, unsigned\
    \ int a1, unsigned int a2,\n               unsigned int a3, unsigned int a4, unsigned\
    \ int a5,\n               unsigned int a6, unsigned int a7)\n      : x(_mm256_set_epi32(a7,\
    \ a6, a5, a4, a3, a2, a1, a0)) {}\n  inline operator m256&() { return x; }\n \
    \ inline operator const m256&() const { return x; }\n  inline int& operator[](int\
    \ i) { return *(reinterpret_cast<int*>(&x) + i); }\n  inline const int& operator[](int\
    \ i) const {\n    return *(reinterpret_cast<const int*>(&x) + i);\n  }\n\n  friend\
    \ ostream& operator<<(ostream& os, const mmint& m) {\n    unsigned r = R[0], mod\
    \ = M1[0];\n    auto reduce1 = [&](const uint64_t& b) {\n      unsigned res =\
    \ (b + uint64_t(unsigned(b) * unsigned(-r)) * mod) >> 32;\n      return res >=\
    \ mod ? res - mod : res;\n    };\n    for (int i = 0; i < 8; i++) {\n      os\
    \ << reduce1(m[i]) << (i == 7 ? \"\" : \" \");\n    }\n    return os;\n  }\n\n\
    \  template <typename mint>\n  static void set_mod() {\n    R = _mm256_set1_epi32(mint::r);\n\
    \    M0 = _mm256_setzero_si256();\n    M1 = _mm256_set1_epi32(mint::get_mod());\n\
    \    M2 = _mm256_set1_epi32(mint::get_mod() * 2);\n    N2 = _mm256_set1_epi32(mint::n2);\n\
    \  }\n\n  static inline mmint reduce(const mmint& prod02, const mmint& prod13)\
    \ {\n    m256 unpalo = _mm256_unpacklo_epi32(prod02, prod13);\n    m256 unpahi\
    \ = _mm256_unpackhi_epi32(prod02, prod13);\n    m256 prodlo = _mm256_unpacklo_epi64(unpalo,\
    \ unpahi);\n    m256 prodhi = _mm256_unpackhi_epi64(unpalo, unpahi);\n    m256\
    \ hiplm1 = _mm256_add_epi32(prodhi, M1);\n    m256 prodlohi = _mm256_shuffle_epi32(prodlo,\
    \ 0xF5);\n    m256 lmlr02 = _mm256_mul_epu32(prodlo, R);\n    m256 lmlr13 = _mm256_mul_epu32(prodlohi,\
    \ R);\n    m256 prod02_ = _mm256_mul_epu32(lmlr02, M1);\n    m256 prod13_ = _mm256_mul_epu32(lmlr13,\
    \ M1);\n    m256 unpalo_ = _mm256_unpacklo_epi32(prod02_, prod13_);\n    m256\
    \ unpahi_ = _mm256_unpackhi_epi32(prod02_, prod13_);\n    m256 prod = _mm256_unpackhi_epi64(unpalo_,\
    \ unpahi_);\n    return _mm256_sub_epi32(hiplm1, prod);\n  }\n\n  static inline\
    \ mmint itom(const mmint& A) { return A * N2; }\n\n  static inline mmint mtoi(const\
    \ mmint& A) {\n    m256 A13 = _mm256_shuffle_epi32(A, 0xF5);\n    m256 lmlr02\
    \ = _mm256_mul_epu32(A, R);\n    m256 lmlr13 = _mm256_mul_epu32(A13, R);\n   \
    \ m256 prod02_ = _mm256_mul_epu32(lmlr02, M1);\n    m256 prod13_ = _mm256_mul_epu32(lmlr13,\
    \ M1);\n    m256 unpalo_ = _mm256_unpacklo_epi32(prod02_, prod13_);\n    m256\
    \ unpahi_ = _mm256_unpackhi_epi32(prod02_, prod13_);\n    m256 prod = _mm256_unpackhi_epi64(unpalo_,\
    \ unpahi_);\n    m256 cmp = _mm256_cmpgt_epi32(prod, M0);\n    m256 dif = _mm256_and_si256(cmp,\
    \ M1);\n    return _mm256_sub_epi32(dif, prod);\n  }\n\n  friend inline mmint\
    \ operator+(const mmint& A, const mmint& B) {\n    m256 apb = _mm256_add_epi32(A,\
    \ B);\n    m256 ret = _mm256_sub_epi32(apb, M2);\n    m256 cmp = _mm256_cmpgt_epi32(M0,\
    \ ret);\n    m256 add = _mm256_and_si256(cmp, M2);\n    return _mm256_add_epi32(add,\
    \ ret);\n  }\n\n  friend inline mmint operator-(const mmint& A, const mmint& B)\
    \ {\n    m256 ret = _mm256_sub_epi32(A, B);\n    m256 cmp = _mm256_cmpgt_epi32(M0,\
    \ ret);\n    m256 add = _mm256_and_si256(cmp, M2);\n    return _mm256_add_epi32(add,\
    \ ret);\n  }\n\n  friend inline mmint operator*(const mmint& A, const mmint& B)\
    \ {\n    m256 a13 = _mm256_shuffle_epi32(A, 0xF5);\n    m256 b13 = _mm256_shuffle_epi32(B,\
    \ 0xF5);\n    m256 prod02 = _mm256_mul_epu32(A, B);\n    m256 prod13 = _mm256_mul_epu32(a13,\
    \ b13);\n    return reduce(prod02, prod13);\n  }\n\n  inline mmint& operator+=(const\
    \ mmint& A) { return (*this) = (*this) + A; }\n  inline mmint& operator-=(const\
    \ mmint& A) { return (*this) = (*this) - A; }\n  inline mmint& operator*=(const\
    \ mmint& A) { return (*this) = (*this) * A; }\n\n  bool operator==(const mmint&\
    \ A) {\n    m256 sub = _mm256_sub_epi32(x, A.x);\n    return _mm256_testz_si256(sub,\
    \ sub) == 1;\n  }\n  bool operator!=(const mmint& A) { return !((*this) == A);\
    \ }\n};\n__attribute__((aligned(32))) mmint mmint::R;\n__attribute__((aligned(32)))\
    \ mmint mmint::M0, mmint::M1, mmint::M2, mmint::N2;\n\n/**\n * @brief vectorize\
    \ modint\n */\n"
  code: "#pragma once\n\n#pragma GCC optimize(\"O3,unroll-loops\")\n#pragma GCC target(\"\
    avx2\")\n\nusing m256 = __m256i;\nstruct alignas(32) mmint {\n  m256 x;\n  static\
    \ mmint R, M0, M1, M2, N2;\n\n  mmint() : x() {}\n  inline mmint(const m256& _x)\
    \ : x(_x) {}\n  inline mmint(unsigned int a) : x(_mm256_set1_epi32(a)) {}\n  inline\
    \ mmint(unsigned int a0, unsigned int a1, unsigned int a2,\n               unsigned\
    \ int a3, unsigned int a4, unsigned int a5,\n               unsigned int a6, unsigned\
    \ int a7)\n      : x(_mm256_set_epi32(a7, a6, a5, a4, a3, a2, a1, a0)) {}\n  inline\
    \ operator m256&() { return x; }\n  inline operator const m256&() const { return\
    \ x; }\n  inline int& operator[](int i) { return *(reinterpret_cast<int*>(&x)\
    \ + i); }\n  inline const int& operator[](int i) const {\n    return *(reinterpret_cast<const\
    \ int*>(&x) + i);\n  }\n\n  friend ostream& operator<<(ostream& os, const mmint&\
    \ m) {\n    unsigned r = R[0], mod = M1[0];\n    auto reduce1 = [&](const uint64_t&\
    \ b) {\n      unsigned res = (b + uint64_t(unsigned(b) * unsigned(-r)) * mod)\
    \ >> 32;\n      return res >= mod ? res - mod : res;\n    };\n    for (int i =\
    \ 0; i < 8; i++) {\n      os << reduce1(m[i]) << (i == 7 ? \"\" : \" \");\n  \
    \  }\n    return os;\n  }\n\n  template <typename mint>\n  static void set_mod()\
    \ {\n    R = _mm256_set1_epi32(mint::r);\n    M0 = _mm256_setzero_si256();\n \
    \   M1 = _mm256_set1_epi32(mint::get_mod());\n    M2 = _mm256_set1_epi32(mint::get_mod()\
    \ * 2);\n    N2 = _mm256_set1_epi32(mint::n2);\n  }\n\n  static inline mmint reduce(const\
    \ mmint& prod02, const mmint& prod13) {\n    m256 unpalo = _mm256_unpacklo_epi32(prod02,\
    \ prod13);\n    m256 unpahi = _mm256_unpackhi_epi32(prod02, prod13);\n    m256\
    \ prodlo = _mm256_unpacklo_epi64(unpalo, unpahi);\n    m256 prodhi = _mm256_unpackhi_epi64(unpalo,\
    \ unpahi);\n    m256 hiplm1 = _mm256_add_epi32(prodhi, M1);\n    m256 prodlohi\
    \ = _mm256_shuffle_epi32(prodlo, 0xF5);\n    m256 lmlr02 = _mm256_mul_epu32(prodlo,\
    \ R);\n    m256 lmlr13 = _mm256_mul_epu32(prodlohi, R);\n    m256 prod02_ = _mm256_mul_epu32(lmlr02,\
    \ M1);\n    m256 prod13_ = _mm256_mul_epu32(lmlr13, M1);\n    m256 unpalo_ = _mm256_unpacklo_epi32(prod02_,\
    \ prod13_);\n    m256 unpahi_ = _mm256_unpackhi_epi32(prod02_, prod13_);\n   \
    \ m256 prod = _mm256_unpackhi_epi64(unpalo_, unpahi_);\n    return _mm256_sub_epi32(hiplm1,\
    \ prod);\n  }\n\n  static inline mmint itom(const mmint& A) { return A * N2; }\n\
    \n  static inline mmint mtoi(const mmint& A) {\n    m256 A13 = _mm256_shuffle_epi32(A,\
    \ 0xF5);\n    m256 lmlr02 = _mm256_mul_epu32(A, R);\n    m256 lmlr13 = _mm256_mul_epu32(A13,\
    \ R);\n    m256 prod02_ = _mm256_mul_epu32(lmlr02, M1);\n    m256 prod13_ = _mm256_mul_epu32(lmlr13,\
    \ M1);\n    m256 unpalo_ = _mm256_unpacklo_epi32(prod02_, prod13_);\n    m256\
    \ unpahi_ = _mm256_unpackhi_epi32(prod02_, prod13_);\n    m256 prod = _mm256_unpackhi_epi64(unpalo_,\
    \ unpahi_);\n    m256 cmp = _mm256_cmpgt_epi32(prod, M0);\n    m256 dif = _mm256_and_si256(cmp,\
    \ M1);\n    return _mm256_sub_epi32(dif, prod);\n  }\n\n  friend inline mmint\
    \ operator+(const mmint& A, const mmint& B) {\n    m256 apb = _mm256_add_epi32(A,\
    \ B);\n    m256 ret = _mm256_sub_epi32(apb, M2);\n    m256 cmp = _mm256_cmpgt_epi32(M0,\
    \ ret);\n    m256 add = _mm256_and_si256(cmp, M2);\n    return _mm256_add_epi32(add,\
    \ ret);\n  }\n\n  friend inline mmint operator-(const mmint& A, const mmint& B)\
    \ {\n    m256 ret = _mm256_sub_epi32(A, B);\n    m256 cmp = _mm256_cmpgt_epi32(M0,\
    \ ret);\n    m256 add = _mm256_and_si256(cmp, M2);\n    return _mm256_add_epi32(add,\
    \ ret);\n  }\n\n  friend inline mmint operator*(const mmint& A, const mmint& B)\
    \ {\n    m256 a13 = _mm256_shuffle_epi32(A, 0xF5);\n    m256 b13 = _mm256_shuffle_epi32(B,\
    \ 0xF5);\n    m256 prod02 = _mm256_mul_epu32(A, B);\n    m256 prod13 = _mm256_mul_epu32(a13,\
    \ b13);\n    return reduce(prod02, prod13);\n  }\n\n  inline mmint& operator+=(const\
    \ mmint& A) { return (*this) = (*this) + A; }\n  inline mmint& operator-=(const\
    \ mmint& A) { return (*this) = (*this) - A; }\n  inline mmint& operator*=(const\
    \ mmint& A) { return (*this) = (*this) * A; }\n\n  bool operator==(const mmint&\
    \ A) {\n    m256 sub = _mm256_sub_epi32(x, A.x);\n    return _mm256_testz_si256(sub,\
    \ sub) == 1;\n  }\n  bool operator!=(const mmint& A) { return !((*this) == A);\
    \ }\n};\n__attribute__((aligned(32))) mmint mmint::R;\n__attribute__((aligned(32)))\
    \ mmint mmint::M0, mmint::M1, mmint::M2, mmint::N2;\n\n/**\n * @brief vectorize\
    \ modint\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: modint/vectorize-modint.hpp
  requiredBy:
  - math-fast/subset-convolution.hpp
  - math-fast/mat-prod-strassen.hpp
  timestamp: '2021-05-19 02:04:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-matrix-product-vectorize-modint.test.cpp
  - verify/verify-yosupo-math/yosupo-subset-convolution-fast.test.cpp
documentation_of: modint/vectorize-modint.hpp
layout: document
redirect_from:
- /library/modint/vectorize-modint.hpp
- /library/modint/vectorize-modint.hpp.html
title: vectorize modint
---
