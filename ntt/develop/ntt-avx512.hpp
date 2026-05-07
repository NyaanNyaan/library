#pragma once

#include<x86intrin.h>

using namespace std;

#include "simd-montgomery-avx512.hpp"

__attribute__((target("avx512f"))) inline m512 my512_mulhi_epu32(
    const m512 &a, const m512 &b) {
  m512 a13 = _mm512_shuffle_epi32(a, _MM_PERM_ENUM(0xF5));
  m512 b13 = _mm512_shuffle_epi32(b, _MM_PERM_ENUM(0xF5));
  m512 prod02 = _mm512_mul_epu32(a, b);
  m512 prod13 = _mm512_mul_epu32(a13, b13);
  m512 prod = _mm512_unpackhi_epi64(_mm512_unpacklo_epi32(prod02, prod13),
                                    _mm512_unpackhi_epi32(prod02, prod13));
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

  __attribute__((target("avx512f"))) void ntt(mint *a, int n) {
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
            const m128 T0 = _mm_load_si128((m128 *)(a + j0));
            const m128 T1 = _mm_load_si128((m128 *)(a + j1));
            const m128 T2 = _mm_load_si128((m128 *)(a + j2));
            const m128 T3 = _mm_load_si128((m128 *)(a + j3));
            const m128 MT1 = mul_128(T1, XX);
            const m128 MT2 = mul_128(T2, WW);
            const m128 MT3 = mul_128(T3, WX);
            const m128 T0P2 = add_128(T0, MT2, m2);
            const m128 T1P3 = add_128(MT1, MT3, m2);
            const m128 T0M2 = sub_128(T0, MT2, m2);
            const m128 T1M3 = mul_128(sub_128(MT1, MT3, m2), Imag);
            _mm_store_si128((m128 *)(a + j0), add_128(T0P2, T1P3, m2));
            _mm_store_si128((m128 *)(a + j1), sub_128(T0P2, T1P3, m2));
            _mm_store_si128((m128 *)(a + j2), add_128(T0M2, T1M3, m2));
            _mm_store_si128((m128 *)(a + j3), sub_128(T0M2, T1M3, m2));
          }
          xx *= dw[__builtin_ctz((jh += 4))];
        }
      } else {
        const m512 m2 = _mm512_set1_epi32(mod + mod);
        const m512 Imag = _mm512_set1_epi32(imag.a);
        mint ww = one, xx = one, wx = one;
        for (int jh = 0; jh < u; jh += 4) {
          ww = xx * xx, wx = ww * xx;
          const m512 WW = _mm512_set1_epi32(ww.a);
          const m512 WX = _mm512_set1_epi32(wx.a);
          const m512 XX = _mm512_set1_epi32(xx.a);
          int j0 = jh * v;
          int j1 = j0 + v;
          int j2 = j1 + v;
          int j3 = j2 + v;
          int je = j1;
          for (; j0 < je; j0 += 16, j1 += 16, j2 += 16, j3 += 16) {
            const m512 T0 = _mm512_load_si512((m512 *)(a + j0));
            const m512 T1 = _mm512_load_si512((m512 *)(a + j1));
            const m512 T2 = _mm512_load_si512((m512 *)(a + j2));
            const m512 T3 = _mm512_load_si512((m512 *)(a + j3));
            const m512 MT1 = mul_512(T1, XX);
            const m512 MT2 = mul_512(T2, WW);
            const m512 MT3 = mul_512(T3, WX);
            const m512 T0P2 = add_512(T0, MT2, m2);
            const m512 T1P3 = add_512(MT1, MT3, m2);
            const m512 T0M2 = sub_512(T0, MT2, m2);
            const m512 T1M3 = mul_512(sub_512(MT1, MT3, m2), Imag);
            _mm512_store_si512((m512 *)(a + j0), add_512(T0P2, T1P3, m2));
            _mm512_store_si512((m512 *)(a + j1), sub_512(T0P2, T1P3, m2));
            _mm512_store_si512((m512 *)(a + j2), add_512(T0M2, T1M3, m2));
            _mm512_store_si512((m512 *)(a + j3), sub_512(T0M2, T1M3, m2));
          }
          xx *= dw[__builtin_ctz(jh + 4)];
        }
      }
      u <<= 2;
      v >>= 2;
    }
  }

  __attribute__((target("avx512f"))) void intt(mint *a, int n,
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
            const m128 T0 = _mm_load_si128((m128 *)(a + j0));
            const m128 T1 = _mm_load_si128((m128 *)(a + j1));
            const m128 T2 = _mm_load_si128((m128 *)(a + j2));
            const m128 T3 = _mm_load_si128((m128 *)(a + j3));
            const m128 T0P1 = add_128(T0, T1, m2);
            const m128 T2P3 = add_128(T2, T3, m2);
            const m128 T0M1 = mul_128(sub_128(T0, T1, m2), XX);
            m128 T2M3 = mul_128(sub_128(T2, T3, m2), YY);
            _mm_store_si128((m128 *)(a + j0), add_128(T0P1, T2P3, m2));
            _mm_store_si128((m128 *)(a + j2),
                            mul_128(sub_128(T0P1, T2P3, m2), WW));
            _mm_store_si128((m128 *)(a + j1), add_128(T0M1, T2M3, m2));
            _mm_store_si128((m128 *)(a + j3),
                            mul_128(sub_128(T0M1, T2M3, m2), WW));
          }
          xx *= dy[__builtin_ctz(jh += 4)];
        }
      } else {
        const m512 m2 = _mm512_set1_epi32(mod + mod);
        mint ww = one, xx = one, yy = one;
        u <<= 2;
        for (int jh = 0; jh < u;) {
          ww = xx * xx, yy = xx * imag;
          const m512 WW = _mm512_set1_epi32(ww.a);
          const m512 XX = _mm512_set1_epi32(xx.a);
          const m512 YY = _mm512_set1_epi32(yy.a);
          int j0 = jh * v;
          int j1 = j0 + v;
          int j2 = j1 + v;
          int j3 = j2 + v;
          int je = j1;
          for (; j0 < je; j0 += 16, j1 += 16, j2 += 16, j3 += 16) {
            const m512 T0 = _mm512_load_si512((m512 *)(a + j0));
            const m512 T1 = _mm512_load_si512((m512 *)(a + j1));
            const m512 T2 = _mm512_load_si512((m512 *)(a + j2));
            const m512 T3 = _mm512_load_si512((m512 *)(a + j3));
            const m512 T0P1 = add_512(T0, T1, m2);
            const m512 T2P3 = add_512(T2, T3, m2);
            const m512 T0M1 = mul_512(sub_512(T0, T1, m2), XX);
            const m512 T2M3 = mul_512(sub_512(T2, T3, m2), YY);
            _mm512_store_si512((m512 *)(a + j0), add_512(T0P1, T2P3, m2));
            _mm512_store_si512((m512 *)(a + j2),
                               mul_512(sub_512(T0P1, T2P3, m2), WW));
            _mm512_store_si512((m512 *)(a + j1), add_512(T0M1, T2M3, m2));
            _mm512_store_si512((m512 *)(a + j3),
                               mul_512(sub_512(T0M1, T2M3, m2), WW));
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

  __attribute__((target("avx512f"))) void inplace_multiply(
      uint32_t *s, uint32_t *t, int l1, int l2, int zero_padding = true) {
    int l = l1 + l2 - 1;
    int M = 4;
    while (M < l) M <<= 1;
    if (zero_padding) {
      for (int i = l1; i < M; i++) s[i] = 0;
      for (int i = l2; i < M; i++) t[i] = 0;
    }
    const m512 m0 = _mm512_set1_epi32(0);
    const m512 m1 = _mm512_set1_epi32(mod);
    const m512 r = _mm512_set1_epi32(mint::r);
    const m512 N2 = _mm512_set1_epi32(mint::n2);
    for (int i = 0; i < l1; i += 16) {
      m512 a = _mm512_load_si512((m512 *)(s + i));
      m512 b = mul_512(a, N2);
      _mm512_store_si512((m512 *)(s + i), b);
    }
    for (int i = 0; i < l2; i += 16) {
      m512 a = _mm512_load_si512((m512 *)(t + i));
      m512 b = mul_512(a, N2);
      _mm512_store_si512((m512 *)(t + i), b);
    }
    ntt(reinterpret_cast<mint *>(s), M);
    ntt(reinterpret_cast<mint *>(t), M);
    for (int i = 0; i < M; i += 16) {
      m512 a = _mm512_load_si512((m512 *)(s + i));
      m512 b = _mm512_load_si512((m512 *)(t + i));
      m512 c = mul_512(a, b);
      _mm512_store_si512((m512 *)(s + i), c);
    }
    intt(reinterpret_cast<mint *>(s), M, false);
    const m512 INVM = _mm512_set1_epi32((mint(M).inverse()).a);
    for (int i = 0; i < l; i += 16) {
      m512 a = _mm512_load_si512((m512 *)(s + i));
      m512 b = mul_512(a, INVM);
      m512 c = my512_mulhi_epu32(_mm512_mullo_epi32(b, r), m1);
      m512 d = _mm512_sub_epi32(m0, c);
      m512 e = _mm512_sub_epi32(m1, c);
      m512 f = _mm512_min_epu32(d, e);
      _mm512_store_si512((m512 *)(s + i), f);
    }
  }

  __attribute__((target("avx512f"))) void inplace_multiply2(
      uint32_t *s, uint32_t *t, int l1, int l2, int zero_padding = true) {
    int l = l1 + l2 - 1;
    int M = 4;
    while (M < l) M <<= 1;
    if (zero_padding) {
      for (int i = l1; i < M; i++) s[i] = 0;
      for (int i = l2; i < M; i++) t[i] = 0;
    }
    const m512 m0 = _mm512_set1_epi32(0);
    const m512 m1 = _mm512_set1_epi32(mod);
    const m512 r = _mm512_set1_epi32(mint::r);
    ntt(reinterpret_cast<mint *>(s), M);
    ntt(reinterpret_cast<mint *>(t), M);
    for (int i = 0; i < M; i += 16) {
      m512 a = _mm512_load_si512((m512 *)(s + i));
      m512 b = _mm512_load_si512((m512 *)(t + i));
      m512 c = mul_512(a, b);
      _mm512_store_si512((m512 *)(s + i), c);
    }
    intt(reinterpret_cast<mint *>(s), M, false);
    const m512 INVM = _mm512_set1_epi32((mint(M).inverse()).a);
    for (int i = 0; i < l; i += 16) {
      m512 a = _mm512_load_si512((m512 *)(s + i));
      m512 b = mul_512(a, INVM);
      m512 c = my512_mulhi_epu32(_mm512_mullo_epi32(b, r), m1);
      m512 d = _mm512_sub_epi32(m0, c);
      m512 e = _mm512_sub_epi32(m1, c);
      m512 f = _mm512_min_epu32(d, e);
      _mm512_store_si512((m512 *)(s + i), f);
    }
  }
};
