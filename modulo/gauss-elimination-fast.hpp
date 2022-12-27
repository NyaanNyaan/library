#pragma once

#include "../modint/simd-montgomery.hpp"


namespace Gauss {
  
constexpr int MAT_SIZE = 4096;
uint32_t a_buf_[MAT_SIZE][MAT_SIZE] __attribute__((aligned(64)));

// return value: (rank, (-1) ^ (number of swap time))
template <typename mint>
__attribute__((target("avx2"))) pair<int, mint> GaussianElimination(
    const vector<vector<mint>> &m, int LinearEquation = false) {
  mint(&a)[MAT_SIZE][MAT_SIZE] = *reinterpret_cast<mint(*)[MAT_SIZE][MAT_SIZE]>(a_buf_);
  int H = m.size(), W = m[0].size(), rank = 0;
  mint det = 1;
  for (int i = 0; i < H; i++)
    for (int j = 0; j < W; j++) a[i][j].a = m[i][j].a;

  __m256i r = _mm256_set1_epi32(mint::r);
  __m256i m0 = _mm256_set1_epi32(0);
  __m256i m1 = _mm256_set1_epi32(mint::get_mod());
  __m256i m2 = _mm256_set1_epi32(mint::get_mod() << 1);

  for (int j = 0; j < (LinearEquation ? (W - 1) : W); j++) {
    // find basis
    if (rank == H) break;
    int idx = -1;
    for (int i = rank; i < H; i++) {
      if (a[i][j].get() != 0) {
        idx = i;
        break;
      }
    }
    if (idx == -1) {
      det = 0;
      continue;
    }

    // swap
    if (rank != idx) {
      det = -det;
      for (int l = j; l < W; l++) swap(a[rank][l], a[idx][l]);
    }
    det *= a[rank][j];

    // normalize
    if (LinearEquation) {
      if (a[rank][j].get() != 1) {
        mint coeff = a[rank][j].inverse();
        __m256i COEFF = _mm256_set1_epi32(coeff.a);
        for (int i = j / 8 * 8; i < W; i += 8) {
          __m256i R = _mm256_load_si256((__m256i *)(a[rank] + i));
          __m256i RmulC = montgomery_mul_256(R, COEFF, r, m1);
          _mm256_store_si256((__m256i *)(a[rank] + i), RmulC);
        }
      }
    }

    // elimination
    for (int k = (LinearEquation ? 0 : rank + 1); k < H; k++) {
      if (k == rank) continue;
      if (a[k][j].get() != 0) {
        mint coeff = a[k][j] / a[rank][j];
        __m256i COEFF = _mm256_set1_epi32(coeff.a);
        for (int i = j / 8 * 8; i < W; i += 8) {
          __m256i R = _mm256_load_si256((__m256i *)(a[rank] + i));
          __m256i K = _mm256_load_si256((__m256i *)(a[k] + i));
          __m256i RmulC = montgomery_mul_256(R, COEFF, r, m1);
          __m256i KmnsR = montgomery_sub_256(K, RmulC, m2, m0);
          _mm256_store_si256((__m256i *)(a[k] + i), KmnsR);
        }
      }
    }
    rank++;
  }
  return {rank, det};
}

// calculate determinant
template <typename mint>
mint determinant(const vector<vector<mint>> &mat) {
  return GaussianElimination(mat).second;
}

// return V<V<mint>>
// 0 column ... one of solutions
// 1 ~ (W - rank) column ... bases
// if not exist, return empty vector
template <typename mint>
vector<vector<mint>> LinearEquation(vector<vector<mint>> A, vector<mint> B) {
  int H = A.size(), W = A[0].size();
  for (int i = 0; i < H; i++) A[i].push_back(B[i]);

  auto p = GaussianElimination(A, true);

  mint(&a)[MAT_SIZE][MAT_SIZE] = *reinterpret_cast<mint(*)[MAT_SIZE][MAT_SIZE]>(a_buf_);
  int rank = p.first;

  // check if solutions exist
  for (int i = rank; i < H; ++i)
    if (a[i][W] != 0) return vector<vector<mint>>{};

  vector<vector<mint>> res(1, vector<mint>(W));
  vector<int> pivot(W, -1);
  for (int i = 0, j = 0; i < rank; ++i) {
    while (a[i][j] == 0) ++j;
    res[0][j] = a[i][W], pivot[j] = i;
  }
  for (int j = 0; j < W; ++j) {
    if (pivot[j] == -1) {
      vector<mint> x(W);
      x[j] = 1;
      for (int k = 0; k < j; ++k)
        if (pivot[k] != -1) x[k] = -a[pivot[k]][j];
      res.push_back(x);
    }
  }
  return res;
}

}  // namespace Gauss

using Gauss::determinant;
using Gauss::LinearEquation;
