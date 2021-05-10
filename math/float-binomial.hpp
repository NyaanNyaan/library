#pragma once



struct FloatBinomial {
  vector<long double> f;
  static constexpr long double LOGZERO = -1e10;

  FloatBinomial(int MAX) {
    f.resize(MAX + 1, 0.0);
    f[0] = 0.0;
    for (int i = 1; i <= MAX; i++) {
      f[i] = f[i - 1] + logl(i);
    }
  }

  long double logfac(int n) const { return f[n]; }

  long double logfinv(int n) const { return -f[n]; }

  long double logC(int n, int k) const {
    if (n < k || k < 0 || n < 0) return LOGZERO;
    return f[n] - f[n - k] - f[k];
  }

  long double logP(int n, int k) const {
    if (n < k || k < 0 || n < 0) return LOGZERO;
    return f[n] - f[n - k];
  }
};