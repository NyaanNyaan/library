#pragma once

template <typename T>
struct Binomial {
  vector<T> fac_, finv_, inv_;
  Binomial(int MAX = 0) : fac_(MAX + 10), finv_(MAX + 10), inv_(MAX + 10) {
    assert(T::get_mod() != 0);
    MAX += 9;
    fac_[0] = finv_[0] = inv_[0] = 1;
    for (int i = 1; i <= MAX; i++) fac_[i] = fac_[i - 1] * i;
    finv_[MAX] = fac_[MAX].inverse();
    for (int i = MAX - 1; i > 0; i--) finv_[i] = finv_[i + 1] * (i + 1);
    for (int i = 1; i <= MAX; i++) inv_[i] = finv_[i] * fac_[i - 1];
  }

  void extend() {
    int n = fac_.size();
    T fac = fac_.back() * n;
    T inv = (-inv_[T::get_mod() % n]) * (T::get_mod() / n);
    T finv = finv_.back() * inv;
    fac_.push_back(fac);
    finv_.push_back(finv);
    inv_.push_back(inv);
  }

  T fac(int i) {
    if(i < 0) return T(0);
    while (i >= (int)fac_.size()) extend();
    return fac_[i];
  }

  T finv(int i) {
    if(i < 0) return T(0);
    while (i >= (int)finv_.size()) extend();
    return finv_[i];
  }

  T inv(int i) {
    if(i < 0) return T(0);
    while (i >= (int)inv_.size()) extend();
    return inv_[i];
  }

  T C(int n, int r) {
    if (n < 0 || n < r || r < 0) return T(0);
    return fac(n) * finv(n - r) * finv(r);
  }

  T C_naive(int n, int r) {
    if (n < 0 || n < r || r < 0) return T(0);
    T ret = T(1);
    r = min(r, n - r);
    for (int i = 1; i <= r; ++i) ret *= inv(i) * (n--);
    return ret;
  }

  T P(int n, int r) {
    if (n < 0 || n < r || r < 0) return T(0);
    return fac(n) * finv(n - r);
  }

  T H(int n, int r) {
    if (n < 0 || r < 0) return T(0);
    return r == 0 ? 1 : C(n + r - 1, r);
  }
};
