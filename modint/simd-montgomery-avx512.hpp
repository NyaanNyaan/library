#pragma once

#include <immintrin.h>
using namespace std;

using m128 = __m128i;
using m256 = __m256i;
using m512 = __m512i;

__attribute__((target("avx2"))) inline m128 mul_128(const m128 &A,
                                                    const m128 &B) {
  m128 a13 = _mm_shuffle_epi32(A, 0xF5);
  m128 b13 = _mm_shuffle_epi32(B, 0xF5);
  m128 prod02 = _mm_mul_epu32(A, B);
  m128 prod13 = _mm_mul_epu32(a13, b13);
  m128 modm2 = _mm_set1_epi32((119 << 23) - 1);
  m128 mod = _mm_set1_epi32((119 << 23) + 1);
  m128 x02 = _mm_mul_epu32(prod02, modm2);
  m128 x13 = _mm_mul_epu32(prod13, modm2);
  m128 y02 = _mm_mul_epu32(x02, mod);
  m128 y13 = _mm_mul_epu32(x13, mod);
  m128 z02 = _mm_add_epi64(y02, prod02);
  m128 z13 = _mm_add_epi64(y13, prod13);
  m128 z02_2 = _mm_shuffle_epi32(z02, 0xB1);
  return _mm_or_si128(z02_2, z13);
}

__attribute__((target("avx2"))) inline m128 add_128(const m128 &A,
                                                    const m128 &B,
                                                    const m128 &M2) {
  m128 ret = _mm_add_epi32(A, B);
  m128 ret_sub = _mm_sub_epi32(ret, M2);
  return _mm_min_epu32(ret, ret_sub);
}

__attribute__((target("avx2"))) inline m128 sub_128(const m128 &A,
                                                    const m128 &B,
                                                    const m128 &M2) {
  m128 ret = _mm_sub_epi32(A, B);
  m128 ret_add = _mm_add_epi32(ret, M2);
  return _mm_min_epu32(ret, ret_add);
}

__attribute__((target("avx2"))) inline m256 mul_256(const m256 &A,
                                                    const m256 &B) {
  m256 a13 = _mm256_shuffle_epi32(A, 0xF5);
  m256 b13 = _mm256_shuffle_epi32(B, 0xF5);
  m256 prod02 = _mm256_mul_epu32(A, B);
  m256 prod13 = _mm256_mul_epu32(a13, b13);
  m256 modm2 = _mm256_set1_epi32((119 << 23) - 1);
  m256 mod = _mm256_set1_epi32((119 << 23) + 1);
  m256 x02 = _mm256_mul_epu32(prod02, modm2);
  m256 x13 = _mm256_mul_epu32(prod13, modm2);
  m256 y02 = _mm256_mul_epu32(x02, mod);
  m256 y13 = _mm256_mul_epu32(x13, mod);
  m256 z02 = _mm256_add_epi64(y02, prod02);
  m256 z13 = _mm256_add_epi64(y13, prod13);
  m256 z02_2 = _mm256_shuffle_epi32(z02, 0xB1);
  return _mm256_or_si256(z02_2, z13);
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

__attribute__((target("avx512f"))) inline m512 mul_512(const m512 &A,
                                                       const m512 &B) {
  m512 a13 = _mm512_shuffle_epi32(A, _MM_PERM_ENUM(0xF5));
  m512 b13 = _mm512_shuffle_epi32(B, _MM_PERM_ENUM(0xF5));
  m512 prod02 = _mm512_mul_epu32(A, B);
  m512 prod13 = _mm512_mul_epu32(a13, b13);
  m512 modm2 = _mm512_set1_epi32((119 << 23) - 1);
  m512 mod = _mm512_set1_epi32((119 << 23) + 1);
  m512 x02 = _mm512_mul_epu32(prod02, modm2);
  m512 x13 = _mm512_mul_epu32(prod13, modm2);
  m512 y02 = _mm512_mul_epu32(x02, mod);
  m512 y13 = _mm512_mul_epu32(x13, mod);
  m512 z02 = _mm512_add_epi64(y02, prod02);
  m512 z13 = _mm512_add_epi64(y13, prod13);
  m512 z02_2 = _mm512_shuffle_epi32(z02, _MM_PERM_ENUM(0xB1));
  return _mm512_or_si512(z02_2, z13);
}

__attribute__((target("avx512f"))) inline m512 add_512(const m512 &A,
                                                       const m512 &B,
                                                       const m512 &M2) {
  m512 ret = _mm512_add_epi32(A, B);
  m512 ret_sub = _mm512_sub_epi32(ret, M2);
  return _mm512_min_epu32(ret, ret_sub);
}

__attribute__((target("avx512f"))) inline m512 sub_512(const m512 &A,
                                                       const m512 &B,
                                                       const m512 &M2) {
  m512 ret = _mm512_sub_epi32(A, B);
  m512 ret_add = _mm512_add_epi32(ret, M2);
  return _mm512_min_epu32(ret, ret_add);
}
