#pragma once



struct FloatBinomial {
  vector<long double> fac_;
  static constexpr long double LOGZERO = -1e10;

  FloatBinomial(int MAX) {
    fac_.resize(MAX + 1, 0.0);
    fac_[0] = 0.0;
    for (int i = 1; i <= MAX; i++) {
      fac_[i] = fac_[i - 1] + logl(i);
    }
  }

  long double logfac(int n) const { return fac_[n]; }

  long double logfinv(int n) const { return -fac_[n]; }

  long double logC(int n, int k) const {
    if (n < k || k < 0 || n < 0) return LOGZERO;
    return fac_[n] - fac_[n - k] - fac_[k];
  }

  long double logP(int n, int k) const {
    if (n < k || k < 0 || n < 0) return LOGZERO;
    return fac_[n] - fac_[n - k];
  }
};