#pragma once

#include "../modint/vectorize-modint.hpp"

// B*Bの正方行列を高速に乗算するライブラリ。
// B*B行列a,bを タテB行 ヨコB/8行の行列と見なす.
// s : 正順に配置。すなわちa_{i,k}をs[i * (B / 8) + k]に配置する。
// t : 逆順に配置。すなわちb_{k,j}をt[j * B + k]に配置する。
// u : 正順に配置。すなわちc_{i,j}をu[i * (B / 8) + j]に配置する。
namespace fast_mat_prod_impl {
constexpr int B = 1 << 7;
constexpr int B8 = B / 8;

void mul_simd(mmint* __restrict__ s, mmint* __restrict__ t,
              mmint* __restrict__ u) {
  for (int i = 0; i < B * B8; i++) {
    const m256 cmpS = _mm256_cmpgt_epi32(s[i], mmint::M1);
    const m256 cmpT = _mm256_cmpgt_epi32(t[i], mmint::M1);
    const m256 difS = _mm256_and_si256(cmpS, mmint::M1);
    const m256 difT = _mm256_and_si256(cmpT, mmint::M1);
    s[i] = _mm256_sub_epi32(s[i], difS);
    t[i] = _mm256_sub_epi32(t[i], difT);
  }

  mmint th1, th2, zero = _mm256_setzero_si256();
  th1[1] = th1[3] = th1[5] = th1[7] = mmint::M1[0];
  th2[1] = th2[3] = th2[5] = th2[7] = mmint::M2[0];

#define INIT_X(x, y)                          \
  m256 prod02##x##y = _mm256_setzero_si256(); \
  m256 prod13##x##y = _mm256_setzero_si256()

#define INIT_Y(j, k, l, y)            \
  m256 T##y = t[(j + y) * B + k + l]; \
  const m256 T13##y = _mm256_shuffle_epi32(T##y, 0xF5);

#define PROD(x, y)                                              \
  m256 S##x##y = _mm256_set1_epi32(s[(i + x) * B8 + k / 8][l]); \
  const m256 ST02##x##y = _mm256_mul_epu32(S##x##y, T##y);      \
  const m256 ST13##x##y = _mm256_mul_epu32(S##x##y, T13##y);    \
  prod02##x##y = _mm256_add_epi64(prod02##x##y, ST02##x##y);    \
  prod13##x##y = _mm256_add_epi64(prod13##x##y, ST13##x##y)

#define COMP(x, y)                                            \
  m256 cmp02##x##y = _mm256_cmpgt_epi64(zero, prod02##x##y);  \
  m256 cmp13##x##y = _mm256_cmpgt_epi64(zero, prod13##x##y);  \
  m256 dif02##x##y = _mm256_and_si256(cmp02##x##y, th2);      \
  m256 dif13##x##y = _mm256_and_si256(cmp13##x##y, th2);      \
  prod02##x##y = _mm256_sub_epi64(prod02##x##y, dif02##x##y); \
  prod13##x##y = _mm256_sub_epi64(prod13##x##y, dif13##x##y)

#define REDUCE(x, y)                                      \
  for (int _ = 0; _ < 2; _++) {                           \
    m256 cmp02 = _mm256_cmpgt_epi64(prod02##x##y, th1);   \
    m256 cmp13 = _mm256_cmpgt_epi64(prod13##x##y, th1);   \
    m256 dif02 = _mm256_and_si256(cmp02, th1);            \
    m256 dif13 = _mm256_and_si256(cmp13, th1);            \
    prod02##x##y = _mm256_sub_epi64(prod02##x##y, dif02); \
    prod13##x##y = _mm256_sub_epi64(prod13##x##y, dif13); \
  }                                                       \
  u[(i + x) * B8 + j + y] = mmint::reduce(prod02##x##y, prod13##x##y)

  for (int i = 0; i < B; i += 8) {
    for (int j = 0; j < B8; j += 1) {
      INIT_X(0, 0);
      INIT_X(1, 0);
      INIT_X(2, 0);
      INIT_X(3, 0);
      INIT_X(4, 0);
      INIT_X(5, 0);
      INIT_X(6, 0);
      INIT_X(7, 0);
      for (int k = 0; k < B; k += 8) {
        for (int l = 0; l < 8; l++) {
          INIT_Y(j, k, l, 0);
          PROD(0, 0);
          PROD(1, 0);
          PROD(2, 0);
          PROD(3, 0);
          PROD(4, 0);
          PROD(5, 0);
          PROD(6, 0);
          PROD(7, 0);
        }
        COMP(0, 0);
        COMP(1, 0);
        COMP(2, 0);
        COMP(3, 0);
        COMP(4, 0);
        COMP(5, 0);
        COMP(6, 0);
        COMP(7, 0);
      }
      REDUCE(0, 0);
      REDUCE(1, 0);
      REDUCE(2, 0);
      REDUCE(3, 0);
      REDUCE(4, 0);
      REDUCE(5, 0);
      REDUCE(6, 0);
      REDUCE(7, 0);
    }
  }
}

#undef INIT
#undef PROD
#undef COMP
#undef REDUCE

void strassen(int N, mmint* __restrict__ s, mmint* __restrict__ t,
              mmint* __restrict__ u) {
  for (int i = 0; i < N * N / 8; i++) u[i] = mmint::M0;

  if (N == B) {
    mul_simd(s, t, u);
    return;
  }

  mmint* ps = s + N * N / 8;
  mmint* pt = t + N * N / 8;
  mmint* pu = u + N * N / 8;
  int nx = N * N / 32;
  int o11 = nx * 0, o12 = nx * 1, o21 = nx * 2, o22 = nx * 3;

  // P1
  for (int i = 0; i < nx; i++) ps[i] = s[o11 + i] + s[o22 + i];
  for (int i = 0; i < nx; i++) pt[i] = t[o11 + i] + t[o22 + i];
  strassen(N / 2, ps, pt, pu);
  for (int i = 0; i < nx; i++) u[o11 + i] = pu[i], u[o22 + i] = pu[i];

  // P2
  for (int i = 0; i < nx; i++) ps[i] = s[o21 + i] + s[o22 + i];
  for (int i = 0; i < nx; i++) pt[i] = t[o11 + i];
  strassen(N / 2, ps, pt, pu);
  for (int i = 0; i < nx; i++) u[o21 + i] = pu[i], u[o22 + i] -= pu[i];

  // P3
  for (int i = 0; i < nx; i++) ps[i] = s[o11 + i];
  for (int i = 0; i < nx; i++) pt[i] = t[o12 + i] - t[o22 + i];
  strassen(N / 2, ps, pt, pu);
  for (int i = 0; i < nx; i++) u[o12 + i] = pu[i], u[o22 + i] += pu[i];

  // P4
  for (int i = 0; i < nx; i++) ps[i] = s[o22 + i];
  for (int i = 0; i < nx; i++) pt[i] = t[o21 + i] - t[o11 + i];
  strassen(N / 2, ps, pt, pu);
  for (int i = 0; i < nx; i++) u[o11 + i] += pu[i], u[o21 + i] += pu[i];

  // P5
  for (int i = 0; i < nx; i++) ps[i] = s[o11 + i] + s[o12 + i];
  for (int i = 0; i < nx; i++) pt[i] = t[o22 + i];
  strassen(N / 2, ps, pt, pu);
  for (int i = 0; i < nx; i++) u[o11 + i] -= pu[i], u[o12 + i] += pu[i];

  // P6
  for (int i = 0; i < nx; i++) ps[i] = s[o21 + i] - s[o11 + i];
  for (int i = 0; i < nx; i++) pt[i] = t[o11 + i] + t[o12 + i];
  strassen(N / 2, ps, pt, pu);
  for (int i = 0; i < nx; i++) u[o22 + i] += pu[i];

  // P7
  for (int i = 0; i < nx; i++) ps[i] = s[o12 + i] - s[o22 + i];
  for (int i = 0; i < nx; i++) pt[i] = t[o21 + i] + t[o22 + i];
  strassen(N / 2, ps, pt, pu);
  for (int i = 0; i < nx; i++) u[o11 + i] += pu[i];
}

constexpr int S = 1024;
constexpr int S8 = S / 8;
mmint s[S * S8 * 3 / 2], t[S * S8 * 3 / 2], u[S * S8 * 3 / 2];

void place_s(int N, int a, int b, mmint* __restrict__ dst,
             mmint* __restrict__ src) {
  if (N == B) {
    for (int i = 0; i < B; i++) {
      memcpy(dst + i * B8, src + (a + i) * S8 + b / 8, B8 * sizeof(mmint));
    }
    return;
  }
  int nx = N * N / 32, M = N / 2;
  place_s(M, a + 0, b + 0, dst + nx * 0, src);
  place_s(M, a + 0, b + M, dst + nx * 1, src);
  place_s(M, a + M, b + 0, dst + nx * 2, src);
  place_s(M, a + M, b + M, dst + nx * 3, src);
}

void place_t(int N, int a, int b, mmint* __restrict__ dst,
             mmint* __restrict__ src) {
  if (N == B) {
    // t : 逆順に配置。すなわちb_{k,j}をt[j * B + k]に配置する。
    for (int k = 0; k < B; k++) {
      for (int j = 0; j < B8; j++) {
        dst[j * B + k] = src[(a + k) * S8 + j + b / 8];
      }
    }
    return;
  }
  int nx = N * N / 32, M = N / 2;
  place_t(M, a + 0, b + 0, dst + nx * 0, src);
  place_t(M, a + 0, b + M, dst + nx * 1, src);
  place_t(M, a + M, b + 0, dst + nx * 2, src);
  place_t(M, a + M, b + M, dst + nx * 3, src);
}

void place_rev(int N, int a, int b, mmint* __restrict__ dst,
               mmint* __restrict__ src) {
  if (N == B) {
    for (int i = 0; i < B; i++) {
      memcpy(src + (a + i) * S8 + b / 8, dst + i * B8, B8 * sizeof(mmint));
    }
    return;
  }
  int nx = N * N / 32, M = N / 2;
  place_rev(M, a + 0, b + 0, dst + nx * 0, src);
  place_rev(M, a + 0, b + M, dst + nx * 1, src);
  place_rev(M, a + M, b + 0, dst + nx * 2, src);
  place_rev(M, a + M, b + M, dst + nx * 3, src);
}

void prod(unsigned int* __restrict__ a, unsigned int* __restrict__ b,
          unsigned int* __restrict__ c) {
  place_s(S, 0, 0, s, reinterpret_cast<mmint*>(a));
  place_t(S, 0, 0, t, reinterpret_cast<mmint*>(b));
  for (int i = 0; i < S * S8; i++) s[i] = mmint::itom(s[i]);
  for (int i = 0; i < S * S8; i++) t[i] = mmint::itom(t[i]);
  strassen(S, s, t, u);
  for (int i = 0; i < S * S8; i++) u[i] = mmint::mtoi(u[i]);
  place_rev(S, 0, 0, u, reinterpret_cast<mmint*>(c));
}

}  // namespace fast_mat_prod_impl
