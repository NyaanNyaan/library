#pragma once

using namespace std;

#include "simd-montgomery-avx512.hpp"

__attribute__((target("avx2"))) inline __m256i _my256_mullo_epu32(
    const __m256i &a, const __m256i &b) {
  return _mm256_mullo_epi32(a, b);
}

__attribute__((target("avx2"))) inline __m256i _my256_mulhi_epu32(
    const __m256i &a, const __m256i &b) {
  __m256i a13 = _mm256_shuffle_epi32(a, 0xF5);
  __m256i b13 = _mm256_shuffle_epi32(b, 0xF5);
  __m256i prod02 = _mm256_mul_epu32(a, b);
  __m256i prod13 = _mm256_mul_epu32(a13, b13);
  __m256i prod = _mm256_unpackhi_epi64(_mm256_unpacklo_epi32(prod02, prod13),
                                       _mm256_unpackhi_epi32(prod02, prod13));
  return prod;
}

template <typename mint>
struct NTT_single {
  static constexpr uint32_t mod = mint::get_mod();
  static constexpr uint32_t pr = 3;
  static constexpr int level = __builtin_ctzll(mod - 1);
  mint dw[level], dy[level];

  constexpr NTT_single() { setwy(level); }

  constexpr void setwy(int k) {
    mint w[level], y[level];
    w[k - 1] = mint(pr).pow((mod - 1) / (1 << k));
    y[k - 1] = w[k - 1].inverse();
    for (int i = k - 2; i > 0; --i)
      w[i] = w[i + 1] * w[i + 1], y[i] = y[i + 1] * y[i + 1];
    dw[0] = dy[0] = w[1] * w[1];
    dw[1] = w[1], dy[1] = y[1], dw[2] = w[2], dy[2] = y[2];
    for (int i = 3; i < k; ++i) {
      dw[i] = dw[i - 1] * y[i - 2] * w[i];
      dy[i] = dy[i - 1] * w[i - 2] * y[i];
    }
  }

  __attribute__((target("avx2"))) void ntt(mint *a, int n) {
    int k = n ? __builtin_ctz(n) : 0;
    if (k == 0) return;
    if (k == 1) {
      mint a1 = a[1];
      a[1] = a[0] - a[1];
      a[0] = a[0] + a1;
      return;
    }
    if (k & 1) {
      int v = 1 << (k - 1);
      for (int j = 0; j < v; ++j) {
        mint ajv = a[j + v];
        a[j + v] = a[j] - ajv;
        a[j] += ajv;
      }
    }
    int u = 1 << (2 + (k & 1));
    int v = 1 << (k - 2 - (k & 1));
    mint one = mint(1);
    mint imag = dw[1];
    while (v) {
      if (v == 1) {
        mint ww = one, xx = one, wx = one;
        for (int jh = 0; jh < u;) {
          ww = xx * xx, wx = ww * xx;
          mint t0 = a[jh + 0], t1 = a[jh + 1] * xx;
          mint t2 = a[jh + 2] * ww, t3 = a[jh + 3] * wx;
          mint t0p2 = t0 + t2, t1p3 = t1 + t3;
          mint t0m2 = t0 - t2, t1m3 = (t1 - t3) * imag;
          a[jh + 0] = t0p2 + t1p3, a[jh + 1] = t0p2 - t1p3;
          a[jh + 2] = t0m2 + t1m3, a[jh + 3] = t0m2 - t1m3;
          xx *= dw[__builtin_ctz((jh += 4))];
        }
      } else if (v == 4) {
        const m128 m2 = _mm_set1_epi32(mod + mod);
        const m128 Imag = _mm_set1_epi32(imag.a);
        mint ww = one, xx = one, wx = one;
        for (int jh = 0; jh < u;) {
          ww = xx * xx, wx = ww * xx;
          const m128 WW = _mm_set1_epi32(ww.a);
          const m128 WX = _mm_set1_epi32(wx.a);
          const m128 XX = _mm_set1_epi32(xx.a);
          int j0 = jh * v;
          int j1 = j0 + v;
          int j2 = j1 + v;
          int j3 = j2 + v;
          int je = j1;
          for (; j0 < je; j0 += 4, j1 += 4, j2 += 4, j3 += 4) {
            const m128 T0 = _mm_loadu_si128((m128 *)(a + j0));
            const m128 T1 = _mm_loadu_si128((m128 *)(a + j1));
            const m128 T2 = _mm_loadu_si128((m128 *)(a + j2));
            const m128 T3 = _mm_loadu_si128((m128 *)(a + j3));
            const m128 MT1 = mul_128(T1, XX);
            const m128 MT2 = mul_128(T2, WW);
            const m128 MT3 = mul_128(T3, WX);
            const m128 T0P2 = add_128(T0, MT2, m2);
            const m128 T1P3 = add_128(MT1, MT3, m2);
            const m128 T0M2 = sub_128(T0, MT2, m2);
            const m128 T1M3 = mul_128(sub_128(MT1, MT3, m2), Imag);
            _mm_storeu_si128((m128 *)(a + j0), add_128(T0P2, T1P3, m2));
            _mm_storeu_si128((m128 *)(a + j1), sub_128(T0P2, T1P3, m2));
            _mm_storeu_si128((m128 *)(a + j2), add_128(T0M2, T1M3, m2));
            _mm_storeu_si128((m128 *)(a + j3), sub_128(T0M2, T1M3, m2));
          }
          xx *= dw[__builtin_ctz((jh += 4))];
        }
      } else {
        const m256 m2 = _mm256_set1_epi32(mod + mod);
        const m256 Imag = _mm256_set1_epi32(imag.a);
        mint ww = one, xx = one, wx = one;
        for (int jh = 0; jh < u; jh += 4) {
          ww = xx * xx, wx = ww * xx;
          const m256 WW = _mm256_set1_epi32(ww.a);
          const m256 WX = _mm256_set1_epi32(wx.a);
          const m256 XX = _mm256_set1_epi32(xx.a);
          int j0 = jh * v;
          int j1 = j0 + v;
          int j2 = j1 + v;
          int j3 = j2 + v;
          int je = j1;
          for (; j0 < je; j0 += 8, j1 += 8, j2 += 8, j3 += 8) {
            const m256 T0 = _mm256_loadu_si256((m256 *)(a + j0));
            const m256 T1 = _mm256_loadu_si256((m256 *)(a + j1));
            const m256 T2 = _mm256_loadu_si256((m256 *)(a + j2));
            const m256 T3 = _mm256_loadu_si256((m256 *)(a + j3));
            const m256 MT1 = mul_256(T1, XX);
            const m256 MT2 = mul_256(T2, WW);
            const m256 MT3 = mul_256(T3, WX);
            const m256 T0P2 = add_256(T0, MT2, m2);
            const m256 T1P3 = add_256(MT1, MT3, m2);
            const m256 T0M2 = sub_256(T0, MT2, m2);
            const m256 T1M3 = mul_256(sub_256(MT1, MT3, m2), Imag);
            _mm256_storeu_si256((m256 *)(a + j0), add_256(T0P2, T1P3, m2));
            _mm256_storeu_si256((m256 *)(a + j1), sub_256(T0P2, T1P3, m2));
            _mm256_storeu_si256((m256 *)(a + j2), add_256(T0M2, T1M3, m2));
            _mm256_storeu_si256((m256 *)(a + j3), sub_256(T0M2, T1M3, m2));
          }
          xx *= dw[__builtin_ctz(jh + 4)];
        }
      }
      u <<= 2;
      v >>= 2;
    }
  }

  __attribute__((target("avx2"))) void intt(mint *a, int n,
                                            int normalize = true) {
    int k = n ? __builtin_ctz(n) : 0;
    if (k == 0) return;
    if (k == 1) {
      mint a1 = a[1];
      a[1] = a[0] - a[1];
      a[0] = a[0] + a1;
      if (normalize) {
        a[0] *= mint(2).inverse();
        a[1] *= mint(2).inverse();
      }
      return;
    }
    int u = 1 << (k - 2);
    int v = 1;
    mint one = mint(1);
    mint imag = dy[1];
    while (u) {
      if (v == 1) {
        mint ww = one, xx = one, yy = one;
        u <<= 2;
        for (int jh = 0; jh < u;) {
          ww = xx * xx, yy = xx * imag;
          mint t0 = a[jh + 0], t1 = a[jh + 1];
          mint t2 = a[jh + 2], t3 = a[jh + 3];
          mint t0p1 = t0 + t1, t2p3 = t2 + t3;
          mint t0m1 = (t0 - t1) * xx, t2m3 = (t2 - t3) * yy;
          a[jh + 0] = t0p1 + t2p3, a[jh + 2] = (t0p1 - t2p3) * ww;
          a[jh + 1] = t0m1 + t2m3, a[jh + 3] = (t0m1 - t2m3) * ww;
          xx *= dy[__builtin_ctz(jh += 4)];
        }
      } else if (v == 4) {
        const m128 m2 = _mm_set1_epi32(mod + mod);
        mint ww = one, xx = one, yy = one;
        u <<= 2;
        for (int jh = 0; jh < u;) {
          ww = xx * xx, yy = xx * imag;
          const m128 WW = _mm_set1_epi32(ww.a);
          const m128 XX = _mm_set1_epi32(xx.a);
          const m128 YY = _mm_set1_epi32(yy.a);
          int j0 = jh * v;
          int j1 = j0 + v;
          int j2 = j1 + v;
          int j3 = j2 + v;
          int je = j1;
          for (; j0 < je; j0 += 4, j1 += 4, j2 += 4, j3 += 4) {
            const m128 T0 = _mm_loadu_si128((m128 *)(a + j0));
            const m128 T1 = _mm_loadu_si128((m128 *)(a + j1));
            const m128 T2 = _mm_loadu_si128((m128 *)(a + j2));
            const m128 T3 = _mm_loadu_si128((m128 *)(a + j3));
            const m128 T0P1 = add_128(T0, T1, m2);
            const m128 T2P3 = add_128(T2, T3, m2);
            const m128 T0M1 = mul_128(sub_128(T0, T1, m2), XX);
            m128 T2M3 = mul_128(sub_128(T2, T3, m2), YY);
            _mm_storeu_si128((m128 *)(a + j0), add_128(T0P1, T2P3, m2));
            _mm_storeu_si128((m128 *)(a + j2),
                             mul_128(sub_128(T0P1, T2P3, m2), WW));
            _mm_storeu_si128((m128 *)(a + j1), add_128(T0M1, T2M3, m2));
            _mm_storeu_si128((m128 *)(a + j3),
                             mul_128(sub_128(T0M1, T2M3, m2), WW));
          }
          xx *= dy[__builtin_ctz(jh += 4)];
        }
      } else {
        const m256 m2 = _mm256_set1_epi32(mod + mod);
        mint ww = one, xx = one, yy = one;
        u <<= 2;
        for (int jh = 0; jh < u;) {
          ww = xx * xx, yy = xx * imag;
          const m256 WW = _mm256_set1_epi32(ww.a);
          const m256 XX = _mm256_set1_epi32(xx.a);
          const m256 YY = _mm256_set1_epi32(yy.a);
          int j0 = jh * v;
          int j1 = j0 + v;
          int j2 = j1 + v;
          int j3 = j2 + v;
          int je = j1;
          for (; j0 < je; j0 += 8, j1 += 8, j2 += 8, j3 += 8) {
            const m256 T0 = _mm256_loadu_si256((m256 *)(a + j0));
            const m256 T1 = _mm256_loadu_si256((m256 *)(a + j1));
            const m256 T2 = _mm256_loadu_si256((m256 *)(a + j2));
            const m256 T3 = _mm256_loadu_si256((m256 *)(a + j3));
            const m256 T0P1 = add_256(T0, T1, m2);
            const m256 T2P3 = add_256(T2, T3, m2);
            const m256 T0M1 = mul_256(sub_256(T0, T1, m2), XX);
            const m256 T2M3 = mul_256(sub_256(T2, T3, m2), YY);
            _mm256_storeu_si256((m256 *)(a + j0), add_256(T0P1, T2P3, m2));
            _mm256_storeu_si256((m256 *)(a + j2),
                                mul_256(sub_256(T0P1, T2P3, m2), WW));
            _mm256_storeu_si256((m256 *)(a + j1), add_256(T0M1, T2M3, m2));
            _mm256_storeu_si256((m256 *)(a + j3),
                                mul_256(sub_256(T0M1, T2M3, m2), WW));
          }
          xx *= dy[__builtin_ctz(jh += 4)];
        }
      }
      u >>= 4;
      v <<= 2;
    }
    if (k & 1) {
      v = 1 << (k - 1);
      for (int j = 0; j < v; ++j) {
        mint ajv = a[j] - a[j + v];
        a[j] += a[j + v];
        a[j + v] = ajv;
      }
    }
    if (normalize) {
      mint invn = mint(n).inverse();
      for (int i = 0; i < n; i++) a[i] *= invn;
    }
  }

  __attribute__((target("avx2"))) void inplace_multiply(
      uint32_t *s, uint32_t *t, int l1, int l2, int zero_padding = true) {
    int l = l1 + l2 - 1;
    int M = 4;
    while (M < l) M <<= 1;
    if (zero_padding) {
      for (int i = l1; i < M; i++) s[i] = 0;
      for (int i = l2; i < M; i++) t[i] = 0;
    }
    const m256 m0 = _mm256_set1_epi32(0);
    const m256 m1 = _mm256_set1_epi32(mod);
    const m256 r = _mm256_set1_epi32(mint::r);
    const m256 N2 = _mm256_set1_epi32(mint::n2);
    for (int i = 0; i < l1; i += 8) {
      m256 a = _mm256_loadu_si256((m256 *)(s + i));
      m256 b = mul_256(a, N2);
      _mm256_storeu_si256((m256 *)(s + i), b);
    }
    for (int i = 0; i < l2; i += 8) {
      m256 a = _mm256_loadu_si256((m256 *)(t + i));
      m256 b = mul_256(a, N2);
      _mm256_storeu_si256((m256 *)(t + i), b);
    }
    ntt(reinterpret_cast<mint *>(s), M);
    ntt(reinterpret_cast<mint *>(t), M);
    for (int i = 0; i < M; i += 8) {
      m256 a = _mm256_loadu_si256((m256 *)(s + i));
      m256 b = _mm256_loadu_si256((m256 *)(t + i));
      m256 c = mul_256(a, b);
      _mm256_storeu_si256((m256 *)(s + i), c);
    }
    intt(reinterpret_cast<mint *>(s), M, false);
    const m256 INVM = _mm256_set1_epi32((mint(M).inverse()).a);
    for (int i = 0; i < l; i += 8) {
      m256 a = _mm256_loadu_si256((m256 *)(s + i));
      m256 b = mul_256(a, INVM);
      m256 c = _my256_mulhi_epu32(_my256_mullo_epu32(b, r), m1);
      m256 d = _mm256_and_si256(_mm256_cmpgt_epi32(c, m0), m1);
      m256 e = _mm256_sub_epi32(d, c);
      _mm256_storeu_si256((m256 *)(s + i), e);
    }
  }

  __attribute__((target("avx2"))) void inplace_multiply2(
      uint32_t *s, uint32_t *t, int l1, int l2, int zero_padding = true) {
    int l = l1 + l2 - 1;
    int M = 4;
    while (M < l) M <<= 1;
    if (zero_padding) {
      for (int i = l1; i < M; i++) s[i] = 0;
      for (int i = l2; i < M; i++) t[i] = 0;
    }
    const m256 m0 = _mm256_set1_epi32(0);
    const m256 m1 = _mm256_set1_epi32(mod);
    const m256 r = _mm256_set1_epi32(mint::r);
    ntt(reinterpret_cast<mint *>(s), M);
    ntt(reinterpret_cast<mint *>(t), M);
    for (int i = 0; i < M; i += 8) {
      m256 a = _mm256_loadu_si256((m256 *)(s + i));
      m256 b = _mm256_loadu_si256((m256 *)(t + i));
      m256 c = mul_256(a, b);
      _mm256_storeu_si256((m256 *)(s + i), c);
    }
    intt(reinterpret_cast<mint *>(s), M, false);
    const m256 INVM = _mm256_set1_epi32((mint(M).inverse()).a);
    for (int i = 0; i < l; i += 8) {
      m256 a = _mm256_loadu_si256((m256 *)(s + i));
      m256 b = mul_256(a, INVM);
      m256 c = _my256_mulhi_epu32(_my256_mullo_epu32(b, r), m1);
      m256 d = _mm256_and_si256(_mm256_cmpgt_epi32(c, m0), m1);
      m256 e = _mm256_sub_epi32(d, c);
      _mm256_storeu_si256((m256 *)(s + i), e);
    }
  }
};
