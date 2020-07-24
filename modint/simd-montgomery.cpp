#pragma once
#ifndef Nyaan_template
#include "../competitive-template.cpp"
#endif

constexpr int SZ = 1 << 19;
#include <immintrin.h>
using u32 = uint32_t;
using u64 = uint64_t;

__attribute__((target("sse4.2"))) __attribute__((always_inline)) __m128i
my_mullo_epu32(const __m128i &a, const __m128i &b) {
  return _mm_mullo_epi32(a, b);
}

__attribute__((target("sse4.2"))) __attribute__((always_inline)) __m128i
my_mulhi_epu32(const __m128i &a, const __m128i &b) {
  __m128i a13 = _mm_shuffle_epi32(a, 0xF5);
  __m128i b13 = _mm_shuffle_epi32(b, 0xF5);
  __m128i prod02 = _mm_mul_epu32(a, b);
  __m128i prod13 = _mm_mul_epu32(a13, b13);
  __m128i prod = _mm_unpackhi_epi64(_mm_unpacklo_epi32(prod02, prod13),
                                    _mm_unpackhi_epi32(prod02, prod13));
  return prod;
}

__attribute__((target("sse4.2"))) __m128i montgomery_mul(const __m128i &a,
                                                         const __m128i &b,
                                                         const __m128i &r,
                                                         const __m128i &m1) {
  return _mm_sub_epi32(
      _mm_add_epi32(my_mulhi_epu32(a, b), m1),
      my_mulhi_epu32(my_mullo_epu32(my_mullo_epu32(a, b), r), m1));
}

__attribute__((target("sse4.2"))) __m128i montgomery_add(const __m128i &a,
                                                         const __m128i &b,
                                                         const __m128i &m2,
                                                         const __m128i &m0) {
  __m128i ret = _mm_sub_epi32(_mm_add_epi32(a, b), m2);
  return _mm_add_epi32(_mm_and_si128(_mm_cmpgt_epi32(m0, ret), m2), ret);
}

__attribute__((target("sse4.2"))) __m128i montgomery_sub(const __m128i &a,
                                                         const __m128i &b,
                                                         const __m128i &m2,
                                                         const __m128i &m0) {
  __m128i ret = _mm_sub_epi32(a, b);
  return _mm_add_epi32(_mm_and_si128(_mm_cmpgt_epi32(m0, ret), m2), ret);
}
