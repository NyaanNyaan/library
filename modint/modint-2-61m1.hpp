#pragma once

#include <cassert>
#include <ostream>
using namespace std;

struct modint_2_61m1 {
  using M = modint_2_61m1;
  using u64 = unsigned long long;
  using u128 = __uint128_t;

  static constexpr u64 mod = (1uLL << 61) - 1;
  u64 x;

  static constexpr u64 modulo(u128 y) {
    u64 val = (y >> 61) + (y & mod);
    return val >= mod ? val - mod : val;
  }

  modint_2_61m1() : x(0) {}
  modint_2_61m1(long long _x) {
    long long y = _x % (long long)mod;
    if (y < 0) y += mod;
    x = y;
  }

  static M raw(u64 y) {
    M res;
    res.x = y;
    return res;
  }
  u64 get() const { return x; }
  static u64 get_mod() { return mod; }

  friend M operator+(const M& l, const M& r) {
    u64 y = l.x + r.x;
    if (y >= mod) y -= mod;
    return raw(y);
  }
  friend M operator-(const M& l, const M& r) {
    u64 y = l.x - r.x;
    if (y >= mod) y += mod;
    return raw(y);
  }
  friend M operator*(const M& l, const M& r) {
    return raw(modulo(u128(l.x) * r.x));
  }
  friend M operator/(const M& l, const M& r) { return l * r.inverse(); }

  M& operator+=(const M& r) { return *this = *this + r; }
  M& operator-=(const M& r) { return *this = *this - r; }
  M& operator*=(const M& r) { return *this = *this * r; }
  M& operator/=(const M& r) { return *this = *this / r; }
  M operator-() const { return raw(x ? mod - x : u64{0}); }
  M operator+() const { return *this; }

  M pow(u64 e) const {
    M res{1}, a{*this};
    while (e) {
      if (e & 1) res = res * a;
      a = a * a;
      e >>= 1;
    }
    return res;
  }
  M inverse() const {
    assert(x != 0);
    return this->pow(mod - 2);
  }

  friend bool operator==(const M& l, const M& r) { return l.x == r.x; }
  friend bool operator!=(const M& l, const M& r) { return l.x != r.x; }
  friend ostream& operator<<(ostream& os, const M& r) { return os << r.x; }
};
