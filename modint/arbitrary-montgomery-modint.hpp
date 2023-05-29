#pragma once

#include <iostream>
using namespace std;

template <typename Int, typename UInt, typename Long, typename ULong, int id>
struct ArbitraryLazyMontgomeryModIntBase {
  using mint = ArbitraryLazyMontgomeryModIntBase;

  inline static UInt mod;
  inline static UInt r;
  inline static UInt n2;
  static constexpr int bit_length = sizeof(UInt) * 8;

  static UInt get_r() {
    UInt ret = mod;
    while (mod * ret != 1) ret *= UInt(2) - mod * ret;
    return ret;
  }
  static void set_mod(UInt m) {
    assert(m < (UInt(1u) << (bit_length - 2)));
    assert((m & 1) == 1);
    mod = m, n2 = -ULong(m) % m, r = get_r();
  }
  UInt a;

  ArbitraryLazyMontgomeryModIntBase() : a(0) {}
  ArbitraryLazyMontgomeryModIntBase(const Long &b)
      : a(reduce(ULong(b % mod + mod) * n2)){};

  static UInt reduce(const ULong &b) {
    return (b + ULong(UInt(b) * UInt(-r)) * mod) >> bit_length;
  }

  mint &operator+=(const mint &b) {
    if (Int(a += b.a - 2 * mod) < 0) a += 2 * mod;
    return *this;
  }
  mint &operator-=(const mint &b) {
    if (Int(a -= b.a) < 0) a += 2 * mod;
    return *this;
  }
  mint &operator*=(const mint &b) {
    a = reduce(ULong(a) * b.a);
    return *this;
  }
  mint &operator/=(const mint &b) {
    *this *= b.inverse();
    return *this;
  }

  mint operator+(const mint &b) const { return mint(*this) += b; }
  mint operator-(const mint &b) const { return mint(*this) -= b; }
  mint operator*(const mint &b) const { return mint(*this) *= b; }
  mint operator/(const mint &b) const { return mint(*this) /= b; }

  bool operator==(const mint &b) const {
    return (a >= mod ? a - mod : a) == (b.a >= mod ? b.a - mod : b.a);
  }
  bool operator!=(const mint &b) const {
    return (a >= mod ? a - mod : a) != (b.a >= mod ? b.a - mod : b.a);
  }
  mint operator-() const { return mint(0) - mint(*this); }
  mint operator+() const { return mint(*this); }

  mint pow(ULong n) const {
    mint ret(1), mul(*this);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul, n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const mint &b) {
    return os << b.get();
  }

  friend istream &operator>>(istream &is, mint &b) {
    Long t;
    is >> t;
    b = ArbitraryLazyMontgomeryModIntBase(t);
    return (is);
  }

  mint inverse() const {
    Int x = get(), y = get_mod(), u = 1, v = 0;
    while (y > 0) {
      Int t = x / y;
      swap(x -= t * y, y);
      swap(u -= t * v, v);
    }
    return mint{u};
  }

  UInt get() const {
    UInt ret = reduce(a);
    return ret >= mod ? ret - mod : ret;
  }

  static UInt get_mod() { return mod; }
};

// id に適当な乱数を割り当てて使う
template <int id>
using ArbitraryLazyMontgomeryModInt =
    ArbitraryLazyMontgomeryModIntBase<int, unsigned int, long long,
                                      unsigned long long, id>;
template <int id>
using ArbitraryLazyMontgomeryModInt64bit =
    ArbitraryLazyMontgomeryModIntBase<long long, unsigned long long, __int128_t,
                                      __uint128_t, id>;
