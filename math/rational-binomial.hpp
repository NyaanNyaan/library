#pragma once

#include "rational.hpp"

template <typename R = Rational>
struct Binomial_rational {
  vector<R> fc;
  Binomial_rational(int = 0) { fc.emplace_back(1); }
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
  
  R P(int n, int r) {
    if (n < 0 || n < r || r < 0) return R(0);
    return fac(n) * finv(n - r);
  }
  // [x^r] 1 / (1-x)^n
  R H(int n, int r) {
    if (n < 0 || r < 0) return R(0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};
