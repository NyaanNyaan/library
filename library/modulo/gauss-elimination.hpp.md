---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :heavy_check_mark: modulo/gauss-elimination.hpp

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#5dcb4a1ea5a35da52691d50c8313c333">modulo</a>
* <a href="{{ site.github.repository_url }}/blob/master/modulo/gauss-elimination.hpp">View this file on GitHub</a>
    - Last commit date: 2020-07-30 19:30:32+09:00




## Depends on

* :question: <a href="../modint/simd-montgomery.hpp.html">modint/simd-montgomery.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-math/yosupo-determinant.test.cpp.html">verify/verify-yosupo-math/yosupo-determinant.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-math/yosupo-linear-equation.test.cpp.html">verify/verify-yosupo-math/yosupo-linear-equation.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/verify/verify-yosupo-math/yosupo-sparse-determinant.test.cpp.html">verify/verify-yosupo-math/yosupo-sparse-determinant.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#pragma once
#include <bits/stdc++.h>
using namespace std;

#include "modint/simd-montgomery.hpp"

namespace Gauss {
uint32_t a_buf_[4096][4096] __attribute__((aligned(64)));

// return value: (rank, (-1) ^ (number of swap time))
template <typename mint>
__attribute__((target("avx2"))) pair<int, int> GaussianElimination(
    const vector<vector<mint>> &m, int LinearEquation = false) {
  mint(&a)[4096][4096] = *reinterpret_cast<mint(*)[4096][4096]>(a_buf_);
  int H = m.size(), W = m[0].size(), rank = 0;
  int det = 1;
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
      if (a[i][j].get() != 0) idx = i;
      if (idx != -1) break;
    }
    if (idx == -1) {
      if (LinearEquation)
        continue;
      else
        return {0, 0};
    }

    // swap
    if (rank != idx) {
      det = -det;
      for (int l = j; l < W; l++) swap(a[rank][l], a[idx][l]);
    }

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
      if (a[k][rank].get() != 0) {
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
  mint(&a)[4096][4096] = *reinterpret_cast<mint(*)[4096][4096]>(a_buf_);
  auto p = GaussianElimination(mat);
  if (p.first != (int)mat.size()) return mint(0);
  mint det = p.second;
  for (int i = 0; i < (int)mat.size(); i++) det *= a[i][i];
  return det;
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

  mint(&a)[4096][4096] = *reinterpret_cast<mint(*)[4096][4096]>(a_buf_);
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
      x[j] = -1;
      for (int k = 0; k < j; ++k)
        if (pivot[k] != -1) x[k] = a[pivot[k]][j];
      res.push_back(x);
    }
  }
  return res;
}

}  // namespace Gauss
using namespace Gauss;

```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
#line 2 "modulo/gauss-elimination.hpp"
#include <bits/stdc++.h>
using namespace std;

#line 3 "modint/simd-montgomery.hpp"
using namespace std;
#line 5 "modint/simd-montgomery.hpp"

__attribute__((target("sse4.2"))) __attribute__((always_inline)) __m128i
my128_mullo_epu32(const __m128i &a, const __m128i &b) {
  return _mm_mullo_epi32(a, b);
}

__attribute__((target("sse4.2"))) __attribute__((always_inline)) __m128i
my128_mulhi_epu32(const __m128i &a, const __m128i &b) {
  __m128i a13 = _mm_shuffle_epi32(a, 0xF5);
  __m128i b13 = _mm_shuffle_epi32(b, 0xF5);
  __m128i prod02 = _mm_mul_epu32(a, b);
  __m128i prod13 = _mm_mul_epu32(a13, b13);
  __m128i prod = _mm_unpackhi_epi64(_mm_unpacklo_epi32(prod02, prod13),
                                    _mm_unpackhi_epi32(prod02, prod13));
  return prod;
}

__attribute__((target("sse4.2"))) __attribute__((always_inline)) __m128i
montgomery_mul_128(const __m128i &a, const __m128i &b, const __m128i &r,
                   const __m128i &m1) {
  return _mm_sub_epi32(
      _mm_add_epi32(my128_mulhi_epu32(a, b), m1),
      my128_mulhi_epu32(my128_mullo_epu32(my128_mullo_epu32(a, b), r), m1));
}

__attribute__((target("sse4.2"))) __attribute__((always_inline)) __m128i
montgomery_add_128(const __m128i &a, const __m128i &b, const __m128i &m2,
                   const __m128i &m0) {
  __m128i ret = _mm_sub_epi32(_mm_add_epi32(a, b), m2);
  return _mm_add_epi32(_mm_and_si128(_mm_cmpgt_epi32(m0, ret), m2), ret);
}

__attribute__((target("sse4.2"))) __attribute__((always_inline)) __m128i
montgomery_sub_128(const __m128i &a, const __m128i &b, const __m128i &m2,
                   const __m128i &m0) {
  __m128i ret = _mm_sub_epi32(a, b);
  return _mm_add_epi32(_mm_and_si128(_mm_cmpgt_epi32(m0, ret), m2), ret);
}

__attribute__((target("avx2"))) __attribute__((always_inline)) __m256i
my256_mullo_epu32(const __m256i &a, const __m256i &b) {
  return _mm256_mullo_epi32(a, b);
}

__attribute__((target("avx2"))) __attribute__((always_inline)) __m256i
my256_mulhi_epu32(const __m256i &a, const __m256i &b) {
  __m256i a13 = _mm256_shuffle_epi32(a, 0xF5);
  __m256i b13 = _mm256_shuffle_epi32(b, 0xF5);
  __m256i prod02 = _mm256_mul_epu32(a, b);
  __m256i prod13 = _mm256_mul_epu32(a13, b13);
  __m256i prod = _mm256_unpackhi_epi64(_mm256_unpacklo_epi32(prod02, prod13),
                                       _mm256_unpackhi_epi32(prod02, prod13));
  return prod;
}

__attribute__((target("avx2"))) __attribute__((always_inline)) __m256i
montgomery_mul_256(const __m256i &a, const __m256i &b, const __m256i &r,
                   const __m256i &m1) {
  return _mm256_sub_epi32(
      _mm256_add_epi32(my256_mulhi_epu32(a, b), m1),
      my256_mulhi_epu32(my256_mullo_epu32(my256_mullo_epu32(a, b), r), m1));
}

__attribute__((target("avx2"))) __attribute__((always_inline)) __m256i
montgomery_add_256(const __m256i &a, const __m256i &b, const __m256i &m2,
                   const __m256i &m0) {
  __m256i ret = _mm256_sub_epi32(_mm256_add_epi32(a, b), m2);
  return _mm256_add_epi32(_mm256_and_si256(_mm256_cmpgt_epi32(m0, ret), m2),
                          ret);
}

__attribute__((target("avx2"))) __attribute__((always_inline)) __m256i
montgomery_sub_256(const __m256i &a, const __m256i &b, const __m256i &m2,
                   const __m256i &m0) {
  __m256i ret = _mm256_sub_epi32(a, b);
  return _mm256_add_epi32(_mm256_and_si256(_mm256_cmpgt_epi32(m0, ret), m2),
                          ret);
}
#line 6 "modulo/gauss-elimination.hpp"

namespace Gauss {
uint32_t a_buf_[4096][4096] __attribute__((aligned(64)));

// return value: (rank, (-1) ^ (number of swap time))
template <typename mint>
__attribute__((target("avx2"))) pair<int, int> GaussianElimination(
    const vector<vector<mint>> &m, int LinearEquation = false) {
  mint(&a)[4096][4096] = *reinterpret_cast<mint(*)[4096][4096]>(a_buf_);
  int H = m.size(), W = m[0].size(), rank = 0;
  int det = 1;
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
      if (a[i][j].get() != 0) idx = i;
      if (idx != -1) break;
    }
    if (idx == -1) {
      if (LinearEquation)
        continue;
      else
        return {0, 0};
    }

    // swap
    if (rank != idx) {
      det = -det;
      for (int l = j; l < W; l++) swap(a[rank][l], a[idx][l]);
    }

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
      if (a[k][rank].get() != 0) {
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
  mint(&a)[4096][4096] = *reinterpret_cast<mint(*)[4096][4096]>(a_buf_);
  auto p = GaussianElimination(mat);
  if (p.first != (int)mat.size()) return mint(0);
  mint det = p.second;
  for (int i = 0; i < (int)mat.size(); i++) det *= a[i][i];
  return det;
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

  mint(&a)[4096][4096] = *reinterpret_cast<mint(*)[4096][4096]>(a_buf_);
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
      x[j] = -1;
      for (int k = 0; k < j; ++k)
        if (pivot[k] != -1) x[k] = a[pivot[k]][j];
      res.push_back(x);
    }
  }
  return res;
}

}  // namespace Gauss
using namespace Gauss;

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

