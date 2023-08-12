#pragma once

#include <immintrin.h>

#include <array>

using namespace std;

#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx2")

template <typename _mint>
struct alignas(32) vectorize_modint {
  using mint = _mint;
  using m256 = __m256i;
  using vmint = vectorize_modint;
  m256 x;
  inline static vmint R = mint::r;
  inline static vmint M0 = 0;
  inline static vmint M1 = mint::get_mod();
  inline static vmint M2 = mint::get_mod() * 2;
  inline static vmint N2 = mint::n2;
  vectorize_modint() = default;
  vectorize_modint(int a) : x(_mm256_set1_epi32(a)) {}
  vectorize_modint(const m256& _x) : x(_x) {}
  vectorize_modint(const array<int, 8>& a)
      : x(_mm256_loadu_si256((m256*)a.data())) {}
  vectorize_modint(int a0, int a1, int a2, int a3, int a4, int a5, int a6,
                   int a7)
      : x(_mm256_set_epi32(a7, a6, a5, a4, a3, a2, a1, a0)) {}
  int at(int i) const {
    /*
    alignas(32) array<int, 8> b;
    _mm256_store_si256((m256*)b.data(), x);
    return b[i];
    */
    return *(reinterpret_cast<const int*>(&x) + i);
  }
  void set(int i, int val) {
    /*
    alignas(32) array<int, 8> b;
    _mm256_store_si256((m256*)b.data(), x);
    b[i] = val;
    x = _mm256_load_si256((m256*)b.data());
    */
    *(reinterpret_cast<int*>(&x) + i) = val;
  }
  operator const __m256i&() const { return x; }
  friend ostream& operator<<(ostream& os, const vmint& m) {
    vmint a = mtoi(m);
    for (int i = 0; i < 8; i++) os << a.at(i) << (i == 7 ? "" : " ");
    return os;
  }
  static vmint reduce(const vmint& prod02, const vmint& prod13) {
    m256 unpalo = _mm256_unpacklo_epi32(prod02, prod13);
    m256 unpahi = _mm256_unpackhi_epi32(prod02, prod13);
    m256 prodlo = _mm256_unpacklo_epi64(unpalo, unpahi);
    m256 prodhi = _mm256_unpackhi_epi64(unpalo, unpahi);
    m256 hiplm1 = _mm256_add_epi32(prodhi, M1);
    m256 prodlohi = _mm256_shuffle_epi32(prodlo, 0xF5);
    m256 lmlr02 = _mm256_mul_epu32(prodlo, R);
    m256 lmlr13 = _mm256_mul_epu32(prodlohi, R);
    m256 prod02_ = _mm256_mul_epu32(lmlr02, M1);
    m256 prod13_ = _mm256_mul_epu32(lmlr13, M1);
    m256 unpalo_ = _mm256_unpacklo_epi32(prod02_, prod13_);
    m256 unpahi_ = _mm256_unpackhi_epi32(prod02_, prod13_);
    m256 prod = _mm256_unpackhi_epi64(unpalo_, unpahi_);
    return _mm256_sub_epi32(hiplm1, prod);
  }
  static vmint itom(const vmint& A) { return A * N2; }
  static vmint mtoi(const vmint& A) {
    m256 A13 = _mm256_shuffle_epi32(A, 0xF5);
    m256 lmlr02 = _mm256_mul_epu32(A, R);
    m256 lmlr13 = _mm256_mul_epu32(A13, R);
    m256 prod02_ = _mm256_mul_epu32(lmlr02, M1);
    m256 prod13_ = _mm256_mul_epu32(lmlr13, M1);
    m256 unpalo_ = _mm256_unpacklo_epi32(prod02_, prod13_);
    m256 unpahi_ = _mm256_unpackhi_epi32(prod02_, prod13_);
    m256 prod = _mm256_unpackhi_epi64(unpalo_, unpahi_);
    m256 cmp = _mm256_cmpgt_epi32(prod, M0);
    m256 dif = _mm256_and_si256(cmp, M1);
    return _mm256_sub_epi32(dif, prod);
  }
  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) friend vmint
  operator+(const vmint& A, const vmint& B) {
    m256 apb = _mm256_add_epi32(A, B);
    m256 ret = _mm256_sub_epi32(apb, M2);
    return _mm256_min_epu32(apb, ret);
  }
  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) friend vmint
  operator-(const vmint& A, const vmint& B) {
    m256 amb = _mm256_sub_epi32(A, B);
    m256 ret = _mm256_add_epi32(amb, M2);
    return _mm256_min_epu32(amb, ret);
  }
  __attribute__((target("avx2"), optimize("O3", "unroll-loops"))) friend vmint
  operator*(const vmint& A, const vmint& B) {
    m256 a13 = _mm256_shuffle_epi32(A, 0xF5);
    m256 b13 = _mm256_shuffle_epi32(B, 0xF5);
    m256 prod02 = _mm256_mul_epu32(A, B);
    m256 prod13 = _mm256_mul_epu32(a13, b13);
    return reduce(prod02, prod13);
  }
  vmint& operator+=(const vmint& A) { return (*this) = (*this) + A; }
  vmint& operator-=(const vmint& A) { return (*this) = (*this) - A; }
  vmint& operator*=(const vmint& A) { return (*this) = (*this) * A; }
};
