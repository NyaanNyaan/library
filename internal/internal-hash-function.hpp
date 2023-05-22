#pragma once

#include <cassert>
using namespace std;

#include "internal-seed.hpp"
#include "internal-type-traits.hpp"

namespace internal {
// 整数, 整数列を 64 bit unsigned int へ移す

using u64 = unsigned long long;
using u128 = __uint128_t;

ENABLE_HAS_TYPE(first_type);
ENABLE_HAS_TYPE(second_type);
ENABLE_HAS_TYPE(iterator);

template <typename T>
u64 hash_function(const T& x) {
  static u64 r = seed();
  constexpr u64 z1 = 11995408973635179863ULL;
  if constexpr (is_broadly_integral_v<T>) {
    // Integral
    return (u64(x) ^ r) * z1;
  } else if constexpr (has_first_type_v<T> && has_second_type_v<T>) {
    // pair
    constexpr u64 z2 = 10150724397891781847ULL;
    return hash_function(x.first) + hash_function(x.second) * z2;
  } else if constexpr (has_iterator_v<T>) {
    // Container
    constexpr u64 mod = (1LL << 61) - 1;
    constexpr u64 base = 950699498548472943ULL;
    u64 m = 0;
    for (auto& z : x) {
      u64 w;
      if constexpr (is_broadly_integral_v<T>) {
        w = u64(z) ^ r;
      } else {
        w = hash_function(z);
      }
      u128 y = u128(m) * base + (w & mod);
      m = (y & mod) + (y >> 61);
      if (m >= mod) m -= mod;
    }
    m ^= m << 24, m ^= m >> 31, m ^= m << 35;
    return m;
  } else {
    static_assert([]() { return false; }());
  }
}

template <typename Key>
struct HashObject {
  size_t operator()(const Key& x) const { return hash_function(x); }
};

}  // namespace internal

/*
@brief ハッシュ関数
*/