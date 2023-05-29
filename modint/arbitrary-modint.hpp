#pragma once

#include "barrett-reduction.hpp"

template <int id>
struct ArbitraryModIntBase {
  int x;

  ArbitraryModIntBase() : x(0) {}

  ArbitraryModIntBase(int64_t y) {
    int z = y % get_mod();
    if (z < 0) z += get_mod();
    x = z;
  }

  ArbitraryModIntBase &operator+=(const ArbitraryModIntBase &p) {
    if ((x += p.x) >= get_mod()) x -= get_mod();
    return *this;
  }

  ArbitraryModIntBase &operator-=(const ArbitraryModIntBase &p) {
    if ((x += get_mod() - p.x) >= get_mod()) x -= get_mod();
    return *this;
  }

  ArbitraryModIntBase &operator*=(const ArbitraryModIntBase &p) {
    x = rem((unsigned long long)x * p.x);
    return *this;
  }

  ArbitraryModIntBase &operator/=(const ArbitraryModIntBase &p) {
    *this *= p.inverse();
    return *this;
  }

  ArbitraryModIntBase operator-() const { return ArbitraryModIntBase(-x); }
  ArbitraryModIntBase operator+() const { return *this; }

  ArbitraryModIntBase operator+(const ArbitraryModIntBase &p) const {
    return ArbitraryModIntBase(*this) += p;
  }

  ArbitraryModIntBase operator-(const ArbitraryModIntBase &p) const {
    return ArbitraryModIntBase(*this) -= p;
  }

  ArbitraryModIntBase operator*(const ArbitraryModIntBase &p) const {
    return ArbitraryModIntBase(*this) *= p;
  }

  ArbitraryModIntBase operator/(const ArbitraryModIntBase &p) const {
    return ArbitraryModIntBase(*this) /= p;
  }

  bool operator==(const ArbitraryModIntBase &p) const { return x == p.x; }

  bool operator!=(const ArbitraryModIntBase &p) const { return x != p.x; }

  ArbitraryModIntBase inverse() const {
    int a = x, b = get_mod(), u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return ArbitraryModIntBase(u);
  }

  ArbitraryModIntBase pow(int64_t n) const {
    ArbitraryModIntBase ret(1), mul(x);
    while (n > 0) {
      if (n & 1) ret *= mul;
      mul *= mul;
      n >>= 1;
    }
    return ret;
  }

  friend ostream &operator<<(ostream &os, const ArbitraryModIntBase &p) {
    return os << p.x;
  }

  friend istream &operator>>(istream &is, ArbitraryModIntBase &a) {
    int64_t t;
    is >> t;
    a = ArbitraryModIntBase(t);
    return (is);
  }

  int get() const { return x; }

  inline unsigned int rem(unsigned long long p) { return barrett().rem(p); }

  static inline Barrett &barrett() {
    static Barrett b;
    return b;
  }

  static inline int &get_mod() {
    static int mod = 0;
    return mod;
  }

  static void set_mod(int md) {
    assert(0 < md && md <= (1LL << 30) - 1);
    get_mod() = md;
    barrett() = Barrett(md);
  }
};

using ArbitraryModInt = ArbitraryModIntBase<-1>;

/**
 * @brief modint (2^{30} 未満の任意 mod 用)
 */
