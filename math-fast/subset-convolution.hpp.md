---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modint/vectorize-modint.hpp
    title: vectorize modint
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-subset-convolution-fast.test.cpp
    title: verify/verify-yosupo-math/yosupo-subset-convolution-fast.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math-fast/subset-convolution.hpp\"\n\n#line 2 \"modint/vectorize-modint.hpp\"\
    \n\n#pragma GCC optimize(\"O3,unroll-loops\")\n#pragma GCC target(\"avx2\")\n\n\
    using m256 = __m256i;\nstruct alignas(32) mmint {\n  m256 x;\n  static mmint R,\
    \ M0, M1, M2, N2;\n\n  mmint() : x() {}\n  inline mmint(const m256& _x) : x(_x)\
    \ {}\n  inline mmint(unsigned int a) : x(_mm256_set1_epi32(a)) {}\n  inline mmint(unsigned\
    \ int a0, unsigned int a1, unsigned int a2,\n               unsigned int a3, unsigned\
    \ int a4, unsigned int a5,\n               unsigned int a6, unsigned int a7)\n\
    \      : x(_mm256_set_epi32(a7, a6, a5, a4, a3, a2, a1, a0)) {}\n  inline operator\
    \ m256&() { return x; }\n  inline operator const m256&() const { return x; }\n\
    \  inline int& operator[](int i) { return *(reinterpret_cast<int*>(&x) + i); }\n\
    \  inline const int& operator[](int i) const {\n    return *(reinterpret_cast<const\
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
    \ modint\n */\n#line 4 \"math-fast/subset-convolution.hpp\"\n\ntemplate <typename\
    \ mint>\nvector<mint> fast_multiply(const vector<mint>& a, const vector<mint>&\
    \ b) {\n  int n = a.size();\n  int d = __builtin_ctz(n);\n  assert(d <= 23);\n\
    \  mmint* a1 = new mmint[max(n, 8) * 3];\n  mmint* a2 = new mmint[max(n, 8) *\
    \ 3];\n  memset((void*)a1, 0, max(n, 8) * 3 * sizeof(mmint));\n  memset((void*)a2,\
    \ 0, max(n, 8) * 3 * sizeof(mmint));\n  mmint b1[24], b2[24], b3[24];\n\n  for\
    \ (int i = 0; i < n; i++) {\n    unsigned int pc = __builtin_popcount(i);\n  \
    \  a1[i * 3 + pc / 8][pc % 8] = a[i].a;\n    a2[i * 3 + pc / 8][pc % 8] = b[i].a;\n\
    \  }\n\n  for (int j = 2; j <= n; j += 2) {\n    unsigned int pc = __builtin_popcount(j);\n\
    \    unsigned int ctz = __builtin_ctz(j);\n    for (int h = 0; h < d; h++) {\n\
    \      if (j & (1 << h)) break;\n      int li = j - 2 * (1 << h), ri = j - (1\
    \ << h);\n      if (pc + ctz <= 16) {\n        for (int i = 0; i < 3 * (1 << h);\
    \ i += 3) {\n          a1[ri * 3 + i + 0] += a1[li * 3 + i + 0];\n          a2[ri\
    \ * 3 + i + 0] += a2[li * 3 + i + 0];\n          a1[ri * 3 + i + 1] += a1[li *\
    \ 3 + i + 1];\n          a2[ri * 3 + i + 1] += a2[li * 3 + i + 1];\n        }\n\
    \      } else {\n        for (int i = 0; i < 3 * (1 << h); i++) {\n          a1[ri\
    \ * 3 + i] += a1[li * 3 + i];\n          a2[ri * 3 + i] += a2[li * 3 + i];\n \
    \       }\n      }\n    }\n  }\n\n  mmint th = _mm256_set1_epi64x(4LL * mmint::M1[0]\
    \ * mmint::M1[0]);\n\n  for (int is = 0; is < n; is += 8) {\n    int mpc = d;\n\
    \n    for (int i = is; i < is + 8; i++) {\n      int pc = __builtin_popcount(i);\n\
    \      mpc = min(mpc, pc);\n      for (int j = 0; j <= d; j++) {\n        b1[j][i\
    \ - is] = a1[i * 3 + j / 8][j % 8];\n        b2[j][i - is] = a2[i * 3 + j / 8][j\
    \ % 8];\n        b3[j][i - is] = 0;\n      }\n    }\n\n    for (int j = 0; j <=\
    \ d; j++) {\n      m256 cmpB1 = _mm256_cmpgt_epi32(mmint::M1, b1[j]);\n      m256\
    \ cmpB2 = _mm256_cmpgt_epi32(mmint::M1, b2[j]);\n      m256 difB1 = _mm256_andnot_si256(cmpB1,\
    \ mmint::M1);\n      m256 difB2 = _mm256_andnot_si256(cmpB2, mmint::M1);\n   \
    \   b1[j] = _mm256_sub_epi32(b1[j], difB1);\n      b2[j] = _mm256_sub_epi32(b2[j],\
    \ difB2);\n    }\n\n#define PROD(k)                                          \
    \   \\\n  m256 A13##k = _mm256_shuffle_epi32(b1[j + k], 0xF5);      \\\n  m256\
    \ B13##k = _mm256_shuffle_epi32(b2[l - j - k], 0xF5);  \\\n  m256 p02##k = _mm256_mul_epi32(b1[j\
    \ + k], b2[l - j - k]); \\\n  m256 p13##k = _mm256_mul_epi32(A13##k, B13##k);\
    \           \\\n  prod02 = _mm256_add_epi64(prod02, p02##k);                \\\
    \n  prod13 = _mm256_add_epi64(prod13, p13##k)\n#define COMP()                \
    \                   \\\n  do {                                           \\\n\
    \    m256 cmp02 = _mm256_cmpgt_epi64(prod02, th); \\\n    m256 cmp13 = _mm256_cmpgt_epi64(prod13,\
    \ th); \\\n    m256 dif02 = _mm256_and_si256(cmp02, th);    \\\n    m256 dif13\
    \ = _mm256_and_si256(cmp13, th);    \\\n    prod02 = _mm256_sub_epi64(prod02,\
    \ dif02);    \\\n    prod13 = _mm256_sub_epi64(prod13, dif13);    \\\n  } while\
    \ (0)\n\n    for (int l = mpc; l <= d; l++) {\n      int j = 0;\n      mmint prod02\
    \ = mmint::M0, prod13 = mmint::M0;\n\n      for (; j <= l - 3; j += 4) {\n   \
    \     PROD(0);\n        PROD(1);\n        PROD(2);\n        PROD(3);\n       \
    \ COMP();\n      }\n      for (; j <= l; j++) {\n        PROD(0);\n      }\n \
    \     COMP();\n      b3[l] = mmint::reduce(prod02, prod13);\n    }\n\n#undef PROD\n\
    #undef COMP\n\n    for (int i = is; i < is + 8; i++) {\n      for (unsigned j\
    \ = mpc; j <= unsigned(d); j++) {\n        a1[i * 3 + j / 8][j % 8] = b3[j][i\
    \ - is];\n      }\n    }\n  }\n\n  for (int j = 2; j <= n; j += 2) {\n    for\
    \ (int h = 0; h < d; h++) {\n      if (j & (1 << h)) break;\n      int li = j\
    \ - 2 * (1 << h), ri = j - (1 << h);\n      for (int i = 0; i < 3 * (1 << h);\
    \ i++) {\n        a1[ri * 3 + i] -= a1[li * 3 + i];\n      }\n    }\n  }\n\n \
    \ vector<mint> c(n);\n  for (int i = 0; i < n; i++) {\n    unsigned int pc = __builtin_popcount(i);\n\
    \    c[i].a = a1[i * 3 + pc / 8][pc % 8];\n  }\n\n  delete[](a1);\n  delete[](a2);\n\
    \  return c;\n}\n"
  code: "#pragma once\n\n#include \"../modint/vectorize-modint.hpp\"\n\ntemplate <typename\
    \ mint>\nvector<mint> fast_multiply(const vector<mint>& a, const vector<mint>&\
    \ b) {\n  int n = a.size();\n  int d = __builtin_ctz(n);\n  assert(d <= 23);\n\
    \  mmint* a1 = new mmint[max(n, 8) * 3];\n  mmint* a2 = new mmint[max(n, 8) *\
    \ 3];\n  memset((void*)a1, 0, max(n, 8) * 3 * sizeof(mmint));\n  memset((void*)a2,\
    \ 0, max(n, 8) * 3 * sizeof(mmint));\n  mmint b1[24], b2[24], b3[24];\n\n  for\
    \ (int i = 0; i < n; i++) {\n    unsigned int pc = __builtin_popcount(i);\n  \
    \  a1[i * 3 + pc / 8][pc % 8] = a[i].a;\n    a2[i * 3 + pc / 8][pc % 8] = b[i].a;\n\
    \  }\n\n  for (int j = 2; j <= n; j += 2) {\n    unsigned int pc = __builtin_popcount(j);\n\
    \    unsigned int ctz = __builtin_ctz(j);\n    for (int h = 0; h < d; h++) {\n\
    \      if (j & (1 << h)) break;\n      int li = j - 2 * (1 << h), ri = j - (1\
    \ << h);\n      if (pc + ctz <= 16) {\n        for (int i = 0; i < 3 * (1 << h);\
    \ i += 3) {\n          a1[ri * 3 + i + 0] += a1[li * 3 + i + 0];\n          a2[ri\
    \ * 3 + i + 0] += a2[li * 3 + i + 0];\n          a1[ri * 3 + i + 1] += a1[li *\
    \ 3 + i + 1];\n          a2[ri * 3 + i + 1] += a2[li * 3 + i + 1];\n        }\n\
    \      } else {\n        for (int i = 0; i < 3 * (1 << h); i++) {\n          a1[ri\
    \ * 3 + i] += a1[li * 3 + i];\n          a2[ri * 3 + i] += a2[li * 3 + i];\n \
    \       }\n      }\n    }\n  }\n\n  mmint th = _mm256_set1_epi64x(4LL * mmint::M1[0]\
    \ * mmint::M1[0]);\n\n  for (int is = 0; is < n; is += 8) {\n    int mpc = d;\n\
    \n    for (int i = is; i < is + 8; i++) {\n      int pc = __builtin_popcount(i);\n\
    \      mpc = min(mpc, pc);\n      for (int j = 0; j <= d; j++) {\n        b1[j][i\
    \ - is] = a1[i * 3 + j / 8][j % 8];\n        b2[j][i - is] = a2[i * 3 + j / 8][j\
    \ % 8];\n        b3[j][i - is] = 0;\n      }\n    }\n\n    for (int j = 0; j <=\
    \ d; j++) {\n      m256 cmpB1 = _mm256_cmpgt_epi32(mmint::M1, b1[j]);\n      m256\
    \ cmpB2 = _mm256_cmpgt_epi32(mmint::M1, b2[j]);\n      m256 difB1 = _mm256_andnot_si256(cmpB1,\
    \ mmint::M1);\n      m256 difB2 = _mm256_andnot_si256(cmpB2, mmint::M1);\n   \
    \   b1[j] = _mm256_sub_epi32(b1[j], difB1);\n      b2[j] = _mm256_sub_epi32(b2[j],\
    \ difB2);\n    }\n\n#define PROD(k)                                          \
    \   \\\n  m256 A13##k = _mm256_shuffle_epi32(b1[j + k], 0xF5);      \\\n  m256\
    \ B13##k = _mm256_shuffle_epi32(b2[l - j - k], 0xF5);  \\\n  m256 p02##k = _mm256_mul_epi32(b1[j\
    \ + k], b2[l - j - k]); \\\n  m256 p13##k = _mm256_mul_epi32(A13##k, B13##k);\
    \           \\\n  prod02 = _mm256_add_epi64(prod02, p02##k);                \\\
    \n  prod13 = _mm256_add_epi64(prod13, p13##k)\n#define COMP()                \
    \                   \\\n  do {                                           \\\n\
    \    m256 cmp02 = _mm256_cmpgt_epi64(prod02, th); \\\n    m256 cmp13 = _mm256_cmpgt_epi64(prod13,\
    \ th); \\\n    m256 dif02 = _mm256_and_si256(cmp02, th);    \\\n    m256 dif13\
    \ = _mm256_and_si256(cmp13, th);    \\\n    prod02 = _mm256_sub_epi64(prod02,\
    \ dif02);    \\\n    prod13 = _mm256_sub_epi64(prod13, dif13);    \\\n  } while\
    \ (0)\n\n    for (int l = mpc; l <= d; l++) {\n      int j = 0;\n      mmint prod02\
    \ = mmint::M0, prod13 = mmint::M0;\n\n      for (; j <= l - 3; j += 4) {\n   \
    \     PROD(0);\n        PROD(1);\n        PROD(2);\n        PROD(3);\n       \
    \ COMP();\n      }\n      for (; j <= l; j++) {\n        PROD(0);\n      }\n \
    \     COMP();\n      b3[l] = mmint::reduce(prod02, prod13);\n    }\n\n#undef PROD\n\
    #undef COMP\n\n    for (int i = is; i < is + 8; i++) {\n      for (unsigned j\
    \ = mpc; j <= unsigned(d); j++) {\n        a1[i * 3 + j / 8][j % 8] = b3[j][i\
    \ - is];\n      }\n    }\n  }\n\n  for (int j = 2; j <= n; j += 2) {\n    for\
    \ (int h = 0; h < d; h++) {\n      if (j & (1 << h)) break;\n      int li = j\
    \ - 2 * (1 << h), ri = j - (1 << h);\n      for (int i = 0; i < 3 * (1 << h);\
    \ i++) {\n        a1[ri * 3 + i] -= a1[li * 3 + i];\n      }\n    }\n  }\n\n \
    \ vector<mint> c(n);\n  for (int i = 0; i < n; i++) {\n    unsigned int pc = __builtin_popcount(i);\n\
    \    c[i].a = a1[i * 3 + pc / 8][pc % 8];\n  }\n\n  delete[](a1);\n  delete[](a2);\n\
    \  return c;\n}\n"
  dependsOn:
  - modint/vectorize-modint.hpp
  isVerificationFile: false
  path: math-fast/subset-convolution.hpp
  requiredBy: []
  timestamp: '2021-05-19 02:04:33+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-subset-convolution-fast.test.cpp
documentation_of: math-fast/subset-convolution.hpp
layout: document
redirect_from:
- /library/math-fast/subset-convolution.hpp
- /library/math-fast/subset-convolution.hpp.html
title: math-fast/subset-convolution.hpp
---
