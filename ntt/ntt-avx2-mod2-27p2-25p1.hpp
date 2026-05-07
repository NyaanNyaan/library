#pragma once

#include <cstdint>
#include <vector>
using namespace std;

#include <immintrin.h>

using m128 = __m128i;
using m256 = __m256i;

__attribute__((target("sse4.2"))) inline m128 my128_mullo_epu32(const m128 &a,
                                                                const m128 &b) {
  return _mm_mullo_epi32(a, b);
}

__attribute__((target("sse4.2"))) inline m128 my128_mulhi_epu32(const m128 &a,
                                                                const m128 &b) {
  m128 a13 = _mm_shuffle_epi32(a, 0xF5);
  m128 b13 = _mm_shuffle_epi32(b, 0xF5);
  m128 prod02 = _mm_mul_epu32(a, b);
  m128 prod13 = _mm_mul_epu32(a13, b13);
  m128 prod = _mm_unpackhi_epi64(_mm_unpacklo_epi32(prod02, prod13),
                                 _mm_unpackhi_epi32(prod02, prod13));
  return prod;
}

__attribute__((target("sse4.2"))) inline m128 montgomery_mul_128(
    const m128 &a, const m128 &b, const m128 &r, const m128 &m1) {
  return _mm_sub_epi32(
      _mm_add_epi32(my128_mulhi_epu32(a, b), m1),
      my128_mulhi_epu32(my128_mullo_epu32(my128_mullo_epu32(a, b), r), m1));
}

__attribute__((target("sse4.2"))) inline m128 montgomery_add_128(
    const m128 &a, const m128 &b, const m128 &m2, const m128 &m0) {
  m128 ret = _mm_sub_epi32(_mm_add_epi32(a, b), m2);
  return _mm_add_epi32(_mm_and_si128(_mm_cmpgt_epi32(m0, ret), m2), ret);
}

__attribute__((target("sse4.2"))) inline m128 montgomery_sub_128(
    const m128 &a, const m128 &b, const m128 &m2, const m128 &m0) {
  m128 ret = _mm_sub_epi32(a, b);
  return _mm_add_epi32(_mm_and_si128(_mm_cmpgt_epi32(m0, ret), m2), ret);
}

__attribute__((target("avx2"))) inline m256 my256_mullo_epu32(const m256 &a,
                                                              const m256 &b) {
  return _mm256_mullo_epi32(a, b);
}

__attribute__((target("avx2"))) inline m256 my256_mulhi_epu32(const m256 &a,
                                                              const m256 &b) {
  m256 a13 = _mm256_shuffle_epi32(a, 0xF5);
  m256 b13 = _mm256_shuffle_epi32(b, 0xF5);
  m256 prod02 = _mm256_mul_epu32(a, b);
  m256 prod13 = _mm256_mul_epu32(a13, b13);
  m256 prod = _mm256_unpackhi_epi64(_mm256_unpacklo_epi32(prod02, prod13),
                                    _mm256_unpackhi_epi32(prod02, prod13));
  return prod;
}

__attribute__((target("avx2"))) inline m256 mul_256(const m256 &A,
                                                    const m256 &B) {
  m256 a13 = _mm256_shuffle_epi32(A, 0xF5);
  m256 b13 = _mm256_shuffle_epi32(B, 0xF5);
  // | c0 := a0 * b0 | c2 := a2 * b2 |
  m256 prod02 = _mm256_mul_epu32(A, B);
  // | c1 := a1 * b1 | c3 := a3 * b3 |
  m256 prod13 = _mm256_mul_epu32(a13, b13);

  m256 modm2 = _mm256_set1_epi32((5 << 25) - 1);
  m256 mod = _mm256_set1_epi32((5 << 25) + 1);

  m256 x02 = _mm256_mul_epu32(prod02, modm2);
  m256 x13 = _mm256_mul_epu32(prod13, modm2);

  m256 y02 = _mm256_mul_epu32(x02, mod);
  m256 y13 = _mm256_mul_epu32(x13, mod);

  m256 z02 = _mm256_add_epi64(y02, prod02);
  m256 z13 = _mm256_add_epi64(y13, prod13);

  m256 z02_2 = _mm256_shuffle_epi32(z02, 0xB1);
  return _mm256_or_si256(z02_2, z13);
  /*
  // |  c0l  |  c1l  |  c0h  |  c1h  |
  m256 unpalo = _mm256_unpacklo_epi32(prod02, prod13);
  // |  c2l  |  c3l  |  c2h  |  c3h  |
  m256 unpahi = _mm256_unpackhi_epi32(prod02, prod13);
  // |  c0l  |  c1l  |  c2l  |  c3l  |
  m256 prodlo = _mm256_unpacklo_epi64(unpalo, unpahi);
  // |  c0h  |  c1h  |  c2h  |  c3h  |
  m256 prodhi = _mm256_unpackhi_epi64(unpalo, unpahi);

  m256 mask = _mm256_set_epi32(0, -1u, 0, -1u, 0, -1u, 0, -1u);

  m256 p02sl27 = _mm256_slli_epi64(prod02, 27);
  m256 p02sl25 = _mm256_slli_epi64(prod02, 25);
  m256 x02mid1 = _mm256_add_epi64(p02sl27, p02sl25);
  m256 x02mid2 = _mm256_sub_epi64(x02mid1, prod02);
  m256 x02 = _mm256_and_si256(x02mid2, mask);

  m256 p13sl27 = _mm256_slli_epi64(prod13, 27);
  m256 p13sl25 = _mm256_slli_epi64(prod13, 25);
  m256 x13mid1 = _mm256_add_epi64(p13sl27, p13sl25);
  m256 x13mid2 = _mm256_sub_epi64(x13mid1, prod13);
  m256 x13 = _mm256_and_si256(x13mid2, mask);

  m256 x02sl27 = _mm256_slli_epi64(x02, 27);
  m256 x02sl25 = _mm256_slli_epi64(x02, 25);
  m256 s02 = _mm256_add_epi64(prod02, x02);
  m256 t02 = _mm256_add_epi64(x02sl27, x02sl25);
  m256 u02 = _mm256_add_epi64(s02, t02);

  m256 x13sl27 = _mm256_slli_epi64(x13, 27);
  m256 x13sl25 = _mm256_slli_epi64(x13, 25);
  m256 s13 = _mm256_add_epi64(prod13, x13);
  m256 t13 = _mm256_add_epi64(x13sl27, x13sl25);
  m256 u13 = _mm256_add_epi64(s13, t13);

  m256 u02_2 = _mm256_shuffle_epi32(u02, 0xB1);
  return _mm256_or_si256(u02_2, u13);
  */
}

__attribute__((target("avx2"))) inline m256 add_256(const m256 &A,
                                                    const m256 &B,
                                                    const m256 &M2) {
  m256 ret = _mm256_add_epi32(A, B);
  m256 ret_sub = _mm256_sub_epi32(ret, M2);
  return _mm256_min_epu32(ret, ret_sub);
}

__attribute__((target("avx2"))) inline m256 sub_256(const m256 &A,
                                                    const m256 &B,
                                                    const m256 &M2) {
  m256 ret = _mm256_sub_epi32(A, B);
  m256 ret_add = _mm256_add_epi32(ret, M2);
  return _mm256_min_epu32(ret, ret_add);
}

namespace ntt_inner {
using u64 = uint64_t;

constexpr int SZ_FFT_BUF = 1 << 23;
uint32_t _buf1[SZ_FFT_BUF] __attribute__((aligned(64)));
uint32_t _buf2[SZ_FFT_BUF] __attribute__((aligned(64)));
}  // namespace ntt_inner

template <typename mint>
struct NTT_mod2_27p2_25p1 {
  static constexpr uint32_t mod = mint::get_mod();
  static constexpr uint32_t pr = 3;
  static constexpr int level = __builtin_ctzll(mod - 1);
  mint dw[level], dy[level];
  mint *buf1, *buf2;

  constexpr NTT_mod2_27p2_25p1() {
    setwy(level);
    union raw_cast {
      mint dat;
      uint32_t _;
    };
    buf1 = &(((raw_cast *)(ntt_inner::_buf1))->dat);
    buf2 = &(((raw_cast *)(ntt_inner::_buf2))->dat);
  }

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
      if (v < 8) {
        for (int j = 0; j < v; ++j) {
          mint ajv = a[j + v];
          a[j + v] = a[j] - ajv;
          a[j] += ajv;
        }
      } else {
        const m256 m2 = _mm256_set1_epi32(mod + mod);
        int j0 = 0;
        int j1 = v;
        for (; j0 < v; j0 += 8, j1 += 8) {
          m256 T0 = _mm256_loadu_si256((m256 *)(a + j0));
          m256 T1 = _mm256_loadu_si256((m256 *)(a + j1));
          m256 naj = add_256(T0, T1, m2);
          m256 najv = sub_256(T0, T1, m2);
          _mm256_storeu_si256((m256 *)(a + j0), naj);
          _mm256_storeu_si256((m256 *)(a + j1), najv);
        }
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
        const m128 m0 = _mm_set1_epi32(0);
        const m128 m1 = _mm_set1_epi32(mod);
        const m128 m2 = _mm_set1_epi32(mod + mod);
        const m128 r = _mm_set1_epi32(mint::r);
        const m128 Imag = _mm_set1_epi32(imag.a);
        mint ww = one, xx = one, wx = one;
        for (int jh = 0; jh < u;) {
          if (jh == 0) {
            int j0 = 0;
            int j1 = v;
            int j2 = j1 + v;
            int j3 = j2 + v;
            int je = v;
            for (; j0 < je; j0 += 4, j1 += 4, j2 += 4, j3 += 4) {
              const m128 T0 = _mm_loadu_si128((m128 *)(a + j0));
              const m128 T1 = _mm_loadu_si128((m128 *)(a + j1));
              const m128 T2 = _mm_loadu_si128((m128 *)(a + j2));
              const m128 T3 = _mm_loadu_si128((m128 *)(a + j3));
              const m128 T0P2 = montgomery_add_128(T0, T2, m2, m0);
              const m128 T1P3 = montgomery_add_128(T1, T3, m2, m0);
              const m128 T0M2 = montgomery_sub_128(T0, T2, m2, m0);
              const m128 T1M3 = montgomery_mul_128(
                  montgomery_sub_128(T1, T3, m2, m0), Imag, r, m1);
              _mm_storeu_si128((m128 *)(a + j0),
                               montgomery_add_128(T0P2, T1P3, m2, m0));
              _mm_storeu_si128((m128 *)(a + j1),
                               montgomery_sub_128(T0P2, T1P3, m2, m0));
              _mm_storeu_si128((m128 *)(a + j2),
                               montgomery_add_128(T0M2, T1M3, m2, m0));
              _mm_storeu_si128((m128 *)(a + j3),
                               montgomery_sub_128(T0M2, T1M3, m2, m0));
            }
          } else {
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
              const m128 MT1 = montgomery_mul_128(T1, XX, r, m1);
              const m128 MT2 = montgomery_mul_128(T2, WW, r, m1);
              const m128 MT3 = montgomery_mul_128(T3, WX, r, m1);
              const m128 T0P2 = montgomery_add_128(T0, MT2, m2, m0);
              const m128 T1P3 = montgomery_add_128(MT1, MT3, m2, m0);
              const m128 T0M2 = montgomery_sub_128(T0, MT2, m2, m0);
              const m128 T1M3 = montgomery_mul_128(
                  montgomery_sub_128(MT1, MT3, m2, m0), Imag, r, m1);
              _mm_storeu_si128((m128 *)(a + j0),
                               montgomery_add_128(T0P2, T1P3, m2, m0));
              _mm_storeu_si128((m128 *)(a + j1),
                               montgomery_sub_128(T0P2, T1P3, m2, m0));
              _mm_storeu_si128((m128 *)(a + j2),
                               montgomery_add_128(T0M2, T1M3, m2, m0));
              _mm_storeu_si128((m128 *)(a + j3),
                               montgomery_sub_128(T0M2, T1M3, m2, m0));
            }
          }
          xx *= dw[__builtin_ctz((jh += 4))];
        }
      } else {
        const m256 m2 = _mm256_set1_epi32(mod + mod);
        const m256 Imag = _mm256_set1_epi32(imag.a);
        mint ww = one, xx = one, wx = one;
        for (int jh = 0; jh < u;) {
          if (jh == 0) {
            int j0 = 0;
            int j1 = v;
            int j2 = j1 + v;
            int j3 = j2 + v;
            int je = v;
            for (; j0 < je; j0 += 8, j1 += 8, j2 += 8, j3 += 8) {
              const m256 T0 = _mm256_loadu_si256((m256 *)(a + j0));
              const m256 T1 = _mm256_loadu_si256((m256 *)(a + j1));
              const m256 T2 = _mm256_loadu_si256((m256 *)(a + j2));
              const m256 T3 = _mm256_loadu_si256((m256 *)(a + j3));
              const m256 T0P2 = add_256(T0, T2, m2);
              const m256 T1P3 = add_256(T1, T3, m2);
              const m256 T0M2 = sub_256(T0, T2, m2);
              const m256 T1M3 = mul_256(sub_256(T1, T3, m2), Imag);
              _mm256_storeu_si256((m256 *)(a + j0), add_256(T0P2, T1P3, m2));
              _mm256_storeu_si256((m256 *)(a + j1), sub_256(T0P2, T1P3, m2));
              _mm256_storeu_si256((m256 *)(a + j2), add_256(T0M2, T1M3, m2));
              _mm256_storeu_si256((m256 *)(a + j3), sub_256(T0M2, T1M3, m2));
            }
          } else {
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
          }
          xx *= dw[__builtin_ctz((jh += 4))];
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
        const m128 m0 = _mm_set1_epi32(0);
        const m128 m1 = _mm_set1_epi32(mod);
        const m128 m2 = _mm_set1_epi32(mod + mod);
        const m128 r = _mm_set1_epi32(mint::r);
        const m128 Imag = _mm_set1_epi32(imag.a);
        mint ww = one, xx = one, yy = one;
        u <<= 2;
        for (int jh = 0; jh < u;) {
          if (jh == 0) {
            int j0 = 0;
            int j1 = v;
            int j2 = v + v;
            int j3 = j2 + v;
            for (; j0 < v; j0 += 4, j1 += 4, j2 += 4, j3 += 4) {
              const m128 T0 = _mm_loadu_si128((m128 *)(a + j0));
              const m128 T1 = _mm_loadu_si128((m128 *)(a + j1));
              const m128 T2 = _mm_loadu_si128((m128 *)(a + j2));
              const m128 T3 = _mm_loadu_si128((m128 *)(a + j3));
              const m128 T0P1 = montgomery_add_128(T0, T1, m2, m0);
              const m128 T2P3 = montgomery_add_128(T2, T3, m2, m0);
              const m128 T0M1 = montgomery_sub_128(T0, T1, m2, m0);
              const m128 T2M3 = montgomery_mul_128(
                  montgomery_sub_128(T2, T3, m2, m0), Imag, r, m1);
              _mm_storeu_si128((m128 *)(a + j0),
                               montgomery_add_128(T0P1, T2P3, m2, m0));
              _mm_storeu_si128((m128 *)(a + j2),
                               montgomery_sub_128(T0P1, T2P3, m2, m0));
              _mm_storeu_si128((m128 *)(a + j1),
                               montgomery_add_128(T0M1, T2M3, m2, m0));
              _mm_storeu_si128((m128 *)(a + j3),
                               montgomery_sub_128(T0M1, T2M3, m2, m0));
            }
          } else {
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
              const m128 T0P1 = montgomery_add_128(T0, T1, m2, m0);
              const m128 T2P3 = montgomery_add_128(T2, T3, m2, m0);
              const m128 T0M1 = montgomery_mul_128(
                  montgomery_sub_128(T0, T1, m2, m0), XX, r, m1);
              m128 T2M3 = montgomery_mul_128(montgomery_sub_128(T2, T3, m2, m0),
                                             YY, r, m1);
              _mm_storeu_si128((m128 *)(a + j0),
                               montgomery_add_128(T0P1, T2P3, m2, m0));
              _mm_storeu_si128(
                  (m128 *)(a + j2),
                  montgomery_mul_128(montgomery_sub_128(T0P1, T2P3, m2, m0), WW,
                                     r, m1));
              _mm_storeu_si128((m128 *)(a + j1),
                               montgomery_add_128(T0M1, T2M3, m2, m0));
              _mm_storeu_si128(
                  (m128 *)(a + j3),
                  montgomery_mul_128(montgomery_sub_128(T0M1, T2M3, m2, m0), WW,
                                     r, m1));
            }
          }
          xx *= dy[__builtin_ctz(jh += 4)];
        }
      } else {
        const m256 m2 = _mm256_set1_epi32(mod + mod);
        const m256 Imag = _mm256_set1_epi32(imag.a);
        mint ww = one, xx = one, yy = one;
        u <<= 2;
        for (int jh = 0; jh < u;) {
          if (jh == 0) {
            int j0 = 0;
            int j1 = v;
            int j2 = v + v;
            int j3 = j2 + v;
            for (; j0 < v; j0 += 8, j1 += 8, j2 += 8, j3 += 8) {
              const m256 T0 = _mm256_loadu_si256((m256 *)(a + j0));
              const m256 T1 = _mm256_loadu_si256((m256 *)(a + j1));
              const m256 T2 = _mm256_loadu_si256((m256 *)(a + j2));
              const m256 T3 = _mm256_loadu_si256((m256 *)(a + j3));
              const m256 T0P1 = add_256(T0, T1, m2);
              const m256 T2P3 = add_256(T2, T3, m2);
              const m256 T0M1 = sub_256(T0, T1, m2);
              const m256 T2M3 = mul_256(sub_256(T2, T3, m2), Imag);
              _mm256_storeu_si256((m256 *)(a + j0), add_256(T0P1, T2P3, m2));
              _mm256_storeu_si256((m256 *)(a + j2), sub_256(T0P1, T2P3, m2));
              _mm256_storeu_si256((m256 *)(a + j1), add_256(T0M1, T2M3, m2));
              _mm256_storeu_si256((m256 *)(a + j3), sub_256(T0M1, T2M3, m2));
            }
          } else {
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
          }
          xx *= dy[__builtin_ctz(jh += 4)];
        }
      }
      u >>= 4;
      v <<= 2;
    }
    if (k & 1) {
      v = 1 << (k - 1);
      if (v < 8) {
        for (int j = 0; j < v; ++j) {
          mint ajv = a[j] - a[j + v];
          a[j] += a[j + v];
          a[j + v] = ajv;
        }
      } else {
        const m256 m2 = _mm256_set1_epi32(mod + mod);
        int j0 = 0;
        int j1 = v;
        for (; j0 < v; j0 += 8, j1 += 8) {
          const m256 T0 = _mm256_loadu_si256((m256 *)(a + j0));
          const m256 T1 = _mm256_loadu_si256((m256 *)(a + j1));
          m256 naj = add_256(T0, T1, m2);
          m256 najv = sub_256(T0, T1, m2);
          _mm256_storeu_si256((m256 *)(a + j0), naj);
          _mm256_storeu_si256((m256 *)(a + j1), najv);
        }
      }
    }
    if (normalize) {
      mint invn = mint(n).inverse();
      for (int i = 0; i < n; i++) a[i] *= invn;
    }
  }

  __attribute__((target("avx2"))) void inplace_multiply(
      int l1, int l2, int zero_padding = true) {
    int l = l1 + l2 - 1;
    int M = 4;
    while (M < l) M <<= 1;
    if (zero_padding) {
      for (int i = l1; i < M; i++) ntt_inner::_buf1[i] = 0;
      for (int i = l2; i < M; i++) ntt_inner::_buf2[i] = 0;
    }
    const m256 m0 = _mm256_set1_epi32(0);
    const m256 m1 = _mm256_set1_epi32(mod);
    const m256 r = _mm256_set1_epi32(mint::r);
    const m256 N2 = _mm256_set1_epi32(mint::n2);
    for (int i = 0; i < l1; i += 8) {
      m256 a = _mm256_loadu_si256((m256 *)(ntt_inner::_buf1 + i));
      m256 b = mul_256(a, N2);
      _mm256_storeu_si256((m256 *)(ntt_inner::_buf1 + i), b);
    }
    for (int i = 0; i < l2; i += 8) {
      m256 a = _mm256_loadu_si256((m256 *)(ntt_inner::_buf2 + i));
      m256 b = mul_256(a, N2);
      _mm256_storeu_si256((m256 *)(ntt_inner::_buf2 + i), b);
    }
    ntt(buf1, M);
    ntt(buf2, M);
    for (int i = 0; i < M; i += 8) {
      m256 a = _mm256_loadu_si256((m256 *)(ntt_inner::_buf1 + i));
      m256 b = _mm256_loadu_si256((m256 *)(ntt_inner::_buf2 + i));
      m256 c = mul_256(a, b);
      _mm256_storeu_si256((m256 *)(ntt_inner::_buf1 + i), c);
    }
    intt(buf1, M, false);
    const m256 INVM = _mm256_set1_epi32((mint(M).inverse()).a);
    for (int i = 0; i < l; i += 8) {
      m256 a = _mm256_loadu_si256((m256 *)(ntt_inner::_buf1 + i));
      m256 b = mul_256(a, INVM);
      m256 c = my256_mulhi_epu32(my256_mullo_epu32(b, r), m1);
      m256 d = _mm256_and_si256(_mm256_cmpgt_epi32(c, m0), m1);
      m256 e = _mm256_sub_epi32(d, c);
      _mm256_storeu_si256((m256 *)(ntt_inner::_buf1 + i), e);
    }
  }

  vector<mint> multiply(const vector<mint> &a, const vector<mint> &b) {
    if (a.size() == 0 && b.size() == 0) return vector<mint>{};
    int l = a.size() + b.size() - 1;
    if (min<int>(a.size(), b.size()) <= 40) {
      vector<mint> s(l);
      for (int i = 0; i < (int)a.size(); ++i)
        for (int j = 0; j < (int)b.size(); ++j) s[i + j] += a[i] * b[j];
      return s;
    }
    assert(l <= ntt_inner::SZ_FFT_BUF);
    int M = 4;
    while (M < l) M <<= 1;
    for (int i = 0; i < (int)a.size(); ++i) buf1[i].a = a[i].a;
    for (int i = (int)a.size(); i < M; ++i) buf1[i].a = 0;
    for (int i = 0; i < (int)b.size(); ++i) buf2[i].a = b[i].a;
    for (int i = (int)b.size(); i < M; ++i) buf2[i].a = 0;
    ntt(buf1, M);
    ntt(buf2, M);
    for (int i = 0; i < M; ++i)
      buf1[i].a = mint::reduce(uint64_t(buf1[i].a) * buf2[i].a);
    intt(buf1, M, false);
    vector<mint> s(l);
    mint invm = mint(M).inverse();
    for (int i = 0; i < l; ++i) s[i] = buf1[i] * invm;
    return s;
  }
};
