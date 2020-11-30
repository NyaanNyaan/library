---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: modint/montgomery-modint.hpp
    title: modint/montgomery-modint.hpp
  - icon: ':question:'
    path: modint/simd-montgomery.hpp
    title: modint/simd-montgomery.hpp
  - icon: ':heavy_check_mark:'
    path: ntt/arbitrary-ntt.hpp
    title: ntt/arbitrary-ntt.hpp
  - icon: ':question:'
    path: ntt/ntt-avx2.hpp
    title: ntt/ntt-avx2.hpp
  - icon: ':heavy_check_mark:'
    path: tree/centroid-decomposition.hpp
    title: tree/centroid-decomposition.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-graph/yosupo-frequency-table-of-tree-distance.test.cpp
    title: verify/verify-yosupo-graph/yosupo-frequency-table-of-tree-distance.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/tree/frequency-table-of-tree-distance.md
    document_title: "\u9802\u70B9\u9593\u306E\u8DDD\u96E2\u306E\u5EA6\u6570\u5206\u5E03"
    links: []
  bundledCode: "#line 2 \"tree/frequency-table-of-tree-distance.hpp\"\n#include <bits/stdc++.h>\n\
    using namespace std;\n\n#line 3 \"ntt/arbitrary-ntt.hpp\"\nusing namespace std;\n\
    \n#line 3 \"modint/montgomery-modint.hpp\"\nusing namespace std;\n\ntemplate <uint32_t\
    \ mod>\nstruct LazyMontgomeryModInt {\n  using mint = LazyMontgomeryModInt;\n\
    \  using i32 = int32_t;\n  using u32 = uint32_t;\n  using u64 = uint64_t;\n\n\
    \  static constexpr u32 get_r() {\n    u32 ret = mod;\n    for (i32 i = 0; i <\
    \ 4; ++i) ret *= 2 - mod * ret;\n    return ret;\n  }\n\n  static constexpr u32\
    \ r = get_r();\n  static constexpr u32 n2 = -u64(mod) % mod;\n  static_assert(r\
    \ * mod == 1, \"invalid, r * mod != 1\");\n  static_assert(mod < (1 << 30), \"\
    invalid, mod >= 2 ^ 30\");\n  static_assert((mod & 1) == 1, \"invalid, mod % 2\
    \ == 0\");\n\n  u32 a;\n\n  constexpr LazyMontgomeryModInt() : a(0) {}\n  constexpr\
    \ LazyMontgomeryModInt(const int64_t &b)\n      : a(reduce(u64(b % mod + mod)\
    \ * n2)){};\n\n  static constexpr u32 reduce(const u64 &b) {\n    return (b +\
    \ u64(u32(b) * u32(-r)) * mod) >> 32;\n  }\n\n  constexpr mint &operator+=(const\
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
    \ { return mod; }\n};\n#line 3 \"ntt/ntt-avx2.hpp\"\nusing namespace std;\n\n\
    #line 3 \"modint/simd-montgomery.hpp\"\nusing namespace std;\n#include <immintrin.h>\n\
    \n__attribute__((target(\"sse4.2\"))) __attribute__((always_inline)) __m128i\n\
    my128_mullo_epu32(const __m128i &a, const __m128i &b) {\n  return _mm_mullo_epi32(a,\
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
    \ ret), m2),\n                          ret);\n}\n#line 6 \"ntt/ntt-avx2.hpp\"\
    \n\nconstexpr int SZ_FFT_BUF = 1 << 23;\nuint32_t buf1_[SZ_FFT_BUF] __attribute__((aligned(64)));\n\
    uint32_t buf2_[SZ_FFT_BUF] __attribute__((aligned(64)));\n\ntemplate <typename\
    \ mint>\nstruct NTT {\n  static constexpr uint32_t get_pr() {\n    uint32_t mod\
    \ = mint::get_mod();\n    using u64 = uint64_t;\n    u64 ds[32] = {};\n    int\
    \ idx = 0;\n    u64 m = mod - 1;\n    for (u64 i = 2; i * i <= m; ++i) {\n   \
    \   if (m % i == 0) {\n        ds[idx++] = i;\n        while (m % i == 0) m /=\
    \ i;\n      }\n    }\n    if (m != 1) ds[idx++] = m;\n\n    uint32_t pr = 2;\n\
    \    while (1) {\n      int flg = 1;\n      for (int i = 0; i < idx; ++i) {\n\
    \        u64 a = pr, b = (mod - 1) / ds[i], r = 1;\n        while (b) {\n    \
    \      if (b & 1) r = r * a % mod;\n          a = a * a % mod;\n          b >>=\
    \ 1;\n        }\n        if (r == 1) {\n          flg = 0;\n          break;\n\
    \        }\n      }\n      if (flg == 1) break;\n      ++pr;\n    }\n    return\
    \ pr;\n  };\n\n  static constexpr uint32_t mod = mint::get_mod();\n  static constexpr\
    \ uint32_t pr = get_pr();\n  static constexpr int level = __builtin_ctzll(mod\
    \ - 1);\n  mint dw[level], dy[level];\n  mint *buf1, *buf2;\n\n  constexpr NTT()\
    \ {\n    setwy(level);\n    buf1 = reinterpret_cast<mint *>(::buf1_);\n    buf2\
    \ = reinterpret_cast<mint *>(::buf2_);\n  }\n\n  constexpr void setwy(int k) {\n\
    \    mint w[level], y[level];\n    w[k - 1] = mint(pr).pow((mod - 1) / (1 << k));\n\
    \    y[k - 1] = w[k - 1].inverse();\n    for (int i = k - 2; i > 0; --i)\n   \
    \   w[i] = w[i + 1] * w[i + 1], y[i] = y[i + 1] * y[i + 1];\n    dw[0] = dy[0]\
    \ = w[1] * w[1];\n    dw[1] = w[1], dy[1] = y[1], dw[2] = w[2], dy[2] = y[2];\n\
    \    for (int i = 3; i < k; ++i) {\n      dw[i] = dw[i - 1] * y[i - 2] * w[i];\n\
    \      dy[i] = dy[i - 1] * w[i - 2] * y[i];\n    }\n  }\n\n  __attribute__((target(\"\
    avx2\"))) void ntt(mint *a, int n) {\n    int k = n ? __builtin_ctz(n) : 0;\n\
    \    if (k == 0) return;\n    if (k == 1) {\n      mint a1 = a[1];\n      a[1]\
    \ = a[0] - a[1];\n      a[0] = a[0] + a1;\n      return;\n    }\n    if (k & 1)\
    \ {\n      int v = 1 << (k - 1);\n      if (v < 8) {\n        for (int j = 0;\
    \ j < v; ++j) {\n          mint ajv = a[j + v];\n          a[j + v] = a[j] - ajv;\n\
    \          a[j] += ajv;\n        }\n      } else {\n        const __m256i m0 =\
    \ _mm256_set1_epi32(0);\n        const __m256i m2 = _mm256_set1_epi32(mod + mod);\n\
    \        int j0 = 0;\n        int j1 = v;\n        for (; j0 < v; j0 += 8, j1\
    \ += 8) {\n          __m256i T0 = _mm256_loadu_si256((__m256i *)(a + j0));\n \
    \         __m256i T1 = _mm256_loadu_si256((__m256i *)(a + j1));\n          __m256i\
    \ naj = montgomery_add_256(T0, T1, m2, m0);\n          __m256i najv = montgomery_sub_256(T0,\
    \ T1, m2, m0);\n          _mm256_storeu_si256((__m256i *)(a + j0), naj);\n   \
    \       _mm256_storeu_si256((__m256i *)(a + j1), najv);\n        }\n      }\n\
    \    }\n    int u = 1 << (2 + (k & 1));\n    int v = 1 << (k - 2 - (k & 1));\n\
    \    mint one = mint(1);\n    mint imag = dw[1];\n    while (v) {\n      if (v\
    \ == 1) {\n        mint ww = one, xx = one, wx = one;\n        for (int jh = 0;\
    \ jh < u;) {\n          ww = xx * xx, wx = ww * xx;\n          mint t0 = a[jh\
    \ + 0], t1 = a[jh + 1] * xx;\n          mint t2 = a[jh + 2] * ww, t3 = a[jh +\
    \ 3] * wx;\n          mint t0p2 = t0 + t2, t1p3 = t1 + t3;\n          mint t0m2\
    \ = t0 - t2, t1m3 = (t1 - t3) * imag;\n          a[jh + 0] = t0p2 + t1p3, a[jh\
    \ + 1] = t0p2 - t1p3;\n          a[jh + 2] = t0m2 + t1m3, a[jh + 3] = t0m2 - t1m3;\n\
    \          xx *= dw[__builtin_ctz((jh += 4))];\n        }\n      } else if (v\
    \ == 4) {\n        const __m128i m0 = _mm_set1_epi32(0);\n        const __m128i\
    \ m1 = _mm_set1_epi32(mod);\n        const __m128i m2 = _mm_set1_epi32(mod + mod);\n\
    \        const __m128i r = _mm_set1_epi32(mint::r);\n        const __m128i Imag\
    \ = _mm_set1_epi32(imag.a);\n        mint ww = one, xx = one, wx = one;\n    \
    \    for (int jh = 0; jh < u;) {\n          if (jh == 0) {\n            int j0\
    \ = 0;\n            int j1 = v;\n            int j2 = j1 + v;\n            int\
    \ j3 = j2 + v;\n            int je = v;\n            for (; j0 < je; j0 += 4,\
    \ j1 += 4, j2 += 4, j3 += 4) {\n              const __m128i T0 = _mm_loadu_si128((__m128i\
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
    \ (int i = l1; i < M; i++) buf1_[i] = 0;\n      for (int i = l2; i < M; i++) buf2_[i]\
    \ = 0;\n    }\n    const __m256i m0 = _mm256_set1_epi32(0);\n    const __m256i\
    \ m1 = _mm256_set1_epi32(mod);\n    const __m256i r = _mm256_set1_epi32(mint::r);\n\
    \    const __m256i N2 = _mm256_set1_epi32(mint::n2);\n    for (int i = 0; i <\
    \ l1; i += 8) {\n      __m256i a = _mm256_loadu_si256((__m256i *)(buf1_ + i));\n\
    \      __m256i b = montgomery_mul_256(a, N2, r, m1);\n      _mm256_storeu_si256((__m256i\
    \ *)(buf1_ + i), b);\n    }\n    for (int i = 0; i < l2; i += 8) {\n      __m256i\
    \ a = _mm256_loadu_si256((__m256i *)(buf2_ + i));\n      __m256i b = montgomery_mul_256(a,\
    \ N2, r, m1);\n      _mm256_storeu_si256((__m256i *)(buf2_ + i), b);\n    }\n\
    \    ntt(buf1, M);\n    ntt(buf2, M);\n    for (int i = 0; i < M; i += 8) {\n\
    \      __m256i a = _mm256_loadu_si256((__m256i *)(buf1_ + i));\n      __m256i\
    \ b = _mm256_loadu_si256((__m256i *)(buf2_ + i));\n      __m256i c = montgomery_mul_256(a,\
    \ b, r, m1);\n      _mm256_storeu_si256((__m256i *)(buf1_ + i), c);\n    }\n \
    \   intt(buf1, M, false);\n    const __m256i INVM = _mm256_set1_epi32((mint(M).inverse()).a);\n\
    \    for (int i = 0; i < l; i += 8) {\n      __m256i a = _mm256_loadu_si256((__m256i\
    \ *)(buf1_ + i));\n      __m256i b = montgomery_mul_256(a, INVM, r, m1);\n   \
    \   __m256i c = my256_mulhi_epu32(my256_mullo_epu32(b, r), m1);\n      __m256i\
    \ d = _mm256_and_si256(_mm256_cmpgt_epi32(c, m0), m1);\n      __m256i e = _mm256_sub_epi32(d,\
    \ c);\n      _mm256_storeu_si256((__m256i *)(buf1_ + i), e);\n    }\n  }\n\n \
    \ void ntt(vector<mint> &a) {\n    int M = (int)a.size();\n    for (int i = 0;\
    \ i < M; i++) buf1[i].a = a[i].a;\n    ntt(buf1, M);\n    for (int i = 0; i <\
    \ M; i++) a[i].a = buf1[i].a;\n  }\n\n  void intt(vector<mint> &a) {\n    int\
    \ M = (int)a.size();\n    for (int i = 0; i < M; i++) buf1[i].a = a[i].a;\n  \
    \  intt(buf1, M, true);\n    for (int i = 0; i < M; i++) a[i].a = buf1[i].a;\n\
    \  }\n\n  vector<mint> multiply(const vector<mint> &a, const vector<mint> &b)\
    \ {\n    if (a.size() == 0 && b.size() == 0) return vector<mint>{};\n    int l\
    \ = a.size() + b.size() - 1;\n    if (min<int>(a.size(), b.size()) <= 40) {\n\
    \      vector<mint> s(l);\n      for (int i = 0; i < (int)a.size(); ++i)\n   \
    \     for (int j = 0; j < (int)b.size(); ++j) s[i + j] += a[i] * b[j];\n     \
    \ return s;\n    }\n    assert(l <= SZ_FFT_BUF);\n    int M = 4;\n    while (M\
    \ < l) M <<= 1;\n    for (int i = 0; i < (int)a.size(); ++i) buf1[i].a = a[i].a;\n\
    \    for (int i = (int)a.size(); i < M; ++i) buf1[i].a = 0;\n    for (int i =\
    \ 0; i < (int)b.size(); ++i) buf2[i].a = b[i].a;\n    for (int i = (int)b.size();\
    \ i < M; ++i) buf2[i].a = 0;\n    ntt(buf1, M);\n    ntt(buf2, M);\n    for (int\
    \ i = 0; i < M; ++i)\n      buf1[i].a = mint::reduce(uint64_t(buf1[i].a) * buf2[i].a);\n\
    \    intt(buf1, M, false);\n    vector<mint> s(l);\n    mint invm = mint(M).inverse();\n\
    \    for (int i = 0; i < l; ++i) s[i] = buf1[i] * invm;\n    return s;\n  }\n\n\
    \  void ntt_doubling(vector<mint> &a) {\n    int M = (int)a.size();\n    for (int\
    \ i = 0; i < M; i++) buf1[i].a = a[i].a;\n    intt(buf1, M);\n    mint r = 1,\
    \ zeta = mint(pr).pow((mint::get_mod() - 1) / (M << 1));\n    for (int i = 0;\
    \ i < M; i++) buf1[i] *= r, r *= zeta;\n    ntt(buf1, M);\n    a.resize(2 * M);\n\
    \    for (int i = 0; i < M; i++) a[M + i].a = buf1[i].a;\n  }\n};\n#line 7 \"\
    ntt/arbitrary-ntt.hpp\"\n\nnamespace ArbitraryNTT {\nusing i64 = int64_t;\nusing\
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
    }\n}  // namespace ArbitraryNTT\n#line 3 \"tree/centroid-decomposition.hpp\"\n\
    using namespace std;\n\ntemplate <typename G>\nstruct CentroidDecomposition {\n\
    \  const G &g;\n  vector<int> sub;\n  vector<bool> v;\n  vector<vector<int>> tree;\n\
    \  int root;\n\n  CentroidDecomposition(const G &g_, int isbuild = true) : g(g_)\
    \ {\n    sub.resize(g.size(), 0);\n    v.resize(g.size(), false);\n    if (isbuild)\
    \ build();\n  }\n\n  void build() {\n    tree.resize(g.size());\n    root = build_dfs(0);\n\
    \  }\n\n  int get_size(int cur, int par) {\n    sub[cur] = 1;\n    for (auto &dst\
    \ : g[cur]) {\n      if (dst == par || v[dst]) continue;\n      sub[cur] += get_size(dst,\
    \ cur);\n    }\n    return sub[cur];\n  }\n\n  int get_centroid(int cur, int par,\
    \ int mid) {\n    for (auto &dst : g[cur]) {\n      if (dst == par || v[dst])\
    \ continue;\n      if (sub[dst] > mid) return get_centroid(dst, cur, mid);\n \
    \   }\n    return cur;\n  }\n\n  int build_dfs(int cur) {\n    int centroid =\
    \ get_centroid(cur, -1, get_size(cur, -1) / 2);\n    v[centroid] = true;\n   \
    \ for (auto &dst : g[centroid]) {\n      if (!v[dst]) {\n        int nxt = build_dfs(dst);\n\
    \        if (centroid != nxt) tree[centroid].emplace_back(nxt);\n      }\n   \
    \ }\n    v[centroid] = false;\n    return centroid;\n  }\n};\n#line 7 \"tree/frequency-table-of-tree-distance.hpp\"\
    \n\ntemplate <typename G>\nstruct FrequencyTableOfTreeDistance : CentroidDecomposition<G>\
    \ {\n  using CentroidDecomposition<G>::g;\n  using CentroidDecomposition<G>::v;\n\
    \  using CentroidDecomposition<G>::get_size;\n  using CentroidDecomposition<G>::get_centroid;\n\
    \n  FrequencyTableOfTreeDistance(const G &g)\n      : CentroidDecomposition<G>(g,\
    \ false) {}\n\n  vector<long long> count, self;\n\n  void dfs_depth(int cur, int\
    \ par, int d) {\n    while ((int)count.size() <= d) count.emplace_back(0);\n \
    \   while ((int)self.size() <= d) self.emplace_back(0);\n    ++count[d];\n   \
    \ ++self[d];\n    for (int dst : g[cur]) {\n      if (par == dst || v[dst]) continue;\n\
    \      dfs_depth(dst, cur, d + 1);\n    }\n  };\n\n  vector<long long> get(int\
    \ start = 0) {\n    queue<int> Q;\n    int root = get_centroid(start, -1, get_size(start,\
    \ -1) / 2);\n    Q.push(root);\n    vector<long long> ans;\n    ans.reserve(g.size());\n\
    \    count.reserve(g.size());\n    self.reserve(g.size());\n\n    while (!Q.empty())\
    \ {\n      int r = Q.front();\n      Q.pop();\n      count.clear();\n      v[r]\
    \ = 1;\n      for (auto &c : g[r]) {\n        if (v[c]) continue;\n        self.clear();\n\
    \        Q.emplace(get_centroid(c, -1, get_size(c, -1) / 2));\n        dfs_depth(c,\
    \ r, 1);\n        auto self2 = ArbitraryNTT::multiply_u128(self, self);\n    \
    \    while (self2.size() > ans.size()) ans.emplace_back(0);\n        for (int\
    \ i = 0; i < (int)self2.size(); i++) ans[i] -= self2[i];\n      }\n      if (count.empty())\
    \ continue;\n      ++count[0];\n      auto count2 = ArbitraryNTT::multiply_u128(count,\
    \ count);\n      while (count2.size() > ans.size()) ans.emplace_back(0);\n   \
    \   for (int i = 0; i < (int)count2.size(); i++) ans[i] += count2[i];\n    }\n\
    \n    for (auto &x : ans) x >>= 1;\n    return ans;\n  }\n};\n\n/**\n * @brief\
    \ \u9802\u70B9\u9593\u306E\u8DDD\u96E2\u306E\u5EA6\u6570\u5206\u5E03\n * @docs\
    \ docs/tree/frequency-table-of-tree-distance.md\n */\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\n\n#include\
    \ \"../ntt/arbitrary-ntt.hpp\"\n#include \"./centroid-decomposition.hpp\"\n\n\
    template <typename G>\nstruct FrequencyTableOfTreeDistance : CentroidDecomposition<G>\
    \ {\n  using CentroidDecomposition<G>::g;\n  using CentroidDecomposition<G>::v;\n\
    \  using CentroidDecomposition<G>::get_size;\n  using CentroidDecomposition<G>::get_centroid;\n\
    \n  FrequencyTableOfTreeDistance(const G &g)\n      : CentroidDecomposition<G>(g,\
    \ false) {}\n\n  vector<long long> count, self;\n\n  void dfs_depth(int cur, int\
    \ par, int d) {\n    while ((int)count.size() <= d) count.emplace_back(0);\n \
    \   while ((int)self.size() <= d) self.emplace_back(0);\n    ++count[d];\n   \
    \ ++self[d];\n    for (int dst : g[cur]) {\n      if (par == dst || v[dst]) continue;\n\
    \      dfs_depth(dst, cur, d + 1);\n    }\n  };\n\n  vector<long long> get(int\
    \ start = 0) {\n    queue<int> Q;\n    int root = get_centroid(start, -1, get_size(start,\
    \ -1) / 2);\n    Q.push(root);\n    vector<long long> ans;\n    ans.reserve(g.size());\n\
    \    count.reserve(g.size());\n    self.reserve(g.size());\n\n    while (!Q.empty())\
    \ {\n      int r = Q.front();\n      Q.pop();\n      count.clear();\n      v[r]\
    \ = 1;\n      for (auto &c : g[r]) {\n        if (v[c]) continue;\n        self.clear();\n\
    \        Q.emplace(get_centroid(c, -1, get_size(c, -1) / 2));\n        dfs_depth(c,\
    \ r, 1);\n        auto self2 = ArbitraryNTT::multiply_u128(self, self);\n    \
    \    while (self2.size() > ans.size()) ans.emplace_back(0);\n        for (int\
    \ i = 0; i < (int)self2.size(); i++) ans[i] -= self2[i];\n      }\n      if (count.empty())\
    \ continue;\n      ++count[0];\n      auto count2 = ArbitraryNTT::multiply_u128(count,\
    \ count);\n      while (count2.size() > ans.size()) ans.emplace_back(0);\n   \
    \   for (int i = 0; i < (int)count2.size(); i++) ans[i] += count2[i];\n    }\n\
    \n    for (auto &x : ans) x >>= 1;\n    return ans;\n  }\n};\n\n/**\n * @brief\
    \ \u9802\u70B9\u9593\u306E\u8DDD\u96E2\u306E\u5EA6\u6570\u5206\u5E03\n * @docs\
    \ docs/tree/frequency-table-of-tree-distance.md\n */\n"
  dependsOn:
  - ntt/arbitrary-ntt.hpp
  - modint/montgomery-modint.hpp
  - ntt/ntt-avx2.hpp
  - modint/simd-montgomery.hpp
  - tree/centroid-decomposition.hpp
  isVerificationFile: false
  path: tree/frequency-table-of-tree-distance.hpp
  requiredBy: []
  timestamp: '2020-11-27 00:47:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-graph/yosupo-frequency-table-of-tree-distance.test.cpp
documentation_of: tree/frequency-table-of-tree-distance.hpp
layout: document
redirect_from:
- /library/tree/frequency-table-of-tree-distance.hpp
- /library/tree/frequency-table-of-tree-distance.hpp.html
title: "\u9802\u70B9\u9593\u306E\u8DDD\u96E2\u306E\u5EA6\u6570\u5206\u5E03"
---
## 頂点間の距離の度数分布

頂点間の距離の度数分布を$\mathrm{O}(n \log^2 n)$で計算するライブラリ。

#### 使い方

- `FrequencyTableOfTreeDistance(const G &g)`: 重心分解用のデータ構造を構築する。
- `get(start = 0)`: startを根として計算した結果を返す。
