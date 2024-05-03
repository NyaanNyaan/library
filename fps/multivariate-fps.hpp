#pragma once

#include <algorithm>
#include <cassert>
#include <vector>
using namespace std;

#include "../modulo/binomial.hpp"
#include "../ntt/multivariate-multiplication.hpp"
#include "formal-power-series.hpp"

// FFT mod でないと使えない
// f.size() != (base の総積) でも動くが, 二項演算は長さが等しい列同士しかダメ
// 添え字アクセスは operator() を使う
template <typename mint>
struct MultivariateFormalPowerSeries {
  using mfps = MultivariateFormalPowerSeries<mint>;
  using fps = FormalPowerSeries<mint>;

  fps f;
  vector<int> base;

  MultivariateFormalPowerSeries() = default;
  MultivariateFormalPowerSeries(const vector<int>& _base) : base(_base) {
    int n = 1;
    for (auto& x : base) n *= x;
    f.resize(n);
  }
  MultivariateFormalPowerSeries(const fps& _f, const vector<int>& _base)
      : f(_f), base(_base) {}

  friend ostream& operator<<(ostream& os, const mfps& rhs) {
    os << "[ ";
    for (int i = 0; i < (int)rhs.f.size(); i++) {
      os << rhs.f[i] << (i + 1 == (int)rhs.f.size() ? "" : ", ");
    }
    return os << " ]";
  }

  long long _id(int) { return 0; }
  template <typename Head, typename... Tail>
  long long _id(int i, Head&& head, Tail&&... tail) {
    assert(i < (int)base.size() && (int)head < base[i]);
    return head + _id(i + 1, std::forward<Tail>(tail)...) * base[i];
  }
  template <typename... Args>
  long long id(Args&&... args) {
    return _id(0, std::forward<Args>(args)...);
  }
  template <typename... Args>
  mint& operator()(Args&&... args) {
    return f[id(std::forward<Args>(args)...)];
  }

  mfps& operator+=(const mfps& rhs) {
    assert(base == rhs.base && f.size() == rhs.f.size());
    for (int i = 0; i < (int)f.size(); i++) f[i] += rhs.f[i];
    return *this;
  }
  mfps& operator-=(const mfps& rhs) {
    assert(base == rhs.base && f.size() == rhs.f.size());
    for (int i = 0; i < (int)f.size(); i++) f[i] -= rhs.f[i];
    return *this;
  }
  mfps& operator*=(const mfps& rhs) {
    assert(base == rhs.base && f.size() == rhs.f.size());
    f = multivariate_multiplication(f, rhs.f, base);
    return *this;
  }
  mfps& operator/=(const mfps& rhs) {
    assert(base == rhs.base);
    assert(f.size() == rhs.f.size());
    return (*this) *= rhs.inv();
  }

  mfps& operator+=(const mint& rhs) {
    assert(!f.empty());
    f[0] += rhs;
    return *this;
  }
  mfps& operator-=(const mint& rhs) {
    assert(!f.empty());
    f[0] -= rhs;
    return *this;
  }
  mfps& operator*=(const mint& rhs) {
    for (auto& x : f) x *= rhs;
    return *this;
  }
  mfps& operator/=(const mint& rhs) {
    for (auto& x : f) x /= rhs;
    return *this;
  }

  mfps operator+(const mfps& rhs) const { return mfps{*this} += rhs; }
  mfps operator-(const mfps& rhs) const { return mfps{*this} -= rhs; }
  mfps operator*(const mfps& rhs) const { return mfps{*this} *= rhs; }
  mfps operator/(const mfps& rhs) const { return mfps{*this} /= rhs; }

  mfps operator+(const mint& rhs) const { return mfps{*this} += rhs; }
  mfps operator-(const mint& rhs) const { return mfps{*this} -= rhs; }
  mfps operator*(const mint& rhs) const { return mfps{*this} *= rhs; }
  mfps operator/(const mint& rhs) const { return mfps{*this} /= rhs; }

  mfps operator+() const { return mfps{*this}; }
  mfps operator-() const { return mfps{-f, base}; }

  friend bool operator==(const mfps& lhs, const mfps& rhs) {
    return lhs.f == rhs.f && lhs.base == rhs.base;
  }
  friend bool operator!=(const mfps& lhs, const mfps& rhs) {
    return lhs.f != rhs.f || lhs.base != rhs.base;
  }

  mfps diff() const {
    mfps g{*this};
    for (int i = 0; i < (int)g.f.size(); i++) g.f[i] *= i;
    return g;
  }
  mfps integral() const {
    static Binomial<mint> binom;
    mfps g{*this};
    for (int i = 1; i < (int)g.f.size(); i++) g.f[i] *= binom.inv(i);
    return g;
  }

  mfps inv() const {
    assert(f[0] != 0);
    if (base.empty()) return mfps{fps{f[0].inverse()}, base};
    int n = f.size(), s = base.size(), W = 1;
    while (W < 2 * n) W *= 2;

    vector<int> chi(W);
    for (int i = 0; i < W; i++) {
      int x = i;
      for (int j = 0; j < s - 1; j++) chi[i] += (x /= base[j]);
      chi[i] %= s;
    }
    auto hadamard_prod = [&s](vector<fps>& F, vector<fps>& G, vector<fps>& H) {
      fps a(s);
      for (int k = 0; k < (int)F[0].size(); k++) {
        fill(begin(a), end(a), typename fps::value_type());
        for (int i = 0; i < s; i++)
          for (int j = 0; j < s; j++) {
            a[i + j - (i + j >= s ? s : 0)] += F[i][k] * G[j][k];
          }
        for (int i = 0; i < s; i++) H[i][k] = a[i];
      }
    };
    fps g(W);
    g[0] = f[0].inverse();
    for (int d = 1; d < n; d *= 2) {
      vector<fps> F(s, fps(2 * d)), G(s, fps(2 * d)), H(s, fps(2 * d));
      for (int j = 0; j < min((int)f.size(), 2 * d); j++) F[chi[j]][j] = f[j];
      for (int j = 0; j < d; j++) G[chi[j]][j] = g[j];
      for (auto& x : F) x.ntt();
      for (auto& x : G) x.ntt();
      hadamard_prod(F, G, H);
      for (auto& x : H) x.intt();
      for (auto& x : F) fill(begin(x), end(x), typename fps::value_type());
      for (int j = d; j < 2 * d; j++) F[chi[j]][j] = H[chi[j]][j];
      for (auto& x : F) x.ntt();
      hadamard_prod(F, G, H);
      for (auto& x : H) x.intt();
      for (int j = d; j < 2 * d; j++) g[j] = -H[chi[j]][j];
    }
    mfps res{*this};
    res.f = fps{begin(g), begin(g) + n};
    return res;
  }
  mfps log() const {
    assert(!f.empty() && f[0] == 1);
    return ((*this).diff() / *this).integral();
  }
  mfps exp() const {
    assert(!f.empty() && f[0] == mint{0});
    int n = f.size();
    mfps g{fps{1}, base};
    for (int d = 1; d < n; d *= 2) {
      int s = min(n, d * 2);
      g.f.resize(s, mint{0});
      g *= mfps{fps{begin(f), begin(f) + s}, base} - g.log() + 1;
    }
    return g;
  }
  mfps pow(long long e) const {
    assert(!f.empty());
    if (f[0] != 0) {
      mint f0inv = f[0].inverse(), coe = f[0].pow(e);
      return (((*this) * f0inv).log() * e).exp() * coe;
    }
    int n = f.size();
    long long base_sum = 0;
    for (auto& b : base) base_sum += b - 1;
    if (e > base_sum) return mfps{fps(n), base};
    mfps res{fps(n), base}, a{*this};
    res.f[0] = 1;
    for (; e; a *= a, e >>= 1) {
      if (e & 1) res *= a;
    }
    return res;
  }
};

/**
 * @brief 多変数形式的冪級数ライブラリ
 */
