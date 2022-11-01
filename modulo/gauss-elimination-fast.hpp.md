---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: modint/simd-montgomery.hpp
    title: modint/simd-montgomery.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: verify/verify-unit-test/gauss-elimination.test.cpp
    title: verify/verify-unit-test/gauss-elimination.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-determinant.test.cpp
    title: verify/verify-yosupo-math/yosupo-determinant.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-linear-equation.test.cpp
    title: verify/verify-yosupo-math/yosupo-linear-equation.test.cpp
  - icon: ':heavy_check_mark:'
    path: verify/verify-yosupo-math/yosupo-sparse-determinant.test.cpp
    title: verify/verify-yosupo-math/yosupo-sparse-determinant.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"modulo/gauss-elimination-fast.hpp\"\n\n#line 2 \"modint/simd-montgomery.hpp\"\
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
    \ m2),\n                          ret);\n}\n#line 4 \"modulo/gauss-elimination-fast.hpp\"\
    \n\n\nnamespace Gauss {\n  \nconstexpr int MAT_SIZE = 4096;\nuint32_t a_buf_[MAT_SIZE][MAT_SIZE]\
    \ __attribute__((aligned(64)));\n\n// return value: (rank, (-1) ^ (number of swap\
    \ time))\ntemplate <typename mint>\n__attribute__((target(\"avx2\"))) pair<int,\
    \ mint> GaussianElimination(\n    const vector<vector<mint>> &m, int LinearEquation\
    \ = false) {\n  mint(&a)[MAT_SIZE][MAT_SIZE] = *reinterpret_cast<mint(*)[MAT_SIZE][MAT_SIZE]>(a_buf_);\n\
    \  int H = m.size(), W = m[0].size(), rank = 0;\n  mint det = 1;\n  for (int i\
    \ = 0; i < H; i++)\n    for (int j = 0; j < W; j++) a[i][j].a = m[i][j].a;\n\n\
    \  __m256i r = _mm256_set1_epi32(mint::r);\n  __m256i m0 = _mm256_set1_epi32(0);\n\
    \  __m256i m1 = _mm256_set1_epi32(mint::get_mod());\n  __m256i m2 = _mm256_set1_epi32(mint::get_mod()\
    \ << 1);\n\n  for (int j = 0; j < (LinearEquation ? (W - 1) : W); j++) {\n   \
    \ // find basis\n    if (rank == H) break;\n    int idx = -1;\n    for (int i\
    \ = rank; i < H; i++) {\n      if (a[i][j].get() != 0) {\n        idx = i;\n \
    \       break;\n      }\n    }\n    if (idx == -1) {\n      det = 0;\n      continue;\n\
    \    }\n\n    // swap\n    if (rank != idx) {\n      det = -det;\n      for (int\
    \ l = j; l < W; l++) swap(a[rank][l], a[idx][l]);\n    }\n    det *= a[rank][j];\n\
    \n    // normalize\n    if (LinearEquation) {\n      if (a[rank][j].get() != 1)\
    \ {\n        mint coeff = a[rank][j].inverse();\n        __m256i COEFF = _mm256_set1_epi32(coeff.a);\n\
    \        for (int i = j / 8 * 8; i < W; i += 8) {\n          __m256i R = _mm256_load_si256((__m256i\
    \ *)(a[rank] + i));\n          __m256i RmulC = montgomery_mul_256(R, COEFF, r,\
    \ m1);\n          _mm256_store_si256((__m256i *)(a[rank] + i), RmulC);\n     \
    \   }\n      }\n    }\n\n    // elimination\n    for (int k = (LinearEquation\
    \ ? 0 : rank + 1); k < H; k++) {\n      if (k == rank) continue;\n      if (a[k][j].get()\
    \ != 0) {\n        mint coeff = a[k][j] / a[rank][j];\n        __m256i COEFF =\
    \ _mm256_set1_epi32(coeff.a);\n        for (int i = j / 8 * 8; i < W; i += 8)\
    \ {\n          __m256i R = _mm256_load_si256((__m256i *)(a[rank] + i));\n    \
    \      __m256i K = _mm256_load_si256((__m256i *)(a[k] + i));\n          __m256i\
    \ RmulC = montgomery_mul_256(R, COEFF, r, m1);\n          __m256i KmnsR = montgomery_sub_256(K,\
    \ RmulC, m2, m0);\n          _mm256_store_si256((__m256i *)(a[k] + i), KmnsR);\n\
    \        }\n      }\n    }\n    rank++;\n  }\n  return {rank, det};\n}\n\n// calculate\
    \ determinant\ntemplate <typename mint>\nmint determinant(const vector<vector<mint>>\
    \ &mat) {\n  return GaussianElimination(mat).second;\n}\n\n// return V<V<mint>>\n\
    // 0 column ... one of solutions\n// 1 ~ (W - rank) column ... bases\n// if not\
    \ exist, return empty vector\ntemplate <typename mint>\nvector<vector<mint>> LinearEquation(vector<vector<mint>>\
    \ A, vector<mint> B) {\n  int H = A.size(), W = A[0].size();\n  for (int i = 0;\
    \ i < H; i++) A[i].push_back(B[i]);\n\n  auto p = GaussianElimination(A, true);\n\
    \n  mint(&a)[MAT_SIZE][MAT_SIZE] = *reinterpret_cast<mint(*)[MAT_SIZE][MAT_SIZE]>(a_buf_);\n\
    \  int rank = p.first;\n\n  // check if solutions exist\n  for (int i = rank;\
    \ i < H; ++i)\n    if (a[i][W] != 0) return vector<vector<mint>>{};\n\n  vector<vector<mint>>\
    \ res(1, vector<mint>(W));\n  vector<int> pivot(W, -1);\n  for (int i = 0, j =\
    \ 0; i < rank; ++i) {\n    while (a[i][j] == 0) ++j;\n    res[0][j] = a[i][W],\
    \ pivot[j] = i;\n  }\n  for (int j = 0; j < W; ++j) {\n    if (pivot[j] == -1)\
    \ {\n      vector<mint> x(W);\n      x[j] = 1;\n      for (int k = 0; k < j; ++k)\n\
    \        if (pivot[k] != -1) x[k] = -a[pivot[k]][j];\n      res.push_back(x);\n\
    \    }\n  }\n  return res;\n}\n\n}  // namespace Gauss\n\nusing Gauss::determinant;\n\
    using Gauss::LinearEquation;\n"
  code: "#pragma once\n\n#include \"../modint/simd-montgomery.hpp\"\n\n\nnamespace\
    \ Gauss {\n  \nconstexpr int MAT_SIZE = 4096;\nuint32_t a_buf_[MAT_SIZE][MAT_SIZE]\
    \ __attribute__((aligned(64)));\n\n// return value: (rank, (-1) ^ (number of swap\
    \ time))\ntemplate <typename mint>\n__attribute__((target(\"avx2\"))) pair<int,\
    \ mint> GaussianElimination(\n    const vector<vector<mint>> &m, int LinearEquation\
    \ = false) {\n  mint(&a)[MAT_SIZE][MAT_SIZE] = *reinterpret_cast<mint(*)[MAT_SIZE][MAT_SIZE]>(a_buf_);\n\
    \  int H = m.size(), W = m[0].size(), rank = 0;\n  mint det = 1;\n  for (int i\
    \ = 0; i < H; i++)\n    for (int j = 0; j < W; j++) a[i][j].a = m[i][j].a;\n\n\
    \  __m256i r = _mm256_set1_epi32(mint::r);\n  __m256i m0 = _mm256_set1_epi32(0);\n\
    \  __m256i m1 = _mm256_set1_epi32(mint::get_mod());\n  __m256i m2 = _mm256_set1_epi32(mint::get_mod()\
    \ << 1);\n\n  for (int j = 0; j < (LinearEquation ? (W - 1) : W); j++) {\n   \
    \ // find basis\n    if (rank == H) break;\n    int idx = -1;\n    for (int i\
    \ = rank; i < H; i++) {\n      if (a[i][j].get() != 0) {\n        idx = i;\n \
    \       break;\n      }\n    }\n    if (idx == -1) {\n      det = 0;\n      continue;\n\
    \    }\n\n    // swap\n    if (rank != idx) {\n      det = -det;\n      for (int\
    \ l = j; l < W; l++) swap(a[rank][l], a[idx][l]);\n    }\n    det *= a[rank][j];\n\
    \n    // normalize\n    if (LinearEquation) {\n      if (a[rank][j].get() != 1)\
    \ {\n        mint coeff = a[rank][j].inverse();\n        __m256i COEFF = _mm256_set1_epi32(coeff.a);\n\
    \        for (int i = j / 8 * 8; i < W; i += 8) {\n          __m256i R = _mm256_load_si256((__m256i\
    \ *)(a[rank] + i));\n          __m256i RmulC = montgomery_mul_256(R, COEFF, r,\
    \ m1);\n          _mm256_store_si256((__m256i *)(a[rank] + i), RmulC);\n     \
    \   }\n      }\n    }\n\n    // elimination\n    for (int k = (LinearEquation\
    \ ? 0 : rank + 1); k < H; k++) {\n      if (k == rank) continue;\n      if (a[k][j].get()\
    \ != 0) {\n        mint coeff = a[k][j] / a[rank][j];\n        __m256i COEFF =\
    \ _mm256_set1_epi32(coeff.a);\n        for (int i = j / 8 * 8; i < W; i += 8)\
    \ {\n          __m256i R = _mm256_load_si256((__m256i *)(a[rank] + i));\n    \
    \      __m256i K = _mm256_load_si256((__m256i *)(a[k] + i));\n          __m256i\
    \ RmulC = montgomery_mul_256(R, COEFF, r, m1);\n          __m256i KmnsR = montgomery_sub_256(K,\
    \ RmulC, m2, m0);\n          _mm256_store_si256((__m256i *)(a[k] + i), KmnsR);\n\
    \        }\n      }\n    }\n    rank++;\n  }\n  return {rank, det};\n}\n\n// calculate\
    \ determinant\ntemplate <typename mint>\nmint determinant(const vector<vector<mint>>\
    \ &mat) {\n  return GaussianElimination(mat).second;\n}\n\n// return V<V<mint>>\n\
    // 0 column ... one of solutions\n// 1 ~ (W - rank) column ... bases\n// if not\
    \ exist, return empty vector\ntemplate <typename mint>\nvector<vector<mint>> LinearEquation(vector<vector<mint>>\
    \ A, vector<mint> B) {\n  int H = A.size(), W = A[0].size();\n  for (int i = 0;\
    \ i < H; i++) A[i].push_back(B[i]);\n\n  auto p = GaussianElimination(A, true);\n\
    \n  mint(&a)[MAT_SIZE][MAT_SIZE] = *reinterpret_cast<mint(*)[MAT_SIZE][MAT_SIZE]>(a_buf_);\n\
    \  int rank = p.first;\n\n  // check if solutions exist\n  for (int i = rank;\
    \ i < H; ++i)\n    if (a[i][W] != 0) return vector<vector<mint>>{};\n\n  vector<vector<mint>>\
    \ res(1, vector<mint>(W));\n  vector<int> pivot(W, -1);\n  for (int i = 0, j =\
    \ 0; i < rank; ++i) {\n    while (a[i][j] == 0) ++j;\n    res[0][j] = a[i][W],\
    \ pivot[j] = i;\n  }\n  for (int j = 0; j < W; ++j) {\n    if (pivot[j] == -1)\
    \ {\n      vector<mint> x(W);\n      x[j] = 1;\n      for (int k = 0; k < j; ++k)\n\
    \        if (pivot[k] != -1) x[k] = -a[pivot[k]][j];\n      res.push_back(x);\n\
    \    }\n  }\n  return res;\n}\n\n}  // namespace Gauss\n\nusing Gauss::determinant;\n\
    using Gauss::LinearEquation;\n"
  dependsOn:
  - modint/simd-montgomery.hpp
  isVerificationFile: false
  path: modulo/gauss-elimination-fast.hpp
  requiredBy: []
  timestamp: '2022-08-22 19:46:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - verify/verify-yosupo-math/yosupo-linear-equation.test.cpp
  - verify/verify-yosupo-math/yosupo-determinant.test.cpp
  - verify/verify-yosupo-math/yosupo-sparse-determinant.test.cpp
  - verify/verify-unit-test/gauss-elimination.test.cpp
documentation_of: modulo/gauss-elimination-fast.hpp
layout: document
redirect_from:
- /library/modulo/gauss-elimination-fast.hpp
- /library/modulo/gauss-elimination-fast.hpp.html
title: modulo/gauss-elimination-fast.hpp
---
