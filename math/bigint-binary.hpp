
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#include "../ntt/arbitrary-ntt.hpp"

namespace BinaryBigIntImpl {

using u32 = unsigned int;
using u64 = unsigned long long;
using i64 = long long;

// 0 は neg=false, dat={} として扱う
struct BinaryBigInt {
  using M = BinaryBigInt;
  bool neg;
  vector<u32> dat;

  BinaryBigInt() : neg(false), dat() {}

  BinaryBigInt(bool _neg, const vector<u32>& _dat) : neg(_neg), dat(_dat) {}

  BinaryBigInt(const string& S, int base) : neg(false) {
    assert(base == 16);
    int ie = -1;
    if (S[0] == '-') neg = true, ie++;
    for (int r = S.size() - 1; r > ie; r -= 8) {
      int l = max(r - 8, ie);
      u32 x = 0;
      for (int i = l + 1; i <= r; i++) {
        int c = 0;
        if ('0' <= S[i] and S[i] <= '9') {
          c = S[i] - '0';
        } else if ('A' <= S[i] and S[i] <= 'F') {
          c = S[i] - 'A' + 10;
        } else {
          c = S[i] - 'a' + 10;
        }
        x = c + (x << 4);
      }
      dat.push_back(x);
    }
    _shrink();
  }

  friend M operator+(const M& lhs, const M& rhs) {
    if (lhs.neg == rhs.neg) return {lhs.neg, _add(lhs.dat, rhs.dat)};
    if (_leq(lhs.dat, rhs.dat)) {
      // |l| <= |r|
      auto c = _sub(rhs.dat, lhs.dat);
      bool n = _is_zero(c) ? false : rhs.neg;
      return {n, c};
    }
    auto c = _sub(lhs.dat, rhs.dat);
    bool n = _is_zero(c) ? false : lhs.neg;
    return {n, c};
  }
  friend M operator-(const M& lhs, const M& rhs) { return lhs + (-rhs); }
  friend M operator*(const M& lhs, const M& rhs) {
    auto c = _mul(lhs.dat, rhs.dat);
    bool n = _is_zero(c) ? false : (lhs.neg ^ rhs.neg);
    return {n, c};
  }

  M& operator+=(const M& rhs) { return (*this) = (*this) + rhs; }
  M& operator-=(const M& rhs) { return (*this) = (*this) - rhs; }
  M& operator*=(const M& rhs) { return (*this) = (*this) * rhs; }

  M operator-() const {
    if (is_zero()) return *this;
    return {!neg, dat};
  }
  M operator+() const { return *this; }
  friend M abs(const M& m) { return {false, m.dat}; }
  bool is_zero() const { return _is_zero(dat); }

  friend bool operator==(const M& lhs, const M& rhs) {
    return lhs.neg == rhs.neg && lhs.dat == rhs.dat;
  }
  friend bool operator!=(const M& lhs, const M& rhs) {
    return lhs.neg != rhs.neg || lhs.dat != rhs.dat;
  }
  friend bool operator<(const M& lhs, const M& rhs) {
    return lhs == rhs ? false : _neq_lt(lhs, rhs);
  }
  friend bool operator<=(const M& lhs, const M& rhs) {
    return lhs == rhs ? true : _neq_lt(lhs, rhs);
  }
  friend bool operator>(const M& lhs, const M& rhs) {
    return lhs == rhs ? false : _neq_lt(rhs, lhs);
  }
  friend bool operator>=(const M& lhs, const M& rhs) {
    return lhs == rhs ? true : _neq_lt(rhs, lhs);
  }

  // 0 の時 0 を返す
  int ctz() const {
    if (dat.empty()) return 0;
    int i = 0;
    while (dat[i] == 0) i++;
    return 32 * i + __builtin_ctzll(dat[i]);
  }
  M& operator<<=(int s) {
    assert(s >= 0);
    if (dat.empty()) return *this;
    int q = s / 32, r = s % 32;
    dat.push_back(0);
    if (r) {
      for (int i = (int)dat.size() - 1; i >= 1; i--) {
        dat[i] = (dat[i] << r) | (dat[i - 1] >> (32 - r));
      }
      dat[0] <<= r;
    }
    dat.insert(begin(dat), q, 0);
    return *this;
  }
  M& operator>>=(int s) {
    assert(s >= 0);
    int q = s / 32, r = s % 32;
    if ((int)dat.size() <= q) {
      dat.clear();
      return *this;
    }
    dat.erase(begin(dat), begin(dat) + q);
    if (r) {
      for (int i = 0; i + 1 < (int)dat.size(); i++) {
        dat[i] = (dat[i] >> r) | (dat[i + 1] << (32 - r));
      }
      dat.back() >>= r;
    }
    _shrink();
    return *this;
  }

  friend M gcd(M a, M b) {
    a.neg = b.neg = false;
    if(a.dat.empty()) return b;
    if(b.dat.empty()) return a;
    int at = a.ctz(), bt = b.ctz();
    a >>= at, b >>= bt;
    if (a < b) swap(a, b);
    while (!b.dat.empty()) {
      a -= b;
      a >>= a.ctz();
      if (a < b) swap(a, b);
    }
    return a <<= min(at, bt);
  }

  string to_hex() const {
    if (dat.empty()) return "0";
    string res;
    for (int i = 0; i < (int)dat.size(); i++) {
      u32 x = dat[i];
      for (int j = 0; j < 8; j++) {
        res.push_back("0123456789ABCDEF"[x & 15]);
        x >>= 4;
      }
    }
    while (res.back() == '0') res.pop_back();
    reverse(begin(res), end(res));
    if (neg) res.insert(begin(res), '-');
    return res;
  }

 private:
  // size
  int _size() const { return dat.size(); }
  // a == b
  static bool _eq(const vector<u32>& a, const vector<u32>& b) { return a == b; }
  // a < b
  static bool _lt(const vector<u32>& a, const vector<u32>& b) {
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i = a.size() - 1; i >= 0; i--) {
      if (a[i] != b[i]) return a[i] < b[i];
    }
    return false;
  }
  // a <= b
  static bool _leq(const vector<u32>& a, const vector<u32>& b) {
    return _eq(a, b) || _lt(a, b);
  }
  // a < b (s.t. a != b)
  static bool _neq_lt(const M& lhs, const M& rhs) {
    assert(lhs != rhs);
    if (lhs.neg != rhs.neg) return lhs.neg;
    bool f = _lt(lhs.dat, rhs.dat);
    if (f) return !lhs.neg;
    return lhs.neg;
  }
  // a == 0
  static bool _is_zero(const vector<u32>& a) { return a.empty(); }
  // 末尾 0 を削除
  static void _shrink(vector<u32>& a) {
    while (a.size() && a.back() == 0) a.pop_back();
  }
  // 末尾 0 を削除
  void _shrink() {
    while (_size() && dat.back() == 0) dat.pop_back();
  }
  // a + b
  static vector<u32> _add(const vector<u32>& a, const vector<u32>& b) {
    vector<u32> c(max(a.size(), b.size()) + 1);
    int carry = 0;
    for (int i = 0; i < (int)c.size(); i++) {
      u64 s = carry;
      carry = 0;
      if (i < (int)a.size()) s += a[i];
      if (i < (int)b.size()) s += b[i];
      if (s >= (1uLL << 32)) s -= 1uLL << 32, carry = 1;
      c[i] = s;
    }
    _shrink(c);
    return c;
  }
  // a - b
  static vector<u32> _sub(const vector<u32>& a, const vector<u32>& b) {
    assert(_leq(b, a));
    vector<u32> c{a};
    i64 borrow = 0;
    for (int i = 0; i < (int)a.size(); i++) {
      if (i < (int)b.size()) borrow += b[i];
      i64 x = c[i] - borrow;
      borrow = 0;
      if (x < 0) x += 1uLL << 32, borrow = 1;
      c[i] = x;
    }
    assert(borrow == 0);
    _shrink(c);
    return c;
  }
  // a * b (fft)
  static vector<u32> _mul(const vector<u32>& a, const vector<u32>& b) {
    if (a.empty() || b.empty()) return {};
    vector<int> a2(a.size() * 2), b2(b.size() * 2);
    for (int i = 0; i < (int)a.size(); i++) {
      a2[i * 2 + 0] = a[i] & 65535;
      a2[i * 2 + 1] = a[i] >> 16;
    }
    for (int i = 0; i < (int)b.size(); i++) {
      b2[i * 2 + 0] = b[i] & 65535;
      b2[i * 2 + 1] = b[i] >> 16;
    }
    auto m = ArbitraryNTT::multiply_u128(a2, b2);
    vector<u32> c;
    c.reserve(a.size() + b.size() + 3);
    __uint128_t x = 0;
    for (int i = 0;; i += 2) {
      if (i >= (int)m.size() && x == 0) break;
      if (i + 0 < (int)m.size()) x += m[i + 0];
      if (i + 1 < (int)m.size()) x += m[i + 1] << 16;
      c.push_back(x & ((1uLL << 32) - 1));
      x >>= 32;
    }
    _shrink(c);
    return c;
  }
};

}  // namespace BinaryBigIntImpl

using BinaryBigIntImpl::BinaryBigInt;
