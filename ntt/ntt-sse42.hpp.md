---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: modint/simd-montgomery.hpp
    title: modint/simd-montgomery.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-ntt/yosupo-convolution-ntt-sse42.test.cpp
    title: verify/verify-yosupo-ntt/yosupo-convolution-ntt-sse42.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"ntt/ntt-sse42.hpp\"\n\n\n\n#line 2 \"modint/simd-montgomery.hpp\"\
    \n\n#include <immintrin.h>\n\n__attribute__((target(\"sse4.2\"))) inline __m128i\
    \ my128_mullo_epu32(\n    const __m128i &a, const __m128i &b) {\n  return _mm_mullo_epi32(a,\
    \ b);\n}\n\n__attribute__((target(\"sse4.2\"))) inline __m128i my128_mulhi_epu32(\n\
    \    const __m128i &a, const __m128i &b) {\n  __m128i a13 = _mm_shuffle_epi32(a,\
    \ 0xF5);\n  __m128i b13 = _mm_shuffle_epi32(b, 0xF5);\n  __m128i prod02 = _mm_mul_epu32(a,\
    \ b);\n  __m128i prod13 = _mm_mul_epu32(a13, b13);\n  __m128i prod = _mm_unpackhi_epi64(_mm_unpacklo_epi32(prod02,\
    \ prod13),\n                                    _mm_unpackhi_epi32(prod02, prod13));\n\
    \  return prod;\n}\n\n__attribute__((target(\"sse4.2\"))) inline __m128i montgomery_mul_128(\n\
    \    const __m128i &a, const __m128i &b, const __m128i &r, const __m128i &m1)\
    \ {\n  return _mm_sub_epi32(\n      _mm_add_epi32(my128_mulhi_epu32(a, b), m1),\n\
    \      my128_mulhi_epu32(my128_mullo_epu32(my128_mullo_epu32(a, b), r), m1));\n\
    }\n\n__attribute__((target(\"sse4.2\"))) inline __m128i montgomery_add_128(\n\
    \    const __m128i &a, const __m128i &b, const __m128i &m2, const __m128i &m0)\
    \ {\n  __m128i ret = _mm_sub_epi32(_mm_add_epi32(a, b), m2);\n  return _mm_add_epi32(_mm_and_si128(_mm_cmpgt_epi32(m0,\
    \ ret), m2), ret);\n}\n\n__attribute__((target(\"sse4.2\"))) inline __m128i montgomery_sub_128(\n\
    \    const __m128i &a, const __m128i &b, const __m128i &m2, const __m128i &m0)\
    \ {\n  __m128i ret = _mm_sub_epi32(a, b);\n  return _mm_add_epi32(_mm_and_si128(_mm_cmpgt_epi32(m0,\
    \ ret), m2), ret);\n}\n\n__attribute__((target(\"avx2\"))) inline __m256i my256_mullo_epu32(\n\
    \    const __m256i &a, const __m256i &b) {\n  return _mm256_mullo_epi32(a, b);\n\
    }\n\n__attribute__((target(\"avx2\"))) inline __m256i my256_mulhi_epu32(\n   \
    \ const __m256i &a, const __m256i &b) {\n  __m256i a13 = _mm256_shuffle_epi32(a,\
    \ 0xF5);\n  __m256i b13 = _mm256_shuffle_epi32(b, 0xF5);\n  __m256i prod02 = _mm256_mul_epu32(a,\
    \ b);\n  __m256i prod13 = _mm256_mul_epu32(a13, b13);\n  __m256i prod = _mm256_unpackhi_epi64(_mm256_unpacklo_epi32(prod02,\
    \ prod13),\n                                       _mm256_unpackhi_epi32(prod02,\
    \ prod13));\n  return prod;\n}\n\n__attribute__((target(\"avx2\"))) inline __m256i\
    \ montgomery_mul_256(\n    const __m256i &a, const __m256i &b, const __m256i &r,\
    \ const __m256i &m1) {\n  return _mm256_sub_epi32(\n      _mm256_add_epi32(my256_mulhi_epu32(a,\
    \ b), m1),\n      my256_mulhi_epu32(my256_mullo_epu32(my256_mullo_epu32(a, b),\
    \ r), m1));\n}\n\n__attribute__((target(\"avx2\"))) inline __m256i montgomery_add_256(\n\
    \    const __m256i &a, const __m256i &b, const __m256i &m2, const __m256i &m0)\
    \ {\n  __m256i ret = _mm256_sub_epi32(_mm256_add_epi32(a, b), m2);\n  return _mm256_add_epi32(_mm256_and_si256(_mm256_cmpgt_epi32(m0,\
    \ ret), m2),\n                          ret);\n}\n\n__attribute__((target(\"avx2\"\
    ))) inline __m256i montgomery_sub_256(\n    const __m256i &a, const __m256i &b,\
    \ const __m256i &m2, const __m256i &m0) {\n  __m256i ret = _mm256_sub_epi32(a,\
    \ b);\n  return _mm256_add_epi32(_mm256_and_si256(_mm256_cmpgt_epi32(m0, ret),\
    \ m2),\n                          ret);\n}\n#line 6 \"ntt/ntt-sse42.hpp\"\n\n\
    constexpr int SZ_FFT_BUF = 1 << 23;\nuint32_t buf1_[SZ_FFT_BUF] __attribute__((aligned(64)));\n\
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
    \ - 1);\n  mint dw[level], dy[level];\n  mint *buf1, *buf2;\n\n  NTT() {\n   \
    \ setwy(level);\n    buf1 = reinterpret_cast<mint *>(::buf1_);\n    buf2 = reinterpret_cast<mint\
    \ *>(::buf2_);\n  }\n\n  constexpr void setwy(int k) {\n    mint w[level], y[level];\n\
    \    w[k - 1] = mint(pr).pow((mod - 1) / (1 << k));\n    y[k - 1] = w[k - 1].inverse();\n\
    \    for (int i = k - 2; i > 0; --i)\n      w[i] = w[i + 1] * w[i + 1], y[i] =\
    \ y[i + 1] * y[i + 1];\n    dw[1] = w[1], dy[1] = y[1], dw[2] = w[2], dy[2] =\
    \ y[2];\n    for (int i = 3; i < k; ++i) {\n      dw[i] = dw[i - 1] * y[i - 2]\
    \ * w[i];\n      dy[i] = dy[i - 1] * w[i - 2] * y[i];\n    }\n  }\n\n  __attribute__((target(\"\
    sse4.2\"))) void ntt(mint *a, int n) {\n    int k = n ? __builtin_ctz(n) : 0;\n\
    \    if (k == 0) return;\n    if (k == 1) {\n      mint a1 = a[1];\n      a[1]\
    \ = a[0] - a[1];\n      a[0] = a[0] + a1;\n      return;\n    }\n    if (k & 1)\
    \ {\n      int v = 1 << (k - 1);\n      for (int j = 0; j < v; ++j) {\n      \
    \  mint ajv = a[j + v];\n        a[j + v] = a[j] - ajv;\n        a[j] += ajv;\n\
    \      }\n    }\n    int u = 1 << (2 + (k & 1));\n    int v = 1 << (k - 2 - (k\
    \ & 1));\n    mint one = mint(1);\n    mint imag = dw[1];\n    const __m128i m0\
    \ = _mm_set1_epi32(0);\n    const __m128i m1 = _mm_set1_epi32(mod);\n    const\
    \ __m128i m2 = _mm_set1_epi32(mod + mod);\n    const __m128i r = _mm_set1_epi32(mint::r);\n\
    \    const __m128i Imag = _mm_set1_epi32(imag.a);\n    while (v) {\n      if (v\
    \ == 1) {\n        mint ww = one, xx = one, wx = one;\n        for (int jh = 0;\
    \ jh < u;) {\n          ww = xx * xx, wx = ww * xx;\n          mint t0 = a[jh\
    \ + 0], t1 = a[jh + 1] * xx;\n          mint t2 = a[jh + 2] * ww, t3 = a[jh +\
    \ 3] * wx;\n          mint t0p2 = t0 + t2, t1p3 = t1 + t3;\n          mint t0m2\
    \ = t0 - t2, t1m3 = (t1 - t3) * imag;\n          a[jh + 0] = t0p2 + t1p3, a[jh\
    \ + 1] = t0p2 - t1p3;\n          a[jh + 2] = t0m2 + t1m3, a[jh + 3] = t0m2 - t1m3;\n\
    \          xx *= dw[__builtin_ctz((jh += 4))];\n        }\n      } else {\n  \
    \      mint ww = one, xx = one, wx = one;\n        for (int jh = 0; jh < u;) {\n\
    \          if (jh == 0) {\n            int j0 = 0;\n            int j1 = v;\n\
    \            int j2 = j1 + v;\n            int j3 = j2 + v;\n            int je\
    \ = v;\n            for (; j0 < je; j0 += 4, j1 += 4, j2 += 4, j3 += 4) {\n  \
    \            __m128i T0 = _mm_loadu_si128((__m128i *)(a + j0));\n            \
    \  __m128i T1 = _mm_loadu_si128((__m128i *)(a + j1));\n              __m128i T2\
    \ = _mm_loadu_si128((__m128i *)(a + j2));\n              __m128i T3 = _mm_loadu_si128((__m128i\
    \ *)(a + j3));\n              __m128i T0P2 = montgomery_add_128(T0, T2, m2, m0);\n\
    \              __m128i T1P3 = montgomery_add_128(T1, T3, m2, m0);\n          \
    \    __m128i T0M2 = montgomery_sub_128(T0, T2, m2, m0);\n              __m128i\
    \ T1M3 =\n                  montgomery_mul_128(montgomery_sub_128(T1, T3, m2,\
    \ m0), Imag, r, m1);\n              _mm_storeu_si128((__m128i *)(a + j0),\n  \
    \                             montgomery_add_128(T0P2, T1P3, m2, m0));\n     \
    \         _mm_storeu_si128((__m128i *)(a + j1),\n                            \
    \   montgomery_sub_128(T0P2, T1P3, m2, m0));\n              _mm_storeu_si128((__m128i\
    \ *)(a + j2),\n                               montgomery_add_128(T0M2, T1M3, m2,\
    \ m0));\n              _mm_storeu_si128((__m128i *)(a + j3),\n               \
    \                montgomery_sub_128(T0M2, T1M3, m2, m0));\n            }\n   \
    \       } else {\n            ww = xx * xx, wx = ww * xx;\n            __m128i\
    \ WW = _mm_set1_epi32(ww.a);\n            __m128i WX = _mm_set1_epi32(wx.a);\n\
    \            __m128i XX = _mm_set1_epi32(xx.a);\n            int j0 = jh * v;\n\
    \            int j1 = j0 + v;\n            int j2 = j1 + v;\n            int j3\
    \ = j2 + v;\n            int je = j1;\n            for (; j0 < je; j0 += 4, j1\
    \ += 4, j2 += 4, j3 += 4) {\n              __m128i T0 = _mm_loadu_si128((__m128i\
    \ *)(a + j0));\n              __m128i T1 = _mm_loadu_si128((__m128i *)(a + j1));\n\
    \              __m128i T2 = _mm_loadu_si128((__m128i *)(a + j2));\n          \
    \    __m128i T3 = _mm_loadu_si128((__m128i *)(a + j3));\n              T1 = montgomery_mul_128(T1,\
    \ XX, r, m1);\n              T2 = montgomery_mul_128(T2, WW, r, m1);\n       \
    \       T3 = montgomery_mul_128(T3, WX, r, m1);\n              __m128i T0P2 =\
    \ montgomery_add_128(T0, T2, m2, m0);\n              __m128i T1P3 = montgomery_add_128(T1,\
    \ T3, m2, m0);\n              __m128i T0M2 = montgomery_sub_128(T0, T2, m2, m0);\n\
    \              __m128i T1M3 =\n                  montgomery_mul_128(montgomery_sub_128(T1,\
    \ T3, m2, m0), Imag, r, m1);\n              _mm_storeu_si128((__m128i *)(a + j0),\n\
    \                               montgomery_add_128(T0P2, T1P3, m2, m0));\n   \
    \           _mm_storeu_si128((__m128i *)(a + j1),\n                          \
    \     montgomery_sub_128(T0P2, T1P3, m2, m0));\n              _mm_storeu_si128((__m128i\
    \ *)(a + j2),\n                               montgomery_add_128(T0M2, T1M3, m2,\
    \ m0));\n              _mm_storeu_si128((__m128i *)(a + j3),\n               \
    \                montgomery_sub_128(T0M2, T1M3, m2, m0));\n            }\n   \
    \       }\n          xx *= dw[__builtin_ctz((jh += 4))];\n        }\n      }\n\
    \      u <<= 2;\n      v >>= 2;\n    }\n  }\n\n  __attribute__((target(\"sse4.2\"\
    ))) void intt(mint *a, int n,\n                                              int\
    \ normalize = true) {\n    int k = n ? __builtin_ctz(n) : 0;\n    if (k == 0)\
    \ return;\n    if (k == 1) {\n      mint a1 = a[1];\n      a[1] = a[0] - a[1];\n\
    \      a[0] = a[0] + a1;\n      return;\n    }\n    int u = 1 << (k - 2);\n  \
    \  int v = 1;\n    mint one = mint(1);\n    mint imag = dy[1];\n    const __m128i\
    \ m0 = _mm_set1_epi32(0);\n    const __m128i m1 = _mm_set1_epi32(mod);\n    const\
    \ __m128i m2 = _mm_set1_epi32(mod + mod);\n    const __m128i r = _mm_set1_epi32(mint::r);\n\
    \    const __m128i Imag = _mm_set1_epi32(imag.a);\n    while (u) {\n      if (v\
    \ == 1) {\n        mint ww = one, xx = one, yy = one;\n        u <<= 2;\n    \
    \    for (int jh = 0; jh < u;) {\n          ww = xx * xx, yy = xx * imag;\n  \
    \        mint t0 = a[jh + 0], t1 = a[jh + 1];\n          mint t2 = a[jh + 2],\
    \ t3 = a[jh + 3];\n          mint t0p1 = t0 + t1, t2p3 = t2 + t3;\n          mint\
    \ t0m1 = (t0 - t1) * xx, t2m3 = (t2 - t3) * yy;\n          a[jh + 0] = t0p1 +\
    \ t2p3, a[jh + 2] = (t0p1 - t2p3) * ww;\n          a[jh + 1] = t0m1 + t2m3, a[jh\
    \ + 3] = (t0m1 - t2m3) * ww;\n          xx *= dy[__builtin_ctz(jh += 4)];\n  \
    \      }\n      } else {\n        mint ww = one, xx = one, yy = one;\n       \
    \ u <<= 2;\n        for (int jh = 0; jh < u;) {\n          if (jh == 0) {\n  \
    \          int j0 = 0;\n            int j1 = v;\n            int j2 = v + v;\n\
    \            int j3 = j2 + v;\n            for (; j0 < v; j0 += 4, j1 += 4, j2\
    \ += 4, j3 += 4) {\n              __m128i T0 = _mm_loadu_si128((__m128i *)(a +\
    \ j0));\n              __m128i T1 = _mm_loadu_si128((__m128i *)(a + j1));\n  \
    \            __m128i T2 = _mm_loadu_si128((__m128i *)(a + j2));\n            \
    \  __m128i T3 = _mm_loadu_si128((__m128i *)(a + j3));\n              __m128i T0P1\
    \ = montgomery_add_128(T0, T1, m2, m0);\n              __m128i T2P3 = montgomery_add_128(T2,\
    \ T3, m2, m0);\n              __m128i T0M1 = montgomery_sub_128(T0, T1, m2, m0);\n\
    \              __m128i T2M3 =\n                  montgomery_mul_128(montgomery_sub_128(T2,\
    \ T3, m2, m0), Imag, r, m1);\n              _mm_storeu_si128((__m128i *)(a + j0),\n\
    \                               montgomery_add_128(T0P1, T2P3, m2, m0));\n   \
    \           _mm_storeu_si128((__m128i *)(a + j2),\n                          \
    \     montgomery_sub_128(T0P1, T2P3, m2, m0));\n              _mm_storeu_si128((__m128i\
    \ *)(a + j1),\n                               montgomery_add_128(T0M1, T2M3, m2,\
    \ m0));\n              _mm_storeu_si128((__m128i *)(a + j3),\n               \
    \                montgomery_sub_128(T0M1, T2M3, m2, m0));\n            }\n   \
    \       } else {\n            ww = xx * xx, yy = xx * imag;\n            __m128i\
    \ WW = _mm_set1_epi32(ww.a);\n            __m128i XX = _mm_set1_epi32(xx.a);\n\
    \            __m128i YY = _mm_set1_epi32(yy.a);\n            int j0 = jh * v;\n\
    \            int j1 = j0 + v;\n            int j2 = j1 + v;\n            int j3\
    \ = j2 + v;\n            int je = j1;\n            for (; j0 < je; j0 += 4, j1\
    \ += 4, j2 += 4, j3 += 4) {\n              __m128i T0 = _mm_loadu_si128((__m128i\
    \ *)(a + j0));\n              __m128i T1 = _mm_loadu_si128((__m128i *)(a + j1));\n\
    \              __m128i T2 = _mm_loadu_si128((__m128i *)(a + j2));\n          \
    \    __m128i T3 = _mm_loadu_si128((__m128i *)(a + j3));\n              __m128i\
    \ T0P1 = montgomery_add_128(T0, T1, m2, m0);\n              __m128i T2P3 = montgomery_add_128(T2,\
    \ T3, m2, m0);\n              __m128i T0M1 =\n                  montgomery_mul_128(montgomery_sub_128(T0,\
    \ T1, m2, m0), XX, r, m1);\n              __m128i T2M3 =\n                  montgomery_mul_128(montgomery_sub_128(T2,\
    \ T3, m2, m0), YY, r, m1);\n              _mm_storeu_si128((__m128i *)(a + j0),\n\
    \                               montgomery_add_128(T0P1, T2P3, m2, m0));\n   \
    \           _mm_storeu_si128(\n                  (__m128i *)(a + j2),\n      \
    \            montgomery_mul_128(montgomery_sub_128(T0P1, T2P3, m2, m0), WW, r,\n\
    \                                 m1));\n              _mm_storeu_si128((__m128i\
    \ *)(a + j1),\n                               montgomery_add_128(T0M1, T2M3, m2,\
    \ m0));\n              _mm_storeu_si128(\n                  (__m128i *)(a + j3),\n\
    \                  montgomery_mul_128(montgomery_sub_128(T0M1, T2M3, m2, m0),\
    \ WW, r,\n                                 m1));\n            }\n          }\n\
    \          xx *= dy[__builtin_ctz(jh += 4)];\n        }\n      }\n      u >>=\
    \ 4;\n      v <<= 2;\n    }\n    if (k & 1) {\n      u = 1 << (k - 1);\n     \
    \ for (int j = 0; j < u; ++j) {\n        mint ajv = a[j] - a[j + u];\n       \
    \ a[j] += a[j + u];\n        a[j + u] = ajv;\n      }\n    }\n    if (normalize)\
    \ {\n      mint invn = one / mint(n);\n      for (int i = 0; i < n; i++) a[i]\
    \ *= invn;\n    }\n  }\n\n  constexpr vector<mint> multiply(const vector<mint>\
    \ &a,\n                                  const vector<mint> &b) {\n    int l =\
    \ a.size() + b.size() - 1;\n    if (min<int>(a.size(), b.size()) <= 40) {\n  \
    \    vector<mint> s(l);\n      for (int i = 0; i < (int)a.size(); ++i)\n     \
    \   for (int j = 0; j < (int)b.size(); ++j) s[i + j] += a[i] * b[j];\n      return\
    \ s;\n    }\n    int M = 4;\n    while (M < l) M <<= 1;\n    for (int i = 0; i\
    \ < (int)a.size(); ++i) buf1[i].a = a[i].a;\n    for (int i = (int)a.size(); i\
    \ < M; ++i) buf1[i].a = 0;\n    for (int i = 0; i < (int)b.size(); ++i) buf2[i].a\
    \ = b[i].a;\n    for (int i = (int)b.size(); i < M; ++i) buf2[i].a = 0;\n    ntt(buf1,\
    \ M);\n    ntt(buf2, M);\n    for (int i = 0; i < M; ++i)\n      buf1[i].a = mint::reduce(uint64_t(buf1[i].a)\
    \ * buf2[i].a);\n    intt(buf1, M, false);\n    vector<mint> s(l);\n    mint invm\
    \ = mint(M).inverse();\n    for (int i = 0; i < l; ++i) s[i] = buf1[i] * invm;\n\
    \    return s;\n  }\n};\n"
  code: "#pragma once\n\n\n\n#include \"../modint/simd-montgomery.hpp\"\n\nconstexpr\
    \ int SZ_FFT_BUF = 1 << 23;\nuint32_t buf1_[SZ_FFT_BUF] __attribute__((aligned(64)));\n\
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
    \ - 1);\n  mint dw[level], dy[level];\n  mint *buf1, *buf2;\n\n  NTT() {\n   \
    \ setwy(level);\n    buf1 = reinterpret_cast<mint *>(::buf1_);\n    buf2 = reinterpret_cast<mint\
    \ *>(::buf2_);\n  }\n\n  constexpr void setwy(int k) {\n    mint w[level], y[level];\n\
    \    w[k - 1] = mint(pr).pow((mod - 1) / (1 << k));\n    y[k - 1] = w[k - 1].inverse();\n\
    \    for (int i = k - 2; i > 0; --i)\n      w[i] = w[i + 1] * w[i + 1], y[i] =\
    \ y[i + 1] * y[i + 1];\n    dw[1] = w[1], dy[1] = y[1], dw[2] = w[2], dy[2] =\
    \ y[2];\n    for (int i = 3; i < k; ++i) {\n      dw[i] = dw[i - 1] * y[i - 2]\
    \ * w[i];\n      dy[i] = dy[i - 1] * w[i - 2] * y[i];\n    }\n  }\n\n  __attribute__((target(\"\
    sse4.2\"))) void ntt(mint *a, int n) {\n    int k = n ? __builtin_ctz(n) : 0;\n\
    \    if (k == 0) return;\n    if (k == 1) {\n      mint a1 = a[1];\n      a[1]\
    \ = a[0] - a[1];\n      a[0] = a[0] + a1;\n      return;\n    }\n    if (k & 1)\
    \ {\n      int v = 1 << (k - 1);\n      for (int j = 0; j < v; ++j) {\n      \
    \  mint ajv = a[j + v];\n        a[j + v] = a[j] - ajv;\n        a[j] += ajv;\n\
    \      }\n    }\n    int u = 1 << (2 + (k & 1));\n    int v = 1 << (k - 2 - (k\
    \ & 1));\n    mint one = mint(1);\n    mint imag = dw[1];\n    const __m128i m0\
    \ = _mm_set1_epi32(0);\n    const __m128i m1 = _mm_set1_epi32(mod);\n    const\
    \ __m128i m2 = _mm_set1_epi32(mod + mod);\n    const __m128i r = _mm_set1_epi32(mint::r);\n\
    \    const __m128i Imag = _mm_set1_epi32(imag.a);\n    while (v) {\n      if (v\
    \ == 1) {\n        mint ww = one, xx = one, wx = one;\n        for (int jh = 0;\
    \ jh < u;) {\n          ww = xx * xx, wx = ww * xx;\n          mint t0 = a[jh\
    \ + 0], t1 = a[jh + 1] * xx;\n          mint t2 = a[jh + 2] * ww, t3 = a[jh +\
    \ 3] * wx;\n          mint t0p2 = t0 + t2, t1p3 = t1 + t3;\n          mint t0m2\
    \ = t0 - t2, t1m3 = (t1 - t3) * imag;\n          a[jh + 0] = t0p2 + t1p3, a[jh\
    \ + 1] = t0p2 - t1p3;\n          a[jh + 2] = t0m2 + t1m3, a[jh + 3] = t0m2 - t1m3;\n\
    \          xx *= dw[__builtin_ctz((jh += 4))];\n        }\n      } else {\n  \
    \      mint ww = one, xx = one, wx = one;\n        for (int jh = 0; jh < u;) {\n\
    \          if (jh == 0) {\n            int j0 = 0;\n            int j1 = v;\n\
    \            int j2 = j1 + v;\n            int j3 = j2 + v;\n            int je\
    \ = v;\n            for (; j0 < je; j0 += 4, j1 += 4, j2 += 4, j3 += 4) {\n  \
    \            __m128i T0 = _mm_loadu_si128((__m128i *)(a + j0));\n            \
    \  __m128i T1 = _mm_loadu_si128((__m128i *)(a + j1));\n              __m128i T2\
    \ = _mm_loadu_si128((__m128i *)(a + j2));\n              __m128i T3 = _mm_loadu_si128((__m128i\
    \ *)(a + j3));\n              __m128i T0P2 = montgomery_add_128(T0, T2, m2, m0);\n\
    \              __m128i T1P3 = montgomery_add_128(T1, T3, m2, m0);\n          \
    \    __m128i T0M2 = montgomery_sub_128(T0, T2, m2, m0);\n              __m128i\
    \ T1M3 =\n                  montgomery_mul_128(montgomery_sub_128(T1, T3, m2,\
    \ m0), Imag, r, m1);\n              _mm_storeu_si128((__m128i *)(a + j0),\n  \
    \                             montgomery_add_128(T0P2, T1P3, m2, m0));\n     \
    \         _mm_storeu_si128((__m128i *)(a + j1),\n                            \
    \   montgomery_sub_128(T0P2, T1P3, m2, m0));\n              _mm_storeu_si128((__m128i\
    \ *)(a + j2),\n                               montgomery_add_128(T0M2, T1M3, m2,\
    \ m0));\n              _mm_storeu_si128((__m128i *)(a + j3),\n               \
    \                montgomery_sub_128(T0M2, T1M3, m2, m0));\n            }\n   \
    \       } else {\n            ww = xx * xx, wx = ww * xx;\n            __m128i\
    \ WW = _mm_set1_epi32(ww.a);\n            __m128i WX = _mm_set1_epi32(wx.a);\n\
    \            __m128i XX = _mm_set1_epi32(xx.a);\n            int j0 = jh * v;\n\
    \            int j1 = j0 + v;\n            int j2 = j1 + v;\n            int j3\
    \ = j2 + v;\n            int je = j1;\n            for (; j0 < je; j0 += 4, j1\
    \ += 4, j2 += 4, j3 += 4) {\n              __m128i T0 = _mm_loadu_si128((__m128i\
    \ *)(a + j0));\n              __m128i T1 = _mm_loadu_si128((__m128i *)(a + j1));\n\
    \              __m128i T2 = _mm_loadu_si128((__m128i *)(a + j2));\n          \
    \    __m128i T3 = _mm_loadu_si128((__m128i *)(a + j3));\n              T1 = montgomery_mul_128(T1,\
    \ XX, r, m1);\n              T2 = montgomery_mul_128(T2, WW, r, m1);\n       \
    \       T3 = montgomery_mul_128(T3, WX, r, m1);\n              __m128i T0P2 =\
    \ montgomery_add_128(T0, T2, m2, m0);\n              __m128i T1P3 = montgomery_add_128(T1,\
    \ T3, m2, m0);\n              __m128i T0M2 = montgomery_sub_128(T0, T2, m2, m0);\n\
    \              __m128i T1M3 =\n                  montgomery_mul_128(montgomery_sub_128(T1,\
    \ T3, m2, m0), Imag, r, m1);\n              _mm_storeu_si128((__m128i *)(a + j0),\n\
    \                               montgomery_add_128(T0P2, T1P3, m2, m0));\n   \
    \           _mm_storeu_si128((__m128i *)(a + j1),\n                          \
    \     montgomery_sub_128(T0P2, T1P3, m2, m0));\n              _mm_storeu_si128((__m128i\
    \ *)(a + j2),\n                               montgomery_add_128(T0M2, T1M3, m2,\
    \ m0));\n              _mm_storeu_si128((__m128i *)(a + j3),\n               \
    \                montgomery_sub_128(T0M2, T1M3, m2, m0));\n            }\n   \
    \       }\n          xx *= dw[__builtin_ctz((jh += 4))];\n        }\n      }\n\
    \      u <<= 2;\n      v >>= 2;\n    }\n  }\n\n  __attribute__((target(\"sse4.2\"\
    ))) void intt(mint *a, int n,\n                                              int\
    \ normalize = true) {\n    int k = n ? __builtin_ctz(n) : 0;\n    if (k == 0)\
    \ return;\n    if (k == 1) {\n      mint a1 = a[1];\n      a[1] = a[0] - a[1];\n\
    \      a[0] = a[0] + a1;\n      return;\n    }\n    int u = 1 << (k - 2);\n  \
    \  int v = 1;\n    mint one = mint(1);\n    mint imag = dy[1];\n    const __m128i\
    \ m0 = _mm_set1_epi32(0);\n    const __m128i m1 = _mm_set1_epi32(mod);\n    const\
    \ __m128i m2 = _mm_set1_epi32(mod + mod);\n    const __m128i r = _mm_set1_epi32(mint::r);\n\
    \    const __m128i Imag = _mm_set1_epi32(imag.a);\n    while (u) {\n      if (v\
    \ == 1) {\n        mint ww = one, xx = one, yy = one;\n        u <<= 2;\n    \
    \    for (int jh = 0; jh < u;) {\n          ww = xx * xx, yy = xx * imag;\n  \
    \        mint t0 = a[jh + 0], t1 = a[jh + 1];\n          mint t2 = a[jh + 2],\
    \ t3 = a[jh + 3];\n          mint t0p1 = t0 + t1, t2p3 = t2 + t3;\n          mint\
    \ t0m1 = (t0 - t1) * xx, t2m3 = (t2 - t3) * yy;\n          a[jh + 0] = t0p1 +\
    \ t2p3, a[jh + 2] = (t0p1 - t2p3) * ww;\n          a[jh + 1] = t0m1 + t2m3, a[jh\
    \ + 3] = (t0m1 - t2m3) * ww;\n          xx *= dy[__builtin_ctz(jh += 4)];\n  \
    \      }\n      } else {\n        mint ww = one, xx = one, yy = one;\n       \
    \ u <<= 2;\n        for (int jh = 0; jh < u;) {\n          if (jh == 0) {\n  \
    \          int j0 = 0;\n            int j1 = v;\n            int j2 = v + v;\n\
    \            int j3 = j2 + v;\n            for (; j0 < v; j0 += 4, j1 += 4, j2\
    \ += 4, j3 += 4) {\n              __m128i T0 = _mm_loadu_si128((__m128i *)(a +\
    \ j0));\n              __m128i T1 = _mm_loadu_si128((__m128i *)(a + j1));\n  \
    \            __m128i T2 = _mm_loadu_si128((__m128i *)(a + j2));\n            \
    \  __m128i T3 = _mm_loadu_si128((__m128i *)(a + j3));\n              __m128i T0P1\
    \ = montgomery_add_128(T0, T1, m2, m0);\n              __m128i T2P3 = montgomery_add_128(T2,\
    \ T3, m2, m0);\n              __m128i T0M1 = montgomery_sub_128(T0, T1, m2, m0);\n\
    \              __m128i T2M3 =\n                  montgomery_mul_128(montgomery_sub_128(T2,\
    \ T3, m2, m0), Imag, r, m1);\n              _mm_storeu_si128((__m128i *)(a + j0),\n\
    \                               montgomery_add_128(T0P1, T2P3, m2, m0));\n   \
    \           _mm_storeu_si128((__m128i *)(a + j2),\n                          \
    \     montgomery_sub_128(T0P1, T2P3, m2, m0));\n              _mm_storeu_si128((__m128i\
    \ *)(a + j1),\n                               montgomery_add_128(T0M1, T2M3, m2,\
    \ m0));\n              _mm_storeu_si128((__m128i *)(a + j3),\n               \
    \                montgomery_sub_128(T0M1, T2M3, m2, m0));\n            }\n   \
    \       } else {\n            ww = xx * xx, yy = xx * imag;\n            __m128i\
    \ WW = _mm_set1_epi32(ww.a);\n            __m128i XX = _mm_set1_epi32(xx.a);\n\
    \            __m128i YY = _mm_set1_epi32(yy.a);\n            int j0 = jh * v;\n\
    \            int j1 = j0 + v;\n            int j2 = j1 + v;\n            int j3\
    \ = j2 + v;\n            int je = j1;\n            for (; j0 < je; j0 += 4, j1\
    \ += 4, j2 += 4, j3 += 4) {\n              __m128i T0 = _mm_loadu_si128((__m128i\
    \ *)(a + j0));\n              __m128i T1 = _mm_loadu_si128((__m128i *)(a + j1));\n\
    \              __m128i T2 = _mm_loadu_si128((__m128i *)(a + j2));\n          \
    \    __m128i T3 = _mm_loadu_si128((__m128i *)(a + j3));\n              __m128i\
    \ T0P1 = montgomery_add_128(T0, T1, m2, m0);\n              __m128i T2P3 = montgomery_add_128(T2,\
    \ T3, m2, m0);\n              __m128i T0M1 =\n                  montgomery_mul_128(montgomery_sub_128(T0,\
    \ T1, m2, m0), XX, r, m1);\n              __m128i T2M3 =\n                  montgomery_mul_128(montgomery_sub_128(T2,\
    \ T3, m2, m0), YY, r, m1);\n              _mm_storeu_si128((__m128i *)(a + j0),\n\
    \                               montgomery_add_128(T0P1, T2P3, m2, m0));\n   \
    \           _mm_storeu_si128(\n                  (__m128i *)(a + j2),\n      \
    \            montgomery_mul_128(montgomery_sub_128(T0P1, T2P3, m2, m0), WW, r,\n\
    \                                 m1));\n              _mm_storeu_si128((__m128i\
    \ *)(a + j1),\n                               montgomery_add_128(T0M1, T2M3, m2,\
    \ m0));\n              _mm_storeu_si128(\n                  (__m128i *)(a + j3),\n\
    \                  montgomery_mul_128(montgomery_sub_128(T0M1, T2M3, m2, m0),\
    \ WW, r,\n                                 m1));\n            }\n          }\n\
    \          xx *= dy[__builtin_ctz(jh += 4)];\n        }\n      }\n      u >>=\
    \ 4;\n      v <<= 2;\n    }\n    if (k & 1) {\n      u = 1 << (k - 1);\n     \
    \ for (int j = 0; j < u; ++j) {\n        mint ajv = a[j] - a[j + u];\n       \
    \ a[j] += a[j + u];\n        a[j + u] = ajv;\n      }\n    }\n    if (normalize)\
    \ {\n      mint invn = one / mint(n);\n      for (int i = 0; i < n; i++) a[i]\
    \ *= invn;\n    }\n  }\n\n  constexpr vector<mint> multiply(const vector<mint>\
    \ &a,\n                                  const vector<mint> &b) {\n    int l =\
    \ a.size() + b.size() - 1;\n    if (min<int>(a.size(), b.size()) <= 40) {\n  \
    \    vector<mint> s(l);\n      for (int i = 0; i < (int)a.size(); ++i)\n     \
    \   for (int j = 0; j < (int)b.size(); ++j) s[i + j] += a[i] * b[j];\n      return\
    \ s;\n    }\n    int M = 4;\n    while (M < l) M <<= 1;\n    for (int i = 0; i\
    \ < (int)a.size(); ++i) buf1[i].a = a[i].a;\n    for (int i = (int)a.size(); i\
    \ < M; ++i) buf1[i].a = 0;\n    for (int i = 0; i < (int)b.size(); ++i) buf2[i].a\
    \ = b[i].a;\n    for (int i = (int)b.size(); i < M; ++i) buf2[i].a = 0;\n    ntt(buf1,\
    \ M);\n    ntt(buf2, M);\n    for (int i = 0; i < M; ++i)\n      buf1[i].a = mint::reduce(uint64_t(buf1[i].a)\
    \ * buf2[i].a);\n    intt(buf1, M, false);\n    vector<mint> s(l);\n    mint invm\
    \ = mint(M).inverse();\n    for (int i = 0; i < l; ++i) s[i] = buf1[i] * invm;\n\
    \    return s;\n  }\n};\n"
  dependsOn:
  - modint/simd-montgomery.hpp
  isVerificationFile: false
  path: ntt/ntt-sse42.hpp
  requiredBy: []
  timestamp: '2021-04-26 16:30:13+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-ntt/yosupo-convolution-ntt-sse42.test.cpp
documentation_of: ntt/ntt-sse42.hpp
layout: document
redirect_from:
- /library/ntt/ntt-sse42.hpp
- /library/ntt/ntt-sse42.hpp.html
title: ntt/ntt-sse42.hpp
---
