#pragma once

#include <cassert>
#include <vector>
using namespace std;

#include "../modint/vectorize-modint.hpp"

template <typename mint>
vector<mint> fast_multiply(const vector<mint>& a, const vector<mint>& b) {
  int n = a.size();
  int d = __builtin_ctz(n);
  assert(d <= 23);
  mmint* a1 = new mmint[max(n, 8) * 3];
  mmint* a2 = new mmint[max(n, 8) * 3];
  memset((void*)a1, 0, max(n, 8) * 3 * sizeof(mmint));
  memset((void*)a2, 0, max(n, 8) * 3 * sizeof(mmint));
  mmint b1[24], b2[24], b3[24];

  for (int i = 0; i < n; i++) {
    unsigned int pc = __builtin_popcount(i);
    a1[i * 3 + pc / 8][pc % 8] = a[i].a;
    a2[i * 3 + pc / 8][pc % 8] = b[i].a;
  }

  for (int j = 2; j <= n; j += 2) {
    unsigned int pc = __builtin_popcount(j);
    unsigned int ctz = __builtin_ctz(j);
    for (int h = 0; h < d; h++) {
      if (j & (1 << h)) break;
      int li = j - 2 * (1 << h), ri = j - (1 << h);
      if (pc + ctz <= 16) {
        for (int i = 0; i < 3 * (1 << h); i += 3) {
          a1[ri * 3 + i + 0] += a1[li * 3 + i + 0];
          a2[ri * 3 + i + 0] += a2[li * 3 + i + 0];
          a1[ri * 3 + i + 1] += a1[li * 3 + i + 1];
          a2[ri * 3 + i + 1] += a2[li * 3 + i + 1];
        }
      } else {
        for (int i = 0; i < 3 * (1 << h); i++) {
          a1[ri * 3 + i] += a1[li * 3 + i];
          a2[ri * 3 + i] += a2[li * 3 + i];
        }
      }
    }
  }

  mmint th = _mm256_set1_epi64x(4LL * mmint::M1[0] * mmint::M1[0]);

  for (int is = 0; is < n; is += 8) {
    int mpc = d;

    for (int i = is; i < is + 8; i++) {
      int pc = __builtin_popcount(i);
      mpc = min(mpc, pc);
      for (int j = 0; j <= d; j++) {
        b1[j][i - is] = a1[i * 3 + j / 8][j % 8];
        b2[j][i - is] = a2[i * 3 + j / 8][j % 8];
        b3[j][i - is] = 0;
      }
    }

    for (int j = 0; j <= d; j++) {
      m256 cmpB1 = _mm256_cmpgt_epi32(mmint::M1, b1[j]);
      m256 cmpB2 = _mm256_cmpgt_epi32(mmint::M1, b2[j]);
      m256 difB1 = _mm256_andnot_si256(cmpB1, mmint::M1);
      m256 difB2 = _mm256_andnot_si256(cmpB2, mmint::M1);
      b1[j] = _mm256_sub_epi32(b1[j], difB1);
      b2[j] = _mm256_sub_epi32(b2[j], difB2);
    }

#define PROD(k)                                             \
  m256 A13##k = _mm256_shuffle_epi32(b1[j + k], 0xF5);      \
  m256 B13##k = _mm256_shuffle_epi32(b2[l - j - k], 0xF5);  \
  m256 p02##k = _mm256_mul_epi32(b1[j + k], b2[l - j - k]); \
  m256 p13##k = _mm256_mul_epi32(A13##k, B13##k);           \
  prod02 = _mm256_add_epi64(prod02, p02##k);                \
  prod13 = _mm256_add_epi64(prod13, p13##k)
#define COMP()                                   \
  do {                                           \
    m256 cmp02 = _mm256_cmpgt_epi64(prod02, th); \
    m256 cmp13 = _mm256_cmpgt_epi64(prod13, th); \
    m256 dif02 = _mm256_and_si256(cmp02, th);    \
    m256 dif13 = _mm256_and_si256(cmp13, th);    \
    prod02 = _mm256_sub_epi64(prod02, dif02);    \
    prod13 = _mm256_sub_epi64(prod13, dif13);    \
  } while (0)

    for (int l = mpc; l <= d; l++) {
      int j = 0;
      mmint prod02 = mmint::M0, prod13 = mmint::M0;

      for (; j <= l - 3; j += 4) {
        PROD(0);
        PROD(1);
        PROD(2);
        PROD(3);
        COMP();
      }
      for (; j <= l; j++) {
        PROD(0);
      }
      COMP();
      b3[l] = mmint::reduce(prod02, prod13);
    }

#undef PROD
#undef COMP

    for (int i = is; i < is + 8; i++) {
      for (unsigned j = mpc; j <= unsigned(d); j++) {
        a1[i * 3 + j / 8][j % 8] = b3[j][i - is];
      }
    }
  }

  for (int j = 2; j <= n; j += 2) {
    for (int h = 0; h < d; h++) {
      if (j & (1 << h)) break;
      int li = j - 2 * (1 << h), ri = j - (1 << h);
      for (int i = 0; i < 3 * (1 << h); i++) {
        a1[ri * 3 + i] -= a1[li * 3 + i];
      }
    }
  }

  vector<mint> c(n);
  for (int i = 0; i < n; i++) {
    unsigned int pc = __builtin_popcount(i);
    c[i].a = a1[i * 3 + pc / 8][pc % 8];
  }

  delete[] (a1);
  delete[] (a2);
  return c;
}
