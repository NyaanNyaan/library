#pragma once

#include "rational-binomial.hpp"
#include "rational.hpp"

template <typename R = Rational>
struct FormalPowerSeries_rational : vector<R> {
  using vector<R>::vector;
  using fps = FormalPowerSeries_rational;

  fps &operator+=(const fps &r) {
    if (r.size() > this->size()) this->resize(r.size());
    for (int i = 0; i < (int)r.size(); i++) (*this)[i] += r[i];
    return *this;
  }

  fps &operator+=(const R &r) {
    if (this->empty()) this->resize(1);
    (*this)[0] += r;
    return *this;
  }

  fps &operator-=(const fps &r) {
    if (r.size() > this->size()) this->resize(r.size());
    for (int i = 0; i < (int)r.size(); i++) (*this)[i] -= r[i];
    return *this;
  }

  fps &operator-=(const R &r) {
    if (this->empty()) this->resize(1);
    (*this)[0] -= r;
    return *this;
  }

  fps &operator*=(const fps &r) {
    int n = this->size() + r.size() - 1;
    fps f(n);
    for (int i = 0; i < (int)this->size(); i++) {
      for (int j = 0; j < (int)r.size(); j++) {
        f[i + j] += (*this)[i] * r[j];
      }
    }
    return *this = f;
  }

  fps &operator*=(const R &v) {
    for (int k = 0; k < (int)this->size(); k++) (*this)[k] *= v;
    return *this;
  }

  fps &operator/=(const fps &r) {
    if (this->size() < r.size()) {
      this->clear();
      return *this;
    }
    int n = this->size() - r.size() + 1;
    fps f(*this), g(r);
    g.shrink();
    R coeff = g.back().inverse();
    for (auto &x : g) x *= coeff;
    int deg = (int)f.size() - (int)g.size() + 1;
    int gs = g.size();
    fps quo(deg);
    for (int i = deg - 1; i >= 0; i--) {
      quo[i] = f[i + gs - 1];
      for (int j = 0; j < gs; j++) f[i + j] -= quo[i] * g[j];
    }
    *this = quo * coeff;
    this->resize(n, R(0));
    return *this;
  }

  fps &operator%=(const fps &r) {
    *this -= *this / r * r;
    shrink();
    return *this;
  }

  fps operator+(const fps &r) const { return fps(*this) += r; }
  fps operator+(const R &v) const { return fps(*this) += v; }
  fps operator-(const fps &r) const { return fps(*this) -= r; }
  fps operator-(const R &v) const { return fps(*this) -= v; }
  fps operator*(const fps &r) const { return fps(*this) *= r; }
  fps operator*(const R &v) const { return fps(*this) *= v; }
  fps operator/(const fps &r) const { return fps(*this) /= r; }
  fps operator%(const fps &r) const { return fps(*this) %= r; }
  fps operator-() const {
    fps ret(this->size());
    for (int i = 0; i < (int)this->size(); i++) ret[i] = -(*this)[i];
    return ret;
  }

  void shrink() {
    while (this->size() && this->back() == R(0)) this->pop_back();
  }

  fps rev() const {
    fps ret(*this);
    reverse(begin(ret), end(ret));
    return ret;
  }

  fps dot(fps r) const {
    fps ret(min(this->size(), r.size()));
    for (int i = 0; i < (int)ret.size(); i++) ret[i] = (*this)[i] * r[i];
    return ret;
  }

  // 前 sz 項を取ってくる。sz に足りない項は 0 埋めする
  fps pre(int sz) const {
    fps ret(begin(*this), begin(*this) + min((int)this->size(), sz));
    if ((int)ret.size() < sz) ret.resize(sz);
    return ret;
  }

  fps operator>>(int sz) const {
    if ((int)this->size() <= sz) return {};
    fps ret(*this);
    ret.erase(ret.begin(), ret.begin() + sz);
    return ret;
  }

  fps operator<<(int sz) const {
    fps ret(*this);
    ret.insert(ret.begin(), sz, R(0));
    return ret;
  }

  fps diff() const {
    const int n = (int)this->size();
    fps ret(max(0, n - 1));
    R one(1), coeff(1);
    for (int i = 1; i < n; i++) {
      ret[i - 1] = (*this)[i] * coeff;
      coeff += one;
    }
    return ret;
  }

  fps integral() const {
    const int n = (int)this->size();
    fps ret(n + 1);
    for (int i = 0; i < n; i++) ret[i + 1] = (*this)[i] / (i + 1);
    return ret;
  }

  R eval(R x) const {
    R r = 0, w = 1;
    for (auto &v : *this) r += w * v, w *= x;
    return r;
  }

  fps inv(int deg = -1) const {
    assert((*this)[0] != R(0));
    if (deg == -1) deg = (*this).size();
    fps ret{R(1) / (*this)[0]};
    for (int i = 1; i < deg; i <<= 1) {
      ret = (ret + ret - ret * ret * (*this).pre(i << 1)).pre(i << 1);
    }
    return ret.pre(deg);
  }
  fps log(int deg = -1) const {
    assert(!(*this).empty() && (*this)[0] == R(1));
    if (deg == -1) deg = (int)this->size();
    return (this->diff() * this->inv(deg)).pre(deg - 1).integral();
  }
  fps exp(int deg = -1) const {
    assert((*this).size() == 0 || (*this)[0] == R(0));
    if (deg == -1) deg = (int)this->size();
    fps ret{R(1)};
    for (int i = 1; i < deg; i <<= 1) {
      ret = (ret * (pre(i << 1) + R(1) - ret.log(i << 1))).pre(i << 1);
    }
    return ret.pre(deg);
  }
  fps pow(int64_t k, int deg = -1) const {
    const int n = (int)this->size();
    if (deg == -1) deg = n;
    if (k == 0) {
      fps ret(deg);
      if (deg) ret[0] = 1;
      return ret;
    }
    for (int i = 0; i < n; i++) {
      if ((*this)[i] != R(0)) {
        R rev = R(1) / (*this)[i];
        fps ret = (((*this * rev) >> i).log(deg) * k).exp(deg);
        ret *= (*this)[i].pow(k);
        ret = (ret << (i * k)).pre(deg);
        if ((int)ret.size() < deg) ret.resize(deg, R(0));
        return ret;
      }
      if (__int128_t(i + 1) * k >= deg) return fps(deg, R(0));
    }
    return fps(deg, R(0));
  }
};
