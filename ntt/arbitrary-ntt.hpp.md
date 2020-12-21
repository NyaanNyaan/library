---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  - icon: ':question:'
    path: modint/simd-montgomery.hpp
    title: modint/simd-montgomery.hpp
  - icon: ':question:'
    path: ntt/ntt-avx2.hpp
    title: ntt/ntt-avx2.hpp
  _extendedRequiredBy:
  - icon: ':question:'
    path: fps/arbitrary-fps.hpp
    title: fps/arbitrary-fps.hpp
  - icon: ':x:'
    path: tree/frequency-table-of-tree-distance.hpp
    title: "\u9802\u70B9\u9593\u306E\u8DDD\u96E2\u306E\u5EA6\u6570\u5206\u5E03"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-exp-arb.test.cpp
    title: verify/verify-yosupo-fps/yosupo-exp-arb.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-inv-arb.test.cpp
    title: verify/verify-yosupo-fps/yosupo-inv-arb.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-fps/yosupo-log-arb.test.cpp
    title: verify/verify-yosupo-fps/yosupo-log-arb.test.cpp
  - icon: ':x:'
    path: verify/verify-yosupo-fps/yosupo-pow-arb.test.cpp
    title: verify/verify-yosupo-fps/yosupo-pow-arb.test.cpp
  - icon: ':x:'
    path: verify/verify-yosupo-graph/yosupo-frequency-table-of-tree-distance.test.cpp
    title: verify/verify-yosupo-graph/yosupo-frequency-table-of-tree-distance.test.cpp
  - icon: ':x:'
    path: verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt-arbitrarymodint.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt-arbitrarymodint.test.cpp
  - icon: ':x:'
    path: verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt-arbitraryprimemodint.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt-arbitraryprimemodint.test.cpp
  - icon: ':x:'
    path: verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt.test.cpp
  - icon: ':x:'
    path: verify/verify-yuki/yuki-0214.test.cpp
    title: verify/verify-yuki/yuki-0214.test.cpp
  - icon: ':x:'
    path: verify/verify-yuki/yuki-0215-nth-term.test.cpp
    title: verify/verify-yuki/yuki-0215-nth-term.test.cpp
  - icon: ':x:'
    path: verify/verify-yuki/yuki-0215.test.cpp
    title: verify/verify-yuki/yuki-0215.test.cpp
  - icon: ':x:'
    path: verify/verify-yuki/yuki-1080.test.cpp
    title: verify/verify-yuki/yuki-1080.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ntt/arbitrary-ntt.hpp\"\n\n\n\n#line 2 \"modint/montgomery-modint.hpp\"\
    \n\n\n\ntemplate <uint32_t mod>\nstruct LazyMontgomeryModInt {\n  using mint =\
    \ LazyMontgomeryModInt;\n  using i32 = int32_t;\n  using u32 = uint32_t;\n  using\
    \ u64 = uint64_t;\n\n  static constexpr u32 get_r() {\n    u32 ret = mod;\n  \
    \  for (i32 i = 0; i < 4; ++i) ret *= 2 - mod * ret;\n    return ret;\n  }\n\n\
    \  static constexpr u32 r = get_r();\n  static constexpr u32 n2 = -u64(mod) %\
    \ mod;\n  static_assert(r * mod == 1, \"invalid, r * mod != 1\");\n  static_assert(mod\
    \ < (1 << 30), \"invalid, mod >= 2 ^ 30\");\n  static_assert((mod & 1) == 1, \"\
    invalid, mod % 2 == 0\");\n\n  u32 a;\n\n  constexpr LazyMontgomeryModInt() :\
    \ a(0) {}\n  constexpr LazyMontgomeryModInt(const int64_t &b)\n      : a(reduce(u64(b\
    \ % mod + mod) * n2)){};\n\n  static constexpr u32 reduce(const u64 &b) {\n  \
    \  return (b + u64(u32(b) * u32(-r)) * mod) >> 32;\n  }\n\n  constexpr mint &operator+=(const\
    \ mint &b) {\n    if (i32(a += b.a - 2 * mod) < 0) a += 2 * mod;\n    return *this;\n\
    \  }\n\n  constexpr mint &operator-=(const mint &b) {\n    if (i32(a -= b.a) <\
    \ 0) a += 2 * mod;\n    return *this;\n  }\n\n  constexpr mint &operator*=(const\
    \ mint &b) {\n    a = reduce(u64(a) * b.a);\n    return *this;\n  }\n\n  constexpr\
    \ mint &operator/=(const mint &b) {\n    *this *= b.inverse();\n    return *this;\n\
    \  }\n\n  constexpr mint operator+(const mint &b) const { return mint(*this) +=\
    \ b; }\n  constexpr mint operator-(const mint &b) const { return mint(*this) -=\
    \ b; }\n  constexpr mint operator*(const mint &b) const { return mint(*this) *=\
    \ b; }\n  constexpr mint operator/(const mint &b) const { return mint(*this) /=\
    \ b; }\n  constexpr bool operator==(const mint &b) const {\n    return (a >= mod\
    \ ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);\n  }\n  constexpr bool operator!=(const\
    \ mint &b) const {\n    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a -\
    \ mod : b.a);\n  }\n  constexpr mint operator-() const { return mint() - mint(*this);\
    \ }\n\n  constexpr mint pow(u64 n) const {\n    mint ret(1), mul(*this);\n   \
    \ while (n > 0) {\n      if (n & 1) ret *= mul;\n      mul *= mul;\n      n >>=\
    \ 1;\n    }\n    return ret;\n  }\n  \n  constexpr mint inverse() const { return\
    \ pow(mod - 2); }\n\n  friend ostream &operator<<(ostream &os, const mint &b)\
    \ {\n    return os << b.get();\n  }\n\n  friend istream &operator>>(istream &is,\
    \ mint &b) {\n    int64_t t;\n    is >> t;\n    b = LazyMontgomeryModInt<mod>(t);\n\
    \    return (is);\n  }\n  \n  constexpr u32 get() const {\n    u32 ret = reduce(a);\n\
    \    return ret >= mod ? ret - mod : ret;\n  }\n\n  static constexpr u32 get_mod()\
    \ { return mod; }\n};\n#line 2 \"ntt/ntt-avx2.hpp\"\n\n#line 2 \"modint/simd-montgomery.hpp\"\
    \n\n\n#include <immintrin.h>\n\n__attribute__((target(\"sse4.2\"))) __attribute__((always_inline))\
    \ __m128i\nmy128_mullo_epu32(const __m128i &a, const __m128i &b) {\n  return _mm_mullo_epi32(a,\
    \ b);\n}\n\n__attribute__((target(\"sse4.2\"))) __attribute__((always_inline))\
    \ __m128i\nmy128_mulhi_epu32(const __m128i &a, const __m128i &b) {\n  __m128i\
    \ a13 = _mm_shuffle_epi32(a, 0xF5);\n  __m128i b13 = _mm_shuffle_epi32(b, 0xF5);\n\
    \  __m128i prod02 = _mm_mul_epu32(a, b);\n  __m128i prod13 = _mm_mul_epu32(a13,\
    \ b13);\n  __m128i prod = _mm_unpackhi_epi64(_mm_unpacklo_epi32(prod02, prod13),\n\
    \                                    _mm_unpackhi_epi32(prod02, prod13));\n  return\
    \ prod;\n}\n\n__attribute__((target(\"sse4.2\"))) __attribute__((always_inline))\
    \ __m128i\nmontgomery_mul_128(const __m128i &a, const __m128i &b, const __m128i\
    \ &r,\n                   const __m128i &m1) {\n  return _mm_sub_epi32(\n    \
    \  _mm_add_epi32(my128_mulhi_epu32(a, b), m1),\n      my128_mulhi_epu32(my128_mullo_epu32(my128_mullo_epu32(a,\
    \ b), r), m1));\n}\n\n__attribute__((target(\"sse4.2\"))) __attribute__((always_inline))\
    \ __m128i\nmontgomery_add_128(const __m128i &a, const __m128i &b, const __m128i\
    \ &m2,\n                   const __m128i &m0) {\n  __m128i ret = _mm_sub_epi32(_mm_add_epi32(a,\
    \ b), m2);\n  return _mm_add_epi32(_mm_and_si128(_mm_cmpgt_epi32(m0, ret), m2),\
    \ ret);\n}\n\n__attribute__((target(\"sse4.2\"))) __attribute__((always_inline))\
    \ __m128i\nmontgomery_sub_128(const __m128i &a, const __m128i &b, const __m128i\
    \ &m2,\n                   const __m128i &m0) {\n  __m128i ret = _mm_sub_epi32(a,\
    \ b);\n  return _mm_add_epi32(_mm_and_si128(_mm_cmpgt_epi32(m0, ret), m2), ret);\n\
    }\n\n__attribute__((target(\"avx2\"))) __attribute__((always_inline)) __m256i\n\
    my256_mullo_epu32(const __m256i &a, const __m256i &b) {\n  return _mm256_mullo_epi32(a,\
    \ b);\n}\n\n__attribute__((target(\"avx2\"))) __attribute__((always_inline)) __m256i\n\
    my256_mulhi_epu32(const __m256i &a, const __m256i &b) {\n  __m256i a13 = _mm256_shuffle_epi32(a,\
    \ 0xF5);\n  __m256i b13 = _mm256_shuffle_epi32(b, 0xF5);\n  __m256i prod02 = _mm256_mul_epu32(a,\
    \ b);\n  __m256i prod13 = _mm256_mul_epu32(a13, b13);\n  __m256i prod = _mm256_unpackhi_epi64(_mm256_unpacklo_epi32(prod02,\
    \ prod13),\n                                       _mm256_unpackhi_epi32(prod02,\
    \ prod13));\n  return prod;\n}\n\n__attribute__((target(\"avx2\"))) __attribute__((always_inline))\
    \ __m256i\nmontgomery_mul_256(const __m256i &a, const __m256i &b, const __m256i\
    \ &r,\n                   const __m256i &m1) {\n  return _mm256_sub_epi32(\n \
    \     _mm256_add_epi32(my256_mulhi_epu32(a, b), m1),\n      my256_mulhi_epu32(my256_mullo_epu32(my256_mullo_epu32(a,\
    \ b), r), m1));\n}\n\n__attribute__((target(\"avx2\"))) __attribute__((always_inline))\
    \ __m256i\nmontgomery_add_256(const __m256i &a, const __m256i &b, const __m256i\
    \ &m2,\n                   const __m256i &m0) {\n  __m256i ret = _mm256_sub_epi32(_mm256_add_epi32(a,\
    \ b), m2);\n  return _mm256_add_epi32(_mm256_and_si256(_mm256_cmpgt_epi32(m0,\
    \ ret), m2),\n                          ret);\n}\n\n__attribute__((target(\"avx2\"\
    ))) __attribute__((always_inline)) __m256i\nmontgomery_sub_256(const __m256i &a,\
    \ const __m256i &b, const __m256i &m2,\n                   const __m256i &m0)\
    \ {\n  __m256i ret = _mm256_sub_epi32(a, b);\n  return _mm256_add_epi32(_mm256_and_si256(_mm256_cmpgt_epi32(m0,\
    \ ret), m2),\n                          ret);\n}\n#line 4 \"ntt/ntt-avx2.hpp\"\
    \n\nnamespace ntt_inner {\nusing u64 = uint64_t;\nconstexpr uint32_t get_pr(uint32_t\
    \ mod) {\n  if (mod == 2) return 1;\n  u64 ds[32] = {};\n  int idx = 0;\n  u64\
    \ m = mod - 1;\n  for (u64 i = 2; i * i <= m; ++i) {\n    if (m % i == 0) {\n\
    \      ds[idx++] = i;\n      while (m % i == 0) m /= i;\n    }\n  }\n  if (m !=\
    \ 1) ds[idx++] = m;\n\n  uint32_t pr = 2;\n  while (1) {\n    int flg = 1;\n \
    \   for (int i = 0; i < idx; ++i) {\n      u64 a = pr, b = (mod - 1) / ds[i],\
    \ r = 1;\n      while (b) {\n        if (b & 1) r = r * a % mod;\n        a =\
    \ a * a % mod;\n        b >>= 1;\n      }\n      if (r == 1) {\n        flg =\
    \ 0;\n        break;\n      }\n    }\n    if (flg == 1) break;\n    ++pr;\n  }\n\
    \  return pr;\n}\n\nconstexpr int SZ_FFT_BUF = 1 << 23;\nuint32_t _buf1[SZ_FFT_BUF]\
    \ __attribute__((aligned(64)));\nuint32_t _buf2[SZ_FFT_BUF] __attribute__((aligned(64)));\n\
    }  // namespace ntt_inner\n\ntemplate <typename mint>\nstruct NTT {\n  static\
    \ constexpr uint32_t mod = mint::get_mod();\n  static constexpr uint32_t pr =\
    \ ntt_inner::get_pr(mint::get_mod());\n  static constexpr int level = __builtin_ctzll(mod\
    \ - 1);\n  mint dw[level], dy[level];\n  mint *buf1, *buf2;\n\n  constexpr NTT()\
    \ {\n    setwy(level);\n    union raw_cast {\n      mint dat;\n      uint32_t\
    \ _;\n    };\n    buf1 = &(((raw_cast *)(ntt_inner::_buf1))->dat);\n    buf2 =\
    \ &(((raw_cast *)(ntt_inner::_buf2))->dat);\n  }\n\n  constexpr void setwy(int\
    \ k) {\n    mint w[level], y[level];\n    w[k - 1] = mint(pr).pow((mod - 1) /\
    \ (1 << k));\n    y[k - 1] = w[k - 1].inverse();\n    for (int i = k - 2; i >\
    \ 0; --i)\n      w[i] = w[i + 1] * w[i + 1], y[i] = y[i + 1] * y[i + 1];\n   \
    \ dw[0] = dy[0] = w[1] * w[1];\n    dw[1] = w[1], dy[1] = y[1], dw[2] = w[2],\
    \ dy[2] = y[2];\n    for (int i = 3; i < k; ++i) {\n      dw[i] = dw[i - 1] *\
    \ y[i - 2] * w[i];\n      dy[i] = dy[i - 1] * w[i - 2] * y[i];\n    }\n  }\n\n\
    \  __attribute__((target(\"avx2\"))) void ntt(mint *a, int n) {\n    int k = n\
    \ ? __builtin_ctz(n) : 0;\n    if (k == 0) return;\n    if (k == 1) {\n      mint\
    \ a1 = a[1];\n      a[1] = a[0] - a[1];\n      a[0] = a[0] + a1;\n      return;\n\
    \    }\n    if (k & 1) {\n      int v = 1 << (k - 1);\n      if (v < 8) {\n  \
    \      for (int j = 0; j < v; ++j) {\n          mint ajv = a[j + v];\n       \
    \   a[j + v] = a[j] - ajv;\n          a[j] += ajv;\n        }\n      } else {\n\
    \        const __m256i m0 = _mm256_set1_epi32(0);\n        const __m256i m2 =\
    \ _mm256_set1_epi32(mod + mod);\n        int j0 = 0;\n        int j1 = v;\n  \
    \      for (; j0 < v; j0 += 8, j1 += 8) {\n          __m256i T0 = _mm256_loadu_si256((__m256i\
    \ *)(a + j0));\n          __m256i T1 = _mm256_loadu_si256((__m256i *)(a + j1));\n\
    \          __m256i naj = montgomery_add_256(T0, T1, m2, m0);\n          __m256i\
    \ najv = montgomery_sub_256(T0, T1, m2, m0);\n          _mm256_storeu_si256((__m256i\
    \ *)(a + j0), naj);\n          _mm256_storeu_si256((__m256i *)(a + j1), najv);\n\
    \        }\n      }\n    }\n    int u = 1 << (2 + (k & 1));\n    int v = 1 <<\
    \ (k - 2 - (k & 1));\n    mint one = mint(1);\n    mint imag = dw[1];\n    while\
    \ (v) {\n      if (v == 1) {\n        mint ww = one, xx = one, wx = one;\n   \
    \     for (int jh = 0; jh < u;) {\n          ww = xx * xx, wx = ww * xx;\n   \
    \       mint t0 = a[jh + 0], t1 = a[jh + 1] * xx;\n          mint t2 = a[jh +\
    \ 2] * ww, t3 = a[jh + 3] * wx;\n          mint t0p2 = t0 + t2, t1p3 = t1 + t3;\n\
    \          mint t0m2 = t0 - t2, t1m3 = (t1 - t3) * imag;\n          a[jh + 0]\
    \ = t0p2 + t1p3, a[jh + 1] = t0p2 - t1p3;\n          a[jh + 2] = t0m2 + t1m3,\
    \ a[jh + 3] = t0m2 - t1m3;\n          xx *= dw[__builtin_ctz((jh += 4))];\n  \
    \      }\n      } else if (v == 4) {\n        const __m128i m0 = _mm_set1_epi32(0);\n\
    \        const __m128i m1 = _mm_set1_epi32(mod);\n        const __m128i m2 = _mm_set1_epi32(mod\
    \ + mod);\n        const __m128i r = _mm_set1_epi32(mint::r);\n        const __m128i\
    \ Imag = _mm_set1_epi32(imag.a);\n        mint ww = one, xx = one, wx = one;\n\
    \        for (int jh = 0; jh < u;) {\n          if (jh == 0) {\n            int\
    \ j0 = 0;\n            int j1 = v;\n            int j2 = j1 + v;\n           \
    \ int j3 = j2 + v;\n            int je = v;\n            for (; j0 < je; j0 +=\
    \ 4, j1 += 4, j2 += 4, j3 += 4) {\n              const __m128i T0 = _mm_loadu_si128((__m128i\
    \ *)(a + j0));\n              const __m128i T1 = _mm_loadu_si128((__m128i *)(a\
    \ + j1));\n              const __m128i T2 = _mm_loadu_si128((__m128i *)(a + j2));\n\
    \              const __m128i T3 = _mm_loadu_si128((__m128i *)(a + j3));\n    \
    \          const __m128i T0P2 = montgomery_add_128(T0, T2, m2, m0);\n        \
    \      const __m128i T1P3 = montgomery_add_128(T1, T3, m2, m0);\n            \
    \  const __m128i T0M2 = montgomery_sub_128(T0, T2, m2, m0);\n              const\
    \ __m128i T1M3 = montgomery_mul_128(\n                  montgomery_sub_128(T1,\
    \ T3, m2, m0), Imag, r, m1);\n              _mm_storeu_si128((__m128i *)(a + j0),\n\
    \                               montgomery_add_128(T0P2, T1P3, m2, m0));\n   \
    \           _mm_storeu_si128((__m128i *)(a + j1),\n                          \
    \     montgomery_sub_128(T0P2, T1P3, m2, m0));\n              _mm_storeu_si128((__m128i\
    \ *)(a + j2),\n                               montgomery_add_128(T0M2, T1M3, m2,\
    \ m0));\n              _mm_storeu_si128((__m128i *)(a + j3),\n               \
    \                montgomery_sub_128(T0M2, T1M3, m2, m0));\n            }\n   \
    \       } else {\n            ww = xx * xx, wx = ww * xx;\n            const __m128i\
    \ WW = _mm_set1_epi32(ww.a);\n            const __m128i WX = _mm_set1_epi32(wx.a);\n\
    \            const __m128i XX = _mm_set1_epi32(xx.a);\n            int j0 = jh\
    \ * v;\n            int j1 = j0 + v;\n            int j2 = j1 + v;\n         \
    \   int j3 = j2 + v;\n            int je = j1;\n            for (; j0 < je; j0\
    \ += 4, j1 += 4, j2 += 4, j3 += 4) {\n              const __m128i T0 = _mm_loadu_si128((__m128i\
    \ *)(a + j0));\n              const __m128i T1 = _mm_loadu_si128((__m128i *)(a\
    \ + j1));\n              const __m128i T2 = _mm_loadu_si128((__m128i *)(a + j2));\n\
    \              const __m128i T3 = _mm_loadu_si128((__m128i *)(a + j3));\n    \
    \          const __m128i MT1 = montgomery_mul_128(T1, XX, r, m1);\n          \
    \    const __m128i MT2 = montgomery_mul_128(T2, WW, r, m1);\n              const\
    \ __m128i MT3 = montgomery_mul_128(T3, WX, r, m1);\n              const __m128i\
    \ T0P2 = montgomery_add_128(T0, MT2, m2, m0);\n              const __m128i T1P3\
    \ = montgomery_add_128(MT1, MT3, m2, m0);\n              const __m128i T0M2 =\
    \ montgomery_sub_128(T0, MT2, m2, m0);\n              const __m128i T1M3 = montgomery_mul_128(\n\
    \                  montgomery_sub_128(MT1, MT3, m2, m0), Imag, r, m1);\n     \
    \         _mm_storeu_si128((__m128i *)(a + j0),\n                            \
    \   montgomery_add_128(T0P2, T1P3, m2, m0));\n              _mm_storeu_si128((__m128i\
    \ *)(a + j1),\n                               montgomery_sub_128(T0P2, T1P3, m2,\
    \ m0));\n              _mm_storeu_si128((__m128i *)(a + j2),\n               \
    \                montgomery_add_128(T0M2, T1M3, m2, m0));\n              _mm_storeu_si128((__m128i\
    \ *)(a + j3),\n                               montgomery_sub_128(T0M2, T1M3, m2,\
    \ m0));\n            }\n          }\n          xx *= dw[__builtin_ctz((jh += 4))];\n\
    \        }\n      } else {\n        const __m256i m0 = _mm256_set1_epi32(0);\n\
    \        const __m256i m1 = _mm256_set1_epi32(mod);\n        const __m256i m2\
    \ = _mm256_set1_epi32(mod + mod);\n        const __m256i r = _mm256_set1_epi32(mint::r);\n\
    \        const __m256i Imag = _mm256_set1_epi32(imag.a);\n        mint ww = one,\
    \ xx = one, wx = one;\n        for (int jh = 0; jh < u;) {\n          if (jh ==\
    \ 0) {\n            int j0 = 0;\n            int j1 = v;\n            int j2 =\
    \ j1 + v;\n            int j3 = j2 + v;\n            int je = v;\n           \
    \ for (; j0 < je; j0 += 8, j1 += 8, j2 += 8, j3 += 8) {\n              const __m256i\
    \ T0 = _mm256_loadu_si256((__m256i *)(a + j0));\n              const __m256i T1\
    \ = _mm256_loadu_si256((__m256i *)(a + j1));\n              const __m256i T2 =\
    \ _mm256_loadu_si256((__m256i *)(a + j2));\n              const __m256i T3 = _mm256_loadu_si256((__m256i\
    \ *)(a + j3));\n              const __m256i T0P2 = montgomery_add_256(T0, T2,\
    \ m2, m0);\n              const __m256i T1P3 = montgomery_add_256(T1, T3, m2,\
    \ m0);\n              const __m256i T0M2 = montgomery_sub_256(T0, T2, m2, m0);\n\
    \              const __m256i T1M3 = montgomery_mul_256(\n                  montgomery_sub_256(T1,\
    \ T3, m2, m0), Imag, r, m1);\n              _mm256_storeu_si256((__m256i *)(a\
    \ + j0),\n                                  montgomery_add_256(T0P2, T1P3, m2,\
    \ m0));\n              _mm256_storeu_si256((__m256i *)(a + j1),\n            \
    \                      montgomery_sub_256(T0P2, T1P3, m2, m0));\n            \
    \  _mm256_storeu_si256((__m256i *)(a + j2),\n                                \
    \  montgomery_add_256(T0M2, T1M3, m2, m0));\n              _mm256_storeu_si256((__m256i\
    \ *)(a + j3),\n                                  montgomery_sub_256(T0M2, T1M3,\
    \ m2, m0));\n            }\n          } else {\n            ww = xx * xx, wx =\
    \ ww * xx;\n            const __m256i WW = _mm256_set1_epi32(ww.a);\n        \
    \    const __m256i WX = _mm256_set1_epi32(wx.a);\n            const __m256i XX\
    \ = _mm256_set1_epi32(xx.a);\n            int j0 = jh * v;\n            int j1\
    \ = j0 + v;\n            int j2 = j1 + v;\n            int j3 = j2 + v;\n    \
    \        int je = j1;\n            for (; j0 < je; j0 += 8, j1 += 8, j2 += 8,\
    \ j3 += 8) {\n              const __m256i T0 = _mm256_loadu_si256((__m256i *)(a\
    \ + j0));\n              const __m256i T1 = _mm256_loadu_si256((__m256i *)(a +\
    \ j1));\n              const __m256i T2 = _mm256_loadu_si256((__m256i *)(a + j2));\n\
    \              const __m256i T3 = _mm256_loadu_si256((__m256i *)(a + j3));\n \
    \             const __m256i MT1 = montgomery_mul_256(T1, XX, r, m1);\n       \
    \       const __m256i MT2 = montgomery_mul_256(T2, WW, r, m1);\n             \
    \ const __m256i MT3 = montgomery_mul_256(T3, WX, r, m1);\n              const\
    \ __m256i T0P2 = montgomery_add_256(T0, MT2, m2, m0);\n              const __m256i\
    \ T1P3 = montgomery_add_256(MT1, MT3, m2, m0);\n              const __m256i T0M2\
    \ = montgomery_sub_256(T0, MT2, m2, m0);\n              const __m256i T1M3 = montgomery_mul_256(\n\
    \                  montgomery_sub_256(MT1, MT3, m2, m0), Imag, r, m1);\n     \
    \         _mm256_storeu_si256((__m256i *)(a + j0),\n                         \
    \         montgomery_add_256(T0P2, T1P3, m2, m0));\n              _mm256_storeu_si256((__m256i\
    \ *)(a + j1),\n                                  montgomery_sub_256(T0P2, T1P3,\
    \ m2, m0));\n              _mm256_storeu_si256((__m256i *)(a + j2),\n        \
    \                          montgomery_add_256(T0M2, T1M3, m2, m0));\n        \
    \      _mm256_storeu_si256((__m256i *)(a + j3),\n                            \
    \      montgomery_sub_256(T0M2, T1M3, m2, m0));\n            }\n          }\n\
    \          xx *= dw[__builtin_ctz((jh += 4))];\n        }\n      }\n      u <<=\
    \ 2;\n      v >>= 2;\n    }\n  }\n\n  __attribute__((target(\"avx2\"))) void intt(mint\
    \ *a, int n,\n                                            int normalize = true)\
    \ {\n    int k = n ? __builtin_ctz(n) : 0;\n    if (k == 0) return;\n    if (k\
    \ == 1) {\n      mint a1 = a[1];\n      a[1] = a[0] - a[1];\n      a[0] = a[0]\
    \ + a1;\n      if (normalize) {\n        a[0] *= mint(2).inverse();\n        a[1]\
    \ *= mint(2).inverse();\n      }\n      return;\n    }\n    int u = 1 << (k -\
    \ 2);\n    int v = 1;\n    mint one = mint(1);\n    mint imag = dy[1];\n    while\
    \ (u) {\n      if (v == 1) {\n        mint ww = one, xx = one, yy = one;\n   \
    \     u <<= 2;\n        for (int jh = 0; jh < u;) {\n          ww = xx * xx, yy\
    \ = xx * imag;\n          mint t0 = a[jh + 0], t1 = a[jh + 1];\n          mint\
    \ t2 = a[jh + 2], t3 = a[jh + 3];\n          mint t0p1 = t0 + t1, t2p3 = t2 +\
    \ t3;\n          mint t0m1 = (t0 - t1) * xx, t2m3 = (t2 - t3) * yy;\n        \
    \  a[jh + 0] = t0p1 + t2p3, a[jh + 2] = (t0p1 - t2p3) * ww;\n          a[jh +\
    \ 1] = t0m1 + t2m3, a[jh + 3] = (t0m1 - t2m3) * ww;\n          xx *= dy[__builtin_ctz(jh\
    \ += 4)];\n        }\n      } else if (v == 4) {\n        const __m128i m0 = _mm_set1_epi32(0);\n\
    \        const __m128i m1 = _mm_set1_epi32(mod);\n        const __m128i m2 = _mm_set1_epi32(mod\
    \ + mod);\n        const __m128i r = _mm_set1_epi32(mint::r);\n        const __m128i\
    \ Imag = _mm_set1_epi32(imag.a);\n        mint ww = one, xx = one, yy = one;\n\
    \        u <<= 2;\n        for (int jh = 0; jh < u;) {\n          if (jh == 0)\
    \ {\n            int j0 = 0;\n            int j1 = v;\n            int j2 = v\
    \ + v;\n            int j3 = j2 + v;\n            for (; j0 < v; j0 += 4, j1 +=\
    \ 4, j2 += 4, j3 += 4) {\n              const __m128i T0 = _mm_loadu_si128((__m128i\
    \ *)(a + j0));\n              const __m128i T1 = _mm_loadu_si128((__m128i *)(a\
    \ + j1));\n              const __m128i T2 = _mm_loadu_si128((__m128i *)(a + j2));\n\
    \              const __m128i T3 = _mm_loadu_si128((__m128i *)(a + j3));\n    \
    \          const __m128i T0P1 = montgomery_add_128(T0, T1, m2, m0);\n        \
    \      const __m128i T2P3 = montgomery_add_128(T2, T3, m2, m0);\n            \
    \  const __m128i T0M1 = montgomery_sub_128(T0, T1, m2, m0);\n              const\
    \ __m128i T2M3 = montgomery_mul_128(\n                  montgomery_sub_128(T2,\
    \ T3, m2, m0), Imag, r, m1);\n              _mm_storeu_si128((__m128i *)(a + j0),\n\
    \                               montgomery_add_128(T0P1, T2P3, m2, m0));\n   \
    \           _mm_storeu_si128((__m128i *)(a + j2),\n                          \
    \     montgomery_sub_128(T0P1, T2P3, m2, m0));\n              _mm_storeu_si128((__m128i\
    \ *)(a + j1),\n                               montgomery_add_128(T0M1, T2M3, m2,\
    \ m0));\n              _mm_storeu_si128((__m128i *)(a + j3),\n               \
    \                montgomery_sub_128(T0M1, T2M3, m2, m0));\n            }\n   \
    \       } else {\n            ww = xx * xx, yy = xx * imag;\n            const\
    \ __m128i WW = _mm_set1_epi32(ww.a);\n            const __m128i XX = _mm_set1_epi32(xx.a);\n\
    \            const __m128i YY = _mm_set1_epi32(yy.a);\n            int j0 = jh\
    \ * v;\n            int j1 = j0 + v;\n            int j2 = j1 + v;\n         \
    \   int j3 = j2 + v;\n            int je = j1;\n            for (; j0 < je; j0\
    \ += 4, j1 += 4, j2 += 4, j3 += 4) {\n              const __m128i T0 = _mm_loadu_si128((__m128i\
    \ *)(a + j0));\n              const __m128i T1 = _mm_loadu_si128((__m128i *)(a\
    \ + j1));\n              const __m128i T2 = _mm_loadu_si128((__m128i *)(a + j2));\n\
    \              const __m128i T3 = _mm_loadu_si128((__m128i *)(a + j3));\n    \
    \          const __m128i T0P1 = montgomery_add_128(T0, T1, m2, m0);\n        \
    \      const __m128i T2P3 = montgomery_add_128(T2, T3, m2, m0);\n            \
    \  const __m128i T0M1 = montgomery_mul_128(\n                  montgomery_sub_128(T0,\
    \ T1, m2, m0), XX, r, m1);\n              __m128i T2M3 = montgomery_mul_128(\n\
    \                  montgomery_sub_128(T2, T3, m2, m0), YY, r, m1);\n         \
    \     _mm_storeu_si128((__m128i *)(a + j0),\n                               montgomery_add_128(T0P1,\
    \ T2P3, m2, m0));\n              _mm_storeu_si128(\n                  (__m128i\
    \ *)(a + j2),\n                  montgomery_mul_128(montgomery_sub_128(T0P1, T2P3,\
    \ m2, m0), WW,\n                                     r, m1));\n              _mm_storeu_si128((__m128i\
    \ *)(a + j1),\n                               montgomery_add_128(T0M1, T2M3, m2,\
    \ m0));\n              _mm_storeu_si128(\n                  (__m128i *)(a + j3),\n\
    \                  montgomery_mul_128(montgomery_sub_128(T0M1, T2M3, m2, m0),\
    \ WW,\n                                     r, m1));\n            }\n        \
    \  }\n          xx *= dy[__builtin_ctz(jh += 4)];\n        }\n      } else {\n\
    \        const __m256i m0 = _mm256_set1_epi32(0);\n        const __m256i m1 =\
    \ _mm256_set1_epi32(mod);\n        const __m256i m2 = _mm256_set1_epi32(mod +\
    \ mod);\n        const __m256i r = _mm256_set1_epi32(mint::r);\n        const\
    \ __m256i Imag = _mm256_set1_epi32(imag.a);\n        mint ww = one, xx = one,\
    \ yy = one;\n        u <<= 2;\n        for (int jh = 0; jh < u;) {\n         \
    \ if (jh == 0) {\n            int j0 = 0;\n            int j1 = v;\n         \
    \   int j2 = v + v;\n            int j3 = j2 + v;\n            for (; j0 < v;\
    \ j0 += 8, j1 += 8, j2 += 8, j3 += 8) {\n              const __m256i T0 = _mm256_loadu_si256((__m256i\
    \ *)(a + j0));\n              const __m256i T1 = _mm256_loadu_si256((__m256i *)(a\
    \ + j1));\n              const __m256i T2 = _mm256_loadu_si256((__m256i *)(a +\
    \ j2));\n              const __m256i T3 = _mm256_loadu_si256((__m256i *)(a + j3));\n\
    \              const __m256i T0P1 = montgomery_add_256(T0, T1, m2, m0);\n    \
    \          const __m256i T2P3 = montgomery_add_256(T2, T3, m2, m0);\n        \
    \      const __m256i T0M1 = montgomery_sub_256(T0, T1, m2, m0);\n            \
    \  const __m256i T2M3 = montgomery_mul_256(\n                  montgomery_sub_256(T2,\
    \ T3, m2, m0), Imag, r, m1);\n              _mm256_storeu_si256((__m256i *)(a\
    \ + j0),\n                                  montgomery_add_256(T0P1, T2P3, m2,\
    \ m0));\n              _mm256_storeu_si256((__m256i *)(a + j2),\n            \
    \                      montgomery_sub_256(T0P1, T2P3, m2, m0));\n            \
    \  _mm256_storeu_si256((__m256i *)(a + j1),\n                                \
    \  montgomery_add_256(T0M1, T2M3, m2, m0));\n              _mm256_storeu_si256((__m256i\
    \ *)(a + j3),\n                                  montgomery_sub_256(T0M1, T2M3,\
    \ m2, m0));\n            }\n          } else {\n            ww = xx * xx, yy =\
    \ xx * imag;\n            const __m256i WW = _mm256_set1_epi32(ww.a);\n      \
    \      const __m256i XX = _mm256_set1_epi32(xx.a);\n            const __m256i\
    \ YY = _mm256_set1_epi32(yy.a);\n            int j0 = jh * v;\n            int\
    \ j1 = j0 + v;\n            int j2 = j1 + v;\n            int j3 = j2 + v;\n \
    \           int je = j1;\n            for (; j0 < je; j0 += 8, j1 += 8, j2 +=\
    \ 8, j3 += 8) {\n              const __m256i T0 = _mm256_loadu_si256((__m256i\
    \ *)(a + j0));\n              const __m256i T1 = _mm256_loadu_si256((__m256i *)(a\
    \ + j1));\n              const __m256i T2 = _mm256_loadu_si256((__m256i *)(a +\
    \ j2));\n              const __m256i T3 = _mm256_loadu_si256((__m256i *)(a + j3));\n\
    \              const __m256i T0P1 = montgomery_add_256(T0, T1, m2, m0);\n    \
    \          const __m256i T2P3 = montgomery_add_256(T2, T3, m2, m0);\n        \
    \      const __m256i T0M1 = montgomery_mul_256(\n                  montgomery_sub_256(T0,\
    \ T1, m2, m0), XX, r, m1);\n              const __m256i T2M3 = montgomery_mul_256(\n\
    \                  montgomery_sub_256(T2, T3, m2, m0), YY, r, m1);\n         \
    \     _mm256_storeu_si256((__m256i *)(a + j0),\n                             \
    \     montgomery_add_256(T0P1, T2P3, m2, m0));\n              _mm256_storeu_si256(\n\
    \                  (__m256i *)(a + j2),\n                  montgomery_mul_256(montgomery_sub_256(T0P1,\
    \ T2P3, m2, m0), WW,\n                                     r, m1));\n        \
    \      _mm256_storeu_si256((__m256i *)(a + j1),\n                            \
    \      montgomery_add_256(T0M1, T2M3, m2, m0));\n              _mm256_storeu_si256(\n\
    \                  (__m256i *)(a + j3),\n                  montgomery_mul_256(montgomery_sub_256(T0M1,\
    \ T2M3, m2, m0), WW,\n                                     r, m1));\n        \
    \    }\n          }\n          xx *= dy[__builtin_ctz(jh += 4)];\n        }\n\
    \      }\n      u >>= 4;\n      v <<= 2;\n    }\n    if (k & 1) {\n      v = 1\
    \ << (k - 1);\n      if (v < 8) {\n        for (int j = 0; j < v; ++j) {\n   \
    \       mint ajv = a[j] - a[j + v];\n          a[j] += a[j + v];\n          a[j\
    \ + v] = ajv;\n        }\n      } else {\n        const __m256i m0 = _mm256_set1_epi32(0);\n\
    \        const __m256i m2 = _mm256_set1_epi32(mod + mod);\n        int j0 = 0;\n\
    \        int j1 = v;\n        for (; j0 < v; j0 += 8, j1 += 8) {\n          const\
    \ __m256i T0 = _mm256_loadu_si256((__m256i *)(a + j0));\n          const __m256i\
    \ T1 = _mm256_loadu_si256((__m256i *)(a + j1));\n          __m256i naj = montgomery_add_256(T0,\
    \ T1, m2, m0);\n          __m256i najv = montgomery_sub_256(T0, T1, m2, m0);\n\
    \          _mm256_storeu_si256((__m256i *)(a + j0), naj);\n          _mm256_storeu_si256((__m256i\
    \ *)(a + j1), najv);\n        }\n      }\n    }\n    if (normalize) {\n      mint\
    \ invn = mint(n).inverse();\n      for (int i = 0; i < n; i++) a[i] *= invn;\n\
    \    }\n  }\n\n  __attribute__((target(\"avx2\"))) void inplace_multiply(\n  \
    \    int l1, int l2, int zero_padding = true) {\n    int l = l1 + l2 - 1;\n  \
    \  int M = 4;\n    while (M < l) M <<= 1;\n    if (zero_padding) {\n      for\
    \ (int i = l1; i < M; i++) ntt_inner::_buf1[i] = 0;\n      for (int i = l2; i\
    \ < M; i++) ntt_inner::_buf2[i] = 0;\n    }\n    const __m256i m0 = _mm256_set1_epi32(0);\n\
    \    const __m256i m1 = _mm256_set1_epi32(mod);\n    const __m256i r = _mm256_set1_epi32(mint::r);\n\
    \    const __m256i N2 = _mm256_set1_epi32(mint::n2);\n    for (int i = 0; i <\
    \ l1; i += 8) {\n      __m256i a = _mm256_loadu_si256((__m256i *)(ntt_inner::_buf1\
    \ + i));\n      __m256i b = montgomery_mul_256(a, N2, r, m1);\n      _mm256_storeu_si256((__m256i\
    \ *)(ntt_inner::_buf1 + i), b);\n    }\n    for (int i = 0; i < l2; i += 8) {\n\
    \      __m256i a = _mm256_loadu_si256((__m256i *)(ntt_inner::_buf2 + i));\n  \
    \    __m256i b = montgomery_mul_256(a, N2, r, m1);\n      _mm256_storeu_si256((__m256i\
    \ *)(ntt_inner::_buf2 + i), b);\n    }\n    ntt(buf1, M);\n    ntt(buf2, M);\n\
    \    for (int i = 0; i < M; i += 8) {\n      __m256i a = _mm256_loadu_si256((__m256i\
    \ *)(ntt_inner::_buf1 + i));\n      __m256i b = _mm256_loadu_si256((__m256i *)(ntt_inner::_buf2\
    \ + i));\n      __m256i c = montgomery_mul_256(a, b, r, m1);\n      _mm256_storeu_si256((__m256i\
    \ *)(ntt_inner::_buf1 + i), c);\n    }\n    intt(buf1, M, false);\n    const __m256i\
    \ INVM = _mm256_set1_epi32((mint(M).inverse()).a);\n    for (int i = 0; i < l;\
    \ i += 8) {\n      __m256i a = _mm256_loadu_si256((__m256i *)(ntt_inner::_buf1\
    \ + i));\n      __m256i b = montgomery_mul_256(a, INVM, r, m1);\n      __m256i\
    \ c = my256_mulhi_epu32(my256_mullo_epu32(b, r), m1);\n      __m256i d = _mm256_and_si256(_mm256_cmpgt_epi32(c,\
    \ m0), m1);\n      __m256i e = _mm256_sub_epi32(d, c);\n      _mm256_storeu_si256((__m256i\
    \ *)(ntt_inner::_buf1 + i), e);\n    }\n  }\n\n  void ntt(vector<mint> &a) {\n\
    \    int M = (int)a.size();\n    for (int i = 0; i < M; i++) buf1[i].a = a[i].a;\n\
    \    ntt(buf1, M);\n    for (int i = 0; i < M; i++) a[i].a = buf1[i].a;\n  }\n\
    \n  void intt(vector<mint> &a) {\n    int M = (int)a.size();\n    for (int i =\
    \ 0; i < M; i++) buf1[i].a = a[i].a;\n    intt(buf1, M, true);\n    for (int i\
    \ = 0; i < M; i++) a[i].a = buf1[i].a;\n  }\n\n  vector<mint> multiply(const vector<mint>\
    \ &a, const vector<mint> &b) {\n    if (a.size() == 0 && b.size() == 0) return\
    \ vector<mint>{};\n    int l = a.size() + b.size() - 1;\n    if (min<int>(a.size(),\
    \ b.size()) <= 40) {\n      vector<mint> s(l);\n      for (int i = 0; i < (int)a.size();\
    \ ++i)\n        for (int j = 0; j < (int)b.size(); ++j) s[i + j] += a[i] * b[j];\n\
    \      return s;\n    }\n    assert(l <= ntt_inner::SZ_FFT_BUF);\n    int M =\
    \ 4;\n    while (M < l) M <<= 1;\n    for (int i = 0; i < (int)a.size(); ++i)\
    \ buf1[i].a = a[i].a;\n    for (int i = (int)a.size(); i < M; ++i) buf1[i].a =\
    \ 0;\n    for (int i = 0; i < (int)b.size(); ++i) buf2[i].a = b[i].a;\n    for\
    \ (int i = (int)b.size(); i < M; ++i) buf2[i].a = 0;\n    ntt(buf1, M);\n    ntt(buf2,\
    \ M);\n    for (int i = 0; i < M; ++i)\n      buf1[i].a = mint::reduce(uint64_t(buf1[i].a)\
    \ * buf2[i].a);\n    intt(buf1, M, false);\n    vector<mint> s(l);\n    mint invm\
    \ = mint(M).inverse();\n    for (int i = 0; i < l; ++i) s[i] = buf1[i] * invm;\n\
    \    return s;\n  }\n\n  void ntt_doubling(vector<mint> &a) {\n    int M = (int)a.size();\n\
    \    for (int i = 0; i < M; i++) buf1[i].a = a[i].a;\n    intt(buf1, M);\n   \
    \ mint r = 1, zeta = mint(pr).pow((mint::get_mod() - 1) / (M << 1));\n    for\
    \ (int i = 0; i < M; i++) buf1[i] *= r, r *= zeta;\n    ntt(buf1, M);\n    a.resize(2\
    \ * M);\n    for (int i = 0; i < M; i++) a[M + i].a = buf1[i].a;\n  }\n};\n#line\
    \ 7 \"ntt/arbitrary-ntt.hpp\"\n\nnamespace ArbitraryNTT {\nusing i64 = int64_t;\n\
    using u128 = __uint128_t;\nconstexpr int32_t m0 = 167772161;\nconstexpr int32_t\
    \ m1 = 469762049;\nconstexpr int32_t m2 = 754974721;\nusing mint0 = LazyMontgomeryModInt<m0>;\n\
    using mint1 = LazyMontgomeryModInt<m1>;\nusing mint2 = LazyMontgomeryModInt<m2>;\n\
    constexpr int r01 = mint1(m0).inverse().get();\nconstexpr int r02 = mint2(m0).inverse().get();\n\
    constexpr int r12 = mint2(m1).inverse().get();\nconstexpr int r02r12 = i64(r02)\
    \ * r12 % m2;\nconstexpr i64 w1 = m0;\nconstexpr i64 w2 = i64(m0) * m1;\n\ntemplate\
    \ <typename T, typename submint>\nvector<submint> mul(const vector<T> &a, const\
    \ vector<T> &b) {\n  NTT<submint> ntt;\n  vector<submint> s(a.size()), t(b.size());\n\
    \  for (int i = 0; i < (int)a.size(); ++i) s[i] = i64(a[i] % submint::get_mod());\n\
    \  for (int i = 0; i < (int)b.size(); ++i) t[i] = i64(b[i] % submint::get_mod());\n\
    \  return ntt.multiply(s, t);\n}\n\ntemplate <typename T>\nvector<int> multiply(const\
    \ vector<T> &s, const vector<T> &t, int mod) {\n  auto d0 = mul<T, mint0>(s, t);\n\
    \  auto d1 = mul<T, mint1>(s, t);\n  auto d2 = mul<T, mint2>(s, t);\n  int n =\
    \ d0.size();\n  vector<int> ret(n);\n  const int W1 = w1 % mod;\n  const int W2\
    \ = w2 % mod;\n  for (int i = 0; i < n; i++) {\n    int n1 = d1[i].get(), n2 =\
    \ d2[i].get(), a = d0[i].get();\n    int b = i64(n1 + m1 - a) * r01 % m1;\n  \
    \  int c = (i64(n2 + m2 - a) * r02r12 + i64(m2 - b) * r12) % m2;\n    ret[i] =\
    \ (i64(a) + i64(b) * W1 + i64(c) * W2) % mod;\n  }\n  return ret;\n}\n\ntemplate\
    \ <typename mint>\nvector<mint> multiply(const vector<mint> &a, const vector<mint>\
    \ &b) {\n  if (a.size() == 0 && b.size() == 0) return {};\n  if (min<int>(a.size(),\
    \ b.size()) < 128) {\n    vector<mint> ret(a.size() + b.size() - 1);\n    for\
    \ (int i = 0; i < (int)a.size(); ++i)\n      for (int j = 0; j < (int)b.size();\
    \ ++j) ret[i + j] += a[i] * b[j];\n    return ret;\n  }\n  vector<int> s(a.size()),\
    \ t(b.size());\n  for (int i = 0; i < (int)a.size(); ++i) s[i] = a[i].get();\n\
    \  for (int i = 0; i < (int)b.size(); ++i) t[i] = b[i].get();\n  vector<int> u\
    \ = multiply<int>(s, t, mint::get_mod());\n  vector<mint> ret(u.size());\n  for\
    \ (int i = 0; i < (int)u.size(); ++i) ret[i] = mint(u[i]);\n  return ret;\n}\n\
    \ntemplate <typename T>\nvector<u128> multiply_u128(const vector<T> &s, const\
    \ vector<T> &t) {\n  if (s.size() == 0 && t.size() == 0) return {};\n  if (min<int>(s.size(),\
    \ t.size()) < 128) {\n    vector<u128> ret(s.size() + t.size() - 1);\n    for\
    \ (int i = 0; i < (int)s.size(); ++i)\n      for (int j = 0; j < (int)t.size();\
    \ ++j) ret[i + j] += i64(s[i]) * t[j];\n    return ret;\n  }\n  auto d0 = mul<T,\
    \ mint0>(s, t);\n  auto d1 = mul<T, mint1>(s, t);\n  auto d2 = mul<T, mint2>(s,\
    \ t);\n  int n = d0.size();\n  vector<u128> ret(n);\n  for (int i = 0; i < n;\
    \ i++) {\n    i64 n1 = d1[i].get(), n2 = d2[i].get();\n    i64 a = d0[i].get();\n\
    \    u128 b = (n1 + m1 - a) * r01 % m1;\n    u128 c = ((n2 + m2 - a) * r02r12\
    \ + (m2 - b) * r12) % m2;\n    ret[i] = a + b * w1 + c * w2;\n  }\n  return ret;\n\
    }\n}  // namespace ArbitraryNTT\n"
  code: "#pragma once\n\n\n\n#include \"../modint/montgomery-modint.hpp\"\n#include\
    \ \"./ntt-avx2.hpp\"\n\nnamespace ArbitraryNTT {\nusing i64 = int64_t;\nusing\
    \ u128 = __uint128_t;\nconstexpr int32_t m0 = 167772161;\nconstexpr int32_t m1\
    \ = 469762049;\nconstexpr int32_t m2 = 754974721;\nusing mint0 = LazyMontgomeryModInt<m0>;\n\
    using mint1 = LazyMontgomeryModInt<m1>;\nusing mint2 = LazyMontgomeryModInt<m2>;\n\
    constexpr int r01 = mint1(m0).inverse().get();\nconstexpr int r02 = mint2(m0).inverse().get();\n\
    constexpr int r12 = mint2(m1).inverse().get();\nconstexpr int r02r12 = i64(r02)\
    \ * r12 % m2;\nconstexpr i64 w1 = m0;\nconstexpr i64 w2 = i64(m0) * m1;\n\ntemplate\
    \ <typename T, typename submint>\nvector<submint> mul(const vector<T> &a, const\
    \ vector<T> &b) {\n  NTT<submint> ntt;\n  vector<submint> s(a.size()), t(b.size());\n\
    \  for (int i = 0; i < (int)a.size(); ++i) s[i] = i64(a[i] % submint::get_mod());\n\
    \  for (int i = 0; i < (int)b.size(); ++i) t[i] = i64(b[i] % submint::get_mod());\n\
    \  return ntt.multiply(s, t);\n}\n\ntemplate <typename T>\nvector<int> multiply(const\
    \ vector<T> &s, const vector<T> &t, int mod) {\n  auto d0 = mul<T, mint0>(s, t);\n\
    \  auto d1 = mul<T, mint1>(s, t);\n  auto d2 = mul<T, mint2>(s, t);\n  int n =\
    \ d0.size();\n  vector<int> ret(n);\n  const int W1 = w1 % mod;\n  const int W2\
    \ = w2 % mod;\n  for (int i = 0; i < n; i++) {\n    int n1 = d1[i].get(), n2 =\
    \ d2[i].get(), a = d0[i].get();\n    int b = i64(n1 + m1 - a) * r01 % m1;\n  \
    \  int c = (i64(n2 + m2 - a) * r02r12 + i64(m2 - b) * r12) % m2;\n    ret[i] =\
    \ (i64(a) + i64(b) * W1 + i64(c) * W2) % mod;\n  }\n  return ret;\n}\n\ntemplate\
    \ <typename mint>\nvector<mint> multiply(const vector<mint> &a, const vector<mint>\
    \ &b) {\n  if (a.size() == 0 && b.size() == 0) return {};\n  if (min<int>(a.size(),\
    \ b.size()) < 128) {\n    vector<mint> ret(a.size() + b.size() - 1);\n    for\
    \ (int i = 0; i < (int)a.size(); ++i)\n      for (int j = 0; j < (int)b.size();\
    \ ++j) ret[i + j] += a[i] * b[j];\n    return ret;\n  }\n  vector<int> s(a.size()),\
    \ t(b.size());\n  for (int i = 0; i < (int)a.size(); ++i) s[i] = a[i].get();\n\
    \  for (int i = 0; i < (int)b.size(); ++i) t[i] = b[i].get();\n  vector<int> u\
    \ = multiply<int>(s, t, mint::get_mod());\n  vector<mint> ret(u.size());\n  for\
    \ (int i = 0; i < (int)u.size(); ++i) ret[i] = mint(u[i]);\n  return ret;\n}\n\
    \ntemplate <typename T>\nvector<u128> multiply_u128(const vector<T> &s, const\
    \ vector<T> &t) {\n  if (s.size() == 0 && t.size() == 0) return {};\n  if (min<int>(s.size(),\
    \ t.size()) < 128) {\n    vector<u128> ret(s.size() + t.size() - 1);\n    for\
    \ (int i = 0; i < (int)s.size(); ++i)\n      for (int j = 0; j < (int)t.size();\
    \ ++j) ret[i + j] += i64(s[i]) * t[j];\n    return ret;\n  }\n  auto d0 = mul<T,\
    \ mint0>(s, t);\n  auto d1 = mul<T, mint1>(s, t);\n  auto d2 = mul<T, mint2>(s,\
    \ t);\n  int n = d0.size();\n  vector<u128> ret(n);\n  for (int i = 0; i < n;\
    \ i++) {\n    i64 n1 = d1[i].get(), n2 = d2[i].get();\n    i64 a = d0[i].get();\n\
    \    u128 b = (n1 + m1 - a) * r01 % m1;\n    u128 c = ((n2 + m2 - a) * r02r12\
    \ + (m2 - b) * r12) % m2;\n    ret[i] = a + b * w1 + c * w2;\n  }\n  return ret;\n\
    }\n}  // namespace ArbitraryNTT"
  dependsOn:
  - modint/montgomery-modint.hpp
  - ntt/ntt-avx2.hpp
  - modint/simd-montgomery.hpp
  isVerificationFile: false
  path: ntt/arbitrary-ntt.hpp
  requiredBy:
  - tree/frequency-table-of-tree-distance.hpp
  - fps/arbitrary-fps.hpp
  timestamp: '2020-12-22 00:51:45+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt.test.cpp
  - verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt-arbitrarymodint.test.cpp
  - verify/verify-yosupo-ntt/yosupo-convolution-arbitraryntt-arbitraryprimemodint.test.cpp
  - verify/verify-yosupo-fps/yosupo-log-arb.test.cpp
  - verify/verify-yosupo-fps/yosupo-exp-arb.test.cpp
  - verify/verify-yosupo-fps/yosupo-inv-arb.test.cpp
  - verify/verify-yosupo-fps/yosupo-pow-arb.test.cpp
  - verify/verify-yuki/yuki-0215.test.cpp
  - verify/verify-yuki/yuki-0214.test.cpp
  - verify/verify-yuki/yuki-0215-nth-term.test.cpp
  - verify/verify-yuki/yuki-1080.test.cpp
  - verify/verify-yosupo-graph/yosupo-frequency-table-of-tree-distance.test.cpp
documentation_of: ntt/arbitrary-ntt.hpp
layout: document
redirect_from:
- /library/ntt/arbitrary-ntt.hpp
- /library/ntt/arbitrary-ntt.hpp.html
title: ntt/arbitrary-ntt.hpp
---
