#pragma once

#include <cassert>
#include <ostream>
using namespace std;

// % より遅い(笑)
struct modint_2_32m2_30p1 {
  using M = modint_2_32m2_30p1;
  using u32 = unsigned int;
  using u64 = unsigned long long;

  static constexpr u32 mod = 1u - (1u << 30);
  static constexpr u32 X = -1u / 3;
  u32 x;

  static constexpr u32 modulo(u64 c) {
    u32 h = c >> 32, l = c & -1u;
    u32 y = (u64(h) * X) >> 32;
    u32 m = l >= mod ? l - mod : l;
    u32 r = m - (y << 2);
    u32 s = m < r ? r + mod : r;
    u32 z = h - y - (y << 1);
    u32 t = s - (z + mod - (z << 30));
    return s < t ? t + mod : t;
  }

  modint_2_32m2_30p1(uint32_t _x = 0) : x(_x) {}

  static M raw(u32 y) {
    M res;
    res.x = y;
    return res;
  }
  u32 get() const { return x; }
  static constexpr u32 get_mod() { return mod; }

  friend M operator+(const M& l, const M& r) {
    u32 y = l.x + r.x - mod;
    return raw(y > l.x ? y + mod : y);
  }
  friend M operator-(const M& l, const M& r) {
    u32 y = l.x - r.x;
    return raw(y > l.x ? y + mod : y);
  }
  friend M operator*(const M& l, const M& r) {
    return raw(modulo(u64(l.x) * r.x));
  }
  friend M operator/(const M& l, const M& r) { return l * r.inverse(); }

  M& operator+=(const M& r) { return *this = *this + r; }
  M& operator-=(const M& r) { return *this = *this - r; }
  M& operator*=(const M& r) { return *this = *this * r; }
  M& operator/=(const M& r) { return *this = *this / r; }
  M operator-() const { return raw(x ? mod - x : u32{0}); }
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
