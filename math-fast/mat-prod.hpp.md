---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modint/vectorize-modint.hpp
    title: vectorize modint
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-matrix-product-vectorize-modint.test.cpp
    title: verify/verify-yosupo-math/yosupo-matrix-product-vectorize-modint.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"math-fast/mat-prod.hpp\"\n\n#line 2 \"modint/vectorize-modint.hpp\"\
    \n\n#pragma GCC optimize(\"O3,unroll-loops\")\n#pragma GCC target(\"avx2\")\n\n\
    using m256 = __m256i;\nstruct alignas(32) mmint {\n  m256 x;\n  static m256 R,\
    \ mR, M0, M1, M2, N2;\n\n  mmint() : x() {}\n  inline mmint(const m256& _x) :\
    \ x(_x) {}\n  inline mmint(int a) : x(_mm256_set1_epi32(a)) {}\n  inline mmint(int\
    \ a0, int a1, int a2, int a3, int a4, int a5, int a6, int a7)\n      : x(_mm256_set_epi32(a7,\
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
    \    mR = _mm256_sub_epi32(M0, R);\n  }\n\n  static inline mmint reduce(const\
    \ mmint& prod02, const mmint& prod13) {\n    m256 unpalo = _mm256_unpacklo_epi32(prod02,\
    \ prod13);\n    m256 unpahi = _mm256_unpackhi_epi32(prod02, prod13);\n    m256\
    \ prodlo = _mm256_unpacklo_epi64(unpalo, unpahi);\n    m256 prodhi = _mm256_unpackhi_epi64(unpalo,\
    \ unpahi);\n    m256 hiplm1 = _mm256_add_epi32(prodhi, M1);\n    m256 lomulr =\
    \ _mm256_mullo_epi32(prodlo, R);\n    m256 a13 = _mm256_shuffle_epi32(lomulr,\
    \ 0xF5);\n    m256 prod02_ = _mm256_mul_epu32(lomulr, M1);\n    m256 prod13_ =\
    \ _mm256_mul_epu32(a13, M1);\n    m256 unpalo_ = _mm256_unpacklo_epi32(prod02_,\
    \ prod13_);\n    m256 unpahi_ = _mm256_unpackhi_epi32(prod02_, prod13_);\n   \
    \ m256 prod = _mm256_unpackhi_epi64(unpalo_, unpahi_);\n    return _mm256_sub_epi32(hiplm1,\
    \ prod);\n  }\n\n  static inline mmint itom(const mmint& A) { return A * N2; }\n\
    \n  static inline mmint mtoi(const mmint& A) {\n    m256 lomulr = _mm256_mullo_epi32(A,\
    \ mR);\n    m256 a13 = _mm256_shuffle_epi32(lomulr, 0xF5);\n    m256 prod02_ =\
    \ _mm256_mul_epu32(lomulr, M1);\n    m256 prod13_ = _mm256_mul_epu32(a13, M1);\n\
    \    m256 unpalo_ = _mm256_unpacklo_epi32(prod02_, prod13_);\n    m256 unpahi_\
    \ = _mm256_unpackhi_epi32(prod02_, prod13_);\n    m256 prod = _mm256_unpackhi_epi64(unpalo_,\
    \ unpahi_);\n    m256 cmpA = _mm256_cmpgt_epi32(A, M0);\n    m256 addA = _mm256_and_si256(cmpA,\
    \ mmint(1));\n    return _mm256_add_epi32(prod, addA);\n  }\n\n  friend inline\
    \ mmint operator+(const mmint& A, const mmint& B) {\n    m256 apb = _mm256_add_epi32(A,\
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
    \ }\n};\n__attribute__((aligned(32))) __m256i mmint::R, mmint::mR;\n__attribute__((aligned(32)))\
    \ __m256i mmint::M0, mmint::M1, mmint::M2, mmint::N2;\n\n/**\n * @brief vectorize\
    \ modint\n */\n#line 4 \"math-fast/mat-prod.hpp\"\n\n// B*B\u306E\u6B63\u65B9\u884C\
    \u5217\u3092\u9AD8\u901F\u306B\u4E57\u7B97\u3059\u308B\u30E9\u30A4\u30D6\u30E9\
    \u30EA\u3002\n// B*B\u884C\u5217a,b\u3092 \u30BF\u30C6B\u884C \u30E8\u30B3B/8\u884C\
    \u306E\u884C\u5217\u3068\u898B\u306A\u3059.\n// s : \u6B63\u9806\u306B\u914D\u7F6E\
    \u3002\u3059\u306A\u308F\u3061a_{i,k}\u3092s[i * (B / 8) + k]\u306B\u914D\u7F6E\
    \u3059\u308B\u3002\n// t : \u9006\u9806\u306B\u914D\u7F6E\u3002\u3059\u306A\u308F\
    \u3061b_{k,j}\u3092t[j * B + k]\u306B\u914D\u7F6E\u3059\u308B\u3002\n// u : \u6B63\
    \u9806\u306B\u914D\u7F6E\u3002\u3059\u306A\u308F\u3061c_{i,j}\u3092u[i * (B /\
    \ 8) + j]\u306B\u914D\u7F6E\u3059\u308B\u3002\nnamespace fast_mat_prod_impl {\n\
    constexpr int B = 1 << 7;\nconstexpr int B8 = B / 8;\n\nvoid mul_simd(mmint* __restrict__\
    \ s, mmint* __restrict__ t,\n              mmint* __restrict__ u) {\n  for (int\
    \ i = 0; i < B * B8; i++) {\n    const m256 cmpS = _mm256_cmpgt_epi32(s[i], mmint::M1);\n\
    \    const m256 cmpT = _mm256_cmpgt_epi32(t[i], mmint::M1);\n    const m256 difS\
    \ = _mm256_and_si256(cmpS, mmint::M1);\n    const m256 difT = _mm256_and_si256(cmpT,\
    \ mmint::M1);\n    s[i] = _mm256_sub_epi32(s[i], difS);\n    t[i] = _mm256_sub_epi32(t[i],\
    \ difT);\n  }\n\n  mmint th1, th2, zero = _mm256_setzero_si256();\n  th1[1] =\
    \ th1[3] = th1[5] = th1[7] = mmint::M1[0];\n  th2[1] = th2[3] = th2[5] = th2[7]\
    \ = mmint::M2[0];\n\n#define INIT_X(x, y)                          \\\n  m256\
    \ prod02##x##y = _mm256_setzero_si256(); \\\n  m256 prod13##x##y = _mm256_setzero_si256()\n\
    \n#define INIT_Y(j, k, l, y)            \\\n  m256 T##y = t[(j + y) * B + k +\
    \ l]; \\\n  const m256 T13##y = _mm256_shuffle_epi32(T##y, 0xF5);\n\n#define PROD(x,\
    \ y)                                              \\\n  m256 S##x##y = _mm256_set1_epi32(s[(i\
    \ + x) * B8 + k / 8][l]); \\\n  const m256 ST02##x##y = _mm256_mul_epu32(S##x##y,\
    \ T##y);      \\\n  const m256 ST13##x##y = _mm256_mul_epu32(S##x##y, T13##y);\
    \    \\\n  prod02##x##y = _mm256_add_epi64(prod02##x##y, ST02##x##y);    \\\n\
    \  prod13##x##y = _mm256_add_epi64(prod13##x##y, ST13##x##y)\n\n#define COMP(x,\
    \ y)                                            \\\n  m256 cmp02##x##y = _mm256_cmpgt_epi64(zero,\
    \ prod02##x##y);  \\\n  m256 cmp13##x##y = _mm256_cmpgt_epi64(zero, prod13##x##y);\
    \  \\\n  m256 dif02##x##y = _mm256_and_si256(cmp02##x##y, th2);      \\\n  m256\
    \ dif13##x##y = _mm256_and_si256(cmp13##x##y, th2);      \\\n  prod02##x##y =\
    \ _mm256_sub_epi64(prod02##x##y, dif02##x##y); \\\n  prod13##x##y = _mm256_sub_epi64(prod13##x##y,\
    \ dif13##x##y)\n\n#define REDUCE(x, y)                                      \\\
    \n  for (int _ = 0; _ < 2; _++) {                           \\\n    m256 cmp02\
    \ = _mm256_cmpgt_epi64(prod02##x##y, th1);   \\\n    m256 cmp13 = _mm256_cmpgt_epi64(prod13##x##y,\
    \ th1);   \\\n    m256 dif02 = _mm256_and_si256(cmp02, th1);            \\\n \
    \   m256 dif13 = _mm256_and_si256(cmp13, th1);            \\\n    prod02##x##y\
    \ = _mm256_sub_epi64(prod02##x##y, dif02); \\\n    prod13##x##y = _mm256_sub_epi64(prod13##x##y,\
    \ dif13); \\\n  }                                                       \\\n \
    \ u[(i + x) * B8 + j + y] = mmint::reduce(prod02##x##y, prod13##x##y)\n\n  for\
    \ (int i = 0; i < B; i += 8) {\n    for (int j = 0; j < B8; j += 1) {\n      INIT_X(0,\
    \ 0);\n      INIT_X(1, 0);\n      INIT_X(2, 0);\n      INIT_X(3, 0);\n      INIT_X(4,\
    \ 0);\n      INIT_X(5, 0);\n      INIT_X(6, 0);\n      INIT_X(7, 0);\n      for\
    \ (int k = 0; k < B; k += 8) {\n        for (int l = 0; l < 8; l++) {\n      \
    \    INIT_Y(j, k, l, 0);\n          PROD(0, 0);\n          PROD(1, 0);\n     \
    \     PROD(2, 0);\n          PROD(3, 0);\n          PROD(4, 0);\n          PROD(5,\
    \ 0);\n          PROD(6, 0);\n          PROD(7, 0);\n        }\n        COMP(0,\
    \ 0);\n        COMP(1, 0);\n        COMP(2, 0);\n        COMP(3, 0);\n       \
    \ COMP(4, 0);\n        COMP(5, 0);\n        COMP(6, 0);\n        COMP(7, 0);\n\
    \      }\n      REDUCE(0, 0);\n      REDUCE(1, 0);\n      REDUCE(2, 0);\n    \
    \  REDUCE(3, 0);\n      REDUCE(4, 0);\n      REDUCE(5, 0);\n      REDUCE(6, 0);\n\
    \      REDUCE(7, 0);\n    }\n  }\n}\n\n#undef INIT\n#undef PROD\n#undef COMP\n\
    #undef REDUCE\n\nvoid strassen(int N, mmint* __restrict__ s, mmint* __restrict__\
    \ t,\n              mmint* __restrict__ u) {\n  for (int i = 0; i < N * N / 8;\
    \ i++) u[i] = mmint::M0;\n\n  if (N == B) {\n    mul_simd(s, t, u);\n    return;\n\
    \  }\n\n  mmint* ps = s + N * N / 8;\n  mmint* pt = t + N * N / 8;\n  mmint* pu\
    \ = u + N * N / 8;\n  int nx = N * N / 32;\n  int o11 = nx * 0, o12 = nx * 1,\
    \ o21 = nx * 2, o22 = nx * 3;\n\n  // P1\n  for (int i = 0; i < nx; i++) ps[i]\
    \ = s[o11 + i] + s[o22 + i];\n  for (int i = 0; i < nx; i++) pt[i] = t[o11 + i]\
    \ + t[o22 + i];\n  strassen(N / 2, ps, pt, pu);\n  for (int i = 0; i < nx; i++)\
    \ u[o11 + i] = pu[i], u[o22 + i] = pu[i];\n\n  // P2\n  for (int i = 0; i < nx;\
    \ i++) ps[i] = s[o21 + i] + s[o22 + i];\n  for (int i = 0; i < nx; i++) pt[i]\
    \ = t[o11 + i];\n  strassen(N / 2, ps, pt, pu);\n  for (int i = 0; i < nx; i++)\
    \ u[o21 + i] = pu[i], u[o22 + i] -= pu[i];\n\n  // P3\n  for (int i = 0; i < nx;\
    \ i++) ps[i] = s[o11 + i];\n  for (int i = 0; i < nx; i++) pt[i] = t[o12 + i]\
    \ - t[o22 + i];\n  strassen(N / 2, ps, pt, pu);\n  for (int i = 0; i < nx; i++)\
    \ u[o12 + i] = pu[i], u[o22 + i] += pu[i];\n\n  // P4\n  for (int i = 0; i < nx;\
    \ i++) ps[i] = s[o22 + i];\n  for (int i = 0; i < nx; i++) pt[i] = t[o21 + i]\
    \ - t[o11 + i];\n  strassen(N / 2, ps, pt, pu);\n  for (int i = 0; i < nx; i++)\
    \ u[o11 + i] += pu[i], u[o21 + i] += pu[i];\n\n  // P5\n  for (int i = 0; i <\
    \ nx; i++) ps[i] = s[o11 + i] + s[o12 + i];\n  for (int i = 0; i < nx; i++) pt[i]\
    \ = t[o22 + i];\n  strassen(N / 2, ps, pt, pu);\n  for (int i = 0; i < nx; i++)\
    \ u[o11 + i] -= pu[i], u[o12 + i] += pu[i];\n\n  // P6\n  for (int i = 0; i <\
    \ nx; i++) ps[i] = s[o21 + i] - s[o11 + i];\n  for (int i = 0; i < nx; i++) pt[i]\
    \ = t[o11 + i] + t[o12 + i];\n  strassen(N / 2, ps, pt, pu);\n  for (int i = 0;\
    \ i < nx; i++) u[o22 + i] += pu[i];\n\n  // P7\n  for (int i = 0; i < nx; i++)\
    \ ps[i] = s[o12 + i] - s[o22 + i];\n  for (int i = 0; i < nx; i++) pt[i] = t[o21\
    \ + i] + t[o22 + i];\n  strassen(N / 2, ps, pt, pu);\n  for (int i = 0; i < nx;\
    \ i++) u[o11 + i] += pu[i];\n}\n\nconstexpr int S = 1024;\nconstexpr int S8 =\
    \ S / 8;\nmmint s[S * S8 * 3 / 2], t[S * S8 * 3 / 2], u[S * S8 * 3 / 2];\n\nvoid\
    \ place_s(int N, int a, int b, mmint* __restrict__ dst,\n             mmint* __restrict__\
    \ src) {\n  if (N == B) {\n    for (int i = 0; i < B; i++) {\n      memcpy(dst\
    \ + i * B8, src + (a + i) * S8 + b / 8, B8 * sizeof(mmint));\n    }\n    return;\n\
    \  }\n  int nx = N * N / 32, M = N / 2;\n  place_s(M, a + 0, b + 0, dst + nx *\
    \ 0, src);\n  place_s(M, a + 0, b + M, dst + nx * 1, src);\n  place_s(M, a + M,\
    \ b + 0, dst + nx * 2, src);\n  place_s(M, a + M, b + M, dst + nx * 3, src);\n\
    }\n\nvoid place_t(int N, int a, int b, mmint* __restrict__ dst,\n            \
    \ mmint* __restrict__ src) {\n  if (N == B) {\n    // t : \u9006\u9806\u306B\u914D\
    \u7F6E\u3002\u3059\u306A\u308F\u3061b_{k,j}\u3092t[j * B + k]\u306B\u914D\u7F6E\
    \u3059\u308B\u3002\n    for (int k = 0; k < B; k++) {\n      for (int j = 0; j\
    \ < B8; j++) {\n        dst[j * B + k] = src[(a + k) * S8 + j + b / 8];\n    \
    \  }\n    }\n    return;\n  }\n  int nx = N * N / 32, M = N / 2;\n  place_t(M,\
    \ a + 0, b + 0, dst + nx * 0, src);\n  place_t(M, a + 0, b + M, dst + nx * 1,\
    \ src);\n  place_t(M, a + M, b + 0, dst + nx * 2, src);\n  place_t(M, a + M, b\
    \ + M, dst + nx * 3, src);\n}\n\nvoid place_rev(int N, int a, int b, mmint* __restrict__\
    \ dst,\n               mmint* __restrict__ src) {\n  if (N == B) {\n    for (int\
    \ i = 0; i < B; i++) {\n      memcpy(src + (a + i) * S8 + b / 8, dst + i * B8,\
    \ B8 * sizeof(mmint));\n    }\n    return;\n  }\n  int nx = N * N / 32, M = N\
    \ / 2;\n  place_rev(M, a + 0, b + 0, dst + nx * 0, src);\n  place_rev(M, a + 0,\
    \ b + M, dst + nx * 1, src);\n  place_rev(M, a + M, b + 0, dst + nx * 2, src);\n\
    \  place_rev(M, a + M, b + M, dst + nx * 3, src);\n}\n\nvoid prod(unsigned int*\
    \ __restrict__ a, unsigned int* __restrict__ b,\n          unsigned int* __restrict__\
    \ c) {\n  place_s(S, 0, 0, s, reinterpret_cast<mmint*>(a));\n  place_t(S, 0, 0,\
    \ t, reinterpret_cast<mmint*>(b));\n  for (int i = 0; i < S * S8; i++) s[i] =\
    \ mmint::itom(s[i]);\n  for (int i = 0; i < S * S8; i++) t[i] = mmint::itom(t[i]);\n\
    \  strassen(S, s, t, u);\n  for (int i = 0; i < S * S8; i++) u[i] = mmint::mtoi(u[i]);\n\
    \  place_rev(S, 0, 0, u, reinterpret_cast<mmint*>(c));\n}\n\n}  // namespace fast_mat_prod_impl\n"
  code: "#pragma once\n\n#include \"../modint/vectorize-modint.hpp\"\n\n// B*B\u306E\
    \u6B63\u65B9\u884C\u5217\u3092\u9AD8\u901F\u306B\u4E57\u7B97\u3059\u308B\u30E9\
    \u30A4\u30D6\u30E9\u30EA\u3002\n// B*B\u884C\u5217a,b\u3092 \u30BF\u30C6B\u884C\
    \ \u30E8\u30B3B/8\u884C\u306E\u884C\u5217\u3068\u898B\u306A\u3059.\n// s : \u6B63\
    \u9806\u306B\u914D\u7F6E\u3002\u3059\u306A\u308F\u3061a_{i,k}\u3092s[i * (B /\
    \ 8) + k]\u306B\u914D\u7F6E\u3059\u308B\u3002\n// t : \u9006\u9806\u306B\u914D\
    \u7F6E\u3002\u3059\u306A\u308F\u3061b_{k,j}\u3092t[j * B + k]\u306B\u914D\u7F6E\
    \u3059\u308B\u3002\n// u : \u6B63\u9806\u306B\u914D\u7F6E\u3002\u3059\u306A\u308F\
    \u3061c_{i,j}\u3092u[i * (B / 8) + j]\u306B\u914D\u7F6E\u3059\u308B\u3002\nnamespace\
    \ fast_mat_prod_impl {\nconstexpr int B = 1 << 7;\nconstexpr int B8 = B / 8;\n\
    \nvoid mul_simd(mmint* __restrict__ s, mmint* __restrict__ t,\n              mmint*\
    \ __restrict__ u) {\n  for (int i = 0; i < B * B8; i++) {\n    const m256 cmpS\
    \ = _mm256_cmpgt_epi32(s[i], mmint::M1);\n    const m256 cmpT = _mm256_cmpgt_epi32(t[i],\
    \ mmint::M1);\n    const m256 difS = _mm256_and_si256(cmpS, mmint::M1);\n    const\
    \ m256 difT = _mm256_and_si256(cmpT, mmint::M1);\n    s[i] = _mm256_sub_epi32(s[i],\
    \ difS);\n    t[i] = _mm256_sub_epi32(t[i], difT);\n  }\n\n  mmint th1, th2, zero\
    \ = _mm256_setzero_si256();\n  th1[1] = th1[3] = th1[5] = th1[7] = mmint::M1[0];\n\
    \  th2[1] = th2[3] = th2[5] = th2[7] = mmint::M2[0];\n\n#define INIT_X(x, y) \
    \                         \\\n  m256 prod02##x##y = _mm256_setzero_si256(); \\\
    \n  m256 prod13##x##y = _mm256_setzero_si256()\n\n#define INIT_Y(j, k, l, y) \
    \           \\\n  m256 T##y = t[(j + y) * B + k + l]; \\\n  const m256 T13##y\
    \ = _mm256_shuffle_epi32(T##y, 0xF5);\n\n#define PROD(x, y)                  \
    \                            \\\n  m256 S##x##y = _mm256_set1_epi32(s[(i + x)\
    \ * B8 + k / 8][l]); \\\n  const m256 ST02##x##y = _mm256_mul_epu32(S##x##y, T##y);\
    \      \\\n  const m256 ST13##x##y = _mm256_mul_epu32(S##x##y, T13##y);    \\\n\
    \  prod02##x##y = _mm256_add_epi64(prod02##x##y, ST02##x##y);    \\\n  prod13##x##y\
    \ = _mm256_add_epi64(prod13##x##y, ST13##x##y)\n\n#define COMP(x, y)         \
    \                                   \\\n  m256 cmp02##x##y = _mm256_cmpgt_epi64(zero,\
    \ prod02##x##y);  \\\n  m256 cmp13##x##y = _mm256_cmpgt_epi64(zero, prod13##x##y);\
    \  \\\n  m256 dif02##x##y = _mm256_and_si256(cmp02##x##y, th2);      \\\n  m256\
    \ dif13##x##y = _mm256_and_si256(cmp13##x##y, th2);      \\\n  prod02##x##y =\
    \ _mm256_sub_epi64(prod02##x##y, dif02##x##y); \\\n  prod13##x##y = _mm256_sub_epi64(prod13##x##y,\
    \ dif13##x##y)\n\n#define REDUCE(x, y)                                      \\\
    \n  for (int _ = 0; _ < 2; _++) {                           \\\n    m256 cmp02\
    \ = _mm256_cmpgt_epi64(prod02##x##y, th1);   \\\n    m256 cmp13 = _mm256_cmpgt_epi64(prod13##x##y,\
    \ th1);   \\\n    m256 dif02 = _mm256_and_si256(cmp02, th1);            \\\n \
    \   m256 dif13 = _mm256_and_si256(cmp13, th1);            \\\n    prod02##x##y\
    \ = _mm256_sub_epi64(prod02##x##y, dif02); \\\n    prod13##x##y = _mm256_sub_epi64(prod13##x##y,\
    \ dif13); \\\n  }                                                       \\\n \
    \ u[(i + x) * B8 + j + y] = mmint::reduce(prod02##x##y, prod13##x##y)\n\n  for\
    \ (int i = 0; i < B; i += 8) {\n    for (int j = 0; j < B8; j += 1) {\n      INIT_X(0,\
    \ 0);\n      INIT_X(1, 0);\n      INIT_X(2, 0);\n      INIT_X(3, 0);\n      INIT_X(4,\
    \ 0);\n      INIT_X(5, 0);\n      INIT_X(6, 0);\n      INIT_X(7, 0);\n      for\
    \ (int k = 0; k < B; k += 8) {\n        for (int l = 0; l < 8; l++) {\n      \
    \    INIT_Y(j, k, l, 0);\n          PROD(0, 0);\n          PROD(1, 0);\n     \
    \     PROD(2, 0);\n          PROD(3, 0);\n          PROD(4, 0);\n          PROD(5,\
    \ 0);\n          PROD(6, 0);\n          PROD(7, 0);\n        }\n        COMP(0,\
    \ 0);\n        COMP(1, 0);\n        COMP(2, 0);\n        COMP(3, 0);\n       \
    \ COMP(4, 0);\n        COMP(5, 0);\n        COMP(6, 0);\n        COMP(7, 0);\n\
    \      }\n      REDUCE(0, 0);\n      REDUCE(1, 0);\n      REDUCE(2, 0);\n    \
    \  REDUCE(3, 0);\n      REDUCE(4, 0);\n      REDUCE(5, 0);\n      REDUCE(6, 0);\n\
    \      REDUCE(7, 0);\n    }\n  }\n}\n\n#undef INIT\n#undef PROD\n#undef COMP\n\
    #undef REDUCE\n\nvoid strassen(int N, mmint* __restrict__ s, mmint* __restrict__\
    \ t,\n              mmint* __restrict__ u) {\n  for (int i = 0; i < N * N / 8;\
    \ i++) u[i] = mmint::M0;\n\n  if (N == B) {\n    mul_simd(s, t, u);\n    return;\n\
    \  }\n\n  mmint* ps = s + N * N / 8;\n  mmint* pt = t + N * N / 8;\n  mmint* pu\
    \ = u + N * N / 8;\n  int nx = N * N / 32;\n  int o11 = nx * 0, o12 = nx * 1,\
    \ o21 = nx * 2, o22 = nx * 3;\n\n  // P1\n  for (int i = 0; i < nx; i++) ps[i]\
    \ = s[o11 + i] + s[o22 + i];\n  for (int i = 0; i < nx; i++) pt[i] = t[o11 + i]\
    \ + t[o22 + i];\n  strassen(N / 2, ps, pt, pu);\n  for (int i = 0; i < nx; i++)\
    \ u[o11 + i] = pu[i], u[o22 + i] = pu[i];\n\n  // P2\n  for (int i = 0; i < nx;\
    \ i++) ps[i] = s[o21 + i] + s[o22 + i];\n  for (int i = 0; i < nx; i++) pt[i]\
    \ = t[o11 + i];\n  strassen(N / 2, ps, pt, pu);\n  for (int i = 0; i < nx; i++)\
    \ u[o21 + i] = pu[i], u[o22 + i] -= pu[i];\n\n  // P3\n  for (int i = 0; i < nx;\
    \ i++) ps[i] = s[o11 + i];\n  for (int i = 0; i < nx; i++) pt[i] = t[o12 + i]\
    \ - t[o22 + i];\n  strassen(N / 2, ps, pt, pu);\n  for (int i = 0; i < nx; i++)\
    \ u[o12 + i] = pu[i], u[o22 + i] += pu[i];\n\n  // P4\n  for (int i = 0; i < nx;\
    \ i++) ps[i] = s[o22 + i];\n  for (int i = 0; i < nx; i++) pt[i] = t[o21 + i]\
    \ - t[o11 + i];\n  strassen(N / 2, ps, pt, pu);\n  for (int i = 0; i < nx; i++)\
    \ u[o11 + i] += pu[i], u[o21 + i] += pu[i];\n\n  // P5\n  for (int i = 0; i <\
    \ nx; i++) ps[i] = s[o11 + i] + s[o12 + i];\n  for (int i = 0; i < nx; i++) pt[i]\
    \ = t[o22 + i];\n  strassen(N / 2, ps, pt, pu);\n  for (int i = 0; i < nx; i++)\
    \ u[o11 + i] -= pu[i], u[o12 + i] += pu[i];\n\n  // P6\n  for (int i = 0; i <\
    \ nx; i++) ps[i] = s[o21 + i] - s[o11 + i];\n  for (int i = 0; i < nx; i++) pt[i]\
    \ = t[o11 + i] + t[o12 + i];\n  strassen(N / 2, ps, pt, pu);\n  for (int i = 0;\
    \ i < nx; i++) u[o22 + i] += pu[i];\n\n  // P7\n  for (int i = 0; i < nx; i++)\
    \ ps[i] = s[o12 + i] - s[o22 + i];\n  for (int i = 0; i < nx; i++) pt[i] = t[o21\
    \ + i] + t[o22 + i];\n  strassen(N / 2, ps, pt, pu);\n  for (int i = 0; i < nx;\
    \ i++) u[o11 + i] += pu[i];\n}\n\nconstexpr int S = 1024;\nconstexpr int S8 =\
    \ S / 8;\nmmint s[S * S8 * 3 / 2], t[S * S8 * 3 / 2], u[S * S8 * 3 / 2];\n\nvoid\
    \ place_s(int N, int a, int b, mmint* __restrict__ dst,\n             mmint* __restrict__\
    \ src) {\n  if (N == B) {\n    for (int i = 0; i < B; i++) {\n      memcpy(dst\
    \ + i * B8, src + (a + i) * S8 + b / 8, B8 * sizeof(mmint));\n    }\n    return;\n\
    \  }\n  int nx = N * N / 32, M = N / 2;\n  place_s(M, a + 0, b + 0, dst + nx *\
    \ 0, src);\n  place_s(M, a + 0, b + M, dst + nx * 1, src);\n  place_s(M, a + M,\
    \ b + 0, dst + nx * 2, src);\n  place_s(M, a + M, b + M, dst + nx * 3, src);\n\
    }\n\nvoid place_t(int N, int a, int b, mmint* __restrict__ dst,\n            \
    \ mmint* __restrict__ src) {\n  if (N == B) {\n    // t : \u9006\u9806\u306B\u914D\
    \u7F6E\u3002\u3059\u306A\u308F\u3061b_{k,j}\u3092t[j * B + k]\u306B\u914D\u7F6E\
    \u3059\u308B\u3002\n    for (int k = 0; k < B; k++) {\n      for (int j = 0; j\
    \ < B8; j++) {\n        dst[j * B + k] = src[(a + k) * S8 + j + b / 8];\n    \
    \  }\n    }\n    return;\n  }\n  int nx = N * N / 32, M = N / 2;\n  place_t(M,\
    \ a + 0, b + 0, dst + nx * 0, src);\n  place_t(M, a + 0, b + M, dst + nx * 1,\
    \ src);\n  place_t(M, a + M, b + 0, dst + nx * 2, src);\n  place_t(M, a + M, b\
    \ + M, dst + nx * 3, src);\n}\n\nvoid place_rev(int N, int a, int b, mmint* __restrict__\
    \ dst,\n               mmint* __restrict__ src) {\n  if (N == B) {\n    for (int\
    \ i = 0; i < B; i++) {\n      memcpy(src + (a + i) * S8 + b / 8, dst + i * B8,\
    \ B8 * sizeof(mmint));\n    }\n    return;\n  }\n  int nx = N * N / 32, M = N\
    \ / 2;\n  place_rev(M, a + 0, b + 0, dst + nx * 0, src);\n  place_rev(M, a + 0,\
    \ b + M, dst + nx * 1, src);\n  place_rev(M, a + M, b + 0, dst + nx * 2, src);\n\
    \  place_rev(M, a + M, b + M, dst + nx * 3, src);\n}\n\nvoid prod(unsigned int*\
    \ __restrict__ a, unsigned int* __restrict__ b,\n          unsigned int* __restrict__\
    \ c) {\n  place_s(S, 0, 0, s, reinterpret_cast<mmint*>(a));\n  place_t(S, 0, 0,\
    \ t, reinterpret_cast<mmint*>(b));\n  for (int i = 0; i < S * S8; i++) s[i] =\
    \ mmint::itom(s[i]);\n  for (int i = 0; i < S * S8; i++) t[i] = mmint::itom(t[i]);\n\
    \  strassen(S, s, t, u);\n  for (int i = 0; i < S * S8; i++) u[i] = mmint::mtoi(u[i]);\n\
    \  place_rev(S, 0, 0, u, reinterpret_cast<mmint*>(c));\n}\n\n}  // namespace fast_mat_prod_impl"
  dependsOn:
  - modint/vectorize-modint.hpp
  isVerificationFile: false
  path: math-fast/mat-prod.hpp
  requiredBy: []
  timestamp: '2021-05-17 14:05:56+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-matrix-product-vectorize-modint.test.cpp
documentation_of: math-fast/mat-prod.hpp
layout: document
redirect_from:
- /library/math-fast/mat-prod.hpp
- /library/math-fast/mat-prod.hpp.html
title: math-fast/mat-prod.hpp
---
