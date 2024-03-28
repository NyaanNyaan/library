#pragma once

#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>
using namespace std;

#include "../internal/internal-type-traits.hpp"
#include "../ntt/arbitrary-ntt.hpp"

namespace MultiPrecisionIntegerImpl {
struct TENS {
  static constexpr int offset = 30;
  constexpr TENS() : _tend() {
    _tend[offset] = 1;
    for (int i = 1; i <= offset; i++) {
      _tend[offset + i] = _tend[offset + i - 1] * 10.0;
      _tend[offset - i] = 1.0 / _tend[offset + i];
    }
  }
  long double ten_ld(int n) const {
    assert(-offset <= n and n <= offset);
    return _tend[n + offset];
  }

 private:
  long double _tend[offset * 2 + 1];
};
}  // namespace MultiPrecisionIntegerImpl

// 0 は neg=false, dat={} として扱う
struct MultiPrecisionInteger {
  using M = MultiPrecisionInteger;
  inline constexpr static MultiPrecisionIntegerImpl::TENS tens = {};

  static constexpr int D = 1000000000;
  static constexpr int logD = 9;
  bool neg;
  vector<int> dat;

  MultiPrecisionInteger() : neg(false), dat() {}

  MultiPrecisionInteger(bool n, const vector<int>& d) : neg(n), dat(d) {}

  template <typename I,
            enable_if_t<internal::is_broadly_integral_v<I>>* = nullptr>
  MultiPrecisionInteger(I x) : neg(false) {
    if constexpr (internal::is_broadly_signed_v<I>) {
      if (x < 0) neg = true, x = -x;
    }
    while (x) dat.push_back(x % D), x /= D;
  }

  MultiPrecisionInteger(const string& S) : neg(false) {
    assert(!S.empty());
    if (S.size() == 1u && S[0] == '0') return;
    int l = 0;
    if (S[0] == '-') ++l, neg = true;
    for (int ie = S.size(); l < ie; ie -= logD) {
      int is = max(l, ie - logD);
      long long x = 0;
      for (int i = is; i < ie; i++) x = x * 10 + S[i] - '0';
      dat.push_back(x);
    }
    while(!dat.empty() and dat.back() == 0) dat.pop_back();
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
  friend pair<M, M> divmod(const M& lhs, const M& rhs) {
    auto dm = _divmod_newton(lhs.dat, rhs.dat);
    bool dn = _is_zero(dm.first) ? false : lhs.neg != rhs.neg;
    bool mn = _is_zero(dm.second) ? false : lhs.neg;
    return {M{dn, dm.first}, M{mn, dm.second}};
  }
  friend M operator/(const M& lhs, const M& rhs) {
    return divmod(lhs, rhs).first;
  }
  friend M operator%(const M& lhs, const M& rhs) {
    return divmod(lhs, rhs).second;
  }

  M& operator+=(const M& rhs) { return (*this) = (*this) + rhs; }
  M& operator-=(const M& rhs) { return (*this) = (*this) - rhs; }
  M& operator*=(const M& rhs) { return (*this) = (*this) * rhs; }
  M& operator/=(const M& rhs) { return (*this) = (*this) / rhs; }
  M& operator%=(const M& rhs) { return (*this) = (*this) % rhs; }

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
    if (lhs == rhs) return false;
    return _neq_lt(lhs, rhs);
  }
  friend bool operator<=(const M& lhs, const M& rhs) {
    if (lhs == rhs) return true;
    return _neq_lt(lhs, rhs);
  }
  friend bool operator>(const M& lhs, const M& rhs) {
    if (lhs == rhs) return false;
    return _neq_lt(rhs, lhs);
  }
  friend bool operator>=(const M& lhs, const M& rhs) {
    if (lhs == rhs) return true;
    return _neq_lt(rhs, lhs);
  }

  // a * 10^b (1 <= |a| < 10) の形で渡す
  // 相対誤差：10^{-16} ~ 10^{-19} 程度 (処理系依存)
  pair<long double, int> dfp() const {
    if (is_zero()) return {0, 0};
    int l = max<int>(0, _size() - 3);
    int b = logD * l;
    string prefix{};
    for (int i = _size() - 1; i >= l; i--) {
      prefix += _itos(dat[i], i != _size() - 1);
    }
    b += prefix.size() - 1;
    long double a = 0;
    for (auto& c : prefix) a = a * 10.0 + (c - '0');
    a *= tens.ten_ld(-((int)prefix.size()) + 1);
    a = clamp<long double>(a, 1.0, nextafterl(10.0, 1.0));
    if (neg) a = -a;
    return {a, b};
  }
  string to_string() const {
    if (is_zero()) return "0";
    string res;
    if (neg) res.push_back('-');
    for (int i = _size() - 1; i >= 0; i--) {
      res += _itos(dat[i], i != _size() - 1);
    }
    return res;
  }
  long double to_ld() const {
    auto [a, b] = dfp();
    if (-tens.offset <= b and b <= tens.offset) {
      return a * tens.ten_ld(b);
    }
    return a * powl(10, b);
  }
  long long to_ll() const {
    long long res = _to_ll(dat);
    return neg ? -res : res;
  }
  __int128_t to_i128() const {
    __int128_t res = _to_i128(dat);
    return neg ? -res : res;
  }

  friend istream& operator>>(istream& is, M& m) {
    string s;
    is >> s;
    m = M{s};
    return is;
  }

  friend ostream& operator<<(ostream& os, const M& m) {
    return os << m.to_string();
  }

  // 内部の関数をテスト
  static void _test_private_function(const M&, const M&);

 private:
  // size
  int _size() const { return dat.size(); }
  // a == b
  static bool _eq(const vector<int>& a, const vector<int>& b) { return a == b; }
  // a < b
  static bool _lt(const vector<int>& a, const vector<int>& b) {
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i = a.size() - 1; i >= 0; i--) {
      if (a[i] != b[i]) return a[i] < b[i];
    }
    return false;
  }
  // a <= b
  static bool _leq(const vector<int>& a, const vector<int>& b) {
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
  static bool _is_zero(const vector<int>& a) { return a.empty(); }
  // a == 1
  static bool _is_one(const vector<int>& a) {
    return (int)a.size() == 1 && a[0] == 1;
  }
  // 末尾 0 を削除
  static void _shrink(vector<int>& a) {
    while (a.size() && a.back() == 0) a.pop_back();
  }
  // 末尾 0 を削除
  void _shrink() {
    while (_size() && dat.back() == 0) dat.pop_back();
  }
  // a + b
  static vector<int> _add(const vector<int>& a, const vector<int>& b) {
    vector<int> c(max(a.size(), b.size()) + 1);
    for (int i = 0; i < (int)a.size(); i++) c[i] += a[i];
    for (int i = 0; i < (int)b.size(); i++) c[i] += b[i];
    for (int i = 0; i < (int)c.size() - 1; i++) {
      if (c[i] >= D) c[i] -= D, c[i + 1]++;
    }
    _shrink(c);
    return c;
  }
  // a - b
  static vector<int> _sub(const vector<int>& a, const vector<int>& b) {
    assert(_leq(b, a));
    vector<int> c{a};
    int borrow = 0;
    for (int i = 0; i < (int)a.size(); i++) {
      if (i < (int)b.size()) borrow += b[i];
      c[i] -= borrow;
      borrow = 0;
      if (c[i] < 0) c[i] += D, borrow = 1;
    }
    assert(borrow == 0);
    _shrink(c);
    return c;
  }
  // a * b (fft)
  static vector<int> _mul_fft(const vector<int>& a, const vector<int>& b) {
    if (a.empty() || b.empty()) return {};
    auto m = ArbitraryNTT::multiply_u128(a, b);
    vector<int> c;
    c.reserve(m.size() + 3);
    __uint128_t x = 0;
    for (int i = 0;; i++) {
      if (i >= (int)m.size() && x == 0) break;
      if (i < (int)m.size()) x += m[i];
      c.push_back(x % D);
      x /= D;
    }
    _shrink(c);
    return c;
  }
  // a * b (naive)
  static vector<int> _mul_naive(const vector<int>& a, const vector<int>& b) {
    if (a.empty() || b.empty()) return {};
    vector<long long> prod(a.size() + b.size() - 1 + 1);
    for (int i = 0; i < (int)a.size(); i++) {
      for (int j = 0; j < (int)b.size(); j++) {
        long long p = 1LL * a[i] * b[j];
        prod[i + j] += p;
        if (prod[i + j] >= (4LL * D * D)) {
          prod[i + j] -= 4LL * D * D;
          prod[i + j + 1] += 4LL * D;
        }
      }
    }
    vector<int> c(prod.size() + 1);
    long long x = 0;
    int i = 0;
    for (; i < (int)prod.size(); i++) x += prod[i], c[i] = x % D, x /= D;
    while (x) c[i] = x % D, x /= D, i++;
    _shrink(c);
    return c;
  }
  // a * b
  static vector<int> _mul(const vector<int>& a, const vector<int>& b) {
    if (_is_zero(a) || _is_zero(b)) return {};
    if (_is_one(a)) return b;
    if (_is_one(b)) return a;
    if (min<int>(a.size(), b.size()) <= 128) {
      return a.size() < b.size() ? _mul_naive(b, a) : _mul_naive(a, b);
    }
    return _mul_fft(a, b);
  }
  // 0 <= A < 1e18, 1 <= B < 1e9
  static pair<vector<int>, vector<int>> _divmod_li(const vector<int>& a,
                                                   const vector<int>& b) {
    assert(0 <= (int)a.size() && (int)a.size() <= 2);
    assert((int)b.size() == 1);
    long long va = _to_ll(a);
    int vb = b[0];
    return {_integer_to_vec(va / vb), _integer_to_vec(va % vb)};
  }
  // 0 <= A < 1e18, 1 <= B < 1e18
  static pair<vector<int>, vector<int>> _divmod_ll(const vector<int>& a,
                                                   const vector<int>& b) {
    assert(0 <= (int)a.size() && (int)a.size() <= 2);
    assert(1 <= (int)b.size() && (int)b.size() <= 2);
    long long va = _to_ll(a), vb = _to_ll(b);
    return {_integer_to_vec(va / vb), _integer_to_vec(va % vb)};
  }
  // 1 <= B < 1e9
  static pair<vector<int>, vector<int>> _divmod_1e9(const vector<int>& a,
                                                    const vector<int>& b) {
    assert((int)b.size() == 1);
    if (b[0] == 1) return {a, {}};
    if ((int)a.size() <= 2) return _divmod_li(a, b);
    vector<int> quo(a.size());
    long long d = 0;
    int b0 = b[0];
    for (int i = a.size() - 1; i >= 0; i--) {
      d = d * D + a[i];
      assert(d < 1LL * D * b0);
      int q = d / b0, r = d % b0;
      quo[i] = q, d = r;
    }
    _shrink(quo);
    return {quo, d ? vector<int>{int(d)} : vector<int>{}};
  }
  // 0 <= A, 1 <= B
  static pair<vector<int>, vector<int>> _divmod_naive(const vector<int>& a,
                                                      const vector<int>& b) {
    if (_is_zero(b)) {
      cerr << "Divide by Zero Exception" << endl;
      exit(1);
    }
    assert(1 <= (int)b.size());
    if ((int)b.size() == 1) return _divmod_1e9(a, b);
    if (max<int>(a.size(), b.size()) <= 2) return _divmod_ll(a, b);
    if (_lt(a, b)) return {{}, a};
    // B >= 1e9, A >= B
    int norm = D / (b.back() + 1);
    vector<int> x = _mul(a, {norm});
    vector<int> y = _mul(b, {norm});
    int yb = y.back();
    vector<int> quo(x.size() - y.size() + 1);
    vector<int> rem(x.end() - y.size(), x.end());
    for (int i = quo.size() - 1; i >= 0; i--) {
      if (rem.size() < y.size()) {
        // do nothing
      } else if (rem.size() == y.size()) {
        if (_leq(y, rem)) {
          quo[i] = 1, rem = _sub(rem, y);
        }
      } else {
        assert(y.size() + 1 == rem.size());
        long long rb = 1LL * rem[rem.size() - 1] * D + rem[rem.size() - 2];
        int q = rb / yb;
        vector<int> yq = _mul(y, {q});
        // 真の商は q-2 以上 q+1 以下だが自信が無いので念のため while を回す
        while (_lt(rem, yq)) q--, yq = _sub(yq, y);
        rem = _sub(rem, yq);
        while (_leq(y, rem)) q++, rem = _sub(rem, y);
        quo[i] = q;
      }
      if (i) rem.insert(begin(rem), x[i - 1]);
    }
    _shrink(quo), _shrink(rem);
    auto [q2, r2] = _divmod_1e9(rem, {norm});
    assert(_is_zero(r2));
    return {quo, q2};
  }

  // 0 <= A, 1 <= B
  static pair<vector<int>, vector<int>> _divmod_dc(const vector<int>& a,
                                                   const vector<int>& b);

  // 1 / a を 絶対誤差 B^{-deg} で求める
  static vector<int> _calc_inv(const vector<int>& a, int deg) {
    assert(!a.empty() && D / 2 <= a.back() and a.back() < D);
    int k = deg, c = a.size();
    while (k > 64) k = (k + 1) / 2;
    vector<int> z(c + k + 1);
    z.back() = 1;
    z = _divmod_naive(z, a).first;
    while (k < deg) {
      vector<int> s = _mul(z, z);
      s.insert(begin(s), 0);
      int d = min(c, 2 * k + 1);
      vector<int> t{end(a) - d, end(a)}, u = _mul(s, t);
      u.erase(begin(u), begin(u) + d);
      vector<int> w(k + 1), w2 = _add(z, z);
      copy(begin(w2), end(w2), back_inserter(w));
      z = _sub(w, u);
      z.erase(begin(z));
      k *= 2;
    }
    z.erase(begin(z), begin(z) + k - deg);
    return z;
  }

  static pair<vector<int>, vector<int>> _divmod_newton(const vector<int>& a,
                                                       const vector<int>& b) {
    if (_is_zero(b)) {
      cerr << "Divide by Zero Exception" << endl;
      exit(1);
    }
    if ((int)b.size() <= 64) return _divmod_naive(a, b);
    if ((int)a.size() - (int)b.size() <= 64) return _divmod_naive(a, b);
    int norm = D / (b.back() + 1);
    vector<int> x = _mul(a, {norm});
    vector<int> y = _mul(b, {norm});
    int s = x.size(), t = y.size();
    int deg = s - t + 2;
    vector<int> z = _calc_inv(y, deg);
    vector<int> q = _mul(x, z);
    q.erase(begin(q), begin(q) + t + deg);
    vector<int> yq = _mul(y, {q});
    while (_lt(x, yq)) q = _sub(q, {1}), yq = _sub(yq, y);
    vector<int> r = _sub(x, yq);
    while (_leq(y, r)) q = _add(q, {1}), r = _sub(r, y);
    _shrink(q), _shrink(r);
    auto [q2, r2] = _divmod_1e9(r, {norm});
    assert(_is_zero(r2));
    return {q, q2};
  }

  // int -> string
  // 先頭かどうかに応じて zero padding するかを決める
  static string _itos(int x, bool zero_padding) {
    assert(0 <= x && x < D);
    string res;
    for (int i = 0; i < logD; i++) {
      res.push_back('0' + x % 10), x /= 10;
    }
    if (!zero_padding) {
      while (res.size() && res.back() == '0') res.pop_back();
      assert(!res.empty());
    }
    reverse(begin(res), end(res));
    return res;
  }

  // convert ll to vec
  template <typename I,
            enable_if_t<internal::is_broadly_integral_v<I>>* = nullptr>
  static vector<int> _integer_to_vec(I x) {
    if constexpr (internal::is_broadly_signed_v<I>) {
      assert(x >= 0);
    }
    vector<int> res;
    while (x) res.push_back(x % D), x /= D;
    return res;
  }

  static long long _to_ll(const vector<int>& a) {
    long long res = 0;
    for (int i = (int)a.size() - 1; i >= 0; i--) res = res * D + a[i];
    return res;
  }

  static __int128_t _to_i128(const vector<int>& a) {
    __int128_t res = 0;
    for (int i = (int)a.size() - 1; i >= 0; i--) res = res * D + a[i];
    return res;
  }

  static void _dump(const vector<int>& a, string s = "") {
    if (!s.empty()) cerr << s << " : ";
    cerr << "{ ";
    for (int i = 0; i < (int)a.size(); i++) cerr << a[i] << ", ";
    cerr << "}" << endl;
  }
};

using bigint = MultiPrecisionInteger;

/**
 * @brief 多倍長整数
 */
