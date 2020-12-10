---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: '#line 2 "misc/simd.hpp"


    #include <immintrin.h>


    using m256 = __m256i;

    #define ALIGN __attribute__((aligned(64)))


    #define SET(x) _mm256_set1_epi32(x)

    #define SET64(x) _mm256_set1_epi64x(x)

    #define LOAD(p) _mm256_loadu_si256((__m256i*)(p))

    #define STORE(p, A) _mm256_storeu_si256((__m256i*)(p), A)


    #define AND(a, b) _mm256_and_si256(a, b)

    #define ADD(a, b) _mm256_add_epi32(a, b)

    #define SUB(a, b) _mm256_sub_epi32(a, b)

    #define CMP(a, b) _mm256_cmpgt_epi32(a, b)


    #define GETMOD(a, MOD) SUB(a, AND(CMP(a, MOD), MOD))

    #define MADD(a, b, MOD) GETMOD(ADD(a, b), MOD)

    #define MSUB(a, b, MOD) GETMOD(SUB(ADD(a, MOD), b), MOD)


    #define SETLO(a) _mm256_shuffle_epi32(a, 0xA0)

    #define SETHI(a) _mm256_shuffle_epi32(a, 0xF9)

    #define CAST64(a) AND(a, SET64(0xFFFFFFFF))

    #define ADD64(a, b) _mm256_add_epi64(a, b)

    '
  code: '#pragma once


    #include <immintrin.h>


    using m256 = __m256i;

    #define ALIGN __attribute__((aligned(64)))


    #define SET(x) _mm256_set1_epi32(x)

    #define SET64(x) _mm256_set1_epi64x(x)

    #define LOAD(p) _mm256_loadu_si256((__m256i*)(p))

    #define STORE(p, A) _mm256_storeu_si256((__m256i*)(p), A)


    #define AND(a, b) _mm256_and_si256(a, b)

    #define ADD(a, b) _mm256_add_epi32(a, b)

    #define SUB(a, b) _mm256_sub_epi32(a, b)

    #define CMP(a, b) _mm256_cmpgt_epi32(a, b)


    #define GETMOD(a, MOD) SUB(a, AND(CMP(a, MOD), MOD))

    #define MADD(a, b, MOD) GETMOD(ADD(a, b), MOD)

    #define MSUB(a, b, MOD) GETMOD(SUB(ADD(a, MOD), b), MOD)


    #define SETLO(a) _mm256_shuffle_epi32(a, 0xA0)

    #define SETHI(a) _mm256_shuffle_epi32(a, 0xF9)

    #define CAST64(a) AND(a, SET64(0xFFFFFFFF))

    #define ADD64(a, b) _mm256_add_epi64(a, b)

    '
  dependsOn: []
  isVerificationFile: false
  path: misc/simd.hpp
  requiredBy: []
  timestamp: '2020-12-10 19:54:55+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: misc/simd.hpp
layout: document
redirect_from:
- /library/misc/simd.hpp
- /library/misc/simd.hpp.html
title: misc/simd.hpp
---
