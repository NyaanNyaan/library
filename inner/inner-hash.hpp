#pragma once

namespace inner {
using u64 = unsigned long long;
using u128 = __uint128_t;

template <int BASE_NUM>
struct Hash : array<u64, BASE_NUM> {
  using array<u64, BASE_NUM>::operator[];
  static constexpr int n = BASE_NUM;

  Hash() : array<u64, BASE_NUM>() {}

  static constexpr u64 md = (1ull << 61) - 1;

  static u64 cast(const int64_t &a) { return a < 0 ? a + md : a; }

  static inline constexpr u64 modmul(const u64 &a, const u64 &b) {
    u128 ret = u128(a) * b;
    ret = (ret & md) + (ret >> 61);
    return ret >= md ? ret - md : ret;
  }
  static inline constexpr u64 modfma(const u64 &a, const u64 &b, const u64 &c) {
    u128 ret = u128(a) * b + c;
    ret = (ret & md) + (ret >> 61);
    return ret >= md ? ret - md : ret;
  }
  constexpr static Hash set(u64 a) {
    Hash res;
    for (int i = 0; i < n; i++) res[i] = a;
    return res;
  }
  Hash &operator+=(const Hash &r) {
    for (int i = 0; i < n; i++)
      if (((*this)[i] += r[i]) >= md) (*this)[i] -= md;
    return *this;
  }
  Hash &operator+=(const u64 &r) {
    for (int i = 0; i < n; i++)
      if (((*this)[i] += r) >= md) (*this)[i] -= md;
    return *this;
  }
  Hash &operator-=(const Hash &r) {
    for (int i = 0; i < n; i++)
      if (((*this)[i] += md - r[i]) >= md) (*this)[i] -= md;
    return *this;
  }
  Hash &operator-=(const u64 &r) {
    for (int i = 0; i < n; i++)
      if (((*this)[i] += md - r) >= md) (*this)[i] -= md;
    return *this;
  }
  inline Hash &operator*=(const Hash &r) {
    for (int i = 0; i < n; i++) (*this)[i] = modmul((*this)[i], r[i]);
    return *this;
  }
  Hash operator+(const Hash &r) { return Hash(*this) += r; }
  Hash operator+(const u64 &r) { return Hash(*this) += r; }
  Hash operator-(const Hash &r) { return Hash(*this) -= r; }
  Hash operator-(const u64 &r) { return Hash(*this) -= r; }
  inline Hash operator*(const Hash &r) { return Hash(*this) *= r; }
  Hash operator-() const {
    Hash res;
    for (int i = 0; i < n; i++) res[i] = (*this)[i] == 0 ? 0 : md - (*this)[i];
    return res;
  }
  friend Hash pfma(const Hash &a, const Hash &b, const Hash &c) {
    Hash res;
    for (int i = 0; i < n; i++) res[i] = modfma(a[i], b[i], c[i]);
    return res;
  }
  friend Hash pfma(const Hash &a, const Hash &b, const u64 &c) {
    Hash res;
    for (int i = 0; i < n; i++) res[i] = modfma(a[i], b[i], c);
    return res;
  }

  static Hash get_basis() {
    constexpr u64 ds[] = {2, 3, 5, 7, 11, 13, 31, 41, 61, 151, 331, 1321};
    static auto rand_time =
        chrono::duration_cast<chrono::nanoseconds>(
            chrono::high_resolution_clock::now().time_since_epoch())
            .count();
    static mt19937_64 rng(rand_time);

    auto modpow = [&](u64 a, u64 b) {
      u64 r = 1;
      for (a %= md; b; a = modmul(a, a), b >>= 1) r = modmul(r, a);
      return r;
    };
    auto isPrimitive = [&](u64 x) {
      for (auto &d : ds)
        if (modpow(x, (md - 1) / d) <= 1) return false;
      return true;
    };

    Hash h;
    for (int i = 0; i < n; i++) {
      while (isPrimitive(h[i] = rng() % (md - 1) + 1) == false)
        ;
    }
    return h;
  }
};

}  // namespace inner
