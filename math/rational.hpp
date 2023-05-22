#pragma once

#include <cassert>
#include <numeric>
#include <vector>
using namespace std;

#include "../internal/internal-type-traits.hpp"
#include "../math-fast/gcd.hpp"

// T : 値, U : 比較用
template <typename T, typename U>
struct RationalBase {
  using R = RationalBase;
  using Key = T;
  T x, y;
  RationalBase() : x(0), y(1) {}
  template <typename T1>
  RationalBase(const T1& _x) : RationalBase<T, U>(_x, T1{1}) {}
  template <typename T1, typename T2>
  RationalBase(const T1& _x, const T2& _y) : x(_x), y(_y) {
    assert(y != 0);
    if (y == -1) x = -x, y = -y;
    if (y != 1) {
      T g;
      if constexpr (internal::is_broadly_integral_v<T>) {
        if constexpr (sizeof(T) == 16) {
          g = binary_gcd128(x, y);
        } else {
          g = binary_gcd(x, y);
        }
      } else {
        g = gcd(x, y);
      }
      if (g != 0) x /= g, y /= g;
      if (y < 0) x = -x, y = -y;
    }
  }
  // y = 0 の代入も認める
  static R raw(T _x, T _y) {
    R r;
    r.x = _x, r.y = _y;
    return r;
  }
  friend R operator+(const R& l, const R& r) {
    if (l.y == r.y) return R{l.x + r.x, l.y};
    return R{l.x * r.y + l.y * r.x, l.y * r.y};
  }
  friend R operator-(const R& l, const R& r) {
    if (l.y == r.y) return R{l.x - r.x, l.y};
    return R{l.x * r.y - l.y * r.x, l.y * r.y};
  }
  friend R operator*(const R& l, const R& r) { return R{l.x * r.x, l.y * r.y}; }
  friend R operator/(const R& l, const R& r) { return R{l.x * r.y, l.y * r.x}; }
  R& operator+=(const R& r) { return (*this) = (*this) + r; }
  R& operator-=(const R& r) { return (*this) = (*this) - r; }
  R& operator*=(const R& r) { return (*this) = (*this) * r; }
  R& operator/=(const R& r) { return (*this) = (*this) / r; }
  R operator-() const { return raw(-x, y); }
  R inverse() const {
    assert(x != 0);
    R r = raw(y, x);
    if (r.y < 0) r.x = -r.x, r.y = -r.y;
    return r;
  }
  R pow(long long p) const {
    R res{1}, base{*this};
    while (p) {
      if (p & 1) res *= base;
      base *= base;
      p >>= 1;
    }
    return res;
  }
  friend bool operator==(const R& l, const R& r) {
    return l.x == r.x && l.y == r.y;
  };
  friend bool operator!=(const R& l, const R& r) {
    return l.x != r.x || l.y != r.y;
  };
  friend bool operator<(const R& l, const R& r) {
    return U{l.x} * r.y < U{l.y} * r.x;
  };
  friend bool operator<=(const R& l, const R& r) { return l < r || l == r; }
  friend bool operator>(const R& l, const R& r) {
    return U{l.x} * r.y > U{l.y} * r.x;
  };
  friend bool operator>=(const R& l, const R& r) { return l > r || l == r; }
  friend ostream& operator<<(ostream& os, const R& r) {
    os << r.x;
    if (r.x != 0 && r.y != 1) os << "/" << r.y;
    return os;
  }

  T to_mint(T mod) const {
    assert(mod != 0);
    T a = y, b = mod, u = 1, v = 0, t;
    while (b > 0) {
      t = a / b;
      swap(a -= t * b, b);
      swap(u -= t * v, v);
    }
    return U((u % mod + mod) % mod) * x % mod;
  }
};

using Rational = RationalBase<long long, __int128_t>;

template <typename R = Rational>
struct Binomial {
  vector<R> fc;
  Binomial(int = 0) { fc.emplace_back(1); }
  void extend() {
    int n = fc.size();
    R nxt = fc.back() * n;
    fc.push_back(nxt);
  }
  R fac(int n) {
    if (n < 0) return 0;
    while ((int)fc.size() <= n) extend();
    return fc[n];
  }
  R finv(int n) {
    if (n < 0) return 0;
    return fac(n).inverse();
  }
  R inv(int n) {
    if (n < 0) return -inv(-n);
    return R{1, max(n, 1)};
  }
  R C(int n, int r) {
    if (n < 0 or r < 0 or n < r) return R{0};
    return fac(n) * finv(n - r) * finv(r);
  }
  R operator()(int n, int r) { return C(n, r); }
  template <typename I>
  R multinomial(const vector<I>& r) {
    static_assert(is_integral<I>::value == true);
    int n = 0;
    for (auto& x : r) {
      if (x < 0) return R{0};
      n += x;
    }
    R res = fac(n);
    for (auto& x : r) res *= finv(x);
    return res;
  }

  template <typename I>
  R operator()(const vector<I>& r) {
    return multinomial(r);
  }
};
